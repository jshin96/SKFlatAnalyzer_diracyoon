import sys
#sys.path.remove('/opt/ohpc/pub/apps/root_6_12_06/lib')
import ROOT 
from ROOT import TFile
from Plotter.DataAndMC import DataAndMC
import array
# NOTE: This script use pyROOT with python version >= 3.6 because of f-strings
# If you want to use lower python version, change f"...{var}" to "...{}".format(var)
# In the tamsa server, setting an environment with CMSSW_11_* will be sufficient

# set global variables

variables = ["ZCand_Mass_",
             "LeadJet_BTagging_Score_",
             "Z_leadjet_dphi_Val_",
             "leadjet_pt_",
             "leadjet_pt_frac_",
             "pTlead_over_rest_",
             "pTlead_over_rest_alpha_0_",
             "pTlead_over_rest_alpha_1_",
             "pTlead_over_rest_alpha_2_",
             "pTlead_over_rest_alpha_3_",
             "pTlead_over_rest_alpha_4_",
             "pTlead_over_rest_alpha_5_",
             "Z_pT_"
             ]
combine_variables = [
             "pTlead_over_rest_alpha_6_",
             "pTlead_over_rest_alpha_7_",
             "pTlead_over_rest_alpha_8_",
             "pTlead_over_rest_alpha_9_"
		]


x_titles = ["M(#mu^{+}#mu^{-})",
            "BTagging Score",
            "#Delta#phi(Leadjet,Z)",
            "Leadjet p_T",
            "p_T(LeadJet)/p_T(Z)",
            "p_T(lead)/p_T(ll+sub)",
            "p_T(lead)/p_T(ll+sub)",
            "p_T(lead)/p_T(ll+sub)",
            "p_T(lead)/p_T(ll+sub)",
            "p_T(lead)/p_T(ll+sub)",
            "p_T(lead)/p_T(ll+sub)",
            "p_T(lead)/p_T(ll+sub)",
            "Z p_T"
            ]
combine_x_titles = ["p_T(lead)/p_T(ll+sub)",
            "p_T(lead)/p_T(ll+sub)",
            "p_T(lead)/p_T(ll+sub)",
            "p_T(lead)/p_T(ll+sub)"
		]
combine_x_min = [0.,   #lead jet pt / (Z+subjet) pt
         0.,   #lead jet pt / (Z+subjet) pt
         0.,   #lead jet pt / (Z+subjet) pt
         0.   #lead jet pt / (Z+subjet) pt
	]
x_min = [70., #Z Mass
         0.,  #Lead B Score
         0.,  #Lead dphi
         0.,  #Lead PT
         0.,  #Lead PT frac
         0.,   #lead jet pt / (Z+subjet) pt
         0.,   #lead jet pt / (Z+subjet) pt
         0.,   #lead jet pt / (Z+subjet) pt
         0.,   #lead jet pt / (Z+subjet) pt
         0.,   #lead jet pt / (Z+subjet) pt
         0.,   #lead jet pt / (Z+subjet) pt
         0.,   #lead jet pt / (Z+subjet) pt
         0.  #Z PT
         ] 
combine_x_max = [2.,   #lead jet pt / (Z+subjet) pt
         2.,   #lead jet pt / (Z+subjet) pt
         2.,   #lead jet pt / (Z+subjet) pt
         2.   #lead jet pt / (Z+subjet) pt
	]
x_max = [110., #Z Mass
         1.,  #Lead B Score
         3.2,  #Lead dphi
         200.,  #Lead PT
         1.,  #Lead PT frac
         2.,   #lead jet pt / (Z+subjet) pt
         2.,   #lead jet pt / (Z+subjet) pt
         2.,   #lead jet pt / (Z+subjet) pt
         2.,   #lead jet pt / (Z+subjet) pt
         2.,   #lead jet pt / (Z+subjet) pt
         2.,   #lead jet pt / (Z+subjet) pt
         2.,   #lead jet pt / (Z+subjet) pt
         200.   #Z PT
         ] 
DATASTREAMs = ["DoubleMuon","EGamma"]
#DATASTREAMs = ["DoubleMuon"]
MCs = ["TTLL_powheg", 
       "TTLJ_powheg",
#       "DYBJets_MG_HT-100to200",
#       "DYBJets_MG_HT-200toinf",
       "DYJets_MG",
       "SingleTop_tW_antitop_NoFullyHad",
       "SingleTop_tW_top_NoFullyHad",
       "WW_pythia",
       "ZZ_pythia",
       "WZ_pythia"]

# set plotting parameters
info_params = {"info": "L^{int} = 41.5 fb^{-1}",
               "cms_text": "CMS",
               "extra_text": "Work in progress"
              }

# get histograms
def get_hist(sample, histkey, syst, data_name):
	fkey=""
	'''
	if "DoubleMuon" in data_name:
		if sample == "data":
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_Mu/2018/BReg_low_pt_RunSyst__/DATA/Vcb_BJetRegression_Single_Mu_{DATASTREAM}.root"
		elif syst == 0:
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_Mu/2018/BReg_low_pt_RunSyst__/Vcb_BJetRegression_Single_Mu_{sample}.root"
		else:
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_Mu/2018/BReg_low_pt_RunSyst__/Vcb_BJetRegression_Single_Mu_{sample}.root"
	
	if "Gamma" in data_name:
		if sample == "data":
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_El/2018/BReg_low_pt_RunSyst__/DATA/Vcb_BJetRegression_Single_El_{DATASTREAM}.root"
		elif syst == 0:
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_El/2018/BReg_low_pt_RunSyst__/Vcb_BJetRegression_Single_El_{sample}.root"
		else:
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_El/2018/BReg_low_pt_RunSyst__/Vcb_BJetRegression_Single_El_{sample}.root"
	'''
	'''
	if "DoubleMuon" in data_name:
		if sample == "data":
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_Mu/2018/BReg_high_pt_RunSyst__/DATA/Vcb_BJetRegression_Single_Mu_{DATASTREAM}.root"
		elif syst == 0:
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_Mu/2018/BReg_high_pt_RunSyst__/Vcb_BJetRegression_Single_Mu_{sample}.root"
		else:
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_Mu/2018/BReg_high_pt_RunSyst__/Vcb_BJetRegression_Single_Mu_{sample}.root"
	
	if "Gamma" in data_name:
		if sample == "data":
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_El/2018/BReg_high_pt_RunSyst__/DATA/Vcb_BJetRegression_Single_El_{DATASTREAM}.root"
		elif syst == 0:
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_El/2018/BReg_high_pt_RunSyst__/Vcb_BJetRegression_Single_El_{sample}.root"
		else:
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_El/2018/BReg_high_pt_RunSyst__/Vcb_BJetRegression_Single_El_{sample}.root"
	'''	
	
	if "DoubleMuon" in data_name:
		if sample == "data":
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_Mu/2018/low_pt_RunSyst__/DATA/Vcb_BJetRegression_Single_Mu_{DATASTREAM}.root"
		elif syst == 0:
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_Mu/2018/low_pt_RunSyst__/Vcb_BJetRegression_Single_Mu_{sample}.root"
		else:
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_Mu/2018/low_pt_RunSyst__/Vcb_BJetRegression_Single_Mu_{sample}.root"
	
	if "Gamma" in data_name:
		if sample == "data":
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_El/2018/low_pt_RunSyst__/DATA/Vcb_BJetRegression_Single_El_{DATASTREAM}.root"
		elif syst == 0:
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_El/2018/low_pt_RunSyst__/Vcb_BJetRegression_Single_El_{sample}.root"
		else:
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_El/2018/low_pt_RunSyst__/Vcb_BJetRegression_Single_El_{sample}.root"
	
	'''
	if "DoubleMuon" in data_name:
		if sample == "data":
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_Mu/2018/high_pt_RunSyst__/DATA/Vcb_BJetRegression_Single_Mu_{DATASTREAM}.root"
		elif syst == 0:
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_Mu/2018/high_pt_RunSyst__/Vcb_BJetRegression_Single_Mu_{sample}.root"
		else:
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_Mu/2018/high_pt_RunSyst__/Vcb_BJetRegression_Single_Mu_{sample}.root"
	
	if "Gamma" in data_name:
		if sample == "data":
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_El/2018/high_pt_RunSyst__/DATA/Vcb_BJetRegression_Single_El_{DATASTREAM}.root"
		elif syst == 0:
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_El/2018/high_pt_RunSyst__/Vcb_BJetRegression_Single_El_{sample}.root"
		else:
			fkey = f"/data6/Users/shin/SKFlatOutput/Run2UltraLegacy_v3/Vcb_BJetRegression_Single_El/2018/high_pt_RunSyst__/Vcb_BJetRegression_Single_El_{sample}.root"	
	'''

	f = TFile.Open(fkey)
	h = f.Get(histkey)
	h.SetDirectory(0)
	return h
NBINS=7
alpha_mean =      []
res_mean =        []
alpha_error =     []
res_error =       []
alpha_sigma =     []
res_sigma =       []
alpha_sig_error = []
res_sig_error =   []
for k in range(NBINS):
	alpha_mean.append([])
	res_mean.append([])
	alpha_error.append([])
	res_error.append([])
	alpha_sigma.append([])
	res_sigma.append([])
	alpha_sig_error.append([])
	res_sig_error.append([])
#alpha_mean =      [[],[],[],[],[],[],[]]
#res_mean =        [[],[],[],[],[],[],[]]
#alpha_error =     [[],[],[],[],[],[],[]]
#res_error =       [[],[],[],[],[],[],[]]
#alpha_sigma =     [[],[],[],[],[],[],[]]
#res_sigma =       [[],[],[],[],[],[],[]]
#alpha_sig_error = [[],[],[],[],[],[],[]]
#res_sig_error =   [[],[],[],[],[],[],[]]
mean_c=-999
Centrals = ["POGTightWithTightIso_Central","passLooseID_Central"]
UPs = ["POGTightWithTightIso_Syst_JetEnUp","passLooseID_Syst_JetEnUp"]
DOWNs = ["POGTightWithTightIso_Syst_JetEnDown","passLooseID_Syst_JetEnDown"]
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
	h_mc = dict()
	h_up = dict()
	h_down = dict()
	for m in range(len(DATASTREAMs)):
		DATASTREAM = DATASTREAMs[m]
		Central = Centrals[m]
		UP = UPs[m]
		DOWN = DOWNs[m]
#		if var != "pTlead_over_rest_": continue
		if "pTlead" not in var and "Genb" not in var: continue
#		if "pTlead" in var or "Genb" in var: continue
		if var == "ZCand_Mass_" or "pTlead_" in var or "Genb" in var:
			systkey_up = UP+"/"+var+UP
			systkey_down = DOWN+"/"+var+DOWN
			histkey = Central+"/"+var+Central
		else:
			systkey_up = UP+"/"+var
			systkey_down = DOWN+"/"+var
			histkey = Central+"/"+var
			

#		print("running: %s" %histkey)
		if "Genb" not in histkey:
			if m == 0:
				h_data = get_hist("data", histkey,0,DATASTREAM)
			else:
				add_h_data = get_hist("data", histkey,0,DATASTREAM)
				h_data.Add(add_h_data,1.0)
		else:
			if m == 0:
				try:
					h_data = get_hist(mc, histkey,0,DATASTREAM)
				except AttributeError:
					print("MC %s has no data" %mc)
				
			else:
				try:
					add_h_data = get_hist(mc, histkey,0,DATASTREAM)
					h_data.Add(add_h_data,1.0)
				except AttributeError:
					print("MC %s has no data" %mc)
						
		for mc in MCs:
			if m ==0:
				try:
					h_up[mc] = get_hist(mc, systkey_up,1,DATASTREAM)
				except AttributeError:
					print("MC %s has no data" %mc)
					continue
						
				try:
					h_down[mc] = get_hist(mc, systkey_down,-1,DATASTREAM)
				except AttributeError:
					print("MC %s has no data" %mc)
					continue
				try:
					h_mc[mc] = get_hist(mc, histkey,0,DATASTREAM)
				except AttributeError:
					print("MC %s has no data" %mc)
					continue
			else:
				try:
					h_up[mc].Add(get_hist(mc, systkey_up,1,DATASTREAM),1.0)
				except (AttributeError, KeyError):
					print("MC %s has no data" %mc)
					continue
						
				try:
					h_down[mc].Add(get_hist(mc, systkey_down,-1,DATASTREAM),1.0)
				except (AttributeError, KeyError):
					print("MC %s has no data" %mc)
					continue
				try:
					h_mc[mc].Add(get_hist(mc, histkey,0,DATASTREAM),1.0)
				except (AttributeError, KeyError):
					print("MC %s has no data" %mc)
					continue
		layouts = ["ratio","2by2"]
		for layout in layouts:
			cvs_params = {"logy": False,"grid": False,
		       	     "pad_dim": layout
		       		 }
			plotter = DataAndMC(cvs_params, hist_params, info_params)
			plotter.get_hists(h_data, h_mc, h_up, h_down)
		

			if m == len(DATASTREAMs)-1:
				if layout == "2by2":
					mean_c,mean_u,mean_d,mean_o,sigma_c,sigma_u,sigma_d,sigma_o = plotter.get_fit()
					if "Genb_Jetb" in var:
						for t in range(NBINS-1):
							if str(t) in var and mean_c != -999:
								res_mean[t]=[mean_c.getValV()]
								res_error[t]=[mean_c.getError()]
								res_sigma[t]=[sigma_c.getValV()]
								res_sig_error[t]=[sigma_c.getError()]
								plotter.save(f"DataAndMC_{histkey.replace('/', '_')}_%i_Fit.png" %t)
					elif "pTlead_over_rest_alpha_" in var:
						for t in range(NBINS-1):
							if str(t) in var and mean_c != -999:
								alpha_mean[t]=[mean_c.getValV(),mean_u.getValV(),mean_d.getValV(),mean_o.getValV()]
								alpha_error[t]=[mean_c.getError(),mean_u.getError(),mean_d.getError(),mean_o.getError()]
								alpha_sigma[t]=[sigma_c.getValV(),sigma_u.getValV(),sigma_d.getValV(),sigma_o.getValV()]
								alpha_sig_error[t]=[sigma_c.getError(),sigma_u.getError(),sigma_d.getError(),sigma_o.getError()]
								plotter.save(f"DataAndMC_{histkey.replace('/', '_')}_%i_Fit.png" %t)
			
				elif layout == "ratio":
					plotter.combine()
					plotter.save(f"DataAndMC_{histkey.replace('/', '_')}.png")

h_mc = dict()
h_up = dict()
h_down = dict()
not_empty_DATA=0
not_empty_MC=0
for i,var in enumerate(combine_variables):
	hist_params = {"x_title": combine_x_titles[i],
	               "x_range": [combine_x_min[i], combine_x_max[i]],
	               "y_title": "Events",
	               "ratio_title": "Data/MC",
	               "ratio_range": [0.5, 1.5],
	               #"rebin" : 5,
	       	       }
	for m in range(len(DATASTREAMs)):
		DATASTREAM = DATASTREAMs[m]
		Central = Centrals[m]
		UP = UPs[m]
		DOWN = DOWNs[m]
#		if "pTlead" not in var and "Genb" not in var: continue
#		if "pTlead" in var or "Genb" in var: continue
		if var == "ZCand_Mass_" or "pTlead_" in var or "Genb" in var:
			systkey_up = UP+"/"+var+UP
			systkey_down = DOWN+"/"+var+DOWN
			histkey = Central+"/"+var+Central
		else:
			systkey_up = UP+"/"+var
			systkey_down = DOWN+"/"+var
			histkey = Central+"/"+var
			
		if not_empty_DATA == 0:
			h_data = get_hist("data", histkey,0,DATASTREAM)
			not_empty_DATA = 1
		else:
			add_h_data = get_hist("data", histkey,0,DATASTREAM)
			h_data.Add(add_h_data,1.0)
		for mc in MCs:
			if not_empty_MC == 0:
				try:
					h_up[mc] = get_hist(mc, systkey_up,1,DATASTREAM)
					not_empty_MC == 1
				except AttributeError:
					print("MC %s has no data" %mc)
					continue
					
				try:
					h_down[mc] = get_hist(mc, systkey_down,-1,DATASTREAM)
					not_empty_MC == 1
				except AttributeError:
					print("MC %s has no data" %mc)
					continue
				try:
					h_mc[mc] = get_hist(mc, histkey,0,DATASTREAM)
					not_empty_MC == 1
				except AttributeError:
					print("MC %s has no data" %mc)
					continue
			else:
				try:
					h_up[mc].Add(get_hist(mc, systkey_up,1,DATASTREAM),1.0)
				except (AttributeError, KeyError):
					print("MC %s has no data" %mc)
					continue
					
				try:
					h_down[mc].Add(get_hist(mc, systkey_down,-1,DATASTREAM),1.0)
				except (AttributeError, KeyError):
					print("MC %s has no data" %mc)
					continue
				try:
					h_mc[mc].Add(get_hist(mc, histkey,0,DATASTREAM),1.0)
				except (AttributeError, KeyError):
					print("MC %s has no data" %mc)
					continue
layouts = ["ratio","2by2"]
t="last"

for layout in layouts:
	cvs_params = {"logy": False,"grid": False,
			"pad_dim": layout
			}
	plotter = DataAndMC(cvs_params, hist_params, info_params)
	plotter.get_hists(h_data, h_mc, h_up, h_down)
		

	if layout == "2by2":
		mean_c,mean_u,mean_d,mean_o,sigma_c,sigma_u,sigma_d,sigma_o = plotter.get_fit()
#		if "Genb_Jetb" in var:
#				if mean_c != -999:
#					res_mean[-1]=[mean_c.getValV()]
#					res_error[-1]=[mean_c.getError()]
#					res_sigma[-1]=[sigma_c.getValV()]
#					res_sig_error[-1]=[sigma_c.getError()]
#					plotter.save(f"DataAndMC_{histkey.replace('/', '_')}_%i_Fit.png" %t+1)
#		elif "pTlead_over_rest_alpha_" in var:
		if mean_c != -999:
			alpha_mean[-1]=[mean_c.getValV(),mean_u.getValV(),mean_d.getValV(),mean_o.getValV()]
			alpha_error[-1]=[mean_c.getError(),mean_u.getError(),mean_d.getError(),mean_o.getError()]
			alpha_sigma[-1]=[sigma_c.getValV(),sigma_u.getValV(),sigma_d.getValV(),sigma_o.getValV()]
			alpha_sig_error[-1]=[sigma_c.getError(),sigma_u.getError(),sigma_d.getError(),sigma_o.getError()]
			plotter.save(f"DataAndMC_{histkey.replace('/', '_')}_%s_Fit.png" %t)
			
	elif layout == "ratio":
		plotter.combine()
		plotter.save(f"DataAndMC_{histkey.replace('/', '_')}.png")

if mean_c != -999:
#	binnings = [20,40,60,80,100,140,180,220,260,300,400]
	binnings = [20,40,60,80,100,140,180,400]
	binning = array.array('d',binnings)
	central_hist = ROOT.TH1F("central","central",NBINS,binning)
#	res_hist = ROOT.TH1F("resolution","resolution",10,binning)
	up_hist = ROOT.TH1F("up","up",NBINS,binning)
	down_hist = ROOT.TH1F("down","down",NBINS,binning)
	data_hist = ROOT.TH1F("data","data",NBINS,binning)
	central_hist.SetLineColor(ROOT.kRed)
	central_hist.SetLineWidth(2)
	central_hist.SetStats(0)
	up_hist.SetLineColor(ROOT.kBlue)
	up_hist.SetLineWidth(0)
	up_hist.SetStats(0)
	down_hist.SetLineColor(ROOT.kCyan)
	down_hist.SetLineWidth(0)
	down_hist.SetStats(0)
	data_hist.SetLineColor(ROOT.kBlack)
	data_hist.SetLineWidth(2)
	data_hist.SetStats(0)
	central_sigma = ROOT.TH1F("mean_central","Sigma",NBINS,binning)
#	res_sigma = ROOT.TH1F("mean_res","sigma res",10,binning)
	up_sigma = ROOT.TH1F("mean_up","sigma up",NBINS,binning)
	down_sigma = ROOT.TH1F("mean_down","sigma down",NBINS,binning)
	data_sigma = ROOT.TH1F("mean_data","sigma data",NBINS,binning)
	central_sigma.SetLineColor(ROOT.kRed)
	central_sigma.SetLineWidth(2)
	central_sigma.SetStats(0)
	up_sigma.SetLineColor(ROOT.kBlue)
	up_sigma.SetLineWidth(0)
	up_sigma.SetStats(0)
	down_sigma.SetLineColor(ROOT.kCyan)
	down_sigma.SetLineWidth(0)
	down_sigma.SetStats(0)
	data_sigma.SetLineColor(ROOT.kBlack)
	data_sigma.SetLineWidth(2)
	data_sigma.SetStats(0)
	central_mean_hist = ROOT.TH1F("mean_central","Mean",NBINS,binning)
#	res_mean_hist = ROOT.TH1F("mean_res","sigma res",10,binning)
	up_mean_hist = ROOT.TH1F("mean_up","mean up",NBINS,binning)
	down_mean_hist = ROOT.TH1F("mean_down","mean down",NBINS,binning)
	data_mean_hist = ROOT.TH1F("mean_data","mean data",NBINS,binning)
	central_mean_hist.SetLineColor(ROOT.kRed)
	central_mean_hist.SetLineWidth(2)
	central_mean_hist.SetStats(0)
	up_mean_hist.SetLineColor(ROOT.kBlue)
	up_mean_hist.SetLineWidth(0)
	up_mean_hist.SetStats(0)
	down_mean_hist.SetLineColor(ROOT.kCyan)
	down_mean_hist.SetLineWidth(0)
	down_mean_hist.SetStats(0)
	data_mean_hist.SetLineColor(ROOT.kBlack)
	data_mean_hist.SetLineWidth(2)
	data_mean_hist.SetStats(0)


	for i in range(NBINS):
#		res_mean_hist.SetBinContent(i+1,alpha_mean[i][0])
#		res_mean_hist.SetBinError(i+1,alpha_error[i][0])
#		res_hist.SetBinContent(i+1,res_sigma[i][0])
#		res_hist.SetBinError(i+1,res_sig_error[i][0])
		central_mean_hist.SetBinContent(i+1,alpha_mean[i][0])
		central_mean_hist.SetBinError(i+1,alpha_error[i][0])
		up_mean_hist.SetBinContent(i+1,alpha_mean[i][0])
		up_mean_hist.SetBinError(i+1,alpha_error[i][0])
		down_mean_hist.SetBinContent(i+1,alpha_mean[i][0])
		down_mean_hist.SetBinError(i+1,alpha_error[i][0])
		data_mean_hist.SetBinContent(i+1,alpha_mean[i][3])
		data_mean_hist.SetBinError(i+1,alpha_error[i][3])
		central_sigma.SetBinContent(i+1,alpha_sigma[i][0])
		central_sigma.SetBinError(i+1,alpha_sig_error[i][0])
		data_sigma.SetBinContent(i+1,alpha_sigma[i][3])
		data_sigma.SetBinError(i+1,alpha_sig_error[i][3])
		up_sigma.SetBinContent(i+1,alpha_sigma[i][1])
		up_sigma.SetBinError(i+1,alpha_sig_error[i][1])
		down_sigma.SetBinContent(i+1,alpha_sigma[i][2])
		down_sigma.SetBinError(i+1,alpha_sig_error[i][2])
	central_hist=central_sigma.Clone("Resolution")
	data_hist=data_sigma.Clone("Data")
	up_hist=up_sigma.Clone("Up")
	down_hist=down_sigma.Clone("Down")


	
	legend = ROOT.TLegend(0.65, 0.70, 0.93, 0.87)
	legend.SetFillStyle(0)
	legend.SetTextSize(0.02)
	legend.AddEntry(data_hist,"Data")
	legend.AddEntry(central_hist,"Central")
	legend.AddEntry(up_hist,"JEC up")
	legend.AddEntry(down_hist,"JEC down")
	central_mean_hist.SetMarkerColor(ROOT.kRed)
	central_mean_hist.SetMarkerStyle(ROOT.kFullCircle)
	central_hist.SetMarkerColor(ROOT.kRed)
	central_hist.SetMarkerStyle(ROOT.kFullCircle)
	data_mean_hist.SetMarkerColor(ROOT.kBlack)
	data_mean_hist.SetMarkerStyle(ROOT.kFullCircle)
	data_hist.SetMarkerColor(ROOT.kBlack)
	data_hist.SetMarkerStyle(ROOT.kFullCircle)
	data_mean_hist.SetLineWidth(2)
	central_sigma.SetLineWidth(2)
	central_sigma.SetMarkerStyle(ROOT.kFullCircle)
	central_sigma.SetMarkerColor(ROOT.kRed)
	data_sigma.SetMarkerStyle(ROOT.kFullCircle)
	data_sigma.SetMarkerColor(ROOT.kBlack)
	
#	ROOT.gStyle.SetErrorX(0.1)
	c = ROOT.TCanvas("","",680,680)
	c.cd()
	central_mean_hist.GetYaxis().SetRangeUser(0.5,1.5)
	up_mean_hist.SetFillColor(ROOT.kBlue)
	up_mean_hist.SetFillStyle(3135)
	down_mean_hist.SetFillColor(ROOT.kCyan)
	down_mean_hist.SetFillStyle(3145)
	central_mean_hist.Draw(" PE X0")
	up_mean_hist.Draw("SAME L e2 f")
	down_mean_hist.Draw("SAME L e2 f")
	data_mean_hist.Draw("SAME E PE X0")
	legend.Draw("SAME")
	central_mean_hist.Draw("SAME PE X0")
	c.SaveAs("alpha_mean_value.C")
	c.SaveAs("alpha_mean_value.png")


	c1 = ROOT.TCanvas("","",680,680)
	c1.cd()
	central_sigma.GetYaxis().SetRangeUser(0,0.5)
	up_sigma.SetFillColor(ROOT.kBlue)
	up_sigma.SetFillStyle(3135)
	down_sigma.SetFillColor(ROOT.kCyan)
	down_sigma.SetFillStyle(3145)
	central_sigma.SetLineWidth(0)
	data_sigma.SetLineWidth(0)
	central_sigma.Draw("HIST E PE X0")
	up_sigma.Draw("SAME L e2 f")
	down_sigma.Draw("SAME L e2 f")
	data_sigma.Draw("SAME HIST E PE X0")
	central_sigma.Draw("SAME HIST E PE X0")
	legend.Draw("SAME")
	c1.SaveAs("alpha_sigma_value.C")
	c1.SaveAs("alpha_sigma_value.png")

	c1.Clear()

	central_hist.Divide(central_mean_hist)
	up_hist.Divide(up_mean_hist)
	down_hist.Divide(down_mean_hist)
	data_hist.Divide(data_mean_hist)
#	res_hist.Divide(res_mean_hist)

#	init_lin_hist = ROOT.TF1("init_linear_hist","([0]*x + [1])",0,1)
#	init_lin_hist.SetParameter(0,0.3)
#	init_lin_hist.SetParameter(1,0.22)

#	res_hist.Fit("init_linear_hist","R","",0.0,0.3)

#	ck_hist = (init_lin_hist.GetParameter(0)/init_lin_hist.GetParameter(1))
	
#	print("ck: %f" %ck_hist)

#	lin_data_1 = ROOT.TF1("linear_data_1","[0]*x",0,1)
#	lin_data_2 = ROOT.TF1("linear_data_2","[1]*([0]*x + 1)",0,1)
#	lin_hist_1 = ROOT.TF1("linear_hist_1","[0]*x",0,1)
#	lin_hist_2 = ROOT.TF1("linear_hist_2","[1]*([0]*x + 1)",0,1)


#	conv_data = ROOT.TF1Convolution("linear_data_1","linear_data_2",0,1,True)
#	conv_hist = ROOT.TF1Convolution("linear_hist_1","linear_hist_2",0,1,True)

#	lin_data = ROOT.TF1("linear_data", conv_data,0,1,conv_data.GetNpar())
#	lin_hist = ROOT.TF1("linear_hist", conv_hist,0,1,conv_data.GetNpar())

#	lin_data.SetParameter(0,0.5)
#	lin_hist.SetParameter(0,0.5)
#	lin_data.SetParameter(1,0.5)
#	lin_hist.SetParameter(1,0.5)
#	lin_data.FixParameter(2,ck_hist)
#	lin_hist.FixParameter(2,ck_hist)




#	central_hist.Fit("linear_hist","0 R","",0.0,0.3)
#	data_hist.Fit("linear_data","0 R","",0.0,0.3)

#	c_hist=lin_hist.GetParameter(1)
#	m_hist=lin_hist.GetParameter(0)
#	c_data=lin_data.GetParameter(1)
#	m_data=lin_data.GetParameter(0)

#	lin_hist.SetLineColor(ROOT.kRed)
#	lin_hist.SetLineWidth(2)
#	init_lin_hist.SetLineColor(ROOT.kGreen)
#	init_lin_hist.SetLineWidth(2)
#	lin_data.SetLineColor(ROOT.kBlack)
#	lin_data.SetLineWidth(2)


#	print("c of MC: %f" %c_hist)
#	print("c of data: %f" %c_data)
#	print("scale: %f" %(c_data/c_hist))

	legend = ROOT.TLegend(0.65, 0.65, 0.93, 0.87)
	legend.SetFillStyle(0)
	legend.SetTextSize(0.02)
#	legend.AddEntry(0,"c_k = %f" %ck_hist)
	legend.AddEntry(data_hist,"Data")
#	legend.AddEntry(res_hist,"Intrinsic")
#	legend.AddEntry(lin_data,"m_{data}\cdot x + c_{data}(c_k \cdot x + 1)")
#	legend.AddEntry(init_lin_hist,"c_{0} x + m_{0}")
#	legend.AddEntry(0,"m_{data} = %f, c_{data} = %f" %(m_data,c_data))
	legend.AddEntry(central_hist,"Central MC")
#	legend.AddEntry(lin_hist,"m_{MC}\cdot x + c_{MC}(c_k \cdot x + 1)")
#	legend.AddEntry(0,"m_{MC} = %f, c_{MC} = %f" %(m_hist,c_hist))
	legend.AddEntry(up_hist,"JEC up MC")
	legend.AddEntry(down_hist,"JEC down MC")
	#### wightou BReg $$$$
	raw_hist_line = ROOT.TLine(0,0.250286,400,0.250286)
	raw_data_line = ROOT.TLine(0,0.274431,400,0.274431)
	##### with BReg ####
#	raw_hist_line = ROOT.TLine(0,0.227330,400,0.227330)
#	raw_data_line = ROOT.TLine(0,0.253386,400,0.253386)


	raw_data_line.SetLineWidth(2)
	raw_data_line.SetLineColor(ROOT.kBlack)
	raw_data_line.SetLineStyle(9)
	raw_hist_line.SetLineWidth(2)
	raw_hist_line.SetLineColor(ROOT.kRed)
	raw_hist_line.SetLineStyle(9)
	c1 = ROOT.TCanvas("","",680,680)
	c1.cd()
	central_hist.GetYaxis().SetRangeUser(0,0.5)
	up_hist.SetFillColor(ROOT.kBlue)
	up_hist.SetFillStyle(3135)
	down_hist.SetFillColor(ROOT.kCyan)
	down_hist.SetFillStyle(3145)
	central_hist.SetLineWidth(0)
	data_hist.SetLineWidth(0)
	central_hist.Draw("HIST E PE X0")
	raw_data_line.Draw("SAME")
	raw_hist_line.Draw("SAME")
#	init_lin_hist.Draw("SAME")
#	lin_hist.Draw("SAME")
#	lin_data.Draw("SAME")
#	init_lin_hist.Draw("SAME")
	up_hist.Draw("SAME L e2 f")
	down_hist.Draw("SAME L e2 f")
	central_hist.Draw("SAME HIST E PE X0")
#	res_hist.Draw("SAME HIST E PE X0")
	data_hist.Draw("SAME HIST E PE X0")
	legend.Draw("SAME")
	c1.SaveAs("alpha_resolution_value.C")
	c1.SaveAs("alpha_resolution_value.png")



