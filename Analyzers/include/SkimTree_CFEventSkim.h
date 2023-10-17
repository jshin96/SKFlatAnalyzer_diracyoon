#ifndef SkimTree_CFEventSkim_h
#define SkimTree_CFEventSkim_h

#include "HNL_LeptonCore.h"

class SkimTree_CFEventSkim : public HNL_LeptonCore {

public:

  void initializeAnalyzer();
  void executeEventFromParameter(AnalyzerParameter param);
  void executeEvent();

  SkimTree_CFEventSkim();
  ~SkimTree_CFEventSkim();

  TTree *newtree;

  void WriteHist();

};



#endif
