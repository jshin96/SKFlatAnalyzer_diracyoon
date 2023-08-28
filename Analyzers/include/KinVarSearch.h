#ifndef KinVarSearch_h
#define KinVarSearch_h

#include "AnalyzerCore.h"

class KinVarSearch : public AnalyzerCore {

public:

  void initializeAnalyzer();
  void executeEventFromParameter(AnalyzerParameter param);
  void executeEvent();

  bool SS2l, TriLep, TetraLep; 
  bool DblMu, DblEG, MuEG;
  bool SystRun;
  vector<TString> TrigList_DblMu, TrigList_DblEG, TrigList_MuEG;

  void MakeTreeSS2L(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl, vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                    vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label);

  TTree *tree_mm;
  TTree *tree_ee;
  void WriteHist();
  void InitializeTreeVars();

  vector<JetTagging::Parameters> jtps;

  Int_t Nj, Nb;
  Float_t Ptl1, Ptl2, Ptj1, Ptj2, Ptj3, MET, HT;
  Float_t dRll;
  Float_t dRlj11, dRlj12, dRlj13, dRlj21, dRlj22, dRlj23;
  Float_t dRlb11, dRlb21, dRlnb11, dRlnb21;
  Float_t MSSSF;
  Float_t MTvl1, MTllv, Ml2j1W_BkdTop, Ml2W_BkdTop, MTbl1v_BkdTop, Ml1v_BkdTop, Mbl1v_BkdTop;
  Float_t MbllW_1jL, MllW_1jL, Ml1W_1jL, Ml2W_1jL;
  Float_t MbllW_1jH, MllW_1jH, Ml1W_1jH, Ml2W_1jH;
  Float_t MbllW_H, Ml1W_H, Ml2W_H; 
  Float_t w_tot;


  KinVarSearch();
  ~KinVarSearch();

};



#endif
