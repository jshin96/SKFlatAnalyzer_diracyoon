#ifndef KinVarPlot_h
#define KinVarPlot_h

#include "AnalyzerCore.h"

#include <iostream>
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"

class KinVarPlot : public AnalyzerCore {

public:

  void initializeAnalyzer();
  void executeEventFromParameter(AnalyzerParameter param);
  void executeEvent();

  bool OS2l, SS2l, TriLep, TetraLep; 
  bool DblMu, DblEG, MuEG,SglMu, SglEG, SingleTrigger, BDTCR;
  bool FakeRun, ConvRun, FlipRun, SystRun, GenSyst, PUVETO, ReverseBDT, POGEl, CFCorr;
  bool DiscPlots, VarPlots, EffFlow, GlobFeas, GenMatchedDist, DecCompCheck, DiscCutOpt, DiscTable, DiscCNC, TestPlot, BDTVal, UnFlipped, OrSingle;
  vector<TString> TrigList_DblMu, TrigList_DblEG, TrigList_MuEG, TrigList_SglEG,TrigList_SglMu;

  void MakePlotSS2L(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                    vector<Jet>& JetColl, vector<Jet>& BJetColl, vector<Jet>& rawJetColl, JetTagging::Parameters& param_jets, Particle& vMET, float weight, TString Label);
  void MakePlot3L(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                  vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);
  void MakePlot4L(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                  vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                  vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);
  void CheckEffFlow(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                    vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                    vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& ev, float weight, TString Label);
  void CheckDecayComposition(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                             vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                             vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& ev, float weight, TString Label);
  void CheckGenMatchedDist(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                           vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                           vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);
  void TestPlotSS2L(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                    vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);

  void  DoSystRun(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                  vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                  vector<Jet>& JetColl, vector<Jet>& BJetColl, vector<Jet>& rawJetColl, JetTagging::Parameters& param_jets, Particle& vMET, Event& Ev, float weight, TString Label);




  void InitializeTreeVars();
  void InitializeReader(TMVA::Reader* ThisReader, TString Option);
  void PlotParameters(TString Label);
  void PlotDiscriminators(TString Label);
  bool PassDiscCut(TString Mix, TString MNStr, float Disc);
  void FillGlobFeasBins2L(TString Mix, TString Label);

  float GetDataFakeRate(float VarX, float VarY, TString Key, TString Opt);
  float GetDataFakeWeight(vector<Muon>& MuColl, vector<Electron>& ElColl, vector<Jet>& rawbjetColl,
                          TString MuTID, TString ElTID, TString MuFRKey, TString ElFRKey, TString Opt);
  float GetCFRWeight(vector<Electron>& ElColl, TString Option);
  float GetCFRAndSF(float VarX, float VarY, TString Key, TString Opt);

  int   GetGenLepInfo(vector<Electron>& ElColl, vector<Muon>& MuColl, TString Option="");
  void  SetUpGenNormHists();


  vector<JetTagging::Parameters> jtps;

  vector<Gen> truthColl;
  Float_t NjPre, NbPre, NljPre;
  Float_t Nj, Nb, HEMFrac;
  Float_t Ptl1, Ptl2, MET, HT, MET_Removed, MET_Corrected, MET_Corrected_Up, MET_Corrected_Down;
  vector<int> GenJet_Matches;
  int HEM_Remove;
  Float_t dRll;
  Float_t dRlj11, dRlj12, dRlj13, dRlj21, dRlj22, dRlj23;
  Float_t MSSSF;
  Float_t MTvl1, MTllv, Ml2j1W_BkdTop, Ml2W_BkdTop, MTbl1v_BkdTop;
  Float_t MbllW_1jL, MllW_1jL, Ml1W_1jL, Ml2W_1jL;
  Float_t MbllW_1jH, Ml1W_1jH, Ml2W_1jH;
  Float_t MbllW_H, Ml1W_H, Ml2W_H; 
  Float_t Overlap_lj, Overlap_lb; 
  TLorentzVector GenJet;

  TFile* FRFile_El; TFile* FRFile_Mu; TFile* CFRFile; TFile* GenNormFile; 
  std::map< TString, TH2D* > maphist_FR;
  std::map< TString, TH1D* > maphist_GenNorm;
  std::vector<std::pair<float,TString>> SysWgtStrPairList;
  vector<Gen> TruthColl;


  Float_t w_tot, disc_BDTG;
  TMVA::Reader *MVAReaderL, *MVAReaderH;
  vector<TString> MNStrListL, MNStrListH;

  KinVarPlot();
  ~KinVarPlot();

};



#endif
