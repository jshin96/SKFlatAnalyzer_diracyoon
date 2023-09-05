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


  vector<Gen> truthColl;

  GenSigStudy();
  ~GenSigStudy();

};



#endif
