#include "HNL_SignalStudies.h"

void HNL_SignalStudies::initializeAnalyzer(){

  std::vector<JetTagging::Parameters> jtps;
  //  jtps.push_back( JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Loose, JetTagging::incl, JetTagging::comb) );
  //jtps.push_back( JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets) );
  //jtps.push_back( JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Tight, JetTagging::incl, JetTagging::comb) );

  jtps.push_back( JetTagging::Parameters(JetTagging::DeepCSV, JetTagging::Loose, JetTagging::incl, JetTagging::comb) );
  jtps.push_back( JetTagging::Parameters(JetTagging::DeepCSV, JetTagging::Medium, JetTagging::incl, JetTagging::comb) );
  jtps.push_back( JetTagging::Parameters(JetTagging::DeepCSV, JetTagging::Tight, JetTagging::incl, JetTagging::comb) );


  if(DataYear==2016){ 
    
    Trigger_HNL_Muon = {
      "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v", 
      "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v",
      "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v",
      "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v"
    };
    Trigger_HNL_MuonH = {
      "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v",
      "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v"
    };                 // 35918.219492947
  
  }  // END OF 2016 Triggers
  else if(DataYear==2017){
    Trigger_HNL_Muon = {
      "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v",
      "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v",
      "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_v"
    };
      
  } // end of 2017 triggers
  else if(DataYear==2018){
    
    Trigger_HNL_Muon = {
      "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v"
    };
    

  } // end of 20


  //--- Method 1d using JetTagging::iterativefit needs csv file changing in histmap to run
  // jtps.push_back( JetTagging::Parameters(JetTagging::DeepCSV, JetTagging::Medium, JetTagging::iterativefit, JetTagging::iterativefit) );
  mcCorr->SetJetTaggingParameters(jtps);

  //====== reduce branches to speed up processing                                                                                                                                      
  if(fChain->GetListOfFiles()->GetEntries()){
    TString filename=fChain->GetListOfFiles()->At(0)->GetTitle();
    if(filename.Contains("Run2UltraLegacy_v2")) IsUL=true;
    else IsUL=false;
  }else{
    cout<<"[AFBAnalyzer::initializeAnalyzer] no input file"<<endl;
    exit(EXIT_FAILURE);
  }


  

}




void HNL_SignalStudies::executeEvent(){

  FillHist ("NoCut", 1, 1, 2, 0., 2.,"");
  
  //==== Gen for genmatching

  TString process="";
  if(!IsData){
    gens = GetGens();
    
    process = GetProcess();

    vector<TString> labels ={"Inclusive","OS_ElEl", "SS_El-El-", "SS_El+El+","OS_MuMu", "SS_Mu-Mu-" , "SS_Mu+Mu+","OS_ElMu","SS_El-Mu-" ,"SS_El+Mu+", "OS_MuEl","SS_Mu-El-","SS_Mu+El+"};

    HNL_LeptonCore::FillEventCutflowAll("SignalProcess","SplitChannel",MCweight(true,true), labels, process);
    HNL_LeptonCore::FillEventCutflowAll("SignalProcess","SplitChannel",MCweight(true,true), labels, "Inclusive");
    

    if(_jentry% 10000==0){
      cout << "process = " << process << endl;
      
      PrintGen(gens);
    }


  }
  else{
    if(this->DataStream == "SingleMuon") process = "MuMu";
    else if(this->DataStream == "DoubleMuon") process = "MuMu";
    else if(this->DataStream == "MuonEG") process = "EMu";
    else process = "EE";
  }
  
  
  RunSignalPlotter(process);
}

void HNL_SignalStudies::RunSignalPlotter(TString process){


  AnalyzerParameter param  ;
  param.Clear();

  param.syst_ = AnalyzerParameter::Central;
  param.Name  = "SignalStudy";

  param.MCCorrrectionIgnoreNoHist = false;

  param.Jet_ID                     = "tight";
  param.FatJet_ID                  = "tight";
  param.BJet_Method                = "2a";




  //************************************************/// 
  // setup vector of all objects
  //************************************************///
  AllJets      = GetAllJets();
  AllFatJets   = puppiCorr->Correct(GetAllFatJets());

  
  double weight(1.);

  Event ev = GetEvent();

  //=== Apply MC weight
  if(!IsDATA){
    double this_mc_weight = ev.GetTriggerLumi("Full") * MCweight(true, true) * GetKFactor();
    weight     *=  this_mc_weight;
    FillWeightHist("MCWeight_" ,MCweight(true, true));
    FillWeightHist("MCFullWeight_" , this_mc_weight);
    
  }

  
  // HL ID
  std::vector<Electron>   myelectrons = GetElectrons( "HNTightV2", 10., 2.5);
  std::vector<Muon>       mymuons     = GetMuons    ( "HNTightV2", 5., 2.4);

  // EXO17028 ID
  
  std::vector<Electron>   myelectrons_js = GetElectrons("HNTight_17028", 10., 2.5);  
  std::vector<Muon>       mymuons_js     = GetMuons    ("HNTight_17028", 5., 2.4);


  std::vector<Electron>   vetoelectrons = GetElectrons("HNVeto2016", 10., 2.5); 
  std::vector<Muon>       vetomuons     = GetMuons    ("HNVeto2016", 5., 2.4);

  std::vector<Tau>        mytaus      = GetTaus("HNVeto",20., 2.3); 
  std::vector<Tau>        alltaus     = GetTaus("NoCut", 20., 2.3);
  

  vector<FatJet>   this_AllFatJets   = AllFatJets;

  std::vector<FatJet>   fatjets_tmp  = SelectFatJets(this_AllFatJets, param.FatJet_ID, 200, 5.);
  std::vector<Jet>      jets_tmp     = GetJets   ( param.Jet_ID,    15., 5.);

  std::vector<FatJet> fatjets                  = GetAK8Jets(fatjets_tmp, 200., 2.7, true,  1., true, -999, true, 40., 130., vetoelectrons, vetomuons);
  std::vector<FatJet> fatjets_notag            = GetAK8Jets(fatjets_tmp, 200., 2.7, true,  1., false, -999, true, 40., 130., vetoelectrons, vetomuons);
  std::vector<Jet> jets                        = GetAK4Jets(jets_tmp,     20., 2.7, true,  0.4,0.8,"loose",        vetoelectrons, vetomuons,fatjets);
  std::vector<Jet> vbf_jets                    = GetAK4Jets(jets_tmp,     30., 4.7, true,  0.4,0.8,"loose",   vetoelectrons, vetomuons,fatjets);

  if (IsData || ( process.Contains("Mu+Mu+") or   process.Contains("Mu-Mu-") )){
    RunMuonChannel(myelectrons,vetoelectrons, mymuons,vetomuons, mytaus, jets, vbf_jets, fatjets,ev, param, weight );

    param.Name = param.Name + "_LAK8";
    RunMuonChannel(myelectrons,vetoelectrons, mymuons,vetomuons, mytaus, jets, vbf_jets, fatjets_notag,ev, param, weight );
    
  }

}


void HNL_SignalStudies::RunMuonChannel(std::vector<Electron> ElectronColl, std::vector<Electron> VetoElectronColl, std::vector<Muon> MuonColl,  std::vector<Muon> VetoMuonColl, std::vector<Tau> TauColl,  std::vector<Jet> JetColl, std::vector<Jet> VBFJetColl,  std::vector<FatJet> FatjetColl,  Event Ev, AnalyzerParameter param,  float _weight)   {

  Particle METUnsmearedv = Ev.GetMETVector();
  Particle METv =UpdateMETSmearedJet(METUnsmearedv, JetColl);

  if(IsData && ! DataStream.Contains("DoubleMuon")) return;


  std::vector<Lepton *> leps       = MakeLeptonPointerVector(MuonColl,ElectronColl);
  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(VetoMuonColl,VetoElectronColl);

  
  int njets =  (VBFJetColl.size() + FatjetColl.size()) ;
  if( int(JetColl.size() + FatjetColl.size()) > njets) njets = JetColl.size() + FatjetColl.size();
  
  bool dijet = (FatjetColl.size() > 0) || (JetColl.size() > 1);

  
  int  NBJets_medium      =  GetNBJets2a("tight","Medium");
  bool PassBJetMVeto = (NBJets_medium==0);
  
  param.Name = "MuonChannelSignals_"+param.Name;
  FillEventCutflow(sigmm,_weight, "SSNoCut", param.Name);
  FillEventCutflow(sigmm_17028,_weight, "SSNoCut", param.Name);
  
  // UL ANALYSIS
  
  if(!IsData){
    
    
    vector<Gen> gen_lep= GetGenLepronsSignal();
    std::sort(gen_lep.begin(),   gen_lep.end(),        PtComparing);

    if(gen_lep.size() == 2){
      if( (fabs(gen_lep[0].Eta()) < 2.4 && gen_lep[0].Pt() > 20) &&
	  (fabs(gen_lep[1].Eta()) < 2.4 && gen_lep[1].Pt() > 10)){
	FillEventCutflow(sigmm,_weight, "SSGen", param.Name);
	FillEventCutflow(sigmm_17028,_weight, "SSGen", param.Name);

      }
      else return;
    }
    else return;
  }
  if(!Ev.PassTrigger(Trigger_HNL_Muon)) return;
  FillEventCutflow(sigmm,_weight, "SSMMTrig",  param.Name);
  FillEventCutflow(sigmm_17028,_weight, "SSMMTrig",  param.Name);


  
  if(SameCharge(VetoMuonColl)) {
    
    FillEventCutflow(sigmm,_weight, "SSMMLoose",  param.Name);
    FillEventCutflow(sigmm_17028,_weight, "SSMMLoose",  param.Name);

  }

  if(MuonColl.size()!=2)  return;
  if(!SameCharge(MuonColl)) return;
  FillEventCutflow(sigmm,_weight, "SSMM",  param.Name);
  FillEventCutflow(sigmm_17028,_weight, "SSMM",  param.Name);

  
  if(MuonColl[0].Pt() < 20) return;
  if(MuonColl[1].Pt() < 10) return;

  FillEventCutflow(sigmm,_weight, "SSMM_Pt",  param.Name);
  FillEventCutflow(sigmm_17028,_weight, "SSMM_Pt",  param.Name);

  
  if(SameCharge(MuonColl) && VetoMuonColl.size()==2 && VetoElectronColl.size()==0 ) {
    
    FillEventCutflow(sigmm,_weight, "SSMM_LepVeto",  param.Name);

    if(GetLLMass(leps) > 10.)            FillEventCutflow(sigmm,_weight, "SSMM_LLMass",  param.Name);
    if(njets > 0 && GetLLMass(leps) > 10.)            FillEventCutflow(sigmm,_weight, "SSMM_Jet",  param.Name);
    if(dijet && GetLLMass(leps) > 10.)            FillEventCutflow(sigmm,_weight, "SSMM_DiJet",  param.Name);
    
    if(PassBJetMVeto && GetLLMass(leps) > 10.)            FillEventCutflow(sigmm,_weight, "SSMM_BJet",  param.Name);
    
    TString channel_string= GetChannelString(MuMu, SS);
    bool tau_veto = (TauColl.size()==0);
    
    if(GetLLMass(leps) > 10. && tau_veto && PassBJetMVeto) {
      
      FillEventCutflow(sigmm,_weight, "SSMM_vTau",  param.Name);
      
      if(FatjetColl.size() > 0){
	if(RunSignalRegionAK8( MuMu, SS, leps, leps_veto, JetColl, FatjetColl, "Medium", METv, param,  channel_string, _weight ))   FillEventCutflow(sigmm,_weight, "SSMM_SR1",  param.Name);
	else FillEventCutflow(sigmm,_weight, "SSMM_SR1Fail",  param.Name);
      }
      else{
	
	// 2 methods:
	//1) cut on ht/pt  < 1 and Zepp -> Cut and count in SR2
	//2) use ht/pt shape in SR2 and keep events
	
	//if(PassVBFInitial(vbf_jets)) {
	
	if(PassVBFInitial(VBFJetColl)&&RunSignalRegionWW( MuMu,SS, leps, leps_veto,  VBFJetColl, FatjetColl, "Medium", METv, param,  channel_string, _weight )){    
	  FillEventCutflow(sigmm,_weight, "SSMM_SR2",  param.Name);
	  
	  
	}
	else{
	  
	  if(RunSignalRegionAK4(MuMu, SS, leps, leps_veto, JetColl, FatjetColl, "Medium", METv, param,  channel_string, _weight ))             FillEventCutflow(sigmm,_weight, "SSMM_SR3",  param.Name);
	  
	  
	  else if(JetColl.size() < 2 && leps[1]->Pt() >80.)             FillEventCutflow(sigmm,_weight, "SSMM_SR4",  param.Name);
	  
	  else             FillEventCutflow(sigmm,_weight, "SSMM_SR3Fail",  param.Name);
	  
	}// SR3
      } // NO AK8
    } // LLMASS
  }
  
  
  
  // 17028 ANALYSIS                                                                                                                                                                                                                                                                                                            
  
  if(SameCharge(MuonColl) && VetoMuonColl.size()==2 && VetoElectronColl.size()==0 ) {
    

    FillEventCutflow(sigmm_17028,_weight, "SSMM_LepVeto",  param.Name);
    if(GetLLMass(MuonColl) > 10.)            FillEventCutflow(sigmm_17028,_weight, "SSMM_LLMass",  param.Name);
    if(njets > 0 && GetLLMass(MuonColl) > 10.)            FillEventCutflow(sigmm_17028,_weight, "SSMM_Jet",  param.Name);
    if(dijet  && GetLLMass(MuonColl) > 10.)            FillEventCutflow(sigmm_17028,_weight, "SSMM_DiJet",  param.Name);
    if(PassBJetMVeto&& dijet > 0 && GetLLMass(MuonColl) > 10.)            FillEventCutflow(sigmm_17028,_weight, "SSMM_BJet",  param.Name);
    
    
    TString channel_string= GetChannelString(MuMu, SS);
    if(GetLLMass(MuonColl) > 10.&&PassBJetMVeto) {
      
      if(FatjetColl.size() > 0){
	if(RunSignalRegionAK8( MuMu, SS, leps, leps_veto, JetColl, FatjetColl, "Medium", METv, param,  channel_string, _weight ))   FillEventCutflow(sigmm_17028,_weight, "SSMM_SR1",  param.Name);
	else             FillEventCutflow(sigmm_17028,_weight, "SSMM_SR1Fail",  param.Name);
	
      }
      else{
	
	if(RunSignalRegionAK4(MuMu, SS, leps, leps_veto, JetColl, FatjetColl, "Medium", METv, param,  channel_string, _weight ))             FillEventCutflow(sigmm_17028,_weight, "SSMM_SR3",  param.Name);
	
	
	else             FillEventCutflow(sigmm_17028,_weight, "SSMM_SR3Fail",  param.Name);
	
      }// SR3                                                                                                                                                                                                                                                                                                             
    } // NO AK8                                                                                                                                                                                                                                                                                                           
  } // LLMASS                                                                                                                                                                                                                                                                                                             
  

  return;
  
}
void HNL_SignalStudies::FillAllMuonPlots(TString label , TString cut,  std::vector<Muon> muons, float w){

  for(unsigned int i=0; i <  muons.size(); i++){

    TString mu_lab="muon1";
    if(i==1) mu_lab="muon2";
    if(i==2) mu_lab="muon3";

    TString eta_label="";
    if(fabs(muons.at(i).Eta()) < 1.5) eta_label = "_barrel";
    else eta_label = "_endcap";

    
    FillAllMuonPlots(mu_lab+label, cut, muons.at(i), w);
    FillAllMuonPlots(mu_lab+label+eta_label, cut, muons.at(i), w);

    FillAllMuonPlots("muon"+label, cut, muons.at(i), w);
    FillAllMuonPlots("muon"+label+eta_label, cut, muons.at(i), w);

    if(muons.at(i).MVA() < 0.5)     FillAllMuonPlots("muon"+label+eta_label+"_lowmva", cut, muons.at(i), w);
    else FillAllMuonPlots("muon"+label+eta_label+"_highmva", cut, muons.at(i), w);


  }

  return;
}
void HNL_SignalStudies::FillAllMuonPlots(TString label , TString cut,  Muon mu, float w){
  
  vector<Jet> JetAllColl = GetJets("NoID", 10., 3.0);
  int IdxMatchJet=-1;
  double mindR(999.);

  double PtRelv0(0.);
  double PtRelv1(0.);
  double PtRatio(1.);
  double jet_disc(-1);
  for(unsigned int ij=0; ij<JetAllColl.size(); ij++){
    float dR=mu.DeltaR(JetAllColl.at(ij));
    if(dR>0.4) continue;
    if(dR<mindR){ mindR=dR; IdxMatchJet=ij; }
  }
  if(IdxMatchJet!=-1){
    PtRatio = mu.Pt()/JetAllColl.at(IdxMatchJet).Pt();
    TLorentzVector JetNoLep(JetAllColl.at(IdxMatchJet));
    JetNoLep -= mu;
    PtRelv0 = mu.Perp(JetAllColl.at(IdxMatchJet).Vect());
    PtRelv1 = mu.Perp(JetNoLep.Vect());
    jet_disc = JetAllColl.at(IdxMatchJet).GetTaggerResult(JetTagging::DeepCSV);

  }

  FillHist( cut+ "/ID_POGLoose_"+label, mu.PassID("POGLoose"), w, 2, 0., 2.);
  FillHist( cut+ "/ID_POGMedium_"+label, mu.PassID("POGMedium"), w, 2, 0., 2.);
  FillHist( cut+ "/ID_POGTight_"+label, mu.PassID("POGTight"), w, 2, 0., 2.);
  FillHist( cut+ "/ID_POGHighPt_"+label, mu.PassID("POGHighPt"), w, 2, 0., 2.);

  FillHist( cut+ "/ptrel_0_"+label , PtRelv0 , w, 200, 0., 20., "");
  FillHist( cut+ "/ptrel_1_"+label , PtRelv1 , w, 200, 0., 20., "");
  FillHist( cut+ "/ptrel_def_"+label , mu.lep_jet_ptrel() , w, 200, 0., 20., "");
  FillHist( cut+ "/ptratio_def_"+label , mu.lep_jet_ptratio() , w, 100, 0., 2., "");
  FillHist( cut+ "/ptratio_"+label , PtRatio , w, 100, 0., 2., "");
  FillHist( cut+ "/jet_disc_"+label , jet_disc , w, 400, -2., 2., "");

  double new_iso = mu.RelIso() / (PtRatio * PtRelv1);
  double new_miso = mu.MiniRelIso() / (PtRatio * PtRelv1);
  FillHist( cut+ "/new_iso_"+label , new_iso , fabs(w), 100000, 0., 1., "");
  FillHist( cut+ "/new_miso_"+label , new_miso , fabs(w), 100000, 0., 1., "");
  FillHist( cut+ "/ptratio_rel", PtRelv1, PtRatio, fabs(w), 200, 0., 20., 100, 0., 2.);

  if(mu.MiniRelIso() < 0.2)   FillHist( cut+ "/ptratio_rel_miso02", PtRelv1, PtRatio, fabs(w), 200, 0., 20., 100, 0., 2.);
  if(mu.MiniRelIso() < 0.1)   FillHist( cut+ "/ptratio_rel_miso01", PtRelv1, PtRatio, fabs(w), 200, 0., 20., 100, 0., 2.);
  if(mu.MiniRelIso() < 0.08)   FillHist( cut+ "/ptratio_rel_miso008", PtRelv1, PtRatio, fabs(w), 200, 0., 20., 100, 0., 2.);
  if(mu.MiniRelIso() < 0.05)   FillHist( cut+ "/ptratio_rel_miso005", PtRelv1, PtRatio, fabs(w), 200, 0., 20., 100, 0., 2.);
  if(mu.RelIso() < 0.2)   FillHist( cut+ "/ptratio_rel_iso02", PtRelv1, PtRatio, fabs(w), 200, 0., 20., 100, 0., 2.);
  if(mu.RelIso() < 0.1)   FillHist( cut+ "/ptratio_rel_iso01", PtRelv1, PtRatio, fabs(w), 200, 0., 20., 100, 0., 2.);
  if(mu.RelIso() < 0.08)   FillHist( cut+ "/ptratio_rel_iso008", PtRelv1, PtRatio, fabs(w), 200, 0., 20., 100, 0., 2.);
  if(mu.RelIso() < 0.05)   FillHist( cut+ "/ptratio_rel_iso005", PtRelv1, PtRatio, fabs(w), 200, 0., 20., 100, 0., 2.);

  FillHist( cut+ "/pt_mu_"+label , mu.Pt() , w, 500, 0., 1000., "muon p_{T} GeV");
  FillHist( cut+ "/dxy_mu_"+label , mu.dXY() , w, 500, -0.2, 0.2, "dXY");
  FillHist( cut+ "/dz_mu_"+label , mu.dZ() , w, 500, -0.5, 0.5, "dZ");
  FillHist( cut+ "/reliso_mu_"+label , mu.RelIso() , w, 50, 0., 1., "R_{ISO} GeV");
  FillHist( cut+ "/eta_"+label  , mu.Eta() , w, 60, -3., 3.,"muon #eta");
  FillHist( cut+ "/IP3D_"+label  , mu.IP3D()/mu.IP3Derr(), w, 400, -20., 20., "IP3D");

  FillHist( cut+ "/mva_"+label  , mu.MVA(), w, 400, -1., 1., "MVA");
  FillHist( cut+ "/pt_mva_"+label , mu.Pt() , mu.MVA(), fabs(w), 200, 0., 1000., 400, -1., 1.);

  FillHist( cut+ "/chi2_"+label  , mu.Chi2(), w, 1000,0., 100., "chi2");
  FillHist( cut+ "/validhits_"+label  , mu.ValidMuonHits(), w, 100,0., 100., "");
  FillHist( cut+ "/matched_stations_"+label  , mu.MatchedStations(), w, 10,0., 10., "");
  FillHist( cut+ "/pixel_hits_"+label  , mu.PixelHits(), w, 10,0., 10., "");
  FillHist( cut+ "/minireliso_mu_"+label , mu.MiniRelIso() , w, 50, 0., 1., "R_{ISO} GeV");
  FillHist( cut+ "/tracker_layers_"+label  , mu.TrackerLayers(), w, 50,0., 50., "");
  
  return; 
}

void HNL_SignalStudies::FillAllElectronPlots(TString label , TString cut,  std::vector<Electron> els, float w){

  FillHist( cut+ "/nelectrons"+label , size(els) , w, 5, 0., 5., "n_{el}");

  for(unsigned int i=0; i < els.size(); i++){
    TString el_lab="el1";
    if(i==1) el_lab="el2";
    if(i==2) el_lab="el3";
    if(!els[i].IsGsfCtfScPixChargeConsistent()){
      FillHist( cut+ "/pt_vetoel_cc_"+el_lab+label , els.at(i).Pt() , w, 500, 0., 1000., "el p_{T} GeV");
      
    }

    //FillAllElectronPlots(el_label+label, cut, el, w);

  }
  return;

}

HNL_SignalStudies::HNL_SignalStudies(){


}
 
HNL_SignalStudies::~HNL_SignalStudies(){

}

bool HNL_SignalStudies::PassVBF(vector<Jet>  jets,std::vector<Lepton *> leps){
  
  if(leps.size() != 2) return false;
  double ll_dphi = fabs(TVector2::Phi_mpi_pi( ( (*leps[0]).Phi() - (*leps[1]).Phi() )) );
  if(ll_dphi < 2.) return false;
  if( ( (*leps[0]) + (*leps[1]) ).M() < 20.) return false;
  if(jets.size() < 2) return false;
  
  double maxDiJetDeta=0.;
  int ijet1(-1), ijet2(-1);
  for(unsigned int ij = 0; ij < jets.size()-1; ij++){
    for(unsigned int ij2 = ij+1; ij2 < jets.size(); ij2++){
      
      double deta = fabs(jets[ij].Eta() - jets[ij2].Eta());
      if(deta > maxDiJetDeta) {
	maxDiJetDeta=deta;
	ijet1=ij;
	ijet2=ij2;
      }
    }
  }

  if(jets[1].Pt() < 30) return false;
  if(maxDiJetDeta < 2.5) return false;
  Particle JJ = jets[ijet1] + jets[ijet2];
  if(JJ.M() < 750.) return false;
  double Av_JetEta= 0.5*(jets[ijet1].Eta()+ jets[ijet2].Eta());
  double zeppenfeld = TMath::Max((*leps[0]).Eta()  - Av_JetEta , (*leps[1]).Eta()  - Av_JetEta ) /maxDiJetDeta;
  
  if(zeppenfeld > 0.75) return false;
  
  return true;
}

bool HNL_SignalStudies::PassVBFv2(vector<Jet>  jets,std::vector<Lepton *> leps){

  if(leps.size() != 2) return false;
  double ll_dphi = fabs(TVector2::Phi_mpi_pi( ( (*leps[0]).Phi() - (*leps[1]).Phi() ))) ;
  if(ll_dphi < 2.) return false;
  if( ( (*leps[0]) + (*leps[1]) ).M() < 20.) return false;
  if(jets.size() < 2) return false;

  int ijet1=0;
  int ijet2=1;

  double DiJetDeta = fabs(jets[ijet1].Eta() - jets[ijet2].Eta());
  if(DiJetDeta < 2.5) return false;

  if(jets[1].Pt() < 30)  return false;
  Particle JJ = jets[ijet1] + jets[ijet2];
  if(JJ.M() < 750.) return false;
  double Av_JetEta= 0.5*(jets[ijet1].Eta()+ jets[ijet2].Eta());
  double zeppenfeld = TMath::Max((*leps[0]).Eta()  - Av_JetEta , (*leps[1]).Eta()  - Av_JetEta ) /DiJetDeta;

  if(zeppenfeld > 0.75) return false;

  return true;
}

void HNL_SignalStudies::MakeType1SignalPlots(TString process){

  bool mupt_pass=true;
  int mother_nu(0);
  unsigned int ind_w(0);
  TString  mu_ch="";

  gens = GetGens();
  
  for(unsigned int i=2; i<gens.size(); i++){
    Gen gen = gens.at(i);
    vector<int> history = TrackGenSelfHistory(gen, gens);
    
    if(gens.at(gen.MotherIndex()).PID() == 9900012 || gens.at(gen.MotherIndex()).PID() == 9900014){
      if(gen.PID() == 13) mu_ch="minus";
      if(gen.PID() == -13) mu_ch="plus";
      
    }
    
    

    if(fabs(gen.PID()) == 24 && (gens.at(gen.MotherIndex()).PID() == 9900012 || gens.at(gen.MotherIndex()).PID() == 9900014)){
      ind_w= i;
    }
    
    if((gen.PID() == 9900012 || gen.PID() == 9900014) &&  gen.Status() == 22) {
      mother_nu= gen.MotherIndex();
    }
  }
  for(unsigned int i=2; i<gens.size(); i++){
    Gen gen = gens.at(i);
    vector<int> history = TrackGenSelfHistory(gen, gens);
    
    
    if(int(gen.MotherIndex()) == ind_w && gen.Status() == 23) {
      FillHist( ("SignalGen"+process+"/" + mu_ch+"jet_w_pt").Data(), gens.at(i).Pt(), 1., 200, 0., 400.,"");
      FillHist( "SignalGen"+process+"/" + mu_ch+"jet_w_eta", gens.at(i).Eta(),  1., 60, -3., 3,"");
      FillHist( "SignalGen"+process+"/" + mu_ch+"w_dijet_mass", gens.at(gen.MotherIndex()).M(),  1., 200, 0., 200.,"");
    }
    if(gen.PID() == 9900012 || gen.PID() == 9900014){
      FillHist( "SignalGen"+process+"/" + mu_ch+"Neutrino_pt", gens.at(i).Pt(), 1., 200, 0., 400.,"");
      FillHist( "SignalGen"+process+"/" + mu_ch+"Neutrino_mass", gens.at(i).M(), 1., 200, 0., 2000.,"");
      FillHist( "SignalGen"+process+"/" + mu_ch+"Neutrino_eta", gens.at(i).Eta(), 1., 60, -3., 3,"");
    }
    if(fabs(gen.PID()) != 13) continue;

    FillHist( "SignalGen"+process+"/" + mu_ch+"Lep_mu_all_pt", gen.Pt(), 1., 200, 0., 400.,"");

    if(gens.at(gen.MotherIndex()).PID() == 9900012|| gens.at(gen.MotherIndex()).PID() == 9900014) {
      FillHist( "SignalGen"+process+"/" + mu_ch+"Lep_mu_Neutrino_pt", gen.Pt(), 1., 200, 0., 400.,"");
      FillHist( "SignalGen"+process+"/" + mu_ch+"Lep_mu_Neutrino_eta", gen.Eta(),  1., 60, -3., 3,"");
      
      for(unsigned int j=2; j<gens.size(); j++){
	Gen gen2 = gens.at(j);
	vector<int> history = TrackGenSelfHistory(gen2, gens);
	if(j==ind_w){
	  FillHist( "SignalGen"+process+"/" + mu_ch+"Lep_mu_Neutrino_dr_W_Neutrino", gen2.DeltaR(gen), 1., 100, 0., 10.,"");
	  FillHist( "SignalGen"+process+"/" + mu_ch+"Mass_mu_Neutrino__W_Neutrino", (gen2 + gen).M(), 1., 150, 0., 1500.,"");
	}
      }
      
      if(gen.Pt() < 50.) mupt_pass = false;
    }
    else if(gen.MotherIndex() == mother_nu){
      FillHist( "SignalGen"+process+"/" + mu_ch+"Lep_mu_W_pt", gen.Pt(), 1., 200, 0., 400.,"");
      FillHist( "SignalGen"+process+"/" + mu_ch+"Lep_mu_W_eta", gen.Eta(),  1., 60, -3., 3,"");
      if(gen.Pt() < 50.) mupt_pass = false;
      
    }
  }
  
  bool elpt_pass=true;
  for(unsigned int i=2; i<gens.size(); i++){
    Gen gen = gens.at(i);
    vector<int> history = TrackGenSelfHistory(gen, gens);
    
    if(fabs(gen.PID()) != 11) continue;
    
    if(gens.at(gen.MotherIndex()).PID() == 9900012|| gens.at(gen.MotherIndex()).PID() == 9900014) {
      FillHist( "SignalGen"+process+"/" + mu_ch+"Lep_el_Neutrino_pt", gen.Pt(), 1., 200, 0., 400.,"");
      if(gen.Pt() < 35.) elpt_pass = false;
    }
    else if(gen.MotherIndex() == mother_nu){
      
      FillHist( "SignalGen"+process+"/" + mu_ch+"Lep_el_W_pt", gen.Pt(), 1., 200, 0., 400., "");
      
      if(gen.Pt() < 35.) elpt_pass = false;
      
    }
  }
  


}
