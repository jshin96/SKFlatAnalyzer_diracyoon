#include "DiLepValid.h"

void DiLepValid::initializeAnalyzer(){

  SglLTrig=false, DiLTrig=false, ElEl=false, MuMu=false, ElMu=false; 
  HEMCheck=false, SystRun=false;
  for(unsigned int i=0; i<Userflags.size(); i++){
    if(Userflags.at(i).Contains("SglLTrig")) SglLTrig = true; 
    if(Userflags.at(i).Contains("DiLTrig" )) DiLTrig  = true; 
    if(Userflags.at(i).Contains("ElEl"    )) ElEl     = true; 
    if(Userflags.at(i).Contains("MuMu"    )) MuMu     = true; 
    if(Userflags.at(i).Contains("ElMu"    )) ElMu     = true; 
    if(Userflags.at(i).Contains("HEMCheck")) HEMCheck = true;
    if(Userflags.at(i).Contains("SystRun" )) SystRun  = true; 
  }

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
      TrigList_DiMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v", "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v", "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v"};
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
    else if(ElEl){ TrigList = TrigList_DiEl; SFKey_Trig="DiElIso_HNTopID17SS"; }
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
    w_GenNorm = ev.MCweight()*weight_norm_1invpb*GetKFactor()*ev.GetTriggerLumi("Full");
    w_BR      = GetBRWeight();
    w_PU      = GetPileUpWeight(nPileUp, 0);
    weight *= w_GenNorm * w_BR * w_PU;
  }

  if(!ev.PassTrigger(TrigList)) return;
  if(!PassMETFilter()) return;

  bool PreCutPass=false;
  vector<Muon>     muonPreColl     = GetMuons("NOCUT", 8., 2.4);
  vector<Electron> electronPreColl = GetElectrons("NOCUT", 8., 2.5);
  sort(muonPreColl.begin(), muonPreColl.end(), PtComparing);
  sort(electronPreColl.begin(), electronPreColl.end(), PtComparing);
  if(ElEl and electronPreColl.size()>1) PreCutPass=true;
  if(MuMu and muonPreColl.size()>1    ) PreCutPass=true;
  if(ElMu and electronPreColl.size()>0 && muonPreColl.size()>0) PreCutPass=true;
  if(!PreCutPass) return;

  //TString MuTID = "POGMIDTIso", MuLID = "POGMIDVVLIso";
  TString MuTID = "TopHNT", MuLID = "TopHNLLIsop6SIP5";
  TString ElTID = "TopHN17SST", ElLID = "TopHNSSNM01LFixLMVAIsop4NoSIP_"+GetEraShort(), ElVID = "TopHNV";  
  float PTminEl = ElTID.Contains("SS")? 15.:10.;
  vector<Muon>     muonTightColl     = SelectMuons(muonPreColl, MuTID, 10., 2.4);
  vector<Electron> electronTightColl = SelectElectrons(electronPreColl, ElTID, PTminEl, 2.5);
  vector<Muon>     muonLooseColl     = SelectMuons(muonPreColl, MuLID, 10., 2.4);
  vector<Electron> electronLooseColl = SelectElectrons(electronPreColl, ElLID, PTminEl, 2.5);
  vector<Electron> electronVetoColl  = SelectElectrons(electronPreColl, ElVID, 10., 2.5);


  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
  vector<Jet> jetNoVetoColl  = GetJets("tight", 25., 2.4);
  sort(jetNoVetoColl.begin(), jetNoVetoColl.end(), PtComparing);
  vector<Jet> bjetNoVetoColl = SelBJets(jetNoVetoColl, param_jets);
  vector<Jet> jetColl  = JetsVetoLeptonInside(jetNoVetoColl, electronVetoColl, muonLooseColl, 0.4);
  vector<Jet> bjetColl = SelBJets(jetColl, param_jets);


  Particle vMET = ev.GetMETVector();
  Particle vMET_T1xy = GetvMET("T1xyCorr");


  vector<Gen> truthColl;


  bool EventCand = false;
  float w_topptrw = 1., w_prefire = 1., sf_trig = 1.;
  float sf_mutk = 1., sf_muid = 1., sf_muiso = 1., sf_elreco = 1., sf_elid = 1., sf_btag = 1.;
  if(MuMu){ EventCand = muonLooseColl.size()>1; }
  if(ElEl){ EventCand = electronLooseColl.size()>1; }
  if(ElMu){ EventCand = electronLooseColl.size()>0 && muonLooseColl.size()>0; }
  if((!IsDATA) and EventCand){
    if(MCSample.Contains("TT") and MCSample.Contains("powheg")){ truthColl = GetGens(); w_topptrw = mcCorr->GetTopPtReweight(truthColl); }
    w_prefire = GetPrefireWeight(0);
    sf_muid   = GetMuonSF(muonTightColl, MuTID, "ID");
    //sf_muid   = GetMuonSF(muonTightColl, "NUM_MediumID_DEN_TrackerMuons", "ID")*GetMuonSF(muonTightColl, "TopHNTIsoIP_POGMID", "ISO");
    //sf_muid   = GetMuonSF(muonTightColl, "NUM_MediumID_DEN_TrackerMuons", "ID")*GetMuonSF(muonTightColl, "NUM_TightRelIso_DEN_MediumID", "ISO");
    sf_elreco = GetElectronSF(electronTightColl, "", "Reco");
    sf_elid   = GetElectronSF(electronTightColl, ElTID, "ID");
    sf_btag   = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets);
    sf_trig   = mcCorr->GetTriggerSF(electronTightColl, muonTightColl, SFKey_Trig, "");
    //cout<<"w_prefire:"<<w_prefire<<" sf_trig:"<<sf_trig<<endl;
    //cout<<"sf_mutk"<<sf_mutk<<" sf_muid:"<<sf_muid<<" sf_muiso:"<<sf_muiso<<" sf_elreco:"<<sf_elreco<<" sf_elid:"<<sf_elid<<" sf_btag:"<<sf_btag<<endl;
  }
  weight *= w_topptrw * w_prefire * sf_trig;
  weight *= sf_mutk * sf_muid * sf_muiso * sf_elreco * sf_elid * sf_btag;

 
  if(MuMu){
    if(HEMCheck){
      CheckHEMIssue(muonTightColl, muonLooseColl, electronTightColl, electronLooseColl, jetColl, bjetColl, vMET_T1xy, weight, "", "");
    }
    else{
      AnalyzeDiMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, weight, "");
      AnalyzeDiMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, w_GenNorm, "_NoW");
      AnalyzeDiMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, w_GenNorm*w_prefire, "_Pref");
      AnalyzeDiMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, w_GenNorm*w_prefire*w_PU, "_PrefPU");
      AnalyzeDiMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, w_GenNorm*w_prefire*w_PU*sf_muid*sf_muiso, "_PrefPUID");
      AnalyzeDiMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, w_GenNorm*w_prefire*w_PU*sf_muid*sf_muiso*sf_trig, "_PrefPUIDTrig");
    }
  }
  if(ElEl){
    if(HEMCheck){
      CheckHEMIssue(muonTightColl, muonLooseColl, electronTightColl, electronLooseColl, jetColl, bjetColl, vMET_T1xy, weight, "", "");
    }
    else{
      AnalyzeDiElectron(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, weight, "");
      AnalyzeDiElectron(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, w_GenNorm, "_NoW");
      AnalyzeDiElectron(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, w_GenNorm*w_prefire, "_Pref");
      AnalyzeDiElectron(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, w_GenNorm*w_prefire*w_PU, "_PrefPU");
      AnalyzeDiElectron(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, w_GenNorm*w_prefire*w_PU*sf_elreco, "_PrefPUReco");
      AnalyzeDiElectron(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, w_GenNorm*w_prefire*w_PU*sf_elreco*sf_elid, "_PrefPURecoID");
      AnalyzeDiElectron(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET, w_GenNorm*w_prefire*w_PU*sf_elreco*sf_elid*sf_trig, "_PrefPURecoIDTrig");
    }
  }
  if(ElMu){
    if(HEMCheck){
      CheckHEMIssue(muonTightColl, muonLooseColl, electronTightColl, electronLooseColl, jetColl, bjetColl, vMET_T1xy,
                    weight, "", "");
    }
    else{
      AnalyzeElectronMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET_T1xy,
                          weight, "");
      AnalyzeElectronMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET,
                          w_GenNorm, "_NoW");
      AnalyzeElectronMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET,
                          w_GenNorm*w_prefire, "_Pref");
      AnalyzeElectronMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET,
                          w_GenNorm*w_prefire*w_PU, "_PrefPU");
      AnalyzeElectronMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET,
                          w_GenNorm*w_prefire*w_PU*sf_muid*sf_muiso*sf_trig, "_PrefPUIDTrigMu");
      AnalyzeElectronMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET,
                          w_GenNorm*w_prefire*w_PU*sf_muid*sf_muiso*sf_elreco*sf_elid*sf_trig, "_PrefPUIDTrigMuEl");
      AnalyzeElectronMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET_T1xy,
                          w_GenNorm*w_prefire*w_PU*sf_muid*sf_muiso*sf_elreco*sf_elid*sf_trig, "_PrefPUIDTrigMuElMETPhi");
      AnalyzeElectronMuon(muonTightColl, muonLooseColl, electronTightColl, electronVetoColl, jetColl, bjetColl, vMET_T1xy,
                          w_GenNorm*w_prefire*w_PU*sf_muid*sf_muiso*sf_elreco*sf_elid*sf_trig*sf_btag, "_PrefPUIDTrigMuElMETPhiBTag");
    }
  }

}


void DiLepValid::AnalyzeDiMuon(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl,
                               vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{
  if( !(MuTColl.size()==2 && MuLColl.size()==2) ) return;
  if( ElLColl.size()!=0 ) return;
  if( MuTColl.at(0).Charge() == MuTColl.at(1).Charge() ) return;

  float PTmin1 = 10., PTmin2 = 10.;
  if     (SglLTrig){ PTmin1 = DataYear==2017? 29.:26.; PTmin2 = 10.; }
  else if(DiLTrig ){ PTmin1 = 20., PTmin2 = 10.; }
  if( !(MuTColl.at(0).Pt()>PTmin1 && MuTColl.at(1).Pt()>PTmin2) ) return; 
  
  float Mmumu = (MuTColl.at(0)+MuTColl.at(1)).M();
  if(Mmumu<50) return;
       
  FillHist("NCount"+Label, 0., weight, 1, 0., 1.);
  FillHist("NPV"   +Label, nPV, weight, 80, 0., 80.);
  FillHist("Rho"   +Label, Rho, weight, 70, 0., 70.);
  FillHist("Mmumu" +Label, Mmumu, weight, 60, 60., 120.);
  FillHist("PtMu1" +Label, MuTColl.at(0).Pt(), weight, 40, 0., 200.);
  FillHist("PtMu2" +Label, MuTColl.at(1).Pt(), weight, 40, 0., 200.);
  FillHist("EtaMu1"+Label, MuTColl.at(0).Eta(), weight, 20, -5., 5.);
  FillHist("EtaMu2"+Label, MuTColl.at(1).Eta(), weight, 20, -5., 5.);
  FillHist("NJet"  +Label, JetColl.size(), weight, 10, 0., 10.);
  FillHist("NBJet" +Label, BJetColl.size(), weight, 10, 0., 10.);
  FillHist("MET"   +Label, vMET.Pt(), weight, 40, 0., 200.);

  float HT=0; for(unsigned int itj=0; itj<JetColl.size(); itj++){ HT+=JetColl.at(itj).Pt(); }
  float ST=HT+vMET.Pt()+MuTColl.at(0).Pt()+MuTColl.at(1).Pt();
  float MET2ST=pow(vMET.Pt(),2.)/ST;
  float MET2HT=HT==0? 0.:pow(vMET.Pt(),2.)/HT;
  FillHist("ST"+Label, ST, weight, 60, 0., 300.);
  FillHist("HT"+Label, HT, weight, 40, 0., 200.);
  FillHist("MET2ST"+Label, MET2ST, weight, 40, 0., 200.);
  FillHist("MET2HT"+Label, MET2HT, weight, 40, 0., 200.);

} 


void DiLepValid::AnalyzeDiElectron(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl,
                                   vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{
  if( !(ElTColl.size()==2 && ElLColl.size()==2) ) return;
  if( MuLColl.size()!=0 ) return;
  if( ElTColl.at(0).Charge() == ElTColl.at(1).Charge() ) return;

  float PTmin1 = 10., PTmin2 = 10.;
  if     (SglLTrig){ PTmin1 = DataYear==2016? 30.:35.; PTmin2 = 10.; }
  else if(DiLTrig ){ PTmin1 = 25., PTmin2 = 15.; }
  if( !(ElTColl.at(0).Pt()>PTmin1 && ElTColl.at(1).Pt()>PTmin2) ) return; 

  float Melel = (ElTColl.at(0)+ElTColl.at(1)).M();
  if(Melel<50) return;

  FillHist("NCount"+Label, 0., weight, 1, 0., 1.);
  FillHist("NPV"   +Label, nPV, weight, 80, 0., 80.);
  FillHist("Rho"   +Label, Rho, weight, 70, 0., 70.);
  FillHist("Melel" +Label, Melel, weight, 60, 60., 120.);
  FillHist("PtEl1" +Label, ElTColl.at(0).Pt(), weight, 40, 0., 200.);
  FillHist("PtEl2" +Label, ElTColl.at(1).Pt(), weight, 40, 0., 200.);
  FillHist("EtaEl1"+Label, ElTColl.at(0).Eta(), weight, 20, -5., 5.);
  FillHist("EtaEl2"+Label, ElTColl.at(1).Eta(), weight, 20, -5., 5.);
  FillHist("NJet"  +Label, JetColl.size(), weight, 10, 0., 10.);
  FillHist("NBJet" +Label, BJetColl.size(), weight, 10, 0., 10.);
  FillHist("MET"   +Label, vMET.Pt(), weight, 40, 0., 200.);

}


void DiLepValid::AnalyzeElectronMuon(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl,
                                     vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)

{
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


  FillHist("NCount"+Label, 0., weight, 1, 0., 1.);
  FillHist("NPV"+Label, nPV, weight, 80, 0., 80.);
  FillHist("Rho"+Label, Rho, weight, 70, 0., 70.);
  FillHist("PtMu1" +Label, MuTColl.at(0).Pt(), weight, 30, 0., 300.);
  FillHist("PtEl1" +Label, ElTColl.at(0).Pt(), weight, 30, 0., 300.);
  FillHist("PtJet1"+Label, JetColl.at(0).Pt(), weight, 50, 0., 500.);
  FillHist("PtJet2"+Label, JetColl.at(1).Pt(), weight, 40, 0., 400.);
  FillHist("EtaMu1"+Label, MuTColl.at(0).Eta(), weight, 20, -5., 5.);
  FillHist("EtaEl1"+Label, ElTColl.at(0).Eta(), weight, 20, -5., 5.);
  FillHist("EtaJet1"+Label, JetColl.at(0).Eta(), weight, 20, -5., 5.);
  FillHist("EtaJet2"+Label, JetColl.at(1).Eta(), weight, 20, -5., 5.);
  FillHist("MET"   +Label, vMET.Pt(), weight, 40, 0., 400.);
  FillHist("METPhi"+Label, vMET.Phi(), weight, 10, -3.15, 3.15);
  FillHist("NJet"  +Label, JetColl.size(), weight, 10, 0., 10.);
  FillHist("NBJet" +Label, BJetColl.size(), weight, 10, 0., 10.);
  FillHist("dRElMu"+Label, MuTColl.at(0).DeltaR(ElTColl.at(0)), weight, 50, 0., 5.);

  float HT=0; for(unsigned int itj=0; itj<JetColl.size(); itj++){ HT+=JetColl.at(itj).Pt(); }
  float ST=HT+vMET.Pt()+MuTColl.at(0).Pt()+ElTColl.at(0).Pt();
  float MET2ST=pow(vMET.Pt(),2.)/ST;
  float MET2HT=pow(vMET.Pt(),2.)/HT;
  FillHist("ST"+Label, ST, weight, 48, 0., 1200.);
  FillHist("HT"+Label, HT, weight, 32, 0., 800.);
  FillHist("MET2ST"+Label, MET2ST, weight, 12, 0., 120.);
  FillHist("MET2HT"+Label, MET2HT, weight, 30, 0., 300.);

}


void DiLepValid::CheckHEMIssue(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl,
                               vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label, TString Option)
{

  if(DataYear!=2018) return;

  if(MuMu){
    if( !(MuTColl.size()==2 && MuLColl.size()==2) ) return;
    if( ElLColl.size()!=0 ) return;
    if( DataYear==2016 or DataYear==2018 ){ if(MuTColl.at(0).Pt()<26) return; }
    else{                                   if(MuTColl.at(0).Pt()<29) return; }
    if( MuTColl.at(0).Charge() == MuTColl.at(1).Charge() ) return;
    float Mmumu = (MuTColl.at(0)+MuTColl.at(1)).M();
    if(Mmumu<50) return;

    const int NEtaEdges=5, NPhiEdges=9;
    double EtaEdges_p[NEtaEdges]={0., 0.6, 1.3, 1.9, 2.5};
    double PhiEdges[NPhiEdges]={-3.15, -2.4, -1.6, -0.8, 0., 0.8, 1.6, 2.4, 3.15};
    float mu2_feta=fabs(MuTColl.at(1).Eta()), mu2_phi = MuTColl.at(1).Phi();

    if(mu2_feta>0){ FillHist("Mu2_fEtaPhi_p"+Label, mu2_feta, mu2_phi, weight, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges); }
    else{           FillHist("Mu2_fEtaPhi_m"+Label, mu2_feta, mu2_phi, weight, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges); }

    if(IsDATA && IsHEMIssueRun()){
      if(mu2_feta>0){ FillHist("Mu2_fEtaPhi_p_HEMRun"+Label, mu2_feta, mu2_phi, weight, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges); }
      else{           FillHist("Mu2_fEtaPhi_m_HEMRun"+Label, mu2_feta, mu2_phi, weight, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges); }
    }
  }
  if(ElEl){
    if( !(ElTColl.size()==2 && ElLColl.size()==2) ) return;
    if( MuLColl.size()!=0 ) return;
    if( ElTColl.at(0).Charge() == ElTColl.at(1).Charge() ) return;
    if( DataYear==2016 ){ if(ElTColl.at(0).Pt()<30) return; }
    else                { if(ElTColl.at(0).Pt()<35) return; }
    if( !(fabs(ElTColl.at(0).Eta())<2.5 && fabs(ElTColl.at(1).Eta())<2.5) ) return;
    float Melel = (ElTColl.at(0)+ElTColl.at(1)).M();
    if(Melel<50) return;

    const int NEtaEdges=5, NPhiEdges=9;
    double EtaEdges_p[NEtaEdges]={0., 0.6, 1.3, 1.9, 2.5};
    double PhiEdges[NPhiEdges]={-3.15, -2.4, -1.6, -0.8, 0., 0.8, 1.6, 2.4, 3.15};
    float el2_feta=fabs(ElTColl.at(1).Eta()), el2_phi = ElTColl.at(1).Phi();
    if(el2_feta>0){ FillHist("El2_fEtaPhi_p"+Label, el2_feta, el2_phi, weight, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges); }
    else{         FillHist("El2_fEtaPhi_m"+Label, el2_feta, el2_phi, weight, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges); }
    if(IsDATA && IsHEMIssueRun()){
      if(el2_feta>0){ FillHist("El2_fEtaPhi_p_HEMRun"+Label, el2_feta, el2_phi, weight, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges); }
      else{           FillHist("El2_fEtaPhi_m_HEMRun"+Label, el2_feta, el2_phi, weight, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges); }
    }
  }
  if(ElMu){
    if( !(ElTColl.size()==1 && ElLColl.size()==1) ) return;
    if( !(MuTColl.size()==1 && MuLColl.size()==1) ) return;
    if( !(JetColl.size()>1 && BJetColl.size()>0) ) return;
    if( MuTColl.at(0).Charge() == ElTColl.at(0).Charge() ) return;
    if( fabs(ElTColl.at(0).Eta())>2.5 ) return;
    if( MuTColl.at(0).DeltaR(ElTColl.at(0))<0.4 ) return;
    if( DataYear==2016 or DataYear==2018 ){ if(MuTColl.at(0).Pt()<26) return; }
    else{                                   if(MuTColl.at(0).Pt()<29) return; }

    const int NEtaEdges=5, NPhiEdges=9;
    double EtaEdges_p[NEtaEdges]={0., 0.6, 1.3, 1.9, 2.5};
    double PhiEdges[NPhiEdges]={-3.15, -2.4, -1.6, -0.8, 0., 0.8, 1.6, 2.4, 3.15};
    for(unsigned int it_j=0; it_j<JetColl.size(); it_j++){
      float j_pt = JetColl.at(it_j).Pt(), j_eta = JetColl.at(it_j).Eta();
      float j_phi = JetColl.at(it_j).Phi(), j_feta = fabs(j_eta);
      if( (IsDATA && IsHEMIssueRun()) or (!IsDATA) ){
        if(IsHEMIssueReg(JetColl.at(it_j))){
          FillHist("CHEF_HEMReg" +Label, JetColl.at(it_j).GetIDVariable("CHEF"), weight, 20, 0., 1.);
          FillHist("NHEF_HEMReg" +Label, JetColl.at(it_j).GetIDVariable("NHEF"), weight, 20, 0., 1.);
          FillHist("CEMEF_HEMReg"+Label, JetColl.at(it_j).GetIDVariable("CEMEF"), weight, 20, 0., 1.);
          FillHist("NEMEF_HEMReg"+Label, JetColl.at(it_j).GetIDVariable("NEMEF"), weight, 20, 0., 1.);
          FillHist("MuEF_HEMReg" +Label, JetColl.at(it_j).GetIDVariable("MuEF"), weight, 20, 0., 1.);
          FillHist("CMult_HEMReg"+Label, JetColl.at(it_j).GetIDVariable("CMult"), weight, 25, 0., 50.);
          FillHist("NMult_HEMReg"+Label, JetColl.at(it_j).GetIDVariable("NMult"), weight, 25, 0., 50.);
        }
        else if(IsHEMCRReg(JetColl.at(it_j), "SameEta") or IsHEMCRReg(JetColl.at(it_j), "SamePhi")){
          FillHist("CHEF_NonHEMReg" +Label, JetColl.at(it_j).GetIDVariable("CHEF"), weight, 20, 0., 1.);
          FillHist("NHEF_NonHEMReg" +Label, JetColl.at(it_j).GetIDVariable("NHEF"), weight, 20, 0., 1.);
          FillHist("CEMEF_NonHEMReg"+Label, JetColl.at(it_j).GetIDVariable("CEMEF"), weight, 20, 0., 1.);
          FillHist("NEMEF_NonHEMReg"+Label, JetColl.at(it_j).GetIDVariable("NEMEF"), weight, 20, 0., 1.);
          FillHist("MuEF_NonHEMReg" +Label, JetColl.at(it_j).GetIDVariable("MuEF"), weight, 20, 0., 1.);
          FillHist("CMult_NonHEMReg"+Label, JetColl.at(it_j).GetIDVariable("CMult"), weight, 25, 0., 50.);
          FillHist("NMult_NonHEMReg"+Label, JetColl.at(it_j).GetIDVariable("NMult"), weight, 25, 0., 50.);
        }
      }


      if(j_eta>0){ FillHist("Nj_fEtaPhi_p" +Label, j_feta, j_phi, weight, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
                   FillHist("Ptj_fEtaPhi_p"+Label, j_feta, j_phi, weight*j_pt, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
      }
      else{        FillHist("Nj_fEtaPhi_m" +Label, j_feta, j_phi, weight, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
                   FillHist("Ptj_fEtaPhi_m"+Label, j_feta, j_phi, weight*j_pt, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
      }
      if(IsDATA && IsHEMIssueRun()){
        if(j_eta>0){ FillHist("Nj_fEtaPhi_p_HEMRun"+Label, j_feta, j_phi, weight, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
                     FillHist("Ptj_fEtaPhi_p_HEMRun"+Label, j_feta, j_phi, weight*j_pt, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
        }
        else{        FillHist("Nj_fEtaPhi_m_HEMRun"+Label, j_feta, j_phi, weight, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
                     FillHist("Ptj_fEtaPhi_m_HEMRun"+Label, j_feta, j_phi, weight*j_pt, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
        }
      }
      else if(IsDATA && !IsHEMIssueRun()){
        if(j_eta>0){ FillHist("Nj_fEtaPhi_p_NonHEMRun"+Label, j_feta, j_phi, weight, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
                     FillHist("Ptj_fEtaPhi_p_NonHEMRun"+Label, j_feta, j_phi, weight*j_pt, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
        }
        else{        FillHist("Nj_fEtaPhi_m_NonHEMRun"+Label, j_feta, j_phi, weight, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
                     FillHist("Ptj_fEtaPhi_m_NonHEMRun"+Label, j_feta, j_phi, weight*j_pt, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
        }
      }
    }//End of jet loop
    for(unsigned int it_b=0; it_b<BJetColl.size(); it_b++){
      float b_pt=BJetColl.at(it_b).Pt(), b_eta=BJetColl.at(it_b).Eta();
      float b_feta=fabs(b_eta), b_phi = BJetColl.at(it_b).Phi();
      if(b_eta>0){ FillHist("Nb_fEtaPhi_p"+Label, b_feta, b_phi, weight, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
                   FillHist("Ptb_fEtaPhi_p"+Label, b_feta, b_phi, weight*b_pt, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
      }
      else{        FillHist("Nb_fEtaPhi_m"+Label, b_feta, b_phi, weight, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
                   FillHist("Ptb_fEtaPhi_m"+Label, b_feta, b_phi, weight*b_pt, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
      }
      if(IsDATA && IsHEMIssueRun()){
        if(b_eta>0){ FillHist("Nb_fEtaPhi_p_HEMRun"+Label, b_feta, b_phi, weight, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
                     FillHist("Ptb_fEtaPhi_p_HEMRun"+Label, b_feta, b_phi, weight*b_pt, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
        }
        else{        FillHist("Nb_fEtaPhi_m_HEMRun"+Label, b_feta, b_phi, weight, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
                     FillHist("Ptb_fEtaPhi_m_HEMRun"+Label, b_feta, b_phi, weight*b_pt, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
        }
      }
      else if(IsDATA && !IsHEMIssueRun()){
        if(b_eta>0){ FillHist("Nb_fEtaPhi_p_NonHEMRun"+Label, b_feta, b_phi, weight, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
                     FillHist("Ptb_fEtaPhi_p_NonHEMRun"+Label, b_feta, b_phi, weight*b_pt, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
        }
        else{        FillHist("Nb_fEtaPhi_m_NonHEMRun"+Label, b_feta, b_phi, weight, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
                     FillHist("Ptb_fEtaPhi_m_NonHEMRun"+Label, b_feta, b_phi, weight*b_pt, NEtaEdges-1, EtaEdges_p, NPhiEdges-1, PhiEdges);
        }
      }
    }//End of b-jet loop
  }//End of ElMu

}


void DiLepValid::executeEventFromParameter(AnalyzerParameter param){

  if(!PassMETFilter()) return;

  Event ev = GetEvent();

}

DiLepValid::DiLepValid(){

}

DiLepValid::~DiLepValid(){

}


