#include "AnalyzerParameter.h"

void AnalyzerParameter::Clear(){

  Name    = "Default";
  DefName = "Default";
  Channel = "";
  hprefix = "";

  MCCorrrectionIgnoreNoHist = false;
  DEBUG = false;

  WriteOutVerbose = 0;
  SRConfig="";

  // IDS
  Electron_Tight_ID = "Default";
  Electron_Loose_ID = "Default";
  Electron_Veto_ID  = "Default";
  Electron_FR_ID    = "Default";
  Electron_CF_ID    = "Default";
  Tau_Tight_ID      = "Default";
  Tau_Loose_ID      = "Default";
  Tau_Veto_ID       = "Default";
  Muon_Tight_ID     = "Default";
  Muon_Loose_ID     = "Default";
  Muon_Veto_ID      = "Default";
  Muon_FR_ID        = "Default";
  Muon_CF_ID        = "Default";
  TriggerSelection  = "Default";
  JetPUID           = "Default";
  Jet_ID            = "Default";
  FatJet_ID         = "Default";

  /// Keys
  k.Electron_ID_SF = "Default";
  k.Electron_Trigger_SF = "Default";
  k.Electron_FR = "Default";
  k.Electron_PR = "Default";
  k.Electron_CF = "Default";
  k.Muon_RECO_SF = "Default";
  k.Muon_Trigger_SF = "Default";
  k.Muon_ID_SF = "Default";
  k.Muon_ISO_SF = "Default";
  k.Muon_Trigger_SF = "Default";
  k.Muon_FR = "Default";
  k.Muon_PR = "Default";
  k.Muon_CF = "Default";
  k.EMu_Trigger_SF = "Default";


  Electron_Tight_RelIso = 999.;
  Electron_Loose_RelIso = 999.;
  Electron_Veto_RelIso = 999.;
  Electron_UseMini = false;
  Electron_UsePtCone = false;
  Electron_MinPt = 10.;
  Muon_Tight_RelIso = 999.;
  Muon_Loose_RelIso = 999.;
  Muon_Veto_RelIso = 999.;
  Muon_UseMini = false;
  Muon_UsePtCone = false;
  Muon_UseTuneP = false;
  Muon_MinPt = 10.;

  SystDir_PU=0;
  SystDir_BTag="central";
  BJet_Method="1a";
  FakeRateMethod="BDTFlavour";
  FakeMethod="MC";
  CFMethod="MC";
  ConvMethod="MC";

  Apply_Weight_LumiNorm  = true;
  Apply_Weight_SumW      = true;
  Apply_Weight_PileUp    = true;
  Apply_Weight_PreFire   = true;
  Apply_Weight_kFactor   = true;
  Apply_Weight_TriggerSF = true;
  Apply_Weight_IDSF      = true;
  Apply_Weight_RECOSF    = true;
  Apply_Weight_Z0        = true;
  Apply_Weight_TopCorr   = true;
  Apply_Weight_DYCorr    = true;

  syst_ = Central;

}

AnalyzerParameter::AnalyzerParameter(){

  Name    = "Default";
  DefName = "Default";
  Channel = "";
  hprefix = "";


  Electron_Tight_ID = "Default";
  Electron_Loose_ID = "Default";
  Electron_Veto_ID  = "Default";
  Electron_FR_ID    = "Default";
  Electron_CF_ID    = "Default";
  Tau_Tight_ID      = "Default";
  Tau_Loose_ID      = "Default";
  Tau_Veto_ID       = "Default";
  Muon_Tight_ID     = "Default";
  Muon_Loose_ID     = "Default";
  Muon_Veto_ID      = "Default";
  Muon_FR_ID        = "Default";
  Muon_CF_ID        = "Default";

  TriggerSelection = "Dilep";
  JetPUID          = "Default";  
  Jet_ID           = "tight";  
  FatJet_ID        = "tight";  

  /// Keys                                                                                                                                                                                                                             
  k.Electron_ID_SF = "Default";
  k.Electron_Trigger_SF = "Default";
  k.Electron_FR = "Default";
  k.Electron_PR = "Default";
  k.Electron_CF = "Default";
  k.Muon_RECO_SF = "MuonRecoSF"; 
  k.Muon_Trigger_SF = "Default";
  k.Muon_ID_SF = "Default";
  k.Muon_ISO_SF = "Default";
  k.Muon_Trigger_SF = "Default";
  k.Muon_FR = "Default";
  k.Muon_PR = "Default";
  k.Muon_CF = "Default";
  k.EMu_Trigger_SF = "Default";


  MCCorrrectionIgnoreNoHist = false;
  DEBUG = false;

  WriteOutVerbose = 0;
  SRConfig="";


  SystDir_PU=0;
  SystDir_BTag="Default";
  FakeRateMethod="BDTFlavour";  FakeMethod="MC";   CFMethod="MC";   ConvMethod="MC";   BJet_Method="Default";


  /// Set weights to true by default
  Apply_Weight_LumiNorm  = true;
  Apply_Weight_SumW      = true;
  Apply_Weight_PileUp    = true;
  Apply_Weight_PreFire   = true;
  Apply_Weight_kFactor   = true;
  Apply_Weight_TriggerSF = true;
  Apply_Weight_IDSF      = true;
  Apply_Weight_RECOSF    = true;
  Apply_Weight_Z0        = true;
  Apply_Weight_TopCorr   = true;
  Apply_Weight_DYCorr    = true;
  syst_ = Central;
  
  /////////// JETS
  Jet_MinPt = 10.;  Jet_MaxEta = 5.;  BJet_Method                = "1a";
  /// ---------                                                                                                                                                                                
  FatJet_MinPt = 200.;  FatJet_MaxEta = 5.;
  /// ---------                                                                                                                                                                                
  Muon_MinPt = 10.; Muon_MaxEta = 2.4;
  /// ---------                                                                                                                                                                                
  Electron_MinPt = 10.;  Electron_MaxEta = 2.5;


}

double AnalyzerParameter::EventWeight(){
  
  double EvWeight = 1;

  if(Apply_Weight_LumiNorm) EvWeight*= w.lumiweight;
  if(Apply_Weight_PileUp)   EvWeight*= w.PUweight;
  if(Apply_Weight_PreFire)  EvWeight*= w.prefireweight;
  if(Apply_Weight_Z0)       EvWeight*= w.z0weight;
  if(Apply_Weight_TopCorr)  EvWeight*= w.topptweight;
  if(Apply_Weight_DYCorr)   EvWeight*= w.weakweight;
  if(Apply_Weight_DYCorr)   EvWeight*= w.zptweight;
  
  return EvWeight;

}

void AnalyzerParameter::PrintParameters(){

  cout << "\n PrintParameters:" <<endl;
  cout << "--------------------------------------" << endl;
  cout << "Name    = " << Name << endl;
  cout << "DefName    = " << DefName << endl;
  cout << "Channel    = " << Channel << endl;
  cout << "hprefix    = " << hprefix << endl;
  cout << "SRConfig    = " << SRConfig << endl;

  cout << "\n IDs:" <<endl;
  cout << "--------------------------------------" << endl;

  cout << "Electron_Tight_ID = " << Electron_Tight_ID << endl;
  cout << "Electron_Loose_ID = " << Electron_Loose_ID << endl;
  cout << "Electron_Veto_ID  = " << Electron_Veto_ID << endl;
  cout << "Electron_FR_ID    = " << Electron_FR_ID << endl;
  cout << "Electron_CF_ID    = " << Electron_CF_ID << endl;
  cout << "Tau_Tight_ID      = " << Tau_Tight_ID << endl;
  cout << "Tau_Loose_ID      = " << Tau_Loose_ID << endl;
  cout << "Tau_Veto_ID       = " << Tau_Veto_ID << endl;
  cout << "Muon_Tight_ID     = " << Muon_Tight_ID << endl;
  cout << "Muon_Loose_ID     = " << Muon_Loose_ID << endl;
  cout << "Muon_Veto_ID      = " << Muon_Veto_ID << endl;
  cout << "Muon_FR_ID        = " << Muon_FR_ID << endl;
  cout << "Muon_CF_ID        = " << Muon_CF_ID << endl;
  cout << "TriggerSelection  = " << TriggerSelection << endl;
  cout << "JetPUID           = " << JetPUID << endl;
  cout << "Jet_ID            = " << Jet_ID << endl;
  cout << "FatJet_ID         = " << FatJet_ID << endl;
  cout << "\n Keys:" <<endl;
  cout << "--------------------------------------" << endl;
  cout << "k.Electron_ID_SF = " << k.Electron_ID_SF << endl;
  cout << "k.Electron_Trigger_SF = " << k.Electron_Trigger_SF << endl;
  cout << "k.Electron_FR = " << k.Electron_FR << endl;
  cout << "k.Electron_PR = " << k.Electron_PR << endl;
  cout << "k.Electron_CF = " << k.Electron_CF << endl;
  cout << "k.Muon_RECO_SF = " << k.Muon_RECO_SF << endl;
  cout << "k.Muon_Trigger_SF = " << k.Muon_Trigger_SF << endl;
  cout << "k.Muon_ID_SF = " << k.Muon_ID_SF << endl;
  cout << "k.Muon_ISO_SF = " << k.Muon_ISO_SF << endl;
  cout << "k.Muon_Trigger_SF = " << k.Muon_Trigger_SF << endl;
  cout << "k.Muon_FR = " << k.Muon_FR << endl;
  cout << "k.Muon_PR = " << k.Muon_PR << endl;
  cout << "k.Muon_CF = " << k.Muon_CF << endl;
  cout << "k.EMu_Trigger_SF = " << k.EMu_Trigger_SF << endl;
  cout << "\n Weights:" << endl;
  cout << "--------------------------------------" << endl;
  cout << "w.lumiweight  = " << w.lumiweight << endl;
  cout << "w.PUweight =" << w.PUweight << endl;
  cout << "w.PUweight_up =" << w.PUweight_up<< endl;
  cout << "w.PUweight_down = " << w.PUweight_down << endl;
  cout << "w.prefireweight "<< w.prefireweight << endl;  
  cout << "w.prefireweight_up = " << w.prefireweight_up << endl; 
  cout << "w.prefireweight_down = " << w.prefireweight_down<< endl;
  cout << "w.z0weight = " << w.z0weight<< endl;
  cout << "w.weakweight = " << w.weakweight<< endl;
  cout << "w.zptweight = " << w.zptweight<< endl;
  cout << "w.topptweight = " << w.topptweight<< endl;
  
}

TString AnalyzerParameter::GetSystType(){

  if(syst_==Syst::Central){
    return "Central";
  }
  else if(syst_==Syst::JetResUp){
    return "JetResUp";
  }
  else if(syst_==Syst::JetResDown){
    return "JetResDown";
  }
  else if(syst_==Syst::JetEnUp){
    return "JetEnUp";
  }
  else if(syst_==Syst::JetEnDown){
    return "JetEnDown";
  }
  else if(syst_==Syst::PrefireUp){
    return "PrefireUp";
  }
  else if(syst_==Syst::PrefireDown){
    return "PrefireDown";
  }
  else if(syst_==Syst::PUUp){
    return "PUUp";
  }
  else if(syst_==Syst::PUDown){
    return "PUDown";
  }

  else if(syst_==Syst::JetPUIDUp){
    return "JetPUIDUp";
  }
  else if(syst_==Syst::JetPUIDDown){
    return "JetPUIDDown";
  }
  else if(syst_==Syst::JetMassSmearUp){
    return "JetMassSmearUp";
  }
  else if(syst_==Syst::JetMassSmearDown){
    return "JetMassSmearDown";
  }
  else if(syst_==Syst::MuonRecoSFUp){
    return "MuonRecoSFUp";
  }
  else if(syst_==Syst::MuonRecoSFDown){
    return "MuonRecoSFDown";
  }
  
  else if(syst_==Syst::MuonEnUp){
    return "MuonEnUp";
  }
  else if(syst_==Syst::MuonEnDown){
    return "MuonEnDown";
  }
  
  else if(syst_==Syst::MuonIDSFUp){
    return "MuonIDSFUp";
  }
  else if(syst_==Syst::MuonIDSFDown){
    return "MuonIDSFDown";
  }
  else if(syst_==Syst::MuonISOSFUp){

    return "MuonISOSFUp";
 }
  else if(syst_==Syst::MuonISOSFDown){
    return "MuonISOSFDown";
  }
  else if(syst_==Syst::MuonTriggerSFUp){
    return "MuonTriggerSFUp";
  }
  else if(syst_==Syst::MuonTriggerSFDown){
    return "MuonTriggerSFDown";
  }
  else if(syst_==Syst::ElectronRecoSFUp){
    return "ElectronRecoSFUp";
  }
  else if(syst_==Syst::ElectronRecoSFDown){
    return "ElectronRecoSFDown";
  }
  else if(syst_==Syst::ElectronResUp){
    return "ElectronResUp";
  }
  else if(syst_==Syst::ElectronResDown){
    return "ElectronResDown";
  }
  else if(syst_==Syst::ElectronEnUp){
    return "ElectronEnUp";
  }
  else if(syst_==Syst::ElectronEnDown){
    return "ElectronEnDown";
  }
  else if(syst_==Syst::ElectronIDSFUp){
    return "ElectronIDSFUp";
  }
  else if(syst_==Syst::ElectronIDSFDown){
    return "ElectronIDSFDown";
  }
  else if(syst_==Syst::ElectronTriggerSFUp){
    return "ElectronTriggerSFUp";
  }
  else if(syst_==Syst::ElectronTriggerSFDown){
    return "ElectronTriggerSFDown";
  }
  else if(syst_==Syst::BTagSFHTagUp){
    return "BTagSFHTagUp";
  }
  else if(syst_==Syst::BTagSFHTagDown){
    return "BTagSFHTagDown";
  }
  else if(syst_==Syst::BTagSFLTagUp){
    return "BTagSFLTagUp";
  }
  else if(syst_==Syst::BTagSFLTagDown){
    return "BTagSFLTagDown";
  }
  else if(syst_==Syst::METUnclUp){
    return "METUnclUp";
  }
  else if(syst_==Syst::METUnclDown){
    return "METUnclDown";
  }
  else if(syst_==Syst::CFUp){
    return "CFUp";
  }
  else if(syst_==Syst::CFDown){
    return "CFDown";
  }
  else if(syst_==Syst::FRUp){
    return "FRUp";
  }
  else if(syst_==Syst::FRDown){
    return "FRDown";
  }


  else{
    cout << "[AnalyzerParameter::GetSystType] Wrong Syst" << endl;
    exit(ENODATA);
    return "ERROR";
  }

}

AnalyzerParameter::~AnalyzerParameter(){
}
