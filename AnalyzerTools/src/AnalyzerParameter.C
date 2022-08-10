#include "AnalyzerParameter.h"

void AnalyzerParameter::Clear(){

  Name = "Default";
  DefName = "Default";

  MCCorrrectionIgnoreNoHist = false;
  DEBUG = false;

  Electron_Tight_ID = "Default";
  Electron_Loose_ID = "Default";
  Electron_Veto_ID = "Default";
  Electron_ID_SF_Key = "Default";
  Electron_Trigger_SF_Key = "Default";
  Electron_Trigger_NameForSF = "Default";

  Electron_FR_ID = "Default";
  Electron_FR_Key = "Default";
  Electron_CF_ID = "Default";
  Electron_CF_Key = "Default";
  Electron_Tight_RelIso = 999.;
  Electron_Loose_RelIso = 999.;
  Electron_Veto_RelIso = 999.;
  Electron_UseMini = false;
  Electron_UsePtCone = false;
  Electron_MinPt = 10.;


  
  Tau_Tight_ID = "Default";
  Tau_Loose_ID = "Default";
  Tau_Veto_ID = "Default";

  Muon_Tight_ID = "Default";
  Muon_Loose_ID = "Default";
  Muon_Veto_ID = "Default";
  Muon_RECO_SF_Key = "Default";
  Muon_Trigger_SF_Key = "Default";
  Muon_Trigger_NameForSF = "Default";
  Muon_ID_SF_Key = "Default";
  Muon_ISO_SF_Key = "Default";
  Muon_Trigger_SF_Key = "Default";
  Muon_FR_ID = "Default";
  Muon_FR_Key = "Default";
  Muon_CF_ID = "Default";
  Muon_CF_Key = "Default";
  Muon_Tight_RelIso = 999.;
  Muon_Loose_RelIso = 999.;
  Muon_Veto_RelIso = 999.;
  Muon_UseMini = false;
  Muon_UsePtCone = false;
  Muon_UseTuneP = false;
  Muon_MinPt = 10.;

  SystDir_ElectronIDSF=0;
  SystDir_ElectronRecoSF=0;
  SystDir_PU=0;
  SystDir_BTag="central";
  BJet_Method="2a";


  Jet_ID = "Default";
  FatJet_ID = "Default";

  syst_ = Central;

}

AnalyzerParameter::AnalyzerParameter(){

  Name = "Default";
  DefName = "Default";

  MCCorrrectionIgnoreNoHist = false;
  DEBUG = false;

  Electron_Tight_ID = "Default";
  Electron_Loose_ID = "Default";
  Electron_Veto_ID = "Default";
  Electron_ID_SF_Key = "Default";
  Electron_Trigger_NameForSF = "Default";
  Electron_Trigger_SF_Key = "Default";


  Tau_Tight_ID = "Default";
  Tau_Loose_ID = "Default";
  Tau_Veto_ID = "Default";

  Muon_Tight_ID = "Default";
  Muon_Loose_ID = "Default";
  Muon_Veto_ID = "Default";
  Muon_RECO_SF_Key = "Default";
  Muon_ID_SF_Key = "Default";
  Muon_ISO_SF_Key = "Default";
  Muon_Trigger_SF_Key = "Default";
  Muon_Trigger_NameForSF = "Default";
    


  SystDir_ElectronIDSF=0;
  SystDir_ElectronRecoSF=0;
  SystDir_PU=0;
  SystDir_BTag="Default";
  BJet_Method="Default";

  Jet_ID = "Default";
  FatJet_ID = "Default";

  syst_ = Central;

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
  else if(syst_==Syst::MuonEnUp){
    return "MuonEnUp";
  }
  else if(syst_==Syst::MuonEnDown){
    return "MuonEnDown";
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
  else{
    cout << "[AnalyzerParameter::GetSystType] Wrong Syst" << endl;
    exit(ENODATA);
    return "ERROR";
  }

}

AnalyzerParameter::~AnalyzerParameter(){
}
