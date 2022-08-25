#ifndef HNL_ConvStudy_h
#define HNL_ConvStudy_h

#include "HNL_RegionDefinitions.h"

class HNL_ConvStudy : public HNL_RegionDefinitions {

 public:


  void initializeAnalyzer();
  void executeEvent();

  HNL_ConvStudy();
  ~HNL_ConvStudy();




};



#endif
