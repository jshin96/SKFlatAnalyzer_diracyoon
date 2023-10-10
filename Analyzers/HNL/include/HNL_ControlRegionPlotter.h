#ifndef HNL_ControlRegionPlotter_h
#define HNL_ControlRegionPlotter_h

#include "HNL_RegionDefinitions.h"

class HNL_ControlRegionPlotter : public HNL_RegionDefinitions {

 public:


  void initializeAnalyzer();
  void executeEvent();

  HNL_ControlRegionPlotter();
  ~HNL_ControlRegionPlotter();

  void RunControlRegions(vector<HNL_LeptonCore::Channel> ChannelsToRun,AnalyzerParameter param, vector<TString> CRs);


};



#endif
