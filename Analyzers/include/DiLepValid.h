#ifndef DiLepValid_h
#define DiLepValid_h

#include "AnalyzerCore.h"

class DiLepValid : public AnalyzerCore {

public:

  void initializeAnalyzer();
  void executeEventFromParameter(AnalyzerParameter param);
  void executeEvent();

  bool SglLTrig, DiLTrig;
  bool ElEl, MuMu, ElMu; 
  bool HEMCheck;
  bool SystRun;
  vector<TString> TrigList, TrigList_SglMu, TrigList_SglEl, TrigList_DiMu, TrigList_DiEl, TrigList_ElMu;
  TString SFKey_Trig;

  void AnalyzeDiMuon(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Electron>& EleTColl, vector<Electron>& EleLColl,
                     vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);
  void AnalyzeDiElectron(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Electron>& EleTColl, vector<Electron>& EleLColl,
                         vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);
  void AnalyzeElectronMuon(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Electron>& EleTColl, vector<Electron>& EleLColl,
                           vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);


  void CheckHEMIssue(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl,
                     vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label, TString Option);



  DiLepValid();
  ~DiLepValid();

};



#endif

