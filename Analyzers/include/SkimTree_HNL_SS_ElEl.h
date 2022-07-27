#ifndef SkimTree_HNL_SS_ElEl_h
#define SkimTree_HNL_SS_ElEl_h

#include "HNL_LeptonCore.h"


class SkimTree_HNL_SS_ElEl : public HNL_LeptonCore {


public:

  void initializeAnalyzer();
  void executeEventFromParameter(AnalyzerParameter param);
  void executeEvent();

  SkimTree_HNL_SS_ElEl();
  ~SkimTree_HNL_SS_ElEl();

  TTree *newtree;
  void WriteHist();

};



#endif
