#ifndef HNL_RegionDefinitionsOpt_h
#define HNL_RegionDefinitionsOpt_h

#include "TRandom.h"

#include "HNL_LeptonCore.h"

class HNL_RegionDefinitionsOpt : public HNL_LeptonCore {

 public:

  HNL_RegionDefinitionsOpt();
  ~HNL_RegionDefinitionsOpt();

  // analyis functions to run SR
  
			
  void   RunAllSignalRegions(HNL_LeptonCore::ChargeType q, 
			     std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Tau> taus, 
			     std::vector<Jet>  all_jets, std::vector<Jet> loose_jets, std::vector<Jet> jets, std::vector<Jet> jets_vbf, std::vector<FatJet>  fatjets, 
			     std::vector<Jet> bjets,std::vector<Jet> bjetsSR1, 
			     Event ev,  Particle METv, AnalyzerParameter param,  float w);


  /// PRESEL 
  bool  PassPreselection(HNL_LeptonCore::Channel channel,HNL_LeptonCore::ChargeType q, 
			 std::vector<Lepton *> leps,std::vector<Lepton *> leps_veto,std::vector<Tau> TauColl, 
			 std::vector<Jet> jets, std::vector<Jet> vbf_jets,std::vector<FatJet>  fatjets, std::vector<Jet> bjets, 
			 Event ev, Particle METv, AnalyzerParameter param, TString channel_string ,  float w);


  //// SIGNAL REGION DEFINITIONS

  bool  RunSignalRegionAK8(HNL_LeptonCore::Channel channel,HNL_LeptonCore::ChargeType q, 
			   std::vector<Lepton *> leps,std::vector<Lepton *> leps_veto, std::vector<Tau> Taus, 
			   std::vector<Jet> jets, std::vector<FatJet>  fatjets, std::vector<Jet> bjets, 
			   Event ev,  Particle METv, AnalyzerParameter param, TString channel_string ,  float w);
  
  TString  RunSignalRegionAK8String(TString mass, HNL_LeptonCore::Channel channel,HNL_LeptonCore::ChargeType q, 
				    std::vector<Lepton *> leps,std::vector<Lepton *> leps_veto, std::vector<Tau> Taus, 
				    std::vector<Jet> jets, std::vector<FatJet>  fatjets, std::vector<Jet> bjets, 
				    Event ev,  Particle METv, AnalyzerParameter param, TString channel_string ,  float w);


  
  bool RunSignalRegionWW(HNL_LeptonCore::Channel channel,HNL_LeptonCore::ChargeType q, 
			 std::vector<Lepton *> leps,std::vector<Lepton *> leps_veto,  std::vector<Tau> Taus, 
			 std::vector<Jet> loose_jets, std::vector<Jet> jets, std::vector<FatJet>  fatjets, std::vector<Jet> bjets, 
			 Event ev,  Particle METv, AnalyzerParameter param, TString channel_string ,  float w);

  TString RunSignalRegionWWString(HNL_LeptonCore::Channel channel,HNL_LeptonCore::ChargeType q, 
				  std::vector<Lepton *> leps,std::vector<Lepton *> leps_veto,  std::vector<Tau> Taus, 
				  std::vector<Jet> loose_jets, std::vector<Jet> jets, std::vector<FatJet>  fatjets, std::vector<Jet> bjets, 
				  Event ev,  Particle METv, AnalyzerParameter param, TString channel_string ,  float w);


  bool  RunSignalRegionAK4(HNL_LeptonCore::Channel channel,HNL_LeptonCore::ChargeType q, 
			   std::vector<Lepton *> leps,std::vector<Lepton *> leps_veto,  std::vector<Tau> Taus, 
			   std::vector<Jet> jets, std::vector<FatJet>  fatjets, std::vector<Jet> bjets, 
			   Event ev,  Particle METv, AnalyzerParameter param, TString channel_string ,  float w);


  TString  RunSignalRegionAK4String(HNL_LeptonCore::Channel channel,HNL_LeptonCore::ChargeType q, 
				    std::vector<Lepton *> leps,std::vector<Lepton *> leps_veto,  std::vector<Tau> Taus, 
				    std::vector<Jet> jets, std::vector<FatJet>  fatjets, std::vector<Jet> bjets, 
				    Event ev,  Particle METv, AnalyzerParameter param, TString channel_string ,  float w);
  
  TString RunSignalRegionAK4StringBDT(TString mn, HNL_LeptonCore::Channel channel , std::vector<Lepton *> LepTCol ,
				      std::vector<Jet> JetColl,std::vector<Jet> B_JetColl, Particle METv,   Event ev);




  bool PassVBF(vector<Jet>  jets,std::vector<Lepton *> leps1, double mjj_cut,bool use_leadjet=false);
  bool PassVBFInitial(vector<Jet>  jets);
  



  double LowMassEdgeSR1(HNL_LeptonCore::Channel channel, TString mass );
  double UpperMassEdgeSR1(HNL_LeptonCore::Channel channel, TString mass );



};



#endif

