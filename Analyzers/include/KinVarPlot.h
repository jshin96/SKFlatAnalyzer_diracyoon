#ifndef KinVarPlot_h
#define KinVarPlot_h

#include "AnalyzerCore.h"

#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"

class KinVarPlot : public AnalyzerCore {

public:

  void initializeAnalyzer();
  void executeEventFromParameter(AnalyzerParameter param);
  void executeEvent();

  bool SS2l, TriLep, TetraLep; 
  bool DblMu, DblEG, MuEG;
  bool FakeRun, ConvRun, FlipRun, SystRun;
  bool VarPlots, EffFlow, GlobFeas;
  vector<TString> TrigList_DblMu, TrigList_DblEG, TrigList_MuEG;

  void MakePlotSS2L(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                    vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);
  void MakePlot3L(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                  vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);
  void MakePlot4L(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                  vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                  vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);
  void CheckEffFlow(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                    vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                    vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& ev, float weight, TString Label);
  void RunStdSyst(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                  vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                  vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);



  void InitializeTreeVars();
  void PlotParameters(TString Label);
  void FillGlobFeasBins2L(TString Mix, TString Label);
  float CalcTestFakeWeight(vector<Muon>& MuColl, vector<Electron>& ElColl, TString MuIDT, TString MuIDL, TString ElIDT, TString ElIDL, int NBJet=0, int SystDir=0);
  float GetTestMuFR(Muon& Mu, TString Key, int SystDir=0);
  float GetTestElFR(Electron& El, TString Key, int SystDir=0);
  float GetCFRSF(Electron& El, TString Tag, TString Option="");
  float GetFlipCorrPT(Electron& El, TString Tag, TString Option="");
  int   GetGenLepInfo(vector<Electron>& ElColl, vector<Muon>& MuColl, TString Option="");



  Float_t Nj, Nb, NjPre, NbPre;
  Float_t Ptl1, Ptl2, Ptj1, Ptj2, Ptj3, HT, MET2HT;
  Float_t dRll, dRlj11, dRlj12, dRlj13, dRlj21, dRlj22, dRlj23;
  Float_t MSSSF, MTvl1, MTvl2;
  Float_t MllW_2jL, MllW_1jL, MllW1_H;
  Float_t Ml1W_2jL, Ml1W_1jL, Ml2W_2jL, Ml2W_1jL, Ml1W1_H, Ml2W1_H;
  Float_t w_tot, disc_BDTG;
  Float_t MSSSFPre;
  TMVA::Reader *MVAReader;
  vector<TString> MNStrList;

  KinVarPlot();
  ~KinVarPlot();

};



#endif
