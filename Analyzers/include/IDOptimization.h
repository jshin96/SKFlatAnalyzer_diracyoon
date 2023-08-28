#ifndef IDOptimization_h
#define IDOptimization_h

#include "AnalyzerCore.h"

class IDOptimization : public AnalyzerCore {

public:

  void initializeAnalyzer();
  void executeEventFromParameter(AnalyzerParameter param);
  void executeEvent();

  bool MuID, ElID, ZData; 
  bool IDVarDist, IDCutFlow, TrigCutCheck, SelEffCheck, MultiIsoTest;
  bool DblMu, DblEG, MuEG;
  bool SystRun;
  vector<TString> TrigList_DblMu, TrigList_DblEG;
  vector<Gen> truthColl;


  void CheckIDVar_MC(vector<Muon>& MuRawColl, vector<Electron>& ElRawColl, vector<Jet>& JetRawColl,
                     float weight, TString MuLID, TString ElLID, TString Label, TString Option);
  void CheckIDCutFlow(vector<Muon>& MuRawColl, vector<Electron>& ElRawColl, vector<Jet>& JetNoVetoColl, vector<Gen>& TruthColl, float weight, TString Label, TString Option);
  void CheckTrigCutInDist(vector<Muon>& MuRawColl, vector<Electron>& ElRawColl, vector<Jet>& JetRawColl, float weight,
                          TString MuLID, TString ElLID, TString Label, TString Option);


  void CheckMultiIso(vector<Muon>& MuPreColl, vector<Electron>& ElPreColl, vector<Jet>& JetNoVetoColl, vector<Jet>& BJetNoVetoColl,
                     Particle& vMET, vector<Gen>& TruthColl, Event& ev, float weight, TString Label);
  void CheckSelectionEfficiency(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuRawColl,
                                vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElRawColl,
                                vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& ev, float weight, TString Label);

  void TEST(vector<Muon>& MuRawColl, vector<Electron>& ElRawColl,
            vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& ev, float weight, TString Label);





  IDOptimization();
  ~IDOptimization();

};



#endif

