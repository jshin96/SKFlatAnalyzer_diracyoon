#include "KinVarPlot.h"

void KinVarPlot::initializeAnalyzer(){

  TriLep=false, TetraLep=false, SS2l=false; 
  FakeRun=false, ConvRun=false, FlipRun=false, SystRun=false; 
  VarPlots=false, EffFlow=false, GlobFeas=false;
  for(unsigned int i=0; i<Userflags.size(); i++){
    if(Userflags.at(i).Contains("SS2l"))       SS2l       = true;
    if(Userflags.at(i).Contains("TriLep"))     TriLep     = true;
    if(Userflags.at(i).Contains("TetraLep"))   TetraLep   = true; 
    if(Userflags.at(i).Contains("VarPlots"))   VarPlots   = true; 
    if(Userflags.at(i).Contains("GlobFeas"))   GlobFeas   = true; 
    if(Userflags.at(i).Contains("EffFlow"))    EffFlow    = true; 
    if(Userflags.at(i).Contains("FakeRun"))    FakeRun    = true; 
    if(Userflags.at(i).Contains("ConvRun"))    ConvRun    = true; 
    if(Userflags.at(i).Contains("FlipRun"))    FlipRun    = true; 
    if(Userflags.at(i).Contains("SystRun"))    SystRun    = true; 
  }

  DblMu=false, DblEG=false, MuEG=false;
  if     (DataStream.Contains("DoubleMuon")) DblMu=true;
  else if(DataStream.Contains("MuonEG"))     MuEG =true;
  else if(DataStream.Contains("DoubleEG"))   DblEG=true;
  else if(DataYear==2018 and DataStream.Contains("EGamma")) DblEG=true;

  if(DataYear==2016){
    TrigList_DblMu.push_back("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v");
    TrigList_DblMu.push_back("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v");
    TrigList_DblMu.push_back("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v");
    TrigList_DblMu.push_back("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v");

    TrigList_MuEG.push_back("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v");
    TrigList_MuEG.push_back("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v");
    TrigList_MuEG.push_back("HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v");
    TrigList_MuEG.push_back("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v");

    TrigList_DblEG.push_back("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v");
  }
  if(DataYear==2017){
    TrigList_DblMu.push_back("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v");
    TrigList_DblMu.push_back("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v");
    TrigList_DblMu.push_back("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v");

    TrigList_MuEG.push_back("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v");
    TrigList_MuEG.push_back("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v");

    TrigList_DblEG.push_back("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v");
  }
  if(DataYear==2018){
    TrigList_DblMu.push_back("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v");

    TrigList_MuEG.push_back("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v");
    TrigList_MuEG.push_back("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v");

    TrigList_DblEG.push_back("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v");
  }

  //Set up the tagger map only for the param settings to be used.
  vector<JetTagging::Parameters> jtps;
  jtps.push_back( JetTagging::Parameters(JetTagging::DeepCSV, JetTagging::Medium, JetTagging::incl, JetTagging::mujets) );
  mcCorr->SetJetTaggingParameters(jtps);

  InitializeTreeVars();

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


  TString AnalyzerPath=std::getenv("SKFlat_WD"), MVAPath="/data/Run2Legacy_v4/2017/MVAClassifier/";
  MNStrList = {"20", "50", "75", "100"};
  for(unsigned int im=0; im<MNStrList.size() && SS2l; im++){
    TString FileName_Mu="TMVAClassification_MN"+MNStrList.at(im)+"_Mu_BDTG.weights.xml"; 
    TString FileName_El="TMVAClassification_MN"+MNStrList.at(im)+"_El_BDTG.weights.xml"; 
    TString MVATagStr_Mu = "BDTG_MN"+MNStrList.at(im)+"_Mu";
    TString MVATagStr_El = "BDTG_MN"+MNStrList.at(im)+"_El";
    MVAReader->BookMVA(MVATagStr_Mu, AnalyzerPath+MVAPath+FileName_Mu);
    MVAReader->BookMVA(MVATagStr_El, AnalyzerPath+MVAPath+FileName_El);
  }

  outfile->cd();

}


void KinVarPlot::executeEvent(){


  Event ev = GetEvent();
  float weight = 1., w_GenNorm=1., w_BR=1., w_PU=1.;
  if(!IsDATA){
    w_GenNorm = ev.MCweight()*weight_norm_1invpb*GetKFactor()*ev.GetTriggerLumi("Full");
    w_BR      = GetBRWeight();
    w_PU      = GetPileUpWeight(nPileUp, 0);
    weight *= w_GenNorm * w_BR * w_PU;
  }
  FillHist("CutFlow", 0., weight, 20, 0., 20.);

  bool PassTrig=false, PassMETFilterList=false;
  if(TetraLep or TriLep){
    if(!IsDATA) PassTrig = ev.PassTrigger(TrigList_MuEG) or ev.PassTrigger(TrigList_DblMu) or ev.PassTrigger(TrigList_DblEG);
    else{
      if     (MuEG)  PassTrig = ev.PassTrigger(TrigList_MuEG);
      else if(DblMu) PassTrig = (!ev.PassTrigger(TrigList_MuEG)) and ev.PassTrigger(TrigList_DblMu);
      else if(DblEG) PassTrig = (!(ev.PassTrigger(TrigList_MuEG) or ev.PassTrigger(TrigList_DblMu))) and ev.PassTrigger(DblEG);
    }
  }
  else if(SS2l){
    if(!IsDATA) PassTrig = ev.PassTrigger(TrigList_DblMu) or ev.PassTrigger(TrigList_DblEG) or ev.PassTrigger(TrigList_MuEG);
    else{
      if     (DblMu) PassTrig = ev.PassTrigger(TrigList_DblMu);
      else if(DblEG) PassTrig = ev.PassTrigger(TrigList_DblEG);
      else if(MuEG)  PassTrig = ev.PassTrigger(TrigList_MuEG);
    }
  }
  PassMETFilterList=PassMETFilter();
  if(EffFlow){ PassTrig=true; PassMETFilterList=true; }
  if(!PassTrig) return;
  FillHist("CutFlow", 1., weight, 20, 0., 20.);
  if(!PassMETFilterList) return;
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
    if(FlipRun && IsDATA && (NPreMu+NPreEl)>1) PreCutPass=true;
  }
  if(!PreCutPass) return;


  TString IDSSLabel = SS2l? "SS":""; TString TLabel = FakeRun? "L":"T";
  vector<Muon>     muonTightColl     = SelectMuons(muonPreColl, "TopHN17"+TLabel, 10., 2.4);
  vector<Electron> electronTightColl = SelectElectrons(electronPreColl, "TopHN17"+IDSSLabel+TLabel, 15., 2.5);
  vector<Muon>     muonLooseColl     = SelectMuons(muonPreColl, "TopHN17L", 10., 2.4);
  vector<Electron> electronLooseColl = SelectElectrons(electronPreColl, "TopHN17"+IDSSLabel+"L", 15., 2.5);
  vector<Muon>     muonVetoColl      = SelectMuons(muonPreColl, "TopHN17L", 10., 2.4);
  vector<Electron> electronVetoColl  = SelectElectrons(electronPreColl, "TopHN17L", 10., 2.5);

  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepCSV, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
  vector<Jet> jetPreColl = GetAllJets();
  sort(jetPreColl.begin(), jetPreColl.end(), PtComparing);
  vector<Jet> jetColl  = SelectJets(jetPreColl, muonLooseColl, electronVetoColl, "tight", 25., 2.4, "LVeto");
  vector<Jet> bjetColl = SelBJets(jetColl, param_jets);

  Particle vMET = ev.GetMETVector();
  Particle vMET_xyCorr(pfMET_Type1_PhiCor_pt*TMath::Cos(pfMET_Type1_PhiCor_phi), pfMET_Type1_PhiCor_pt*TMath::Sin(pfMET_Type1_PhiCor_phi), 0., pfMET_Type1_PhiCor_pt);

  vector<Gen> truthColl;


  bool EventCand = false;
  if(SS2l){ EventCand = muonTightColl.size()==2 or electronTightColl.size()==2 or (muonTightColl.size()==1 && electronTightColl.size()==1); }
  if(TriLep){ EventCand = (muonTightColl.size()+electronTightColl.size())==3; }
  if(TetraLep){ EventCand = (muonTightColl.size()+electronTightColl.size())==4; }

  float w_TopPtRW = 1., w_Prefire = 1., sf_Trig = 1., w_FR=1.;
  float sf_MuTk = 1., sf_MuID = 1., sf_MuIso = 1., sf_ElReco = 1., sf_ElID = 1., sf_BTag = 1.;
  if((!IsDATA) and EventCand){
    //if(MCSample.Contains("TT") and MCSample.Contains("powheg")) truthColl = GetGens();
    //w_TopPtRW = mcCorr->GetTopPtReweight(truthColl);
    sf_MuID   = GetMuonSF(muonTightColl, "TopHNID_TkMu", "ID");
    //sf_MuIso  = GetMuonSF(muonTightColl, "POGTIso_POGTID", "Iso");
    sf_ElReco = GetElectronSF(electronTightColl, "", "Reco");
    sf_ElID   = GetElectronSF(electronTightColl, "TopHNID"+IDSSLabel, "ID");
    sf_BTag   = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets);
    TString SFKey_Trig_All = muonTightColl.size()==2? "DiMuIso_HNTopID":electronTightColl.size()==2? "DiElIso_HNTopIDSS":"EMuIso_HNTopIDSS"; 
    sf_Trig   = SS2l? mcCorr->GetTriggerSF(electronTightColl, muonTightColl, SFKey_Trig_All, ""):1.;
    w_Prefire = GetPrefireWeight(0);
    //cout<<"w_gen:"<<w_gen<<" w_lumi:"<<w_lumi<<" w_PU:"<<w_PU<<" w_prefire:"<<w_prefire<<" sf_trig:"<<sf_trig<<endl;
    //cout<<"sf_mutk"<<sf_mutk<<" sf_muid:"<<sf_muid<<" sf_muiso:"<<sf_muiso<<" sf_elreco:"<<sf_elreco<<" sf_elid:"<<sf_elid<<" sf_btag:"<<sf_btag<<endl;
  }
  if(IsDATA && FakeRun && EventCand){
    w_FR      = CalcTestFakeWeight(muonLooseColl, electronLooseColl,
                  "TopHN17T", "TopHN17L", "TopHN17"+IDSSLabel+"T", "TopHN17"+IDSSLabel+"L", bjetColl.size(), 0);
  }
//  if(IsDATA && FlipRun && EventCand){
//    for(unsigned int ie=0; ie<electronTightColl.size(); ie++){
//      w_CF += GetCFRSF(electronTightColl.at(ie), "App2Bin2_Fin", "DataEff");
//    }
//  }
  weight *= w_TopPtRW * w_Prefire * sf_Trig * w_FR;
  weight *= sf_MuTk * sf_MuID * sf_MuIso * sf_ElReco * sf_ElID * sf_BTag;

 
  if(SS2l){
    if(VarPlots or GlobFeas){
      if(!(IsDATA && FlipRun)){
        MakePlotSS2L(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_xyCorr, weight, "");
      }
      else{
        for(unsigned ie=0; ie<electronTightColl.size(); ie++){
          double w_CFN = GetCFRSF(electronTightColl.at(ie), "App2Bin2_Fin", "DataEff");
          double PTN   = GetFlipCorrPT(electronTightColl.at(ie), "App2Bin2_Fin", "DataScaleSmear");
          std::vector<Electron> ElTCollN = electronTightColl;
          ElTCollN.at(ie).SetPtEtaPhiM(PTN, electronTightColl.at(ie).Eta(), electronTightColl.at(ie).Phi(), electronTightColl.at(ie).M());
          MakePlotSS2L(muonTightColl, muonLooseColl, muonVetoColl, ElTCollN, electronLooseColl, electronVetoColl,
                       jetColl, bjetColl, vMET_xyCorr, weight*w_CFN, "");
        }
      }
    }
    if(EffFlow){
      CheckEffFlow(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
                   jetColl, bjetColl, vMET_xyCorr, ev, w_GenNorm*w_BR*w_PU, "");
    }
  }
  if(TriLep){
    if(GlobFeas){
      MakePlot3L(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
                 jetColl, bjetColl, vMET_xyCorr, weight, "");
    }
  }
  if(TetraLep){
    if(GlobFeas){
      MakePlot4L(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
                 jetColl, bjetColl, vMET_xyCorr, weight, "");
    }
  }
  if(SystRun && ((!IsDATA) or FakeRun)){
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

    float w_PUUp=1., w_PUDown=1., w_PrefireUp=1., w_PrefireDown=1., w_FRUp=1., w_FRDown=1.;
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
    }
    if(FakeRun && EventCand){
      w_FRUp   = CalcTestFakeWeight(muonLooseColl, electronLooseColl,
                  "TopHN17T", "TopHN17L", "TopHN17"+IDSSLabel+"T", "TopHN17"+IDSSLabel+"L", bjetColl.size(),  1);
      w_FRDown = CalcTestFakeWeight(muonLooseColl, electronLooseColl,
                  "TopHN17T", "TopHN17L", "TopHN17"+IDSSLabel+"T", "TopHN17"+IDSSLabel+"L", bjetColl.size(), -1);
    }

    float w_base = w_GenNorm * w_BR * w_TopPtRW * sf_MuTk * sf_MuID * sf_MuIso * sf_ElID * sf_Trig;
    float weight_PUUp        = w_base * w_PUUp   * w_Prefire     * w_FR     * sf_ElReco     * sf_BTag;
    float weight_PUDown      = w_base * w_PUDown * w_Prefire     * w_FR     * sf_ElReco     * sf_BTag;
    float weight_PrefireUp   = w_base * w_PU     * w_PrefireUp   * w_FR     * sf_ElReco     * sf_BTag;
    float weight_PrefireDown = w_base * w_PU     * w_PrefireDown * w_FR     * sf_ElReco     * sf_BTag;
    float weight_FRUp        = w_base * w_PU     * w_Prefire     * w_FRUp   * sf_ElReco     * sf_BTag;
    float weight_FRDown      = w_base * w_PU     * w_Prefire     * w_FRDown * sf_ElReco     * sf_BTag;
    float weight_ElRecoUp    = w_base * w_PU     * w_Prefire     * w_FR     * sf_ElRecoUp   * sf_BTag;
    float weight_ElRecoDown  = w_base * w_PU     * w_Prefire     * w_FR     * sf_ElRecoDown * sf_BTag;
    float weight_JESUp       = w_base * w_PU     * w_Prefire     * w_FR     * sf_ElReco     * sf_BTag_JESUp;
    float weight_JESDown     = w_base * w_PU     * w_Prefire     * w_FR     * sf_ElReco     * sf_BTag_JESDown;
    float weight_JERUp       = w_base * w_PU     * w_Prefire     * w_FR     * sf_ElReco     * sf_BTag_JERUp;
    float weight_JERDown     = w_base * w_PU     * w_Prefire     * w_FR     * sf_ElReco     * sf_BTag_JERDown;
    float weight_LTagUp      = w_base * w_PU     * w_Prefire     * w_FR     * sf_ElReco     * sf_BTag_LTagUp;
    float weight_LTagDown    = w_base * w_PU     * w_Prefire     * w_FR     * sf_ElReco     * sf_BTag_LTagDown;
    float weight_HTagUp      = w_base * w_PU     * w_Prefire     * w_FR     * sf_ElReco     * sf_BTag_HTagUp;
    float weight_HTagDown    = w_base * w_PU     * w_Prefire     * w_FR     * sf_ElReco     * sf_BTag_HTagDown;

    bool StdSyst=false;
    if(SS2l){
      if(EffFlow && !IsDATA && !FakeRun){
        CheckEffFlow(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_xyCorr, ev, w_GenNorm*w_BR*w_PU, "");
      }
      if(VarPlots or GlobFeas) StdSyst=true;
    }//End of SS2l
    if(TriLep){ if(GlobFeas) StdSyst=true; }
    if(TetraLep){ if(GlobFeas) StdSyst=true; }
    if(StdSyst){
      if(!IsDATA && !FakeRun){
        RunStdSyst(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_xyCorr, weight_PUUp, "_SystUp_PU");
        RunStdSyst(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_xyCorr, weight_PUDown, "_SystDown_PU");
        RunStdSyst(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_xyCorr, weight_PrefireUp, "_SystUp_Pref");
        RunStdSyst(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_xyCorr, weight_PrefireDown, "_SystDown_Pref");
        RunStdSyst(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_xyCorr, weight_ElRecoUp, "_SystUp_ElReco");
        RunStdSyst(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_xyCorr, weight_ElRecoDown, "_SystDown_ElReco");
        RunStdSyst(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetJESUpColl, bjetJESUpColl, vMET_T1xy_JESUp, weight_JESUp, "_SystUp_JES");
        RunStdSyst(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetJESDownColl, bjetJESDownColl, vMET_T1xy_JESDown, weight_JESDown, "_SystDown_JES");
        RunStdSyst(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetJERUpColl, bjetJERUpColl, vMET_T1xy_JERUp, weight_JERUp, "_SystUp_JER");
        RunStdSyst(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetJERDownColl, bjetJERDownColl, vMET_T1xy_JERDown, weight_JERDown, "_SystDown_JER");
        RunStdSyst(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy_UnclUp, weight, "_SystUp_Uncl");
        RunStdSyst(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_T1xy_UnclDown, weight, "_SystDown_Uncl");
        RunStdSyst(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_xyCorr, weight_LTagUp, "_SystUp_LTag");
        RunStdSyst(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_xyCorr, weight_LTagDown, "_SystDown_LTag");
        RunStdSyst(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_xyCorr, weight_HTagUp, "_SystUp_HTag");
        RunStdSyst(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                     jetColl, bjetColl, vMET_xyCorr, weight_HTagDown, "_SystDown_HTag");
      }
      else if(FakeRun){
          RunStdSyst(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                       jetColl, bjetColl, vMET_xyCorr, weight_FRUp, "_SystUp_FR");
          RunStdSyst(muonTightColl, muonLooseColl, muonLooseColl, electronTightColl, electronLooseColl, electronVetoColl,
                       jetColl, bjetColl, vMET_xyCorr, weight_FRDown, "_SystDown_FR");
      }
    }
  }//End of Syst

}


void KinVarPlot::RunStdSyst(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                            vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                            vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label){

  if(SS2l){
    if(GlobFeas or VarPlots){ MakePlotSS2L(MuTColl, MuLColl, MuVColl, ElTColl, ElLColl, ElVColl, JetColl, BJetColl, vMET, weight, Label); }
  }
  if(TriLep){
    if(GlobFeas){ MakePlot3L(MuTColl, MuLColl, MuVColl, ElTColl, ElLColl, ElVColl, JetColl, BJetColl, vMET, weight, Label); }
  }
  if(TetraLep){
    if(GlobFeas){ MakePlot4L(MuTColl, MuLColl, MuVColl, ElTColl, ElLColl, ElVColl, JetColl, BJetColl, vMET, weight, Label); }
  }
}



void KinVarPlot::CheckEffFlow(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                              vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                              vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& ev, float weight, TString Label)
{

  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  float w_Prefire = 1., sf_Trig = 1.;
  float sf_MuID = 1., sf_ElReco = 1., sf_ElID = 1., sf_BTag = 1.;
  if((NMuL+NElL)>1){
    JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepCSV, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
    w_Prefire = GetPrefireWeight(0);
    TString SFKey_Trig_All = MuTColl.size()==2? "DiMuIso_HNTopID":ElTColl.size()==2? "DiElIso_HNTopIDSS":"EMuIso_HNTopIDSS"; 
    sf_Trig   = mcCorr->GetTriggerSF(ElTColl, MuTColl, SFKey_Trig_All, "");
    sf_MuID   = GetMuonSF(MuTColl, "TopHNID_TkMu", "ID");
    sf_ElReco = GetElectronSF(ElTColl, "", "Reco");
    sf_ElID   = GetElectronSF(ElTColl, "TopHNIDSS", "ID");
    sf_BTag   = mcCorr->GetBTaggingReweight_1a(JetColl, param_jets);
  }
  int it_cut=0;
  FillHist("SelEffFlow_2M"+Label, it_cut, weight, 10, 0., 10.);
  FillHist("SelEffFlow_2E"+Label, it_cut, weight, 10, 0., 10.); it_cut++;

  if(!PassMETFilter()) return;
  FillHist("SelEffFlow_2M"+Label, it_cut, weight, 10, 0., 10.);
  FillHist("SelEffFlow_2E"+Label, it_cut, weight, 10, 0., 10.); it_cut++;

  weight *= sf_MuID*sf_ElID*sf_ElReco*sf_BTag;
  if( !( (NMuT==2 and NElT==0) or (NElT==2 and NMuT==0) ) ) return;
  if( !(NMuT==NMuL and NElT==NElL) ) return;
  if( !(NMuT==NMuV and NElT==NElV) ) return;
  if(NMuT==2){
    Label="_2M"+Label;
    if(!(MuTColl.at(0).Pt()>20 && MuTColl.at(1).Pt()>10)) return;
    FillHist("SelEffFlow"+Label, it_cut, weight, 10, 0., 10.); it_cut++;

    double Mll = (MuTColl.at(0)+MuTColl.at(1)).M();
    if(DataYear>2016 && Mll<4) return; 
    FillHist("SelEffFlow"+Label, it_cut, weight, 10, 0., 10.); it_cut++;

    weight*=w_Prefire;
    FillHist("SelEffFlow"+Label, it_cut, weight, 10, 0., 10.); it_cut++;

    if(!ev.PassTrigger(TrigList_DblMu)) return;
    weight*=sf_Trig;
    FillHist("SelEffFlow"+Label, it_cut, weight, 10, 0., 10.); it_cut++;

    if(MuTColl.at(0).Charge()!=MuTColl.at(1).Charge()) return;
    FillHist("SelEffFlow"+Label, it_cut, weight, 10, 0., 10.); it_cut++;

    if(BJetColl.size()<1) return;
    FillHist("SelEffFlow"+Label, it_cut, weight, 10, 0., 10.); it_cut++;

    if(JetColl.size() <3) return;
    FillHist("SelEffFlow"+Label, it_cut, weight, 10, 0., 10.); it_cut++;

    FillHist("NEvent"+Label, 0., weight, 1, 0., 1.);
  }
  if(NElT==2){
    Label="_2E"+Label;
    if(!(ElTColl.at(0).Pt()>25 && ElTColl.at(1).Pt()>15)) return;
    FillHist("SelEffFlow"+Label, it_cut, weight, 10, 0., 10.); it_cut++;

    weight*=w_Prefire;
    FillHist("SelEffFlow"+Label, it_cut, weight, 10, 0., 10.); it_cut++;

    if(!ev.PassTrigger(TrigList_DblEG)) return;
    weight*=sf_Trig;
    FillHist("SelEffFlow"+Label, it_cut, weight, 10, 0., 10.); it_cut++;

    int aSumQ = abs(SumCharge(ElLColl));
    if(aSumQ==0) return;
    FillHist("SelEffFlow"+Label, it_cut, weight, 10, 0., 10.); it_cut++;

    if(BJetColl.size()<1) return;
    FillHist("SelEffFlow"+Label, it_cut, weight, 10, 0., 10.); it_cut++;

    if(JetColl.size() <3) return;
    FillHist("SelEffFlow"+Label, it_cut, weight, 10, 0., 10.); it_cut++;

    double Mll = (ElTColl.at(0)+ElTColl.at(1)).M();
    if(fabs(Mll-91.2)<10.) return;
    FillHist("SelEffFlow"+Label, it_cut, weight, 10, 0., 10.); it_cut++;

    FillHist("NEvent"+Label, 0., weight, 1, 0., 1.);
  }
}


void KinVarPlot::MakePlotSS2L(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                              vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                              vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{

  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  if( !( (NMuT==2 and NElT==0) or (NElT==2 and NMuT==0) ) ) return;
  if( !(NMuT==NMuL and NElT==NElL) ) return;
  if( !(NMuT==NMuV and NElT==NElV) ) return;
  if( FakeRun      and weight==0.  ) return; 
  if(NMuT==2){
    if(MuTColl.at(0).Charge()!=MuTColl.at(1).Charge()) return;
    if(!(MuTColl.at(0).Pt()>20 && MuTColl.at(1).Pt()>10)) return;
    double Mll = (MuTColl.at(0)+MuTColl.at(1)).M();
    if(DataYear>2016 && Mll<4) return; 
    if(!IsDATA){
      int GenLepInfo = GetGenLepInfo(ElTColl, MuTColl);
      if(ConvRun && GenLepInfo>=100) return;
      if(FlipRun && (GenLepInfo>999 or GenLepInfo<100)) return;
    }
    InitializeTreeVars();
    if(VarPlots) FillHist("NbPre_2M"+Label, BJetColl.size(), weight, 5, 0., 5.);
    if(BJetColl.size()<1) return;
    if(VarPlots) FillHist("NjPre_2M"+Label, JetColl.size(), weight, 10, 0., 10.);
    if(JetColl.size() <3) return;
    if(VarPlots) FillHist("MSSSFPre_2M"+Label, Mll, weight, 25, 0., 250.);


    Nj      = JetColl.size();
    Nb      = BJetColl.size();
    //Nb      = min((Float_t) BJetColl.size(),(Float_t) 2.);
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
    if(VarPlots) PlotParameters("_2M"+Label);
    if(GlobFeas) FillGlobFeasBins2L("Mu",Label);
  }
  if(NElT==2){
    int aSumQ = abs(SumCharge(ElLColl));
    if(IsDATA && FlipRun){ if(aSumQ!=0) return; }
    else                 { if(aSumQ==0) return; }
    if(!(ElTColl.at(0).Pt()>25 && ElTColl.at(1).Pt()>15)) return;
    if(!IsDATA){
      int GenLepInfo = GetGenLepInfo(ElTColl, MuTColl);
      int IdxFlipped = GenLepInfo % 1000;
      if(ConvRun && GenLepInfo>=100) return;
      if(FlipRun && (GenLepInfo>999 or GenLepInfo<100)) return;
      if(FlipRun && IdxFlipped<2){ weight *= GetCFRSF(ElTColl.at(IdxFlipped), "App2Bin1_Fin"); }
    }
    InitializeTreeVars();
    double Mll = (ElTColl.at(0)+ElTColl.at(1)).M();
    if(VarPlots) FillHist("NbPre_2E"+Label, BJetColl.size(), weight, 5, 0., 5.);
    if(BJetColl.size()<1) return;
    if(VarPlots) FillHist("NjPre_2E"+Label, JetColl.size(), weight, 10, 0., 10.);
    if(JetColl.size() <3) return;
    if(VarPlots) FillHist("MSSSFPre_2E"+Label, Mll, weight, 25, 0., 250.);
    if(fabs(Mll-91.2)<10.) return;

    Nj      = JetColl.size();
    Nb      = BJetColl.size();
    //Nb      = min((Float_t) BJetColl.size(),(Float_t) 2.);
    Ptl1    = ElTColl.at(0).Pt();
    Ptl2    = ElTColl.at(1).Pt();
    Ptj1    = JetColl.at(0).Pt();
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
    if(VarPlots) PlotParameters("_2E"+Label);
    if(GlobFeas) FillGlobFeasBins2L("El",Label);
  }

}

void KinVarPlot::FillGlobFeasBins2L(TString Mix, TString Label){

  for(unsigned int im=0; im<MNStrList.size(); im++){
    TString MN = MNStrList.at(im), MVATagStr = "BDTG_MN"+MN+"_"+Mix;
    if(MCSample.Contains("MN")){
      if(!MCSample.Contains("MN"+MN)) continue;
      if(!MCSample.Contains(Mix)) continue;
    }
    float MVAvalue = MVAReader->EvaluateMVA(MVATagStr);
    int Nbin    = Mix=="Mu"? 47:27, Nbin2L = Mix=="Mu"? 40:20;
    int IdxFill = ceil( (MVAvalue+1.)/2.*((float) Nbin2L) );
    if(IdxFill<1 or IdxFill>Nbin2L) IdxFill=0;
    FillHist("SigBins_"+Mix+"_MN"+MN+Label, IdxFill+1E-2, w_tot, Nbin, 1., 1.+(float) Nbin);
  }

}



void KinVarPlot::MakePlot3L(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                            vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                            vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{
  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  int NLepT = NMuT+NElT, NLepL = NMuL+NElL, NLepV = NMuV+NElV;
  if( !( NLepT==3 && NLepL==3 && NLepV==3 ) ) return; 
  if( FakeRun      and weight==0.  ) return; 

  bool PassTrigAcc=false;
  if(NMuT>1){
    for(unsigned int im1=0; im1<MuTColl.size(); im1++){
    for(unsigned int im2=im1+1; im2<MuTColl.size(); im2++){
      float PTl1 = MuTColl.at(im1).Pt(), PTl2 = MuTColl.at(im2).Pt();
      float Mll  = (MuTColl.at(im1)+MuTColl.at(im2)).M();
      if(PTl1>20 && PTl2>10 && (DataYear==2016 or Mll>4)){ PassTrigAcc=true;  }
    }}
  }
  if(NElT>1 && !PassTrigAcc){
    for(unsigned int ie1=0; ie1<ElTColl.size(); ie1++){
    for(unsigned int ie2=ie1+1; ie2<ElTColl.size(); ie2++){
      float PTl1 = ElTColl.at(ie1).Pt(), PTl2 = ElTColl.at(ie2).Pt();
      if(PTl1>25 && PTl2>15){ PassTrigAcc=true;  }
    }}
  }
  if(NMuT>0 && NElT>0 && !PassTrigAcc){
    for(unsigned int ie=0; ie<ElTColl.size(); ie++){
    for(unsigned int im=ie+1; im<MuTColl.size(); im++){
      float PTe = ElTColl.at(ie).Pt(), PTm = MuTColl.at(im).Pt();
      if( (PTe>25 && PTm>10) or (PTe>15 && PTm>25) ){ PassTrigAcc=true;  }
    }}
  }
  if(!PassTrigAcc) return;

  int Qtot = SumCharge(MuTColl, ElTColl);
  if(abs(Qtot)!=1) return;

  int IdxSt=0, Nb=BJetColl.size(), Nj=JetColl.size();
  //M3l, Mll for N->llv, Mmix for Mll of lNl current
  float M3l=-1, MNll=-1, Mmix=-1;
  bool PassMVeto=false;  bool OptimizeMode=false;
  if(NMuT==3 && NElT==0){
    IdxSt=1;
    int IdxOS  = TriMuChargeIndex(MuTColl, "OS");
    int IdxSS2 = TriMuChargeIndex(MuTColl, "SS2");
    int IdxSS1 = TriMuChargeIndex(MuTColl, "SS1");
    float MOSSS1 = (MuTColl.at(IdxOS)+MuTColl.at(IdxSS1)).M();
    float MOSSS2 = (MuTColl.at(IdxOS)+MuTColl.at(IdxSS2)).M();
    if(MOSSS1>11 && MOSSS2>11 && fabs(MOSSS1-91.2)>10 && fabs(MOSSS2-91.2)>10) PassMVeto=true;
    M3l  = (MuTColl.at(0)+MuTColl.at(1)+MuTColl.at(2)).M();
    MNll = (MuTColl.at(IdxOS)+MuTColl.at(IdxSS2)).M(); 
    Mmix = (MuTColl.at(IdxSS1)+MuTColl.at(IdxSS2)).M();
  }
  else if(NMuT==2 && NElT==1){
    IdxSt=MuTColl.at(0).Charge()!=MuTColl.at(1).Charge()? 2:3;
    int IdxlWN = MuTColl.at(0).Charge()!=ElTColl.at(0).Charge()? 0:1;
    float MOSSS = IdxSt==2? (MuTColl.at(0)+MuTColl.at(1)).M():-1.;
    if(IdxSt==3 or (MOSSS>11 && fabs(MOSSS-91.2)>10)) PassMVeto=true;
    M3l  = (MuTColl.at(0)+MuTColl.at(1)+ElTColl.at(0)).M();
    MNll = (MuTColl.at(IdxlWN)+ElTColl.at(0)).M();
    Mmix = (MuTColl.at(0)+MuTColl.at(1)).M();
  }
  else if(NMuT==1 && NElT==2){
    IdxSt=ElTColl.at(0).Charge()!=ElTColl.at(1).Charge()? 4:5;
    int IdxlWN = MuTColl.at(0).Charge()!=ElTColl.at(0).Charge()? 0:1;
    float MOSSS = IdxSt==4? (ElTColl.at(0)+ElTColl.at(1)).M():0.;
    if(IdxSt==5 or (MOSSS>11 && fabs(MOSSS-91.2)>10)) PassMVeto=true;
    M3l  = (ElTColl.at(0)+ElTColl.at(1)+MuTColl.at(0)).M();
    MNll = (MuTColl.at(0)+ElTColl.at(IdxlWN)).M();
    Mmix = (ElTColl.at(0)+ElTColl.at(1)).M();
  }
  else if(NMuT==0 && NElT==3){
    IdxSt=6;
    int IdxOS  = TriElChargeIndex(ElTColl, "OS");
    int IdxSS2 = TriElChargeIndex(ElTColl, "SS2");
    int IdxSS1 = TriElChargeIndex(ElTColl, "SS1");
    float MOSSS1 = (ElTColl.at(IdxOS)+ElTColl.at(IdxSS1)).M();
    float MOSSS2 = (ElTColl.at(IdxOS)+ElTColl.at(IdxSS2)).M();
    if(MOSSS1>11 && MOSSS2>11 && fabs(MOSSS1-91.2)>10 && fabs(MOSSS2-91.2)>10) PassMVeto=true;
    M3l  = (ElTColl.at(0)+ElTColl.at(1)+ElTColl.at(2)).M();
    MNll = (ElTColl.at(IdxOS)+ElTColl.at(IdxSS2)).M();
    Mmix = (ElTColl.at(0)+ElTColl.at(1)).M();
  }
  if(!PassMVeto) return;
  if(OptimizeMode){ FillHist("Nb_Pre"+Label, Nb, weight,  5, 0., 5.);
                    FillHist("Nj_Pre"+Label, Nj, weight, 10, 0., 10.); }
  if(!(Nb>0 && Nj>1)) return;
  if(!IsDATA){
    int GenLepInfo = GetGenLepInfo(ElTColl, MuTColl);
    if(ConvRun && GenLepInfo>=100) return;
  }

  FillHist("IdxSt"+Label, IdxSt, weight, 6, 1., 7.);
  if(OptimizeMode){
    FillHist("M3l"+Label, M3l, weight, 40, 0., 200.);
    FillHist("Mmix"+Label, Mmix, weight, 40, 0., 200.);
    FillHist("MNll"+Label, MNll, weight, 40, 0., 200.);
    FillHist("M3l_MNll"+Label, M3l, MNll, weight, 40, 0., 200., 40, 0., 200.);
    FillHist("M3l_Mmix"+Label, M3l, Mmix, weight, 40, 0., 200., 40, 0., 200.);
    FillHist("MNll_Mmix"+Label, MNll, Mmix, weight, 40, 0., 200., 40, 0., 200.);
  }
  
  vector<TString> MixList={"Mu", "El"};
  for(unsigned int ix=0; ix<MixList.size(); ix++){
  for(unsigned int im=0; im<MNStrList.size(); im++){
    TString MN=MNStrList.at(im), Mix=MixList.at(ix);
    if(MCSample.Contains("MN")){
      if(!MCSample.Contains("MN"+MN)) continue;
      if(!MCSample.Contains(Mix)) continue;
    }

    int IdxFill = Mix=="Mu"? 40:20; bool PassMWin=false;
    if(Mix=="El"){
      if(MN=="20" ){ PassMWin = (M3l>50 && M3l<80) && ((Mmix>45 && Mmix<80) or (MNll>5 && MNll<20)); }
      if(MN=="50" ){ PassMWin = (M3l>40 && M3l<70) && ((Mmix>20 && Mmix<60) or (MNll>10 && MNll<50)); }
      if(MN=="75" ){ PassMWin = (M3l>30 && M3l<60) && ((Mmix>10) or (MNll>10)); }
      if(MN=="100"){ PassMWin = (M3l>30 && M3l<90) && ((Mmix>15) or (MNll>15)); }
      if(IdxSt<4) continue;
      IdxFill += (IdxSt-3);
    }
    else if(Mix=="Mu"){
      if(MN=="20" ){ PassMWin =((M3l>55 && M3l<80) &&  (Mmix>30 && Mmix<70))
                            or ((M3l>50 && M3l<80) &&  (MNll >5 && MNll<20)); }
      if(MN=="50" ){ PassMWin = (M3l>35 && M3l<75) && ((Mmix>10 && Mmix<55) or (MNll>10 && MNll<55)); }
      if(MN=="75" ){ PassMWin = (M3l>20 && M3l<65) && ((Mmix> 5 && Mmix<40) or (MNll>10)); }
      if(MN=="100"){ PassMWin = (M3l>30 && M3l<85) && ((Mmix>15 && Mmix<55) or (MNll>15 && MNll<55)); }
      if(IdxSt>3) continue;
      IdxFill += IdxSt;
    }
    //if(!PassMWin) continue;

    int Nbin=Mix=="Mu"? 47:27;
    FillHist("SigBins_"+Mix+"_MN"+MN+Label, IdxFill+1E-2, weight, Nbin, 1., 1.+(float) Nbin);
  }}

}


void KinVarPlot::MakePlot4L(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                            vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                            vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{

  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  int NLepT = NMuT+NElT, NLepL = NMuL+NElL, NLepV = NMuV+NElV;
  if( !( NLepT==4 && NLepL==4 && NLepV==4 ) ) return; 
  if( FakeRun      and weight==0.  ) return; 

  bool PassTrigAcc=false;
  if(NMuT>1){
    for(unsigned int im1=0; im1<MuTColl.size(); im1++){
    for(unsigned int im2=im1+1; im2<MuTColl.size(); im2++){
      float PTl1 = MuTColl.at(im1).Pt(), PTl2 = MuTColl.at(im2).Pt();
      float Mll  = (MuTColl.at(im1)+MuTColl.at(im2)).M();
      if(PTl1>20 && PTl2>10 && (DataYear==2016 or Mll>4)){ PassTrigAcc=true;  }
    }}
  }
  if(NElT>1 && !PassTrigAcc){
    for(unsigned int ie1=0; ie1<ElTColl.size(); ie1++){
    for(unsigned int ie2=ie1+1; ie2<ElTColl.size(); ie2++){
      float PTl1 = ElTColl.at(ie1).Pt(), PTl2 = ElTColl.at(ie2).Pt();
      if(PTl1>25 && PTl2>15){ PassTrigAcc=true;  }
    }}
  }
  if(NMuT>0 && NElT>0 && !PassTrigAcc){
    for(unsigned int ie=0; ie<ElTColl.size(); ie++){
    for(unsigned int im=ie+1; im<MuTColl.size(); im++){
      float PTe = ElTColl.at(ie).Pt(), PTm = MuTColl.at(im).Pt();
      if( (PTe>25 && PTm>10) or (PTe>15 && PTm>25) ){ PassTrigAcc=true;  }
    }}
  }
  if(!PassTrigAcc) return;

  int SumQ_M = SumCharge(MuTColl), SumQ_E = SumCharge(ElTColl), Qtot = SumQ_M+SumQ_E;
  if(abs(Qtot)!=0) return;

  int IdxSt=0, Nb=BJetColl.size(), Nj=JetColl.size();
  bool PassMVeto=true;  bool OptimizeMode=false;
  vector<int> IdxMpColl, IdxMmColl, IdxEpColl, IdxEmColl;
  for(unsigned int i=0; i<MuTColl.size(); i++){
    if(MuTColl.at(i).Charge()>0){ IdxMpColl.push_back(i); } else{ IdxMmColl.push_back(i); }
  }
  for(unsigned int i=0; i<ElTColl.size(); i++){
    if(ElTColl.at(i).Charge()>0){ IdxEpColl.push_back(i); } else{ IdxEmColl.push_back(i); }
  }
  for(unsigned int imp=0; imp<IdxMpColl.size() && PassMVeto; imp++){
  for(unsigned int imm=0; imm<IdxMmColl.size() && PassMVeto; imm++){
    float MOSSS = (MuTColl.at(IdxMpColl.at(imp))+MuTColl.at(IdxMmColl.at(imm))).M();
    if(MOSSS<11 or fabs(MOSSS-91.2)<10){ PassMVeto=false; }
  }}
  for(unsigned int iep=0; iep<IdxEpColl.size() && PassMVeto; iep++){
  for(unsigned int iem=0; iem<IdxEmColl.size() && PassMVeto; iem++){
    float MOSSS = (ElTColl.at(IdxEpColl.at(iep))+ElTColl.at(IdxEmColl.at(iem))).M();
    if(MOSSS<11 or fabs(MOSSS-91.2)<10){ PassMVeto=false; }
  }}
  if(!PassMVeto) return;

  if     (NMuT==4 && NElT==0){ IdxSt=1; }
  else if(NMuT==3 && NElT==1){ IdxSt=2; }
  else if(NMuT==2 && NElT==2){ IdxSt=SumQ_M==0? 3:4; }
  else if(NMuT==1 && NElT==3){ IdxSt=5; }
  else if(NMuT==0 && NElT==4){ IdxSt=6; }
  if(OptimizeMode){ FillHist("Nb_Pre"+Label, Nb, weight,  5, 0., 5.);
                    FillHist("Nj_Pre"+Label, Nj, weight, 10, 0., 10.); }
  if(!(Nb>0)) return;
  if(!IsDATA){
    int GenLepInfo = GetGenLepInfo(ElTColl, MuTColl);
    if(ConvRun && GenLepInfo>=100) return;
  }

  FillHist("IdxSt"+Label, IdxSt, weight, 6, 1., 7.);

  vector<TString> MixList={"Mu", "El"};
  for(unsigned int ix=0; ix<MixList.size(); ix++){
  for(unsigned int im=0; im<MNStrList.size(); im++){
    TString MN=MNStrList.at(im), Mix=MixList.at(ix);
    if(MCSample.Contains("MN")){
      if(!MCSample.Contains("MN"+MN)) continue;
      if(!MCSample.Contains(Mix)) continue;
    }
    if(Mix=="Mu" && IdxSt>4) continue;
    if(Mix=="El" && IdxSt<3) continue;

    int IdxFill= Mix=="Mu"? 43:23;
    if(Mix=="Mu") IdxFill+=IdxSt;
    else if(Mix=="El") IdxFill+=(IdxSt-2);
       
    int Nbin=Mix=="Mu"? 47:27;
    FillHist("SigBins_"+Mix+"_MN"+MN+Label, IdxFill+1E-2, weight, Nbin, 1., 1.+(float) Nbin);
  }}

}


void KinVarPlot::PlotParameters(TString Label){

  FillHist("NEvt"+Label, 0., w_tot, 1, 0., 1.);
  FillHist("Nj"+Label, Nj, w_tot, 10, 0., 10.);
  FillHist("Nb"+Label, Nb, w_tot, 5, 0., 5.);
  FillHist("Ptl1"+Label, Ptl1, w_tot, 25, 0., 250.);
  FillHist("Ptl2"+Label, Ptl2, w_tot, 20, 0., 100.);
  FillHist("Ptj1"+Label, Ptj1, w_tot, 25, 0., 500.);
  FillHist("Ptj2"+Label, Ptj2, w_tot, 30, 0., 300.);
  FillHist("Ptj3"+Label, Ptj3, w_tot, 20, 0., 200.);
  FillHist("HT"+Label, HT, w_tot, 25, 0., 1000.);
  FillHist("MET2HT"+Label, MET2HT, w_tot, 20, 0., 100.);
  FillHist("dRll"+Label, dRll, w_tot, 25, 0., 5.);
  FillHist("dRlj11"+Label, dRlj11, w_tot, 25, 0., 5.);
  FillHist("dRlj12"+Label, dRlj12, w_tot, 25, 0., 5.);
  FillHist("dRlj13"+Label, dRlj13, w_tot, 25, 0., 5.);
  FillHist("dRlj21"+Label, dRlj21, w_tot, 25, 0., 5.);
  FillHist("dRlj22"+Label, dRlj22, w_tot, 25, 0., 5.);
  FillHist("dRlj23"+Label, dRlj23, w_tot, 25, 0., 5.);
  FillHist("MSSSF"+Label, MSSSF, w_tot, 25, 0., 250.);
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
    //bool Is2E = Label.Contains("_2E"), Is2M = Label.Contains("_2M");
    TString MVATagStr_Mu = "BDTG_MN"+MNStrList.at(im)+"_Mu";
    TString MVATagStr_El = "BDTG_MN"+MNStrList.at(im)+"_El";
    float MVAvalue_Mu = MVAReader->EvaluateMVA(MVATagStr_Mu);
    float MVAvalue_El = MVAReader->EvaluateMVA(MVATagStr_El);
    FillHist("BDTG_Mu_MN"+MNStrList.at(im)+Label, MVAvalue_Mu, w_tot, 40, -1., 1.);
    FillHist("BDTG_El_MN"+MNStrList.at(im)+Label, MVAvalue_El, w_tot, 40, -1., 1.);
  }

}


void KinVarPlot::executeEventFromParameter(AnalyzerParameter param){
}


void KinVarPlot::InitializeTreeVars(){

  Nj=-1, Nb=-1, NjPre=-1, NbPre=-1;
  Ptl1=-1, Ptl2=-1, Ptj1=-1, Ptj2=-1, Ptj3=-1, HT=-1, MET2HT=-1;
  dRll=-1, dRlj11=-1, dRlj12=-1, dRlj13=-1, dRlj21=-1, dRlj22=-1, dRlj23=-1;
  MSSSF=-1, MTvl1=-1, MTvl2=-1, MSSSFPre=-1;
  MllW_2jL=-1, MllW_1jL=-1, MllW1_H=-1;
  Ml1W_2jL=-1, Ml1W_1jL=-1, Ml2W_2jL=-1, Ml2W_1jL=-1, Ml1W1_H=-1, Ml2W1_H=-1;
  w_tot=-1;

}

float KinVarPlot::CalcTestFakeWeight(vector<Muon>& MuColl, vector<Electron>& ElColl, TString MuIDT, TString MuIDL, TString ElIDT, TString ElIDL, int NBJet, int SystDir){

  float w_FR=-1.; int NLepLNotT=0;
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


float KinVarPlot::GetTestElFR(Electron& El, TString Key, int SystDir){

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
  else if(Key=="TopHN17T_TopHN17L_Incl"){
    float TightIso=0.1;
    PTCorr = El.CalcPtCone(El.MiniRelIso(), TightIso);
    if(fEta<0.8){
      if     (PTCorr<10) FR=0.;
      else if(PTCorr<15) FR=0.4807840*(1.+(SystDir==0? 0.:SystDir>0? 0.194663:-0.0056314));
      else if(PTCorr<20) FR=0.3118340*(1.+(SystDir==0? 0.:SystDir>0? 0.761238:-0.0251098));
      else if(PTCorr<25) FR=0.2213380*(1.+(SystDir==0? 0.:SystDir>0? 0.284172:-0.0381324));
      else if(PTCorr<35) FR=0.1512650*(1.+(SystDir==0? 0.:SystDir>0? 0.225515:-0.0782336));
      else               FR=0.1501550*(1.+(SystDir==0? 0.:SystDir>0? 0.070695:-0.20367	));
    }
    else if(fEta<1.479){
      if     (PTCorr<10) FR=0.;
      else if(PTCorr<15) FR=0.524825*(1.+(SystDir==0? 0.:SystDir>0? 0.201887:-0.0288285));
      else if(PTCorr<20) FR=0.333069*(1.+(SystDir==0? 0.:SystDir>0? 0.456229:-0.0238859));
      else if(PTCorr<25) FR=0.23612 *(1.+(SystDir==0? 0.:SystDir>0? 0.467767:-0.015617 ));
      else if(PTCorr<35) FR=0.181259*(1.+(SystDir==0? 0.:SystDir>0? 0.657878:-0.0141794));
      else               FR=0.166092*(1.+(SystDir==0? 0.:SystDir>0? 0.23336 :-0.0728628));
    }
    else{
      if     (PTCorr<10) FR=0.;
      else if(PTCorr<15) FR=0.589752*(1.+(SystDir==0? 0.:SystDir>0? 0.281454:-0.0126225));
      else if(PTCorr<20) FR=0.379835*(1.+(SystDir==0? 0.:SystDir>0? 0.196977:-0.0152252));
      else if(PTCorr<25) FR=0.286548*(1.+(SystDir==0? 0.:SystDir>0? 0.473662:-0.0105759));
      else if(PTCorr<35) FR=0.218437*(1.+(SystDir==0? 0.:SystDir>0? 0.237345:-0.0208057));
      else               FR=0.167665*(1.+(SystDir==0? 0.:SystDir>0? 0.450305:-0.108753));
    }
  }
  else if(Key=="TopHN17T_TopHN17L_HasB"){
    float TightIso=0.1;
    PTCorr = El.CalcPtCone(El.MiniRelIso(), TightIso);
    if(fEta<0.8){
      if     (PTCorr<10) FR = 0.;
      else if(PTCorr<15) FR = 0.4807840*(1.194663+(SystDir==0? 0.:SystDir>0? 0.0056314:-0.194663));
      else if(PTCorr<20) FR = 0.3118340*(1.761238+(SystDir==0? 0.:SystDir>0? 0.0251098:-0.761238));
      else if(PTCorr<25) FR = 0.2213380*(1.284172+(SystDir==0? 0.:SystDir>0? 0.0381324:-0.284172));
      else if(PTCorr<35) FR = 0.1512650*(1.225515+(SystDir==0? 0.:SystDir>0? 0.0782336:-0.225515));
      else               FR = 0.1501550*(1.070695+(SystDir==0? 0.:SystDir>0? 0.20367  :-0.070695));
    }
    else if(fEta<1.479){
      if     (PTCorr<10) FR = 0.;
      else if(PTCorr<15) FR = 0.524825*(1.201887+(SystDir==0? 0.:SystDir>0? 0.0288285:-0.201887));
      else if(PTCorr<20) FR = 0.333069*(1.456229+(SystDir==0? 0.:SystDir>0? 0.0238859:-0.456229));
      else if(PTCorr<25) FR = 0.23612 *(1.467767+(SystDir==0? 0.:SystDir>0? 0.015617 :-0.467767));
      else if(PTCorr<35) FR = 0.181259*(1.657878+(SystDir==0? 0.:SystDir>0? 0.0141794:-0.657878));
      else               FR = 0.166092*(1.23336 +(SystDir==0? 0.:SystDir>0? 0.0728628:-0.23336 ));
    }
    else{
      if     (PTCorr<10) FR = 0.;
      else if(PTCorr<15) FR = 0.589752*(1.281454+(SystDir==0? 0.:SystDir>0? 0.0126225:-0.281454));
      else if(PTCorr<20) FR = 0.379835*(1.196977+(SystDir==0? 0.:SystDir>0? 0.0152252:-0.196977));
      else if(PTCorr<25) FR = 0.286548*(1.473662+(SystDir==0? 0.:SystDir>0? 0.0105759:-0.473662));
      else if(PTCorr<35) FR = 0.218437*(1.237345+(SystDir==0? 0.:SystDir>0? 0.0208057:-0.237345));
      else               FR = 0.167665*(1.450305+(SystDir==0? 0.:SystDir>0? 0.108753 :-0.450305));
    }
  }

  return FR;
}


float KinVarPlot::GetTestMuFR(Muon& Mu, TString Key, int SystDir){

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




float KinVarPlot::GetCFRSF(Electron& El, TString Tag, TString Option){

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



float KinVarPlot::GetFlipCorrPT(Electron& El, TString Tag, TString Option){

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



int KinVarPlot::GetGenLepInfo(vector<Electron>& ElColl, vector<Muon>& MuColl, TString Option){

  vector<Gen> TruthColl = GetGens();
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



KinVarPlot::KinVarPlot(){

  TMVA::Tools::Instance();
  MVAReader = new TMVA::Reader();

}


KinVarPlot::~KinVarPlot(){

  delete MVAReader;

}
