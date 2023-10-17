#ifndef SkimTree_ConvEventSkim_h
#define SkimTree_ConvEventSkim_h

#include "HNL_LeptonCore.h"

class SkimTree_ConvEventSkim : public HNL_LeptonCore {

public:

  void initializeAnalyzer();
  void executeEventFromParameter(AnalyzerParameter param);
  void executeEvent();

  SkimTree_ConvEventSkim();
  ~SkimTree_ConvEventSkim();

  TTree *newtree;

  void WriteHist();

};



#endif
