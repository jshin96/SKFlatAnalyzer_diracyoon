#include "ControlPlots.h"

void ControlPlots::initializeAnalyzer(){

  TriLep=false, TetraLep=false, SS2l=false, OS2l=false;
  TopBSrc=false, SB_SS2L=false, SB_OS2L=false, CFlip=false, ConvCR=false, FkCR3l=false;
  ConvSrcDep=false, TrigClos=false, TypeFRCheck=false;
  FakeRun=false, ConvRun=false, FlipRun=false, SystRun=false; 
  for(unsigned int i=0; i<Userflags.size(); i++){
    if(Userflags.at(i).Contains("SS2l"))        SS2l        = true;
    if(Userflags.at(i).Contains("TriLep"))      TriLep      = true;
    if(Userflags.at(i).Contains("TetraLep"))    TetraLep    = true; 
    if(Userflags.at(i).Contains("OS2l"))        OS2l        = true;
    if(Userflags.at(i).Contains("SB_SS2L"))     SB_SS2L     = true;
    if(Userflags.at(i).Contains("SB_OS2L"))     SB_OS2L     = true;
    if(Userflags.at(i).Contains("TopBSrc"))     TopBSrc     = true;
    if(Userflags.at(i).Contains("CFlip"))       CFlip       = true;
    if(Userflags.at(i).Contains("FkCR3l"))      FkCR3l      = true;
    if(Userflags.at(i).Contains("ConvCR"))      ConvCR      = true;
    if(Userflags.at(i).Contains("ConvSrcDep"))  ConvSrcDep  = true;
    if(Userflags.at(i).Contains("TrigClos"))    TrigClos    = true;
    if(Userflags.at(i).Contains("TypeFRCheck")) TypeFRCheck = true;
    if(Userflags.at(i).Contains("FakeRun"))     FakeRun     = true; 
    if(Userflags.at(i).Contains("ConvRun"))     ConvRun     = true; 
    if(Userflags.at(i).Contains("FlipRun"))     FlipRun     = true; 
    if(Userflags.at(i).Contains("SystRun"))     SystRun     = true; 
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
    w_GenNorm = ev.MCweight()*weight_norm_1invpb*GetKFactor()*ev.GetTriggerLumi("Full");
    w_BR      = GetBRWeight();
    w_PU      = GetPileUpWeight(nPileUp, 0);
    weight *= w_GenNorm * w_BR * w_PU;
  }
  FillHist("CutFlow", 0., weight, 20, 0., 20.);

  bool PassTrig=false;
  if(TetraLep or TriLep){
    if(!IsDATA) PassTrig = ev.PassTrigger(TrigList_DblMu) or ev.PassTrigger(TrigList_DblEG);
    else{
      //1PD for 1FS
      if     (DblMu) PassTrig = ev.PassTrigger(TrigList_DblMu);
      else if(DblEG) PassTrig = ev.PassTrigger(TrigList_DblEG);
      else if(MuEG)  PassTrig = ev.PassTrigger(TrigList_MuEG);
      else if(SglEl) PassTrig = !ev.PassTrigger(TrigList_DblEG) and ev.PassTrigger(TrigList_SglEl);
      //TrigSoup
      //if     (MuEG)  PassTrig = ev.PassTrigger(TrigList_MuEG);
      //else if(DblMu) PassTrig = (!ev.PassTrigger(TrigList_MuEG)) and ev.PassTrigger(TrigList_DblMu);
      //else if(DblEG) PassTrig = (!(ev.PassTrigger(TrigList_MuEG) or ev.PassTrigger(TrigList_DblMu))) and ev.PassTrigger(TrigList_DblEG);
    }
  }
  else if(SS2l or OS2l){
    if(!IsDATA) PassTrig = ev.PassTrigger(TrigList_DblMu) or ev.PassTrigger(TrigList_DblEG) or ev.PassTrigger(TrigList_MuEG);
    else{
      if     (DblMu) PassTrig = ev.PassTrigger(TrigList_DblMu);
      else if(DblEG) PassTrig = ev.PassTrigger(TrigList_DblEG);
      else if(MuEG)  PassTrig = ev.PassTrigger(TrigList_MuEG);
    }
  }
  if(TrigClos or TypeFRCheck) PassTrig=true;
  if(!PassTrig) return;
  FillHist("CutFlow", 1., weight, 20, 0., 20.);
  if(!PassMETFilter()) return;
  FillHist("CutFlow", 2., weight, 20, 0., 20.);

  bool PreCutPass=false;
  vector<Muon>     muonPreColl     = GetMuons("NOCUT", 5., 2.4);
  vector<Electron> electronPreColl = GetElectrons("NOCUT", 5., 2.5);
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
  if(TypeFRCheck && electronPreColl.size()>0) PreCutPass=true;
  if(!PreCutPass) return;


  TString IDSSLabel = "SS";
  //TString MuTID = "TopHNT", MuLID = "TopHNLLIsop6SIP5", MuVID="TopHNV";
  TString MuTID = "TopHNT", MuLID = "TopHNLLIsop6SIP5", MuVID=MuLID;
  TString ElTID = "TopHN17SST", ElLID = "TopHNSSNM01LFixLMVAIsop4NoSIP_"+GetEraShort(), ElVID = "TopHNV";  
  //TString ElTID = "TopHN17SST", ElLID = "TopHNSSNM01LFixLMVAIsop4NoSIP_"+GetEraShort(), ElVID = ElLID;  
  vector<Muon>     muonTightColl     = SelectMuons    (muonPreColl    , FakeRun? MuLID:MuTID, 10., 2.4);
  vector<Electron> electronTightColl = SelectElectrons(electronPreColl, FakeRun? ElLID:ElTID, 15., 2.5);
  vector<Muon>     muonLooseColl     = SelectMuons    (muonPreColl    , MuLID, 10., 2.4);
  vector<Electron> electronLooseColl = SelectElectrons(electronPreColl, ElLID, 15., 2.5);
  vector<Muon>     muonVetoColl      = SelectMuons    (muonPreColl    , MuVID, 10., 2.4);
  vector<Electron> electronVetoColl  = SelectElectrons(electronPreColl, ElVID, 10., 2.5);


  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
  vector<Jet> jetPreColl = GetAllJets();
  sort(jetPreColl.begin(), jetPreColl.end(), PtComparing);
  vector<Jet> jetColl  = SelectJets(jetPreColl, muonLooseColl, electronVetoColl, "tight", 25., 2.4, "LVeto");
  vector<Jet> bjetColl = SelBJets(jetColl, param_jets);


  Particle vMET_T1xy = GetvMET("T1xyCorr");

  bool FillGenColl=!IsDATA && (ConvRun or FakeRun or FlipRun or TypeFRCheck);
  if(FillGenColl) truthColl=GetGens(); 


  bool EventCand = false;
  if(SS2l or OS2l){ EventCand = (muonLooseColl.size()+electronLooseColl.size())==2; }
  if(TriLep){ EventCand = (muonLooseColl.size()+electronLooseColl.size())==3; }
  if(TetraLep){ EventCand = (muonLooseColl.size()+electronLooseColl.size())>3; }
  if(TypeFRCheck) EventCand=true;

  float w_TopPtRW = 1., w_Prefire = 1., sf_Trig = 1., w_FR=1.;
  float sf_MuTk = 1., sf_MuID = 1., sf_MuIso = 1., sf_ElReco = 1., sf_ElID = 1., sf_BTag = 1.;
  float w_CF = 1., w_CV = 1.;
  if((!IsDATA) and EventCand){
    //if(MCSample.Contains("TT") and MCSample.Contains("powheg")) truthColl = GetGens();
    //w_TopPtRW = mcCorr->GetTopPtReweight(truthColl);
    sf_MuID   = GetMuonSF(muonTightColl, MuTID, "ID");
    sf_ElReco = GetElectronSF(electronLooseColl, "", "Reco");
    sf_ElID   = GetElectronSF(electronTightColl, ElTID, "ID");
    sf_BTag   = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets);
    //ElKey: DiElIso_HNTopID17SS DiElIso_HNTopIDSS  //MuKey: DiMuIso_HNTopID
    int NEl = electronTightColl.size(), NMu = muonTightColl.size();
    TString TrSFKey = NMu>1? "DiMuIso_HNTopID":NEl>1? "DiElIso_HNTopID17SS":"";
    bool ApplyTrSF = TrSFKey!="" && (SS2l or OS2l or TriLep) && (!TrigClos);
    sf_Trig   = ApplyTrSF? mcCorr->GetTriggerSF(electronTightColl, muonTightColl, TrSFKey, ""):1.;
    w_Prefire = GetPrefireWeight(0);
    if(FlipRun && !FakeRun) w_CF = GetCFRWeight(electronTightColl, "");
    //if(     ConvRun       ) w_CV = GetConvSF(ElTID, 0); 
  }
  if(FakeRun && EventCand){
    w_FR = GetDataFakeWeight(muonLooseColl, electronLooseColl, MuTID, ElTID, "FR_cent_"+MuTID+"_"+MuLID, "FR_cent_"+ElTID+"_"+ElLID+"_Pt15", "");
  }
  weight *= w_TopPtRW * w_Prefire * sf_Trig; 
  weight *= sf_MuTk * sf_MuID * sf_MuIso * sf_ElReco * sf_ElID * sf_BTag * w_CV * w_CF * w_FR;
  //cout<<" w_PU:"<<w_PU<<" w_Prefire:"<<w_Prefire<<" sf_Trig:"<<sf_Trig<<endl;
  //cout<<" sfIDMu:"<<sf_MuID<<" sfIsoMu:"<<sf_MuIso<<" sfRecEl:"<<sf_ElReco<<" sfIDEl:"<<sf_ElID<<" sfBTag:"<<sf_BTag<<endl;

  if(TrigClos){
    CheckTrigMCClos(muonTightColl, muonVetoColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET_T1xy, ev, weight, "");
  }
  if(TypeFRCheck){
    vector<double> PTEdges   = {15, 20, 30, 50, 100};
    vector<double> fEtaEdges = {0., 0.8, 1.5, 2.5};
    for(unsigned int ie=0; ie<electronLooseColl.size() && !IsDATA; ie++){
      Electron* El = &electronLooseColl.at(ie);
      float PT = El->Pt(), Eta = El->Eta(), fEta = fabs(Eta);
      int LepType = GetLeptonType_JH(*El, truthColl);
      TString TypeStr="";
      if(LepType<0 && LepType>-5) TypeStr="_HFk";
      else if(LepType<-4) TypeStr="_ExCv";
      else if(LepType>0){
        int Idx_Closest    = GenMatchedIdx(*El,truthColl); 
        int IdxType_NearEl = LepType>3? GetPrElType_InSameSCRange(Idx_Closest, truthColl, "IdxType"):Idx_Closest;
        int Idx_NearEl     = LepType>3? IdxType_NearEl/10:Idx_Closest;
        if(El->Charge()*truthColl.at(Idx_NearEl).PID()>0) TypeStr = LepType==3? "_PrTaCF":"_PrCF";
        else                                              TypeStr = LepType==3? "_PrTa":"_Pr";
      }
      FillHist("NElL_PTfEta"+TypeStr, PT, fEta, weight, PTEdges.size()-1, &PTEdges[0], fEtaEdges.size()-1, &fEtaEdges[0]);
      if(El->PassID(ElTID)){
        FillHist("NElT_PTfEta"+TypeStr, PT, fEta, weight, PTEdges.size()-1, &PTEdges[0], fEtaEdges.size()-1, &fEtaEdges[0]);
      }
      
      int it_cut=0; FillHist("IDCutFlow"+TypeStr, it_cut, weight, 10, 0., 10.);
      if(!El->passMVAID_noIso_WP90()) continue;
      it_cut++; FillHist("IDCutFlow"+TypeStr, it_cut, weight, 10, 0., 10.);
      if(!(El->MiniRelIso()<0.1)    ) continue;
      it_cut++; FillHist("IDCutFlow"+TypeStr, it_cut, weight, 10, 0., 10.);
      if(!(El->SIP3D()<4.)          ) continue;
      it_cut++; FillHist("IDCutFlow"+TypeStr, it_cut, weight, 10, 0., 10.);
    }
  }
  if(OS2l){
    if(SB_OS2L){
      PlotTop2LCR_OS2L(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
                       jetColl, bjetColl, vMET_T1xy, weight, "");
    }
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
    if(TopBSrc){ CheckTopBSrc(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
                              jetColl, bjetColl, vMET_T1xy, weight, ""); }
    if(ConvSrcDep){ CheckConvSrcDep(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
                                    jetColl, bjetColl, vMET_T1xy, weight, ""); }
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
  if( SystRun && ((!IsDATA && !(FakeRun)) or (IsDATA && FakeRun)) ){
    vector<Electron> ElCFPT1UpTColl = SelectElectrons(electronPreColl, FakeRun? ElLID:ElTID, 15., 2.5, "SystCFPT1Up");
    vector<Electron> ElCFPT1UpLColl = SelectElectrons(electronPreColl, ElLID, 15., 2.5, "SystCFPT1Up");
    vector<Electron> ElCFPT2UpTColl = SelectElectrons(electronPreColl, FakeRun? ElLID:ElTID, 15., 2.5, "SystCFPT2Up");
    vector<Electron> ElCFPT2UpLColl = SelectElectrons(electronPreColl, ElLID, 15., 2.5, "SystCFPT2Up");
    vector<Electron> ElCFPT1DownTColl = SelectElectrons(electronPreColl, FakeRun? ElLID:ElTID, 15., 2.5, "SystCFPT1Down");
    vector<Electron> ElCFPT1DownLColl = SelectElectrons(electronPreColl, ElLID, 15., 2.5, "SystCFPT1Down");
    vector<Electron> ElCFPT2DownTColl = SelectElectrons(electronPreColl, FakeRun? ElLID:ElTID, 15., 2.5, "SystCFPT2Down");
    vector<Electron> ElCFPT2DownLColl = SelectElectrons(electronPreColl, ElLID, 15., 2.5, "SystCFPT2Down");
    vector<Jet> jetJESUpColl    = SelectJets(jetPreColl, muonLooseColl, electronVetoColl, "tight", 25., 2.4, "LVetoSystJESUp");
    vector<Jet> jetJESDownColl  = SelectJets(jetPreColl, muonLooseColl, electronVetoColl, "tight", 25., 2.4, "LVetoSystJESDown");
    vector<Jet> jetJERUpColl    = SelectJets(jetPreColl, muonLooseColl, electronVetoColl, "tight", 25., 2.4, "LVetoSystJERUp");
    vector<Jet> jetJERDownColl  = SelectJets(jetPreColl, muonLooseColl, electronVetoColl, "tight", 25., 2.4, "LVetoSystJERDown");
    vector<Jet> bjetJESUpColl   = SelBJets(jetJESUpColl, param_jets);
    vector<Jet> bjetJESDownColl = SelBJets(jetJESDownColl, param_jets);
    vector<Jet> bjetJERUpColl   = SelBJets(jetJERUpColl, param_jets);
    vector<Jet> bjetJERDownColl = SelBJets(jetJERDownColl, param_jets);
    Particle vMET_T1xy_JESUp    = GetvMET("T1xyCorr", "SystUpJES");
    Particle vMET_T1xy_JESDown  = GetvMET("T1xyCorr", "SystDownJES");
    Particle vMET_T1xy_JERUp    = GetvMET("T1xyCorr", "SystUpJER");
    Particle vMET_T1xy_JERDown  = GetvMET("T1xyCorr", "SystDownJER");
    Particle vMET_T1xy_UnclUp   = GetvMET("T1xyCorr", "SystUpUncl");
    Particle vMET_T1xy_UnclDown = GetvMET("T1xyCorr", "SystDownUncl");

    float w_PUUp=1., w_PUDown=1., w_PrefireUp=1., w_PrefireDown=1.;
    float w_FRUp=1., w_FRDown=1., w_CFUp=1., w_CFDown=1., w_FrCF1=0., w_FrCF2=0.;
    float sf_ElRecoUp=1., sf_ElRecoDown=1.;
    float sf_BTag_JESUp=1., sf_BTag_JESDown=1., sf_BTag_JERUp=1., sf_BTag_JERDown=1.;
    float sf_BTag_LTagUp=1., sf_BTag_LTagDown=1., sf_BTag_HTagUp=1., sf_BTag_HTagDown=1.;
    if(!IsDATA && EventCand){
      w_PrefireUp   = GetPrefireWeight(1), w_PrefireDown = GetPrefireWeight(-1);
      w_PUUp        = GetPileUpWeight(nPileUp, 1);
      w_PUDown      = GetPileUpWeight(nPileUp,-1);
      sf_ElRecoUp   = GetElectronSF(electronTightColl, "", "RecoSystUp");
      sf_ElRecoDown = GetElectronSF(electronTightColl, "", "RecoSystDown");
      sf_BTag_JESUp    = mcCorr->GetBTaggingReweight_1a(jetJESUpColl, param_jets);
      sf_BTag_JESDown  = mcCorr->GetBTaggingReweight_1a(jetJESDownColl, param_jets);
      sf_BTag_JERUp    = mcCorr->GetBTaggingReweight_1a(jetJERUpColl, param_jets);
      sf_BTag_JERDown  = mcCorr->GetBTaggingReweight_1a(jetJERDownColl, param_jets);
      sf_BTag_LTagUp   = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets, "SystUpLTag");
      sf_BTag_LTagDown = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets, "SystDownLTag");
      sf_BTag_HTagUp   = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets, "SystUpHTag");
      sf_BTag_HTagDown = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets, "SystDownHTag");
      if(FlipRun && !FakeRun){
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

    float w_base = w_GenNorm * w_BR * w_TopPtRW * sf_MuTk * sf_MuID * sf_MuIso * sf_ElID * sf_Trig * w_CV;
    float weight_PUUp        = w_base * w_PUUp   * w_Prefire     * w_CF     * w_FR     * sf_ElReco     * sf_BTag;
    float weight_PUDown      = w_base * w_PUDown * w_Prefire     * w_CF     * w_FR     * sf_ElReco     * sf_BTag;
    float weight_PrefireUp   = w_base * w_PU     * w_PrefireUp   * w_CF     * w_FR     * sf_ElReco     * sf_BTag;
    float weight_PrefireDown = w_base * w_PU     * w_PrefireDown * w_CF     * w_FR     * sf_ElReco     * sf_BTag;
    float weight_CFUp        = w_base * w_PU     * w_Prefire     * w_CFUp   * w_FR     * sf_ElReco     * sf_BTag;
    float weight_CFDown      = w_base * w_PU     * w_Prefire     * w_CFDown * w_FR     * sf_ElReco     * sf_BTag;
    float weight_FRUp        = w_base * w_PU     * w_Prefire     * w_CF     * w_FRUp   * sf_ElReco     * sf_BTag;
    float weight_FRDown      = w_base * w_PU     * w_Prefire     * w_CF     * w_FRDown * sf_ElReco     * sf_BTag;
    float weight_ElRecoUp    = w_base * w_PU     * w_Prefire     * w_CF     * w_FR     * sf_ElRecoUp   * sf_BTag;
    float weight_ElRecoDown  = w_base * w_PU     * w_Prefire     * w_CF     * w_FR     * sf_ElRecoDown * sf_BTag;
    float weight_JESUp       = w_base * w_PU     * w_Prefire     * w_CF     * w_FR     * sf_ElReco     * sf_BTag_JESUp;
    float weight_JESDown     = w_base * w_PU     * w_Prefire     * w_CF     * w_FR     * sf_ElReco     * sf_BTag_JESDown;
    float weight_JERUp       = w_base * w_PU     * w_Prefire     * w_CF     * w_FR     * sf_ElReco     * sf_BTag_JERUp;
    float weight_JERDown     = w_base * w_PU     * w_Prefire     * w_CF     * w_FR     * sf_ElReco     * sf_BTag_JERDown;
    float weight_LTagUp      = w_base * w_PU     * w_Prefire     * w_CF     * w_FR     * sf_ElReco     * sf_BTag_LTagUp;
    float weight_LTagDown    = w_base * w_PU     * w_Prefire     * w_CF     * w_FR     * sf_ElReco     * sf_BTag_LTagDown;
    float weight_HTagUp      = w_base * w_PU     * w_Prefire     * w_CF     * w_FR     * sf_ElReco     * sf_BTag_HTagUp;
    float weight_HTagDown    = w_base * w_PU     * w_Prefire     * w_CF     * w_FR     * sf_ElReco     * sf_BTag_HTagDown;

    if(SB_SS2L){
      if(!IsDATA && !FakeRun && !FlipRun){
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_PUUp, "_SystUp_PU");
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_PUDown, "_SystDown_PU");
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_PrefireUp, "_SystUp_Pref");
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_PrefireDown, "_SystDown_Pref");
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_ElRecoUp, "_SystUp_ElReco");
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_ElRecoDown, "_SystDown_ElReco");
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetJESUpColl, bjetJESUpColl, vMET_T1xy_JESUp, weight_JESUp, "_SystUp_JES");
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetJESDownColl, bjetJESDownColl, vMET_T1xy_JESDown, weight_JESDown, "_SystDown_JES");
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetJERUpColl, bjetJERUpColl, vMET_T1xy_JERUp, weight_JERUp, "_SystUp_JER");
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetJERDownColl, bjetJERDownColl, vMET_T1xy_JERDown, weight_JERDown, "_SystDown_JER");
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy_UnclUp, weight, "_SystUp_Uncl");
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy_UnclDown, weight, "_SystDown_Uncl");
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_LTagUp, "_SystUp_LTag");
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_LTagDown, "_SystDown_LTag");
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_HTagUp, "_SystUp_HTag");
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_HTagDown, "_SystDown_HTag");
      }
      else if(!IsDATA && FlipRun){
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_CFUp, "_SystUp_CF");
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_CFDown, "_SystDown_CF");
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, ElCFPT1UpTColl, ElCFPT1UpLColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight*w_FrCF1, "_SystUp_CFPT");
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, ElCFPT1DownTColl, ElCFPT1DownLColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight*w_FrCF1, "_SystDown_CFPT");
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, ElCFPT2UpTColl, ElCFPT2UpLColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight*w_FrCF2, "_SystUp_CFPT");
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, ElCFPT2DownTColl, ElCFPT2DownLColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight*w_FrCF2, "_SystDown_CFPT");
      }
      else if(FakeRun){
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_FRUp, "_SystUp_FR");
        MakePlotSS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_FRDown, "_SystDown_FR");
      }
    }
    if(OS2l && SB_OS2L){
      if(!IsDATA && !FakeRun){
        PlotTop2LCR_OS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_PUUp, "_SystUp_PU");
        PlotTop2LCR_OS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_PUDown, "_SystDown_PU");
        PlotTop2LCR_OS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_PrefireUp, "_SystUp_Pref");
        PlotTop2LCR_OS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_PrefireDown, "_SystDown_Pref");
        PlotTop2LCR_OS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_ElRecoUp, "_SystUp_ElReco");
        PlotTop2LCR_OS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_ElRecoDown, "_SystDown_ElReco");
        PlotTop2LCR_OS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetJESUpColl, bjetJESUpColl, vMET_T1xy_JESUp, weight_JESUp, "_SystUp_JES");
        PlotTop2LCR_OS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetJESDownColl, bjetJESDownColl, vMET_T1xy_JESDown, weight_JESDown, "_SystDown_JES");
        PlotTop2LCR_OS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetJERUpColl, bjetJERUpColl, vMET_T1xy_JERUp, weight_JERUp, "_SystUp_JER");
        PlotTop2LCR_OS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetJERDownColl, bjetJERDownColl, vMET_T1xy_JERDown, weight_JERDown, "_SystDown_JER");
        PlotTop2LCR_OS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy_UnclUp, weight, "_SystUp_Uncl");
        PlotTop2LCR_OS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy_UnclDown, weight, "_SystDown_Uncl");
        PlotTop2LCR_OS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_LTagUp, "_SystUp_LTag");
        PlotTop2LCR_OS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_LTagDown, "_SystDown_LTag");
        PlotTop2LCR_OS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_HTagUp, "_SystUp_HTag");
        PlotTop2LCR_OS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy, weight_HTagDown, "_SystDown_HTag");
      }
      else if(FakeRun){
          PlotTop2LCR_OS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                       jetColl, bjetColl, vMET_T1xy, weight_FRUp, "_SystUp_FR");
          PlotTop2LCR_OS2L(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                       jetColl, bjetColl, vMET_T1xy, weight_FRDown, "_SystDown_FR");
      }
    }

    if(FkCR3l){
      if(!IsDATA && !FakeRun){
        CheckFkCR3l(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy, ev, weight_PUUp, "_SystUp_PU");
        CheckFkCR3l(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy, ev, weight_PUDown, "_SystDown_PU");
        CheckFkCR3l(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy, ev, weight_PrefireUp, "_SystUp_Pref");
        CheckFkCR3l(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy, ev, weight_PrefireDown, "_SystDown_Pref");
        CheckFkCR3l(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy, ev, weight_ElRecoUp, "_SystUp_ElReco");
        CheckFkCR3l(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy, ev, weight_ElRecoDown, "_SystDown_ElReco");
        CheckFkCR3l(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetJESUpColl, bjetJESUpColl, vMET_T1xy_JESUp, ev, weight_JESUp, "_SystUp_JES");
        CheckFkCR3l(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetJESDownColl, bjetJESDownColl, vMET_T1xy_JESDown, ev, weight_JESDown, "_SystDown_JES");
        CheckFkCR3l(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetJERUpColl, bjetJERUpColl, vMET_T1xy_JERUp, ev, weight_JERUp, "_SystUp_JER");
        CheckFkCR3l(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetJERDownColl, bjetJERDownColl, vMET_T1xy_JERDown, ev, weight_JERDown, "_SystDown_JER");
        CheckFkCR3l(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy_UnclUp, ev, weight, "_SystUp_Uncl");
        CheckFkCR3l(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy_UnclDown, ev, weight, "_SystDown_Uncl");
        CheckFkCR3l(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy, ev, weight_LTagUp, "_SystUp_LTag");
        CheckFkCR3l(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy, ev, weight_LTagDown, "_SystDown_LTag");
        CheckFkCR3l(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy, ev, weight_HTagUp, "_SystUp_HTag");
        CheckFkCR3l(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy, ev, weight_HTagDown, "_SystDown_HTag");
      }
      else if(FakeRun){
          CheckFkCR3l(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                      jetColl, bjetColl, vMET_T1xy, ev, weight_FRUp, "_SystUp_FR");
          CheckFkCR3l(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                      jetColl, bjetColl, vMET_T1xy, ev, weight_FRDown, "_SystDown_FR");
      }
    }
    if(ConvCR){
      if(!IsDATA && !FakeRun){
        CheckConvCR(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy, ev, weight_PUUp, "_SystUp_PU");
        CheckConvCR(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy, ev, weight_PUDown, "_SystDown_PU");
        CheckConvCR(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy, ev, weight_PrefireUp, "_SystUp_Pref");
        CheckConvCR(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy, ev, weight_PrefireDown, "_SystDown_Pref");
        CheckConvCR(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy, ev, weight_ElRecoUp, "_SystUp_ElReco");
        CheckConvCR(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy, ev, weight_ElRecoDown, "_SystDown_ElReco");
        CheckConvCR(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetJESUpColl, bjetJESUpColl, vMET_T1xy_JESUp, ev, weight_JESUp, "_SystUp_JES");
        CheckConvCR(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetJESDownColl, bjetJESDownColl, vMET_T1xy_JESDown, ev, weight_JESDown, "_SystDown_JES");
        CheckConvCR(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetJERUpColl, bjetJERUpColl, vMET_T1xy_JERUp, ev, weight_JERUp, "_SystUp_JER");
        CheckConvCR(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetJERDownColl, bjetJERDownColl, vMET_T1xy_JERDown, ev, weight_JERDown, "_SystDown_JER");
        CheckConvCR(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy_UnclUp, ev, weight, "_SystUp_Uncl");
        CheckConvCR(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy_UnclDown, ev, weight, "_SystDown_Uncl");
        CheckConvCR(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy, ev, weight_LTagUp, "_SystUp_LTag");
        CheckConvCR(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy, ev, weight_LTagDown, "_SystDown_LTag");
        CheckConvCR(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy, ev, weight_HTagUp, "_SystUp_HTag");
        CheckConvCR(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                    jetColl, bjetColl, vMET_T1xy, ev, weight_HTagDown, "_SystDown_HTag");
      }
      else if(FakeRun){
          CheckConvCR(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                      jetColl, bjetColl, vMET_T1xy, ev, weight_FRUp, "_SystUp_FR");
          CheckConvCR(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                      jetColl, bjetColl, vMET_T1xy, ev, weight_FRDown, "_SystDown_FR");
      }
    }
    if(CFlip){
      if(!IsDATA && !FakeRun && !FlipRun){
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                        jetColl, bjetColl, vMET_T1xy, weight_PUUp, "_SystUp_PU");
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                        jetColl, bjetColl, vMET_T1xy, weight_PUDown, "_SystDown_PU");
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                        jetColl, bjetColl, vMET_T1xy, weight_PrefireUp, "_SystUp_Pref");
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                        jetColl, bjetColl, vMET_T1xy, weight_PrefireDown, "_SystDown_Pref");
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                        jetColl, bjetColl, vMET_T1xy, weight_ElRecoUp, "_SystUp_ElReco");
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                        jetColl, bjetColl, vMET_T1xy, weight_ElRecoDown, "_SystDown_ElReco");
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                        jetJESUpColl, bjetJESUpColl, vMET_T1xy_JESUp, weight_JESUp, "_SystUp_JES");
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                        jetJESDownColl, bjetJESDownColl, vMET_T1xy_JESDown, weight_JESDown, "_SystDown_JES");
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                        jetJERUpColl, bjetJERUpColl, vMET_T1xy_JERUp, weight_JERUp, "_SystUp_JER");
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                        jetJERDownColl, bjetJERDownColl, vMET_T1xy_JERDown, weight_JERDown, "_SystDown_JER");
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                        jetColl, bjetColl, vMET_T1xy_UnclUp, weight, "_SystUp_Uncl");
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                        jetColl, bjetColl, vMET_T1xy_UnclDown, weight, "_SystDown_Uncl");
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                        jetColl, bjetColl, vMET_T1xy, weight_LTagUp, "_SystUp_LTag");
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                        jetColl, bjetColl, vMET_T1xy, weight_LTagDown, "_SystDown_LTag");
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                        jetColl, bjetColl, vMET_T1xy, weight_HTagUp, "_SystUp_HTag");
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                        jetColl, bjetColl, vMET_T1xy, weight_HTagDown, "_SystDown_HTag");
      }
      else if(!IsDATA && FlipRun){
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                        jetColl, bjetColl, vMET_T1xy, weight_CFUp, "_SystUp_CF");
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                        jetColl, bjetColl, vMET_T1xy, weight_CFDown, "_SystDown_CF");
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, ElCFPT1DownTColl, ElCFPT1DownLColl, electronVetoColl,
                        jetColl, bjetColl, vMET_T1xy, weight*w_FrCF1, "_SystUp_CFPT");
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, ElCFPT1DownTColl, ElCFPT1DownLColl, electronVetoColl,
                        jetColl, bjetColl, vMET_T1xy, weight*w_FrCF1, "_SystDown_CFPT");
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, ElCFPT2DownTColl, ElCFPT2DownLColl, electronVetoColl,
                        jetColl, bjetColl, vMET_T1xy, weight*w_FrCF2, "_SystUp_CFPT");
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, ElCFPT2DownTColl, ElCFPT2DownLColl, electronVetoColl,
                        jetColl, bjetColl, vMET_T1xy, weight*w_FrCF2, "_SystDown_CFPT");
      }
      else if(FakeRun){
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                        jetColl, bjetColl, vMET_T1xy, weight_FRUp, "_SystUp_FR");
        CheckChargeFlip(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                        jetColl, bjetColl, vMET_T1xy, weight_FRDown, "_SystDown_FR");
      }
    }
  }
}


void ControlPlots::CheckTrigMCClos(vector<Muon>& MuTColl, vector<Muon>& MuVColl, vector<Electron>& ElTColl, vector<Electron>& ElVColl,
                                   vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& Ev, float weight, TString Label)
{
  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  if( !(NMuT==NMuV && NElT==NElV) ) return;
  if(NMuT==2 && NElT==0){
    if( abs(SumCharge(MuTColl))!=0 ) return;
    bool Acc_2MTr = MuTColl.at(0).Pt()>20 && MuTColl.at(1).Pt()>10 && (MuTColl.at(0)+MuTColl.at(1)).M()>4;
    if(!Acc_2MTr) return;
    float Eff_2MTr_MC = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "DiMuIso_HNTopID", false, "");
    float Eff_2MTr_RD = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "DiMuIso_HNTopID", true, "");
    FillHist("NCnt_2MTr_2M"+Label, 0., weight, 1, 0., 1.);
    FillHist("NTrCnt_MCExp_2MTr_2M"+Label, 0., weight*Eff_2MTr_MC, 1, 0., 1.);
    FillHist("NTrCnt_RDExp_2MTr_2M"+Label, 0., weight*Eff_2MTr_RD, 1, 0., 1.);
    if(Ev.PassTrigger(TrigList_DblMu)) FillHist("NTrCnt_MCObs_2MTr_2M"+Label, 0., weight, 1, 0., 1.);
  }
  if(NElT==2 && NMuT==0){
    if( abs(SumCharge(ElTColl))!=0 ) return;
    bool Acc_2ETr = ElTColl.at(0).Pt()>25 && ElTColl.at(1).Pt()>15;
    if(!Acc_2ETr) return;
    float Eff_2ETr_MC = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "DiElIso_HNTopID17SS", false, "");
    float Eff_2ETr_RD = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "DiElIso_HNTopID17SS", true, "");
    FillHist("NCnt_2ETr_2E"+Label, 0., weight, 1, 0., 1.);
    FillHist("NTrCnt_MCExp_2ETr_2E"+Label, 0., weight*Eff_2ETr_MC, 1, 0., 1.);
    FillHist("NTrCnt_RDExp_2ETr_2E"+Label, 0., weight*Eff_2ETr_RD, 1, 0., 1.);
    if(Ev.PassTrigger(TrigList_DblEG)) FillHist("NTrCnt_MCObs_2ETr_2E"+Label, 0., weight, 1, 0., 1.);
  }
  if(NElT==1 && NMuT==2){
    if( abs(SumCharge(MuTColl))!=0 ) return;
    bool Acc_2MTr = MuTColl.at(0).Pt()>20 && MuTColl.at(1).Pt()>10 && (MuTColl.at(0)+MuTColl.at(1)).M()>4;
    bool Acc_EMTr = (ElTColl.at(0).Pt()>25 or MuTColl.at(0).Pt()>25) && (ElTColl.at(0).Pt()>15 && MuTColl.at(1).Pt()>10);
    bool Acc_SoupTr = Acc_2MTr or Acc_EMTr;
    if(!Acc_SoupTr) return;
    if(Acc_EMTr && false){
      float Eff_EMTr_MC = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "EMuIso_HNTopID17SS", false, "");
      float Eff_EMTr_RD = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "EMuIso_HNTopID17SS", true, "");
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
    if(Acc_SoupTr && false){
      float Eff_SoupTr_MC = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "TrigSoup2L_HNTopID17SS", false, "");
      float Eff_SoupTr_RD = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "TrigSoup2L_HNTopID17SS", true, "");
      FillHist("NCnt_SoupTr_1E2M"+Label, 0., weight, 1, 0., 1.);
      FillHist("NTrCnt_MCExp_SoupTr_1E2M"+Label, 0., weight*Eff_SoupTr_MC, 1, 0., 1.);
      FillHist("NTrCnt_RDExp_SoupTr_1E2M"+Label, 0., weight*Eff_SoupTr_RD, 1, 0., 1.);
      if(Ev.PassTrigger(TrigList_DblEG) or Ev.PassTrigger(TrigList_MuEG)){
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
    if(Acc_EMTr && false){
      float Eff_EMTr_MC = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "EMuIso_HNTopID17SS", false, "");
      float Eff_EMTr_RD = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "EMuIso_HNTopID17SS", true, "");
      FillHist("NCnt_EMTr_2E1M"+Label, 0., weight, 1, 0., 1.);
      FillHist("NTrCnt_MCExp_EMTr_2E1M"+Label, 0., weight*Eff_EMTr_MC, 1, 0., 1.);
      FillHist("NTrCnt_RDExp_EMTr_2E1M"+Label, 0., weight*Eff_EMTr_RD, 1, 0., 1.);
      if(Ev.PassTrigger(TrigList_MuEG)) FillHist("NTrCnt_MCObs_EMTr_2E1M"+Label, 0., weight, 1, 0., 1.);
    } 
    if(Acc_2ETr){
      float Eff_2ETr_MC = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "DiElIso_HNTopID17SS", false, "");
      float Eff_2ETr_RD = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "DiElIso_HNTopID17SS", true, "");
      FillHist("NCnt_2ETr_2E1M"+Label, 0., weight, 1, 0., 1.);
      FillHist("NTrCnt_MCExp_2ETr_2E1M"+Label, 0., weight*Eff_2ETr_MC, 1, 0., 1.);
      FillHist("NTrCnt_RDExp_2ETr_2E1M"+Label, 0., weight*Eff_2ETr_RD, 1, 0., 1.);
      if(Ev.PassTrigger(TrigList_DblEG)) FillHist("NTrCnt_MCObs_2ETr_2E1M"+Label, 0., weight, 1, 0., 1.);
    }
    if(Acc_SoupTr && false){
      float Eff_SoupTr_MC = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "TrigSoup2L_HNTopID17SS", false, "");
      float Eff_SoupTr_RD = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "TrigSoup2L_HNTopID17SS", true, "");
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
    float Eff_Tr_MC = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "DiElIso_HNTopID17SS", false, "");
    float Eff_Tr_RD = mcCorr->TriggerEfficiency(ElTColl, MuTColl, "DiElIso_HNTopID17SS", true, "");
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
  if( FakeRun      and weight==0.  ) return; 
  if( !( (NMuT==2 and NElT==0) or (NElT==2 and NMuT==0) ) ) return;
  if( !(NMuT==NMuL and NElT==NElL) ) return;
  if( !(NMuT==NMuV and NElT==NElV) ) return;
  if(NMuT==2){
    Label="_2M"+Label;
    if(MuTColl.at(0).Charge()!=MuTColl.at(1).Charge()) return;
    if(!(MuTColl.at(0).Pt()>20 && MuTColl.at(1).Pt()>10)) return;
    float Mll = (MuTColl.at(0)+MuTColl.at(1)).M();
    if(DataYear>2016 && Mll<4) return; 
    if(!IsDATA){
      int GenLepInfo = GetGenLepInfo(ElTColl, MuTColl);
      if(ConvRun && GenLepInfo>=100) return;
      if(FlipRun && (GenLepInfo>999 or GenLepInfo<100)) return;
    }
  }
  else if(NElT==2){
    Label="_2E"+Label;
    int aSumQ = abs(SumCharge(ElLColl));
    //if(aSumQ==0) return;
    //if(FlipRun            ){ if(aSumQ!=0) return; }
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

  int Nj=JetColl.size(), Nb=BJetColl.size();
  //FillHist("h2D_Nj_Nb"+Label, Nj, Nb, newweight, 10, 0., 10., 5, 0., 5.);
   
  float Mll=-1., PTl1=-1, Etal1=999., PTl2=-1., Etal2=-1., MTW=-1., MET=-1.;
  bool IsOnZ=false, IsBJOrtho=false;
  if(NMuT==2){
    Mll   = (MuTColl.at(0)+MuTColl.at(1)).M();
    PTl1  = MuTColl.at(0).Pt();  Etal1 = MuTColl.at(0).Eta();
    PTl2  = MuTColl.at(1).Pt();  Etal2 = MuTColl.at(1).Eta();
    MTW   = MT(MuTColl.at(0), vMET);
  }
  else if(NElT==2){
    Mll   = (ElTColl.at(0)+ElTColl.at(1)).M();
    PTl1  = ElTColl.at(0).Pt();  Etal1 = ElTColl.at(0).Eta();
    PTl2  = ElTColl.at(1).Pt();  Etal2 = ElTColl.at(1).Eta();
    MTW   = MT(ElTColl.at(0), vMET);
  }
  MET = vMET.Pt();
  IsOnZ = fabs(Mll-91.2)<15.; IsBJOrtho = Nb==0 && Nj<3;
  TString EtaStr = fabs(Etal1)<1.5 && fabs(Etal2)<1.5? "_BB": fabs(Etal1)>1.5 && fabs(Etal2)>1.5? "_EE":"_EB";
  //TString EtaStr = fabs(Etal1)<1.5? "_E1B":"_E1E";

  vector<TString> EtaTagList = {"", EtaStr};
  vector<TString> SelTagList;
  if(   IsBJOrtho    ) SelTagList.push_back("_0Blt3J"); 
  if( Nb==0 && Nj<1  ) SelTagList.push_back("_0Blt1J");
  if( IsOnZ && Nb==0 ) SelTagList.push_back("_OnZ0B");
  if(     IsOnZ      ) SelTagList.push_back("_OnZ");
  

  for(unsigned int it=0; it<SelTagList.size(); it++){
  for(unsigned int iEta=0; iEta<EtaTagList.size(); iEta++){
    TString SelTag(SelTagList.at(it)), EtaTag(EtaTagList.at(iEta));
    FillHist("NCount"+SelTag+EtaTag+Label, 0., newweight, 1, 0., 1.);
    FillHist("Mll"+SelTag+EtaTag+Label, Mll, newweight, 20, 0., 200.);
    FillHist("MllnearZ"+SelTag+EtaTag+Label, Mll, newweight, 30, 60., 120.);
    FillHist("PTl1"+SelTag+EtaTag+Label, PTl1, newweight, 30, 0., 300.);
    FillHist("PTl2"+SelTag+EtaTag+Label, PTl2, newweight, 20, 0., 200.);
    FillHist("Etal1"+SelTag+EtaTag+Label, Etal1, newweight, 20, -5., 5.);
    FillHist("Etal2"+SelTag+EtaTag+Label, Etal2, newweight, 20, -5., 5.);
    FillHist("MET"+SelTag+EtaTag+Label, MET, newweight, 20, 0., 200.);
    FillHist("MTW"+SelTag+EtaTag+Label, MTW, newweight, 20, 0., 200.);
  }}
}


void ControlPlots::CheckFkCR3l(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                               vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                               vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& Ev, float weight, TString Label)
{
  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  int NLepT=NMuT+NElT;
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

  float PTl1_Z=0., PTl2_Z=0., PTl_Fk=0., Etal1_Z=0., Etal2_Z=0., Etal_Fk=0.;
  float MOSSF_Z=0., MTW=0., MOSSF1=0., MOSSF2=0., M3l=0.;
  float dRZFk=-1, dEtaZFk=-1;
  if(NMuT==2 && NElT==1){
    if( !(PassTrAcc_MM && Ev.PassTrigger(TrigList_DblMu)) ) return;
    Label     = "_2M1E"+Label;
    PTl1_Z    = MuConeColl.at(0).Pt() , PTl2_Z  = MuConeColl.at(1).Pt();
    Etal1_Z   = MuConeColl.at(0).Eta(), Etal2_Z = MuConeColl.at(1).Eta();
    PTl_Fk    = ElConeColl.at(0).Pt() , Etal_Fk = ElConeColl.at(0).Eta();
    MOSSF_Z   = (MuConeColl.at(0)+MuConeColl.at(1)).M(), MTW = MT(ElConeColl.at(0), vMET), MOSSF1=MOSSF_Z; 
    M3l       = (MuConeColl.at(0)+MuConeColl.at(1)+ElConeColl.at(0)).M();
    dRZFk     = ElConeColl.at(0).DeltaR(MuConeColl.at(0)+MuConeColl.at(1));
    dEtaZFk   = fabs(ElConeColl.at(0).Eta()-(MuConeColl.at(0)+MuConeColl.at(1)).Eta());
  }
  else if(NMuT==1 && NElT==2){
    if( !(PassTrAcc_EE && Ev.PassTrigger(TrigList_DblEG)) ) return;
    Label     = "_1M2E"+Label;
    PTl1_Z    = ElConeColl.at(0).Pt() , PTl2_Z  = ElConeColl.at(1).Pt();
    Etal1_Z   = ElConeColl.at(0).Eta(), Etal2_Z = ElConeColl.at(1).Eta();
    PTl_Fk    = MuConeColl.at(0).Pt() , Etal_Fk = MuConeColl.at(0).Eta();
    MOSSF_Z   = (ElConeColl.at(0)+ElConeColl.at(1)).M(), MTW = MT(MuConeColl.at(0), vMET), MOSSF1=MOSSF_Z;
    M3l       = (ElConeColl.at(0)+ElConeColl.at(1)+MuConeColl.at(0)).M();
    dRZFk     = MuConeColl.at(0).DeltaR(ElConeColl.at(0)+ElConeColl.at(1));
    dEtaZFk   = fabs(MuConeColl.at(0).Eta()-(ElConeColl.at(0)+ElConeColl.at(1)).Eta());
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
  }
  else if(NElT==3){
    if( !PassTrAcc_EE ) return;
    //if( !(PassTrAcc_EE && Ev.PassTrigger(TrigList_DblEG)) ) return;
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
  }
  else return;

  if(MOSSF1<12 or ((NMuT>2 or NElT>2) and MOSSF2<12)) return;
  bool OnZ=fabs(MOSSF_Z-91.2)<10.;
  //if(M3l<91.2+15.) return;

  if(!IsDATA){
    int GenLepInfo = GetGenLepInfo(ElTColl, MuTColl);
    if(ConvRun && GenLepInfo>=1000) return;

    //doesn't seem to work well; DYPS describes better than ZG+DYPS for ISR Zg phase space
    //let's just use PS samples. They are quite minor ones after all
    //int NPt15=0;
    //for(unsigned int im=0; im<MuLColl.size(); im++){ if(MuLColl.at(im).Pt()>15) NPt15++; }
    //for(unsigned int ie=0; ie<ElLColl.size(); ie++){ if(ElLColl.at(ie).Pt()>15) NPt15++; }
    //if     (MCSample.Contains("ZG"    ) && NPt15!=3) return;
    //else if(MCSample.Contains("DYJets") && NPt15==3) return;
  }


  Label = "_3l"+Label;
  FillHist("M3l"+Label, M3l, weight, 50, 0., 500.);
  FillHist("MOSSF1"+Label, MOSSF1, weight, 40, 0., 200.);
  FillHist("MOSSF2"+Label, MOSSF2, weight, 40, 0., 200.);
  FillHist("PTl1_Z"+Label, PTl1_Z, weight, 40, 0., 200.);
  FillHist("PTl2_Z"+Label, PTl2_Z, weight, 40, 0., 200.);
  FillHist("PTl_Fk"+Label, PTl_Fk, weight, 40, 0., 200.);
  FillHist("Etal1_Z"+Label, Etal1_Z, weight, 20, -5., 5.);
  FillHist("Etal2_Z"+Label, Etal2_Z, weight, 20, -5., 5.);
  FillHist("Etal_Fk"+Label, Etal_Fk, weight, 20, -5., 5.);
  FillHist("MOSSF_Z"+Label, MOSSF_Z, weight, 30, 60., 120.);
  FillHist("Nj"+Label, JetColl.size(), weight, 10, 0., 10.);
  FillHist("Nb"+Label, BJetColl.size(), weight, 5, 0., 5.);
  FillHist("MET"+Label, vMET.Pt(), weight, 20, 0., 200.);
  FillHist("MTW"+Label, MTW, weight, 20, 0., 200.); 
  FillHist("dRZFk"+Label, dRZFk, weight, 25, 0., 5.);
  FillHist("dEtaZFk"+Label, dEtaZFk, weight, 25, 0., 5.);
  if(OnZ){
    Label.ReplaceAll("_3l","_3lOnZ");
    FillHist("M3l"+Label, M3l, weight, 50, 0., 500.);
    FillHist("MOSSF1"+Label, MOSSF1, weight, 40, 0., 200.);
    FillHist("MOSSF2"+Label, MOSSF2, weight, 40, 0., 200.);
    FillHist("PTl1_Z"+Label, PTl1_Z, weight, 40, 0., 200.);
    FillHist("PTl2_Z"+Label, PTl2_Z, weight, 40, 0., 200.);
    FillHist("PTl_Fk"+Label, PTl_Fk, weight, 40, 0., 200.);
    FillHist("Etal1_Z"+Label, Etal1_Z, weight, 20, -5., 5.);
    FillHist("Etal2_Z"+Label, Etal2_Z, weight, 20, -5., 5.);
    FillHist("Etal_Fk"+Label, Etal_Fk, weight, 20, -5., 5.);
    FillHist("MOSSF_Z"+Label, MOSSF_Z, weight, 30, 60., 120.);
    FillHist("Nj"+Label, JetColl.size(), weight, 10, 0., 10.);
    FillHist("Nb"+Label, BJetColl.size(), weight, 5, 0., 5.);
    FillHist("MET"+Label, vMET.Pt(), weight, 20, 0., 200.);
    FillHist("MTW"+Label, MTW, weight, 20, 0., 200.); 
    FillHist("dRZFk"+Label, dRZFk, weight, 25, 0., 5.);
    FillHist("dEtaZFk"+Label, dEtaZFk, weight, 25, 0., 5.);
  }

}



void ControlPlots::CheckConvSrcDep(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                                   vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                                   vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{

  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  float PTCut1=10., PTCut2=10.;
  if     (NMuT==2){ PTCut1=20., PTCut2=10.; }
  else if(NElT==2){ PTCut1=25., PTCut2=15.; }

  if( !( (NMuT==2 and NElT==0) or (NElT==2 and NMuT==0) ) ) return;
  if( !(NMuT==NMuL and NElT==NElL) ) return;
  if( !(NMuT==NMuV and NElT==NElV) ) return;
  if(NMuT==2){
    Label="_2M"+Label;
    if(!(MuTColl.at(0).Pt()>PTCut1 && MuTColl.at(1).Pt()>PTCut2)) return;
    double Mll = (MuTColl.at(0)+MuTColl.at(1)).M();
    if(DataYear>2016 && Mll<4) return; 
    if(MuTColl.at(0).Charge()!=MuTColl.at(1).Charge()) return;

    int GenLepInfo=-1;
    if(!IsDATA){
      GenLepInfo = GetGenLepInfo(ElTColl, MuTColl);
      if(GenLepInfo>=100) return;
      float HasExConv = GenLepInfo>=10? 1.:0.;
      FillHist("HasExConv"+Label, HasExConv, weight, 2, 0., 2.);
      if(BJetColl.size()>0 && JetColl.size()>2){ FillHist("HasExConvBJ"+Label, HasExConv, weight, 2, 0., 2.); }
    }
    FillHist("Ptl2_InCv"+Label, MuTColl.at(1).Pt(), weight, 40, 0., 200.);
    FillHist("Etal2_InCv"+Label, MuTColl.at(1).Eta(), weight, 20, -5., 5.);
    FillHist("Ptl2_Etal_InCv"+Label, MuTColl.at(1).Pt(), MuTColl.at(1).Eta(), weight, 40, 0., 200., 20, -5., 5.); 
  }
  if(NElT==2){
    Label="_2E"+Label;
    if(!(ElTColl.at(0).Pt()>PTCut1 && ElTColl.at(1).Pt()>PTCut2)) return;
    int aSumQ = abs(SumCharge(ElLColl));
    if(aSumQ==0) return;

    double Mll = (ElTColl.at(0)+ElTColl.at(1)).M();
    if(fabs(Mll-91.2)<10.) return;

    int GenLepInfo=-1;
    if(!IsDATA){
      GenLepInfo = GetGenLepInfo(ElTColl, MuTColl);
      if(GenLepInfo>=100) return;
      //int IdxFlipped = GenLepInfo % 1000;
      //if(FlipRun && (GenLepInfo>999 or GenLepInfo<100)) return;
      //if(FlipRun && IdxFlipped<2){ weight *= GetCFRSF(ElTColl.at(IdxFlipped), "App2Bin1_Fin"); }
      //NFk*1000+NFlip*100+NCv*10+IdxFlipped;
      float HasExConv = GenLepInfo>=10? 1.:0.;
      FillHist("HasExConv"+Label, HasExConv, weight, 2, 0., 2.);
      if(BJetColl.size()>0 && JetColl.size()>2){ FillHist("HasExConvBJ"+Label, HasExConv, weight, 2, 0., 2.); }
    }
    vector<Gen> TruthColl = GetGens();
    int IdxExCv=-1; ///int Type1=0, Type2=0, Idx1=-1, Idx2=-1;
    for(unsigned int ie=0; ie<ElTColl.size(); ie++){
      int LepType = GetLeptonType_JH(ElTColl.at(ie), TruthColl);
      //int MatchedIdx = GenMatchedIdx(ElTColl.at(ie), TruthColl);
      //int LepTypeClose = GetLeptonType_JH(MatchedIdx, TruthColl);
      //int NearbyIdx  = LepType>0? GetPrElType_InSameSCRange(MatchedIdx, TruthColl, "Idx"):-1;
      //cout<<ie<<" "<<LepType<<" "<<LepTypeClose<<" "<<MatchedIdx<<" "<<NearbyIdx<<endl;
      //if     (ie==0){ Type1=LepType; Idx1=MatchedIdx; }
      //else if(ie==1){ Type2=LepType; Idx2=MatchedIdx; }
      if(LepType<-4) IdxExCv=ie;
      else continue;
    }
    if(GenLepInfo>=10 && IdxExCv==-1){ FillHist("ErrCntEx"+Label, 0., 1, 1, 0., 1.); return; }
    
    if(GenLepInfo>=10){
      FillHist("Ptl_ExCv"+Label, ElTColl.at(IdxExCv).Pt(), weight, 40, 0., 200.);
      FillHist("Etal_ExCv"+Label, ElTColl.at(IdxExCv).Eta(), weight, 20, -5., 5.);
      FillHist("Ptl_Etal_ExCv"+Label, ElTColl.at(IdxExCv).Pt(), ElTColl.at(IdxExCv).Eta(), weight, 40, 0., 200., 20, -5., 5.); 
    }
    else{
      FillHist("Ptl2_InCv"+Label, ElTColl.at(1).Pt(), weight, 40, 0., 200.);
      FillHist("Etal2_InCv"+Label, ElTColl.at(1).Eta(), weight, 20, -5., 5.);
      FillHist("Ptl2_Etal_InCv"+Label, ElTColl.at(1).Pt(), ElTColl.at(1).Eta(), weight, 40, 0., 200., 20, -5., 5.); 
    }
  }

}



void ControlPlots::CheckConvCR(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                               vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                               vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& Ev, float weight, TString Label)
{
  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  int NLepT=NMuT+NElT;
  if( FakeRun      and weight==0.  ) return; 
  if( !(NMuT==NMuL and NElT==NElL) ) return;
  if( !(NMuT==NMuV and NElT==NElV) ) return;
  if( NLepT!=3 ) return;
  bool PassTrAcc=false, PassTrAcc_MM=false, PassTrAcc_EE=false, PassTrAcc_EM=false;
  if( NMuT>1 && MuLColl.at(0).Pt()>20 && MuLColl.at(1).Pt()>10 ) PassTrAcc_MM=true;
  if( NElT>1 && ElLColl.at(0).Pt()>25 && ElLColl.at(1).Pt()>15 ) PassTrAcc_EE=true;
  if( NElT>0 && NMuT>0 && ElLColl.at(0).Pt()>25 && MuLColl.at(0).Pt()>10 ) PassTrAcc_EM=true;
  if( NElT>0 && NMuT>0 && ElLColl.at(0).Pt()>15 && MuLColl.at(0).Pt()>25 ) PassTrAcc_EM=true;
  PassTrAcc = PassTrAcc_MM or PassTrAcc_EE or PassTrAcc_EM;
  if(!PassTrAcc) return;
  int Qtot_Mu = SumCharge(MuLColl), Qtot_El = SumCharge(ElLColl), Qtot_Lep = Qtot_Mu+Qtot_El;
  if( abs(Qtot_Lep)!=1 ) return;
  if( NMuT==2 && Qtot_Mu!=0 ) return;
  if( NElT==2 && Qtot_El!=0 ) return;
  if( BJetColl.size()>0 ) return;

  //int NJet = JetColl.size();
  float PTl1_Z=0., PTl2_Z=0., PTl_Cv=0., Etal1_Z=0., Etal2_Z=0., Etal_Cv=0.;
  float MTW=0., MOSSF1=0., MOSSF2=0., M3l=0.;
  if(NMuT==2 && NElT==1){
    if( !(PassTrAcc_MM && Ev.PassTrigger(TrigList_DblMu)) ) return;
    Label   = "_2M1E"+Label;
    PTl1_Z  = MuTColl.at(0).Pt() , PTl2_Z  = MuTColl.at(1).Pt();
    Etal1_Z = MuTColl.at(0).Eta(), Etal2_Z = MuTColl.at(1).Eta();
    PTl_Cv  = ElTColl.at(0).Pt() , Etal_Cv = ElTColl.at(0).Eta();
    MOSSF1  = (MuTColl.at(0)+MuTColl.at(1)).M(), MTW = MT(ElTColl.at(0), vMET);
    M3l     = (MuTColl.at(0)+MuTColl.at(1)+ElTColl.at(0)).M();
  }
  else if(NMuT==1 && NElT==2){
    if( !(PassTrAcc_EE && Ev.PassTrigger(TrigList_DblEG)) ) return;
    Label   = "_1M2E"+Label;
    PTl1_Z  = ElTColl.at(0).Pt() , PTl2_Z  = ElTColl.at(1).Pt();
    Etal1_Z = ElTColl.at(0).Eta(), Etal2_Z = ElTColl.at(1).Eta();
    PTl_Cv  = MuTColl.at(0).Pt() , Etal_Cv = MuTColl.at(0).Eta();
    MOSSF1  = (ElTColl.at(0)+ElTColl.at(1)).M(), MTW = MT(MuTColl.at(0), vMET);
    M3l     = (ElTColl.at(0)+ElTColl.at(1)+MuTColl.at(0)).M();
  }
  else if(NMuT==3 && NElT==0){
    if( !(PassTrAcc_MM && Ev.PassTrigger(TrigList_DblMu)) ) return;
    Label   = "_3M0E"+Label;
    int IdxOS  = TriMuChargeIndex(MuTColl, "OS");
    int IdxSS1 = TriMuChargeIndex(MuTColl, "SS1");
    int IdxSS2 = TriMuChargeIndex(MuTColl, "SS2");
    MOSSF1 = (MuTColl.at(IdxOS)+MuTColl.at(IdxSS1)).M();
    MOSSF2 = (MuTColl.at(IdxOS)+MuTColl.at(IdxSS2)).M();
    int IdxL1_Z=-1, IdxL2_Z=-1, IdxL_Cv=-1;
    if(fabs(MOSSF1-91.2)<fabs(MOSSF2-91.2)){
      IdxL1_Z = MuTColl.at(IdxOS).Pt()>MuTColl.at(IdxSS1).Pt()? IdxOS:IdxSS1;
      IdxL2_Z = MuTColl.at(IdxOS).Pt()>MuTColl.at(IdxSS1).Pt()? IdxSS1:IdxOS;
      IdxL_Cv = IdxSS2;
    }
    else{
      IdxL1_Z = MuTColl.at(IdxOS).Pt()>MuTColl.at(IdxSS2).Pt()? IdxOS:IdxSS2;
      IdxL2_Z = MuTColl.at(IdxOS).Pt()>MuTColl.at(IdxSS2).Pt()? IdxSS2:IdxOS;
      IdxL_Cv = IdxSS1;
    }
    PTl1_Z  = MuTColl.at(IdxL1_Z).Pt() , PTl2_Z = MuTColl.at(IdxL2_Z).Pt();
    Etal1_Z = MuTColl.at(IdxL1_Z).Eta(), Etal2_Z = MuTColl.at(IdxL2_Z).Eta();
    PTl_Cv  = MuTColl.at(IdxL_Cv).Pt() , Etal_Cv = MuTColl.at(IdxL_Cv).Eta();
    MTW     = MT(MuTColl.at(IdxL_Cv), vMET);
    M3l     = (MuTColl.at(0)+MuTColl.at(1)+MuTColl.at(2)).M();
  }
  else if(NMuT==0 && NElT==3){
    if( !(PassTrAcc_EE && Ev.PassTrigger(TrigList_DblEG)) ) return;
    Label   = "_0M3E"+Label;
    int IdxOS  = TriElChargeIndex(ElTColl, "OS");
    int IdxSS1 = TriElChargeIndex(ElTColl, "SS1");
    int IdxSS2 = TriElChargeIndex(ElTColl, "SS2");
    MOSSF1 = (ElTColl.at(IdxOS)+ElTColl.at(IdxSS1)).M();
    MOSSF2 = (ElTColl.at(IdxOS)+ElTColl.at(IdxSS2)).M();
    int IdxL1_Z=-1, IdxL2_Z=-1, IdxL_Cv=-1;
    if(fabs(MOSSF1-91.2)<fabs(MOSSF2-91.2)){
      IdxL1_Z = ElTColl.at(IdxOS).Pt()>ElTColl.at(IdxSS1).Pt()? IdxOS:IdxSS1;
      IdxL2_Z = ElTColl.at(IdxOS).Pt()>ElTColl.at(IdxSS1).Pt()? IdxSS1:IdxOS;
      IdxL_Cv = IdxSS2;
    }
    else{
      IdxL1_Z = ElTColl.at(IdxOS).Pt()>ElTColl.at(IdxSS2).Pt()? IdxOS:IdxSS2;
      IdxL2_Z = ElTColl.at(IdxOS).Pt()>ElTColl.at(IdxSS2).Pt()? IdxSS2:IdxOS;
      IdxL_Cv = IdxSS1;
    }
    PTl1_Z  = ElTColl.at(IdxL1_Z).Pt() , PTl2_Z = ElTColl.at(IdxL2_Z).Pt();
    Etal1_Z = ElTColl.at(IdxL1_Z).Eta(), Etal2_Z = ElTColl.at(IdxL2_Z).Eta();
    PTl_Cv  = ElTColl.at(IdxL_Cv).Pt() , Etal_Cv = ElTColl.at(IdxL_Cv).Eta();
    MTW     = MT(ElTColl.at(IdxL_Cv), vMET);
    M3l     = (ElTColl.at(0)+ElTColl.at(1)+ElTColl.at(2)).M();
  }

  if( MOSSF1<12 or ((NMuT>2 or NElT>2) and MOSSF2<12) ) return;
  if( fabs(MOSSF1-91.2)<10 or fabs(MOSSF2-91.2)<10    ) return;
  if( fabs(M3l-91.2)>10. ) return;

  if(!IsDATA){
    int GenLepInfo = GetGenLepInfo(ElTColl, MuTColl);
    if(ConvRun && GenLepInfo>=1000 ) return;
    //if(ConvRun && GenLepInfo>=100 ) return;
  }
  int NPt20=0;
  for(unsigned int im=0; im<MuLColl.size(); im++){
    if(MuLColl.at(im).Pt()>15) NPt20++;
  }
  for(unsigned int ie=0; ie<ElLColl.size(); ie++){
    if(ElLColl.at(ie).Pt()>15) NPt20++;
  }
  if(MCSample.Contains("ZG") && NPt20!=3) return;

  vector<TString> SelTagList={"_ZGSel"};
  if(!IsDATA && MCSample.Contains("ZG")){
    if(NPt20==3) SelTagList.push_back("_ZGSel20");
  }
  else if(!IsDATA && MCSample.Contains("DY")){
    if(NPt20!=3) SelTagList.push_back("_ZGSel20");
  }
  else{ SelTagList.push_back("_ZGSel20"); }

  for(unsigned int iSel=0; iSel<SelTagList.size(); iSel++){
    TString SelTag(SelTagList.at(iSel));
    FillHist("NCount"+SelTag+Label, 0., weight, 1, 0., 1.);
    FillHist("M3l"+SelTag+Label, M3l, weight, 30, 60., 120.);
    FillHist("MOSSF1"+SelTag+Label, MOSSF1, weight, 15, 0., 150.);
    FillHist("MOSSF2"+SelTag+Label, MOSSF2, weight, 15, 0., 150.);
    FillHist("PTl1_Z"+SelTag+Label, PTl1_Z, weight, 24, 0., 120.);
    FillHist("PTl2_Z"+SelTag+Label, PTl2_Z, weight, 16, 0., 80.);
    FillHist("PTl_Cv"+SelTag+Label, PTl_Cv, weight, 16, 0., 80.);
    FillHist("Etal1_Z"+SelTag+Label, Etal1_Z, weight, 20, -5., 5.);
    FillHist("Etal2_Z"+SelTag+Label, Etal2_Z, weight, 20, -5., 5.);
    FillHist("Etal_Cv"+SelTag+Label, Etal_Cv, weight, 20, -5., 5.);
    FillHist("Nj"+SelTag+Label, JetColl.size(), weight, 10, 0., 10.);
    FillHist("Nb"+SelTag+Label, BJetColl.size(), weight, 5, 0., 5.);
    FillHist("MET"+SelTag+Label, vMET.Pt(), weight, 20, 0., 200.);
    FillHist("MTW"+SelTag+Label, MTW, weight, 20, 0., 200.); 
  }

}


void ControlPlots::PlotTop2LCR_OS2L(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                                    vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                                    vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{
  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  if( !( (NMuT==2 and NElT==0) or (NElT==2 and NMuT==0) or (NElT==1 and NMuT==1) ) ) return;
  if( !(NMuT==NMuL and NElT==NElL) ) return;
  if( !(NMuT==NMuV and NElT==NElV) ) return;
  if(NMuT==2){
    if(MuTColl.at(0).Charge()==MuTColl.at(1).Charge()) return;
    if(!(MuTColl.at(0).Pt()>20 && MuTColl.at(1).Pt()>10)) return;
    float Mll = (MuTColl.at(0)+MuTColl.at(1)).M();
    if(Mll<12 or fabs(Mll-91.2)<15) return; 
    if(BJetColl.size()<1) return;
    if(JetColl.size() <3) return;
    if(!IsDATA){
      int GenLepInfo = GetGenLepInfo(ElTColl, MuTColl);
      if(GenLepInfo>999) return;
    }
    InitializeTreeVars();
    SetVarSS2L(MuTColl, MuLColl, MuVColl, ElTColl, ElLColl, ElVColl, JetColl, BJetColl, vMET, weight, "");
    PlotParameters(Label+"_2M");
  }
  if(NElT==2){
    if(ElTColl.at(0).Charge()==ElTColl.at(1).Charge()) return;
    if(!(ElTColl.at(0).Pt()>25 && ElTColl.at(1).Pt()>15)) return;
    float Mll = (ElTColl.at(0)+ElTColl.at(1)).M();
    if(Mll<12 or fabs(Mll-91.2)<15) return; 
    if(BJetColl.size()<1) return;
    if(JetColl.size() <3) return;
    if(!IsDATA){
      int GenLepInfo = GetGenLepInfo(ElTColl, MuTColl);
      if(GenLepInfo>999) return;
    }
    InitializeTreeVars();
    SetVarSS2L(MuTColl, MuLColl, MuVColl, ElTColl, ElLColl, ElVColl, JetColl, BJetColl, vMET, weight, "");
    PlotParameters(Label+"_2E");
  }
  if(NElT==1 && NMuT==1){
    if(ElTColl.at(0).Charge()==MuTColl.at(0).Charge()) return;
    if(!(MuTColl.at(0).Pt()>10 && ElTColl.at(0).Pt()>15)) return; 
    if(!(MuTColl.at(0).Pt()>25 || ElTColl.at(0).Pt()>25)) return; 
    if(BJetColl.size()<1) return;
    if(JetColl.size() <3) return;
    if(!IsDATA){
      int GenLepInfo = GetGenLepInfo(ElTColl, MuTColl);
      if(GenLepInfo>999) return;
    }
    Muon TmpMu1 = MuTColl.at(0); Muon TmpMu2 = MuTColl.at(0);
    TmpMu2.SetPtEtaPhiE(ElTColl.at(0).Pt(), ElTColl.at(0).Eta(), ElTColl.at(0).Phi(), ElTColl.at(0).E());
    vector<Muon> TmpMuColl = {TmpMu1, TmpMu2}; vector<Electron> NullColl;
    std::sort(TmpMuColl.begin(), TmpMuColl.end(), PtComparing);
    InitializeTreeVars();
    SetVarSS2L(TmpMuColl, TmpMuColl, TmpMuColl, NullColl, NullColl, NullColl, JetColl, BJetColl, vMET, weight, "");
    PlotParameters(Label+"_EM");
  }

}


void ControlPlots::CheckTopBSrc(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                                vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                                vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{
  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  if( !( (NMuT==2 and NElT==0) or (NElT==2 and NMuT==0) ) ) return;
  if( !(NMuT==NMuL and NElT==NElL) ) return;
  if( !(NMuT==NMuV and NElT==NElV) ) return;
  if(NMuT==2){
    Label+="_2M";
    if(MuTColl.at(0).Charge()!=MuTColl.at(1).Charge()) return;
    if(!(MuTColl.at(0).Pt()>20 && MuTColl.at(1).Pt()>10)) return;
    float Mll = (MuTColl.at(0)+MuTColl.at(1)).M();
    if(DataYear>2016 && Mll<4) return; 
    if(BJetColl.size()<1) return;
    if(JetColl.size() <3) return;
    vector<Gen> TruthColl = GetGens();
    
    int NFkCv=0, TypePtFake=-1, NPr=0, NInConv=0, NExConv=0, NFk=0, NElse=0;
    for(unsigned int it_m=0; it_m<MuTColl.size(); it_m++){
      int LepType = GetLeptonType(MuTColl.at(it_m), TruthColl);
      if(LepType>0 && LepType<4) NPr++;
      else if(LepType==4 or LepType==5)  NInConv++;
      else if(LepType==-5 or LepType==-6) NExConv++;
      else if(LepType<0 && LepType>-5) NFk++;
      else NElse++;
      if(LepType>0) continue;
      FillHist("LepType"+Label, LepType, weight, 6, -6., 0.);
      NFkCv++;
      if     (it_m==0     ) TypePtFake=1;
      else if(TypePtFake<0) TypePtFake=2;
      else                  TypePtFake=3;

      if(LepType==-2){
        int MatchedIdx  = GenMatchedIdx(MuTColl.at(it_m),TruthColl);
        int MotherIdx   = FirstNonSelfMotherIdx(MatchedIdx,TruthColl);
        int GrMotherIdx = FirstNonSelfMotherIdx(MotherIdx,TruthColl);
        int fMPID       = MotherIdx<0?   -1:abs(TruthColl.at(MotherIdx).PID()); 
        int fGrMPID     = GrMotherIdx<0? -1:abs(TruthColl.at(GrMotherIdx).PID());
        int MPIDType=0, GrMPIDType=0;
        if     (fMPID%1000>550 && fMPID%1000<560 && (fMPID/1000)%10!=5) MPIDType=1;
        else if(fMPID%1000>500 && fMPID%1000<550 && (fMPID/1000)%10!=5) MPIDType=2;
        else if(fMPID%1000>440 && fMPID%1000<450 && (fMPID/1000)%10!=5 && (fMPID/1000)%10!=4) MPIDType=3;
        else if(fMPID%1000>400 && fMPID%1000<440 && (fMPID/1000)%10!=5 && (fMPID/1000)%10!=4) MPIDType=4;
        else if((fMPID/1000)%10==5) MPIDType=5;
        else if((fMPID/1000)%10==4) MPIDType=6;
        else MPIDType=7;

        if     (fGrMPID%1000>550 && fGrMPID%1000<560 && (fGrMPID/1000)%10!=5) GrMPIDType=1;
        else if(fGrMPID%1000>500 && fGrMPID%1000<550 && (fGrMPID/1000)%10!=5) GrMPIDType=2;
        else if(fGrMPID%1000>440 && fGrMPID%1000<450 && (fGrMPID/1000)%10!=5 && (fGrMPID/1000)%10!=4) GrMPIDType=3;
        else if(fGrMPID%1000>400 && fGrMPID%1000<440 && (fGrMPID/1000)%10!=5 && (fGrMPID/1000)%10!=4) GrMPIDType=4;
        else if((fGrMPID/1000)%10==5) GrMPIDType=5;
        else if((fGrMPID/1000)%10==4) GrMPIDType=6;
        else GrMPIDType=7;

        FillHist("MPIDType"+Label, MPIDType, weight, 10, 0., 10.);
        FillHist("GrMPIDType"+Label, GrMPIDType, weight, 10, 0., 10.);
      }
    }
    FillHist("NFkCv"+Label, NFkCv, weight, 3, 0., 3.);
    FillHist("TypePtFake"+Label, TypePtFake, weight, 5, -1., 4.);
    if     (NPr==2                        ) FillHist("LepTypePair"+Label, 0., weight, 10, 0., 10.);
    else if(NPr==1 && NFk==1              ) FillHist("LepTypePair"+Label, 1., weight, 10, 0., 10.);
    else if(NPr==1 && NInConv==1          ) FillHist("LepTypePair"+Label, 2., weight, 10, 0., 10.);
    else if(NPr==1 && NExConv==1          ) FillHist("LepTypePair"+Label, 3., weight, 10, 0., 10.);
    else if(NPr==0 && NFk==2              ) FillHist("LepTypePair"+Label, 4., weight, 10, 0., 10.);
    else if(NPr==0 && NFk==1 && NInConv==1) FillHist("LepTypePair"+Label, 5., weight, 10, 0., 10.);
    else if(NPr==0 && NFk==1 && NExConv==1) FillHist("LepTypePair"+Label, 6., weight, 10, 0., 10.);
    else if(NPr==0 && NInConv==2          ) FillHist("LepTypePair"+Label, 7., weight, 10, 0., 10.);
    else if(NPr==0 && NExConv==2          ) FillHist("LepTypePair"+Label, 8., weight, 10, 0., 10.);

    int NB_b=0, NB_c=0, NB_l=0;
    for(unsigned int it_b=0; it_b<BJetColl.size(); it_b++){
      bool NearB=false, NearCNotB=false;
      for(unsigned int it_t=2; it_t<TruthColl.size(); it_t++){
        int apid  = abs(TruthColl.at(it_t).PID());
        //int ampid = abs(TruthColl.at(TruthColl.at(it_t).MotherIndex()).PID());
        if(!(apid==5 or apid==4)) continue;
        if(BJetColl.at(it_b).DeltaR(TruthColl.at(it_t))>0.5) continue;
        if(TruthColl.at(it_t).Pt()/BJetColl.at(it_b).Pt()<0.5) continue;
        if     (apid==5){ NearB=true; break; }
        else if(apid==4){ NearCNotB=true; break; }
      }
      if     (NearB)     NB_b++; 
      else if(NearCNotB) NB_c++;
      else               NB_l++;
    }
    FillHist("NB_b"+Label, NB_b, weight, 5, 0., 5.);
    FillHist("NB_c"+Label, NB_c, weight, 5, 0., 5.);
    FillHist("NB_l"+Label, NB_l, weight, 5, 0., 5.);
    if(BJetColl.size()==1 && NB_b==0 && NB_c==0) FillHist("NB_Comp"+Label, 0., weight, 19, 0., 19.);
    if(BJetColl.size()==1 && NB_b==0 && NB_c==1) FillHist("NB_Comp"+Label, 1., weight, 19, 0., 19.);
    if(BJetColl.size()==1 && NB_b==1 && NB_c==0) FillHist("NB_Comp"+Label, 2., weight, 19, 0., 19.);
    if(BJetColl.size()==2 && NB_b==0 && NB_c==0) FillHist("NB_Comp"+Label, 3., weight, 19, 0., 19.);
    if(BJetColl.size()==2 && NB_b==0 && NB_c==1) FillHist("NB_Comp"+Label, 4., weight, 19, 0., 19.);
    if(BJetColl.size()==2 && NB_b==0 && NB_c==2) FillHist("NB_Comp"+Label, 5., weight, 19, 0., 19.);
    if(BJetColl.size()==2 && NB_b==1 && NB_c==0) FillHist("NB_Comp"+Label, 6., weight, 19, 0., 19.);
    if(BJetColl.size()==2 && NB_b==1 && NB_c==1) FillHist("NB_Comp"+Label, 7., weight, 19, 0., 19.);
    if(BJetColl.size()==2 && NB_b==2 && NB_c==0) FillHist("NB_Comp"+Label, 8., weight, 19, 0., 19.);
    if(BJetColl.size()==3 && NB_b==0 && NB_c==0) FillHist("NB_Comp"+Label, 9., weight, 19, 0., 19.);
    if(BJetColl.size()==3 && NB_b==0 && NB_c==1) FillHist("NB_Comp"+Label, 10., weight, 19, 0., 19.);
    if(BJetColl.size()==3 && NB_b==0 && NB_c==2) FillHist("NB_Comp"+Label, 11., weight, 19, 0., 19.);
    if(BJetColl.size()==3 && NB_b==0 && NB_c==3) FillHist("NB_Comp"+Label, 12., weight, 19, 0., 19.);
    if(BJetColl.size()==3 && NB_b==1 && NB_c==0) FillHist("NB_Comp"+Label, 13., weight, 19, 0., 19.);
    if(BJetColl.size()==3 && NB_b==1 && NB_c==1) FillHist("NB_Comp"+Label, 14., weight, 19, 0., 19.);
    if(BJetColl.size()==3 && NB_b==1 && NB_c==2) FillHist("NB_Comp"+Label, 15., weight, 19, 0., 19.);
    if(BJetColl.size()==3 && NB_b==2 && NB_c==0) FillHist("NB_Comp"+Label, 16., weight, 19, 0., 19.);
    if(BJetColl.size()==3 && NB_b==2 && NB_c==1) FillHist("NB_Comp"+Label, 17., weight, 19, 0., 19.);
    if(BJetColl.size()==3 && NB_b==3 && NB_c==0) FillHist("NB_Comp"+Label, 18., weight, 19, 0., 19.);
  }
  if(NElT==2){
    Label+="_2E";
    if(ElTColl.at(0).Charge()!=ElTColl.at(1).Charge()) return;
    if(!(ElTColl.at(0).Pt()>25 && ElTColl.at(1).Pt()>15)) return;
    if(BJetColl.size()<1) return;
    if(JetColl.size() <3) return;
    vector<Gen> TruthColl = GetGens();
    
    int NFkCv=0, TypePtFake=-1, NPr=0, NInConv=0, NExConv=0, NFk=0, NElse=0;
    for(unsigned int it_e=0; it_e<ElTColl.size(); it_e++){
      int LepType = GetLeptonType(ElTColl.at(it_e), TruthColl);
      if(LepType>0 && LepType<4) NPr++;
      else if(LepType==4 or LepType==5)  NInConv++;
      else if(LepType==-5 or LepType==-6) NExConv++;
      else if(LepType<0 && LepType>-5) NFk++;
      else NElse++;
      if(LepType>0) continue;
      FillHist("LepType"+Label, LepType, weight, 6, -6., 0.);
      NFkCv++;
      if     (it_e==0     ) TypePtFake=1;
      else if(TypePtFake<0) TypePtFake=2;
      else                  TypePtFake=3;

      if(LepType==-2){
        int MatchedIdx  = GenMatchedIdx(ElTColl.at(it_e),TruthColl);
        int MotherIdx   = FirstNonSelfMotherIdx(MatchedIdx,TruthColl);
        int GrMotherIdx = FirstNonSelfMotherIdx(MotherIdx,TruthColl);
        int fMPID       = MotherIdx<0?   -1:abs(TruthColl.at(MotherIdx).PID()); 
        int fGrMPID     = GrMotherIdx<0? -1:abs(TruthColl.at(GrMotherIdx).PID());
        int MPIDType=0, GrMPIDType=0;
        if     (fMPID%1000>550 && fMPID%1000<560 && (fMPID/1000)%10!=5) MPIDType=1;
        else if(fMPID%1000>500 && fMPID%1000<550 && (fMPID/1000)%10!=5) MPIDType=2;
        else if(fMPID%1000>440 && fMPID%1000<450 && (fMPID/1000)%10!=5 && (fMPID/1000)%10!=4) MPIDType=3;
        else if(fMPID%1000>400 && fMPID%1000<440 && (fMPID/1000)%10!=5 && (fMPID/1000)%10!=4) MPIDType=4;
        else if((fMPID/1000)%10==5) MPIDType=5;
        else if((fMPID/1000)%10==4) MPIDType=6;
        else MPIDType=7;

        if     (fGrMPID%1000>550 && fGrMPID%1000<560 && (fGrMPID/1000)%10!=5) GrMPIDType=1;
        else if(fGrMPID%1000>500 && fGrMPID%1000<550 && (fGrMPID/1000)%10!=5) GrMPIDType=2;
        else if(fGrMPID%1000>440 && fGrMPID%1000<450 && (fGrMPID/1000)%10!=5 && (fGrMPID/1000)%10!=4) GrMPIDType=3;
        else if(fGrMPID%1000>400 && fGrMPID%1000<440 && (fGrMPID/1000)%10!=5 && (fGrMPID/1000)%10!=4) GrMPIDType=4;
        else if((fGrMPID/1000)%10==5) GrMPIDType=5;
        else if((fGrMPID/1000)%10==4) GrMPIDType=6;
        else GrMPIDType=7;

        FillHist("MPIDType"+Label, MPIDType, weight, 10, 0., 10.);
        FillHist("GrMPIDType"+Label, GrMPIDType, weight, 10, 0., 10.);
      }
    }
    FillHist("NFkCv"+Label, NFkCv, weight, 3, 0., 3.);
    FillHist("TypePtFake"+Label, TypePtFake, weight, 5, -1., 4.);
    if     (NPr==2                        ) FillHist("LepTypePair"+Label, 0., weight, 10, 0., 10.);
    else if(NPr==1 && NFk==1              ) FillHist("LepTypePair"+Label, 1., weight, 10, 0., 10.);
    else if(NPr==1 && NInConv==1          ) FillHist("LepTypePair"+Label, 2., weight, 10, 0., 10.);
    else if(NPr==1 && NExConv==1          ) FillHist("LepTypePair"+Label, 3., weight, 10, 0., 10.);
    else if(NPr==0 && NFk==2              ) FillHist("LepTypePair"+Label, 4., weight, 10, 0., 10.);
    else if(NPr==0 && NFk==1 && NInConv==1) FillHist("LepTypePair"+Label, 5., weight, 10, 0., 10.);
    else if(NPr==0 && NFk==1 && NExConv==1) FillHist("LepTypePair"+Label, 6., weight, 10, 0., 10.);
    else if(NPr==0 && NInConv==2          ) FillHist("LepTypePair"+Label, 7., weight, 10, 0., 10.);
    else if(NPr==0 && NExConv==2          ) FillHist("LepTypePair"+Label, 8., weight, 10, 0., 10.);


    int NB_b=0, NB_c=0, NB_l=0;
    for(unsigned int it_b=0; it_b<BJetColl.size(); it_b++){
      bool NearB=false, NearCNotB=false;
      for(unsigned int it_t=2; it_t<TruthColl.size(); it_t++){
        int apid  = abs(TruthColl.at(it_t).PID());
        //int ampid = abs(TruthColl.at(TruthColl.at(it_t).MotherIndex()).PID());
        if(!(apid==5 or apid==4)) continue;
        if(BJetColl.at(it_b).DeltaR(TruthColl.at(it_t))>0.5) continue;
        if(TruthColl.at(it_t).Pt()/BJetColl.at(it_b).Pt()<0.5) continue;
        if     (apid==5){ NearB=true; break; }
        else if(apid==4){ NearCNotB=true; break; }
      }
      if     (NearB)     NB_b++; 
      else if(NearCNotB) NB_c++;
      else               NB_l++;
    }
    FillHist("NB_b"+Label, NB_b, weight, 5, 0., 5.);
    FillHist("NB_c"+Label, NB_c, weight, 5, 0., 5.);
    FillHist("NB_l"+Label, NB_l, weight, 5, 0., 5.);
    if(BJetColl.size()==1 && NB_b==0 && NB_c==0) FillHist("NB_Comp"+Label, 0., weight, 19, 0., 19.);
    if(BJetColl.size()==1 && NB_b==0 && NB_c==1) FillHist("NB_Comp"+Label, 1., weight, 19, 0., 19.);
    if(BJetColl.size()==1 && NB_b==1 && NB_c==0) FillHist("NB_Comp"+Label, 2., weight, 19, 0., 19.);
    if(BJetColl.size()==2 && NB_b==0 && NB_c==0) FillHist("NB_Comp"+Label, 3., weight, 19, 0., 19.);
    if(BJetColl.size()==2 && NB_b==0 && NB_c==1) FillHist("NB_Comp"+Label, 4., weight, 19, 0., 19.);
    if(BJetColl.size()==2 && NB_b==0 && NB_c==2) FillHist("NB_Comp"+Label, 5., weight, 19, 0., 19.);
    if(BJetColl.size()==2 && NB_b==1 && NB_c==0) FillHist("NB_Comp"+Label, 6., weight, 19, 0., 19.);
    if(BJetColl.size()==2 && NB_b==1 && NB_c==1) FillHist("NB_Comp"+Label, 7., weight, 19, 0., 19.);
    if(BJetColl.size()==2 && NB_b==2 && NB_c==0) FillHist("NB_Comp"+Label, 8., weight, 19, 0., 19.);
    if(BJetColl.size()==3 && NB_b==0 && NB_c==0) FillHist("NB_Comp"+Label, 9., weight, 19, 0., 19.);
    if(BJetColl.size()==3 && NB_b==0 && NB_c==1) FillHist("NB_Comp"+Label, 10., weight, 19, 0., 19.);
    if(BJetColl.size()==3 && NB_b==0 && NB_c==2) FillHist("NB_Comp"+Label, 11., weight, 19, 0., 19.);
    if(BJetColl.size()==3 && NB_b==0 && NB_c==3) FillHist("NB_Comp"+Label, 12., weight, 19, 0., 19.);
    if(BJetColl.size()==3 && NB_b==1 && NB_c==0) FillHist("NB_Comp"+Label, 13., weight, 19, 0., 19.);
    if(BJetColl.size()==3 && NB_b==1 && NB_c==1) FillHist("NB_Comp"+Label, 14., weight, 19, 0., 19.);
    if(BJetColl.size()==3 && NB_b==1 && NB_c==2) FillHist("NB_Comp"+Label, 15., weight, 19, 0., 19.);
    if(BJetColl.size()==3 && NB_b==2 && NB_c==0) FillHist("NB_Comp"+Label, 16., weight, 19, 0., 19.);
    if(BJetColl.size()==3 && NB_b==2 && NB_c==1) FillHist("NB_Comp"+Label, 17., weight, 19, 0., 19.);
    if(BJetColl.size()==3 && NB_b==3 && NB_c==0) FillHist("NB_Comp"+Label, 18., weight, 19, 0., 19.);
  }

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
    if(MuLColl.at(0).Charge()!=MuLColl.at(1).Charge()) return;
    if(!(MuLColl.at(0).Pt()>20 && MuLColl.at(1).Pt()>10)) return;
    float Mll = (MuLColl.at(0)+MuLColl.at(1)).M();
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
      MuConeColl=MuTColl;
      for(unsigned int im=0; im<MuTColl.size(); im++){ 
        float TightIso = 0.1;
        float RelIso = MuTColl.at(im).MiniRelIso();
        float PTCorr = MuTColl.at(im).CalcPtCone(RelIso,TightIso), PT=MuTColl.at(im).Pt();
        if(RelIso>TightIso) MuConeColl.at(im)*=PTCorr/PT;
      }
    }

    InitializeTreeVars();
    if(!FakeRun) SetVarSS2L(MuTColl, MuLColl, MuVColl, ElTColl, ElLColl, ElVColl, JetColl, BJetColl, vMET, weight, "");
    else         SetVarSS2L(MuConeColl, MuLColl, MuVColl, ElConeColl, ElLColl, ElVColl, JetColl, BJetColl, vMET, weight, "");

    //if((!FakeRun) && Mll<80) return;
    //if(  FakeRun  && (MuConeColl.at(0)+MuConeColl.at(1)).M()<80) return;
    if(MVAReader->EvaluateMVA("BDTG_MN50_Mu")>0) return;
    PlotParametersSS(Label+"_2M");
  }
  if(NElL==2){
    int aSumQ = abs(SumCharge(ElLColl)); float MCCFSF=1.;
    if(FlipRun && !FakeRun){ if(aSumQ!=0) return; }
    else                   { if(aSumQ==0) return; }
    if(!(ElLColl.at(0).Pt()>25 && ElLColl.at(1).Pt()>15)) return;
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
      ElConeColl=ElTColl;
      for(unsigned int ie=0; ie<ElTColl.size(); ie++){ 
        float RelIso = ElTColl.at(ie).MiniRelIso();
        float PTCorr = ElTColl.at(ie).CalcPtCone(RelIso,0.1), PT=ElTColl.at(ie).Pt();
        if(RelIso>0.1) ElConeColl.at(ie)*=PTCorr/PT;
      }
    }
    //if((!FakeRun) && (ElLColl.at(0)+ElLColl.at(1)).M()<101.2) return;
    //if(  FakeRun  && (ElConeColl.at(0)+ElConeColl.at(1)).M()<101.2) return;

    InitializeTreeVars();
    if(!FakeRun) SetVarSS2L(MuTColl, MuLColl, MuVColl, ElTColl, ElLColl, ElVColl, JetColl, BJetColl, vMET, newweight, "");
    else         SetVarSS2L(MuConeColl, MuLColl, MuVColl, ElConeColl, ElLColl, ElVColl, JetColl, BJetColl, vMET, newweight, "");

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



float ControlPlots::CalcTestFakeWeight(vector<Muon>& MuColl, vector<Electron>& ElColl, TString MuIDT, TString MuIDL, TString ElIDT, TString ElIDL, int NBJet, int SystDir){

  float w_FR=IsDATA? -1.:1.; int NLepLNotT=0;
  for(unsigned int im=0; im<MuColl.size(); im++){
    if(MuColl.at(im).PassID(MuIDT)) continue;
    float FR = GetTestMuFR(MuColl.at(im), MuIDT+"_"+MuIDL+"_Incl", SystDir);
    w_FR*=-FR/(1.-FR);
    NLepLNotT++;
  }

  for(unsigned int ie=0; ie<ElColl.size(); ie++){
    if(ElColl.at(ie).PassID(ElIDT)) continue;
    TString SelCond = NBJet==0? "Incl":"HasB";
    float FR = GetTestElFR(ElColl.at(ie), ElIDT+"_"+ElIDL+"_"+SelCond, SystDir);
    w_FR*=-FR/(1.-FR);
    NLepLNotT++;
  }
  if(NLepLNotT==0) w_FR=0.;
  
  return w_FR;  
}


float ControlPlots::GetConvSF(TString ElTID, int SystDir){

  TString Era = GetEraShort(); float SF = 1.;
  if(ElTID=="TopHNSSTWP90Isop1"){
    if     (Era=="2016a"){ SF = 0.961*(1.+((float) SystDir)*0.19); }
    else if(Era=="2016b"){ SF = 1.129*(1.+((float) SystDir)*0.16); }
    else if(Era=="2017" ){ SF = 1.040*(1.+((float) SystDir)*0.16); }
    else if(Era=="2018" ){ SF = 1.122*(1.+((float) SystDir)*0.16); }
  }
  else if(ElTID=="TopHN17SST"){
    if     (Era=="2016a"){ SF = 0.938*(1.+((float) SystDir)*0.2 ); }
    else if(Era=="2016b"){ SF = 0.861*(1.+((float) SystDir)*0.21); }
    else if(Era=="2017" ){ SF = 1.019*(1.+((float) SystDir)*0.18); }
    else if(Era=="2018" ){ SF = 1.043*(1.+((float) SystDir)*0.17); }
  }

  return SF;
}


float ControlPlots::GetTestElFR(Electron& El, TString Key, int SystDir){

  float FR=0., PTCorr=0., fEta=fabs(El.Eta());
  if(Key=="TopHN17SST_TopHN17SSL_Incl"){
    float TightIso=0.1;
    PTCorr = El.CalcPtCone(El.MiniRelIso(), TightIso);
    if(fEta<0.8){
      if     (PTCorr<15) FR=0.;
      else if(PTCorr<20) FR=0.379217*(1.+(SystDir==0? 0.:SystDir>0? 0.354774 :-0.0106956));
      else if(PTCorr<25) FR=0.224299*(1.+(SystDir==0? 0.:SystDir>0? 0.281698 :-0.0359124));
      else if(PTCorr<35) FR=0.154058*(1.+(SystDir==0? 0.:SystDir>0? 0.22729  :-0.0616697));
      else               FR=0.159764*(1.+(SystDir==0? 0.:SystDir>0? 0.0699418:-0.209737 ));
    }
    else if(fEta<1.479){
      if     (PTCorr<15) FR=0.;
      else if(PTCorr<20) FR=0.3647  *(1.+(SystDir==0? 0.:SystDir>0? 0.351692:-0.027291 ));
      else if(PTCorr<25) FR=0.236944*(1.+(SystDir==0? 0.:SystDir>0? 0.466218:-0.0097618));
      else if(PTCorr<35) FR=0.183473*(1.+(SystDir==0? 0.:SystDir>0? 0.647966:-0.0151806));
      else               FR=0.167406*(1.+(SystDir==0? 0.:SystDir>0? 0.192329:-0.0774894));
    }
    else{
      if     (PTCorr<15) FR=0.;
      else if(PTCorr<20) FR=0.43818*(1.+(SystDir==0? 0.:SystDir>0? 0.267022:-0.0116451));
      else if(PTCorr<25) FR=0.30755*(1.+(SystDir==0? 0.:SystDir>0? 0.463056:-0.0087176));
      else if(PTCorr<35) FR=0.24232*(1.+(SystDir==0? 0.:SystDir>0? 0.264124:-0.0071143));
      else               FR=0.18749*(1.+(SystDir==0? 0.:SystDir>0? 0.559945:-0.107224 ));
    }
  }
  else if(Key=="TopHN17SST_TopHN17SSL_HasB"){
    float TightIso=0.1;
    PTCorr = El.CalcPtCone(El.MiniRelIso(), TightIso);
    if(fEta<0.8){
      if     (PTCorr<15) FR=0.;
      else if(PTCorr<20) FR=0.379217*(1.353263+(SystDir==0? 0.:SystDir>0? 0.0106956:-0.354774 ));
      else if(PTCorr<25) FR=0.224299*(1.249031+(SystDir==0? 0.:SystDir>0? 0.0359124:-0.281698 ));
      else if(PTCorr<35) FR=0.154058*(1.222836+(SystDir==0? 0.:SystDir>0? 0.0616697:-0.22729  ));
      else               FR=0.159764*(1.      +(SystDir==0? 0.:SystDir>0? 0.209737 :-0.0699418));
    }
    else if(fEta<1.479){
      if     (PTCorr<15) FR=0.;
      else if(PTCorr<20) FR=0.3647  *(1.351683+(SystDir==0? 0.:SystDir>0? 0.027291 :-0.351692));
      else if(PTCorr<25) FR=0.236944*(1.465871+(SystDir==0? 0.:SystDir>0? 0.0097618:-0.466218));
      else if(PTCorr<35) FR=0.183473*(1.64359 +(SystDir==0? 0.:SystDir>0? 0.0151806:-0.647966));
      else               FR=0.167406*(1.184503+(SystDir==0? 0.:SystDir>0? 0.0774894:-0.192329));
    }
    else{
      if     (PTCorr<15) FR=0.;
      else if(PTCorr<20) FR=0.43818 *(1.266234+(SystDir==0? 0.:SystDir>0? 0.0116451:-0.267022));
      else if(PTCorr<25) FR=0.307551*(1.460599+(SystDir==0? 0.:SystDir>0? 0.0087176:-0.463056));
      else if(PTCorr<35) FR=0.24232 *(1.263883+(SystDir==0? 0.:SystDir>0? 0.0071143:-0.264124));
      else               FR=0.18749 *(1.559198+(SystDir==0? 0.:SystDir>0? 0.107224 :-0.559945));
    }
  }

  return FR;
}


float ControlPlots::GetTestMuFR(Muon& Mu, TString Key, int SystDir){

  float FR=0., PTCorr=0., fEta=fabs(Mu.Eta());
  if(Key=="TopHN17T_TopHN17L_Incl"){
    float TightIso=0.1;
    PTCorr = Mu.CalcPtCone(Mu.MiniRelIso(), TightIso);
    if(fEta<0.9){
      if     (PTCorr<10) FR=0.;
      else if(PTCorr<15) FR=0.468723*(1.+(SystDir==0? 0.:SystDir>0? 0.0996232:-0.00039495));
      else if(PTCorr<20) FR=0.258502*(1.+(SystDir==0? 0.:SystDir>0? 0.100746 :-0.128182  ));
      else if(PTCorr<30) FR=0.170125*(1.+(SystDir==0? 0.:SystDir>0? 0.247411 :-0.0809608 ));
      else               FR=0.10884 *(1.+(SystDir==0? 0.:SystDir>0? 0.128926 :-0.166817  ));
    }
    else if(fEta<1.6){
      if     (PTCorr<10) FR=0.;
      else if(PTCorr<15) FR=0.507634*(1.+(SystDir==0? 0.:SystDir>0? 0.0767083:-0.0461033));
      else if(PTCorr<20) FR=0.302245*(1.+(SystDir==0? 0.:SystDir>0? 0.0849491:-0.0551178));
      else if(PTCorr<30) FR=0.223215*(1.+(SystDir==0? 0.:SystDir>0? 0.121284 :-0.144019 ));
      else               FR=0.150397*(1.+(SystDir==0? 0.:SystDir>0? 0.0901934:-0.212049 ));
    }
    else{
      if     (PTCorr<10) FR=0.;
      else if(PTCorr<15) FR=0.583916*(1.+(SystDir==0? 0.:SystDir>0? 0.126021 :-0.00025308));
      else if(PTCorr<20) FR=0.330751*(1.+(SystDir==0? 0.:SystDir>0? 0.153935 :-0.0504944 ));
      else if(PTCorr<30) FR=0.276111*(1.+(SystDir==0? 0.:SystDir>0? 0.17514  :-0.00782237));
      else               FR=0.211517*(1.+(SystDir==0? 0.:SystDir>0? 0.0826472:-0.0732807 ));
    }
  }

  return FR;
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


float ControlPlots::GetFlipCorrPT(Electron& El, TString Tag, TString Option){

  if(!(IsDATA  && Option.Contains("Data"))) return 0.;

  bool DoScale = Option.Contains("Scale"), DoSmear = Option.Contains("Smear");
  float PT=El.Pt(), fEta=fabs(El.Eta());
  int EtaRegIndex1 = fEta<1.47? 0:1;
  int EtaRegIndex2 = fEta<0.8? 0:fEta<1.47? 1: fEta<2.? 2:3;
  int PtRegIndex1  = PT<35? 0:PT<50? 1: 2;
  int PtRegIndex2  = PT<35? 0:PT<50? 1:PT<100? 2:3;
  int BinIndex1 = EtaRegIndex1*3+PtRegIndex1+1; 
  int BinIndex2 = EtaRegIndex2+1; 
  int BinIndex3 = PtRegIndex2 +1; 

  float PTScaleCorr=0., PTResCorr=0., ReturnPT=PT, RelRes=0.;
  if(Tag.Contains("App2Bin1_")){
    int Idx = BinIndex1;
    PTScaleCorr = Idx==1? 0.978:Idx==2? 0.981:Idx==3? 0.988:Idx==4? 0.972:Idx==5? 0.985:Idx==6? 0.990:0.;
    PTResCorr   = Idx==1?  1.38:Idx==2?  1.47:Idx==3?  1.31:Idx==4?  1.15:Idx==5?  1.08:Idx==6? 0.981:0.;
    RelRes      = Idx==1? 0.0322:Idx==2? 0.0276:Idx==3? 0.0264:Idx==4? 0.0388:Idx==5? 0.0375:Idx==6? 0.0382:0.;
  }
  else if(Tag.Contains("App2Bin2_")){//POG res.+const. scale res. matching mee dist.
    int Idx = BinIndex2;
    PTScaleCorr = 0.985;
    PTResCorr   = 1.75;
    RelRes      = Idx==1? 0.01:Idx==2? 0.0153:Idx==3? 0.0217:Idx==4? 0.0208:0.;
  }
  else if(Tag.Contains("App2Bin3_")){
    int Idx = BinIndex3;
    PTScaleCorr = Idx==1? 0.976:Idx==2? 0.985:Idx==3? 0.992:Idx==4? 0.999:0.;
    PTResCorr   = Idx==1?  1.29:Idx==2?  1.41:Idx==3?  1.32:Idx==4?  1.18:0.;
    RelRes      = Idx==1? 0.0343:Idx==2? 0.0287:Idx==3? 0.0285:Idx==4? 0.0297:0.;
  }
  PTScaleCorr = 1.-2.*(1.-PTScaleCorr);
  PTResCorr   = 1.-2.*(1.-PTResCorr);

  if(DoScale) ReturnPT = PT*PTScaleCorr;
  if(DoSmear) ReturnPT = ReturnPT*( 1.+gRandom->Gaus(0,RelRes)*sqrt(max(pow(PTResCorr,2.)-1,0.)) );

  return ReturnPT;
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

  TString AnalyzerPath=std::getenv("SKFlat_WD"), MVAPath="/data/Run2UltraLegacy_v2/2017/MVAClassifier/";
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

