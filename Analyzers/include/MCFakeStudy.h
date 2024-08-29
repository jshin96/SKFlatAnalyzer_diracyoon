#ifndef MCFakeStudy_h
#define MCFakeStudy_h

#include "AnalyzerCore.h"

class MCFakeStudy : public AnalyzerCore {

public:

  void initializeAnalyzer();
  void executeEventFromParameter(AnalyzerParameter param);
  void executeEvent();

  bool SpecTrig, NoTrig;
  bool ElFR, MuFR;
  bool LIDOpt, MeasMCFR, MCClosure, CompCheck;
  bool SystRun;
  vector<TString> TrigList_ElFR, TrigList_MuFR, TrigList_DblMu, TrigList_DblEG, TrigList_MuEG;
  TString EraShort;

  void CheckIDPerf(vector<Electron>& ElRawColl, vector<Jet>& JetCleanColl, float weight, vector<TString>& ElIDList, TString Label, TString Option);
  void CheckMVACutDist(vector<Electron>& ElColl, float weight, TString Label, TString Option="");
  void CheckIDVarDist(vector<Electron>& ElRawColl, vector<Jet>& JetCleanColl, float weight, TString ElID, TString Label, TString Option);
  void CheckSelectionEfficiency(vector<Muon>& MuRawColl, vector<Electron>& ElRawColl, vector<Jet>& JetRawColl, vector<Jet>& BJetRawColl, Particle& vMET, Event& ev,
                                TString MuTID, TString MuLID, TString ElTID, TString ElLID, float weight, TString Label);
  void MeasMCTtoLRatio(vector<Muon>& FakePreColl, vector<Jet>& JetColl, vector<double>& PtEdges, float weight, TString LooseID, TString TightID, TString Label, TString Option);
  void MeasMCTtoLRatio(vector<Electron>& FakePreColl, vector<Jet>& JetColl, vector<double>& PtEdges, float weight, TString LooseID, TString TightID, TString Label, TString Option);
  void RunTestRun(vector<Muon>& FakePreColl, vector<Jet>& JetColl, float weight, TString PreID, TString TightID, TString Label, TString Option);
  void RunTestRun(vector<Electron>& FakePreColl, vector<Jet>& JetColl, float MVACut, float IsoCut, vector<double>& PtEdges, float weight, TString PreID, TString TightID, TString Label, TString Option);

  void ScanFakeRate(vector<Muon>& FakePreColl, vector<Jet>& JetColl, TString Var1Str, TString Var2Str, float Var1Cut, float Var2Cut, vector<double>& PtEdges, float weight, TString PreID, TString TightID, TString Label, TString Option);
  void ScanFakeRate(vector<Electron>& FakePreColl, vector<Jet>& JetColl, TString Var1Str, TString Var2Str, float Var1Cut, float Var2Cut, vector<double>& PtEdges, float weight, TString PreID, TString TightID, TString Label, TString Option);
  int  GetFakeLepSrcType(Lepton& Lep, vector<Jet>& JetColl);

  float NvtxReweight(TString Key);

  bool PassFRMeasSel(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                     vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& Ev, TString Label);


  void EmulQCDFRMeas(vector<Muon>& MuRawColl, vector<Electron>& ElRawColl, vector<Jet>& JetRawColl,
                     Particle& vMET, Event& Ev, vector<Gen>& TruthColl, float weight, 
                     TString MuTID, TString MuLID, TString ElTID, TString ElLID, TString ElVID, TString Label, TString Option="");
  void CheckMCClosure(vector<Muon>& MuRawColl, vector<Electron>& ElRawColl, vector<Jet>& JetRawColl, 
                      Particle& vMET, Event& Ev, vector<Gen>& TruthColl, float weight, 
                      TString MuTID, TString MuLID, TString ElTID, TString ElLID, TString ElVID, TString Label, TString Option="");
  void CheckFakeComposition(vector<Muon>& MuRawColl, vector<Electron>& ElRawColl, vector<Jet>& JetRawColl, Particle& vMET, Event& ev,
                            TString MuTID, TString MuLID, TString ElTID, TString ElLID, TString ElVID, float weight, TString Label);


  float GetMCFakeRate(float VarX, float VarY, TString Key, int SystDir);
  float GetMCFakeWeight(vector<Muon>& MuColl, vector<Electron>& ElColl, TString MuTID, TString ElTID, TString MuFRKey, TString ElFRKey, int SystDir, float FR_MCCorr);
  float GetGenMatchFakeWeight(vector<Muon>& MuColl, vector<Electron>& ElColl, vector<Gen>& TruthColl, TString MuTID, TString ElTID, TString MuFRKey, TString ElFRKey, float FR_MCCorr);
  int   GetGenLepInfo(vector<Electron>& ElColl, vector<Muon>& MuColl, vector<Gen>& TruthColl);

  void  InitializeReader(TMVA::Reader* ThisReader, TString Option);
  void  InitializeTreeVars();

  Float_t Nj, Nb;
  Float_t Ptl1, Ptl2, MET, HT;
  Float_t dRll;
  Float_t dRlj11, dRlj12, dRlj13, dRlj21, dRlj22, dRlj23;
  Float_t MSSSF;
  Float_t MTvl1, MTllv, Ml2j1W_BkdTop, Ml2W_BkdTop, MTbl1v_BkdTop;
  Float_t MbllW_1jL, MllW_1jL, Ml1W_1jL, Ml2W_1jL;
  Float_t MbllW_1jH, Ml1W_1jH, Ml2W_1jH;
  Float_t MbllW_H, Ml1W_H, Ml2W_H; 

  vector<JetTagging::Parameters> jtps;

  TFile* FRFile; 
  std::map< TString, TH2D* > maphist_FR;
//  TGraph* gr_MVAL;

  TMVA::Reader *MVAReaderL, *MVAReaderH;
  vector<TString> MNStrListL, MNStrListH;
  vector<Gen> truthColl; 

  MCFakeStudy();
  ~MCFakeStudy();

};


#endif
