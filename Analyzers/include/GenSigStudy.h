#ifndef GenSigStudy_h
#define GenSigStudy_h

#include "AnalyzerCore.h"

class GenSigStudy : public AnalyzerCore {

public:

  void initializeAnalyzer();
  void executeEvent();

  bool All2l, SS2l, OS2l; 
  bool TrAccCheck, TrRateCheck; 
  bool DblMu, DblEG, MuEG;
  bool FakeRun, ConvRun, FlipRun, SystRun;
  vector<TString> TrigList_DblMu, TrigList_DblEG, TrigList_MuEG, TrigList_SglMu, TrigList_SglEl;

  void TrigAccCheck(float weight, TString Label);
  void RecoTrigRateCheck(vector<Muon>& MuPreColl, vector<Electron>& ElPreColl, Event& Ev, TString MuTID, TString ElTID, float weight, TString Label);

  void GetMassDists(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                    vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                    vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);
  void CheckMCCFClosure(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                        vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                        vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);
  float GetTmpCFRate(float PT, float fEta);
  void CheckChargeFlip(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                       vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                       vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);
  void MeasMCCFRate(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                    vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                    vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);
  void MeasMCPTScale(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                     vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                     vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);



  float CalcTestFakeWeight(vector<Muon>& MuColl, vector<Electron>& ElColl, TString MuIDT, TString MuIDL, TString ElIDT, TString ElIDL, int NBJet=0, int SystDir=0);
  float GetTestMuFR(Muon& Mu, TString Key, int SystDir=0);
  float GetTestElFR(Electron& El, TString Key, int SystDir=0);
  float GetCFRSF(Electron& El, TString Tag, TString Option="");
  float GetFlipCorrPT(Electron& El, TString Tag, TString Option="");
  float GetMCCFR(float VarX, float VarY, TString Key);



  vector<Gen> truthColl;

  GenSigStudy();
  ~GenSigStudy();

};



#endif
