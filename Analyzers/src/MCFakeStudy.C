#include "MCFakeStudy.h"

void MCFakeStudy::initializeAnalyzer(){

  ElFR=false, MuFR=false;
  LIDOpt=false, MeasMCFR=false, MCClosure=false, CompCheck=false;
  SystRun=false; 
  SpecTrig=false, NoTrig=false;
  for(unsigned int i=0; i<Userflags.size(); i++){
    if(Userflags.at(i).Contains("ElFR"))        ElFR        = true; 
    if(Userflags.at(i).Contains("MuFR"))        MuFR        = true; 
    if(Userflags.at(i).Contains("LIDOpt"))      LIDOpt      = true;
    if(Userflags.at(i).Contains("MeasMCFR"))    MeasMCFR    = true; 
    if(Userflags.at(i).Contains("MCClosure"))   MCClosure   = true; 
    if(Userflags.at(i).Contains("CompCheck"))   CompCheck   = true;
    if(Userflags.at(i).Contains("NoTrig"))      NoTrig      = true; 
    if(Userflags.at(i).Contains("SpecTrig"))    SpecTrig    = true; 
    if(Userflags.at(i).Contains("SystRun"))     SystRun     = true; 
  }

  EraShort = GetEraShort();

  TrigList_MuFR.push_back("HLT_Mu17_TrkIsoVVL_v");
  TrigList_MuFR.push_back("HLT_Mu8_TrkIsoVVL_v");
  TrigList_ElFR.push_back("HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v");
  TrigList_ElFR.push_back("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v");
  TrigList_ElFR.push_back("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v");

  if(EraShort=="2016a"){
    TrigList_DblMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v", "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v"};
    TrigList_DblEG = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"};
  }
  else if(EraShort=="2016b"){
    TrigList_DblMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v", "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v", "HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v"};
    TrigList_DblEG = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"};
  }
  else if(DataYear==2017){
    TrigList_DblMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v", "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v"};
    TrigList_DblEG = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v"};
  }
  else if(DataYear==2018){
    TrigList_DblMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v"};
    TrigList_DblEG = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v"};
  }

  //Set up the tagger map only for the param settings to be used.
  jtps.push_back( JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets) );
  mcCorr->SetJetTaggingParameters(jtps);

  TString AnalyzerPath=getenv("SKFlat_WD"), SKFlatV = getenv("SKFlatV");
  TString FilePath="/data/"+SKFlatV+"/"+GetEra()+"/FakeRate/MCFR/"+(MuFR? "MuFR/":ElFR? "ElFR/":"");
  FRFile  = new TFile(AnalyzerPath+FilePath+"FR_MC_"+GetEraShort()+".root");

  if(MCClosure){ InitializeReader(MVAReaderL, "BelowMW"); InitializeReader(MVAReaderH, "AboveMW"); }
}


void MCFakeStudy::executeEvent(){


  Event ev = GetEvent();
  float weight = 1.;
  if(!IsDATA){
    weight*=MCweight()*GetKFactor()*ev.GetTriggerLumi("Full");
    weight*=GetPileUpWeight(nPileUp, 0);
  }
  FillHist("CutFlow", 0., weight, 20, 0., 20.);

  bool PassTrig=false;
  if     (MuFR && (MCClosure)){ PassTrig = ev.PassTrigger(TrigList_DblMu); }
  else if(ElFR && (MCClosure)){ PassTrig = ev.PassTrigger(TrigList_DblEG); }
  if(LIDOpt or MeasMCFR or NoTrig or CompCheck) PassTrig=true;
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


  TString IDSSLabel = "SS";
  vector<Muon>     muonTightColl     ;
  vector<Electron> electronTightColl ;
  vector<Muon>     muonLooseColl     ;
  vector<Electron> electronLooseColl ;
  vector<Electron> electronVetoColl  ;


  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
  vector<Jet> jetPreColl = GetAllJets();
  sort(jetPreColl.begin(), jetPreColl.end(), PtComparing);
  vector<Jet> jetNoVetoColl  = SelectJets(jetPreColl, muonLooseColl, electronVetoColl, "NoID", 10., 2.4, "");
  vector<Jet> bjetNoVetoColl = SelBJets(jetNoVetoColl, param_jets);


  Particle vMET      = GetvMET("PUPPIMETT1");
  Particle vMET_T1xy = GetvMET("PUPPIMETT1xyCorr");

  bool FillGenColl = MeasMCFR or MCClosure or LIDOpt or CompCheck;
  if(FillGenColl) truthColl = GetGens();


  bool EventCand = false;//These codes ar only for MC study; correction is not needed at all, unless using for test purpose

  float w_topptrw = 1., w_prefire = 1., sf_trig = 1.;
  float sf_mutk = 1., sf_muid = 1., sf_muiso = 1., sf_elreco = 1., sf_elid = 1., sf_btag = 1.;
  if(!IsDATA && EventCand){
    //w_prefire = GetPrefireWeight(0);
    //if(MCSample.Contains("TT") and MCSample.Contains("powheg")) truthColl = GetGens();
    //w_topptrw = mcCorr->GetTopPtReweight(truthColl);
    //sf_muid   = GetMuonSF(muonTightColl, "TopHNID_TkMu", "ID");
    //sf_muiso  = GetMuonSF(muonTightColl, "POGTIso_POGTID", "Iso");
    //sf_elreco = GetElectronSF(electronLooseColl, "", "Reco");
    //sf_elid   = GetElectronSF(electronTightColl, "TopHNID"+IDSSLabel, "ID");
    //sf_btag   = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets);
    //TString SFKey_Trig_All = muonTightColl.size()==2? "DiMuIso_HNTopID":electronTightColl.size()==2? "DiElIso_HNTopIDSS":"EMuIso_HNTopIDSS"; 
    //sf_trig   = SS2l? mcCorr->GetTriggerSF(electronTightColl, muonTightColl, SFKey_Trig_All, ""):1.;
    //cout<<"w_gen:"<<w_gen<<" w_lumi:"<<w_lumi<<" w_PU:"<<w_PU<<" w_prefire:"<<w_prefire<<" sf_trig:"<<sf_trig<<endl;
    //cout<<"sf_mutk"<<sf_mutk<<" sf_muid:"<<sf_muid<<" sf_muiso:"<<sf_muiso<<" sf_elreco:"<<sf_elreco<<" sf_elid:"<<sf_elid<<" sf_btag:"<<sf_btag<<endl;
  }
  weight *= w_topptrw * w_prefire * sf_trig;
  weight *= sf_mutk * sf_muid * sf_muiso * sf_elreco * sf_elid * sf_btag;

 
  if(MuFR){
    if(LIDOpt){
      vector<Muon> muonFakeLPreOptColl = SelectMuons(muonPreColl, "POGMHLT", 5., 2.5);
      vector<Muon> FakeColl     = SkimLepColl(muonFakeLPreOptColl, truthColl, "HFake");
      vector<Muon> FakeMBColl   = SkimLepColl(FakeColl, "MB");
      vector<Muon> FakeMOColl   = SkimLepColl(FakeColl, "MO");
      vector<Muon> FakeMEColl   = SkimLepColl(FakeColl, "ME");
      vector<Jet>  JetCleanColl = SkimJetColl(jetNoVetoColl, truthColl, "NoPrNoTau");
  
      vector<double> PtEdges={10., 15., 20., 25., 35., 50., 70., 100., 200.};

  
      bool FullScanning=false, SpecificWP=false, CheckLepSrcComp=false; //IDVarDist=false, CvCheck=false, IDPerfCheck=false;
      //RunTestRun(muonFakeLPreOptColl, JetCleanColl, weight, "TopHN17L_TkIso", "TopHN17T_TkIso", "_TopHN17TLHLT", "");
      if(FullScanning){
        //For Scanning with Fine Steps
        //vector<float> MVACuts={-0.9}; vector<float> IsoCuts={0.4};
        vector<float> IsoCuts={0.4, 0.6, 0.8, 1., -1};
        vector<float> SIPCuts={3, 4, 5, 6, 7, 8, 10, 12, 14, 16, 18, 20, -1};

        for(int it_var1=0; it_var1<(int) IsoCuts.size(); it_var1++){
          for(int it_var2=0; it_var2<(int) SIPCuts.size(); it_var2++){
            float Var1Cut = IsoCuts.at(it_var1), Var2Cut = SIPCuts.at(it_var2);
            ScanFakeRate(FakeMBColl, JetCleanColl, "iso", "sip", Var1Cut, Var2Cut, PtEdges, weight,
                         "POGMHLT", "TopHNT", "_TopHN", "MBJetPtParam");
            ScanFakeRate(FakeMOColl, JetCleanColl, "iso", "sip", Var1Cut, Var2Cut, PtEdges, weight,
                         "POGMHLT", "TopHNT", "_TopHN", "MOJetPtParam");
            ScanFakeRate(FakeMEColl , JetCleanColl, "iso", "sip", Var1Cut, Var2Cut, PtEdges, weight,
                         "POGMHLT", "TopHNT", "_TopHN", "MEJetPtParam");
          }
        }
      }
      if(SpecificWP){
        MeasMCTtoLRatio(FakeColl  , JetCleanColl, PtEdges, weight, "TopHNLForTIsop10_"+GetEraShort(), "TopHNTIsop10", "_TopHNTIsop10L", "AllConePt");
        MeasMCTtoLRatio(FakeMBColl, JetCleanColl, PtEdges, weight, "TopHNLForTIsop10_"+GetEraShort(), "TopHNTIsop10", "_TopHNTIsop10L", "MBConePt");
        MeasMCTtoLRatio(FakeMOColl, JetCleanColl, PtEdges, weight, "TopHNLForTIsop10_"+GetEraShort(), "TopHNTIsop10", "_TopHNTIsop10L", "MOConePt");
        MeasMCTtoLRatio(FakeMEColl, JetCleanColl, PtEdges, weight, "TopHNLForTIsop10_"+GetEraShort(), "TopHNTIsop10", "_TopHNTIsop10L", "MEConePt");

      }
      if(CheckLepSrcComp){
        CheckSelectionEfficiency(muonPreColl, electronPreColl, jetNoVetoColl, bjetNoVetoColl, vMET, ev,
                                 "TopHN17T_TkIso", "TopHN17L_TkIso", "TopHNSST_WP90Isop1", "TopHNSSL_DynLMVAIsop4NoSIP_Pt10", weight, "_TopHN17HLT");
        CheckSelectionEfficiency(muonPreColl, electronPreColl, jetNoVetoColl, bjetNoVetoColl, vMET, ev,
                                 "TopHN17T_TkIso", "POGMHLT", "TopHNSST_WP90Isop1", "TopHNSSL_DynLMVAIsop4NoSIP_Pt10", weight, "_POGMHLT");
      }
    }
    if(MeasMCFR){
      vector<Jet> JetCleanColl = SkimJetColl(jetNoVetoColl, truthColl, "NoPrNoTau");
      EmulQCDFRMeas(muonPreColl, electronPreColl, JetCleanColl, vMET_T1xy, ev, truthColl, weight, 
                    "TopHNT", "TopHNLLIsop6NoSIP", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_TopHNT_TopHNLLIsop6NoSIP_Trig", "MuFRTrig");
      EmulQCDFRMeas(muonPreColl, electronPreColl, JetCleanColl, vMET_T1xy, ev, truthColl, weight, 
                    "TopHNT", "TopHNLLIsop6SIP8", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_TopHNT_TopHNLLIsop6SIP8_Trig", "MuFRTrig");
      EmulQCDFRMeas(muonPreColl, electronPreColl, JetCleanColl, vMET_T1xy, ev, truthColl, weight, 
                    "TopHNT", "TopHNLLIsop6SIP6", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_TopHNT_TopHNLLIsop6SIP6_Trig", "MuFRTrig");
      EmulQCDFRMeas(muonPreColl, electronPreColl, JetCleanColl, vMET_T1xy, ev, truthColl, weight, 
                    "TopHNT", "TopHNLLIsop6SIP5", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_TopHNT_TopHNLLIsop6SIP5_Trig", "MuFRTrig");
      EmulQCDFRMeas(muonPreColl, electronPreColl, JetCleanColl, vMET_T1xy, ev, truthColl, weight, 
                    "TopHNT", "TopHNLLIsop6SIP4", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_TopHNT_TopHNLLIsop6SIP4_Trig", "MuFRTrig");
      EmulQCDFRMeas(muonPreColl, electronPreColl, JetCleanColl, vMET_T1xy, ev, truthColl, weight, 
                    "TopHNT", "TopHNLLIsop6", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_TopHNT_TopHNLLIsop6_Trig", "MuFRTrig");

      EmulQCDFRMeas(muonPreColl, electronPreColl, JetCleanColl, vMET_T1xy, ev, truthColl, weight, 
                    "TopHNT", "TopHNLLIsop6NoSIP", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_TopHNT_TopHNLLIsop6NoSIP_QCDMeasSel", "MuFRQCDMeasSel");
      EmulQCDFRMeas(muonPreColl, electronPreColl, JetCleanColl, vMET_T1xy, ev, truthColl, weight, 
                    "TopHNT", "TopHNLLIsop6SIP8", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_TopHNT_TopHNLLIsop6SIP8_QCDMeasSel", "MuFRQCDMeasSel");
      EmulQCDFRMeas(muonPreColl, electronPreColl, JetCleanColl, vMET_T1xy, ev, truthColl, weight, 
                    "TopHNT", "TopHNLLIsop6SIP6", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_TopHNT_TopHNLLIsop6SIP6_QCDMeasSel", "MuFRQCDMeasSel");
      EmulQCDFRMeas(muonPreColl, electronPreColl, JetCleanColl, vMET_T1xy, ev, truthColl, weight, 
                    "TopHNT", "TopHNLLIsop6SIP5", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_TopHNT_TopHNLLIsop6SIP5_QCDMeasSel", "MuFRQCDMeasSel");
      EmulQCDFRMeas(muonPreColl, electronPreColl, JetCleanColl, vMET_T1xy, ev, truthColl, weight, 
                    "TopHNT", "TopHNLLIsop6SIP4", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_TopHNT_TopHNLLIsop6SIP4_QCDMeasSel", "MuFRQCDMeasSel");
      EmulQCDFRMeas(muonPreColl, electronPreColl, JetCleanColl, vMET_T1xy, ev, truthColl, weight, 
                    "TopHNT", "TopHNLLIsop6", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_TopHNT_TopHNLLIsop6_QCDMeasSel", "MuFRQCDMeasSel");
    }
    if(MCClosure){
      vector<TString> VarList = {""}; //{"", "FRUp", "FRDown"};
      for(unsigned int iVar=0; iVar<VarList.size(); iVar++){
        TString Var(VarList.at(iVar)), VarTag = Var!=""? "_"+Var:Var;
        CheckMCClosure(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
           "TopHNT", "TopHNLLIsop6NoSIP", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_FRTT_TopHNT_TopHNLLIsop6NoSIP"+VarTag, "TrigConeBasis"+Var);
        CheckMCClosure(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
           "TopHNT", "TopHNLLIsop6NoSIP", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_FRQCD_TopHNT_TopHNLLIsop6NoSIP"+VarTag, "TrigConeBasis"+Var);
  
        CheckMCClosure(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
          "TopHNT", "TopHNLLIsop6SIP8", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_FRTT_TopHNT_TopHNLLIsop6SIP8"+VarTag, "TrigConeBasis"+Var);
        CheckMCClosure(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
          "TopHNT", "TopHNLLIsop6SIP8", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_FRQCD_TopHNT_TopHNLLIsop6SIP8"+VarTag, "TrigConeBasis"+Var);
  
        CheckMCClosure(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
          "TopHNT", "TopHNLLIsop6SIP6", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_FRTT_TopHNT_TopHNLLIsop6SIP6"+VarTag, "TrigConeBasis"+Var);
        CheckMCClosure(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
          "TopHNT", "TopHNLLIsop6SIP6", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_FRQCD_TopHNT_TopHNLLIsop6SIP6"+VarTag, "TrigConeBasis"+Var);
  
        CheckMCClosure(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
          "TopHNT", "TopHNLLIsop6SIP5", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_FRTT_TopHNT_TopHNLLIsop6SIP5"+VarTag, "TrigConeBasis"+Var);
        CheckMCClosure(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
          "TopHNT", "TopHNLLIsop6SIP5", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_FRQCD_TopHNT_TopHNLLIsop6SIP5"+VarTag, "TrigConeBasis"+Var);
  
        CheckMCClosure(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
          "TopHNT", "TopHNLLIsop6SIP4", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_FRTT_TopHNT_TopHNLLIsop6SIP4"+VarTag, "TrigConeBasis"+Var);
        CheckMCClosure(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
          "TopHNT", "TopHNLLIsop6SIP4", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_FRQCD_TopHNT_TopHNLLIsop6SIP4"+VarTag, "TrigConeBasis"+Var);
  
        CheckMCClosure(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
          "TopHNT", "TopHNLLIsop6", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_FRTT_TopHNT_TopHNLLIsop6"+VarTag, "TrigConeBasis"+Var);
        CheckMCClosure(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
          "TopHNT", "TopHNLLIsop6", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_FRQCD_TopHNT_TopHNLLIsop6"+VarTag, "TrigConeBasis"+Var);
  
  
        CheckMCClosure(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
          "TopHNT", "TopHNLLIsop6NoSIP", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_FRQCD_TopHNT_TopHNLLIsop6NoSIP_MeasSel"+VarTag, "QCDMeasSelConeBasis"+Var);
        CheckMCClosure(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
          "TopHNT", "TopHNLLIsop6SIP8", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_FRQCD_TopHNT_TopHNLLIsop6SIP8_MeasSel"+VarTag, "QCDMeasSelConeBasis"+Var);
        CheckMCClosure(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
          "TopHNT", "TopHNLLIsop6SIP6", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_FRQCD_TopHNT_TopHNLLIsop6SIP6_MeasSel"+VarTag, "QCDMeasSelConeBasis"+Var);
        CheckMCClosure(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
          "TopHNT", "TopHNLLIsop6SIP5", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_FRQCD_TopHNT_TopHNLLIsop6SIP5_MeasSel"+VarTag, "QCDMeasSelConeBasis"+Var);
        CheckMCClosure(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
          "TopHNT", "TopHNLLIsop6SIP4", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_FRQCD_TopHNT_TopHNLLIsop6SIP4_MeasSel"+VarTag, "QCDMeasSelConeBasis"+Var);
        CheckMCClosure(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
          "TopHNT", "TopHNLLIsop6", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_FRQCD_TopHNT_TopHNLLIsop6_MeasSel"+VarTag, "QCDMeasSelConeBasis"+Var);
      }
    }
    if(CompCheck){
      if(MCSample.Contains("QCD")){
        CheckFakeComposition(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, 
                           "TopHNT", "TopHNLLIsop6SIP5", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNL_"+GetEraShort(), weight, "_MeasSel");
        CheckFakeComposition(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, 
                           "TopHNT", "TopHNLLIsop6SIP5", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNL_"+GetEraShort(), weight, "_MeasSelPOGT");
      }
      else{
        CheckFakeComposition(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, 
                           "TopHNT", "TopHNLLIsop6SIP5", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNL_"+GetEraShort(), weight, "_SRSel");
        CheckFakeComposition(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, 
                           "TopHNT", "TopHNLLIsop6SIP5", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNL_"+GetEraShort(), weight, "_SRSelPOGT");
      }
    }
  }
  if(ElFR){
    if(LIDOpt){
      vector<Electron> electronFakeLPreOptColl = SelectElectrons(electronPreColl, "TopHNSS_Isop4NoSIPMVA", 10., 2.5);
      vector<Electron> FakeColl     = SkimLepColl(electronFakeLPreOptColl, truthColl, "HFake");
      vector<Electron> FakeB1Coll   = SkimLepColl(FakeColl, "B1");
      vector<Electron> FakeB2Coll   = SkimLepColl(FakeColl, "B2");
      vector<Electron> FakeEColl    = SkimLepColl(FakeColl, "E");
      vector<Jet>      JetCleanColl = SkimJetColl(jetNoVetoColl, truthColl, "NoPrNoTau");
  
      vector<double> PtEdges={10., 15., 20., 25., 35., 50., 70., 100., 200.};

  
      bool FullScanning=true, CheckTau=false, IDVarDist=false, CvCheck=false, IDPerfCheck=false, SpecificWP=true;
      if(SpecTrig){ FullScanning=false; CvCheck=true; }
      if(CvCheck){
        CheckSelectionEfficiency(muonPreColl, electronPreColl, jetNoVetoColl, bjetNoVetoColl, vMET, ev,
                                 "TopHN17T", "TopHN17L", "TopHNSST_WP90Isop1", "TopHNSS_Isop4NoSIPMVA", weight, "_TopHNSS_Isop4NoSIPMVA");
        CheckSelectionEfficiency(muonPreColl, electronPreColl, jetNoVetoColl, bjetNoVetoColl, vMET, ev,
                                 "TopHN17T", "TopHN17L", "TopHNSST_WP90Isop1", "TopHNSSL_DynLMVAIsop4NoSIP", weight, "_TopHNSS_DynLMVAIsop4NoSIP");
      }
      if(IDPerfCheck){
        vector<TString> ElIDList = {"passVetoID", "passLooseID", "passMediumID", "passTightID", "passMVAID_noIso_WP80", "passMVAID_noIso_WP90", "passMVAID_noIso_WPLoose", "passMVAID_iso_WP80", "passMVAID_iso_WP90", "passMVAID_iso_WPLoose", "POGMVAniWP90_Isop1", "HctoWA16T", "TopHNSST_WP90Isop1", "TopHNSST_WP80Isop1", "TopHNIsoSST_WP90Isop1", "TopHNIsoSST_WP80Isop1"};
        CheckIDPerf(electronPreColl, JetCleanColl, weight, ElIDList, "", "");
        CheckIDPerf(electronPreColl, JetCleanColl, weight, ElIDList, "_Ptlt25", "PtMax25");
      }
      if(CheckTau){
        vector<Muon> muonTmpLColl = SelectMuons(muonPreColl, "TopHNL", 10., 2.4);
        CheckSelectionEfficiency(muonTmpLColl, electronFakeLPreOptColl, jetNoVetoColl, bjetNoVetoColl, vMET, ev,
                                 "TopHN17T", "TopHN17L", "TopHNSST_WP90Isop1", "TopHNSS_NoIsoMVA", weight, "_TopHNSSWP90Isop1_NoINoMva");

        vector<Electron> FakeTauhColl;
        for(unsigned int ie=0; ie<FakeColl.size(); ie++){
          bool HasMatched=false; int  ElType = GetLeptonType_JH(FakeColl.at(ie), truthColl);
          for(unsigned int it=2; it<truthColl.size() && ElType==-1 && !HasMatched; it++){
            int mIdx=FirstNonSelfMotherIdx(it, truthColl);
            int apid=abs(truthColl.at(it).PID()), ampid=mIdx>0? abs(truthColl.at(mIdx).PID()):-1;
            if( truthColl.at(it).Status()!=1 ) continue;
            if( apid>10 && apid<20 ) continue;
            if( !(ampid==15) ) continue;
            if( !(truthColl.at(it).Pt()>10) ) continue;
            if( !(FakeColl.at(ie).DeltaR(truthColl.at(it))<0.1) ) continue;
            HasMatched=true; FakeTauhColl.push_back(FakeColl.at(ie));
          }
        }
        MeasMCTtoLRatio(FakeTauhColl, jetNoVetoColl, PtEdges, weight, "TopHNIsoSSL_Mva0Isop2", "TopHNSST_WP80Isop1", "_TopHNSSWP90Isop1_Mva0Isop2_Tauh", "All");
        MeasMCTtoLRatio(FakeTauhColl, jetNoVetoColl, PtEdges, weight, "TopHNIsoSSL_Mvam1Isop1", "TopHNSST_WP80Isop1", "_TopHNSSWP90Isop1_Mvam1_Tauh", "All");
        MeasMCTtoLRatio(FakeColl, JetCleanColl, PtEdges, weight, "TopHNIsoSSL_Mva0Isop2", "TopHNSST_WP80Isop1", "_TopHNSSWP90Isop1_Mva0Isop2", "All");
        MeasMCTtoLRatio(FakeColl, JetCleanColl, PtEdges, weight, "TopHNIsoSSL_Mvam1Isop1", "TopHNSST_WP80Isop1", "_TopHNSSWP90Isop1_Mvam1", "All");
      }
      if(IDVarDist){
        bool MVACutDist=false;
        CheckIDVarDist(electronPreColl, JetCleanColl, weight, "NoID", "_NoID", "");
        CheckIDVarDist(electronFakeLPreOptColl, JetCleanColl, weight, "TopHNSS_NoIsoMVA", "_TopHNSSNoIsoMVA", "");
        CheckIDVarDist(electronFakeLPreOptColl, JetCleanColl, weight, "TopHNSS_Isop4NoSIPMVA", "_TopHNSSIsop4NoSIPMVA", "");
        CheckIDVarDist(electronFakeLPreOptColl, JetCleanColl, weight, "TopHNSST_WP90Isop1", "_TopHNSSTWP90Isop1", "");
        CheckIDVarDist(electronFakeLPreOptColl, JetCleanColl, weight, "TopHNSST_WP90Isop1", "_TopHNSSTWP90Isop1_Ptlt25", "PtMax25");

        if(MVACutDist) CheckMVACutDist(electronPreColl, weight, "_NoID");
      }
      if(FullScanning){
        //For Scanning with Fine Steps
        //vector<float> MVACuts={-0.9}; vector<float> IsoCuts={0.4};
        //vector<float> IsoCuts={-1., 0.1, 0.2, 0.4};
        vector<float> IsoCuts={0.4};
        //vector<float> MVACuts={-1., -0.9, -0.8, -0.7, -0.6, -0.5, -0.4, -0.3, -0.2, -0.1, 0., 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 0.99, 0.999, 1.};
        vector<float> MVACuts={-0.7, -0.69, -0.68, -0.67, -0.66, -0.65, -0.64, -0.63, -0.62, -0.61,
                               -0.6, -0.59, -0.58, -0.57, -0.56, -0.55, -0.54, -0.53, -0.52, -0.51,
                               -0.5, -0.49, -0.48, -0.47, -0.46, -0.45, -0.44, -0.43, -0.42, -0.41,
                               -0.4, -0.39, -0.38, -0.37, -0.36, -0.35, -0.34, -0.33, -0.32, -0.31,
                               -0.3, -0.29, -0.28, -0.27, -0.26, -0.25, -0.24, -0.23, -0.22, -0.21,
                               -0.2, -0.19, -0.18, -0.17, -0.16, -0.15, -0.14, -0.13, -0.12, -0.11,
                               -0.1, -0.09, -0.08, -0.07, -0.06, -0.05, -0.04, -0.03, -0.02, -0.01,
                                0.0,  0.01,  0.02,  0.03,  0.04,  0.05,  0.06,  0.07,  0.08,  0.09,
                                0.1,  0.11,  0.12,  0.13,  0.14,  0.15,  0.16,  0.17,  0.18,  0.19,
                                0.2,  0.21,  0.22,  0.23,  0.24,  0.25,  0.26,  0.27,  0.28,  0.29,
                                0.3,  0.31,  0.32,  0.33,  0.34,  0.35,  0.36,  0.37,  0.38,  0.39,
                                0.4,  0.41,  0.42,  0.43,  0.44,  0.45,  0.46,  0.47,  0.48,  0.49,
                                0.5,  0.51,  0.52,  0.53,  0.54,  0.55,  0.56,  0.57,  0.58,  0.59,
                                0.6,  0.61,  0.62,  0.63,  0.64,  0.65,  0.66,  0.67,  0.68,  0.69,
                                0.7,  0.71,  0.72,  0.73,  0.74,  0.75,  0.76,  0.77,  0.78,  0.79,
                                0.8,  0.81,  0.82,  0.83,  0.84,  0.85,  0.86,  0.87,  0.88,  0.89,
                                0.9,  0.91,  0.92,  0.93,  0.94,  0.95,  0.96,  0.97,  0.98,  0.99,
                                0.991, 0.992, 0.993, 0.994, 0.995, 0.996, 0.997, 0.998, 0.999, 1.};
        vector<float> SIPCuts={-1};
        if(SpecificWP){
          //previous
          MeasMCTtoLRatio(FakeColl  , JetCleanColl, PtEdges, weight, "TopHN17SSL", "TopHN17SST", "_TopHN17SST_17L", "All");
          MeasMCTtoLRatio(FakeB1Coll, JetCleanColl, PtEdges, weight, "TopHN17SSL", "TopHN17SST", "_TopHN17SST_17L", "B1");
          MeasMCTtoLRatio(FakeB2Coll, JetCleanColl, PtEdges, weight, "TopHN17SSL", "TopHN17SST", "_TopHN17SST_17L", "B2");
          MeasMCTtoLRatio(FakeEColl , JetCleanColl, PtEdges, weight, "TopHN17SSL", "TopHN17SST", "_TopHN17SST_17L", "E");
          //only iso projection
          MeasMCTtoLRatio(FakeColl  , JetCleanColl, PtEdges, weight, "TopHNSSL_WP90Isop4", "TopHNSST", "_TopHNSST_Isop4", "All");
          MeasMCTtoLRatio(FakeB1Coll, JetCleanColl, PtEdges, weight, "TopHNSSL_WP90Isop4", "TopHNSST", "_TopHNSST_Isop4", "B1");
          MeasMCTtoLRatio(FakeB2Coll, JetCleanColl, PtEdges, weight, "TopHNSSL_WP90Isop4", "TopHNSST", "_TopHNSST_Isop4", "B2");
          MeasMCTtoLRatio(FakeEColl , JetCleanColl, PtEdges, weight, "TopHNSSL_WP90Isop4", "TopHNSST", "_TopHNSST_Isop4", "E");
          //Fixed Loose MVA + LooseIso + LooseSIP
          MeasMCTtoLRatio(FakeColl  , JetCleanColl, PtEdges, weight, "TopHNSSL_"+EraShort, "TopHNSST", "_TopHNSST_FixLMVAIsop4NoSIP", "All");
          MeasMCTtoLRatio(FakeB1Coll, JetCleanColl, PtEdges, weight, "TopHNSSL_"+EraShort, "TopHNSST", "_TopHNSST_FixLMVAIsop4NoSIP", "B1");
          MeasMCTtoLRatio(FakeB2Coll, JetCleanColl, PtEdges, weight, "TopHNSSL_"+EraShort, "TopHNSST", "_TopHNSST_FixLMVAIsop4NoSIP", "B2");
          MeasMCTtoLRatio(FakeEColl , JetCleanColl, PtEdges, weight, "TopHNSSL_"+EraShort, "TopHNSST", "_TopHNSST_FixLMVAIsop4NoSIP", "E");
        }

        for(int it_var1=0; it_var1<(int) MVACuts.size() && !SpecificWP; it_var1++){
          for(int it_var2=0; it_var2<(int) SIPCuts.size(); it_var2++){
        //for(int it_var2=0; it_var2<(int) IsoCuts.size(); it_var2++){
            //float Var1Cut = MVACuts.at(it_var1), Var2Cut = IsoCuts.at(it_var2);
            float Var1Cut = MVACuts.at(it_var1), Var2Cut = SIPCuts.at(it_var2);
//            ScanFakeRate(FakeB1Coll, JetCleanColl, "mva", "sip", Var1Cut, Var2Cut, PtEdges, weight,
//                         "TopHNSS_Isop4NoSIPMVA", "TopHNSSTWP90Isop1", "_TopHNSSWP90Isop1", "B1ConePt");
//            ScanFakeRate(FakeB2Coll, JetCleanColl, "mva", "sip", Var1Cut, Var2Cut, PtEdges, weight,
//                         "TopHNSS_Isop4NoSIPMVA", "TopHNSSTWP90Isop1", "_TopHNSSWP90Isop1", "B2ConePt");
//            ScanFakeRate(FakeEColl , JetCleanColl, "mva", "sip", Var1Cut, Var2Cut, PtEdges, weight,
//                         "TopHNSS_Isop4NoSIPMVA", "TopHNSSTWP90Isop1", "_TopHNSSWP90Isop1", "EConePt");

            ScanFakeRate(FakeB1Coll, JetCleanColl, "mva", "sip", Var1Cut, Var2Cut, PtEdges, weight,
                         "TopHNSS_Isop4NoSIPMVA", "TopHNSST", "_TopHNSST", "B1ConePt");
            ScanFakeRate(FakeB2Coll, JetCleanColl, "mva", "sip", Var1Cut, Var2Cut, PtEdges, weight,
                         "TopHNSS_Isop4NoSIPMVA", "TopHNSST", "_TopHNSST", "B2ConePt");
            ScanFakeRate(FakeEColl , JetCleanColl, "mva", "sip", Var1Cut, Var2Cut, PtEdges, weight,
                         "TopHNSS_Isop4NoSIPMVA", "TopHNSST", "_TopHNSST", "EConePt");

          }
        }
      }
    }
    if(MeasMCFR){
      EmulQCDFRMeas(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
                    "TopHNT", "TopHNL", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_TopHNSST_TopHNSSL", "ElFR");
      EmulQCDFRMeas(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
                    "TopHNT", "TopHNL", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_TopHNSST_TopHNSSL_Trig", "ElFRTrig");
      EmulQCDFRMeas(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
                    "TopHNT", "TopHNL", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_TopHNSST_TopHNSSL_QCDMeasSel", "ElFRQCDMeasSel");
    }
    if(MCClosure){
      vector<TString> VarList = {""}; //{"", "FRUp", "FRDown"};
      for(unsigned int iVar=0; iVar<VarList.size(); iVar++){
        TString Var(VarList.at(iVar)), VarTag = Var!=""? "_"+Var:Var;
        CheckMCClosure(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
                       "TopHNT", "TopHNLLIsop6SIP5", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_FRTT_TopHNSST_TopHNSSL"+VarTag, "ConeBasis"+Var);
        CheckMCClosure(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
                       "TopHNT", "TopHNLLIsop6SIP5", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_FRQCD_TopHNSST_TopHNSSL"+VarTag, "ConeBasis"+Var);
        CheckMCClosure(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
                       "TopHNT", "TopHNLLIsop6SIP5", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_FRTT_TopHNSST_TopHNSSL_Trig"+VarTag, "TrigConeBasis"+Var);
        CheckMCClosure(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
                       "TopHNT", "TopHNLLIsop6SIP5", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_FRQCD_TopHNSST_TopHNSSL_Trig"+VarTag, "TrigConeBasis"+Var);
        CheckMCClosure(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, truthColl, weight, 
                       "TopHNT", "TopHNLLIsop6SIP5", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNV", "_FRQCD_TopHNSST_TopHNSSL_MeasSel"+VarTag, "QCDMeasSelConeBasis"+Var);
      }
    }
    if(CompCheck){
      if(MCSample.Contains("QCD")){
        CheckFakeComposition(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, 
                           "TopHNT", "TopHNLLIsop6SIP5", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNL_"+GetEraShort(), weight, "_MeasSel");
      }
      else{
        CheckFakeComposition(muonPreColl, electronPreColl, jetPreColl, vMET_T1xy, ev, 
                           "TopHNT", "TopHNLLIsop6SIP5", "TopHNSST", "TopHNSSL_"+GetEraShort(), "TopHNL_"+GetEraShort(), weight, "_SRSel");
      }
    }
  }

}


void MCFakeStudy::CheckFakeComposition(vector<Muon>& MuRawColl, vector<Electron>& ElRawColl, vector<Jet>& JetRawColl, Particle& vMET, Event& ev,
                                       TString MuTID, TString MuLID, TString ElTID, TString ElLID, TString ElVID, float weight, TString Label)
{
  bool SelQCD = Label.Contains("MeasSel"), SelSR = Label.Contains("SRSel"), ApplyPOGT = Label.Contains("POGT");
  bool IsSRSB = false, IsSR = false;
  vector<Muon>     MuTColl  = SelectMuons    (MuRawColl, MuTID, 10., 2.4);
  vector<Muon>     MuLColl  = SelectMuons    (MuRawColl, MuLID, 10., 2.4);
  vector<Electron> ElTColl  = SelectElectrons(ElRawColl, ElTID, 15., 2.5);
  vector<Electron> ElLColl  = SelectElectrons(ElRawColl, ElLID, 15., 2.5);
  vector<Electron> ElVColl  = SelectElectrons(ElRawColl, ElVID, 10., 2.5);

  vector<Jet>  JetVetoColl  = SelectJets(JetRawColl, MuLColl, ElVColl, "tightLepVeto", 25., 2.4, "LVeto");
  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
  vector<Jet>  BJetVetoColl = SelBJets  (JetVetoColl, param_jets);

  if(SelQCD){
    bool PassFRMeas_Mu17=false, PassFRMeas_Mu8=false; bool PassFRMeas_El23=false, PassFRMeas_El12=false;
    TString MinPtElStr=ElTID.Contains("SS")? "_Pt15":"_Pt10";
    PassFRMeas_Mu17 = PassFRMeasSel(MuTColl, MuLColl, ElTColl, ElLColl, ElVColl, JetVetoColl, BJetVetoColl, vMET, ev, "TrigMu17");
    PassFRMeas_Mu8  = PassFRMeasSel(MuTColl, MuLColl, ElTColl, ElLColl, ElVColl, JetVetoColl, BJetVetoColl, vMET, ev, "TrigMu8");
    PassFRMeas_El23 = PassFRMeasSel(MuTColl, MuLColl, ElTColl, ElLColl, ElVColl, JetVetoColl, BJetVetoColl, vMET, ev, "TrigEl23"+MinPtElStr);
    PassFRMeas_El12 = PassFRMeasSel(MuTColl, MuLColl, ElTColl, ElLColl, ElVColl, JetVetoColl, BJetVetoColl, vMET, ev, "TrigEl12"+MinPtElStr);
    if(!(PassFRMeas_Mu17 or PassFRMeas_Mu8 or PassFRMeas_El23 or PassFRMeas_El12)) return;
  }
  if(SelSR){
    int NMuT=MuTColl.size(), NMuL=MuLColl.size(), NMuV=MuLColl.size(), NElT=ElTColl.size(), NElL=ElLColl.size(), NElV=ElVColl.size();
    int NJet=JetVetoColl.size(), NBJet=BJetVetoColl.size(), NLJet=NJet-NBJet; 
    int Qtot = SumCharge(MuLColl, ElLColl);
    if( !( (NMuL==2 && NElL==0) or (NMuL==0 && NElL==2) ) ) return;
    if( !( NMuL==NMuV && NElL==NElV ) ) return;
    if( abs(Qtot)!=2 ) return;
    if(NMuL==2){
      if( !ev.PassTrigger(TrigList_DblMu) ) return;
      if( !(MuLColl.at(0).Pt()>20 && MuLColl.at(1).Pt()>10) ) return;
      if( (MuLColl.at(0)+MuLColl.at(1)).M()<4 ) return;
    }
    if(NElL==2){
      if( !ev.PassTrigger(TrigList_DblEG) ) return;
      if( !(ElLColl.at(0).Pt()>25 && ElLColl.at(1).Pt()>15) ) return;
      if( fabs( (ElLColl.at(0)+ElLColl.at(1)).M()-91.2 )<10 ) return;
    }
    if( !(NJet>=3 && NBJet>=1 && NLJet>=1) ) return;
    if( NMuT==2 or NElT==2 ) IsSR = true;
    IsSRSB = !IsSR;
    if(IsSR  ) Label+="_SR";
    if(IsSRSB) Label+="_SRSB";
  }

  for(unsigned int im=0; im<MuLColl.size() && MuFR; im++){
    Muon* Mu = &MuLColl.at(im);
    bool PassTID = Mu->PassID(MuTID);
    bool PassPOG = ApplyPOGT? Mu->PassID("POGTight"):true;
    int  SrcType = GetFakeLepSrcType(*Mu, JetRawColl);
    int  LepType = GetLeptonType_JH(*Mu,truthColl);
    float fEta   = fabs(Mu->Eta());
    if(ApplyPOGT && !PassPOG  ) continue;
    if(LepType>0 or LepType<-4) continue;
    TString EtaReg = fEta<0.9? "Reg1":fEta<1.6? "Reg2":"Reg3";

    vector<TString> TagList = {Label, EtaReg+Label};
    if(PassTID){ TagList.push_back("_TID"+Label); TagList.push_back("_TID"+EtaReg+Label); }
    for(unsigned itag=0; itag<TagList.size(); itag++){
      TString Tag(TagList.at(itag));
      FillHist("FakeLepType_Mu"+Tag+Label, LepType, weight, 5, -4., 1.);
      FillHist("FakeSrcType_Mu"+Tag+Label, SrcType, weight, 5, -1., 4.);
      FillHist("FakeLepTSrcT_Mu"+Tag+Label, LepType, SrcType, weight, 5, -4., 1., 5, -1., 4.);
    }
  }

  for(unsigned int ie=0; ie<ElLColl.size() && ElFR; ie++){
    Electron* El = &ElLColl.at(ie);
    bool PassTID = El->PassID(ElTID);
    int  SrcType = GetFakeLepSrcType(*El, JetRawColl);
    int  LepType = GetLeptonType_JH(*El,truthColl);
    float fEta   = fabs(El->Eta());
    if(LepType>0 or LepType<-4) continue;
    TString EtaReg = fEta<0.8? "Reg1":fEta<1.5? "Reg2":"Reg3";

    vector<TString> TagList = {Label, EtaReg+Label};
    if(PassTID){ TagList.push_back("_TID"+Label); TagList.push_back("_TID"+EtaReg+Label); }
    for(unsigned itag=0; itag<TagList.size(); itag++){
      TString Tag(TagList.at(itag));
      FillHist("FakeLepType_El"+Tag+Label, LepType, weight, 5, -4., 1.);
      FillHist("FakeSrcType_El"+Tag+Label, SrcType, weight, 5, -1., 4.);
      FillHist("FakeLepTSrcT_El"+Tag+Label, LepType, SrcType, weight, 5, -4., 1., 5, -1., 4.);
    }
  }

}


void MCFakeStudy::CheckSelectionEfficiency(
vector<Muon>& MuRawColl, vector<Electron>& ElRawColl, vector<Jet>& JetRawColl, vector<Jet>& BJetRawColl, Particle& vMET, Event& ev,
TString MuTID, TString MuLID, TString ElTID, TString ElLID, float weight, TString Label){

  vector<Electron> ElTColl, ElLColl;
    for(unsigned int ie=0; ie<ElRawColl.size(); ie++){ if(ElRawColl.at(ie).PassID(ElTID)) ElTColl.push_back(ElRawColl.at(ie)); }
    for(unsigned int ie=0; ie<ElRawColl.size(); ie++){ if(ElRawColl.at(ie).PassID(ElLID)) ElLColl.push_back(ElRawColl.at(ie)); }
  vector<Muon> MuTColl, MuLColl;
    for(unsigned int im=0; im<MuRawColl.size(); im++){ if(MuRawColl.at(im).PassID(MuTID)) MuTColl.push_back(MuRawColl.at(im)); }
    for(unsigned int im=0; im<MuRawColl.size(); im++){ if(MuRawColl.at(im).PassID(MuLID)) MuLColl.push_back(MuRawColl.at(im)); }

  vector<Jet> JetColl = JetsVetoLeptonInside(JetRawColl, ElLColl, MuLColl, 0.4);
  vector<Jet> BJetColl = JetsVetoLeptonInside(BJetRawColl, ElLColl, MuLColl, 0.4);

  int NPrL=0, NPrTaL=0, NPrTah=0, NHFk=0, NExCv=0;
  bool PassTT=false;
  if(ElFR){
    if( !(ElLColl.size()==2) ) return;
    if( !(MuLColl.size()==0 && MuTColl.size()==0) ) return;
    if(!(ElLColl.at(0).Pt()>25 && ElLColl.at(1).Pt()>15) ) return;
    if( ElLColl.at(0).Charge() != ElLColl.at(1).Charge() ) return;
    if(fabs((ElLColl.at(0)+ElLColl.at(1)).M()-91.2)<10   ) return;
    if( !(JetColl.size()>2 && BJetColl.size()>0) ) return;
    if( ElTColl.size()==2 ) PassTT=true;
  
    for(unsigned int ie=0; ie<ElLColl.size(); ie++){
      bool HasMatched=false, IsPr=false, IsPrTaL=false, IsHFk=false, IsExCv=false;
      int  ElType = GetLeptonType_JH(ElLColl.at(ie), truthColl);
      IsPr = ElType>0 && ElType!=3, IsPrTaL = ElType==3, IsHFk=ElType<0 && ElType>-5, IsExCv=ElType<-4;
      if     (IsPr   ) NPrL++;
      else if(IsPrTaL) NPrTaL++;
      else if(IsHFk  ) NHFk++;
      else if(IsExCv ) NExCv++;
  
      for(unsigned int it=2; it<truthColl.size() && IsHFk && !HasMatched; it++){
        int mIdx = FirstNonSelfMotherIdx(it, truthColl), grmIdx = FirstNonSelfMotherIdx(mIdx, truthColl);
        int mIdx_1st = LastSelfMotherIdx(mIdx,truthColl); 
        int apid=abs(truthColl.at(it).PID()), ampid=mIdx!=-1? abs(truthColl.at(mIdx).PID()):-1;
        int MSt_1st = mIdx_1st!=-1? truthColl.at(mIdx_1st).Status():-1;
        int agrmpid = grmIdx!=-1? abs(truthColl.at(grmIdx).PID()):-1;
        if( truthColl.at(it).Status()!=1 ) continue;
        if( apid>10 && apid<20 ) continue;
        if( !(ampid==15) ) continue;
        if( !(truthColl.at(it).Pt()>10) ) continue;//PT(mom)>PT(daughter)
        if( !( (agrmpid>=23 && agrmpid<=25) or (MSt_1st>20 && MSt_1st<30) ) ) continue; 
        if( !(ElLColl.at(ie).DeltaR(truthColl.at(it))<0.1) ) continue;
        NPrTah++; HasMatched=true;
      }
    }
  }
  else if(MuFR){
    if( !(MuLColl.size()==2) ) return;
    if( !(ElLColl.size()==0 && ElTColl.size()==0) ) return;
    if(!(MuLColl.at(0).Pt()>20 && MuLColl.at(1).Pt()>10) ) return;
    if( MuLColl.at(0).Charge() != MuLColl.at(1).Charge() ) return;
    if( (MuLColl.at(0)+MuLColl.at(1)).M()<4      ) return;
    if( !(JetColl.size()>2 && BJetColl.size()>0) ) return;
    if( MuTColl.size()==2 ) PassTT=true;
  
    for(unsigned int im=0; im<MuLColl.size(); im++){
      bool IsPrL=false, IsPrTaL=false, IsHFk=false, IsExCv=false;
      int  MuType = GetLeptonType_JH(MuLColl.at(im), truthColl);
      IsPrL = MuType>0 && MuType!=3, IsPrTaL=MuType==3, IsHFk=MuType<0 && MuType>-5, IsExCv=MuType<-4;
      if     (IsPrL  ) NPrL++;
      else if(IsPrTaL) NPrTaL++;
      else if(IsHFk  ) NHFk++;
      else if(IsExCv ) NExCv++;
    }
  }
  else return;

  //if(NPrL==2) return;
  //if(NHFake==0) return;
  TString TypeStr("");
  if     (NPrL  ==1 && NPrTah==1 ) TypeStr="_1PL1PTah";
  else if(NPrTaL==1 && NPrTah==1 ) TypeStr="_1PTaL1PTah";
  else if(NHFk  ==2 && NPrTah==1 ) TypeStr="_1FkJ1PTah";
  else if(NExCv ==1 && NPrTah==1 ) TypeStr="_1Cv1PTah";
  else if(NPrL  ==1 && NPrTah==0 && NHFk==1) TypeStr="_1PL1FkJ";
  else if(NPrTaL==1 && NPrTah==0 && NHFk==1) TypeStr="_1PTaL1FkJ";
  else if(NExCv ==1 && NPrTah==0 && NHFk==1) TypeStr="_1Cv1FkJ";
  else if(NPrL  ==1 && NPrTaL==1 ) TypeStr="_1PL1PTaL";
  else if(NPrL  ==1 && NExCv==1  ) TypeStr="_1PL1Cv";
  else if(NPrTaL==1 && NExCv==1  ) TypeStr="_1PTaL1Cv";
  else if(       NPrTah==2       ) TypeStr="_2PTah";
  else if(NHFk  ==2 && NPrTah ==0) TypeStr="_2FkJ";
  else if(       NPrL==2         ) TypeStr="_2PL";
  else if(      NPrTaL==2        ) TypeStr="_2PTaL";
  else if(      NExCv==2         ) TypeStr="_2Cv";
  else                             TypeStr="_Else";

  //All
  FillHist("NEvt"+Label, 0, weight, 2, 0., 2.); 
  if(PassTT) FillHist("NEvt"+Label, 1, weight, 2, 0., 2.);

  //Per Type
  FillHist("NEvt"+TypeStr+Label, 0, weight, 2, 0., 2.); 
  if(PassTT) FillHist("NEvt"+TypeStr+Label, 1, weight, 2, 0., 2.);

}


void MCFakeStudy::RunTestRun(vector<Muon>& FakePreColl, vector<Jet>& JetCleanColl, float weight, TString PreID, TString TightID, TString Label, TString Option){

  vector<double> EtaEdges = {0., 0.5, 0.9, 1.2, 1.6, 2.1, 2.4};
  vector<double> PtEdges  = {10, 15, 20, 25, 35, 50, 70, 100, 200};

  for(unsigned int im=0; im<FakePreColl.size(); im++){
    Muon* Mu = &FakePreColl.at(im);
    float TightIso=0.1;
    float PT=Mu->Pt(), fEta = fabs(Mu->Eta()), PTCorr = Mu->CalcPtCone(Mu->MiniRelIso(), TightIso);
    float PTMax = Option.Contains("PtMax25")? 25:-1;
    if( PT < 10 ) continue;
    if( PTMax>0 && PT>PTMax ) continue;
    if( !Mu->PassID(PreID) ) continue;

    int  LepType = GetLeptonType_JH(*Mu,truthColl);
    bool IsPr = LepType>0 && LepType!=3, IsPrTa = LepType==3, IsExCv = LepType<-4, IsHMisReco = LepType==-1, IsHNonPrMu = LepType>-5 && LepType<-1;
    bool IsHFk = IsHMisReco or IsHNonPrMu;
    int  MatchJetType = IsHFk? GetFakeLepSrcType(*Mu, JetCleanColl):0;

    TString MuType  = IsPr? "_Pr": IsExCv? "_ExCv": IsHFk? "_HFk":"";
    TString SrcType = MatchJetType==3? "_BjMatch": MatchJetType==2? "_CjMatch": MatchJetType==1? "_LjMatch":
                      MatchJetType==-1? "_NoMatch": "";

    FillHist("NCnt_MuJMatch"+Label, MatchJetType, weight, 5, -1., 4.);
    FillHist("LepType"+Label, LepType, weight, 20, -10., 10.);
    if(LepType==0) FillHist("NCntLTypeErr"+Label, 0., weight, 1, 0., 1.);
    if(IsHFk && MatchJetType<=0) continue; //Checked to be ignorable & irrelevant to study
    if(IsExCv or IsPrTa) continue;

    vector<TString> LabelList;
    LabelList.push_back(Label);
    LabelList.push_back(MuType+SrcType+Label);

    for(unsigned int il=0; il<LabelList.size(); il++){
      TString FinLabel = LabelList.at(il);
      FillHist("MuSumW_All_PT_FR1D"+FinLabel, PTCorr, weight, PtEdges.size()-1, &PtEdges[0]);
      FillHist("MuSumW_All_fEta_FR1D"+FinLabel, fEta, weight, EtaEdges.size()-1, &EtaEdges[0]);
      FillHist("MuSumW_All_PTfEta_FR2D"+FinLabel, PTCorr, fEta, weight, PtEdges.size()-1, &PtEdges[0], EtaEdges.size()-1, &EtaEdges[0]);
      if(Mu->PassID(TightID)){
        FillHist("MuIDSumW_All_PT_FR1D"+FinLabel, PTCorr, weight, PtEdges.size()-1, &PtEdges[0]);
        FillHist("MuIDSumW_All_fEta_FR1D"+FinLabel, fEta, weight, EtaEdges.size()-1, &EtaEdges[0]);
        FillHist("MuIDSumW_All_PTfEta_FR2D"+FinLabel, PTCorr, fEta, weight, PtEdges.size()-1, &PtEdges[0], EtaEdges.size()-1, &EtaEdges[0]);
      }
    }
  }
}


void MCFakeStudy::RunTestRun(vector<Electron>& FakePreColl, vector<Jet>& JetColl, float MVACut, float IsoCut, vector<double>& PtEdges, float weight, TString PreID, TString TightID, TString Label, TString Option){

  vector<Electron> FakeColl;
    for(unsigned int i=0; i<FakePreColl.size(); i++){ if(FakePreColl.at(i).PassID(PreID)) FakeColl.push_back(FakePreColl.at(i)); }

  std::ostringstream s1,s2;
  s1<<MVACut; s2<<IsoCut;
  TString Str_MVACut=s1.str(); Str_MVACut.ReplaceAll(".","p"); Str_MVACut.ReplaceAll("-","m");
  TString Str_IsoCut=s2.str(); Str_IsoCut.ReplaceAll(".","p");
  
  TString EtaReg="";
  if(Option.Contains("B1")) EtaReg="B1";
  else if(Option.Contains("B2")) EtaReg="B2";
  else if(Option.Contains("E")) EtaReg="E";
  else if(Option.Contains("All")) EtaReg="";

  float TightIso=0.;
  if     (TightID.Contains("Isop1"))  TightIso=0.1;
  else if(TightID.Contains("Isop08")) TightIso=0.08;
  else if(TightID.Contains("TopHN17")) TightIso=0.1;
  else   { printf("no matched iso wp.\n"); return; }

  //bool MVAInclIso = Label.Contains("TopHNIso");

  for(unsigned int i=0; i<FakeColl.size(); i++){
    float mRelIso = FakeColl.at(i).MiniRelIso();
    float RelIso  = FakeColl.at(i).RelIso();
    float MVA     = FakeColl.at(i).MVANoIso();
    float MVAIso  = FakeColl.at(i).MVAIso();
    float PTCorr      = FakeColl.at(i).CalcPtCone(RelIso,TightIso);
    int   FakeSrcType = GetFakeLepSrcType(FakeColl.at(i), JetColl);

    if(PTCorr<10.   ) continue;
    if(RelIso >0.4) RelIso =0.4-1E-6;
    if(mRelIso>0.4) mRelIso=0.4-1E-6;
    TString MatchTag = FakeSrcType==3? "_BjMatch": FakeSrcType==2? "_CjMatch": FakeSrcType==1? "_LjMatch":"_NoMatch";
    FillHist("MVA_Eta"+EtaReg+"_All"+Label, MVA, weight, 40, -1., 1.);;
    FillHist("mRelIso_Eta"+EtaReg+"_All"+Label, mRelIso, weight, 40, 0., 0.4);;
    FillHist("MVAIso_Eta"+EtaReg+"_All"+Label, MVAIso, weight, 40, -1., 1.);;
    FillHist("RelIso_Eta"+EtaReg+"_All"+Label, RelIso, weight, 40, 0., 0.4);;

    FillHist("MVA_Eta"+EtaReg+MatchTag+Label, MVA, weight, 40, -1., 1.);;
    FillHist("mRelIso_Eta"+EtaReg+MatchTag+Label, mRelIso, weight, 40, 0., 0.4);;
    FillHist("MVAIso_Eta"+EtaReg+MatchTag+Label, MVAIso, weight, 40, -1., 1.);;
    FillHist("RelIso_Eta"+EtaReg+MatchTag+Label, RelIso, weight, 40, 0., 0.4);;
    FillHist("FakeSrcType_Eta"+EtaReg+Label, FakeSrcType, weight, 10, -5, 5);

  }//End of Fake Lepton Loop 


}


void MCFakeStudy::CheckMVACutDist(vector<Electron>& ElColl, float weight, TString Label, TString Option){

  for(unsigned int ie=0; ie<ElColl.size(); ie++){
    Electron* El = &ElColl.at(ie);
    float PT=El->Pt(), fEta=fabs(El->scEta());
    if( PT < 10 ) continue;
    if( El->etaRegion()==Electron::EtaRegion::GAP ) continue;
    TString EtaReg  = fEta<0.8? "B1": fEta<1.479? "B2": "E"; 

    vector<double> MVAEdges = {1E-6, 2E-6, 5E-6, 1E-5, 2E-5, 5E-5, 1E-4, 2E-4, 5E-4, 1E-3, 2E-3, 5E-3, 1E-2, 2E-2, 5E-2, 1E-1, 2E-1};
    vector<double> PtEdges  = {10., 15., 20., 25., 30., 40., 50., 70., 100., 200.};
    const int NMVAEdges=(const int) MVAEdges.size(), NPtEdges=(const int) PtEdges.size();

    FillHist("Elnoiso"+EtaReg+"_PT_MVA"+Label, PT, fabs(El->MVANoIso()-1.), weight, NPtEdges-1, &PtEdges[0], NMVAEdges-1, &MVAEdges[0]);
    FillHist("Eliso"+EtaReg+"_PT_MVA"+Label, PT, fabs(El->MVAIso()-1.), weight, NPtEdges-1, &PtEdges[0], NMVAEdges-1, &MVAEdges[0]);
    if(El->passMVAID_noIso_WP80()){
      FillHist("ElWP90noiso"+EtaReg+"_PT_MVA"+Label, PT, fabs(El->MVANoIso()-1.), weight, NPtEdges-1, &PtEdges[0], NMVAEdges-1, &MVAEdges[0]);
    }
    if(El->passMVAID_noIso_WP80()){
      FillHist("ElWP80noiso"+EtaReg+"_PT_MVA"+Label, PT, fabs(El->MVANoIso()-1.), weight, NPtEdges-1, &PtEdges[0], NMVAEdges-1, &MVAEdges[0]);
    }
    if(El->passMVAID_iso_WP80()){
      FillHist("ElWP90iso"+EtaReg+"_PT_MVA"+Label, PT, fabs(El->MVAIso()-1.), weight, NPtEdges-1, &PtEdges[0], NMVAEdges-1, &MVAEdges[0]);
    }
    if(El->passMVAID_iso_WP80()){
      FillHist("ElWP80iso"+EtaReg+"_PT_MVA"+Label, PT, fabs(El->MVAIso()-1.), weight, NPtEdges-1, &PtEdges[0], NMVAEdges-1, &MVAEdges[0]);
    }
  }

}


void MCFakeStudy::CheckIDPerf(vector<Electron>& ElRawColl, vector<Jet>& JetCleanColl, float weight, vector<TString>& ElIDList, TString Label, TString Option){

  for(unsigned int ie=0; ie<ElRawColl.size(); ie++){
    Electron* El = &ElRawColl.at(ie);
    float PT=El->Pt();
    float PTMax = Option.Contains("PtMax25")? 25:-1;
    if( PT < 10 ) continue;
    if( PTMax>0 && PT>PTMax ) continue;
    if( El->etaRegion()==Electron::EtaRegion::GAP ) continue;

    int  LepType = GetLeptonType_JH(*El,truthColl);
    bool IsPr = LepType>0, IsExCv = LepType<-4, IsHMisReco = LepType==-1, IsHNonPrEl = LepType>-5 && LepType<-1;
    bool IsHFk = IsHMisReco or IsHNonPrEl;
    int  MatchJetType = IsHFk? GetFakeLepSrcType(*El, JetCleanColl):0;
    bool MatchTrig    =   El->PassFilter("hltEle8CaloIdLTrackIdLIsoVLTrackIsoFilter")
                       or El->PassFilter("hltEle12CaloIdLTrackIdLIsoVLTrackIsoFilter");

    TString ElType  = IsPr? "_Pr": IsExCv? "_ExCv": IsHMisReco? "_HMisReco": IsHNonPrEl? "_HNonPrEl": "";
    TString SrcType = MatchJetType==3? "_BjMatch": MatchJetType==2? "_CjMatch": MatchJetType==1? "_LjMatch":
                      MatchJetType==-1? "_NoMatch": "";

    FillHist("NCnt_ElJMatch"+Label, MatchJetType, weight, 5, -1., 4.);
    if(LepType==0) FillHist("NCntLTypeErr"+Label, 0., weight, 1, 0., 1.);
    if(IsHFk && MatchJetType<=0) continue; //Checked to be ignorable & irrelevant to study

    for(unsigned int iID=0; iID<ElIDList.size(); iID++){
      TString ID = ElIDList.at(iID);
      bool PassedID = El->PassID(ID);
      FillHist("El"+ElType+SrcType+"_"+ID+Label, 0., weight, 4, 0., 4.);
      if(PassedID             ){ FillHist("El"+ElType+SrcType+"_"+ID+Label, 1., weight, 4, 0., 4.); }
      if(MatchTrig            ){ FillHist("El"+ElType+SrcType+"_"+ID+Label, 2., weight, 4, 0., 4.); }
      if(MatchTrig && PassedID){ FillHist("El"+ElType+SrcType+"_"+ID+Label, 3., weight, 4, 0., 4.); }
    }
  }
}




void MCFakeStudy::CheckIDVarDist(vector<Electron>& ElRawColl, vector<Jet>& JetCleanColl, float weight, TString ElID, TString Label, TString Option){

  for(unsigned int ie=0; ie<ElRawColl.size(); ie++){
    Electron* El = &ElRawColl.at(ie);
    float PT=El->Pt(), fEta=fabs(El->Eta());
    float PTMax = Option.Contains("PtMax25")? 25:-1;
    if( PT < 10 ) continue;
    if( PTMax>0 && PT>PTMax ) continue;
    if( El->etaRegion()==Electron::EtaRegion::GAP ) continue;
    if( !El->PassID(ElID) ) continue;

    int  LepType = GetLeptonType_JH(*El,truthColl);
    bool IsPr = LepType>0, IsHFk = LepType<0 && LepType>-5, IsExCv = LepType<-4;
    int  MatchJetType = IsHFk? GetFakeLepSrcType(*El, JetCleanColl):0;
    bool MatchTrig    =   El->PassFilter("hltEle8CaloIdLTrackIdLIsoVLTrackIsoFilter")
                       or El->PassFilter("hltEle12CaloIdLTrackIdLIsoVLTrackIsoFilter");

    float EA_ecal = fEta<1.479? 0.29:0.21, EA_hcal = fEta<1.479? 0.2:0.25;
    float RelEcalPFClusterIsoEA = max(0.,El->ecalPFClusterIso()-Rho*EA_ecal)/PT;
    float RelHcalPFClusterIsoEA = max(0.,El->hcalPFClusterIso()-Rho*EA_hcal)/PT;

    TString ElType  = IsPr? "_Pr": IsHFk? "_HFk": IsExCv? "_ExCv": "";
    TString EtaReg  = fEta<0.8? "B1": fEta<1.479? "B2": "E"; 
    TString SrcType = MatchJetType==3? "_BjMatch": MatchJetType==2? "_CjMatch": MatchJetType==1? "_LjMatch":
                      MatchJetType==-1? "_NoMatch": "";

    FillHist("NCnt_ElJMatch"+Label, MatchJetType, weight, 5, -1., 4.);
    if(LepType==0) FillHist("NCntLTypeErr"+Label, 0., weight, 1, 0., 1.);
    if(IsHFk && MatchJetType<=0) continue; //Checked to be ignorable & irrelevant to study


    //for first round, let's see if we can control fake w/o loosening IP or conv cuts
    FillHist("El"+EtaReg+"_sieie"+ElType+SrcType+Label, El->Full5x5_sigmaIetaIeta(), weight, 50, 0., 0.05);
    FillHist("El"+EtaReg+"_HoverE"+ElType+SrcType+Label, El->HoverE(), weight, 50, 0., 1.);
    FillHist("El"+EtaReg+"_dEtaIn"+ElType+SrcType+Label, fabs(El->dEtaSeed()), weight, 50, 0., 0.05);
    FillHist("El"+EtaReg+"_dPhiIn"+ElType+SrcType+Label, fabs(El->dPhiIn()), weight, 40, 0., 0.2);
    FillHist("El"+EtaReg+"_ooEooP"+ElType+SrcType+Label, fabs(El->InvEminusInvP()), weight, 50, 0., 1.);
    FillHist("El"+EtaReg+"_PFEcalIsoEA"+ElType+SrcType+Label, RelEcalPFClusterIsoEA, weight, 100, 0., 1.);
    FillHist("El"+EtaReg+"_PFHcalIsoEA"+ElType+SrcType+Label, RelHcalPFClusterIsoEA, weight, 100, 0., 1.);
    FillHist("El"+EtaReg+"_TrkIso"+ElType+SrcType+Label, El->dr03TkSumPt()/PT, weight, 50, 0., 1.);
    FillHist("El"+EtaReg+"_SIP3D"+ElType+SrcType+Label, El->SIP3D(), weight, 20, 0., 10.);
    FillHist("El"+EtaReg+"_MVANonIso"+ElType+SrcType+Label, El->MVANoIso(), weight, 40, -1., 1.);
    FillHist("El"+EtaReg+"_MVAIso"+ElType+SrcType+Label, El->MVAIso(), weight, 40, -1., 1.);
    FillHist("El"+EtaReg+"_dXY"+ElType+SrcType+Label, fabs(El->dXY()), weight, 50, 0., 1.);
    if(MatchTrig){
      FillHist("ElTrig"+EtaReg+"_sieie"+ElType+SrcType+Label, El->Full5x5_sigmaIetaIeta(), weight, 50, 0., 0.05);
      FillHist("ElTrig"+EtaReg+"_HoverE"+ElType+SrcType+Label, El->HoverE(), weight, 50, 0., 1.);
      FillHist("ElTrig"+EtaReg+"_dEtaIn"+ElType+SrcType+Label, fabs(El->dEtaSeed()), weight, 50, 0., 0.05);
      FillHist("ElTrig"+EtaReg+"_dPhiIn"+ElType+SrcType+Label, fabs(El->dPhiIn()), weight, 40, 0., 0.2);
      FillHist("ElTrig"+EtaReg+"_ooEooP"+ElType+SrcType+Label, fabs(El->InvEminusInvP()), weight, 50, 0., 1.);
      FillHist("ElTrig"+EtaReg+"_PFEcalIsoEA"+ElType+SrcType+Label, RelEcalPFClusterIsoEA, weight, 100, 0., 1.);
      FillHist("ElTrig"+EtaReg+"_PFHcalIsoEA"+ElType+SrcType+Label, RelHcalPFClusterIsoEA, weight, 100, 0., 1.);
      FillHist("ElTrig"+EtaReg+"_TrkIso"+ElType+SrcType+Label, El->dr03TkSumPt()/PT, weight, 50, 0., 1.);
      FillHist("ElTrig"+EtaReg+"_SIP3D"+ElType+SrcType+Label, El->SIP3D(), weight, 20, 0., 10.);
      FillHist("ElTrig"+EtaReg+"_MVANonIso"+ElType+SrcType+Label, El->MVANoIso(), weight, 40, -1., 1.);
      FillHist("ElTrig"+EtaReg+"_MVAIso"+ElType+SrcType+Label, El->MVAIso(), weight, 40, -1., 1.);
      FillHist("ElTrig"+EtaReg+"_dXY"+ElType+SrcType+Label, fabs(El->dXY()), weight, 50, 0., 1.);
    }
  }
}


void MCFakeStudy::MeasMCTtoLRatio(vector<Muon>& FakePreColl, vector<Jet>& JetColl, vector<double>& PtEdges, float weight, TString LooseID, TString TightID, TString Label, TString Option){

  vector<Muon> FakeColl;
    for(unsigned int i=0; i<FakePreColl.size(); i++){ if(FakePreColl.at(i).PassID(LooseID)) FakeColl.push_back(FakePreColl.at(i)); }

  TString EtaReg=Option.Contains("MB")? "MB": Option.Contains("MO")? "MO": Option.Contains("ME")? "ME": "";

  float TightIso=0.;
  if     (TightID.Contains("Isop10")) TightIso=0.1;
  else if(TightID.Contains("Isop15")) TightIso=0.15;
  else if(TightID.Contains("Isop08")) TightIso=0.08;
  else if(TightID.Contains("TopHN")) TightIso=0.1;
  else   { printf("no matched iso wp.\n"); return; }

  float PTMin=10.;
  //bool EWKProc = Option.Contains("EWK");
  bool ConePtCut=Option.Contains("ConePt");
  for(unsigned int i=0; i<FakeColl.size(); i++){
    float RelIso      = FakeColl.at(i).MiniRelIso();
    float PTCorr      = FakeColl.at(i).CalcPtCone(RelIso,TightIso);
    float PT          = ConePtCut? PTCorr:FakeColl.at(i).Pt();
    int   FakeSrcType = GetFakeLepSrcType(FakeColl.at(i), JetColl);
    TString MatchTag = FakeSrcType==3? "_BjMatch": FakeSrcType==2? "_CjMatch": FakeSrcType==1? "_LjMatch":"_NoMatch";

    if( PT<PTMin ) continue;
    //if( (!EWKProc) && MatchTag=="_NoMatch") continue;
    //Composition
    FillHist("FakeSrcType"+EtaReg+Label, FakeSrcType, weight, 5, -1, 4);

    //AllFakes
    FillHist("Mu"+EtaReg+"SumW_All_PT_FR1D"+Label, PTCorr, weight, PtEdges.size()-1, &PtEdges[0]);
    if(FakeColl.at(i).PassID(TightID)) FillHist("Mu"+EtaReg+"IDSumW_All_PT_FR1D"+Label, PTCorr, weight, PtEdges.size()-1, &PtEdges[0]);

    //PerSources(Only for matched ones)
    FillHist("Mu"+EtaReg+"SumW"+MatchTag+"_PT_FR1D"+Label, PTCorr, weight, PtEdges.size()-1, &PtEdges[0]);   
    if(FakeColl.at(i).PassID(TightID)) FillHist("Mu"+EtaReg+"IDSumW"+MatchTag+"_PT_FR1D"+Label, PTCorr, weight, PtEdges.size()-1, &PtEdges[0]);
  }//End of Fake Lepton Loop 

}



void MCFakeStudy::MeasMCTtoLRatio(vector<Electron>& FakePreColl, vector<Jet>& JetColl, vector<double>& PtEdges, float weight, TString LooseID, TString TightID, TString Label, TString Option){

  vector<Electron> FakeColl;
    for(unsigned int i=0; i<FakePreColl.size(); i++){ if(FakePreColl.at(i).PassID(LooseID)) FakeColl.push_back(FakePreColl.at(i)); }

  TString EtaReg=Option.Contains("B1")? "B1": Option.Contains("B2")? "B2": Option.Contains("E")? "E": "";

  float TightIso=0.;
  if     (TightID.Contains("Isop1"))  TightIso=0.1;
  else if(TightID.Contains("Isop08")) TightIso=0.08;
  else if(TightID.Contains("TopHN")) TightIso=0.1;
  else   { printf("no matched iso wp.\n"); return; }

  float PTMin=10.;
  if(TightID.Contains("SS")) PTMin=15.;

  bool EWKProc = Option.Contains("EWK");
  bool ConePtCut=Option.Contains("ConePt");

  for(unsigned int i=0; i<FakeColl.size(); i++){
    float RelIso      = FakeColl.at(i).MiniRelIso();
    float PTCorr      = FakeColl.at(i).CalcPtCone(RelIso,TightIso);
    float PT          = ConePtCut? PTCorr:FakeColl.at(i).Pt();
    int   FakeSrcType = GetFakeLepSrcType(FakeColl.at(i), JetColl);
    TString MatchTag = FakeSrcType==3? "_BjMatch": FakeSrcType==2? "_CjMatch": FakeSrcType==1? "_LjMatch":"_NoMatch";

    if( PT<PTMin ) continue;
    if( (!EWKProc) && MatchTag=="_NoMatch") continue;
    //Composition
    FillHist("FakeSrcType"+EtaReg+Label, FakeSrcType, weight, 5, -1, 4);

    //AllFakes
    FillHist("Ele"+EtaReg+"SumW_All_PT_FR1D"+Label, PTCorr, weight, PtEdges.size()-1, &PtEdges[0]);
    if(FakeColl.at(i).PassID(TightID)) FillHist("Ele"+EtaReg+"IDSumW_All_PT_FR1D"+Label, PTCorr, weight, PtEdges.size()-1, &PtEdges[0]);

    //PerSources(Only for matched ones)
    FillHist("Ele"+EtaReg+"SumW"+MatchTag+"_PT_FR1D"+Label, PTCorr, weight, PtEdges.size()-1, &PtEdges[0]);   
    if(FakeColl.at(i).PassID(TightID)) FillHist("Ele"+EtaReg+"IDSumW"+MatchTag+"_PT_FR1D"+Label, PTCorr, weight, PtEdges.size()-1, &PtEdges[0]);
  }//End of Fake Lepton Loop 

}


void MCFakeStudy::ScanFakeRate(vector<Muon>& FakePreColl, vector<Jet>& JetColl, TString Var1Str, TString Var2Str, float Var1Cut, float Var2Cut, vector<double>& PtEdges, float weight, TString PreID, TString TightID, TString Label, TString Option){

  vector<Muon> FakeColl;
    for(unsigned int i=0; i<FakePreColl.size(); i++){ if(FakePreColl.at(i).PassID(PreID)) FakeColl.push_back(FakePreColl.at(i)); }

  std::ostringstream s1,s2;
  s1<<Var1Cut; s2<<Var2Cut;
  TString Str_Var1Cut=s1.str(); Str_Var1Cut.ReplaceAll(".","p"), Str_Var1Cut.ReplaceAll("-","m");
  TString Str_Var2Cut=s2.str(); Str_Var2Cut.ReplaceAll(".","p"), Str_Var2Cut.ReplaceAll("-","m");

  if(! (Var1Str=="iso" or Var1Str=="sip") ){ printf("Err: no match to allowed Var1 list\n"); return; }
  if(! (Var2Str=="iso" or Var2Str=="sip") ){ printf("Err: no match to allowed Var2 list\n"); return; }
  
  TString EtaReg="";
  if     (Option.Contains("MB") ) EtaReg="MB";
  else if(Option.Contains("MO") ) EtaReg="MO";
  else if(Option.Contains("ME") ) EtaReg="ME";
  else if(Option.Contains("All")) EtaReg="";

  float TightIso=0.;
  if     (TightID.Contains("Isop10"))  TightIso=0.1;
  else if(TightID.Contains("Isop15"))  TightIso=0.15;
  else if(TightID.Contains("TopHN"))  TightIso=0.1;
  else   { printf("no matched iso wp.\n"); return; }

  float PTMin=10.;
  bool ConePtCut = Option.Contains("ConePt"), JetPtParam = Option.Contains("JetPtParam");

  for(unsigned int i=0; i<FakeColl.size(); i++){
    float RelIso = FakeColl.at(i).MiniRelIso();
    float SIP    = FakeColl.at(i).SIP3D();
    float PTCorr = FakeColl.at(i).CalcPtCone(RelIso,TightIso);
    float PT     = ConePtCut? PTCorr:FakeColl.at(i).Pt();
    float JetPT  = 0.; 
    float Var1   = RelIso, Var2 = SIP;
    int   FakeSrcType = GetFakeLepSrcType(FakeColl.at(i), JetColl);
    TString MatchTag = FakeSrcType==3? "_BjMatch": FakeSrcType==2? "_CjMatch": FakeSrcType==1? "_LjMatch":"_NoMatch";
    
    if(PT<PTMin) continue;
    if(MatchTag=="_NoMatch") continue;
    bool PassVar1 = Var1Cut>=0? Var1<Var1Cut:true;
    bool PassVar2 = Var2Cut>=0? Var2<Var2Cut:true;
    if( !(PassVar1 && PassVar2) ) continue;

    if(JetPtParam){ for(unsigned int ij=0; ij<JetColl.size() && JetPT<1; ij++){ if(JetColl.at(ij).DeltaR(FakeColl.at(i))<0.4) JetPT=JetColl.at(ij).Pt(); } 
                    PTCorr=JetPT; }

    //AllFakes
    FillHist("Mu"+EtaReg+"SumW_"+Var1Str+Str_Var1Cut+Var2Str+Str_Var2Cut+"_All_PT_FR1D"+Label, PTCorr, weight, PtEdges.size()-1, &PtEdges[0]);   
    if(FakeColl.at(i).PassID(TightID)) FillHist("Mu"+EtaReg+"IDSumW_"+Var1Str+Str_Var1Cut+Var2Str+Str_Var2Cut+"_All_PT_FR1D"+Label, PTCorr, weight, PtEdges.size()-1, &PtEdges[0]);

    //PerSources(Only for matched ones)
    FillHist("Mu"+EtaReg+"SumW_"+Var1Str+Str_Var1Cut+Var2Str+Str_Var2Cut+MatchTag+"_PT_FR1D"+Label, PTCorr, weight, PtEdges.size()-1, &PtEdges[0]);   
    if(FakeColl.at(i).PassID(TightID)) FillHist("Mu"+EtaReg+"IDSumW_"+Var1Str+Str_Var1Cut+Var2Str+Str_Var2Cut+MatchTag+"_PT_FR1D"+Label, PTCorr, weight, PtEdges.size()-1, &PtEdges[0]);
  }//End of Fake Lepton Loop 

}



void MCFakeStudy::ScanFakeRate(vector<Electron>& FakePreColl, vector<Jet>& JetColl, TString Var1Str, TString Var2Str, float Var1Cut, float Var2Cut, vector<double>& PtEdges, float weight, TString PreID, TString TightID, TString Label, TString Option){

  vector<Electron> FakeColl;
    for(unsigned int i=0; i<FakePreColl.size(); i++){ if(FakePreColl.at(i).PassID(PreID)) FakeColl.push_back(FakePreColl.at(i)); }

  std::ostringstream s1,s2;
  s1<<Var1Cut; s2<<Var2Cut;
  TString Str_Var1Cut=s1.str(); Str_Var1Cut.ReplaceAll(".","p"), Str_Var1Cut.ReplaceAll("-","m");
  TString Str_Var2Cut=s2.str(); Str_Var2Cut.ReplaceAll(".","p"), Str_Var2Cut.ReplaceAll("-","m");

  if(! (Var1Str=="mva") ){ printf("Err: no match to allowed Var1 list\n"); return; }
  if(! (Var2Str=="iso" or Var2Str=="sip") ){ printf("Err: no match to allowed Var2 list\n"); return; }
  
  TString EtaReg="";
  if     (Option.Contains("B1") ) EtaReg="B1";
  else if(Option.Contains("B2") ) EtaReg="B2";
  else if(Option.Contains("E")  ) EtaReg="E";
  else if(Option.Contains("All")) EtaReg="";

  float TightIso=0.;
  if     (TightID.Contains("Isop1"))  TightIso=0.1;
  else if(TightID.Contains("TopHN"))  TightIso=0.1;
  else   { printf("no matched iso wp.\n"); return; }

  float PTMin=10.;
  if(TightID.Contains("SS")) PTMin=15.;

  bool MVAInclIso = Label.Contains("TopHNIso");
  bool ConePtCut = Option.Contains("ConePt");

  for(unsigned int i=0; i<FakeColl.size(); i++){
    float RelIso = FakeColl.at(i).MiniRelIso();
    float MVA    = MVAInclIso? FakeColl.at(i).MVAIso():FakeColl.at(i).MVANoIso();
    float SIP    = FakeColl.at(i).SIP3D();
    float PTCorr = FakeColl.at(i).CalcPtCone(RelIso,TightIso);
    float PT     = ConePtCut? PTCorr:FakeColl.at(i).Pt();
    float Var1   = MVA, Var2 = Var2Str=="iso"? RelIso:Var2Str=="sip"? SIP:0;
    int   FakeSrcType = GetFakeLepSrcType(FakeColl.at(i), JetColl);
    TString MatchTag = FakeSrcType==3? "_BjMatch": FakeSrcType==2? "_CjMatch": FakeSrcType==1? "_LjMatch":"_NoMatch";

    if(PT<PTMin) continue;
    if(MatchTag=="_NoMatch") continue; //Need to veto EWK-tau jets, predominant fraction of no-match
    bool PassVar1 = Var1Cut>=-1? Var1>Var1Cut:true;
    bool PassVar2 = Var2Cut>= 0? Var2<Var2Cut:true;
    if(Var1Str=="mva" && (!PassVar1)){//loose cuts should not exceed tight cuts
      if(MVAInclIso){
        if(TightID.Contains("WP90")) PassVar1 = FakeColl.at(i).passMVAID_iso_WP90();
        if(TightID.Contains("WP80")) PassVar1 = FakeColl.at(i).passMVAID_iso_WP80();
      }                            
      else{                        
        if(TightID.Contains("WP90")) PassVar1 = FakeColl.at(i).passMVAID_noIso_WP90();
        if(TightID.Contains("WP80")) PassVar1 = FakeColl.at(i).passMVAID_noIso_WP80();
        if(TightID.Contains("TopHNSST")) PassVar1 = FakeColl.at(i).passMVAID_noIso_WP90();
      }
    }
    if( !(PassVar1 && PassVar2) ) continue;

    //AllFakes
    FillHist("Ele"+EtaReg+"SumW_"+Var1Str+Str_Var1Cut+Var2Str+Str_Var2Cut+"_All_PT_FR1D"+Label, PTCorr, weight, PtEdges.size()-1, &PtEdges[0]);   
    if(FakeColl.at(i).PassID(TightID)) FillHist("Ele"+EtaReg+"IDSumW_"+Var1Str+Str_Var1Cut+Var2Str+Str_Var2Cut+"_All_PT_FR1D"+Label, PTCorr, weight, PtEdges.size()-1, &PtEdges[0]);

    //PerSources(Only for matched ones)
    FillHist("Ele"+EtaReg+"SumW_"+Var1Str+Str_Var1Cut+Var2Str+Str_Var2Cut+MatchTag+"_PT_FR1D"+Label, PTCorr, weight, PtEdges.size()-1, &PtEdges[0]);   
    if(FakeColl.at(i).PassID(TightID)) FillHist("Ele"+EtaReg+"IDSumW_"+Var1Str+Str_Var1Cut+Var2Str+Str_Var2Cut+MatchTag+"_PT_FR1D"+Label, PTCorr, weight, PtEdges.size()-1, &PtEdges[0]);
  }//End of Fake Lepton Loop 

}




float MCFakeStudy::GetMCFakeWeight(vector<Muon>& MuColl, vector<Electron>& ElColl, TString MuTID, TString ElTID, TString MuFRKey, TString ElFRKey, int SystDir, float FR_MCCorr){

  if(IsDATA) return 1.;

  float weight=-1.;
  int NLepLNotT=0; float TightIso= 0.1;
  if(MuTID.Contains("TIsop15")) TightIso=0.15;
  for(unsigned int im=0; im<MuColl.size(); im++){
    if(MuColl.at(im).PassID(MuTID)) continue; 
    float PTCorr = MuColl.at(im).CalcPtCone(MuColl.at(im).MiniRelIso(), TightIso);
    float fEta   = fabs(MuColl.at(im).Eta());
    if(MuFRKey.Contains("QCD") && PTCorr>50) PTCorr=49.;
    float FR = GetMCFakeRate(PTCorr, fEta, MuFRKey, SystDir);
    weight*=-FR/(1.-FR);
    NLepLNotT++;
  }

  for(unsigned int ie=0; ie<ElColl.size(); ie++){
    if(ElColl.at(ie).PassID(ElTID)) continue; 
    float PTCorr = ElColl.at(ie).CalcPtCone(ElColl.at(ie).MiniRelIso(), TightIso);
    float fEta   = fabs(ElColl.at(ie).Eta());
    if(ElFRKey.Contains("QCD") && PTCorr>50) PTCorr=49.;
    float FR = GetMCFakeRate(PTCorr, fEta, ElFRKey, SystDir);
    weight*=-FR/(1.-FR);
    NLepLNotT++;
  }
  weight *= (FR_MCCorr);
  if(NLepLNotT==0) weight=0.;
  return weight;
}


float MCFakeStudy::GetGenMatchFakeWeight(vector<Muon>& MuColl, vector<Electron>& ElColl, vector<Gen>& TruthColl, TString MuTID, TString ElTID, TString MuFRKey, TString ElFRKey, float FR_MCCorr){

  if(IsDATA) return 1.;

  float weight=-1.;
  int NLepLNotT=0; float TightIso= 0.1;
  for(unsigned int im=0; im<MuColl.size(); im++){
    if(MuColl.at(im).PassID(MuTID)) continue; 
    int LepType = GetLeptonType_JH(MuColl.at(im), TruthColl);
    if(LepType>0 or LepType<-4) continue;
    float PTCorr = MuColl.at(im).CalcPtCone(MuColl.at(im).MiniRelIso(), TightIso);
    float fEta   = fabs(MuColl.at(im).Eta());
    if(MuFRKey.Contains("QCD") && PTCorr>50) PTCorr=49.;
    float FR     = GetMCFakeRate(PTCorr, fEta, MuFRKey, 0);
    weight*=-FR/(1.-FR);
    NLepLNotT++;
  }

  for(unsigned int ie=0; ie<ElColl.size(); ie++){
    if(ElColl.at(ie).PassID(ElTID)) continue; 
    int LepType = GetLeptonType_JH(ElColl.at(ie), TruthColl);
    if(LepType>0 or LepType<-4) continue;
    float PTCorr = ElColl.at(ie).CalcPtCone(ElColl.at(ie).MiniRelIso(), TightIso);
    float fEta   = fabs(ElColl.at(ie).Eta());
    if(ElFRKey.Contains("QCD") && PTCorr>50) PTCorr=49.;
    float FR     = GetMCFakeRate(PTCorr, fEta, ElFRKey, 0);
    weight*=-FR/(1.-FR);
    NLepLNotT++;
  }

  weight *= (FR_MCCorr);
  if(NLepLNotT==0) weight=0.;
  return weight;
}


bool MCFakeStudy::PassFRMeasSel(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                                vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& Ev, TString Label)
{

  int NMuL=MuLColl.size(), NElL=ElLColl.size(), NElV=ElVColl.size();
  if( !((NMuL==1 && NElL==0) or (NMuL==0 && NElL==1)) ) return false;
  if( NElL!=NElV ) return false;
  if(NMuL==1){
    float TightIso=0.1, RelIso=MuLColl.at(0).MiniRelIso(), JetPtCut=40.;
    float PT=MuLColl.at(0).Pt(), PTCorr=MuLColl.at(0).CalcPtCone(RelIso, TightIso);//, MET=vMET.Pt(), MTW=MT(MuLColl.at(0),vMET);
    bool TrigMu17 = Label.Contains("TrigMu17"), TrigMu8 = Label.Contains("TrigMu8"), TrigSel=false, PassJetReq=false;
    if     (TrigMu17 && Ev.PassTrigger("HLT_Mu17_TrkIsoVVL_v") && PT>20. && PTCorr>=30.){ TrigSel=true; Label.ReplaceAll("TrigMu17",""); }
    else if(TrigMu8  && Ev.PassTrigger("HLT_Mu8_TrkIsoVVL_v")  && PT>10. && PTCorr>10 && PTCorr <30.){ TrigSel=true; Label.ReplaceAll("TrigMu8", ""); }
    if(!TrigSel) return false;

    bool PassNBCut = Label.Contains("HasB")? BJetColl.size()>0:true;
    for(unsigned int i=0; i<JetColl.size(); i++){
      if(JetColl.at(i).Pt()<JetPtCut) continue;
      if(MuLColl.at(0).DeltaR(JetColl.at(i))<1.0) continue;
      PassJetReq=true; break;
    }
    if( !PassJetReq ) return false;
    if( !PassNBCut  ) return false;
    //if( !(MET<25 && MTW<25) ) return false; //excluded for limited MC stat.

  }
  else if(NElL==1){
    float TightIso=0.1, RelIso=ElLColl.at(0).MiniRelIso(), JetPtCut=40.;
    float PT=ElLColl.at(0).Pt(), PTCorr=ElLColl.at(0).CalcPtCone(RelIso, TightIso);//, MET=vMET.Pt(), MTW=MT(ElLColl.at(0),vMET); 
    bool TrigEl23 = Label.Contains("TrigEl23"), TrigEl12 = Label.Contains("TrigEl12"), TrigEl8 = Label.Contains("TrigEl8");
    bool PTCut10 = Label.Contains("_Pt10"), PTCut15 = Label.Contains("_Pt15"), TrigSel=false, PassJetReq=false;
    if(PTCut15){
      if     (TrigEl23 && Ev.PassTrigger("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v") && PT>25. && PTCorr>=35.){
        TrigSel=true; Label.ReplaceAll("TrigEl23_Pt15",""); }
      else if(TrigEl12 && Ev.PassTrigger("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v") && PT>15. && PTCorr <35.){
        TrigSel=true; Label.ReplaceAll("TrigEl12_Pt15",""); }
    }
    else if(PTCut10){
      if     (TrigEl23 && Ev.PassTrigger("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v") && PT>25. && PTCorr>=35.){
        TrigSel=true; Label.ReplaceAll("TrigEl23_Pt10",""); }
      else if(TrigEl12 && Ev.PassTrigger("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v") && PT>15. && PTCorr<35. && PTCorr>=20.){
        TrigSel=true; Label.ReplaceAll("TrigEl12_Pt10",""); }
      else if(TrigEl8  && Ev.PassTrigger("HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v")  && PT>10. && PTCorr<20.){
        TrigSel=true; Label.ReplaceAll("TrigEl8_Pt10",""); }
    }
    if(!TrigSel) return false;

    bool PassNBCut = Label.Contains("HasB")? BJetColl.size()>0:true;
    for(unsigned int i=0; i<JetColl.size(); i++){
      if(JetColl.at(i).Pt()<JetPtCut) continue;
      if(ElLColl.at(0).DeltaR(JetColl.at(i))<1.0) continue;
      PassJetReq=true; break;
    }
    if(!PassJetReq) return false;
    if(!PassNBCut ) return false;
    //if( !(MET<25 && MTW<25) ) return false; //excluded for limited MC stat.
  }
  else return false;

  return true;

}


void MCFakeStudy::EmulQCDFRMeas(vector<Muon>& MuRawColl, vector<Electron>& ElRawColl, vector<Jet>& JetRawColl, 
                                Particle& vMET, Event& Ev, vector<Gen>& TruthColl, float weight, 
                                TString MuTID, TString MuLID, TString ElTID, TString ElLID, TString ElVID, TString Label, TString Option)
{
  //This is intended for emulating FR measurement. In case measuring simple MC counting rate measurements, Use MeasMCTtoLRatio or ScanFakeRate
  //EWK tau treatment is not included here.
  bool DoMuFR = Option.Contains("MuFR"), DoElFR = Option.Contains("ElFR");
  float MinPtMu=10., MinPtEl=ElTID.Contains("SS")? 15.:10.; TString MinPtElStr=ElTID.Contains("SS")? "_Pt15":"_Pt10";
  if(Option.Contains("Pt10")){ MinPtEl=10.; MinPtElStr="_Pt10"; }
  bool ApplyFRMeasSel = Option.Contains("QCDMeasSel"), ApplyVtxRW = false;
  bool PassFRMeas_Mu17=false, PassFRMeas_Mu8=false; bool PassFRMeas_El23=false, PassFRMeas_El12=false;
  bool NoVetoEWK=Option.Contains("NoVetoEWK"), MatchTrig = Option.Contains("Trig"), ConePtCut=Option.Contains("ConePt");
  bool JetPtParam = Option.Contains("JetPtParam"), LepPtParam = Option.Contains("LepPtParam");
  if(ApplyFRMeasSel){
    vector<Muon>     MuTColl  = SelectMuons    (MuRawColl, MuTID, MinPtMu, 2.4);
    vector<Electron> ElTColl  = SelectElectrons(ElRawColl, ElTID, MinPtEl, 2.5);
    vector<Muon>     MuLColl  = SelectMuons    (MuRawColl, MuLID, MinPtMu, 2.4);
    vector<Electron> ElLColl  = SelectElectrons(ElRawColl, ElLID, MinPtEl, 2.5);
    vector<Electron> ElVColl  = SelectElectrons(ElRawColl, ElVID, 10., 2.5);
    vector<Jet>      JetColl  = SelectJets     (JetRawColl, MuLColl, ElVColl, "tight", 25., 2.4, "LVeto");
    JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
    vector<Jet>      BJetColl = SelBJets       (JetColl, param_jets);

    PassFRMeas_Mu17 = PassFRMeasSel(MuTColl, MuLColl, ElTColl, ElLColl, ElVColl, JetColl, BJetColl, vMET, Ev, "TrigMu17");
    PassFRMeas_Mu8  = PassFRMeasSel(MuTColl, MuLColl, ElTColl, ElLColl, ElVColl, JetColl, BJetColl, vMET, Ev, "TrigMu8");
    PassFRMeas_El23 = PassFRMeasSel(MuTColl, MuLColl, ElTColl, ElLColl, ElVColl, JetColl, BJetColl, vMET, Ev, "TrigEl23"+MinPtElStr);
    PassFRMeas_El12 = PassFRMeasSel(MuTColl, MuLColl, ElTColl, ElLColl, ElVColl, JetColl, BJetColl, vMET, Ev, "TrigEl12"+MinPtElStr);
    if(!(PassFRMeas_Mu17 or PassFRMeas_Mu8 or PassFRMeas_El23 or PassFRMeas_El12)) return;

    if(ApplyVtxRW){//Check impact on FR due to PV diff btw. MeasSel vs. AppReg.
      if     (PassFRMeas_Mu17) weight *= NvtxReweight("TrigMu17");
      else if(PassFRMeas_Mu8)  weight *= NvtxReweight("TrigMu8");
      else if(PassFRMeas_El23) weight *= NvtxReweight("TrigEl23_Pt15");
      else if(PassFRMeas_El12) weight *= NvtxReweight("TrigEl12_Pt15");
    }
  }
  FillHist("OptTag"+Label+"_"+Option, 0., weight, 1, 0., 1.);

  for(unsigned int im=0; im<MuRawColl.size() && DoMuFR; im++){
    Muon* Mu = &MuRawColl.at(im);
    float TightIso=0.1, RelIso=Mu->MiniRelIso();
    if(Option.Contains("Isop15")) TightIso=0.15;
    float PTCorr = Mu->CalcPtCone(RelIso, TightIso), Eta=Mu->Eta(), fEta=fabs(Eta);
    float PT     = ConePtCut? PTCorr:Mu->Pt(); 
    float JetPT  = 0.;
    if(LepPtParam) PTCorr=PT;

    if( PT<MinPtMu ) continue;
    if(!Mu->PassID(MuLID)) continue;
    if(MatchTrig && !Mu->PassPath("HLT_Mu8_TrkIsoVVL_v")) continue;
    bool PassTight = Mu->PassID(MuTID);
    int FakeSrcType = GetFakeLepSrcType(*Mu, JetRawColl);
    TString JFlavTag = FakeSrcType==3? "_BjMatch": FakeSrcType==2? "_CjMatch": FakeSrcType==1? "_LjMatch":"_NoMatch";
    if(JetPtParam){
      for(unsigned int ij=0; ij<JetRawColl.size() && FakeSrcType>0 && JetPT<1; ij++){
        if(JetRawColl.at(ij).DeltaR(*Mu)<0.4) JetPT=JetRawColl.at(ij).Pt();
      } 
      if(FakeSrcType<0) JetPT=PT; 
      PTCorr=JetPT;
    }

    TString EtaReg = fEta<0.9? "MB": fEta<1.6? "MO": "ME";
    vector<double> fEtaEdges     = {0., 0.9, 1.6, 2.4};
    vector<double> PTEdges       = {10., 15., 20., 30., 50.};

    if(!MCSample.Contains("QCD") && FakeSrcType==-1) continue;
    if(PTCorr<MinPtMu) continue;

    vector<TString> EtaList  = {"", "MB", "MO", "ME"};
    vector<TString> FlavList = {"_All", "_BjMatch", "_CjMatch", "_LjMatch", "_NoMatch"};
    for(unsigned int iEta=0; iEta<EtaList.size(); iEta++){
    for(unsigned int iFlav=0; iFlav<FlavList.size(); iFlav++){
      if(  EtaList.at(iEta)!=""     &&   EtaList.at(iEta)!=EtaReg  ) continue;
      if(FlavList.at(iFlav)!="_All" && FlavList.at(iFlav)!=JFlavTag) continue;
      TString Eta=EtaList.at(iEta), Flav=FlavList.at(iFlav);
      FillHist("Mu"+Eta+"SumW"+Flav+"_PT_FR1D"+Label, PTCorr, weight, PTEdges.size()-1, &PTEdges[0]);   
      FillHist("MuSumW"+Flav+"_PTfEta2D"+Label, PTCorr, fEta, weight, PTEdges.size()-1, &PTEdges[0], fEtaEdges.size()-1, &fEtaEdges[0]);
      if(PassTight){
        FillHist("Mu"+Eta+"IDSumW"+Flav+"_PT_FR1D"+Label, PTCorr, weight, PTEdges.size()-1, &PTEdges[0]);
        FillHist("MuIDSumW"+Flav+"_PTfEta2D"+Label, PTCorr, fEta, weight, PTEdges.size()-1, &PTEdges[0], fEtaEdges.size()-1, &fEtaEdges[0]);
      }
    }}
  }

  for(unsigned int ie=0; ie<ElRawColl.size() && DoElFR; ie++){
    Electron* El = &ElRawColl.at(ie);
    if( El->Pt()<MinPtEl ) continue;
    if(!El->PassID(ElLID)) continue;
    if(MatchTrig && !El->PassFilter("hltEle8CaloIdLTrackIdLIsoVLTrackIsoFilter")) continue;
    if(!MCSample.Contains("QCD")){
      int LepType = GetLeptonType_JH(*El, TruthColl);
      if(LepType<-4 or LepType>0) continue;
      bool NearEWLep=false;
      for(unsigned int ij=0; ij<JetRawColl.size(); ij++){
        if(JetRawColl.at(ij).DeltaR(*El)>0.4) continue;
        if(HasEWLepInJet(JetRawColl.at(ij), TruthColl, "InclTau")){ NearEWLep=true; break; }
      }
      if(!NoVetoEWK && NearEWLep) continue;
    }
    bool PassTight = El->PassID(ElTID);
    int FakeSrcType = GetFakeLepSrcType(*El, JetRawColl);
    TString JFlavTag = FakeSrcType==3? "_BjMatch": FakeSrcType==2? "_CjMatch": FakeSrcType==1? "_LjMatch":"_NoMatch";

    float TightIso=0.1, RelIso=El->MiniRelIso();
    float PTCorr=El->CalcPtCone(RelIso, TightIso), Eta=El->Eta(), fEta=fabs(Eta);
    TString EtaReg = fEta<0.8? "B1": fEta<1.479? "B2": "E";
    vector<double> fEtaEdges = {0., 0.8, 1.5, 2.5};
    vector<double> PTEdges   = {10., 15., 20., 25., 35., 50., 100., 200.};

    if(PTCorr<MinPtEl) continue;


    vector<TString> EtaList  = {"", "B1", "B2", "E"};
    vector<TString> FlavList = {"_All", "_BjMatch", "_CjMatch", "_LjMatch", "_NoMatch"};
    for(unsigned int iEta=0; iEta<EtaList.size(); iEta++){
    for(unsigned int iFlav=0; iFlav<FlavList.size(); iFlav++){
      if(  EtaList.at(iEta)!=""     &&   EtaList.at(iEta)!=EtaReg  ) continue;
      if(FlavList.at(iFlav)!="_All" && FlavList.at(iFlav)!=JFlavTag) continue;
      TString Eta=EtaList.at(iEta), Flav=FlavList.at(iFlav);
      FillHist("El"+Eta+"SumW"+Flav+"_PT_FR1D"+Label, PTCorr, weight, PTEdges.size()-1, &PTEdges[0]);   
      FillHist("ElSumW"+Flav+"_PTfEta2D"+Label, PTCorr, fEta, weight, PTEdges.size()-1, &PTEdges[0], fEtaEdges.size()-1, &fEtaEdges[0]);
      if(PassTight){
        FillHist("El"+Eta+"IDSumW"+Flav+"_PT_FR1D"+Label, PTCorr, weight, PTEdges.size()-1, &PTEdges[0]);
        FillHist("ElIDSumW"+Flav+"_PTfEta2D"+Label, PTCorr, fEta, weight, PTEdges.size()-1, &PTEdges[0], fEtaEdges.size()-1, &fEtaEdges[0]);
      }
    }}
  }
}


void MCFakeStudy::CheckMCClosure(vector<Muon>& MuRawColl, vector<Electron>& ElRawColl, vector<Jet>& JetRawColl, 
                                 Particle& vMET, Event& Ev, vector<Gen>& TruthColl, float weight, 
                                 TString MuTID, TString MuLID, TString ElTID, TString ElLID, TString ElVID, TString Label, TString Option)
{

  InitializeTreeVars();
  vector<Muon>     MuTColl  = SelectMuons    (MuRawColl, MuTID, 10., 2.4);
  vector<Electron> ElTColl  = SelectElectrons(ElRawColl, ElTID, 15., 2.5);
  vector<Muon>     MuLColl  = SelectMuons    (MuRawColl, MuLID, 10., 2.4);
  vector<Electron> ElLColl  = SelectElectrons(ElRawColl, ElLID, 15., 2.5);
  vector<Electron> ElVColl  = SelectElectrons(ElRawColl, ElVID, 10., 2.5);
  vector<Jet>      JetColl  = SelectJets     (JetRawColl, MuLColl, ElVColl, "tight", 25., 2.4, "LVeto");
  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
  vector<Jet>      BJetColl = SelBJets       (JetColl, param_jets);

/////////////////////// Select Jet that might overlap with leptons without Jet Cleaning


  vector<Jet> DirtyJetColl = SelectJets     (JetRawColl, "tight", 25., 2.4);
  vector<Jet> DirtyBJetColl = SelBJets       (DirtyJetColl, param_jets);
  bool B_overlap = false;
  bool J_overlap = false;
  float FR_MCCorr = 1.0;
  if(MuFR){
    for(unsigned int im=0; im<MuLColl.size(); im++){
      for(unsigned int ij=0; ij<DirtyBJetColl.size(); ij++){
        if(DirtyBJetColl.at(ij).DeltaR(MuLColl.at(im))<0.4){B_overlap = true;}
      }
      for(unsigned int ilj=0; ilj<DirtyJetColl.size(); ilj++){
        if(DirtyJetColl.at(ilj).DeltaR(MuLColl.at(im))<0.4){
          FillHist("Overlap_Mu_Jet_Score"+Label, DirtyJetColl.at(ilj).GetTaggerResult(JetTagging::DeepJet), weight, 30, 0.0, 1.0);
          J_overlap = true;
        }
      }
    }
  }
  else if(ElFR){
    for(unsigned int ie=0; ie<ElLColl.size(); ie++){
      for(unsigned int ij=0; ij<DirtyBJetColl.size(); ij++){
        if(DirtyBJetColl.at(ij).DeltaR(ElLColl.at(ie))<0.4){B_overlap = true;}
      }
      for(unsigned int ilj=0; ilj<DirtyJetColl.size(); ilj++){
        if(DirtyJetColl.at(ilj).DeltaR(ElLColl.at(ie))<0.4){
          FillHist("Overlap_El_Jet_Score"+Label, DirtyJetColl.at(ilj).GetTaggerResult(JetTagging::DeepJet), weight, 30, 0.0, 1.0);
          J_overlap = true;
        }
      }
    }
  }

  if(B_overlap){
    if(MuFR){
      if (GetEraShort() == "2018") { FR_MCCorr = 0.84;}
      else if (GetEraShort() == "2017") { FR_MCCorr = 0.84;}
      else if (GetEraShort() == "2016a") { FR_MCCorr = 0.85;}
      else if (GetEraShort() == "2016b") { FR_MCCorr = 0.85;}
    }
    else if(ElFR){
      if (GetEraShort() == "2018") { FR_MCCorr = 0.86;}
      else if (GetEraShort() == "2017") { FR_MCCorr = 0.81;}
      else if (GetEraShort() == "2016a") { FR_MCCorr = 0.86;}
      else if (GetEraShort() == "2016b") { FR_MCCorr = 0.85;}
    }
  }
  TString FRProc = Label.Contains("FRTT")? "TT_powheg":Label.Contains("FRQCD")? "QCD":"";
  TString MeasSel = Option.Contains("MeasSel")? "_QCDMeasSel":""; 
  TString TrigStr = Option.Contains("Trig")?    "_Trig":"";
  TString MuLIDBase = MuLID, ElLIDBase= ElLID;
  MuLIDBase.ReplaceAll("_2016a",""); MuLIDBase.ReplaceAll("_2016b",""); MuLIDBase.ReplaceAll("_2017",""); MuLIDBase.ReplaceAll("_2018","");
  ElLIDBase.ReplaceAll("_2016a",""); ElLIDBase.ReplaceAll("_2016b",""); ElLIDBase.ReplaceAll("_2017",""); ElLIDBase.ReplaceAll("_2018","");
  TString MuFRKey = "FR2D_"+FRProc+"_"+MuTID+"_"+MuLIDBase+MeasSel+TrigStr+"_All";
  TString ElFRKey = "FR2D_"+FRProc+"_"+ElTID+"_"+ElLIDBase+MeasSel+TrigStr+"_All";
  if(Label.Contains("Pt10")){
    ElFRKey = "FR2D_"+FRProc+"_"+ElTID+"_"+ElLIDBase+"_Pt10"+MeasSel+TrigStr+"_All";
  }
  
  bool ConeBasis = Option.Contains("ConeBasis"), DoGenMatchW = Option.Contains("GenM");
  bool DrawMVA = true;
  int NMuT=MuTColl.size(), NMuL=MuLColl.size(), NElT=ElTColl.size(), NElL=ElLColl.size(), NElV=ElVColl.size();
  vector<Muon> MuConeColl; vector<Electron> ElConeColl;
  if( NElL!=NElV ) return;
  if( !((NMuL==2 && NElL==0) or (NMuL==0 && NElL==2)) ) return;
  if(NMuL==2 && MuFR){
    FillHist("Mu_FR_MCCorr"+Label, FR_MCCorr, 1, 2, 0., 1.99);
    int aSumQ = abs(SumCharge(MuLColl));
    if(aSumQ==0) return;
    if(!(MuLColl.at(0).Pt()>20. && MuLColl.at(1).Pt()>10.)) return;
    double Mll = (MuLColl.at(0)+MuLColl.at(1)).M();
    if(Mll<4) return; 
    if(!(BJetColl.size()>0 && JetColl.size()>2)) return;
    if(!( (JetColl.size()-BJetColl.size())>0 )) return;
    if(!IsDATA){
      int GenLepInfo = GetGenLepInfo(ElLColl, MuLColl, TruthColl);
      if(GenLepInfo<1000) return;
    }
    float FRweight = 1.;
    int SystDir = Option.Contains("FRUp")? 1: Option.Contains("FRDown")? -1: 0; 
    if(DoGenMatchW) FRweight = GetGenMatchFakeWeight(MuLColl, ElLColl, TruthColl, MuTID, ElTID, MuFRKey, ElFRKey, FR_MCCorr);
    else            FRweight = GetMCFakeWeight(MuLColl, ElLColl, MuTID, ElTID, MuFRKey, ElFRKey, SystDir,FR_MCCorr);
    if(NMuT==NMuL && NElT==NElL){ Label="_Obs"+Label; }
    else                        { Label="_Exp"+Label; weight*=FRweight; }

    float TightIso=0.1;
    for(unsigned int im=0; im<MuLColl.size(); im++){
      Muon TmpMu(MuLColl.at(im));
      float RelIso = MuLColl.at(im).MiniRelIso();
      float PTCorr = MuLColl.at(im).CalcPtCone(RelIso,TightIso), PT=MuLColl.at(im).Pt();
      if(ConeBasis && RelIso>TightIso) TmpMu *= PTCorr/PT;
      MuConeColl.push_back(TmpMu);
    }

    vector<Jet> BCandColl = BJetColl.size()>1? BJetColl:JetColl;
    vector<Jet> NonBJetColl = SelLightJets(JetColl, jtps.at(0));

    Nj      = JetColl.size();
    Nb      = min((Float_t) BJetColl.size(),(Float_t) 2.);
    Ptl1    = MuConeColl.at(0).Pt();
    Ptl2    = MuConeColl.at(1).Pt();
    MET     = vMET.Pt();
    dRll    = MuConeColl.at(0).DeltaR(MuConeColl.at(1));
    dRlj11  = MuConeColl.at(0).DeltaR(JetColl.at(0));
    dRlj12  = MuConeColl.at(0).DeltaR(JetColl.at(1));
    dRlj13  = MuConeColl.at(0).DeltaR(JetColl.at(2));
    dRlj21  = MuConeColl.at(1).DeltaR(JetColl.at(0));
    dRlj22  = MuConeColl.at(1).DeltaR(JetColl.at(1));
    dRlj23  = MuConeColl.at(1).DeltaR(JetColl.at(2));
    MSSSF   = (MuConeColl.at(0)+MuConeColl.at(1)).M();
    MTvl1   = MT(MuConeColl.at(0),vMET);
    MTllv   = MT(MuConeColl.at(0)+MuConeColl.at(1), vMET);

    //Vars requiring complex algo.
    HT      = 0;  for(unsigned int itj=0; itj<JetColl.size(); itj++){ HT+=JetColl.at(itj).Pt(); }


    int Idxj1W=-1, Idxj2W=-1; float bestmjjW=-1;
    for(unsigned int ij1=0; ij1<NonBJetColl.size(); ij1++){
    for(unsigned int ij2=ij1+1; ij2<NonBJetColl.size(); ij2++){
      float mjj = (NonBJetColl.at(ij1)+NonBJetColl.at(ij2)).M();
      if(bestmjjW<0){ bestmjjW = mjj; Idxj1W=ij1, Idxj2W=ij2; }
      else{ if(fabs(mjj-80.4)<fabs(bestmjjW-80.4)){ bestmjjW = mjj; Idxj1W=ij1, Idxj2W=ij2; } }
    }} 
    Ml2j1W_BkdTop = (MuConeColl.at(1)+NonBJetColl.at(0)).M();
    Ml2W_BkdTop   = bestmjjW<0? Ml2j1W_BkdTop:(MuConeColl.at(1)+NonBJetColl.at(Idxj1W)+NonBJetColl.at(Idxj2W)).M();
    MTbl1v_BkdTop = MT(BJetColl.at(0)+MuConeColl.at(0),vMET);

   
    int Idxj1W_1jL=-1, Idxbt_1jL=-1; float BestSumDelta_L=-1; 
    for(unsigned int ib=0; ib<BCandColl.size(); ib++){
    for(unsigned int inb=0; inb<NonBJetColl.size(); inb++){
      if(BCandColl.at(ib).DeltaR(NonBJetColl.at(inb))<0.1) continue;
      float mllj = (MuConeColl.at(0)+MuConeColl.at(1)+NonBJetColl.at(inb)).M();
      float mbllj = (MuConeColl.at(0)+MuConeColl.at(1)+NonBJetColl.at(inb)+BCandColl.at(ib)).M();
      float SumDelta = fabs(mbllj-160)+fabs(mllj-75);
      if(BestSumDelta_L<0){ BestSumDelta_L=SumDelta; Idxj1W_1jL=inb; Idxbt_1jL=ib;}
      else{  
        if(SumDelta<BestSumDelta_L){ BestSumDelta_L=SumDelta; Idxj1W_1jL=inb; Idxbt_1jL=ib;}
      }
    }}
    MbllW_1jL = (MuConeColl.at(0)+MuConeColl.at(1)+NonBJetColl.at(Idxj1W_1jL)+BCandColl.at(Idxbt_1jL)).M();
    MllW_1jL  = (MuConeColl.at(0)+MuConeColl.at(1)+NonBJetColl.at(Idxj1W_1jL)).M();
    Ml1W_1jL  = (MuConeColl.at(0)+NonBJetColl.at(Idxj1W_1jL)).M();
    Ml2W_1jL  = (MuConeColl.at(1)+NonBJetColl.at(Idxj1W_1jL)).M();


    int Idxj1W_1jH=-1, Idxbt_1jH=-1; float BestDeltambllj=-1;
    for(unsigned int ib=0; ib<BCandColl.size(); ib++){
    for(unsigned int inb=0; inb<NonBJetColl.size(); inb++){
      if(BCandColl.at(ib).DeltaR(NonBJetColl.at(inb))<0.1) continue;
      float mbllj = (MuConeColl.at(0)+MuConeColl.at(1)+NonBJetColl.at(inb)+BCandColl.at(ib)).M();
      float Deltambllj = fabs(mbllj-130);
      if(BestDeltambllj<0){ BestDeltambllj = Deltambllj; Idxj1W_1jH=inb; Idxbt_1jH=ib;}
      else{  
        if(Deltambllj<BestDeltambllj){ BestDeltambllj = Deltambllj; Idxj1W_1jH=inb; Idxbt_1jH=ib;}
      }
    }}
    MbllW_1jH = (MuConeColl.at(0)+MuConeColl.at(1)+NonBJetColl.at(Idxj1W_1jH)+BCandColl.at(Idxbt_1jH)).M();
    Ml1W_1jH  = (MuConeColl.at(0)+NonBJetColl.at(Idxj1W_1jH)).M();
    Ml2W_1jH  = (MuConeColl.at(1)+NonBJetColl.at(Idxj1W_1jH)).M();


    int Idxj1W_H=-1, Idxj2W_H=-1, Idxbt_H=-1; float BestSumDelta_H=-1; 
    for(unsigned int ib=0; ib<BCandColl.size(); ib++){
    for(unsigned int inb1=0; inb1<NonBJetColl.size(); inb1++){
    for(unsigned int inb2=inb1+1; inb2<NonBJetColl.size(); inb2++){
      if(BCandColl.at(ib).DeltaR(NonBJetColl.at(inb1))<0.1) continue;
      if(BCandColl.at(ib).DeltaR(NonBJetColl.at(inb2))<0.1) continue;
      float mjj    = (NonBJetColl.at(inb1)+NonBJetColl.at(inb2)).M();
      float mblljj = (MuConeColl.at(0)+MuConeColl.at(1)+NonBJetColl.at(inb1)+NonBJetColl.at(inb2)+BCandColl.at(ib)).M();
      float SumDelta = fabs(mblljj-172.5)+fabs(mjj-80.4);
      if(BestSumDelta_H<0){ BestSumDelta_H=SumDelta; Idxj1W_H=inb1; Idxj2W_H=inb2; Idxbt_H=ib;}
      else{  
        if(SumDelta<BestSumDelta_H){ BestSumDelta_H=SumDelta; Idxj1W_H=inb1; Idxj2W_H=inb2; Idxbt_H=ib;}
      }
    }}}
    MbllW_H = BestSumDelta_H<0? -1.:(MuConeColl.at(0)+MuConeColl.at(1)+NonBJetColl.at(Idxj1W_H)+NonBJetColl.at(Idxj2W_H)+BCandColl.at(Idxbt_H)).M();
    Ml1W_H  = BestSumDelta_H<0? -1.:(MuConeColl.at(0)+NonBJetColl.at(Idxj1W_H)+NonBJetColl.at(Idxj2W_H)).M();
    Ml2W_H  = BestSumDelta_H<0? -1.:(MuConeColl.at(1)+NonBJetColl.at(Idxj1W_H)+NonBJetColl.at(Idxj2W_H)).M();


    FillHist("NEvt"+Label, 0., weight, 1, 0., 1.);
    FillHist("Nj"+Label, Nj, weight, 10, 0., 10.);
    FillHist("Nb"+Label, Nb, weight, 5, 0., 5.);
    FillHist("PTl1"+Label, Ptl1, weight, 25, 0., 250.);
    FillHist("PTl2"+Label, Ptl2, weight, 20, 0., 100.);
    FillHist("Etal1"+Label, MuConeColl.at(0).Eta(), weight, 20, -5., 5.);
    FillHist("Etal2"+Label, MuConeColl.at(1).Eta(), weight, 20, -5., 5.);
    FillHist("dRll"+Label,  dRll, weight, 25, 0., 5.);
    FillHist("MSSSF"+Label, MSSSF, weight, 25, 0., 250.);
    FillHist("MET"+Label, MET, weight, 20, 0., 100.);
    FillHist("Overlap_lb"+Label, B_overlap, weight, 2, 0., 2.);
    FillHist("Overlap_lj"+Label, J_overlap, weight, 2, 0., 2.);
    if(DrawMVA){
      for(unsigned int im=0; im<MNStrListL.size(); im++){
        TString MVATagStr_Mu = "BDTG_MN"+MNStrListL.at(im)+"_Mu";
        float MVAvalue_Mu = MVAReaderL->EvaluateMVA(MVATagStr_Mu);
        FillHist("BDTG_Mu_MN"+MNStrListL.at(im)+Label, MVAvalue_Mu, weight, 40, -1., 1.);
      }
      for(unsigned int im=0; im<MNStrListH.size() && NonBJetColl.size()>1; im++){
        TString MVATagStr_Mu = "BDTG_MN"+MNStrListH.at(im)+"_Mu";
        float MVAvalue_Mu = MVAReaderH->EvaluateMVA(MVATagStr_Mu);
        FillHist("BDTG_Mu_MN"+MNStrListH.at(im)+Label, MVAvalue_Mu, weight, 40, -1., 1.);
      }
    }
  }
  if(NElL==2 && ElFR){
    FillHist("El_FR_MCCorr"+Label, FR_MCCorr, 1, 2, 0., 1.99);
    int aSumQ = abs(SumCharge(ElLColl));
    if(aSumQ==0) return;
    if(!( ElLColl.at(0).Pt()>25 && ElLColl.at(1).Pt()>15 )) return;
    if( BJetColl.size()==0 ) return;
    if( JetColl.size()<3   ) return;
    if( (JetColl.size()-BJetColl.size())==0 ) return;

    if(!IsDATA){
      int GenLepInfo = GetGenLepInfo(ElLColl, MuLColl, TruthColl);
      if(GenLepInfo<1000) return;
    }

    float FRweight = 1.;
    int SystDir = Option.Contains("FRUp")? 1: Option.Contains("FRDown")? -1: 0; 
    if(DoGenMatchW) FRweight = GetGenMatchFakeWeight(MuLColl, ElLColl, TruthColl, MuTID, ElTID, MuFRKey, ElFRKey, FR_MCCorr);
    else            FRweight = GetMCFakeWeight(MuLColl, ElLColl, MuTID, ElTID, MuFRKey, ElFRKey, SystDir,FR_MCCorr);
    if(NMuT==NMuL && NElT==NElL){ Label="_Obs"+Label; }
    else                        { Label="_Exp"+Label; weight*=FRweight; }

    float TightIso=0.1;
    for(unsigned int ie=0; ie<ElLColl.size() && ConeBasis; ie++){
      Electron TmpEl(ElLColl.at(ie));
      float RelIso = ElLColl.at(ie).MiniRelIso();
      float PTCorr = ElLColl.at(ie).CalcPtCone(RelIso,TightIso), PT=ElLColl.at(ie).Pt();
      if(RelIso>TightIso) TmpEl *= PTCorr/PT;
      ElConeColl.push_back(TmpEl);
    }

    if(!( fabs( (ElConeColl.at(0)+ElConeColl.at(1)).M()-91.2 )>10 )) return;


    vector<Jet> BCandColl = BJetColl.size()>1? BJetColl:JetColl;
    vector<Jet> NonBJetColl = SelLightJets(JetColl, jtps.at(0));

    Nj      = JetColl.size();
    Nb      = min((Float_t) BJetColl.size(),(Float_t) 2.);
    Ptl1    = ElConeColl.at(0).Pt();
    Ptl2    = ElConeColl.at(1).Pt();
    MET     = vMET.Pt();
    dRll    = ElConeColl.at(0).DeltaR(ElConeColl.at(1));
    dRlj11  = ElConeColl.at(0).DeltaR(JetColl.at(0));
    dRlj12  = ElConeColl.at(0).DeltaR(JetColl.at(1));
    dRlj13  = ElConeColl.at(0).DeltaR(JetColl.at(2));
    dRlj21  = ElConeColl.at(1).DeltaR(JetColl.at(0));
    dRlj22  = ElConeColl.at(1).DeltaR(JetColl.at(1));
    dRlj23  = ElConeColl.at(1).DeltaR(JetColl.at(2));
    MSSSF   = (ElConeColl.at(0)+ElConeColl.at(1)).M();
    MTvl1   = MT(ElConeColl.at(0),vMET);
    MTllv   = MT(ElConeColl.at(0)+ElConeColl.at(1), vMET);

    //Vars requiring complex algo.
    HT      = 0;  for(unsigned int itj=0; itj<JetColl.size(); itj++){ HT+=JetColl.at(itj).Pt(); }

    int Idxj1W=-1, Idxj2W=-1; float bestmjjW=-1;
    for(unsigned int ij1=0; ij1<NonBJetColl.size(); ij1++){
    for(unsigned int ij2=ij1+1; ij2<NonBJetColl.size(); ij2++){
      float mjj = (NonBJetColl.at(ij1)+NonBJetColl.at(ij2)).M();
      if(bestmjjW<0){ bestmjjW = mjj; Idxj1W=ij1, Idxj2W=ij2; }
      else{ if(fabs(mjj-80.4)<fabs(bestmjjW-80.4)){ bestmjjW = mjj; Idxj1W=ij1, Idxj2W=ij2; } }
    }} 
    Ml2j1W_BkdTop = (ElConeColl.at(1)+NonBJetColl.at(0)).M();
    Ml2W_BkdTop   = bestmjjW<0? -1.:(ElConeColl.at(1)+NonBJetColl.at(Idxj1W)+NonBJetColl.at(Idxj2W)).M();
    MTbl1v_BkdTop = MT(BJetColl.at(0)+ElConeColl.at(0),vMET);
   

    int Idxj1W_1jL=-1, Idxbt_1jL=-1; float BestSumDelta_L=-1; 
    for(unsigned int ib=0; ib<BCandColl.size(); ib++){
    for(unsigned int inb=0; inb<NonBJetColl.size(); inb++){
      if(BCandColl.at(ib).DeltaR(NonBJetColl.at(inb))<0.1) continue;
      float mllj = (ElConeColl.at(0)+ElConeColl.at(1)+NonBJetColl.at(inb)).M();
      float mbllj = (ElConeColl.at(0)+ElConeColl.at(1)+NonBJetColl.at(inb)+BCandColl.at(ib)).M();
      float SumDelta = fabs(mbllj-160)+fabs(mllj-75);
      if(BestSumDelta_L<0){ BestSumDelta_L=SumDelta; Idxj1W_1jL=inb; Idxbt_1jL=ib;}
      else{  
        if(SumDelta<BestSumDelta_L){ BestSumDelta_L=SumDelta; Idxj1W_1jL=inb; Idxbt_1jL=ib;}
      }
    }}
    MbllW_1jL = (ElConeColl.at(0)+ElConeColl.at(1)+NonBJetColl.at(Idxj1W_1jL)+BCandColl.at(Idxbt_1jL)).M();
    MllW_1jL  = (ElConeColl.at(0)+ElConeColl.at(1)+NonBJetColl.at(Idxj1W_1jL)).M();
    Ml1W_1jL  = (ElConeColl.at(0)+NonBJetColl.at(Idxj1W_1jL)).M();
    Ml2W_1jL  = (ElConeColl.at(1)+NonBJetColl.at(Idxj1W_1jL)).M();


    int Idxj1W_1jH=-1, Idxbt_1jH=-1; float BestDeltambllj=-1;
    for(unsigned int ib=0; ib<BCandColl.size(); ib++){
    for(unsigned int inb=0; inb<NonBJetColl.size(); inb++){
      if(BCandColl.at(ib).DeltaR(NonBJetColl.at(inb))<0.1) continue;
      float mbllj = (ElConeColl.at(0)+ElConeColl.at(1)+NonBJetColl.at(inb)+BCandColl.at(ib)).M();
      float Deltambllj = fabs(mbllj-130);
      if(BestDeltambllj<0){ BestDeltambllj = Deltambllj; Idxj1W_1jH=inb; Idxbt_1jH=ib;}
      else{  
        if(Deltambllj<BestDeltambllj){ BestDeltambllj = Deltambllj; Idxj1W_1jH=inb; Idxbt_1jH=ib;}
      }
    }}
    MbllW_1jH = (ElConeColl.at(0)+ElConeColl.at(1)+NonBJetColl.at(Idxj1W_1jH)+BCandColl.at(Idxbt_1jH)).M();
    Ml1W_1jH  = (ElConeColl.at(0)+NonBJetColl.at(Idxj1W_1jH)).M();
    Ml2W_1jH  = (ElConeColl.at(1)+NonBJetColl.at(Idxj1W_1jH)).M();


    int Idxj1W_H=-1, Idxj2W_H=-1, Idxbt_H=-1; float BestSumDelta_H=-1; 
    for(unsigned int ib=0; ib<BCandColl.size(); ib++){
    for(unsigned int inb1=0; inb1<NonBJetColl.size(); inb1++){
    for(unsigned int inb2=inb1+1; inb2<NonBJetColl.size(); inb2++){
      if(BCandColl.at(ib).DeltaR(NonBJetColl.at(inb1))<0.1) continue;
      if(BCandColl.at(ib).DeltaR(NonBJetColl.at(inb2))<0.1) continue;
      float mjj    = (NonBJetColl.at(inb1)+NonBJetColl.at(inb2)).M();
      float mblljj = (ElConeColl.at(0)+ElConeColl.at(1)+NonBJetColl.at(inb1)+NonBJetColl.at(inb2)+BCandColl.at(ib)).M();
      float SumDelta = fabs(mblljj-172.5)+fabs(mjj-80.4);
      if(BestSumDelta_H<0){ BestSumDelta_H=SumDelta; Idxj1W_H=inb1; Idxj2W_H=inb2; Idxbt_H=ib;}
      else{  
        if(SumDelta<BestSumDelta_H){ BestSumDelta_H=SumDelta; Idxj1W_H=inb1; Idxj2W_H=inb2; Idxbt_H=ib;}
      }
    }}}
    MbllW_H = BestSumDelta_H<0? -1.:(ElConeColl.at(0)+ElConeColl.at(1)+NonBJetColl.at(Idxj1W_H)+NonBJetColl.at(Idxj2W_H)+BCandColl.at(Idxbt_H)).M();
    Ml1W_H  = BestSumDelta_H<0? -1.:(ElConeColl.at(0)+NonBJetColl.at(Idxj1W_H)+NonBJetColl.at(Idxj2W_H)).M();
    Ml2W_H  = BestSumDelta_H<0? -1.:(ElConeColl.at(1)+NonBJetColl.at(Idxj1W_H)+NonBJetColl.at(Idxj2W_H)).M();


    FillHist("NEvt"+Label, 0., weight, 1, 0., 1.);
    FillHist("Nj"+Label, Nj, weight, 10, 0., 10.);
    FillHist("Nb"+Label, Nb, weight, 5, 0., 5.);
    FillHist("PTl1"+Label, Ptl1, weight, 25, 0., 250.);
    FillHist("PTl2"+Label, Ptl2, weight, 20, 0., 100.);
    FillHist("Etal1"+Label, ElConeColl.at(0).Eta(), weight, 20, -5., 5.);
    FillHist("Etal2"+Label, ElConeColl.at(1).Eta(), weight, 20, -5., 5.);
    FillHist("dRll"+Label,  dRll, weight, 25, 0., 5.);
    FillHist("MSSSF"+Label, MSSSF, weight, 25, 0., 250.);
    FillHist("MET"+Label, MET, weight, 20, 0., 100.);
    FillHist("Overlap_lb"+Label, B_overlap, weight, 2, 0., 2.);
    FillHist("Overlap_lj"+Label, J_overlap, weight, 2, 0., 2.);
    if(DrawMVA){
      for(unsigned int ie=0; ie<MNStrListL.size(); ie++){
        TString MVATagStr_El = "BDTG_MN"+MNStrListL.at(ie)+"_El";
        float MVAvalue_El = MVAReaderL->EvaluateMVA(MVATagStr_El);
        FillHist("BDTG_El_MN"+MNStrListL.at(ie)+Label, MVAvalue_El, weight, 40, -1., 1.);
      }
      for(unsigned int ie=0; ie<MNStrListH.size() && NonBJetColl.size()>1; ie++){
        TString MVATagStr_El = "BDTG_MN"+MNStrListH.at(ie)+"_El";
        float MVAvalue_El = MVAReaderH->EvaluateMVA(MVATagStr_El);
        FillHist("BDTG_El_MN"+MNStrListH.at(ie)+Label, MVAvalue_El, weight, 40, -1., 1.);
      }
    }
  }

}



void MCFakeStudy::executeEventFromParameter(AnalyzerParameter param){

  if(!PassMETFilter()) return;

  Event ev = GetEvent();

}

MCFakeStudy::MCFakeStudy(){

  TMVA::Tools::Instance();
  MVAReaderL = new TMVA::Reader();
  MVAReaderH = new TMVA::Reader();

}

MCFakeStudy::~MCFakeStudy(){

  delete FRFile;  delete MVAReaderL;  delete MVAReaderH;
  for(std::map< TString, TH2D* >::iterator mapit = maphist_FR.begin(); mapit!=maphist_FR.end(); mapit++){
    delete mapit->second;
  }
  maphist_FR.clear();

}


float MCFakeStudy::GetMCFakeRate(float VarX, float VarY, TString Key, int SystDir){

  if(!FRFile->GetListOfKeys()->Contains(Key)){ printf("[Error] No %s in FR File.\n", Key.Data()); return -1.; }

  std::map<TString, TH2D*>::iterator mapit = maphist_FR.find(Key);
  if(mapit == maphist_FR.end()){ //first usage
    maphist_FR[Key] = (TH2D*) ((TH2*) FRFile->Get(Key))->Clone();
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

  float FRNom = mapit->second->GetBinContent(mapit->second->FindBin(VarX,VarY));
  float FRErr = mapit->second->GetBinError  (mapit->second->FindBin(VarX,VarY));
  float FR    = SystDir==0? FRNom: FRNom+((float) SystDir)*FRErr;

  return FR;

}


float MCFakeStudy::NvtxReweight(TString Key){
  
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

  return SF;
}



int MCFakeStudy::GetGenLepInfo(vector<Electron>& ElColl, vector<Muon>& MuColl, vector<Gen>& TruthColl){

  int NFk=0, NFlip=0, NCv=0, IdxFlipped=9;
  for(unsigned int im=0; im<MuColl.size(); im++){
    int LepType = GetLeptonType_JH(MuColl.at(im), TruthColl);
    if(LepType<0 && LepType>-5) NFk++;
  }
  for(unsigned int ie=0; ie<ElColl.size(); ie++){
    int LepType = GetLeptonType_JH(ElColl.at(ie), TruthColl);
    if(LepType<0 && LepType>-5) NFk++;
    else if(LepType<-4) NCv++;
    else if(LepType>0){
      int Idx_Closest    = GenMatchedIdx(ElColl.at(ie),TruthColl);
      int IdxType_NearEl = LepType>3? GetPrElType_InSameSCRange(Idx_Closest, TruthColl, "IdxType"):Idx_Closest;
      int Idx_NearEl     = LepType>3? IdxType_NearEl/10:Idx_Closest;
      if(ElColl.at(ie).Charge()*TruthColl.at(Idx_NearEl).PID()>0){ NFlip++; IdxFlipped=ie; }
    }
  }

  int ReturnVal = NFk*1000+NFlip*100+NCv*10+IdxFlipped;

  return ReturnVal;

}


void MCFakeStudy::InitializeReader(TMVA::Reader* ThisReader, TString Option){

  bool IsBelowMW=true;
  if     (Option.Contains("AboveMW")) IsBelowMW=false;
  else if(Option.Contains("BelowMW")) IsBelowMW=true;

  ThisReader->AddVariable("Nj",    &Nj);
  ThisReader->AddVariable("Nb",    &Nb);
  ThisReader->AddVariable("Ptl1",  &Ptl1);
  ThisReader->AddVariable("Ptl2",  &Ptl2);
  ThisReader->AddVariable("MET",   &MET);
  ThisReader->AddVariable("HT",    &HT);
  ThisReader->AddVariable("dRll",  &dRll);
  ThisReader->AddVariable("dRlj11",&dRlj11);
  ThisReader->AddVariable("dRlj12",&dRlj12);
  ThisReader->AddVariable("dRlj13",&dRlj13);
  ThisReader->AddVariable("dRlj21",&dRlj21);
  ThisReader->AddVariable("dRlj22",&dRlj22);
  ThisReader->AddVariable("dRlj23",&dRlj23);
  ThisReader->AddVariable("MSSSF", &MSSSF);
  if(IsBelowMW){
    ThisReader->AddVariable("MbllW_1jL", &MbllW_1jL);
    ThisReader->AddVariable("MllW_1jL",  &MllW_1jL);
    ThisReader->AddVariable("Ml1W_1jL",  &Ml1W_1jL);
    ThisReader->AddVariable("Ml2W_1jL",  &Ml2W_1jL);
  }
  else{
    ThisReader->AddVariable("MbllW_1jH", &MbllW_1jH);
    ThisReader->AddVariable("Ml1W_1jH",  &Ml1W_1jH);
    ThisReader->AddVariable("Ml2W_1jH",  &Ml2W_1jH);
    ThisReader->AddVariable("MbllW_H",     &MbllW_H);
    ThisReader->AddVariable("Ml1W_H",      &Ml1W_H);
    ThisReader->AddVariable("Ml2W_H",      &Ml2W_H);
    ThisReader->AddVariable("Ml2W_BkdTop", &Ml2W_BkdTop);
  }
  ThisReader->AddVariable("MTvl1", &MTvl1);
  ThisReader->AddVariable("MTbl1v_BkdTop", &MTbl1v_BkdTop);
  ThisReader->AddVariable("Ml2j1W_BkdTop", &Ml2j1W_BkdTop);

  TString AnalyzerPath=std::getenv("SKFlat_WD"), MVAPath="/data/Run2UltraLegacy_v3/FullRun2/MVAClassifier/";
  vector<TString> MNStrList;
  if(IsBelowMW){ MNStrListL = {"20", "50", "75"}; MNStrList = MNStrListL; }
  else         { MNStrListH = {"85", "100"};      MNStrList = MNStrListH; }

  for(unsigned int im=0; im<MNStrList.size(); im++){
    TString FileName_Mu="TMVAClassification_MN"+MNStrList.at(im)+"_Mu_BDTG.weights.xml"; 
    TString FileName_El="TMVAClassification_MN"+MNStrList.at(im)+"_El_BDTG.weights.xml"; 
    TString MVATagStr_Mu = "BDTG_MN"+MNStrList.at(im)+"_Mu";
    TString MVATagStr_El = "BDTG_MN"+MNStrList.at(im)+"_El";
    ThisReader->BookMVA(MVATagStr_Mu, AnalyzerPath+MVAPath+FileName_Mu);
    ThisReader->BookMVA(MVATagStr_El, AnalyzerPath+MVAPath+FileName_El);
  }


}


void MCFakeStudy::InitializeTreeVars(){

  Nj=-1, Nb=-1, Ptl1=-1, Ptl2=-1, MET=-1, HT=-1;
  dRll=-1, dRlj11=-1, dRlj12=-1, dRlj13=-1, dRlj21=-1, dRlj22=-1, dRlj23=-1;
  MSSSF=-1;
  MTvl1=-1, MTllv=-1, Ml2j1W_BkdTop=-1, Ml2W_BkdTop=-1, MTbl1v_BkdTop=-1;
  MbllW_1jL=-1, MllW_1jL=-1, Ml1W_1jL=-1, Ml2W_1jL=-1;
  MbllW_1jH=-1, Ml1W_1jH=-1, Ml2W_1jH=-1;
  MbllW_H=-1, Ml1W_H=-1, Ml2W_H=-1; 

}


int MCFakeStudy::GetFakeLepSrcType(Lepton& Lep, vector<Jet>& JetColl){
  //Type: -1: Unmatched, 1:L, 2:C, 3:B
  int SrcType=-1;
  bool NearB=false, NearC=false, NearL=false;
  for(unsigned int ij=0; ij<JetColl.size(); ij++){
    if(Lep.DeltaR(JetColl.at(ij))<0.4){
      if(JetColl.at(ij).hadronFlavour()==5){ NearB=true; break; }//1)
      else if(JetColl.at(ij).hadronFlavour()==4){ NearC=true; }
      else if(JetColl.at(ij).hadronFlavour()==0){ NearL=true; }
    }
  }

  if     (NearB) SrcType=3;
  else if(NearC) SrcType=2;
  else if(NearL) SrcType=1;

  return SrcType;
//1) Higher Priority to B. if there's multiple near jets, then b-jet has higher priority
}

