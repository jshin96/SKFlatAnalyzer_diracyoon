#include "HNL_SignalRegionPlotter.h"

void HNL_SignalRegionPlotter::initializeAnalyzer(){

  // All default settings like trigger/ PD/ BJet are decalred in HNL_LeptonCore::initializeAnalyzer to make them consistent for all HNL codes

  HNL_LeptonCore::initializeAnalyzer();
  
  SetupEventMVAReader();                                                                                                       
                                                                                                                     
}


void HNL_SignalRegionPlotter::executeEvent(){

  FillTimer("START_EV");
  
  if((_jentry==0)){ 
    // Print out trigger info in HNL_LeptonCore::initializeAnalyzer
    TriggerPrintOut(GetEvent());
  }
  
  AnalyzerParameter param_signal = HNL_LeptonCore::InitialiseHNLParameter("HNL_ULID");
  TString param_signal_name = param_signal.Name;
  RunULAnalysis(param_signal);
  

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

  std::vector<Muon>       MuonCollTInit     = SelectMuons    ( param,mu_ID, Min_Muon_Pt, 2.4,weight);
  std::vector<Electron>   ElectronCollTInit = SelectElectrons( param,el_ID, Min_Electron_Pt, 2.5, weight)  ;
 
  std::vector<Muon>       MuonCollT     = GetLepCollByRunType    ( MuonCollTInit ,param);
  std::vector<Electron>   ElectronCollT  =  GetLepCollByRunType   ( ElectronCollTInit,param);

  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(MuonCollV,ElectronCollV);
  
  std::vector<Tau>        TauColl        = SelectTaus   (leps_veto,param.Tau_Veto_ID,20., 2.3);


  std::vector<FatJet> AK8_JetColl                 = GetHNLAK8Jets(param.AK8JetColl,param);
  std::vector<Jet>    AK4_JetColl                 = GetHNLJets(param.AK4JetColl,     param);
  std::vector<Jet>    AK4_JetAllColl              = GetHNLJets("NoCut_Eta3",param);
  std::vector<Jet>    AK4_JetCollLoose            = GetHNLJets("Loose",     param);
  std::vector<Jet>    AK4_VBF_JetColl             = GetHNLJets("VBFTight",  param);
  std::vector<Jet>    AK4_BJetColl                = GetHNLJets("BJet", param);
 
  Particle METv = GetvMET("PuppiT1xyULCorr",param); // returns MET with systematic correction; run this after all object selection done; NOTE that VBF jet is used here

  
  EvalJetWeight(AK4_JetColl, AK8_JetColl, weight, param);

  FillTimer("START_SR");

  RunAllSignalRegions(Inclusive,
		      ElectronCollT,ElectronCollV,MuonCollT,MuonCollV,  TauColl,
		      AK4_JetCollLoose, AK4_JetAllColl, AK4_JetColl,AK4_VBF_JetColl,AK8_JetColl, AK4_BJetColl, 
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




