#ifndef ControlPlots_h
#define ControlPlots_h

#include "AnalyzerCore.h"

class ControlPlots : public AnalyzerCore {

public:

  void initializeAnalyzer();
  void executeEventFromParameter(AnalyzerParameter param);
  void executeEvent();

  bool OS2l, SS2l, TriLep, TetraLep, TopCR_OS2l, TopBSrc, SB_SS2L, SB_OS2L, CFlip, ConvCR, FkCR3l; 
  bool ConvSrcDep, TrigClos, TypeFRCheck;
  bool DblMu, DblEG, MuEG, SglEl;
  bool FakeRun, ConvRun, FlipRun, SystRun;
  vector<TString> TrigList_DblMu, TrigList_DblEG, TrigList_MuEG, TrigList_SglEl;


  void CheckTrigMCClos(vector<Muon>& MuTColl, vector<Muon>& MuVColl, vector<Electron>& ElTColl, vector<Electron>& ElVColl,
                       vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& Ev, float weight, TString Label);
  void CheckFkCR3l(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                   vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                   vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& Ev, float weight, TString Label);
  void CheckConvCR(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                   vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                   vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, Event& Ev, float weight, TString Label);
  void CheckConvVar(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                    vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                    vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);
  void CheckConvSrcDep(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                       vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                       vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);
  void PlotTop2LCR_OS2L(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                        vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                        vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);
  void CheckTopBSrc(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                    vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                    vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);
  void CheckChargeFlip(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                       vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                       vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);
  void MakePlotSS2L(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                    vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);
  void SetVarSS2L(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                  vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                  vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);


  float GetDataFakeRate(float VarX, float VarY, TString Key, TString Opt);
  float GetDataFakeWeight(vector<Muon>& MuColl, vector<Electron>& ElColl,
                          TString MuTID, TString ElTID, TString MuFRKey, TString ElFRKey, TString Opt);
  float GetCFRWeight(vector<Electron>& ElColl, TString Option);
  float GetCFRAndSF(float VarX, float VarY, TString Key, TString Opt);

  float CalcTestFakeWeight(vector<Muon>& MuColl, vector<Electron>& ElColl, TString MuIDT, TString MuIDL, TString ElIDT, TString ElIDL, int NBJet=0, int SystDir=0);
  float GetTestMuFR(Muon& Mu, TString Key, int SystDir=0);
  float GetTestElFR(Electron& El, TString Key, int SystDir=0);
  float GetCFRSF(Electron& El, TString Tag, TString Option="");
  float GetConvSF(TString ElTID, int SystDir);
  float GetFlipCorrPT(Electron& El, TString Tag, TString Option="");
  int   GetGenLepInfo(vector<Electron>& ElColl, vector<Muon>& MuColl, TString Option="");


  void InitializeTreeVars();
  void InitializeReader();
  void PlotParameters(TString Label);
  void PlotParametersSS(TString Label);

  vector<Gen> truthColl;

  Float_t Nj, Nb;
  Float_t Ptl1, Ptl2, Ptj1, Ptj2, Ptj3, HT, MET2HT;
  Float_t dRll, dRlj11, dRlj12, dRlj13, dRlj21, dRlj22, dRlj23;
  Float_t MSSSF, MTvl1, MTvl2;
  Float_t MllW_2jL, MllW_1jL, MllW1_H, Ml1W_2jL, Ml1W_1jL, Ml2W_2jL, Ml2W_1jL, Ml1W1_H, Ml2W1_H;
  Float_t w_tot;

  TFile* FRFile_El; TFile* FRFile_Mu; TFile* CFRFile; 
  std::map< TString, TH2D* > maphist_FR;

  TMVA::Reader *MVAReader;
  vector<TString> MNStrList;

  ControlPlots();
  ~ControlPlots();

};



#endif
