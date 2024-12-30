#ifndef DiLepValid_h
#define DiLepValid_h

#include "AnalyzerCore.h"

class DiLepValid : public AnalyzerCore {

public:

  void initializeAnalyzer();
  void executeEventFromParameter(AnalyzerParameter param);
  void executeEvent();

  bool SglLTrig, DiLTrig;
  bool ElEl, MuMu, ElMu, SF2L; 
  bool DblMu, DblEG, MuEG, SglEl;
  bool DiLIncl, DiLBJet;
  bool HEMCheck, PUVETO;
  bool SystRun, IDeffP, NoPURW;
  vector<TString> TrigList, TrigList_SglMu, TrigList_SglEl, TrigList_DiMu, TrigList_DiEl, TrigList_ElMu;
  TString SFKey_Trig;


  Particle GetMETPhiTemp(TString Option);

  void AnalyzeDiMuonBJet(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl,
                         vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);
  void AnalyzeDiElectronBJet(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl,
                             vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);
  void AnalyzeDiLeptonBJet(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl,
                           vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);


  void AnalyzeDiMuon(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Electron>& EleTColl, vector<Electron>& EleLColl,
                     vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);
  void AnalyzeDiElectron(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Electron>& EleTColl, vector<Electron>& EleLColl,
                         vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);
  void AnalyzeElectronMuon(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Electron>& EleTColl, vector<Electron>& EleLColl,
                           vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);


  void CheckHEMIssue(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl,
                     vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label, TString Option);

  void  DoSystRun(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                  vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                  vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& Ev, float weight, TString Label);

  std::vector<std::pair<float,TString>> SysWgtStrPairList;


  DiLepValid();
  ~DiLepValid();

};



#endif

