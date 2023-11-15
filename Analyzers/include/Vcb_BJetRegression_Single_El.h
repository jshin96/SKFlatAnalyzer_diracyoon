#ifndef Vcb_BJetRegression_Single_El_h
#define Vcb_BJetRegression_Single_El_h

#include "AnalyzerCore.h"

class Vcb_BJetRegression_Single_El : public AnalyzerCore {

public:

  void initializeAnalyzer();
  void executeEventFromParameter(AnalyzerParameter param);
  void executeEvent();

  bool RunSyst;
  bool RunNewPDF;
  bool RunXSecSyst;

  TString IsoMuTriggerName, IsoElTriggerName;
  double MuTriggerSafePtCut, ElTriggerSafePtCut;

  vector<TString> MuonIDs, MuonIDSFKeys,ElectronIDs, ElectronIDSFKeys,MuonISOSFKeys, ElectronISOSFKeys;
  vector<vector<TString>> LeptonIDs, LeptonIDSFKeys, LeptonISOSFKeys;
  vector<Muon> AllMuons, muons, muons_veto;
  vector<Electron> AllElectrons, electrons, electrons_veto;
  vector<Jet> AllJets, jets;
  vector<Gen> AllGens;
  vector<JetTagging::Parameters> jtps;
  Particle Gen_b;
  double weight_Prefire, weight_pujet_veto;

  Vcb_BJetRegression_Single_El();
  ~Vcb_BJetRegression_Single_El();

};



#endif

