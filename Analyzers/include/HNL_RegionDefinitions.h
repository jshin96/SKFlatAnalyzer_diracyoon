#ifndef HNL_RegionDefinitions_h
#define HNL_RegionDefinitions_h

#include "TRandom.h"

#include "HNL_LeptonCore.h"

class HNL_RegionDefinitions : public HNL_LeptonCore {

 public:

  HNL_RegionDefinitions();
  ~HNL_RegionDefinitions();

  // analyis functions to run SR
  //  void RunElectronChannel(int ptbin , std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<Jet> jets_vbf,  std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param,  float w);
			  
  //void RunMuonChannel(HNL_LeptonCore::Channel    channel, HNL_LeptonCore::ChargeType dilep_charge,std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto,  std::vector<Jet> jets, std::vector<Jet> jets_vbf,  std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param,  float w);
  

  //// SIGNAL REGION DEFINITIONS

  bool  RunSignalRegionAK8(HNL_LeptonCore::Channel channel,HNL_LeptonCore::ChargeType q, std::vector<Lepton *> leps,std::vector<Lepton *> leps_veto, std::vector<Jet> jets, std::vector<FatJet>  fatjets, TString bjet_wp, Particle METv, AnalyzerParameter param, TString channel_string ,  float w);
  bool  RunSignalRegionAK8(HNL_LeptonCore::Channel channel,HNL_LeptonCore::ChargeType q,std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet>  fatjets, TString bjet_wp, Event Ev, AnalyzerParameter param, TString channel_string ,  float w);


  
  bool RunSignalRegionWW(HNL_LeptonCore::Channel channel,HNL_LeptonCore::ChargeType q,std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet>  fatjets, TString bjet_wp, Event ev, AnalyzerParameter param, TString channel_string ,  float w);
  bool RunSignalRegionWW(HNL_LeptonCore::Channel channel,HNL_LeptonCore::ChargeType q, std::vector<Lepton *> leps,std::vector<Lepton *> leps_veto, std::vector<Jet> jets, std::vector<FatJet>  fatjets, TString bjet_wp, Particle METv, AnalyzerParameter param, TString channel_string ,  float w);


  bool  RunSignalRegionAK4(HNL_LeptonCore::Channel channel,HNL_LeptonCore::ChargeType q,std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet>  fatjets, TString bjet_wp, Event ev, AnalyzerParameter param, TString channel_string ,  float w);
  bool  RunSignalRegionAK4(HNL_LeptonCore::Channel channel,HNL_LeptonCore::ChargeType q, std::vector<Lepton *> leps,std::vector<Lepton *> leps_veto, std::vector<Jet> jets, std::vector<FatJet>  fatjets, TString bjet_wp, Particle METv, AnalyzerParameter param, TString channel_string ,  float w);


  bool RunSignalRegionTrilepton(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet>  fatjets, TString bjet_wp, Event ev, AnalyzerParameter param, TString channel_string ,  float w);
  bool RunSignalRegionTrilepton(HNL_LeptonCore::Channel channel, std::vector<Lepton *> leps,std::vector<Lepton *> leps_veto, std::vector<Jet> jets, std::vector<FatJet>  fatjets, TString bjet_wp, Particle METv, AnalyzerParameter param, TString channel_string ,  float w);

 // bool RunElectronChannelSR4(HNL_LeptonCore::Channel channel ,std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet>  fatjets, TString bjet_wp,  Event ev, AnalyzerParameter param,  TString channel_string ,float w);

  bool PassVBF(vector<Jet>  jets,std::vector<Lepton *> leps1, bool use_leadjet=false);
  bool PassVBFInitial(vector<Jet>  jets);
  

  // CR

  void RunMuonChannelCR(std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<Jet> jets_vbf, std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param,  float weight_mm );
  void RunElectronChannelCR(std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets,std::vector<Jet> jets_vbf, std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param,  float weight_mm );


  bool FillOSPreselectionPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto , std::vector<Jet> jets_vbf, std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param, float w);
  bool FillSSPreselectionPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto , std::vector<Jet> jets_vbf, std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param, float w);
  bool FillSSVBFPreselectionPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto , std::vector<Jet> jets_vbf, std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param, float w);


  bool FillZZCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param, float w);
  bool FillZZ2CRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param, float w);

  bool FillZCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param, float w);
  bool FillZNPCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param, float w);

  bool FillTopCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param, float w);
  bool FillWWCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param, float w);
  bool FillWWNPCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param, float w);

  bool FillWZCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param, float w);
  bool FillWZ2CRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param, float w);
  bool FillWZBCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param, float w);

  bool FillZGCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param, float w);
  bool FillWGCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param, float w);

  bool FillHighMassSR1CRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param, float w);
  bool FillHighMassSR2CRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param, float w);

  bool FillHighMass1JetCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param, float w);
  bool FillHighMassBJetCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param, float w);
  bool FillHighMassNPCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet> fatjets,  Event ev, AnalyzerParameter param, float w);







};



#endif

