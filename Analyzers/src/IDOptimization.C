#include "IDOptimization.h"

void IDOptimization::initializeAnalyzer(){

  MuID=false, ElID=false, SystRun=false; 
  IDVarDist=false, IDCutFlow=false;
  TrigCutCheck=false, SelEffCheck=false, MultiIsoTest=false;

  for(unsigned int i=0; i<Userflags.size(); i++){
    if(Userflags.at(i).Contains("MuID"))          MuID          = true; 
    if(Userflags.at(i).Contains("ElID"))          ElID          = true; 
    if(Userflags.at(i).Contains("IDVarDist"))     IDVarDist     = true; 
    if(Userflags.at(i).Contains("IDCutFlow"))     IDCutFlow     = true; 
    if(Userflags.at(i).Contains("TrigCutCheck"))  TrigCutCheck  = true; 
    if(Userflags.at(i).Contains("SelEffCheck"))   SelEffCheck   = true;
    if(Userflags.at(i).Contains("MultiIsoTest"))  MultiIsoTest  = true;
    if(Userflags.at(i).Contains("SystRun"))       SystRun       = true; 
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

    TrigList_DblEG.push_back("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v");
  }
  if(DataYear==2017){
    TrigList_DblMu.push_back("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v");
    TrigList_DblMu.push_back("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v");
    TrigList_DblMu.push_back("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v");

    TrigList_DblEG.push_back("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v");
  }
  if(DataYear==2018){
    TrigList_DblMu.push_back("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v");

    TrigList_DblEG.push_back("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v");
  }

  //Set up the tagger map only for the param settings to be used.
  std::vector<JetTagging::Parameters> jtps;
  jtps.push_back( JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets) );
  mcCorr->SetJetTaggingParameters(jtps);

}


void IDOptimization::executeEvent(){


  Event ev = GetEvent();
  float weight = 1., w_GenNorm=1., w_BR=1., w_PU=1.;
  if(!IsDATA){
    w_GenNorm = ev.MCweight()*weight_norm_1invpb*GetKFactor()*ev.GetTriggerLumi("Full");
    if(MCSample.Contains("tHq") && weight_kHtt->size()>0) w_GenNorm *= weight_kHtt->at(0);
    w_PU      = GetPileUpWeight(nPileUp, 0);
    weight *= w_GenNorm * w_BR * w_PU;
  }

  bool PassTrig=false;
  if(IDVarDist or IDCutFlow or TrigCutCheck or SelEffCheck 
     or MultiIsoTest) PassTrig=true;
  if(!PassTrig) return;
  FillHist("CutFlow", 0., weight*w_GenNorm, 10, 0., 10.);
  if(!PassMETFilter()) return;
  FillHist("CutFlow", 1., weight*w_GenNorm, 10, 0., 10.);

  bool PreCutPass=false;
  vector<Muon>     muonPreColl     = GetMuons("NOCUT", 5., 2.4);
  vector<Electron> electronPreColl = GetElectrons("NOCUT", 5., 2.5);
  sort(muonPreColl.begin(), muonPreColl.end(), PtComparing);
  sort(electronPreColl.begin(), electronPreColl.end(), PtComparing);
  if(IDVarDist or IDCutFlow or TrigCutCheck){
    if(MuID && muonPreColl.size()>0    ) PreCutPass=true;
    if(ElID && electronPreColl.size()>0) PreCutPass=true; 
  }
  if( SelEffCheck or MultiIsoTest ) PreCutPass=true; 
  if(!PreCutPass) return;
  FillHist("CutFlow", 2., weight*w_GenNorm, 10, 0., 10.);


  vector<Muon>     muonRawColl       = GetMuons("NOCUT", 0., 2.4);
  vector<Electron> electronRawColl   = GetElectrons("NOCUT", 0., 2.5);
  std::sort(muonRawColl.begin(), muonRawColl.end(), PtComparing);
  std::sort(electronRawColl.begin(), electronRawColl.end(), PtComparing);

  vector<Muon>     muonTightColl     = SelectMuons(muonPreColl, "TopHN17T", 10., 2.4);
  vector<Electron> electronTightColl = SelectElectrons(electronPreColl, "TopHN17T", 10., 2.5);
  vector<Muon>     muonLooseColl     = SelectMuons(muonPreColl, "TopHN17L", 10., 2.4);
  vector<Electron> electronLooseColl = SelectElectrons(electronPreColl, "TopHN17L", 10., 2.5);
  vector<Electron> electronVetoColl  = SelectElectrons(electronPreColl, "TopHN17L", 10., 2.5);


  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
  vector<Jet> jetPreColl = GetAllJets();
  sort(jetPreColl.begin(), jetPreColl.end(), PtComparing);
  vector<Jet> jetRawColl     = SelectJets(jetPreColl, muonLooseColl, electronVetoColl, "NoID", 10., 2.9, "");
  vector<Jet> jetNoVetoColl  = SelectJets(jetRawColl, muonLooseColl, electronVetoColl, "tight", 25., 2.4, "");
  vector<Jet> bjetNoVetoColl = SelBJets(jetNoVetoColl, param_jets);
  vector<Jet> jetColl   = SelectJets( jetNoVetoColl, muonLooseColl, electronVetoColl, "tight", 25., 2.4, "LVeto");
  vector<Jet> bjetColl  = SelectJets(bjetNoVetoColl, muonLooseColl, electronVetoColl, "tight", 25., 2.4, "LVeto");


  Particle vMET = ev.GetMETVector();
  Particle vMET_xyCorr(pfMET_Type1_PhiCor_pt*TMath::Cos(pfMET_Type1_PhiCor_phi), pfMET_Type1_PhiCor_pt*TMath::Sin(pfMET_Type1_PhiCor_phi), 0., pfMET_Type1_PhiCor_pt);

  bool FillGen = MultiIsoTest or IDVarDist or IDCutFlow or TrigCutCheck or SelEffCheck;
  if(FillGen) truthColl = GetGens();


  float w_topptrw = 1., w_prefire = 1., sf_trig = 1.;
  float sf_mutk = 1., sf_muid = 1., sf_muiso = 1., sf_elreco = 1., sf_elid = 1., sf_btag = 1.;
  bool EventCand = !IsDATA;
  if(MultiIsoTest) EventCand = false;

  if((!IsDATA) && EventCand){
    //w_topptrw = mcCorr->GetTopPtReweight(truthColl);
    w_prefire = GetPrefireWeight(0);
    //sf_muid   = GetMuonSF(muonTightColl, "POGTID_genTrk", "ID");
    //sf_muiso  = GetMuonSF(muonTightColl, "POGTIso_POGTID", "Iso");
    sf_elreco = GetElectronSF(electronTightColl, "", "Reco");
    //sf_elid   = GetElectronSF(electronTightColl, "POGMVAIsoWP90", "ID");
    //sf_btag   = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets);
    //sf_trig   = mcCorr->GetTriggerSF(electronTightColl, muonTightColl, SFKey_Trig, "");
  }
  weight *= w_topptrw * w_prefire * sf_trig;
  weight *= sf_mutk * sf_muid * sf_muiso * sf_elreco * sf_elid * sf_btag;

  if(MuID){ 
    if(IDVarDist){
      CheckIDVar_MC(muonPreColl, electronPreColl, jetRawColl, weight, "NoID"     , "", "_NoID"   , "");
      CheckIDVar_MC(muonPreColl, electronPreColl, jetRawColl, weight, "POGMedium", "", "_POGM"   , "");
      CheckIDVar_MC(muonPreColl, electronPreColl, jetRawColl, weight, "POGMedium", "", "_POGMTrg", "Trg");
      CheckIDVar_MC(muonPreColl, electronPreColl, jetRawColl, weight, "POGMHLT"  , "", "_POGMHLT", "");
    }
    if(IDCutFlow){
      //nominal
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_POGMHLTmIsop10SIP4", "HLT-Iso_mIsop10SIP4_Flow2D");

      //POGIso var.
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_POGMHLTIsop25SIP4", "HLT-Iso_Isop25SIP4");
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_POGMHLTIsop20SIP4", "HLT-Iso_Isop20SIP4");
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_POGMHLTIsop15SIP4", "HLT-Iso_Isop15SIP4");

      //mIso var.
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_POGMHLTmIsop20SIP4", "HLT-Iso_mIsop20SIP4");
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_POGMHLTmIsop15SIP4", "HLT-Iso_mIsop15SIP4");
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_POGMHLTmIsop06SIP4", "HLT-Iso_mIsop06SIP4");

      //HLT-emul var.
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_POGMmIsop10SIP4", "mIsop10SIP4");

      //SIP var.
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_POGMHLTmIsop10SIP3", "HLT-Iso_mIsop10SIP3");
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_POGMHLTmIsop10SIP2", "HLT-Iso_mIsop10SIP2");

      ////HLT-Iso cut order inverted===============================//
      //nominal
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_POGMmIsop10HLTSIP4", "Iso-HLT_mIsop10SIP4_Flow2D");

      //POGIso var.
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_POGMIsop25HLTSIP4", "Iso-HLT_Isop25SIP4");
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_POGMIsop20HLTSIP4", "Iso-HLT_Isop20SIP4");
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_POGMIsop15HLTSIP4", "Iso-HLT_Isop15SIP4");

      //mIso var.
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_POGMmIsop20HLTSIP4", "Iso-HLT_mIsop20SIP4");
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_POGMmIsop15HLTSIP4", "Iso-HLT_mIsop15SIP4");
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_POGMmIsop06HLTSIP4", "Iso-HLT_mIsop06SIP4");
    }
    if(TrigCutCheck){
      CheckTrigCutInDist(muonPreColl, electronPreColl, jetRawColl, weight, "POGMedium", "", "_POGM", "");
      CheckTrigCutInDist(muonPreColl, electronPreColl, jetRawColl, weight, "POGMHLT", "", "_POGMHLT", "");
    }
    if(MultiIsoTest){
      CheckMultiIso(muonPreColl, electronPreColl, jetNoVetoColl, bjetNoVetoColl, vMET_xyCorr, truthColl, ev, weight, "");
    }
  }
  if(ElID){
    if(IDVarDist){
      CheckIDVar_MC(muonPreColl, electronPreColl, jetRawColl, weight, "", "NoID"               , "_NoID"           , "");
      CheckIDVar_MC(muonPreColl, electronPreColl, jetRawColl, weight, "", "POGMVAni90Cv"       , "_MVAni90Cv"      , "");
      CheckIDVar_MC(muonPreColl, electronPreColl, jetRawColl, weight, "", "POGMVAni90HLT172lCv", "_MVAni90HLTCv"   , "");
      CheckIDVar_MC(muonPreColl, electronPreColl, jetRawColl, weight, "", "POGMVAni90HLT172lCv", "_MVAni90HLTCvTrg", "Trg");
    }
    if(IDCutFlow){
      //nominal
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_HLTEANMiss0mIsop10", "HLTEANMiss0mIsop10");

      //Iso03
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_HLTEANMiss0Isop40", "HLTEANMiss0Isop40");
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_HLTEANMiss0Isop20", "HLTEANMiss0Isop20");
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_HLTEANMiss0Isop15", "HLTEANMiss0Isop15");
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_HLTEANMiss0Isop10", "HLTEANMiss0Isop10");
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_HLTEANMiss0Isop08", "HLTEANMiss0Isop08");
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_HLTEANMiss0Isop06", "HLTEANMiss0Isop06");

      //mIso03 cut var.
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_HLTEANMiss0mIsop40", "HLTEANMiss0mIsop40");
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_HLTEANMiss0mIsop20", "HLTEANMiss0mIsop20");
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_HLTEANMiss0mIsop15", "HLTEANMiss0mIsop15");
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_HLTEANMiss0mIsop08", "HLTEANMiss0mIsop08");
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_HLTEANMiss0mIsop06", "HLTEANMiss0mIsop06");

      //NMissHit var.
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_HLTEAmIsop10"      , "HLTEAmIsop10");
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_HLTEANMiss1mIsop10", "HLTEANMiss1mIsop10");

      //HLT emul var.
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_HLTNoEANMiss0mIsop10", "HLTNoEANMiss0mIsop10");
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_HLTTNMiss0mIsop10", "HLTTNMiss0mIsop10");
      CheckIDCutFlow(muonPreColl, electronPreColl, jetNoVetoColl, truthColl, weight, "_NMiss0mIsop10", "NMiss0mIsop10");
    }
    if(TrigCutCheck){
      CheckTrigCutInDist(muonPreColl, electronPreColl, jetRawColl, weight, "", "NoID", "_NoID", "");
      CheckTrigCutInDist(muonPreColl, electronPreColl, jetRawColl, weight, "", "POGMVAni90Cv", "_MVAni90Cv", "");
      CheckTrigCutInDist(muonPreColl, electronPreColl, jetRawColl, weight, "", "POGMVAni90HLT172lCv", "_MVAni90HLT172lCv", "");
    }
    if(MultiIsoTest){
      CheckMultiIso(muonPreColl, electronPreColl, jetNoVetoColl, bjetNoVetoColl, vMET_xyCorr, truthColl, ev, weight, "");
    }
  }
  if(SelEffCheck){
    vector<Muon> MuMiniTColl = SelectMuons(muonPreColl, "TopHN17T", 10., 2.4);
    vector<Muon> MuMinip20Coll = SelectMuons(muonPreColl, "TopHN17Tisop20", 10., 2.4);
    vector<Muon> MuMinip15Coll = SelectMuons(muonPreColl, "TopHN17Tisop15", 10., 2.4);
    vector<Muon> MuMinip10Coll = SelectMuons(muonPreColl, "TopHN17Tisop10", 10., 2.4);
    vector<Muon> MuMiniLColl = SelectMuons(muonPreColl, "TopHN17L", 10., 2.4);
    vector<Muon> MuPOGMIPIsoMColl = SelectMuons(muonPreColl, "POGMIPIsoM", 10., 2.4);
    vector<Muon> MuPOGMIPIsoVVLColl = SelectMuons(muonPreColl, "POGMIPIsoVVL", 10., 2.4);
    vector<Muon> MuPOGIDMPrIsoMColl = SelectMuons(muonPreColl, "POGIDMPrIsoM", 10., 2.4);
    vector<Muon> MuPOGIDMPrIsoVLColl = SelectMuons(muonPreColl, "POGIDMPrIsoVL", 10., 2.4);

    vector<Electron> ElTopHNTColl = SelectElectrons(electronPreColl, "TopHN17T", 10., 2.5);
    vector<Electron> ElTopHNLColl = SelectElectrons(electronPreColl, "TopHN17L", 10., 2.5);
    vector<Electron> ElTopHNSSTNMiss0Coll = SelectElectrons(electronPreColl, "TopHN17SST_NMiss0", 10., 2.5);
    vector<Electron> ElTopHNSSTColl = SelectElectrons(electronPreColl, "TopHN17SST", 10., 2.5);
    vector<Electron> ElTopHNSSLColl = SelectElectrons(electronPreColl, "TopHN17SSL", 10., 2.5);
    vector<Electron> ElTopHNTColl_NoHLT = SelectElectrons(electronPreColl, "TopHN17T_NoHLT", 10., 2.5);
    vector<Electron> ElTopHNLColl_NoHLT = SelectElectrons(electronPreColl, "TopHN17L_NoHLT", 10., 2.5);
    vector<Electron> ElTopHNSSTColl_NoHLT = SelectElectrons(electronPreColl, "TopHN17SST_NoHLT", 10., 2.5);
    vector<Electron> ElTopHNSSLColl_NoHLT = SelectElectrons(electronPreColl, "TopHN17SSL_NoHLT", 10., 2.5);

    if(ElID){
      //CheckSelectionEfficiency(MuMiniTColl, MuMiniLColl, muonRawColl, ElTopHNTColl, ElTopHNLColl, electronRawColl, jetNoVetoColl, bjetNoVetoColl, vMET, ev, weight, "_HLT");
      //CheckSelectionEfficiency(MuMiniTColl, MuMiniLColl, muonRawColl, ElTopHNSSTColl, ElTopHNSSLColl, electronRawColl, jetNoVetoColl, bjetNoVetoColl, vMET, ev, weight, "_HLTSS");
      CheckSelectionEfficiency(MuMiniTColl, MuMiniLColl, muonRawColl, ElTopHNSSTNMiss0Coll, ElTopHNLColl, electronRawColl, jetNoVetoColl, bjetNoVetoColl, vMET, ev, weight, "_HLTSS0Miss");
      //CheckSelectionEfficiency(MuMiniTColl, MuMiniLColl, muonRawColl, ElTopHNTColl_NoHLT, ElTopHNLColl_NoHLT, electronRawColl, jetNoVetoColl, bjetNoVetoColl, vMET, ev, weight, "_NoHLT");
      //CheckSelectionEfficiency(MuMiniTColl, MuMiniLColl, muonRawColl, ElTopHNSSTColl_NoHLT, ElTopHNSSLColl_NoHLT, electronRawColl, jetNoVetoColl, bjetNoVetoColl, vMET, ev, weight, "_NoHLTSS");
    }
    if(MuID){
      CheckSelectionEfficiency(MuMiniTColl, MuMiniLColl, muonRawColl, ElTopHNTColl, ElTopHNLColl, electronRawColl, jetNoVetoColl, bjetNoVetoColl, vMET, ev, weight, "_POGMIPmIsoT");
      //CheckSelectionEfficiency(MuMinip20Coll, MuMiniLColl, muonRawColl, ElTopHNTColl, ElTopHNLColl, electronRawColl, jetNoVetoColl, bjetNoVetoColl, vMET, ev, weight, "_POGMIPmIsop20");
      //CheckSelectionEfficiency(MuMinip15Coll, MuMiniLColl, muonRawColl, ElTopHNTColl, ElTopHNLColl, electronRawColl, jetNoVetoColl, bjetNoVetoColl, vMET, ev, weight, "_POGMIPmIsop15");
      //CheckSelectionEfficiency(MuMinip10Coll, MuMiniLColl, muonRawColl, ElTopHNTColl, ElTopHNLColl, electronRawColl, jetNoVetoColl, bjetNoVetoColl, vMET, ev, weight, "_POGMIPmIsop10");
      //CheckSelectionEfficiency(MuPOGIDMPrIsoMColl, MuPOGIDMPrIsoVLColl, muonRawColl, ElTopHNTColl, ElTopHNLColl, electronRawColl, jetNoVetoColl, bjetNoVetoColl, vMET, ev, weight, "_POGMPrIsoM");
      //CheckSelectionEfficiency(MuPOGMIPIsoMColl, MuPOGMIPIsoVVLColl, muonRawColl, ElTopHNTColl, ElTopHNLColl, electronRawColl, jetNoVetoColl, bjetNoVetoColl, vMET, ev, weight, "_POGMIPIsoM");
    }
  }

}

void IDOptimization::TEST(vector<Muon>& MuRawColl, vector<Electron>& ElRawColl,
vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& ev, float weight, TString Label)
{




 return;
}


void IDOptimization::CheckIDCutFlow(vector<Muon>& MuRawColl, vector<Electron>& ElRawColl, vector<Jet>& JetRawColl, vector<Gen>& TruthColl, float weight, TString Label, TString Option)
{

  float MinPtEl=10., MinPtMu=10., PTMax = Option.Contains("PtMax25")? 25:-1;
  bool HLT1Iso2 = Option.Contains("HLT-Iso"), Iso1HLT2 = !HLT1Iso2, Flow2D=Option.Contains("Flow2D");
  vector<double> EtaEdgesM = {0, 0.9, 1.2, 1.6, 2., 2.4};
  vector<double> PtEdgesM  = {10., 15., 20., 25., 35., 50., 70., 100., 200.};
  for(unsigned int im=0; im<MuRawColl.size() && MuID; im++){
    Muon* Mu = &MuRawColl.at(im);
    float PT = Mu->Pt(); float fEta = fabs(Mu->Eta());
    if( PT<MinPtMu ) continue;
    if( PTMax>0 && PT>PTMax ) continue;

    int  LepType = GetLeptonType_JH(*Mu,TruthColl);
    bool IsPr = LepType>0 && LepType!=3, IsHFk = LepType<0 && LepType>-5, IsExCv = LepType<-4, IsPrTa = LepType==3;
    if(IsHFk){//veto EWK-tau fakes or EWK-lep intervened in ID vars.
      bool NearEWLep=false;
      for(unsigned int ij=0; ij<JetRawColl.size(); ij++){
        if(JetRawColl.at(ij).DeltaR(*Mu)>0.4) continue;
        if(HasEWLepInJet(JetRawColl.at(ij), TruthColl, "InclTau")){ NearEWLep=true; break; }
      }
      if(NearEWLep) continue;
    }
    bool  MatchTrig   = Mu->PassPath("HLT_Mu8_TrkIsoVVL_v");
    bool  PassHLTCut  = Option.Contains("HLT" )? Mu->TrkIso()/PT<0.4:true;
    float RelIso      = Option.Contains("mIso")? Mu->MiniRelIso():Mu->RelIso();
    float IsoCut      = Option.Contains("Isop40")? 0.4: Option.Contains("Isop25")? 0.25: Option.Contains("Isop20")? 0.2:
                        Option.Contains("Isop15")? 0.15: Option.Contains("Isop10")? 0.1: Option.Contains("Isop08")? 0.08:
                        Option.Contains("Isop06")? 0.06:-1;
    float SIPCut      = Option.Contains("SIP4")? 4: Option.Contains("SIP3")? 3: Option.Contains("SIP2")? 2: -1;
    bool  PassIsoCut  = IsoCut>=0? RelIso<IsoCut:true;
    bool  PassSIPCut  = SIPCut>=0? Mu->SIP3D()<SIPCut:true;

    TString MuType  = IsPr? "_Pr": IsHFk? "_HFk": IsExCv? "_ExCv": IsPrTa? "_PrTa": "_Else";
    TString EtaReg  = ""; //fEta<0.8? "_B1": fEta<1.479? "_B2": "_E"; 

    if(LepType==0){ FillHist("NCntLTypeErr"+Label, 0., weight, 1, 0., 1.); continue; }
    if(IsExCv) continue;

    int it_cut=0; TString FinLabel = EtaReg+MuType+Label;
    FillHist("IDCutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;

    if( !Mu->isPOGMedium() ) continue;
    FillHist("IDCutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;
    if(Flow2D){ FillHist("IDCutFlow2D_ID"+FinLabel, PT, fEta, weight, PtEdgesM.size()-1, &PtEdgesM[0], EtaEdgesM.size()-1, &EtaEdgesM[0]); }

    if( (Iso1HLT2 && !PassIsoCut) or (HLT1Iso2 && !PassHLTCut) ) continue;
    FillHist("IDCutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;
    if(Flow2D){ FillHist("IDCutFlow2D_IDC1"+FinLabel, PT, fEta, weight, PtEdgesM.size()-1, &PtEdgesM[0], EtaEdgesM.size()-1, &EtaEdgesM[0]); }

    if( (Iso1HLT2 && !PassHLTCut) or (HLT1Iso2 && !PassIsoCut) ) continue;
    FillHist("IDCutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;
    if(Flow2D){ FillHist("IDCutFlow2D_IDC2"+FinLabel, PT, fEta, weight, PtEdgesM.size()-1, &PtEdgesM[0], EtaEdgesM.size()-1, &EtaEdgesM[0]); }

    if( !PassSIPCut ) continue;
    FillHist("IDCutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;
    if(Flow2D){ FillHist("IDCutFlow2D_IDC1C2IP"+FinLabel, PT, fEta, weight, PtEdgesM.size()-1, &PtEdgesM[0], EtaEdgesM.size()-1, &EtaEdgesM[0]); }

    if( !(fabs(Mu->dZ())<0.1) ) continue;
    FillHist("IDCutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;
     
    if( !MatchTrig ) continue;
    FillHist("IDCutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;
  }

  for(unsigned int ie=0; ie<ElRawColl.size() && ElID; ie++){
    Electron* El = &ElRawColl.at(ie);
    float PT = El->Pt(); //float fEta = fabs(El->Eta());
    if( PT<MinPtEl ) continue;
    if( PTMax>0 && PT>PTMax ) continue;
    if( El->etaRegion()==Electron::EtaRegion::GAP ) continue;

    int  LepType = GetLeptonType_JH(*El,TruthColl);
    bool IsPr = LepType>0, IsHFk = LepType<0 && LepType>-5, IsExCv = LepType<-4;
    if(IsHFk){//veto EWK-tau fakes or EWK-lep intervened in ID vars.
      bool NearEWLep=false;
      for(unsigned int ij=0; ij<JetRawColl.size(); ij++){
        if(JetRawColl.at(ij).DeltaR(*El)>0.4) continue;
        if(HasEWLepInJet(JetRawColl.at(ij), TruthColl, "InclTau")){ NearEWLep=true; break; }
      }
      if(NearEWLep) continue;
    }
    bool  MatchTrig   = El->PassFilter("hltEle8CaloIdLTrackIdLIsoVLTrackIsoFilter");
    bool  PassHLTNoEA = El->Pass_CaloIdL_TrackIdL_IsoVL("NoEA"), PassHLTEA = El->Pass_CaloIdL_TrackIdL_IsoVL();
    bool  PassHLTTight = El->Pass_CaloIdL_TrackIdL_IsoVL_Tight();
    bool  PassHLTCut  = Option.Contains("HLTNoEA")? PassHLTNoEA:Option.Contains("HLTEA")? PassHLTEA: Option.Contains("HLTT")? PassHLTTight:true;
    bool  PassPixHit  = Option.Contains("NMiss1")?  El->NMissingHits()<2: Option.Contains("NMiss0")? El->NMissingHits()==0:true;
    float RelIso      = Option.Contains("mIso")?    El->MiniRelIso():El->RelIso();
    float IsoCut      = Option.Contains("Isop40")? 0.4: Option.Contains("Isop20")? 0.2: Option.Contains("Isop15")? 0.15:
                        Option.Contains("Isop10")? 0.1: Option.Contains("Isop08")? 0.08: Option.Contains("Isop06")? 0.06:-1;
    bool  PassIsoCut  = IsoCut>=0? RelIso<IsoCut:true;

    TString ElType  = IsPr? "_Pr": IsHFk? "_HFk": IsExCv? "_ExCv": "_Else";
    TString EtaReg  = ""; //fEta<0.8? "_B1": fEta<1.479? "_B2": "_E"; 

    if(LepType==0){ FillHist("NCntLTypeErr"+Label, 0., weight, 1, 0., 1.); continue; }

    int it_cut=0; TString FinLabel = EtaReg+ElType+Label;
    FillHist("IDCutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;

    if( !El->passMVAID_noIso_WP90() ) continue;
    FillHist("IDCutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;

    if( (Iso1HLT2 && !PassIsoCut) or (HLT1Iso2 && !PassHLTCut) ) continue;
    FillHist("IDCutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;

    if( (Iso1HLT2 && !PassHLTCut) or (HLT1Iso2 && !PassIsoCut) ) continue;
    FillHist("IDCutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;

    if( !El->PassConversionVeto() ) continue;
    FillHist("IDCutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;

    if( !PassPixHit ) continue;
    FillHist("IDCutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;

    if( !(El->SIP3D()>=0 && El->SIP3D()<4) ) continue;
    FillHist("IDCutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;

    if( !(fabs(El->dZ())<0.1) ) continue;
    FillHist("IDCutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;
     
    if( !El->IsGsfCtfScPixChargeConsistent() ) continue;
    FillHist("IDCutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;

    if( !MatchTrig ) continue;
    FillHist("IDCutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;
    
  }
}


void IDOptimization::CheckMultiIso(vector<Muon>& MuPreColl, vector<Electron>& ElPreColl, vector<Jet>& JetNoVetoColl, vector<Jet>& BJetNoVetoColl, Particle& vMET, vector<Gen>& TruthColl, Event& ev, float weight, TString Label)
{

  float JetPtCut = 10.;
  if     (Label.Contains("_Pt20")) JetPtCut=20.;
  else if(Label.Contains("_Pt25")) JetPtCut=25.;
  vector<Jet> JetAllColl = GetJets("NoID", JetPtCut, 3.);
  for(unsigned int im=0; im<MuPreColl.size(); im++){
    if( !MuPreColl.at(im).PassID("POGMedium") ) return;
    if( !(fabs(MuPreColl.at(im).dZ())<0.1)    ) return;
    if( !(MuPreColl.at(im).IP3Derr()!=0 && fabs(MuPreColl.at(im).IP3D()/MuPreColl.at(im).IP3Derr())<4.) ) return;
    int LepType = GetLeptonType_JH(MuPreColl.at(im), TruthColl);
    TString TypeStr = "";
    if     (LepType>-5 && LepType<0) TypeStr="_HFk";
    else if(LepType>0 && LepType!=3) TypeStr="_Pr";
    else return;

    float PtRelv0=-1., PtRelv1=-1., PtRatio=-1., mindR=1E6; int IdxMatchJet=-1;
    float MiniIso = MuPreColl.at(im).MiniRelIso(); 
    for(unsigned int ij=0; ij<JetAllColl.size(); ij++){
      float dR=MuPreColl.at(im).DeltaR(JetAllColl.at(ij));
      if(dR>0.4) continue;
      if(dR<mindR){ mindR=dR; IdxMatchJet=ij; }
    }
    if(IdxMatchJet!=-1){
      PtRatio = MuPreColl.at(im).Pt()/JetAllColl.at(IdxMatchJet).Pt();
      TLorentzVector JetNoLep(JetAllColl.at(IdxMatchJet));
      JetNoLep -= MuPreColl.at(im);
      PtRelv0 = MuPreColl.at(im).Perp(JetAllColl.at(IdxMatchJet).Vect());
      PtRelv1 = MuPreColl.at(im).Perp(JetNoLep.Vect());
    }
    else{ PtRatio=999., PtRelv0=999., PtRelv1=999.; }
    TString StTag="_M";
    bool PassMltIsoVL = MiniIso < 0.23  && ( PtRatio > 0.60  || PtRelv1 > 5.8 );
    bool PassMltIsoL  = MiniIso < 0.22  && ( PtRatio > 0.63  || PtRelv1 > 6   );
    bool PassMltIsoM  = MiniIso < 0.14  && ( PtRatio > 0.68  || PtRelv1 > 6.7 );
    bool PassMltIsoT  = MiniIso < 0.10  && ( PtRatio > 0.70  || PtRelv1 > 7   );
    bool PassMltIsoVT = MiniIso < 0.075 && ( PtRatio > 0.725 || PtRelv1 > 7   );
    bool PassMltIsoHT = MiniIso < 0.05  && ( PtRatio > 0.725 || PtRelv1 > 8   );
    //PassMuPOGMltL =MuPreColl.at(im).PassSelector(25); PassMuPOGMltM=MuPreColl.at(im).PassSelector(26); //var seems not right
    bool PassMiniIsop20 = MiniIso<0.20;
    bool PassMiniIsop15 = MiniIso<0.15;
    bool PassMiniIsop10 = MiniIso<0.10;
    bool PassHLTCut     = MuPreColl.at(im).TrkIso()/MuPreColl.at(im).Pt()<0.4;

    vector<TString> CutTag = {"_ID"};
    if(PassHLTCut){ CutTag.push_back("_IDHLT"); }
    if(PassMiniIsop20){ CutTag.push_back("_IDmIsop20"); }
    if(PassHLTCut && PassMiniIsop20){ CutTag.push_back("_IDHLTmIsop20"); }

    for(unsigned int ic=0; ic<CutTag.size(); ic++){
      FillHist("PtRelv0"+CutTag.at(ic)+StTag+Label+TypeStr, PtRelv0, weight, 20, 0., 5.);
      FillHist("PtRelv1"+CutTag.at(ic)+StTag+Label+TypeStr, PtRelv1, weight, 80, 0., 20.);
      FillHist("PtRatio"+CutTag.at(ic)+StTag+Label+TypeStr, PtRatio, weight, 60, 0., 1.2);
      FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 0., weight, 13, 0., 13.);
      if(PassMltIsoVL ) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 1., weight, 13, 0., 13.);
      if(PassMltIsoL  ) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 2., weight, 13, 0., 13.);
      if(PassMltIsoM  ) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 3., weight, 13, 0., 13.);
      if(PassMltIsoT  ) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 4., weight, 13, 0., 13.);
      if(PassMltIsoVT ) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 5., weight, 13, 0., 13.);
      if(PassMltIsoHT ) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 6., weight, 13, 0., 13.);
      if(PassMiniIsop20) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 7., weight, 13, 0., 13.);
      if(PassMiniIsop15) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 8., weight, 13, 0., 13.);
      if(PassMiniIsop10) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 9., weight, 13, 0., 13.);
      if(PassHLTCut && PassMiniIsop20) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 10., weight, 13, 0., 13.);
      if(PassHLTCut && PassMiniIsop15) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 11., weight, 13, 0., 13.);
      if(PassHLTCut && PassMiniIsop10) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 12., weight, 13, 0., 13.);
    }
    //mIso || PtRel increases bkd too much (O(10%)) relative to small increase in bkgd (O(1%)) -> don't use it
  }


  for(unsigned int ie=0; ie<ElPreColl.size(); ie++){
    if( !ElPreColl.at(ie).passMVAID_noIso_WP90() ) return;
    if( !(ElPreColl.at(ie).IP3Derr()!=0 && fabs(ElPreColl.at(ie).IP3D()/ElPreColl.at(ie).IP3Derr())<4.) ) return;
    if( !(fabs(ElPreColl.at(ie).dZ())<0.1)     ) return;
    if( !ElPreColl.at(ie).PassConversionVeto() ) return;
    if( !(ElPreColl.at(ie).NMissingHits()<2)   ) return;

    int LepType = GetLeptonType_JH(ElPreColl.at(ie), TruthColl);
    TString TypeStr = "";
    if     (LepType>-5 && LepType<0) TypeStr="_HFk";
    else if(LepType>0 && LepType!=3) TypeStr="_Pr";
    else return;

    float PtRelv0=-1., PtRelv1=-1., PtRatio=-1., mindR=1E6; int IdxMatchJet=-1;
    float MiniIso = ElPreColl.at(ie).MiniRelIso(); 
    for(unsigned int ij=0; ij<JetAllColl.size(); ij++){
      float dR=ElPreColl.at(ie).DeltaR(JetAllColl.at(ij));
      if(dR>0.4) continue;
      if(dR<mindR){ mindR=dR; IdxMatchJet=ij; }
    }
    if(IdxMatchJet!=-1){
      PtRatio = ElPreColl.at(ie).Pt()/JetAllColl.at(IdxMatchJet).Pt();
      TLorentzVector JetNoLep(JetAllColl.at(IdxMatchJet));
      JetNoLep -= ElPreColl.at(ie);
      PtRelv0 = ElPreColl.at(ie).Perp(JetAllColl.at(IdxMatchJet).Vect());
      PtRelv1 = ElPreColl.at(ie).Perp(JetNoLep.Vect());
    }
    else{ PtRatio=999., PtRelv0=999., PtRelv1=999.; }
    TString StTag="_E";
    bool PassMltIsoVL = MiniIso < 0.23  && ( PtRatio > 0.60  || PtRelv1 > 5.8 );
    bool PassMltIsoL  = MiniIso < 0.22  && ( PtRatio > 0.63  || PtRelv1 > 6   );
    bool PassMltIsoM  = MiniIso < 0.14  && ( PtRatio > 0.68  || PtRelv1 > 6.7 );
    bool PassMltIsoT  = MiniIso < 0.10  && ( PtRatio > 0.70  || PtRelv1 > 7   );
    bool PassMltIsoVT = MiniIso < 0.075 && ( PtRatio > 0.725 || PtRelv1 > 7   );
    bool PassMltIsoHT = MiniIso < 0.05  && ( PtRatio > 0.725 || PtRelv1 > 8   );
    bool PassMiniIsop20 = MiniIso<0.20;
    bool PassMiniIsop15 = MiniIso<0.15;
    bool PassMiniIsop10 = MiniIso<0.10;
    bool PassHLTCut     = ElPreColl.at(ie).Pass_CaloIdL_TrackIdL_IsoVL();

    vector<TString> CutTag = {"_ID"};
    if( PassHLTCut ){ CutTag.push_back("_IDHLT"); }
    if( PassMiniIsop20 ){ CutTag.push_back("_IDmIsop20"); }
    if( PassHLTCut && PassMiniIsop20 ){ CutTag.push_back("_IDHLTmIsop20"); }

    for(unsigned int ic=0; ic<CutTag.size(); ic++){
      FillHist("PtRelv0"+CutTag.at(ic)+StTag+Label+TypeStr, PtRelv0, weight, 20, 0., 5.);
      FillHist("PtRelv1"+CutTag.at(ic)+StTag+Label+TypeStr, PtRelv1, weight, 80, 0., 20.);
      FillHist("PtRatio"+CutTag.at(ic)+StTag+Label+TypeStr, PtRatio, weight, 60, 0., 1.2);
      FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 0., weight, 13, 0., 13.);
      if(PassMltIsoVL ) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 1., weight, 13, 0., 13.);
      if(PassMltIsoL  ) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 2., weight, 13, 0., 13.);
      if(PassMltIsoM  ) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 3., weight, 13, 0., 13.);
      if(PassMltIsoT  ) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 4., weight, 13, 0., 13.);
      if(PassMltIsoVT ) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 5., weight, 13, 0., 13.);
      if(PassMltIsoHT ) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 6., weight, 13, 0., 13.);
      if(PassMiniIsop20) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 7., weight, 13, 0., 13.);
      if(PassMiniIsop15) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 8., weight, 13, 0., 13.);
      if(PassMiniIsop10) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 9., weight, 13, 0., 13.);
      if(PassHLTCut && PassMiniIsop20) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 10., weight, 13, 0., 13.);
      if(PassHLTCut && PassMiniIsop15) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 11., weight, 13, 0., 13.);
      if(PassHLTCut && PassMiniIsop10) FillHist("PassMultIsoCut"+CutTag.at(ic)+StTag+Label+TypeStr, 12., weight, 13, 0., 13.);
    }
  }


//  if(NMuT==2){
//    if(!ev.PassTrigger(TrigListLocal)) return;
//    if(MuTColl.at(0).Charge()!=MuTColl.at(1).Charge()) return;
//  }
//  if(NElT==2){
//    Label="_2E"+Label;
//    if(!(ElTColl.at(0).Pt()>PTCut1 && ElTColl.at(1).Pt()>PTCut2)) return;
//    if(!ev.PassTrigger(TrigListLocal)) return;
//  }
}





void IDOptimization::CheckSelectionEfficiency(
vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuRawColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElRawColl,
vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& ev, float weight, TString Label)
{

  if(MuID){
    bool PassTrig = ev.PassTrigger(TrigList_DblMu); TString QStr="";
 
    int Qtot=0, NCntL=0, Idx1=-1, Idx2=-1;
    for(unsigned int it=2; it<truthColl.size(); it++){
      int pid = truthColl.at(it).PID(), apid=abs(pid);
      if(apid!=13) continue;
      
      int midx= truthColl.at(it).MotherIndex(), mpid = midx>-1? truthColl.at(midx).PID():0, ampid = abs(mpid);
      //int LepType = GetLeptonType_JH(it, truthColl);
      if( !(ampid>9900000 or ampid==24 or ampid==6) ) continue;
      //float PT = truthColl.at(it).Pt();
      
      if(pid>0){ Qtot-=1; NCntL+=1; }
      else     { Qtot+=1; NCntL+=1; }
      if(Idx1<0) Idx1=it;
      else       Idx2=it;
    }
    FillHist("Qtot"+Label, Qtot, weight, 20, -10, 10);
    FillHist("NCntL"+Label, NCntL, weight, 20, 0, 20);
    if(NCntL==2 && Qtot==0){ FillHist("Mll"+Label, (truthColl.at(Idx1)+truthColl.at(Idx2)).M(), weight, 200., 0., 200.); }

    if(!PassTrig) return;
    if(!(MuTColl.size()==2 && MuLColl.size()==2)) return;
    if(ElLColl.size()!=0) return;
    if(MuTColl.at(0).Charge()!=MuLColl.at(1).Charge()){ QStr="_OS"; }
    else QStr="_SS";
    //if(MuTColl.at(0).Charge()!=MuLColl.at(1).Charge()) return;
    if(!(MuTColl.at(0).Pt()>20 && MuTColl.at(1).Pt()>10)) return;

    TString FinLabel = QStr+Label;
    int it_cut=0;
    FillHist("CutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;

    float Mmumu = (MuTColl.at(0)+MuTColl.at(1)).M();
    if(Mmumu<4) return;
    FillHist("CutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;

    std::vector<Jet> JetVetoColl  = JetsVetoLeptonInside(JetColl, ElLColl, MuLColl, 0.4);
    std::vector<Jet> BJetVetoColl = JetsVetoLeptonInside(BJetColl, ElLColl, MuLColl, 0.4);

    if(BJetVetoColl.size()==0) return;
    FillHist("CutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;

    if(JetVetoColl.size()<2) return;
    FillHist("CutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;
  }
  if(ElID){
    bool PassTrig = ev.PassTrigger(TrigList_DblEG);
    TString QStr="";
 
    if(!PassTrig) return;
    if(!(ElTColl.size()==2 && ElLColl.size()==2)) return;
    if(MuLColl.size()!=0) return;
    if(ElTColl.at(0).Charge()!=ElLColl.at(1).Charge()){ QStr="_OS"; }
    else QStr = "_SS";
    //if(ElTColl.at(0).Charge()!=ElLColl.at(1).Charge()) return;
    if(!(ElTColl.at(0).Pt()>25 && ElTColl.at(1).Pt()>15)) return;
    TString FinLabel = QStr+Label;
    int it_cut=0;
    FillHist("CutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;

    float Mll = (ElTColl.at(0)+ElTColl.at(1)).M();
    if(fabs(Mll-91.2)<10) return;
    FillHist("CutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;

    std::vector<Jet> JetVetoColl  = JetsVetoLeptonInside(JetColl, ElLColl, MuLColl, 0.4);
    std::vector<Jet> BJetVetoColl = JetsVetoLeptonInside(BJetColl, ElLColl, MuLColl, 0.4);

    if(BJetVetoColl.size()==0) return;
    FillHist("CutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;

    if(JetVetoColl.size()<3) return;
    FillHist("CutFlow"+FinLabel, it_cut, weight, 10, 0., 10.); it_cut++;
  }
}


void IDOptimization::CheckTrigCutInDist(vector<Muon>& MuRawColl, vector<Electron>& ElRawColl, vector<Jet>& JetRawColl, float weight,
                                        TString MuLID, TString ElLID, TString Label, TString Option)
{

  if(MuID){
    for(unsigned int it_m=0; it_m<MuRawColl.size(); it_m++){
      Muon* Mu = &MuRawColl.at(it_m);
      float PT=Mu->Pt();
      float PTMax = Option.Contains("PtMax25")? 25:-1;
      if( PT < 10 ) continue;
      if( PTMax>0 && PT>PTMax ) continue;
      if( !Mu->PassID(MuLID) ) continue;

      bool PassTrig = Mu->PassPath("HLT_Mu8_TrkIsoVVL_v");
      bool PassDZTrig = Mu->PassPath("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v") or Mu->PassPath("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v"); 
      int  LepType = GetLeptonType_JH(*Mu,truthColl);
      bool IsPr = LepType>0 && LepType!=3, IsHFk = LepType<0 && LepType>-5;
      if(IsHFk){//veto EWK-tau fakes or EWK-lep intervened in ID vars.
        bool NearEWLep=false;
        for(unsigned int ij=0; ij<JetRawColl.size(); ij++){
          if(JetRawColl.at(ij).DeltaR(*Mu)>0.4) continue;
          if(HasEWLepInJet(JetRawColl.at(ij), truthColl, "InclTau")){ NearEWLep=true; break; }
        }
        if(NearEWLep) continue;
      }
      if(LepType==0){ FillHist("NCntLTypeErr"+Label, 0., weight, 1, 0., 1.); continue; }
      if( !(IsPr or IsHFk) ) continue;//not interested in 

      TString MuType  = IsPr? "_Pr": IsHFk? "_HFk":"";
      TString TrigStr = PassTrig? "_Trg":"";

      vector<TString> LabelList;
      LabelList.push_back(MuType+Label);
      LabelList.push_back(TrigStr+MuType+Label);
      for(unsigned int il=0; il<LabelList.size(); il++){
        if( (il%2==1) && !PassTrig ) continue;
        TString FinLabel = LabelList.at(il);
        FillHist("MiniRelIso"    +FinLabel, Mu->MiniRelIso(), weight, 50, 0., 1.0);
        FillHist("RelIsoPF"      +FinLabel, Mu->RelIso(), weight, 50, 0., 1.0);
        FillHist("TkIso03"       +FinLabel, Mu->TrkIso()/PT , weight, 50, 0., 1.);
        if( (il%2==0) or (PassDZTrig && PassTrig) ){
          FillHist("dz"          +FinLabel, fabs(Mu->dZ())  , weight, 20, 0., 0.4);
          FillHist("SIP3D"       +FinLabel, Mu->SIP3D(), weight, 20, 0., 10.);
        }
      }
    }
  }

  if(ElID){
    for(unsigned int it_e=0; it_e<ElRawColl.size(); it_e++){
      Electron* El = &ElRawColl.at(it_e);
      float PT=El->Pt(), fEta=fabs(El->Eta());
      float PTMax = Option.Contains("PtMax25")? 25:-1;
      if( PT < 10 ) continue;
      if( PTMax>0 && PT>PTMax ) continue;
      if( El->etaRegion()==Electron::EtaRegion::GAP ) continue;
      if( !El->PassID(ElLID) ) continue;

      int  LepType = GetLeptonType_JH(*El,truthColl);
      bool IsPr = LepType>0 && LepType!=3, IsHFk = LepType<0 && LepType>-5;
      if(IsHFk){//veto EWK-tau fakes or EWK-lep intervened in ID vars.
        bool NearEWLep=false;
        for(unsigned int ij=0; ij<JetRawColl.size(); ij++){
          if(JetRawColl.at(ij).DeltaR(*El)>0.4) continue;
          if(HasEWLepInJet(JetRawColl.at(ij), truthColl, "InclTau")){ NearEWLep=true; break; }
        }
        if(NearEWLep) continue;
      }
      if(LepType==0){ FillHist("NCntLTypeErr"+Label, 0., weight, 1, 0., 1.); continue; }
      if( !(IsPr or IsHFk) ) continue;

      bool  PassTrig   = El->PassFilter("hltEle8CaloIdLTrackIdLIsoVLTrackIsoFilter");
      bool  PassDZTrig = El->PassPath("HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ_v")
                      or El->PassPath("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v")
                      or El->PassPath("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v");     
      float EA_ecal = fEta<1.479? 0.29:0.21, EA_hcal = fEta<1.479? 0.2:0.25;
      float EA16a_ecal = fEta<1.479? 0.16544:0.13212, EA16a_hcal = fEta<1.479? 0.05956:0.13052;
      float RelEcalPFClusterIsoEA = max(0.,El->ecalPFClusterIso()-Rho*EA_ecal)/PT;
      float RelHcalPFClusterIsoEA = max(0.,El->hcalPFClusterIso()-Rho*EA_hcal)/PT;
      float RelEcalPFClusterIsoEA16a = max(0.,El->ecalPFClusterIso()-Rho*EA16a_ecal)/PT;
      float RelHcalPFClusterIsoEA16a = max(0.,El->hcalPFClusterIso()-Rho*EA16a_hcal)/PT;

      TString ElType = IsPr? "_Pr": IsHFk? "_HFk": "";
      TString EtaReg = fEta<1.479? "_B": "_E"; 
      TString TrigStr = PassTrig? "_Trg":"";

      vector<TString> LabelList;
      LabelList.push_back(EtaReg+ElType+Label);
      LabelList.push_back(TrigStr+EtaReg+ElType+Label);
      for(unsigned int il=0; il<LabelList.size(); il++){
        if( (il%2==1) && !PassTrig ) continue;
        TString FinLabel = LabelList.at(il);
        FillHist("sieie"       +FinLabel, El->Full5x5_sigmaIetaIeta(), weight, 50, 0., 0.05);
        FillHist("HoverE"      +FinLabel, El->HoverE(), weight, 50, 0., 0.5);
        FillHist("dEtaIn"      +FinLabel, fabs(El->dEtaSeed()), weight, 60, 0., 0.03);
        FillHist("dPhiIn"      +FinLabel, fabs(El->dPhiIn()), weight, 40, 0., 0.2);
        FillHist("ooEooP"      +FinLabel, fabs(El->InvEminusInvP()), weight, 50, 0., 0.5);
        FillHist("PFEcalIsoEA" +FinLabel, RelEcalPFClusterIsoEA, weight, 100, 0., 1.);
        FillHist("PFHcalIsoEA" +FinLabel, RelHcalPFClusterIsoEA, weight, 100, 0., 1.);
        FillHist("PFEcalIsoEA16a" +FinLabel, RelEcalPFClusterIsoEA16a, weight, 100, 0., 1.);
        FillHist("PFHcalIsoEA16a" +FinLabel, RelHcalPFClusterIsoEA16a, weight, 100, 0., 1.);
        FillHist("PFEcalIso"   +FinLabel, El->ecalPFClusterIso()/PT, weight, 100, 0., 1.);
        FillHist("PFHcalIso"   +FinLabel, El->hcalPFClusterIso()/PT, weight, 100, 0., 1.);
        FillHist("TkIso03"     +FinLabel, El->dr03TkSumPt()/PT, weight, 50, 0., 0.5);
        FillHist("RelIso03"    +FinLabel, El->RelIso(), weight, 50, 0., 1.);
        FillHist("MiniRelIso"  +FinLabel, El->MiniRelIso(), weight, 50, 0., 1.);
        if( (il%2==0) or (PassDZTrig && PassTrig) ){
          FillHist("dz"        +FinLabel, fabs(El->dZ()), weight, 20, 0., 0.4);
          FillHist("SIP3D"     +FinLabel, El->SIP3D(), weight, 20, 0., 10.);
        }
      }
    }
  }

}



void IDOptimization::CheckIDVar_MC(vector<Muon>& MuRawColl, vector<Electron>& ElRawColl, vector<Jet>& JetRawColl, float weight, TString MuLID, TString ElLID, TString Label, TString Option)
{

  if(MuID){
    for(unsigned int it_m=0; it_m<MuRawColl.size(); it_m++){
      Muon* Mu = &MuRawColl.at(it_m);
      float PT=Mu->Pt(), fEta=fabs(Mu->Eta());
      float PTMax = Option.Contains("PtMax25")? 25:-1;
      if( PT < 10 ) continue;
      if( PTMax>0 && PT>PTMax ) continue;
      if( !Mu->PassID(MuLID) ) continue;
      if( Option.Contains("Trg") && !Mu->PassPath("HLT_Mu8_TrkIsoVVL_v") ) continue;

      int  LepType = GetLeptonType_JH(*Mu,truthColl);
      bool IsPr = LepType>0 && LepType!=3, IsHFk = LepType<0 && LepType>-5, IsExCv = LepType<-4, IsPrTa=LepType==3;
      int  MatchJetType = IsHFk? GetFakeLepSrcType(*Mu, JetRawColl):0;
      if(IsHFk){//veto EWK-tau fakes or EWK-lep intervened in ID vars.
        bool NearEWLep=false;
        for(unsigned int ij=0; ij<JetRawColl.size(); ij++){
          if(JetRawColl.at(ij).DeltaR(*Mu)>0.4) continue;
          if(HasEWLepInJet(JetRawColl.at(ij), truthColl, "InclTau")){ NearEWLep=true; break; }
        }
        if(NearEWLep) continue;
      }
      FillHist("NCnt_MuJMatch"+Label, MatchJetType, weight, 5, -1., 4.);
      if(LepType==0){ FillHist("NCntLTypeErr"+Label, 0., weight, 1, 0., 1.); continue; }
      //if(LepType==3) continue;
      if(IsHFk && MatchJetType<=0) continue; //Checked to be ignorable & irrelevant to study

      TString MuType  = IsPr? "_Pr": IsHFk? "_HFk": IsExCv? "_ExCv": IsPrTa? "_PrTa":"";
      TString EtaReg  = fEta<0.8? "_B1": fEta<1.6? "_B2": "_E"; 
      TString SrcType = MatchJetType==3? "_BjMatch": MatchJetType==2? "_CjMatch": MatchJetType==1? "_LjMatch":
                        MatchJetType==-1? "_NoMatch": "";

      vector<TString> LabelList;
      LabelList.push_back(MuType+SrcType+Label);
      LabelList.push_back(EtaReg+MuType+SrcType+Label);
      for(unsigned int il=0; il<LabelList.size(); il++){
        TString FinLabel = LabelList.at(il);
        FillHist("LeptonMVA"     +FinLabel, Mu->MVA(), weight, 40, -1., 1.);
        FillHist("MiniRelIso"    +FinLabel, Mu->MiniRelIso(), weight, 20, 0., 0.4);
        FillHist("RelIsoPF"      +FinLabel, Mu->RelIso(), weight, 20, 0., 0.4);
        FillHist("dxy"           +FinLabel, fabs(Mu->dXY()) , weight, 50, 0., 0.05);
        FillHist("dz"            +FinLabel, fabs(Mu->dZ())  , weight, 50, 0., 0.1);
        FillHist("SIP2D"         +FinLabel, Mu->SIP2D(), weight, 20, 0., 10.);
        FillHist("SIP3D"         +FinLabel, Mu->SIP3D(), weight, 20, 0., 10.);
        FillHist("h2_SIP2D_SIP3D"+FinLabel, Mu->SIP2D(), Mu->SIP3D(), weight, 20, 0., 10., 20, 0., 10.); 
      }
    }
  }
  if(ElID){
    for(unsigned int it_e=0; it_e<ElRawColl.size(); it_e++){
      Electron* El = &ElRawColl.at(it_e);
      float PT=El->Pt(), fEta=fabs(El->Eta());
      float PTMax = Option.Contains("PtMax25")? 25:-1;
      if( PT < 10 ) continue;
      if( PTMax>0 && PT>PTMax ) continue;
      if( El->etaRegion()==Electron::EtaRegion::GAP ) continue;
      if( !El->PassID(ElLID) ) continue;
      if( Option.Contains("Trg") && !El->PassFilter("hltEle8CaloIdLTrackIdLIsoVLTrackIsoFilter") ) continue;

      int  LepType = GetLeptonType_JH(*El,truthColl);
      bool IsPr = LepType>0 && LepType!=3, IsHFk = LepType<0 && LepType>-5, IsExCv = LepType<-4, IsPrTa = LepType==3;
      int  MatchJetType = IsHFk? GetFakeLepSrcType(*El, JetRawColl):0;
      if(IsHFk){//veto EWK-tau fakes or EWK-lep intervened in ID vars.
        bool NearEWLep=false;
        for(unsigned int ij=0; ij<JetRawColl.size(); ij++){
          if(JetRawColl.at(ij).DeltaR(*El)>0.4) continue;
          if(HasEWLepInJet(JetRawColl.at(ij), truthColl, "InclTau")){ NearEWLep=true; break; }
        }
        if(NearEWLep) continue;
      }
      FillHist("NCnt_ElJMatch"+Label, MatchJetType, weight, 5, -1., 4.);
      if(LepType==0){ FillHist("NCntLTypeErr"+Label, 0., weight, 1, 0., 1.); continue; }
      //if(LepType==3) continue;
      if(IsHFk && MatchJetType<=0) continue; //Checked to be ignorable & irrelevant to study

      int   TightQPass = El->IsGsfCtfScPixChargeConsistent()? 1:0;      
      TString ElType  = IsPr? "_Pr": IsHFk? "_HFk": IsExCv? "_ExCv": IsPrTa? "_PrTa":"";
      TString EtaReg  = fEta<0.8? "_B1": fEta<1.479? "_B2": "_E"; 
      TString SrcType = MatchJetType==3? "_BjMatch": MatchJetType==2? "_CjMatch": MatchJetType==1? "_LjMatch":
                        MatchJetType==-1? "_NoMatch": "";

      vector<TString> LabelList;
      LabelList.push_back(ElType+SrcType+Label);
      LabelList.push_back(EtaReg+ElType+SrcType+Label);
      for(unsigned int il=0; il<LabelList.size(); il++){
        TString FinLabel = LabelList.at(il);
        FillHist("MVAIso"        +FinLabel, El->MVAIso(), weight, 40, -1., 1.);
        FillHist("MVANoIso"      +FinLabel, El->MVANoIso(), weight, 40, -1., 1.);
        FillHist("RelIso03"      +FinLabel, El->RelIso(), weight, 20, 0., 0.4);
        FillHist("MiniRelIso"    +FinLabel, El->MiniRelIso(), weight, 20, 0., 0.4);
        FillHist("dxy"           +FinLabel, fabs(El->dXY()) , weight, 50, 0., 0.05);
        FillHist("dz"            +FinLabel, fabs(El->dZ())  , weight, 50, 0., 0.1);
        FillHist("SIP2D"         +FinLabel, El->SIP2D(), weight, 20, 0., 10.);
        FillHist("SIP3D"         +FinLabel, El->SIP3D(), weight, 20, 0., 10.);
        FillHist("h2_SIP2D_SIP3D"+FinLabel, El->SIP2D(), El->SIP3D(), weight, 20, 0., 10., 20, 0., 10.); 
        FillHist("NMissHits"     +FinLabel, El->NMissingHits(), weight, 10, 0., 10.);    
        FillHist("TightQ"        +FinLabel, TightQPass, weight, 2, 0., 2.);
      }
    }
  }
}


void IDOptimization::executeEventFromParameter(AnalyzerParameter param){

  if(!PassMETFilter()) return;

  Event ev = GetEvent();

}

IDOptimization::IDOptimization(){

}

IDOptimization::~IDOptimization(){

}


