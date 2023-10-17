#ifndef SkimTree_FakeEventSkim_h
#define SkimTree_FakeEventSkim_h

#include "HNL_LeptonCore.h"

class SkimTree_FakeEventSkim : public HNL_LeptonCore {

public:

  void initializeAnalyzer();
  void executeEventFromParameter(AnalyzerParameter param);
  void executeEvent();

  SkimTree_FakeEventSkim();
  ~SkimTree_FakeEventSkim();

  TTree *newtree;

  void WriteHist();

};



#endif
