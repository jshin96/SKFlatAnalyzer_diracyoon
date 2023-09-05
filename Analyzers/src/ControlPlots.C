#include "ControlPlots.h"

void ControlPlots::initializeAnalyzer(){

  TriLep=false, TetraLep=false, SS2l=false, OS2l=false;
  SB_SS2L=false, CFlip=false, ConvCR=false, FkCR3l=false;
  TrigClos=false;
  FakeRun=false, ConvRun=false, FlipRun=false, SystRun=false, HEMCheck=false; 
  for(unsigned int i=0; i<Userflags.size(); i++){
    if(Userflags.at(i).Contains("SS2l"))        SS2l        = true;
    if(Userflags.at(i).Contains("TriLep"))      TriLep      = true;
    if(Userflags.at(i).Contains("TetraLep"))    TetraLep    = true; 
    if(Userflags.at(i).Contains("OS2l"))        OS2l        = true;
    if(Userflags.at(i).Contains("SB_SS2L"))     SB_SS2L     = true;
    if(Userflags.at(i).Contains("CFlip"))       CFlip       = true;
    if(Userflags.at(i).Contains("FkCR3l"))      FkCR3l      = true;
    if(Userflags.at(i).Contains("ConvCR"))      ConvCR      = true;
    if(Userflags.at(i).Contains("TrigClos"))    TrigClos    = true;
    if(Userflags.at(i).Contains("FakeRun"))     FakeRun     = true; 
    if(Userflags.at(i).Contains("ConvRun"))     ConvRun     = true; 
    if(Userflags.at(i).Contains("FlipRun"))     FlipRun     = true; 
    if(Userflags.at(i).Contains("SystRun"))     SystRun     = true; 
    if(Userflags.at(i).Contains("HEMCheck"))    HEMCheck    = true; 
  }
  if(FlipRun && !FakeRun) OS2l=true;

  DblMu=false, DblEG=false, MuEG=false, SglEl=false;
  if     (DataStream.Contains("DoubleMuon")) DblMu=true;
  else if(DataStream.Contains("MuonEG"))     MuEG =true;
  else if(DataStream.Contains("DoubleEG"))   DblEG=true;
  else if(DataStream.Contains("SingleElectron")) SglEl=true;
  else if(DataYear==2018 and DataStream.Contains("EGamma")) DblEG=true;

  if(GetEraShort()=="2016a"){
    TrigList_DblMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v", "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v"};
    TrigList_DblEG = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"};
    TrigList_SglEl = {"HLT_Ele27_WPTight_Gsf_v"};
    TrigList_MuEG  = {"HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v", "HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v"};
  }
  else if(GetEraShort()=="2016b"){
    TrigList_DblMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v", "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v", "HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v"};
    TrigList_DblEG = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"};
    TrigList_SglEl = {"HLT_Ele27_WPTight_Gsf_v"};
    TrigList_MuEG  = {"HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v", "HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"};
  }
  else if(DataYear==2017){
    TrigList_DblMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v", "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v"};
    TrigList_DblEG = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v"};
    TrigList_SglEl = {"HLT_Ele32_WPTight_Gsf_v", "HLT_Ele32_WPTight_Gsf_L1DoubleEG_v"};
    TrigList_MuEG = {"HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v", "HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v"};
  }
  else if(DataYear==2018){
    TrigList_DblMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v"};
    TrigList_DblEG = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v"};
    TrigList_SglEl = {"HLT_Ele32_WPTight_Gsf_v"};
    TrigList_MuEG = {"HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v", "HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v"};
  }


  //Set up the tagger map only for the param settings to be used.
  vector<JetTagging::Parameters> jtps;
  jtps.push_back( JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets) );
  mcCorr->SetJetTaggingParameters(jtps);

  TString AnalyzerPath=getenv("SKFlat_WD"), SKFlatV=getenv("SKFlatV");
  TString FileDir_FkEl = AnalyzerPath+"/data/"+SKFlatV+"/"+GetEra()+"/FakeRate/DataFR/ElFR/";
  TString FileDir_FkMu = AnalyzerPath+"/data/"+SKFlatV+"/"+GetEra()+"/FakeRate/DataFR/MuFR/";
  TString FileDir_CF = AnalyzerPath+"/data/"+SKFlatV+"/"+GetEra()+"/CFRate/";
  FRFile_El  = new TFile(FileDir_FkEl+"FR_"+GetEraShort()+".root");
  FRFile_Mu  = new TFile(FileDir_FkMu+"FR_"+GetEraShort()+".root");
  CFRFile = new TFile(FileDir_CF+"CFRateVar.root");

  InitializeTreeVars();
  InitializeReader();
  outfile->cd();

}


void ControlPlots::executeEvent(){


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
  if(TetraLep or TriLep){
    if(!IsDATA){
      PassTrig = ev.PassTrigger(TrigList_DblMu) or ev.PassTrigger(TrigList_DblEG);
    }
    else{
      if     (DblMu) PassTrig = ev.PassTrigger(TrigList_DblMu);
      else if(DblEG) PassTrig = ev.PassTrigger(TrigList_DblEG);
      else if(MuEG)  PassTrig = ev.PassTrigger(TrigList_MuEG);
    }
  }
  else if(SS2l or OS2l){
    if(!IsDATA) PassTrig = ev.PassTrigger(TrigList_DblMu) or ev.PassTrigger(TrigList_DblEG);
    else{
      if     (DblMu) PassTrig = ev.PassTrigger(TrigList_DblMu);
      else if(DblEG) PassTrig = ev.PassTrigger(TrigList_DblEG);
    }
  }
  if(TrigClos) PassTrig=true;
  if(!PassTrig) return;
  FillHist("CutFlow", 1., weight, 20, 0., 20.);
  if(!PassMETFilter()) return;
  FillHist("CutFlow", 2., weight, 20, 0., 20.);

  bool PreCutPass=false;
  TString PreCutIDMu = (SB_SS2L or CFlip or ConvCR or FkCR3l)? "TopHNL":"NOCUT";
  TString PreCutIDEl = (SB_SS2L or CFlip or ConvCR or FkCR3l)? "TopHN_Isop4NoSIPMVA":"NOCUT";
  vector<Muon>     muonPreColl     = GetMuons(PreCutIDMu, 5., 2.4);
  vector<Electron> electronPreColl = GetElectrons(PreCutIDEl, 5., 2.5);
  sort(muonPreColl.begin(), muonPreColl.end(), PtComparing);
  sort(electronPreColl.begin(), electronPreColl.end(), PtComparing);
  if(TriLep and (muonPreColl.size()+electronPreColl.size())>2 ) PreCutPass=true;
  if(TetraLep and (muonPreColl.size()+electronPreColl.size())>3 ) PreCutPass=true;
  if(SS2l){
    int NPreMu=muonPreColl.size(), NPreEl=electronPreColl.size();
    if( (NPreMu+NPreEl)>2 ) PreCutPass=true;
    else if(NPreMu==2 and SumCharge(muonPreColl)!=0) PreCutPass=true;
    else if(NPreEl==2 and SumCharge(electronPreColl)!=0) PreCutPass=true;
  }
  if((OS2l or TrigClos) && (muonPreColl.size()+electronPreColl.size())>1) PreCutPass=true;
  if(electronPreColl.size()>0) PreCutPass=true;
  if(!PreCutPass) return;


  TString IDSSLabel = "SS";
  TString MuTID = "TopHNT", MuLID = "TopHNL", MuVID=MuLID;
  TString ElTID = "TopHNSST", ElLID = "TopHNSSL_"+GetEraShort(), ElVID = "TopHNL_"+GetEraShort();  
  vector<Muon>     muonTightColl     = SelectMuons    (muonPreColl    , FakeRun? MuLID:MuTID, 10., 2.4);
  vector<Electron> electronTightColl = SelectElectrons(electronPreColl, FakeRun? ElLID:ElTID, 15., 2.5);
  vector<Muon>     muonLooseColl     = SelectMuons    (muonPreColl    , MuLID, 10., 2.4);
  vector<Electron> electronLooseColl = SelectElectrons(electronPreColl, ElLID, 15., 2.5);
  vector<Muon>     muonVetoColl      = SelectMuons    (muonPreColl    , MuVID, 10., 2.4);
  vector<Electron> electronVetoColl  = SelectElectrons(electronPreColl, ElVID, 10., 2.5);


  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
  vector<Jet> jetPreColl = GetAllJets();
  sort(jetPreColl.begin(), jetPreColl.end(), PtComparing);
  vector<Jet> jetColl  = SelectJets(jetPreColl, muonLooseColl, electronVetoColl, "tightLepVeto", 25., 2.4, "LVeto");
  vector<Jet> bjetColl = SelBJets(jetColl, param_jets);

  Particle vMET_T1xy = GetvMET("PUPPIMETT1xyCorr");


  bool FillGenColl=!IsDATA && (ConvRun or FakeRun or FlipRun);
  if(FillGenColl) truthColl=GetGens(); 


  bool EventCand = false;
  if(SS2l or OS2l){ EventCand = (muonLooseColl.size()+electronLooseColl.size())==2; }
  if(TriLep){ EventCand = (muonLooseColl.size()+electronLooseColl.size())==3; }
  if(TetraLep){ EventCand = (muonLooseColl.size()+electronLooseColl.size())>3; }

  float w_TopPtRW = 1., w_Pref = 1., sf_Tr = 1., w_FR=1.;
  float sf_MuTk = 1., sf_mID = 1., sf_MuIso = 1., sf_eReco = 1., sf_eID = 1., sf_B = 1.;
  float w_CF = 1., w_CV = 1.;
  if((!IsDATA) and EventCand){
    //if(MCSample.Contains("TT") and MCSample.Contains("powheg")) truthColl = GetGens();
    //w_TopPtRW = mcCorr->GetTopPtReweight(truthColl);
    sf_mID   = GetMuonSF(muonTightColl, MuTID, "ID");
    sf_eReco = GetElectronSF(electronLooseColl, "", "Reco");
    sf_eID   = GetElectronSF(electronTightColl, ElTID, "ID");
    sf_B   = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets);
    int NEl = electronTightColl.size(), NMu = muonTightColl.size();
    TString TrSFKey = "";
    if     ( (OS2l or SS2l) && NMu>1 ) TrSFKey="DiMuIso_HNTopID";
    else if( (OS2l or SS2l) && NEl>1 ) TrSFKey="DiElIso_HNTopIDSS";
    else if( TriLep && NMu>=2   ) TrSFKey="DiMuIso_HNTopID";
    else if( TriLep && NEl>=2   ) TrSFKey="DiElIso_HNTopIDSS";
    bool ApplyTrSF = TrSFKey!="" && (SS2l or OS2l or TriLep) && (!TrigClos);
    sf_Tr   = ApplyTrSF? mcCorr->GetTriggerSF(electronTightColl, muonTightColl, TrSFKey, ""):1.;
    w_Pref = GetPrefireWeight(0);
    if(FlipRun && !FakeRun) w_CF = GetCFRWeight(electronTightColl, "");
  }
  if(FakeRun && EventCand){
    w_FR = GetDataFakeWeight(muonLooseColl, electronLooseColl, MuTID, ElTID, "FR_cent_"+MuTID+"_"+MuLID, "FR_cent_"+ElTID+"_"+ElLID+"_Pt15", "");
  }
  weight *= w_TopPtRW * w_Pref * sf_Tr; 
  weight *= sf_MuTk * sf_mID * sf_MuIso * sf_eReco * sf_eID * sf_B * w_CV * w_CF * w_FR;
  //cout<<" w_PU:"<<w_PU<<" w_Pref:"<<w_Pref<<" sf_Tr:"<<sf_Tr<<endl;
  //cout<<" sfIDMu:"<<sf_mID<<" sfIsoMu:"<<sf_MuIso<<" sfRecEl:"<<sf_eReco<<" sfIDEl:"<<sf_eID<<" sfBTag:"<<sf_B<<endl;

  if(TrigClos){
    CheckTrigMCClos(muonTightColl, muonVetoColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET_T1xy, ev, weight, "");
  }
  if(SS2l){
    if(SB_SS2L){
      MakePlotSS2L(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
                   jetColl, bjetColl, vMET_T1xy, weight, ""); 
    }
    if(CFlip){
      CheckChargeFlip(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
                        jetColl, bjetColl, vMET_T1xy, weight, "");
    }
  }
  if(TriLep){
    if(ConvCR){
      CheckConvCR(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
                  jetColl, bjetColl, vMET_T1xy, ev, weight, "");
    }
    if(FkCR3l){
      CheckFkCR3l(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
                  jetColl, bjetColl, vMET_T1xy, ev, weight, "");
    }
  }
  if(TetraLep){
    CheckCR4l(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
              jetColl, bjetColl, vMET_T1xy, ev, weight, "");
  }
  if( SystRun && ((!IsDATA && !(FakeRun)) or (IsDATA && FakeRun)) ){
    vector<Muon>     MuEnUpTColl, MuEnUpLColl, MuEnDownTColl, MuEnDownLColl;
    vector<Electron> ElSclUpTColl, ElSclUpLColl, ElSclDownTColl, ElSclDownLColl;
    vector<Electron> ElResUpTColl, ElResUpLColl, ElResDownTColl, ElResDownLColl;
    vector<Electron> ElCFPT1UpTColl, ElCFPT1UpLColl, ElCFPT2UpTColl, ElCFPT2UpLColl;
    vector<Electron> ElCFPT1DownTColl, ElCFPT1DownLColl, ElCFPT2DownTColl, ElCFPT2DownLColl;
    vector<Jet>      jetJESUpColl, jetJESDownColl, jetJERUpColl, jetJERDownColl;
    vector<Jet>      bjetJESUpColl, bjetJESDownColl, bjetJERUpColl, bjetJERDownColl;
    Particle         vMET_T1xy_JESUp, vMET_T1xy_JESDown, vMET_T1xy_JERUp, vMET_T1xy_JERDown, vMET_T1xy_UnclUp, vMET_T1xy_UnclDown;
    if(!IsDATA){
      MuEnUpTColl    = SelectMuons(muonPreColl, FakeRun? MuLID:MuTID, 10., 2.4, "SystEnUp");
      MuEnUpLColl    = SelectMuons(muonPreColl, MuLID, 10., 2.4, "SystEnUp");
      MuEnDownTColl  = SelectMuons(muonPreColl, FakeRun? MuLID:MuTID, 10., 2.4, "SystEnDown");
      MuEnDownLColl  = SelectMuons(muonPreColl, MuLID, 10., 2.4, "SystEnDown");
      ElSclUpTColl   = SelectElectrons(electronPreColl, FakeRun? ElLID:ElTID, 15., 2.5, "SystSclUp");
      ElSclUpLColl   = SelectElectrons(electronPreColl, ElLID, 15., 2.5, "SystSclUp");
      ElSclDownTColl = SelectElectrons(electronPreColl, FakeRun? ElLID:ElTID, 15., 2.5, "SystSclDown");
      ElSclDownLColl = SelectElectrons(electronPreColl, ElLID, 15., 2.5, "SystSclDown");
      ElResUpTColl   = SelectElectrons(electronPreColl, FakeRun? ElLID:ElTID, 15., 2.5, "SystResUp");
      ElResUpLColl   = SelectElectrons(electronPreColl, ElLID, 15., 2.5, "SystResUp");
      ElResDownTColl = SelectElectrons(electronPreColl, FakeRun? ElLID:ElTID, 15., 2.5, "SystResDown");
      ElResDownLColl = SelectElectrons(electronPreColl, ElLID, 15., 2.5, "SystResDown");
      if(FlipRun){
        ElCFPT1UpTColl   = SelectElectrons(electronPreColl, FakeRun? ElLID:ElTID, 15., 2.5, "SystCFPT1Up");
        ElCFPT1UpLColl   = SelectElectrons(electronPreColl, ElLID, 15., 2.5, "SystCFPT1Up");
        ElCFPT2UpTColl   = SelectElectrons(electronPreColl, FakeRun? ElLID:ElTID, 15., 2.5, "SystCFPT2Up");
        ElCFPT2UpLColl   = SelectElectrons(electronPreColl, ElLID, 15., 2.5, "SystCFPT2Up");
        ElCFPT1DownTColl = SelectElectrons(electronPreColl, FakeRun? ElLID:ElTID, 15., 2.5, "SystCFPT1Down");
        ElCFPT1DownLColl = SelectElectrons(electronPreColl, ElLID, 15., 2.5, "SystCFPT1Down");
        ElCFPT2DownTColl = SelectElectrons(electronPreColl, FakeRun? ElLID:ElTID, 15., 2.5, "SystCFPT2Down");
        ElCFPT2DownLColl = SelectElectrons(electronPreColl, ElLID, 15., 2.5, "SystCFPT2Down");
      }
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
    float w_FRUp=1., w_FRDown=1.;
    float w_CFUp=1., w_CFDown=1., w_FrCF1=0., w_FrCF2=0., w_CF_ElSclUp=1., w_CF_ElSclDown=1., w_CF_ElResUp=1., w_CF_ElResDown=1.;
    float sf_mIDUp=1., sf_mIDDown=1., sf_mID_MuEnUp=1., sf_mID_MuEnDown=1.;
    float sf_eIDUp=1., sf_eIDDown=1., sf_eID_ElSclUp=1., sf_eID_ElSclDown=1., sf_eID_ElResUp=1., sf_eID_ElResDown=1.;
    float sf_eRecoUp=1., sf_eRecoDown=1., sf_eReco_ElSclUp=1., sf_eReco_ElSclDown=1., sf_eReco_ElResUp=1., sf_eReco_ElResDown=1.;
    float sf_B_JESUp=1., sf_B_JESDown=1., sf_B_JERUp=1., sf_B_JERDown=1.;
    float sf_B_LTagUp=1., sf_B_LTagDown=1., sf_B_HTagUp=1., sf_B_HTagDown=1.;
    float sf_Tr_ElSclUp=1., sf_Tr_ElSclDown=1., sf_Tr_ElResUp=1., sf_Tr_ElResDown=1., sf_Tr_MuEnUp=1., sf_Tr_MuEnDown=1.;
    float sf_TrUp = sf_Tr*1.01, sf_TrDown = sf_Tr*0.99;
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

      sf_Tr_MuEnUp    = MuEnUpTColl.size()>1?    mcCorr->GetTriggerSF(electronTightColl, MuEnUpTColl, "DiMuIso_HNTopID", ""):1.;
      sf_Tr_MuEnDown  = MuEnDownTColl.size()>1?  mcCorr->GetTriggerSF(electronTightColl, MuEnDownTColl, "DiMuIso_HNTopID", ""):1.;
      sf_Tr_ElSclUp   = ElSclUpTColl.size()>1?   mcCorr->GetTriggerSF(ElSclUpTColl, muonTightColl, "DiElIso_HNTopIDSS", ""):1.;
      sf_Tr_ElSclDown = ElSclDownTColl.size()>1? mcCorr->GetTriggerSF(ElSclDownTColl, muonTightColl, "DiElIso_HNTopIDSS", ""):1.;
      sf_Tr_ElResUp   = ElResUpTColl.size()>1?   mcCorr->GetTriggerSF(ElResUpTColl, muonTightColl, "DiElIso_HNTopIDSS", ""):1.;
      sf_Tr_ElResDown = ElResDownTColl.size()>1? mcCorr->GetTriggerSF(ElResDownTColl, muonTightColl, "DiElIso_HNTopIDSS", ""):1.;

      if(FlipRun && !FakeRun){
        w_CF_ElSclUp   = GetCFRWeight(ElSclUpTColl, "");
        w_CF_ElSclDown = GetCFRWeight(ElSclDownTColl, "");
        w_CF_ElResUp   = GetCFRWeight(ElResUpTColl, "");
        w_CF_ElResDown = GetCFRWeight(ElResDownTColl, "");
        w_CFUp   = GetCFRWeight(electronTightColl, "SystUp");
        w_CFDown = GetCFRWeight(electronTightColl, "SystDown");
        for(unsigned int ie=0; ie<electronTightColl.size(); ie++){
          float PT = electronTightColl.at(ie).Pt(), fEta = fabs(electronTightColl.at(ie).Eta());
          float w_FrCF = GetCFRAndSF(PT, fEta, "hCFR_MCFine_PTfEta", "")*GetCFRAndSF(PT, fEta, "hCFR_sf_Var", "");
          w_FrCF = w_CF>0? w_FrCF/w_CF:1.; 
          if     (ie==0) w_FrCF1 = w_FrCF;
          else if(ie==1) w_FrCF2 = w_FrCF;
        }
      }
    }
    if(FakeRun && EventCand){
      w_FRUp   = GetDataFakeWeight(muonLooseColl, electronLooseColl, MuTID, ElTID, "FR_cent_"+MuTID+"_"+MuLID, "FR_cent_"+ElTID+"_"+ElLID+"_Pt15", "SystUpTot"  );
      w_FRDown = GetDataFakeWeight(muonLooseColl, electronLooseColl, MuTID, ElTID, "FR_cent_"+MuTID+"_"+MuLID, "FR_cent_"+ElTID+"_"+ElLID+"_Pt15", "SystDownTot");
    }

    float w_base = w_GenNorm * w_BR * w_TopPtRW * sf_MuTk * w_CV;
    float weight_PUUp      = w_base* w_PUUp  * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_PUDown    = w_base* w_PUDown* w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_PrefUp    = w_base* w_PU    * w_PrefUp  * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_PrefDown  = w_base* w_PU    * w_PrefDown* w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_MuEnUp    = w_base* w_PU    * w_Pref    * w_FR    * w_CF    * sf_mID_MuEnUp  * sf_eReco          * sf_eID          * sf_Tr_MuEnUp   * sf_B;
    float weight_MuEnDown  = w_base* w_PU    * w_Pref    * w_FR    * w_CF    * sf_mID_MuEnDown* sf_eReco          * sf_eID          * sf_Tr_MuEnDown * sf_B;
    float weight_MuIDUp    = w_base* w_PU    * w_Pref    * w_FR    * w_CF    * sf_mIDUp       * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_MuIDDown  = w_base* w_PU    * w_Pref    * w_FR    * w_CF    * sf_mIDDown     * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_ElRecoUp  = w_base* w_PU    * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eRecoUp        * sf_eID          * sf_Tr          * sf_B;
    float weight_ElRecoDown= w_base* w_PU    * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eRecoDown      * sf_eID          * sf_Tr          * sf_B;
    float weight_ElIDUp    = w_base* w_PU    * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eIDUp        * sf_Tr          * sf_B;
    float weight_ElIDDown  = w_base* w_PU    * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eIDDown      * sf_Tr          * sf_B;
    float weight_ElSclUp   = w_base* w_PU    * w_Pref    * w_FR    * w_CF_ElSclUp  * sf_mID   * sf_eReco_ElSclUp  * sf_eID_ElSclUp  * sf_Tr_ElSclUp  * sf_B;
    float weight_ElSclDown = w_base* w_PU    * w_Pref    * w_FR    * w_CF_ElSclDown* sf_mID   * sf_eReco_ElSclDown* sf_eID_ElSclDown* sf_Tr_ElSclDown* sf_B;
    float weight_ElResUp   = w_base* w_PU    * w_Pref    * w_FR    * w_CF_ElResUp  * sf_mID   * sf_eReco_ElResUp  * sf_eID_ElResUp  * sf_Tr_ElResUp  * sf_B;
    float weight_ElResDown = w_base* w_PU    * w_Pref    * w_FR    * w_CF_ElResDown* sf_mID   * sf_eReco_ElResDown* sf_eID_ElResDown* sf_Tr_ElResDown* sf_B;
    float weight_JESUp     = w_base* w_PU    * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_JESUp;
    float weight_JESDown   = w_base* w_PU    * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_JESDown;
    float weight_JERUp     = w_base* w_PU    * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_JERUp;
    float weight_JERDown   = w_base* w_PU    * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_JERDown;
    float weight_LTagUp    = w_base* w_PU    * w_Pref    * w_CF    * w_FR    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_LTagUp;
    float weight_LTagDown  = w_base* w_PU    * w_Pref    * w_CF    * w_FR    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_LTagDown;
    float weight_HTagUp    = w_base* w_PU    * w_Pref    * w_CF    * w_FR    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_HTagUp;
    float weight_HTagDown  = w_base* w_PU    * w_Pref    * w_CF    * w_FR    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_HTagDown;
    float weight_CFUp      = w_base* w_PU    * w_Pref    * w_FR    * w_CFUp  * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_CFDown    = w_base* w_PU    * w_Pref    * w_FR    * w_CFDown* sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_FRUp      = w_base* w_PU    * w_Pref    * w_FRUp  * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_FRDown    = w_base* w_PU    * w_Pref    * w_FRDown* w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_TrUp      = w_base* w_PU    * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_TrUp        * sf_B;
    float weight_TrDown    = w_base* w_PU    * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_TrDown      * sf_B;


    if(!IsDATA && !FakeRun){
      SysWgtStrPairList.clear();//safe-guard, in-case there was usage before this and uncleared
      SysWgtStrPairList.push_back( make_pair(weight_PUUp      , "_SystUp_PU"      ) );
      SysWgtStrPairList.push_back( make_pair(weight_PUDown    , "_SystDown_PU"    ) );
      SysWgtStrPairList.push_back( make_pair(weight_PrefUp    , "_SystUp_Pref"    ) );
      SysWgtStrPairList.push_back( make_pair(weight_PrefDown  , "_SystDown_Pref"  ) );
      SysWgtStrPairList.push_back( make_pair(weight_ElRecoUp  , "_SystUp_ElReco"  ) );
      SysWgtStrPairList.push_back( make_pair(weight_ElRecoDown, "_SystDown_ElReco") );
      SysWgtStrPairList.push_back( make_pair(weight_ElIDUp    , "_SystUp_ElID"    ) );
      SysWgtStrPairList.push_back( make_pair(weight_ElIDDown  , "_SystDown_ElID"  ) );
      SysWgtStrPairList.push_back( make_pair(weight_MuIDUp    , "_SystUp_MuID"    ) );
      SysWgtStrPairList.push_back( make_pair(weight_MuIDDown  , "_SystDown_MuID"  ) );
      SysWgtStrPairList.push_back( make_pair(weight_TrUp      , "_SystUp_Tr"      ) );
      SysWgtStrPairList.push_back( make_pair(weight_TrDown    , "_SystDown_Tr"    ) );
      SysWgtStrPairList.push_back( make_pair(weight_LTagUp    , "_SystUp_LTag"    ) );
      SysWgtStrPairList.push_back( make_pair(weight_LTagDown  , "_SystDown_LTag"  ) );
      SysWgtStrPairList.push_back( make_pair(weight_HTagUp    , "_SystUp_HTag"    ) );
      SysWgtStrPairList.push_back( make_pair(weight_HTagDown  , "_SystDown_HTag"  ) );
      if(FlipRun && !FakeRun){
        SysWgtStrPairList.push_back( make_pair(weight_CFUp  , "_SystUp_CF"  ) );
        SysWgtStrPairList.push_back( make_pair(weight_CFDown, "_SystDown_CF") );
      }
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
      if(FlipRun && !FakeRun){
        DoSystRun(muonTightColl, muonLooseColl, muonLooseColl, ElCFPT1UpTColl, ElCFPT1UpLColl, electronVetoColl,
                  jetColl, bjetColl, vMET_T1xy, ev, weight*w_FrCF1, "_SystUp_CFPT");
        DoSystRun(muonTightColl, muonLooseColl, muonLooseColl, ElCFPT1DownTColl, ElCFPT1DownLColl, electronVetoColl,
                  jetColl, bjetColl, vMET_T1xy, ev, weight*w_FrCF1, "_SystDown_CFPT");
        DoSystRun(muonTightColl, muonLooseColl, muonLooseColl, ElCFPT2UpTColl, ElCFPT2UpLColl, electronVetoColl,
                  jetColl, bjetColl, vMET_T1xy, ev, weight*w_FrCF2, "_SystUp_CFPT");
        DoSystRun(muonTightColl, muonLooseColl, muonLooseColl, ElCFPT2DownTColl, ElCFPT2DownLColl, electronVetoColl,
                  jetColl, bjetColl, vMET_T1xy, ev, weight*w_FrCF2, "_SystDown_CFPT");
      }
    }
    else if(FakeRun){
      SysWgtStrPairList.push_back( make_pair(weight_FRUp  , "_SystUp_FR"  ) );
      SysWgtStrPairList.push_back( make_pair(weight_FRDown, "_SystDown_FR") );
    }
    if(SysWgtStrPairList.size()>0){
      DoSystRun(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                jetColl, bjetColl, vMET_T1xy, ev, weight, "SystWgtVar");
      SysWgtStrPairList.clear();
    }
  }//End of SystRun
}



void ControlPlots::DoSystRun(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                             vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                             vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& Ev, float weight, TString Label)
{

  if(SB_SS2L){
    MakePlotSS2L(MuTColl, MuLColl, MuLColl, ElTColl, ElLColl, ElVColl, JetColl, BJetColl, vMET, weight, Label);
  }
  else if(CFlip){
    CheckChargeFlip(MuTColl, MuLColl, MuLColl, ElTColl, ElLColl, ElVColl, JetColl, BJetColl, vMET, weight, Label);
  }
  else if(FkCR3l){
    CheckFkCR3l(MuTColl, MuLColl, MuLColl, ElTColl, ElLColl, ElVColl, JetColl, BJetColl, vMET, Ev, weight, Label);
  }
  else if(ConvCR){
    CheckConvCR(MuTColl, MuLColl, MuVColl, ElTColl, ElLColl, ElVColl, JetColl, BJetColl, vMET, Ev, weight, Label);
  }
  else{ cout<<"no corresponding cycle!"<<endl; exit(ENODATA); }

  return;
}



void ControlPlots::CheckTrigMCClos(vector<Muon>& MuTColl, vector<Muon>& MuVColl, vector<Electron>& ElTColl, vector<Electron>& ElVColl,
                                   vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& Ev, float weight, TString Label)
{
  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  bool ApplyCut_dRllp3=false;
  if( !(NMuT==NMuV && NElT==NElV) ) return;
  if(ApplyCut_dRllp3){
    for(unsigned int im1=0; im1<MuTColl.size(); im1++){
    for(unsigned int im2=im1+1; im2<MuTColl.size(); im2++){
      if( MuTColl.at(im1).DeltaR(MuTColl.at(im2)) < 0.3 ) return;
    }}
    for(unsigned int ie1=0; ie1<ElTColl.size(); ie1++){
    for(unsigned int ie2=ie1+1; ie2<ElTColl.size(); ie2++){
      if( ElTColl.at(ie1).DeltaR(ElTColl.at(ie2)) < 0.3 ) return;
    }}
    for(unsigned int ie=0; ie<ElTColl.size(); ie++){
    for(unsigned int im=ie+1; im<MuTColl.size(); im++){
      if( ElTColl.at(ie).DeltaR(MuTColl.at(im)) < 0.3 ) return;
    }}
  }
  if(NMuT==2 && NElT==0){
    bool Acc_2MTr = MuTColl.at(0).Pt()>20 && MuTColl.at(1).Pt()>10 && (MuTColl.at(0)+MuTColl.at(1)).M()>4;
    if(!Acc_2MTr) return;
    bool IsSigMC = MCSample.Contains("HeavyN"); int NQTot = abs(SumCharge(MuTColl));
    if( (IsSigMC && NQTot==0) or (!IsSigMC && NQTot!=0) ) return;
    if( IsSigMC ){ if(!(JetColl.size()>2 && BJetColl.size()>0)) return; }
    float Eff_2MTr_MC = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "DiMuIso_HNTopID", false, "");
    float Eff_2MTr_RD = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "DiMuIso_HNTopID", true, "");
    FillHist("NCnt_2MTr_2M"+Label, 0., weight, 1, 0., 1.);
    FillHist("NTrCnt_MCExp_2MTr_2M"+Label, 0., weight*Eff_2MTr_MC, 1, 0., 1.);
    FillHist("NTrCnt_RDExp_2MTr_2M"+Label, 0., weight*Eff_2MTr_RD, 1, 0., 1.);
    if(Ev.PassTrigger(TrigList_DblMu)) FillHist("NTrCnt_MCObs_2MTr_2M"+Label, 0., weight, 1, 0., 1.);
  }
  if(NElT==2 && NMuT==0){
    bool Acc_2ETr = ElTColl.at(0).Pt()>25 && ElTColl.at(1).Pt()>15;
    if(!Acc_2ETr) return;
    bool IsSigMC = MCSample.Contains("HeavyN"); int NQTot = abs(SumCharge(ElTColl));
    if( (IsSigMC && NQTot==0) or (!IsSigMC && NQTot!=0) ) return;
    if( IsSigMC ){ if(!(JetColl.size()>2 && BJetColl.size()>0 && fabs((ElTColl.at(0)+ElTColl.at(1)).M()-91.2)>10)) return; }
    float Eff_2ETr_MC = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "DiElIso_HNTopIDSS", false, "");
    float Eff_2ETr_RD = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "DiElIso_HNTopIDSS", true, "");
    FillHist("NCnt_2ETr_2E"+Label, 0., weight, 1, 0., 1.);
    FillHist("NTrCnt_MCExp_2ETr_2E"+Label, 0., weight*Eff_2ETr_MC, 1, 0., 1.);
    FillHist("NTrCnt_RDExp_2ETr_2E"+Label, 0., weight*Eff_2ETr_RD, 1, 0., 1.);
    if(Ev.PassTrigger(TrigList_DblEG)) FillHist("NTrCnt_MCObs_2ETr_2E"+Label, 0., weight, 1, 0., 1.);
  }
  if(NElT==1 && NMuT==1){
    if( ElTColl.at(0).Charge()==MuTColl.at(0).Charge() ) return;
    bool Acc_EMTr = (ElTColl.at(0).Pt()>25 or MuTColl.at(0).Pt()>25) && (ElTColl.at(0).Pt()>15 && MuTColl.at(0).Pt()>10);
    if(!Acc_EMTr) return;
    float Eff_EMTr_MC = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "EMuIso_HNTopIDSS", false, "");
    float Eff_EMTr_RD = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "EMuIso_HNTopIDSS", true, "");
    FillHist("NCnt_EMTr_1E1M"+Label, 0., weight, 1, 0., 1.);
    FillHist("NTrCnt_MCExp_EMTr_1E1M"+Label, 0., weight*Eff_EMTr_MC, 1, 0., 1.);
    FillHist("NTrCnt_RDExp_EMTr_1E1M"+Label, 0., weight*Eff_EMTr_RD, 1, 0., 1.);
    if(Ev.PassTrigger(TrigList_MuEG)) FillHist("NTrCnt_MCObs_EMTr_1E1M"+Label, 0., weight, 1, 0., 1.);
  }
  if(NElT==1 && NMuT==2){
    if( abs(SumCharge(MuTColl))!=0 ) return;
    bool Acc_2MTr = MuTColl.at(0).Pt()>20 && MuTColl.at(1).Pt()>10 && (MuTColl.at(0)+MuTColl.at(1)).M()>4;
    bool Acc_EMTr = (ElTColl.at(0).Pt()>25 or MuTColl.at(0).Pt()>25) && (ElTColl.at(0).Pt()>15 && MuTColl.at(1).Pt()>10);
    bool Acc_SoupTr = Acc_2MTr or Acc_EMTr;
    if(!Acc_SoupTr) return;
    if(Acc_EMTr){
      float Eff_EMTr_MC = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "EMuIso_HNTopIDSS", false, "");
      float Eff_EMTr_RD = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "EMuIso_HNTopIDSS", true, "");
      FillHist("NCnt_EMTr_1E2M"+Label, 0., weight, 1, 0., 1.);
      FillHist("NTrCnt_MCExp_EMTr_1E2M"+Label, 0., weight*Eff_EMTr_MC, 1, 0., 1.);
      FillHist("NTrCnt_RDExp_EMTr_1E2M"+Label, 0., weight*Eff_EMTr_RD, 1, 0., 1.);
      if(Ev.PassTrigger(TrigList_MuEG)) FillHist("NTrCnt_MCObs_EMTr_1E2M"+Label, 0., weight, 1, 0., 1.);
    } 
    if(Acc_2MTr){
      float Eff_2MTr_MC = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "DiMuIso_HNTopID", false, "");
      float Eff_2MTr_RD = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "DiMuIso_HNTopID", true, "");
      FillHist("NCnt_2MTr_1E2M"+Label, 0., weight, 1, 0., 1.);
      FillHist("NTrCnt_MCExp_2MTr_1E2M"+Label, 0., weight*Eff_2MTr_MC, 1, 0., 1.);
      FillHist("NTrCnt_RDExp_2MTr_1E2M"+Label, 0., weight*Eff_2MTr_RD, 1, 0., 1.);
      if(Ev.PassTrigger(TrigList_DblMu)) FillHist("NTrCnt_MCObs_2MTr_1E2M"+Label, 0., weight, 1, 0., 1.);
    }
    if(Acc_SoupTr){
      float Eff_SoupTr_MC = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "TrigSoup2L_HNTopIDSS", false, "");
      float Eff_SoupTr_RD = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "TrigSoup2L_HNTopIDSS", true, "");
      FillHist("NCnt_SoupTr_1E2M"+Label, 0., weight, 1, 0., 1.);
      FillHist("NTrCnt_MCExp_SoupTr_1E2M"+Label, 0., weight*Eff_SoupTr_MC, 1, 0., 1.);
      FillHist("NTrCnt_RDExp_SoupTr_1E2M"+Label, 0., weight*Eff_SoupTr_RD, 1, 0., 1.);
      if(Ev.PassTrigger(TrigList_DblMu) or Ev.PassTrigger(TrigList_MuEG)){
        FillHist("NTrCnt_MCObs_SoupTr_1E2M"+Label, 0., weight, 1, 0., 1.);
      }
    }
  }
  if(NElT==2 && NMuT==1){
    if( abs(SumCharge(ElTColl))!=0 ) return;
    bool Acc_2ETr = ElTColl.at(0).Pt()>25 && ElTColl.at(1).Pt()>15;
    bool Acc_EMTr = (ElTColl.at(0).Pt()>25 or MuTColl.at(0).Pt()>25) && (ElTColl.at(1).Pt()>15 && MuTColl.at(0).Pt()>10);
    bool Acc_SoupTr = Acc_2ETr or Acc_EMTr;
    if(!Acc_SoupTr) return;
    if(Acc_EMTr){
      float Eff_EMTr_MC = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "EMuIso_HNTopIDSS", false, "");
      float Eff_EMTr_RD = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "EMuIso_HNTopIDSS", true, "");
      FillHist("NCnt_EMTr_2E1M"+Label, 0., weight, 1, 0., 1.);
      FillHist("NTrCnt_MCExp_EMTr_2E1M"+Label, 0., weight*Eff_EMTr_MC, 1, 0., 1.);
      FillHist("NTrCnt_RDExp_EMTr_2E1M"+Label, 0., weight*Eff_EMTr_RD, 1, 0., 1.);
      if(Ev.PassTrigger(TrigList_MuEG)) FillHist("NTrCnt_MCObs_EMTr_2E1M"+Label, 0., weight, 1, 0., 1.);
    } 
    if(Acc_2ETr){
      float Eff_2ETr_MC = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "DiElIso_HNTopIDSS", false, "");
      float Eff_2ETr_RD = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "DiElIso_HNTopIDSS", true, "");
      FillHist("NCnt_2ETr_2E1M"+Label, 0., weight, 1, 0., 1.);
      FillHist("NTrCnt_MCExp_2ETr_2E1M"+Label, 0., weight*Eff_2ETr_MC, 1, 0., 1.);
      FillHist("NTrCnt_RDExp_2ETr_2E1M"+Label, 0., weight*Eff_2ETr_RD, 1, 0., 1.);
      if(Ev.PassTrigger(TrigList_DblEG)) FillHist("NTrCnt_MCObs_2ETr_2E1M"+Label, 0., weight, 1, 0., 1.);
    }
    if(Acc_SoupTr){
      float Eff_SoupTr_MC = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "TrigSoup2L_HNTopIDSS", false, "");
      float Eff_SoupTr_RD = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "TrigSoup2L_HNTopIDSS", true, "");
      FillHist("NCnt_SoupTr_2E1M"+Label, 0., weight, 1, 0., 1.);
      FillHist("NTrCnt_MCExp_SoupTr_2E1M"+Label, 0., weight*Eff_SoupTr_MC, 1, 0., 1.);
      FillHist("NTrCnt_RDExp_SoupTr_2E1M"+Label, 0., weight*Eff_SoupTr_RD, 1, 0., 1.);
      if(Ev.PassTrigger(TrigList_DblEG) or Ev.PassTrigger(TrigList_MuEG)){
        FillHist("NTrCnt_MCObs_SoupTr_2E1M"+Label, 0., weight, 1, 0., 1.);
      }
    }
  }
  if(NElT==3){
    if( !(ElTColl.at(0).Pt()>25 && ElTColl.at(2).Pt()>15) ) return;
    if( abs(SumCharge(ElTColl))!=1 ) return;
    float Eff_Tr_MC = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "DiElIso_HNTopIDSS", false, "");
    float Eff_Tr_RD = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "DiElIso_HNTopIDSS", true, "");
    FillHist("NCnt_2ETr_3E"+Label, 0., weight, 1, 0., 1.);
    FillHist("NTrCnt_MCExp_2ETr_3E"+Label, 0., weight*Eff_Tr_MC, 1, 0., 1.);
    FillHist("NTrCnt_RDExp_2ETr_3E"+Label, 0., weight*Eff_Tr_RD, 1, 0., 1.);
    if(Ev.PassTrigger(TrigList_DblEG)) FillHist("NTrCnt_MCObs_2ETr_3E"+Label, 0., weight, 1, 0., 1.);
  }
  if(NMuT==3){
    if( !(MuTColl.at(0).Pt()>20 && MuTColl.at(2).Pt()>10) ) return;
    if( abs(SumCharge(MuTColl))!=1 ) return;
    float Mll12 = (MuTColl.at(0)+MuTColl.at(1)).M();
    float Mll13 = (MuTColl.at(0)+MuTColl.at(2)).M();
    float Mll23 = (MuTColl.at(1)+MuTColl.at(2)).M();
    if( Mll12<4 or Mll13<4 or Mll23<4 ) return;
    float Eff_Tr_MC = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "DiMuIso_HNTopID", false, "");
    float Eff_Tr_RD = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "DiMuIso_HNTopID", true, "");
    FillHist("NCnt_2MTr_3M"+Label, 0., weight, 1, 0., 1.);
    FillHist("NTrCnt_MCExp_2MTr_3M"+Label, 0., weight*Eff_Tr_MC, 1, 0., 1.);
    FillHist("NTrCnt_RDExp_2MTr_3M"+Label, 0., weight*Eff_Tr_RD, 1, 0., 1.);
    if(Ev.PassTrigger(TrigList_DblMu)) FillHist("NTrCnt_MCObs_2MTr_3M"+Label, 0., weight, 1, 0., 1.);
  }

}


void ControlPlots::CheckChargeFlip(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                                   vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                                   vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{
  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  float MCCFSF = 1.;
  bool ApplyWVar = Label.Contains("SystWgtVar");
  if( ApplyWVar ) Label.ReplaceAll("SystWgtVar","");
  if( FakeRun      and weight==0.  ) return; 
  if( !( (NElT==2  and NMuT==0)  ) ) return;
  if( !(NMuT==NMuL and NElT==NElL) ) return;
  if( !(NMuT==NMuV and NElT==NElV) ) return;
  if(NElT==2){
    Label="_2E"+Label;
    int aSumQ = abs(SumCharge(ElTColl));
    if(FlipRun && !FakeRun){ if(aSumQ!=0) return; }
    else                   { if(aSumQ==0) return; }
    if(!(ElTColl.at(0).Pt()>25 && ElTColl.at(1).Pt()>15)) return;
    if(!IsDATA){
      int GenLepInfo = GetGenLepInfo(ElTColl, MuTColl);
      if(ConvRun && GenLepInfo>=100) return;
      if(FlipRun && aSumQ!=0 && (GenLepInfo>999 or GenLepInfo<100)) return;
      if(FlipRun && FakeRun){
        int IdxFlipped = GenLepInfo % 10;
        MCCFSF = GetCFRAndSF( ElTColl.at(IdxFlipped).Pt(), fabs(ElTColl.at(IdxFlipped).Eta()), "hCFR_sf_Var", "");
      }
    }
  }
  float newweight = weight*MCCFSF;

  vector<Electron> ElConeColl; vector<Muon> MuConeColl;
  if(FakeRun){
    for(unsigned int ie=0; ie<ElTColl.size(); ie++){ 
      Electron TmpEl(ElTColl.at(ie));
      float RelIso = ElTColl.at(ie).MiniRelIso();
      float PTCorr = ElTColl.at(ie).CalcPtCone(RelIso,0.1), PT=ElTColl.at(ie).Pt();
      if(RelIso>0.1) TmpEl *= PTCorr/PT;
      ElConeColl.push_back(TmpEl);
    }
    for(unsigned int im=0; im<MuTColl.size(); im++){ 
      Muon TmpMu(MuTColl.at(im));
      float RelIso = MuTColl.at(im).MiniRelIso();
      float PTCorr = MuTColl.at(im).CalcPtCone(RelIso,0.1), PT=MuTColl.at(im).Pt();
      if(RelIso>0.1) TmpMu *= PTCorr/PT;
      MuConeColl.push_back(TmpMu);
    }
  }
  else{ ElConeColl = ElTColl; MuConeColl = MuTColl; }


  int Nj=JetColl.size(), Nb=BJetColl.size();
  float Mll=-1., PTl1=-1, Etal1=999., PTl2=-1., Etal2=-1., MTW=-1., MET=-1.;
  bool IsOnZ=false, IsBJOrtho=false;
  Mll   = (ElConeColl.at(0)+ElConeColl.at(1)).M();
  PTl1  = ElConeColl.at(0).Pt();  Etal1 = ElConeColl.at(0).Eta();
  PTl2  = ElConeColl.at(1).Pt();  Etal2 = ElConeColl.at(1).Eta();
  MTW   = MT(ElConeColl.at(0), vMET);
  MET   = vMET.Pt();
  IsOnZ = fabs(Mll-91.2)<15.; IsBJOrtho = Nb==0 && Nj<3;
  TString EtaStr = fabs(Etal1)<1.5 && fabs(Etal2)<1.5? "_BB": fabs(Etal1)>1.5 && fabs(Etal2)>1.5? "_EE":"_EB";
  //TString EtaStr = fabs(Etal1)<1.5? "_E1B":"_E1E";

  vector<TString> EtaTagList = {"", EtaStr};
  vector<TString> SelTagList;
  if(   IsBJOrtho    ) SelTagList.push_back("_0Blt3J"); 
  if(     IsOnZ      ) SelTagList.push_back("_OnZ");

  for(unsigned int it=0; it<SelTagList.size(); it++){
  for(unsigned int iEta=0; iEta<EtaTagList.size(); iEta++){
    TString SelTag(SelTagList.at(it)), EtaTag(EtaTagList.at(iEta));
    FillHist("NCount"+SelTag+EtaTag+Label, 0., newweight, 1, 0., 1., ApplyWVar, SysWgtStrPairList);
    FillHist("Mll"+SelTag+EtaTag+Label, Mll, newweight, 20, 0., 200., ApplyWVar, SysWgtStrPairList);
    FillHist("MllnearZ"+SelTag+EtaTag+Label, Mll, newweight, 30, 60., 120., ApplyWVar, SysWgtStrPairList);
    FillHist("PTl1"+SelTag+EtaTag+Label, PTl1, newweight, 30, 0., 300., ApplyWVar, SysWgtStrPairList);
    FillHist("PTl2"+SelTag+EtaTag+Label, PTl2, newweight, 20, 0., 200., ApplyWVar, SysWgtStrPairList);
    FillHist("Etal1"+SelTag+EtaTag+Label, Etal1, newweight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    FillHist("Etal2"+SelTag+EtaTag+Label, Etal2, newweight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    FillHist("MET"+SelTag+EtaTag+Label, MET, newweight, 20, 0., 200., ApplyWVar, SysWgtStrPairList);
    FillHist("MTW"+SelTag+EtaTag+Label, MTW, newweight, 20, 0., 200., ApplyWVar, SysWgtStrPairList);
  }}

}


void ControlPlots::CheckCR4l(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                             vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                             vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& Ev, float weight, TString Label)
{
  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  int NLepT=NMuT+NElT;
  if( FakeRun      and weight==0.  ) return;
  if( !(NMuT==NMuL and NElT==NElL) ) return;
  if( !(NMuT==NMuV and NElT==NElV) ) return;
  if( NLepT!=4 or NElT==1 or NMuT==1 ) return;
  bool PassTrAcc=false, PassTrAcc_MM=false, PassTrAcc_EE=false, PassTrAcc_EM=false;
  if( NMuT>1 && MuTColl.at(0).Pt()>20 && MuTColl.at(1).Pt()>10 ) PassTrAcc_MM=true;
  if( NElT>1 && ElTColl.at(0).Pt()>25 && ElTColl.at(1).Pt()>15 ) PassTrAcc_EE=true;
  if( NElT>0 && NMuT>0 && ElTColl.at(0).Pt()>25 && MuTColl.at(0).Pt()>10 ) PassTrAcc_EM=true;
  if( NElT>0 && NMuT>0 && ElTColl.at(0).Pt()>15 && MuTColl.at(0).Pt()>25 ) PassTrAcc_EM=true;
  if(PassTrAcc_MM){
    for(unsigned int im1=0; im1<MuTColl.size(); im1++){
    for(unsigned int im2=im1+1; im2<MuTColl.size(); im2++){
      if((MuTColl.at(im1)+MuTColl.at(im2)).M()<4){ PassTrAcc_MM=false; break; }
    }}
  }
  PassTrAcc = PassTrAcc_MM or PassTrAcc_EE or PassTrAcc_EM;
  if(!PassTrAcc) return;
  int Qtot_Mu = SumCharge(MuTColl), Qtot_El = SumCharge(ElTColl), Qtot_Lep = Qtot_Mu+Qtot_El;
  if( abs(Qtot_Lep)!=0 ) return;
  if( NMuT==2 && Qtot_Mu!=0 ) return;
  if( NElT==2 && Qtot_El!=0 ) return;

  vector<Electron> ElConeColl; vector<Muon> MuConeColl;
  if(FakeRun){
    for(unsigned int ie=0; ie<ElTColl.size(); ie++){ 
      Electron TmpEl(ElTColl.at(ie));
      float RelIso = ElTColl.at(ie).MiniRelIso();
      float PTCorr = ElTColl.at(ie).CalcPtCone(RelIso,0.1), PT=ElTColl.at(ie).Pt();
      if(RelIso>0.1) TmpEl *= PTCorr/PT;
      ElConeColl.push_back(TmpEl);
    }
    for(unsigned int im=0; im<MuTColl.size(); im++){ 
      Muon TmpMu(MuTColl.at(im));
      float RelIso = MuTColl.at(im).MiniRelIso();
      float PTCorr = MuTColl.at(im).CalcPtCone(RelIso,0.1), PT=MuTColl.at(im).Pt();
      if(RelIso>0.1) TmpMu *= PTCorr/PT;
      MuConeColl.push_back(TmpMu);
    }
  }
  else{ ElConeColl = ElTColl; MuConeColl = MuTColl; }

  float PTl1=0., PTl2=0., PTl3=0., PTl4=0., Etal1=-999., Etal2=-999., Etal3=-999., Etal4=-999.;
  float M4l=-999.;
  TString FinStStr("");
  if(NMuT==2 && NElT==2){
    if( !( (PassTrAcc_MM && Ev.PassTrigger(TrigList_DblMu))
        or (PassTrAcc_EM && Ev.PassTrigger(TrigList_MuEG)) 
        or (PassTrAcc_EE && Ev.PassTrigger(TrigList_DblEG)) ) ) return;
    FinStStr = "_2E2M";
    PTl1    = MuConeColl.at(0).Pt() , PTl2  = MuConeColl.at(1).Pt();
    Etal1   = MuConeColl.at(0).Eta(), Etal2 = MuConeColl.at(1).Eta();
    PTl3    = ElConeColl.at(0).Pt() , PTl4  = ElConeColl.at(1).Pt();
    Etal3   = ElConeColl.at(0).Eta(), Etal4 = ElConeColl.at(1).Eta();
    M4l     = (MuConeColl.at(0)+MuConeColl.at(1)+ElConeColl.at(0)+ElConeColl.at(1)).M();
  }
  else if(NElT==4){
    if( !(PassTrAcc_EE && Ev.PassTrigger(TrigList_DblEG)) ) return; 
    FinStStr = "_4M";
    PTl1    = ElConeColl.at(0).Pt() , PTl2  = ElConeColl.at(1).Pt();
    Etal1   = ElConeColl.at(0).Eta(), Etal2 = ElConeColl.at(1).Eta();
    PTl3    = ElConeColl.at(2).Pt() , PTl4  = ElConeColl.at(3).Pt();
    Etal3   = ElConeColl.at(2).Eta(), Etal4 = ElConeColl.at(3).Eta();
    M4l     = (ElConeColl.at(0)+ElConeColl.at(1)+ElConeColl.at(2)+ElConeColl.at(3)).M();
  }
  else if(NMuT==4){
    if( !(PassTrAcc_MM && Ev.PassTrigger(TrigList_DblMu)) ) return;
    FinStStr = "_4E";
    PTl1    = MuConeColl.at(0).Pt() , PTl2  = MuConeColl.at(1).Pt();
    Etal1   = MuConeColl.at(0).Eta(), Etal2 = MuConeColl.at(1).Eta();
    PTl3    = MuConeColl.at(2).Pt() , PTl4  = MuConeColl.at(3).Pt();
    Etal3   = MuConeColl.at(2).Eta(), Etal4 = MuConeColl.at(3).Eta();
    M4l     = (MuConeColl.at(0)+MuConeColl.at(1)+MuConeColl.at(2)+MuConeColl.at(3)).M();
  }
  else return;

  bool PassQCDVeto=true;
  for(unsigned int im1=0; im1<MuConeColl.size() && PassQCDVeto; im1++){
    for(unsigned int im2=im1+1; im2<MuConeColl.size() && PassQCDVeto; im2++){
      if(MuConeColl.at(im1).Charge()==MuConeColl.at(im2).Charge()) continue;
      float Mll = (MuConeColl.at(im1)+MuConeColl.at(im2)).M();
      if(Mll<12){ PassQCDVeto=false; }
  }}
  for(unsigned int ie1=0; ie1<ElConeColl.size() && PassQCDVeto; ie1++){
    for(unsigned int ie2=ie1+1; ie2<ElConeColl.size() && PassQCDVeto; ie2++){
      if(ElConeColl.at(ie1).Charge()==ElConeColl.at(ie2).Charge()) continue;
      float Mll = (ElConeColl.at(ie1)+ElConeColl.at(ie2)).M();
      if(Mll<12){ PassQCDVeto=false; }
  }}
  if(!PassQCDVeto) return;

  TString MinPtStr("");
  bool MinPt10 = PTl1>10 && PTl2>10 && PTl3>10 && PTl4>10;

  if(!IsDATA){
    int GenLepInfo = GetGenLepInfo(ElTColl, MuTColl);
    if(ConvRun && GenLepInfo>=1000) return;
  }

  vector<TString> LabelList;
  LabelList.push_back("_4l_MinPt5"+Label);
  LabelList.push_back(FinStStr+"_MinPt5"+Label);
  if(MinPt10){
    LabelList.push_back("_4l_MinPt10"+Label);
    LabelList.push_back(FinStStr+"_MinPt10"+Label);
  }

  for(unsigned il=0; il<LabelList.size(); il++){
    TString FinLabel = LabelList.at(il);
    FillHist("M4l"  +FinLabel, M4l , weight, 250, 0., 500.);
    FillHist("PTl1" +FinLabel, PTl1, weight, 40, 0., 200.);
    FillHist("PTl2" +FinLabel, PTl2, weight, 40, 0., 200.);
    FillHist("PTl3" +FinLabel, PTl3, weight, 40, 0., 200.);
    FillHist("PTl4" +FinLabel, PTl4, weight, 40, 0., 200.);
    FillHist("Etal1"+FinLabel, Etal1, weight, 20, -5., 5.);
    FillHist("Etal2"+FinLabel, Etal2, weight, 20, -5., 5.);
    FillHist("Etal3"+FinLabel, Etal3, weight, 20, -5., 5.);
    FillHist("Etal4"+FinLabel, Etal4, weight, 20, -5., 5.);
  }

}



void ControlPlots::CheckFkCR3l(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                               vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                               vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& Ev, float weight, TString Label)
{
  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  int NLepT=NMuT+NElT;
  bool ApplyWVar = Label.Contains("SystWgtVar");
  if( ApplyWVar ) Label.ReplaceAll("SystWgtVar","");
  if( FakeRun      and weight==0.  ) return;
  if( !(NMuT==NMuL and NElT==NElL) ) return;
  if( !(NMuT==NMuV and NElT==NElV) ) return;
  if( NLepT!=3 ) return;
  bool PassTrAcc=false, PassTrAcc_MM=false, PassTrAcc_EE=false, PassTrAcc_EM=false;
  if( NMuT>1 && MuTColl.at(0).Pt()>20 && MuTColl.at(1).Pt()>10 ) PassTrAcc_MM=true;
  if( NElT>1 && ElTColl.at(0).Pt()>25 && ElTColl.at(1).Pt()>15 ) PassTrAcc_EE=true;
  if( NElT>0 && NMuT>0 && ElTColl.at(0).Pt()>25 && MuTColl.at(0).Pt()>10 ) PassTrAcc_EM=true;
  if( NElT>0 && NMuT>0 && ElTColl.at(0).Pt()>15 && MuTColl.at(0).Pt()>25 ) PassTrAcc_EM=true;
  if(PassTrAcc_MM){
    for(unsigned int im1=0; im1<MuTColl.size(); im1++){
    for(unsigned int im2=im1+1; im2<MuTColl.size(); im2++){
      if((MuTColl.at(im1)+MuTColl.at(im2)).M()<4){ PassTrAcc_MM=false; break; }
    }}
  }
  PassTrAcc = PassTrAcc_MM or PassTrAcc_EE or PassTrAcc_EM;
  if(!PassTrAcc) return;
  int Qtot_Mu = SumCharge(MuTColl), Qtot_El = SumCharge(ElTColl), Qtot_Lep = Qtot_Mu+Qtot_El;
  if( abs(Qtot_Lep)!=1 ) return;
  if( NMuT==2 && Qtot_Mu!=0 ) return;
  if( NElT==2 && Qtot_El!=0 ) return;
  if( BJetColl.size()>0 ) return;

  if(HEMCheck){
    bool IsHEMReg=false;
    for(unsigned int im=0; im<MuTColl.size() && !IsHEMReg; im++){
      if(!IsHEMReg){ IsHEMReg=IsHEMIssueReg(MuTColl.at(im)); } else break; 
    }
    for(unsigned int ie=0; ie<ElTColl.size() && !IsHEMReg; ie++){
      if(!IsHEMReg){ IsHEMReg=IsHEMIssueReg(ElTColl.at(ie)); } else break; 
    }
    if(IsHEMReg) return;
  }

  vector<Electron> ElConeColl; vector<Muon> MuConeColl;
  if(FakeRun){
    for(unsigned int ie=0; ie<ElTColl.size(); ie++){ 
      Electron TmpEl(ElTColl.at(ie));
      float RelIso = ElTColl.at(ie).MiniRelIso();
      float PTCorr = ElTColl.at(ie).CalcPtCone(RelIso,0.1), PT=ElTColl.at(ie).Pt();
      if(RelIso>0.1) TmpEl *= PTCorr/PT;
      ElConeColl.push_back(TmpEl);
    }
    for(unsigned int im=0; im<MuTColl.size(); im++){ 
      Muon TmpMu(MuTColl.at(im));
      float RelIso = MuTColl.at(im).MiniRelIso();
      float PTCorr = MuTColl.at(im).CalcPtCone(RelIso,0.1), PT=MuTColl.at(im).Pt();
      if(RelIso>0.1) TmpMu *= PTCorr/PT;
      MuConeColl.push_back(TmpMu);
    }
  }
  else{ ElConeColl = ElTColl; MuConeColl = MuTColl; }

  float PTl1_Z=0., PTl2_Z=0., PTl_Fk=0., Etal1_Z=0., Etal2_Z=0., Etal_Fk=0.;
  float MOSSF_Z=0., MTW=0., MOSSF1=0., MOSSF2=0., M3l=0.;
  float dRZFk=-1, dEtaZFk=-1;
  bool  IsFkHEMReg=false;
  if(NMuT==2 && NElT==1){
    if( !( PassTrAcc_MM && Ev.PassTrigger(TrigList_DblMu) ) ) return; //TrSF2L
    Label     = "_2M1E"+Label;
    PTl1_Z    = MuConeColl.at(0).Pt() , PTl2_Z  = MuConeColl.at(1).Pt();
    Etal1_Z   = MuConeColl.at(0).Eta(), Etal2_Z = MuConeColl.at(1).Eta();
    PTl_Fk    = ElConeColl.at(0).Pt() , Etal_Fk = ElConeColl.at(0).Eta();
    MOSSF_Z   = (MuConeColl.at(0)+MuConeColl.at(1)).M(), MTW = MT(ElConeColl.at(0), vMET), MOSSF1=MOSSF_Z; 
    M3l       = (MuConeColl.at(0)+MuConeColl.at(1)+ElConeColl.at(0)).M();
    dRZFk     = ElConeColl.at(0).DeltaR(MuConeColl.at(0)+MuConeColl.at(1));
    dEtaZFk   = fabs(ElConeColl.at(0).Eta()-(MuConeColl.at(0)+MuConeColl.at(1)).Eta());
    IsFkHEMReg= IsHEMIssueReg(ElConeColl.at(0));
    if(DataYear==2018) IsFkHEMReg= IsHEMIssueReg(ElConeColl.at(0));
  }
  else if(NMuT==1 && NElT==2){
    if( !( PassTrAcc_EE && Ev.PassTrigger(TrigList_DblEG) ) ) return; //TrSF2L
    Label     = "_1M2E"+Label;
    PTl1_Z    = ElConeColl.at(0).Pt() , PTl2_Z  = ElConeColl.at(1).Pt();
    Etal1_Z   = ElConeColl.at(0).Eta(), Etal2_Z = ElConeColl.at(1).Eta();
    PTl_Fk    = MuConeColl.at(0).Pt() , Etal_Fk = MuConeColl.at(0).Eta();
    MOSSF_Z   = (ElConeColl.at(0)+ElConeColl.at(1)).M(), MTW = MT(MuConeColl.at(0), vMET), MOSSF1=MOSSF_Z;
    M3l       = (ElConeColl.at(0)+ElConeColl.at(1)+MuConeColl.at(0)).M();
    dRZFk     = MuConeColl.at(0).DeltaR(ElConeColl.at(0)+ElConeColl.at(1));
    dEtaZFk   = fabs(MuConeColl.at(0).Eta()-(ElConeColl.at(0)+ElConeColl.at(1)).Eta());
    IsFkHEMReg= IsHEMIssueReg(MuConeColl.at(0));
    if(DataYear==2018) IsFkHEMReg= IsHEMIssueReg(MuConeColl.at(0));
  }
  else if(NMuT==3){
    if( !(PassTrAcc_MM && Ev.PassTrigger(TrigList_DblMu)) ) return;
    Label = "_3M0E"+Label;
    int IdxOS  = TriMuChargeIndex(MuConeColl, "OS");
    int IdxSS1 = TriMuChargeIndex(MuConeColl, "SS1");
    int IdxSS2 = TriMuChargeIndex(MuConeColl, "SS2");
    MOSSF1 = (MuConeColl.at(IdxOS)+MuConeColl.at(IdxSS1)).M();
    MOSSF2 = (MuConeColl.at(IdxOS)+MuConeColl.at(IdxSS2)).M();
    int IdxL1_Z=-1, IdxL2_Z=-1, IdxL_Fk=-1;
    if(fabs(MOSSF1-91.2)<fabs(MOSSF2-91.2)){
      IdxL1_Z = MuConeColl.at(IdxOS).Pt()>MuConeColl.at(IdxSS1).Pt()? IdxOS:IdxSS1;
      IdxL2_Z = MuConeColl.at(IdxOS).Pt()>MuConeColl.at(IdxSS1).Pt()? IdxSS1:IdxOS;
      IdxL_Fk = IdxSS2;
    }
    else{
      IdxL1_Z = MuConeColl.at(IdxOS).Pt()>MuConeColl.at(IdxSS2).Pt()? IdxOS:IdxSS2;
      IdxL2_Z = MuConeColl.at(IdxOS).Pt()>MuConeColl.at(IdxSS2).Pt()? IdxSS2:IdxOS;
      IdxL_Fk = IdxSS1;
    }
    PTl1_Z    = MuConeColl.at(IdxL1_Z).Pt() , PTl2_Z  = MuConeColl.at(IdxL2_Z).Pt();
    Etal1_Z   = MuConeColl.at(IdxL1_Z).Eta(), Etal2_Z = MuConeColl.at(IdxL2_Z).Eta();
    PTl_Fk    = MuConeColl.at(IdxL_Fk).Pt() , Etal_Fk = MuConeColl.at(IdxL_Fk).Eta();
    MOSSF_Z   = (MuConeColl.at(IdxL1_Z)+MuConeColl.at(IdxL2_Z)).M(), MTW = MT(MuConeColl.at(IdxL_Fk), vMET);
    M3l       = (MuConeColl.at(0)+MuConeColl.at(1)+MuConeColl.at(2)).M();
    dRZFk     = MuConeColl.at(IdxL_Fk).DeltaR(MuConeColl.at(IdxL1_Z)+MuConeColl.at(IdxL2_Z));
    dEtaZFk   = fabs(MuConeColl.at(IdxL_Fk).Eta()-(MuConeColl.at(IdxL1_Z)+MuConeColl.at(IdxL2_Z)).Eta());
    IsFkHEMReg= IsHEMIssueReg(MuConeColl.at(IdxL_Fk));
    if(DataYear==2018) IsFkHEMReg= IsHEMIssueReg(MuConeColl.at(IdxL_Fk));
  }
  else if(NElT==3){
    if( !(PassTrAcc_EE && Ev.PassTrigger(TrigList_DblEG)) ) return;
    Label = "_0M3E"+Label;
    int IdxOS  = TriElChargeIndex(ElConeColl, "OS");
    int IdxSS1 = TriElChargeIndex(ElConeColl, "SS1");
    int IdxSS2 = TriElChargeIndex(ElConeColl, "SS2");
    MOSSF1 = (ElConeColl.at(IdxOS)+ElConeColl.at(IdxSS1)).M();
    MOSSF2 = (ElConeColl.at(IdxOS)+ElConeColl.at(IdxSS2)).M();
    int IdxL1_Z=-1, IdxL2_Z=-1, IdxL_Fk=-1;
    if(fabs(MOSSF1-91.2)<fabs(MOSSF2-91.2)){
      IdxL1_Z = ElConeColl.at(IdxOS).Pt()>ElConeColl.at(IdxSS1).Pt()? IdxOS:IdxSS1;
      IdxL2_Z = ElConeColl.at(IdxOS).Pt()>ElConeColl.at(IdxSS1).Pt()? IdxSS1:IdxOS;
      IdxL_Fk = IdxSS2;
    }
    else{
      IdxL1_Z = ElConeColl.at(IdxOS).Pt()>ElConeColl.at(IdxSS2).Pt()? IdxOS:IdxSS2;
      IdxL2_Z = ElConeColl.at(IdxOS).Pt()>ElConeColl.at(IdxSS2).Pt()? IdxSS2:IdxOS;
      IdxL_Fk = IdxSS1;
    }
    PTl1_Z    = ElConeColl.at(IdxL1_Z).Pt() , PTl2_Z  = ElConeColl.at(IdxL2_Z).Pt();
    Etal1_Z   = ElConeColl.at(IdxL1_Z).Eta(), Etal2_Z = ElConeColl.at(IdxL2_Z).Eta();
    PTl_Fk    = ElConeColl.at(IdxL_Fk).Pt() , Etal_Fk = ElConeColl.at(IdxL_Fk).Eta();
    MOSSF_Z   = (ElConeColl.at(IdxL1_Z)+ElConeColl.at(IdxL2_Z)).M(), MTW = MT(ElConeColl.at(IdxL_Fk), vMET);
    M3l       = (ElConeColl.at(0)+ElConeColl.at(1)+ElConeColl.at(2)).M();
    dRZFk     = ElConeColl.at(IdxL_Fk).DeltaR(ElConeColl.at(IdxL1_Z)+ElConeColl.at(IdxL2_Z));
    dEtaZFk   = fabs(ElConeColl.at(IdxL_Fk).Eta()-(ElConeColl.at(IdxL1_Z)+ElConeColl.at(IdxL2_Z)).Eta());
    IsFkHEMReg= IsHEMIssueReg(ElConeColl.at(IdxL_Fk));
    if(DataYear==2018) IsFkHEMReg= IsHEMIssueReg(ElConeColl.at(IdxL_Fk));
  }
  else return;

  if(MOSSF1<12 or ((NMuT>2 or NElT>2) and MOSSF2<12)) return;
  bool OnZ=fabs(MOSSF_Z-91.2)<10.;
  //if(M3l<91.2+15.) return;

  if(!IsDATA){
    int GenLepInfo = GetGenLepInfo(ElTColl, MuTColl);
    if(ConvRun && GenLepInfo>=1000) return;
  }

  //Label = "_3l"+Label;
  vector<TString> SelTagList = {"_3l"};
  if(OnZ) SelTagList.push_back("_3lOnZ");

  for(unsigned int iSel=0; iSel<SelTagList.size(); iSel++){
    TString SelTag(SelTagList.at(iSel));
    FillHist("M3l"+SelTag+Label, M3l, weight, 50, 0., 500., ApplyWVar, SysWgtStrPairList);
    FillHist("MOSSF1"+SelTag+Label, MOSSF1, weight, 40, 0., 200., ApplyWVar, SysWgtStrPairList);
    FillHist("MOSSF2"+SelTag+Label, MOSSF2, weight, 40, 0., 200., ApplyWVar, SysWgtStrPairList);
    FillHist("PTl1_Z"+SelTag+Label, PTl1_Z, weight, 40, 0., 200., ApplyWVar, SysWgtStrPairList);
    FillHist("PTl2_Z"+SelTag+Label, PTl2_Z, weight, 40, 0., 200., ApplyWVar, SysWgtStrPairList);
    FillHist("PTl_Fk"+SelTag+Label, PTl_Fk, weight, 40, 0., 200., ApplyWVar, SysWgtStrPairList);
    FillHist("Etal1_Z"+SelTag+Label, Etal1_Z, weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    FillHist("Etal2_Z"+SelTag+Label, Etal2_Z, weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    FillHist("Etal_Fk"+SelTag+Label, Etal_Fk, weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    FillHist("MOSSF_Z"+SelTag+Label, MOSSF_Z, weight, 30, 60., 120., ApplyWVar, SysWgtStrPairList);
    FillHist("Nj"+SelTag+Label, JetColl.size(), weight, 10, 0., 10., ApplyWVar, SysWgtStrPairList);
    FillHist("Nb"+SelTag+Label, BJetColl.size(), weight, 5, 0., 5., ApplyWVar, SysWgtStrPairList);
    FillHist("MET"+SelTag+Label, vMET.Pt(), weight, 20, 0., 200., ApplyWVar, SysWgtStrPairList);
    FillHist("MTW"+SelTag+Label, MTW, weight, 20, 0., 200., ApplyWVar, SysWgtStrPairList); 
    FillHist("dRZFk"+SelTag+Label, dRZFk, weight, 25, 0., 5., ApplyWVar, SysWgtStrPairList);
    FillHist("dEtaZFk"+SelTag+Label, dEtaZFk, weight, 25, 0., 5., ApplyWVar, SysWgtStrPairList);
    if(IsFkHEMReg) FillHist("NCntHEMFk"+SelTag+Label, 0., weight, 1, 0., 1., ApplyWVar, SysWgtStrPairList);
  }


}



void ControlPlots::CheckConvCR(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                               vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                               vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& Ev, float weight, TString Label)
{
  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  int NLepT=NMuT+NElT;
  bool ApplyWVar = Label.Contains("SystWgtVar");
  if( ApplyWVar ) Label.ReplaceAll("SystWgtVar","");
  if( FakeRun      and weight==0.  ) return; 
  if( !(NMuT==NMuL and NElT==NElL) ) return;
  if( !(NMuT==NMuV and NElT==NElV) ) return;
  if( NLepT!=3 ) return;
  bool PassTrAcc=false, PassTrAcc_MM=false, PassTrAcc_EE=false, PassTrAcc_EM=false;
  if( NMuT>1 && MuTColl.at(0).Pt()>20 && MuTColl.at(1).Pt()>10 ) PassTrAcc_MM=true;
  if( NElT>1 && ElTColl.at(0).Pt()>25 && ElTColl.at(1).Pt()>15 ) PassTrAcc_EE=true;
  if( NElT>0 && NMuT>0 && ElTColl.at(0).Pt()>25 && MuTColl.at(0).Pt()>10 ) PassTrAcc_EM=true;
  if( NElT>0 && NMuT>0 && ElTColl.at(0).Pt()>15 && MuTColl.at(0).Pt()>25 ) PassTrAcc_EM=true;
  if(PassTrAcc_MM){
    for(unsigned int im1=0; im1<MuTColl.size(); im1++){
    for(unsigned int im2=im1+1; im2<MuTColl.size(); im2++){
      if((MuTColl.at(im1)+MuTColl.at(im2)).M()<4){ PassTrAcc_MM=false; break; }
    }}
  }
  PassTrAcc = PassTrAcc_MM or PassTrAcc_EE or PassTrAcc_EM;
  if(!PassTrAcc) return;
  int Qtot_Mu = SumCharge(MuTColl), Qtot_El = SumCharge(ElTColl), Qtot_Lep = Qtot_Mu+Qtot_El;
  if( abs(Qtot_Lep)!=1 ) return;
  if( NMuT==2 && Qtot_Mu!=0 ) return;
  if( NElT==2 && Qtot_El!=0 ) return;
  if( BJetColl.size()>0 ) return;

  vector<Electron> ElConeColl; vector<Muon> MuConeColl;
  if(FakeRun){
    for(unsigned int ie=0; ie<ElTColl.size(); ie++){ 
      Electron TmpEl(ElTColl.at(ie));
      float RelIso = ElTColl.at(ie).MiniRelIso();
      float PTCorr = ElTColl.at(ie).CalcPtCone(RelIso,0.1), PT=ElTColl.at(ie).Pt();
      if(RelIso>0.1) TmpEl *= PTCorr/PT;
      ElConeColl.push_back(TmpEl);
    }
    for(unsigned int im=0; im<MuTColl.size(); im++){ 
      Muon TmpMu(MuTColl.at(im));
      float RelIso = MuTColl.at(im).MiniRelIso();
      float PTCorr = MuTColl.at(im).CalcPtCone(RelIso,0.1), PT=MuTColl.at(im).Pt();
      if(RelIso>0.1) TmpMu *= PTCorr/PT;
      MuConeColl.push_back(TmpMu);
    }
  }
  else{ ElConeColl = ElTColl; MuConeColl = MuTColl; }


  float PTl1_Z=0., PTl2_Z=0., PTl_Cv=0., Etal1_Z=0., Etal2_Z=0., Etal_Cv=0.;
  float MTW=0., MOSSF1=0., MOSSF2=0., M3l=0.;
  TString FinSt("");
  if(NMuT==2 && NElT==1){
    if( !(PassTrAcc_MM && Ev.PassTrigger(TrigList_DblMu)) ) return; //TrSF2L
    FinSt   = "_2M1E";
    PTl1_Z  = MuConeColl.at(0).Pt() , PTl2_Z  = MuConeColl.at(1).Pt();
    Etal1_Z = MuConeColl.at(0).Eta(), Etal2_Z = MuConeColl.at(1).Eta();
    PTl_Cv  = ElConeColl.at(0).Pt() , Etal_Cv = ElConeColl.at(0).Eta();
    MOSSF1  = (MuConeColl.at(0)+MuConeColl.at(1)).M(), MTW = MT(ElConeColl.at(0), vMET);
    M3l     = (MuConeColl.at(0)+MuConeColl.at(1)+ElConeColl.at(0)).M();
  }
  else if(NMuT==1 && NElT==2){
    if( !(PassTrAcc_EE && Ev.PassTrigger(TrigList_DblEG)) ) return; //TrSF2L
    FinSt   = "_1M2E";
    PTl1_Z  = ElConeColl.at(0).Pt() , PTl2_Z  = ElConeColl.at(1).Pt();
    Etal1_Z = ElConeColl.at(0).Eta(), Etal2_Z = ElConeColl.at(1).Eta();
    PTl_Cv  = MuConeColl.at(0).Pt() , Etal_Cv = MuConeColl.at(0).Eta();
    MOSSF1  = (ElConeColl.at(0)+ElConeColl.at(1)).M(), MTW = MT(MuConeColl.at(0), vMET);
    M3l     = (ElConeColl.at(0)+ElConeColl.at(1)+MuConeColl.at(0)).M();
  }
  else if(NMuT==3 && NElT==0){
    if( !(PassTrAcc_MM && Ev.PassTrigger(TrigList_DblMu)) ) return;
    FinSt   = "_3M0E";
    int IdxOS  = TriMuChargeIndex(MuConeColl, "OS");
    int IdxSS1 = TriMuChargeIndex(MuConeColl, "SS1");
    int IdxSS2 = TriMuChargeIndex(MuConeColl, "SS2");
    MOSSF1 = (MuConeColl.at(IdxOS)+MuConeColl.at(IdxSS1)).M();
    MOSSF2 = (MuConeColl.at(IdxOS)+MuConeColl.at(IdxSS2)).M();
    int IdxL1_Z=-1, IdxL2_Z=-1, IdxL_Cv=-1;
    if(fabs(MOSSF1-91.2)<fabs(MOSSF2-91.2)){
      IdxL1_Z = MuConeColl.at(IdxOS).Pt()>MuConeColl.at(IdxSS1).Pt()? IdxOS:IdxSS1;
      IdxL2_Z = MuConeColl.at(IdxOS).Pt()>MuConeColl.at(IdxSS1).Pt()? IdxSS1:IdxOS;
      IdxL_Cv = IdxSS2;
    }
    else{
      IdxL1_Z = MuConeColl.at(IdxOS).Pt()>MuConeColl.at(IdxSS2).Pt()? IdxOS:IdxSS2;
      IdxL2_Z = MuConeColl.at(IdxOS).Pt()>MuConeColl.at(IdxSS2).Pt()? IdxSS2:IdxOS;
      IdxL_Cv = IdxSS1;
    }
    PTl1_Z  = MuConeColl.at(IdxL1_Z).Pt() , PTl2_Z = MuConeColl.at(IdxL2_Z).Pt();
    Etal1_Z = MuConeColl.at(IdxL1_Z).Eta(), Etal2_Z = MuConeColl.at(IdxL2_Z).Eta();
    PTl_Cv  = MuConeColl.at(IdxL_Cv).Pt() , Etal_Cv = MuConeColl.at(IdxL_Cv).Eta();
    MTW     = MT(MuConeColl.at(IdxL_Cv), vMET);
    M3l     = (MuConeColl.at(0)+MuConeColl.at(1)+MuConeColl.at(2)).M();
  }
  else if(NMuT==0 && NElT==3){
    if( !(PassTrAcc_EE && Ev.PassTrigger(TrigList_DblEG)) ) return;
    FinSt   = "_0M3E";
    int IdxOS  = TriElChargeIndex(ElConeColl, "OS");
    int IdxSS1 = TriElChargeIndex(ElConeColl, "SS1");
    int IdxSS2 = TriElChargeIndex(ElConeColl, "SS2");
    MOSSF1 = (ElConeColl.at(IdxOS)+ElConeColl.at(IdxSS1)).M();
    MOSSF2 = (ElConeColl.at(IdxOS)+ElConeColl.at(IdxSS2)).M();
    int IdxL1_Z=-1, IdxL2_Z=-1, IdxL_Cv=-1;
    if(fabs(MOSSF1-91.2)<fabs(MOSSF2-91.2)){
      IdxL1_Z = ElConeColl.at(IdxOS).Pt()>ElConeColl.at(IdxSS1).Pt()? IdxOS:IdxSS1;
      IdxL2_Z = ElConeColl.at(IdxOS).Pt()>ElConeColl.at(IdxSS1).Pt()? IdxSS1:IdxOS;
      IdxL_Cv = IdxSS2;
    }
    else{
      IdxL1_Z = ElConeColl.at(IdxOS).Pt()>ElConeColl.at(IdxSS2).Pt()? IdxOS:IdxSS2;
      IdxL2_Z = ElConeColl.at(IdxOS).Pt()>ElConeColl.at(IdxSS2).Pt()? IdxSS2:IdxOS;
      IdxL_Cv = IdxSS1;
    }
    PTl1_Z  = ElConeColl.at(IdxL1_Z).Pt() , PTl2_Z = ElConeColl.at(IdxL2_Z).Pt();
    Etal1_Z = ElConeColl.at(IdxL1_Z).Eta(), Etal2_Z = ElConeColl.at(IdxL2_Z).Eta();
    PTl_Cv  = ElConeColl.at(IdxL_Cv).Pt() , Etal_Cv = ElConeColl.at(IdxL_Cv).Eta();
    MTW     = MT(ElConeColl.at(IdxL_Cv), vMET);
    M3l     = (ElConeColl.at(0)+ElConeColl.at(1)+ElConeColl.at(2)).M();
  }
  else return;

  if( MOSSF1<12 or ((NMuT>2 or NElT>2) and MOSSF2<12) ) return;
  if( fabs(MOSSF1-91.2)<10 or fabs(MOSSF2-91.2)<10    ) return;
  if( fabs(M3l-91.2)>10. ) return;

  
  if(!IsDATA){
    int GenLepInfo = GetGenLepInfo(ElConeColl, MuConeColl);
    if(ConvRun && GenLepInfo>=1000 ) return;
    //if(ConvRun && GenLepInfo>=100 ) return;
    int NCv = GenLepInfo%100/10;
    if(!Label.Contains("Syst")) FillHist("NCv"+FinSt+Label, NCv, weight, 3, 0., 3.);   
  }
  int NPt20=0;
  for(unsigned int im=0; im<MuConeColl.size(); im++){ if(MuConeColl.at(im).Pt()>15) NPt20++; }
  for(unsigned int ie=0; ie<ElConeColl.size(); ie++){ if(ElConeColl.at(ie).Pt()>15) NPt20++; }
  if(MCSample.Contains("ZG") && NPt20!=3) return;

  vector<TString> FinStTagList={FinSt};
  if     (FinSt=="_0M3E" or FinSt=="_2M1E") FinStTagList.push_back("_CvEl");
  else if(FinSt=="_3M0E" or FinSt=="_1M2E") FinStTagList.push_back("_CvMu");
  vector<TString> SelTagList  ={"_ZGSel"};

  for(unsigned int iSt=0; iSt<FinStTagList.size(); iSt++){
  for(unsigned int iSel=0; iSel<SelTagList.size(); iSel++){
    TString FinStTag(FinStTagList.at(iSt)), SelTag(SelTagList.at(iSel));
    FillHist("NCount"+SelTag+FinStTag+Label, 0., weight, 1, 0., 1., ApplyWVar, SysWgtStrPairList);
    FillHist("M3l"+SelTag+FinStTag+Label, M3l, weight, 30, 60., 120., ApplyWVar, SysWgtStrPairList);
    FillHist("MOSSF1"+SelTag+FinStTag+Label, MOSSF1, weight, 15, 0., 150., ApplyWVar, SysWgtStrPairList);
    FillHist("MOSSF2"+SelTag+FinStTag+Label, MOSSF2, weight, 15, 0., 150., ApplyWVar, SysWgtStrPairList);
    FillHist("PTl1_Z"+SelTag+FinStTag+Label, PTl1_Z, weight, 24, 0., 120., ApplyWVar, SysWgtStrPairList);
    FillHist("PTl2_Z"+SelTag+FinStTag+Label, PTl2_Z, weight, 16, 0., 80., ApplyWVar, SysWgtStrPairList);
    FillHist("PTl_Cv"+SelTag+FinStTag+Label, PTl_Cv, weight, 16, 0., 80., ApplyWVar, SysWgtStrPairList);
    FillHist("Etal1_Z"+SelTag+FinStTag+Label, Etal1_Z, weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    FillHist("Etal2_Z"+SelTag+FinStTag+Label, Etal2_Z, weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    FillHist("Etal_Cv"+SelTag+FinStTag+Label, Etal_Cv, weight, 20, -5., 5., ApplyWVar, SysWgtStrPairList);
    FillHist("Nj"+SelTag+FinStTag+Label, JetColl.size(), weight, 10, 0., 10., ApplyWVar, SysWgtStrPairList);
    FillHist("Nb"+SelTag+FinStTag+Label, BJetColl.size(), weight, 5, 0., 5., ApplyWVar, SysWgtStrPairList);
    FillHist("MET"+SelTag+FinStTag+Label, vMET.Pt(), weight, 20, 0., 200., ApplyWVar, SysWgtStrPairList);
    FillHist("MTW"+SelTag+FinStTag+Label, MTW, weight, 20, 0., 200., ApplyWVar, SysWgtStrPairList); 
  }}

}


void ControlPlots::MakePlotSS2L(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                                vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                                vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{

  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  vector<Muon> MuConeColl; vector<Electron> ElConeColl;
  if( !( (NMuT==2 and NElT==0) or (NElT==2 and NMuT==0) ) ) return;
  if( !(NMuT==NMuL and NElT==NElL) ) return;
  if( !(NMuL==NMuV and NElL==NElV) ) return;
  if( FakeRun      and weight==0.  ) return; 
  if(NMuL==2){
    if(MuTColl.at(0).Charge()!=MuTColl.at(1).Charge()) return;
    if(!(MuTColl.at(0).Pt()>20 && MuTColl.at(1).Pt()>10)) return;
    float Mll = (MuTColl.at(0)+MuTColl.at(1)).M();
    if(Mll<4) return; 
    if(!IsDATA){
      int GenLepInfo = GetGenLepInfo(ElTColl, MuTColl);
      if(ConvRun && GenLepInfo>=100) return;
      if(FlipRun && (GenLepInfo>999 or GenLepInfo<100)) return;
    }
    if(BJetColl.size()<1) return;
      FillHist("NJPreCut"+Label+"_2M", JetColl.size(), weight, 10, 0., 10.);
    if(JetColl.size() <3) return;

    if(FakeRun){
      for(unsigned int ie=0; ie<ElTColl.size(); ie++){ 
        Electron TmpEl(ElTColl.at(ie));
        float RelIso = ElTColl.at(ie).MiniRelIso();
        float PTCorr = ElTColl.at(ie).CalcPtCone(RelIso,0.1), PT=ElTColl.at(ie).Pt();
        if(RelIso>0.1) TmpEl *= PTCorr/PT;
        ElConeColl.push_back(TmpEl);
      }
      for(unsigned int im=0; im<MuTColl.size(); im++){ 
        Muon TmpMu(MuTColl.at(im));
        float RelIso = MuTColl.at(im).MiniRelIso();
        float PTCorr = MuTColl.at(im).CalcPtCone(RelIso,0.1), PT=MuTColl.at(im).Pt();
        if(RelIso>0.1) TmpMu *= PTCorr/PT;
        MuConeColl.push_back(TmpMu);
      }
    }
    else{ ElConeColl = ElTColl; MuConeColl = MuTColl; }

    InitializeTreeVars();
    SetVarSS2L(MuConeColl, MuLColl, MuVColl, ElConeColl, ElLColl, ElVColl, JetColl, BJetColl, vMET, weight, "");

    //if( (MuConeColl.at(0)+MuConeColl.at(1)).M()<80 ) return;
    if(MVAReader->EvaluateMVA("BDTG_MN50_Mu")>0) return;
    PlotParametersSS(Label+"_2M");
  }
  if(NElL==2){
    int aSumQ = abs(SumCharge(ElTColl)); float MCCFSF=1.;
    if(FlipRun && !FakeRun){ if(aSumQ!=0) return; }
    else                   { if(aSumQ==0) return; }
    if(!(ElTColl.at(0).Pt()>25 && ElTColl.at(1).Pt()>15)) return;
    if(!IsDATA){
      int GenLepInfo = GetGenLepInfo(ElTColl, MuTColl);
      if(ConvRun && GenLepInfo>=100) return;
      if(FlipRun && aSumQ!=0 && (GenLepInfo>999 or GenLepInfo<100)) return;
      if(FlipRun && FakeRun){
        int IdxFlipped = GenLepInfo % 10;
        MCCFSF = GetCFRAndSF( ElTColl.at(IdxFlipped).Pt(), fabs(ElTColl.at(IdxFlipped).Eta()), "hCFR_sf_Var", "");
      }
    }
    float newweight = weight*MCCFSF;

    if(BJetColl.size()<1) return;
      FillHist("NJPreCut"+Label+"_2E", JetColl.size(), newweight, 10, 0., 10.);
    if(JetColl.size() <3) return;

    if(FakeRun){
      for(unsigned int ie=0; ie<ElTColl.size(); ie++){ 
        Electron TmpEl(ElTColl.at(ie));
        float RelIso = ElTColl.at(ie).MiniRelIso();
        float PTCorr = ElTColl.at(ie).CalcPtCone(RelIso,0.1), PT=ElTColl.at(ie).Pt();
        if(RelIso>0.1) TmpEl *= PTCorr/PT;
        ElConeColl.push_back(TmpEl);
      }
      for(unsigned int im=0; im<MuTColl.size(); im++){ 
        Muon TmpMu(MuTColl.at(im));
        float RelIso = MuTColl.at(im).MiniRelIso();
        float PTCorr = MuTColl.at(im).CalcPtCone(RelIso,0.1), PT=MuTColl.at(im).Pt();
        if(RelIso>0.1) TmpMu *= PTCorr/PT;
        MuConeColl.push_back(TmpMu);
      }
    }
    else{ ElConeColl = ElTColl; MuConeColl = MuTColl; }

    if( fabs( (ElConeColl.at(0)+ElConeColl.at(1)).M()-91.2 )<10 ) return; 

    InitializeTreeVars();
    SetVarSS2L(MuConeColl, MuLColl, MuVColl, ElConeColl, ElLColl, ElVColl, JetColl, BJetColl, vMET, newweight, "");

    if(MVAReader->EvaluateMVA("BDTG_MN50_El")>0) return;
    PlotParametersSS(Label+"_2E");
  }

}


void ControlPlots::SetVarSS2L(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                              vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                              vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{
  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  if( !( (NMuT==2 and NElT==0) or (NElT==2 and NMuT==0) ) ) return;
  if( !(NMuT==NMuL and NElT==NElL) ) return;
  if( !(NMuT==NMuV and NElT==NElV) ) return;
  if(BJetColl.size()<1) return;
  if(JetColl.size() <3) return;
  if(NMuT==2){
    InitializeTreeVars();
    Nj      = JetColl.size();
    Nb      = BJetColl.size();
    Ptl1    = MuTColl.at(0).Pt();
    Ptl2    = MuTColl.at(1).Pt();
    Ptj1    = JetColl.at(0).Pt();
    Ptj2    = JetColl.at(1).Pt();
    Ptj3    = JetColl.at(2).Pt();
    dRll    = MuTColl.at(0).DeltaR(MuTColl.at(1));
    dRlj11  = MuTColl.at(0).DeltaR(JetColl.at(0));
    dRlj12  = MuTColl.at(0).DeltaR(JetColl.at(1));
    dRlj13  = MuTColl.at(0).DeltaR(JetColl.at(2));
    dRlj21  = MuTColl.at(1).DeltaR(JetColl.at(0));
    dRlj22  = MuTColl.at(1).DeltaR(JetColl.at(1));
    dRlj23  = MuTColl.at(1).DeltaR(JetColl.at(2));
    MSSSF   = (MuTColl.at(0)+MuTColl.at(1)).M();
    MTvl1   = MT(MuTColl.at(0),vMET);
    MTvl2   = MT(MuTColl.at(1),vMET);

    //Vars requiring complex algo.
    HT      = 0;
      for(unsigned int itj=0; itj<JetColl.size(); itj++){ HT+=JetColl.at(itj).Pt(); }
    MET2HT  = pow(vMET.Pt(),2.)/HT;
    int Idxj1W_2jL=-1, Idxj2W_2jL=-1; float bestmlljj=-1;
    int Idxj1W_1jL=-1; float bestmllj=-1;
    int Idxj1W1_H=-1, Idxj2W1_H=-1; float bestmjj1=-1;
    for(unsigned int itj1=0; itj1<JetColl.size(); itj1++){
      if(bestmllj<0){ Idxj1W_1jL=itj1; bestmllj=(MuTColl.at(0)+MuTColl.at(1)).M(); }
      else{
        float tmpmljj = (MuTColl.at(0)+MuTColl.at(1)+JetColl.at(itj1)).M();
        if(fabs(tmpmljj-80.4)<fabs(bestmllj-80.4)){ bestmllj=tmpmljj; Idxj1W_1jL=itj1; }
      }
      for(unsigned int itj2=itj1+1; itj2<JetColl.size(); itj2++){
        if(bestmlljj<0){ Idxj1W_2jL=itj1; Idxj2W_2jL=itj2; bestmlljj=(MuTColl.at(0)+MuTColl.at(1)+JetColl.at(itj1)+JetColl.at(itj2)).M(); }
        else{
          float tmpmlljj = (MuTColl.at(0)+MuTColl.at(1)+JetColl.at(itj1)+JetColl.at(itj2)).M();
          if(fabs(tmpmlljj-80.4)<fabs(bestmlljj-80.4)){ bestmlljj=tmpmlljj; Idxj1W_2jL=itj1, Idxj2W_2jL=itj2; }
        }
        if(bestmjj1<0){ Idxj1W1_H=itj1, Idxj2W1_H=itj2; bestmjj1=(JetColl.at(itj1)+JetColl.at(itj2)).M(); }
        else{
          float tmpmjj = (JetColl.at(itj1)+JetColl.at(itj2)).M();
          if(fabs(tmpmjj-80.4)<fabs(bestmjj1-80.4)){ bestmjj1=tmpmjj; Idxj1W1_H=itj1, Idxj2W1_H=itj2; }
        }
      }
    }
    MllW_2jL = bestmlljj;
    MllW_1jL = bestmllj;
    MllW1_H  = (MuTColl.at(0)+MuTColl.at(1)+JetColl.at(Idxj1W1_H)+JetColl.at(Idxj2W1_H)).M();
    Ml1W_2jL = (MuTColl.at(0)+JetColl.at(Idxj1W_2jL)+JetColl.at(Idxj2W_2jL)).M();
    Ml1W_1jL = (MuTColl.at(0)+JetColl.at(Idxj1W_1jL)).M();
    Ml2W_2jL = (MuTColl.at(1)+JetColl.at(Idxj1W_2jL)+JetColl.at(Idxj2W_2jL)).M();
    Ml2W_1jL = (MuTColl.at(1)+JetColl.at(Idxj1W_1jL)).M();
    Ml1W1_H  = (MuTColl.at(0)+JetColl.at(Idxj1W1_H)+JetColl.at(Idxj2W1_H)).M();
    Ml2W1_H  = (MuTColl.at(1)+JetColl.at(Idxj1W1_H)+JetColl.at(Idxj2W1_H)).M();
    w_tot    = weight;
  }
  if(NElT==2){
    InitializeTreeVars();
    Nj      = JetColl.size();
    Nb      = BJetColl.size();
    Ptl1    = ElTColl.at(0).Pt();
    Ptl2    = ElTColl.at(1).Pt();
    Ptj1    = JetColl.at(0).Pt();
    Ptj2    = JetColl.at(1).Pt();
    Ptj3    = JetColl.at(2).Pt();
    dRll    = ElTColl.at(0).DeltaR(ElTColl.at(1));
    dRlj11  = ElTColl.at(0).DeltaR(JetColl.at(0));
    dRlj12  = ElTColl.at(0).DeltaR(JetColl.at(1));
    dRlj13  = ElTColl.at(0).DeltaR(JetColl.at(2));
    dRlj21  = ElTColl.at(1).DeltaR(JetColl.at(0));
    dRlj22  = ElTColl.at(1).DeltaR(JetColl.at(1));
    dRlj23  = ElTColl.at(1).DeltaR(JetColl.at(2));
    MSSSF   = (ElTColl.at(0)+ElTColl.at(1)).M();
    MTvl1   = MT(ElTColl.at(0),vMET);
    MTvl2   = MT(ElTColl.at(1),vMET);

    //Vars requiring complex algo.
    HT      = 0;
      for(unsigned int itj=0; itj<JetColl.size(); itj++){ HT+=JetColl.at(itj).Pt(); }
    MET2HT  = pow(vMET.Pt(),2.)/HT;
    int Idxj1W_2jL=-1, Idxj2W_2jL=-1; float bestmlljj=-1;
    int Idxj1W_1jL=-1; float bestmllj=-1;
    int Idxj1W1_H=-1, Idxj2W1_H=-1; float bestmjj1=-1;
    for(unsigned int itj1=0; itj1<JetColl.size(); itj1++){
      if(bestmllj<0){ Idxj1W_1jL=itj1; bestmllj=(ElTColl.at(0)+ElTColl.at(1)).M(); }
      else{
        float tmpmljj = (ElTColl.at(0)+ElTColl.at(1)+JetColl.at(itj1)).M();
        if(fabs(tmpmljj-80.4)<fabs(bestmllj-80.4)){ bestmllj=tmpmljj; Idxj1W_1jL=itj1; }
      }
      for(unsigned int itj2=itj1+1; itj2<JetColl.size(); itj2++){
        if(bestmlljj<0){ Idxj1W_2jL=itj1; Idxj2W_2jL=itj2; bestmlljj=(ElTColl.at(0)+ElTColl.at(1)+JetColl.at(itj1)+JetColl.at(itj2)).M(); }
        else{
          float tmpmlljj = (ElTColl.at(0)+ElTColl.at(1)+JetColl.at(itj1)+JetColl.at(itj2)).M();
          if(fabs(tmpmlljj-80.4)<fabs(bestmlljj-80.4)){ bestmlljj=tmpmlljj; Idxj1W_2jL=itj1, Idxj2W_2jL=itj2; }
        }
        if(bestmjj1<0){ Idxj1W1_H=itj1, Idxj2W1_H=itj2; bestmjj1=(JetColl.at(itj1)+JetColl.at(itj2)).M(); }
        else{
          float tmpmjj = (JetColl.at(itj1)+JetColl.at(itj2)).M();
          if(fabs(tmpmjj-80.4)<fabs(bestmjj1-80.4)){ bestmjj1=tmpmjj; Idxj1W1_H=itj1, Idxj2W1_H=itj2; }
        }
      }
    }
    MllW_2jL = bestmlljj;
    MllW_1jL = bestmllj;
    MllW1_H  = (ElTColl.at(0)+ElTColl.at(1)+JetColl.at(Idxj1W1_H)+JetColl.at(Idxj2W1_H)).M();
    Ml1W_2jL = (ElTColl.at(0)+JetColl.at(Idxj1W_2jL)+JetColl.at(Idxj2W_2jL)).M();
    Ml1W_1jL = (ElTColl.at(0)+JetColl.at(Idxj1W_1jL)).M();
    Ml2W_2jL = (ElTColl.at(1)+JetColl.at(Idxj1W_2jL)+JetColl.at(Idxj2W_2jL)).M();
    Ml2W_1jL = (ElTColl.at(1)+JetColl.at(Idxj1W_1jL)).M();
    Ml1W1_H  = (ElTColl.at(0)+JetColl.at(Idxj1W1_H)+JetColl.at(Idxj2W1_H)).M();
    Ml2W1_H  = (ElTColl.at(1)+JetColl.at(Idxj1W1_H)+JetColl.at(Idxj2W1_H)).M();
    w_tot    = weight;
  }

}



void ControlPlots::PlotParameters(TString Label){

  FillHist("NEvt"+Label, 0., w_tot, 1, 0., 1.);
  FillHist("Nj"+Label, Nj, w_tot, 10, 0., 10.);
  FillHist("Nb"+Label, Nb, w_tot, 5, 0., 5.);
  FillHist("Ptl1"+Label, Ptl1, w_tot, 25, 0., 250.);
  FillHist("Ptl2"+Label, Ptl2, w_tot, 30, 0., 150.);
  FillHist("Ptj1"+Label, Ptj1, w_tot, 25, 0., 500.);
  FillHist("Ptj2"+Label, Ptj2, w_tot, 30, 0., 300.);
  FillHist("Ptj3"+Label, Ptj3, w_tot, 20, 0., 200.);
  FillHist("HT"+Label, HT, w_tot, 25, 0., 1000.);
  FillHist("MET2HT"+Label, MET2HT, w_tot, 30, 0., 150.);
  FillHist("dRll"+Label, dRll, w_tot, 25, 0., 5.);
  FillHist("dRlj11"+Label, dRlj11, w_tot, 25, 0., 5.);
  FillHist("dRlj12"+Label, dRlj12, w_tot, 25, 0., 5.);
  FillHist("dRlj13"+Label, dRlj13, w_tot, 25, 0., 5.);
  FillHist("dRlj21"+Label, dRlj21, w_tot, 25, 0., 5.);
  FillHist("dRlj22"+Label, dRlj22, w_tot, 25, 0., 5.);
  FillHist("dRlj23"+Label, dRlj23, w_tot, 25, 0., 5.);
  FillHist("MSSSF"+Label, MSSSF, w_tot, 40, 0., 400.);
  FillHist("MTvl1"+Label, MTvl1, w_tot, 30, 0., 300.);
  FillHist("MTvl2"+Label, MTvl2, w_tot, 20, 0., 200.);
  FillHist("MllW_2jL"+Label, MllW_2jL, w_tot, 25, 0., 500.);
  FillHist("MllW_1jL"+Label, MllW_1jL, w_tot, 25, 0., 250.);
  FillHist("MllW1_H"+Label, MllW1_H, w_tot, 24, 0., 600.);
  FillHist("Ml1W_2jL"+Label, Ml1W_2jL, w_tot, 25, 0., 500.);
  FillHist("Ml1W_1jL"+Label, Ml1W_1jL, w_tot, 25, 0., 500.);
  FillHist("Ml2W_2jL"+Label, Ml2W_2jL, w_tot, 40, 0., 400.);
  FillHist("Ml2W_1jL"+Label, Ml2W_1jL, w_tot, 30, 0., 300.);
  FillHist("Ml1W1_H"+Label, Ml1W1_H, w_tot, 30, 0., 600.);
  FillHist("Ml2W1_H"+Label, Ml2W1_H, w_tot, 40, 0., 400.);

  for(unsigned int im=0; im<MNStrList.size(); im++){
    bool Is2E = Label.Contains("_2E"), Is2M = Label.Contains("_2M"), IsEM=Label.Contains("_EM");
    TString MVATagStr_Mu = "BDTG_MN"+MNStrList.at(im)+"_Mu";
    TString MVATagStr_El = "BDTG_MN"+MNStrList.at(im)+"_El";
    float MVAvalue_Mu = Is2M or IsEM? MVAReader->EvaluateMVA(MVATagStr_Mu):999.;
    float MVAvalue_El = Is2E or IsEM? MVAReader->EvaluateMVA(MVATagStr_El):999.;
    if(Is2M or IsEM) FillHist("BDTG_Mu_MN"+MNStrList.at(im)+Label, MVAvalue_Mu, w_tot, 40, -1., 1.);
    if(Is2E or IsEM) FillHist("BDTG_El_MN"+MNStrList.at(im)+Label, MVAvalue_El, w_tot, 40, -1., 1.);
  }

}


void ControlPlots::PlotParametersSS(TString Label){

  FillHist("NEvt"+Label, 0., w_tot, 1, 0., 1.);
  FillHist("Nj"+Label, Nj, w_tot, 10, 0., 10.);
  FillHist("Nb"+Label, Nb, w_tot, 5, 0., 5.);
  FillHist("Ptl1"+Label, Ptl1, w_tot, 15, 0., 300.);
  FillHist("Ptl2"+Label, Ptl2, w_tot, 15, 0., 150.);
  FillHist("Ptj1"+Label, Ptj1, w_tot, 10, 0., 500.);
  FillHist("Ptj2"+Label, Ptj2, w_tot, 12, 0., 300.);
  FillHist("Ptj3"+Label, Ptj3, w_tot,  8, 0., 200.);
  FillHist("HT"+Label, HT, w_tot, 12, 0., 900.);
  FillHist("MET2HT"+Label, MET2HT, w_tot, 15, 0., 150.);
  FillHist("dRll"+Label, dRll, w_tot, 15, 0., 6.);
  FillHist("dRlj11"+Label, dRlj11, w_tot, 15, 0., 6.);
  FillHist("dRlj12"+Label, dRlj12, w_tot, 15, 0., 6.);
  FillHist("dRlj13"+Label, dRlj13, w_tot, 15, 0., 6.);
  FillHist("dRlj21"+Label, dRlj21, w_tot, 15, 0., 6.);
  FillHist("dRlj22"+Label, dRlj22, w_tot, 15, 0., 6.);
  FillHist("dRlj23"+Label, dRlj23, w_tot, 15, 0., 6.);
  FillHist("MSSSF"+Label, MSSSF, w_tot, 40, 0., 400.);
  FillHist("MTvl1"+Label, MTvl1, w_tot, 16, 0., 400.);
  FillHist("MTvl2"+Label, MTvl2, w_tot, 12, 0., 300.);
  FillHist("MllW_2jL"+Label, MllW_2jL, w_tot, 12, 0., 600.);
  FillHist("MllW_1jL"+Label, MllW_1jL, w_tot, 12, 0., 300.);
  FillHist("MllW1_H"+Label, MllW1_H, w_tot, 16, 0., 800.);
  FillHist("Ml1W_2jL"+Label, Ml1W_2jL, w_tot, 12, 0., 600.);
  FillHist("Ml1W_1jL"+Label, Ml1W_1jL, w_tot, 12, 0., 600.);
  FillHist("Ml2W_2jL"+Label, Ml2W_2jL, w_tot, 16, 0., 400.);
  FillHist("Ml2W_1jL"+Label, Ml2W_1jL, w_tot, 10, 0., 400.);
  FillHist("Ml1W1_H"+Label, Ml1W1_H, w_tot, 16, 0., 800.);
  FillHist("Ml2W1_H"+Label, Ml2W1_H, w_tot, 12, 0., 600.);

  for(unsigned int im=0; im<MNStrList.size(); im++){
    bool Is2E = Label.Contains("_2E"), Is2M = Label.Contains("_2M");
    TString MVATagStr_Mu = "BDTG_MN"+MNStrList.at(im)+"_Mu";
    TString MVATagStr_El = "BDTG_MN"+MNStrList.at(im)+"_El";
    float MVAvalue_Mu = Is2M? MVAReader->EvaluateMVA(MVATagStr_Mu):999.;
    float MVAvalue_El = Is2E? MVAReader->EvaluateMVA(MVATagStr_El):999.;
    if(Is2M) FillHist("BDTG_Mu_MN"+MNStrList.at(im)+Label, MVAvalue_Mu, w_tot, 40, -1., 1.);
    if(Is2E) FillHist("BDTG_El_MN"+MNStrList.at(im)+Label, MVAvalue_El, w_tot, 40, -1., 1.);
  }

}



void ControlPlots::executeEventFromParameter(AnalyzerParameter param){
}


void ControlPlots::InitializeTreeVars(){

  Nj=-1, Nb=-1;
  Ptl1=-1, Ptl2=-1, Ptj1=-1, Ptj2=-1, Ptj3=-1, HT=-1, MET2HT=-1;
  dRll=-1, dRlj11=-1, dRlj12=-1, dRlj13=-1, dRlj21=-1, dRlj22=-1, dRlj23=-1;
  MSSSF=-1, MTvl1=-1, MTvl2=-1;
  MllW_2jL=-1, MllW_1jL=-1, MllW1_H=-1, Ml1W_2jL=-1, Ml1W_1jL=-1, Ml2W_2jL=-1, Ml2W_1jL=-1, Ml1W1_H=-1, Ml2W1_H=-1;
  w_tot=-1;

}


float ControlPlots::GetConvSF(TString ElTID, int SystDir){

  TString Era = GetEraShort(); float SF = 1.;
  if(ElTID=="TopHNSSTWP90Isop1"){
    if     (Era=="2016a"){ SF = 0.961*(1.+((float) SystDir)*0.19); }
    else if(Era=="2016b"){ SF = 1.129*(1.+((float) SystDir)*0.16); }
    else if(Era=="2017" ){ SF = 1.040*(1.+((float) SystDir)*0.16); }
    else if(Era=="2018" ){ SF = 1.122*(1.+((float) SystDir)*0.16); }
  }
  else if(ElTID=="TopHNSST"){
    if     (Era=="2016a"){ SF = 0.938*(1.+((float) SystDir)*0.2 ); }
    else if(Era=="2016b"){ SF = 0.861*(1.+((float) SystDir)*0.21); }
    else if(Era=="2017" ){ SF = 1.019*(1.+((float) SystDir)*0.18); }
    else if(Era=="2018" ){ SF = 1.043*(1.+((float) SystDir)*0.17); }
  }

  return SF;
}



float ControlPlots::GetCFRSF(Electron& El, TString Tag, TString Option){

  if     (IsDATA  && Option=="") return 1.;
  else if(IsDATA  && Option!="DataEff") return 0.;
  else if(!IsDATA && Option=="DataEff") return 0.;

  bool ReturnMCEff=Option.Contains("MCEff"), ReturnDataEff=Option.Contains("DataEff");
  float PT=El.Pt(), fEta=fabs(El.Eta());
  int EtaRegIndex1 = fEta<1.47? 0:1;
  int EtaRegIndex2 = fEta<0.8? 0:fEta<1.47? 1: fEta<2.? 2:3;
  int PtRegIndex1  = PT<35? 0:PT<50? 1: 2;
  int PtRegIndex2  = PT<35? 0:PT<50? 1:PT<100? 2:3;
  int BinIndex1 = EtaRegIndex1*3+PtRegIndex1+1; 
  int BinIndex2 = EtaRegIndex2+1; 
  int BinIndex3 = PtRegIndex2 +1; 

  float SF=1., MCEff=1., DataEff=1., ReturnVal=1.;
  if(Tag.Contains("App2Bin1_")){
    int Idx = BinIndex1;
    if(Tag.EndsWith("It1")) SF= Idx==1? 1.49:Idx==2? 1.50:Idx==3? 1.82:Idx==4? 1.51:Idx==5? 1.41:Idx==6? 1.28:1.;
    if(Tag.EndsWith("It2")) SF= Idx==1? 1.03:Idx==2? 1.02:Idx==3? 1.15:Idx==4? 1.02:Idx==5? 1.01:Idx==6? 0.97:1.;
    if(Tag.EndsWith("It3")) SF= Idx==1? 1.01:Idx==2? 1.01:Idx==3? 1.08:Idx==4? 1.00:Idx==5? 1.00:Idx==6? 0.98:1.;
    if(Tag.EndsWith("It4")) SF= Idx==1? 1.01:Idx==2? 1.00:Idx==3? 1.05:Idx==4? 1.00:Idx==5? 1.00:Idx==6? 0.99:1.;
    if(Tag.EndsWith("Fin")){
       SF      = Idx==1? 1.58:Idx==2? 1.54:Idx==3? 2.45:Idx==4? 1.55:Idx==5? 1.41:Idx==6? 1.21:1.;
       DataEff = Idx==1? 7.98E-5:Idx==2? 8.11E-5:Idx==3? 1.50E-4:Idx==4? 1.48E-3:Idx==5? 1.48E-3:Idx==6? 1.67E-3:1.;
       MCEff   = Idx==1? 5.06E-5:Idx==2? 5.25E-5:Idx==3? 6.15E-5:Idx==4? 9.58E-4:Idx==5? 1.04E-3:Idx==6? 1.39E-3:1.;
    }
  }
  else if(Tag.Contains("App2Bin2_")){
    int Idx = BinIndex2;
    if(Tag.EndsWith("It1")) SF= Idx==1? 1.48:Idx==2? 1.56:Idx==3? 1.36:Idx==4? 1.39:1.;
    if(Tag.EndsWith("It2")) SF= Idx==1? 1.05:Idx==2? 1.08:Idx==3? 0.99:Idx==4? 1.00:1.;
    if(Tag.EndsWith("It3")) SF= Idx==1? 1.04:Idx==2? 1.05:Idx==3? 0.99:Idx==4? 1.00:1.;
    if(Tag.EndsWith("It4")) SF= Idx==1? 1.03:Idx==2? 1.03:Idx==3? 1.00:Idx==4? 1.00:1.;
    if(Tag.EndsWith("Fin")){
      SF      = Idx==1? 1.70:Idx==2? 1.87:Idx==3? 1.34:Idx==4? 1.36:1.;
      DataEff = Idx==1? 3.07E-5:Idx==2? 2.03E-4:Idx==3? 1.11E-3:Idx==4? 2.00E-3:1.;
      MCEff   = Idx==1? 1.81E-5:Idx==2? 1.09E-4:Idx==3? 8.31E-4:Idx==4? 1.45E-3:1.;
    }
  }
  else if(Tag.Contains("App2Bin3_")){
    int Idx = BinIndex3;
    if(Tag.EndsWith("It1")) SF= Idx==1? 1.40:Idx==2? 1.44:Idx==3? 1.42:Idx==4? 1.03:1.;
    if(Tag.EndsWith("It2")) SF= Idx==1? 1.00:Idx==2? 1.00:Idx==3? 1.00:Idx==4? 1.13:1.;
    if(Tag.EndsWith("It3")) SF= Idx==1? 1.00:Idx==2? 1.00:Idx==3? 1.00:Idx==4? 1.05:1.;
    if(Tag.EndsWith("It4")) SF= Idx==1? 1.00:Idx==2? 1.00:Idx==3? 1.00:Idx==4? 1.01:1.;
    if(Tag.EndsWith("Fin")){
      SF      = Idx==1? 1.39:Idx==2? 1.46:Idx==3? 1.43:Idx==4? 1.24:1.;
      DataEff = Idx==1? 4.22E-4:Idx==2? 4.11E-4:Idx==3? 5.15E-4:Idx==4? 6.60E-4:1.;
      MCEff   = Idx==1? 3.02E-4:Idx==2? 2.84E-4:Idx==3? 3.62E-4:Idx==4? 5.33E-4:1.;
    }
  }

  if     (ReturnMCEff  ) ReturnVal = MCEff;
  else if(ReturnDataEff) ReturnVal = DataEff;
  else                   ReturnVal = SF; 

  return ReturnVal;
}


int ControlPlots::GetGenLepInfo(vector<Electron>& ElColl, vector<Muon>& MuColl, TString Option){

  if(truthColl.size()==0) truthColl=GetGens();
  //vector<Gen> TruthColl = GetGens();
  int NFk=0, NFlip=0, NCv=0, IdxFlipped=9;
  for(unsigned int im=0; im<MuColl.size(); im++){
    int LepType = GetLeptonType_JH(MuColl.at(im), truthColl);
    if(LepType<0 && LepType>-5) NFk++;
  }
  for(unsigned int ie=0; ie<ElColl.size(); ie++){
    int LepType = GetLeptonType_JH(ElColl.at(ie), truthColl);
    if(LepType<0 && LepType>-5) NFk++;
    else if(LepType<-4) NCv++;
    else if(LepType>0){
      int Idx_Closest    = GenMatchedIdx(ElColl.at(ie),truthColl);
      int IdxType_NearEl = LepType>3? GetPrElType_InSameSCRange(Idx_Closest, truthColl, "IdxType"):Idx_Closest;
      int Idx_NearEl     = LepType>3? IdxType_NearEl/10:Idx_Closest;
      if(ElColl.at(ie).Charge()*truthColl.at(Idx_NearEl).PID()>0){ NFlip++; IdxFlipped=ie; }
    }
  }

  int ReturnVal = NFk*1000+NFlip*100+NCv*10+IdxFlipped;

  return ReturnVal;

}



ControlPlots::ControlPlots(){

  TMVA::Tools::Instance();
  MVAReader = new TMVA::Reader();

}


ControlPlots::~ControlPlots(){

  delete MVAReader;
  delete FRFile_El; delete FRFile_Mu; delete CFRFile;
  for(std::map< TString, TH2D* >::iterator mapit = maphist_FR.begin(); mapit!=maphist_FR.end(); mapit++){
    delete mapit->second;
  }
  maphist_FR.clear();
  SysWgtStrPairList.clear();

}


float ControlPlots::GetDataFakeRate(float VarX, float VarY, TString Key, TString Opt){

  bool MuFR = Opt.Contains("Mu"), ElFR = Opt.Contains("El");
  if(MuFR or ElFR){
    if     (MuFR && !FRFile_Mu->GetListOfKeys()->Contains(Key)){ printf("[Error] No %s in MuFR File.\n", Key.Data()); return -1.; }
    else if(ElFR && !FRFile_El->GetListOfKeys()->Contains(Key)){ printf("[Error] No %s in MuFR File.\n", Key.Data()); return -1.; }
  }
  else{ printf("[Error] MuFR/ElFR haven't set.\n"); return -1; }

  std::map<TString, TH2D*>::iterator mapit = maphist_FR.find(Key);
  if(mapit == maphist_FR.end()){ //first usage
    if     (MuFR) maphist_FR[Key] = (TH2D*) ((TH2*) FRFile_Mu->Get(Key))->Clone();
    else if(ElFR) maphist_FR[Key] = (TH2D*) ((TH2*) FRFile_El->Get(Key))->Clone();
  }

  mapit = maphist_FR.find(Key);
  float Xmin = mapit->second->GetXaxis()->GetBinLowEdge(mapit->second->GetXaxis()->GetFirst());
  float Xmax = mapit->second->GetXaxis()->GetBinUpEdge(mapit->second->GetXaxis()->GetLast());
  float Ymin = mapit->second->GetYaxis()->GetBinLowEdge(mapit->second->GetYaxis()->GetFirst());
  float Ymax = mapit->second->GetYaxis()->GetBinUpEdge(mapit->second->GetYaxis()->GetLast());

  if(VarX<Xmin) VarX=Xmin+1E-10;
  if(VarX>Xmax) VarX=Xmax-1E-10;
  if(VarY<Ymin) VarY=Ymin+1E-10;
  if(VarY>Ymax) VarY=Ymax-1E-10;

  float FR = mapit->second->GetBinContent(mapit->second->FindBin(VarX,VarY));
  if(Opt.Contains("Syst")){
    TString SystDirStr  = Opt.Contains("Up")? "Up":Opt.Contains("Down")? "Down":"";
    TString SystTypeStr("Tot");
    if     (Opt.Contains("AwayJetPt") ) SystTypeStr="AwayJetPt";
    else if(Opt.Contains("HasBJet")   ) SystTypeStr="HasBJet";
    else if(Opt.Contains("PromptNorm")) SystTypeStr="PromptNorm";
    TString SystKey(Key); SystKey.ReplaceAll("FR_cent", "FRErr"+SystDirStr+"_"+SystTypeStr);
    if     (MuFR && !FRFile_Mu->GetListOfKeys()->Contains(SystKey)){ printf("[Error] No %s in MuFR File.\n", SystKey.Data()); return -1.; }
    else if(ElFR && !FRFile_El->GetListOfKeys()->Contains(SystKey)){ printf("[Error] No %s in MuFR File.\n", SystKey.Data()); return -1.; }

    std::map<TString, TH2D*>::iterator mapitSyst = maphist_FR.find(SystKey);
    if(mapitSyst == maphist_FR.end()){ //first usage
      if     (MuFR) maphist_FR[SystKey] = (TH2D*) ((TH2*) FRFile_Mu->Get(SystKey))->Clone();
      else if(ElFR) maphist_FR[SystKey] = (TH2D*) ((TH2*) FRFile_El->Get(SystKey))->Clone();
    }
    mapitSyst = maphist_FR.find(SystKey);
    float RelErr = mapitSyst->second->GetBinContent(mapitSyst->second->FindBin(VarX,VarY));
    FR *= (1.+RelErr);
  }

  return FR;
}


float ControlPlots::GetDataFakeWeight(vector<Muon>& MuColl, vector<Electron>& ElColl, TString MuTID, TString ElTID, TString MuFRKey, TString ElFRKey, TString Opt){

  float weight = IsDATA? -1.:1.;
  int NLepLNotT=0; float TightIso= 0.1;
  bool MuFRConePtCut = MuFRKey.Contains("ConePtCut"), ElFRConePtCut=ElFRKey.Contains("ConePtCut");
  for(unsigned int im=0; im<MuColl.size(); im++){
    if(MuColl.at(im).PassID(MuTID)) continue; 
    float PTCorr = MuColl.at(im).CalcPtCone(MuColl.at(im).MiniRelIso(), TightIso);
    float fEta   = fabs(MuColl.at(im).Eta());
    float FR     = GetDataFakeRate(PTCorr, fEta, MuFRKey, "Mu"+Opt);
    if(PTCorr<15 && MuFRConePtCut) FR*=0.6667;
    weight*=-FR/(1.-FR);
    NLepLNotT++;
  }

  for(unsigned int ie=0; ie<ElColl.size(); ie++){
    if(ElColl.at(ie).PassID(ElTID)) continue; 
    float PTCorr = ElColl.at(ie).CalcPtCone(ElColl.at(ie).MiniRelIso(), TightIso);
    float fEta   = fabs(ElColl.at(ie).Eta());
    float FR     = GetDataFakeRate(PTCorr, fEta, ElFRKey, "El"+Opt);
    if(PTCorr<20 && ElFRConePtCut) FR*=0.9;
    weight*=-FR/(1.-FR);
    NLepLNotT++;
  }
  if(NLepLNotT==0) weight=0.;

  return weight;
}


float ControlPlots::GetCFRAndSF(float VarX, float VarY, TString Key, TString Opt){

  if(!CFRFile->GetListOfKeys()->Contains(Key)){ printf("[Error] No %s in CFR File.\n", Key.Data()); return -1.; }
  map<TString, TH2D*>::iterator mapit = maphist_FR.find(Key);
  if(mapit == maphist_FR.end()){ //first usage
    maphist_FR[Key] = (TH2D*) ((TH2*) CFRFile->Get(Key))->Clone();
    mapit = maphist_FR.find(Key);
  }

  float Xmin = mapit->second->GetXaxis()->GetBinLowEdge(mapit->second->GetXaxis()->GetFirst());
  float Xmax = mapit->second->GetXaxis()->GetBinUpEdge(mapit->second->GetXaxis()->GetLast());
  float Ymin = mapit->second->GetYaxis()->GetBinLowEdge(mapit->second->GetYaxis()->GetFirst());
  float Ymax = mapit->second->GetYaxis()->GetBinUpEdge(mapit->second->GetYaxis()->GetLast());

  if(VarX<Xmin) VarX=Xmin+1E-10;
  if(VarX>Xmax) VarX=Xmax-1E-10;
  if(VarY<Ymin) VarY=Ymin+1E-10;
  if(VarY>Ymax) VarY=Ymax-1E-10;

  float CFR = mapit->second->GetBinContent(mapit->second->FindBin(VarX,VarY));
  float Err = mapit->second->GetBinError(mapit->second->FindBin(VarX,VarY));
  if(Opt.Contains("Syst")){
    int SystDir = Opt.Contains("Up")? 1:Opt.Contains("Down")? -1:0;
    CFR+= ((float) SystDir)*Err;
  }
  return CFR;

}


float ControlPlots::GetCFRWeight(vector<Electron>& ElColl, TString Option){

  float SumCFR=0.;
  for(unsigned int ie=0; ie<ElColl.size(); ie++){
    float PT = ElColl.at(ie).Pt(), fEta = fabs(ElColl.at(ie).Eta());
    float MCCFR = GetCFRAndSF(PT, fEta, "hCFR_MCFine_PTfEta", Option);
    float SF    = GetCFRAndSF(PT, fEta, "hCFR_sf_Var", Option);
    SumCFR+=MCCFR*SF;
  }

  return SumCFR;
}




void ControlPlots::InitializeReader(){

  MVAReader->AddVariable("Nj"      , &Nj      );
  MVAReader->AddVariable("Nb"      , &Nb      );
  MVAReader->AddVariable("Ptl1"    , &Ptl1    );
  MVAReader->AddVariable("Ptl2"    , &Ptl2    );
  MVAReader->AddVariable("Ptj1"    , &Ptj1    );
  MVAReader->AddVariable("Ptj2"    , &Ptj2    );
  MVAReader->AddVariable("Ptj3"    , &Ptj3    );
  MVAReader->AddVariable("HT"      , &HT      );
  MVAReader->AddVariable("MET2HT"  , &MET2HT  );
  MVAReader->AddVariable("dRll"    , &dRll    );
  MVAReader->AddVariable("dRlj11"  , &dRlj11  );
  MVAReader->AddVariable("dRlj12"  , &dRlj12  );
  MVAReader->AddVariable("dRlj13"  , &dRlj13  );
  MVAReader->AddVariable("dRlj21"  , &dRlj21  );
  MVAReader->AddVariable("dRlj22"  , &dRlj22  );
  MVAReader->AddVariable("dRlj23"  , &dRlj23  );
  MVAReader->AddVariable("MSSSF"   , &MSSSF   );
  MVAReader->AddVariable("MTvl1"   , &MTvl1   );
  MVAReader->AddVariable("MTvl2"   , &MTvl2   );
  MVAReader->AddVariable("MllW_2jL", &MllW_2jL);
  MVAReader->AddVariable("MllW_1jL", &MllW_1jL);
  MVAReader->AddVariable("Ml1W_2jL", &Ml1W_2jL);
  MVAReader->AddVariable("Ml1W_1jL", &Ml1W_1jL);
  MVAReader->AddVariable("Ml2W_2jL", &Ml2W_2jL);
  MVAReader->AddVariable("Ml2W_1jL", &Ml2W_1jL);
  MVAReader->AddVariable("MllW1_H" , &MllW1_H );
  MVAReader->AddVariable("Ml1W1_H" , &Ml1W1_H );
  MVAReader->AddVariable("Ml2W1_H" , &Ml2W1_H );

  TString AnalyzerPath=std::getenv("SKFlat_WD"), MVAPath="/data/Run2UltraLegacy_v3/2017/MVAClassifier/";
  //TString AnalyzerPath=std::getenv("SKFlat_WD"), MVAPath="/data/Run2UltraLegacy_v2/"+TString::Itoa(DataYear,10)+"/MVAClassifier/";
  MNStrList = {"20", "50", "75", "100"};
  for(unsigned int im=0; im<MNStrList.size(); im++){
    TString FileName_Mu="TMVAClassification_MN"+MNStrList.at(im)+"_Mu_BDTG.weights.xml"; 
    TString FileName_El="TMVAClassification_MN"+MNStrList.at(im)+"_El_BDTG.weights.xml"; 
    TString MVATagStr_Mu = "BDTG_MN"+MNStrList.at(im)+"_Mu";
    TString MVATagStr_El = "BDTG_MN"+MNStrList.at(im)+"_El";
    MVAReader->BookMVA(MVATagStr_Mu, AnalyzerPath+MVAPath+FileName_Mu);
    MVAReader->BookMVA(MVATagStr_El, AnalyzerPath+MVAPath+FileName_El);
  }
}

