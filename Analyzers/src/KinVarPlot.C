#include "KinVarPlot.h"

void KinVarPlot::initializeAnalyzer(){

  TriLep=false, TetraLep=false, SS2l=false, OS2l=false; 
  FakeRun=false, ConvRun=false, FlipRun=false, SystRun=false, GenSyst=false, PUVETO = false, ReverseBDT = false; 
  DiscPlots=false, VarPlots=false, EffFlow=false, GlobFeas=false, GenMatchedDist=false, DecCompCheck=false;
  DiscCutOpt=false, DiscTable=false, DiscCNC=false, TestPlot=false;
  for(unsigned int i=0; i<Userflags.size(); i++){
    if(Userflags.at(i).Contains("OS2l"))       OS2l       = true;
    if(Userflags.at(i).Contains("SS2l"))       SS2l       = true;
    if(Userflags.at(i).Contains("TriLep"))     TriLep     = true;
    if(Userflags.at(i).Contains("TetraLep"))   TetraLep   = true; 
    if(Userflags.at(i).Contains("DiscPlots"))  DiscPlots  = true; 
    if(Userflags.at(i).Contains("VarPlots"))   VarPlots   = true; 
    if(Userflags.at(i).Contains("GenMatchedDist")) GenMatchedDist = true; 
    if(Userflags.at(i).Contains("DecCompCheck"))   DecCompCheck   = true; 
    if(Userflags.at(i).Contains("DiscCutOpt"))     DiscCutOpt     = true; 
    if(Userflags.at(i).Contains("DiscTable"))  DiscTable  = true; 
    if(Userflags.at(i).Contains("DiscCNC"))    DiscCNC    = true; 
    if(Userflags.at(i).Contains("TestPlot"))   TestPlot   = true; 
    if(Userflags.at(i).Contains("EffFlow"))    EffFlow    = true; 
    if(Userflags.at(i).Contains("FakeRun"))    FakeRun    = true; 
    if(Userflags.at(i).Contains("ConvRun"))    ConvRun    = true; 
    if(Userflags.at(i).Contains("FlipRun"))    FlipRun    = true; 
    if(Userflags.at(i).Contains("SystRun"))    SystRun    = true; 
    if(Userflags.at(i).Contains("GenSyst"))    GenSyst    = true; 
    if(Userflags.at(i).Contains("PUVETO"))     PUVETO    = true; 
    if(Userflags.at(i).Contains("ReverseBDT"))     ReverseBDT    = true; 
  }
  if(FlipRun && !FakeRun) OS2l=true;
//  if(FlipRun && !FakeRun) SS2l=true;

  DblMu=false, DblEG=false, MuEG=false;
  if     (DataStream.Contains("DoubleMuon")) DblMu=true;
  else if(DataStream.Contains("MuonEG"))     MuEG =true;
  else if(DataStream.Contains("DoubleEG"))   DblEG=true;
  else if(DataYear==2018 and DataStream.Contains("EGamma")) DblEG=true;


  if(GetEraShort()=="2016a"){
    TrigList_DblMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v", "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v"};
    TrigList_DblEG = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"};
    TrigList_MuEG  = {"HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v", "HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v"};
  }
  else if(GetEraShort()=="2016b"){
    TrigList_DblMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v", "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v", "HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v"};
    TrigList_DblEG = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"};
    TrigList_MuEG  = {"HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v", "HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"};
  }
  else if(DataYear==2017){
    TrigList_DblMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v", "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v"};
    TrigList_DblEG = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v"};
    TrigList_MuEG  = {"HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v", "HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v"};
  }
  else if(DataYear==2018){
    TrigList_DblMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v"};
    TrigList_DblEG = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v"};
    TrigList_MuEG  = {"HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v", "HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v"};
  }



  //Set up the tagger map only for the param settings to be used.
  //vector<JetTagging::Parameters> jtps;
  jtps.push_back( JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets) );
  mcCorr->SetJetTaggingParameters(jtps);

  TString AnalyzerPath=getenv("SKFlat_WD"), SKFlatV=getenv("SKFlatV"), SKOutPath=getenv("SKFlatOutputDir");
  TString FileDir_FkEl = AnalyzerPath+"/data/"+SKFlatV+"/"+GetEra()+"/FakeRate/DataFR/ElFR/";
  TString FileDir_FkMu = AnalyzerPath+"/data/"+SKFlatV+"/"+GetEra()+"/FakeRate/DataFR/MuFR/";
  TString FileDir_CF   = AnalyzerPath+"/data/"+SKFlatV+"/"+GetEra()+"/CFRate/";
  TString FileDir_Norm = SKOutPath+"/"+"_Original_jbh/"+SKFlatV+"/GetEffLumi/"+GetEra()+"/";
  FRFile_El  = new TFile(FileDir_FkEl+"FR_"+GetEraShort()+".root");
  FRFile_Mu  = new TFile(FileDir_FkMu+"FR_"+GetEraShort()+".root");
  CFRFile    = new TFile(FileDir_CF+"CFRateVar.root");
  if(MCSample.Contains("HeavyN") && SystRun){
    if(!gSystem->AccessPathName(FileDir_Norm+"GetEffLumi_"+MCSample+".root")){
      GenNormFile= new TFile(FileDir_Norm+"GetEffLumi_"+MCSample+".root");
      SetUpGenNormHists();
    }
    else{ cout<<"no gen norm file"<<endl; SystRun=false; }
  }

  InitializeTreeVars();
  if(DiscPlots or VarPlots){ InitializeReader(MVAReaderL, "BelowMW"); InitializeReader(MVAReaderH, "AboveMW"); }
  outfile->cd();

}


void KinVarPlot::executeEvent(){
  Event ev = GetEvent();
  float weight = 1., w_GenNorm=1., w_BR=1., w_PU=1.;
  if(!IsDATA){
    w_GenNorm = MCweight()*GetKFactor()*ev.GetTriggerLumi("Full");
    w_BR      = GetBRWeight();
    w_PU      = GetPileUpWeight(nPileUp, 0);
    weight *= w_GenNorm * w_BR * w_PU;
  }
  //FillHist("SumGenW_PU", 0., w_GenNorm, 3, 0., 3.);
  //FillHist("SumGenW_PU", 1., w_GenNorm*w_BR, 3, 0., 3.);
  //FillHist("SumGenW_PU", 2., w_GenNorm*w_BR*w_PU, 3, 0., 3.);
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
  else if(SS2l or OS2l){
    if(!IsDATA) PassTrig = ev.PassTrigger(TrigList_DblMu) or ev.PassTrigger(TrigList_DblEG);
    else{
      if     (DblMu) PassTrig = ev.PassTrigger(TrigList_DblMu);
      else if(DblEG) PassTrig = ev.PassTrigger(TrigList_DblEG);
      else if(MuEG)  PassTrig = ev.PassTrigger(TrigList_MuEG);
    }
  }
  PassMETFilterList=PassMETFilter();
  if(EffFlow or DecCompCheck){
    if(MCSample.Contains("HeavyN")){ PassTrig=true; PassMETFilterList=true; }
  }
  if(!PassTrig) return;
  FillHist("CutFlow", 1., weight, 20, 0., 20.);
  if(!PassMETFilterList) return;
  FillHist("CutFlow", 2., weight, 20, 0., 20.);

  bool PreCutPass=false;
  vector<Muon>     muonPreColl     = GetMuons("TopHNL", 5., 2.4);
  vector<Electron> electronPreColl = GetElectrons("TopHN_Isop4NoSIPMVA", 5., 2.5);
  //vector<Muon>     muonPreColl     = GetMuons("NOCUT", 5., 2.4);
  //vector<Electron> electronPreColl = GetElectrons("NOCUT", 5., 2.5);
  sort(muonPreColl.begin(), muonPreColl.end(), PtComparing);
  sort(electronPreColl.begin(), electronPreColl.end(), PtComparing);
  if(TriLep   and (muonPreColl.size()+electronPreColl.size())>2 ) PreCutPass=true;
  if(TetraLep and (muonPreColl.size()+electronPreColl.size())>3 ) PreCutPass=true;
  if(SS2l){
    int NPreMu=muonPreColl.size(), NPreEl=electronPreColl.size();
    if( (NPreMu+NPreEl)>2 ) PreCutPass=true;
    else if(NPreMu==2 and SumCharge(muonPreColl)!=0) PreCutPass=true;
    else if(NPreEl==2 and SumCharge(electronPreColl)!=0) PreCutPass=true;
  }
  if(OS2l and (electronPreColl.size()+muonPreColl.size())>1 ) PreCutPass=true;
  if((DecCompCheck or EffFlow) && MCSample.Contains("HeavyN")) PreCutPass=true;
  if(!PreCutPass) return;

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
  vector<Jet> jetColl;
/////////// Pileup Jet Veto
  if(PUVETO){
    jetColl  = SelectJets(jetPreColl, "LoosePileupJetVeto", 25., 2.4);
    jetColl  = SelectJets(jetColl, muonLooseColl, electronVetoColl, "tightLepVeto", 25., 2.4, "LVeto");
  } 
  else { 
    jetColl = SelectJets(jetPreColl, muonLooseColl, electronVetoColl, "tightLepVeto", 25., 2.4, "LVeto");
  }
/////////// Pileup Jet Veto
  vector<Jet> rawjetColl  = SelectJets(jetPreColl, "LoosePileupJetVeto", 25., 2.4);
  rawjetColl  = SelectJets(rawjetColl, "tight", 25., 2.4);
  vector<Jet> bjetColl = SelBJets(jetColl, param_jets);
  vector<Jet> rawbjetColl = SelBJets(rawjetColl, param_jets);

  Particle vMET_T1xy = GetvMET("PUPPIMETT1xyCorr");

  bool FillGenColl=!IsDATA && (ConvRun or FakeRun or FlipRun or GenMatchedDist or DecCompCheck);
  if(FillGenColl) truthColl=GetGens(); 


  bool EventCand = false;
  if(OS2l or SS2l){ EventCand = muonTightColl.size()==2 or electronTightColl.size()==2; }
  if(TriLep){ EventCand = (muonTightColl.size()+electronTightColl.size())==3; }
  if(TetraLep){ EventCand = (muonTightColl.size()+electronTightColl.size())==4; }
  if(EffFlow && MCSample.Contains("HeavyN")) EventCand=false;

  float w_TopPtRW = 1., w_Pref = 1., sf_Tr = 1., w_FR=1., w_PUVeto=1.;
  float sf_MuTk = 1., sf_mID = 1., sf_MuIso = 1., sf_eReco = 1., sf_eID = 1., sf_B = 1.;
  float w_CF = 1., w_CV = 1.;
  if((!IsDATA) and EventCand){
    sf_mID   = GetMuonSF(muonTightColl, MuTID, "ID");
    sf_eReco = GetElectronSF(electronLooseColl, "", "Reco");
    sf_eID   = GetElectronSF(electronTightColl, ElTID, "ID");
    sf_B     = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets);
    if(EffFlow) sf_B=1.;
    int NEl = electronTightColl.size(), NMu = muonTightColl.size();
    TString TrSFKey = "";
    if     ( (OS2l or SS2l) && NMu>1 ) TrSFKey="DiMuIso_HNTopID";
    else if( (OS2l or SS2l) && NEl>1 ) TrSFKey="DiElIso_HNTopIDSS";
    else if( TriLep && (NMu+NEl)>2   ) TrSFKey="TrigSoup2L_HNTopIDSS";
    bool ApplyTrSF = TrSFKey!="" && (SS2l or OS2l or TriLep);
    sf_Tr  = ApplyTrSF? mcCorr->GetTriggerSF(electronTightColl, muonTightColl, TrSFKey, ""):1.;
    w_Pref = GetPrefireWeight(0);
    if(FlipRun && !FakeRun) w_CF = GetCFRWeight(electronTightColl, "");
    //if(     ConvRun       ) w_CV = GetConvSF(ElTID, 0); 
  }
  if(FakeRun && EventCand){
    w_FR = GetDataFakeWeight(muonLooseColl, electronLooseColl, rawbjetColl, MuTID, ElTID, "FR_cent_"+MuTID+"_"+MuLID, "FR_cent_"+ElTID+"_"+ElLID+"_Pt15", "");
  }
  if(PUVETO) w_PUVeto = mcCorr->PileupJetVeto_Reweight(jetColl, "LoosePileupJetVeto", 0);
  weight *= w_TopPtRW * w_Pref * sf_Tr * w_PUVeto; 
  weight *= sf_MuTk * sf_mID * sf_MuIso * sf_eReco * sf_eID * sf_B * w_CV * w_CF * w_FR;
 
  if(SS2l or OS2l){
    if(VarPlots or DiscPlots){
      MakePlotSS2L(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
                   jetColl, bjetColl, vMET_T1xy, weight, "");
    }
    if(GenMatchedDist){
      CheckGenMatchedDist(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
                          jetColl, bjetColl, vMET_T1xy, weight, "");
    }
    if(TestPlot){
      TestPlotSS2L(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
                   jetColl, bjetColl, vMET_T1xy, weight, "");
    }
    if(EffFlow){
      bool IsSigMC = !IsDATA && MCSample.Contains("HeavyN");
      float ThisW = IsSigMC? w_GenNorm*w_BR*w_PU:weight;
      CheckEffFlow(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
                   jetColl, bjetColl, vMET_T1xy, ev, ThisW, "");
    }
    if(DecCompCheck){
      CheckDecayComposition(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
                            jetColl, bjetColl, vMET_T1xy, ev, weight, "");
    }
  }
  if(TriLep){
    MakePlot3L(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
               jetColl, bjetColl, vMET_T1xy, weight, "");
  }
  if(TetraLep){
    MakePlot4L(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
               jetColl, bjetColl, vMET_T1xy, weight, "");
  }
  if( SystRun && ((!IsDATA && !(FakeRun)) or (IsDATA && FakeRun)) ){
    vector<Muon>     MuEnUpTColl, MuEnUpLColl, MuEnDownTColl, MuEnDownLColl;
    vector<Electron> ElSclUpTColl, ElSclUpLColl, ElSclDownTColl, ElSclDownLColl;
    vector<Electron> ElResUpTColl, ElResUpLColl, ElResDownTColl, ElResDownLColl;
//    vector<Electron> ElCFPT1UpTColl, ElCFPT1UpLColl, ElCFPT2UpTColl, ElCFPT2UpLColl;
//    vector<Electron> ElCFPT1DownTColl, ElCFPT1DownLColl, ElCFPT2DownTColl, ElCFPT2DownLColl;
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
//      if(FlipRun){
//        ElCFPT1UpTColl   = SelectElectrons(electronPreColl, FakeRun? ElLID:ElTID, 15., 2.5, "SystCFPT1Up");
//        ElCFPT1UpLColl   = SelectElectrons(electronPreColl, ElLID, 15., 2.5, "SystCFPT1Up");
//        ElCFPT2UpTColl   = SelectElectrons(electronPreColl, FakeRun? ElLID:ElTID, 15., 2.5, "SystCFPT2Up");
//        ElCFPT2UpLColl   = SelectElectrons(electronPreColl, ElLID, 15., 2.5, "SystCFPT2Up");
//        ElCFPT1DownTColl = SelectElectrons(electronPreColl, FakeRun? ElLID:ElTID, 15., 2.5, "SystCFPT1Down");
//        ElCFPT1DownLColl = SelectElectrons(electronPreColl, ElLID, 15., 2.5, "SystCFPT1Down");
//        ElCFPT2DownTColl = SelectElectrons(electronPreColl, FakeRun? ElLID:ElTID, 15., 2.5, "SystCFPT2Down");
//        ElCFPT2DownLColl = SelectElectrons(electronPreColl, ElLID, 15., 2.5, "SystCFPT2Down");
//      }
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

    float w_PUUp=1., w_PUDown=1., w_PrefUp=1., w_PrefDown=1., w_PUVetoUp=1., w_PUVetoDown=1.;
    float w_FRUp=1., w_FRDown=1.;
    float w_CFUp=1., w_CFDown=1., w_FrCF1=0., w_FrCF2=0., w_CF_ElSclUp=1., w_CF_ElSclDown=1., w_CF_ElResUp=1., w_CF_ElResDown=1.;
    float sf_mIDUp=1., sf_mIDDown=1., sf_mID_MuEnUp=1., sf_mID_MuEnDown=1.;
    float sf_eIDUp=1., sf_eIDDown=1., sf_eID_ElSclUp=1., sf_eID_ElSclDown=1., sf_eID_ElResUp=1., sf_eID_ElResDown=1.;
    float sf_eRecoUp=1., sf_eRecoDown=1., sf_eReco_ElSclUp=1., sf_eReco_ElSclDown=1., sf_eReco_ElResUp=1., sf_eReco_ElResDown=1.;
    float sf_B_JESUp=1., sf_B_JESDown=1., sf_B_JERUp=1., sf_B_JERDown=1.;
    float sf_B_LTagCorrUp=1., sf_B_LTagCorrDown=1., sf_B_HTagCorrUp=1., sf_B_HTagCorrDown=1.;
    float sf_B_LTagUnCorrUp=1., sf_B_LTagUnCorrDown=1., sf_B_HTagUnCorrUp=1., sf_B_HTagUnCorrDown=1.;
    float sf_Tr_ElSclUp=1., sf_Tr_ElSclDown=1., sf_Tr_ElResUp=1., sf_Tr_ElResDown=1., sf_Tr_MuEnUp=1., sf_Tr_MuEnDown=1.;
    float sf_TrUp = sf_Tr*1.01, sf_TrDown = sf_Tr*0.99;
    if(!IsDATA && EventCand){
      w_PrefUp   = GetPrefireWeight(1), w_PrefDown = GetPrefireWeight(-1);
      w_PUUp     = GetPileUpWeight(nPileUp, 1);
      w_PUDown   = GetPileUpWeight(nPileUp,-1);
      if(PUVETO){
        w_PUVetoUp =  mcCorr->PileupJetVeto_Reweight(jetColl, "LoosePileupJetVeto", +1);
        w_PUVetoDown =  mcCorr->PileupJetVeto_Reweight(jetColl, "LoosePileupJetVeto", -1);
      }

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
      sf_mID_MuEnUp   = GetMuonSF(MuEnUpTColl, MuTID, "ID");
      sf_mID_MuEnDown = GetMuonSF(MuEnDownTColl, MuTID, "ID");

      sf_B_JESUp    = mcCorr->GetBTaggingReweight_1a(jetJESUpColl, param_jets);
      sf_B_JESDown  = mcCorr->GetBTaggingReweight_1a(jetJESDownColl, param_jets);
      sf_B_JERUp    = mcCorr->GetBTaggingReweight_1a(jetJERUpColl, param_jets);
      sf_B_JERDown  = mcCorr->GetBTaggingReweight_1a(jetJERDownColl, param_jets);
      sf_B_LTagCorrUp   = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets, "SystUpLTagCorr");
      sf_B_LTagCorrDown = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets, "SystDownLTagCorr");
      sf_B_HTagCorrUp   = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets, "SystUpHTagCorr");
      sf_B_HTagCorrDown = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets, "SystDownHTagCorr");
      sf_B_LTagUnCorrUp   = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets, "SystUpLTagUnCorr");
      sf_B_LTagUnCorrDown = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets, "SystDownLTagUnCorr");
      sf_B_HTagUnCorrUp   = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets, "SystUpHTagUnCorr");
      sf_B_HTagUnCorrDown = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets, "SystDownHTagUnCorr");

      sf_Tr_MuEnUp   = MuEnUpTColl.size()>1?   mcCorr->GetTriggerSF(electronTightColl, MuEnUpTColl, "DiMuIso_HNTopID", ""):1.;
      sf_Tr_MuEnDown = MuEnDownTColl.size()>1? mcCorr->GetTriggerSF(electronTightColl, MuEnDownTColl, "DiMuIso_HNTopID", ""):1.;
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
      w_FRUp   = GetDataFakeWeight(muonLooseColl, electronLooseColl, rawbjetColl, MuTID, ElTID, "FR_cent_"+MuTID+"_"+MuLID, "FR_cent_"+ElTID+"_"+ElLID+"_Pt15", "SystUpTot"  );
      w_FRDown = GetDataFakeWeight(muonLooseColl, electronLooseColl, rawbjetColl, MuTID, ElTID, "FR_cent_"+MuTID+"_"+MuLID, "FR_cent_"+ElTID+"_"+ElLID+"_Pt15", "SystDownTot");
    }


    float w_base = w_GenNorm * w_BR * w_TopPtRW * sf_MuTk * w_CV;
    float weight_PUUp      = w_base* w_PUUp * w_PUVeto  * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_PUDown    = w_base* w_PUDown * w_PUVeto * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_PUVetoUp      = w_base* w_PU * w_PUVetoUp * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_PUVetoDown      = w_base* w_PU * w_PUVetoDown  * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_PrefUp    = w_base* w_PU * w_PUVeto   * w_PrefUp  * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_PrefDown  = w_base* w_PU * w_PUVeto   * w_PrefDown* w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_MuEnUp    = w_base* w_PU * w_PUVeto   * w_Pref    * w_FR    * w_CF    * sf_mID_MuEnUp  * sf_eReco          * sf_eID          * sf_Tr_MuEnUp   * sf_B;
    float weight_MuEnDown  = w_base* w_PU * w_PUVeto   * w_Pref    * w_FR    * w_CF    * sf_mID_MuEnDown* sf_eReco          * sf_eID          * sf_Tr_MuEnDown * sf_B;
    float weight_MuIDUp    = w_base* w_PU * w_PUVeto   * w_Pref    * w_FR    * w_CF    * sf_mIDUp       * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_MuIDDown  = w_base* w_PU * w_PUVeto   * w_Pref    * w_FR    * w_CF    * sf_mIDDown     * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_ElRecoUp  = w_base* w_PU * w_PUVeto   * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eRecoUp        * sf_eID          * sf_Tr          * sf_B;
    float weight_ElRecoDown= w_base* w_PU * w_PUVeto   * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eRecoDown      * sf_eID          * sf_Tr          * sf_B;
    float weight_ElIDUp    = w_base* w_PU * w_PUVeto   * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eIDUp        * sf_Tr          * sf_B;
    float weight_ElIDDown  = w_base* w_PU * w_PUVeto   * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eIDDown      * sf_Tr          * sf_B;
    float weight_ElSclUp   = w_base* w_PU * w_PUVeto   * w_Pref    * w_FR    * w_CF_ElSclUp  * sf_mID   * sf_eReco_ElSclUp  * sf_eID_ElSclUp  * sf_Tr_ElSclUp  * sf_B;
    float weight_ElSclDown = w_base* w_PU * w_PUVeto   * w_Pref    * w_FR    * w_CF_ElSclDown* sf_mID   * sf_eReco_ElSclDown* sf_eID_ElSclDown* sf_Tr_ElSclDown* sf_B;
    float weight_ElResUp   = w_base* w_PU * w_PUVeto   * w_Pref    * w_FR    * w_CF_ElResUp  * sf_mID   * sf_eReco_ElResUp  * sf_eID_ElResUp  * sf_Tr_ElResUp  * sf_B;
    float weight_ElResDown = w_base* w_PU * w_PUVeto   * w_Pref    * w_FR    * w_CF_ElResDown* sf_mID   * sf_eReco_ElResDown* sf_eID_ElResDown* sf_Tr_ElResDown* sf_B;
    float weight_JESUp     = w_base* w_PU * w_PUVeto   * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_JESUp;
    float weight_JESDown   = w_base* w_PU * w_PUVeto   * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_JESDown;
    float weight_JERUp     = w_base* w_PU * w_PUVeto   * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_JERUp;
    float weight_JERDown   = w_base* w_PU * w_PUVeto   * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_JERDown;
    float weight_LTagCorrUp    = w_base* w_PU * w_PUVeto *  w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_LTagCorrUp;
    float weight_LTagCorrDown  = w_base* w_PU * w_PUVeto * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_LTagCorrDown;
    float weight_LTagUnCorrUp  = w_base* w_PU * w_PUVeto * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_LTagUnCorrUp;
    float weight_LTagUnCorrDown= w_base* w_PU * w_PUVeto * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_LTagUnCorrDown;
    float weight_HTagCorrUp    = w_base* w_PU * w_PUVeto * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_HTagCorrUp;
    float weight_HTagCorrDown  = w_base* w_PU * w_PUVeto * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_HTagCorrDown;
    float weight_HTagUnCorrUp  = w_base* w_PU * w_PUVeto  * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_HTagUnCorrUp;
    float weight_HTagUnCorrDown= w_base* w_PU * w_PUVeto * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B_HTagUnCorrDown;
    float weight_CFUp      = w_base* w_PU * w_PUVeto   * w_Pref    * w_FR    * w_CFUp  * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_CFDown    = w_base* w_PU * w_PUVeto   * w_Pref    * w_FR    * w_CFDown* sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_FRUp      = w_base* w_PU * w_PUVeto   * w_Pref    * w_FRUp  * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_FRDown    = w_base* w_PU * w_PUVeto   * w_Pref    * w_FRDown* w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_Tr          * sf_B;
    float weight_TrUp      = w_base* w_PU * w_PUVeto   * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_TrUp        * sf_B;
    float weight_TrDown    = w_base* w_PU * w_PUVeto   * w_Pref    * w_FR    * w_CF    * sf_mID         * sf_eReco          * sf_eID          * sf_TrDown      * sf_B;

    if(!IsDATA && !FakeRun){
      SysWgtStrPairList.clear();//safe-guard, in-case there was usage before this and uncleared
      SysWgtStrPairList.push_back( make_pair(weight_PUUp          , "_SystUp_PU"          ) );
      SysWgtStrPairList.push_back( make_pair(weight_PUDown        , "_SystDown_PU"        ) );
      SysWgtStrPairList.push_back( make_pair(weight_PUVetoUp      , "_SystUp_PUVeto"      ) );
      SysWgtStrPairList.push_back( make_pair(weight_PUVetoDown    , "_SystDown_PUVeto"    ) );
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
      SysWgtStrPairList.push_back( make_pair(weight_LTagCorrUp    , "_SystUp_LTagCorr"    ) );
      SysWgtStrPairList.push_back( make_pair(weight_LTagCorrDown  , "_SystDown_LTagCorr"  ) );
      SysWgtStrPairList.push_back( make_pair(weight_LTagUnCorrUp  , "_SystUp_LTagUnCorr"  ) );
      SysWgtStrPairList.push_back( make_pair(weight_LTagUnCorrDown, "_SystDown_LTagUnCorr") );
      SysWgtStrPairList.push_back( make_pair(weight_HTagCorrUp    , "_SystUp_HTagCorr"    ) );
      SysWgtStrPairList.push_back( make_pair(weight_HTagCorrDown  , "_SystDown_HTagCorr"  ) );
      SysWgtStrPairList.push_back( make_pair(weight_HTagUnCorrUp  , "_SystUp_HTagUnCorr"  ) );
      SysWgtStrPairList.push_back( make_pair(weight_HTagUnCorrDown, "_SystDown_HTagUnCorr") );
      if(FlipRun && !FakeRun){
        SysWgtStrPairList.push_back( make_pair(weight_CFUp  , "_SystUp_CF"  ) );
        SysWgtStrPairList.push_back( make_pair(weight_CFDown, "_SystDown_CF") );
      }
      if(MCSample.Contains("HeavyN") && DiscCNC) GenSyst=true;
      if(MCSample.Contains("HeavyN") && DiscCutOpt) GenSyst=true;
      bool CheckAccVar = MCSample.Contains("HeavyN");
      if(GenSyst){
        map<TString, TH1D*>::iterator mapit = maphist_GenNorm.find("sumW_Scale");
        float NormNom = CheckAccVar? mapit->second->GetBinContent(1) * w_GenNorm * w_BR:1.; 
        for(unsigned int iw=0; iw<weight_Scale->size(); iw++){
          map<TString, TH1D*>::iterator mapit = maphist_GenNorm.find("sumW_Scale");
          float Norm = CheckAccVar? mapit->second->GetBinContent(iw+1) * w_GenNorm * w_BR:1.;
          SysWgtStrPairList.push_back( make_pair(weight*weight_Scale->at(iw)*(NormNom/Norm), "_Syst_Scale"+TString::Itoa(iw,10)) );
        }
        for(unsigned int iw=0; iw<weight_PDF->size(); iw++){
          map<TString, TH1D*>::iterator mapit = maphist_GenNorm.find("sumW_PDF");
          float Norm = CheckAccVar? mapit->second->GetBinContent(iw+1) * w_GenNorm * w_BR:1.;
          SysWgtStrPairList.push_back( make_pair(weight*weight_PDF->at(iw)*(NormNom/Norm), "_Syst_PDF"+TString::Itoa(iw,10)) );
        }
        for(unsigned int iw=0; iw<weight_AlphaS->size(); iw++){
          map<TString, TH1D*>::iterator mapit = maphist_GenNorm.find("sumW_AlphaS");
          float Norm = CheckAccVar? mapit->second->GetBinContent(iw+1) * w_GenNorm * w_BR:1.;
          SysWgtStrPairList.push_back( make_pair(weight*weight_AlphaS->at(iw)*(NormNom/Norm), "_Syst_AlphaS"+TString::Itoa(iw,10)) );
        }
        for(unsigned int iw=0; iw<weight_alpsfact->size(); iw++){
          map<TString, TH1D*>::iterator mapit = maphist_GenNorm.find("sumW_alpsfact");
          float Norm = CheckAccVar? mapit->second->GetBinContent(iw+1) * w_GenNorm * w_BR:1.;
          SysWgtStrPairList.push_back( make_pair(weight*weight_alpsfact->at(iw)*(NormNom/Norm), "_Syst_alpsfact"+TString::Itoa(iw,10)) );
        }
        for(unsigned int iw=0; iw<weight_PSSyst->size(); iw++){
          if( !(iw==1 or iw==2) ) continue;
          map<TString, TH1D*>::iterator mapit = maphist_GenNorm.find("sumW_PSSyst");
          float Norm = CheckAccVar? mapit->second->GetBinContent(iw+1) * w_GenNorm * w_BR:1.;
          SysWgtStrPairList.push_back( make_pair(weight*weight_PSSyst->at(iw)*(NormNom/Norm), "_Syst_PSScaleFSR"+TString::Itoa(iw,10)) );
        }
        for(unsigned int iw=0; iw<weight_PSSyst->size(); iw++){
          if( !(iw==19 or iw==20) ) continue;
          map<TString, TH1D*>::iterator mapit = maphist_GenNorm.find("sumW_PSSyst");
          float Norm = CheckAccVar? mapit->second->GetBinContent(iw+1) * w_GenNorm * w_BR:1.;
          SysWgtStrPairList.push_back( make_pair(weight*weight_PSSyst->at(iw)*(NormNom/Norm), "_Syst_PSScaleISR"+TString::Itoa(iw,10)) );
        }
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
//      if(FlipRun && !FakeRun){
//        DoSystRun(muonTightColl, muonLooseColl, muonLooseColl, ElCFPT1UpTColl, ElCFPT1UpLColl, electronVetoColl,
//                  jetColl, bjetColl, vMET_T1xy, ev, weight*w_FrCF1, "_SystUp_CFPT");
//        DoSystRun(muonTightColl, muonLooseColl, muonLooseColl, ElCFPT1DownTColl, ElCFPT1DownLColl, electronVetoColl,
//                  jetColl, bjetColl, vMET_T1xy, ev, weight*w_FrCF1, "_SystDown_CFPT");
//        DoSystRun(muonTightColl, muonLooseColl, muonLooseColl, ElCFPT2UpTColl, ElCFPT2UpLColl, electronVetoColl,
//                  jetColl, bjetColl, vMET_T1xy, ev, weight*w_FrCF2, "_SystUp_CFPT");
//        DoSystRun(muonTightColl, muonLooseColl, muonLooseColl, ElCFPT2DownTColl, ElCFPT2DownLColl, electronVetoColl,
//                  jetColl, bjetColl, vMET_T1xy, ev, weight*w_FrCF2, "_SystDown_CFPT");
//      }
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
  }//End of Syst

}


void KinVarPlot::DoSystRun(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                           vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                           vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& Ev, float weight, TString Label)
{

  if(VarPlots or DiscPlots){
    MakePlotSS2L(MuTColl, MuLColl, MuVColl, ElTColl, ElLColl, ElVColl, JetColl, BJetColl, vMET, weight, Label);
  }
  else if(TriLep){
    MakePlot3L(MuTColl, MuLColl, MuVColl, ElTColl, ElLColl, ElVColl, JetColl, BJetColl, vMET, weight, Label); 
  }
  else if(TetraLep){
    MakePlot4L(MuTColl, MuLColl, MuVColl, ElTColl, ElLColl, ElVColl, JetColl, BJetColl, vMET, weight, Label);
  }
  else{ cout<<"no corresponding cycle!"<<endl; exit(ENODATA); }

  return;
}



void KinVarPlot::CheckEffFlow(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                              vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                              vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& ev, float weight, TString Label)
{

  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  float w_Pref = 1., sf_Tr = 1.;
  float sf_mID = 1., sf_eReco = 1., sf_eID = 1., sf_B = 1.;
  bool IsSigMC = !IsDATA && MCSample.Contains("HeavyN");
  int it_cut=0;
  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
  if(!IsDATA && !IsSigMC && (NMuL+NElL)>1 ){ sf_B = mcCorr->GetBTaggingReweight_1a(JetColl, param_jets); }
  if(IsSigMC){
    if((NMuL+NElL)>1){
      w_Pref = GetPrefireWeight(0);
      TString SFKey_Trig_All = MuTColl.size()==2? "DiMuIso_HNTopID":ElTColl.size()==2? "DiElIso_HNTopIDSS":"EMuIso_HNTopIDSS"; 
      sf_Tr   = mcCorr->GetTriggerSF(ElTColl, MuTColl, SFKey_Trig_All, "");
      sf_mID   = GetMuonSF(MuTColl, "TopHNT", "ID");
      sf_eReco = GetElectronSF(ElTColl, "", "Reco");
      sf_eID   = GetElectronSF(ElTColl, "TopHNSST", "ID");
      sf_B   = mcCorr->GetBTaggingReweight_1a(JetColl, param_jets);
    }

    //tot rate.
    FillHist("SelEffFlow_2M"+Label, it_cut, weight, 20, 0., 20.);
    FillHist("SelEffFlow_2E"+Label, it_cut, weight, 20, 0., 20.); it_cut++;

    //MET filter cut
    if(!PassMETFilter()) return;
    FillHist("SelEffFlow_2M"+Label, it_cut, weight, 20, 0., 20.);
    FillHist("SelEffFlow_2E"+Label, it_cut, weight, 20, 0., 20.); it_cut++;

    //Prefire
    weight*=w_Pref;
    FillHist("SelEffFlow_2M"+Label, it_cut, weight, 20, 0., 20.); 
    FillHist("SelEffFlow_2E"+Label, it_cut, weight, 20, 0., 20.); it_cut++;
  
    //HLT
    if( !(ev.PassTrigger(TrigList_DblMu) or ev.PassTrigger(TrigList_DblEG)) ) return;
    weight*=sf_Tr;
    if( ev.PassTrigger(TrigList_DblMu) ) FillHist("SelEffFlow_2M"+Label, it_cut, weight, 20, 0., 20.);
    if( ev.PassTrigger(TrigList_DblEG) ) FillHist("SelEffFlow_2E"+Label, it_cut, weight, 20, 0., 20.);
    it_cut++;
  }

  //2lss
  if(IsSigMC) weight *= sf_mID*sf_eID*sf_eReco;
  if     (NMuT==2) Label="_2M"+Label;
  else if(NElT==2) Label="_2E"+Label;
  if( !( (NMuT==2 and NElT==0 && MuTColl.at(0).Charge()==MuTColl.at(1).Charge())
      or (NElT==2 and NMuT==0 && ElTColl.at(0).Charge()==ElTColl.at(1).Charge()) ) ) return;
  if( IsSigMC && !( (NMuT==2 && ev.PassTrigger(TrigList_DblMu)) or (NElT==2 && ev.PassTrigger(TrigList_DblEG)) ) ) return;
  FillHist("SelEffFlow"+Label, it_cut, weight, 20, 0., 20.); it_cut++;

  //3rd lep. veto
  if( !(NMuT==NMuL and NElT==NElL) ) return;
  if( !(NMuT==NMuV and NElT==NElV) ) return;
  FillHist("SelEffFlow"+Label, it_cut, weight, 20, 0., 20.); it_cut++;

  //trig pt acc.
  if( NMuT==2 && !(MuTColl.at(0).Pt()>20 && MuTColl.at(1).Pt()>10) ) return;
  if( NElT==2 && !(ElTColl.at(0).Pt()>25 && ElTColl.at(1).Pt()>15) ) return;
  FillHist("SelEffFlow"+Label, it_cut, weight, 20, 0., 20.); it_cut++;

  //mll acc. for trig(2m), for CF veto (2e)
  if( NMuT==2 && !( (MuTColl.at(0)+MuTColl.at(1)).M()>4 ) ) return;
  if( NElT==2 && !( fabs((ElTColl.at(0)+ElTColl.at(1)).M()-91.2)>10 ) ) return;
  FillHist("SelEffFlow"+Label, it_cut, weight, 20, 0., 20.); it_cut++;

  //NB cut
  if(BJetColl.size()<1) return;
  weight *= sf_B;
  FillHist("SelEffFlow"+Label, it_cut, weight, 20, 0., 20.); it_cut++;

  //NJ cut
  if(JetColl.size() <3) return;
  FillHist("SelEffFlow"+Label, it_cut, weight, 20, 0., 20.); it_cut++;

  //NLJ cut
  int NLJet = JetColl.size()-BJetColl.size();
  if(NLJet==0) return;
  FillHist("SelEffFlow"+Label, it_cut, weight, 20, 0., 20.); it_cut++;

  if(NLJet<2) return;
  FillHist("SelEffFlow"+Label, it_cut, weight, 20, 0., 20.); it_cut++;

  FillHist("NEvent"+Label, 0., weight, 1, 0., 1.);

}

void KinVarPlot::CheckDecayComposition(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                                       vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                                       vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& ev, float weight, TString Label)
{

  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  bool IsSigMC = !IsDATA && MCSample.Contains("HeavyN");
  if(!IsSigMC) return;


  int NlW=0, Nlt=0, NlN=0;
  int NeW=0, NmW=0, NtaW=0, Net=0, Nmt=0, NeN=0, NmN=0, NtaN=0;
  int Nfromt=0;
  for(unsigned int it=2; it<truthColl.size(); it++){
    int PID = truthColl.at(it).PID(), aPID = abs(PID);
    if( !(aPID>9900000) ) continue;

    int MIdx = truthColl.at(it).MotherIndex(), MPID = truthColl.at(MIdx).PID(), aMPID = abs(MPID);
    if( MPID==PID or aMPID==aPID ) continue;
    
    if     ( MPID==24 or MPID== 6) Nfromt= 1;
    else if(MPID==-24 or MPID==-6) Nfromt=-1;
  }
  if(Nfromt==0){ cout<<"something wrong 1"<<endl; return; }
 
        
  for(unsigned int it=2; it<truthColl.size(); it++){
    int PID = truthColl.at(it).PID(), aPID = abs(PID);
    if( !(aPID==11 or aPID==13 or aPID==15) ) continue;

    int MIdx = truthColl.at(it).MotherIndex(), MPID = truthColl.at(MIdx).PID(), aMPID = abs(MPID);
    if( MPID==PID or aMPID==aPID ) continue;
    if( !(aMPID==23 or aMPID==24 or aMPID==25 or aMPID==6 or aMPID>9900000) ) continue;

    int GrMIdx = FirstNonSelfMotherIdx(MIdx, truthColl);
    int GrMPID = GrMIdx!=-1? truthColl.at(GrMIdx).PID():0, aGrMPID = abs(GrMPID);

    if(aMPID>9900000){
      if     (aPID==11){ NeN++; NlN++; }
      else if(aPID==13){ NmN++; NlN++; }
      else if(aPID==15){ NtaN++; NlN++; }
    }
    else if(aGrMPID>9900000 && (aMPID==23 or aMPID==24 or aMPID==25)){
      if     (aPID==11){ NeN++; NlN++; }
      else if(aPID==13){ NmN++; NlN++; }
      else if(aPID==15){ NtaN++; NlN++; }
    }
    else if(aMPID==6){
      if     (aPID==11){ Net++; Nlt++; }
      else if(aPID==13){ Nmt++; Nlt++; }
      else if(aPID==15) continue;
    }
    else if(MPID==24 && GrMPID==6){
      if(Nfromt==1){
        if     (aPID==11){ Net++; Nlt++; }
        else if(aPID==13){ Nmt++; Nlt++; }
        else if(aPID==15) continue;
      }
      else{
        if     (aPID==11){ NeW++; NlW++; }
        else if(aPID==13){ NmW++; NlW++; }
        else if(aPID==15){ NtaW++; NlW++; }
      }
    }
    else if(MPID==-24 && GrMPID==-6){
      if(Nfromt==-1){
        if     (aPID==11){ Net++; Nlt++; }
        else if(aPID==13){ Nmt++; Nlt++; }
        else if(aPID==15) continue;
      }
      else{
        if     (aPID==11){ NeW++; NlW++; }
        else if(aPID==13){ NmW++; NlW++; }
        else if(aPID==15){ NtaW++; NlW++; }
      }
    }
  }
  if( NeW>1){ while( NeW>1){  NeW-=2; NlW-=2; } }
  if( NmW>1){ while( NmW>1){  NmW-=2; NlW-=2; } }
  if(NtaW>1){ while(NtaW>1){ NtaW-=2; NlW-=2; } }
  if( Net>1){ while( Net>1){  Net-=2; Nlt-=2; } }
  if( Nmt>1){ while( Nmt>1){  Nmt-=2; Nlt-=2; } }
  if( NeN>2){ while( NeN>2){  NeN-=2; NlN-=2; } }
  if( NmN>2){ while( NmN>2){  NmN-=2; NlN-=2; } }
  if(NtaN>2){ while(NtaN>2){ NtaN-=2; NlN-=2; } }

  int NDecMode=0, WDecMode=0;
  if     (NeN==1 && NlN==1 ) NDecMode=0;
  else if(NmN==1 && NlN==1 ) NDecMode=1;
  else if(NeN==2           ) NDecMode=2;
  else if(NeN==1 && NmN==1 ) NDecMode=3;
  else if(NeN==1 && NtaN==1) NDecMode=4;
  else if(NmN==2           ) NDecMode=5;
  else if(NmN==1 && NtaN==1) NDecMode=6;
  else if(NtaN==2          ) NDecMode=7;

  if     (NeW==1 ) WDecMode=1;
  else if(NmW==1 ) WDecMode=2;
  else if(NtaW==1) WDecMode=3;

  float w_GenNorm = MCweight()*GetKFactor()*ev.GetTriggerLumi("Full");
  float w_BR      = GetBRWeight();
  float w_PU      = GetPileUpWeight(nPileUp, 0);
  float w_GenOnly = w_GenNorm * w_BR * w_PU;

  if(NlN>2 or Nlt!=1 or NlW>1 or NlN==0){ FillHist("NCntErr_All", 0., w_GenOnly, 1, 0., 1.); return; }
  FillHist("NlW_All", NlW, w_GenOnly, 10, 0., 10.);
  FillHist("Nlt_All", Nlt, w_GenOnly, 10, 0., 10.);
  FillHist("NlN_All", NlN, w_GenOnly, 10, 0., 10.);
  FillHist("WDecMode_All", WDecMode, w_GenOnly, 4, 0., 4.);
  FillHist("NDecMode_All", NDecMode, w_GenOnly, 8, 0., 8.);
  FillHist("NWDecMode_All", NDecMode, WDecMode, w_GenOnly, 8, 0., 8., 4, 0., 4.);

  //SELECTION
  //2lss
  if( !( (NMuT==2 and NElT==0 && MuTColl.at(0).Charge()==MuTColl.at(1).Charge())
      or (NElT==2 and NMuT==0 && ElTColl.at(0).Charge()==ElTColl.at(1).Charge()) ) ) return;

  //trigger+evt filter
  if( !( (NMuT==2 && ev.PassTrigger(TrigList_DblMu))
      or (NElT==2 && ev.PassTrigger(TrigList_DblEG)) ) ) return;
  if( !PassMETFilter() ) return;

  //3rd lep. veto
  if( !(NMuT==NMuL and NElT==NElL) ) return;
  if( !(NMuT==NMuV and NElT==NElV) ) return;

  //trig pt acc.
  if( NMuT==2 && !(MuTColl.at(0).Pt()>20 && MuTColl.at(1).Pt()>10) ) return;
  if( NElT==2 && !(ElTColl.at(0).Pt()>25 && ElTColl.at(1).Pt()>15) ) return;

  //mll acc. for trig(2m), for CF veto (2e)
  if( NMuT==2 && !( (MuTColl.at(0)+MuTColl.at(1)).M()>4 ) ) return;
  if( NElT==2 && !( fabs((ElTColl.at(0)+ElTColl.at(1)).M()-91.2)>10 ) ) return;

  //NB cut
  if(BJetColl.size()<1) return;

  //NJ cut
  if(JetColl.size() <3) return;

  //NLJ cut
  int NLJet = JetColl.size()-BJetColl.size();
  if(NLJet==0) return;

  if(NlN>2 or Nlt!=1 or NlW>1 or NlN==0){ FillHist("NCntErr_1LJ", 0., weight, 1, 0., 1.); return; }
  FillHist("NlW_1LJ", NlW, weight, 10, 0., 10.);
  FillHist("Nlt_1LJ", Nlt, weight, 10, 0., 10.);
  FillHist("NlN_1LJ", NlN, weight, 10, 0., 10.);
  FillHist("WDecMode_1LJ", WDecMode, weight, 4, 0., 4.);
  FillHist("NDecMode_1LJ", NDecMode, weight, 8, 0., 8.);
  FillHist("NWDecMode_1LJ", NDecMode, WDecMode, weight, 8, 0., 8., 4, 0., 4.);

  if( !(MCSample.Contains("MN85") or MCSample.Contains("MN95") or MCSample.Contains("MN100") or MCSample.Contains("MN120")) ){
    FillHist("WDecMode_PreSel", WDecMode, weight, 4, 0., 4.);
    FillHist("NDecMode_PreSel", NDecMode, weight, 8, 0., 8.);
    FillHist("NWDecMode_PreSel", NDecMode, WDecMode, weight, 8, 0., 8., 4, 0., 4.);
  }
  else if(NLJet>1){
    FillHist("WDecMode_PreSel", WDecMode, weight, 4, 0., 4.);
    FillHist("NDecMode_PreSel", NDecMode, weight, 8, 0., 8.);
    FillHist("NWDecMode_PreSel", NDecMode, WDecMode, weight, 8, 0., 8., 4, 0., 4.);
  }


  if(NLJet<2) return;
  FillHist("WDecMode_2LJ", WDecMode, weight, 4, 0., 4.);
  FillHist("NDecMode_2LJ", NDecMode, weight, 8, 0., 8.);
  FillHist("NWDecMode_2LJ", NDecMode, WDecMode, weight, 8, 0., 8., 4, 0., 4.);

}



void KinVarPlot::CheckGenMatchedDist(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                                     vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                                     vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{

  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  if( truthColl.size()==0) return;
  if( !( (NMuT==2 and NElT==0) or (NElT==2 and NMuT==0) ) ) return;
  if( !(NMuT==NMuL and NElT==NElL) ) return;
  if( !(NMuT==NMuV and NElT==NElV) ) return;
  if( FakeRun      and weight==0.  ) return; 
  if(NMuT==2){
    Label="_2M"+Label;
    if(MuTColl.at(0).Charge()!=MuTColl.at(1).Charge()) return;
    if(!(MuTColl.at(0).Pt()>20 && MuTColl.at(1).Pt()>10)) return;
    double Mll = (MuTColl.at(0)+MuTColl.at(1)).M();
    if(Mll<4) return; 
    if(!IsDATA){
      int GenLepInfo = GetGenLepInfo(ElTColl, MuTColl);
      if(ConvRun && GenLepInfo>=100) return;
      if(FlipRun && (GenLepInfo>999 or GenLepInfo<100)) return;
    }
    InitializeTreeVars();
    if(BJetColl.size()<1) return;
    if(JetColl.size() <3) return;

    bool IsSignal = MCSample.Contains("HeavyN"), IsTTBkd = MCSample.Contains("TT") && MCSample.Contains("powheg");
    bool checkedHN=false; int tDecN = 0, tDeclFk1 = 0 ; bool FkPrSameSrc=false;
    for(unsigned int it=2; it<truthColl.size() && IsSignal && !checkedHN; it++){
      int PID = truthColl.at(it).PID(), aPID = abs(PID);
      if(aPID<9900000) continue;
      int MIdx = truthColl.at(it).MotherIndex(), MPID = truthColl.at(MIdx).PID(), aMPID = abs(MPID);
      if(MPID==PID) continue;
      if( !(aMPID==6 or aMPID==24) ) continue;

      if     (MPID==6  or MPID== 24) tDecN= 1;
      else if(MPID==-6 or MPID==-24) tDecN=-1;
      checkedHN=true;
    }
    if(IsSignal && tDecN==0){ cout<<"dec assingment wrong"<<endl; return; }



    int IdxFk1=-1, IdxFk2=-1, IdxPrW1=-1, Idxlt=-1, IdxlN=-1;
    int Idxbt=-1, Idxbtx=-1, IdxjW1=-1, IdxjW2=-1, IdxjN1=-1, IdxjN2=-1;
    int Nbt=0, NjW=0, NjN=0, NjPrElse=0, NjUnmatch=0;
    for(unsigned int im=0; im<MuTColl.size(); im++){
      int LepType = GetLeptonType_JH(MuTColl.at(im), truthColl);
      if(LepType<0 && LepType>-5){ if(IdxFk1<0){ IdxFk1=im; } else{ IdxFk2=im; } }
      else if(LepType>0 && LepType!=3){
        if     (IsTTBkd ){ if(IdxPrW1<0){ IdxPrW1=im; } }
        else if(IsSignal){
          int MatchedTruthIdx = GenMatchedIdx(MuTColl.at(im),truthColl);
          int MotherIdx = FirstNonSelfMotherIdx(MatchedTruthIdx,truthColl);
          int MPID = truthColl.at(MotherIdx).PID(), aMPID = abs(MPID);
          if     (aMPID>9900000        ) IdxlN=im;
          else if(aMPID==6 or aMPID==24) Idxlt=im;
        }
      }
    }
    int NFk = IdxFk2!=-1? 2: IdxFk1!=-1? 1: 0;
    FillHist("NFk"+Label, NFk, weight, 2, 0., 2.);
    if(Idxlt>=0 && IdxlN>=0){ FillHist("IdxlN" +Label, IdxlN , weight, 2, 0., 2.); }
    if(       NFk==1       ){ FillHist("IdxlFk"+Label, IdxFk1, weight, 2, 0., 2.); }


    if(IsTTBkd && IdxFk1!=-1){
      int MatchedIdxFk=GenMatchedIdx(MuTColl.at(IdxFk1),truthColl);
      int midx=MatchedIdxFk;
      while(midx!=-1 && abs(truthColl.at(midx).PID())!=6){
        midx = truthColl.at(midx).MotherIndex();
        if(midx<0) break;
        if(truthColl.at(midx).PID()== 6) tDeclFk1= 1;
        if(truthColl.at(midx).PID()==-6) tDeclFk1=-1;
      }
      if(tDeclFk1== 1 && IdxPrW1!=-1 && MuTColl.at(IdxPrW1).Charge()>0) FkPrSameSrc=true;
      if(tDeclFk1==-1 && IdxPrW1!=-1 && MuTColl.at(IdxPrW1).Charge()<0) FkPrSameSrc=true;
    }
    

    for(unsigned int ij=0; ij<JetColl.size(); ij++){
      int jetFlav     = JetColl.at(ij).GenHFHadronMatcherFlavour();
      int jetFlavOrig = JetColl.at(ij).GenHFHadronMatcherOrigin();
      if(jetFlav==5){
        if     (jetFlavOrig== 6){ Idxbt  = ij; Nbt++; }
        else if(jetFlavOrig==-6){ Idxbtx = ij; Nbt++; }
      }
      else if(jetFlav!=-999){
        bool MatchOrigin=false;
        for(unsigned int it=2; it<truthColl.size() && !MatchOrigin; it++){
          int PID = truthColl.at(it).PID(), aPID = abs(PID);
          if( !(aPID<=4) ) continue;
          int MIdx = truthColl.at(it).MotherIndex(), MPID = truthColl.at(MIdx).PID(), aMPID = abs(MPID);
          int GrMIdx = FirstNonSelfMotherIdx(MIdx,truthColl), GrMPID = GrMIdx!=-1? truthColl.at(GrMIdx).PID():0, aGrMPID=abs(GrMPID);
          if(MPID==PID) continue;
          if( !(aMPID==24 or aMPID>9900000) ) continue;
          if(JetColl.at(ij).DeltaR(truthColl.at(it))>0.4) continue;
    
          if(aMPID==24){
            if(IsSignal){
              if     (tDecN==1 && MPID<0 && GrMPID==-6     ){ if(IdxjW1==-1){ IdxjW1=ij; NjW++; } else if(IdxjW2==-1){ IdxjW2=ij; NjW++; } }
              else if(tDecN==1 && MPID<0 && aGrMPID>9900000){ if(IdxjN1==-1){ IdxjN1=ij; NjN++; } else if(IdxjN2==-1){ IdxjN2=ij; NjN++; } }
              else if(tDecN<0  && MPID>0 && GrMPID==6      ){ if(IdxjW1==-1){ IdxjW1=ij; NjW++; } else if(IdxjW2==-1){ IdxjW2=ij; NjW++; } }
              else if(tDecN<0  && MPID>0 && aGrMPID>9900000){ if(IdxjN1==-1){ IdxjN1=ij; NjN++; } else if(IdxjN2==-1){ IdxjN2=ij; NjN++; } }
            }
            else{
              if(IdxjW1==-1){ IdxjW1=ij; NjW++; } else if(IdxjW2==-1){ IdxjW2=ij; NjW++; }
            }
          }
          else if(aMPID>9900000){
            if     (tDecN==1){ if(IdxjN1==-1){ IdxjN1=ij; NjN++; } else if(IdxjN2==-1){ IdxjN2=ij; NjN++; } }
            else if(tDecN<0 ){ if(IdxjN1==-1){ IdxjN1=ij; NjN++; } else if(IdxjN2==-1){ IdxjN2=ij; NjN++; } }
          }
          MatchOrigin=true;
        }
        if(!MatchOrigin) NjPrElse++;
      }
      else{ NjUnmatch++; }
    }
    FillHist("Nbt"+Label, Nbt, weight, 5, 0., 5.);
    FillHist("NjW"+Label, NjW, weight, 10, 0., 10.);
    FillHist("NjN"+Label, NjN, weight, 10, 0., 10.);
    FillHist("NjPrElse" +Label,  NjPrElse, weight, 10, 0., 10.);
    FillHist("NjUnmatch"+Label, NjUnmatch, weight, 10, 0., 10.);
    FillHist("Idxbt"+Label, Idxbt, weight, 10, 0., 10.);
    FillHist("Idxbtx"+Label, Idxbtx, weight, 10, 0., 10.);
    FillHist("IdxjW1"+Label, IdxjW1, weight, 10, 0., 10.);
    FillHist("IdxjW2"+Label, IdxjW2, weight, 10, 0., 10.);
    FillHist("IdxjN1"+Label, IdxjN1, weight, 10, 0., 10.);
    FillHist("IdxjN2"+Label, IdxjN2, weight, 10, 0., 10.);
    if(IdxlN!=-1 && Idxlt!=-1){
      FillHist("NCntFullMatch"+Label, 0., weight, 2, 0., 2.);
      if(Nbt==2 && NjW==2 && NjN==2) FillHist("NCntFullMatch"+Label, 1., weight, 2, 0., 2.);
    }


    float Mbjj=-1, MljW=-1, MljjW=-1, MlljW=-1, MlljjW=-1, MblljW=-1., MblljjW=-1;
    float dRlNjW1=-1, dRlNjN1=-1, dRltjW1=-1, dRltjN1=-1;
    //Signal
    if(IsSignal){
      if(tDecN== 1 && IdxjW1!=-1 && IdxjW2!=-1 && Idxbtx!=-1) Mbjj = (JetColl.at(IdxjW1)+JetColl.at(IdxjW2)+JetColl.at(Idxbtx)).M();
      if(tDecN==-1 && IdxjW1!=-1 && IdxjW2!=-1 && Idxbt !=-1) Mbjj = (JetColl.at(IdxjW1)+JetColl.at(IdxjW2)+JetColl.at(Idxbt) ).M();
      if(IdxlN!=-1 && IdxjN1!=-1) MljW = (MuTColl.at(IdxlN)+JetColl.at(IdxjN1)).M();
      if(IdxlN!=-1 && IdxjN1!=-1 && IdxjN2!=-1) MljjW = (MuTColl.at(IdxlN)+JetColl.at(IdxjN1)+JetColl.at(IdxjN2)).M();
      if(IdxlN!=-1 && Idxlt !=-1 && IdxjN1!=-1){
        MlljW = (MuTColl.at(IdxlN)+MuTColl.at(Idxlt)+JetColl.at(IdxjN1)).M();
        if(tDecN==1 && Idxbt !=-1) MblljW = (MuTColl.at(IdxlN)+MuTColl.at(Idxlt)+JetColl.at(IdxjN1)+JetColl.at(Idxbt)).M();
        if(tDecN<0  && Idxbtx!=-1) MblljW = (MuTColl.at(IdxlN)+MuTColl.at(Idxlt)+JetColl.at(IdxjN1)+JetColl.at(Idxbtx)).M();
      }
      if(IdxlN!=-1 && Idxlt !=-1 && IdxjN1!=-1 && IdxjN2!=-1){
        MlljjW = (MuTColl.at(IdxlN)+MuTColl.at(Idxlt)+JetColl.at(IdxjN1)+JetColl.at(IdxjN2)).M();
        if(tDecN==1 && Idxbt !=-1) MblljjW = (MuTColl.at(IdxlN)+MuTColl.at(Idxlt)+JetColl.at(IdxjN1)+JetColl.at(IdxjN2)+JetColl.at(Idxbt)).M();
        if(tDecN<0  && Idxbtx!=-1) MblljjW = (MuTColl.at(IdxlN)+MuTColl.at(Idxlt)+JetColl.at(IdxjN1)+JetColl.at(IdxjN2)+JetColl.at(Idxbtx)).M();
      }
      if(IdxlN!=-1 && IdxjW1!=-1) dRlNjW1 = MuTColl.at(IdxlN).DeltaR(JetColl.at(IdxjW1));
      if(IdxlN!=-1 && IdxjN1!=-1) dRlNjN1 = MuTColl.at(IdxlN).DeltaR(JetColl.at(IdxjN1));
      if(Idxlt!=-1 && IdxjW1!=-1) dRltjW1 = MuTColl.at(Idxlt).DeltaR(JetColl.at(IdxjW1));
      if(Idxlt!=-1 && IdxjN1!=-1) dRltjN1 = MuTColl.at(Idxlt).DeltaR(JetColl.at(IdxjN1));
    }
    //Bkd
    if(IsTTBkd){
      if(IdxFk1!=-1 && IdxjW1!=-1              ) MljW  = (MuTColl.at(IdxFk1)+JetColl.at(IdxjW1)).M();
      if(IdxFk1!=-1 && IdxjW1!=-1 && IdxjW2!=-1) MljjW = (MuTColl.at(IdxFk1)+JetColl.at(IdxjW1)+JetColl.at(IdxjW2)).M();
    }

    float PTb=-1, PTjW1=-1, PTjW2=-1, PTjN1=-1, PTjN2=-1;
    if(Idxbt !=-1) PTb   = JetColl.at(Idxbt).Pt();
    if(IdxjW1!=-1) PTjW1 = JetColl.at(IdxjW1).Pt();
    if(IdxjW2!=-1) PTjW2 = JetColl.at(IdxjW2).Pt();
    if(IdxjN1!=-1) PTjN1 = JetColl.at(IdxjN1).Pt();
    if(IdxjN2!=-1) PTjN2 = JetColl.at(IdxjN2).Pt();

    if(IsSignal){
      FillHist("Mll"    +Label,     Mll, weight, 24, 0., 120.);
      FillHist("MljW"   +Label,    MljW, weight, 40, 0., 200.);
      FillHist("MljjW"  +Label,   MljjW, weight, 40, 0., 200.);
      FillHist("MlljW"  +Label,   MlljW, weight, 40, 0., 200.);
      FillHist("MlljjW" +Label,  MlljjW, weight, 40, 0., 200.);
      FillHist("Mbjj"   +Label,    Mbjj, weight, 40, 0., 400.);
      FillHist("MblljW" +Label,  MblljW, weight, 40, 0., 400.);
      FillHist("MblljjW"+Label, MblljjW, weight, 40, 0., 400.);
      FillHist("PTb"    +Label,     PTb, weight, 40, 0., 400.);
      FillHist("PTjW1"  +Label,   PTjW1, weight, 20, 0., 200.);
      FillHist("PTjW2"  +Label,   PTjW2, weight, 20, 0., 200.);
      FillHist("PTjN1"  +Label,   PTjN1, weight, 20, 0., 200.);
      FillHist("PTjN2"  +Label,   PTjN2, weight, 20, 0., 200.);
      FillHist("dRlNjW1"+Label, dRlNjW1, weight, 25, 0., 5.);
      FillHist("dRlNjN1"+Label, dRlNjN1, weight, 25, 0., 5.);
      FillHist("dRltjW1"+Label, dRltjW1, weight, 25, 0., 5.);
      FillHist("dRltjN1"+Label, dRltjN1, weight, 25, 0., 5.);
    }
    if(IsTTBkd && IdxFk1!=-1 && IdxPrW1!=-1){
      FillHist("PTlW" +Label, MuTColl.at(IdxPrW1).Pt(), weight, 20, 0., 200.);
      FillHist("PTlFk"+Label,  MuTColl.at(IdxFk1).Pt(), weight, 24, 0., 120.);
      if(FkPrSameSrc) Label="_SameSrc"+Label;
      else            Label="_DiffSrc"+Label;
      FillHist("Mll"  +Label,                      Mll, weight, 24, 0., 120.);
      FillHist("MTllv"+Label, MT(MuTColl.at(IdxPrW1)+MuTColl.at(IdxFk1),vMET), weight, 20, 0., 200.);
      FillHist("MljW_Fk" +Label,  MljW, weight, 40, 0., 400.);
      FillHist("MljjW_Fk"+Label, MljjW, weight, 40, 0., 400.);
      FillHist("dRll" +Label, MuTColl.at(IdxPrW1).DeltaR(MuTColl.at(IdxFk1)), weight, 25, 0., 5.);
      if(Idxbt !=-1) FillHist("dRlb_Fk"+Label,  MuTColl.at(IdxFk1).DeltaR(JetColl.at(Idxbt )), weight, 25 , 0., 5.);
      if(Idxbtx!=-1) FillHist("dRlb_Fk"+Label,  MuTColl.at(IdxFk1).DeltaR(JetColl.at(Idxbtx)), weight, 25 , 0., 5.);
      if(Idxbt !=-1) FillHist("dRlb_Pr"+Label, MuTColl.at(IdxPrW1).DeltaR(JetColl.at(Idxbt )), weight, 25 , 0., 5.);
      if(Idxbtx!=-1) FillHist("dRlb_Pr"+Label, MuTColl.at(IdxPrW1).DeltaR(JetColl.at(Idxbtx)), weight, 25 , 0., 5.);
      if(IdxjW1!=-1) FillHist("dRljW1_Fk"+Label, MuTColl.at(IdxFk1).DeltaR(JetColl.at(IdxjW1)), weight, 25, 0., 5.);
      if(IdxjW1!=-1) FillHist("dRljW1_Pr"+Label, MuTColl.at(IdxPrW1).DeltaR(JetColl.at(IdxjW1)), weight, 25, 0., 5.);
    }
  
  }
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
    }

    InitializeTreeVars();
    if(BJetColl.size()<1) return;
    if(JetColl.size() <3) return;

    double Mll = (ElTColl.at(0)+ElTColl.at(1)).M();
    if(fabs(Mll-91.2)<10.) return;

    bool IsSignal = MCSample.Contains("HeavyN"), IsTTBkd = MCSample.Contains("TT") && MCSample.Contains("powheg");
    bool checkedHN=false; int tDecN = 0, tDeclFk1 = 0 ; bool FkPrSameSrc=false;
    for(unsigned int it=2; it<truthColl.size() && IsSignal && !checkedHN; it++){
      int PID = truthColl.at(it).PID(), aPID = abs(PID);
      if(aPID<9900000) continue;
      int MIdx = truthColl.at(it).MotherIndex(), MPID = truthColl.at(MIdx).PID(), aMPID = abs(MPID);
      if(MPID==PID) continue;
      if( !(aMPID==6 or aMPID==24) ) continue;

      if     (MPID==6  or MPID== 24) tDecN= 1;
      else if(MPID==-6 or MPID==-24) tDecN=-1;
      checkedHN=true;
    }
    if(IsSignal && tDecN==0){ cout<<"dec assingment wrong"<<endl; return; }


    int IdxFk1=-1, IdxFk2=-1, IdxPrW1=-1, Idxlt=-1, IdxlN=-1;
    int Idxbt=-1, Idxbtx=-1, IdxjW1=-1, IdxjW2=-1, IdxjN1=-1, IdxjN2=-1;
    int Nbt=0, NjW=0, NjN=0, NjPrElse=0, NjUnmatch=0;
    for(unsigned int im=0; im<ElTColl.size(); im++){
      int LepType = GetLeptonType_JH(ElTColl.at(im), truthColl);
      if(LepType<0 && LepType>-5){ if(IdxFk1<0){ IdxFk1=im; } else{ IdxFk2=im; } }
      else if(LepType>0 && LepType!=3){
        if     (IsTTBkd ){ if(IdxPrW1<0){ IdxPrW1=im; } }
        else if(IsSignal){
          int MatchedTruthIdx = GenMatchedIdx(ElTColl.at(im),truthColl);
          int MotherIdx = FirstNonSelfMotherIdx(MatchedTruthIdx,truthColl);
          int MPID = truthColl.at(MotherIdx).PID(), aMPID = abs(MPID);
          if     (aMPID>9900000        ) IdxlN=im;
          else if(aMPID==6 or aMPID==24) Idxlt=im;
        }
      }
    }
    int NFk = IdxFk2!=-1? 2: IdxFk1!=-1? 1: 0;
    FillHist("NFk"+Label, NFk, weight, 2, 0., 2.);
    if(Idxlt>=0 && IdxlN>=0){ FillHist("IdxlN" +Label, IdxlN , weight, 2, 0., 2.); }
    if(       NFk==1       ){ FillHist("IdxlFk"+Label, IdxFk1, weight, 2, 0., 2.); }


    if(IsTTBkd && IdxFk1!=-1){
      int MatchedIdxFk=GenMatchedIdx(ElTColl.at(IdxFk1),truthColl);
      int midx=MatchedIdxFk;
      while(midx!=-1 && abs(truthColl.at(midx).PID())!=6){
        midx = truthColl.at(midx).MotherIndex();
        if(midx<0) break;
        if(truthColl.at(midx).PID()== 6) tDeclFk1= 1;
        if(truthColl.at(midx).PID()==-6) tDeclFk1=-1;
      }
      if(tDeclFk1== 1 && IdxPrW1!=-1 && ElTColl.at(IdxPrW1).Charge()>0) FkPrSameSrc=true;
      if(tDeclFk1==-1 && IdxPrW1!=-1 && ElTColl.at(IdxPrW1).Charge()<0) FkPrSameSrc=true;
    }
    

    for(unsigned int ij=0; ij<JetColl.size(); ij++){
      int jetFlav     = JetColl.at(ij).GenHFHadronMatcherFlavour();
      int jetFlavOrig = JetColl.at(ij).GenHFHadronMatcherOrigin();
      if(jetFlav==5){
        if     (jetFlavOrig== 6){ Idxbt  = ij; Nbt++; }
        else if(jetFlavOrig==-6){ Idxbtx = ij; Nbt++; }
      }
      else if(jetFlav!=-999){
        bool MatchOrigin=false;
        for(unsigned int it=2; it<truthColl.size() && !MatchOrigin; it++){
          int PID = truthColl.at(it).PID(), aPID = abs(PID);
          if( !(aPID<=4) ) continue;
          int MIdx = truthColl.at(it).MotherIndex(), MPID = truthColl.at(MIdx).PID(), aMPID = abs(MPID);
          int GrMIdx = FirstNonSelfMotherIdx(MIdx,truthColl), GrMPID = GrMIdx!=-1? truthColl.at(GrMIdx).PID():0, aGrMPID=abs(GrMPID);
          if(MPID==PID) continue;
          if( !(aMPID==24 or aMPID>9900000) ) continue;

          float PT=truthColl.at(it).Pt();
          if(PT<0.2) continue;
          if(fabs(JetColl.at(ij).Pt()-PT)/PT>1) continue;
          if(JetColl.at(ij).DeltaR(truthColl.at(it))>0.4) continue;
    
          if(aMPID==24){
            if(IsSignal){
              if     (tDecN==1 && MPID<0 && GrMPID==-6     ){ if(IdxjW1==-1){ IdxjW1=ij; NjW++; } else if(IdxjW2==-1){ IdxjW2=ij; NjW++; } }
              else if(tDecN==1 && MPID<0 && aGrMPID>9900000){ if(IdxjN1==-1){ IdxjN1=ij; NjN++; } else if(IdxjN2==-1){ IdxjN2=ij; NjN++; } }
              else if(tDecN<0  && MPID>0 && GrMPID==6      ){ if(IdxjW1==-1){ IdxjW1=ij; NjW++; } else if(IdxjW2==-1){ IdxjW2=ij; NjW++; } }
              else if(tDecN<0  && MPID>0 && aGrMPID>9900000){ if(IdxjN1==-1){ IdxjN1=ij; NjN++; } else if(IdxjN2==-1){ IdxjN2=ij; NjN++; } }
            }
            else{
              if(IdxjW1==-1){ IdxjW1=ij; NjW++; } else if(IdxjW2==-1){ IdxjW2=ij; NjW++; }
            }
          }
          else if(aMPID>9900000){
            if     (tDecN==1){ if(IdxjN1==-1){ IdxjN1=ij; NjN++; } else if(IdxjN2==-1){ IdxjN2=ij; NjN++; } }
            else if(tDecN<0 ){ if(IdxjN1==-1){ IdxjN1=ij; NjN++; } else if(IdxjN2==-1){ IdxjN2=ij; NjN++; } }
          }
          MatchOrigin=true;
        }
        if(!MatchOrigin) NjPrElse++;
      }
      else{ NjUnmatch++; }
    }
    FillHist("Nbt"+Label, Nbt, weight, 5, 0., 5.);
    FillHist("NjW"+Label, NjW, weight, 10, 0., 10.);
    FillHist("NjN"+Label, NjN, weight, 10, 0., 10.);
    FillHist("NjPrElse" +Label,  NjPrElse, weight, 10, 0., 10.);
    FillHist("NjUnmatch"+Label, NjUnmatch, weight, 10, 0., 10.);
    FillHist("Idxbt"+Label, Idxbt, weight, 10, 0., 10.);
    FillHist("Idxbtx"+Label, Idxbtx, weight, 10, 0., 10.);
    FillHist("IdxjW1"+Label, IdxjW1, weight, 10, 0., 10.);
    FillHist("IdxjW2"+Label, IdxjW2, weight, 10, 0., 10.);
    FillHist("IdxjN1"+Label, IdxjN1, weight, 10, 0., 10.);
    FillHist("IdxjN2"+Label, IdxjN2, weight, 10, 0., 10.);
    if(IdxlN!=-1 && Idxlt!=-1){
      FillHist("NCntFullMatch"+Label, 0., weight, 2, 0., 2.);
      if(Nbt==2 && NjW==2 && NjN==2) FillHist("NCntFullMatch"+Label, 1., weight, 2, 0., 2.);
    }


    float Mbjj=-1, MljW=-1, MljjW=-1, MlljW=-1, MlljjW=-1, MblljW=-1., MblljjW=-1;
    float dRlNjW1=-1, dRlNjN1=-1, dRltjW1=-1, dRltjN1=-1;
    //Signal
    if(IsSignal){
      if(tDecN== 1 && IdxjW1!=-1 && IdxjW2!=-1 && Idxbtx!=-1) Mbjj = (JetColl.at(IdxjW1)+JetColl.at(IdxjW2)+JetColl.at(Idxbtx)).M();
      if(tDecN==-1 && IdxjW1!=-1 && IdxjW2!=-1 && Idxbt !=-1) Mbjj = (JetColl.at(IdxjW1)+JetColl.at(IdxjW2)+JetColl.at(Idxbt) ).M();
      if(IdxlN!=-1 && IdxjN1!=-1) MljW = (ElTColl.at(IdxlN)+JetColl.at(IdxjN1)).M();
      if(IdxlN!=-1 && IdxjN1!=-1 && IdxjN2!=-1) MljjW = (ElTColl.at(IdxlN)+JetColl.at(IdxjN1)+JetColl.at(IdxjN2)).M();
      if(IdxlN!=-1 && Idxlt !=-1 && IdxjN1!=-1){
        MlljW = (ElTColl.at(IdxlN)+ElTColl.at(Idxlt)+JetColl.at(IdxjN1)).M();
        if(tDecN==1 && Idxbt !=-1) MblljW = (ElTColl.at(IdxlN)+ElTColl.at(Idxlt)+JetColl.at(IdxjN1)+JetColl.at(Idxbt)).M();
        if(tDecN<0  && Idxbtx!=-1) MblljW = (ElTColl.at(IdxlN)+ElTColl.at(Idxlt)+JetColl.at(IdxjN1)+JetColl.at(Idxbtx)).M();
      }
      if(IdxlN!=-1 && Idxlt !=-1 && IdxjN1!=-1 && IdxjN2!=-1){
        MlljjW = (ElTColl.at(IdxlN)+ElTColl.at(Idxlt)+JetColl.at(IdxjN1)+JetColl.at(IdxjN2)).M();
        if(tDecN==1 && Idxbt !=-1) MblljjW = (ElTColl.at(IdxlN)+ElTColl.at(Idxlt)+JetColl.at(IdxjN1)+JetColl.at(IdxjN2)+JetColl.at(Idxbt)).M();
        if(tDecN<0  && Idxbtx!=-1) MblljjW = (ElTColl.at(IdxlN)+ElTColl.at(Idxlt)+JetColl.at(IdxjN1)+JetColl.at(IdxjN2)+JetColl.at(Idxbtx)).M();
      }
      if(IdxlN!=-1 && IdxjW1!=-1) dRlNjW1 = ElTColl.at(IdxlN).DeltaR(JetColl.at(IdxjW1));
      if(IdxlN!=-1 && IdxjN1!=-1) dRlNjN1 = ElTColl.at(IdxlN).DeltaR(JetColl.at(IdxjN1));
      if(Idxlt!=-1 && IdxjW1!=-1) dRltjW1 = ElTColl.at(Idxlt).DeltaR(JetColl.at(IdxjW1));
      if(Idxlt!=-1 && IdxjN1!=-1) dRltjN1 = ElTColl.at(Idxlt).DeltaR(JetColl.at(IdxjN1));
    }
    //Bkd
    if(IsTTBkd){
      if(IdxFk1!=-1 && IdxjW1!=-1              ) MljW  = (ElTColl.at(IdxFk1)+JetColl.at(IdxjW1)).M();
      if(IdxFk1!=-1 && IdxjW1!=-1 && IdxjW2!=-1) MljjW = (ElTColl.at(IdxFk1)+JetColl.at(IdxjW1)+JetColl.at(IdxjW2)).M();
    }

    float PTb=-1, PTjW1=-1, PTjW2=-1, PTjN1=-1, PTjN2=-1;
    if(Idxbt !=-1) PTb   = JetColl.at(Idxbt).Pt();
    if(IdxjW1!=-1) PTjW1 = JetColl.at(IdxjW1).Pt();
    if(IdxjW2!=-1) PTjW2 = JetColl.at(IdxjW2).Pt();
    if(IdxjN1!=-1) PTjN1 = JetColl.at(IdxjN1).Pt();
    if(IdxjN2!=-1) PTjN2 = JetColl.at(IdxjN2).Pt();

    if(IsSignal){
      FillHist("Mll"    +Label,     Mll, weight, 24, 0., 120.);
      FillHist("MljW"   +Label,    MljW, weight, 40, 0., 200.);
      FillHist("MljjW"  +Label,   MljjW, weight, 40, 0., 200.);
      FillHist("MlljW"  +Label,   MlljW, weight, 40, 0., 200.);
      FillHist("MlljjW" +Label,  MlljjW, weight, 40, 0., 200.);
      FillHist("Mbjj"   +Label,    Mbjj, weight, 40, 0., 400.);
      FillHist("MblljW" +Label,  MblljW, weight, 40, 0., 400.);
      FillHist("MblljjW"+Label, MblljjW, weight, 40, 0., 400.);
      FillHist("PTb"    +Label,     PTb, weight, 40, 0., 400.);
      FillHist("PTjW1"  +Label,   PTjW1, weight, 20, 0., 200.);
      FillHist("PTjW2"  +Label,   PTjW2, weight, 20, 0., 200.);
      FillHist("PTjN1"  +Label,   PTjN1, weight, 20, 0., 200.);
      FillHist("PTjN2"  +Label,   PTjN2, weight, 20, 0., 200.);
      FillHist("dRlNjW1"+Label, dRlNjW1, weight, 25, 0., 5.);
      FillHist("dRlNjN1"+Label, dRlNjN1, weight, 25, 0., 5.);
      FillHist("dRltjW1"+Label, dRltjW1, weight, 25, 0., 5.);
      FillHist("dRltjN1"+Label, dRltjN1, weight, 25, 0., 5.);
    }
    if(IsTTBkd && IdxFk1!=-1 && IdxPrW1!=-1){
      FillHist("PTlW" +Label, ElTColl.at(IdxPrW1).Pt(), weight, 20, 0., 200.);
      FillHist("PTlFk"+Label,  ElTColl.at(IdxFk1).Pt(), weight, 24, 0., 120.);
      if(FkPrSameSrc) Label="_SameSrc"+Label;
      else            Label="_DiffSrc"+Label;
      FillHist("Mll"  +Label,                      Mll, weight, 24, 0., 120.);
      FillHist("MTllv"+Label, MT(ElTColl.at(IdxPrW1)+ElTColl.at(IdxFk1),vMET), weight, 20, 0., 200.);
      FillHist("MljW_Fk" +Label,  MljW, weight, 40, 0., 400.);
      FillHist("MljjW_Fk"+Label, MljjW, weight, 40, 0., 400.);
      FillHist("dRll" +Label, ElTColl.at(IdxPrW1).DeltaR(ElTColl.at(IdxFk1)), weight, 25, 0., 5.);
      if(Idxbt !=-1) FillHist("dRlb_Fk"+Label,  ElTColl.at(IdxFk1).DeltaR(JetColl.at(Idxbt )), weight, 25 , 0., 5.);
      if(Idxbtx!=-1) FillHist("dRlb_Fk"+Label,  ElTColl.at(IdxFk1).DeltaR(JetColl.at(Idxbtx)), weight, 25 , 0., 5.);
      if(Idxbt !=-1) FillHist("dRlb_Pr"+Label, ElTColl.at(IdxPrW1).DeltaR(JetColl.at(Idxbt )), weight, 25 , 0., 5.);
      if(Idxbtx!=-1) FillHist("dRlb_Pr"+Label, ElTColl.at(IdxPrW1).DeltaR(JetColl.at(Idxbtx)), weight, 25 , 0., 5.);
      if(IdxjW1!=-1) FillHist("dRljW1_Fk"+Label, ElTColl.at(IdxFk1).DeltaR(JetColl.at(IdxjW1)), weight, 25, 0., 5.);
      if(IdxjW1!=-1) FillHist("dRljW1_Pr"+Label, ElTColl.at(IdxPrW1).DeltaR(JetColl.at(IdxjW1)), weight, 25, 0., 5.);
    }
  }

}



void KinVarPlot::TestPlotSS2L(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                              vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                              vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{

  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  if( !( (NMuT==2 and NElT==0) or (NElT==2 and NMuT==0) ) ) return;
  if( !(NMuT==NMuL and NElT==NElL) ) return;
  if( !(NMuT==NMuV and NElT==NElV) ) return;
  if( FakeRun      and weight==0.  ) return; 
  if(NMuT==2){
    Label="_2M"+Label;
    if(MuTColl.at(0).Charge()!=MuTColl.at(1).Charge()) return;
    if(!(MuTColl.at(0).Pt()>20 && MuTColl.at(1).Pt()>10)) return;
    double Mll = (MuTColl.at(0)+MuTColl.at(1)).M();
    if(Mll<4) return; 
    if(!IsDATA && false){
      int GenLepInfo = GetGenLepInfo(ElTColl, MuTColl);
      if(ConvRun && GenLepInfo>=100) return;
      if(FlipRun && (GenLepInfo>999 or GenLepInfo<100)) return;
    }
    if(BJetColl.size()<1) return;

    float mt1jN = MCSample.Contains("MN20")? 170: MCSample.Contains("MN50")? 160: MCSample.Contains("MN75")? 150:172.5;
    vector<Jet> BCandColl = BJetColl.size()>1? BJetColl:JetColl;
    vector<Jet> NonBJetColl = SelLightJets(JetColl, jtps.at(0));

    FillHist("NJet" +Label,     JetColl.size(), weight, 10, 0., 10.);
    if(JetColl.size() <3) return;
    FillHist("NBJet_geq3J"+Label,    BJetColl.size(), weight,  5, 0.,  5.);
    FillHist("NLJet_geq3J"+Label, NonBJetColl.size(), weight, 10, 0., 10.);

    int Idxj1W=-1, Idxj2W=-1; float bestmjjW=-1;
    for(unsigned int ij1=0; ij1<NonBJetColl.size(); ij1++){
    for(unsigned int ij2=ij1+1; ij2<NonBJetColl.size(); ij2++){
      float mjj = (NonBJetColl.at(ij1)+NonBJetColl.at(ij2)).M();
      if(bestmjjW<0){ bestmjjW = mjj; Idxj1W=ij1, Idxj2W=ij2; }
      else{ if(fabs(mjj-80.4)<fabs(bestmjjW-80.4)){ bestmjjW = mjj; Idxj1W=ij1, Idxj2W=ij2; } }
    }} 
    if(bestmjjW>0){
      FillHist("Ml1W_jjCondMW"+Label, (MuTColl.at(0)+NonBJetColl.at(Idxj1W)+NonBJetColl.at(Idxj2W)).M(), weight, 40, 0., 200.);
      FillHist("Ml2W_jjCondMW"+Label, (MuTColl.at(1)+NonBJetColl.at(Idxj1W)+NonBJetColl.at(Idxj2W)).M(), weight, 40, 0., 200.);
    }
    else{ FillHist("NCntNoCand_jjCondMW"+Label, 0., weight, 1, 0., 1.); }


    int Idxj1W_1jLCondMW=-1; float bestmllj_CondMW=-1; 
    for(unsigned int inb=0; inb<NonBJetColl.size(); inb++){
      float mllj = (MuTColl.at(0)+MuTColl.at(1)+NonBJetColl.at(inb)).M();
      if(bestmllj_CondMW<0){ bestmllj_CondMW=mllj; Idxj1W_1jLCondMW=inb; }
      else{  
        if(fabs(mllj-75)<fabs(bestmllj_CondMW-75)){ bestmllj_CondMW=mllj; Idxj1W_1jLCondMW=inb; }
      }
    }
    if(bestmllj_CondMW>0){
      FillHist("Ml1jW_CondMW"+Label, (MuTColl.at(0)+NonBJetColl.at(Idxj1W_1jLCondMW)).M(), weight, 40, 0., 200.);
      FillHist("Ml2jW_CondMW"+Label, (MuTColl.at(1)+NonBJetColl.at(Idxj1W_1jLCondMW)).M(), weight, 40, 0., 200.);
      FillHist("MlljW_CondMW"+Label, (MuTColl.at(0)+MuTColl.at(1)+NonBJetColl.at(Idxj1W_1jLCondMW)).M(), weight, 40, 0., 200.);
      FillHist("MblljW_CondMW"+Label, (MuTColl.at(0)+MuTColl.at(1)+NonBJetColl.at(Idxj1W_1jLCondMW)+BCandColl.at(0)).M(), weight, 40, 0., 400.);
    }
    else{ FillHist("NCntNoCand_CondMW"+Label, 0., weight, 1, 0., 1.); }

    int Idxj1W_1jLCondMt=-1, Idxbt_1jLCondMt=-1; float bestmbllj_CondMt=-1; 
    for(unsigned int ib=0; ib<BCandColl.size(); ib++){
    for(unsigned int inb=0; inb<NonBJetColl.size(); inb++){
      if(BCandColl.at(ib).DeltaR(NonBJetColl.at(inb))<0.1) continue;
      float mbllj = (MuTColl.at(0)+MuTColl.at(1)+NonBJetColl.at(inb)+BCandColl.at(ib)).M();
      if(bestmbllj_CondMt<0){ bestmbllj_CondMt=mbllj; Idxj1W_1jLCondMt=inb; Idxbt_1jLCondMt=ib;}
      else{  
        if(fabs(mbllj-mt1jN)<fabs(bestmbllj_CondMt-mt1jN)){ bestmbllj_CondMt=mbllj; Idxj1W_1jLCondMt=inb; Idxbt_1jLCondMt=ib;}
      }
    }}
    if(bestmbllj_CondMt>0){
      FillHist("Ml1jW_CondMt"+Label, (MuTColl.at(0)+NonBJetColl.at(Idxj1W_1jLCondMt)).M(), weight, 40, 0., 200.);
      FillHist("Ml2jW_CondMt"+Label, (MuTColl.at(1)+NonBJetColl.at(Idxj1W_1jLCondMt)).M(), weight, 40, 0., 200.);
      FillHist("MlljW_CondMt"+Label, (MuTColl.at(0)+MuTColl.at(1)+NonBJetColl.at(Idxj1W_1jLCondMt)).M(), weight, 40, 0., 200.);
      FillHist("MblljW_CondMt"+Label, (MuTColl.at(0)+MuTColl.at(1)+NonBJetColl.at(Idxj1W_1jLCondMt)+BCandColl.at(Idxbt_1jLCondMt)).M(), weight, 40, 0., 400.);
    }
    else{ FillHist("NCntNoCand_CondMt"+Label, 0., weight, 1, 0., 1.); }
    

    int Idxj1W_1jLCondMtW=-1, Idxbt_1jLCondMtW=-1; float BestSumDelta=-1; 
    for(unsigned int ib=0; ib<BCandColl.size(); ib++){
    for(unsigned int inb=0; inb<NonBJetColl.size(); inb++){
      if(BCandColl.at(ib).DeltaR(NonBJetColl.at(inb))<0.1) continue;
      float mllj = (MuTColl.at(0)+MuTColl.at(1)+NonBJetColl.at(inb)).M();
      float mbllj = (MuTColl.at(0)+MuTColl.at(1)+NonBJetColl.at(inb)+BCandColl.at(ib)).M();
      float SumDelta = fabs(mbllj-160)+fabs(mllj-75);
      if(BestSumDelta<0){ BestSumDelta=SumDelta; Idxj1W_1jLCondMtW=inb; Idxbt_1jLCondMtW=ib;}
      else{  
        if(SumDelta<BestSumDelta){ BestSumDelta=SumDelta; Idxj1W_1jLCondMtW=inb; Idxbt_1jLCondMtW=ib;}
      }
    }}
    if(BestSumDelta>0){
      FillHist("Ml1jW_CondMtW"+Label, (MuTColl.at(0)+NonBJetColl.at(Idxj1W_1jLCondMtW)).M(), weight, 40, 0., 200.);
      FillHist("Ml2jW_CondMtW"+Label, (MuTColl.at(1)+NonBJetColl.at(Idxj1W_1jLCondMtW)).M(), weight, 40, 0., 200.);
      FillHist("MlljW_CondMtW"+Label, (MuTColl.at(0)+MuTColl.at(1)+NonBJetColl.at(Idxj1W_1jLCondMtW)).M(), weight, 40, 0., 200.);
      FillHist("MblljW_CondMtW"+Label, (MuTColl.at(0)+MuTColl.at(1)+NonBJetColl.at(Idxj1W_1jLCondMtW)+BCandColl.at(Idxbt_1jLCondMtW)).M(), weight, 40, 0., 400.);
    }
    else{ FillHist("NCntNoCand_CondMtW"+Label, 0., weight, 1, 0., 1.); }

  }
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
    }
    if(BJetColl.size()<1) return;

    float mt1jN = MCSample.Contains("MN20")? 170: MCSample.Contains("MN50")? 160: MCSample.Contains("MN75")? 150:172.5;
    vector<Jet> BCandColl = BJetColl.size()>1? BJetColl:JetColl;
    vector<Jet> NonBJetColl = SelLightJets(JetColl, jtps.at(0));

    FillHist("NJet" +Label,     JetColl.size(), weight, 10, 0., 10.);
    if(JetColl.size() <3) return;
    FillHist("NBJet_geq3J"+Label,    BJetColl.size(), weight,  5, 0.,  5.);
    FillHist("NLJet_geq3J"+Label, NonBJetColl.size(), weight, 10, 0., 10.);


    double Mll = (ElTColl.at(0)+ElTColl.at(1)).M();
    if(fabs(Mll-91.2)<10.) return;


    int Idxj1W=-1, Idxj2W=-1; float bestmjjW=-1;
    for(unsigned int ij1=0; ij1<NonBJetColl.size(); ij1++){
    for(unsigned int ij2=ij1+1; ij2<NonBJetColl.size(); ij2++){
      float mjj = (NonBJetColl.at(ij1)+NonBJetColl.at(ij2)).M();
      if(bestmjjW<0){ bestmjjW = mjj; Idxj1W=ij1, Idxj2W=ij2; }
      else{ if(fabs(mjj-80.4)<fabs(bestmjjW-80.4)){ bestmjjW = mjj; Idxj1W=ij1, Idxj2W=ij2; } }
    }} 
    if(bestmjjW>0){
      FillHist("Ml1W_jjCondMW"+Label, (ElTColl.at(0)+NonBJetColl.at(Idxj1W)+NonBJetColl.at(Idxj2W)).M(), weight, 40, 0., 200.);
      FillHist("Ml2W_jjCondMW"+Label, (ElTColl.at(1)+NonBJetColl.at(Idxj1W)+NonBJetColl.at(Idxj2W)).M(), weight, 40, 0., 200.);
    }
    else{ FillHist("NCntNoCand_jjCondMW"+Label, 0., weight, 1, 0., 1.); }


    int Idxj1W_1jLCondMW=-1; float bestmllj_CondMW=-1; 
    for(unsigned int inb=0; inb<NonBJetColl.size(); inb++){
      float mllj = (ElTColl.at(0)+ElTColl.at(1)+NonBJetColl.at(inb)).M();
      if(bestmllj_CondMW<0){ bestmllj_CondMW=mllj; Idxj1W_1jLCondMW=inb; }
      else{  
        if(fabs(mllj-75)<fabs(bestmllj_CondMW-75)){ bestmllj_CondMW=mllj; Idxj1W_1jLCondMW=inb; }
      }
    }
    if(bestmllj_CondMW>0){
      FillHist("Ml1jW_CondMW"+Label, (ElTColl.at(0)+NonBJetColl.at(Idxj1W_1jLCondMW)).M(), weight, 40, 0., 200.);
      FillHist("Ml2jW_CondMW"+Label, (ElTColl.at(1)+NonBJetColl.at(Idxj1W_1jLCondMW)).M(), weight, 40, 0., 200.);
      FillHist("MlljW_CondMW"+Label, (ElTColl.at(0)+ElTColl.at(1)+NonBJetColl.at(Idxj1W_1jLCondMW)).M(), weight, 40, 0., 200.);
      FillHist("MblljW_CondMW"+Label, (ElTColl.at(0)+ElTColl.at(1)+NonBJetColl.at(Idxj1W_1jLCondMW)+BCandColl.at(0)).M(), weight, 40, 0., 400.);
    }
    else{ FillHist("NCntNoCand_CondMW"+Label, 0., weight, 1, 0., 1.); }

    int Idxj1W_1jLCondMt=-1, Idxbt_1jLCondMt=-1; float bestmbllj_CondMt=-1; 
    for(unsigned int ib=0; ib<BCandColl.size(); ib++){
    for(unsigned int inb=0; inb<NonBJetColl.size(); inb++){
      if(BCandColl.at(ib).DeltaR(NonBJetColl.at(inb))<0.1) continue;
      float mbllj = (ElTColl.at(0)+ElTColl.at(1)+NonBJetColl.at(inb)+BCandColl.at(ib)).M();
      if(bestmbllj_CondMt<0){ bestmbllj_CondMt=mbllj; Idxj1W_1jLCondMt=inb; Idxbt_1jLCondMt=ib;}
      else{  
        if(fabs(mbllj-mt1jN)<fabs(bestmbllj_CondMt-mt1jN)){ bestmbllj_CondMt=mbllj; Idxj1W_1jLCondMt=inb; Idxbt_1jLCondMt=ib;}
      }
    }}
    if(bestmbllj_CondMt>0){
      FillHist("Ml1jW_CondMt"+Label, (ElTColl.at(0)+NonBJetColl.at(Idxj1W_1jLCondMt)).M(), weight, 40, 0., 200.);
      FillHist("Ml2jW_CondMt"+Label, (ElTColl.at(1)+NonBJetColl.at(Idxj1W_1jLCondMt)).M(), weight, 40, 0., 200.);
      FillHist("MlljW_CondMt"+Label, (ElTColl.at(0)+ElTColl.at(1)+NonBJetColl.at(Idxj1W_1jLCondMt)).M(), weight, 40, 0., 200.);
      FillHist("MblljW_CondMt"+Label, (ElTColl.at(0)+ElTColl.at(1)+NonBJetColl.at(Idxj1W_1jLCondMt)+BCandColl.at(Idxbt_1jLCondMt)).M(), weight, 40, 0., 400.);
    }
    else{ FillHist("NCntNoCand_CondMt"+Label, 0., weight, 1, 0., 1.); }
    

    int Idxj1W_1jLCondMtW=-1, Idxbt_1jLCondMtW=-1; float BestSumDelta=-1; 
    for(unsigned int ib=0; ib<BCandColl.size(); ib++){
    for(unsigned int inb=0; inb<NonBJetColl.size(); inb++){
      if(BCandColl.at(ib).DeltaR(NonBJetColl.at(inb))<0.1) continue;
      float mllj = (ElTColl.at(0)+ElTColl.at(1)+NonBJetColl.at(inb)).M();
      float mbllj = (ElTColl.at(0)+ElTColl.at(1)+NonBJetColl.at(inb)+BCandColl.at(ib)).M();
      float SumDelta = fabs(mbllj-160)+fabs(mllj-75);
      if(BestSumDelta<0){ BestSumDelta=SumDelta; Idxj1W_1jLCondMtW=inb; Idxbt_1jLCondMtW=ib;}
      else{  
        if(SumDelta<BestSumDelta){ BestSumDelta=SumDelta; Idxj1W_1jLCondMtW=inb; Idxbt_1jLCondMtW=ib;}
      }
    }}
    if(BestSumDelta>0){
      FillHist("Ml1jW_CondMtW"+Label, (ElTColl.at(0)+NonBJetColl.at(Idxj1W_1jLCondMtW)).M(), weight, 40, 0., 200.);
      FillHist("Ml2jW_CondMtW"+Label, (ElTColl.at(1)+NonBJetColl.at(Idxj1W_1jLCondMtW)).M(), weight, 40, 0., 200.);
      FillHist("MlljW_CondMtW"+Label, (ElTColl.at(0)+ElTColl.at(1)+NonBJetColl.at(Idxj1W_1jLCondMtW)).M(), weight, 40, 0., 200.);
      FillHist("MblljW_CondMtW"+Label, (ElTColl.at(0)+ElTColl.at(1)+NonBJetColl.at(Idxj1W_1jLCondMtW)+BCandColl.at(Idxbt_1jLCondMtW)).M(), weight, 40, 0., 400.);
    }
    else{ FillHist("NCntNoCand_CondMtW"+Label, 0., weight, 1, 0., 1.); }


  }

}




void KinVarPlot::MakePlotSS2L(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                              vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                              vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{

  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  vector<Muon> MuConeColl; vector<Electron> ElConeColl;
  if( !( (NMuT==2 and NElT==0) or (NElT==2 and NMuT==0) ) ) return;
  if( !(NMuT==NMuL and NElT==NElL) ) return;
  if( !(NMuT==NMuV and NElT==NElV) ) return;
  if( FakeRun      and weight==0.  ) return; 
  
  if(NMuT==2){
    if(!IsDATA && MCSample.Contains("HeavyN-El")) return;
    //if(MuTColl.at(0).Charge()==MuTColl.at(1).Charge()) return;
    if(MuTColl.at(0).Charge()!=MuTColl.at(1).Charge()) return;
    if(!(MuTColl.at(0).Pt()>20 && MuTColl.at(1).Pt()>10)) return;
    double Mll = (MuTColl.at(0)+MuTColl.at(1)).M();
    if(Mll<4) return; 
//    if(fabs(Mll-91.2)>10.) return;
    if(!IsDATA){
      int GenLepInfo = GetGenLepInfo(ElTColl, MuTColl);
      if(ConvRun && GenLepInfo>=100) return;
      if(FlipRun && (GenLepInfo>999 or GenLepInfo<100)) return;
    }
    InitializeTreeVars();
    NbPre = BJetColl.size();
    if(BJetColl.size()<1) return;
    NjPre = JetColl.size();
    if(JetColl.size() <3) return;

    vector<Jet> BCandColl = BJetColl.size()>1? BJetColl:JetColl;
    vector<Jet> NonBJetColl = SelLightJets(JetColl, jtps.at(0));
    NljPre = NonBJetColl.size();
    if(NonBJetColl.size()==0) return;

    if(FakeRun){
      cout<<"Fake Cone Correction"<<endl;
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
    cout<<"MW candidate"<<endl;
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
    cout<<"Mt candidate"<<endl;
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

    MbllW_1jL = 0;
    MllW_1jL  = 0;
    Ml1W_1jL  = 0;
    Ml2W_1jL  = 0;



    int Idxj1W_1jH=-1, Idxbt_1jH=-1; float BestDeltambllj=-1;
    cout<<"semi-top reco"<<endl;
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

    MbllW_1jH=0;
    Ml1W_1jH=0;
    Ml2W_1jH=0;


    int Idxj1W_H=-1, Idxj2W_H=-1, Idxbt_H=-1; float BestSumDelta_H=-1; 
    cout<<"full top reco"<<endl;
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

    MbllW_H = 0;
    Ml1W_H = 0;
    Ml2W_H = 0;


    if( !(Label.Contains("SystWgtVar") && SysWgtStrPairList.size()>0) ){
      w_tot   = weight;
      if(VarPlots){
        PlotParameters("_2M_MNltMW"+Label);
        if(NonBJetColl.size()>1) PlotParameters("_2M_MNgtMW"+Label);
//        PlotParameters("_2M_MNgtMW"+Label);
      }
      if(DiscPlots){
        PlotDiscriminators("_2M_MNltMW"+Label);
        if(NonBJetColl.size()>1) PlotDiscriminators("_2M_MNgtMW"+Label);
      }
    }
    else{
      Label.ReplaceAll("SystWgtVar","");
      for(unsigned int iw=0; iw<SysWgtStrPairList.size(); iw++){
        w_tot           = SysWgtStrPairList.at(iw).first;
        TString SystStr = SysWgtStrPairList.at(iw).second;
        if(VarPlots){
          PlotParameters("_2M_MNltMW"+Label+SystStr);
//          PlotParameters("_2M_MNgtMW"+Label+SystStr);
          if(NonBJetColl.size()>1) PlotParameters("_2M_MNgtMW"+Label+SystStr);
        }
        if(DiscPlots){
          PlotDiscriminators("_2M_MNltMW"+Label+SystStr);
          if(NonBJetColl.size()>1) PlotDiscriminators("_2M_MNgtMW"+Label+SystStr);
        }
      }
    }
  }
  if(NElT==2){
    if(!IsDATA && MCSample.Contains("HeavyN-Mu")) return;
    int aSumQ = abs(SumCharge(ElTColl)); float MCCFSF=1.;
    if(FlipRun && !FakeRun){ if(aSumQ!=0) return; }
    else                   { if(aSumQ==0) return; }
    //if(FlipRun && !FakeRun){ if(aSumQ==0) return; }
    //else                   { if(aSumQ!=0) return; }
    if(!(ElTColl.at(0).Pt()>25 && ElTColl.at(1).Pt()>15)) return;
    if(!IsDATA){
      int GenLepInfo = GetGenLepInfo(ElTColl, MuTColl);
      if(ConvRun && GenLepInfo>=100) return;
      if(FlipRun && aSumQ!=0 && (GenLepInfo>999 or GenLepInfo<100)) return;
      //if(FlipRun && aSumQ==0 && (GenLepInfo>999 or GenLepInfo<100)) return;
      if(FlipRun && FakeRun){
        int IdxFlipped = GenLepInfo % 10;
        MCCFSF = GetCFRAndSF( ElTColl.at(IdxFlipped).Pt(), fabs(ElTColl.at(IdxFlipped).Eta()), "hCFR_sf_Var", "");
      }
    }
    float newweight = weight*MCCFSF;

    InitializeTreeVars();
    cout<<"Error 10"<<endl;
    NbPre = BJetColl.size();
    if(BJetColl.size()<1) return;
    NjPre = JetColl.size();
    if(JetColl.size() <3) return;
    cout<<"Error 11"<<endl;

    vector<Jet> BCandColl = BJetColl.size()>1? BJetColl:JetColl;
    vector<Jet> NonBJetColl = SelLightJets(JetColl, jtps.at(0));
    NljPre = NonBJetColl.size();
    if(NonBJetColl.size()==0) return;

    if(FakeRun){
      cout<<"Fake Cone Correction"<<endl;
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
    float Etal1 = ElConeColl.at(0).Eta();
    float Etal2 = ElConeColl.at(1).Eta();
    TString EtaStr = fabs(Etal1)<1.5 && fabs(Etal2)<1.5? "_BB": fabs(Etal1)>1.5 && fabs(Etal2)>1.5? "_EE":"_EB";

///// FlipRun PT Correction
    if(FlipRun && !IsDATA){
      float PT_Shift = 1.0;
      TString Era = GetEraShort();
      if(EtaStr = "_BB"){
        if(Era == "2018"){
          PT_Shift = 0.980;
        }
        if(Era == "2017"){
          PT_Shift = 0.976;
        }
        if(Era == "2016b"){
          PT_Shift = 0.986;
        }
        if(Era == "2016a"){
          PT_Shift = 0.984;
        }
      }
      if(EtaStr = "_EE"){
        if(Era == "2018"){
          PT_Shift = 0.985;
        }
        if(Era == "2017"){
          PT_Shift = 0.989;
        }
        if(Era == "2016b"){
          PT_Shift = 0.990;
        }
        if(Era == "2016a"){
          PT_Shift = 0.990;
        }
      }
      if(EtaStr = "_EB"){
        if(Era == "2018"){
          PT_Shift = 0.983;
        }
        if(Era == "2017"){
          PT_Shift = 0.984;
        }
        if(Era == "2016b"){
          PT_Shift = 0.986;
        }
        if(Era == "2016a"){
          PT_Shift = 0.987;
        }
      }

      vMET.SetPxPyPzE(vMET.Px()-ElConeColl.at(0).Px()-ElConeColl.at(1).Px(),
                      vMET.Py()-ElConeColl.at(0).Py()-ElConeColl.at(1).Py(),
                      vMET.Pz()-ElConeColl.at(0).Pz()-ElConeColl.at(1).Pz(),
                      vMET.E());
      ElConeColl.at(0).SetPtEtaPhiM(PT_Shift*ElConeColl.at(0).Pt(),ElConeColl.at(0).Eta(),ElConeColl.at(0).Phi(),ElConeColl.at(0).M());
      ElConeColl.at(1).SetPtEtaPhiM(PT_Shift*ElConeColl.at(1).Pt(),ElConeColl.at(1).Eta(),ElConeColl.at(1).Phi(),ElConeColl.at(1).M());
      vMET.SetPxPyPzE(vMET.Px()+ElConeColl.at(0).Px()+ElConeColl.at(1).Px(),
                      vMET.Py()+ElConeColl.at(0).Py()+ElConeColl.at(1).Py(),
                      vMET.Pz()+ElConeColl.at(0).Pz()+ElConeColl.at(1).Pz(),
                      vMET.E());
    }

///// FlipRun PT Correction Done


    float Mll = (ElConeColl.at(0)+ElConeColl.at(1)).M();
    if(fabs(Mll-91.2)<10.) return;
//    if(fabs(Mll-91.2)>10.) return;

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
    Ml2j1W_BkdTop=0;
    Ml2W_BkdTop=0;
    MTbl1v_BkdTop=0;

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
    MbllW_1jL = 0;
    MllW_1jL = 0;
    Ml1W_1jL = 0;
    Ml2W_1jL = 0;


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
    MbllW_1jH = 0;
    Ml1W_1jH = 0;
    Ml2W_1jH = 0;

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
    MbllW_H = 0;
    Ml1W_H = 0;
    Ml2W_H = 0;

    if( !(Label.Contains("SystWgtVar") && SysWgtStrPairList.size()>0) ){
      w_tot   = newweight;
      if(VarPlots){
        PlotParameters("_2E_MNltMW"+Label);
//        PlotParameters("_2E_MNgtMW"+Label);
        if(NonBJetColl.size()>1) PlotParameters("_2E_MNgtMW"+Label);
      }
      if(DiscPlots){
        PlotDiscriminators("_2E_MNltMW"+Label);
        if(NonBJetColl.size()>1) PlotDiscriminators("_2E_MNgtMW"+Label);
      }
    }
    else{
      Label.ReplaceAll("SystWgtVar","");
      for(unsigned int iw=0; iw<SysWgtStrPairList.size(); iw++){
        w_tot           = SysWgtStrPairList.at(iw).first * MCCFSF;
        TString SystStr = SysWgtStrPairList.at(iw).second;
        if(VarPlots){
          PlotParameters("_2E_MNltMW"+Label+SystStr);
//          PlotParameters("_2E_MNgtMW"+Label+SystStr);
          if(NonBJetColl.size()>1) PlotParameters("_2E_MNgtMW"+Label+SystStr);
        }
        if(DiscPlots){
          PlotDiscriminators("_2E_MNltMW"+Label+SystStr);
          if(NonBJetColl.size()>1) PlotDiscriminators("_2E_MNgtMW"+Label+SystStr);
        }
      }
    }
  }

}



void KinVarPlot::MakePlot3L(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                            vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                            vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{
  //Used in feasibility study of merging 4L final states using MC + fake (RD) in the early study with prelegacy dataset.
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
  vector<TString> MNStrList={"20", "50", "75", "100"};
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
    if(!PassMWin) continue;

    int Nbin=Mix=="Mu"? 47:27;
    FillHist("SigBins_"+Mix+"_MN"+MN+Label, IdxFill+1E-2, weight, Nbin, 1., 1.+(float) Nbin);
  }}

}


void KinVarPlot::MakePlot4L(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                            vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                            vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{
  //Used in feasibility study of merging 4L final states using MC + fake (RD) in the early study with prelegacy dataset.
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
  vector<TString> MNStrList={"20", "50", "75", "100"};
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
 
  bool BelowMW = Label.Contains("_MNltMW");
  bool AboveMW = Label.Contains("_MNgtMW");
  if( !(BelowMW or AboveMW) ) return;

  if(BelowMW){
    FillHist("NljPre"+Label, NljPre, w_tot, 10, 0., 10.);
    FillHist("NjPre"+Label ,  NjPre, w_tot, 10, 0., 10.);
    FillHist("NbPre"+Label ,  NbPre, w_tot, 4, 0., 4.);
  }
  FillHist("NEvt"+Label, 0., w_tot, 1, 0., 1.);
  FillHist("Nj"+Label, Nj, w_tot, 10, 0., 10.);
  FillHist("Nb"+Label, Nb, w_tot, 4, 0, 4.);
  FillHist("Ptl1"+Label, Ptl1, w_tot, 25, 0., 250.);
  FillHist("Ptl2"+Label, Ptl2, w_tot, 20, 0., 100.);
  FillHist("HT"+Label, HT, w_tot, 25, 0., 1000.);
  FillHist("MET"+Label, MET, w_tot, 30, 0., 300.);
  FillHist("dRll"+Label, dRll, w_tot, 25, 0., 5.);
  FillHist("dRlj11"+Label, dRlj11, w_tot, 25, 0., 5.);
  FillHist("dRlj12"+Label, dRlj12, w_tot, 25, 0., 5.);
  FillHist("dRlj13"+Label, dRlj13, w_tot, 25, 0., 5.);
  FillHist("dRlj21"+Label, dRlj21, w_tot, 25, 0., 5.);
  FillHist("dRlj22"+Label, dRlj22, w_tot, 25, 0., 5.);
  FillHist("dRlj23"+Label, dRlj23, w_tot, 25, 0., 5.);
  FillHist("MSSSF"+Label, MSSSF, w_tot, 50, 0., 250.);
  //FillHist("MSSSF_Fine"+Label, MSSSF, w_tot, 15, 190., 220.);
  FillHist("MTvl1"+Label, MTvl1, w_tot, 30, 0., 300.);
  FillHist("MTllv"+Label, MTvl1, w_tot, 36, 0., 360.);
  FillHist("MTbl1v_BkdTop"+Label, MTbl1v_BkdTop, w_tot, 50, 0., 500.);
  FillHist("Ml2j1W_BkdTop"+Label, Ml2j1W_BkdTop, w_tot, 40, 0., 400.);
  if(BelowMW){
    FillHist("MbllW_1jL"+Label, MbllW_1jL, w_tot, 50, 0., 500.);
    FillHist("MllW_1jL"+Label, MllW_1jL, w_tot, 50, 0., 500.);
    FillHist("Ml1W_1jL"+Label, Ml1W_1jL, w_tot, 36, 0., 360.);
    FillHist("Ml2W_1jL"+Label, Ml2W_1jL, w_tot, 40, 0., 200.);
  }
  if(AboveMW){
    FillHist("MbllW_1jH"+Label, MbllW_1jH, w_tot, 50, 0., 500.);
    FillHist("Ml1W_1jH"+Label, Ml1W_1jH, w_tot, 36, 0., 360.);
    FillHist("Ml2W_1jH"+Label, Ml2W_1jH, w_tot, 40, 0., 200.);
    FillHist("MbllW_H"+Label, MbllW_H, w_tot, 50, 0., 1000.);
    FillHist("Ml1W_H"+Label, Ml1W_H, w_tot, 60, 0., 600.);
    FillHist("Ml2W_H"+Label, Ml2W_H, w_tot, 40, 0., 400.);
    FillHist("Ml2W_BkdTop"+Label, Ml2W_BkdTop, w_tot, 50, 0., 500.);
  }

}


void KinVarPlot::PlotDiscriminators(TString Label){
 
  bool BelowMW = Label.Contains("_MNltMW");
  bool AboveMW = Label.Contains("_MNgtMW");
  if( !(BelowMW or AboveMW) ) return;

  vector<TString> MNStrList;
  if(BelowMW) MNStrList = MNStrListL; 
  else        MNStrList = MNStrListH;
  for(unsigned int im=0; im<MNStrList.size(); im++){
    bool Is2E = Label.Contains("_2E"), Is2M = Label.Contains("_2M");
    if(!(Is2E or Is2M)) continue;
    TString MixTag = Is2E? "_El":Is2M? "_Mu":"";
    TString MVATagStr = "BDTG_MN"+MNStrList.at(im)+MixTag;
    float MVAvalue = BelowMW? MVAReaderL->EvaluateMVA(MVATagStr):MVAReaderH->EvaluateMVA(MVATagStr);
    bool  PassCut  = PassDiscCut(MixTag, MNStrList.at(im), MVAvalue);
    if(ReverseBDT) {PassCut = !PassCut;}
    if(DiscCutOpt) FillHist("BDTG"+MixTag+"_MN"+MNStrList.at(im)+Label, MVAvalue, w_tot, 200, -1., 1.);
    else if(DiscTable){
      int BinIdx = BelowMW? im:im+MNStrListL.size();
      TString NewLabel(Label);
      NewLabel.ReplaceAll("_MNgtMW",""); NewLabel.ReplaceAll("_MNltMW","");
      FillHist("NCntBDTG_All"+NewLabel, PassCut? (double) BinIdx:-1., w_tot, 5, 0., 5.);

      int BinIdxPre = BelowMW? 0:1;
      if(im==0) FillHist("NCntPreSel_All"+NewLabel, BinIdxPre, w_tot, 2, 0., 2.);
    }
    else if(DiscCNC) FillHist("BDTG"+MixTag+"_MN"+MNStrList.at(im)+Label, PassCut? 1.:0., w_tot, 2, 0., 2.);
    else             FillHist("BDTG"+MixTag+"_MN"+MNStrList.at(im)+Label, MVAvalue, w_tot,  20, -1., 1.);
  }

}


bool KinVarPlot::PassDiscCut(TString Mix, TString MNStr, float Disc){
  
  float Cut=-1.;
  //bool Is16a=GetEraShort()=="2016a", Is16b=GetEraShort()=="2016b", Is17=DataYear==2017, Is18= DataYear==2018;
  if     (Mix.Contains("Mu") && MNStr=="20" ) Cut=0.76;
  else if(Mix.Contains("Mu") && MNStr=="30" ) Cut=0.76;
  else if(Mix.Contains("Mu") && MNStr=="40" ) Cut=0.88;
  else if(Mix.Contains("Mu") && MNStr=="50" ) Cut=0.88;
  else if(Mix.Contains("Mu") && MNStr=="60" ) Cut=0.88;
  else if(Mix.Contains("Mu") && MNStr=="70" ) Cut=0.92;
  else if(Mix.Contains("Mu") && MNStr=="75" ) Cut=0.92;
  else if(Mix.Contains("Mu") && MNStr=="85" ) Cut=0.92;
  else if(Mix.Contains("Mu") && MNStr=="95" ) Cut=0.94;
  else if(Mix.Contains("Mu") && MNStr=="100") Cut=0.94;
  else if(Mix.Contains("El") && MNStr=="20" ) Cut=0.72;
  else if(Mix.Contains("El") && MNStr=="30" ) Cut=0.72;
  else if(Mix.Contains("El") && MNStr=="40" ) Cut=0.80;
  else if(Mix.Contains("El") && MNStr=="50" ) Cut=0.80;
  else if(Mix.Contains("El") && MNStr=="60" ) Cut=0.80;
  else if(Mix.Contains("El") && MNStr=="70" ) Cut=0.78;
  else if(Mix.Contains("El") && MNStr=="75" ) Cut=0.78;
  else if(Mix.Contains("El") && MNStr=="85" ) Cut=0.70;
  else if(Mix.Contains("El") && MNStr=="95" ) Cut=0.85;
  else if(Mix.Contains("El") && MNStr=="100") Cut=0.85; //In case problem with stat->go-to 85
  //For comparison with era dependent optimization
  //if     (Mix.Contains("Mu") && MNStr=="20" ) Cut=Is16a?  0.8:Is16b? 0.76:Is17?  0.8:Is18? 0.76:0.76;
  //else if(Mix.Contains("Mu") && MNStr=="50" ) Cut=Is16a?  0.8:Is16b? 0.88:Is17? 0.88:Is18? 0.88:0.88;
  //else if(Mix.Contains("Mu") && MNStr=="75" ) Cut=Is16a? 0.84:Is16b? 0.78:Is17? 0.88:Is18? 0.88:0.92;
  //else if(Mix.Contains("Mu") && MNStr=="85" ) Cut=Is16a? 0.92:Is16b?  0.9:Is17?  0.9:Is18? 0.94:0.92;
  //else if(Mix.Contains("Mu") && MNStr=="100") Cut=Is16a? 0.84:Is16b?  0.9:Is17? 0.82:Is18?  0.9:0.86;
  //else if(Mix.Contains("El") && MNStr=="20" ) Cut=Is16a?  0.7:Is16b? 0.66:Is17?  0.7:Is18? 0.66:0.72;
  //else if(Mix.Contains("El") && MNStr=="50" ) Cut=Is16a?  0.7:Is16b?  0.8:Is17?  0.8:Is18? 0.75:0.74;
  //else if(Mix.Contains("El") && MNStr=="75" ) Cut=Is16a?  0.5:Is16b?  0.5:Is17? 0.66:Is18? 0.56:0.52;
  //else if(Mix.Contains("El") && MNStr=="85" ) Cut=Is16a? 0.64:Is16b? 0.66:Is17? 0.76:Is18?  0.7: 0.7;
  //else if(Mix.Contains("El") && MNStr=="100") Cut=Is16a? 0.82:Is16b?  0.7:Is17? 0.85:Is18?  0.8:0.82;
  //else if(!(Is16a or Is16b or Is17 or Is18)){ cout<<"No matching era"<<endl; }
  else {cout<<"No matching cut scenario!"<<endl; }

  return Disc>Cut;

}


void KinVarPlot::executeEventFromParameter(AnalyzerParameter param){
}


void KinVarPlot::InitializeTreeVars(){

  NjPre=-1, NbPre=-1, NljPre=-1;
  Nj=-1, Nb=-1, Ptl1=-1, Ptl2=-1, MET=-1, HT=-1;
  dRll=-1, dRlj11=-1, dRlj12=-1, dRlj13=-1, dRlj21=-1, dRlj22=-1, dRlj23=-1;
  MSSSF=-1;
  MTvl1=-1, MTllv=-1, Ml2j1W_BkdTop=-1, Ml2W_BkdTop=-1, MTbl1v_BkdTop=-1;
  MbllW_1jL=-1, MllW_1jL=-1, Ml1W_1jL=-1, Ml2W_1jL=-1;
  MbllW_1jH=-1, Ml1W_1jH=-1, Ml2W_1jH=-1;
  MbllW_H=-1, Ml1W_H=-1, Ml2W_H=-1; 
  w_tot=-1;

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
  MVAReaderL = new TMVA::Reader();
  MVAReaderH = new TMVA::Reader();

}


KinVarPlot::~KinVarPlot(){

  for(std::map< TString, TH2D* >::iterator mapit = maphist_FR.begin(); mapit!=maphist_FR.end(); mapit++){
    delete mapit->second;
  }
  maphist_FR.clear();
  for(std::map< TString, TH1D* >::iterator mapit = maphist_GenNorm.begin(); mapit!=maphist_GenNorm.end(); mapit++){
    delete mapit->second;
  }
  maphist_GenNorm.clear();
  SysWgtStrPairList.clear();
  delete MVAReaderL;  delete MVAReaderH;
  delete FRFile_El; delete FRFile_Mu; delete CFRFile; delete GenNormFile;

}


void KinVarPlot::InitializeReader(TMVA::Reader* ThisReader, TString Option){

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


float KinVarPlot::GetDataFakeRate(float VarX, float VarY, TString Key, TString Opt){

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


float KinVarPlot::GetDataFakeWeight(vector<Muon>& MuColl, vector<Electron>& ElColl, vector<Jet>& rawbjetColl, TString MuTID, TString ElTID, TString MuFRKey, TString ElFRKey, TString Opt){

  float weight = IsDATA? -1.:1.;
  int NLepLNotT=0; float TightIso= 0.1;
  bool MuFRConePtCut = MuFRKey.Contains("ConePtCut"), ElFRConePtCut=ElFRKey.Contains("ConePtCut");
  for(unsigned int im=0; im<MuColl.size(); im++){
    if(MuColl.at(im).PassID(MuTID)) continue; 
    for(unsigned int ib=0; ib<rawbjetColl.size(); ib++){
      if(rawbjetColl.at(ib).DeltaR(MuColl.at(im))<0.4){
        if (GetEraShort() == "2018") { weight *= 0.84;}
        else if (GetEraShort() == "2017") { weight *= 0.84;}
        else if (GetEraShort() == "2016a") { weight *= 0.85;}
        else if (GetEraShort() == "2016b") { weight *= 0.85;}
      }
    }
    float PTCorr = MuColl.at(im).CalcPtCone(MuColl.at(im).MiniRelIso(), TightIso);
    float fEta   = fabs(MuColl.at(im).Eta());
    float FR     = GetDataFakeRate(PTCorr, fEta, MuFRKey, "Mu"+Opt);
    if(PTCorr<15 && MuFRConePtCut) FR*=0.6667;
    weight*=-FR/(1.-FR);
    NLepLNotT++;
  }

  for(unsigned int ie=0; ie<ElColl.size(); ie++){
    if(ElColl.at(ie).PassID(ElTID)) continue; 
    for(unsigned int ib=0; ib<rawbjetColl.size(); ib++){
      if(rawbjetColl.at(ib).DeltaR(ElColl.at(ie))<0.4){
        if (GetEraShort() == "2018") { weight *= 0.86;}
        else if (GetEraShort() == "2017") { weight *= 0.81;}
        else if (GetEraShort() == "2016a") { weight *= 0.86;}
        else if (GetEraShort() == "2016b") { weight *= 0.85;}     
      }
    }
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


float KinVarPlot::GetCFRAndSF(float VarX, float VarY, TString Key, TString Opt){

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


float KinVarPlot::GetCFRWeight(vector<Electron>& ElColl, TString Option){

  float SumCFR=0.;
  for(unsigned int ie=0; ie<ElColl.size(); ie++){
    float PT = ElColl.at(ie).Pt(), fEta = fabs(ElColl.at(ie).Eta());
    float MCCFR = GetCFRAndSF(PT, fEta, "hCFR_MCFine_PTfEta", Option);
    float SF    = GetCFRAndSF(PT, fEta, "hCFR_sf_Var", Option);
    SumCFR+=MCCFR*SF;
  }

  return SumCFR;
}


void KinVarPlot::SetUpGenNormHists(){

  map<TString, TH1D*>::iterator mapit;
  mapit = maphist_GenNorm.find("sumW_Scale");
  if(mapit==maphist_GenNorm.end()) maphist_GenNorm["sumW_Scale"] = (TH1D*) ((TH1*) GenNormFile->Get("sumW_Scale"))->Clone();

  mapit = maphist_GenNorm.find("sumW_PDF");
  if(mapit==maphist_GenNorm.end()) maphist_GenNorm["sumW_PDF"] = (TH1D*) ((TH1*) GenNormFile->Get("sumW_PDF"))->Clone();

  mapit = maphist_GenNorm.find("sumW_AlphaS");
  if(mapit==maphist_GenNorm.end()) maphist_GenNorm["sumW_AlphaS"] = (TH1D*) ((TH1*) GenNormFile->Get("sumW_AlphaS"))->Clone();

  mapit = maphist_GenNorm.find("sumW_alpsfact");
  if(mapit==maphist_GenNorm.end()) maphist_GenNorm["sumW_alpsfact"] = (TH1D*) ((TH1*) GenNormFile->Get("sumW_alpsfact"))->Clone();

  mapit = maphist_GenNorm.find("sumW_PSSyst");
  if(mapit==maphist_GenNorm.end()) maphist_GenNorm["sumW_PSSyst"] = (TH1D*) ((TH1*) GenNormFile->Get("sumW_PSSyst"))->Clone();

}
