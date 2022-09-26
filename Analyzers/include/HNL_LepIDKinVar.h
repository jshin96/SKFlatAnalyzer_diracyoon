#ifndef HNL_LepIDKinVar_h
#define HNL_LepIDKinVar_h

#include "HNL_RegionDefinitions.h"

class HNL_LepIDKinVar : public HNL_RegionDefinitions {

 public:

  void initializeAnalyzer();
  void executeEventFromParameter(AnalyzerParameter param);
  void executeEvent();

  bool SS2l, TriLep, TetraLep; 
  bool DblMu, DblEG, MuEG;
  bool SystRun;
  vector<TString> TrigList_DblMu, TrigList_DblEG, TrigList_MuEG;

  void MakeTreeSS2L(HNL_LeptonCore::Channel, vector<Lepton *>  LepTColl,
		    vector<Muon>Muons,
		    vector<Electron> Electrons,
                    vector<Jet>& JetAllColl,
		    float weight, TString Label);

  TTree *tree_mm;
  TTree *tree_ee;

  void WriteHist();
  void InitializeTreeVars();

  Float_t Ptl1, Ptl2, Etal1, Etal2;
  Float_t PtRatiol1, PtRatiol2, PtRatioAJl1, PtRatioAJl2, PtRelv0l1, PtRelv1l1, PtRelv0l2, PtRelv1l2;
  Float_t CEMFracAJl1, CEMFracAJl2, NEMFracAJl1, NEMFracAJl2, CHFracAJl1, CHFracAJl2, NHFracAJl1, NHFracAJl2, MuFracAJl1, MuFracAJl2, JetDiscAJl1, JetDiscAJl2;
  Float_t CEMFracCJl1, CEMFracCJl2, NEMFracCJl1, NEMFracCJl2, CHFracCJl1, CHFracCJl2, NHFracCJl1, NHFracCJl2, MuFracCJl1, MuFracCJl2, JetDiscCJl1, JetDiscCJl2;
  Float_t Dxyl1,Dxyl2,Dzl1,Dzl2,RelIsol1,RelIsol2,IP3Dl1,IP3Dl2,MVAl1,MVAl2,Chi2l1,Chi2l2, Minirelisol1,Minirelisol2,Full5x5_sigmaIetaIetal1,Full5x5_sigmaIetaIetal2,dEtaSeedl1,dEtaSeedl2,dPhiInl1,dPhiInl2,HoverEl1,HoverEl2,TrkIsol1,TrkIsol2,InvEminusInvP_l1,InvEminusInvP_l2,ecalPFClusterIsol1,ecalPFClusterIsol2,hcalPFClusterIsol1,hcalPFClusterIsol2;

  Int_t isEcalDrivenl1,isEcalDrivenl2,Pixel_hitsl1,Pixel_hitsl2;
  Int_t Validhitsl1,Validhitsl2,Matched_stationsl1,Matched_stationsl2,Tracker_layersl1,Tracker_layersl2,MissingHitsl1,MissingHitsl2;
  Int_t POGTightl1,POGTightl2, POGMediuml1,POGMediuml2;
  Int_t PassConversionVetol1,PassConversionVetol2,IsGsfCtfScPixChargeConsistentl1,IsGsfCtfScPixChargeConsistentl2;
  Float_t w_tot;

  HNL_LepIDKinVar();
  ~HNL_LepIDKinVar();

};



#endif
