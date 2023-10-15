#include "HNL_ControlRegionPlotter.h"

void HNL_ControlRegionPlotter::initializeAnalyzer(){

  HNL_LeptonCore::initializeAnalyzer();
  SetupEventMVAReader();

  nLog = 100000;
}


void HNL_ControlRegionPlotter::executeEvent(){

  if(!(_jentry%10000)) run_Debug=true;
  else run_Debug=false;

  Event ev = GetEvent();

  vector<TString> LepIDs = {"HNL_ULID"};//,"HNTightV2","TopHN", "DefaultPOGTight"};

  vector<HNL_LeptonCore::Channel> ChannelsToRun = {EE,MuMu,EMu,MuE};
  for (auto id: LepIDs){
    for(auto channel : ChannelsToRun){
      AnalyzerParameter param_signal = HNL_LeptonCore::InitialiseHNLParameter(id,channel);
      
      ///// Run command
      vector<TString> CRToRun;
      if(HasFlag("OS_VR"))   CRToRun = {"CR_OS_Z","CR_OS_Top","CR_OS_Top2","CR_OS_ZAk8","CR_OS_TopAK8"};
      if(HasFlag("SS_CR"))   CRToRun.push_back("SS_CR");
      if(HasFlag("SS_CR"))   CRToRun.push_back("Presel");
      if(HasFlag("VV_VR"))   CRToRun.push_back("VV_VR");
      if(HasFlag("VV_VR"))   CRToRun.push_back("VG_VR");
      RunControlRegions(param_signal , CRToRun );
    }
  }
  
  /// For BDT plots 

  if(HasFlag("BDTCheck")) {
    AnalyzerParameter param_signal = HNL_LeptonCore::InitialiseHNLParameter("SignalStudy");
    vector<TString> IDs = {"HNL_ULID_Baseline"};
    TString param_signal_name = param_signal.Name;
    for (auto id: IDs){
      param_signal.Electron_Tight_ID = id;
      param_signal.Muon_Tight_ID = id;
      param_signal.Name = param_signal_name + id;
      param_signal.DefName = param_signal_name + id;
      param_signal.k.Electron_ID_SF = "Default";
      param_signal.Muon_FR_ID = "HNL_ULID_Baseline";
      param_signal.Electron_FR_ID = "HNL_ULID_Baseline";
      RunControlRegions(param_signal , {"BDTCheck"});

      return;
    }
  }



  return;
  
}

void HNL_ControlRegionPlotter::RunControlRegions(AnalyzerParameter param, vector<TString> CRs){


  if(_jentry==0) param.PrintParameters();
  run_Debug = (_jentry%nLog==0);

  if(run_Debug) cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  
  Event ev = GetEvent();

  /// SetupWeight applies w_GenNorm=1., w_BR=1., w_PU  w_Pref  
  double weight =SetupWeight(ev,param);
  
  if(run_Debug) cout << "HNL_ControlRegionPlotter::RunControlRegions Gen*Lumi Weight = " << weight << endl;
  if(run_Debug) cout << "HNL_ControlRegionPlotter::RunControlRegions ParamWeight = " << param.EventWeight() << endl; 

  // HL ID                                                                                                                                                   
  std::vector<Electron>   ElectronVetoColl = GetElectrons(param.Electron_Veto_ID, 10.,  2.5);
  std::vector<Muon>       MuonVetoColl     = GetMuons    (param.Muon_Veto_ID,     10.,  2.4);

  /// IF ruunning fake then use FR_ID not Tight
  TString Electron_ID = (RunFake) ?  param.Electron_FR_ID  : param.Electron_Tight_ID ;
  TString Muon_ID     = (RunFake) ?  param.Muon_FR_ID      : param.Muon_Tight_ID ;
  if(param.FakeMethod == "MC"){
    Electron_ID =param.Electron_Tight_ID;
    Muon_ID = param.Muon_Tight_ID;
  }

  double Min_Muon_Pt     = RunFake ? 7  : 10.;
  double Min_Electron_Pt = RunFake ? 10 : 15;

  if(run_Debug) cout << "HNL_ControlRegionPlotter::RunControlRegions Min_Muon_Pt = " << Min_Muon_Pt << endl;
  if(run_Debug) cout << "HNL_ControlRegionPlotter::RunControlRegions Min_Electron_Pt = " << Min_Electron_Pt << endl;


  // 3 Methods to run MC
  // 1) Fakes/ CF are done by data and Conv done my MC
  // - in this case if MC should remove Fake lep and CF leps
  // - this is done by Adding option 

  std::vector<Muon>       MuonTightCollInit     = SelectMuons    ( param,Muon_ID,     Min_Muon_Pt,     2.4,weight); 
  std::vector<Electron>   ElectronTightCollInit = SelectElectrons( param,Electron_ID, Min_Electron_Pt, 2.5,weight);

  if(run_Debug)  cout << "HNL_ControlRegionPlotter::RunControlRegions Number of Muon Tight Coll = " << MuonTightCollInit.size() << endl;
  if(run_Debug)  cout << "HNL_ControlRegionPlotter::RunControlRegions Number of Electron Tight Coll  = " << ElectronTightCollInit.size() << endl;
  
  std::vector<Muon>       MuonTightColl      =  GetLepCollByRunType    (MuonTightCollInit,    param);  
  std::vector<Electron>   ElectronTightColl  =  GetLepCollByRunType    (ElectronTightCollInit,param);
  std::vector<Lepton *>   Leps_Veto          =  MakeLeptonPointerVector(MuonVetoColl,ElectronVetoColl);

  if(run_Debug) {
    cout << "HNL_ControlRegionPlotter::RunControlRegions Number of GenMatched Tight Muons = "     << MuonTightColl.size() << endl;
    cout << "HNL_ControlRegionPlotter::RunControlRegions Number of GenMatched Tight Electrons = " << ElectronTightColl.size() << endl;
  }

  // Creat Lepton vector to have lepton blind codes                                                                                                          

  Particle METv = GetvMET("PuppiT1xyULCorr",param); // returns MET with systematic correction                                                                      

  std::vector<FatJet> AK8_JetColl                 = GetHNLAK8Jets(param.AK8JetColl,param);
  std::vector<Jet>    AK4_JetColl                 = GetHNLJets(param.AK4JetColl,     param);
  std::vector<Jet>    AK4_JetAllColl              = GetHNLJets("NoCut_Eta3",param);
  std::vector<Jet>    AK4_JetCollLoose            = GetHNLJets("Loose",     param);
  std::vector<Jet>    AK4_VBF_JetColl             = GetHNLJets("VBFTight",  param);
  std::vector<Jet>    AK4_BJetColl                = GetHNLJets("BJet", param);

  EvalJetWeight(AK4_JetColl, AK8_JetColl, weight, param);
  
  RunAllControlRegions(ElectronTightColl,ElectronVetoColl,MuonTightColl,MuonVetoColl, AK4_JetAllColl, AK4_JetColl,AK4_VBF_JetColl,AK8_JetColl, AK4_BJetColl, ev,METv, param, CRs,weight);
  

}




HNL_ControlRegionPlotter::HNL_ControlRegionPlotter(){


}
 
HNL_ControlRegionPlotter::~HNL_ControlRegionPlotter(){

}
