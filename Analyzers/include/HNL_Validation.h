#ifndef HNL_Validation_h
#define HNL_Validation_h

#include "HNL_RegionDefinitions.h"

class HNL_Validation : public HNL_RegionDefinitions {

 public:


  void initializeAnalyzer();
  void executeEvent();

  HNL_Validation();
  ~HNL_Validation();



  void RunULAnalysis(AnalyzerParameter param);
  void RunEXO17028Analysis(AnalyzerParameter param);

  ///void RunMuonChannel(std::vector<Lepton *> LepsT,std::vector<Lepton *> LepsV,std::vector<Tau> TauColl,  std::vector<Jet> JetColl, std::vector<Jet> VBFJetColl,  std::vector<FatJet> FatjetColl,  std::vector<Jet> bjets, Event Ev, AnalyzerParameter param,  float _weight)   ;


};



#endif
