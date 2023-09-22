#include "HNL_ControlRegionPlotter.h"

void HNL_ControlRegionPlotter::initializeAnalyzer(){

  HNL_LeptonCore::initializeAnalyzer();
  //SetupIDMVAReaderDefault(); /// Not needed for BDT skim                                                                                                                                                                                                                  
  //SetupEventMVAReader();
  SetupIDMVAReaderDefault(false,false);

}


void HNL_ControlRegionPlotter::executeEvent(){


  if(!(_jentry%10000)) run_Debug=true;
  else run_Debug=false;

  Event ev = GetEvent();


  if(HasFlag("BDTCheck")) {

  AnalyzerParameter param_signal = HNL_LeptonCore::InitialiseHNLParameter("HNL");
  vector<TString> IDs = {};

    IDs.push_back("HNL_ULID_Baseline");
    TString param_signal_name = param_signal.Name;
    for (auto id: IDs){
      param_signal.Electron_Tight_ID = id;
      param_signal.Muon_Tight_ID = id;
      param_signal.Name = param_signal_name + id;
      param_signal.DefName = param_signal_name + id;
      param_signal.Electron_ID_SF_Key = "Default";
      param_signal.Muon_FR_ID = "HNL_ULID_Baseline";
      param_signal.Electron_FR_ID = "HNL_ULID_Baseline";
      param_signal.Muon_FR_Key  ="ptcone_eta_AwayJetPt40";
      param_signal.Electron_FR_Key  = "ptcone_eta_AwayJetPt40";
      
      RunControlRegions(param_signal , {"BDTCheck"});
      
      return;
    }
  }
  
  vector<TString> ELIDs = {"HNL_ULID_"+GetYearString()};//,"HNTightV2"};
  for (auto id: ELIDs){
    AnalyzerParameter param_signal = HNL_LeptonCore::InitialiseHNLParameter("HNL");
    /// Name
    param_signal.Name    =  id;
    param_signal.DefName =  id;
    
    //// Background 
    param_signal.FakeRateMethod = "BDTFlavour";
    param_signal.FakeMethod   = "DATA";
    param_signal.CFMethod   = "MC";
    param_signal.ConvMethod = "MC";
    /// IDs
    param_signal.Electron_Tight_ID = id;
    param_signal.Electron_FR_ID    = "HNL_ULID_FO_"+GetYearString();
    param_signal.Muon_Tight_ID     = id;
    param_signal.Muon_FR_ID        = "HNL_ULID_FO";
    
    //// Correction
    if(id=="HNL_ULID_"+GetYearString())param_signal.Electron_ID_SF_Key = "passHNL_ULID_"+GetYearString();
    else if(id=="HNTightV2")param_signal.Electron_ID_SF_Key = "passHNTightV2";
    else  param_signal.Electron_ID_SF_Key = "Default";
    
    param_signal.Muon_ID_SF_Key = "NUM_HNL_ULID_"+GetYearString();
    param_signal.Muon_Tight_ID  = "HNL_ULID_"+GetYearString();
    param_signal.Muon_RECO_SF_Key = "MuonRecoSF";

    ///// Run command
    if(HasFlag("OSCR")) RunControlRegions(param_signal , {"CR_OS_Z"});
    else RunControlRegions(param_signal , {"CR_OS_Z","CR_OS_Top","CR_SR","CR_VV","CR_VG","VV"});
  }
  
  return;

}

void HNL_ControlRegionPlotter::RunControlRegions(AnalyzerParameter param, vector<TString> CRs){


  if(_jentry==0) PrintParam(param);
  run_Debug = (_jentry%nLog==0);
  
  if(run_Debug) {
      
    if(RunFake)  cout << "HNL_ControlRegionPlotter::RunControlRegions [RunFake]" << endl;
    else if(RunCF)  cout << "HNL_ControlRegionPlotter::RunControlRegions [RunCF]" << endl;
    else if(RunConv)  cout << "HNL_ControlRegionPlotter::RunControlRegions [RunConv]" << endl;
    else if(RunPromptTLRemoval)  cout << "HNL_ControlRegionPlotter::RunControlRegions [RunFake]" << endl;
    else  cout << "HNL_ControlRegionPlotter::RunControlRegions [Standard]" << endl;
  }

  Event ev = GetEvent();
  double weight =SetupWeight(ev,param);
  if(run_Debug) cout << "HNL_ControlRegionPlotter::RunControlRegions Weight = " << weight << endl;
  

  // HL ID                                                                                                                                                   
  std::vector<Electron>   ElectronCollV = GetElectrons(param.Electron_Veto_ID, 10., 2.5);
  std::vector<Muon>       MuonCollV     = GetMuons    (param.Muon_Veto_ID,     5.,  2.4);

  TString el_ID = (RunFake) ?  param.Electron_FR_ID  : param.Electron_Tight_ID ;
  TString mu_ID = (RunFake) ?  param.Muon_FR_ID      : param.Muon_Tight_ID ;

  //// OS CHECK TMP FAKE
  //  el_ID= param.Electron_Tight_ID;
  //mu_ID =param.Muon_Tight_ID;

  double Min_Muon_Pt     = (RunFake) ? 10. : 10.;
  double Min_Electron_Pt = (RunFake) ? 10. : 10.;

  if(run_Debug) {
    cout << "Min_Muon_Pt = " << Min_Muon_Pt << endl;
    cout << "Min_Electron_Pt = " << Min_Electron_Pt << endl;
						
  }

  // 3 Methods to run MC
  // 1) Fakes/ CF are done by data and Conv done my MC
  // - in this case if MC should remove Fake lep and CF leps
  // - this is done by Adding option 
  // std::vector<Muon>       MuonCollT     = GetLepCollByRunType    ( GetMuons    ( param,mu_ID, Min_Muon_Pt, 2.4, RunFake)      ,gens,param,"");
  //std::vector<Electron>   ElectronCollT = GetLepCollByRunType    ( GetElectrons( param,el_ID, Min_Electron_Pt, 2.5, RunFake)  ,gens,param,"");

  std::vector<Muon>       MuonCollTInit = GetMuons        ( param,mu_ID, Min_Muon_Pt,     2.4,RunFake);
  std::vector<Electron>   ElectronCollTInit = GetElectrons( param,el_ID, Min_Electron_Pt, 2.5,RunFake)  ;

  if(run_Debug) {
    cout << "MuonCollTInit size = " << MuonCollTInit.size() << endl;
    cout << "ElectronCollTInit size = " << ElectronCollTInit.size() << endl;
  }

  std::vector<Muon>       MuonCollT      =  GetLepCollByRunType    ( MuonCollTInit, param);  
  std::vector<Electron>   ElectronCollT  =  GetLepCollByRunType   ( ElectronCollTInit,param);

  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(MuonCollV,ElectronCollV);

  if(run_Debug) {
    cout << "Number of Tight Muons = " << MuonCollT.size() << endl;
    cout << "Number of Tight Electrons = " << ElectronCollT.size() << endl;
  }

  // Creat Lepton vector to have lepton blind codes                                                                                                          

  Particle METv = GetvMET("PuppiT1xyULCorr"); // reyturns MET with systematic correction                                                                      

  if(run_Debug) cout << "PuppiT1xyULCorr = " << METv.Pt() << endl;

  std::vector<FatJet> AK8_JetColl                 = GetHNLAK8Jets("HNL_PNL",param);
  std::vector<Jet>    AK4_JetAllColl              = GetHNLJets("NoCut_Eta3",param);
  std::vector<Jet>    AK4_JetColl                 = GetHNLJets("Tight",     param);
  std::vector<Jet>    AK4_JetCollLoose            = GetHNLJets("Loose",     param);
  std::vector<Jet>    AK4_VBF_JetColl             = GetHNLJets("VBFTight",  param);
  std::vector<Jet>    AK4_BJetColl                = GetHNLJets("BJetM",     param);
  std::vector<Jet>    AK4_BJetCollSR1             = GetHNLJets("BJetT",     param);

  TString PUIDWP="";
  if(PUIDWP != ""){
    double PJet_PUID_weight = GetJetPileupIDSF(AK4_JetColl, PUIDWP, param);
    weight*= PJet_PUID_weight;
    FillWeightHist("PJet_PUID_weight_" ,PJet_PUID_weight);
  }

  // Get BJet collection
  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
  double sf_btag               = GetBJetSF(param,  AK4_JetColl, param_jets);
  if(!IsData )weight*= sf_btag;

  RunAllControlRegions(ElectronCollT,ElectronCollV,MuonCollT,MuonCollV, AK4_JetAllColl, AK4_JetColl,AK4_VBF_JetColl,AK8_JetColl, AK4_BJetColl, ev,METv, param, CRs,weight);
  

}




HNL_ControlRegionPlotter::HNL_ControlRegionPlotter(){


}
 
HNL_ControlRegionPlotter::~HNL_ControlRegionPlotter(){

}
