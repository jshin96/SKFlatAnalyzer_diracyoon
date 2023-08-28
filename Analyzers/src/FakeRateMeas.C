#include "FakeRateMeas.h"

void FakeRateMeas::initializeAnalyzer(){

  ElFR=false, MuFR=false, MeasFR=false, MeasPU=false, PrVal=false, METMTWCut=false;
  SystRun=false, ConePtCut=false; 
  for(unsigned int i=0; i<Userflags.size(); i++){
    if(Userflags.at(i).Contains("ElFR"))      ElFR      = true; 
    if(Userflags.at(i).Contains("MuFR"))      MuFR      = true; 
    if(Userflags.at(i).Contains("MeasFR"))    MeasFR    = true; 
    if(Userflags.at(i).Contains("MeasPU"))    MeasPU    = true; 
    if(Userflags.at(i).Contains("METMTWCut")) METMTWCut = true; 
    if(Userflags.at(i).Contains("PrVal"))     PrVal     = true; 
    if(Userflags.at(i).Contains("ConePtCut")) ConePtCut = true; 
    if(Userflags.at(i).Contains("SystRun"))   SystRun   = true; 
  }

  DblMu=false, DblEG=false, MuEG=false, SglMu=false, SglEl=false;
  if     (DataStream.Contains("DoubleMuon"))     DblMu=true;
  else if(DataStream.Contains("MuonEG"))         MuEG =true;
  else if(DataStream.Contains("DoubleEG"))       DblEG=true;
  else if(DataStream.Contains("SingleMuon"))     SglMu=true;
  else if(DataStream.Contains("SingleElectron")) SglEl=true;
  else if(DataStream.Contains("EGamma"))         SglEl=true;

  //Mu8 Mu17 : 16-DblMu, 17-DblMu, 18-DblMu
  //Mu3      : 16-DblMu, 17-SglMu, 18-SglMu
  //El8,12,23: 16-DblEG, 17-SglEl, 18-EGM
  if(IsDATA){
    if(DataYear==2016){ 
      if(DblMu) TrigList_MuFR = {"HLT_Mu17_TrkIsoVVL_v", "HLT_Mu8_TrkIsoVVL_v", "HLT_Mu3_PFJet40_v"};
      if(DblEG) TrigList_ElFR = {"HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v", "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v", "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v"};
    }
    else if(DataYear==2017){
      if(DblMu) TrigList_MuFR = {"HLT_Mu17_TrkIsoVVL_v", "HLT_Mu8_TrkIsoVVL_v"};
      if(SglMu) TrigList_MuFR = {"HLT_Mu3_PFJet40_v"};
      if(SglEl) TrigList_ElFR = {"HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v", "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v", "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v"};
    }
    else if(DataYear==2018){
      if(DblMu) TrigList_MuFR = {"HLT_Mu17_TrkIsoVVL_v", "HLT_Mu8_TrkIsoVVL_v"};
      if(SglMu) TrigList_MuFR = {"HLT_Mu3_PFJet40_v"};
      if(SglEl) TrigList_ElFR = {"HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v", "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v", "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v"};
    }
  }
  else{
    TrigList_MuFR.push_back("HLT_Mu17_TrkIsoVVL_v");
    TrigList_MuFR.push_back("HLT_Mu8_TrkIsoVVL_v");
    TrigList_MuFR.push_back("HLT_Mu3_PFJet40_v");
  
    TrigList_ElFR.push_back("HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v");
    TrigList_ElFR.push_back("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v");
    TrigList_ElFR.push_back("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v");
  }

  //Set up the tagger map only for the param settings to be used.
  std::vector<JetTagging::Parameters> jtps;
  jtps.push_back( JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets) );
  mcCorr->SetJetTaggingParameters(jtps);


  TString AnalyzerPath=getenv("SKFlat_WD"), SKFlatV = getenv("SKFlatV");
  TString FRType = ElFR? "ElFR":MuFR? "MuFR":"";
  TString FilePath="/data/"+SKFlatV+"/"+GetEra()+"/FakeRate/NvtxSF/"+FRType+"/";
  NvtxSFFile = new TFile(AnalyzerPath+FilePath+"NvtxSF_"+GetEraShort()+".root");

}


void FakeRateMeas::executeEvent(){


  Event ev = GetEvent();
  float weight = 1., w_GenNorm=1., w_BR=1., w_PU=1.;
  if(!IsDATA){
    w_GenNorm = MCweight()*GetKFactor()*ev.GetTriggerLumi("Full");
    w_BR      = GetBRWeight();
    w_PU      = GetPileUpWeight(nPileUp, 0);
    weight *= w_GenNorm * w_BR * w_PU;
  }
  FillHist("CutFlow", 0., weight, 20, 0., 20.);

  bool PassTrig=false;
  if     (MuFR){ PassTrig = ev.PassTrigger(TrigList_MuFR); }
  else if(ElFR){ PassTrig = ev.PassTrigger(TrigList_ElFR); }
  if(!PassTrig) return;
  FillHist("CutFlow", 1., weight, 20, 0., 20.);
  if(!PassMETFilter()) return;
  FillHist("CutFlow", 2., weight, 20, 0., 20.);

  bool PreCutPass=false;
  vector<Muon>     muonPreColl     = GetMuons("NOCUT", 5., 2.4);
  vector<Electron> electronPreColl = GetElectrons("NOCUT", 5., 2.5);
  sort(muonPreColl.begin(), muonPreColl.end(), PtComparing);
  sort(electronPreColl.begin(), electronPreColl.end(), PtComparing);
  if     (MuFR and muonPreColl.size()>0    ) PreCutPass=true;
  else if(ElFR and electronPreColl.size()>0) PreCutPass=true;
  if(!PreCutPass) return;


  TString IDSSLabel = "SS"; float PTminMu = MuFR && ConePtCut? 5.:10.; 
  TString MuTID="TopHNT", MuLID="TopHNL";
  TString ElTID="TopHNSST", ElLID="TopHNSSL_"+GetEraShort(), ElVID="TopHNL_"+GetEraShort();
  vector<Muon>     muonTightColl     = SelectMuons(muonPreColl, MuTID, PTminMu, 2.4);
  vector<Electron> electronTightColl = SelectElectrons(electronPreColl, ElTID, 10., 2.5);
  vector<Muon>     muonLooseColl     = SelectMuons(muonPreColl, MuLID, PTminMu, 2.4);
  vector<Electron> electronLooseColl = SelectElectrons(electronPreColl, ElLID, 10., 2.5);
  vector<Electron> electronVetoColl  = SelectElectrons(electronPreColl, ElVID, 10., 2.5);


  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
  vector<Jet> jetPreColl = GetAllJets();
  sort(jetPreColl.begin(), jetPreColl.end(), PtComparing);
  vector<Jet> jetColl  = SelectJets(jetPreColl, muonLooseColl, electronVetoColl, "tightLepVeto", 25., 2.4, "LVeto");
  vector<Jet> bjetColl = SelBJets(jetColl, param_jets);


  Particle vMET_T1xy = GetvMET("PUPPIMETT1xyCorr");

  std::vector<Gen> truthColl;

  bool EventCand = false;
  if     (MuFR){ EventCand = muonLooseColl.size()>0; }
  else if(ElFR){ EventCand = electronVetoColl.size()>0; }

  float w_TopPtRW = 1., w_Prefire = 1., sf_Trig = 1.;
  float sf_MuTk = 1., sf_MuID = 1., sf_MuIso = 1., sf_ElReco = 1., sf_ElID = 1., sf_BTag = 1.;
  float sf_mu17 = 1, sf_mu8 = 1., sf_el23 = 1., sf_el12 = 1.;
  float nvtxRW_El23 = 1., nvtxRW_El12 = 1., nvtxRW_El8 = 1., nvtxRW_Mu17 = 1., nvtxRW_Mu8 = 1., nvtxRW_Mu3 = 1.;
  float w_Norm_El23 = 1., w_Norm_El12 = 1., w_Norm_El8 = 1., w_Norm_Mu17 = 1., w_Norm_Mu8 = 1., w_Norm_Mu3 = 1.;
  if((!IsDATA) and EventCand){
    //if(MCSample.Contains("TT") and MCSample.Contains("powheg")) truthColl = GetGens();
    //w_TopPtRW = mcCorr->GetTopPtReweight(truthColl);
    sf_MuID   = GetMuonSF(muonTightColl, MuTID, "ID");
    sf_ElReco = GetElectronSF(electronVetoColl, "", "Reco");
    sf_ElID   = GetElectronSF(electronTightColl, ElTID, "ID");
    sf_BTag   = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets);
    sf_mu17   = 1.; //mcCorr->GetTriggerSF(electronTightColl, muonTightColl, "Mu17Leg_MMTr", "");
    sf_mu8    = 1.; //mcCorr->GetTriggerSF(electronTightColl, muonTightColl, "Mu8Leg_MMTr", "");
    sf_el23   = 1.; //mcCorr->GetTriggerSF(electronTightColl, muonTightColl, "Ele23Leg_EETr", "");//[1]
    sf_el12   = 1.; //mcCorr->GetTriggerSF(electronTightColl, muonTightColl, "Ele12Leg_EETr", "");//[1]
    w_Prefire = GetPrefireWeight(0);
    TString PtTag = !ConePtCut? "_Pt15":"_Pt10";
    nvtxRW_El23   = ElFR && !MeasPU? GetNvtxReweight(nPV, "NPV_1j_TrigEl23"+PtTag+"_Ratio"):1.;
    nvtxRW_El12   = ElFR && !MeasPU? GetNvtxReweight(nPV, "NPV_1j_TrigEl12"+PtTag+"_Ratio"):1.;
    nvtxRW_El8    = ElFR && ((!MeasPU) && ConePtCut)? GetNvtxReweight(nPV, "NPV_1j_TrigEl8"+PtTag+"_Ratio"):1.;
    nvtxRW_Mu17   = MuFR && !MeasPU? GetNvtxReweight(nPV, "NPV_1j_TrigMu17_Ratio"):1.;
    nvtxRW_Mu8    = MuFR && !MeasPU? GetNvtxReweight(nPV, "NPV_1j_TrigMu8_Ratio"):1.;
    nvtxRW_Mu3    = MuFR && ((!MeasPU) && ConePtCut)? GetNvtxReweight(nPV, "NPV_1j_TrigMu3_Ratio"):1.;
    w_Norm_El23 = GetResidualNormSF("El23"+PtTag, GetEraShort());
    w_Norm_El12 = GetResidualNormSF("El12"+PtTag, GetEraShort());
    w_Norm_El8  = ConePtCut? GetResidualNormSF("El8" +PtTag, GetEraShort()):1.;
    w_Norm_Mu17 = GetResidualNormSF("Mu17", GetEraShort());
    w_Norm_Mu8  = GetResidualNormSF("Mu8", GetEraShort());
    w_Norm_Mu3  = GetResidualNormSF("Mu3", GetEraShort());
    //cout<<"w_gen:"<<w_gen<<" w_lumi:"<<w_lumi<<" w_PU:"<<w_PU<<" w_Prefire:"<<w_Prefire<<" sf_Trig:"<<sf_Trig<<endl;
    //cout<<"sf_MuTk"<<sf_MuTk<<" sf_MuID:"<<sf_MuID<<" sf_MuIso:"<<sf_MuIso<<" sf_ElReco:"<<sf_ElReco<<" sf_ElID:"<<sf_ElID<<" sf_BTag:"<<sf_BTag<<endl;
  }
  weight *= w_TopPtRW * w_Prefire * sf_Trig;
  weight *= sf_MuTk * sf_MuID * sf_MuIso * sf_ElReco * sf_ElID * sf_BTag;
  //[1] not applying SF, as kinematic dependent SF is only meaningful near turn-on, dominated by L1 eff,
  //    but they are seeded from completely different L1 paths. SF beyond turn-on region is practically constant.
  //    Also I checked shape agreement is better w/o SF. Henceforth, not applied though machinery is ready.


 
  if(MuFR){
    vector<TString> OptList, LIDList;
    if(ConePtCut) OptList = {"TrigMu17", "TrigMu8", "TrigMu3"};
    else          OptList = {"TrigMu17", "TrigMu8"};
    LIDList = {"TopHNL", "TopHNLLIsop6", "TopHNLLIsop6SIP4", "TopHNLLIsop6SIP5", "TopHNLLIsop6SIP6", "TopHNLLIsop6SIP7", "TopHNLLIsop6SIP8", "TopHNLLIsop6NoSIP"};

    if(MeasPU){
      for(unsigned int iOpt=0; iOpt<OptList.size(); iOpt++){
        TString Opt(OptList.at(iOpt));
        float sf_Tr = Opt.Contains("17")? sf_mu17:Opt.Contains("8")? sf_mu8: 1.;
        MeasPileUp(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                   jetColl, bjetColl, vMET_T1xy, ev, weight*sf_Tr, "_"+Opt);
      }
    }
    if(PrVal){
      for(unsigned int iOpt=0; iOpt<OptList.size(); iOpt++){
        TString Opt(OptList.at(iOpt));
        float sf_Tr  = Opt.Contains("17")? sf_mu17:Opt.Contains("8")? sf_mu8: 1.;
        float nvtxRW = Opt.Contains("17")? nvtxRW_Mu17:Opt.Contains("8")? nvtxRW_Mu8:Opt.Contains("3")? nvtxRW_Mu3:1.;
        CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                         jetColl, bjetColl, vMET_T1xy, ev, weight*nvtxRW*sf_Tr, Opt);
      }
    }
    if(MeasFR){
      for(unsigned int iID=0; iID<LIDList.size(); iID++){
        TString TmpMuLID = LIDList.at(iID);
        vector<Muon> MuLColl = SelectMuons(muonPreColl, TmpMuLID, PTminMu, 2.4);
        vector<Jet>  JetColl = SelectJets(jetPreColl, MuLColl, electronVetoColl, "tightLepVeto", 25., 2.4, "LVeto");
        vector<Jet> BJetColl = SelBJets(JetColl, param_jets);
        for(unsigned int iOpt=0; iOpt<OptList.size(); iOpt++){
          TString Opt = OptList.at(iOpt);
          float w_Norm = Opt.Contains("17")? w_Norm_Mu17:Opt.Contains("8")? w_Norm_Mu8:Opt.Contains("3")? w_Norm_Mu3:1.;
          float nvtxRW = Opt.Contains("17")? nvtxRW_Mu17:Opt.Contains("8")? nvtxRW_Mu8:Opt.Contains("3")? nvtxRW_Mu3:1.;
          float sf_Tr  = Opt.Contains("17")? sf_mu17:Opt.Contains("8")? sf_mu8:1.;
          MeasFakeRate(muonTightColl, MuLColl, MuLColl, electronTightColl, electronLooseColl, electronVetoColl,
                       JetColl, BJetColl, vMET_T1xy, ev, weight*w_Norm*nvtxRW*sf_Tr, "_"+TmpMuLID+"_Cent", Opt);
        }
      }
    }
    if(METMTWCut){
      OptimizeMETMTWCuts(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                         jetColl, bjetColl, vMET_T1xy, ev, weight, "TrigMu8");
    }
  }
  if(ElFR){
    vector<TString> OptList, LIDList; TString PtTag; 
    if(ConePtCut){ PtTag="_Pt10"; OptList = {"TrigEl23", "TrigEl12", "TrigEl8"}; }
    else         { PtTag="_Pt15"; OptList = {"TrigEl23", "TrigEl12"}; }

    if(MeasPU){
      //SS2l: TrigElXX_Pt15, 3l4l: TrigElXX_Pt10
      for(unsigned int iOpt=0; iOpt<OptList.size(); iOpt++){
        TString Opt(OptList.at(iOpt));
        float sf_Tr = Opt.Contains("23")? sf_el23:Opt.Contains("12")? sf_el12: 1.;
        MeasPileUp(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                   jetColl, bjetColl, vMET_T1xy, ev, weight*sf_Tr, "_"+Opt+PtTag);
      }
    }
    if(PrVal){
      //SS2l: TrigElXX_Pt15, 3l4l: TrigElXX_Pt10
      for(unsigned int iOpt=0; iOpt<OptList.size(); iOpt++){
        TString Opt(OptList.at(iOpt));
        float sf_Tr  = Opt.Contains("23")? sf_el23:Opt.Contains("12")? sf_el12: 1.;
        float nvtxRW = Opt.Contains("23")? nvtxRW_El23:Opt.Contains("12")? nvtxRW_El12:Opt.Contains("8")? nvtxRW_El8:1.;
        CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                         jetColl, bjetColl, vMET_T1xy, ev, weight*nvtxRW*sf_Tr, Opt+PtTag);
      }
    }
    if(MeasFR){
      for(unsigned int iID=0; iID<LIDList.size(); iID++){
        TString ElLID = LIDList.at(iID);
        vector<Electron> ElLColl  = SelectElectrons(electronPreColl, ElLID, 10., 2.5);
        for(unsigned int iOpt=0; iOpt<OptList.size(); iOpt++){
          TString Opt = OptList.at(iOpt)+PtTag;
          float w_Norm = Opt.Contains("23")? w_Norm_El23:Opt.Contains("12")? w_Norm_El12:Opt.Contains("8")? w_Norm_El8:1.;
          float nvtxRW = Opt.Contains("23")? nvtxRW_El23:Opt.Contains("12")? nvtxRW_El12:Opt.Contains("8")? nvtxRW_El8:1.;
          float sf_Tr = Opt.Contains("23")? sf_el23:Opt.Contains("12")? sf_el12:1.;
          MeasFakeRate(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, ElLColl, electronVetoColl,
                       jetColl, bjetColl, vMET_T1xy, ev, weight*w_Norm*nvtxRW*sf_Tr, "_"+ElLID+PtTag+"_Cent", Opt);
        }
      }
    }
    if(METMTWCut){
      OptimizeMETMTWCuts(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                         jetColl, bjetColl, vMET_T1xy, ev, weight, "TrigEl12_Pt15");
    }
  }
  if(SystRun && ((!IsDATA) or MeasFR)){
    vector<Jet> jet20Coll       = SelectJets(jetPreColl, muonLooseColl, electronVetoColl, "tightLepVeto", 20., 2.4, "LVeto");
    vector<Jet> jetJESUpColl    = SelectJets(jetPreColl, muonLooseColl, electronVetoColl, "tightLepVeto", 25., 2.4, "LVetoSystJESUp");
    vector<Jet> jetJESDownColl  = SelectJets(jetPreColl, muonLooseColl, electronVetoColl, "tightLepVeto", 25., 2.4, "LVetoSystJESDown");
    vector<Jet> jetJERUpColl    = SelectJets(jetPreColl, muonLooseColl, electronVetoColl, "tightLepVeto", 25., 2.4, "LVetoSystJERUp");
    vector<Jet> jetJERDownColl  = SelectJets(jetPreColl, muonLooseColl, electronVetoColl, "tightLepVeto", 25., 2.4, "LVetoSystJERDown");
    vector<Jet> bjetJESUpColl   = SelBJets(jetJESUpColl, param_jets);
    vector<Jet> bjetJESDownColl = SelBJets(jetJESDownColl, param_jets);
    vector<Jet> bjetJERUpColl   = SelBJets(jetJERUpColl, param_jets);
    vector<Jet> bjetJERDownColl = SelBJets(jetJERDownColl, param_jets);
    Particle vMET_T1xy_JESUp    = GetvMET("PUPPIMETT1xyCorr", "SystUpJES");
    Particle vMET_T1xy_JESDown  = GetvMET("PUPPIMETT1xyCorr", "SystDownJES");
    Particle vMET_T1xy_JERUp    = GetvMET("PUPPIMETT1xyCorr", "SystUpJER");
    Particle vMET_T1xy_JERDown  = GetvMET("PUPPIMETT1xyCorr", "SystDownJER");
    Particle vMET_T1xy_UnclUp   = GetvMET("PUPPIMETT1xyCorr", "SystUpUncl");
    Particle vMET_T1xy_UnclDown = GetvMET("PUPPIMETT1xyCorr", "SystDownUncl");


    float w_PUUp=1., w_PUDown=1., w_PrefireUp=1., w_PrefireDown=1.;
    float sf_ElRecoUp=1., sf_ElRecoDown=1.;
    float sf_BTag_JESUp=1., sf_BTag_JESDown=1., sf_BTag_JERUp=1., sf_BTag_JERDown=1.;
    float sf_BTag_LTagUp=1., sf_BTag_LTagDown=1., sf_BTag_HTagUp=1., sf_BTag_HTagDown=1.;
    if(!IsDATA && EventCand){
      w_PrefireUp   = GetPrefireWeight(1), w_PrefireDown = GetPrefireWeight(-1);
      w_PUUp        = GetPileUpWeight(nPileUp, 1);
      w_PUDown      = GetPileUpWeight(nPileUp,-1);
      sf_ElRecoUp   = GetElectronSF(electronVetoColl, "", "RecoSystUp");
      sf_ElRecoDown = GetElectronSF(electronVetoColl, "", "RecoSystDown");
      sf_BTag_JESUp    = mcCorr->GetBTaggingReweight_1a(jetJESUpColl, param_jets);
      sf_BTag_JESDown  = mcCorr->GetBTaggingReweight_1a(jetJESDownColl, param_jets);
      sf_BTag_JERUp    = mcCorr->GetBTaggingReweight_1a(jetJERUpColl, param_jets);
      sf_BTag_JERDown  = mcCorr->GetBTaggingReweight_1a(jetJERDownColl, param_jets);
      sf_BTag_LTagUp   = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets, "SystUpLTag");
      sf_BTag_LTagDown = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets, "SystDownLTag");
      sf_BTag_HTagUp   = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets, "SystUpHTag");
      sf_BTag_HTagDown = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets, "SystDownHTag");
    }

    float w_base = w_GenNorm * w_BR * w_TopPtRW * sf_MuTk * sf_MuID * sf_MuIso * sf_ElID;
    float weight_PUUp        = w_base * w_PUUp   * w_Prefire     * sf_ElReco     * sf_BTag;
    float weight_PUDown      = w_base * w_PUDown * w_Prefire     * sf_ElReco     * sf_BTag;
    float weight_PrefireUp   = w_base * w_PU     * w_PrefireUp   * sf_ElReco     * sf_BTag;
    float weight_PrefireDown = w_base * w_PU     * w_PrefireDown * sf_ElReco     * sf_BTag;
    float weight_ElRecoUp    = w_base * w_PU     * w_Prefire     * sf_ElRecoUp   * sf_BTag;
    float weight_ElRecoDown  = w_base * w_PU     * w_Prefire     * sf_ElRecoDown * sf_BTag;
    float weight_JESUp       = w_base * w_PU     * w_Prefire     * sf_ElReco     * sf_BTag_JESUp;
    float weight_JESDown     = w_base * w_PU     * w_Prefire     * sf_ElReco     * sf_BTag_JESDown;
    float weight_JERUp       = w_base * w_PU     * w_Prefire     * sf_ElReco     * sf_BTag_JERUp;
    float weight_JERDown     = w_base * w_PU     * w_Prefire     * sf_ElReco     * sf_BTag_JERDown;
    float weight_LTagUp      = w_base * w_PU     * w_Prefire     * sf_ElReco     * sf_BTag_LTagUp;
    float weight_LTagDown    = w_base * w_PU     * w_Prefire     * sf_ElReco     * sf_BTag_LTagDown;
    float weight_HTagUp      = w_base * w_PU     * w_Prefire     * sf_ElReco     * sf_BTag_HTagUp;
    float weight_HTagDown    = w_base * w_PU     * w_Prefire     * sf_ElReco     * sf_BTag_HTagDown;


    if(MuFR){
      vector<TString> OptList, LIDList;
      if(ConePtCut) OptList = {"TrigMu17", "TrigMu8", "TrigMu3"};
      else          OptList = {"TrigMu17", "TrigMu8"};
      LIDList = {"TopHNL", "TopHNLLIsop6", "TopHNLLIsop6SIP4", "TopHNLLIsop6SIP5", "TopHNLLIsop6SIP6", "TopHNLLIsop6SIP7", "TopHNLLIsop6SIP8", "TopHNLLIsop6NoSIP"};

      if(MeasFR){
        for(unsigned int iID=0; iID<LIDList.size(); iID++){
          TString TmpMuLID = LIDList.at(iID);
          vector<Muon> MuLColl   = SelectMuons(muonPreColl, TmpMuLID, PTminMu, 2.4);
          vector<Jet>  JetColl   = SelectJets(jetPreColl, MuLColl, electronVetoColl, "tightLepVeto", 25., 2.4, "LVeto");
          vector<Jet>  Jet20Coll = SelectJets(jetPreColl, MuLColl, electronVetoColl, "tightLepVeto", 20., 2.4, "LVeto");
          vector<Jet>  BJetColl  = SelBJets(JetColl, param_jets);
          for(unsigned int iOpt=0; iOpt<OptList.size(); iOpt++){
            TString Opt = OptList.at(iOpt);
            float w_Norm = Opt.Contains("17")? w_Norm_Mu17:Opt.Contains("8")? w_Norm_Mu8:Opt.Contains("3")? w_Norm_Mu3:1.;
            float w_NormUp =!IsDATA? 1.15:1., w_NormDown=!IsDATA? 0.85:1.;
            float nvtxRW = Opt.Contains("17")? nvtxRW_Mu17:Opt.Contains("8")? nvtxRW_Mu8:Opt.Contains("3")? nvtxRW_Mu3:1.;
            float sf_Tr  = Opt.Contains("17")? sf_mu17:Opt.Contains("8")? sf_mu8:1.;
            float tmpWBase = weight*w_Norm*nvtxRW*sf_Tr;
            MeasFakeRate(muonTightColl, MuLColl, MuLColl, electronTightColl, electronLooseColl, electronVetoColl,
                         JetColl, BJetColl, vMET_T1xy, ev, tmpWBase*w_NormUp, "_"+TmpMuLID+"_PrUp", Opt);
            MeasFakeRate(muonTightColl, MuLColl, MuLColl, electronTightColl, electronLooseColl, electronVetoColl,
                         JetColl, BJetColl, vMET_T1xy, ev, tmpWBase*w_NormDown, "_"+TmpMuLID+"_PrDown", Opt);
            MeasFakeRate(muonTightColl, MuLColl, MuLColl, electronTightColl, electronLooseColl, electronVetoColl,
                         JetColl, BJetColl, vMET_T1xy, ev, tmpWBase, "_"+TmpMuLID+"_HasB", Opt);
            MeasFakeRate(muonTightColl, MuLColl, MuLColl, electronTightColl, electronLooseColl, electronVetoColl,
                         Jet20Coll, BJetColl, vMET_T1xy, ev, tmpWBase, "_"+TmpMuLID+"_JetPt20", Opt);
            MeasFakeRate(muonTightColl, MuLColl, MuLColl, electronTightColl, electronLooseColl, electronVetoColl,
                         JetColl, BJetColl, vMET_T1xy, ev, tmpWBase, "_"+TmpMuLID+"_JetPt60", Opt);
          }
        }
      }
      if(PrVal){
        for(unsigned int iOpt=0; iOpt<OptList.size(); iOpt++){
          TString Opt = OptList.at(iOpt);
          float sf_Tr = Opt.Contains("17")? sf_mu17:Opt.Contains("8")? sf_mu8: 1.;
          float nvtxRW = Opt.Contains("17")? nvtxRW_Mu17:Opt.Contains("8")? nvtxRW_Mu8:Opt.Contains("3")? nvtxRW_Mu3:1.;
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight*sf_Tr, Opt+"_SystUp_Nvtx");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight*sf_Tr, Opt+"_SystDown_Nvtx");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight_PUUp*nvtxRW*sf_Tr, Opt+"_SystUp_PU");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight_PUDown*nvtxRW*sf_Tr, Opt+"_SystDown_PU");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight_PrefireUp*nvtxRW*sf_Tr, Opt+"_SystUp_Prefire");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight_PrefireDown*nvtxRW*sf_Tr, Opt+"_SystDown_Prefire");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight_ElRecoUp*nvtxRW*sf_Tr, Opt+"_SystUp_ElReco");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight_ElRecoDown*nvtxRW*sf_Tr, Opt+"_SystDown_ElReco");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetJESUpColl, bjetJESUpColl, vMET_T1xy_JESUp, ev, weight_JESUp*nvtxRW*sf_Tr, Opt+"_SystUp_JES");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetJESDownColl, bjetJESDownColl, vMET_T1xy_JESDown, ev, weight_JESDown*nvtxRW*sf_Tr, Opt+"_SystDown_JES");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetJERUpColl, bjetJERUpColl, vMET_T1xy_JERUp, ev, weight_JERUp*nvtxRW*sf_Tr, Opt+"_SystUp_JER");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetJERDownColl, bjetJERDownColl, vMET_T1xy_JERDown, ev, weight_JERDown*nvtxRW*sf_Tr, Opt+"_SystDown_JER");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy_UnclUp, ev, weight*nvtxRW*sf_Tr, Opt+"_SystUp_Uncl");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy_UnclDown, ev, weight*nvtxRW*sf_Tr, Opt+"_SystDown_Uncl");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight_LTagUp*nvtxRW*sf_Tr, Opt+"_SystUp_LTag");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight_LTagDown*nvtxRW*sf_Tr, Opt+"_SystDown_LTag");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight_HTagUp*nvtxRW*sf_Tr, Opt+"_SystUp_HTag");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight_HTagDown*nvtxRW*sf_Tr, Opt+"_SystDown_HTag");
        }
      }//End of PrVal
    }//End of MuFR
    if(ElFR){
      vector<TString> OptList, LIDList; TString PtTag; 
      if(ConePtCut){ PtTag="_Pt10"; OptList = {"TrigEl23", "TrigEl12", "TrigEl8"}; }
      else         { PtTag="_Pt15"; OptList = {"TrigEl23", "TrigEl12"}; }
      LIDList = {"TopHNSSL_"+GetEraShort(), "TopHNSSL_WP90Isop4", "TopHN17SSL"};  

      if(MeasFR){
        for(unsigned int iID=0; iID<LIDList.size(); iID++){
          TString TmpElLID = LIDList.at(iID);
          vector<Electron> ElLColl  = SelectElectrons(electronPreColl, TmpElLID, 10., 2.5);
          for(unsigned int iOpt=0; iOpt<OptList.size(); iOpt++){
            TString Opt = OptList.at(iOpt)+PtTag;
            float w_Norm = Opt.Contains("23")? w_Norm_El23:Opt.Contains("12")? w_Norm_El12:Opt.Contains("8")? w_Norm_El8:1.;
            float w_NormUp =!IsDATA? 1.15:1., w_NormDown=!IsDATA? 0.85:1.;
            float nvtxRW = Opt.Contains("23")? nvtxRW_El23:Opt.Contains("12")? nvtxRW_El12:Opt.Contains("8")? nvtxRW_El8:1.;
            float sf_Tr  = Opt.Contains("23")? sf_el23:Opt.Contains("12")? sf_el12:1.;
            float tmpWBase = weight*w_Norm*nvtxRW*sf_Tr;
            MeasFakeRate(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, ElLColl, electronVetoColl,
                         jetColl, bjetColl, vMET_T1xy, ev, tmpWBase*w_NormUp, "_"+TmpElLID+PtTag+"_PrUp", Opt);
            MeasFakeRate(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, ElLColl, electronVetoColl,
                         jetColl, bjetColl, vMET_T1xy, ev, tmpWBase*w_NormDown, "_"+TmpElLID+PtTag+"_PrDown", Opt);
            MeasFakeRate(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, ElLColl, electronVetoColl,
                         jetColl, bjetColl, vMET_T1xy, ev, tmpWBase, "_"+TmpElLID+PtTag+"_HasB", Opt);
            MeasFakeRate(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, ElLColl, electronVetoColl,
                         jetColl, bjetColl, vMET_T1xy, ev, tmpWBase, "_"+TmpElLID+PtTag+"_JetPt30", Opt);
            MeasFakeRate(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, ElLColl, electronVetoColl,
                         jetColl, bjetColl, vMET_T1xy, ev, tmpWBase, "_"+TmpElLID+PtTag+"_JetPt60", Opt);
          }
        }
      }
      if(PrVal){
        for(unsigned int iOpt=0; iOpt<OptList.size(); iOpt++){
          TString Opt = OptList.at(iOpt);
          float sf_Tr  = Opt.Contains("23")? sf_el23:Opt.Contains("12")? sf_el12:1.;
          float nvtxRW = Opt.Contains("23")? nvtxRW_El23:Opt.Contains("12")? nvtxRW_El12:Opt.Contains("8")? nvtxRW_El8:1.;
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight*sf_Tr, Opt+PtTag+"_SystUp_Nvtx");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight*sf_Tr, Opt+PtTag+"_SystDown_Nvtx");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight_PUUp*nvtxRW*sf_Tr, Opt+PtTag+"_SystUp_PU");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight_PUDown*nvtxRW*sf_Tr, Opt+PtTag+"_SystDown_PU");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight_PrefireUp*nvtxRW*sf_Tr, Opt+PtTag+"_SystUp_Prefire");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight_PrefireDown*nvtxRW*sf_Tr, Opt+PtTag+"_SystDown_Prefire");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight_ElRecoUp*nvtxRW*sf_Tr, Opt+PtTag+"_SystUp_ElReco");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight_ElRecoDown*nvtxRW*sf_Tr, Opt+PtTag+"_SystDown_ElReco");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetJESUpColl, bjetJESUpColl, vMET_T1xy_JESUp, ev, weight_JESUp*nvtxRW*sf_Tr, Opt+PtTag+"_SystUp_JES");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetJESDownColl, bjetJESDownColl, vMET_T1xy_JESDown, ev, weight_JESDown*nvtxRW*sf_Tr, Opt+PtTag+"_SystDown_JES");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetJERUpColl, bjetJERUpColl, vMET_T1xy_JERUp, ev, weight_JERUp*nvtxRW*sf_Tr, Opt+PtTag+"_SystUp_JER");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetJERDownColl, bjetJERDownColl, vMET_T1xy_JERDown, ev, weight_JERDown*nvtxRW*sf_Tr, Opt+PtTag+"_SystDown_JER");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy_UnclUp, ev, weight*nvtxRW*sf_Tr, Opt+PtTag+"_SystUp_Uncl");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy_UnclDown, ev, weight*nvtxRW*sf_Tr, Opt+PtTag+"_SystDown_Uncl");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight_LTagUp*nvtxRW*sf_Tr, Opt+PtTag+"_SystUp_LTag");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight_LTagDown*nvtxRW*sf_Tr, Opt+PtTag+"_SystDown_LTag");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight_HTagUp*nvtxRW*sf_Tr, Opt+PtTag+"_SystUp_HTag");
          CheckPromptValid(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                           jetColl, bjetColl, vMET_T1xy, ev, weight_HTagDown*nvtxRW*sf_Tr, Opt+PtTag+"_SystDown_HTag");
        }
      }//End of PrVal
    }//End of ElFR
  }//End of SystRun

}


void FakeRateMeas::CheckPromptValid(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                                    vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                                    vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& Ev, float weight, TString Label)
{
  bool TrigMu17 = Label.Contains("TrigMu17"), TrigMu8  = Label.Contains("TrigMu8"),  TrigMu3 = Label.Contains("TrigMu3");
  bool TrigEl23 = Label.Contains("TrigEl23"), TrigEl12 = Label.Contains("TrigEl12"), TrigEl8 = Label.Contains("TrigEl8");
  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  if(IsDATA){
    if( (TrigMu17 or TrigMu8) && (!DblMu) ) return;
    if( TrigMu3 && ( !((DataYear==2016 && DblMu) or (DataYear>2016 && SglMu)) ) ) return;
    if( (TrigEl23 or TrigEl12 or TrigEl8) && ( !((DataYear==2016 && DblEG) or (DataYear>2016 && SglEl)) ) ) return;
  }
  if( !( (NMuL==1 && NElL==0) or (NElL==1 && NMuL==0) or (NMuL==2 && NElL==0) or (NMuL==0 && NElL==2) ) ) return;
  if( !(NMuL==NMuV && NElL==NElV) ) return;
  if( !(NMuL==NMuT && NElL==NElT) ) return;
  if(NMuT==1){
    float PT = MuTColl.at(0).Pt(), fEta = fabs(MuTColl.at(0).Eta()), MTW = MT(MuTColl.at(0),vMET), MET=vMET.Pt();
    float PTCorr = MuTColl.at(0).CalcPtCone(MuTColl.at(0).MiniRelIso(), 0.1);
    bool TrigSel=false, PassJetReq=false;
    if     (TrigMu17 && Ev.PassTrigger("HLT_Mu17_TrkIsoVVL_v") && PT>20) TrigSel=true;
    else if(TrigMu8  && Ev.PassTrigger("HLT_Mu8_TrkIsoVVL_v")  && PT>10) TrigSel=true;
    else if(TrigMu3  && Ev.PassTrigger("HLT_Mu3_PFJet40_v")    && PT>5 ) TrigSel=true;
    else return;
    if(!TrigSel) return;

    for(unsigned int i=0; i<JetColl.size(); i++){
      if(JetColl.at(i).Pt()<40) continue;
      if(MuTColl.at(0).DeltaR(JetColl.at(i))<1.0) continue;
      PassJetReq=true; break;
    }

    vector<double> PTEdges2D   = {10., 15., 20., 30., 50.};                     
    TString EtaReg = fEta<0.9? "B":fEta<1.6? "BE":"E";
    vector<TString> LabelList;
    LabelList.push_back("_"+Label);
    if(PassJetReq                    ) LabelList.push_back("_1j_"+Label);
    if(PassJetReq && MET>50          ) LabelList.push_back("_1jMET_"+Label);
    if(PassJetReq && MET>50 && MTW>90) LabelList.push_back("_1jMETMTW_"+Label);
    if(PassJetReq && MET<25 && MTW<25) LabelList.push_back("_MeasReg_"+Label);
    for(unsigned int il=0; il<LabelList.size(); il++){
      TString FinLabel = LabelList.at(il);
      bool geq1j = FinLabel.BeginsWith("_1j") or FinLabel.BeginsWith("_MeasReg");
      if(!FinLabel.Contains("MeasReg")){
        FillHist("Rho"+FinLabel, Rho, weight, 35, 0., 70.);
        FillHist("NPV"+FinLabel, nPV, weight, 80, 0., 80.);
        FillHist("PTl"+FinLabel, PT, weight, 40, 0., 200.);
        FillHist("Etal"+FinLabel, MuTColl.at(0).Eta(), weight, 20, -5., 5.);
        FillHist("MET"+FinLabel, MET, weight, 20, 0., 200.);
        FillHist("MTW"+FinLabel, MTW, weight, 40, 0., 200.);
        FillHist("NCount"+FinLabel, 0., weight, 1, 0., 1.);
        if(!geq1j) continue;
        FillHist("Ptj1" +FinLabel, JetColl.at(0).Pt() , weight, 20, 0., 200.);
        FillHist("Etaj1"+FinLabel, JetColl.at(0).Eta(), weight, 20, -5., 5.);
        FillHist("dRlj1"+FinLabel, MuTColl.at(0).DeltaR(JetColl.at(0)), weight, 25, 0., 5.);
      }
      else if(geq1j){ FillHist("PTCorr"+EtaReg+FinLabel, PTCorr, weight, PTEdges2D.size()-1, &PTEdges2D[0]); }
    }
  }
  else if(NElT==1){
    float PT = ElTColl.at(0).Pt(), fEta = fabs(ElTColl.at(0).Eta()), MTW = MT(ElTColl.at(0),vMET), MET=vMET.Pt();
    float PTCorr = ElTColl.at(0).CalcPtCone(ElTColl.at(0).MiniRelIso(), 0.1);
    bool TrigSel=false, PassJetReq=false;
    if     (TrigEl23 && Ev.PassTrigger("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v") && PT>25) TrigSel=true;
    else if(TrigEl12 && Ev.PassTrigger("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v") && PT>15) TrigSel=true;
    else if(TrigEl8  && Ev.PassTrigger("HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v")  && PT>10) TrigSel=true;
    if(!TrigSel) return;

    for(unsigned int i=0; i<JetColl.size(); i++){
      if(JetColl.at(i).Pt()<40) continue;
      if(ElTColl.at(0).DeltaR(JetColl.at(i))<1.0) continue;
      PassJetReq=true; break;
    }
    if(!PassJetReq) return;

    vector<double> PTEdges2D = {15., 20., 25., 35., 50.};
    TString EtaReg = fEta<0.8? "B1":fEta<1.479? "B2":"E";
    vector<TString> LabelList;
    LabelList.push_back("_1j_"+Label);
    if(MET>50          ) LabelList.push_back("_1jMET_"+Label);
    if(MET>50 && MTW>90) LabelList.push_back("_1jMETMTW_"+Label);
    if(MET<25 && MTW<25) LabelList.push_back("_MeasReg_"+Label);
    for(unsigned int il=0; il<LabelList.size(); il++){
      TString FinLabel = LabelList.at(il);
      if(!FinLabel.Contains("MeasReg")){
        FillHist("Rho"+FinLabel, Rho, weight, 35, 0., 70.);
        FillHist("NPV"+FinLabel, nPV, weight, 80, 0., 80.);
        FillHist("PTl"+FinLabel, PT, weight, 40, 0., 200.);
        FillHist("Etal" +FinLabel, ElTColl.at(0).Eta(), weight, 20, -5., 5.);
        FillHist("Ptj1" +FinLabel, JetColl.at(0).Pt() , weight, 20, 0., 200.);
        FillHist("Etaj1"+FinLabel, JetColl.at(0).Eta(), weight, 20, -5., 5.);
        FillHist("dRlj1"+FinLabel, ElTColl.at(0).DeltaR(JetColl.at(0)), weight, 25, 0., 5.);
        FillHist("MET"+FinLabel, MET, weight, 20, 0., 200.);
        FillHist("MTW"+FinLabel, MTW, weight, 40, 0., 200.);
        FillHist("NCount"+FinLabel, 0., weight, 1, 0., 1.);
      }
      else{ FillHist("PTCorr"+EtaReg+FinLabel, PTCorr, weight, PTEdges2D.size()-1, &PTEdges2D[0]); }
    }
  }
  else if(NMuT==2){
    float PT1 = MuTColl.at(0).Pt(), PT2 = MuTColl.at(1).Pt(); 
    bool TrigSel=false, PassJetReq=false;
    if     (TrigMu17 && Ev.PassTrigger("HLT_Mu17_TrkIsoVVL_v") && PT1>20 && PT2>10) TrigSel=true;
    else if(TrigMu8  && Ev.PassTrigger("HLT_Mu8_TrkIsoVVL_v")  && PT1>10 && PT2>10) TrigSel=true;
    else if(TrigMu3  && Ev.PassTrigger("HLT_Mu3_PFJet40_v")    && PT1>5           ) TrigSel=true;
    else return;
    if(!TrigSel) return;
    if(MuTColl.at(0).Charge()==MuTColl.at(1).Charge()) return;

    float Mll = (MuTColl.at(0)+MuTColl.at(1)).M();
    if(fabs(Mll-91.2)>15.) return;

    for(unsigned int i=0; i<JetColl.size(); i++){
      if(JetColl.at(i).Pt()<40) continue;
      if(MuTColl.at(0).DeltaR(JetColl.at(i))<1.0) continue;
      PassJetReq=true; break;
    }

    vector<TString> LabelList;
    LabelList.push_back("_2lMQ_"+Label);
    if(PassJetReq) LabelList.push_back("_1j2lMQ_"+Label);
    for(unsigned int il=0; il<LabelList.size(); il++){
      TString FinLabel = LabelList.at(il);
      FillHist("NPV"+FinLabel, nPV, weight, 80, 0., 80.);
      FillHist("PTl1"+FinLabel, PT1, weight, 40, 0., 200.);
      FillHist("Etal1"+FinLabel, MuTColl.at(0).Eta(), weight, 20, -5., 5.);
      FillHist("PTl2"+FinLabel, PT2, weight, 24, 0., 120.);
      FillHist("Etal2"+FinLabel, MuTColl.at(1).Eta(), weight, 20, -5., 5.);
      FillHist("Mll"+FinLabel, Mll, weight, 30, 60., 120.); 
      FillHist("NCount"+FinLabel, 0., weight, 1, 0., 1.);
    }
  }
  else if(NElT==2){
    float PT1 = ElTColl.at(0).Pt(), PT2 = ElTColl.at(1).Pt(); 
    bool TrigSel=false, PassJetReq=false;
    if     (TrigEl23 && Ev.PassTrigger("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v") && PT1>25) TrigSel=true;
    else if(TrigEl12 && Ev.PassTrigger("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v") && PT1>15) TrigSel=true;
    else if(TrigEl8  && Ev.PassTrigger("HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v")  && PT1>10) TrigSel=true;
    if(!TrigSel) return;
    if(Label.Contains("Pt15") && PT2<15) return;
    else if(Label.Contains("PT10") && PT2<10) return;
    if(ElTColl.at(0).Charge()==ElTColl.at(1).Charge()) return;

    float Mll = (ElTColl.at(0)+ElTColl.at(1)).M();
    if(fabs(Mll-91.2)>15.) return;

    for(unsigned int i=0; i<JetColl.size(); i++){
      if(JetColl.at(i).Pt()<40) continue;
      if(ElTColl.at(0).DeltaR(JetColl.at(i))<1.0) continue;
      PassJetReq=true; break;
    }

    vector<TString> LabelList;
    LabelList.push_back("_2lMQ_"+Label);
    if(PassJetReq) LabelList.push_back("_1j2lMQ_"+Label);
    for(unsigned int il=0; il<LabelList.size(); il++){
      TString FinLabel = LabelList.at(il);
      FillHist("NPV"+FinLabel, nPV, weight, 80, 0., 80.);
      FillHist("PTl1"+FinLabel, PT1, weight, 40, 0., 200.);
      FillHist("Etal1"+FinLabel, ElTColl.at(0).Eta(), weight, 20, -5., 5.);
      FillHist("PTl2"+FinLabel, PT2, weight, 24, 0., 120.);
      FillHist("Etal2"+FinLabel, ElTColl.at(1).Eta(), weight, 20, -5., 5.);
      FillHist("Mll"+FinLabel, Mll, weight, 30, 60., 120.); 
      FillHist("NCount"+FinLabel, 0., weight, 1, 0., 1.);
    }
  }

}


void FakeRateMeas::MeasPileUp(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                              vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                              vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& Ev, float weight, TString Label)
{
  bool TrigMu17 = Label.Contains("TrigMu17"), TrigMu8  = Label.Contains("TrigMu8"),  TrigMu3 = Label.Contains("TrigMu3");
  bool TrigEl23 = Label.Contains("TrigEl23"), TrigEl12 = Label.Contains("TrigEl12"), TrigEl8 = Label.Contains("TrigEl8");
  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  if(IsDATA){
    if( (TrigMu17 or TrigMu8) && (!DblMu) ) return;
    if( TrigMu3 && ( !((DataYear==2016 && DblMu) or (DataYear>2016 && SglMu)) ) ) return;
    if( (TrigEl23 or TrigEl12 or TrigEl8) && ( !((DataYear==2016 && DblEG) or (DataYear>2016 && SglEl)) ) ) return;
  }
  if( !( (NMuL==1 and NElL==0) or (NElL==1 and NMuL==0) ) ) return;
  if( !(NMuL==NMuV and NElL==NElV) ) return;
  if( !(NMuL==NMuT and NElL==NElT) ) return;
  if(NMuT==1){
    float PT = MuTColl.at(0).Pt(), MTW = MT(MuTColl.at(0),vMET), MET=vMET.Pt();
    bool TrigSel=false, PassJetReq=false;
    if     (TrigMu17 && Ev.PassTrigger("HLT_Mu17_TrkIsoVVL_v") && PT>20) TrigSel=true;
    else if(TrigMu8  && Ev.PassTrigger("HLT_Mu8_TrkIsoVVL_v")  && PT>10) TrigSel=true;
    else if(TrigMu3  && Ev.PassTrigger("HLT_Mu3_PFJet40_v")    && PT>5 ) TrigSel=true;
    else return;
    if(!TrigSel) return;
    FillHist("Rho"+Label, Rho, weight, 70, 0., 70.);
    FillHist("NPV"+Label, nPV, weight, 80, 0., 80.);

    for(unsigned int i=0; i<JetColl.size(); i++){
      if(JetColl.at(i).Pt()<40) continue;
      if(MuTColl.at(0).DeltaR(JetColl.at(i))<1.0) continue;
      PassJetReq=true; break;
    }
    if(!PassJetReq) return;
    FillHist("Rho_1j"+Label, Rho, weight, 70, 0., 70.);
    FillHist("NPV_1j"+Label, nPV, weight, 80, 0., 80.);

    if( !(MET>50 && MTW>80) ) return;
    FillHist("Rho_1jMETMTW"+Label, Rho, weight, 70, 0., 70.);
    FillHist("NPV_1jMETMTW"+Label, nPV, weight, 80, 0., 80.);
  }
  else if(NElT==1){
    float PT = ElTColl.at(0).Pt(), MTW = MT(ElTColl.at(0),vMET), MET=vMET.Pt();
    bool TrigSel=false, PassJetReq=false;
    if     (TrigEl23 && Ev.PassTrigger("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v") && PT>25) TrigSel=true;
    else if(TrigEl12 && Ev.PassTrigger("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v") && PT>15) TrigSel=true;
    else if(TrigEl8  && Ev.PassTrigger("HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v")  && PT>10) TrigSel=true;
    if(!TrigSel) return;
    FillHist("Rho"+Label, Rho, weight, 70, 0., 70.);
    FillHist("NPV"+Label, nPV, weight, 80, 0., 80.);

    for(unsigned int i=0; i<JetColl.size(); i++){
      if(JetColl.at(i).Pt()<40) continue;
      if(ElTColl.at(0).DeltaR(JetColl.at(i))<1.0) continue;
      PassJetReq=true; break;
    }
    if(!PassJetReq) return;
    FillHist("Rho_1j"+Label, Rho, weight, 70, 0., 70.);
    FillHist("NPV_1j"+Label, nPV, weight, 80, 0., 80.);

    if( !(MET>50 && MTW>80) ) return;
    FillHist("Rho_1jMETMTW"+Label, Rho, weight, 70, 0., 70.);
    FillHist("NPV_1jMETMTW"+Label, nPV, weight, 80, 0., 80.);
  }
}



void FakeRateMeas::OptimizeMETMTWCuts(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                                      vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                                      vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& Ev, float weight, TString Label)
{
  int NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  if( !( (NMuL==1 and NElL==0) or (NElL==1 and NMuL==0) ) ) return;
  if( !(NMuL==NMuV and NElL==NElV) ) return;
  if(NMuL==1){
    float PT = MuLColl.at(0).Pt(), MTW = MT(MuLColl.at(0),vMET), MET=vMET.Pt();
    bool TrigMu8 = Label.Contains("TrigMu8"), TrigSel=false, PassJetReq=false;
    if(TrigMu8 && Ev.PassTrigger("HLT_Mu8_TrkIsoVVL_v") && PT>10) TrigSel=true;
    else return;
    if(!TrigSel) return;

    for(unsigned int i=0; i<JetColl.size(); i++){
      if(JetColl.at(i).Pt()<40) continue;
      if(MuLColl.at(0).DeltaR(JetColl.at(i))<1.0) continue;
      PassJetReq=true; break;
    }
    if(!PassJetReq) return;
    Label="_"+Label;

    FillHist("SumW"+Label, 0., weight, 1, 0., 1.);
    FillHist("MET"+Label, MET, weight, 40, 0., 200.);
    FillHist("MTW"+Label, MTW, weight, 40, 0., 200.);
    for(float METCut=0.; METCut<100.; METCut+=5.){
      for(float MTWCut=0.; MTWCut<100.; MTWCut+=5.){
        if(MET<METCut && MTW<MTWCut){ FillHist("SumWInMETMTW"+Label, METCut-1E-4, MTWCut-1E-4, weight, 20, 0., 100., 20, 0., 100.); }
      }
    }
  }
  else if(NElL==1){
    float PT = ElLColl.at(0).Pt(), MTW = MT(ElLColl.at(0),vMET), MET=vMET.Pt();
    bool TrigEl12 = Label.Contains("TrigEl12"), TrigEl8 = Label.Contains("TrigEl8");
    bool PTCut15 = Label.Contains("Pt15"), PTCut10 = Label.Contains("Pt10");
    bool TrigSel=false, PassJetReq=false;
    if     (TrigEl12 && Ev.PassTrigger("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v")) TrigSel=true;
    else if(TrigEl8  && Ev.PassTrigger("HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v") ) TrigSel=true;
    if(!TrigSel) return;
    if(PTCut15 && PT<15) return;
    else if(PTCut10 && PT<10) return; 

    for(unsigned int i=0; i<JetColl.size(); i++){
      if(JetColl.at(i).Pt()<40) continue;
      if(ElLColl.at(0).DeltaR(JetColl.at(i))<1.0) continue;
      PassJetReq=true; break;
    }
    if(!PassJetReq) return;
    Label="_"+Label;

    FillHist("SumW"+Label, 0., weight, 1, 0., 1.);
    FillHist("MET"+Label, MET, weight, 40, 0., 200.);
    FillHist("MTW"+Label, MTW, weight, 40, 0., 200.);
    for(float METCut=0.; METCut<100.; METCut+=5.){
      for(float MTWCut=0.; MTWCut<100.; MTWCut+=5.){
        if(MET<METCut && MTW<MTWCut){ FillHist("SumWInMETMTW"+Label, METCut-1E-4, MTWCut-1E-4, weight, 20, 0., 100., 20, 0., 100.); }
      }
    }
  }
}


void FakeRateMeas::MeasFakeRate(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                                vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                                vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& Ev, float weight, TString Label, TString Option)
{
  bool TrigMu17 = Option.Contains("TrigMu17"), TrigMu8 = Option.Contains("TrigMu8"), TrigMu3=Option.Contains("TrigMu3");
  bool TrigEl23 = Option.Contains("TrigEl23"), TrigEl12 = Option.Contains("TrigEl12"), TrigEl8 = Option.Contains("TrigEl8");
  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  if(IsDATA){
    if( (TrigMu17 or TrigMu8) && (!DblMu) ) return;
    if( TrigMu3 && ( !((DataYear==2016 && DblMu) or (DataYear>2016 && SglMu)) ) ) return;
    if( (TrigEl23 or TrigEl12 or TrigEl8) && ( !((DataYear==2016 && DblEG) or (DataYear>2016 && SglEl)) ) ) return;
  }
  if( !( (NMuL==1 and NElL==0) or (NElL==1 and NMuL==0) ) ) return;
  if( !(NMuL==NMuV and NElL==NElV) ) return;
  if(NMuL==1){
    float TightIso=0.1, RelIso=MuLColl.at(0).MiniRelIso(), MET=vMET.Pt(), MTW=MT(MuLColl.at(0),vMET);
    float PT=MuLColl.at(0).Pt(), PTCorr=MuLColl.at(0).CalcPtCone(RelIso, TightIso), Eta=MuLColl.at(0).Eta(), fEta=fabs(Eta);
    vector<double> PTEdges1D   = {10., 15., 20., 25., 30., 40., 50., 70., 100.};
    vector<double> PTEdges2D   = {10., 15., 20., 30., 50.};                     
    vector<double> EtaEdges1D  = {-2.4, -1.6, -0.9, 0., 0.9, 1.6, 2.4};         
    vector<double> fEtaEdges2D = {0., 0.9, 1.6, 2.4};                           
    bool PTParam = Option.Contains("PTParam"), TrigSel=false, PassJetReq=false;
    if(ConePtCut){
      if     (TrigMu17 && Ev.PassTrigger("HLT_Mu17_TrkIsoVVL_v") && PT>20. && PTCorr>=30.               ){ TrigSel=true; }
      else if(TrigMu8  && Ev.PassTrigger("HLT_Mu8_TrkIsoVVL_v")  && PT>10. && PTCorr>=15. && PTCorr <30.){ TrigSel=true; }
      else if(TrigMu3  && Ev.PassTrigger("HLT_Mu3_PFJet40_v")    && PT>5.  && PTCorr >10. && PTCorr <15.){ TrigSel=true; }
    }
    else if(PTParam){
      if     (TrigMu17 && Ev.PassTrigger("HLT_Mu17_TrkIsoVVL_v") && PT>20. ) TrigSel=true;
      else if(TrigMu8  && Ev.PassTrigger("HLT_Mu8_TrkIsoVVL_v")  && PT>10. ) TrigSel=true;
      PTCorr = PT;
    }
    else{
      if     (TrigMu17 && Ev.PassTrigger("HLT_Mu17_TrkIsoVVL_v") && PT>20. && PTCorr>=30.){ TrigSel=true; }
      else if(TrigMu8  && Ev.PassTrigger("HLT_Mu8_TrkIsoVVL_v")  && PT>10. && PTCorr <30.){ TrigSel=true; }
    }
    if(!TrigSel) return;

    float JetPtCut = Label.Contains("JetPt20")? 20.: Label.Contains("JetPt60")? 60.: 40.;
    bool PassNBCut = Label.Contains("HasB")? BJetColl.size()>0:true;
    for(unsigned int i=0; i<JetColl.size(); i++){
      if(JetColl.at(i).Pt()<JetPtCut) continue;
      if(MuLColl.at(0).DeltaR(JetColl.at(i))<1.0) continue;
      PassJetReq=true; break;
    }
    if(!PassJetReq) return;
    if(!PassNBCut ) return;
    if( !(MET<25 && MTW<25) ) return;


    TString EtaReg = fEta<0.9? "B":fEta<1.6? "BE":"E";
    FillHist("SumWL_PT1D"+Label, PTCorr, weight, PTEdges1D.size()-1, &PTEdges1D[0]);
    FillHist("SumWL_Eta1D"+Label, Eta, weight, EtaEdges1D.size()-1, &EtaEdges1D[0]);
    FillHist("SumWL_PTfEta2D"+Label, PTCorr, fEta, weight, PTEdges2D.size()-1, &PTEdges2D[0], fEtaEdges2D.size()-1, &fEtaEdges2D[0]);
    FillHist("MuAllSumW_PT_FR1D"+Label, PTCorr, weight, PTEdges2D.size()-1, &PTEdges2D[0]);
    FillHist("Mu"+EtaReg+"SumW_PT_FR1D"+Label, PTCorr, weight, PTEdges2D.size()-1, &PTEdges2D[0]);
    if(NMuT>0){
      FillHist("SumWT_PT1D"+Label, PTCorr, weight, PTEdges1D.size()-1, &PTEdges1D[0]);
      FillHist("SumWT_Eta1D"+Label, Eta, weight, EtaEdges1D.size()-1, &EtaEdges1D[0]);
      FillHist("SumWT_PTfEta2D"+Label, PTCorr, fEta, weight, PTEdges2D.size()-1, &PTEdges2D[0], fEtaEdges2D.size()-1, &fEtaEdges2D[0]);
      FillHist("MuAllIDSumW_PT_FR1D"+Label, PTCorr, weight, PTEdges2D.size()-1, &PTEdges2D[0]);
      FillHist("Mu"+EtaReg+"IDSumW_PT_FR1D"+Label, PTCorr, weight, PTEdges2D.size()-1, &PTEdges2D[0]);
    }
  }
  else if(NElL==1){
    float TightIso=0.1, RelIso=ElLColl.at(0).MiniRelIso(), MET=vMET.Pt(), MTW=MT(ElLColl.at(0),vMET);
    float PT=ElLColl.at(0).Pt(), PTCorr=ElLColl.at(0).CalcPtCone(RelIso, TightIso), Eta=ElLColl.at(0).Eta(), fEta=fabs(Eta);
    bool PTCut10 = Option.Contains("_Pt10"), PTCut15 = Option.Contains("_Pt15"), TrigSel=false, PassJetReq=false;
    vector<double> PTEdges1D   = {10., 15., 20., 25., 30., 35., 40., 50., 70., 100.};
    vector<double> PTEdges2D   = {10., 15., 20., 25., 35., 50.};                     
    vector<double> EtaEdges1D  = {-2.5, -1.5, -0.8, 0., 0., 1.5, 2.5};               
    vector<double> fEtaEdges2D = {0., 0.8, 1.5, 2.5};                                
    if(PTCut15){
      if     (TrigEl23 && Ev.PassTrigger("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v") && PT>25. && PTCorr>=35.){ TrigSel=true; }
      else if(TrigEl12 && Ev.PassTrigger("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v") && PT>15. && PTCorr <35.){ TrigSel=true; }
      PTEdges1D.erase(PTEdges1D.begin()); PTEdges2D.erase(PTEdges2D.begin());
    }
    else if(PTCut10){
      if     (TrigEl23 && Ev.PassTrigger("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v") && PT>25. && PTCorr>=35.              ){ TrigSel=true; }
      else if(TrigEl12 && Ev.PassTrigger("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v") && PT>15. && PTCorr<35. && PTCorr>=20.){ TrigSel=true; }
      else if(TrigEl8  && Ev.PassTrigger("HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v")  && PT>10. && PTCorr<20.               ){ TrigSel=true; }
    }
    if(!TrigSel) return;

    float JetPtCut = Label.Contains("JetPt30")? 30.: Label.Contains("JetPt60")? 60.: 40.;
    bool PassNBCut = Label.Contains("HasB")? BJetColl.size()>0:true;
    for(unsigned int i=0; i<JetColl.size(); i++){
      if(JetColl.at(i).Pt()<JetPtCut) continue;
      if(ElLColl.at(0).DeltaR(JetColl.at(i))<1.0) continue;
      PassJetReq=true; break;
    }
    if(!PassJetReq) return;
    if(!PassNBCut ) return;
    if( !(MET<25 && MTW<25) ) return;


    TString EtaReg = fEta<0.8? "B1":fEta<1.479? "B2":"E";
    FillHist("SumWL_PT1D"+Label, PTCorr, weight, PTEdges1D.size()-1, &PTEdges1D[0]);
    FillHist("SumWL_Eta1D"+Label, Eta, weight, EtaEdges1D.size()-1, &EtaEdges1D[0]);
    FillHist("SumWL_PTfEta2D"+Label, PTCorr, fEta, weight, PTEdges2D.size()-1, &PTEdges2D[0], fEtaEdges2D.size()-1, &fEtaEdges2D[0]);
    FillHist("ElAllSumW_PT_FR1D"+Label, PTCorr, weight, PTEdges2D.size()-1, &PTEdges2D[0]);
    FillHist("El"+EtaReg+"SumW_PT_FR1D"+Label, PTCorr, weight, PTEdges2D.size()-1, &PTEdges2D[0]);
    if(NElT>0){
      FillHist("SumWT_PT1D"+Label, PTCorr, weight, PTEdges1D.size()-1, &PTEdges1D[0]);
      FillHist("SumWT_Eta1D"+Label, Eta, weight, EtaEdges1D.size()-1, &EtaEdges1D[0]);
      FillHist("SumWT_PTfEta2D"+Label, PTCorr, fEta, weight, PTEdges2D.size()-1, &PTEdges2D[0], fEtaEdges2D.size()-1, &fEtaEdges2D[0]);
      FillHist("ElAllIDSumW_PT_FR1D"+Label, PTCorr, weight, PTEdges2D.size()-1, &PTEdges2D[0]);
      FillHist("El"+EtaReg+"IDSumW_PT_FR1D"+Label, PTCorr, weight, PTEdges2D.size()-1, &PTEdges2D[0]);
    }
  }
}



void FakeRateMeas::executeEventFromParameter(AnalyzerParameter param){

  if(!PassMETFilter()) return;

  Event ev = GetEvent();

}

FakeRateMeas::FakeRateMeas(){

}

FakeRateMeas::~FakeRateMeas(){

  delete NvtxSFFile;
  for(std::map< TString, TH1D* >::iterator mapit = maphist_NvtxSF.begin(); mapit!=maphist_NvtxSF.end(); mapit++){
    delete mapit->second;
  }
  maphist_NvtxSF.clear();

}


float FakeRateMeas::GetNvtxReweight(int NPV, TString Key){

  if(!NvtxSFFile->GetListOfKeys()->Contains(Key)){ printf("[Error] No %s in NvtxSF File.\n", Key.Data()); return -1.; }

  std::map<TString, TH1D*>::iterator mapit = maphist_NvtxSF.find(Key);
  if(mapit == maphist_NvtxSF.end()){ //first usage
    maphist_NvtxSF[Key] = (TH1D*) ((TH1*) NvtxSFFile->Get(Key))->Clone();
  }

  mapit = maphist_NvtxSF.find(Key);
  float Xmin = mapit->second->GetXaxis()->GetBinLowEdge(mapit->second->GetXaxis()->GetFirst());
  float Xmax = mapit->second->GetXaxis()->GetBinUpEdge(mapit->second->GetXaxis()->GetLast());

  float VarX = ((float) NPV)+1E-10;
  if(VarX<Xmin) VarX=Xmin+1E-10;
  if(VarX>Xmax) VarX=Xmax-1E-10;

  float NvtxSF = mapit->second->GetBinContent(mapit->second->FindBin(VarX));
  if(NvtxSF>10) NvtxSF=1.;

  return NvtxSF;

}



float FakeRateMeas::GetResidualNormSF(TString Key, TString Era){

  if(IsDATA) return 1.;

  float SF=1.;
  if(Era=="2016a"){
    if     (Key.Contains("Mu17")) SF = 9.068e-03;
    else if(Key.Contains("Mu8" )) SF = 4.373e-04;
    else if(Key.Contains("Mu3" )) SF = 1.711e-04;
    else if(Key.Contains("El23")) SF = 2.737e-03;
    else if(Key.Contains("El12")) SF = 6.321e-04;
    else if(Key.Contains("El8" )) SF = 2.419e-04;
  }
  else if(Era=="2016b"){
    if     (Key.Contains("Mu17")) SF = 1.461e-03;
    else if(Key.Contains("Mu8" )) SF = 7.881e-05;
    else if(Key.Contains("Mu3" )) SF = 1.221e-04;
    else if(Key.Contains("El23")) SF = 5.722e-04;
    else if(Key.Contains("El12")) SF = 2.561e-04;
    else if(Key.Contains("El8" )) SF = 1.977e-04;
  }
  else if(Era=="2017"){
    if     (Key.Contains("Mu17")) SF = 1.544e-03;
    else if(Key.Contains("Mu8" )) SF = 9.336e-05;
    else if(Key.Contains("Mu3" )) SF = 1.369e-04;
    else if(Key.Contains("El23")) SF = 1.001e-03;
    else if(Key.Contains("El12")) SF = 7.211e-04;
    else if(Key.Contains("El8" )) SF = 1.247e-04;
  }
  else if(Era=="2018"){
    if     (Key.Contains("Mu17")) SF = 7.191e-04;
    else if(Key.Contains("Mu8" )) SF = 1.526e-04;
    else if(Key.Contains("Mu3" )) SF = 9.699e-05;
    else if(Key.Contains("El23")) SF = 5.888e-04;
    else if(Key.Contains("El12")) SF = 6.874e-04;
    else if(Key.Contains("El8" )) SF = 1.190e-04;
  }

  return SF;
}


float FakeRateMeas::NvtxReweight(TString Key){
  
  if(IsDATA) return 1.;

  float SF=1.;
  if(Key=="TrigMu17"){
    if     (nPV==1) SF=3.29;
    else if(nPV==2) SF=2.96;
    else if(nPV==3) SF=1.95;
    else if(nPV==4) SF=1.80;
    else if(nPV==5) SF=1.40;
    else if(nPV==6) SF=1.45;
    else if(nPV==7) SF=1.43;
    else if(nPV==8) SF=1.42;
    else if(nPV==9) SF=1.29;
    else if(nPV==10) SF=1.26;
    else if(nPV==11) SF=1.22;
    else if(nPV==12) SF=1.19;
    else if(nPV==13) SF=1.16;
    else if(nPV==14) SF=1.14;
    else if(nPV==15) SF=1.12;
    else if(nPV==16) SF=1.12;
    else if(nPV==17) SF=1.10;
    else if(nPV==18) SF=1.09;
    else if(nPV==19) SF=1.05;
    else if(nPV==20) SF=1.05;
    else if(nPV==21) SF=1.05;
    else if(nPV==22) SF=1.04;
    else if(nPV==23) SF=1.02;
    else if(nPV==24) SF=1.03;
    else if(nPV==25) SF=1.02;
    else if(nPV==26) SF=1.00;
    else if(nPV==27) SF=1.00;
    else if(nPV==28) SF=0.98;
    else if(nPV==29) SF=0.99;
    else if(nPV==30) SF=0.98;
    else if(nPV==31) SF=0.95;
    else if(nPV==32) SF=0.93;
    else if(nPV==33) SF=0.92;
    else if(nPV==34) SF=0.90;
    else if(nPV==35) SF=0.88;
    else if(nPV==36) SF=0.88;
    else if(nPV==37) SF=0.85;
    else if(nPV==38) SF=0.83;
    else if(nPV==39) SF=0.82;
    else if(nPV==40) SF=0.83;
    else if(nPV==41) SF=0.80;
    else if(nPV==42) SF=0.81;
    else if(nPV==43) SF=0.81;
    else if(nPV==44) SF=0.80;
    else if(nPV==45) SF=0.81;
    else if(nPV==46) SF=0.85;
    else if(nPV==47) SF=0.82;
    else if(nPV==48) SF=0.88;
    else if(nPV==49) SF=0.90;
    else if(nPV==50) SF=0.90;
    else if(nPV==51) SF=0.98;
    else if(nPV==52) SF=1.00;
    else if(nPV==53) SF=1.07;
    else if(nPV==54) SF=1.07;
    else if(nPV==55) SF=1.11;
    else if(nPV==56) SF=1.19;
    else if(nPV==57) SF=1.33;
    else if(nPV==58) SF=1.25;
    else if(nPV==59) SF=1.37;
    else if(nPV==60) SF=1.49;
    else if(nPV==61) SF=1.65;
    else if(nPV==62) SF=1.71;
    else if(nPV==63) SF=1.64;
    else if(nPV==64) SF=1.76;
    else if(nPV==65) SF=1.83;
    else if(nPV==66) SF=2.09;
    else if(nPV==67) SF=2.32;
    else if(nPV==68) SF=1.94;
    else if(nPV==69) SF=2.05;
    else if(nPV==70) SF=2.53;
    else if(nPV==71) SF=2.24;
    else if(nPV==72) SF=2.71;
    else if(nPV==73) SF=3.33;
    else if(nPV==74) SF=2.31;
    else if(nPV==75) SF=3.02;
    else if(nPV==76) SF=2.45;
    else if(nPV==77) SF=2.85;
    else if(nPV==78) SF=3.32;
    else if(nPV>=79) SF=3.69;
  }
  else if(Key=="TrigMu8"){
    if     (nPV==1) SF=2.97;
    else if(nPV==2) SF=3.21;
    else if(nPV==3) SF=2.48;
    else if(nPV==4) SF=2.08;
    else if(nPV==5) SF=1.63;
    else if(nPV==6) SF=1.72;
    else if(nPV==7) SF=1.46;
    else if(nPV==8) SF=1.58;
    else if(nPV==9) SF=1.46;
    else if(nPV==10) SF=1.47;
    else if(nPV==11) SF=1.37;
    else if(nPV==12) SF=1.34;
    else if(nPV==13) SF=1.30;
    else if(nPV==14) SF=1.27;
    else if(nPV==15) SF=1.21;
    else if(nPV==16) SF=1.19;
    else if(nPV==17) SF=1.16;
    else if(nPV==18) SF=1.14;
    else if(nPV==19) SF=1.11;
    else if(nPV==20) SF=1.08;
    else if(nPV==21) SF=1.07;
    else if(nPV==22) SF=1.05;
    else if(nPV==23) SF=1.03;
    else if(nPV==24) SF=1.01;
    else if(nPV==25) SF=1.00;
    else if(nPV==26) SF=0.99;
    else if(nPV==27) SF=0.97;
    else if(nPV==28) SF=0.96;
    else if(nPV==29) SF=0.95;
    else if(nPV==30) SF=0.92;
    else if(nPV==31) SF=0.91;
    else if(nPV==32) SF=0.88;
    else if(nPV==33) SF=0.88;
    else if(nPV==34) SF=0.85;
    else if(nPV==35) SF=0.83;
    else if(nPV==36) SF=0.83;
    else if(nPV==37) SF=0.80;
    else if(nPV==38) SF=0.77;
    else if(nPV==39) SF=0.79;
    else if(nPV==40) SF=0.77;
    else if(nPV==41) SF=0.76;
    else if(nPV==42) SF=0.78;
    else if(nPV==43) SF=0.76;
    else if(nPV==44) SF=0.75;
    else if(nPV==45) SF=0.77;
    else if(nPV==46) SF=0.76;
    else if(nPV==47) SF=0.79;
    else if(nPV==48) SF=0.82;
    else if(nPV==49) SF=0.81;
    else if(nPV==50) SF=0.84;
    else if(nPV==51) SF=0.85;
    else if(nPV==52) SF=0.90;
    else if(nPV==53) SF=0.96;
    else if(nPV==54) SF=0.91;
    else if(nPV==55) SF=0.99;
    else if(nPV==56) SF=1.02;
    else if(nPV==57) SF=1.18;
    else if(nPV==58) SF=1.24;
    else if(nPV==59) SF=1.22;
    else if(nPV==60) SF=1.38;
    else if(nPV==61) SF=1.42;
    else if(nPV==62) SF=1.56;
    else if(nPV==63) SF=1.60;
    else if(nPV==64) SF=1.86;
    else if(nPV==65) SF=1.83;
    else if(nPV==66) SF=1.69;
    else if(nPV==67) SF=1.81;
    else if(nPV==68) SF=2.14;
    else if(nPV==69) SF=1.93;
    else if(nPV==70) SF=1.97;
    else if(nPV==71) SF=2.22;
    else if(nPV==72) SF=2.31;
    else if(nPV==73) SF=1.93;
    else if(nPV==74) SF=2.21;
    else if(nPV==75) SF=2.25;
    else if(nPV==76) SF=2.41;
    else if(nPV==77) SF=2.92;
    else if(nPV==78) SF=2.12;
    else if(nPV>=79) SF=2.92;
  }
  else if(Key=="TrigEl23_Pt15"){
    if     (nPV== 1) SF=9.33;
    else if(nPV== 2) SF=6.10;
    else if(nPV== 3) SF=3.09;
    else if(nPV== 4) SF=3.92;
    else if(nPV== 5) SF=3.58;
    else if(nPV== 6) SF=2.92;
    else if(nPV== 7) SF=2.53;
    else if(nPV== 8) SF=2.56;
    else if(nPV== 9) SF=2.37;
    else if(nPV==10) SF=2.02;
    else if(nPV==11) SF=2.01;
    else if(nPV==12) SF=1.73;
    else if(nPV==13) SF=1.64;
    else if(nPV==14) SF=1.48;
    else if(nPV==15) SF=1.36;
    else if(nPV==16) SF=1.29;
    else if(nPV==17) SF=1.26;
    else if(nPV==18) SF=1.21;
    else if(nPV==19) SF=1.14;
    else if(nPV==20) SF=1.14;
    else if(nPV==21) SF=1.13;
    else if(nPV==22) SF=1.09;
    else if(nPV==23) SF=1.03;
    else if(nPV==24) SF=1.04;
    else if(nPV==25) SF=1.01;
    else if(nPV==26) SF=0.98;
    else if(nPV==27) SF=0.98;
    else if(nPV==28) SF=0.91;
    else if(nPV==29) SF=0.93;
    else if(nPV==30) SF=0.89;
    else if(nPV==31) SF=0.91;
    else if(nPV==32) SF=0.84;
    else if(nPV==33) SF=0.81;
    else if(nPV==34) SF=0.82;
    else if(nPV==35) SF=0.77;
    else if(nPV==36) SF=0.73;
    else if(nPV==37) SF=0.70;
    else if(nPV==38) SF=0.66;
    else if(nPV==39) SF=0.64;
    else if(nPV==40) SF=0.65;
    else if(nPV==41) SF=0.57;
    else if(nPV==42) SF=0.61;
    else if(nPV==43) SF=0.54;
    else if(nPV==44) SF=0.55;
    else if(nPV==45) SF=0.60;
    else if(nPV==46) SF=0.55;
    else if(nPV==47) SF=0.59;
    else if(nPV==48) SF=0.57;
    else if(nPV==49) SF=0.61;
    else if(nPV==50) SF=0.52;
    else if(nPV==51) SF=0.58;
    else if(nPV==52) SF=0.59;
    else if(nPV==53) SF=0.66;
    else if(nPV==54) SF=0.72;
    else if(nPV==55) SF=0.69;
    else if(nPV==56) SF=0.73;
    else if(nPV==57) SF=0.81;
    else if(nPV==58) SF=0.73;
    else if(nPV==59) SF=0.80;
    else if(nPV==60) SF=0.75;
    else if(nPV==61) SF=1.01;
    else if(nPV==62) SF=0.99;
    else if(nPV==63) SF=0.79;
    else if(nPV==64) SF=0.82;
    else if(nPV==65) SF=1.56;
    else if(nPV==66) SF=1.20;
    else if(nPV==67) SF=0.98;
    else if(nPV==68) SF=1.60;
    else if(nPV==69) SF=1.87;
    else if(nPV==70) SF=1.44;
    else if(nPV==71) SF=1.13;
    else if(nPV==72) SF=1.12;
    else if(nPV==73) SF=1.82;
    else if(nPV==74) SF=0.58;
    else if(nPV==75) SF=1.88;
    else if(nPV==76) SF=1.80;
    else if(nPV==77) SF=1.50;
    else if(nPV==78) SF=2.02;
    else if(nPV>=79) SF=1.39;
  }
  else if(Key=="TrigEl12_Pt15"){
    if     (nPV== 1) SF=4.87;
    else if(nPV== 2) SF=4.41;
    else if(nPV== 3) SF=2.88;
    else if(nPV== 4) SF=2.31;
    else if(nPV== 5) SF=1.78;
    else if(nPV== 6) SF=1.81;
    else if(nPV== 7) SF=1.79;
    else if(nPV== 8) SF=1.58;
    else if(nPV== 9) SF=1.56;
    else if(nPV==10) SF=1.45;
    else if(nPV==11) SF=1.47;
    else if(nPV==12) SF=1.35;
    else if(nPV==13) SF=1.27;
    else if(nPV==14) SF=1.25;
    else if(nPV==15) SF=1.18;
    else if(nPV==16) SF=1.13;
    else if(nPV==17) SF=1.14;
    else if(nPV==18) SF=1.10;
    else if(nPV==19) SF=1.10;
    else if(nPV==20) SF=1.12;
    else if(nPV==21) SF=1.10;
    else if(nPV==22) SF=1.05;
    else if(nPV==23) SF=1.03;
    else if(nPV==24) SF=1.02;
    else if(nPV==25) SF=1.02;
    else if(nPV==26) SF=0.98;
    else if(nPV==27) SF=0.99;
    else if(nPV==28) SF=0.95;
    else if(nPV==29) SF=0.95;
    else if(nPV==30) SF=0.94;
    else if(nPV==31) SF=0.94;
    else if(nPV==32) SF=0.90;
    else if(nPV==33) SF=0.90;
    else if(nPV==34) SF=0.86;
    else if(nPV==35) SF=0.88;
    else if(nPV==36) SF=0.84;
    else if(nPV==37) SF=0.82;
    else if(nPV==38) SF=0.81;
    else if(nPV==39) SF=0.77;
    else if(nPV==40) SF=0.81;
    else if(nPV==41) SF=0.72;
    else if(nPV==42) SF=0.76;
    else if(nPV==43) SF=0.75;
    else if(nPV==44) SF=0.73;
    else if(nPV==45) SF=0.79;
    else if(nPV==46) SF=0.75;
    else if(nPV==47) SF=0.78;
    else if(nPV==48) SF=0.78;
    else if(nPV==49) SF=0.81;
    else if(nPV==50) SF=0.77;
    else if(nPV==51) SF=0.83;
    else if(nPV==52) SF=0.87;
    else if(nPV==53) SF=0.90;
    else if(nPV==54) SF=0.94;
    else if(nPV==55) SF=1.08;
    else if(nPV==56) SF=1.09;
    else if(nPV==57) SF=1.18;
    else if(nPV==58) SF=1.16;
    else if(nPV==59) SF=1.33;
    else if(nPV==60) SF=1.10;
    else if(nPV==61) SF=1.52;
    else if(nPV==62) SF=1.43;
    else if(nPV==63) SF=1.13;
    else if(nPV==64) SF=1.10;
    else if(nPV==65) SF=2.36;
    else if(nPV==66) SF=1.54;
    else if(nPV==67) SF=1.38;
    else if(nPV==68) SF=1.83;
    else if(nPV==69) SF=2.13;
    else if(nPV==70) SF=2.11;
    else if(nPV==71) SF=1.39;
    else if(nPV==72) SF=1.85;
    else if(nPV==73) SF=2.61;
    else if(nPV==74) SF=1.01;
    else if(nPV==75) SF=2.18;
    else if(nPV==76) SF=3.55;
    else if(nPV==77) SF=2.86;
    else if(nPV==78) SF=2.94;
    else if(nPV>=79) SF=2.11;
  }
  else if(Key=="TrigEl23_Pt10"){
    if(nPV== 1) SF=10.10;
    else if(nPV== 2) SF=6.13;
    else if(nPV== 3) SF=3.27;
    else if(nPV== 4) SF=3.83;
    else if(nPV== 5) SF=3.62;
    else if(nPV== 6) SF=2.99;
    else if(nPV== 7) SF=2.67;
    else if(nPV== 8) SF=2.59;
    else if(nPV== 9) SF=2.39;
    else if(nPV==10) SF=2.06;
    else if(nPV==11) SF=2.02;
    else if(nPV==12) SF=1.74;
    else if(nPV==13) SF=1.65;
    else if(nPV==14) SF=1.50;
    else if(nPV==15) SF=1.36;
    else if(nPV==16) SF=1.29;
    else if(nPV==17) SF=1.28;
    else if(nPV==18) SF=1.20;
    else if(nPV==19) SF=1.14;
    else if(nPV==20) SF=1.14;
    else if(nPV==21) SF=1.13;
    else if(nPV==22) SF=1.08;
    else if(nPV==23) SF=1.02;
    else if(nPV==24) SF=1.04;
    else if(nPV==25) SF=1.01;
    else if(nPV==26) SF=0.98;
    else if(nPV==27) SF=0.99;
    else if(nPV==28) SF=0.92;
    else if(nPV==29) SF=0.91;
    else if(nPV==30) SF=0.90;
    else if(nPV==31) SF=0.90;
    else if(nPV==32) SF=0.84;
    else if(nPV==33) SF=0.81;
    else if(nPV==34) SF=0.81;
    else if(nPV==35) SF=0.77;
    else if(nPV==36) SF=0.71;
    else if(nPV==37) SF=0.70;
    else if(nPV==38) SF=0.65;
    else if(nPV==39) SF=0.64;
    else if(nPV==40) SF=0.66;
    else if(nPV==41) SF=0.55;
    else if(nPV==42) SF=0.60;
    else if(nPV==43) SF=0.54;
    else if(nPV==44) SF=0.56;
    else if(nPV==45) SF=0.60;
    else if(nPV==46) SF=0.55;
    else if(nPV==47) SF=0.58;
    else if(nPV==48) SF=0.58;
    else if(nPV==49) SF=0.61;
    else if(nPV==50) SF=0.52;
    else if(nPV==51) SF=0.59;
    else if(nPV==52) SF=0.60;
    else if(nPV==53) SF=0.65;
    else if(nPV==54) SF=0.72;
    else if(nPV==55) SF=0.73;
    else if(nPV==56) SF=0.78;
    else if(nPV==57) SF=0.81;
    else if(nPV==58) SF=0.79;
    else if(nPV==59) SF=0.82;
    else if(nPV==60) SF=0.81;
    else if(nPV==61) SF=1.05;
    else if(nPV==62) SF=0.98;
    else if(nPV==63) SF=0.85;
    else if(nPV==64) SF=0.90;
    else if(nPV==65) SF=1.49;
    else if(nPV==66) SF=1.12;
    else if(nPV==67) SF=1.26;
    else if(nPV==68) SF=1.52;
    else if(nPV==69) SF=1.78;
    else if(nPV==70) SF=1.43;
    else if(nPV==71) SF=1.52;
    else if(nPV==72) SF=1.19;
    else if(nPV==73) SF=2.31;
    else if(nPV==74) SF=0.52;
    else if(nPV==75) SF=1.67;
    else if(nPV==76) SF=1.61;
    else if(nPV==77) SF=1.33;
    else if(nPV==78) SF=1.76;
    else if(nPV>=79) SF=1.22;
  }
  else if(Key=="TrigEl12_Pt10"){
    if(nPV== 1) SF=5.06;
    else if(nPV== 2) SF=4.11;
    else if(nPV== 3) SF=3.04;
    else if(nPV== 4) SF=2.38;
    else if(nPV== 5) SF=1.87;
    else if(nPV== 6) SF=1.85;
    else if(nPV== 7) SF=1.80;
    else if(nPV== 8) SF=1.60;
    else if(nPV== 9) SF=1.59;
    else if(nPV==10) SF=1.47;
    else if(nPV==11) SF=1.47;
    else if(nPV==12) SF=1.35;
    else if(nPV==13) SF=1.28;
    else if(nPV==14) SF=1.26;
    else if(nPV==15) SF=1.19;
    else if(nPV==16) SF=1.13;
    else if(nPV==17) SF=1.14;
    else if(nPV==18) SF=1.10;
    else if(nPV==19) SF=1.10;
    else if(nPV==20) SF=1.11;
    else if(nPV==21) SF=1.10;
    else if(nPV==22) SF=1.05;
    else if(nPV==23) SF=1.03;
    else if(nPV==24) SF=1.02;
    else if(nPV==25) SF=1.02;
    else if(nPV==26) SF=0.98;
    else if(nPV==27) SF=0.99;
    else if(nPV==28) SF=0.96;
    else if(nPV==29) SF=0.94;
    else if(nPV==30) SF=0.94;
    else if(nPV==31) SF=0.93;
    else if(nPV==32) SF=0.90;
    else if(nPV==33) SF=0.90;
    else if(nPV==34) SF=0.86;
    else if(nPV==35) SF=0.87;
    else if(nPV==36) SF=0.83;
    else if(nPV==37) SF=0.82;
    else if(nPV==38) SF=0.80;
    else if(nPV==39) SF=0.77;
    else if(nPV==40) SF=0.82;
    else if(nPV==41) SF=0.72;
    else if(nPV==42) SF=0.76;
    else if(nPV==43) SF=0.75;
    else if(nPV==44) SF=0.73;
    else if(nPV==45) SF=0.79;
    else if(nPV==46) SF=0.76;
    else if(nPV==47) SF=0.78;
    else if(nPV==48) SF=0.79;
    else if(nPV==49) SF=0.83;
    else if(nPV==50) SF=0.77;
    else if(nPV==51) SF=0.82;
    else if(nPV==52) SF=0.89;
    else if(nPV==53) SF=0.89;
    else if(nPV==54) SF=0.96;
    else if(nPV==55) SF=1.13;
    else if(nPV==56) SF=1.14;
    else if(nPV==57) SF=1.17;
    else if(nPV==58) SF=1.22;
    else if(nPV==59) SF=1.33;
    else if(nPV==60) SF=1.14;
    else if(nPV==61) SF=1.56;
    else if(nPV==62) SF=1.42;
    else if(nPV==63) SF=1.16;
    else if(nPV==64) SF=1.17;
    else if(nPV==65) SF=2.31;
    else if(nPV==66) SF=1.39;
    else if(nPV==67) SF=1.63;
    else if(nPV==68) SF=1.77;
    else if(nPV==69) SF=2.07;
    else if(nPV==70) SF=2.08;
    else if(nPV==71) SF=1.75;
    else if(nPV==72) SF=1.86;
    else if(nPV==73) SF=3.04;
    else if(nPV==74) SF=1.17;
    else if(nPV==75) SF=1.99;
    else if(nPV==76) SF=3.10;
    else if(nPV==77) SF=2.60;
    else if(nPV==78) SF=2.64;
    else if(nPV>=79) SF=1.99;
  }
  else if(Key=="TrigEl8_Pt10"){
    if(nPV== 1) SF=2.34;
    else if(nPV== 2) SF=3.35;
    else if(nPV== 3) SF=4.93;
    else if(nPV== 4) SF=1.97;
    else if(nPV== 5) SF=3.60;
    else if(nPV== 6) SF=3.18;
    else if(nPV== 7) SF=3.11;
    else if(nPV== 8) SF=2.26;
    else if(nPV== 9) SF=2.88;
    else if(nPV==10) SF=2.32;
    else if(nPV==11) SF=2.43;
    else if(nPV==12) SF=2.21;
    else if(nPV==13) SF=2.03;
    else if(nPV==14) SF=1.73;
    else if(nPV==15) SF=1.67;
    else if(nPV==16) SF=1.52;
    else if(nPV==17) SF=1.50;
    else if(nPV==18) SF=1.41;
    else if(nPV==19) SF=1.27;
    else if(nPV==20) SF=1.21;
    else if(nPV==21) SF=1.19;
    else if(nPV==22) SF=1.06;
    else if(nPV==23) SF=1.05;
    else if(nPV==24) SF=1.01;
    else if(nPV==25) SF=0.99;
    else if(nPV==26) SF=0.88;
    else if(nPV==27) SF=0.90;
    else if(nPV==28) SF=0.92;
    else if(nPV==29) SF=0.84;
    else if(nPV==30) SF=0.80;
    else if(nPV==31) SF=0.76;
    else if(nPV==32) SF=0.71;
    else if(nPV==33) SF=0.70;
    else if(nPV==34) SF=0.66;
    else if(nPV==35) SF=0.61;
    else if(nPV==36) SF=0.59;
    else if(nPV==37) SF=0.57;
    else if(nPV==38) SF=0.52;
    else if(nPV==39) SF=0.52;
    else if(nPV==40) SF=0.52;
    else if(nPV==41) SF=0.44;
    else if(nPV==42) SF=0.46;
    else if(nPV==43) SF=0.43;
    else if(nPV==44) SF=0.38;
    else if(nPV==45) SF=0.39;
    else if(nPV==46) SF=0.47;
    else if(nPV==47) SF=0.40;
    else if(nPV==48) SF=0.47;
    else if(nPV==49) SF=0.42;
    else if(nPV==50) SF=0.29;
    else if(nPV==51) SF=0.35;
    else if(nPV==52) SF=0.55;
    else if(nPV==53) SF=0.50;
    else if(nPV==54) SF=0.39;
    else if(nPV==55) SF=0.68;
    else if(nPV==56) SF=0.61;
    else if(nPV==57) SF=0.54;
    else if(nPV==58) SF=0.58;
    else if(nPV==59) SF=0.76;
    else if(nPV==60) SF=0.30;
    else if(nPV==61) SF=0.91;
    else if(nPV==62) SF=0.48;
    else if(nPV==63) SF=0.58;
    else if(nPV==64) SF=0.18;
    else if(nPV==65) SF=0.99;
    else if(nPV==66) SF=2.16;
    else if(nPV==67) SF=0.67;
    else if(nPV==68) SF=0.00;
    else if(nPV==69) SF=0.47;
    else if(nPV==70) SF=1.18;
    else if(nPV==71) SF=0.00;
    else if(nPV==72) SF=0.81;
    else if(nPV==73) SF=0.93;
    else if(nPV==74) SF=0.00;
    else if(nPV==75) SF=0.00;
    else if(nPV==76) SF=0.00;
    else if(nPV==77) SF=0.00;
    else if(nPV==78) SF=3.76;
    else if(nPV>=79) SF=0.74;
  }

  return SF;
}



bool FakeRateMeas::IsNearBJet(Lepton& Lepton, vector<Jet>& BJetColl){

  bool FoundNearB=false;
  for(unsigned int it_b=0; it_b<BJetColl.size(); it_b++){
    if(Lepton.DeltaR(BJetColl.at(it_b))<0.4){ FoundNearB=true; break; }
  }

  return FoundNearB;
}
