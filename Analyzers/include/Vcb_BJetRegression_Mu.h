#ifndef Vcb_BJetRegression_Mu_h
#define Vcb_BJetRegression_Mu_h

#include "AnalyzerCore.h"

class Vcb_BJetRegression_Mu : public AnalyzerCore {

public:

  void initializeAnalyzer();
  void executeEventFromParameter(AnalyzerParameter param);
  void executeEvent();

  bool RunSyst;
  bool run_debug;
  bool RunNewPDF;
  bool RunXSecSyst;
  TString Muon_Tight_ID, Muon_Loose_ID, Electron_Loose_ID, Electron_Tight_ID;
  TString HLTMuTriggerName, HLTElTriggerName, MuTriggerName, ElTriggerName;
  double MuTriggerSafePtCut, ElTriggerSafePtCut;

  double weight_Mu_ISO_up,weight_Mu_ISO_down,weight_Mu_ID_up,weight_Mu_ID_down,weight_Mu_trig_up,weight_Mu_trig_down, weight_prefire_up, weight_prefire_down,weight_pileup_up,weight_pileup_down,weight_pu_veto_up, weight_pu_veto_down, weight_PileUp, weight_up, weight_down;

  TString MuonID, ElectronID;
  vector<Muon> AllMuons, muons, muons_veto;
  vector<Electron> AllElectrons, electrons, electrons_veto;
  vector<Jet> AllJets, jets;
  vector<Gen> AllGens;
  vector<JetTagging::Parameters> jtps;
  Particle Gen_b;

  double weight_Prefire, weight_pujet_veto;

  Vcb_BJetRegression_Mu();
  ~Vcb_BJetRegression_Mu();

};



#endif

