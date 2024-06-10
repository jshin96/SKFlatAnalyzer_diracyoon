#!/usr/bin/python3

import os,sys,time
import argparse
#sys.path.remove('/opt/ohpc/pub/apps/root_6_12_06/lib')
import ROOT 
from ROOT import TFile
from Plotter.DataAndMC import DataAndMC
import array
import random
parser = argparse.ArgumentParser(description='')
parser.add_argument('-e', dest="Era", default="2017",help="2016preVFP(2016a), 2016postVFP(2016b), 2017, 2018",type=str)
parser.add_argument('-B', dest="BREG_FLAG",default="0",help="run BRegression == 1, not run BRegression == 0",type=int)
parser.add_argument('-r', dest="mult_range",default=1.5,help="range for fitting",type=float)
parser.add_argument('-s', dest="Setting",default="original",help="Fitting Function Setting: original,modified,free",type=str)
parser.add_argument('-M', dest="Scale",default="",help="mur,muf Scale: dd,dn,du,nd,nu,ud,un,uu",type=str)
args = parser.parse_args()
ROOT.gROOT.SetBatch(True)

run_year=args.Era
BREG_FLAG = args.BREG_FLAG
setting = args.Setting
range_mult = args.mult_range
scale_variation = args.Scale
## make userflags as a list
Userflags = []
def fitting_plots(mean_vals,mean_err,sigma_vals,sigma_err,res_mean_vals,res_mean_err,res_sigma_vals,res_sigma_err,mean_correct,plot_name, Fit_setting, run_year,scale_variation):
	if mean_correct != -999:
		fitting_res_mean = res_mean_vals
		fitting_res_mean_error = res_mean_err
		fitting_res_sigma = res_sigma_vals
		fitting_res_sigma_error = res_sigma_err
		fitting_mean = mean_vals
		fitting_mean_error = mean_err
		fitting_sigma = sigma_vals
		fitting_sigma_error = sigma_err
		binnings = [0,0.1,0.155,0.185,0.23,0.3]
#		binnings = [0,0.155,0.185,0.23,0.3]
		binning = array.array('d',binnings)
		res_hist = ROOT.TH1F("resolution","resolution",5,binning)
		central_hist = ROOT.TH1F("central_resolution","central",5,binning)
		up_hist = ROOT.TH1F("up_resolution","up",5,binning)
		down_hist = ROOT.TH1F("down_resolution","down",5,binning)
		data_hist = ROOT.TH1F("data_resolution","data",5,binning)
		central_hist.SetLineColor(ROOT.kRed)
		central_hist.SetLineWidth(2)
		central_hist.SetStats(0)
		up_hist.SetLineColor(ROOT.kBlue)
		up_hist.SetLineWidth(1)
		up_hist.SetStats(0)
		down_hist.SetLineColor(ROOT.kCyan)
		down_hist.SetLineWidth(1)
		down_hist.SetStats(0)
		data_hist.SetLineColor(ROOT.kBlack)
		data_hist.SetLineWidth(2)
		data_hist.SetStats(0)
		central_mean_hist = ROOT.TH1F("mean_central","sigma central",5,binning)
		up_mean_hist = ROOT.TH1F("mean_up","sigma up",5,binning)
		down_mean_hist = ROOT.TH1F("mean_down","sigma down",5,binning)
		up_mean_ratio = ROOT.TH1F("mean_up_ratio","mean up ratio",5,binning)
		down_mean_ratio = ROOT.TH1F("mean_down_ratio","mean down ratio",5,binning)
		data_mean_hist = ROOT.TH1F("mean_data","sigma data",5,binning)
		res_mean_hist = ROOT.TH1F("mean_res","sigma res",5,binning)
		un_m = ROOT.TH1F("un_m","un mean",5,binning)
		dn_m = ROOT.TH1F("dn_m","dn mean",5,binning)
		nu_m = ROOT.TH1F("nu_m","nu mean",5,binning)
		nd_m = ROOT.TH1F("nd_m","nd mean",5,binning)
		uu_m = ROOT.TH1F("uu_m","uu mean",5,binning)
		dd_m = ROOT.TH1F("dd_m","dd mean",5,binning)
		un_s = ROOT.TH1F("un_s","un sigma",5,binning)
		dn_s = ROOT.TH1F("dn_s","dn sigma",5,binning)
		nu_s = ROOT.TH1F("nu_s","nu sigma",5,binning)
		nd_s = ROOT.TH1F("nd_s","nd sigma",5,binning)
		uu_s = ROOT.TH1F("uu_s","uu sigma",5,binning)
		dd_s = ROOT.TH1F("dd_s","dd sigma",5,binning)
		central_mean_hist.SetLineColor(ROOT.kRed)
		central_mean_hist.SetLineWidth(2)
		central_mean_hist.SetStats(0)
		up_mean_hist.SetLineColor(ROOT.kBlue)
		up_mean_hist.SetLineWidth(1)
		up_mean_hist.SetStats(0)
		down_mean_hist.SetLineColor(ROOT.kCyan)
		down_mean_hist.SetLineWidth(1)
		down_mean_hist.SetStats(0)
		data_mean_hist.SetLineColor(ROOT.kBlack)
		data_mean_hist.SetLineWidth(2)
		data_mean_hist.SetStats(0)
	
		central_sigma=central_hist.Clone("Central_resolution"+plot_name)
		data_sigma=data_hist.Clone("Data_resolution"+plot_name)
		up_sigma=up_hist.Clone("Up_resolution"+plot_name)
		down_sigma=down_hist.Clone("Down_resolution"+plot_name)
		temp_central_mean=central_hist.Clone("temp_Central"+plot_name)
		temp_data_mean=data_hist.Clone("temp_Data"+plot_name)
		temp_up_mean=up_hist.Clone("temp_Up"+plot_name)
		temp_down_mean=down_hist.Clone("temp_Down"+plot_name)


		for i in range(5):
			res_mean_hist.SetBinContent(i+1,fitting_res_mean[i][0])
			res_mean_hist.SetBinError(i+1,fitting_res_mean_error[i][0])
			res_hist.SetBinContent(i+1,fitting_res_sigma[i][0])
			res_hist.SetBinError(i+1,fitting_res_sigma_error[i][0])
			up_mean_ratio.SetBinContent(i+1,fitting_mean[i][1])
			up_mean_ratio.SetBinError(i+1,fitting_mean_error[i][1])
			down_mean_ratio.SetBinError(i+1,fitting_mean_error[i][2])
			down_mean_ratio.SetBinContent(i+1,fitting_mean[i][2])
			central_mean_hist.SetBinContent(i+1,fitting_mean[i][0])
			central_mean_hist.SetBinError(i+1,fitting_mean_error[i][0])
			if fitting_mean[i][1]>fitting_mean[i][0]:
				up_mean_hist.SetBinContent(i+1,fitting_mean[i][0]+((fitting_mean[i][1]-fitting_mean[i][0])/2))
				up_mean_hist.SetBinError(i+1,((fitting_mean[i][1]-fitting_mean[i][0])/2))
#				up_mean_hist.SetBinError(i+1,fitting_mean_error[i][1])
			else:
				up_mean_hist.SetBinContent(i+1,fitting_mean[i][0]-(abs(fitting_mean[i][1]-fitting_mean[i][0])/2))
				up_mean_hist.SetBinError(i+1,(abs(fitting_mean[i][1]-fitting_mean[i][0])/2))
#				up_mean_hist.SetBinError(i+1,fitting_mean_error[i][1])
			if fitting_mean[i][2]>fitting_mean[i][0]:
				down_mean_hist.SetBinContent(i+1,fitting_mean[i][0]+((fitting_mean[i][2]-fitting_mean[i][0])/2))
				down_mean_hist.SetBinError(i+1,((fitting_mean[i][2]-fitting_mean[i][0])/2))
#				down_mean_hist.SetBinError(i+1,fitting_mean_error[i][1])
			else:
				down_mean_hist.SetBinContent(i+1,fitting_mean[i][0]-(abs(fitting_mean[i][2]-fitting_mean[i][0])/2))
				down_mean_hist.SetBinError(i+1,(abs(fitting_mean[i][2]-fitting_mean[i][0])/2))
#				down_mean_hist.SetBinError(i+1,fitting_mean_error[i][1])



			data_mean_hist.SetBinContent(i+1,fitting_mean[i][3])
			data_mean_hist.SetBinError(i+1,fitting_mean_error[i][3])
	
			un_m.SetBinContent(i+1,fitting_mean[i][4])
			dn_m.SetBinContent(i+1,fitting_mean[i][5])
			nu_m.SetBinContent(i+1,fitting_mean[i][6])
			nd_m.SetBinContent(i+1,fitting_mean[i][7])
			uu_m.SetBinContent(i+1,fitting_mean[i][8])
			dd_m.SetBinContent(i+1,fitting_mean[i][9])
			un_m.SetBinError(i+1,fitting_mean_error[i][4])
			dn_m.SetBinError(i+1,fitting_mean_error[i][5])
			nu_m.SetBinError(i+1,fitting_mean_error[i][6])
			nd_m.SetBinError(i+1,fitting_mean_error[i][7])
			uu_m.SetBinError(i+1,fitting_mean_error[i][8])
			dd_m.SetBinError(i+1,fitting_mean_error[i][9])


			central_sigma.SetBinContent(i+1,fitting_sigma[i][0])
			central_sigma.SetBinError(i+1,fitting_sigma_error[i][0])
			if fitting_sigma[i][1]>fitting_sigma[i][0]:
				up_sigma.SetBinContent(i+1,fitting_sigma[i][0]+(abs(fitting_sigma[i][1]-fitting_sigma[i][0])/2))
				up_sigma.SetBinError(i+1,abs(fitting_sigma[i][1]-fitting_sigma[i][0])/2)
#				up_sigma.SetBinError(i+1,fitting_sigma[i][1])
			else:
				up_sigma.SetBinContent(i+1,fitting_sigma[i][0]-(abs(fitting_sigma[i][1]-fitting_sigma[i][0])/2))
				up_sigma.SetBinError(i+1,abs(fitting_sigma[i][1]-fitting_sigma[i][0])/2)
#				up_sigma.SetBinError(i+1,fitting_sigma[i][1])
			if fitting_sigma[i][1]>fitting_sigma[i][0]:
				down_sigma.SetBinContent(i+1,fitting_sigma[i][0]+(abs(fitting_sigma[i][2]-fitting_sigma[i][0])/2))
				down_sigma.SetBinError(i+1,abs(fitting_sigma[i][2]-fitting_sigma[i][0])/2)
#				down_sigma.SetBinError(i+1,fitting_sigma[i][2])
			else:
				down_sigma.SetBinContent(i+1,fitting_sigma[i][0]-(abs(fitting_sigma[i][2]-fitting_sigma[i][0])/2))
				down_sigma.SetBinError(i+1,abs(fitting_sigma[i][2]-fitting_sigma[i][0])/2)
#				down_sigma.SetBinError(i+1,fitting_sigma[i][2])
			data_sigma.SetBinContent(i+1,fitting_sigma[i][3])
			data_sigma.SetBinError(i+1,fitting_sigma_error[i][3])
					


			un_s.SetBinContent(i+1,fitting_sigma[i][4])
			dn_s.SetBinContent(i+1,fitting_sigma[i][5])
			nu_s.SetBinContent(i+1,fitting_sigma[i][6])
			nd_s.SetBinContent(i+1,fitting_sigma[i][7])
			uu_s.SetBinContent(i+1,fitting_sigma[i][8])
			dd_s.SetBinContent(i+1,fitting_sigma[i][9])
			un_s.SetBinError(i+1,fitting_sigma_error[i][4])
			dn_s.SetBinError(i+1,fitting_sigma_error[i][5])
			nu_s.SetBinError(i+1,fitting_sigma_error[i][6])
			nd_s.SetBinError(i+1,fitting_sigma_error[i][7])
			uu_s.SetBinError(i+1,fitting_sigma_error[i][8])
			dd_s.SetBinError(i+1,fitting_sigma_error[i][9])
			temp_central_mean.SetBinContent(i+1,fitting_mean[i][0])
			temp_central_mean.SetBinError(i+1,fitting_mean_error[i][0])
			temp_up_mean.SetBinContent(i+1,fitting_mean[i][1])
			temp_up_mean.SetBinError(i+1,fitting_mean_error[i][1])
			temp_down_mean.SetBinContent(i+1,fitting_mean[i][2])
			temp_down_mean.SetBinError(i+1,fitting_mean_error[i][2])
			temp_data_mean.SetBinContent(i+1,fitting_mean[i][3])
			temp_data_mean.SetBinError(i+1,fitting_mean_error[i][3])

			central_hist.SetBinContent(i+1,fitting_sigma[i][0])
			central_hist.SetBinError(i+1,fitting_sigma_error[i][0])
			up_hist.SetBinContent(i+1,fitting_sigma[i][1])
			up_hist.SetBinError(i+1,fitting_sigma_error[i][1])
			down_hist.SetBinContent(i+1,fitting_sigma[i][2])
			down_hist.SetBinError(i+1,fitting_sigma_error[i][2])
			data_hist.SetBinContent(i+1,fitting_sigma[i][3])
			data_hist.SetBinError(i+1,fitting_sigma_error[i][3])
	
		un_r = un_s.Clone("un_r")
		dn_r = dn_s.Clone("dn_r")
		nu_r = nu_s.Clone("nu_r")
		nd_r = nd_s.Clone("nd_r")
		uu_r = uu_s.Clone("uu_r")
		dd_r = dd_s.Clone("dd_r")


		central_mean_hist.SetLineWidth(2)
		central_mean_hist.SetMarkerStyle(20)
		central_mean_hist.SetMarkerColor(ROOT.kRed)
		central_mean_hist.SetStats(0)
		res_hist.SetLineColor(ROOT.kGreen)
		res_hist.SetMarkerStyle(20)
		res_hist.SetMarkerColor(ROOT.kGreen)
		res_hist.SetLineWidth(2)
		res_hist.SetStats(0)
		res_mean_hist.SetLineColor(ROOT.kGreen)
		res_mean_hist.SetMarkerStyle(20)
		res_mean_hist.SetMarkerColor(ROOT.kGreen)
		res_mean_hist.SetLineWidth(2)
		res_mean_hist.SetStats(0)
		up_mean_hist.SetLineColor(ROOT.kBlue)
		up_mean_hist.SetLineWidth(1)
		up_mean_hist.SetStats(0)
		down_mean_hist.SetLineColor(ROOT.kCyan)
		down_mean_hist.SetLineWidth(1)
		down_mean_hist.SetStats(0)
		data_mean_hist.SetLineColor(ROOT.kBlack)
		data_mean_hist.SetLineWidth(2)
		data_mean_hist.SetStats(0)
		data_mean_hist.SetMarkerStyle(20)
		data_mean_hist.SetMarkerColor(ROOT.kBlack)
		central_sigma.SetLineWidth(2)
		central_sigma.SetStats(0)
		central_sigma.SetMarkerStyle(20)
		central_sigma.SetMarkerColor(ROOT.kRed)
		data_sigma.SetMarkerStyle(20)
		data_sigma.SetMarkerColor(ROOT.kBlack)
		up_mean_hist.SetFillColor(ROOT.kBlue)
		up_mean_hist.SetFillStyle(3135)
		down_mean_hist.SetFillColor(ROOT.kCyan)
		down_mean_hist.SetFillStyle(3145)
		up_sigma.SetFillColor(ROOT.kBlue)
		up_sigma.SetFillStyle(3135)
		down_sigma.SetFillColor(ROOT.kCyan)
		down_sigma.SetFillStyle(3145)
		central_mean_hist.SetLineColor(ROOT.kRed)
		
		data_sigma.SetLineWidth(2)
		data_sigma.SetStats(0)
		legend = ROOT.TLegend(0.65, 0.70,0.93, 0.87)
		legend.SetFillStyle(0)
		legend.SetTextSize(0.02)
		legend.AddEntry(data_hist,"Data")
		legend.AddEntry(central_hist,"Central")
		legend.AddEntry(up_hist,"JEC up")
		legend.AddEntry(down_hist,"JEC down")
		
		c = ROOT.TCanvas("","",680,900)
		c.cd()
		mean_ratio = central_mean_hist.Clone()
		mean_ratio.Divide(data_mean_hist)
		mean_ratio.GetYaxis().SetRangeUser(0.5,1.5)
		mean_ratio.GetYaxis().SetNdivisions(207)
		lin_mean = ROOT.TF1("lin_mean","([0] * x) + [1]",0,0.3)
		lin_mean.SetParameter(0,-0.01)
		lin_mean.SetParameter(1,1.0)
		lin_mean_result=mean_ratio.Fit("lin_mean","M Q E P S 0","",0.0,0.3)
		up_mean_ratio.Divide(data_mean_hist)
		up_mean_ratio.GetYaxis().SetRangeUser(0.5,1.5)
		up_mean_ratio.GetYaxis().SetNdivisions(207)
		uplin_mean = ROOT.TF1("uplin_mean","([0] * x) + [1]",0,0.3)
		uplin_mean.SetParameter(0,-0.01)
		uplin_mean.SetParameter(1,1.0)
		down_mean_ratio.Divide(data_mean_hist)
		down_mean_ratio.GetYaxis().SetRangeUser(0.5,1.5)
		down_mean_ratio.GetYaxis().SetNdivisions(207)
		downlin_mean = ROOT.TF1("downlin_mean","([0] * x) + [1]",0,0.3)
		downlin_mean.SetParameter(0,-0.01)
		downlin_mean.SetParameter(1,1.0)
		uplin_mean_result=up_mean_ratio.Fit("uplin_mean","M Q E P S 0","",0.0,0.3)
		downlin_mean_result=down_mean_ratio.Fit("downlin_mean","M Q E P S 0","",0.0,0.3)
		uplin_mean.SetLineColor(ROOT.kBlue)
		downlin_mean.SetLineColor(ROOT.kCyan)
		temp_chi2=100
		NTries=0
		m_zero = 100
		while NTries<100:
			if lin_mean_result.Chi2()<temp_chi2:
				temp_chi2=lin_mean_result.Chi2()
				m_zero = lin_mean.GetParameter(1)
				m_err = lin_mean.GetParError(1)
				lin_mean.SetParameter(0,-0.01-NTries*0.001)
				lin_mean.SetParameter(1,1.0-NTries*0.002)
				lin_mean_result=mean_ratio.Fit("lin_mean","M Q E P S 0","",0.0,0.3)
			NTries+=1



		pad1 = ROOT.TPad("p1","p1",0,0.3,1,1)
		pad1.Draw()
		pad1.cd()
		blank_hist=ROOT.TH1F("blank","blank",4,binning)
		blank_hist.SetLineWidth(0)
		blank_hist.SetLineColor(0)
		blank_hist.SetMarkerColor(0)
		blank_hist.SetMarkerSize(0)
		legend.AddEntry(blank_hist ,"JEC SF: %f #pm %f" %(m_zero,m_err))
		central_mean_hist.GetYaxis().SetRangeUser(0.5,1)
		central_mean_hist.Draw(" e x0 *")
		central_mean_hist.GetYaxis().SetTitle("#mu")
		central_mean_hist.GetXaxis().SetTitle("#alpha")
		central_mean_hist.SetTitle("%s #mu" %run_year)
		up_mean_hist.Draw("SAME e2 L")
		down_mean_hist.Draw("SAME e2 L")
		data_mean_hist.Draw("SAME e x0 *")
		res_mean_hist.Draw("SAME e x0 *")
		central_mean_hist.Draw("SAME e x0 *")
		legend.Draw("SAME")
		c.cd()
		pad2 = ROOT.TPad("p1","p1",0,0.05,1,0.3)
		pad2.Draw()
		pad2.cd()
		mean_ratio.GetYaxis().SetRangeUser(0.9,1.1)
		mean_ratio.Draw("e X0 *")
		up_mean_ratio.SetMarkerStyle(20)
		up_mean_ratio.SetMarkerColor(ROOT.kBlue)
		down_mean_ratio.SetMarkerStyle(20)
		down_mean_ratio.SetMarkerColor(ROOT.kCyan)
		up_mean_ratio.Draw("e X0 * same")
		down_mean_ratio.Draw("e X0 * same")
		lin_mean.Draw("same")
		uplin_mean.Draw("same")
		downlin_mean.Draw("same")
		c.SaveAs("alpha_mean_value_"+plot_name+"_"+scale_variation+".png")
		c.SaveAs("alpha_mean_value_"+plot_name+"_"+scale_variation+".C")
	
	
		c1 = ROOT.TCanvas("","",680,680)
		c1.cd()
		central_sigma.GetYaxis().SetRangeUser(0,0.5)
		central_sigma.Draw("e x0 *")
		central_sigma.GetYaxis().SetTitle("#sigma")
		central_sigma.GetXaxis().SetTitle("#alpha")
		central_sigma.SetTitle("%s #sigma" %run_year)
		up_sigma.Draw("SAME e2 L ")
		down_sigma.Draw("SAME e2 L")
		data_sigma.Draw("SAME e x0 *")
		res_hist.Draw("SAME e x0 *")
		central_sigma.Draw("SAME e x0 *")
		legend.Draw("SAME")
		c1.SaveAs("alpha_sigma_value_"+plot_name+"_"+scale_variation+".png")
		c1.SaveAs("alpha_sigma_value_"+plot_name+"_"+scale_variation+".C")
	
		c1.Clear()
	
		un_r.Divide(un_m)
		dn_r.Divide(dn_m)
		nu_r.Divide(nu_m)
		nd_r.Divide(nd_m)
		uu_r.Divide(uu_m)
		dd_r.Divide(dd_m)


		central_hist.Divide(temp_central_mean)
		up_hist.Divide(temp_up_mean)
		down_hist.Divide(temp_down_mean)
		data_hist.Divide(temp_data_mean)
		res_hist.Divide(res_mean_hist)
		for i in range(5):
			max_scale=0
			min_scale=0
			JEC_up_high=0
			JEC_up_low=0
			JEC_down_high=0
			JEC_down_low=0
			max_scale=max((central_hist.GetBinContent(i+1)-un_r.GetBinContent(i+1)),(central_hist.GetBinContent(i+1)-dn_r.GetBinContent(i+1)),(central_hist.GetBinContent(i+1)-nu_r.GetBinContent(i+1)),(central_hist.GetBinContent(i+1)-nd_r.GetBinContent(i+1)),(central_hist.GetBinContent(i+1)-uu_r.GetBinContent(i+1)),(central_hist.GetBinContent(i+1)-dd_r.GetBinContent(i+1)),0)
			min_scale=min((central_hist.GetBinContent(i+1)-un_r.GetBinContent(i+1)),(central_hist.GetBinContent(i+1)-dn_r.GetBinContent(i+1)),(central_hist.GetBinContent(i+1)-nu_r.GetBinContent(i+1)),(central_hist.GetBinContent(i+1)-nd_r.GetBinContent(i+1)),(central_hist.GetBinContent(i+1)-uu_r.GetBinContent(i+1)),(central_hist.GetBinContent(i+1)-dd_r.GetBinContent(i+1)),0)
			
			if up_hist.GetBinContent(i+1)>central_hist.GetBinContent(i+1):
				JEC_up_high=(up_hist.GetBinContent(i+1)-central_hist.GetBinContent(i+1))
			elif up_hist.GetBinContent(i+1)<=central_hist.GetBinContent(i+1):
				JEC_up_low=(central_hist.GetBinContent(i+1)-up_hist.GetBinContent(i+1))
			if down_hist.GetBinContent(i+1)>central_hist.GetBinContent(i+1):
				JEC_down_high=(down_hist.GetBinContent(i+1)-central_hist.GetBinContent(i+1))
			elif down_hist.GetBinContent(i+1)<=central_hist.GetBinContent(i+1):
				JEC_down_low=(central_hist.GetBinContent(i+1)-down_hist.GetBinContent(i+1))
			up_hist.SetBinContent(i+1,central_hist.GetBinContent(i+1)+(((abs(JEC_up_high)**2+abs(JEC_down_high)**2+abs(max_scale)**2)**0.5)/2))
			up_hist.SetBinError(i+1,(((abs(JEC_up_high)**2+abs(JEC_down_high)**2+abs(max_scale)**2)**0.5)/2))
			down_hist.SetBinContent(i+1,central_hist.GetBinContent(i+1)-(((abs(JEC_up_low)**2+abs(JEC_down_low)**2+abs(min_scale)**2)**0.5)/2))
			down_hist.SetBinError(i+1,(((abs(JEC_up_low)**2+abs(JEC_down_low)**2+abs(min_scale)**2)**0.5)/2))
		central_hist.SetMarkerStyle(20)
		central_hist.SetMarkerColor(ROOT.kRed)
		data_hist.SetMarkerStyle(20)
		data_hist.SetMarkerColor(ROOT.kBlack)
		res_hist.SetMarkerStyle(20)
		res_hist.SetMarkerColor(ROOT.kGreen)
		ROOT.Math.MinimizerOptions.SetDefaultMinimizer("Minuit2")
		init_lin_hist = ROOT.TF1("init_lin_hist","([0]*x + [1])",0,0.3)
		init_lin_hist.SetParameter(0,0.3)
		init_lin_hist.SetParameter(1,0.22)
	
		res_hist.Fit("init_lin_hist","Q 0","",0.0,0.3)
	
		ck_hist = (init_lin_hist.GetParameter(0)/init_lin_hist.GetParameter(1))
#		ck_hist = (init_lin_hist.GetParameter(0))
		
#		print("ck: %f" %ck_hist)
	
		lin_data_1 = ROOT.TF1("lin_data_1","([0] * x)",0,0.3)
		lin_hist_1 = ROOT.TF1("lin_hist_1","([0] * x)",0,0.3)
		if Fit_setting == "original": 
			lin_data_2 = ROOT.TF1("lin_data_2","([0] * ([1] * x + 1))",0,0.3)
			lin_hist_2 = ROOT.TF1("lin_hist_2","([0] * ([1] * x + 1))",0,0.3)
			lin_data = ROOT.TF1("lin_data", "((([0] * x)**2)+(([1] * ([2] * x + 1))**2))**0.5", 0,0.3)
			lin_hist = ROOT.TF1("lin_hist", "((([0] * x)**2)+(([1] * ([2] * x + 1))**2))**0.5", 0,0.3)

		elif Fit_setting == "modified": 
			lin_data_2 = ROOT.TF1("lin_data_2","(([1] * x + [0]))",0,0.3)
			lin_hist_2 = ROOT.TF1("lin_hist_2","(([1] * x + [0]))",0,0.3)
			lin_data = ROOT.TF1("lin_data", "((([0] * x)**2)+((([2] * x + [1]))**2))**0.5", 0,0.3)
			lin_hist = ROOT.TF1("lin_hist", "((([0] * x)**2)+((([2] * x + [1]))**2))**0.5", 0,0.3)
		elif Fit_setting == "free": 
			lin_data_2 = ROOT.TF1("lin_data_2","([0] * ([1] * x + 1))",0,0.3)
			lin_hist_2 = ROOT.TF1("lin_hist_2","([0] * ([1] * x + 1))",0,0.3)
			lin_data = ROOT.TF1("lin_data", "((([0] * x)**2)+(([1] * ([2] * x + 1))**2))**0.5", 0,0.3)
			lin_hist = ROOT.TF1("lin_hist", "((([0] * x)**2)+(([1] * ([2] * x + 1))**2))**0.5", 0,0.3)
		else:
			print("Fitting Setting not available")
			return
#		if Fit_setting == "original": 
#			lin_data_2 = ROOT.TF1("lin_data_2","([0] * ([1] * x + 1))",0,0.3)
#			lin_hist_2 = ROOT.TF1("lin_hist_2","([0] * ([1] * x + 1))",0,0.3)
#
#		elif Fit_setting == "modified": 
#			lin_data_2 = ROOT.TF1("lin_data_2","(([1] * x + [0]))",0,0.3)
#			lin_hist_2 = ROOT.TF1("lin_hist_2","(([1] * x + [0]))",0,0.3)
#		elif Fit_setting == "free": 
#			lin_data_2 = ROOT.TF1("lin_data_2","([0] * ([1] * x + 1))",0,0.3)
#			lin_hist_2 = ROOT.TF1("lin_hist_2","([0] * ([1] * x + 1))",0,0.3)
#		else:
#			print("Fitting Setting not available")
#			return
#		lin_data_2 = ROOT.TF1("lin_data_2","(([1] * x + [0]))",0,0.3)
#		lin_data_2 = ROOT.TF1("lin_data_2","(([1] * x + [0]))",0,0.3)
#		lin_hist_2 = ROOT.TF1("lin_hist_2","(([1] * x + [0]))",0,0.3)
#		lin_hist_2 = ROOT.TF1("lin_hist_2","(([1] * x + [0]))",0,0.3)
#		lin_data_1.SetParName(0,"m_data")
#		lin_hist_1.SetParName(0,"m_hist")
#		lin_data_2.SetParName(0,"c_data")
#		lin_hist_2.SetParName(0,"c_hist")
	
#		conv_data = ROOT.TF1Convolution("lin_data_1","lin_data_2",0,0.3,False)
#		conv_hist = ROOT.TF1Convolution("lin_hist_1","lin_hist_2",0,0.3,False)
#		lin_data = ROOT.TF1("lin_data", conv_data, 0,1.0,conv_data.GetNpar())
#		lin_hist = ROOT.TF1("lin_hist", conv_hist, 0,1.0,conv_hist.GetNpar())
		

		if Fit_setting == "original": 
			lin_data.FixParameter(2,ck_hist)
			lin_hist.FixParameter(2,ck_hist)
		lin_data.SetParLimits(0,0.0,5.0)
		lin_data.SetParLimits(1,0.0,5.0)
		lin_hist.SetParLimits(0,0.0,5.0)
		lin_hist.SetParLimits(1,0.0,5.0)
#		lin_data.SetRange(0.0,0.3)
#		lin_hist.SetRange(0.0,0.3)
		hist_chi2=9999999999
		data_chi2=9999999999
		best_h_c_e = 9999
		best_h_m_e = 9999
		best_h_k_e = 9999
		best_d_c_e = 9999
		best_d_m_e = 9999
		best_d_k_e = 9999
		best_h_c = 9999
		best_h_m = 9999
		best_h_k = 9999
		best_d_c = 9999
		best_d_m = 9999
		best_d_k = 9999
		ncalls = 10000
		tries = 0
		data_success = False
		hist_success = False
		while tries < 1000:
			temp_g= random.uniform(0,2)
			temp_h= random.uniform(0,2)
#			if data_success == False:
			lin_data.SetParameter(0,temp_h)
			lin_data.SetParameter(1,temp_g)
			lin_hist.SetParameter(0,temp_h)
			lin_hist.SetParameter(1,temp_g)
			data_result=data_hist.Fit("lin_data","M Q E P S 0","",0.0,0.3)
			hist_result=central_hist.Fit("lin_hist","M Q E P S 0","",0.0,0.3)
			
			if data_chi2>data_result.Chi2():
				data_success == data_result.IsValid()
				data_chi2 = data_result.Chi2()		
				best_d_k = lin_data.GetParameter(2)
				best_d_c = lin_data.GetParameter(1)
				best_d_m = lin_data.GetParameter(0)
				best_d_k_e = lin_data.GetParError(2)
				best_d_c_e = lin_data.GetParError(1)
				best_d_m_e = lin_data.GetParError(0)
#			if hist_success == False:
			if hist_chi2>hist_result.Chi2():
				hist_success == hist_result.IsValid()
				hist_chi2 = hist_result.Chi2()	
				best_h_k = lin_hist.GetParameter(2)
				best_h_c = lin_hist.GetParameter(1)
				best_h_m = lin_hist.GetParameter(0)
				best_h_k_e = lin_hist.GetParError(2)
				best_h_c_e = lin_hist.GetParError(1)
				best_h_m_e = lin_hist.GetParError(0)
				

			tries += 1



		lin_hist.SetParameter(0,best_h_m)
		lin_hist.SetParameter(1,best_h_c)
		lin_hist.SetParameter(2,best_h_k)
		lin_data.SetParameter(0,best_d_m)
		lin_data.SetParameter(1,best_d_c)
		lin_data.SetParameter(2,best_d_k)
		lin_hist.SetParError(0,best_h_m_e)
		lin_hist.SetParError(1,best_h_c_e)
		lin_hist.SetParError(2,best_h_k_e)
		lin_data.SetParError(0,best_d_m_e)
		lin_data.SetParError(1,best_d_c_e)
		lin_data.SetParError(2,best_d_k_e)



		c_hist_err=lin_hist.GetParError(1)
		m_hist_err=lin_hist.GetParError(0)
		k_hist_err=lin_hist.GetParError(2)
		c_data_err=lin_data.GetParError(1)
		m_data_err=lin_data.GetParError(0)
		k_data_err=lin_data.GetParError(2)
		c_hist=lin_hist.GetParameter(1)
		m_hist=lin_hist.GetParameter(0)
		k_hist=lin_hist.GetParameter(2)
		c_data=lin_data.GetParameter(1)
		m_data=lin_data.GetParameter(0)
		k_data=lin_data.GetParameter(2)
		lin_hist.SetLineColor(ROOT.kRed)
		lin_hist.SetLineWidth(2)
		lin_data.SetLineColor(ROOT.kBlack)
		lin_data.SetLineWidth(2)
		pseudo_hist = ROOT.TH1F("pseudo_hist","pseudo_hist",20,0,0.5)
		pseudo_data = ROOT.TH1F("pseudo_data","pseudo_data",20,0,0.5)
#		for i in range(10000):
#			temp_c_hist = random.gauss(c_hist,c_hist_err)			
#			temp_m_hist = random.gauss(m_hist,m_hist_err)				
#			temp_c_data = random.gauss(c_data,c_data_err)		
#			temp_m_data = random.gauss(m_data,m_data_err)						
#			temp_lin_data = ROOT.TF1("temp_linear_data", conv_data, 0,1,conv_data.GetNpar())
#			temp_lin_hist = ROOT.TF1("temp_linear_hist", conv_hist, 0,1,conv_data.GetNpar())
#			temp_lin_data.FixParameter(0,temp_m_data)
#			temp_lin_data.FixParameter(2,ck_hist)
#			temp_lin_data.FixParameter(1,temp_c_data)
#			temp_lin_hist.FixParameter(0,temp_m_hist)
#			temp_lin_hist.FixParameter(2,ck_hist)
#			temp_lin_hist.FixParameter(1,temp_c_hist)
#			pseudo_data.Fill(temp_lin_data.Eval(0))	
#			pseudo_hist.Fill(temp_lin_hist.Eval(0))
		
#		pseudo_hist.Fit("gaus")
#		pseudo_data.Fit("gaus")
#		pseudo_d_hist=pseudo_hist.GetFunction("gaus")
#		pseudo_h_hist=pseudo_data.GetFunction("gaus")
#		error_data=pseudo_d_hist.GetParameter(2)
#		error_hist=pseudo_h_hist.GetParameter(2)

	
#		print("c of MC: %f" %c_hist)
#		print("c of data: %f" %c_data)
#		print("scale: %.3f" %(c_data/c_hist))
		blank_hist=ROOT.TH1F("blank","blank",4,binning)
		blank_hist.SetLineWidth(0)
		blank_hist.SetLineColor(0)
		blank_hist.SetMarkerColor(0)
		blank_hist.SetMarkerSize(0)
		central_hist.SetLineWidth(2)
		up_hist.SetLineWidth(0)
		down_hist.SetLineWidth(0)
		data_hist.SetLineWidth(2)
		up_hist.SetLineWidth(1)
		up_hist.SetFillColorAlpha(ROOT.kBlue,0.35)
		up_hist.SetLineColor(ROOT.kBlue)
		down_hist.SetLineWidth(1)
		down_hist.SetFillColorAlpha(ROOT.kBlue,0.35)
		down_hist.SetLineColor(ROOT.kCyan)
		up_hist.SetFillStyle(1001)
		down_hist.SetFillStyle(1001)
		y_0_mc = lin_hist.Eval(0)
		y_0_data = lin_data.Eval(0)
#		REG_SCALE = lin_data.Eval(0)/lin_hist.Eval(0)
		REG_SCALE = c_data/c_hist
#		REG_SCALE_ERR = abs(REG_SCALE)*((error_hist/y_0_mc)**2+(error_data/y_0_data)**2)**0.5
		REG_SCALE_ERR = abs(REG_SCALE)*((c_hist_err/c_hist)**2+(c_data_err/c_data)**2)**0.5
		legend1 = ROOT.TLegend(0.1, 0.1, 0.5, 0.25)
		legend2 = ROOT.TLegend(0.5, 0.1, 0.9, 0.25)
		legend1.SetFillStyle(1001)
		legend1.SetTextSize(0.02)
		legend2.SetFillStyle(1001)
		legend2.SetTextSize(0.02)
		legend1.AddEntry(res_hist,"Intrinsic")
		legend1.AddEntry(init_lin_hist,"c_{0} x + m_{0}")
		legend1.AddEntry(blank_hist,"c_{k} = %.3f" %ck_hist)
		legend1.AddEntry(data_hist,"Data")
		if Fit_setting == "original": 
			legend1.AddEntry(lin_data,"m_{data}\cdot x \oplus c_{data}(k_{data} \cdot x + 1)")
		elif Fit_setting == "modified": 
			legend1.AddEntry(lin_data,"m_{data}\cdot x \oplus (k_{data} \cdot x + c_{data})")
		elif Fit_setting == "free": 
			legend1.AddEntry(lin_data,"m_{data}\cdot x \oplus c_{data}(k_{data} \cdot x + 1)")
		legend1.AddEntry(blank_hist,"m_{data} = %.3f \pm %.3f" %(m_data,m_data_err))
		legend1.AddEntry(blank_hist,"k_{data} = %.3f \pm %.3f" %(k_data,k_data_err))
		legend1.AddEntry(blank_hist,"c_{data} = %.3f \pm %.3f" %(c_data,c_data_err))
#		legend.AddEntry(blank_hist,"y(0)_{data} = %.3f \pm %.3f" %(y_0_data,error_data))
		legend2.AddEntry(blank_hist,"scale = %.3f \pm %.3f" %(REG_SCALE,REG_SCALE_ERR))
		legend2.AddEntry(up_hist,"JEC + Scale Variation")
#		legend2.AddEntry(down_hist,"JEC down MC")
		legend2.AddEntry(central_hist,"Central MC")
		if Fit_setting == "original": 
			legend2.AddEntry(lin_hist,"m_{MC}\cdot x \oplus c_{MC}(k_{MC} \cdot x + 1)")
		elif Fit_setting == "modified": 
			legend2.AddEntry(lin_hist,"m_{MC}\cdot x \oplus (k_{MC} \cdot x + c_{MC})")
		elif Fit_setting == "free": 
			legend2.AddEntry(lin_hist,"m_{MC}\cdot x \oplus c_{MC}(k_{MC} \cdot x + 1)")
		legend2.AddEntry(blank_hist,"m_{MC} = %.3f \pm %.3f" %(m_hist,m_hist_err))
		legend2.AddEntry(blank_hist,"k_{MC} = %.3f \pm %.3f" %(k_hist,k_hist_err))
		legend2.AddEntry(blank_hist,"c_{MC} = %.3f \pm %.3f" %(c_hist,c_hist_err))
#		legend.AddEntry(blank_hist,"y(0)_{MC} = %.3f \pm %.3f" %(y_0_mc,error_hist))
	
	
#		for i in range(4):
#			if central_hist.GetBinContent(1+i)-up_hist.GetBinContent(1+i)>0:
#				up_hist.SetBinContent(i+1,central_hist.GetBinContent(1+i)-(abs(central_hist.GetBinContent(1+i)-up_hist.GetBinContent(1+i))/2))
#				up_hist.SetBinError(i+1,abs(central_hist.GetBinContent(1+i)-up_hist.GetBinContent(1+i))/2)
#			elif central_hist.GetBinContent(1+i)-up_hist.GetBinContent(1+i)<=0:
#				up_hist.SetBinContent(i+1,central_hist.GetBinContent(1+i)+(abs(central_hist.GetBinContent(1+i)-up_hist.GetBinContent(1+i))/2))
#				up_hist.SetBinError(i+1,abs(central_hist.GetBinContent(1+i)-up_hist.GetBinContent(1+i))/2)
#			if central_hist.GetBinContent(1+i)-down_hist.GetBinContent(1+i)>0:
#				down_hist.SetBinContent(i+1,central_hist.GetBinContent(1+i)-(abs(central_hist.GetBinContent(1+i)-down_hist.GetBinContent(1+i))/2))
#				down_hist.SetBinError(i+1,abs(central_hist.GetBinContent(1+i)-down_hist.GetBinContent(1+i))/2)
#			elif central_hist.GetBinContent(1+i)-down_hist.GetBinContent(1+i)<=0:
#				down_hist.SetBinContent(i+1,central_hist.GetBinContent(1+i)+(abs(central_hist.GetBinContent(1+i)-down_hist.GetBinContent(1+i))/2))
#				down_hist.SetBinError(i+1,abs(central_hist.GetBinContent(1+i)-down_hist.GetBinContent(1+i))/2)
		c2 = ROOT.TCanvas("","",680,680)
		c2.cd()
		central_hist.GetYaxis().SetRangeUser(-0.1,0.41)
		central_hist.GetXaxis().SetRangeUser(0,0.35)
		central_hist.Draw("E X0 ")
		central_hist.SetTitle("%s resolution" %run_year)
		central_hist.GetYaxis().SetTitle("resolution")
		central_hist.GetXaxis().SetTitle("#alpha")
		lin_hist.Draw("SAME")
		lin_data.Draw("SAME")
		up_hist.Draw("SAME E0 E2 L")
		down_hist.Draw("SAME E0 E2 L")
		data_hist.Draw("SAME E X0")
		central_hist.Draw("SAME E X0 ")
		legend1.Draw("SAME")
		legend2.Draw("SAME")
		init_lin_hist.SetLineColor(ROOT.kGreen)
		init_lin_hist.SetLineWidth(2)
		res_hist.SetLineColor(ROOT.kGreen)
		res_hist.SetLineWidth(2)
		init_lin_hist.Draw("SAME")
		res_hist.Draw("SAME E X0 ")
		c2.SaveAs("alpha_resolution_value_"+plot_name+"_"+scale_variation+".png")
		c2.SaveAs("alpha_resolution_value_"+plot_name+"_"+scale_variation+".C")
		c2.Clear()





# NOTE: This script use pyROOT with python version >= 3.6 because of f-strings
# If you want to use lower python version, change f"...{var}" to "...{}".format(var)
# In the tamsa server, setting an environment with CMSSW_11_* will be sufficient

# set global variables
variables = ["ZCand_Mass_",
             "LeadJet_BTagging_Score_",
             "SubJet_BTagging_Score_",
             "Z_leadjet_dphi_Val_",
             "Z_subjet_dphi_Val_",
             "leadjet_pt_",
             "subjet_pt_",
             "leadjet_pt_frac_",
             "subjet_pt_frac_",
             "Z_pT_",
             "Genb_Jetb_1_",
             "Genb_Jetb_2_",
             "Genb_Jetb_3_",
             "Genb_Jetb_4_",
             "Genb_Jetb_5_",
             "pTlead_over_rest_",
             "pTlead_over_rest_alpha_1_",
             "pTlead_over_rest_alpha_2_",
             "pTlead_over_rest_alpha_3_",
             "pTlead_over_rest_alpha_4_",
             "pTlead_over_rest_alpha_5_",
             #"pTlead_over_rest_all_alpha_1_",
             #"pTlead_over_rest_all_alpha_2_",
             #"pTlead_over_rest_all_alpha_3_",
             #"pTlead_over_rest_all_alpha_4_",
             #"pTlead_over_rest_all_alpha_5_",
#             "Balanced_subjet_frac_",
#             "Unbalanced_subjet_frac_",
#             "All_Balanced_subjet_frac_",
#             "All_Unbalanced_subjet_frac_"
             ]



x_titles = ["M(#mu^{+}#mu^{-})",
            "BTagging Score",
            "BTagging Score",
            "#Delta#phi(Leadjet,Z)",
            "#Delta#phi(Subjet,Z)",
            "Leadjet p_T",
            "Subjet p_T",
            "p_T(LeadJet)/p_T(Z)",
            "p_T(SubJet)/p_T(Z)",
            "Z p_T",
            "p_T(Gen_b)/p_T(Jet_b)",
            "p_T(Gen_b)/p_T(Jet_b)",
            "p_T(Gen_b)/p_T(Jet_b)",
            "p_T(Gen_b)/p_T(Jet_b)",
            "p_T(Gen_b)/p_T(Jet_b)",
            "p_T(lead)/p_T(ll+sub)",
            "p_T(lead)/p_T(ll+sub)",
            "p_T(lead)/p_T(ll+sub)",
            "p_T(lead)/p_T(ll+sub)",
            "p_T(lead)/p_T(ll+sub)",
            "p_T(lead)/p_T(ll+sub)",
#            "p_T(lead)/p_T(ll+sub)",
#            "p_T(lead)/p_T(ll+sub)",
#            "p_T(lead)/p_T(ll+sub)",
#            "p_T(lead)/p_T(ll+sub)",
#            "p_T(lead)/p_T(ll+sub)",
#            "p_T(sub)/p_T(ll)",
#            "p_T(sub)/p_T(ll)",
#            "p_T(sub)/p_T(ll)",
#            "p_T(sub)/p_T(ll)",
            ]
x_min = [70., #Z Mass
         0.,  #Lead B Score
         0.,  #Sub B Score
         0.,  #Lead dphi
         0.,  #Sub dphi
         0.,  #Lead PT
         0.,  #Sub PT
         0.,  #Lead PT frac
         0.,  #Sub PT frac
         0.,  #Z PT
         0.,  #Gen / Jet b
         0.,  #Gen / Jet b
         0.,  #Gen / Jet b
         0.,  #Gen / Jet b
         0.,  #Gen / Jet b
         0.,   #lead jet pt / (Z) pt
         0.,   #lead jet pt / (Z) pt
         0.,   #lead jet pt / (Z) pt
         0.,   #lead jet pt / (Z) pt
         0.,   #lead jet pt / (Z) pt
         0.,   #lead jet pt / (Z) pt
#         0.,   #lead jet pt / (Z+subjet) pt
#         0.,   #lead jet pt / (Z+subjet) pt
#         0.,   #lead jet pt / (Z+subjet) pt
#         0.,   #lead jet pt / (Z+subjet) pt
#         0.,   #lead jet pt / (Z+subjet) pt
#         0.,   #sub jet pt / (Z) pt
#         0.,   #sub jet pt / (Z) pt
#         0.,   #sub jet pt / (Z) pt
#         0.   #sub jet pt / (Z) pt
         ] 
x_max = [110., #Z Mass
         1.,  #Lead B Score
         1.,  #Sub B Score
         3.2,  #Lead dphi
         3.2,  #Sub dphi
         200.,  #Lead PT
         200.,  #Sub PT
         1.,  #Lead PT frac
         1.,  #Sub PT frac
         200.,   #Z PT
         2.,   #Gen pt / Jet pt
         2.,   #Gen pt / Jet pt
         2.,   #Gen pt / Jet pt
         2.,   #Gen pt / Jet pt
         2.,   #Gen pt / Jet pt
         2.,   #lead jet pt / (Z) pt
         2.,   #lead jet pt / (Z) pt
         2.,   #lead jet pt / (Z) pt
         2.,   #lead jet pt / (Z) pt
         2.,   #lead jet pt / (Z) pt
         2.,   #lead jet pt / (Z) pt
#         2.,   #lead jet pt / (Z+subjet) pt
#         2.,   #lead jet pt / (Z+subjet) pt
#         2.,   #lead jet pt / (Z+subjet) pt
#         2.,   #lead jet pt / (Z+subjet) pt
#         2.,   #lead jet pt / (Z+subjet) pt
#         2.,   #sub jet pt / (Z) pt
#         2.,   #sub jet pt / (Z) pt
#         2.,   #sub jet pt / (Z) pt
#         2.   #sub jet pt / (Z) pt
         ] 
MCs = ["TTLL_powheg",
#       "TTLJ_powheg", 
#       "DYJets_MG",
#       "DYJets_MG_HT-70toinf",
       "DYJets_MG_HT-70to100",
       "DYJets_MG_HT-100to200",
       "DYJets_MG_HT-200to400",
       "DYJets_MG_HT-400to600",
       "DYJets_MG_HT-600to800",
       "DYJets_MG_HT-800to1200",
       "DYJets_MG_HT-1200to2500",
       "DYJets_MG_HT-2500toInf",
       "SingleTop_tW_antitop_NoFullyHad",
       "SingleTop_tW_top_NoFullyHad",
       "SingleTop_sch_Lep",
       "WW_pythia",
       "ZZ_pythia",
       "WZ_pythia"
         ]

# set plotting parameters
info_params = {"info": "L^{int} = 41.5 fb^{-1}",
               "cms_text": "CMS",
               "extra_text": "Work in progress"
              }

# get histograms
def get_hist(sample, histkey, syst, data_name,year,BREG_FLAG_TEMP):
	fkey=""
	if BREG_FLAG_TEMP == 1:
		if "DoubleMuon" in data_name:
			if sample == "data":
				fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Mu_BReg/"+year+"/BReg_20_RunSyst__/DATA/Vcb_BJetRegression_Mu_BReg_%s.root" %data_name
			elif syst == 0:
				fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Mu_BReg/"+year+"/BReg_20_RunSyst__/Vcb_BJetRegression_Mu_BReg_%s.root" %sample
			else:
				fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Mu_BReg/"+year+"/BReg_20_RunSyst__/Vcb_BJetRegression_Mu_BReg_%s.root" %sample
		
		if "EG" in data_name:
			if sample == "data":
				fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_El_BReg/"+year+"/BReg_20_RunSyst__/DATA/Vcb_BJetRegression_El_BReg_%s.root" %data_name
			elif syst == 0:
				fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_El_BReg/"+year+"/BReg_20_RunSyst__/Vcb_BJetRegression_El_BReg_%s.root" %sample
			else:
				fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_El_BReg/"+year+"/BReg_20_RunSyst__/Vcb_BJetRegression_El_BReg_%s.root" %sample
	if BREG_FLAG_TEMP == 0:
		if "DoubleMuon" in data_name:
			if sample == "data":
				fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Mu/"+year+"/no_BReg_20_RunSyst__/DATA/Vcb_BJetRegression_Mu_%s.root" %data_name
			elif syst == 0:
				fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Mu/"+year+"/no_BReg_20_RunSyst__/Vcb_BJetRegression_Mu_%s.root" %sample
			else:
				fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Mu/"+year+"/no_BReg_20_RunSyst__/Vcb_BJetRegression_Mu_%s.root" %sample
		
		if "EG" in data_name:
			if sample == "data":
				fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_El/"+year+"/no_BReg_20_RunSyst__/DATA/Vcb_BJetRegression_El_%s.root" %data_name
			elif syst == 0:
				fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_El/"+year+"/no_BReg_20_RunSyst__/Vcb_BJetRegression_El_%s.root" %sample
			else:
				fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_El/"+year+"/no_BReg_20_RunSyst__/Vcb_BJetRegression_El_%s.root" %sample
	f = TFile.Open(fkey)
	h = f.Get(histkey)
	h.SetDirectory(0)
	return h
alpha_mean = [[],[],[],[],[],[]]
alpha_error = [[],[],[],[],[],[]]
alpha_sigma = [[],[],[],[],[],[]]
alpha_sig_error = [[],[],[],[],[],[]]
All_alpha_mean = [[],[],[],[],[],[]]
All_alpha_error = [[],[],[],[],[],[]]
All_alpha_sigma = [[],[],[],[],[],[]]
All_alpha_sig_error = [[],[],[],[],[],[]]
res_mean = [[],[],[],[],[],[]]
res_error = [[],[],[],[],[],[]]
res_sigma = [[],[],[],[],[],[]]
res_sig_error = [[],[],[],[],[],[]]
mean_c=-999
if run_year == "2018":
	DATASTREAMs = ["DoubleMuon","EGamma"]
else:
	DATASTREAMs = ["DoubleMuon","DoubleEG"]

Centrals = ["POGTightWithTightIso_Central","passMVAID_iso_WP80_Central"]
UPs = ["POGTightWithTightIso_Syst_JetEnUp","passMVAID_iso_WP80_Syst_JetEnUp"]
DOWNs = ["POGTightWithTightIso_Syst_JetEnDown","passMVAID_iso_WP80_Syst_JetEnDown"]


#DATASTREAMs = ["DoubleEG"]
#DATASTREAMs = ["EGamma"]
#DATASTREAMs = ["DoubleMuon"]
#Centrals = ["passMVAID_iso_WP80_Central"]
#UPs = ["passMVAID_iso_WP80_Syst_JetEnUp"]
#DOWNs = ["passMVAID_iso_WP80_Syst_JetEnDown"]
#Centrals = ["POGTightWithTightIso_Central"]
#UPs = ["POGTightWithTightIso_Syst_JetEnUp"]
#DOWNs = ["POGTightWithTightIso_Syst_JetEnDown"]
for i,var in enumerate(variables):
	hist_params = {"x_title": x_titles[i],
	               "x_range": [x_min[i], x_max[i]],
	               "y_title": "Events",
	               "ratio_title": "Data/MC",
	               "ratio_range": [0.5, 1.5],
	               #"rebin" : 5,
	       	       }
	cvs_params = {"logy": False,"grid": False,
#	             "pad_dim": "ratio"
	              "pad_dim": "2by2"
	             }
	h_mc = dict()
	h_un = dict()
	h_dn = dict()
	h_nu = dict()
	h_nd = dict()
	h_uu = dict()
	h_dd = dict()
	h_up = dict()
	h_down = dict()
	for m in range(len(DATASTREAMs)):
		DATASTREAM = DATASTREAMs[m]
		Central = Centrals[m]
		UP = UPs[m]
		DOWN = DOWNs[m]


		datakey_up = UP+"/"+var
		datakey_down = DOWN+"/"+var
		datakey = Central+"/"+var
		systkey_up = UP+"/"+var
		systkey_down = DOWN+"/"+var
		histkey = Central+"/"+var
		print(systkey_up)
#		if var == "ZCand_Mass_" or "pTlead_" in var or "Genb" in var:
#			systkey_up = UP+"/"+var+UP
#			systkey_down = DOWN+"/"+var+DOWN
#			histkey = Central+"/"+var+Central
#		else:
#			systkey_up = UP+"/"+var
#			systkey_down = DOWN+"/"+var
#			histkey = Central+"/"+var
			
	
		if "Genb" not in histkey:
			if m == 0:
				h_data = get_hist("data", datakey,0,DATASTREAM,run_year,BREG_FLAG)
			else:
				add_h_data = get_hist("data", datakey,0,DATASTREAM,run_year,BREG_FLAG)
				h_data.Add(add_h_data,1.0)
		else:
			for mc in MCs:
				if m == 0:
					try:
						h_data = get_hist(mc, histkey+"",0,DATASTREAM,run_year,BREG_FLAG)
					except AttributeError:
						print("MC %s has no data" %mc)
						continue
				else:
					try:
						h_data.Add(get_hist(mc, histkey+"",0,DATASTREAM,run_year,BREG_FLAG),1.0)
					except (AttributeError, KeyError):
						print("MC %s has no data" %mc)
						continue
						
		for mc in MCs:
			if m ==0:
				try:
					h_up[mc] = get_hist(mc, systkey_up+"",1,DATASTREAM,run_year,BREG_FLAG)
				except AttributeError:
					print("MC %s has no data" %mc)
					continue
						
				try:
					h_down[mc] = get_hist(mc, systkey_down+"",-1,DATASTREAM,run_year,BREG_FLAG)
				except AttributeError:
					print("MC %s has no data" %mc)
					continue
				try:
					h_mc[mc] = get_hist(mc, histkey+"",0,DATASTREAM,run_year,BREG_FLAG)
				except AttributeError:
					print("MC %s has no data" %mc)
					continue
				try:
					h_un[mc] = get_hist(mc, histkey+"_un"+"",0,DATASTREAM,run_year,BREG_FLAG)
				except AttributeError:
					print("MC %s has no data" %mc)
					continue
				try:
					h_dn[mc] = get_hist(mc, histkey+"_dn"+"",0,DATASTREAM,run_year,BREG_FLAG)
				except AttributeError:
					print("MC %s has no data" %mc)
					continue
				try:
					h_nu[mc] = get_hist(mc, histkey+"_nu"+"",0,DATASTREAM,run_year,BREG_FLAG)
				except AttributeError:
					print("MC %s has no data" %mc)
					continue
				try:
					h_nd[mc] = get_hist(mc, histkey+"_nd"+"",0,DATASTREAM,run_year,BREG_FLAG)
				except AttributeError:
					print("MC %s has no data" %mc)
					continue
				try:
					h_uu[mc] = get_hist(mc, histkey+"_uu"+"",0,DATASTREAM,run_year,BREG_FLAG)
				except AttributeError:
					print("MC %s has no data" %mc)
					continue
				try:
					h_dd[mc] = get_hist(mc, histkey+"_dd"+"",0,DATASTREAM,run_year,BREG_FLAG)
				except AttributeError:
					print("MC %s has no data" %mc)
					continue
			else:
				try:
					h_up[mc].Add(get_hist(mc, systkey_up+"",1,DATASTREAM,run_year,BREG_FLAG),1.0)
				except (AttributeError, KeyError):
					print("MC %s has no data" %mc)
					continue
						
				try:
					h_down[mc].Add(get_hist(mc, systkey_down+"",-1,DATASTREAM,run_year,BREG_FLAG),1.0)
				except (AttributeError, KeyError):
					print("MC %s has no data" %mc)
					continue
				try:
					h_mc[mc].Add(get_hist(mc, histkey+"",0,DATASTREAM,run_year,BREG_FLAG),1.0)
				except (AttributeError, KeyError):
					print("MC %s has no data" %mc)
					continue
				try:
					h_un[mc].Add(get_hist(mc, histkey+"_un"+"",0,DATASTREAM,run_year,BREG_FLAG),1.0)
				except (AttributeError, KeyError):
					print("MC %s has no data" %mc)
					continue
				try:
					h_dn[mc].Add(get_hist(mc, histkey+"_dn"+"",0,DATASTREAM,run_year,BREG_FLAG),1.0)
				except (AttributeError, KeyError):
					print("MC %s has no data" %mc)
					continue
				try:
					h_nu[mc].Add(get_hist(mc, histkey+"_nu"+"",0,DATASTREAM,run_year,BREG_FLAG),1.0)
				except (AttributeError, KeyError):
					print("MC %s has no data" %mc)
					continue
				try:
					h_nd[mc].Add(get_hist(mc, histkey+"_nd"+"",0,DATASTREAM,run_year,BREG_FLAG),1.0)
				except (AttributeError, KeyError):
					print("MC %s has no data" %mc)
					continue
				try:
					h_uu[mc].Add(get_hist(mc, histkey+"_uu"+"",0,DATASTREAM,run_year,BREG_FLAG),1.0)
				except (AttributeError, KeyError):
					print("MC %s has no data" %mc)
					continue
				try:
					h_dd[mc].Add(get_hist(mc, histkey+"_dd"+"",0,DATASTREAM,run_year,BREG_FLAG),1.0)
				except (AttributeError, KeyError):
					print("MC %s has no data" %mc)
					continue
		if m == len(DATASTREAMs)-1:
			layouts = ["ratio","2by2"]
			for layout in layouts:
				cvs_params = {"logy": False,"grid": False,
						"pad_dim": layout
						}
				plotter = DataAndMC(cvs_params, hist_params, info_params)
				plotter.get_hists(h_data, h_mc, h_up, h_down,h_un,h_dn,h_nu,h_nd,h_uu,h_dd)
				if layout == "2by2":
					if "pTlead" not in var and "Genb" not in var: continue
					mean_c,mean_u,mean_d,mean_o,mean_un ,mean_dn ,mean_nu ,mean_nd ,mean_uu ,mean_dd ,sigma_c,sigma_u,sigma_d,sigma_o,sigma_un ,sigma_dn ,sigma_nu ,sigma_nd ,sigma_uu ,sigma_dd  = plotter.get_fit(range_mult)
					if var == "Genb_Jetb_1_" and mean_c != -999:
						res_mean[0]=[mean_c.getValV()]
						res_error[0]=[mean_c.getError()]
						res_sigma[0]=[sigma_c.getValV()]
						res_sig_error[0]=[sigma_c.getError()]
						plotter.save(f"DataAndMC_{histkey.replace('/', '_')}_Fit.png")
					elif var == "Genb_Jetb_2_" and mean_c != -999:
						res_mean[1]=[mean_c.getValV()]
						res_error[1]=[mean_c.getError()]
						res_sigma[1]=[sigma_c.getValV()]
						res_sig_error[1]=[sigma_c.getError()]
						plotter.save(f"DataAndMC_{histkey.replace('/', '_')}_Fit.png")
					elif var == "Genb_Jetb_3_" and mean_c != -999:
						res_mean[2]=[mean_c.getValV()]
						res_error[2]=[mean_c.getError()]
						res_sigma[2]=[sigma_c.getValV()]
						res_sig_error[2]=[sigma_c.getError()]
						plotter.save(f"DataAndMC_{histkey.replace('/', '_')}_Fit.png")
					elif var == "Genb_Jetb_4_" and mean_c != -999:
						res_mean[3]=[mean_c.getValV()]
						res_error[3]=[mean_c.getError()]
						res_sigma[3]=[sigma_c.getValV()]
						res_sig_error[3]=[sigma_c.getError()]
						plotter.save(f"DataAndMC_{histkey.replace('/', '_')}_Fit.png")
					elif var == "Genb_Jetb_5_" and mean_c != -999:
						res_mean[4]=[mean_c.getValV()]
						res_error[4]=[mean_c.getError()]
						res_sigma[4]=[sigma_c.getValV()]
						res_sig_error[4]=[sigma_c.getError()]
						plotter.save(f"DataAndMC_{histkey.replace('/', '_')}_Fit.png")
					elif var == "pTlead_over_rest_alpha_1_" and mean_c != -999:
						alpha_mean[0]=[mean_c.getValV(),mean_u.getValV(),mean_d.getValV(),mean_o.getValV(),mean_un.getValV(),mean_dn.getValV(),mean_nu.getValV(),mean_nd.getValV(),mean_uu.getValV(),mean_dd.getValV()]
						alpha_error[0]=[mean_c.getError(),mean_u.getError(),mean_d.getError(),mean_o.getError(),mean_un.getError(),mean_dn.getError(),mean_nu.getError(),mean_nd.getError(),mean_uu.getError(),mean_dd.getError()]
						alpha_sigma[0]=[sigma_c.getValV(),sigma_u.getValV(),sigma_d.getValV(),sigma_o.getValV(),sigma_un.getValV(),sigma_dn.getValV(),sigma_nu.getValV(),sigma_nd.getValV(),sigma_uu.getValV(),sigma_dd.getValV()]
						alpha_sig_error[0]=[sigma_c.getError(),sigma_u.getError(),sigma_d.getError(),sigma_o.getError(),sigma_un.getError(),sigma_dn.getError(),sigma_nu.getError(),sigma_nd.getError(),sigma_uu.getError(),sigma_dd.getError()]
						plotter.save(f"DataAndMC_{histkey.replace('/', '_')}_Fit.png",f"DataAndMC_{histkey.replace('/', '_')}_Fit.C")
				
					elif var == "pTlead_over_rest_alpha_2_" and mean_c != -999:
						alpha_mean[1]=[mean_c.getValV(),mean_u.getValV(),mean_d.getValV(),mean_o.getValV(),mean_un.getValV(),mean_dn.getValV(),mean_nu.getValV(),mean_nd.getValV(),mean_uu.getValV(),mean_dd.getValV()]
						alpha_error[1]=[mean_c.getError(),mean_u.getError(),mean_d.getError(),mean_o.getError(),mean_un.getError(),mean_dn.getError(),mean_nu.getError(),mean_nd.getError(),mean_uu.getError(),mean_dd.getError()]
						alpha_sigma[1]=[sigma_c.getValV(),sigma_u.getValV(),sigma_d.getValV(),sigma_o.getValV(),sigma_un.getValV(),sigma_dn.getValV(),sigma_nu.getValV(),sigma_nd.getValV(),sigma_uu.getValV(),sigma_dd.getValV()]
						alpha_sig_error[1]=[sigma_c.getError(),sigma_u.getError(),sigma_d.getError(),sigma_o.getError(),sigma_un.getError(),sigma_dn.getError(),sigma_nu.getError(),sigma_nd.getError(),sigma_uu.getError(),sigma_dd.getError()]
						plotter.save(f"DataAndMC_{histkey.replace('/', '_')}_Fit.png", f"DataAndMC_{histkey.replace('/', '_')}_Fit.C")
		
					elif var == "pTlead_over_rest_alpha_3_" and mean_c != -999:
						alpha_mean[2]=[mean_c.getValV(),mean_u.getValV(),mean_d.getValV(),mean_o.getValV(),mean_un.getValV(),mean_dn.getValV(),mean_nu.getValV(),mean_nd.getValV(),mean_uu.getValV(),mean_dd.getValV()]
						alpha_error[2]=[mean_c.getError(),mean_u.getError(),mean_d.getError(),mean_o.getError(),mean_un.getError(),mean_dn.getError(),mean_nu.getError(),mean_nd.getError(),mean_uu.getError(),mean_dd.getError()]
						alpha_sigma[2]=[sigma_c.getValV(),sigma_u.getValV(),sigma_d.getValV(),sigma_o.getValV(),sigma_un.getValV(),sigma_dn.getValV(),sigma_nu.getValV(),sigma_nd.getValV(),sigma_uu.getValV(),sigma_dd.getValV()]
						alpha_sig_error[2]=[sigma_c.getError(),sigma_u.getError(),sigma_d.getError(),sigma_o.getError(),sigma_un.getError(),sigma_dn.getError(),sigma_nu.getError(),sigma_nd.getError(),sigma_uu.getError(),sigma_dd.getError()]
						plotter.save(f"DataAndMC_{histkey.replace('/', '_')}_Fit.png", f"DataAndMC_{histkey.replace('/', '_')}_Fit.C")

					elif var == "pTlead_over_rest_alpha_4_" and mean_c != -999:
						alpha_mean[3]=[mean_c.getValV(),mean_u.getValV(),mean_d.getValV(),mean_o.getValV(),mean_un.getValV(),mean_dn.getValV(),mean_nu.getValV(),mean_nd.getValV(),mean_uu.getValV(),mean_dd.getValV()]
						alpha_error[3]=[mean_c.getError(),mean_u.getError(),mean_d.getError(),mean_o.getError(),mean_un.getError(),mean_dn.getError(),mean_nu.getError(),mean_nd.getError(),mean_uu.getError(),mean_dd.getError()]
						alpha_sigma[3]=[sigma_c.getValV(),sigma_u.getValV(),sigma_d.getValV(),sigma_o.getValV(),sigma_un.getValV(),sigma_dn.getValV(),sigma_nu.getValV(),sigma_nd.getValV(),sigma_uu.getValV(),sigma_dd.getValV()]
						alpha_sig_error[3]=[sigma_c.getError(),sigma_u.getError(),sigma_d.getError(),sigma_o.getError(),sigma_un.getError(),sigma_dn.getError(),sigma_nu.getError(),sigma_nd.getError(),sigma_uu.getError(),sigma_dd.getError()]
						plotter.save(f"DataAndMC_{histkey.replace('/', '_')}_Fit.png", f"DataAndMC_{histkey.replace('/', '_')}_Fit.C")
					elif var == "pTlead_over_rest_alpha_5_" and mean_c != -999:
						alpha_mean[4]=[mean_c.getValV(),mean_u.getValV(),mean_d.getValV(),mean_o.getValV(),mean_un.getValV(),mean_dn.getValV(),mean_nu.getValV(),mean_nd.getValV(),mean_uu.getValV(),mean_dd.getValV()]
						alpha_error[4]=[mean_c.getError(),mean_u.getError(),mean_d.getError(),mean_o.getError(),mean_un.getError(),mean_dn.getError(),mean_nu.getError(),mean_nd.getError(),mean_uu.getError(),mean_dd.getError()]
						alpha_sigma[4]=[sigma_c.getValV(),sigma_u.getValV(),sigma_d.getValV(),sigma_o.getValV(),sigma_un.getValV(),sigma_dn.getValV(),sigma_nu.getValV(),sigma_nd.getValV(),sigma_uu.getValV(),sigma_dd.getValV()]
						alpha_sig_error[4]=[sigma_c.getError(),sigma_u.getError(),sigma_d.getError(),sigma_o.getError(),sigma_un.getError(),sigma_dn.getError(),sigma_nu.getError(),sigma_nd.getError(),sigma_uu.getError(),sigma_dd.getError()]
						plotter.save(f"DataAndMC_{histkey.replace('/', '_')}_Fit.png", f"DataAndMC_{histkey.replace('/', '_')}_Fit.C")
					elif var == "pTlead_over_rest_" and mean_c != -999:
						alpha_mean[5]=[mean_c.getValV(),mean_u.getValV(),mean_d.getValV(),mean_o.getValV(),mean_un.getValV(),mean_dn.getValV(),mean_nu.getValV(),mean_nd.getValV(),mean_uu.getValV(),mean_dd.getValV()]
						alpha_error[5]=[mean_c.getError(),mean_u.getError(),mean_d.getError(),mean_o.getError(),mean_un.getError(),mean_dn.getError(),mean_nu.getError(),mean_nd.getError(),mean_uu.getError(),mean_dd.getError()]
						alpha_sigma[5]=[sigma_c.getValV(),sigma_u.getValV(),sigma_d.getValV(),sigma_o.getValV(),sigma_un.getValV(),sigma_dn.getValV(),sigma_nu.getValV(),sigma_nd.getValV(),sigma_uu.getValV(),sigma_dd.getValV()]
						alpha_sig_error[5]=[sigma_c.getError(),sigma_u.getError(),sigma_d.getError(),sigma_o.getError(),sigma_un.getError(),sigma_dn.getError(),sigma_nu.getError(),sigma_nd.getError(),sigma_uu.getError(),sigma_dd.getError()]
						plotter.save(f"DataAndMC_{histkey.replace('/', '_')}_Fit.png")
				elif layout == "ratio":
					plotter.combine()
					plotter.save(f"DataAndMC_{histkey.replace('/', '_')}.png")
fitting_plots(alpha_mean,alpha_error,alpha_sigma,alpha_sig_error,res_mean,res_error,res_sigma,res_sig_error,alpha_mean[0][0],"Only_Z",setting,run_year,scale_variation)
#fitting_plots(All_alpha_mean,All_alpha_error,All_alpha_sigma,All_alpha_sig_error,res_mean,res_error,res_sigma,res_sig_error,All_alpha_mean[0][0],"All",setting,run_year,scale_variation)
