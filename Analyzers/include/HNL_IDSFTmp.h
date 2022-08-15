#ifndef HNL_IDSFTmp_h
#define HNL_IDSFTmp_h

#include "HNL_RegionDefinitions.h"

class HNL_IDSFTmp : public HNL_RegionDefinitions {

 public:


  void initializeAnalyzer();
  void executeEvent();

  HNL_IDSFTmp();
  ~HNL_IDSFTmp();

  void MeasureElectronIDSF(AnalyzerParameter param);
  void MeasureMuonIDSF(AnalyzerParameter param);
  void MeasureIDSF(HNL_LeptonCore::Channel dilep_channel, vector<Muon > LeptonColl, TString ID, double w);
  void MeasureIDSF(HNL_LeptonCore::Channel dilep_channel, vector<Electron > LeptonColl, TString ID, double w);

};



#endif
