#include "HNL_LeptonCore.h"


void HNL_LeptonCore::FillEventCutflowAll(TString analysis_dir_name,TString histname, double weight, vector<TString> lables, TString label){
  FillEventCutflowDef(analysis_dir_name,histname, weight,lables, label);
  if(!IsData)FillEventCutflowDef(analysis_dir_name,histname+"_no_weight",1.,lables, label);                                                                                                                                                                                   

}
void HNL_LeptonCore::FillEventCutflowDef(TString analysis_dir_name,TString histname, double weight, vector<TString> lables, TString label){

  char end_str = string(analysis_dir_name).back();

  if ( end_str  == '/') {
    cout << "[HNL_LeptonCore::FillEventCutflowDef ] ERROR in assiging Hist name, remove / from end " << endl;
    cout << analysis_dir_name << endl;
    exit(EXIT_FAILURE);

  }
  TH1D *this_hist = GetHist1D(analysis_dir_name+"/"+histname);

  if( !this_hist ){
    TString cf_name="FillEventCutflow";

    if(histname.Contains("SR")) cf_name="LimitBins/";
    if(histname.Contains("_massbinned")) cf_name="FillEventCutflow_MassBinned";
    if(!analysis_dir_name.Contains("ChannelCutFlow"))  cf_name = analysis_dir_name + "/"+cf_name;
    else cf_name = analysis_dir_name;

    this_hist = new TH1D(cf_name+"/"+histname, "", lables.size(), 0, lables.size());
    for (unsigned int i=0 ; i < lables.size(); i++)  this_hist->GetXaxis()->SetBinLabel(i+1,lables[i]);
    this_hist->SetDirectory(NULL);

    maphist_TH1D[analysis_dir_name+"/"+histname] = this_hist;
  }
  this_hist->Fill(label, weight);

}




void HNL_LeptonCore::FillEventCutflow(HNL_LeptonCore::SearchRegion sr, double event_weight, TString label,   TString analysis_dir_name, AnalyzerParameter param){
  
  FillEventCutflow(sr, event_weight, label, analysis_dir_name+"/"+param.Channel, param.WriteOutVerbose);
  FillEventCutflow(sr, event_weight, label, analysis_dir_name+"/"+param.InclusiveChannel, param.WriteOutVerbose);
  return;
}


void HNL_LeptonCore::FillEventCutflow(HNL_LeptonCore::SearchRegion sr, double event_weight, TString label,   TString analysis_dir_name, int verbose_level){



  if (run_Debug) cout << "FillEventCutflow " << label << " " << analysis_dir_name <<  endl;

  vector<TString> labels;
  TString EVhitname("");

  if (verbose_level < 0) return;

  if (verbose_level == 0) {

    if(sr==SR1 ){
      labels = {  "SR1_Init",
                  "SR1_lep_charge",
                  "SR1_lep_pt",
                  "SR1_dilep_mass" ,
                  "SR1_1AK8" ,
                  "SR1_MET" ,
                  "SR1_Wmass",
                  "SR1_bveto",
                  "SR1_Lep2Pt",
                  "SR1_PNTagger",
                  "SR1_LepPt",
                  "SR1_DphiN_Wlep",
                  "SR1_TauVeto",
                  "SR1_HTPt",
                  "SR1_masscuts" };
      EVhitname= "Cutflow_SR1";
    }

    if(sr==SR2){
      labels = {  "SR2_lep_charge",
                  "SR2_lep_pt",
                  "SR2_DPhi",
                  "SR2_LLMass",
                  "SR2_DiJet",
                  "SR2_DiJetEta",
                  "SR2_DiJetMass",
                  "SR2_VBF",
                  "SR2_met",
                  "SR2_ht_lt1",
                  "SR2_bveto",
                  "SR2_Final"};
      EVhitname= "Cutflow_SR2";
    }

    if( sr==SR3Fail){
      labels = {
        "SR3_2vl",
        "SR3_mll",
        "SR3_bveto",
        "SR3_met",
        "SR3_dijet",
        "SR3_0jpt",
        "SR3_Wmass300",
        "SR3_leppt",
        "SR3_Wmass400",
        "SR3_Nmass300"};

      EVhitname= "Cutflow_SR3Fail";

    }
    if( sr==SR3){
      labels = { "SR3_lep_charge" ,
                 "SR3_lep_pt",
                 "SR3_dilep_mass",
                 "SR3_bveto",
                 "SR3_MET",
                 "SR3_0JetBin",
                 "SR3_1JetBin",
                 "SR3_jet",
                 "SR3_dijet",
                 "SR3_J1Pt",
                 "SR3_W1Mass",
                 "SR3_LepPt"
      };

      EVhitname= "Cutflow_SR3";
    }

    if(sr==MuonSRSummary){

      labels = {"Inclusive",
                "GenMatch",
                "CheckLeptonFlavourForChannel",
                "METFilter",
                "CFCut",
                "Preselection",
                "AK8",
                "SigReg1",
                "SigReg1Fail",
                "SigReg2",
                "SigReg3",
                "SigReg3Pass",
                "SigReg3Fail"};

      EVhitname= "Cutflow_Summary_Muon";

    }
    if( sr==SR3BDT){
      labels = {  "SR3_lep_charge" ,
                  "SR3_lep_pt",
                  "SR3_dilep_mass",
                  "SR3_jet",
                  "SR3_dijet",
                  "SR3_Wmass",
                  "SR3_J1Pt",
                  "SR3_MET",
                  "SR3_bveto"};
      EVhitname= "Cutflow_SR3BDT";
    }

    if(sr==PreselSS || sr==Presel ){
      labels = {"NoCut", "METFilter", "Trigger", "Dilepton","SS_Dilep" ,"SS_lep_veto", "SS_Dilep_mass", "SS_Presel"};
      EVhitname = "SS_Presel";
    }
    if(sr==PreselOS || sr==Presel ){
      labels = {"NoCut", "METFilter", "Trigger", "Dilepton", "OS_Dilep" ,"OS_lep_veto", "OS_Dilep_mass", "OS_Presel"};
      EVhitname ="OS_Presel";
    }
    if(sr==ChannelDepInc ){
      labels = {"MuMu_NoCut","EE_NoCut","EMu_NoCut"};
      EVhitname ="ChannelDependant_Inclusive";
    }
    if(sr==ChannelDepIncQ ){
      labels = {"MuMu_MMQ_NoCut","MuMu_PPQ_NoCut", "EE_MMQ_NoCut",  "EE_PPQ_NoCut","EMu_MMQ_NoCut", "EMu_PPQ_NoCut"};
      EVhitname ="ChannelDependantQQ_Inclusive";
    }
    if(sr==ChannelDepDilep){
      labels = {"MuMu_Dilep","EE_Dilep","EMu_Dilep"};
      EVhitname ="ChannelDependantDilep";
    }
    if(sr==ChannelDepTrigger){
      labels = {"MuMu_Trigger","EE_Trigger","EMu_Trigger", "MuMu_MultiTrigger","EE_MultiTrigger","EMu_MultiTrigger"};
      EVhitname ="ChannelDependantTrigger";
    }
    if(sr==ChannelDepPresel){
      labels = {"MuMu_Presel","EE_Presel","EMu_Presel"};
      EVhitname ="ChannelDependantPresel";
    }

    if(sr==ChannelDepSR1){
      labels = {"MuMu_SR1","EE_SR1","EMu_SR1"};
      EVhitname ="ChannelDependantSR1";
    }
    if(sr==ChannelDepSR2){
      labels = {"MuMu_SR2","EE_SR2","EMu_SR2"};
      EVhitname ="ChannelDependantSR2";
    }

    if(sr==ChannelDepSR3){
      labels = {"MuMu_SR3","EE_SR3","EMu_SR3"};
      EVhitname ="ChannelDependantSR3";
    }

    if(sr==ChannelDepFAILSR3){
      labels = {"MuMu_SR3Fail_0j","MuMu_SR3Fail_1j","MuMu_SR3Fail_2j", "EE_SR3Fail_0j","EE_SR3Fail_1j","EE_SR3Fail_2j","EMu_SR3Fail_0j","EMu_SR3Fail_1j","EMu_SR3Fail_2j"};
      EVhitname ="ChannelDependantSR3Fail";
    }

    if(sr==SR){
      labels = {"SR1Pass","SR1Fail","SR2Pass","SR2Fail","SR3Pass","SR3Fail","SR4Pass","SR4Fail"
      };
      EVhitname ="SR_Summary";
    }

    if(sr==ChannelDepCR1){
      labels = {"MuMu_CR1","EE_CR1","EMu_CR1"};
      EVhitname ="ChannelDependantCR1";
    }
    if(sr==ChannelDepCR2){
      labels = {"MuMu_CR2","EE_CR2","EMu_CR2"};
      EVhitname ="ChannelDependantCR2";
    }

    if(sr==ChannelDepCR3){
      labels = {"MuMu_CR3","EE_CR3","EMu_CR3"};
      EVhitname ="ChannelDependantCR3";
    }

    if(sr == ControlRegion){
      labels = {"NoCut","HEMVeto","METFilter","GENMatched","LeptonFlavour","Trigger","OS_VR","VV_VR","VG_VR","SS_CR"};
      EVhitname = "ValidationRegionFlow";

    }

  }

  if(verbose_level >= 0){

    vector<TString> SRlabels = {"SR1_MNbin1","SR1_MNbin2","SR1_MNbin3","SR1_MNbin4","SR1_MNbin5", "SR1_MNbin6","SR1_MNbin7","SR1_MNbin8",
                                "SR2_HTLTbin1", "SR2_HTLTbin2",
                                "SR3_bin1","SR3_bin2","SR3_bin3","SR3_bin4","SR3_bin5","SR3_bin6","SR3_bin7","SR3_bin8", "SR3_bin9","SR3_bin10","SR3_bin11"};
    vector<TString> SRQlabels=  {"QMSR1_MNbin1","QMSR1_MNbin2","QMSR1_MNbin3","QMSR1_MNbin4","QMSR1_MNbin5","QMSR1_MNbin6","QMSR1_MNbin7","QMSR2_HTLTbin1", "QMSR2_HTLTbin2",  "QMSR3_bin1","QMSR3_bin2","QMSR3_bin3","QMSR3_bin4","QMSR3_bin5","QMSR3_bin6","QMSR3_bin7",  "QPSR1_MNbin1","QPSR1_MNbin2","QPSR1_MNbin3","QPSR1_MNbin4","QPSR1_MNbin5","QPSR1_MNbin6","QPSR1_MNbin7","QPSR2_HTLTbin1","QPSR2_HTLTbin2",  "QPSR3_bin1","QPSR3_bin2","QPSR3_bin3","QPSR3_bin4","QPSR3_bin5","Q\
PSR3_bin6","QPSR3_bin7"};
    vector<TString> SRBDTlabels=  {"SR1_MNbin1","SR1_MNbin2","SR1_MNbin3","SR1_MNbin4","SR1_MNbin5","SR1_MNbin6","SR1_MNbin7","SR1_MNbin8",
                                   "SR2_HTLTbin1", "SR2_HTLTbin2",
                                   "SR3_BDTbin1","SR3_BDTbin2","SR3_BDTbin3","SR3_BDTbin4","SR3_BDTbin5","SR3_BDTbin6","SR3_BDTbin7","SR3_BDTbin8","SR3_BDTbin9"};


    vector<TString> SRlabelsOpt = {"SR1_MNbin1","SR1_MNbin2","SR1_MNbin3","SR1_MNbin4",
				   "SR2_HTLTbin1", "SR2_HTLTbin2",
				   "SR3_bin1","SR3_bin2","SR3_bin3","SR3_bin4","SR3_bin5","SR3_bin6","SR3_bin7","SR3_bin8", "SR3_bin9","SR3_bin10","SR3_bin11"};
    vector<TString> SRBDTlabelsOpt=  {"SR1_MNbin1","SR1_MNbin2","SR1_MNbin3","SR1_MNbin4",
				      "SR2_HTLTbin1", "SR2_HTLTbin2",
				      "SR3_BDTbin1","SR3_BDTbin2","SR3_BDTbin3","SR3_BDTbin4","SR3_BDTbin5","SR3_BDTbin6","SR3_BDTbin7"};

    ///// STANDARD ANALYSIS LIMIT LABELS                                                                                                                                                                                                                                                                                                                                                                                                                                                     
    if(sr==MuonSR    || sr==ElectronSR    || sr==ElectronMuonSR)       labels = SRlabels;
    ///// STANDARD ANALYSIS LIMIT LABELS WITH CHARGE SPLIT                                                                                                                                                                                                                                                                                                                                                                                                                                   
    if(sr==MuonSRQQ  || sr==ElectronSRQQ  || sr==ElectronMuonSRQQ)     labels = SRQlabels;
    ///// STANDARD ANALYSIS LIMIT LABELS FOR BDT MASSES                                                                                                                                                                                                                                                                                                                                                                                                                                      
    if(sr==MuonSRBDT || sr==ElectronSRBDT || sr==ElectronMuonSRBDT)    labels = SRBDTlabels ;

    //// OPTIMISING LIMIT PLOTS                                                                                                                                                                                                                                                                                                                                                                                                                                                              
    if(sr==MuonSRBDTOpt || sr==ElectronSRBDTOpt || sr==ElectronMuonSRBDTOpt)    labels = SRBDTlabelsOpt ;
    if(sr==MuonSROpt    || sr==ElectronSROpt    || sr==ElectronMuonSROpt)       labels = SRlabelsOpt;

    //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
    if(sr==MuonSR         || sr==MuonSRBDT         || sr==MuonSROpt         || sr==MuonSRBDTOpt)         EVhitname ="MuonSR";
    if(sr==ElectronSR     || sr==ElectronSRBDT     || sr==ElectronSROpt     || sr==ElectronSRBDTOpt)     EVhitname ="ElectronSR";
    if(sr==ElectronMuonSR || sr==ElectronMuonSRBDT || sr==ElectronMuonSROpt || sr==ElectronMuonSRBDTOpt) EVhitname ="ElectronMuonSR";
    //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
    if(sr==MuonSRQQ )       EVhitname ="MuonChargeSplitSR";
    if(sr==ElectronSRQQ)    EVhitname ="ElectronChargeSplitSR";
    if(sr==ElectronMuonSRQQ)EVhitname ="ElectronMuonChargeSplitSR";

  }


  if(verbose_level==0){
    if(sr==CR){

      labels = { "Z_CR","Top_CR","Top_CR2", "TopAK8_CR","ZAK8_CR","WpWp_CR1","WpWp_CR2","WpWp_CRNP","WpWp_CRNP2","ZZ_CR","ZZLoose_CR","ZG_CR","WG_CR","WZ_CR","WG_Method2_CR","ZG_Method2_CR","WZ2_CR","WZB_CR","HighMassSR1_CR","HighMassSR2_CR","HighMassSR3_CR" ,"HighMass1Jet_CR","HighMassBJet_CR","HighMassNP_CR","ZNP_CR","SSPresel","SSVBFPresel"};


      EVhitname ="ControlRegions";
    }

    if(sr==SR1Tau ){
      vector<TString> JID = {"JetVVL","JetVL","JetL","JetM","JetT","JetVT","JetVVT"};
      vector<TString> ElID = {"ElVVL","ElVL","ElL","ElM","ElT","ElVT","ElVVT"};
      vector<TString> MuID = {"MuVL","MuL","MuM","MuT"};
      labels = {"SR1"};
      for(auto ij :  JID){
        for(auto iel : ElID){
          for(auto imu : MuID){
            TString TID=ij+"_"+iel+"_"+imu;
            labels.push_back(TID);
          }
        }
      }
      EVhitname= "SR1Tau";
    }

    if(sr==SR2Tau ){
      vector<TString> JID = {"JetVVL","JetVL","JetL","JetM","JetT","JetVT","JetVVT"};
      vector<TString> ElID = {"ElVVL","ElVL","ElL","ElM","ElT","ElVT","ElVVT"};
      vector<TString> MuID = {"MuVL","MuL","MuM","MuT"};
      labels = {"SR2"};
      for(auto ij :  JID){
        for(auto iel : ElID){
          for(auto imu : MuID){
            TString TID=ij+"_"+iel+"_"+imu;
            labels.push_back(TID);
          }
        }
      }
      EVhitname= "SR2Tau";
    }

    if(sr==SR3Tau ){
      vector<TString> JID = {"JetVVL","JetVL","JetL","JetM","JetT","JetVT","JetVVT"};
      vector<TString> ElID = {"ElVVL","ElVL","ElL","ElM","ElT","ElVT","ElVVT"};
      vector<TString> MuID = {"MuVL","MuL","MuM","MuT"};
      labels = {"SR3"};
      for(auto ij :  JID){
        for(auto iel : ElID){
          for(auto imu : MuID){
            TString TID=ij+"_"+iel+"_"+imu;
            labels.push_back(TID);
          }
        }
      }
      EVhitname= "SR3Tau";
    }
    if(sr==sigmm){
      labels = {"SSNoCut", "SSGen", "SSGen2", "SSMuMuTrig", "SSMuMuTrig2", "SSMuMuTrig2L", "SSMuMu", "SSMuMu_Pt", "SSMuMu_HEMVeto","SSMuMu_LepVeto", "SSMuMu_LLMass",  "SSMuMu_vTau","SSMuMu_Jet","SSMuMu_BJet", "SSMuMu_DiJet",  "SSMuMu_SR1","SSMuMu_SR1Fail", "SSMuMu_SR2","SSMuMu_SR3","SSMuMu_SR4","SSMuMu_SR5","SSMuMu_SR3Fail"};
      EVhitname ="SR_Summary";
    }

    if(sr==sigmm_17028){
      labels = {"SSNoCut", "SSGen","SSGen2", "SSMuMuTrig", "SSMuMuTrig2","SSMuMuTrig2L" , "SSMuMu","SSMuMu_Pt", "SSMuMu_HEMVeto","SSMuMu_LepVeto", "SSMuMu_LLMass", "SSMuMu_Jet", "SSMuMu_BJet", "SSMuMu_DiJet",  "SSMuMu_SR1","SSMuMu_SR1Fail","SSMuMu_SR3","SSMuMu_SR3Fail"};
      EVhitname ="SR_Summary_17028";
    }

    if(sr==sigee){
      labels = {"SSNoCut", "SSGen", "SSGen2", "SSEETrig", "SSEETrig2", "SSEETrig2L","SSEE", "SSEE_Pt","SSEE_LepVeto", "SSEE_HEMVeto","SSEE_LLMass",  "SSEE_vTau","SSEE_Jet","SSEE_BJet", "SSEE_DiJet",  "SSEE_SR1","SSEE_SR1Fail", "SSEE_SR2","SSEE_SR3","SSEE_SR4","SSEE_SR5","SSEE_SR3Fail"};
      EVhitname ="SR_Summary";
    }

    if(sr==sigee_17028){
      labels = {"SSNoCut", "SSGen","SSGen2", "SSEETrig", "SSEETrig2", "SSEETrig2L", "SSEE","SSEE_Pt", "SSEE_HEMVeto", "SSEE_LepVeto", "SSEE_LLMass", "SSEE_Jet", "SSEE_BJet", "SSEE_DiJet",  "SSEE_SR1","SSEE_SR1Fail","SSEE_SR3","SSEE_SR3Fail"};
      EVhitname ="SR_Summary_17028";
    }



    if(sr==sigem){
      labels = {"SSNoCut", "SSGen", "SSGen2", "SSEMuTrig", "SSEMuTrig2","SSEMuTrig2L","SSEMu", "SSEMu_Pt","SSEMu_LepVeto", "SSEMu_LLMass",  "SSEMu_vTau","SSEMu_Jet","SSEMu_BJet", "SSEMu_DiJet",  "SSEMu_SR1","SSEMu_SR1Fail", "SSEMu_SR2","SSEMu_SR3","SSEMu_SR4","SSEMu_SR5","SSEMu_SR3Fail"};
      EVhitname ="SR_Summary";
    }

    if(sr==sigem_17028){
      labels = {"SSNoCut", "SSGen","SSGen2", "SSEMuTrig", "SSEMuTrig2", "SSEMuTrig2L", "SSEMu","SSEMu_Pt", "SSEMu_LepVeto", "SSEMu_LLMass", "SSEMu_Jet", "SSEMu_BJet", "SSEMu_DiJet",  "SSEMu_SR1","SSEMu_SR1Fail","SSEMu_SR3","SSEMu_SR3Fail"};
      EVhitname ="SR_Summary_17028";
    }

  }

  if(labels.size() == 0) return;

  HNL_LeptonCore::FillEventCutflowAll(analysis_dir_name,EVhitname, event_weight, labels, label);

  return;
}



void HNL_LeptonCore::FillEventCutflowPerMass(TString analysis_dir_name,SearchRegion sr, double event_weight, TString label,   TString massname){

  if(sr==SR3 ){

    vector<TString> labels = {
      "SR3_default",
      "SR3_jetsize",
      "SR3_jetpt",
      "SR3_W_DR_lep2",
      "SR3_lepPt1",
      "SR3_lepPt2",
      "SR3_Wmass_Low",
      "SR3_Wmass_High",
      "SR3_lljj",
      "SR3_Nmass_Low",
      "SR3_Nmass_High",
      "SR3_MET"};

    if(run_Debug)  cout << "FillEventCutflowAll : " << analysis_dir_name+"_SR3" << " " << label << endl;
    HNL_LeptonCore::FillEventCutflowAll(analysis_dir_name,"Massopt_"+massname, event_weight, labels, label);
  }



  if(sr== SR1 ){

    vector<TString> labels = {
      "SR1_default",
      "SR1_lepPt1",
      "SR1_lepPt2",
      "SR1_SDmass_Low",
      "SR1_SDmass_High",
      "SR1_Nmass_Low",
      "SR1_Nmass_High",
      "SR1_MET"};

    if(run_Debug)  cout << "FillEventCutflowAll : " << analysis_dir_name+"_SR1" << " " << label << endl;
    HNL_LeptonCore::FillEventCutflowAll(analysis_dir_name,"Massopt_"+massname, event_weight, labels, label);
  }


  return;

}



void HNL_LeptonCore::FillEventCutflowSR(TString analysis_dir_name,HNL_LeptonCore::SearchRegion sr, double event_weight, TString label){

  vector<TString> masses = {"100","125","200","250","300","400","500","600","700","800","900","1000","1100","1200","1300","1400","1500","1700","2000","2500","5000","20000"};



  if(sr== SR1){
    vector<TString> labels;
    for (unsigned int x=0; x < masses.size(); x++) labels.push_back("HNL_SR1_mn"+masses[x] );
    TString histname = "SR1_massbinned";
    HNL_LeptonCore::FillEventCutflowAll(analysis_dir_name,histname, event_weight, labels, label);
  }

  if(sr== SR2){
    vector<TString> labels;
    for (unsigned int x=0; x < masses.size(); x++) labels.push_back("HNL_SR2_mn"+masses[x] );
    TString histname = "SR2_massbinned";
    HNL_LeptonCore::FillEventCutflowAll(analysis_dir_name,histname, event_weight, labels, label);
  }
  if(sr == SR3){
    vector<TString> labels;
    for (unsigned int x=0; x < masses.size(); x++) labels.push_back("HNL_SR3_mn"+masses[x] );
    TString histname = "SR3_massbinned";
    HNL_LeptonCore::FillEventCutflowAll(analysis_dir_name,histname, event_weight, labels, label);

  }

  return;

}

void HNL_LeptonCore::FillFullTypeCutflow(TString histname, double weight, vector<TString> lables, TString label1, TString label2){

  TH2D *this_hist = GetHist2D(histname);
  if( !this_hist ){
    this_hist = new TH2D("FillEventFullType/"+histname, "", lables.size(), 0, lables.size(),  lables.size(), 0, lables.size());
    this_hist->SetDirectory(NULL);
    for (unsigned int i=0 ; i < lables.size(); i++)  this_hist->GetXaxis()->SetBinLabel(i+1,lables[i]);
    for (unsigned int i=0 ; i < lables.size(); i++)  this_hist->GetYaxis()->SetBinLabel(i+1,lables[i]);

    maphist_TH2D[histname] = this_hist;
  }

  this_hist->Fill(label1, label2, fabs(weight));

}


void HNL_LeptonCore::FillTypeCutflow(TString histname, double weight, vector<TString> lables, TString label1, TString label2){

  TH2D *this_hist = GetHist2D(histname);
  if( !this_hist ){
    this_hist = new TH2D("CR2DCutflow/"+histname, "", lables.size(), 0, lables.size(),  lables.size(), 0, lables.size());
    this_hist->SetDirectory(NULL);
    for (unsigned int i=0 ; i < lables.size(); i++)  this_hist->GetXaxis()->SetBinLabel(i+1,lables[i]);
    for (unsigned int i=0 ; i < lables.size(); i++)  this_hist->GetYaxis()->SetBinLabel(i+1,lables[i]);

    maphist_TH2D[histname] = this_hist;
  }

  this_hist->Fill(label1, label2, fabs(weight));

}


void HNL_LeptonCore::FillCutFlow(bool IsCentral, TString suffix, TString histname, double ev_weight){

  if(IsCentral)   FillHist(suffix+"/"+histname, 0., ev_weight, 1, 0., 1.);

  return ;
}
