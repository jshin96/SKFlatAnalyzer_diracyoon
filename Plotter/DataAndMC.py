from ROOT import TFile, THStack, TLegend, TH1, RooRealVar,RooGaussian,RooDataHist,RooArgList,RooFit,TCanvas, RooCBShape, RooCrystalBall, RooArgList
from Plotter.PlotterBase import PlotterBase
import ROOT
from random import uniform
import numpy as np
class DataAndMC(PlotterBase):
    def __init__(self, cvs_params, hist_params, info_params):
        logy = cvs_params['logy']
        grid = cvs_params['grid']
        pad_dim = cvs_params['pad_dim']
        super().__init__(cvs_type=pad_dim, logy=logy, grid=grid)
        self.hist_params = hist_params
        self.info_params = info_params
        self.__set_legend()

    def __set_legend(self):
        self.legend = TLegend(0.65, 0.50, 0.93, 0.87)
        self.legend.SetFillStyle(0)
        self.legend.SetBorderSize(0)

    def get_hists(self, hist_obs, hists_exp, hist_up, hist_down,scale_un,scale_dn,scale_nu,scale_nd,scale_uu,scale_dd):
#    def get_hists(self, hist_obs, hists_exp):
        print("INFO: Storing histograms...")
        self.hist_obs = hist_obs
        self.hists_exp = hists_exp
        self.stack = THStack('stack', '')
        self.syst = None
        self.hist_up = hist_up
        self.hist_down = hist_down
        self.syst_up = None
        self.syst_down = None
        
        self.scale_un = scale_un
        self.scale_dn = scale_dn
        self.scale_nu = scale_nu
        self.scale_nd = scale_nd
        self.scale_uu = scale_uu
        self.scale_dd = scale_dd
        self.syst_un = None
        self.syst_dn = None
        self.syst_nu = None
        self.syst_nd = None
        self.syst_uu = None
        self.syst_dd = None
        
        self.ratio = None
        self.ratio_syst = None
        self.ratio_syst_up = None
        self.ratio_syst_down = None
        self.ratio_syst_un = None
        self.ratio_syst_dn = None
        self.ratio_syst_nu = None
        self.ratio_syst_nd = None
        self.ratio_syst_uu = None
        self.ratio_syst_dd = None

        self.__decorate_hists()
        self.__make_stack_and_syst()
        self.__make_ratio()



    def __make_stack_and_syst(self):
        for hist in self.hists_exp.values():
            self.stack.Add(hist)
        # for systematics
            if self.syst == None:
                self.syst = hist.Clone("syst")
            else:
                self.syst.Add(hist)
        for up in self.hist_up.values():
            if self.syst_up == None and up != None:
                self.syst_up = up.Clone("syst_up")
            elif up != None:
                self.syst_up.Add(up)
        for down in self.hist_down.values():
            if self.syst_down == None and down != None:
                self.syst_down = down.Clone("syst_down")
            elif down != None:
                self.syst_down.Add(down)
        for un in self.scale_un.values():
            if self.syst_un == None and un != None:
                self.syst_un = un.Clone("syst_un")
            elif un != None:
                self.syst_un.Add(un)
        for dn in self.scale_dn.values():
            if self.syst_dn == None and dn != None:
                self.syst_dn = dn.Clone("syst_dn")
            elif dn != None:
                self.syst_dn.Add(dn)
        for nu in self.scale_nu.values():
            if self.syst_nu == None and nu != None:
                self.syst_nu = nu.Clone("syst_nu")
            elif nu != None:
                self.syst_nu.Add(nu)
        for nd in self.scale_nd.values():
            if self.syst_nd == None and nd != None:
                self.syst_nd = nd.Clone("syst_nd")
            elif nd != None:
                self.syst_nd.Add(nd)
        for uu in self.scale_uu.values():
            if self.syst_uu == None and uu != None:
                self.syst_uu = uu.Clone("syst_uu")
            elif uu != None:
                self.syst_uu.Add(uu)
        for dd in self.scale_dd.values():
            if self.syst_dd == None and dd != None:
                self.syst_dd = dd.Clone("syst_dd")
            elif dd != None:
                self.syst_dd.Add(dd)

        self.hist_exp = self.syst
        if self.syst_up != None:
            self.hist_exp_up = self.syst_up.Clone("hist_exp_up")
            self.syst_up.Add(self.syst,-1)
        else:
            self.hist_exp_up = self.syst.Clone("hist_exp_up")
            
        if self.syst_down != None:
            self.hist_exp_down = self.syst_down.Clone("hist_exp_down")
            self.syst_down.Add(self.syst,-1)
        else:
            self.hist_exp_up = self.syst.Clone("hist_exp_down")
            
        up_error = -999
        down_error = -999
        for bin_index in range(1,self.syst.GetNbinsX()+1):
            bin_content = self.syst.GetBinContent(bin_index)
            up_error = (self.syst.GetBinError(bin_index)**2+self.syst_up.GetBinContent(bin_index)**2+self.hist_exp_up.GetBinError(bin_index)**2)**0.5
            down_error = (self.syst.GetBinError(bin_index)**2+self.syst_down.GetBinContent(bin_index)**2+self.hist_exp_down.GetBinError(bin_index)**2)**0.5
            if up_error != -999 and down_error != -999:
                self.syst_up.SetBinContent(bin_index,bin_content)
                self.syst_up.SetBinError(bin_index,up_error)
                self.syst_down.SetBinContent(bin_index,bin_content)
                self.syst_down.SetBinError(bin_index,down_error)

        # stack
        self.stack.Draw()   # need to draw stack first to change axis
        self.stack.GetHistogram().GetXaxis().SetLabelSize(0.04)


        # syst
        # TODO: Add systematic errors
        self.syst.SetStats(0)
        self.syst.SetFillColorAlpha(12, 0.6)
        self.syst.SetFillStyle(3144)
        self.syst.GetXaxis().SetLabelSize(0.04)
        self.syst_up.SetStats(0)
        self.syst_up.SetFillColorAlpha(9, 0.5)
        self.syst_up.SetFillStyle(3135)
        self.syst_up.GetXaxis().SetLabelSize(0.04)
        self.syst_down.SetStats(0)
        self.syst_down.SetFillColorAlpha(46, 0.5)
        self.syst_down.SetFillStyle(3145)
        self.syst_down.GetXaxis().SetLabelSize(0.04)
        self.legend.AddEntry(self.syst_up, 'stat+syst_up', 'f')
        self.legend.AddEntry(self.syst_down, 'stat+syst_down', 'f')
        self.legend.AddEntry(self.syst, 'stat+syst', 'f')
    def __decorate_hists(self):
        # basic settings
        self.hist_obs.SetStats(0)
        for hist in self.hists_exp.values():
            hist.SetStats(0)

        if "rebin" in self.hist_params.keys():
            rebin = self.hist_params['rebin']
            self.hist_obs.Rebin(rebin)
            for hist in self.hists_exp.values():
                hist.Rebin(rebin)

        # x axis
        self.hist_obs.GetXaxis().SetLabelSize(0.04)
        for hist in self.hists_exp.values():
            hist.GetXaxis().SetLabelSize(0)

        if "x_range" in self.hist_params.keys():
            x_range = self.hist_params['x_range']
            self.hist_obs.GetXaxis().SetRangeUser(x_range[0], x_range[1])
            for hist in self.hists_exp.values():
                hist.GetXaxis().SetRangeUser(x_range[0], x_range[1])

        # y axis
        print("INFO: y axis range set to be maximum of data plot")
        maximum = self.hist_obs.GetMaximum()
        y_title = self.hist_params['y_title']
        self.hist_obs.GetYaxis().SetTitle(y_title)
        self.hist_obs.GetYaxis().SetTitleOffset(1.4)

        # style
        self.hist_obs.SetMarkerStyle(8)
        self.hist_obs.SetMarkerSize(0.4)
        self.hist_obs.SetMarkerColor(1)

        # add to legend
        self.legend.AddEntry(self.hist_obs, "Data", "lep")
        for name, hist in self.hists_exp.items():
            self.legend.AddEntry(hist, name, "f")

    def __make_ratio(self):
        ratio_range = self.hist_params['ratio_range']
        x_title = self.hist_params['x_title']

        self.ratio = self.hist_obs.Clone("ratio")
        self.ratio.Divide(self.hist_exp)
        self.ratio_syst= self.syst.Clone("ratio_syst")
        self.ratio_syst.Divide(self.hist_exp)
        self.ratio_syst_up = self.syst_up.Clone("ratio_syst_up")
        self.ratio_syst_down = self.syst_down.Clone("ratio_syst_down")
        self.ratio_syst_up.Divide(self.hist_exp)        
        self.ratio_syst_down.Divide(self.hist_exp)        

        self.ratio.SetStats(0)
        self.ratio.SetTitle("")

        # x axis
        self.ratio.GetXaxis().SetTitle(x_title)
        self.ratio_syst_up.GetXaxis().SetTitle(x_title)
        self.ratio_syst_down.GetXaxis().SetTitle(x_title)
        self.ratio_syst_up.GetXaxis().SetTitleSize(0.1)
        self.ratio_syst_up.GetXaxis().SetTitleOffset(0.8)
        self.ratio_syst_up.GetXaxis().SetLabelSize(0.04)

        # y axis
        self.ratio_syst_up.GetYaxis().SetRangeUser(ratio_range[0], ratio_range[1])
        self.ratio_syst_up.GetYaxis().SetTitle(self.hist_params["ratio_title"])
        self.ratio_syst_up.GetYaxis().CenterTitle()
        self.ratio_syst_up.GetYaxis().SetTitleSize(0.1)
        self.ratio_syst_up.GetYaxis().SetTitleOffset(0.4)
        self.ratio_syst_up.GetYaxis().SetLabelSize(0.04)

        # ratio_syst
        self.ratio_syst.SetStats(0)
        self.ratio_syst.SetFillColorAlpha(12, 0.6)
        self.ratio_syst.SetFillStyle(3144)

    def get_fit(self,range_mult):
        nmin_val = 0.05
        nmax_val = 4
        amin_val = 0.5
        amax_val = 5
#        nmin_val = 0.1
#        nmax_val = 3
#        amin_val = 1.0
#        amax_val = 4
        x_c = RooRealVar("x_c","x_c",0.0,2.0)
        x_u = RooRealVar("x_u","x_u",0.0,2.0)
        x_d = RooRealVar("x_d","x_d",0.0,2.0)
        x_o = RooRealVar("x_o","x_o",0.0,2.0)
        x_un = RooRealVar("x_un","x_un",0.0,2.0)
        x_dn = RooRealVar("x_dn","x_dn",0.0,2.0)
        x_nu = RooRealVar("x_nu","x_nu",0.0,2.0)
        x_nd = RooRealVar("x_nd","x_nd",0.0,2.0)
        x_uu = RooRealVar("x_uu","x_uu",0.0,2.0)
        x_dd = RooRealVar("x_dd","x_dd",0.0,2.0)
        mean_c = RooRealVar("mean_c","central mean of gaussian", 0.8,0.4,1.2)
        sigma_c = RooRealVar("sigma_c","central sigma of gaussian",0.2,0.05,0.3)
        mean_u = RooRealVar("mean_u","up mean of gaussian", 0.8,0.4,1.2)
        sigma_u = RooRealVar("sigma_u","up sigma of gaussian",0.2,0.05,0.3)
        mean_d = RooRealVar("mean_d","down mean of gaussian", 0.8,0.4,1.2)
        sigma_d = RooRealVar("sigma_d","down sigma of gaussian",0.2,0.05,0.3)
        mean_o = RooRealVar("mean_o","obs mean of gaussian", 0.8,0.4,1.2)
        sigma_o = RooRealVar("sigma_o","obs sigma of gaussian",0.2,0.05,0.3)
        mean_un = RooRealVar("mean_un","un mean of gaussian", 0.8,0.4,1.2)
        sigma_un = RooRealVar("sigma_un","un sigma of gaussian",0.2,0.05,0.3)
        mean_dn = RooRealVar("mean_dn","dn mean of gaussian", 0.8,0.4,1.2)
        sigma_dn = RooRealVar("sigma_dn","dn sigma of gaussian",0.2,0.05,0.3)
        mean_nu = RooRealVar("mean_nu","nu mean of gaussian", 0.8,0.4,1.2)
        sigma_nu = RooRealVar("sigma_nu","nu sigma of gaussian",0.2,0.05,0.3)
        mean_nd = RooRealVar("mean_nd","nd mean of gaussian", 0.8,0.4,1.2)
        sigma_nd = RooRealVar("sigma_nd","nd sigma of gaussian",0.2,0.05,0.3)
        mean_uu = RooRealVar("mean_uu","uu mean of gaussian", 0.8,0.4,1.2)
        sigma_uu = RooRealVar("sigma_uu","uu sigma of gaussian",0.2,0.05,0.3)
        mean_dd = RooRealVar("mean_dd","dd mean of gaussian", 0.8,0.4,1.2)
        sigma_dd = RooRealVar("sigma_dd","dd sigma of gaussian",0.2,0.05,0.3)

        aLc = RooRealVar("ALC","power left central",amin_val,amax_val)
        nLc = RooRealVar("NLC","exponent left central",nmin_val,nmax_val)
        aRc = RooRealVar("ARC","power right central",amin_val,amax_val)
        nRc = RooRealVar("NRC","exponent right central",nmin_val,nmax_val)

        aLu = RooRealVar("ALU","power left up",amin_val,amax_val)
        nLu = RooRealVar("NLU","exponent left up",nmin_val,nmax_val)
        aRu = RooRealVar("ARU","power right up",amin_val,amax_val)
        nRu = RooRealVar("NRU","exponent right up",nmin_val,nmax_val)

        aLd = RooRealVar("ALD","power left down",amin_val,amax_val)
        nLd = RooRealVar("NLD","exponent left down",nmin_val,nmax_val)
        aRd = RooRealVar("ARD","power right down",amin_val,amax_val)
        nRd = RooRealVar("NRD","exponent right down",nmin_val,nmax_val)

        aLo = RooRealVar("ALO","power left data",amin_val,amax_val)
        nLo = RooRealVar("NLO","exponent left data",nmin_val,nmax_val)
        aRo = RooRealVar("ARO","power right data",amin_val,amax_val)
        nRo = RooRealVar("NRO","exponent right data",nmin_val,nmax_val)

        aLun = RooRealVar("ALun","power left un",amin_val,amax_val)
        nLun = RooRealVar("NLun","exponent left un",nmin_val,nmax_val)
        aRun = RooRealVar("ARun","power right un",amin_val,amax_val)
        nRun = RooRealVar("NRun","exponent right un",nmin_val,nmax_val)

        aLdn = RooRealVar("ALdn","power left dn",amin_val,amax_val)
        nLdn = RooRealVar("NLdn","exponent left dn",nmin_val,nmax_val)
        aRdn = RooRealVar("ARdn","power right dn",amin_val,amax_val)
        nRdn = RooRealVar("NRdn","exponent right dn",nmin_val,nmax_val)

        aLnu = RooRealVar("ALnu","power left nu",amin_val,amax_val)
        nLnu = RooRealVar("NLnu","exponent left nu",nmin_val,nmax_val)
        aRnu = RooRealVar("ARnu","power right nu",amin_val,amax_val)
        nRnu = RooRealVar("NRnu","exponent right nu",nmin_val,nmax_val)

        aLnd = RooRealVar("ALnd","power left nd",amin_val,amax_val)
        nLnd = RooRealVar("NLnd","exponent left nd",nmin_val,nmax_val)
        aRnd = RooRealVar("ARnd","power right nd",amin_val,amax_val)
        nRnd = RooRealVar("NRnd","exponent right nd",nmin_val,nmax_val)

        aLuu = RooRealVar("ALuu","power left uu",amin_val,amax_val)
        nLuu = RooRealVar("NLuu","exponent left uu",nmin_val,nmax_val)
        aRuu = RooRealVar("ARuu","power right uu",amin_val,amax_val)
        nRuu = RooRealVar("NRuu","exponent right uu",nmin_val,nmax_val)

        aLdd = RooRealVar("ALdd","power left dd",amin_val,amax_val)
        nLdd = RooRealVar("NLdd","exponent left dd",nmin_val,nmax_val)
        aRdd = RooRealVar("ARdd","power right dd",amin_val,amax_val)
        nRdd = RooRealVar("NRdd","exponent right dd",nmin_val,nmax_val)


        self.norm_c=self.syst.Clone("norm_c")
        self.norm_u=self.hist_exp_up.Clone("norm_u")
        self.norm_d=self.hist_exp_down.Clone("norm_d")
        self.norm_o=self.hist_obs.Clone("norm_o")
        self.norm_un = self.syst_un.Clone("norm_un")
        self.norm_dn = self.syst_dn.Clone("norm_dn")
        self.norm_nu = self.syst_nu.Clone("norm_nu")
        self.norm_nd = self.syst_nd.Clone("norm_nd")
        self.norm_uu = self.syst_uu.Clone("norm_uu")
        self.norm_dd = self.syst_dd.Clone("norm_dd")


        max_c = self.norm_c.GetBinContent(self.norm_c.GetMaximumBin())
        max_u = self.norm_u.GetBinContent(self.norm_u.GetMaximumBin())
        max_d = self.norm_d.GetBinContent(self.norm_d.GetMaximumBin())
        max_o = self.norm_o.GetBinContent(self.norm_o.GetMaximumBin())
        max_un = self.norm_un.GetBinContent(self.norm_un.GetMaximumBin())
        max_dn = self.norm_dn.GetBinContent(self.norm_dn.GetMaximumBin())
        max_nu = self.norm_nu.GetBinContent(self.norm_nu.GetMaximumBin())
        max_nd = self.norm_nd.GetBinContent(self.norm_nd.GetMaximumBin())
        max_uu = self.norm_uu.GetBinContent(self.norm_uu.GetMaximumBin())
        max_dd = self.norm_dd.GetBinContent(self.norm_dd.GetMaximumBin())
        """
        bin_width_c=max(int(50/max_c),1)
        bin_width_u=max(int(50/max_u),1)
        bin_width_d=max(int(50/max_d),1)
        bin_width_o=max(int(50/max_o),1)
        bin_width_un=max(int(50/max_un),1)
        bin_width_dn=max(int(50/max_dn),1)
        bin_width_nu=max(int(50/max_nu),1)
        bin_width_nd=max(int(50/max_nd),1)
        bin_width_uu=max(int(50/max_uu),1)
        bin_width_dd=max(int(50/max_dd),1)
        """
        bin_width_c=24/25
        bin_width_u=24/25
        bin_width_d=24/25
        bin_width_o=24/25
        bin_width_un=24/25
        bin_width_dn=24/25
        bin_width_nu=24/25
        bin_width_nd=24/25
        bin_width_uu=24/25
        bin_width_dd=24/25

        binning_c = np.linspace(0,2,int(25/bin_width_c),endpoint=False)
        binning_u = np.linspace(0,2,int(25/bin_width_u),endpoint=False)
        binning_d = np.linspace(0,2,int(25/bin_width_d),endpoint=False)
        binning_o = np.linspace(0,2,int(25/bin_width_o),endpoint=False)
        binning_un = np.linspace(0,2,int(25/bin_width_un),endpoint=False)
        binning_dn = np.linspace(0,2,int(25/bin_width_dn),endpoint=False)
        binning_nu = np.linspace(0,2,int(25/bin_width_nu),endpoint=False)
        binning_nd = np.linspace(0,2,int(25/bin_width_nd),endpoint=False)
        binning_uu = np.linspace(0,2,int(25/bin_width_uu),endpoint=False)
        binning_dd = np.linspace(0,2,int(25/bin_width_dd),endpoint=False)



#        if max_c < 50: 
#            self.norm_c=self.norm_c.Rebin(int(25/bin_width_c)-1,"new_c",binning_c)
#        if max_u < 50: 
#            self.norm_u=self.norm_u.Rebin(int(25/bin_width_u)-1,"new_u",binning_u)
#        if max_d < 50: 
#            self.norm_d=self.norm_d.Rebin(int(25/bin_width_d)-1,"new_d",binning_d)
#        if max_o < 50: 
#            self.norm_o=self.norm_o.Rebin(int(25/bin_width_o)-1,"new_o",binning_o)
#        if max_un < 50: 
#            self.norm_un=self.norm_un.Rebin(int(25/bin_width_un)-1,"new_un",binning_un)
#        if max_dn < 50: 
#            self.norm_dn=self.norm_dn.Rebin(int(25/bin_width_dn)-1,"new_dn",binning_dn)
#        if max_nu < 50: 
#            self.norm_nu=self.norm_nu.Rebin(int(25/bin_width_nu)-1,"new_nu",binning_nu)
#        if max_nd < 50: 
#            self.norm_nd=self.norm_nd.Rebin(int(25/bin_width_nd)-1,"new_nd",binning_nd)
#        if max_uu < 50: 
#            self.norm_uu=self.norm_uu.Rebin(int(25/bin_width_uu)-1,"new_uu",binning_uu)
#        if max_dd < 50: 
#            self.norm_dd=self.norm_dd.Rebin(int(25/bin_width_dd)-1,"new_dd",binning_dd)


#        self.norm_c.Scale(1/self.norm_c.GetMaximum())
#        self.norm_u.Scale(1/self.norm_u.GetMaximum())
#        self.norm_d.Scale(1/self.norm_d.GetMaximum())
#        self.norm_o.Scale(1/self.norm_o.GetMaximum())


        x_c.setRange("central", 0.5,1.5)
        x_u.setRange("up", 0.5,1.5)
        x_d.setRange("down", 0.5,1.5)
        x_o.setRange("obs", 0.5,1.5)
        x_un.setRange("un", 0.5,1.5)
        x_dn.setRange("dn", 0.5,1.5)
        x_nu.setRange("nu", 0.5,1.5)
        x_nd.setRange("nd", 0.5,1.5)
        x_uu.setRange("uu", 0.5,1.5)
        x_dd.setRange("dd", 0.5,1.5)

        dh_c = RooDataHist("dh_central","dh_central",RooArgList(x_c),self.norm_c)
        dh_u = RooDataHist("dh_up","dh_up",RooArgList(x_u),self.norm_u)
        dh_d = RooDataHist("dh_down","dh_down",RooArgList(x_d),self.norm_d)
        dh_o = RooDataHist("dh_data","dh_data",RooArgList(x_o),self.norm_o)
        dh_un = RooDataHist("dh_un","dh_un",RooArgList(x_un),self.norm_un)
        dh_dn = RooDataHist("dh_dn","dh_dn",RooArgList(x_dn),self.norm_dn)
        dh_nu = RooDataHist("dh_nu","dh_nu",RooArgList(x_nu),self.norm_nu)
        dh_nd = RooDataHist("dh_nd","dh_nd",RooArgList(x_nd),self.norm_nd)
        dh_uu = RooDataHist("dh_uu","dh_uu",RooArgList(x_uu),self.norm_uu)
        dh_dd = RooDataHist("dh_dd","dh_dd",RooArgList(x_dd),self.norm_dd)
        CB_c = RooCrystalBall("DSCB_c","central DSCB fit",x_c,mean_c,sigma_c,aLc,nLc,aRc,nRc)
        CB_u = RooCrystalBall("DSCB_u","up DSCB fit",x_u,mean_u,sigma_u,aLu,nLu,aRu,nRu)
        CB_d = RooCrystalBall("DSCB_d","down DSCB fit",x_d,mean_d,sigma_d,aLd,nLd,aRd,nRd)
        CB_o = RooCrystalBall("DSCB_o","obs DSCB fit",x_o,mean_o,sigma_o,aLo,nLo,aRo,nRo)
        CB_un = RooCrystalBall("DSCB_un","un DSCB fit",x_un,mean_un,sigma_un,aLun,nLun,aRun,nRun)
        CB_dn = RooCrystalBall("DSCB_dn","dn DSCB fit",x_dn,mean_dn,sigma_dn,aLdn,nLdn,aRdn,nRdn)
        CB_nu = RooCrystalBall("DSCB_nu","nu DSCB fit",x_nu,mean_nu,sigma_nu,aLnu,nLnu,aRnu,nRnu)
        CB_nd = RooCrystalBall("DSCB_nd","nd DSCB fit",x_nd,mean_nd,sigma_nd,aLnd,nLnd,aRnd,nRnd)
        CB_uu = RooCrystalBall("DSCB_uu","uu DSCB fit",x_uu,mean_uu,sigma_uu,aLuu,nLuu,aRuu,nRuu)
        CB_dd = RooCrystalBall("DSCB_dd","dd DSCB fit",x_dd,mean_dd,sigma_dd,aLdd,nLdd,aRdd,nRdd)



#        gauss_c = RooGaussian("gauss_c","central gaussian fit",x_c,mean_c,sigma_c)
#        gauss_u = RooGaussian("gauss_u","up gaussian fit",x_u,mean_u,sigma_u)
#        gauss_d = RooGaussian("gauss_d","down gaussian fit",x_d,mean_d,sigma_d)
#        gauss_o = RooGaussian("gauss_o","obs gaussian fit",x_o,mean_o,sigma_o)
#        gauss_c.fitTo(dh_c,RooFit.SumW2Error(True),RooFit.Range("central"))
#        gauss_u.fitTo(dh_u,RooFit.SumW2Error(True),RooFit.Range("up"))
#        gauss_d.fitTo(dh_d,RooFit.SumW2Error(True),RooFit.Range("down"))
#        gauss_o.fitTo(dh_o,RooFit.SumW2Error(True),RooFit.Range("obs"))
        CB_c.fitTo(dh_c,RooFit.AsymptoticError(True),RooFit.Minos(True),RooFit.Verbose(False),RooFit.Range("central"),RooFit.PrintLevel(-1),RooFit.Save(False))
        CB_u.fitTo(dh_u,RooFit.AsymptoticError(True),RooFit.Minos(True),RooFit.Verbose(False),RooFit.Range("up"),RooFit.PrintLevel(-1),RooFit.Save(False))
        CB_d.fitTo(dh_d,RooFit.AsymptoticError(True),RooFit.Minos(True),RooFit.Verbose(False),RooFit.Range("down"),RooFit.PrintLevel(-1),RooFit.Save(False))
        CB_o.fitTo(dh_o,RooFit.AsymptoticError(True),RooFit.Minos(True),RooFit.Verbose(False),RooFit.Range("obs"),RooFit.PrintLevel(-1),RooFit.Save(False))
        CB_un.fitTo(dh_o,RooFit.AsymptoticError(True),RooFit.Minos(True),RooFit.Verbose(False),RooFit.Range("un"),RooFit.PrintLevel(-1),RooFit.Save(False))
        CB_dn.fitTo(dh_o,RooFit.AsymptoticError(True),RooFit.Minos(True),RooFit.Verbose(False),RooFit.Range("dn"),RooFit.PrintLevel(-1),RooFit.Save(False))
        CB_nu.fitTo(dh_o,RooFit.AsymptoticError(True),RooFit.Minos(True),RooFit.Verbose(False),RooFit.Range("nu"),RooFit.PrintLevel(-1),RooFit.Save(False))
        CB_nd.fitTo(dh_o,RooFit.AsymptoticError(True),RooFit.Minos(True),RooFit.Verbose(False),RooFit.Range("nd"),RooFit.PrintLevel(-1),RooFit.Save(False))
        CB_uu.fitTo(dh_o,RooFit.AsymptoticError(True),RooFit.Minos(True),RooFit.Verbose(False),RooFit.Range("uu"),RooFit.PrintLevel(-1),RooFit.Save(False))
        CB_dd.fitTo(dh_o,RooFit.AsymptoticError(True),RooFit.Minos(True),RooFit.Verbose(False),RooFit.Range("dd"),RooFit.PrintLevel(-1),RooFit.Save(False))


        aLc2 = RooRealVar("ALC2","power left central",amin_val,amax_val)
        nLc2 = RooRealVar("NLC2","exponent left central",nmin_val,nmax_val)
        aRc2 = RooRealVar("ARC2","power right central",amin_val,amax_val)
        nRc2 = RooRealVar("NRC2","exponent right central",nmin_val,nmax_val)

        aLu2 = RooRealVar("ALU2","power left up",amin_val,amax_val)
        nLu2 = RooRealVar("NLU2","exponent left up",nmin_val,nmax_val)
        aRu2 = RooRealVar("ARU2","power right up",amin_val,amax_val)
        nRu2 = RooRealVar("NRU2","exponent right up",nmin_val,nmax_val)

        aLd2 = RooRealVar("ALD2","power left down",amin_val,amax_val)
        nLd2 = RooRealVar("NLD2","exponent left down",nmin_val,nmax_val)
        aRd2 = RooRealVar("ARD2","power right down",amin_val,amax_val)
        nRd2 = RooRealVar("NRD2","exponent right down",nmin_val,nmax_val)

        aLo2 = RooRealVar("ALO2","power left data",amin_val,amax_val)
        nLo2 = RooRealVar("NLO2","exponent left data",nmin_val,nmax_val)
        aRo2 = RooRealVar("ARO2","power right data",amin_val,amax_val)
        nRo2 = RooRealVar("NRO2","exponent right data",nmin_val,nmax_val)

        aLun2 = RooRealVar("ALun2","power left un",amin_val,amax_val)
        nLun2 = RooRealVar("NLun2","exponent left un",nmin_val,nmax_val)
        aRun2 = RooRealVar("ARun2","power right un",amin_val,amax_val)
        nRun2 = RooRealVar("NRun2","exponent right un",nmin_val,nmax_val)

        aLdn2 = RooRealVar("ALdn2","power left dn",amin_val,amax_val)
        nLdn2 = RooRealVar("NLdn2","exponent left dn",nmin_val,nmax_val)
        aRdn2 = RooRealVar("ARdn2","power right dn",amin_val,amax_val)
        nRdn2 = RooRealVar("NRdn2","exponent right dn",nmin_val,nmax_val)

        aLnu2 = RooRealVar("ALnu2","power left nu",amin_val,amax_val)
        nLnu2 = RooRealVar("NLnu2","exponent left nu",nmin_val,nmax_val)
        aRnu2 = RooRealVar("ARnu2","power right nu",amin_val,amax_val)
        nRnu2 = RooRealVar("NRnu2","exponent right nu",nmin_val,nmax_val)

        aLnd2 = RooRealVar("ALnd2","power left nd",amin_val,amax_val)
        nLnd2 = RooRealVar("NLnd2","exponent left nd",nmin_val,nmax_val)
        aRnd2 = RooRealVar("ARnd2","power right nd",amin_val,amax_val)
        nRnd2 = RooRealVar("NRnd2","exponent right nd",nmin_val,nmax_val)

        aLuu2 = RooRealVar("ALuu2","power left uu",amin_val,amax_val)
        nLuu2 = RooRealVar("NLuu2","exponent left uu",nmin_val,nmax_val)
        aRuu2 = RooRealVar("ARuu2","power right uu",amin_val,amax_val)
        nRuu2 = RooRealVar("NRuu2","exponent right uu",nmin_val,nmax_val)

        aLdd2 = RooRealVar("ALdd2","power left dd",amin_val,amax_val)
        nLdd2 = RooRealVar("NLdd2","exponent left dd",nmin_val,nmax_val)
        aRdd2 = RooRealVar("ARdd2","power right dd",amin_val,amax_val)
        nRdd2 = RooRealVar("NRdd2","exponent right dd",nmin_val,nmax_val)

        x_c2 = RooRealVar("x_c2","x_c2",0.0,2.0)
        x_u2 = RooRealVar("x_u2","x_u2",0.0,2.0)
        x_d2 = RooRealVar("x_d2","x_d2",0.0,2.0)
        x_o2 = RooRealVar("x_o2","x_o2",0.0,2.0)
        x_un2 = RooRealVar("x_un2","x_un2",0.0,2.0)
        x_dn2 = RooRealVar("x_dn2","x_dn2",0.0,2.0)
        x_nu2 = RooRealVar("x_nu2","x_nu2",0.0,2.0)
        x_nd2 = RooRealVar("x_nd2","x_nd2",0.0,2.0)
        x_uu2 = RooRealVar("x_uu2","x_uu2",0.0,2.0)
        x_dd2 = RooRealVar("x_dd2","x_dd2",0.0,2.0)


        dh_c2 = RooDataHist("dh_central2","dh_central2",RooArgList(x_c2),self.norm_c)
        dh_u2 = RooDataHist("dh_up2","dh_up2",RooArgList(x_u2),self.norm_u)
        dh_d2 = RooDataHist("dh_down2","dh_down2",RooArgList(x_d2),self.norm_d)
        dh_o2 = RooDataHist("dh_data2","dh_data2",RooArgList(x_o2),self.norm_o)
        dh_un2 = RooDataHist("dh_un2","dh_un2",RooArgList(x_un2),self.syst_un)
        dh_dn2 = RooDataHist("dh_dn2","dh_dn2",RooArgList(x_dn2),self.syst_dn)
        dh_nu2 = RooDataHist("dh_nu2","dh_nu2",RooArgList(x_nu2),self.syst_nu)
        dh_nd2 = RooDataHist("dh_nd2","dh_nd2",RooArgList(x_nd2),self.syst_nd)
        dh_uu2 = RooDataHist("dh_uu2","dh_uu2",RooArgList(x_uu2),self.syst_uu)
        dh_dd2 = RooDataHist("dh_dd2","dh_dd2",RooArgList(x_dd2),self.syst_dd)
        mean_c2 = RooRealVar("mean_c2","central2 mean of gaussian", mean_c.getValV(),0.4,1.2)
        sigma_c2 = RooRealVar("sigma_c2","central2 sigma of gaussian",sigma_c.getValV(),0.05,0.3)
        mean_u2 = RooRealVar("mean_u2","up2 mean of gaussian", mean_u.getValV(),0.4,1.2)
        sigma_u2 = RooRealVar("sigma_u2","up2 sigma of gaussian",sigma_u.getValV(),0.05,0.3)
        mean_d2 = RooRealVar("mean_d2","down2 mean of gaussian", mean_d.getValV(),0.4,1.2)
        sigma_d2 = RooRealVar("sigma_d2","down2 sigma of gaussian",sigma_d.getValV(),0.05,0.3)
        mean_o2 = RooRealVar("mean_o2","obs2 mean of gaussian", mean_o.getValV(),0.4,1.2)
        sigma_o2 = RooRealVar("sigma_o2","obs2 sigma of gaussian",sigma_o.getValV(),0.05,0.3)
        mean_un2 = RooRealVar("mean_un2","un2 mean of gaussian", 0.8,0.4,1.2)
        mean_dn2 = RooRealVar("mean_dn2","dn2 mean of gaussian", 0.8,0.4,1.2)
        mean_nu2 = RooRealVar("mean_nu2","nu2 mean of gaussian", 0.8,0.4,1.2)
        mean_nd2 = RooRealVar("mean_nd2","nd2 mean of gaussian", 0.8,0.4,1.2)
        mean_uu2 = RooRealVar("mean_uu2","uu2 mean of gaussian", 0.8,0.4,1.2)
        mean_dd2 = RooRealVar("mean_dd2","dd2 mean of gaussian", 0.8,0.4,1.2)
        sigma_un2 = RooRealVar("sigma_un2","un2 sigma of gaussian",0.2,0.05,0.3)
        sigma_dn2 = RooRealVar("sigma_dn2","dn2 sigma of gaussian",0.2,0.05,0.3)
        sigma_nu2 = RooRealVar("sigma_nu2","nu2 sigma of gaussian",0.2,0.05,0.3)
        sigma_nd2 = RooRealVar("sigma_nd2","nd2 sigma of gaussian",0.2,0.05,0.3)
        sigma_uu2 = RooRealVar("sigma_uu2","uu2 sigma of gaussian",0.2,0.05,0.3)
        sigma_dd2 = RooRealVar("sigma_dd2","dd2 sigma of gaussian",0.2,0.05,0.3)
        range_scale = range_mult
        x_c2.setRange("central2", mean_c.getValV()-range_scale*sigma_c.getValV(),mean_c.getValV()+range_scale*sigma_c.getValV())
        x_u2.setRange("up2", mean_u.getValV()-range_scale*sigma_u.getValV(),mean_u.getValV()+range_scale*sigma_u.getValV())
        x_d2.setRange("down2", mean_d.getValV()-range_scale*sigma_d.getValV(),mean_d.getValV()+range_scale*sigma_d.getValV())
        x_o2.setRange("obs2", mean_o.getValV()-range_scale*sigma_o.getValV(),mean_o.getValV()+range_scale*sigma_o.getValV())
        x_un2.setRange("un2", mean_un.getValV()-range_scale*sigma_un.getValV(),mean_un.getValV()+range_scale*sigma_un.getValV())
        x_dn2.setRange("dn2", mean_dn.getValV()-range_scale*sigma_dn.getValV(),mean_dn.getValV()+range_scale*sigma_dn.getValV())
        x_nu2.setRange("nu2", mean_nu.getValV()-range_scale*sigma_nu.getValV(),mean_nu.getValV()+range_scale*sigma_nu.getValV())
        x_nd2.setRange("nd2", mean_nd.getValV()-range_scale*sigma_nd.getValV(),mean_nd.getValV()+range_scale*sigma_nd.getValV())
        x_uu2.setRange("uu2", mean_uu.getValV()-range_scale*sigma_uu.getValV(),mean_uu.getValV()+range_scale*sigma_uu.getValV())
        x_dd2.setRange("dd2", mean_dd.getValV()-range_scale*sigma_dd.getValV(),mean_dd.getValV()+range_scale*sigma_dd.getValV())


        CB_c2 = RooCrystalBall("DSCB_c2","central2 DSCB fit",x_c2,mean_c2,sigma_c2,aLc2,nLc2,aRc2,nRc2)
        CB_u2 = RooCrystalBall("DSCB_u2","up2 DSCB fit",x_u2,mean_u2,sigma_u2,aLu2,nLu2,aRu2,nRu2)
        CB_d2 = RooCrystalBall("DSCB_d2","down2 DSCB fit",x_d2,mean_d2,sigma_d2,aLd2,nLd2,aRd2,nRd2)
        CB_o2 = RooCrystalBall("DSCB_o2","obs2 DSCB fit",x_o2,mean_o2,sigma_o2,aLo2,nLo2,aRo2,nRo2)
        CB_un2 = RooCrystalBall("DSCB_un2","un2 DSCB fit",x_un2,mean_un2,sigma_un2,aLun2,nLun2,aRun2,nRun2)
        CB_dn2 = RooCrystalBall("DSCB_dn2","dn2 DSCB fit",x_dn2,mean_dn2,sigma_dn2,aLdn2,nLdn2,aRdn2,nRdn2)
        CB_nu2 = RooCrystalBall("DSCB_nu2","nu2 DSCB fit",x_nu2,mean_nu2,sigma_nu2,aLnu2,nLnu2,aRnu2,nRnu2)
        CB_nd2 = RooCrystalBall("DSCB_nd2","nd2 DSCB fit",x_nd2,mean_nd2,sigma_nd2,aLnd2,nLnd2,aRnd2,nRnd2)
        CB_uu2 = RooCrystalBall("DSCB_uu2","uu2 DSCB fit",x_uu2,mean_uu2,sigma_uu2,aLuu2,nLuu2,aRuu2,nRuu2)
        CB_dd2 = RooCrystalBall("DSCB_dd2","dd2 DSCB fit",x_dd2,mean_dd2,sigma_dd2,aLdd2,nLdd2,aRdd2,nRdd2)


#        gauss_c2 = RooGaussian("gauss_c2","central2 gaussian fit",x_c2,mean_c2,sigma_c2)
#        gauss_u2 = RooGaussian("gauss_u2","up2 gaussian fit",x_u2,mean_u2,sigma_u2)
#        gauss_d2 = RooGaussian("gauss_d2","down2 gaussian fit",x_d2,mean_d2,sigma_d2)
#        gauss_o2 = RooGaussian("gauss_o2","obs2 gaussian fit",x_o2,mean_o2,sigma_o2)

#        gauss_c2.fitTo(dh_c2,RooFit.Minos(False),RooFit.AsymptoticError(True),RooFit.Verbose(False),RooFit.Range("central2"))
#        gauss_u2.fitTo(dh_u2,RooFit.Minos(False),RooFit.AsymptoticError(True),RooFit.Verbose(False),RooFit.Range("up2"))
#        gauss_d2.fitTo(dh_d2,RooFit.Minos(False),RooFit.AsymptoticError(True),RooFit.Verbose(False),RooFit.Range("down2"))
#        gauss_o2.fitTo(dh_o2,RooFit.Minos(False),RooFit.AsymptoticError(True),RooFit.Verbose(False),RooFit.Range("obs2"))
        CB_c2.fitTo(dh_c2,RooFit.AsymptoticError(True),RooFit.Minos(True),RooFit.Verbose(False),RooFit.Range("central2"))
        CB_u2.fitTo(dh_u2,RooFit.AsymptoticError(True),RooFit.Minos(True),RooFit.Verbose(False),RooFit.Range("up2"))
        CB_d2.fitTo(dh_d2,RooFit.AsymptoticError(True),RooFit.Minos(True),RooFit.Verbose(False),RooFit.Range("down2"))
        CB_o2.fitTo(dh_o2,RooFit.AsymptoticError(True),RooFit.Minos(True),RooFit.Verbose(False),RooFit.Range("obs2"))
        CB_un2.fitTo(dh_un2,RooFit.AsymptoticError(True),RooFit.Minos(True),RooFit.Verbose(False),RooFit.Range("un2"))
        CB_dn2.fitTo(dh_dn2,RooFit.AsymptoticError(True),RooFit.Minos(True),RooFit.Verbose(False),RooFit.Range("dn2"))
        CB_nu2.fitTo(dh_nu2,RooFit.AsymptoticError(True),RooFit.Minos(True),RooFit.Verbose(False),RooFit.Range("nu2"))
        CB_nd2.fitTo(dh_nd2,RooFit.AsymptoticError(True),RooFit.Minos(True),RooFit.Verbose(False),RooFit.Range("nd2"))
        CB_uu2.fitTo(dh_uu2,RooFit.AsymptoticError(True),RooFit.Minos(True),RooFit.Verbose(False),RooFit.Range("uu2"))
        CB_dd2.fitTo(dh_dd2,RooFit.AsymptoticError(True),RooFit.Minos(True),RooFit.Verbose(False),RooFit.Range("dd2"))

        aLcf = aLc2.clone("aLcf")
        nLcf = nLc2.clone("nLcf")
        aRcf = aRc2.clone("aRcf")
        nRcf = nRc2.clone("nRcf")
        aLuf = aLu2.clone("aLuf")
        nLuf = nLu2.clone("nLuf")
        aRuf = aRu2.clone("aRuf")
        nRuf = nRu2.clone("nRuf")
        aLdf = aLd2.clone("aLdf")
        nLdf = nLd2.clone("nLdf")
        aRdf = aRd2.clone("aRdf")
        nRdf = nRd2.clone("nRdf")
        aLof = aLo2.clone("aLof")
        nLof = nLo2.clone("nLof")
        aRof = aRo2.clone("aRof")
        nRof = nRo2.clone("nRof")
        aLunf = aLun2.clone("aLunf")
        nLunf = nLun2.clone("nLunf")
        aRunf = aRun2.clone("aRunf")
        nRunf = nRun2.clone("nRunf")
        aLdnf = aLdn2.clone("aLdnf")
        nLdnf = nLdn2.clone("nLdnf")
        aRdnf = aRdn2.clone("aRdnf")
        nRdnf = nRdn2.clone("nRdnf")
        aLnuf = aLnu2.clone("aLnuf")
        nLnuf = nLnu2.clone("nLnuf")
        aRnuf = aRnu2.clone("aRnuf")
        nRnuf = nRnu2.clone("nRnuf")
        aLndf = aLnd2.clone("aLndf")
        nLndf = nLnd2.clone("nLndf")
        aRndf = aRnd2.clone("aRndf")
        nRndf = nRnd2.clone("nRndf")
        aLuuf = aLuu2.clone("aLuuf")
        nLuuf = nLuu2.clone("nLuuf")
        aRuuf = aRuu2.clone("aRuuf")
        nRuuf = nRuu2.clone("nRuuf")
        aLddf = aLdd2.clone("aLddf")
        nLddf = nLdd2.clone("nLddf")
        aRddf = aRdd2.clone("aRddf")
        nRddf = nRdd2.clone("nRddf")
        mean_cf = mean_c2.clone("mean_cf")
        mean_uf = mean_u2.clone("mean_uf")
        mean_df = mean_d2.clone("mean_df")
        mean_of = mean_o2.clone("mean_of")
        mean_unf = mean_un2.clone("mean_unf")
        mean_dnf = mean_dn2.clone("mean_dnf")
        mean_nuf = mean_nu2.clone("mean_nuf")
        mean_ndf = mean_nd2.clone("mean_ndf")
        mean_uuf = mean_uu2.clone("mean_uuf")
        mean_ddf = mean_dd2.clone("mean_ddf")
        sigma_cf = sigma_c2.clone("sigma_cf")
        sigma_uf = sigma_u2.clone("sigma_uf")
        sigma_df = sigma_d2.clone("sigma_df")
        sigma_of = sigma_o2.clone("sigma_of")
        sigma_unf = sigma_un2.clone("sigma_unf")
        sigma_dnf = sigma_dn2.clone("sigma_dnf")
        sigma_nuf = sigma_nu2.clone("sigma_nuf")
        sigma_ndf = sigma_nd2.clone("sigma_ndf")
        sigma_uuf = sigma_uu2.clone("sigma_uuf")
        sigma_ddf = sigma_dd2.clone("sigma_ddf")
        c_tries = 0
        u_tries = 0
        d_tries = 0
        o_tries = 0
        un_tries = 0
        dn_tries = 0
        nu_tries = 0
        nd_tries = 0
        uu_tries = 0
        dd_tries = 0
        chi2_c = 100000000000
        chi2_u = 100000000000
        chi2_d = 100000000000
        chi2_o = 100000000000
        chi2_un = 100000000000
        chi2_dn = 100000000000
        chi2_nu = 100000000000
        chi2_nd = 100000000000
        chi2_uu = 100000000000
        chi2_dd = 100000000000
        temp_chi2_c = 1000000000
        temp_chi2_u = 1000000000
        temp_chi2_d = 1000000000
        temp_chi2_o = 1000000000
        temp_chi2_un = 1000000000
        temp_chi2_dn = 1000000000
        temp_chi2_nu = 1000000000
        temp_chi2_nd = 1000000000
        temp_chi2_uu = 1000000000
        temp_chi2_dd = 1000000000
        KS_c = -100000000000
        KS_u = -100000000000
        KS_d = -100000000000
        KS_o = -100000000000
        KS_un = -100000000000
        KS_dn = -100000000000
        KS_nu = -100000000000
        KS_nd = -100000000000
        KS_uu = -100000000000
        KS_dd = -100000000000
        temp_KS_c = -1000000000
        temp_KS_u = -1000000000
        temp_KS_d = -1000000000
        temp_KS_o = -1000000000
        temp_KS_un = -1000000000
        temp_KS_dn = -1000000000
        temp_KS_nu = -1000000000
        temp_KS_nd = -1000000000
        temp_KS_uu = -1000000000
        temp_KS_dd = -1000000000
        tries = 500
        self.frame_c = x_c2.frame()
        self.frame_u = x_u2.frame()
        self.frame_d = x_d2.frame()
        self.frame_o = x_o2.frame()
        self.frame_un = x_un2.frame()
        self.frame_dn = x_dn2.frame()
        self.frame_nu = x_nu2.frame()
        self.frame_nd = x_nd2.frame()
        self.frame_uu = x_uu2.frame()
        self.frame_dd = x_dd2.frame()

        """
        NDF_c=int(2*(range_scale*sigma_c.getValV())//(self.norm_c.GetXaxis().GetBinWidth(1)))-5
        NDF_u=int(2*(range_scale*sigma_u.getValV())//(self.norm_u.GetXaxis().GetBinWidth(1)))-5
        NDF_d=int(2*(range_scale*sigma_d.getValV())//(self.norm_d.GetXaxis().GetBinWidth(1)))-5
        NDF_o=int(2*(range_scale*sigma_o.getValV())//(self.norm_o.GetXaxis().GetBinWidth(1)))-5
        NDF_un=int(2*(range_scale*sigma_un.getValV())//(self.norm_un.GetXaxis().GetBinWidth(1)))-5
        NDF_dn=int(2*(range_scale*sigma_dn.getValV())//(self.norm_dn.GetXaxis().GetBinWidth(1)))-5
        NDF_nu=int(2*(range_scale*sigma_nu.getValV())//(self.norm_nu.GetXaxis().GetBinWidth(1)))-5
        NDF_nd=int(2*(range_scale*sigma_nd.getValV())//(self.norm_nd.GetXaxis().GetBinWidth(1)))-5
        NDF_uu=int(2*(range_scale*sigma_uu.getValV())//(self.norm_uu.GetXaxis().GetBinWidth(1)))-5
        NDF_dd=int(2*(range_scale*sigma_dd.getValV())//(self.norm_dd.GetXaxis().GetBinWidth(1)))-5
        if NDF_c == 0 :
            NDF_c = -1
        if NDF_u == 0 :
            NDF_u = -1
        if NDF_d == 0 :
            NDF_d = -1
        if NDF_o == 0 :
            NDF_o = -1
        if NDF_un == 0 :
            NDF_un = -1
        if NDF_dn == 0 :
            NDF_dn = -1
        if NDF_nu == 0 :
            NDF_nu = -1
        if NDF_nd == 0 :
            NDF_nd = -1
        if NDF_uu == 0 :
            NDF_uu = -1
        if NDF_dd == 0 :
            NDF_dd = -1
        """
#        if (NDF_c<1 or NDF_u<1 or NDF_d<1 or NDF_o<1 or NDF_un<1 or NDF_dn<1 or NDF_nu<1 or NDF_nd<1 or NDF_uu<1 or NDF_dd<1):
#            return -999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999,-999

        while c_tries<tries:
            temp_frame_c = x_c2.frame()
            aLc2 = RooRealVar("ALC2","power2 left central",uniform(amin_val,amax_val),amin_val,amax_val)
            nLc2 = RooRealVar("NLC2","exponent2 left central",uniform(nmin_val,nmax_val),nmin_val,nmax_val)
            aRc2 = RooRealVar("ARC2","power2 right central",uniform(amin_val,amax_val),amin_val,amax_val)
            nRc2 = RooRealVar("NRC2","exponent2 right central",uniform(nmin_val,nmax_val),nmin_val,nmax_val)
            mean_c2 = RooRealVar("mean_c2","central2 mean of gaussian", mean_c.getValV()+uniform(-nmin_val,nmin_val),0.4,1.2)
            sigma_c2 = RooRealVar("sigma_c2","central2 sigma of gaussian",sigma_c.getValV()+uniform(-nmin_val,nmin_val),0.05,0.3)
            CB_c2 = RooCrystalBall("DSCB_c2","central2 DSCB fit",x_c2,mean_c2,sigma_c2,aLc2,nLc2,aRc2,nRc2)
            CB_c2.fitTo(dh_c2,RooFit.Minos(True),RooFit.AsymptoticError(True),RooFit.Verbose(False),RooFit.Range("central2"))
            dh_c2.plotOn(temp_frame_c,RooFit.LineWidth(0),RooFit.MarkerSize(0))
            CB_c2.plotOn(temp_frame_c,RooFit.Name("Central"),RooFit.LineColor(2),RooFit.LineStyle(1),RooFit.LineWidth(2),RooFit.Range("central2"))
            h_dh_c = self.norm_c.Clone("h_dh_c")
            x_c2.setBins(25)
            x_c2.setRange(0.0,2.0)
#            th_CB_c = CB_c2.asTF(x_c2)
#            h_CB_c = th_CB_c.GetHistogram()
#            h_CB_c.Rebin(4)
            th_CB_c = CB_c2.generateBinned(x_c2,100000)
            h_CB_c = th_CB_c.createHistogram("h_CB_c",x_c2,RooFit.Binning(25,0.0,2.0))
            h_CB_c.Scale(h_dh_c.GetMaximum()/h_CB_c.GetMaximum())
            low_c=h_dh_c.FindBin(mean_c.getValV()-range_scale*sigma_c.getValV())
            high_c=h_dh_c.FindBin(mean_c.getValV()+range_scale*sigma_c.getValV())
            for b in range(25):
                if b+1 >= low_c and b+1<=high_c:
                    h_CB_c.SetBinError(b+1,h_dh_c.GetBinError(b+1))
                else:
                    h_CB_c.SetBinError(b+1,0)
                    h_dh_c.SetBinError(b+1,0)
                    h_CB_c.SetBinContent(b+1,0)
                    h_dh_c.SetBinContent(b+1,0)
#            dh_c2.fillHistogram(h_dh_c,x_c2)
#            CB_c2.fillHistogram(h_CB_c,x_c2)
            temp_KS_c = h_CB_c.KolmogorovTest(h_dh_c,"X")
#            temp_chi2_c = temp_frame_c.chiSquare()/NDF_c
#            if abs(1-temp_chi2_c) < abs(1-chi2_c) and NDF_c>0:
#                chi2_c = temp_chi2_c
            if temp_KS_c > KS_c:
                KS_c = temp_KS_c
                mean_cf = mean_c2.clone("mean_cf")
                sigma_cf = sigma_c2.clone("sigma_cf")
                aLcf = aLc2.clone("aLcf")
                nLcf = nLc2.clone("nLcf")
                aRcf = aRc2.clone("aRcf")
                nRcf = nRc2.clone("nRcf")
            c_tries += 1

        while u_tries<tries:
            temp_frame_u = x_u2.frame()
            aLu2 = RooRealVar("ALU2","power2 left up",uniform(amin_val,amax_val),amin_val,amax_val)
            nLu2 = RooRealVar("NLU2","exponent2 left up",uniform(nmin_val,nmax_val),nmin_val,nmax_val)
            aRu2 = RooRealVar("ARU2","power2 right up",uniform(amin_val,amax_val),amin_val,amax_val)
            nRu2 = RooRealVar("NRU2","exponent2 right up",uniform(nmin_val,nmax_val),nmin_val,nmax_val)
            mean_u2 = RooRealVar("mean_u2","up2 mean of gaussian", mean_u.getValV()+uniform(-nmin_val,nmin_val),0.4,1.2)
            sigma_u2 = RooRealVar("sigma_u2","up2 sigma of gaussian",sigma_u.getValV()+uniform(-nmin_val,nmin_val),0.05,0.3)
            CB_u2 = RooCrystalBall("DSCB_u2","up2 DSCB fit",x_u2,mean_u2,sigma_u2,aLu2,nLu2,aRu2,nRu2)
            CB_u2.fitTo(dh_u2,RooFit.Minos(True),RooFit.AsymptoticError(True),RooFit.Verbose(False),RooFit.Range("up2"))
            dh_u2.plotOn(temp_frame_u,RooFit.LineWidth(0),RooFit.MarkerSize(0))
            CB_u2.plotOn(temp_frame_u,RooFit.Name("up"),RooFit.LineColor(4),RooFit.LineStyle(1),RooFit.LineWidth(2),RooFit.Range("up2"))
#            temp_chi2_u = temp_frame_u.chiSquare()/NDF_u
#            if abs(1-temp_chi2_u) < abs(1-chi2_u) and NDF_u>0:
#                chi2_u = temp_chi2_u
            h_dh_u = self.norm_u.Clone("h_dh_u")
            x_u2.setBins(25)
            x_u2.setRange(0.0,2.0)
#            th_CB_u = CB_u2.asTF(x_u2)
#            h_CB_u = th_CB_u.GetHistogram()
#            h_CB_u.Rebin(4)
            th_CB_u = CB_u2.generateBinned(x_u2,100000)
            h_CB_u = th_CB_u.createHistogram("h_CB_u",x_u2,RooFit.Binning(25,0.0,2.0))
            h_CB_u.Scale(h_dh_u.GetMaximum()/h_CB_u.GetMaximum())
            low_u=h_dh_u.FindBin(mean_u.getValV()-range_scale*sigma_u.getValV())
            high_u=h_dh_u.FindBin(mean_u.getValV()+range_scale*sigma_u.getValV())
            for b in range(25):
                if b+1 >= low_u and b+1<=high_u:
                    h_CB_u.SetBinError(b+1,h_dh_u.GetBinError(b+1))
                else:
                    h_CB_u.SetBinError(b+1,0)
                    h_dh_u.SetBinError(b+1,0)
                    h_CB_u.SetBinContent(b+1,0)
                    h_dh_u.SetBinContent(b+1,0)
#            for b in range(25):
#                h_CB_u.SetBinError(b+1,h_dh_u.GetBinError(b+1))
#            dh_u2.fillHistogram(h_dh_u,x_u2)
#            CB_u2.fillHistogram(h_CB_u,x_u2)
            temp_KS_u = h_CB_u.KolmogorovTest(h_dh_u,"X")
            if temp_KS_u > KS_u:
                KS_u = temp_KS_u
                mean_uf = mean_u2.clone("mean_uf")
                sigma_uf = sigma_u2.clone("sigma_uf")
                aLuf = aLu2.clone("aLuf")
                nLuf = nLu2.clone("nLuf")
                aRuf = aRu2.clone("aRuf")
                nRuf = nRu2.clone("nRuf")
            u_tries += 1

        while d_tries<tries:
            temp_frame_d = x_d2.frame()
            aLd2 = RooRealVar("ALD2","power2 left down",uniform(amin_val,amax_val),amin_val,amax_val)
            nLd2 = RooRealVar("NLD2","exponent2 left down",uniform(nmin_val,nmax_val),nmin_val,nmax_val)
            aRd2 = RooRealVar("ARD2","power2 right down",uniform(amin_val,amax_val),amin_val,amax_val)
            nRd2 = RooRealVar("NRD2","exponent2 right down",uniform(nmin_val,nmax_val),nmin_val,nmax_val)
            mean_d2 = RooRealVar("mean_d2","down2 mean of gaussian", mean_d.getValV()+uniform(-nmin_val,nmin_val),0.4,1.2)
            sigma_d2 = RooRealVar("sigma_d2","down2 sigma of gaussian",sigma_d.getValV()+uniform(-nmin_val,nmin_val),0.05,0.3)
            CB_d2 = RooCrystalBall("DSCB_d2","down2 DSCB fit",x_d2,mean_d2,sigma_d2,aLd2,nLd2,aRd2,nRd2)
            CB_d2.fitTo(dh_d2,RooFit.Minos(True),RooFit.AsymptoticError(True),RooFit.Verbose(False),RooFit.Range("down2"))
            dh_d2.plotOn(temp_frame_d,RooFit.LineWidth(0),RooFit.MarkerSize(0))
            CB_d2.plotOn(temp_frame_d,RooFit.Name("down"),RooFit.LineColor(7),RooFit.LineStyle(1),RooFit.LineWidth(2),RooFit.Range("down2"))
#            temp_chi2_d = temp_frame_d.chiSquare()/NDF_d
#            if abs(1-temp_chi2_d) < abs(1-chi2_d) and NDF_d>0:
#                chi2_d = temp_chi2_d
            h_dh_d = self.norm_d.Clone("h_dh_d")
            x_d2.setBins(25)
            x_d2.setRange(0.0,2.0)
#            th_CB_d = CB_d2.asTF(x_d2)
#            h_CB_d = th_CB_d.GetHistogram()
#            h_CB_d.Rebin(4)
            th_CB_d = CB_d2.generateBinned(x_d2,100000)
            h_CB_d = th_CB_d.createHistogram("h_CB_d",x_d2,RooFit.Binning(25,0.0,2.0))
            h_CB_d.Scale(h_dh_d.GetMaximum()/h_CB_d.GetMaximum())
            low_d=h_dh_d.FindBin(mean_d.getValV()-range_scale*sigma_d.getValV())
            high_d=h_dh_d.FindBin(mean_d.getValV()+range_scale*sigma_d.getValV())
            for b in range(25):
                if b+1 >= low_d and b+1<=high_d:
                    h_CB_d.SetBinError(b+1,h_dh_d.GetBinError(b+1))
                else:
                    h_CB_d.SetBinError(b+1,0)
                    h_dh_d.SetBinError(b+1,0)
                    h_CB_d.SetBinContent(b+1,0)
                    h_dh_d.SetBinContent(b+1,0)
#            for b in range(25):
#                h_CB_d.SetBinError(b+1,h_dh_d.GetBinError(b+1))
#            dh_d2.fillHistogram(h_dh_d,x_d2)
#            CB_d2.fillHistogram(h_CB_d,x_d2)
            temp_KS_d = h_CB_d.KolmogorovTest(h_dh_d,"X")
            if temp_KS_d > KS_d:
                KS_d = temp_KS_d
                mean_df = mean_d2.clone("mean_df")
                sigma_df = sigma_d2.clone("sigma_df")
                aLdf = aLd2.clone("aLdf")
                nLdf = nLd2.clone("nLdf")
                aRdf = aRd2.clone("aRdf")
                nRdf = nRd2.clone("nRdf")
            d_tries += 1

        while o_tries<tries:
            temp_frame_o = x_o2.frame()
            aLo2 = RooRealVar("ALO2","power2 left data",uniform(amin_val,amax_val),amin_val,amax_val)
            nLo2 = RooRealVar("NLO2","exponent2 left data",uniform(nmin_val,nmax_val),nmin_val,nmax_val)
            aRo2 = RooRealVar("ARO2","power2 right data",uniform(amin_val,amax_val),amin_val,amax_val)
            nRo2 = RooRealVar("NRO2","exponent2 right data",uniform(nmin_val,nmax_val),nmin_val,nmax_val)
            mean_o2 = RooRealVar("mean_o2","obs2 mean of gaussian", mean_o.getValV()+uniform(-nmin_val,nmin_val),0.4,1.2)
            sigma_o2 = RooRealVar("sigma_o2","obs2 sigma of gaussian",sigma_o.getValV()+uniform(-nmin_val,nmin_val),0.05,0.3)
            CB_o2 = RooCrystalBall("DSCB_o2","obs2 DSCB fit",x_o2,mean_o2,sigma_o2,aLo2,nLo2,aRo2,nRo2)
            CB_o2.fitTo(dh_o2,RooFit.Minos(True),RooFit.AsymptoticError(True),RooFit.Verbose(False),RooFit.Range("obs2"))
            dh_o2.plotOn(temp_frame_o,RooFit.LineWidth(0),RooFit.MarkerSize(0))
            CB_o2.plotOn(temp_frame_o,RooFit.Name("observation"),RooFit.LineColor(1),RooFit.LineStyle(1),RooFit.LineWidth(2),RooFit.Range("obs2"))
#            temp_chi2_o = temp_frame_o.chiSquare()/NDF_o
#            if abs(1-temp_chi2_o) < abs(1-chi2_o) and NDF_o>0:
#                chi2_o = temp_chi2_o
            h_dh_o = self.norm_o.Clone("h_dh_o")
            x_o2.setBins(25)
            x_o2.setRange(0.0,2.0)
#            th_CB_o = CB_o2.asTF(x_o2)
#            h_CB_o = th_CB_o.GetHistogram()
#            h_CB_o.Rebin(4)
            th_CB_o = CB_o2.generateBinned(x_o2,100000)
            h_CB_o = th_CB_o.createHistogram("h_CB_o",x_o2,RooFit.Binning(25,0.0,2.0))
            h_CB_o.Scale(h_dh_o.GetBinContent(h_dh_o.GetMaximumBin())/h_CB_o.GetBinContent(h_CB_o.GetMaximumBin()))
            low_o=h_dh_o.FindBin(mean_o.getValV()-range_scale*sigma_o.getValV())
            high_o=h_dh_o.FindBin(mean_o.getValV()+range_scale*sigma_o.getValV())
            for b in range(25):
                if b+1 >= low_o and b+1<=high_o:
                    h_CB_o.SetBinError(b+1,h_dh_o.GetBinError(b+1))
                else:
                    h_CB_o.SetBinError(b+1,0)
                    h_dh_o.SetBinError(b+1,0)
                    h_CB_o.SetBinContent(b+1,0)
                    h_dh_o.SetBinContent(b+1,0)
#            for b in range(25):
#                h_CB_o.SetBinError(b+1,h_dh_o.GetBinError(b+1))
#            dh_o2.fillHistogram(h_dh_o,x_o2)
#            CB_o2.fillHistogram(h_CB_o,x_o2)
            temp_KS_o = h_CB_o.KolmogorovTest(h_dh_o,"X")
            if temp_KS_o > KS_o:
                KS_o = temp_KS_o
                mean_of = mean_o2.clone("mean_of")
                sigma_of = sigma_o2.clone("sigma_of")
                aLof = aLo2.clone("aLof")
                nLof = nLo2.clone("nLof")
                aRof = aRo2.clone("aRof")
                nRof = nRo2.clone("nRof")
            o_tries += 1

        while un_tries<tries:
            temp_frame_un = x_un2.frame()
            aLun2 = RooRealVar("ALun2","power2 left un",uniform(amin_val,amax_val),amin_val,amax_val)
            nLun2 = RooRealVar("NLun2","exponent2 left un",uniform(nmin_val,nmax_val),nmin_val,nmax_val)
            aRun2 = RooRealVar("ARun2","power2 right un",uniform(amin_val,amax_val),amin_val,amax_val)
            nRun2 = RooRealVar("NRun2","exponent2 right un",uniform(nmin_val,nmax_val),nmin_val,nmax_val)
            mean_un2 = RooRealVar("mean_un2","un2 mean of gaussian", mean_o.getValV()+uniform(-nmin_val,nmin_val),0.4,1.2)
            sigma_un2 = RooRealVar("sigma_un2","un2 sigma of gaussian",sigma_o.getValV()+uniform(-nmin_val,nmin_val),0.05,0.3)
            CB_un2 = RooCrystalBall("DSCB_un2","un2 DSCB fit",x_un2,mean_un2,sigma_un2,aLun2,nLun2,aRun2,nRun2)
            CB_un2.fitTo(dh_un2,RooFit.Minos(True),RooFit.AsymptoticError(True),RooFit.Verbose(False),RooFit.Range("un2"))
            dh_un2.plotOn(temp_frame_un,RooFit.LineWidth(0),RooFit.MarkerSize(0))
            CB_un2.plotOn(temp_frame_un,RooFit.Name("observation"),RooFit.LineColor(1),RooFit.LineStyle(1),RooFit.LineWidth(2),RooFit.Range("un2"))
#            temp_chi2_un = temp_frame_un.chiSquare()/NDF_un
#            if abs(1-temp_chi2_un) < abs(1-chi2_un) and NDF_un>0:
#                chi2_un = temp_chi2_un
            h_dh_un = self.norm_un.Clone("h_dh_un")
            x_un2.setBins(25)
            x_un2.setRange(0.0,2.0)
#            th_CB_un = CB_un2.asTF(x_un2)
#            h_CB_un = th_CB_un.GetHistogram()
#            h_CB_un.Rebin(4)
            th_CB_un = CB_un2.generateBinned(x_un2,100000)
            h_CB_un = th_CB_un.createHistogram("h_CB_un",x_un2,RooFit.Binning(25,0.0,2.0))
            h_CB_un.Scale(h_dh_un.GetMaximum()/h_CB_un.GetMaximum())
            low_un=h_dh_un.FindBin(mean_un.getValV()-range_scale*sigma_un.getValV())
            high_un=h_dh_un.FindBin(mean_un.getValV()+range_scale*sigma_un.getValV())
            for b in range(25):
                if b+1 >= low_un and b+1<=high_un:
                    h_CB_un.SetBinError(b+1,h_dh_un.GetBinError(b+1))
                else:
                    h_CB_un.SetBinError(b+1,0)
                    h_dh_un.SetBinError(b+1,0)
                    h_CB_un.SetBinContent(b+1,0)
                    h_dh_un.SetBinContent(b+1,0)
#            for b in range(25):
#                h_CB_un.SetBinError(b+1,h_dh_un.GetBinError(b+1))
#            dh_un2.fillHistogram(h_dh_un,x_un2)
#            CB_un2.fillHistogram(h_CB_un,x_un2)
            temp_KS_un = h_dh_un.KolmogorovTest(h_CB_un)
            if temp_KS_un > KS_un:
                KS_un = temp_KS_un
                mean_unf = mean_un2.clone("mean_unf")
                sigma_unf = sigma_un2.clone("sigma_unf")
                aLunf = aLun2.clone("aLunf")
                nLunf = nLun2.clone("nLunf")
                aRunf = aRun2.clone("aRunf")
                nRunf = nRun2.clone("nRunf")
            un_tries += 1

        while dn_tries<tries:
            temp_frame_dn = x_dn2.frame()
            aLdn2 = RooRealVar("ALdn2","power2 left dn",uniform(amin_val,amax_val),amin_val,amax_val)
            nLdn2 = RooRealVar("NLdn2","exponent2 left dn",uniform(nmin_val,nmax_val),nmin_val,nmax_val)
            aRdn2 = RooRealVar("ARdn2","power2 right dn",uniform(amin_val,amax_val),amin_val,amax_val)
            nRdn2 = RooRealVar("NRdn2","exponent2 right dn",uniform(nmin_val,nmax_val),nmin_val,nmax_val)
            mean_dn2 = RooRealVar("mean_dn2","dn2 mean of gaussian", mean_o.getValV()+uniform(-nmin_val,nmin_val),0.4,1.2)
            sigma_dn2 = RooRealVar("sigma_dn2","dn2 sigma of gaussian",sigma_o.getValV()+uniform(-nmin_val,nmin_val),0.05,0.3)
            CB_dn2 = RooCrystalBall("DSCB_dn2","dn2 DSCB fit",x_dn2,mean_dn2,sigma_dn2,aLdn2,nLdn2,aRdn2,nRdn2)
            CB_dn2.fitTo(dh_dn2,RooFit.Minos(True),RooFit.AsymptoticError(True),RooFit.Verbose(False),RooFit.Range("dn2"))
            dh_dn2.plotOn(temp_frame_dn,RooFit.LineWidth(0),RooFit.MarkerSize(0))
            CB_dn2.plotOn(temp_frame_dn,RooFit.Name("observation"),RooFit.LineColor(1),RooFit.LineStyle(1),RooFit.LineWidth(2),RooFit.Range("dn2"))
#            temp_chi2_dn = temp_frame_dn.chiSquare()/NDF_dn
#            if abs(1-temp_chi2_dn) < abs(1-chi2_dn) and NDF_dn>0:
#                chi2_dn = temp_chi2_dn
            h_dh_dn = self.norm_dn.Clone("h_dh_dn")
            x_dn2.setBins(25)
            x_dn2.setRange(0.0,2.0)
#            th_CB_dn = CB_dn2.asTF(x_dn2)
#            h_CB_dn = th_CB_dn.GetHistogram()
#            h_CB_dn.Rebin(4)
            th_CB_dn = CB_dn2.generateBinned(x_dn2,100000)
            h_CB_dn = th_CB_dn.createHistogram("h_CB_dn",x_dn2,RooFit.Binning(25,0.0,2.0))
            h_CB_dn.Scale(h_dh_dn.GetMaximum()/h_CB_dn.GetMaximum())
            low_dn=h_dh_dn.FindBin(mean_dn.getValV()-range_scale*sigma_dn.getValV())
            high_dn=h_dh_dn.FindBin(mean_dn.getValV()+range_scale*sigma_dn.getValV())
            for b in range(25):
                if b+1 >= low_dn and b+1<=high_dn:
                    h_CB_dn.SetBinError(b+1,h_dh_dn.GetBinError(b+1))
                else:
                    h_CB_dn.SetBinError(b+1,0)
                    h_dh_dn.SetBinError(b+1,0)
                    h_CB_dn.SetBinContent(b+1,0)
                    h_dh_dn.SetBinContent(b+1,0)
#            for b in range(25):
#                h_CB_dn.SetBinError(b+1,h_dh_dn.GetBinError(b+1))
#            dh_dn2.fillHistogram(h_dh_dn,x_dn2)
#            CB_dn2.fillHistogram(h_CB_dn,x_dn2)
            temp_KS_dn = h_dh_dn.KolmogorovTest(h_CB_dn)
            if temp_KS_dn > KS_dn:
                KS_dn = temp_KS_dn
                mean_dnf = mean_dn2.clone("mean_dnf")
                sigma_dnf = sigma_dn2.clone("sigma_dnf")
                aLdnf = aLdn2.clone("aLdnf")
                nLdnf = nLdn2.clone("nLdnf")
                aRdnf = aRdn2.clone("aRdnf")
                nRdnf = nRdn2.clone("nRdnf")
            dn_tries += 1

        while nu_tries<tries:
            temp_frame_nu = x_nu2.frame()
            aLnu2 = RooRealVar("ALnu2","power2 left nu",uniform(amin_val,amax_val),amin_val,amax_val)
            nLnu2 = RooRealVar("NLnu2","exponent2 left nu",uniform(nmin_val,nmax_val),nmin_val,nmax_val)
            aRnu2 = RooRealVar("ARnu2","power2 right nu",uniform(amin_val,amax_val),amin_val,amax_val)
            nRnu2 = RooRealVar("NRnu2","exponent2 right nu",uniform(nmin_val,nmax_val),nmin_val,nmax_val)
            mean_nu2 = RooRealVar("mean_nu2","nu2 mean of gaussian", mean_o.getValV()+uniform(-nmin_val,nmin_val),0.4,1.2)
            sigma_nu2 = RooRealVar("sigma_nu2","nu2 sigma of gaussian",sigma_o.getValV()+uniform(-nmin_val,nmin_val),0.05,0.3)
            CB_nu2 = RooCrystalBall("DSCB_nu2","nu2 DSCB fit",x_nu2,mean_nu2,sigma_nu2,aLnu2,nLnu2,aRnu2,nRnu2)
            CB_nu2.fitTo(dh_nu2,RooFit.Minos(True),RooFit.AsymptoticError(True),RooFit.Verbose(False),RooFit.Range("nu2"))
            dh_nu2.plotOn(temp_frame_nu,RooFit.LineWidth(0),RooFit.MarkerSize(0))
            CB_nu2.plotOn(temp_frame_nu,RooFit.Name("observation"),RooFit.LineColor(1),RooFit.LineStyle(1),RooFit.LineWidth(2),RooFit.Range("nu2"))
#            temp_chi2_nu = temp_frame_nu.chiSquare()/NDF_nu
#            if abs(1-temp_chi2_nu) < abs(1-chi2_nu) and NDF_nu>0:
#                chi2_nu = temp_chi2_nu
            h_dh_nu = self.norm_nu.Clone("h_dh_nu")
            x_nu2.setBins(25)
            x_nu2.setRange(0.0,2.0)
#            th_CB_nu = CB_nu2.asTF(x_nu2,RooArgList({mean_nu2,sigma_nu2,aLnu2,nLnu2,aRnu2,nRnu2}))
#            th_CB_nu = CB_nu2.asTF(x_nu2)
#            h_CB_nu = th_CB_nu.GetHistogram()
#            h_CB_nu.Rebin(4)
            th_CB_nu = CB_nu2.generateBinned(x_nu2,100000)
            h_CB_nu = th_CB_nu.createHistogram("h_CB_nu",x_nu2,RooFit.Binning(25,0.0,2.0))
            h_CB_nu.Scale(h_dh_nu.GetMaximum()/h_CB_nu.GetMaximum())
            low_nu=h_dh_nu.FindBin(mean_nu.getValV()-range_scale*sigma_nu.getValV())
            high_nu=h_dh_nu.FindBin(mean_nu.getValV()+range_scale*sigma_nu.getValV())
            for b in range(25):
                if b+1 >= low_nu and b+1<=high_nu:
                    h_CB_nu.SetBinError(b+1,h_dh_nu.GetBinError(b+1))
                else:
                    h_CB_nu.SetBinError(b+1,0)
                    h_dh_nu.SetBinError(b+1,0)
                    h_CB_nu.SetBinContent(b+1,0)
                    h_dh_nu.SetBinContent(b+1,0)
#            for b in range(25):
#                h_CB_nu.SetBinError(b+1,h_dh_nu.GetBinError(b+1))
#            dh_nu2.fillHistogram(h_dh_nu,x_nu2)
#            CB_nu2.fillHistogram(h_CB_nu,x_nu2)
            temp_KS_nu = h_dh_nu.KolmogorovTest(h_CB_nu)
            if temp_KS_nu > KS_nu:
                KS_nu = temp_KS_nu
                mean_nuf = mean_nu2.clone("mean_nuf")
                sigma_nuf = sigma_nu2.clone("sigma_nuf")
                aLnuf = aLnu2.clone("aLnuf")
                nLnuf = nLnu2.clone("nLnuf")
                aRnuf = aRnu2.clone("aRnuf")
                nRnuf = nRnu2.clone("nRnuf")
            nu_tries += 1

        while nd_tries<tries:
            temp_frame_nd = x_nd2.frame()
            aLnd2 = RooRealVar("ALnd2","power2 left nd",uniform(amin_val,amax_val),amin_val,amax_val)
            nLnd2 = RooRealVar("NLnd2","exponent2 left nd",uniform(nmin_val,nmax_val),nmin_val,nmax_val)
            aRnd2 = RooRealVar("ARnd2","power2 right nd",uniform(amin_val,amax_val),amin_val,amax_val)
            nRnd2 = RooRealVar("NRnd2","exponent2 right nd",uniform(nmin_val,nmax_val),nmin_val,nmax_val)
            mean_nd2 = RooRealVar("mean_nd2","nd2 mean of gaussian", mean_o.getValV()+uniform(-nmin_val,nmin_val),0.4,1.2)
            sigma_nd2 = RooRealVar("sigma_nd2","nd2 sigma of gaussian",sigma_o.getValV()+uniform(-nmin_val,nmin_val),0.05,0.3)
            CB_nd2 = RooCrystalBall("DSCB_nd2","nd2 DSCB fit",x_nd2,mean_nd2,sigma_nd2,aLnd2,nLnd2,aRnd2,nRnd2)
            CB_nd2.fitTo(dh_nd2,RooFit.Minos(True),RooFit.AsymptoticError(True),RooFit.Verbose(False),RooFit.Range("nd2"))
            dh_nd2.plotOn(temp_frame_nd,RooFit.LineWidth(0),RooFit.MarkerSize(0))
            CB_nd2.plotOn(temp_frame_nd,RooFit.Name("observation"),RooFit.LineColor(1),RooFit.LineStyle(1),RooFit.LineWidth(2),RooFit.Range("nd2"))
#            temp_chi2_nd = temp_frame_nd.chiSquare()/NDF_nd
#            if abs(1-temp_chi2_nd) < abs(1-chi2_nd) and NDF_nd>0:
#                chi2_nd = temp_chi2_nd
            h_dh_nd = self.norm_nd.Clone("h_dh_nd")
            x_nd2.setBins(25)
            x_nd2.setRange(0.0,2.0)
#            th_CB_nd = CB_nd2.asTF(x_nd2,RooArgList({mean_nd2,sigma_nd2,aLnd2,nLnd2,aRnd2,nRnd2}))
#            th_CB_nd = CB_nd2.asTF(x_nd2)
#            h_CB_nd = th_CB_nd.GetHistogram()
#            h_CB_nd.Rebin(4)
            th_CB_nd = CB_nd2.generateBinned(x_nd2,100000)
            h_CB_nd = th_CB_nd.createHistogram("h_CB_nd",x_nd2,RooFit.Binning(25,0.0,2.0))
            h_CB_nd.Scale(h_dh_nd.GetMaximum()/h_CB_nd.GetMaximum())
            low_nd=h_dh_nd.FindBin(mean_nd.getValV()-range_scale*sigma_nd.getValV())
            high_nd=h_dh_nd.FindBin(mean_nd.getValV()+range_scale*sigma_nd.getValV())
            for b in range(25):
                if b+1 >= low_nd and b+1<=high_nd:
                    h_CB_nd.SetBinError(b+1,h_dh_nd.GetBinError(b+1))
                else:
                    h_CB_nd.SetBinError(b+1,0)
                    h_dh_nd.SetBinError(b+1,0)
                    h_CB_nd.SetBinContent(b+1,0)
                    h_dh_nd.SetBinContent(b+1,0)
#            for b in range(25):
#                h_CB_nd.SetBinError(b+1,h_dh_nd.GetBinError(b+1))
#            dh_nd2.fillHistogram(h_dh_nd,x_nd2)
#            CB_nd2.fillHistogram(h_CB_nd,x_nd2)
            temp_KS_nd = h_dh_nd.KolmogorovTest(h_CB_nd)
            if temp_KS_nd > KS_nd:
                KS_nd = temp_KS_nd
                mean_ndf = mean_nd2.clone("mean_ndf")
                sigma_ndf = sigma_nd2.clone("sigma_ndf")
                aLndf = aLnd2.clone("aLndf")
                nLndf = nLnd2.clone("nLndf")
                aRndf = aRnd2.clone("aRndf")
                nRndf = nRnd2.clone("nRndf")
            nd_tries += 1
        while uu_tries<tries:
            temp_frame_uu = x_uu2.frame()
            aLuu2 = RooRealVar("ALuu2","power2 left uu",uniform(amin_val,amax_val),amin_val,amax_val)
            nLuu2 = RooRealVar("NLuu2","exponent2 left uu",uniform(nmin_val,nmax_val),nmin_val,nmax_val)
            aRuu2 = RooRealVar("ARuu2","power2 right uu",uniform(amin_val,amax_val),amin_val,amax_val)
            nRuu2 = RooRealVar("NRuu2","exponent2 right uu",uniform(nmin_val,nmax_val),nmin_val,nmax_val)
            mean_uu2 = RooRealVar("mean_uu2","uu2 mean of gaussian", mean_o.getValV()+uniform(-nmin_val,nmin_val),0.4,1.2)
            sigma_uu2 = RooRealVar("sigma_uu2","uu2 sigma of gaussian",sigma_o.getValV()+uniform(-nmin_val,nmin_val),0.05,0.3)
            CB_uu2 = RooCrystalBall("DSCB_uu2","uu2 DSCB fit",x_uu2,mean_uu2,sigma_uu2,aLuu2,nLuu2,aRuu2,nRuu2)
            CB_uu2.fitTo(dh_uu2,RooFit.Minos(True),RooFit.AsymptoticError(True),RooFit.Verbose(False),RooFit.Range("uu2"))
            dh_uu2.plotOn(temp_frame_uu,RooFit.LineWidth(0),RooFit.MarkerSize(0))
            CB_uu2.plotOn(temp_frame_uu,RooFit.Name("observation"),RooFit.LineColor(1),RooFit.LineStyle(1),RooFit.LineWidth(2),RooFit.Range("uu2"))
#            temp_chi2_uu = temp_frame_uu.chiSquare()/NDF_uu
#            if abs(1-temp_chi2_uu) < abs(1-chi2_uu) and NDF_uu>0:
#                chi2_uu = temp_chi2_uu
            h_dh_uu = self.norm_uu.Clone("h_dh_uu")
            x_uu2.setBins(25)
            x_uu2.setRange(0.0,2.0)
#            th_CB_uu = CB_uu2.asTF(x_uu2,RooArgList({mean_uu2,sigma_uu2,aLuu2,nLuu2,aRuu2,nRuu2}))
#            th_CB_uu = CB_uu2.asTF(x_uu2)
#            h_CB_uu = th_CB_uu.GetHistogram()
#            h_CB_uu.Rebin(4)
            th_CB_uu = CB_uu2.generateBinned(x_uu2,100000)
            h_CB_uu = th_CB_uu.createHistogram("h_CB_uu",x_uu2,RooFit.Binning(25,0.0,2.0))
            h_CB_uu.Scale(h_dh_uu.GetMaximum()/h_CB_uu.GetMaximum())
            low_uu=h_dh_uu.FindBin(mean_uu.getValV()-range_scale*sigma_uu.getValV())
            high_uu=h_dh_uu.FindBin(mean_uu.getValV()+range_scale*sigma_uu.getValV())
            for b in range(25):
                if b+1 >= low_uu and b+1<=high_uu:
                    h_CB_uu.SetBinError(b+1,h_dh_uu.GetBinError(b+1))
                else:
                    h_CB_uu.SetBinError(b+1,0)
                    h_dh_uu.SetBinError(b+1,0)
                    h_CB_uu.SetBinContent(b+1,0)
                    h_dh_uu.SetBinContent(b+1,0)
#            for b in range(25):
#                h_CB_uu.SetBinError(b+1,h_dh_uu.GetBinError(b+1))
#            dh_uu2.fillHistogram(h_dh_uu,x_uu2)
#            CB_uu2.fillHistogram(h_CB_uu,x_uu2)
            temp_KS_uu = h_dh_uu.KolmogorovTest(h_CB_uu)
            if temp_KS_uu > KS_uu:
                KS_uu = temp_KS_uu
                mean_uuf = mean_uu2.clone("mean_uuf")
                sigma_uuf = sigma_uu2.clone("sigma_uuf")
                aLuuf = aLuu2.clone("aLuuf")
                nLuuf = nLuu2.clone("nLuuf")
                aRuuf = aRuu2.clone("aRuuf")
                nRuuf = nRuu2.clone("nRuuf")
            uu_tries += 1

        while dd_tries<tries:
            temp_frame_dd = x_dd2.frame()
            aLdd2 = RooRealVar("ALdd2","power2 left dd",uniform(amin_val,amax_val),amin_val,amax_val)
            nLdd2 = RooRealVar("NLdd2","exponent2 left dd",uniform(nmin_val,nmax_val),nmin_val,nmax_val)
            aRdd2 = RooRealVar("ARdd2","power2 right dd",uniform(amin_val,amax_val),amin_val,amax_val)
            nRdd2 = RooRealVar("NRdd2","exponent2 right dd",uniform(nmin_val,nmax_val),nmin_val,nmax_val)
            mean_dd2 = RooRealVar("mean_dd2","dd2 mean of gaussian", mean_o.getValV()+uniform(-nmin_val,nmin_val),0.4,1.2)
            sigma_dd2 = RooRealVar("sigma_dd2","dd2 sigma of gaussian",sigma_o.getValV()+uniform(-nmin_val,nmin_val),0.05,0.3)
            CB_dd2 = RooCrystalBall("DSCB_dd2","dd2 DSCB fit",x_dd2,mean_dd2,sigma_dd2,aLdd2,nLdd2,aRdd2,nRdd2)
            CB_dd2.fitTo(dh_dd2,RooFit.Minos(True),RooFit.AsymptoticError(True),RooFit.Verbose(False),RooFit.Range("dd2"))
            dh_dd2.plotOn(temp_frame_dd,RooFit.LineWidth(0),RooFit.MarkerSize(0))
            CB_dd2.plotOn(temp_frame_dd,RooFit.Name("observation"),RooFit.LineColor(1),RooFit.LineStyle(1),RooFit.LineWidth(2),RooFit.Range("dd2"))
#            temp_chi2_dd = temp_frame_dd.chiSquare()/NDF_dd
#            if abs(1-temp_chi2_dd) < abs(1-chi2_dd) and NDF_dd>0:
#                chi2_dd = temp_chi2_dd
            h_dh_dd = self.norm_dd.Clone("h_dh_nn")
            x_dd2.setBins(25)
            x_dd2.setRange(0.0,2.0)
#            th_CB_dd = CB_dd2.asTF(x_dd2,RooArgList({mean_dd2,sigma_dd2,aLdd2,nLdd2,aRdd2,nRdd2}))
#            th_CB_dd = CB_dd2.asTF(x_dd2)
#            h_CB_dd = th_CB_dd.GetHistogram()
#            h_CB_dd.Rebin(4)
            th_CB_dd = CB_dd2.generateBinned(x_dd2,100000)
            h_CB_dd = th_CB_dd.createHistogram("h_CB_dd",x_dd2,RooFit.Binning(25,0.0,2.0))
            h_CB_dd.Scale(h_dh_dd.GetMaximum()/h_CB_dd.GetMaximum())
            low_dd=h_dh_dd.FindBin(mean_dd.getValV()-range_scale*sigma_dd.getValV())
            high_ddn=h_dh_dd.FindBin(mean_d.getValV()+range_scale*sigma_dd.getValV())
            for b in range(25):
                if b+1 >= low_dd and b+1<=high_d:
                    h_CB_dd.SetBinError(b+1,h_dh_dd.GetBinError(b+1))
                else:
                    h_CB_dd.SetBinError(b+1,0)
                    h_dh_dd.SetBinError(b+1,0)
                    h_CB_dd.SetBinContent(b+1,0)
                    h_dh_dd.SetBinContent(b+1,0)
#            for b in range(25):
#                h_CB_dd.SetBinError(b+1,h_dh_dd.GetBinError(b+1))
#            dh_dd2.fillHistogram(h_dh_dd,x_dd2)
#            CB_dd2.fillHistogram(h_CB_dd,x_dd2)
            temp_KS_dd = h_dh_dd.KolmogorovTest(h_CB_dd)
            if temp_KS_dd > KS_dd:
                KS_dd = temp_KS_dd
                mean_ddf = mean_dd2.clone("mean_ddf")
                sigma_ddf = sigma_dd2.clone("sigma_ddf")
                aLddf = aLdd2.clone("aLddf")
                nLddf = nLdd2.clone("nLddf")
                aRddf = aRdd2.clone("aRddf")
                nRddf = nRdd2.clone("nRddf")
            dd_tries += 1



















        self.frame_c = x_c2.frame()
        self.frame_u = x_u2.frame()
        self.frame_d = x_d2.frame()
        self.frame_o = x_o2.frame()
        self.frame_un = x_un2.frame()
        self.frame_dn = x_dn2.frame()
        self.frame_nu = x_nu2.frame()
        self.frame_nd = x_nd2.frame()
        self.frame_uu = x_uu2.frame()
        self.frame_dd = x_dd2.frame()


        CB_cf = RooCrystalBall("DSCB_cf","centralf DSCB fit",x_c2,mean_cf,sigma_cf,aLcf,nLcf,aRcf,nRcf)
        CB_uf = RooCrystalBall("DSCB_uf","upf DSCB fit",x_u2,mean_uf,sigma_uf,aLuf,nLuf,aRuf,nRuf)
        CB_df = RooCrystalBall("DSCB_df","downf DSCB fit",x_d2,mean_df,sigma_df,aLdf,nLdf,aRdf,nRdf)
        CB_of = RooCrystalBall("DSCB_of","obsf DSCB fit",x_o2,mean_of,sigma_of,aLof,nLof,aRof,nRof)
        CB_unf = RooCrystalBall("DSCB_unf","unf DSCB fit",x_un2,mean_unf,sigma_unf,aLunf,nLunf,aRunf,nRunf)
        CB_dnf = RooCrystalBall("DSCB_dnf","dnf DSCB fit",x_dn2,mean_dnf,sigma_dnf,aLdnf,nLdnf,aRdnf,nRdnf)
        CB_nuf = RooCrystalBall("DSCB_nuf","nuf DSCB fit",x_nu2,mean_nuf,sigma_nuf,aLnuf,nLnuf,aRnuf,nRnuf)
        CB_ndf = RooCrystalBall("DSCB_ndf","ndf DSCB fit",x_nd2,mean_ndf,sigma_ndf,aLndf,nLndf,aRndf,nRndf)
        CB_uuf = RooCrystalBall("DSCB_uuf","uuf DSCB fit",x_uu2,mean_uuf,sigma_uuf,aLuuf,nLuuf,aRuuf,nRuuf)
        CB_ddf = RooCrystalBall("DSCB_ddf","ddf DSCB fit",x_dd2,mean_ddf,sigma_ddf,aLddf,nLddf,aRddf,nRddf)

        dh_c2.plotOn(self.frame_c,RooFit.LineWidth(0),RooFit.MarkerSize(0))
        dh_u2.plotOn(self.frame_u,RooFit.LineWidth(0),RooFit.MarkerSize(0))
        dh_d2.plotOn(self.frame_d,RooFit.LineWidth(0),RooFit.MarkerSize(0))
        dh_o2.plotOn(self.frame_o,RooFit.LineWidth(0),RooFit.MarkerSize(0))
        dh_un2.plotOn(self.frame_un,RooFit.LineWidth(0),RooFit.MarkerSize(0))
        dh_dn2.plotOn(self.frame_dn,RooFit.LineWidth(0),RooFit.MarkerSize(0))
        dh_nu2.plotOn(self.frame_nu,RooFit.LineWidth(0),RooFit.MarkerSize(0))
        dh_nd2.plotOn(self.frame_nd,RooFit.LineWidth(0),RooFit.MarkerSize(0))
        dh_uu2.plotOn(self.frame_uu,RooFit.LineWidth(0),RooFit.MarkerSize(0))
        dh_dd2.plotOn(self.frame_dd,RooFit.LineWidth(0),RooFit.MarkerSize(0))
#        CB_cf.plotOn(self.frame_c,RooFit.Name("Central"),RooFit.LineColor(2),RooFit.LineStyle(2),RooFit.LineWidth(1),RooFit.Range(0,2))
#        CB_uf.plotOn(self.frame_u,RooFit.Name("up"),RooFit.LineColor(4),RooFit.LineStyle(2),RooFit.LineWidth(1),RooFit.Range(0,2))
#        CB_df.plotOn(self.frame_d,RooFit.Name("down"),RooFit.LineColor(7),RooFit.LineStyle(2),RooFit.LineWidth(1),RooFit.Range(0,2))
#        CB_of.plotOn(self.frame_o,RooFit.Name("observation"),RooFit.LineColor(1),RooFit.LineStyle(2),RooFit.LineWidth(1),RooFit.Range(0,2))
        CB_cf.plotOn(self.frame_c,RooFit.Name("Central"),RooFit.LineColor(2),RooFit.LineStyle(1),RooFit.LineWidth(2),RooFit.Range("central2"))
        CB_uf.plotOn(self.frame_u,RooFit.Name("up"),RooFit.LineColor(4),RooFit.LineStyle(1),RooFit.LineWidth(2),RooFit.Range("up2"))
        CB_df.plotOn(self.frame_d,RooFit.Name("down"),RooFit.LineColor(7),RooFit.LineStyle(1),RooFit.LineWidth(2),RooFit.Range("down2"))
        CB_of.plotOn(self.frame_o,RooFit.Name("observation"),RooFit.LineColor(1),RooFit.LineStyle(1),RooFit.LineWidth(2),RooFit.Range("obs2"))
        CB_unf.plotOn(self.frame_un,RooFit.Name("un_Fit"),RooFit.LineColor(1),RooFit.LineStyle(1),RooFit.LineWidth(2),RooFit.Range("un2"))
        CB_dnf.plotOn(self.frame_dn,RooFit.Name("dn_Fit"),RooFit.LineColor(1),RooFit.LineStyle(1),RooFit.LineWidth(2),RooFit.Range("dn2"))
        CB_nuf.plotOn(self.frame_nu,RooFit.Name("nu_Fit"),RooFit.LineColor(1),RooFit.LineStyle(1),RooFit.LineWidth(2),RooFit.Range("nu2"))
        CB_ndf.plotOn(self.frame_nd,RooFit.Name("nd_Fit"),RooFit.LineColor(1),RooFit.LineStyle(1),RooFit.LineWidth(2),RooFit.Range("nd2"))
        CB_uuf.plotOn(self.frame_uu,RooFit.Name("uu_Fit"),RooFit.LineColor(1),RooFit.LineStyle(1),RooFit.LineWidth(2),RooFit.Range("uu2"))
        CB_ddf.plotOn(self.frame_dd,RooFit.Name("dd_Fit"),RooFit.LineColor(1),RooFit.LineStyle(1),RooFit.LineWidth(2),RooFit.Range("dd2"))


        info = self.info_params['info']
        cms_text = self.info_params['cms_text']
        extra_text = self.info_params['extra_text']
        super().set_canvas()
        super().set_logo()
        super().set_info()
        self.legend1 = TLegend(0.65, 0.50, 0.93, 0.87)
        self.legend1.SetFillStyle(0)
        self.legend1.SetBorderSize(0)

        self.legend1.Clear()
        super().pad_lefttop().cd()
        super().info().DrawLatexNDC(0.44, 0.93, info)
        super().logo().DrawLatexNDC(0.15, 0.93, cms_text)
        super().extra_logo().DrawLatexNDC(0.15, 0.90, extra_text)
        self.norm_c.SetLineWidth(2)
        self.norm_c.SetLineColor(2)
        self.legend1.SetTextSize(0.03)
        self.legend1.AddEntry(self.norm_c, "Central")
        self.legend1.AddEntry(self.frame_c,"Central Fit","L")
        self.legend1.AddEntry(0,"#mu: %f #pm %f" %(mean_c2.getValV(),mean_c2.getError()),"")
        self.legend1.AddEntry(0,"#sigma: %f #pm %f" %(sigma_c2.getValV(),sigma_c2.getError()),"")
#        self.legend1.AddEntry(0,"#chi^2: %f" %chi2_c,"")
        self.legend1.AddEntry(0,"KS Score: %f" %KS_c,"")
#        self.legend1.AddEntry(0,"NDF: %f" %NDF_c,"")
#        self.legend1.AddEntry(0,"aL: %f #pm %f" %(aLc2.getValV(),aLc2.getError()),"")
#        self.legend1.AddEntry(0,"nL: %f #pm %f" %(nLc2.getValV(),nLc2.getError()),"")
#        self.legend1.AddEntry(0,"aR: %f #pm %f" %(aRc2.getValV(),aRc2.getError()),"")
#        self.legend1.AddEntry(0,"nR: %f #pm %f" %(nRc2.getValV(),nRc2.getError()),"")
        self.norm_c.SetStats(0)
        self.frame_c.SetTitle("p_T Balance")
        self.frame_c.GetXaxis().SetTitle("p_T(j_1)/p_T(Z)")
        self.frame_c.GetYaxis().SetTitle("1/Events")
        self.frame_c.Draw("")
        self.norm_c.Draw("e1 same")
#        h_dh_c.Draw("HIST SAME")
#        h_dh_c.SetLineColor(3)
#        h_CB_c.Draw("HIST SAME")
        self.legend1.Draw("same")
        super().pad_lefttop().RedrawAxis()


        self.legend2 = TLegend(0.65, 0.50, 0.93, 0.87)
        self.legend2.SetFillStyle(0)
        self.legend2.SetBorderSize(0)
        self.legend2.Clear()
        super().pad_righttop().cd()
        super().info().DrawLatexNDC(0.44, 0.93, info)
        super().logo().DrawLatexNDC(0.15, 0.93, cms_text)
        super().extra_logo().DrawLatexNDC(0.15, 0.90, extra_text)
        self.norm_u.SetLineWidth(2)
        self.norm_u.SetLineColor(4)
        self.legend2.SetTextSize(0.03)
        self.legend2.AddEntry(self.norm_u, "JEC up")
        self.legend2.AddEntry(self.frame_u, "JEC up Fit","L")
        self.legend2.AddEntry(0,"#mu: %f #pm %f" %(mean_u2.getValV(),mean_u2.getError()),"")
        self.legend2.AddEntry(0,"#sigma: %f #pm %f" %(sigma_u2.getValV(),sigma_u2.getError()),"")
#        self.legend2.AddEntry(0,"#chi^2: %f" %chi2_u,"")
        self.legend2.AddEntry(0,"KS Score: %f" %KS_u,"")
#        self.legend2.AddEntry(0,"NDF: %f" %NDF_u,"")
#        self.legend2.AddEntry(0,"aL: %f #pm %f" %(aLu2.getValV(),aLu2.getError()),"")
#        self.legend2.AddEntry(0,"nL: %f #pm %f" %(nLu2.getValV(),nLu2.getError()),"")
#        self.legend2.AddEntry(0,"aR: %f #pm %f" %(aRu2.getValV(),aRu2.getError()),"")
#        self.legend2.AddEntry(0,"nR: %f #pm %f" %(nRu2.getValV(),nRu2.getError()),"")
        self.norm_u.SetStats(0)
        self.frame_u.SetTitle("p_T Balance")
        self.frame_u.GetXaxis().SetTitle("p_T(j_1)/p_T(Z)")
        self.frame_u.GetYaxis().SetTitle("1/Events")
        self.frame_u.Draw("")
        self.norm_u.Draw("e1 same")
#        h_dh_u.Draw("HIST SAME")
#        h_dh_u.SetLineColor(3)
#        h_CB_u.Draw("HIST SAME")
        self.legend2.Draw("same")
        super().pad_righttop().RedrawAxis()


        super().pad_leftbottom().cd()
        super().info().DrawLatexNDC(0.44, 0.93, info)
        super().logo().DrawLatexNDC(0.15, 0.93, cms_text)
        super().extra_logo().DrawLatexNDC(0.15, 0.90, extra_text)
        self.legend3 = TLegend(0.65, 0.50, 0.93, 0.87)
        self.legend3.SetFillStyle(0)
        self.legend3.SetBorderSize(0)
        self.legend3.Clear()
        self.norm_d.SetLineWidth(2)
        self.norm_d.SetLineColor(7)
        self.legend3.SetTextSize(0.03)
        self.legend3.AddEntry(self.norm_d, "JEC down")
        self.legend3.AddEntry(self.frame_d,"JEC down Fit","L")
        self.legend3.AddEntry(0,"#mu: %f #pm %f" %(mean_d2.getValV(),mean_d2.getError()),"")
        self.legend3.AddEntry(0,"#sigma: %f #pm %f" %(sigma_d2.getValV(),sigma_d2.getError()),"")
#        self.legend3.AddEntry(0,"#chi^2: %f" %chi2_d,"")
        self.legend3.AddEntry(0,"#KS Score: %f" %KS_d,"")
#        self.legend3.AddEntry(0,"NDF: %f" %NDF_u,"")
#        self.legend3.AddEntry(0,"aL: %f #pm %f" %(aLd2.getValV(),aLd2.getError()),"")
#        self.legend3.AddEntry(0,"nL: %f #pm %f" %(nLd2.getValV(),nLd2.getError()),"")
#        self.legend3.AddEntry(0,"aR: %f #pm %f" %(aRd2.getValV(),aRd2.getError()),"")
#        self.legend3.AddEntry(0,"nR: %f #pm %f" %(nRd2.getValV(),nRd2.getError()),"")
        self.norm_d.SetStats(0)
        self.frame_d.SetTitle("p_T Balance")
        self.frame_d.GetXaxis().SetTitle("p_T(j_1)/p_T(Z)")
        self.frame_d.GetYaxis().SetTitle("1/Events")
        self.frame_d.Draw("")
        self.norm_d.Draw("same e1")
#        h_dh_d.Draw("HIST SAME")
#        h_dh_d.SetLineColor(3)
#        h_CB_d.Draw("HIST SAME")
        self.legend3.Draw("same")
        super().pad_leftbottom().RedrawAxis()


        super().pad_rightbottom().cd()
        super().info().DrawLatexNDC(0.44, 0.93, info)
        super().logo().DrawLatexNDC(0.15, 0.93, cms_text)
        super().extra_logo().DrawLatexNDC(0.15, 0.90, extra_text)
        self.legend4 = TLegend(0.65, 0.50, 0.93, 0.87)
        self.legend4.SetFillStyle(0)
        self.legend4.SetBorderSize(0)
        self.legend4.Clear()
        self.norm_o.SetLineWidth(2)
        self.norm_o.SetLineColor(1)
        self.legend4.SetTextSize(0.03)
        self.legend4.AddEntry(self.norm_o, "Data")
        self.legend4.AddEntry(self.frame_o,"Data Fit","L")
        self.legend4.AddEntry(0,"#mu: %f #pm %f" %(mean_o2.getValV(),mean_o2.getError()),"")
        self.legend4.AddEntry(0,"#sigma: %f #pm %f" %(sigma_o2.getValV(),sigma_o2.getError()),"")
#        self.legend4.AddEntry(0,"#chi^2: %f" %chi2_o,"")
        self.legend4.AddEntry(0,"KS Score: %f" %KS_o,"")
#        self.legend4.AddEntry(0,"NDF: %f" %NDF_o,"")
#        self.legend4.AddEntry(0,"aL: %f #pm %f" %(aLo2.getValV(),aLo2.getError()),"")
#        self.legend4.AddEntry(0,"nL: %f #pm %f" %(nLo2.getValV(),nLo2.getError()),"")
#        self.legend4.AddEntry(0,"aR: %f #pm %f" %(aRo2.getValV(),aRo2.getError()),"")
#        self.legend4.AddEntry(0,"nR: %f #pm %f" %(nRo2.getValV(),nRo2.getError()),"")
        self.norm_o.SetStats(0)
        self.frame_o.SetTitle("p_T Balance")
        self.frame_o.GetXaxis().SetTitle("p_T(j_1)/p_T(Z)")
        self.frame_o.GetYaxis().SetTitle("1/Events")
        self.frame_o.Draw("")
        self.norm_o.Draw("same e1")
#        h_CB_o.Draw("HIST SAME")
#        h_dh_o.SetLineColor(3)
#        h_dh_o.Draw("HIST SAME")
        self.legend4.Draw("same")
        super().pad_rightbottom().RedrawAxis()



        super().cvs().cd()
        super().pad_lefttop().Draw()
        super().pad_righttop().Draw()
        super().pad_leftbottom().Draw()
        super().pad_rightbottom().Draw()

        return mean_c2,mean_u2,mean_d2,mean_o2,mean_un2,mean_dn2,mean_nu2,mean_nd2,mean_uu2,mean_dd2,sigma_c2,sigma_u2,sigma_d2,sigma_o2,sigma_un2,sigma_dn2,sigma_nu2,sigma_nd2,sigma_uu2,sigma_dd2


    def combine(self):
        info = self.info_params['info']
        cms_text = self.info_params['cms_text']
        extra_text = self.info_params['extra_text']

        super().set_canvas()
        super().set_logo()
        super().set_info()
        super().pad_up().cd()
        self.hist_obs.SetLineWidth(2)
        '''
        self.hist_obs.DrawNormalized("p&hist")
#        self.stack.Draw("hist&pfc&same")
        self.syst.DrawNormalized("hist&same")
        self.syst_up.DrawNormalized("e2&f&same")
        self.syst_down.DrawNormalized("e2&f&same")
        self.hist_obs.DrawNormalized("p&hist&same")
        self.hist_obs.DrawNormalized("e1&same")
        '''
        maximum = self.hist_obs.GetMaximum()
        self.hist_obs.GetYaxis().SetRangeUser(0, maximum*2.2)
        if self.logy:
            self.hist_obs.GetYaxis().SetRangeUser(1, maximum*30)
        self.hist_obs.Draw("p&hist")
        self.stack.Draw("hist&pfc&same")
        self.syst.Draw("e2&f&same")
        self.syst_up.Draw("e2&f&same")
        self.syst_down.Draw("e2&f&same")
        self.hist_obs.Draw("p&hist&same")
        self.hist_obs.Draw("e1&same")
        
        self.legend.Draw()
        super().info().DrawLatexNDC(0.74, 0.91, info)
        super().logo().DrawLatexNDC(0.15, 0.83, cms_text)
        super().extra_logo().DrawLatexNDC(0.15, 0.78, extra_text)
        super().pad_up().RedrawAxis()

        super().pad_down().cd()
        self.ratio.SetLineWidth(2)
        
        self.ratio_syst.Draw("e2&f")
        self.ratio_syst_up.Draw("e2&f")
        self.ratio_syst_down.Draw("e2&f&same")
        self.ratio.Draw("pe & hist & same")
        '''
        self.ratio_syst.DrawNormalized("e2&f")
        self.ratio_syst_up.DrawNormalized("e2&f")
        self.ratio_syst_down.DrawNormalized("e2&f&same")
        self.ratio.DrawNormalized("pe & hist & same")
        '''
        super().pad_down().RedrawAxis()

        super().cvs().cd()
        super().pad_up().Draw()
        super().pad_down().Draw()

