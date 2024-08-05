#ifndef HNL_LRSM_h
#define HNL_LRSM_h

#include "HNL_RegionDefinitions.h"

class HNL_LRSM : public HNL_RegionDefinitions {

 public:


  void initializeAnalyzer();
  void executeEvent();

  HNL_LRSM();
  ~HNL_LRSM();



};



#endif
