#ifndef HNL_FakeRateOpt_h
#define HNL_FakeRateOpt_h

#include "HNL_LeptonCore.h"


class HNL_FakeRateOpt  : public HNL_LeptonCore {

 public:

  void initializeAnalyzer();
  void executeEventFromParameter(AnalyzerParameter param, TString El_ID, TString channel);
  void RunE(std::vector<Electron> electrons, std::vector<Muon> muons, std::vector<Jet> jets,AnalyzerParameter param,  float w);
  void RunM(std::vector<Electron> electrons, std::vector<Muon> muons, std::vector<Jet> jets, AnalyzerParameter param,  float w);

  TString SingleElectronPD(TString hlt);
  TString SingleMuonPD(TString hlt);
			 
  
  void executeEvent();

  HNL_FakeRateOpt();
  ~HNL_FakeRateOpt();

  bool isEE;
  bool isMM;
  bool isSingleMu;


  void FillRegionPlots( TString label_1,  std::vector<Jet> jets,  std::vector<Electron> els, std::vector<Muon> mus, Particle  met,  double w);
				  
				    
  void GetFakeRates(std::vector<Lepton *> leps,std::vector<bool> blepsT,  AnalyzerParameter param,TString tightlabel,  std::vector<Jet> jets,  std::vector<Jet> lljets, TString tag,float event_weight, float isocut);
					   
  void GetFakeRateAndPromptRates(std::vector<Lepton *> leps,std::vector<bool> blepsT,AnalyzerParameter param, TString label, float event_weight, float isocut);

  
  float GetPrescale( std::vector<Lepton *> leps);

  void MakeFakeRatePlots(TString label, TString mutag,AnalyzerParameter param,  std::vector<Lepton *> leps , std::vector<bool> blepsT, std::vector<Jet> jets, std::vector<Jet> alljets, float event_weight, float isocut, Particle MET);
			 
  void MakePromptRatePlots(TString label, TString mutag,AnalyzerParameter param,  std::vector<Lepton *> leps , std::vector<bool> lepsT, std::vector<Jet> jets, std::vector<Jet> alljets, float event_weight, float isocut, Particle MET);
			   
  
  bool UseEvent(std::vector<Lepton *> leps,   std::vector< Jet> jets, float awayjetcut, Particle MET, float wt);


  // Lepton ID
  vector<TString> MuonVetoIDs;
  vector<TString> MuonLooseIDs;
  vector<TString> MuonTightIDs;
  vector<TString> ElectronVetoIDs;
  vector<TString> ElectronLooseIDs;
  // Fake rate file
  vector<TString> FakeRateIDs;
  vector<TString> ElectronTightIDs;



  // Lepton pT cut
  double MuonPtCut1;
  double MuonPtCut2;
  double ElectronPtCut1;
  double ElectronPtCut2;
  double EMuPtCut1;
  double EMuPtCut2;

  vector<Gen> gens;

  vector<Electron> AllElectrons;
  vector<Muon> AllMuons, AllTunePMuons;
  vector<Jet> AllJets;
  vector<FatJet> AllFatJets;

  double weight_Prefire, weight_Prefire_Up, weight_Prefire_Down;

  vector<TString> Triggers_Electron, Triggers_Muon;
  TString TriggerNameForSF_Electron, TriggerNameForSF_Muon;
  double TriggerSafePt_Electron, TriggerSafePt_Muon;


  //==== My tool

  void FilAllElectronPlots(TString label , TString cut,  std::vector<Electron> els, float w);

  void FilAllMuonPlots(TString label , TString cut,  std::vector<Muon> mus, float w);

  double MT(Particle a, Particle b);

  void FillRegionPlots(int channel, bool plotCR,TString label_1, TString label_2,  std::vector<Jet> jets,std::vector<Electron> els, std::vector<Muon> mus, Particle  met, double nvtx, double w);


  int GetNBJets();

  //==== pileup
  int N_VTX;
  double weight_PU, weight_PU_Up, weight_PU_Down;

  void FillWeightHist(TString label, double _weight);
  void FillCutFlow(bool IsCentral, TString suffix, TString histname, double weight);
  void FillEventCutflow(int charge_s,int version,float wt,TString cut,    TString label);


};



#endif

