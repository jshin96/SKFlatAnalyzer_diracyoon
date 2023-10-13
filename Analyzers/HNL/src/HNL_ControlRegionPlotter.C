#include "HNL_ControlRegionPlotter.h"

void HNL_ControlRegionPlotter::initializeAnalyzer(){

  HNL_LeptonCore::initializeAnalyzer();
  //SetupEventMVAReader();

}


void HNL_ControlRegionPlotter::executeEvent(){

  if(!(_jentry%10000)) run_Debug=true;
  else run_Debug=false;

  Event ev = GetEvent();

  vector<TString> LepIDs = {"HNL_ULID_"+GetYearString()};//,"HNTightV2","TopHN", "DefaultPOGTight"};
  vector<HNL_LeptonCore::Channel> ChannelsToRun = {EE,MuMu,EMu,MuE};
  for (auto id: LepIDs){

    AnalyzerParameter param_signal = HNL_LeptonCore::InitialiseHNLParameter("HNL");
    /// Name
    param_signal.Name    =  id;
    param_signal.DefName =  id;

    param_signal.Weight_LumiNorm = true;
    param_signal.Weight_SumW     = true;
    param_signal.Weight_PileUp   = true;
    param_signal.Weight_PreFire  = true;
    param_signal.Weight_kFactor  = true;
    param_signal.Weight_IDSF     = true;
    param_signal.Weight_TriggerSF= true;
    
    param_signal.FakeMethod   = "DATA";
    param_signal.CFMethod     = "DATA";
    param_signal.ConvMethod   = "MC";

    /// IDs
    param_signal.Electron_Tight_ID = (id == "TopHN") ? "TopHNSST" :  id;
    param_signal.Muon_Tight_ID     = (id == "TopHN") ? "TopHNT"   :  id;
    
    if(id=="HNTightV2" )        param_signal.Muon_FR_ID        = "HNLooseV1";
    if(id=="TopHN" )            param_signal.Muon_FR_ID        = "TopHNL"; 
    if(id.Contains("HNL_ULID")) param_signal.Muon_FR_ID        = "HNL_ULID_FO";

    if(id=="HNTightV2" )        param_signal.Electron_FR_ID    = "HNLooseV4";
    if(id=="TopHN" )            param_signal.Electron_FR_ID    = "TopHNSSL_"+GetEraShort();
    if(id.Contains("HNL_ULID")) param_signal.Electron_FR_ID    = "HNL_ULID_FO_"+GetYearString();

    if(id=="HNTightV2" ) {
      param_signal.FakeRateMethod       = "PtCone";
      param_signal.Muon_FR_Key          = "AwayJetPt40";
      param_signal.Electron_FR_Key      = "AwayJetPt40";
    }
    if(id=="TopHN" ) {
      param_signal.FakeRateMethod       = "PtConeMini";
      param_signal.Muon_FR_Key          = "FR_cent";
      param_signal.Electron_FR_Key      = "FR_cent";
    }
    if(id =="DefaultPOGTight"){
      param_signal.FakeRateMethod       = "PtCone";
      param_signal.Muon_FR_Key          = "AwayJetPt40";
      param_signal.Electron_FR_Key      = "AwayJetPt40";

    }
    if(id.Contains("HNL_ULID")){
      param_signal.FakeRateMethod       = "BDTFlavour";
      param_signal.Muon_FR_Key          = "FR_cent";
      param_signal.Electron_FR_Key      = "FR_cent";
    }
    //// Correction
    param_signal.Electron_ID_SF_Key = "pass"+id;
    param_signal.Muon_ID_SF_Key     = "NUM_"+id;
    param_signal.Muon_RECO_SF_Key   = "MuonRecoSF";

    if(id =="DefaultPOGTight"){
      param_signal.Muon_ID_SF_Key  =    "NUM_TightID_DEN_TrackerMuons";
      param_signal.Muon_ISO_SF_Key =    "NUM_TightRelIso_DEN_TightIDandIPCut";
      param_signal.Muon_Tight_ID   =    "POGTightWithTightIso";
      param_signal.Electron_ID_SF_Key = "passTightID";
      param_signal.Electron_Tight_ID  = "passPOGTight";
      param_signal.TriggerSelection   = "POGSglLep";
    }
    
    else{
      /// Trigger Key
      param_signal.TriggerSelection   = "Dilep";
    }


    ///// Run command
    vector<TString> CRToRun;
    if(HasFlag("OS_VR"))   CRToRun = {"CR_OS_Z","CR_OS_Top","CR_OS_Top2","CR_OS_ZAk8","CR_OS_TopAK8"};
    if(HasFlag("SS_CR"))   CRToRun.push_back("SS_CR");
    if(HasFlag("SS_CR"))   CRToRun.push_back("Presel");
    if(HasFlag("VV_VR"))   CRToRun.push_back("VV_VR");
    if(HasFlag("VV_VR"))   CRToRun.push_back("VG_VR");
    RunControlRegions(ChannelsToRun,param_signal , CRToRun );
    
  }

  /// For BDT plots 

  if(HasFlag("BDTCheck")) {
    AnalyzerParameter param_signal = HNL_LeptonCore::InitialiseHNLParameter("HNL");
    vector<TString> IDs = {"HNL_ULID_Baseline"};
    TString param_signal_name = param_signal.Name;
    for (auto id: IDs){
      param_signal.Electron_Tight_ID = id;
      param_signal.Muon_Tight_ID = id;
      param_signal.Name = param_signal_name + id;
      param_signal.DefName = param_signal_name + id;
      param_signal.Electron_ID_SF_Key = "Default";
      param_signal.Muon_FR_ID = "HNL_ULID_Baseline";
      param_signal.Electron_FR_ID = "HNL_ULID_Baseline";
      RunControlRegions(ChannelsToRun,param_signal , {"BDTCheck"});

      return;
    }
  }



  return;
  
}

void HNL_ControlRegionPlotter::RunControlRegions(vector<HNL_LeptonCore::Channel> ChannelsToRun,AnalyzerParameter param, vector<TString> CRs){


  if(_jentry==0) PrintParam(param);
  run_Debug = (_jentry%nLog==0);

  if(run_Debug) cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  
  if(run_Debug) {
      
    if(RunFake)  cout << "HNL_ControlRegionPlotter::RunControlRegions [RunFake]" << endl;
    else if(RunCF)  cout << "HNL_ControlRegionPlotter::RunControlRegions [RunCF]" << endl;
    else if(RunConv)  cout << "HNL_ControlRegionPlotter::RunControlRegions [RunConv]" << endl;
    else if(RunPrompt)  cout << "HNL_ControlRegionPlotter::RunControlRegions [RunPrompt]" << endl;
    else  cout << "HNL_ControlRegionPlotter::RunControlRegions [Standard]" << endl;
  }

  Event ev = GetEvent();

  /// SetupWeight applies w_GenNorm=1., w_BR=1., w_PU  w_Pref  
  double weight =SetupWeight(ev,param);
  
  if(run_Debug) cout << "HNL_ControlRegionPlotter::RunControlRegions Gen*Lumi Weight = " << weight << endl;
  
  // HL ID                                                                                                                                                   
  std::vector<Electron>   ElectronVetoColl = GetElectrons(param.Electron_Veto_ID, 10.,  2.5);
  std::vector<Muon>       MuonVetoColl     = GetMuons    (param.Muon_Veto_ID,     10.,  2.4);

  /// IF ruunning fake then sue FR_ID not Tight
  TString Electron_ID = (RunFake) ?  param.Electron_FR_ID  : param.Electron_Tight_ID ;
  TString Muon_ID     = (RunFake) ?  param.Muon_FR_ID      : param.Muon_Tight_ID ;
    
  double Min_Muon_Pt     = RunFake ? 7  : 10.;
  double Min_Electron_Pt = RunFake ? 10 : 15;

  if(run_Debug) cout << "HNL_ControlRegionPlotter::RunControlRegions Min_Muon_Pt = " << Min_Muon_Pt << endl;
  if(run_Debug) cout << "HNL_ControlRegionPlotter::RunControlRegions Min_Electron_Pt = " << Min_Electron_Pt << endl;


  // 3 Methods to run MC
  // 1) Fakes/ CF are done by data and Conv done my MC
  // - in this case if MC should remove Fake lep and CF leps
  // - this is done by Adding option 
  // std::vector<Muon>       MuonTightColl     = GetLepCollByRunType    ( GetMuons    ( param,Muon_ID, Min_Muon_Pt, 2.4, RunFake&&!HasFlag("OS_VR"))      ,gens,param,"");
  //std::vector<Electron>   ElectronTightColl = GetLepCollByRunType    ( GetElectrons( param,Electron_ID, Min_Electron_Pt, 2.5, RunFake&&!HasFlag("OS_VR"))  ,gens,param,"");
  
  std::vector<Muon>       MuonTightCollInit     = GetMuons    ( param,Muon_ID,     Min_Muon_Pt,     2.4,RunFake); /// IF RunFake and param.FakeRateMethod == "PtCone" Pt is switched to pt code in Muon/Electron
  std::vector<Electron>   ElectronTightCollInit = GetElectrons( param,Electron_ID, Min_Electron_Pt, 2.5,RunFake);


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

  Particle METv = GetvMET("PuppiT1xyULCorr"); // returns MET with systematic correction                                                                      
  std::vector<FatJet> AK8_JetColl                 = GetHNLAK8Jets("HNL_PNL",param);
  std::vector<Jet>    AK4_JetColl                 = GetHNLJets("Tight",     param);
  std::vector<Jet>    AK4_JetAllColl              = GetHNLJets("NoCut_Eta3",param);
  std::vector<Jet>    AK4_JetCollLoose            = GetHNLJets("Loose",     param);
  std::vector<Jet>    AK4_VBF_JetColl             = GetHNLJets("VBFTight",  param);
  std::vector<Jet>    AK4_BJetColl                = GetHNLJets("BJetM",     param);

  TString PUIDWP="";
  if(PUIDWP != "")   weight*= FillWeightHist("PJet_PUID_weight_" , GetJetPileupIDSF(AK4_JetColl, PUIDWP, param));
  
  if(!IsData) {
    
    // Get BJet collection
    JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
    double sf_btag                    = GetBJetSF(param,  AK4_JetColl, param_jets);
    weight*= sf_btag;
    FillWeightHist("DeepJetSF", sf_btag);
    for(auto iJ : AK8_JetColl) weight*= FillWeightHist("PNET_JETTagger",iJ.GetTaggerSF(JetTagging::particleNet_WvsQCD, DataEra,0));
   
    double ElSFWeight = GetElectronSFEventWeight(ElectronTightColl, param);
    double MuSFWeight = GetMuonSFEventWeight    (MuonTightColl    , param);

    weight*= ElSFWeight;
    weight*= MuSFWeight;
    
    /// GetElectronSFEventWeight Applied Reco / ID / ISO  
    
    if(run_Debug) cout <<"RunAllControlRegions GetElectronSFEventWeight =" << ElSFWeight << endl;
    if(run_Debug) cout <<"RunAllControlRegions GetMuonSFEventWeight     =" << MuSFWeight << endl;
  }
  //ChannelsToRun
  RunAllControlRegions(ChannelsToRun,ElectronTightColl,ElectronVetoColl,MuonTightColl,MuonVetoColl, AK4_JetAllColl, AK4_JetColl,AK4_VBF_JetColl,AK8_JetColl, AK4_BJetColl, ev,METv, param, CRs,weight);
  

}




HNL_ControlRegionPlotter::HNL_ControlRegionPlotter(){


}
 
HNL_ControlRegionPlotter::~HNL_ControlRegionPlotter(){

}
