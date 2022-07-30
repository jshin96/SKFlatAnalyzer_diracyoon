#ifndef HNL_RegionDefinitions_h
#define HNL_RegionDefinitions_h

#include "TRandom.h"

#include "HNL_LeptonCore.h"

class HNL_RegionDefinitions : public HNL_LeptonCore {

 public:

  HNL_RegionDefinitions();
  ~HNL_RegionDefinitions();

  // analyis functions to run SR
  void RunElectronChannel(int ptbin , std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<Jet> jets_vbf,  std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param,  float w);
			  
  void RunMuonChannel(HNL_RegionDefinitions::Channel    channel, HNL_RegionDefinitions::ChargeType dilep_charge,std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto,  std::vector<Jet> jets, std::vector<Jet> jets_vbf,  std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param,  float w);


  bool  RunSignalRegionAK8(HNL_RegionDefinitions::Channel channel,HNL_RegionDefinitions::ChargeType q, std::vector<Lepton *> leps,std::vector<Lepton *> leps_veto, std::vector<Jet> jets, std::vector<FatJet>  fatjets, TString bjet_wp, Particle METv, AnalyzerParameter param, TString channel_string ,  float w);
  bool  RunSignalRegionAK8(HNL_RegionDefinitions::Channel channel,HNL_RegionDefinitions::ChargeType q,std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet>  fatjets, TString bjet_wp, Event Ev, AnalyzerParameter param, TString channel_string ,  float w);



  bool RunSignalRegionWW(HNL_RegionDefinitions::Channel channel,HNL_RegionDefinitions::ChargeType q,std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet>  fatjets, TString bjet_wp, Event ev, AnalyzerParameter param, TString channel_string ,  float w);


  bool  RunSignalRegionAK4(HNL_RegionDefinitions::Channel channel,HNL_RegionDefinitions::ChargeType q,std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet>  fatjets, TString bjet_wp, Event ev, AnalyzerParameter param, TString channel_string ,  float w);



  bool RunSignalRegionTrilepton(HNL_RegionDefinitions::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet>  fatjets, TString bjet_wp, Event ev, AnalyzerParameter param, TString channel_string ,  float w);

 // bool RunElectronChannelSR4(HNL_RegionDefinitions::Channel channel ,std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet>  fatjets, TString bjet_wp,  Event ev, AnalyzerParameter param,  TString channel_string ,float w);

  bool PassVBF(vector<Jet>  jets,std::vector<Lepton *> leps1);
  bool PassVBFInitial(vector<Jet>  jets);
  



};



#endif

