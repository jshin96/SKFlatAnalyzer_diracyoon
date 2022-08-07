#ifndef HNL_ControlRegionPlotter_h
#define HNL_ControlRegionPlotter_h

#include "HNL_RegionDefinitions.h"

class HNL_ControlRegionPlotter : public HNL_RegionDefinitions {

 public:


  void initializeAnalyzer();
  void executeEvent();

  HNL_ControlRegionPlotter();
  ~HNL_ControlRegionPlotter();



  void RunMuonChannel(std::vector<Lepton *> LepsT,std::vector<Lepton *> LepsV,std::vector<Tau> TauColl,  std::vector<Jet> JetColl, std::vector<Jet> VBFJetColl,  std::vector<FatJet> FatjetColl,  std::vector<Jet> bjets, Event Ev, AnalyzerParameter param,  float _weight)   ;


};



#endif
