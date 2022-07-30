#ifndef HNL_SignalStudies_h
#define HNL_SignalStudies_h

#include "HNL_RegionDefinitions.h"

class HNL_SignalStudies : public HNL_RegionDefinitions {

 public:


  void initializeAnalyzer();
  void executeEvent();

  HNL_SignalStudies();
  ~HNL_SignalStudies();


  void RunLeptonValidation(std::vector<Lepton *> leps,std::vector<Jet> jets, std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param,  float weight_l );
  bool PassVBF(vector<Jet>  jets,std::vector<Lepton *> leps1);
  bool PassVBFv2(vector<Jet>  jets,std::vector<Lepton *> leps1);
  


  void FillAllMuonPlots(TString label , TString cut,  Muon mu, float w);
  void FillAllMuonPlots(TString label , TString cut,  std::vector<Muon> muons, float w);

  void FillAllElectronPlots(TString label , TString cut,  std::vector<Electron> els, float w);
  void RunSignalPlotter(TString process);
  // Lepton ID
  vector<TString> MuonVetoIDs;
  vector<TString> MuonLooseIDs;
  vector<TString> MuonTightIDs;
  vector<TString> ElectronVetoIDs;
  vector<TString> ElectronLooseIDs;
  // Fake rate file
  vector<TString> FakeRateIDs;
  vector<TString> ElectronTightIDs;

  bool IsUL;

  // obj vectors
  vector<Gen> gens;
  vector<Electron> AllElectrons;
  vector<Muon> AllMuons, AllTunePMuons;
  vector<Tau> AllTaus;
  vector<Jet> AllJets;
  vector<FatJet> AllFatJets;

  double weight_Prefire, weight_Prefire_Up, weight_Prefire_Down;


  double weight_PU, weight_PU_Up, weight_PU_Down;

  void MakeType1SignalPlots(TString a);

};



#endif
