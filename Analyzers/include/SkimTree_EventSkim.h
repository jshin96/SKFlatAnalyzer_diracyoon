#ifndef SkimTree_EventSkim_h
#define SkimTree_EventSkim_h

#include "AnalyzerCore.h"

class SkimTree_EventSkim : public AnalyzerCore {

public:

  void initializeAnalyzer();
  void executeEventFromParameter(AnalyzerParameter param);
  void executeEvent();

  SkimTree_EventSkim();
  ~SkimTree_EventSkim();

  TTree *newtree;

  void WriteHist();

};



#endif
