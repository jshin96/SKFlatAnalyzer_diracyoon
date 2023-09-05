#include "DiLepValid.h"

void DiLepValid::initializeAnalyzer(){

  SglLTrig=false, DiLTrig=false, ElEl=false, MuMu=false, ElMu=false, SF2L=false; 
  DiLIncl=false, DiLBJet =false;
  HEMCheck=false, SystRun=false;
  for(unsigned int i=0; i<Userflags.size(); i++){
    if(Userflags.at(i).Contains("SglLTrig")) SglLTrig = true; 
    if(Userflags.at(i).Contains("DiLTrig" )) DiLTrig  = true; 
    if(Userflags.at(i).Contains("ElEl"    )) ElEl     = true; 
    if(Userflags.at(i).Contains("MuMu"    )) MuMu     = true; 
    if(Userflags.at(i).Contains("ElMu"    )) ElMu     = true; 
    if(Userflags.at(i).Contains("SF2L"    )) SF2L     = true; 
    if(Userflags.at(i).Contains("DiLIncl" )) DiLIncl  = true; 
    if(Userflags.at(i).Contains("DiLBJet" )) DiLBJet  = true; 
    if(Userflags.at(i).Contains("HEMCheck")) HEMCheck = true;
    if(Userflags.at(i).Contains("SystRun" )) SystRun  = true; 
  }

  DblMu=false, DblEG=false, MuEG=false, SglEl=false;
  if     (DataStream.Contains("DoubleMuon")) DblMu=true;
  else if(DataStream.Contains("MuonEG"))     MuEG =true;
  else if(DataStream.Contains("DoubleEG"))   DblEG=true;
  else if(DataStream.Contains("SingleElectron")) SglEl=true;
  else if(DataYear==2018 and DataStream.Contains("EGamma")) DblEG=true;

  if(SglLTrig){
    if(DataYear==2016){
      TrigList_SglMu = {"HLT_IsoMu24_v", "HLT_IsoTkMu24_v"}; TrigList_SglEl = {"HLT_Ele27_WPTight_Gsf_v"};
    }
    else if(DataYear==2017){
      TrigList_SglMu = {"HLT_IsoMu27_v"}; TrigList_SglEl = {"HLT_Ele32_WPTight_Gsf_v", "HLT_Ele32_WPTight_Gsf_L1DoubleEG_v"};
    }
    else if(DataYear==2018){
      TrigList_SglMu = {"HLT_IsoMu24_v"}; TrigList_SglEl = {"HLT_Ele32_WPTight_Gsf_v"};
    }
    if(MuMu or ElMu) TrigList = TrigList_SglMu;
    else if(ElEl)    TrigList = TrigList_SglEl;
  }
  else if(DiLTrig){
    if(GetEraShort()=="2016a"){
      TrigList_DiMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v", "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v"};
      TrigList_DiEl = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"};
      TrigList_ElMu = {"HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v", "HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v"};
    }
    else if(GetEraShort()=="2016b"){
      TrigList_DiMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v", "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v", "HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v"};
      TrigList_DiEl = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"};
      TrigList_ElMu = {"HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v", "HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"};
    }
    else if(DataYear==2017){
      TrigList_DiMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v", "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v"};
      TrigList_DiEl = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v"};
      TrigList_ElMu = {"HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v", "HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v"};
    }
    else if(DataYear==2018){
      TrigList_DiMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v"};
      TrigList_DiEl = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v"};
      TrigList_ElMu = {"HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v", "HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v"};
    }
    //if     (MuMu){ TrigList = TrigList_DiMu; SFKey_Trig="DiMuIso_POGMIDTIso"; }
    if     (MuMu){ TrigList = TrigList_DiMu; SFKey_Trig="DiMuIso_HNTopID"; }
    else if(ElEl){ TrigList = TrigList_DiEl; SFKey_Trig="DiElIso_HNTopIDSS"; }
    else if(ElMu){ TrigList = TrigList_ElMu; SFKey_Trig="EMuIso_HNTopIDSS"; }
  }

  //Set up the tagger map only for the param settings to be used.
  vector<JetTagging::Parameters> jtps;
  jtps.push_back( JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets) );
  mcCorr->SetJetTaggingParameters(jtps);

}


void DiLepValid::executeEvent(){


  Event ev = GetEvent();
  float weight=1., w_GenNorm=1., w_BR=1., w_PU=1.;
  if(!IsDATA){
    w_GenNorm = MCweight()*GetKFactor()*ev.GetTriggerLumi("Full");
    w_BR      = GetBRWeight();
    w_PU      = GetPileUpWeight(nPileUp, 0);
    weight *= w_GenNorm * w_BR * w_PU;
  }

  bool PassTrig=false;
  if(SF2L){
    if(!IsDATA) PassTrig = ev.PassTrigger(TrigList_DiMu) or ev.PassTrigger(TrigList_DiEl);
    else{ if     (DblMu) PassTrig =   ev.PassTrigger(TrigList_DiMu);
          else if(DblEG) PassTrig = (!ev.PassTrigger(TrigList_DiMu)) && ev.PassTrigger(TrigList_DiEl);
    }
  }
  else PassTrig = ev.PassTrigger(TrigList);
  if(!PassTrig) return;
  if(!PassMETFilter()) return;

  bool PreCutPass=false;
  vector<Muon>     muonPreColl     = GetMuons("NOCUT", 8., 2.4);
  vector<Electron> electronPreColl = GetElectrons("NOCUT", 8., 2.5);
  sort(muonPreColl.begin(), muonPreColl.end(), PtComparing);
  sort(electronPreColl.begin(), electronPreColl.end(), PtComparing);
  if((ElEl or SF2L) and electronPreColl.size()>1) PreCutPass=true;
  if((MuMu or SF2L) and muonPreColl.size()>1    ) PreCutPass=true;
  if(ElMu and electronPreColl.size()>0 && muonPreColl.size()>0) PreCutPass=true;
  if(!PreCutPass) return;

  TString MuTID = "TopHNT", MuLID = "TopHNL";
  TString ElTID = "TopHNSST", ElLID = "TopHNSSL_"+GetEraShort(), ElVID = "TopHNL_"+GetEraShort();  
  float PTminEl = ElTID.Contains("SS")? 15.:10.;
  vector<Muon>     muonTightColl     = SelectMuons(muonPreColl, MuTID, 10., 2.4);
  vector<Electron> electronTightColl = SelectElectrons(electronPreColl, ElTID, PTminEl, 2.5);
  vector<Muon>     muonLooseColl     = SelectMuons(muonPreColl, MuLID, 10., 2.4);
  vector<Electron> electronLooseColl = SelectElectrons(electronPreColl, ElLID, PTminEl, 2.5);
  vector<Electron> electronVetoColl  = SelectElectrons(electronPreColl, ElVID, 10., 2.5);


  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
  vector<Jet> jetPreColl = GetAllJets();
  sort(jetPreColl.begin(), jetPreColl.end(), PtComparing);
  vector<Jet> jetColl  = SelectJets(jetPreColl, muonLooseColl, electronVetoColl, "tightLepVeto", 25., 2.4, "LVeto");
  vector<Jet> bjetColl = SelBJets(jetColl, param_jets);

  Particle vMET = GetvMET("PUPPIMETT1"); //"T1"
  Particle vMET_T1xy = GetvMET("PUPPIMETT1xyCorr");
 

  vector<Gen> truthColl;


  bool EventCand = false;
  float w_TopPtRW = 1., w_Pref = 1., sf_Tr = 1.;
  float sf_MuTk = 1., sf_mID = 1., sf_muiso = 1., sf_eReco = 1., sf_eID = 1., sf_B = 1.;
  if(MuMu){ EventCand = muonLooseColl.size()>1; }
  if(ElEl){ EventCand = electronLooseColl.size()>1; }
  if(ElMu){ EventCand = electronLooseColl.size()>0 && muonLooseColl.size()>0; }
  if(SF2L){ EventCand = muonLooseColl.size()>1 or electronLooseColl.size()>1; }
  if((!IsDATA) and EventCand){
    if(MCSample.Contains("TT") and MCSample.Contains("powheg")){ truthColl = GetGens(); w_TopPtRW = mcCorr->GetTopPtReweight(truthColl); }
    w_Pref = GetPrefireWeight(0);
    sf_mID   = GetMuonSF(muonTightColl, MuTID, "ID");
    sf_eReco = GetElectronSF(electronTightColl, "", "Reco");
    sf_eID   = GetElectronSF(electronTightColl, ElTID, "ID");
    sf_B   = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets);
    int NEl = electronTightColl.size(), NMu = muonTightColl.size();
    if(SF2L) SFKey_Trig = NEl==2? "DiElIso_HNTopIDSS": NMu==2? "DiMuIso_HNTopID":"";
    sf_Tr   = SFKey_Trig!=""? mcCorr->GetTriggerSF(electronTightColl, muonTightColl, SFKey_Trig, ""):1.;
    //cout<<"w_Pref:"<<w_Pref<<" sf_Tr:"<<sf_Tr<<endl;
    //cout<<"sf_MuTk"<<sf_MuTk<<" sf_mID:"<<sf_mID<<" sf_muiso:"<<sf_muiso<<" sf_eReco:"<<sf_eReco<<" sf_eID:"<<sf_eID<<" sf_B:"<<sf_B<<endl;
  }
  weight *= w_TopPtRW * w_Pref * sf_Tr;
  weight *= sf_MuTk * sf_mID * sf_muiso * sf_eReco * sf_eID * sf_B;

 
  if(SF2L){
    if(DiLBJet){
      AnalyzeDiLeptonBJet(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET_T1xy, weight, "");
    }
  }
  if(MuMu){
    if(DiLIncl){
      AnalyzeDiMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, weight, "");
      AnalyzeDiMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, w_GenNorm, "_NoW");
      AnalyzeDiMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, w_GenNorm*w_Pref, "_Pref");
      AnalyzeDiMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, w_GenNorm*w_Pref*w_PU, "_PrefPU");
      AnalyzeDiMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, w_GenNorm*w_Pref*w_PU*sf_mID*sf_muiso, "_PrefPUID");
      AnalyzeDiMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, w_GenNorm*w_Pref*w_PU*sf_mID*sf_muiso*sf_Tr, "_PrefPUIDTrig");
      AnalyzeDiMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET_T1xy, w_GenNorm*w_Pref*w_PU*sf_mID*sf_muiso*sf_Tr, "_PrefPUIDTrigMETPhi");
    }
    else if(DiLBJet){
      AnalyzeDiMuonBJet(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET_T1xy, weight, "");
    }
  }
  if(ElEl){
    if(DiLIncl){
      AnalyzeDiElectron(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, weight, "");
      AnalyzeDiElectron(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, w_GenNorm, "_NoW");
      AnalyzeDiElectron(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, w_GenNorm*w_Pref, "_Pref");
      AnalyzeDiElectron(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, w_GenNorm*w_Pref*w_PU, "_PrefPU");
      AnalyzeDiElectron(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, w_GenNorm*w_Pref*w_PU*sf_eReco, "_PrefPUReco");
      AnalyzeDiElectron(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, w_GenNorm*w_Pref*w_PU*sf_eReco*sf_eID, "_PrefPURecoID");
      AnalyzeDiElectron(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, w_GenNorm*w_Pref*w_PU*sf_eReco*sf_eID*sf_Tr, "_PrefPURecoIDTrig");
      AnalyzeDiElectron(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET_T1xy, w_GenNorm*w_Pref*w_PU*sf_eReco*sf_eID*sf_Tr, "_PrefPURecoIDTrigMETPhi");
    }
    else if(DiLBJet){
      AnalyzeDiElectronBJet(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET_T1xy, weight, "");
    }
  }
  if(ElMu){
    AnalyzeElectronMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET_T1xy,
                        weight, "");
    AnalyzeElectronMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET,
                        w_GenNorm, "_NoW");
    AnalyzeElectronMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET,
                        w_GenNorm*w_Pref, "_Pref");
    AnalyzeElectronMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET,
                        w_GenNorm*w_Pref*w_PU, "_PrefPU");
    AnalyzeElectronMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET,
                        w_GenNorm*w_Pref*w_PU*sf_mID*sf_muiso*sf_Tr, "_PrefPUIDTrigMu");
    AnalyzeElectronMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET,
                        w_GenNorm*w_Pref*w_PU*sf_mID*sf_muiso*sf_eReco*sf_eID*sf_Tr, "_PrefPUIDTrigMuEl");
    AnalyzeElectronMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET_T1xy,
                        w_GenNorm*w_Pref*w_PU*sf_mID*sf_muiso*sf_eReco*sf_eID*sf_Tr, "_PrefPUIDTrigMuElMETPhi");
    AnalyzeElectronMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET_T1xy,
                        w_GenNorm*w_Pref*w_PU*sf_mID*sf_muiso*sf_eReco*sf_eID*sf_Tr*sf_B, "_PrefPUIDTrigMuElMETPhiBTag");
  }
  if( SystRun && !IsDATA){
    vector<Muon>     MuEnUpTColl, MuEnUpLColl, MuEnDownTColl, MuEnDownLColl;
    vector<Electron> ElSclUpTColl, ElSclUpLColl, ElSclDownTColl, ElSclDownLColl;
    vector<Electron> ElResUpTColl, ElResUpLColl, ElResDownTColl, ElResDownLColl;
    vector<Electron> ElCFPT1UpTColl, ElCFPT1UpLColl, ElCFPT2UpTColl, ElCFPT2UpLColl;
    vector<Electron> ElCFPT1DownTColl, ElCFPT1DownLColl, ElCFPT2DownTColl, ElCFPT2DownLColl;
    vector<Jet>      jetJESUpColl, jetJESDownColl, jetJERUpColl, jetJERDownColl;
    vector<Jet>      bjetJESUpColl, bjetJESDownColl, bjetJERUpColl, bjetJERDownColl;
    Particle         vMET_T1xy_JESUp, vMET_T1xy_JESDown, vMET_T1xy_JERUp, vMET_T1xy_JERDown, vMET_T1xy_UnclUp, vMET_T1xy_UnclDown;
    if(!IsDATA){
      MuEnUpTColl    = SelectMuons(muonPreColl, MuTID, 10., 2.4, "SystEnUp");
      MuEnUpLColl    = SelectMuons(muonPreColl, MuLID, 10., 2.4, "SystEnUp");
      MuEnDownTColl  = SelectMuons(muonPreColl, MuTID, 10., 2.4, "SystEnDown");
      MuEnDownLColl  = SelectMuons(muonPreColl, MuLID, 10., 2.4, "SystEnDown");
      ElSclUpTColl   = SelectElectrons(electronPreColl, ElTID, 15., 2.5, "SystSclUp");
      ElSclUpLColl   = SelectElectrons(electronPreColl, ElLID, 15., 2.5, "SystSclUp");
      ElSclDownTColl = SelectElectrons(electronPreColl, ElTID, 15., 2.5, "SystSclDown");
      ElSclDownLColl = SelectElectrons(electronPreColl, ElLID, 15., 2.5, "SystSclDown");
      ElResUpTColl   = SelectElectrons(electronPreColl, ElTID, 15., 2.5, "SystResUp");
      ElResUpLColl   = SelectElectrons(electronPreColl, ElLID, 15., 2.5, "SystResUp");
      ElResDownTColl = SelectElectrons(electronPreColl, ElTID, 15., 2.5, "SystResDown");
      ElResDownLColl = SelectElectrons(electronPreColl, ElLID, 15., 2.5, "SystResDown");
      jetJESUpColl    = SelectJets(jetPreColl, muonLooseColl, electronVetoColl, "tightLepVeto", 25., 2.4, "LVetoSystJESUp");
      jetJESDownColl  = SelectJets(jetPreColl, muonLooseColl, electronVetoColl, "tightLepVeto", 25., 2.4, "LVetoSystJESDown");
      jetJERUpColl    = SelectJets(jetPreColl, muonLooseColl, electronVetoColl, "tightLepVeto", 25., 2.4, "LVetoSystJERUp");
      jetJERDownColl  = SelectJets(jetPreColl, muonLooseColl, electronVetoColl, "tightLepVeto", 25., 2.4, "LVetoSystJERDown");
      bjetJESUpColl   = SelBJets(jetJESUpColl, param_jets);
      bjetJESDownColl = SelBJets(jetJESDownColl, param_jets);
      bjetJERUpColl   = SelBJets(jetJERUpColl, param_jets);
      bjetJERDownColl = SelBJets(jetJERDownColl, param_jets);
      vMET_T1xy_JESUp    = GetvMET("PUPPIMETT1xyCorr", "SystUpJES");
      vMET_T1xy_JESDown  = GetvMET("PUPPIMETT1xyCorr", "SystDownJES");
      vMET_T1xy_JERUp    = GetvMET("PUPPIMETT1xyCorr", "SystUpJER");
      vMET_T1xy_JERDown  = GetvMET("PUPPIMETT1xyCorr", "SystDownJER");
      vMET_T1xy_UnclUp   = GetvMET("PUPPIMETT1xyCorr", "SystUpUncl");
      vMET_T1xy_UnclDown = GetvMET("PUPPIMETT1xyCorr", "SystDownUncl");
    }

    float w_PUUp=1., w_PUDown=1., w_PrefUp=1., w_PrefDown=1.;
    float sf_mIDUp=1., sf_mIDDown=1., sf_mID_MuEnUp=1., sf_mID_MuEnDown=1.;
    float sf_eIDUp=1., sf_eIDDown=1., sf_eID_ElSclUp=1., sf_eID_ElSclDown=1., sf_eID_ElResUp=1., sf_eID_ElResDown=1.;
    float sf_eRecoUp=1., sf_eRecoDown=1., sf_eReco_ElSclUp=1., sf_eReco_ElSclDown=1., sf_eReco_ElResUp=1., sf_eReco_ElResDown=1.;
    float sf_B_JESUp=1., sf_B_JESDown=1., sf_B_JERUp=1., sf_B_JERDown=1.;
    float sf_B_LTagUp=1., sf_B_LTagDown=1., sf_B_HTagUp=1., sf_B_HTagDown=1.;
    float sf_Tr_ElSclUp=1., sf_Tr_ElSclDown=1., sf_Tr_ElResUp=1., sf_Tr_ElResDown=1., sf_Tr_MuEnUp=1., sf_Tr_MuEnDown=1.;
    float sf_TrUp=sf_Tr*1.01, sf_TrDown=sf_Tr*0.99;
    if(!IsDATA && EventCand){
      w_PrefUp   = GetPrefireWeight(1), w_PrefDown = GetPrefireWeight(-1);
      w_PUUp     = GetPileUpWeight(nPileUp, 1);
      w_PUDown   = GetPileUpWeight(nPileUp,-1);

      sf_eRecoUp   = GetElectronSF(electronTightColl, "", "RecoSystUp");
      sf_eRecoDown = GetElectronSF(electronTightColl, "", "RecoSystDown");
      sf_eReco_ElSclUp   = GetElectronSF(ElSclUpTColl, "", "Reco");
      sf_eReco_ElSclDown = GetElectronSF(ElSclDownTColl, "", "Reco");
      sf_eReco_ElResUp   = GetElectronSF(ElResUpTColl, "", "Reco");
      sf_eReco_ElResDown = GetElectronSF(ElResDownTColl, "", "Reco");
      sf_eIDUp         = GetElectronSF(electronTightColl, ElTID, "IDSystUp");
      sf_eIDDown       = GetElectronSF(electronTightColl, ElTID, "IDSystDown");
      sf_eID_ElSclUp   = GetElectronSF(ElSclUpTColl, ElTID, "ID");
      sf_eID_ElSclDown = GetElectronSF(ElSclDownTColl, ElTID, "ID");
      sf_eID_ElResUp   = GetElectronSF(ElResUpTColl, ElTID, "ID");
      sf_eID_ElResDown = GetElectronSF(ElResDownTColl, ElTID, "ID");
      sf_mIDUp         = GetMuonSF(muonTightColl, MuTID, "IDSystUp");
      sf_mIDDown       = GetMuonSF(muonTightColl, MuTID, "IDSystDown");
      sf_mID_MuEnUp    = GetMuonSF(MuEnUpTColl, MuTID, "ID");
      sf_mID_MuEnDown  = GetMuonSF(MuEnDownTColl, MuTID, "ID");
      sf_B_JESUp    = mcCorr->GetBTaggingReweight_1a(jetJESUpColl, param_jets);
      sf_B_JESDown  = mcCorr->GetBTaggingReweight_1a(jetJESDownColl, param_jets);
      sf_B_JERUp    = mcCorr->GetBTaggingReweight_1a(jetJERUpColl, param_jets);
      sf_B_JERDown  = mcCorr->GetBTaggingReweight_1a(jetJERDownColl, param_jets);
      sf_B_LTagUp   = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets, "SystUpLTag");
      sf_B_LTagDown = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets, "SystDownLTag");
      sf_B_HTagUp   = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets, "SystUpHTag");
      sf_B_HTagDown = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets, "SystDownHTag");
      sf_Tr_MuEnUp    = SFKey_Trig!=""? mcCorr->GetTriggerSF(electronTightColl, MuEnUpTColl, SFKey_Trig, ""):1.;
      sf_Tr_MuEnDown  = SFKey_Trig!=""? mcCorr->GetTriggerSF(electronTightColl, MuEnDownTColl, SFKey_Trig, ""):1.;
      sf_Tr_ElSclUp   = SFKey_Trig!=""? mcCorr->GetTriggerSF(ElSclUpTColl, muonTightColl, SFKey_Trig, ""):1.;
      sf_Tr_ElSclDown = SFKey_Trig!=""? mcCorr->GetTriggerSF(ElSclDownTColl, muonTightColl, SFKey_Trig, ""):1.;
      sf_Tr_ElResUp   = SFKey_Trig!=""? mcCorr->GetTriggerSF(ElResUpTColl, muonTightColl, SFKey_Trig, ""):1.;
      sf_Tr_ElResDown = SFKey_Trig!=""? mcCorr->GetTriggerSF(ElResDownTColl, muonTightColl, SFKey_Trig, ""):1.;
    }

    float w_base = w_GenNorm * w_BR * w_TopPtRW * sf_MuTk ;
    float weight_PUUp      = w_base* w_PUUp  * w_Pref    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_PUDown    = w_base* w_PUDown* w_Pref    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_PrefUp    = w_base* w_PU    * w_PrefUp  * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_PrefDown  = w_base* w_PU    * w_PrefDown* sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_MuEnUp    = w_base* w_PU    * w_Pref    * sf_mID_MuEnUp  * sf_eReco          * sf_eID          * sf_Tr_MuEnUp   * sf_B;
    float weight_MuEnDown  = w_base* w_PU    * w_Pref    * sf_mID_MuEnDown* sf_eReco          * sf_eID          * sf_Tr_MuEnDown * sf_B;
    float weight_MuIDUp    = w_base* w_PU    * w_Pref    * sf_mIDUp       * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_MuIDDown  = w_base* w_PU    * w_Pref    * sf_mIDDown     * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_ElRecoUp  = w_base* w_PU    * w_Pref    * sf_mID         * sf_eRecoUp        * sf_eID          * sf_Tr          * sf_B;
    float weight_ElRecoDown= w_base* w_PU    * w_Pref    * sf_mID         * sf_eRecoDown      * sf_eID          * sf_Tr          * sf_B;
    float weight_ElIDUp    = w_base* w_PU    * w_Pref    * sf_mID         * sf_eReco          * sf_eIDUp        * sf_Tr          * sf_B;
    float weight_ElIDDown  = w_base* w_PU    * w_Pref    * sf_mID         * sf_eReco          * sf_eIDDown      * sf_Tr          * sf_B;
    float weight_ElSclUp   = w_base* w_PU    * w_Pref    * sf_mID         * sf_eReco_ElSclUp  * sf_eID_ElSclUp  * sf_Tr_ElSclUp  * sf_B;
    float weight_ElSclDown = w_base* w_PU    * w_Pref    * sf_mID         * sf_eReco_ElSclDown* sf_eID_ElSclDown* sf_Tr_ElSclDown* sf_B;
    float weight_ElResUp   = w_base* w_PU    * w_Pref    * sf_mID         * sf_eReco_ElResUp  * sf_eID_ElResUp  * sf_Tr_ElResUp  * sf_B;
    float weight_ElResDown = w_base* w_PU    * w_Pref    * sf_mID         * sf_eReco_ElResDown* sf_eID_ElResDown* sf_Tr_ElResDown* sf_B;
    float weight_JESUp     = w_base* w_PU    * w_Pref    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_JESUp;
    float weight_JESDown   = w_base* w_PU    * w_Pref    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_JESDown;
    float weight_JERUp     = w_base* w_PU    * w_Pref    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_JERUp;
    float weight_JERDown   = w_base* w_PU    * w_Pref    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_JERDown;
    float weight_LTagUp    = w_base* w_PU    * w_Pref    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_LTagUp;
    float weight_LTagDown  = w_base* w_PU    * w_Pref    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_LTagDown;
    float weight_HTagUp    = w_base* w_PU    * w_Pref    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_HTagUp;
    float weight_HTagDown  = w_base* w_PU    * w_Pref    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_HTagDown;
    float weight_TrUp      = w_base* w_PU    * w_Pref    * sf_mID         * sf_eReco          * sf_eID          * sf_TrUp        * sf_B;
    float weight_TrDown    = w_base* w_PU    * w_Pref    * sf_mID         * sf_eReco          * sf_eID          * sf_TrDown      * sf_B;


    if(!IsDATA){
      SysWgtStrPairList.clear();//safe-guard, in-case there was usage before this and uncleared
      SysWgtStrPairList.push_back( make_pair(weight_PUUp          , "_SystUp_PU"          ) );
      SysWgtStrPairList.push_back( make_pair(weight_PUDown        , "_SystDown_PU"        ) );
      SysWgtStrPairList.push_back( make_pair(weight_PrefUp        , "_SystUp_Pref"        ) );
      SysWgtStrPairList.push_back( make_pair(weight_PrefDown      , "_SystDown_Pref"      ) );
      SysWgtStrPairList.push_back( make_pair(weight_ElRecoUp      , "_SystUp_ElReco"      ) );
      SysWgtStrPairList.push_back( make_pair(weight_ElRecoDown    , "_SystDown_ElReco"    ) );
      SysWgtStrPairList.push_back( make_pair(weight_ElIDUp        , "_SystUp_ElID"        ) );
      SysWgtStrPairList.push_back( make_pair(weight_ElIDDown      , "_SystDown_ElID"      ) );
      SysWgtStrPairList.push_back( make_pair(weight_MuIDUp        , "_SystUp_MuID"        ) );
      SysWgtStrPairList.push_back( make_pair(weight_MuIDDown      , "_SystDown_MuID"      ) );
      SysWgtStrPairList.push_back( make_pair(weight_TrUp          , "_SystUp_Tr"          ) );
      SysWgtStrPairList.push_back( make_pair(weight_TrDown        , "_SystDown_Tr"        ) );
      SysWgtStrPairList.push_back( make_pair(weight_LTagUp        , "_SystUp_LTag"        ) );
      SysWgtStrPairList.push_back( make_pair(weight_LTagDown      , "_SystDown_LTag"      ) );
      SysWgtStrPairList.push_back( make_pair(weight_HTagUp        , "_SystUp_HTag"        ) );
      SysWgtStrPairList.push_back( make_pair(weight_HTagDown      , "_SystDown_HTag"      ) );

      DoSystRun(muonTightColl, muonLooseColl, muonLooseColl, ElSclUpTColl, ElSclUpLColl, electronVetoColl,
                jetColl, bjetColl, vMET_T1xy, ev, weight_ElSclUp, "_SystUp_ElScl");
      DoSystRun(muonTightColl, muonLooseColl, muonLooseColl, ElSclDownTColl, ElSclDownLColl, electronVetoColl,
                jetColl, bjetColl, vMET_T1xy, ev, weight_ElSclDown, "_SystDown_ElScl");
      DoSystRun(muonTightColl, muonLooseColl, muonLooseColl, ElResUpTColl, ElResUpLColl, electronVetoColl,
                jetColl, bjetColl, vMET_T1xy, ev, weight_ElResUp, "_SystUp_ElRes");
      DoSystRun(muonTightColl, muonLooseColl, muonLooseColl, ElResDownTColl, ElResDownLColl, electronVetoColl,
                jetColl, bjetColl, vMET_T1xy, ev, weight_ElResDown, "_SystDown_ElRes");
      DoSystRun(MuEnUpTColl, MuEnUpLColl, MuEnUpLColl, electronTightColl, electronLooseColl, electronVetoColl,
                jetColl, bjetColl, vMET_T1xy, ev, weight_MuEnUp, "_SystUp_MuEn");
      DoSystRun(MuEnDownTColl, MuEnDownLColl, MuEnDownLColl, electronTightColl, electronLooseColl, electronVetoColl,
                jetColl, bjetColl, vMET_T1xy, ev, weight_MuEnDown, "_SystDown_MuEn");
      DoSystRun(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                jetJESUpColl, bjetJESUpColl, vMET_T1xy_JESUp, ev, weight_JESUp, "_SystUp_JES");
      DoSystRun(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                jetJESDownColl, bjetJESDownColl, vMET_T1xy_JESDown, ev, weight_JESDown, "_SystDown_JES");
      DoSystRun(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                jetJERUpColl, bjetJERUpColl, vMET_T1xy_JERUp, ev, weight_JERUp, "_SystUp_JER");
      DoSystRun(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                jetJERDownColl, bjetJERDownColl, vMET_T1xy_JERDown, ev, weight_JERDown, "_SystDown_JER");
      DoSystRun(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                jetColl, bjetColl, vMET_T1xy_UnclUp, ev, weight, "_SystUp_Uncl");
      DoSystRun(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                jetColl, bjetColl, vMET_T1xy_UnclDown, ev, weight, "_SystDown_Uncl");
    }
    if(SysWgtStrPairList.size()>0){
      DoSystRun(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                jetColl, bjetColl, vMET_T1xy, ev, weight, "SystWgtVar");
      SysWgtStrPairList.clear();
    }
  }

}

void DiLepValid::DoSystRun(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                           vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                           vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& Ev, float weight, TString Label)
{

  if(MuMu && DiLIncl){
    AnalyzeDiMuon(MuTColl, MuVColl, ElTColl, ElVColl, JetColl, BJetColl, vMET, weight, Label);
  }
  else if(ElEl && DiLIncl){
    AnalyzeDiElectron(MuTColl, MuVColl, ElTColl, ElVColl, JetColl, BJetColl, vMET, weight, Label);
  }
  else if(MuMu && DiLBJet){
    AnalyzeDiMuonBJet(MuTColl, MuVColl, ElTColl, ElVColl, JetColl, BJetColl, vMET, weight, Label);
  }
  else if(ElEl && DiLBJet){
    AnalyzeDiElectronBJet(MuTColl, MuVColl, ElTColl, ElVColl, JetColl, BJetColl, vMET, weight, Label);
  }
  else if(SF2L && DiLBJet){
    AnalyzeDiLeptonBJet(MuTColl, MuVColl, ElTColl, ElVColl, JetColl, BJetColl, vMET, weight, Label);
  }
  else{ cout<<"no corresponding cycle!"<<endl; exit(ENODATA); }

  return;

}



void DiLepValid::AnalyzeDiMuon(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl,
                               vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{
  bool ApplyWVar = Label.Contains("SystWgtVar");
  if( ApplyWVar ) Label.ReplaceAll("SystWgtVar","");
  if( !(MuTColl.size()==2 && MuLColl.size()==2) ) return;
  if( ElLColl.size()!=0 ) return;
  if( MuTColl.at(0).Charge() == MuTColl.at(1).Charge() ) return;

  float PTmin1 = 10., PTmin2 = 10.;
  if     (SglLTrig){ PTmin1 = DataYear==2017? 29.:26.; PTmin2 = 10.; }
  else if(DiLTrig ){ PTmin1 = 20., PTmin2 = 10.; }
  if( !(MuTColl.at(0).Pt()>PTmin1 && MuTColl.at(1).Pt()>PTmin2) ) return; 
  
  float Mmumu = (MuTColl.at(0)+MuTColl.at(1)).M();
  if(Mmumu<50) return;

  if(HEMCheck){
    bool IsHEMReg=false;
    for(unsigned int im=0; im<MuTColl.size() && !IsHEMReg; im++){
      if(!IsHEMReg){ IsHEMReg=IsHEMIssueReg(MuTColl.at(im)); } else break; 
    }
    if(IsHEMReg) return;
  }
       
  FillHist("NCount"+Label, 0., weight, 1, 0., 1., ApplyWVar, SysWgtStrPairList);
  FillHist("NPV"   +Label, nPV, weight, 80, 0., 80., ApplyWVar, SysWgtStrPairList);
  FillHist("Rho"   +Label, Rho, weight, 70, 0., 70., ApplyWVar, SysWgtStrPairList);
  FillHist("Mmumu" +Label, Mmumu, weight, 60, 60., 120., ApplyWVar, SysWgtStrPairList);
  FillHist("PtMu1" +Label, MuTColl.at(0).Pt(), weight, 40, 0., 200., ApplyWVar, SysWgtStrPairList);
  FillHist("PtMu2" +Label, MuTColl.at(1).Pt(), weight, 40, 0., 200., ApplyWVar, SysWgtStrPairList);
  FillHist("EtaMu1"+Label, MuTColl.at(0).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
  FillHist("EtaMu2"+Label, MuTColl.at(1).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
  FillHist("NJet"  +Label, JetColl.size(), weight, 10, 0., 10., ApplyWVar, SysWgtStrPairList);
  FillHist("NBJet" +Label, BJetColl.size(), weight, 10, 0., 10., ApplyWVar, SysWgtStrPairList);
  FillHist("MET"   +Label, vMET.Pt(), weight, 40, 0., 200., ApplyWVar, SysWgtStrPairList);
  FillHist("METPhi"+Label, vMET.Phi(), weight, 10, -3.15, 3.15, ApplyWVar, SysWgtStrPairList);

  float HT=0; for(unsigned int itj=0; itj<JetColl.size(); itj++){ HT+=JetColl.at(itj).Pt(); }
  FillHist("HT"+Label, HT, weight, 40, 0., 200., ApplyWVar, SysWgtStrPairList);
} 


void DiLepValid::AnalyzeDiMuonBJet(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl,
                                   vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{
  bool ApplyWVar = Label.Contains("SystWgtVar");
  if( ApplyWVar ) Label.ReplaceAll("SystWgtVar","");
  if( !(MuTColl.size()==2 && MuLColl.size()==2) ) return;
  if( ElLColl.size()!=0 ) return;
  if( MuTColl.at(0).Charge() == MuTColl.at(1).Charge() ) return;

  float PTmin1 = 10., PTmin2 = 10.;
  if     (SglLTrig){ PTmin1 = DataYear==2017? 29.:26.; PTmin2 = 10.; }
  else if(DiLTrig ){ PTmin1 = 20., PTmin2 = 10.; }
  if( !(MuTColl.at(0).Pt()>PTmin1 && MuTColl.at(1).Pt()>PTmin2) ) return; 
  
  float Mmumu = (MuTColl.at(0)+MuTColl.at(1)).M();
  if(Mmumu<12) return;

  if(HEMCheck){
    bool IsHEMReg=false;
    for(unsigned int im=0; im<MuTColl.size() && !IsHEMReg; im++){
      if(!IsHEMReg){ IsHEMReg=IsHEMIssueReg(MuTColl.at(im)); } else break; 
    }
    for(unsigned int ib=0; ib<BJetColl.size() && !IsHEMReg; ib++){
      if(!IsHEMReg){ IsHEMReg=IsHEMIssueReg(BJetColl.at(ib)); } else break; 
    }
    for(unsigned int ij=0; ij<JetColl.size() && !IsHEMReg; ij++){
      if(!IsHEMReg && ij<2){ IsHEMReg=IsHEMIssueReg(JetColl.at(ij)); } else break;
    }   
    if(IsHEMReg) return;
  }

  float HT=0; for(unsigned int itj=0; itj<JetColl.size(); itj++){ HT+=JetColl.at(itj).Pt(); }
  bool OffZ = fabs(Mmumu-91.2)>15, PtJet1_50 = JetColl.size()>0? JetColl.at(0).Pt()>50:false;
  bool MET50 = vMET.Pt()>50.;

  int NBjet = BJetColl.size(), Njet = JetColl.size();
  if(BJetColl.size()==0) return; 

  int it_cut=0;
  FillHist("CutFlow"+Label, it_cut, weight, 20, 0., 20., ApplyWVar, SysWgtStrPairList); it_cut++;

  if(Njet<2) return;
  FillHist("CutFlow"+Label, it_cut, weight, 20, 0., 20., ApplyWVar, SysWgtStrPairList); it_cut++;

  if(!OffZ) return;
  FillHist("CutFlow"+Label, it_cut, weight, 20, 0., 20., ApplyWVar, SysWgtStrPairList); it_cut++;

  if(!PtJet1_50) return;
  FillHist("CutFlow"+Label, it_cut, weight, 20, 0., 20., ApplyWVar, SysWgtStrPairList);


  vector<TString> LabelList = {"_1B2JOffZPtb50"+Label};
  if( MET50 ){
    LabelList.push_back("_1B2JOffZPtb50MET50"+Label);
    FillHist("CutFlow"+Label, it_cut+1, weight, 20, 0., 20., ApplyWVar, SysWgtStrPairList);
  }
  if( NBjet>1 ){
    LabelList.push_back("_2BOffZPtb50"+Label);
    FillHist("CutFlow"+Label, it_cut+2, weight, 20, 0., 20., ApplyWVar, SysWgtStrPairList);
  }
  if( NBjet>1 && MET50 ){
    LabelList.push_back("_2BOffZPtb50MET50"+Label);
    FillHist("CutFlow"+Label, it_cut+3, weight, 20, 0., 20., ApplyWVar, SysWgtStrPairList);
  }
 
  for(unsigned int il=0; il<LabelList.size(); il++){
    TString FinLabel(LabelList.at(il));
    FillHist("NCount"+FinLabel, 0., weight, 1, 0., 1., ApplyWVar, SysWgtStrPairList);
    FillHist("Mmumu" +FinLabel, Mmumu, weight, 30, 0., 300., ApplyWVar, SysWgtStrPairList);
    FillHist("PtMu1" +FinLabel, MuTColl.at(0).Pt(), weight, 30, 0., 300., ApplyWVar, SysWgtStrPairList);
    FillHist("PtMu2" +FinLabel, MuTColl.at(1).Pt(), weight, 30, 0., 300., ApplyWVar, SysWgtStrPairList);
    FillHist("EtaMu1"+FinLabel, MuTColl.at(0).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    FillHist("EtaMu2"+FinLabel, MuTColl.at(1).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    FillHist("PtJet1"+FinLabel, JetColl.at(0).Pt(), weight, 50, 0., 500., ApplyWVar, SysWgtStrPairList);
    if(Njet>1) FillHist("PtJet2"+FinLabel, JetColl.at(1).Pt(), weight, 40, 0., 400., ApplyWVar, SysWgtStrPairList);
    FillHist("PtBJet1"+FinLabel, BJetColl.at(0).Pt(), weight, 50, 0., 500., ApplyWVar, SysWgtStrPairList);
    if(NBjet>1) FillHist("PtBJet2"+FinLabel, BJetColl.at(1).Pt(), weight, 40, 0., 400., ApplyWVar, SysWgtStrPairList);
    FillHist("EtaJet1"+FinLabel, JetColl.at(0).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    if(Njet>1) FillHist("EtaJet2"+FinLabel, JetColl.at(1).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    FillHist("EtaBJet1"+FinLabel, BJetColl.at(0).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    if(NBjet>1) FillHist("EtaBJet2"+FinLabel, BJetColl.at(1).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    FillHist("NJet"  +FinLabel, JetColl.size(), weight, 10, 0., 10., ApplyWVar, SysWgtStrPairList);
    FillHist("NBJet" +FinLabel, BJetColl.size(), weight, 10, 0., 10., ApplyWVar, SysWgtStrPairList);
    FillHist("MET"   +FinLabel, vMET.Pt(), weight, 40, 0., 400., ApplyWVar, SysWgtStrPairList);
    FillHist("METPhi"+FinLabel, vMET.Phi(), weight, 10, -3.15, 3.15, ApplyWVar, SysWgtStrPairList);
    FillHist("HT"+FinLabel, HT, weight, 32, 0., 800., ApplyWVar, SysWgtStrPairList);
    FillHist("dRll"+FinLabel, MuTColl.at(0).DeltaR(MuTColl.at(1)), weight, 25, 0., 5., ApplyWVar, SysWgtStrPairList);
  }

} 


void DiLepValid::AnalyzeDiElectronBJet(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl,
                                       vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{
  bool ApplyWVar = Label.Contains("SystWgtVar");
  if( ApplyWVar ) Label.ReplaceAll("SystWgtVar","");
  if( !(ElTColl.size()==2 && ElLColl.size()==2) ) return;
  if( MuLColl.size()!=0 ) return;
  if( ElTColl.at(0).Charge() == ElTColl.at(1).Charge() ) return;

  float PTmin1 = 10., PTmin2 = 10.;
  if     (SglLTrig){ PTmin1 = DataYear==2016? 30.:35.; PTmin2 = 10.; }
  else if(DiLTrig ){ PTmin1 = 25., PTmin2 = 15.; }
  if( !(ElTColl.at(0).Pt()>PTmin1 && ElTColl.at(1).Pt()>PTmin2) ) return; 

  
  float Melel = (ElTColl.at(0)+ElTColl.at(1)).M();
  if(Melel<12) return;

  if(HEMCheck){
    bool IsHEMReg=false;
    for(unsigned int ie=0; ie<ElTColl.size() && !IsHEMReg; ie++){
      if(!IsHEMReg){ IsHEMReg=IsHEMIssueReg(ElTColl.at(ie)); } else break; 
    }
    for(unsigned int ib=0; ib<BJetColl.size() && !IsHEMReg; ib++){
      if(!IsHEMReg){ IsHEMReg=IsHEMIssueReg(BJetColl.at(ib)); } else break; 
    }
    for(unsigned int ij=0; ij<JetColl.size() && !IsHEMReg; ij++){
      if(!IsHEMReg && ij<2){ IsHEMReg=IsHEMIssueReg(JetColl.at(ij)); } else break;
    }   
    if(IsHEMReg) return;
  }

  float HT=0; for(unsigned int itj=0; itj<JetColl.size(); itj++){ HT+=JetColl.at(itj).Pt(); }
  float ST=HT+vMET.Pt()+ElTColl.at(0).Pt()+ElTColl.at(1).Pt();
  float MET2ST=pow(vMET.Pt(),2.)/ST;
  float MET2HT=HT==0? 0.:pow(vMET.Pt(),2.)/HT;
  bool OffZ = fabs(Melel-91.2)>15, PtJet1_50 = JetColl.size()>0? JetColl.at(0).Pt()>50:false;
  bool MET50 = vMET.Pt()>50.;

  int NBjet = BJetColl.size(), Njet = JetColl.size();
  if(BJetColl.size()==0) return; 

  int it_cut=0;
  FillHist("CutFlow"+Label, it_cut, weight, 20, 0., 20., ApplyWVar, SysWgtStrPairList); it_cut++;

  if(Njet<2) return;
  FillHist("CutFlow"+Label, it_cut, weight, 20, 0., 20., ApplyWVar, SysWgtStrPairList); it_cut++;

  if(!OffZ) return;
  FillHist("CutFlow"+Label, it_cut, weight, 20, 0., 20., ApplyWVar, SysWgtStrPairList); it_cut++;

  if(!PtJet1_50) return;
  FillHist("CutFlow"+Label, it_cut, weight, 20, 0., 20., ApplyWVar, SysWgtStrPairList);


  vector<TString> LabelList = {"_1B2JOffZPtb50"+Label};
  if( MET50 ){
    LabelList.push_back("_1B2JOffZPtb50MET50"+Label);
    FillHist("CutFlow"+Label, it_cut+1, weight, 20, 0., 20., ApplyWVar, SysWgtStrPairList);
  }
  if( NBjet>1 ){
    LabelList.push_back("_2BOffZPtb50"+Label);
    FillHist("CutFlow"+Label, it_cut+2, weight, 20, 0., 20., ApplyWVar, SysWgtStrPairList);
  }
  if( NBjet>1 && MET50 ){
    LabelList.push_back("_2BOffZPtb50MET50"+Label);
    FillHist("CutFlow"+Label, it_cut+3, weight, 20, 0., 20., ApplyWVar, SysWgtStrPairList);
  }
 
  for(unsigned int il=0; il<LabelList.size(); il++){
    TString FinLabel(LabelList.at(il));
    FillHist("NCount"+FinLabel, 0., weight, 1, 0., 1., ApplyWVar, SysWgtStrPairList);
    FillHist("Melel" +FinLabel, Melel, weight, 30, 0., 300., ApplyWVar, SysWgtStrPairList);
    FillHist("PtEl1" +FinLabel, ElTColl.at(0).Pt(), weight, 30, 0., 300., ApplyWVar, SysWgtStrPairList);
    FillHist("PtEl2" +FinLabel, ElTColl.at(1).Pt(), weight, 30, 0., 300., ApplyWVar, SysWgtStrPairList);
    FillHist("EtaEl1"+FinLabel, ElTColl.at(0).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    FillHist("EtaEl2"+FinLabel, ElTColl.at(1).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    FillHist("PtJet1"+FinLabel, JetColl.at(0).Pt(), weight, 50, 0., 500., ApplyWVar, SysWgtStrPairList);
    if(Njet>1) FillHist("PtJet2"+FinLabel, JetColl.at(1).Pt(), weight, 40, 0., 400., ApplyWVar, SysWgtStrPairList);
    FillHist("PtBJet1"+FinLabel, BJetColl.at(0).Pt(), weight, 50, 0., 500., ApplyWVar, SysWgtStrPairList);
    if(NBjet>1) FillHist("PtBJet2"+FinLabel, BJetColl.at(1).Pt(), weight, 40, 0., 400., ApplyWVar, SysWgtStrPairList);
    FillHist("EtaJet1"+FinLabel, JetColl.at(0).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    if(Njet>1) FillHist("EtaJet2"+FinLabel, JetColl.at(1).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    FillHist("EtaBJet1"+FinLabel, BJetColl.at(0).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    if(NBjet>1) FillHist("EtaBJet2"+FinLabel, BJetColl.at(1).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    FillHist("NJet"  +FinLabel, JetColl.size(), weight, 10, 0., 10., ApplyWVar, SysWgtStrPairList);
    FillHist("NBJet" +FinLabel, BJetColl.size(), weight, 10, 0., 10., ApplyWVar, SysWgtStrPairList);
    FillHist("MET"   +FinLabel, vMET.Pt(), weight, 40, 0., 400., ApplyWVar, SysWgtStrPairList);
    FillHist("METPhi"+FinLabel, vMET.Phi(), weight, 10, -3.15, 3.15, ApplyWVar, SysWgtStrPairList);
    FillHist("ST"+FinLabel, ST, weight, 48, 0., 1200., ApplyWVar, SysWgtStrPairList);
    FillHist("HT"+FinLabel, HT, weight, 32, 0., 800., ApplyWVar, SysWgtStrPairList);
    FillHist("MET2ST"+FinLabel, MET2ST, weight, 12, 0., 120., ApplyWVar, SysWgtStrPairList);
    FillHist("MET2HT"+FinLabel, MET2HT, weight, 30, 0., 300., ApplyWVar, SysWgtStrPairList);
    FillHist("dRll"+FinLabel, ElTColl.at(0).DeltaR(ElTColl.at(1)), weight, 25, 0., 5., ApplyWVar, SysWgtStrPairList);
  }

} 


void DiLepValid::AnalyzeDiLeptonBJet(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl,
                                       vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{
  bool ApplyWVar = Label.Contains("SystWgtVar");
  if( ApplyWVar ) Label.ReplaceAll("SystWgtVar","");
  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size();
  if( !( (NMuT==2 && NElT==0) or (NMuT==0 && NElT==2) ) ) return;
  if( !( NMuT==NMuL && NElT==NElL ) ) return;
  if( SumCharge(MuTColl,ElTColl)!=0 ) return;

  float Mll=-1, dRll=-1, HT=-1;//, MET2HT=-1;
  float Ptl1=-1, Ptl2=-1, Etal1=999., Etal2=999.;
  if( NElT==2 ){
    float PTmin1 = 10., PTmin2 = 10.;
    if     (SglLTrig){ PTmin1 = DataYear==2016? 30.:35.; PTmin2 = 10.; }
    else if(DiLTrig ){ PTmin1 = 25., PTmin2 = 15.; }
    if( !(ElTColl.at(0).Pt()>PTmin1 && ElTColl.at(1).Pt()>PTmin2) ) return; 

    Ptl1 = ElTColl.at(0).Pt(), Ptl2 = ElTColl.at(1).Pt();
    Etal1 = ElTColl.at(0).Eta(), Etal2 = ElTColl.at(1).Eta();
    Mll = (ElTColl.at(0)+ElTColl.at(1)).M();
    dRll = ElTColl.at(0).DeltaR(ElTColl.at(1));
    HT=0; for(unsigned int itj=0; itj<JetColl.size(); itj++){ HT+=JetColl.at(itj).Pt(); }
  }
  else if( NMuT==2 ){
    float PTmin1 = 10., PTmin2 = 10.;
    if     (SglLTrig){ PTmin1 = DataYear==2017? 29.:26.; PTmin2 = 10.; }
    else if(DiLTrig ){ PTmin1 = 20., PTmin2 = 10.; }
    if( !(MuTColl.at(0).Pt()>PTmin1 && MuTColl.at(1).Pt()>PTmin2) ) return; 

    Ptl1  = MuTColl.at(0).Pt(), Ptl2 = MuTColl.at(1).Pt();
    Etal1 = MuTColl.at(0).Eta(), Etal2 = MuTColl.at(1).Eta();
    Mll  = (MuTColl.at(0)+MuTColl.at(1)).M();
    dRll = MuTColl.at(0).DeltaR(MuTColl.at(1));
    HT=0; for(unsigned int itj=0; itj<JetColl.size(); itj++){ HT+=JetColl.at(itj).Pt(); }
  }
  else return;

  if(Mll<12) return;

  if(HEMCheck){
    bool IsHEMReg=false;
    for(unsigned int im=0; im<MuTColl.size() && !IsHEMReg; im++){
      if(!IsHEMReg){ IsHEMReg=IsHEMIssueReg(MuTColl.at(im)); } else break; 
    }
    for(unsigned int ie=0; ie<ElTColl.size() && !IsHEMReg; ie++){
      if(!IsHEMReg){ IsHEMReg=IsHEMIssueReg(ElTColl.at(ie)); } else break; 
    }
    for(unsigned int ib=0; ib<BJetColl.size() && !IsHEMReg; ib++){
      if(!IsHEMReg){ IsHEMReg=IsHEMIssueReg(BJetColl.at(ib)); } else break; 
    }
    for(unsigned int ij=0; ij<JetColl.size() && !IsHEMReg; ij++){
      if(!IsHEMReg && ij<2){ IsHEMReg=IsHEMIssueReg(JetColl.at(ij)); } else break;
    }   
    if(IsHEMReg) return;
  }


  bool OffZ = fabs(Mll-91.2)>15, PtJet1_50 = JetColl.size()>0? JetColl.at(0).Pt()>50:false;
  bool MET50 = vMET.Pt()>50.;

  int NBjet = BJetColl.size(), Njet = JetColl.size();
  if(BJetColl.size()==0) return; 

  int it_cut=0;
  FillHist("CutFlow"+Label, it_cut, weight, 20, 0., 20., ApplyWVar, SysWgtStrPairList); it_cut++;

  if(Njet<2) return;
  FillHist("CutFlow"+Label, it_cut, weight, 20, 0., 20., ApplyWVar, SysWgtStrPairList); it_cut++;

  if(!OffZ) return;
  FillHist("CutFlow"+Label, it_cut, weight, 20, 0., 20., ApplyWVar, SysWgtStrPairList); it_cut++;

  if(!PtJet1_50) return;
  FillHist("CutFlow"+Label, it_cut, weight, 20, 0., 20., ApplyWVar, SysWgtStrPairList);


  vector<TString> LabelList = {}; //{"_1B2JOffZPtb50"+Label};
  if( MET50 ){
    //LabelList.push_back("_1B2JOffZPtb50MET50"+Label);
    FillHist("CutFlow"+Label, it_cut+1, weight, 20, 0., 20., ApplyWVar, SysWgtStrPairList);
  }
  if( NBjet>1 ){
    //LabelList.push_back("_2BOffZPtb50"+Label);
    FillHist("CutFlow"+Label, it_cut+2, weight, 20, 0., 20., ApplyWVar, SysWgtStrPairList);
  }
  if( NBjet>1 && MET50 ){
    LabelList.push_back("_2BOffZPtb50MET50"+Label);
    FillHist("CutFlow"+Label, it_cut+3, weight, 20, 0., 20., ApplyWVar, SysWgtStrPairList);
  }
 
  for(unsigned int il=0; il<LabelList.size(); il++){
    TString FinLabel(LabelList.at(il));
    FillHist("NCount"+FinLabel, 0., weight, 1, 0., 1., ApplyWVar, SysWgtStrPairList);
    FillHist("Mll"  +FinLabel, Mll, weight, 30, 0., 300., ApplyWVar, SysWgtStrPairList);
    FillHist("Ptl1" +FinLabel, Ptl1, weight, 30, 0., 300., ApplyWVar, SysWgtStrPairList);
    FillHist("Ptl2" +FinLabel, Ptl2, weight, 30, 0., 300., ApplyWVar, SysWgtStrPairList);
    FillHist("Etal1"+FinLabel, Etal1, weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    FillHist("Etal2"+FinLabel, Etal2, weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    FillHist("PtJet1"+FinLabel, JetColl.at(0).Pt(), weight, 50, 0., 500., ApplyWVar, SysWgtStrPairList);
    if(Njet>1) FillHist("PtJet2"+FinLabel, JetColl.at(1).Pt(), weight, 40, 0., 400., ApplyWVar, SysWgtStrPairList);
    FillHist("PtBJet1"+FinLabel, BJetColl.at(0).Pt(), weight, 50, 0., 500., ApplyWVar, SysWgtStrPairList);
    if(NBjet>1) FillHist("PtBJet2"+FinLabel, BJetColl.at(1).Pt(), weight, 40, 0., 400., ApplyWVar, SysWgtStrPairList);
    FillHist("EtaJet1"+FinLabel, JetColl.at(0).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    if(Njet>1) FillHist("EtaJet2"+FinLabel, JetColl.at(1).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    FillHist("EtaBJet1"+FinLabel, BJetColl.at(0).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    if(NBjet>1) FillHist("EtaBJet2"+FinLabel, BJetColl.at(1).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    FillHist("NJet"  +FinLabel, JetColl.size(), weight, 10, 0., 10., ApplyWVar, SysWgtStrPairList);
    FillHist("NBJet" +FinLabel, BJetColl.size(), weight, 10, 0., 10., ApplyWVar, SysWgtStrPairList);
    FillHist("MET"   +FinLabel, vMET.Pt(), weight, 40, 0., 400., ApplyWVar, SysWgtStrPairList);
    FillHist("METPhi"+FinLabel, vMET.Phi(), weight, 10, -3.15, 3.15, ApplyWVar, SysWgtStrPairList);
    FillHist("HT"    +FinLabel, HT, weight, 32, 0., 800., ApplyWVar, SysWgtStrPairList);
    FillHist("dRll"  +FinLabel, dRll, weight, 25, 0., 5., ApplyWVar, SysWgtStrPairList);
  }

} 





void DiLepValid::AnalyzeDiElectron(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl,
                                   vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{
  bool ApplyWVar = Label.Contains("SystWgtVar");
  if( ApplyWVar ) Label.ReplaceAll("SystWgtVar","");
  if( !(ElTColl.size()==2 && ElLColl.size()==2) ) return;
  if( MuLColl.size()!=0 ) return;
  if( ElTColl.at(0).Charge() == ElTColl.at(1).Charge() ) return;

  float PTmin1 = 10., PTmin2 = 10.;
  if     (SglLTrig){ PTmin1 = DataYear==2016? 30.:35.; PTmin2 = 10.; }
  else if(DiLTrig ){ PTmin1 = 25., PTmin2 = 15.; }
  if( !(ElTColl.at(0).Pt()>PTmin1 && ElTColl.at(1).Pt()>PTmin2) ) return; 

  float Melel = (ElTColl.at(0)+ElTColl.at(1)).M();
  if(Melel<50) return;

  if(HEMCheck){
    bool IsHEMReg=false;
    for(unsigned int im=0; im<ElTColl.size() && !IsHEMReg; im++){
      if(!IsHEMReg){ IsHEMReg=IsHEMIssueReg(ElTColl.at(im)); } else break; 
    }
    if(IsHEMReg) return;
  }

  FillHist("NCount"+Label, 0., weight, 1, 0., 1., ApplyWVar, SysWgtStrPairList);
  FillHist("NPV"   +Label, nPV, weight, 80, 0., 80., ApplyWVar, SysWgtStrPairList);
  FillHist("Rho"   +Label, Rho, weight, 70, 0., 70., ApplyWVar, SysWgtStrPairList);
  FillHist("Melel" +Label, Melel, weight, 60, 60., 120., ApplyWVar, SysWgtStrPairList);
  FillHist("PtEl1" +Label, ElTColl.at(0).Pt(), weight, 40, 0., 200., ApplyWVar, SysWgtStrPairList);
  FillHist("PtEl2" +Label, ElTColl.at(1).Pt(), weight, 40, 0., 200., ApplyWVar, SysWgtStrPairList);
  FillHist("EtaEl1"+Label, ElTColl.at(0).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
  FillHist("EtaEl2"+Label, ElTColl.at(1).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
  FillHist("NJet"  +Label, JetColl.size(), weight, 10, 0., 10., ApplyWVar, SysWgtStrPairList);
  FillHist("NBJet" +Label, BJetColl.size(), weight, 10, 0., 10., ApplyWVar, SysWgtStrPairList);
  FillHist("MET"   +Label, vMET.Pt(), weight, 40, 0., 200., ApplyWVar, SysWgtStrPairList);

}


void DiLepValid::AnalyzeElectronMuon(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl,
                                     vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)

{
  bool ApplyWVar = Label.Contains("SystWgtVar");
  if( ApplyWVar ) Label.ReplaceAll("SystWgtVar","");
  if( !(ElTColl.size()==1 && ElLColl.size()==1) ) return;
  if( !(MuTColl.size()==1 && MuLColl.size()==1) ) return;
  if( !(JetColl.size()>1 && BJetColl.size()>0) ) return;
  if( MuTColl.at(0).Charge() == ElTColl.at(0).Charge() ) return;
  if( MuTColl.at(0).DeltaR(ElTColl.at(0))<0.4 ) return;

  float PTmin1 = 10., PTminMu = 10., PTminEl = 10.;
  if(SglLTrig){ PTminMu = DataYear==2017? 29.:26.; PTminEl = 10., PTmin1 = PTminMu; }
  if(DiLTrig ){ PTminMu = 10., PTminEl = GetEraShort()=="2016a"? 10.:15.; PTmin1 = 25.; }
  if(!(MuTColl.at(0).Pt()>PTminMu && ElTColl.at(0).Pt()>PTminEl)) return; 
  if(!(MuTColl.at(0).Pt()>PTmin1  || ElTColl.at(0).Pt()>PTmin1 )) return; 


  FillHist("NCount"+Label, 0., weight, 1, 0., 1., ApplyWVar, SysWgtStrPairList);
  FillHist("NPV"+Label, nPV, weight, 80, 0., 80., ApplyWVar, SysWgtStrPairList);
  FillHist("Rho"+Label, Rho, weight, 70, 0., 70., ApplyWVar, SysWgtStrPairList);
  FillHist("PtMu1" +Label, MuTColl.at(0).Pt(), weight, 30, 0., 300., ApplyWVar, SysWgtStrPairList);
  FillHist("PtEl1" +Label, ElTColl.at(0).Pt(), weight, 30, 0., 300., ApplyWVar, SysWgtStrPairList);
  FillHist("PtJet1"+Label, JetColl.at(0).Pt(), weight, 50, 0., 500., ApplyWVar, SysWgtStrPairList);
  FillHist("PtJet2"+Label, JetColl.at(1).Pt(), weight, 40, 0., 400., ApplyWVar, SysWgtStrPairList);
  FillHist("EtaMu1"+Label, MuTColl.at(0).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
  FillHist("EtaEl1"+Label, ElTColl.at(0).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
  FillHist("EtaJet1"+Label, JetColl.at(0).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
  FillHist("EtaJet2"+Label, JetColl.at(1).Eta(), weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
  FillHist("MET"   +Label, vMET.Pt(), weight, 40, 0., 400., ApplyWVar, SysWgtStrPairList);
  FillHist("METPhi"+Label, vMET.Phi(), weight, 10, -3.15, 3.15, ApplyWVar, SysWgtStrPairList);
  FillHist("NJet"  +Label, JetColl.size(), weight, 10, 0., 10., ApplyWVar, SysWgtStrPairList);
  FillHist("NBJet" +Label, BJetColl.size(), weight, 10, 0., 10., ApplyWVar, SysWgtStrPairList);
  FillHist("dRElMu"+Label, MuTColl.at(0).DeltaR(ElTColl.at(0)), weight, 50, 0., 5., ApplyWVar, SysWgtStrPairList);

  float HT=0; for(unsigned int itj=0; itj<JetColl.size(); itj++){ HT+=JetColl.at(itj).Pt(); }
  float ST=HT+vMET.Pt()+MuTColl.at(0).Pt()+ElTColl.at(0).Pt();
  float MET2ST=pow(vMET.Pt(),2.)/ST;
  float MET2HT=pow(vMET.Pt(),2.)/HT;
  FillHist("ST"+Label, ST, weight, 48, 0., 1200., ApplyWVar, SysWgtStrPairList);
  FillHist("HT"+Label, HT, weight, 32, 0., 800., ApplyWVar, SysWgtStrPairList);
  FillHist("MET2ST"+Label, MET2ST, weight, 12, 0., 120., ApplyWVar, SysWgtStrPairList);
  FillHist("MET2HT"+Label, MET2HT, weight, 30, 0., 300., ApplyWVar, SysWgtStrPairList);

}


Particle DiLepValid::GetMETPhiTemp(TString Option){

  double METxcorr(0.), METycorr(0.), METOrig(0.), METPhiOrig(0.);
  Particle vMET;

  if(!Option.Contains("PUPPI")){
    if(Option.Contains("T1")){ METOrig=pfMET_Type1_pt; METPhiOrig=pfMET_Type1_phi; }
    else                     { METOrig=pfMET_pt;       METPhiOrig=pfMET_phi;       }
  }
  else{
    if(Option.Contains("T1")){ METOrig=PuppiMET_Type1_pt; METPhiOrig=PuppiMET_Type1_phi; }
    else                     { METOrig=PuppiMET_pt;       METPhiOrig=PuppiMET_phi; }
  }
  
  int npv = min(nPV,100);
  TString runera = TString::Itoa(DataYear,10);
  if(IsDATA){ runera+= GetDataPeriod()+(GetEraShort()=="2016b"? "late":""); }
  else      { runera+= "MC"; runera+=(GetEraShort()=="2016a"? "APV":GetEraShort()=="2016b"? "nonAPV":""); }
  
  if(!Option.Contains("PUPPI")){
    if(DataYear==2017){
      //UL2017
      if     (runera=="2017B") METxcorr = -(-0.211161*npv +0.419333);
      else if(runera=="2017B") METycorr = -(0.251789*npv +-1.28089);
      else if(runera=="2017C") METxcorr = -(-0.185184*npv +-0.164009);
      else if(runera=="2017C") METycorr = -(0.200941*npv +-0.56853);
      else if(runera=="2017D") METxcorr = -(-0.201606*npv +0.426502);
      else if(runera=="2017D") METycorr = -(0.188208*npv +-0.58313);
      else if(runera=="2017E") METxcorr = -(-0.162472*npv +0.176329);
      else if(runera=="2017E") METycorr = -(0.138076*npv +-0.250239);
      else if(runera=="2017F") METxcorr = -(-0.210639*npv +0.72934);
      else if(runera=="2017F") METycorr = -(0.198626*npv +1.028);
      else if(runera=="2017MC") METxcorr = -(-0.300155*npv +1.90608);
      else if(runera=="2017MC") METycorr = -(0.300213*npv +-2.02232);
    }
    else if(DataYear==2018){
      //UL2018
      if(runera=="2018A") METxcorr = -(0.263733*npv +-1.91115);
      else if(runera=="2018A") METycorr = -(0.0431304*npv +-0.112043);
      else if(runera=="2018B") METxcorr = -(0.400466*npv +-3.05914);
      else if(runera=="2018B") METycorr = -(0.146125*npv +-0.533233);
      else if(runera=="2018C") METxcorr = -(0.430911*npv +-1.42865);
      else if(runera=="2018C") METycorr = -(0.0620083*npv +-1.46021);
      else if(runera=="2018D") METxcorr = -(0.457327*npv +-1.56856);
      else if(runera=="2018D") METycorr = -(0.0684071*npv +-0.928372);
      else if(runera=="2018MC") METxcorr = -(0.183518*npv +0.546754);
      else if(runera=="2018MC") METycorr = -(0.192263*npv +-0.42121);
    }
    else if(DataYear==2016){
      //UL2016
      if(runera=="2016B") METxcorr = -(-0.0214894*npv +-0.188255);
      else if(runera=="2016B") METycorr = -(0.0876624*npv +0.812885);
      else if(runera=="2016C") METxcorr = -(-0.032209*npv +0.067288);
      else if(runera=="2016C") METycorr = -(0.113917*npv +0.743906);
      else if(runera=="2016D") METxcorr = -(-0.0293663*npv +0.21106);
      else if(runera=="2016D") METycorr = -(0.11331*npv +0.815787);
      else if(runera=="2016E") METxcorr = -(-0.0132046*npv +0.20073);
      else if(runera=="2016E") METycorr = -(0.134809*npv +0.679068);
      else if(runera=="2016F") METxcorr = -(-0.0543566*npv +0.816597);
      else if(runera=="2016F") METycorr = -(0.114225*npv +1.17266);
      else if(runera=="2016Flate") METxcorr = -(0.134616*npv +-0.89965);
      else if(runera=="2016Flate") METycorr = -(0.0397736*npv +1.0385);
      else if(runera=="2016G") METxcorr = -(0.121809*npv +-0.584893);
      else if(runera=="2016G") METycorr = -(0.0558974*npv +0.891234);
      else if(runera=="2016H") METxcorr = -(0.0868828*npv +-0.703489);
      else if(runera=="2016H") METycorr = -(0.0888774*npv +0.902632);
      else if(runera=="2016MCnonAPV") METxcorr = -(-0.153497*npv +-0.231751);
      else if(runera=="2016MCnonAPV") METycorr = -(0.00731978*npv +0.243323);
      else if(runera=="2016MCAPV") METxcorr = -(-0.188743*npv +0.136539);
      else if(runera=="2016MCAPV") METycorr = -(0.0127927*npv +0.117747);
    }
  }
  else{
    if(DataYear==2017){
      if     (runera=="2017B") METxcorr = -(-0.00382117*npv +-0.666228);
      else if(runera=="2017B") METycorr = -(0.0109034*npv +0.172188);
      else if(runera=="2017C") METxcorr = -(-0.00110699*npv +-0.747643);
      else if(runera=="2017C") METycorr = -(-0.0012184*npv +0.303817);
      else if(runera=="2017D") METxcorr = -(-0.00141442*npv +-0.721382);
      else if(runera=="2017D") METycorr = -(-0.0011873*npv +0.21646);
      else if(runera=="2017E") METxcorr = -(0.00593859*npv +-0.851999);
      else if(runera=="2017E") METycorr = -(-0.00754254*npv +0.245956);
      else if(runera=="2017F") METxcorr = -(0.00765682*npv +-0.945001);
      else if(runera=="2017F") METycorr = -(-0.0154974*npv +0.804176);
      else if(runera=="2017MC") METxcorr = -(-0.0102265*npv +-0.446416);
      else if(runera=="2017MC") METycorr = -(0.0198663*npv +0.243182);
    }
    else if(DataYear==2018){
      //UL2018Puppi
      if(runera=="2018A") METxcorr = -(-0.0073377*npv +0.0250294);
      else if(runera=="2018A") METycorr = -(-0.000406059*npv +0.0417346);
      else if(runera=="2018B") METxcorr = -(0.00434261*npv +0.00892927);
      else if(runera=="2018B") METycorr = -(0.00234695*npv +0.20381);
      else if(runera=="2018C") METxcorr = -(0.00198311*npv +0.37026);
      else if(runera=="2018C") METycorr = -(-0.016127*npv +0.402029);
      else if(runera=="2018D") METxcorr = -(0.00220647*npv +0.378141);
      else if(runera=="2018D") METycorr = -(-0.0160244*npv +0.471053);
      else if(runera=="2018MC") METxcorr = -(-0.0214557*npv +0.969428);
      else if(runera=="2018MC") METycorr = -(0.0167134*npv +0.199296);
    }
    else if(DataYear==2016){
      //UL2016Puppi
      if(runera=="2016B") METxcorr = -(-0.00109025*npv +-0.338093);
      else if(runera=="2016B") METycorr = -(-0.00356058*npv +0.128407);
      else if(runera=="2016C") METxcorr = -(-0.00271913*npv +-0.342268);
      else if(runera=="2016C") METycorr = -(0.00187386*npv +0.104);
      else if(runera=="2016D") METxcorr = -(-0.00254194*npv +-0.305264);
      else if(runera=="2016D") METycorr = -(-0.00177408*npv +0.164639);
      else if(runera=="2016E") METxcorr = -(-0.00358835*npv +-0.225435);
      else if(runera=="2016E") METycorr = -(-0.000444268*npv +0.180479);
      else if(runera=="2016F") METxcorr = -(0.0056759*npv +-0.454101);
      else if(runera=="2016F") METycorr = -(-0.00962707*npv +0.35731);
      else if(runera=="2016Flate") METxcorr = -(0.0234421*npv +-0.371298);
      else if(runera=="2016Flate") METycorr = -(-0.00997438*npv +0.0809178);
      else if(runera=="2016G") METxcorr = -(0.0182134*npv +-0.335786);
      else if(runera=="2016G") METycorr = -(-0.0063338*npv +0.093349);
      else if(runera=="2016H") METxcorr = -(0.015702*npv +-0.340832);
      else if(runera=="2016H") METycorr = -(-0.00544957*npv +0.199093);
      else if(runera=="2016MCnonAPV") METxcorr = -(-0.0058341*npv +-0.395049);
      else if(runera=="2016MCnonAPV") METycorr = -(0.00971595*npv +-0.101288);
      else if(runera=="2016MCAPV") METxcorr = -(-0.0060447*npv +-0.4183);
      else if(runera=="2016MCAPV") METycorr = -(0.008331*npv +-0.0990046);
    }
  }


  double CorrectedMET_x = METOrig *cos( METPhiOrig )+METxcorr;
  double CorrectedMET_y = METOrig *sin( METPhiOrig )+METycorr;

  double CorrectedMET = sqrt(CorrectedMET_x*CorrectedMET_x+CorrectedMET_y*CorrectedMET_y);
  double CorrectedMETPhi;
  if     (CorrectedMET_x==0 && CorrectedMET_y>0) CorrectedMETPhi = TMath::Pi();
  else if(CorrectedMET_x==0 && CorrectedMET_y<0) CorrectedMETPhi = -TMath::Pi();
  else if(CorrectedMET_x >0                    ) CorrectedMETPhi = TMath::ATan(CorrectedMET_y/CorrectedMET_x);
  else if(CorrectedMET_x <0 && CorrectedMET_y>0) CorrectedMETPhi = TMath::ATan(CorrectedMET_y/CorrectedMET_x) + TMath::Pi();
  else if(CorrectedMET_x <0 && CorrectedMET_y<0) CorrectedMETPhi = TMath::ATan(CorrectedMET_y/CorrectedMET_x) - TMath::Pi();
  else CorrectedMETPhi =0;

  vMET.SetPtEtaPhiM(CorrectedMET, 0., CorrectedMETPhi, 0.);

  return vMET;

}


void DiLepValid::executeEventFromParameter(AnalyzerParameter param){

  if(!PassMETFilter()) return;

  Event ev = GetEvent();

}

DiLepValid::DiLepValid(){

}

DiLepValid::~DiLepValid(){

  SysWgtStrPairList.clear();
}


