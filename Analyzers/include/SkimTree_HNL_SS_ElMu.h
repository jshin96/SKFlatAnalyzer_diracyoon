#ifndef SkimTree_HNL_SS_ElMu_h
#define SkimTree_HNL_SS_ElMu_h

#include "HNL_LeptonCore.h"


class SkimTree_HNL_SS_ElMu : public HNL_LeptonCore {


public:

  void initializeAnalyzer();
  void executeEventFromParameter(AnalyzerParameter param);
  void executeEvent();

  SkimTree_HNL_SS_ElMu();
  ~SkimTree_HNL_SS_ElMu();

  TTree *newtree;
  void WriteHist();

};



#endif
