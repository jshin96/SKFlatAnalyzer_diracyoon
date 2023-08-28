#include "Electron.h"

ClassImp(Electron)

Electron::Electron(){

  j_En_up=1.;
  j_En_down=1.;;
  j_Res_up = 1.;
  j_Res_down = 1.;

  j_scEta = -999.;
  j_scPhi = -999.;
  j_scE = -999.;
  j_mvaiso = -999.;
  j_mvanoiso = -999.;
  j_EnergyUnCorr = -999.;
  j_passConversionVeto = false;
  j_NMissingHits = 0;
  j_Full5x5_sigmaIetaIeta = -999.;
  j_dEtaSeed = -999.;
  j_dPhiIn = -999.;
  j_HoverE  = -999.;
  j_InvEminusInvP = -999.;
  j_e2x5OverE5x5 = -999.;
  j_e1x5OverE5x5 = -999.;
  j_trkiso = -999.;
  j_dr03EcalRecHitSumEt = -999.;
  j_dr03HcalDepth1TowerSumEt = -999.;
  j_dr03HcalTowerSumEt = -999.;
  j_dr03TkSumPt = -999.;
  j_ecalPFClusterIso = -999.;
  j_hcalPFClusterIso = -999.;
  j_isEcalDriven = false;
  j_IDBit = 0;
  j_IDCutBit.clear();
  j_Rho = -999.;
  j_isGsfCtfScPixChargeConsistent = false;
  this->SetLeptonFlavour(ELECTRON);
}

Electron::~Electron(){

}

void Electron::SetEnShift(double en_up, double en_down){
  j_En_up = en_up;
  j_En_down = en_down;
}

void Electron::SetResShift(double res_up, double res_down){
  j_Res_up = res_up;
  j_Res_down = res_down;
}

void Electron::SetSC(double sceta, double scphi, double sce){
  j_scEta = sceta;
  j_scPhi = scphi;
  j_scE = sce;
}

void Electron::SetMVA(double mvaiso, double mvanoiso){
  j_mvaiso = mvaiso;
  j_mvanoiso = mvanoiso;
}

void Electron::SetUncorrE(double une){
  j_EnergyUnCorr = une;
}

void Electron::SetPassConversionVeto(bool b){
  j_passConversionVeto = b;
}

void Electron::SetNMissingHits(int n){
  j_NMissingHits = n;
}

void Electron::SetCutBasedIDVariables(
    double Full5x5_sigmaIetaIeta,
    double dEtaSeed,
    double dPhiIn,
    double HoverE,
    double InvEminusInvP,
    double e2x5OverE5x5,
    double e1x5OverE5x5,
    double trackIso,
    double dr03EcalRecHitSumEt,
    double dr03HcalDepth1TowerSumEt,
    double dr03HcalTowerSumEt,
    double dr03TkSumPt,
    double ecalPFClusterIso,
    double hcalPFClusterIso,
    int ecalDriven
  ){
  j_Full5x5_sigmaIetaIeta = Full5x5_sigmaIetaIeta;
  j_dEtaSeed = dEtaSeed;
  j_dPhiIn = dPhiIn;
  j_HoverE = HoverE;
  j_InvEminusInvP = InvEminusInvP;
  j_e2x5OverE5x5 = e2x5OverE5x5;
  j_e1x5OverE5x5 = e1x5OverE5x5;
  j_trkiso = trackIso;
  j_dr03EcalRecHitSumEt = dr03EcalRecHitSumEt;
  j_dr03HcalDepth1TowerSumEt = dr03HcalDepth1TowerSumEt;
  j_dr03HcalTowerSumEt = dr03HcalTowerSumEt;
  j_dr03TkSumPt = dr03TkSumPt;
  j_ecalPFClusterIso = ecalPFClusterIso;
  j_hcalPFClusterIso = hcalPFClusterIso;

  if(ecalDriven==0) j_isEcalDriven = false;
  else j_isEcalDriven = true;
}

void Electron::SetIDBit(unsigned int idbit){
  j_IDBit = idbit;
}

void Electron::SetIDCutBit(vector<int> idcutbit){
  j_IDCutBit = idcutbit;
}

void Electron::SetRelPFIso_Rho(double r){
  j_RelPFIso_Rho = r;
  this->SetRelIso(r);
}

double Electron::EA(){

  //==== RecoEgamma/ElectronIdentification/data/Fall17/effAreaElectrons_cone03_pfNeuHadronsAndPhotons_94X.txt
  
  double eta = fabs(this->scEta());

  if     (eta<1.000) return 0.1440;
  else if(eta<1.479) return 0.1562;
  else if(eta<2.000) return 0.1032;
  else if(eta<2.200) return 0.0859;
  else if(eta<2.300) return 0.1116;
  else if(eta<2.400) return 0.1321;
  else if(eta<2.500) return 0.1654;
  else return 0.1654;

}

bool Electron::PassID(TString ID) const{

  //==== XXX veto Gap Always
  if(etaRegion()==GAP) return false;
  if(ID=="NoID") return true;

  //==== POG
  if(ID=="passVetoID") return passVetoID();
  if(ID=="passLooseID") return passLooseID();
  if(ID=="passMediumID") return passMediumID();
  if(ID=="passTightID") return passTightID();
  if(ID=="passHEEPID") return passHEEPID();
  if(ID=="passHEEPID2018Prompt") return passHEEP2018Prompt();
  if(ID=="passMVAID_noIso_WP80") return passMVAID_noIso_WP80();
  if(ID=="passMVAID_noIso_WP90") return passMVAID_noIso_WP90();
  if(ID=="passMVAID_noIso_WPLoose") return passMVAID_noIso_WPLoose();
  if(ID=="passMVAID_iso_WP80") return passMVAID_iso_WP80();
  if(ID=="passMVAID_iso_WP90") return passMVAID_iso_WP90();
  if(ID=="passMVAID_iso_WPLoose") return passMVAID_iso_WPLoose();
  //==== Customized
  if(ID=="SUSYTight") return Pass_SUSYTight();
  if(ID=="SUSYLoose") return Pass_SUSYLoose();
  if(ID=="NOCUT") return true;
  if(ID=="TESTT") return Pass_TESTID();
  if(ID=="TESTL") return Pass_TESTIDL();
  if(ID=="POGMVAniWP90_Isop1") return (passMVAID_noIso_WP90() and RelIso()<0.1);
  if(ID=="POGMVAniWP90_Isop4") return (passMVAID_noIso_WP90() and RelIso()<0.4);
  if(ID=="HctoWA16T"){
    if(!passMVAID_iso_WP90()) return false;
    if(!(RelIso()<0.06)) return false;
    if(!(fabs(dXY())<0.025 && fabs(dZ())<0.1)) return false; 
    if(! (SIP2D()<4.) ) return false;
    if(!PassConversionVeto()) return false;
    if(!Pass_CaloIdL_TrackIdL_IsoVL_HctoWA()) return false;
    if(!(fabs(Eta())<2.5)) return false;
    return true;
  }
  if(ID=="HctoWA16L"){
    float fEta=fabs(Eta());
    if     (fEta<0.8  ){ if(MVAIso()<-0.92) return false; }
    else if(fEta<1.479){ if(MVAIso()<-0.88) return false; }
    else if(fEta<2.5  ){ if(MVAIso()<-0.78) return false; }
    if(!(RelIso()<0.4)) return false;
    if(!(fabs(dXY())<0.025 && fabs(dZ())<0.1)) return false; 
    if(! (SIP2D()<4.) ) return false;
    if(!PassConversionVeto()) return false;
    if(!Pass_CaloIdL_TrackIdL_IsoVL_HctoWA()) return false;
    if(!(fabs(Eta())<2.5)) return false;
    return true;
  }
  if(ID=="POGMVAni90HLT172lCv"){
    if(!passMVAID_noIso_WP90()) return false;
    if(!Pass_CaloIdL_TrackIdL_IsoVL()) return false;
    if(!PassConversionVeto()) return false;
    if(!(fabs(Eta())<2.5)) return false;
    return true;
  }
  if(ID=="POGMVAni90Cv"){
    if(!passMVAID_noIso_WP90()) return false;
    if(!PassConversionVeto()) return false;
    if(!(fabs(Eta())<2.5)) return false;
    return true;
  }
  if(ID=="POGMVAni80HLT172lCv"){
    if(!passMVAID_noIso_WP80()) return false;
    if(!Pass_CaloIdL_TrackIdL_IsoVL()) return false;
    if(!PassConversionVeto()) return false;
    if(!(fabs(Eta())<2.5)) return false;
    return true;
  }
  if(ID=="POGMVAni80Cv"){
    if(!passMVAID_noIso_WP80()) return false;
    if(!PassConversionVeto()) return false;
    if(!(fabs(Eta())<2.5)) return false;
    return true;
  }
  //Use Checked
  if(ID=="TopHN17T" or ID=="TopHNT"){
    if(! passMVAID_noIso_WP90()          ) return false;
    if(! (MiniRelIso()<0.1)              ) return false;
    if(! (SIP3D()<4.)                    ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL() ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()<2)              ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    return true;
  }
  if(ID=="TopHN17L" or ID=="TopHNL"){
    if(! passMVAID_noIso_WPLoose()       ) return false;
    if(! (MiniRelIso()<0.4)              ) return false;
    if(! (SIP3D()<4.)                    ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL()   ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()<2)              ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    return true;
  }
  if(ID=="TopHN17SST" or ID=="TopHNSST"){
    if(! passMVAID_noIso_WP90()          ) return false;
    if(! (MiniRelIso()<0.1)              ) return false;
    if(! (SIP3D()<4)                     ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL()   ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()<2)              ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    if(! IsGsfCtfScPixChargeConsistent() ) return false;
    return true;
  }
  if(ID=="TopHNSSL_WP90Isop4"){
    if(! passMVAID_noIso_WP90()          ) return false;
    if(! (MiniRelIso()<0.4)              ) return false;
    if(! (SIP3D()<4)                     ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL()   ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()<2)              ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    if(! IsGsfCtfScPixChargeConsistent() ) return false;
    return true;
  }
  if(ID=="TopHN17SSL"){
    if(! passMVAID_noIso_WPLoose()       ) return false;
    if(! (MiniRelIso()<0.4)              ) return false;
    if(! (SIP3D()<4.)                    ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL() ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()<2)              ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    if(! IsGsfCtfScPixChargeConsistent() ) return false;
    return true;
  }
  if(ID.Contains("TopHNSSLFixLMVAIsop4NoSIP_201") or ID.Contains("TopHNSSL_201")){
    if(! (MiniRelIso()<0.4)              ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL()   ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()<=1)             ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    if(! IsGsfCtfScPixChargeConsistent() ) return false;
    float MVACut=-1, fEta=fabs(Eta());
    if     (ID.Contains("2016a")) MVACut=fEta<0.8? 0.96:fEta<1.5? 0.93:0.85;
    else if(ID.Contains("2016b")) MVACut=fEta<0.8? 0.96:fEta<1.5? 0.93:0.85;
    else if(ID.Contains("2017") ) MVACut=fEta<0.8? 0.94:fEta<1.5? 0.79:0.5;
    else if(ID.Contains("2018") ) MVACut=fEta<0.8? 0.94:fEta<1.5? 0.79:0.5;

    if(! (MVANoIso()>MVACut or passMVAID_noIso_WP90()) ) return false;
    return true;
  }
  if(ID.Contains("TopHNL_201")){
    if(! (MiniRelIso()<0.4)              ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL()   ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()<=1)             ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    float MVACut=-1, fEta=fabs(Eta());
    if     (ID.Contains("2016a")) MVACut=fEta<0.8? 0.96:fEta<1.5? 0.93:0.85;
    else if(ID.Contains("2016b")) MVACut=fEta<0.8? 0.96:fEta<1.5? 0.93:0.85;
    else if(ID.Contains("2017") ) MVACut=fEta<0.8? 0.94:fEta<1.5? 0.79:0.5;
    else if(ID.Contains("2018") ) MVACut=fEta<0.8? 0.94:fEta<1.5? 0.79:0.5;

    if(! (MVANoIso()>MVACut or passMVAID_noIso_WP90()) ) return false;
    return true;
  }
  if(ID=="TopHNV"){
    if(! (MVANoIso()  >-0.8 or passMVAID_noIso_WP90()) ) return false;
    if(! (MiniRelIso()< 0.4 )          ) return false;
    if(! (fabs(dZ())  < 0.1 )          ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL() ) return false;
    if(! PassConversionVeto()          ) return false;
    if(! (NMissingHits()<2)            ) return false;
    if(! (fabs(Eta())<2.5)             ) return false;
    return true;
  }
  if(ID=="TopHNSS_Isop4NoSIPMVA"){
    if(! (MiniRelIso()<0.4)              ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL()   ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()<=1)             ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    if(! IsGsfCtfScPixChargeConsistent() ) return false;
    return true;
  }
  if(ID=="TopHN_Isop4NoSIPMVA"){
    if(! (MiniRelIso()<0.4)              ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL()   ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()<=1)             ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    return true;
  }

  //End of usage checked

/*
  if(ID=="TopHN_NoIsoMVA"){
    if(! (IP3Derr()!=0. && fabs(IP3D()/IP3Derr())<4.) ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL() ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()==0)             ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    return true;
  }
  if(ID=="TopHNVSIP4"){
    if(! (MVANoIso()  >-0.8 )          ) return false;
    if(! (MiniRelIso()< 0.4 )          ) return false;
    if(! (fabs(dZ())  < 0.1 )          ) return false;
    if(! (SIP3D()<4.        )          ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL() ) return false;
    if(! PassConversionVeto()          ) return false;
    if(! (NMissingHits()<2)            ) return false;
    if(! (fabs(Eta())<2.5)             ) return false;
    return true;
  }
  if(ID.Contains("TopHNSSNM0LFixLMVAIsop4NoSIP_201")){
    if(! (MiniRelIso()<0.4)              ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL()   ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()==0)             ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    if(! IsGsfCtfScPixChargeConsistent() ) return false;
    float MVACut=-1, fEta=fabs(Eta());
    if     (ID.Contains("2016a")) MVACut=fEta<0.8? 0.98:fEta<1.5? 0.94:0.85;
    else if(ID.Contains("2016b")) MVACut=fEta<0.8? 0.97:fEta<1.5? 0.95:0.88;
    else if(ID.Contains("2017") ) MVACut=fEta<0.8? 0.96:fEta<1.5? 0.85:0.55;
    else if(ID.Contains("2018") ) MVACut=fEta<0.8? 0.96:fEta<1.5? 0.85:0.55;

    if(! (MVANoIso()>MVACut) ) return false;
    return true;
  }

  if(ID.Contains("TopHNSSL_DynLMVAIsop4NoSIP_201") or ID.Contains("TopHNSSLDynLMVAIsop4NoSIP_201")){
    if(! (MiniRelIso()<0.4)              ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL() ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()==0)             ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    if(! IsGsfCtfScPixChargeConsistent() ) return false;
    if(! PassLooseMVA(ID, "PTCorrBase")  ) return false;
    return true;
  }
  if(ID.Contains("TopHNSSL_DynLMVAIsop4NoSIP_Pt10_201") or ID.Contains("TopHNSSLDynLMVAIsop4NoSIPPt10_201")){
    if(! (MiniRelIso()<0.4)              ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL() ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()==0)             ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    if(! IsGsfCtfScPixChargeConsistent() ) return false;
    if(! PassLooseMVA(ID, "PTCorrBase")  ) return false;
    return true;
  }
  if(ID=="TopHNSSNM0_Isop4NoSIPMVA"){
    if(! (MiniRelIso()<0.4)              ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL() ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()==0)             ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    if(! IsGsfCtfScPixChargeConsistent() ) return false;
    return true;
  }
  if(ID=="TopHNSS_NoIsoMVA"){
    if(! (IP3Derr()!=0. && fabs(IP3D()/IP3Derr())<4.) ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL() ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()==0)             ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    if(! IsGsfCtfScPixChargeConsistent() ) return false;
    return true;
  }
  if(ID=="TopHNSS_NoIsoMVANoSIP"){
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL() ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()==0)             ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    if(! IsGsfCtfScPixChargeConsistent() ) return false;
    return true;
  }
  if(ID=="TopHNT_WP90Isop1" or ID=="TopHNTWP90Isop1"){
    if(! passMVAID_noIso_WP90()          ) return false;
    if(! (MiniRelIso()<0.1)              ) return false;
    if(! (IP3Derr()!=0. && fabs(IP3D()/IP3Derr())<4.) ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL() ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()==0)             ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    return true;
  }
  if(ID=="TopHNSSTWP90Isop1"){
    if(! passMVAID_noIso_WP90()          ) return false;
    if(! (MiniRelIso()<0.1)              ) return false;
    if(! (SIP3D()<4.) ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL() ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()==0)             ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    if(! IsGsfCtfScPixChargeConsistent() ) return false;
    return true;
  }
  if(ID=="TopHNT_WP80Isop1"){
    if(! passMVAID_noIso_WP80()          ) return false;
    if(! (MiniRelIso()<0.1)              ) return false;
    if(! (IP3Derr()!=0. && fabs(IP3D()/IP3Derr())<4.) ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL() ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()==0)             ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    return true;
  }
  if(ID=="TopHNSST_WP80Isop1"){
    if(! passMVAID_noIso_WP80()          ) return false;
    if(! (MiniRelIso()<0.1)              ) return false;
    if(! (IP3Derr()!=0. && fabs(IP3D()/IP3Derr())<4.) ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL() ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()==0)             ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    if(! IsGsfCtfScPixChargeConsistent() ) return false;
    return true;
  }




  if(ID=="TopHN17SSTNoIHLT"){
    if(! passMVAID_noIso_WP90()          ) return false;
    if(! (IP3Derr()!=0. && fabs(IP3D()/IP3Derr())<4.) ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()<2)              ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    if(! IsGsfCtfScPixChargeConsistent() ) return false;
    return true;
  }

  if(ID=="TopHN17SSLNoIHLT"){
    if(! passMVAID_noIso_WPLoose()       ) return false;
    if(! (IP3Derr()!=0. && fabs(IP3D()/IP3Derr())<4.) ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()<2)              ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    if(! IsGsfCtfScPixChargeConsistent() ) return false;
    return true;
  }
  if(ID=="TopHN17LNoIHLT"){
    if(! passMVAID_noIso_WPLoose()       ) return false;
    if(! (IP3Derr()!=0. && fabs(IP3D()/IP3Derr())<4.) ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()<2)              ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    return true;
  }
  if(ID=="TopHN17T_NoHLT"){
    if(! passMVAID_noIso_WP90()          ) return false;
    if(! (MiniRelIso()<0.1)              ) return false;
    if(! (IP3Derr()!=0. && fabs(IP3D()/IP3Derr())<4.) ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()<2)              ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    return true;
  }
  if(ID=="TopHN17L_NoHLT"){
    if(! passMVAID_noIso_WPLoose()       ) return false;
    if(! (MiniRelIso()<0.4)              ) return false;
    if(! (IP3Derr()!=0. && fabs(IP3D()/IP3Derr())<4.) ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()<2)              ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    return true;
  }
  if(ID=="TopHN17SST_NoHLT"){
    if(! passMVAID_noIso_WP90()          ) return false;
    if(! (MiniRelIso()<0.1)              ) return false;
    if(! (IP3Derr()!=0. && fabs(IP3D()/IP3Derr())<4.) ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()<2)              ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    if(! IsGsfCtfScPixChargeConsistent() ) return false;
    return true;
  }
  if(ID=="TopHN17SSL_NoHLT"){
    if(! passMVAID_noIso_WPLoose()       ) return false;
    if(! (MiniRelIso()<0.4)              ) return false;
    if(! (IP3Derr()!=0. && fabs(IP3D()/IP3Derr())<4.) ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! PassConversionVeto()            ) return false;
    if(! (NMissingHits()<2)              ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    if(! IsGsfCtfScPixChargeConsistent() ) return false;
    return true;
  }
  if(ID=="TopHN17SSTIDTIsoNoCvNoMHit"){
    if(! passMVAID_noIso_WP90()          ) return false;
    if(! (MiniRelIso()<0.1)              ) return false;
    if(! (IP3Derr()!=0. && fabs(IP3D()/IP3Derr())<4.) ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL() ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    return true;
  }
  if(ID=="TopHN17SSTIDLIsoNoCvNoMHit"){
    if(! passMVAID_noIso_WP90()          ) return false;
    if(! (MiniRelIso()<0.4)              ) return false;
    if(! (IP3Derr()!=0. && fabs(IP3D()/IP3Derr())<4.) ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL() ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    return true;
  }
  if(ID=="TopHN17SSLIDLIsoNoCvNoMHit"){
    if(! passMVAID_noIso_WPLoose()       ) return false;
    if(! (MiniRelIso()<0.4)              ) return false;
    if(! (IP3Derr()!=0. && fabs(IP3D()/IP3Derr())<4.) ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL() ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    return true;
  }
  if(ID=="TopHN17SSTIDTIsoNoMHit"){
    if(! passMVAID_noIso_WP90()          ) return false;
    if(! (MiniRelIso()<0.1)              ) return false;
    if(! (IP3Derr()!=0. && fabs(IP3D()/IP3Derr())<4.) ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL() ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    if(! IsGsfCtfScPixChargeConsistent() ) return false;
    return true;
  }
  if(ID=="TopHN17SSLIDLIsoNoMHit"){
    if(! passMVAID_noIso_WPLoose()       ) return false;
    if(! (MiniRelIso()<0.4)              ) return false;
    if(! (IP3Derr()!=0. && fabs(IP3D()/IP3Derr())<4.) ) return false;
    if(! (fabs(dZ())<0.1)                ) return false;
    if(! Pass_CaloIdL_TrackIdL_IsoVL() ) return false;
    if(! (fabs(Eta())<2.5)               ) return false;
    if(! IsGsfCtfScPixChargeConsistent() ) return false;
    return true;
  }
*/
  cout << "[Electron::PassID] No id : " << ID << endl;
  exit(ENODATA);

  return false;
}


bool Electron::PassLooseMVA(TString wp, TString Option) const{

  vector<float> PTEdges, MVACuts, PTCenters;
  float fEta = fabs(Eta()), PT=Pt(), PTCorr = ((Lepton*) this)->CalcPtCone(MiniRelIso(),0.1);
  bool IsEB1=fEta<0.8, IsEB2=(!IsEB1) && fEta<1.479;
  bool PTBase=false, PTCorrBase=false, NoInt=false;
  if(Option.Contains("PTCorrBase")) PTCorrBase=true;
  else PTBase=true;
  if(Option.Contains("NoInt")) NoInt=true;
  float PTnow = PTBase? PT:PTCorrBase? PTCorr: PT;
  float MVACut = 1; bool PassMVAT=false;

  if(wp.Contains("TopHNSSL_DynLMVAIsop4NoSIP_201") or wp.Contains("TopHNSSLDynLMVAIsop4NoSIP_201")){
    PTEdges =                  {15, 20,   25,   35,   50,   70,  100,  200};
    PTCenters =                { 17.5, 22.5,   30, 42.5,   60,   85,  150};
    if(wp.Contains("2016a")){ 
      if     (IsEB1) MVACuts = { 0.86, 0.98, 0.98, 0.98, 0.95, 0.82, 0.82};
      else if(IsEB2) MVACuts = { 0.57, 0.94, 0.94, 0.94, 0.94, 0.88, 0.88};
      else           MVACuts = {-0.27, 0.80, 0.89, 0.92, 0.92, 0.97, 0.97};
    }
    if(wp.Contains("2016b")){ 
      if     (IsEB1) MVACuts = { 0.86, 0.97, 0.97, 0.97, 0.95, 0.82, 0.82};
      else if(IsEB2) MVACuts = { 0.57, 0.96, 0.96, 0.91, 0.91, 0.78, 0.78};
      else           MVACuts = {-0.27, 0.80, 0.89, 0.92, 0.96, 0.96, 0.98};
    }
    if(wp.Contains("2017")){ 
      if     (IsEB1) MVACuts = { 0.86, 0.96, 0.96, 0.96, 0.82, 0.82, 0.82};
      else if(IsEB2) MVACuts = { 0.57, 0.85, 0.85, 0.85, 0.76, 0.76, 0.76};
      else           MVACuts = {-0.27, 0.25, 0.56, 0.77, 0.87, 0.95, 0.95};
    }
    if(wp.Contains("2018")){ 
      if     (IsEB1) MVACuts = { 0.86, 0.96, 0.96, 0.96, 0.77, 0.77, 0.77};
      else if(IsEB2) MVACuts = { 0.57, 0.85, 0.85, 0.85, 0.76, 0.76, 0.76};
      else           MVACuts = {-0.27, 0.37, 0.60, 0.77, 0.87, 0.92, 0.92};
    }
    PassMVAT  = passMVAID_noIso_WP90(); 
  }
  else if(wp.Contains("TopHNSSL_DynLMVAIsop4NoSIP_Pt10_201") or wp.Contains("TopHNSSLDynLMVAIsop4NoSIPPt10_201")){
    PTEdges =                  {10,  15,   20,    25,  35,   50,   70,  100, 200};
    PTCenters =                { 12.5,  17.5, 22.5,   30, 42.5,   60,   85,  150};
    if(wp.Contains("2016a")){ 
      if     (IsEB1) MVACuts = { 0.86,  0.86, 0.98, 0.98, 0.98, 0.95, 0.82, 0.82};
      else if(IsEB2) MVACuts = { 0.57,  0.57, 0.94, 0.94, 0.94, 0.94, 0.88, 0.88};
      else           MVACuts = {-0.27, -0.27, 0.80, 0.89, 0.92, 0.92, 0.97, 0.97};
    }
    if(wp.Contains("2016b")){ 
      if     (IsEB1) MVACuts = { 0.86,  0.86, 0.97, 0.97, 0.97, 0.95, 0.82, 0.82};
      else if(IsEB2) MVACuts = { 0.57,  0.57, 0.96, 0.96, 0.91, 0.91, 0.78, 0.78};
      else           MVACuts = {-0.27, -0.27, 0.80, 0.89, 0.92, 0.96, 0.96, 0.98};
    }
    if(wp.Contains("2017")){ 
      if     (IsEB1) MVACuts = { 0.86,  0.86, 0.96, 0.96, 0.96, 0.82, 0.82, 0.82};
      else if(IsEB2) MVACuts = { 0.57,  0.57, 0.85, 0.85, 0.85, 0.76, 0.76, 0.76};
      else           MVACuts = {-0.27, -0.27, 0.25, 0.56, 0.77, 0.87, 0.95, 0.95};
    }
    if(wp.Contains("2018")){ 
      if     (IsEB1) MVACuts = { 0.86,  0.86, 0.96, 0.96, 0.96, 0.77, 0.77, 0.77};
      else if(IsEB2) MVACuts = { 0.57,  0.57, 0.85, 0.85, 0.85, 0.76, 0.76, 0.76};
      else           MVACuts = {-0.27, -0.27, 0.37, 0.60, 0.77, 0.87, 0.92, 0.92};
    }
    //if     (IsEB1) MVACuts = { 0.63,  0.83, 0.95, 0.97, 0.94, 0.82, 0.82, 0.51};
    //else if(IsEB2) MVACuts = { 0.05,  0.60, 0.82, 0.87, 0.87, 0.78, 0.83, 0.59};
    //else           MVACuts = {-0.60, -0.27, 0.10, 0.50, 0.74, 0.87, 0.96, 0.96};
    PassMVAT  = passMVAID_noIso_WP90(); 
  }
  else { printf("[Electron::PassLooseMVA] No id : %s\n", wp.Data()); exit(ENODATA); }
  if(PTCenters.size()!=MVACuts.size()){ printf("N(PTCenter)!=N(MVACuts)\n"); exit(ENODATA); }

  int Nbins=MVACuts.size();
  if     (PTnow<PTCenters.at(0)      ){ MVACut = MVACuts.at(0); }
  else if(PTnow>PTCenters.at(Nbins-1)){ MVACut = MVACuts.at(Nbins-1); }
  else{
    for(unsigned int ipt=0; ipt<PTCenters.size()-1 && (!NoInt); ipt++){
      if( !(PTnow>=PTCenters.at(ipt) && PTnow<PTCenters.at(ipt+1)) ) continue;
      float PT1  = PTCenters.at(ipt), PT2 = PTCenters.at(ipt+1);
      float MVA1 = MVACuts.at(ipt), MVA2 = MVACuts.at(ipt+1);
      MVACut = MVA1 + (PTnow-PT1)/(PT2-PT1)*(MVA2-MVA1);
      break;
    }
    for(unsigned int ipt=0; ipt<PTEdges.size()-1 && NoInt; ipt++){
      if( !(PTnow>=PTEdges.at(ipt) && PTnow<PTEdges.at(ipt+1)) ) continue;
      float ThisMVA = MVACuts.at(ipt);
      MVACut = ThisMVA;
      break;
    }
  }

  bool ReturnVal = MVANoIso()>MVACut; 
  if( (!ReturnVal) && PassMVAT ) ReturnVal=true; 
  return ReturnVal;
  
}



bool Electron::passHEEP2018Prompt() const {

  //==== If not endcap, use original function
  if( fabs(scEta()) < 1.566 ) return passHEEPID();

  //==== https://github.com/CMSSNU/SKFlatMaker/blob/Run2Legacy_v4/SKFlatMaker/python/SKFlatMaker_cfi.py#L37-L50
  int HEEPcutbit = IDCutBit().at(11);

  //==== https://twiki.cern.ch/twiki/bin/view/CMS/CutBasedElectronIdentificationRun2#Applying_Individual_Cuts_of_a_Se
  //==== We will modify H/E (bit nr=6) and EM+Had_depth1 (bit nr=8) isolation cut for EndCap for 2018
  //==== Decimal without H/E and EM+Had_depth1 = (4096-1) - (1<<6) - (1<<8) = 3775
  if(! ( (HEEPcutbit&3775)==3775 ) ) return false;

  //==== new cutd : https://indico.cern.ch/event/831669/contributions/3485543/attachments/1871797/3084930/ApprovalSlides_EE_v3.pdf, page 9

  //==== new H/E cut
//double cutValue_HoverE =                                      5 / scE() + 0.05; // original cut
  double cutValue_HoverE = ( -0.4 + 0.4 * fabs(scEta()) ) * Rho() / scE() + 0.05;
  if(! (HoverE()<cutValue_HoverE) ) return false;

  //==== new EM+Had_depth1 cut
//double cutValue_emhaddep1 = UncorrPt() > 50. ? 2.5 + 0.03 * (UncorrPt()-50.) +                        0.28 * Rho() : 2.5 +                        0.28 * Rho(); // original cut
  double cutValue_emhaddep1 = UncorrPt() > 50. ? 2.5 + 0.03 * (UncorrPt()-50.) + (0.15 + 0.07*fabs(scEta())) * Rho() : 2.5 + (0.15 + 0.07*fabs(scEta())) * Rho();
  if(! ( dr03EcalRecHitSumEt() + dr03HcalDepth1TowerSumEt() < cutValue_emhaddep1 ) ) return false;

  return true;

}

bool Electron::Pass_SUSYMVAWP(TString wp) const{

  double sceta = fabs(scEta());

    double cutA = 0.77;
    double cutB = 0.52;

  if(wp=="Tight"){
    if     (sceta<0.8)  { cutA = 0.77; cutB = 0.52; }
    else if(sceta<1.479){ cutA = 0.56; cutB = 0.11; } 
    else                { cutA = 0.48; cutB =-0.01; }
  }
  else if(wp=="Loose"){
    if     (sceta<0.8)  { cutA =-0.48; cutB =-0.85; }
    else if(sceta<1.479){ cutA =-0.67; cutB =-0.91; }
    else                { cutA =-0.49; cutB =-0.83; }
  }
  else{}

  double cutSlope = (cutB-cutA) / 10.;
  double cutFinal = std::min( cutA, std::max(cutB , cutA + cutSlope*(this->Pt()-15.) ) );

  //==== Using NoIso MVA, because we apply MiniIso later
  if(MVANoIso()>cutFinal) return true;
  else return false;

}

bool Electron::Pass_SUSYTight() const{
  if(! Pass_SUSYMVAWP("Tight") ) return false;
  if(! (MiniRelIso()<0.1) ) return false;
  if(! (fabs(dXY())<0.05 && fabs(dZ())<0.1 && fabs(IP3D()/IP3Derr())<8.) ) return false;
  if(! PassConversionVeto() ) return false;
  if(! (NMissingHits()==0) ) return false;

  return true;
}

bool Electron::Pass_SUSYLoose() const{
  if(! Pass_SUSYMVAWP("Loose") ) return false;
  if(! (MiniRelIso()<0.4) ) return false;
  if(! (fabs(dXY())<0.05 && fabs(dZ())<0.1 && fabs(IP3D()/IP3Derr())<8.) ) return false;
  if(! PassConversionVeto() ) return false;
  if(! (NMissingHits()==0) ) return false;

  return true;
}

//==== TEST ID

bool Electron::Pass_TESTID() const{
  if(! passMVAID_noIso_WP90() ) return false;
  if(! (MiniRelIso()<0.1)     ) return false;
  if(! (fabs(dXY())<0.025 && fabs(dZ())<0.1) ) return false;
  if(! (dXYerr()>0. && fabs(dXY()/dXYerr())<4.) ) return false;
  if(! (IP3Derr()>0. && fabs(IP3D()/IP3Derr())<4.) ) return false;
  if(! PassConversionVeto() ) return false;
  if(! Pass_CaloIdL_TrackIdL_IsoVL() ) return false;

  return true;
}



bool Electron::Pass_CaloIdL_TrackIdL_IsoVL_HctoWA() const{
  

  if( fabs(scEta()) <=1.479 ){
    if(! (Full5x5_sigmaIetaIeta() < 0.012) ) return false;
    if(! (fabs(dEtaSeed()) < 0.0095) ) return false;
    if(! (fabs(dPhiIn()) < 0.065) ) return false;
    if(! (HoverE() < 0.09) ) return false;
    if(! (ecalPFClusterIso() < 0.37*Pt()) ) return false;
    if(! (hcalPFClusterIso() < 0.25*Pt()) ) return false;
    if(! (dr03TkSumPt() < 0.18*Pt()) ) return false; 
  }
  else{
    if(! (Full5x5_sigmaIetaIeta() < 0.033) ) return false;
    if(! (HoverE() < 0.09) ) return false;
    if(! (ecalPFClusterIso() < 0.45*Pt()) ) return false;
    if(! (hcalPFClusterIso() < 0.28*Pt()) ) return false;
    if(! (dr03TkSumPt() < 0.18*Pt()) ) return false; 
  }

  return true;
}



bool Electron::Pass_CaloIdL_TrackIdL_IsoVL(TString Option) const{
  
  bool ApplyEA = !Option.Contains("NoEA");
  if( fabs(scEta()) <=1.479 ){
    if(! (Full5x5_sigmaIetaIeta() < 0.013) ) return false;
    if(! (fabs(dEtaSeed()) < 0.01) ) return false;
    if(! (fabs(dPhiIn()) < 0.07) ) return false;
    if(! (HoverE() < 0.13) ) return false;
    if(! (max(0.,ecalPFClusterIso()-Rho()*(ApplyEA? 0.16544:0.)) < 0.5*Pt()) ) return false;
    if(! (max(0.,hcalPFClusterIso()-Rho()*(ApplyEA? 0.05956:0.)) < 0.3*Pt()) ) return false;
    if(! (dr03TkSumPt() < 0.2*Pt()) ) return false; 
  }
  else{
    if(! (Full5x5_sigmaIetaIeta() < 0.035) ) return false;
    if(! (fabs(dEtaSeed()) < 0.015) ) return false;
    if(! (fabs(dPhiIn()) < 0.1) ) return false;
    if(! (HoverE() < 0.13) ) return false;
    if(! (max(0.,ecalPFClusterIso()-Rho()*(ApplyEA? 0.13212:0.)) < 0.5*Pt()) ) return false;
    if(! (max(0.,hcalPFClusterIso()-Rho()*(ApplyEA? 0.13052:0.)) < 0.3*Pt()) ) return false;
    if(! (dr03TkSumPt() < 0.2*Pt()) ) return false; 
  }

  return true;
//1-a) in menu of some periods, dEtaInSeed and dPhiIn cuts are not applied in EE.
//1-b) EA is tightened from the later runs of 2016 to 2018 (i.e. higher EA)
//- the cuts are set as tighter one among them.
//2) cuts are a bit tighter in HctoWA, as it is higher in trig eff. but does not reduce sig eff much.
//   but due to detector degradation, it start to hurt the sig. eff. so set the values as cuts in menu.
}


bool Electron::Pass_CaloIdL_TrackIdL_IsoVL_Tight(TString Option) const{
  
  bool ApplyEA = false;
  //bool ApplyEA = !Option.Contains("NoEA");
  if( fabs(scEta()) <=1.479 ){
    if(! (Full5x5_sigmaIetaIeta() < 0.012) ) return false;
    if(! (fabs(dEtaSeed()) < 0.0095) ) return false;
    if(! (fabs(dPhiIn()) < 0.065) ) return false;
    if(! (HoverE() < 0.09) ) return false;
    if(! (max(0.,ecalPFClusterIso()-Rho()*(ApplyEA? 0.16544:0.)) < 0.5*Pt()) ) return false;
    if(! (max(0.,hcalPFClusterIso()-Rho()*(ApplyEA? 0.05956:0.)) < 0.3*Pt()) ) return false;
    if(! (dr03TkSumPt() < 0.18*Pt()) ) return false; 
  }
  else{
    if(! (Full5x5_sigmaIetaIeta() < 0.033) ) return false;
    if(! (fabs(dEtaSeed()) < 0.015) ) return false;
    if(! (fabs(dPhiIn()) < 0.095) ) return false;
    if(! (HoverE() < 0.09) ) return false;
    if(! (max(0.,ecalPFClusterIso()-Rho()*(ApplyEA? 0.13212:0.)) < 0.5*Pt()) ) return false;
    if(! (max(0.,hcalPFClusterIso()-Rho()*(ApplyEA? 0.13052:0.)) < 0.3*Pt()) ) return false;
    if(! (dr03TkSumPt() < 0.18*Pt()) ) return false; 
  }

  return true;
//1-a) in menu of some periods, dEtaInSeed and dPhiIn cuts are not applied in EE.
//1-b) EA is tightened from the later runs of 2016 to 2018 (i.e. higher EA)
//- the cuts are set as tighter one among them.
//2) cuts are a bit tighter in HctoWA, as it is higher in trig eff. but does not reduce sig eff much.
//   but due to detector degradation, it start to hurt the sig. eff. so set the values as cuts in menu.
}



bool Electron::Pass_CutBasedLooseNoIso() const{

  if( fabs(scEta()) <= 1.479 ){

    if(! (Full5x5_sigmaIetaIeta() < 0.0112) ) return false;
    if(! (fabs(dEtaSeed()) < 0.00377) ) return false;
    if(! (fabs(dPhiIn()) < 0.0884) ) return false;
    if(! (HoverE() < 0.05 + 1.16/scE() + 0.0324*Rho()/scE()) ) return false;
    if(! (fabs(InvEminusInvP()) < 0.193) ) return false;
    if(! (NMissingHits() <= 1) ) return false;
    if(! (PassConversionVeto()) ) return false;

    return true;

  }
  else{

    if(! (Full5x5_sigmaIetaIeta() < 0.0425) ) return false;
    if(! (fabs(dEtaSeed()) < 0.00674) ) return false;
    if(! (fabs(dPhiIn()) <  0.169 ) ) return false;
    if(! (HoverE() < 0.0441 + 2.54/scE() + 0.183*Rho()/scE()) ) return false;
    if(! (fabs(InvEminusInvP()) < 0.111) ) return false;
    if(! (NMissingHits() <= 1) ) return false;
    if(! (PassConversionVeto()) ) return false;

    return true;

  }

}

bool Electron::Pass_CutBasedVetoNoIso() const{
  
  if( fabs(scEta()) <= 1.479 ){
    
    if(! (Full5x5_sigmaIetaIeta() < 0.0126 ) ) return false;
    if(! (fabs(dEtaSeed()) < 0.00463 ) ) return false;
    if(! (fabs(dPhiIn()) < 0.148) ) return false;
    if(! (HoverE() < 0.05 + 1.16/scE() + 0.0324*Rho()/scE()) ) return false;
    if(! (fabs(InvEminusInvP()) < 0.209) ) return false;
    if(! (NMissingHits() <= 2) ) return false;
    if(! (PassConversionVeto()) ) return false;
    
    return true;
  
  }
  else{
    
    if(! (Full5x5_sigmaIetaIeta() < 0.0457) ) return false;
    if(! (fabs(dEtaSeed()) < 0.00814) ) return false;
    if(! (fabs(dPhiIn()) < 0.19) ) return false;
    if(! (HoverE() < 0.05 + 2.54/scE() + 0.183*Rho()/scE()) ) return false;
    if(! (fabs(InvEminusInvP()) < 0.132) ) return false;
    if(! (NMissingHits() <= 3) ) return false;
    if(! (PassConversionVeto()) ) return false;
    
    return true;
  
  }

}

bool Electron::Pass_CutBasedLoose() const{

  if( fabs(scEta()) <= 1.479 ){

    if(! (Full5x5_sigmaIetaIeta() < 0.0112) ) return false;
    if(! (fabs(dEtaSeed()) < 0.00377) ) return false;
    if(! (fabs(dPhiIn()) < 0.0884) ) return false;
    if(! (HoverE() < 0.05 + 1.16/scE() + 0.0324*Rho()/scE()) ) return false;
    if(! (RelIso() < 0.112+0.506/UncorrPt()) ) return false;
    if(! (fabs(InvEminusInvP()) < 0.193) ) return false;
    if(! (NMissingHits() <= 1) ) return false;
    if(! (PassConversionVeto()) ) return false;

    return true;

  }
  else{

    if(! (Full5x5_sigmaIetaIeta() < 0.0425) ) return false;
    if(! (fabs(dEtaSeed()) < 0.00674) ) return false;
    if(! (fabs(dPhiIn()) <  0.169 ) ) return false;
    if(! (HoverE() < 0.0441 + 2.54/scE() + 0.183*Rho()/scE()) ) return false;
    if(! (RelIso() < 0.108+0.963/UncorrPt()) ) return false;
    if(! (fabs(InvEminusInvP()) < 0.111) ) return false;
    if(! (NMissingHits() <= 1) ) return false;
    if(! (PassConversionVeto()) ) return false;

    return true;

  }

}

bool Electron::Pass_CutBasedVeto() const{

  if( fabs(scEta()) <= 1.479 ){

    if(! (Full5x5_sigmaIetaIeta() < 0.0126 ) ) return false;
    if(! (fabs(dEtaSeed()) < 0.00463 ) ) return false;
    if(! (fabs(dPhiIn()) < 0.148) ) return false;
    if(! (HoverE() < 0.05 + 1.16/scE() + 0.0324*Rho()/scE()) ) return false;
    if(! (RelIso() < 0.198+0.506/UncorrPt()) ) return false;
    if(! (fabs(InvEminusInvP()) < 0.209) ) return false;
    if(! (NMissingHits() <= 2) ) return false;
    if(! (PassConversionVeto()) ) return false;

    return true;

  }
  else{

    if(! (Full5x5_sigmaIetaIeta() < 0.0457) ) return false;
    if(! (fabs(dEtaSeed()) < 0.00814) ) return false;
    if(! (fabs(dPhiIn()) < 0.19) ) return false;
    if(! (HoverE() < 0.05 + 2.54/scE() + 0.183*Rho()/scE()) ) return false;
    if(! (RelIso() < 0.203+0.963/UncorrPt()) ) return false;
    if(! (fabs(InvEminusInvP()) < 0.132) ) return false;
    if(! (NMissingHits() <= 3) ) return false;
    if(! (PassConversionVeto()) ) return false;

    return true;

  }

}

void Electron::SetRho(double r){
  j_Rho = r;
}

void Electron::SetIsGsfCtfScPixChargeConsistent(bool b){
  j_isGsfCtfScPixChargeConsistent = b;
}

bool Electron::PassFilter(TString filter) const{
  if( filter=="hltDiMu9Ele9CaloIdLTrackIdLElectronlegDphiFilter" ) return j_filterbits&(ULong64_t(1)<<0);
  else if( filter=="hltEGL1SingleEGOrFilter" ) return j_filterbits&(ULong64_t(1)<<1);
  else if( filter=="hltEle12CaloIdLTrackIdLIsoVLTrackIsoFilter" ) return j_filterbits&(ULong64_t(1)<<2);
  else if( filter=="hltEle16Ele12Ele8CaloIdLTrackIdLDphiLeg1Filter" ) return j_filterbits&(ULong64_t(1)<<3);
  else if( filter=="hltEle16Ele12Ele8CaloIdLTrackIdLDphiLeg2Filter" ) return j_filterbits&(ULong64_t(1)<<4);
  else if( filter=="hltEle17CaloIdLTrackIdLIsoVLTrackIsoFilter" ) return j_filterbits&(ULong64_t(1)<<5);
  else if( filter=="hltEle17CaloIdMGsfTrackIdMDphiFilter" ) return j_filterbits&(ULong64_t(1)<<6);
  else if( filter=="hltEle23CaloIdLTrackIdLIsoVLJet30TrackIsoFilter" ) return j_filterbits&(ULong64_t(1)<<7);
  else if( filter=="hltEle23Ele12CaloIdLTrackIdLIsoVLDZFilter" ) return j_filterbits&(ULong64_t(1)<<8);
  else if( filter=="hltEle23Ele12CaloIdLTrackIdLIsoVLTrackIsoLeg1Filter" ) return j_filterbits&(ULong64_t(1)<<9);
  else if( filter=="hltEle23Ele12CaloIdLTrackIdLIsoVLTrackIsoLeg2Filter" ) return j_filterbits&(ULong64_t(1)<<10);
  else if( filter=="hltEle27WPTightGsfTrackIsoFilter" ) return j_filterbits&(ULong64_t(1)<<11);
  else if( filter=="hltEle27erWPTightGsfTrackIsoFilter" ) return j_filterbits&(ULong64_t(1)<<12);
  else if( filter=="hltEle28WPTightGsfTrackIsoFilter" ) return j_filterbits&(ULong64_t(1)<<13);
  else if( filter=="hltEle32L1DoubleEGWPTightGsfTrackIsoFilter" ) return j_filterbits&(ULong64_t(1)<<14);
  else if( filter=="hltEle32WPTightGsfTrackIsoFilter" ) return j_filterbits&(ULong64_t(1)<<15);
  else if( filter=="hltEle35noerWPTightGsfTrackIsoFilter" ) return j_filterbits&(ULong64_t(1)<<16);
  else if( filter=="hltEle8CaloIdLTrackIdLIsoVLTrackIsoFilter" ) return j_filterbits&(ULong64_t(1)<<17);
  else if( filter=="hltMu23TrkIsoVVLEle12CaloIdLTrackIdLIsoVLDZFilter" ) return j_filterbits&(ULong64_t(1)<<18);
  else if( filter=="hltMu23TrkIsoVVLEle12CaloIdLTrackIdLIsoVLElectronlegTrackIsoFilter" ) return j_filterbits&(ULong64_t(1)<<19);
  else if( filter=="hltMu23TrkIsoVVLEle8CaloIdLTrackIdLIsoVLElectronlegTrackIsoFilter" ) return j_filterbits&(ULong64_t(1)<<20);
  else if( filter=="hltMu8TrkIsoVVLEle23CaloIdLTrackIdLIsoVLDZFilter" ) return j_filterbits&(ULong64_t(1)<<21);
  else if( filter=="hltMu8TrkIsoVVLEle23CaloIdLTrackIdLIsoVLElectronlegTrackIsoFilter" ) return j_filterbits&(ULong64_t(1)<<22);
  else if( filter=="hltMu9Ele9DZFilter" ) return j_filterbits&(ULong64_t(1)<<23);
  else{
    cout<<"[Electron::PassFilter] unknown filter "<<filter<<endl;
    exit(ENODATA);
  }
  return false;
}

bool Electron::PassPath(TString path) const{
  if( path=="HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ_v" ) return j_pathbits&(ULong64_t(1)<<0);
  else if( path=="HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v" ) return j_pathbits&(ULong64_t(1)<<1);
  else if( path=="HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v" ) return j_pathbits&(ULong64_t(1)<<2);
  else if( path=="HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v" ) return j_pathbits&(ULong64_t(1)<<3);
  else if( path=="HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30_v" ) return j_pathbits&(ULong64_t(1)<<4);
  else if( path=="HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v" ) return j_pathbits&(ULong64_t(1)<<5);
  else if( path=="HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v" ) return j_pathbits&(ULong64_t(1)<<6);
  else if( path=="HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v" ) return j_pathbits&(ULong64_t(1)<<7);
  else if( path=="HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v" ) return j_pathbits&(ULong64_t(1)<<8);
  else if( path=="HLT_Ele27_WPTight_Gsf_v" ) return j_pathbits&(ULong64_t(1)<<9);
  else if( path=="HLT_Ele27_eta2p1_WPTight_Gsf_v" ) return j_pathbits&(ULong64_t(1)<<10);
  else if( path=="HLT_Ele28_WPTight_Gsf_v" ) return j_pathbits&(ULong64_t(1)<<11);
  else if( path=="HLT_Ele32_WPTight_Gsf_L1DoubleEG_v" ) return j_pathbits&(ULong64_t(1)<<12);
  else if( path=="HLT_Ele32_WPTight_Gsf_v" ) return j_pathbits&(ULong64_t(1)<<13);
  else if( path=="HLT_Ele35_WPTight_Gsf_v" ) return j_pathbits&(ULong64_t(1)<<14);
  else if( path=="HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v" ) return j_pathbits&(ULong64_t(1)<<15);
  else if( path=="HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v" ) return j_pathbits&(ULong64_t(1)<<16);
  else if( path=="HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v" ) return j_pathbits&(ULong64_t(1)<<17);
  else if( path=="HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ_v" ) return j_pathbits&(ULong64_t(1)<<18);
  else if( path=="HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v" ) return j_pathbits&(ULong64_t(1)<<19);
  else if( path=="HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v" ) return j_pathbits&(ULong64_t(1)<<20);
  else if( path=="HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v" ) return j_pathbits&(ULong64_t(1)<<21);
  else if( path=="HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v" ) return j_pathbits&(ULong64_t(1)<<22);
  else{
    cout<<"[Electron::PassPath] unknown path "<<path<<endl;
    exit(ENODATA);
  }
  return false;
}
