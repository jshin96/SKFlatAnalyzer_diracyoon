#ifndef HNL_SignalStudies_h
#define HNL_SignalStudies_h

#include "HNL_RegionDefinitions.h"

class HNL_SignalStudies : public HNL_RegionDefinitions {

 public:


  void initializeAnalyzer();
  void executeEvent();

  HNL_SignalStudies();
  ~HNL_SignalStudies();



  void RunMuonChannel(std::vector<Electron> ElectronColl, std::vector<Electron> VetoElectronColl, std::vector<Muon> MuonColl,  std::vector<Muon> VetoMuonColl,std::vector<Tau> TauColl,  std::vector<Jet> JetColl, std::vector<Jet> VBFJetColl,  std::vector<FatJet> FatjetColl,  std::vector<Jet> bjets, Event Ev, AnalyzerParameter param,  float _weight)   ;


  void RunSignalPlotter(TString process);
  void MakeType1SignalPlots(TString a);

};



#endif
