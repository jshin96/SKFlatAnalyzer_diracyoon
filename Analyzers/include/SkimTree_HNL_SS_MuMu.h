#ifndef SkimTree_HNL_SS_MuMu_h
#define SkimTree_HNL_SS_MuMu_h

#include "HNL_LeptonCore.h"


class SkimTree_HNL_SS_MuMu : public HNL_LeptonCore {


public:

  void initializeAnalyzer();
  void executeEventFromParameter(AnalyzerParameter param);
  void executeEvent();

  SkimTree_HNL_SS_MuMu();
  ~SkimTree_HNL_SS_MuMu();

  TTree *newtree;
  void WriteHist();

};



#endif
