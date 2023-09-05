#include "HNL_SignalRegionPlotter.h"

void HNL_SignalRegionPlotter::initializeAnalyzer(){

  // All default settings like trigger/ PD/ BJet are decalred in HNL_LeptonCore::initializeAnalyzer to make them consistent for all HNL codes

  HNL_LeptonCore::initializeAnalyzer();
  
  SetupIDMVAReaderDefault(); /// Not needed for BDT skim
  SetupEventMVAReader();                                                                                                                                                                                                                            
}


void HNL_SignalRegionPlotter::executeEvent(){

  FillTimer("START_EV");
  
  if((_jentry==0)){ 
    // Print out trigger info in HNL_LeptonCore::initializeAnalyzer
    TriggerPrintOut(GetEvent());
  }
  
  AnalyzerParameter param_signal = HNL_LeptonCore::InitialiseHNLParameter("MVAUL","_UL");
  param_signal.FakeMethod = "MC";

  //  RunULAnalysis(param_signal);

  //  vector<TString> IDs = {  "HNL_ULID_2016",  "HNL_ULID_2017",      "HNL_ULID_2018",  "HNL_LID_2016",    "HNL_ULID_Run2",  "HNL_ULID_Run2v2", "HNTightV2"};
  vector<TString> IDs = {"HNL_ULID_ConvUpdate","HNL_ULID_ConvUpdateSplit","HNL_ULID_ConvUpdateFlat","HNL_ULID_Conv_2016","HNL_ULID_Conv_Run2", "passMVAID_noIso_WP90"};

  /*"HNL_ULID_OPT_POG1",
    "HNL_ULID_OPT_POG2",
    "HNL_ULID_OPT_POG3",
    "HNL_ULID_OPT_POG4",
    "HNL_ULID_Run2_OPT",
    "HNL_ULID_2016_OPT",
    "HNL_ULID_2017_OPT",
    "HNL_ULID_2018_OPT",
    "HNL_ULID_2016",
    "HNL_ULID_2017",
    "HNL_ULID_2018",
    "HNL_ULID_Run2",
    "HNL_LID_2016",
    "HNL_ULID_Run2v2",
    "HNTightV2"};*/
  
  TString param_signal_name = param_signal.Name;
  
  for (auto id: IDs){
    param_signal.Electron_Tight_ID = id;
    param_signal.Name = param_signal_name + id;
    param_signal.DefName = param_signal_name + id;
    RunULAnalysis(param_signal);
  }

  return;
  if(!IsData) RunSyst=true;
  if(RunSyst){
    TString param_signal_name = param_signal.Name;
    vector<AnalyzerParameter::Syst> SystList;// = GetSystList("Initial");

    for(auto isyst : SystList){
      param_signal.syst_ = AnalyzerParameter::Syst(isyst);
      
      param_signal.Name = "Syst_"+param_signal.GetSystType()+param_signal_name;
      param_signal.DefName = "Syst_"+param_signal.GetSystType()+param_signal_name;
      RunULAnalysis(param_signal);
    }
  }    

  FillTimer("END_EV");

  return ;
}

void HNL_SignalRegionPlotter::RunULAnalysis(AnalyzerParameter param){

  if(run_Debug) cout << "HNL_SignalRegionPlotter::executeEvent " << endl;

  Event ev = GetEvent();
  double weight =SetupWeight(ev,param);

  ///// MERGE WJet samples for more stats                                                                                                                                      
  //if(MCSample.Contains("WJet")){
  //  vector<TString> vec = {"WJet"};
  //  double merge_weight = MergeMultiMC( vec, "" );
  //  weight*= merge_weight;
  // }

  /// Merge DY samples for more stats                                                                                                                                        
  //if(MCSample.Contains("DYJets_MG")){
  //  vector<TString> vec = {"DYMG"};
  //  double merge_weight = MergeMultiMC( vec, "" );
  //  weight*= merge_weight;
  // }


  
  // HL ID
  std::vector<Electron>   ElectronCollV = GetElectrons(param.Electron_Veto_ID, 10., 2.5); 
  std::vector<Muon>       MuonCollV     = GetMuons    (param.Muon_Veto_ID, 5., 2.4);
  

  TString el_ID = (RunFake) ?  param.Electron_FR_ID : param.Electron_Tight_ID ;
  TString mu_ID = (RunFake) ?  param.Muon_FR_ID :  param.Muon_Tight_ID ;
  if(param.FakeMethod == "MC"){
    el_ID =param.Electron_Tight_ID;
    mu_ID = param.Muon_Tight_ID;
  }

  double Min_Muon_Pt     = (RunFake) ? 3. : 5.;
  double Min_Electron_Pt = (RunFake) ? 7. : 10.;

  std::vector<Muon>       MuonCollTInit = GetMuons    ( param,mu_ID, Min_Muon_Pt, 2.4, false);
  std::vector<Electron>   ElectronCollTInit = GetElectrons( param,el_ID, Min_Electron_Pt, 2.5, false)  ;
 
  std::vector<Muon>       MuonCollT     = GetLepCollByRunType    ( MuonCollTInit ,param);
  std::vector<Electron>   ElectronCollT  =  GetLepCollByRunType   ( ElectronCollTInit,param);

  //cout << "Number of MuonCollT = " << MuonCollT.size() << " number of electrons = " << ElectronCollT.size() << endl;

  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(MuonCollV,ElectronCollV);
  //for(auto i : leps_veto )    cout << i->GetFlavour() << " pt = "<< i->Pt() << " eta = "<< i->Eta() << endl;
  
  std::vector<Tau>        TauColl        = GetTaus     (leps_veto,param.Tau_Veto_ID,20., 2.3);

  // Creat Lepton vector to have lepton blind codes 

  
  std::vector<FatJet> AK8_JetColl                 = GetHNLAK8Jets("HNL",param);
  std::vector<Jet> AK4_JetAllColl                 = GetHNLJets("NoCut_Eta3",param);
  std::vector<Jet> JetColl                        = GetHNLJets("Tight",param);
  std::vector<Jet> JetCollLoose                   = GetHNLJets("Loose",param);
  std::vector<Jet> VBF_JetColl                    = GetHNLJets("VBFTight",param);
  std::vector<Jet> BJetColl                       = GetHNLJets("BJetM",param);

 
  Particle METv = GetvMET("PuppiT1xyULCorr",param); // returns MET with systematic correction; run this after all object selection done; NOTE that VBF jet is used here

  // select B jets                                                                                                                                                                        
  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
  double sf_btag               = GetBJetSF(param, JetColl, param_jets);
  
  JetTagging::Parameters param_jetsT = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Tight, JetTagging::incl, JetTagging::mujets);
  double sf_btagSR1               = GetBJetSF(param, JetColl, param_jetsT);

  if(!IsData)weight = weight*sf_btag;

  FillTimer("START_SR");

  RunAllSignalRegions(Inclusive,
		      ElectronCollT,ElectronCollV,MuonCollT,MuonCollV,  TauColl,
		      JetCollLoose, AK4_JetAllColl, JetColl,VBF_JetColl,AK8_JetColl, BJetColl,BJetColl, 
		      ev,METv, param, weight);

  FillTimer("END_SR");


}



 


HNL_SignalRegionPlotter::HNL_SignalRegionPlotter(){

  cout << "HNL_SignalRegionPlotter::HNL_SignalRegionPlotter  TMVA::Tools::Instance() " << endl;
  TMVA::Tools::Instance();
  cout << "Create Reader class " << endl;
  MVAReaderMM = new TMVA::Reader();
  MVAReaderEE = new TMVA::Reader();
  MVAReaderEM = new TMVA::Reader();
  
}
 
HNL_SignalRegionPlotter::~HNL_SignalRegionPlotter(){

  delete MVAReaderMM;
  delete MVAReaderEE;
  delete MVAReaderEM;

}




