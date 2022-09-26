#include "HNL_LepIDKinVar.h"

void HNL_LepIDKinVar::initializeAnalyzer(){

  HNL_LeptonCore::initializeAnalyzer();

  InitializeTreeVars();
  

  tree_mm->Branch("Ptl1", &Ptl1, "Ptl1/F");                        tree_ee->Branch("Ptl1", &Ptl1, "Ptl1/F");
  tree_mm->Branch("Ptl2", &Ptl2, "Ptl2/F");                        tree_ee->Branch("Ptl2", &Ptl2, "Ptl2/F");                                                
  tree_mm->Branch("Etal1", &Etal1, "Etal1/F");                        tree_ee->Branch("Etal1", &Etal1, "Etal1/F");
  tree_mm->Branch("Etal2", &Etal2, "Etal2/F");                        tree_ee->Branch("Etal2", &Etal2, "Etal2/F");

  tree_mm->Branch("Dxyl1", &Dxyl1, "Dxyl1/F");                        tree_ee->Branch("Dxyl1", &Dxyl1, "Dxyl1/F");
  tree_mm->Branch("Dxyl2", &Dxyl2, "Dxyl2/F");                        tree_ee->Branch("Dxyl2", &Dxyl2, "Dxyl2/F");
  tree_mm->Branch("Dzl1", &Dzl1, "Dzl1/F");                        tree_ee->Branch("Dzl1", &Dzl1, "Dzl1/F");
  tree_mm->Branch("Dzl2", &Dzl2, "Dzl2/F");                        tree_ee->Branch("Dzl2", &Dzl2, "Dzl2/F");
  tree_mm->Branch("RelIsol1", &RelIsol1, "RelIsol1/F");                        tree_ee->Branch("RelIsol1", &RelIsol1, "RelIsol1/F");
  tree_mm->Branch("RelIsol2", &RelIsol2, "RelIsol2/F");                        tree_ee->Branch("RelIsol2", &RelIsol2, "RelIsol2/F");
  tree_mm->Branch("IP3Dl1", &IP3Dl1, "IP3Dl1/F");                        tree_ee->Branch("IP3Dl1", &IP3Dl1, "IP3Dl1/F");
  tree_mm->Branch("IP3Dl2", &IP3Dl2, "IP3Dl2/F");                        tree_ee->Branch("IP3Dl2", &IP3Dl2, "IP3Dl2/F");
  tree_mm->Branch("MVAl1", &MVAl1, "MVAl1/F");                        tree_ee->Branch("MVAl1", &MVAl1, "MVAl1/F");
  tree_mm->Branch("MVAl2", &MVAl2, "MVAl2/F");                        tree_ee->Branch("MVAl2", &MVAl2, "MVAl2/F");

  tree_mm->Branch("Chi2l1", &Chi2l1, "Chi2l1/F");  
  tree_mm->Branch("Chi2l2", &Chi2l2, "Chi2l2/F");  
  tree_mm->Branch("Validhitsl1", &Validhitsl1, "Validhitsl1/I");  
  tree_mm->Branch("Validhitsl2", &Validhitsl2, "Validhitsl2/I");  

  tree_mm->Branch("Matched_stationsl1", &Matched_stationsl1, "Matched_stationsl1/I");
  tree_mm->Branch("Matched_stationsl2", &Matched_stationsl2, "Matched_stationsl2/I");

  tree_mm->Branch("Pixel_hitsl1", &Pixel_hitsl1, "Pixel_hitsl1/I");
  tree_mm->Branch("Pixel_hitsl2", &Pixel_hitsl2, "Pixel_hitsl2/I");

  tree_mm->Branch("Minirelisol1", &Minirelisol1, "Minirelisol1/F");
  tree_mm->Branch("Minirelisol2", &Minirelisol2, "Minirelisol2/F");
  
  tree_mm->Branch("Pixel_hitsl1", &Pixel_hitsl1, "Pixel_hitsl1/I");
  tree_mm->Branch("Pixel_hitsl2", &Pixel_hitsl2, "Pixel_hitsl2/I");

  tree_mm->Branch("Tracker_layersl1", &Tracker_layersl1, "Tracker_layersl1/I");
  tree_mm->Branch("Tracker_layersl2", &Tracker_layersl2, "Tracker_layersl2/I");

  tree_mm->Branch("POGTightl1", &POGTightl1, "POGTightl1/I");
  tree_mm->Branch("POGMediuml1", &POGMediuml1, "POGMediuml1/I");
  tree_mm->Branch("POGTightl2", &POGTightl2, "POGTightl2/I");
  tree_mm->Branch("POGMediuml2", &POGMediuml2, "POGMediuml2/I");

  tree_ee->Branch("POGTightl1", &POGTightl1, "POGTightl1/I");
  tree_ee->Branch("POGMediuml1", &POGMediuml1, "POGMediuml1/I");
  tree_ee->Branch("POGTightl2", &POGTightl2, "POGTightl2/I");
  tree_ee->Branch("POGMediuml2", &POGMediuml2, "POGMediuml2/I");


  tree_mm->Branch("PtRatiol1", &PtRatiol1, "PtRatiol1/F");         tree_ee->Branch("PtRatiol1", &PtRatiol1, "PtRatiol1/F");         
  tree_mm->Branch("PtRatiol2", &PtRatiol2, "PtRatiol2/F");         tree_ee->Branch("PtRatiol2", &PtRatiol2, "PtRatiol2/F");         
  tree_mm->Branch("PtRatioAJl1", &PtRatioAJl1, "PtRatioAJl1/F");   tree_ee->Branch("PtRatioAJl1", &PtRatioAJl1, "PtRatioAJl1/F");   
  tree_mm->Branch("PtRatioAJl2", &PtRatioAJl2, "PtRatioAJl2/F");   tree_ee->Branch("PtRatioAJl2", &PtRatioAJl2, "PtRatioAJl2/F");   
  tree_mm->Branch("PtRelv0l1", &PtRelv0l1, "PtRelv0l1/F");         tree_ee->Branch("PtRelv0l1", &PtRelv0l1, "PtRelv0l1/F");         
  tree_mm->Branch("PtRelv0l2", &PtRelv0l2, "PtRelv0l2/F");         tree_ee->Branch("PtRelv0l2", &PtRelv0l2, "PtRelv0l2/F");         
  tree_mm->Branch("PtRelv1l1", &PtRelv1l1, "PtRelv1l1/F");         tree_ee->Branch("PtRelv1l1", &PtRelv1l1, "PtRelv1l1/F");         
  tree_mm->Branch("PtRelv1l2", &PtRelv1l2, "PtRelv1l2/F");         tree_ee->Branch("PtRelv1l2", &PtRelv1l2, "PtRelv1l2/F");         
  tree_mm->Branch("CEMFracAJl1", &CEMFracAJl1, "CEMFracAJl1/F");   tree_ee->Branch("CEMFracAJl1", &CEMFracAJl1, "CEMFracAJl1/F");   
  tree_mm->Branch("CEMFracAJl2", &CEMFracAJl2, "CEMFracAJl2/F");   tree_ee->Branch("CEMFracAJl2", &CEMFracAJl2, "CEMFracAJl2/F");   
  tree_mm->Branch("NEMFracAJl1", &NEMFracAJl1, "NEMFracAJl1/F");   tree_ee->Branch("NEMFracAJl1", &NEMFracAJl1, "NEMFracAJl1/F");   
  tree_mm->Branch("NEMFracAJl2", &NEMFracAJl2, "NEMFracAJl2/F");   tree_ee->Branch("NEMFracAJl2", &NEMFracAJl2, "NEMFracAJl2/F");   
  tree_mm->Branch("CHFracAJl1", &CHFracAJl1, "CHFracAJl1/F");      tree_ee->Branch("CHFracAJl1", &CHFracAJl1, "CHFracAJl1/F");      
  tree_mm->Branch("CHFracAJl2", &CHFracAJl2, "CHFracAJl2/F");      tree_ee->Branch("CHFracAJl2", &CHFracAJl2, "CHFracAJl2/F");      
  tree_mm->Branch("NHFracAJl1", &NHFracAJl1, "NHFracAJl1/F");      tree_ee->Branch("NHFracAJl1", &NHFracAJl1, "NHFracAJl1/F");      
  tree_mm->Branch("NHFracAJl2", &NHFracAJl2, "NHFracAJl2/F");      tree_ee->Branch("NHFracAJl2", &NHFracAJl2, "NHFracAJl2/F");      
  tree_mm->Branch("MuFracAJl1", &MuFracAJl1, "MuFracAJl1/F");      tree_ee->Branch("MuFracAJl1", &MuFracAJl1, "MuFracAJl1/F");      
  tree_mm->Branch("MuFracAJl2", &MuFracAJl2, "MuFracAJl2/F");      tree_ee->Branch("MuFracAJl2", &MuFracAJl2, "MuFracAJl2/F");      
  tree_mm->Branch("JetDiscAJl1", &JetDiscAJl1, "JetDiscAJl1/F");   tree_ee->Branch("JetDiscAJl1", &JetDiscAJl1, "JetDiscAJl1/F");   
  tree_mm->Branch("JetDiscAJl2", &JetDiscAJl2, "JetDiscAJl2/F");   tree_ee->Branch("JetDiscAJl2", &JetDiscAJl2, "JetDiscAJl2/F");   
  tree_mm->Branch("CEMFracCJl1", &CEMFracCJl1, "CEMFracCJl1/F");   tree_ee->Branch("CEMFracCJl1", &CEMFracCJl1, "CEMFracCJl1/F");   
  tree_mm->Branch("CEMFracCJl2", &CEMFracCJl2, "CEMFracCJl2/F");   tree_ee->Branch("CEMFracCJl2", &CEMFracCJl2, "CEMFracCJl2/F");   
  tree_mm->Branch("NEMFracCJl1", &NEMFracCJl1, "NEMFracCJl1/F");   tree_ee->Branch("NEMFracCJl1", &NEMFracCJl1, "NEMFracCJl1/F");   
  tree_mm->Branch("NEMFracCJl2", &NEMFracCJl2, "NEMFracCJl2/F");   tree_ee->Branch("NEMFracCJl2", &NEMFracCJl2, "NEMFracCJl2/F");   
  tree_mm->Branch("CHFracCJl1", &CHFracCJl1, "CHFracCJl1/F");      tree_ee->Branch("CHFracCJl1", &CHFracCJl1, "CHFracCJl1/F");      
  tree_mm->Branch("CHFracCJl2", &CHFracCJl2, "CHFracCJl2/F");      tree_ee->Branch("CHFracCJl2", &CHFracCJl2, "CHFracCJl2/F");      
  tree_mm->Branch("NHFracCJl1", &NHFracCJl1, "NHFracCJl1/F");      tree_ee->Branch("NHFracCJl1", &NHFracCJl1, "NHFracCJl1/F");      
  tree_mm->Branch("NHFracCJl2", &NHFracCJl2, "NHFracCJl2/F");      tree_ee->Branch("NHFracCJl2", &NHFracCJl2, "NHFracCJl2/F");      
  tree_mm->Branch("MuFracCJl1", &MuFracCJl1, "MuFracCJl1/F");      tree_ee->Branch("MuFracCJl1", &MuFracCJl1, "MuFracCJl1/F");      
  tree_mm->Branch("MuFracCJl2", &MuFracCJl2, "MuFracCJl2/F");      tree_ee->Branch("MuFracCJl2", &MuFracCJl2, "MuFracCJl2/F");      
  tree_mm->Branch("JetDiscCJl1", &JetDiscCJl1, "JetDiscCJl1/F");   tree_ee->Branch("JetDiscCJl1", &JetDiscCJl1, "JetDiscCJl1/F");   
  tree_mm->Branch("JetDiscCJl2", &JetDiscCJl2, "JetDiscCJl2/F");   tree_ee->Branch("JetDiscCJl2", &JetDiscCJl2, "JetDiscCJl2/F");   

  tree_ee->Branch("MissingHitsl1", &MissingHitsl1, "MissingHitsl1/I");
  tree_ee->Branch("MissingHitsl2", &MissingHitsl2, "MissingHitsl2/I");
  tree_ee->Branch("Full5x5_sigmaIetaIetal1", &Full5x5_sigmaIetaIetal1, "Full5x5_sigmaIetaIetal1/F");
  tree_ee->Branch("Full5x5_sigmaIetaIetal2", &Full5x5_sigmaIetaIetal2, "Full5x5_sigmaIetaIetal2/F");
  
  tree_ee->Branch("dEtaSeedl1", &dEtaSeedl1, "dEtaSeedl1/F");
  tree_ee->Branch("dEtaSeedl2", &dEtaSeedl2, "dEtaSeedl2/F");


  tree_ee->Branch("dPhiInl1", &dPhiInl1, "dPhiInl1/F");
  tree_ee->Branch("dPhiInl2", &dPhiInl2, "dPhiInl2/F");


  tree_ee->Branch("HoverEl1", &HoverEl1, "HoverEl1/F");
  tree_ee->Branch("HoverEl2", &HoverEl2, "HoverEl2/F");

  tree_ee->Branch("TrkIsol1", &TrkIsol1, "TrkIsol1/F");
  tree_ee->Branch("TrkIsol2", &TrkIsol2, "TrkIsol2/F");

  tree_ee->Branch("isEcalDrivenl1", &isEcalDrivenl1, "isEcalDrivenl1/I");
  tree_ee->Branch("isEcalDrivenl2", &isEcalDrivenl2, "isEcalDrivenl2/I");

  tree_ee->Branch("InvEminusInvP_l1", &InvEminusInvP_l1, "InvEminusInvP_l1/F");
  tree_ee->Branch("InvEminusInvP_l2", &InvEminusInvP_l2, "InvEminusInvP_l2/F");

  tree_ee->Branch("PassConversionVetol1", &PassConversionVetol1, "PassConversionVetol1/I");
  tree_ee->Branch("PassConversionVetol2", &PassConversionVetol2, "PassConversionVetol2/I");

  tree_ee->Branch("ecalPFClusterIsol1", &ecalPFClusterIsol1, "ecalPFClusterIsol1/F");
  tree_ee->Branch("ecalPFClusterIsol2", &ecalPFClusterIsol2, "ecalPFClusterIsol2/F");

  tree_ee->Branch("hcalPFClusterIsol1", &hcalPFClusterIsol1, "hcalPFClusterIsol1/F");
  tree_ee->Branch("hcalPFClusterIsol2", &hcalPFClusterIsol2, "hcalPFClusterIsol2/F");

  tree_ee->Branch("IsGsfCtfScPixChargeConsistentl1", &IsGsfCtfScPixChargeConsistentl1, "IsGsfCtfScPixChargeConsistentl1/I");
  tree_ee->Branch("IsGsfCtfScPixChargeConsistentl2", &IsGsfCtfScPixChargeConsistentl2, "IsGsfCtfScPixChargeConsistentl2/I");

  tree_mm->Branch("w_tot", &w_tot, "w_tot/F");                     tree_ee->Branch("w_tot", &w_tot, "w_tot/F");                     

  outfile->cd();

}


void HNL_LepIDKinVar::executeEvent(){
  
  AnalyzerParameter param_bdt = HNL_LeptonCore::InitialiseHNLParameter("BDT", "");
  
  Event ev = GetEvent();
  double weight =SetupWeight(ev,param_bdt);
  
  FillHist("CutFlow", 0., weight, 20, 0., 20.);
  
  if(!PassMETFilter()) return;

  vector<HNL_LeptonCore::Channel> channels = {EE,MuMu};
  
  for(auto dilep_channel : channels){

    std::vector<Muon>       MuonCollT     = GetLepCollByRunType    ( GetMuons    ( param_bdt,param_bdt.Muon_Veto_ID, 10., 2.4, RunFake)    , gens,param_bdt, "NoSel");
    std::vector<Electron>   ElectronCollT = GetLepCollByRunType    ( GetElectrons( param_bdt,param_bdt.Electron_Veto_ID, 10., 2.5, RunFake), gens,param_bdt, "NoSel");
    
    std::vector<Lepton *> LepsT  = MakeLeptonPointerVector(MuonCollT,ElectronCollT);

    if (!PassTriggerSelection(dilep_channel, ev, LepsT, "Dilep")) continue;

    if(DataEra=="2017" && dilep_channel==MuMu){
      
      if(ev.PassTrigger("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v") && !ev.PassTrigger("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v")) weight = weight*4803.366325775/ev.GetTriggerLumi("Full");

    }

    std::vector<Jet>    AK4_JetAllColl = GetJets("NoID", 10., 3.0);

    bool passCharge = false;
    if(MCSample.Contains("TypeI")) passCharge = true;
    else{
      if(SameCharge(LepsT)) passCharge = true;
    }

    bool EventCand = false;

    if (passCharge && LepsT.size()==2){
      if (GetLLMass(LepsT) > 10.){
	EventCand=true;
      }
    }

    JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
    
    
    std::vector<Electron>   ElectronCollV = GetElectrons(param_bdt.Electron_Veto_ID, 10., 2.5);
    std::vector<Muon>       MuonCollV     = GetMuons    (param_bdt.Muon_Veto_ID, 5., 2.4);
    std::vector<FatJet> fatjets_tmp    = GetFatJets("tight", 200., 5);

    std::vector<FatJet> AK8_JetColl    = GetAK8Jets(fatjets_tmp, 200., 2.7, true, 1., false, -999, false, 40., 130., ElectronCollV, MuonCollV);

    std::vector<Jet>    jets_tmp       = GetJets("tight", 15., 5);
    std::vector<Jet> bjets_tmp                  = GetAK4Jets(jets_tmp,     20., 2.4, true, 0.4, 0.8, "", ElectronCollV, MuonCollV, AK8_JetColl);

    std::vector<Jet> BJetColl         = GetBJets(param_bdt, bjets_tmp, param_jets);
    double sf_btag                    = GetBJetSF(param_bdt, bjets_tmp, param_jets);
    if(!IsData )weight*= sf_btag;
    if(BJetColl.size() > 0) return;
    Particle METv = GetvMET("PuppiT1xyULCorr",param_bdt);
    if(METv.Pt() > 70.) return;
    if(!EventCand) return;

    MakeTreeSS2L(dilep_channel, LepsT,MuonCollT,ElectronCollT, AK4_JetAllColl,  weight, "");

  }
  
}

void HNL_LepIDKinVar::MakeTreeSS2L(HNL_LeptonCore::Channel lep_channel,vector<Lepton *>  LepTColl, 
				   vector<Muon> Muons, 
				   vector<Electron> Electrons,
				   vector<Jet>& JetAllColl,
				   float weight, TString Label)
{
  
  
  
  // CorrectChannelStream checks EE channel has only EE events
  if(!CheckLeptonFlavourForChannel(lep_channel, LepTColl)) return;

  // Pt cut is set in CheckLeptonFlavourForChannel
  //if(!(LepTColl[0]->Pt()>20 && LepTColl[1]->Pt()>10)) return;

  float Mll = GetLLMass(LepTColl);
  if (lep_channel==EE && (fabs(Mll-90.) < 10.)) return;
  
  InitializeTreeVars();
  

  Ptl1    = LepTColl[0]->Pt();
  Ptl2    = LepTColl.at(1)->Pt();
  Etal1   = fabs(LepTColl.at(0)->Eta());
  Etal2   = fabs(LepTColl.at(1)->Eta());
 

  if (lep_channel==EE){

    Dxyl1   = Electrons[0].dXY();
    Dxyl2   = Electrons[1].dXY();

    Dzl1   = Electrons[0].dZ();
    Dzl2   = Electrons[1].dZ();

    RelIsol1    = Electrons[0].RelIso();
    RelIsol2    = Electrons[1].RelIso();

    IP3Dl1    = Electrons[0].IP3D();
    IP3Dl2    = Electrons[1].IP3D();

    MVAl1    = Electrons[0].MVANoIso();
    MVAl2    = Electrons[1].MVANoIso();

    POGTightl1 = Electrons[0].Pass_CutBasedTightNoIso() ?  1: 0;
    POGTightl2 = Electrons[1].Pass_CutBasedTightNoIso()?  1: 0;
    
    POGMediuml1 = Electrons[0].Pass_CutBasedMediumNoIso()?  1: 0;
    POGMediuml2 = Electrons[1].Pass_CutBasedMediumNoIso()?  1: 0;


    Minirelisol1   = Electrons[0].MiniRelIso();
    Minirelisol2   = Electrons[1].MiniRelIso();

    
    MissingHitsl1 = Electrons[0].NMissingHits();
    MissingHitsl2 = Electrons[1].NMissingHits();
    
    Full5x5_sigmaIetaIetal1  = Electrons[0].Full5x5_sigmaIetaIeta();
    Full5x5_sigmaIetaIetal2  = Electrons[1].Full5x5_sigmaIetaIeta();

    dEtaSeedl1  = Electrons[0].dEtaSeed();
    dEtaSeedl2  = Electrons[1].dEtaSeed();

    dPhiInl1  = Electrons[0].dPhiIn();
    dPhiInl2  = Electrons[1].dPhiIn();

    HoverEl1  = Electrons[0].HoverE();
    HoverEl2  = Electrons[1].HoverE();
    
    TrkIsol1  = Electrons[0].TrkIso();
    TrkIsol2  = Electrons[1].TrkIso();

    InvEminusInvP_l1 = fabs(Electrons[0].InvEminusInvP());
    InvEminusInvP_l2 = fabs(Electrons[1].InvEminusInvP());
    
    ecalPFClusterIsol1 = Electrons[0].ecalPFClusterIso()/Electrons[0].UncorrPt();
    ecalPFClusterIsol2 = Electrons[1].ecalPFClusterIso()/Electrons[1].UncorrPt();

    hcalPFClusterIsol1 = Electrons[0].hcalPFClusterIso()/Electrons[0].UncorrPt();
    hcalPFClusterIsol2 = Electrons[1].hcalPFClusterIso()/Electrons[1].UncorrPt();

    isEcalDrivenl1 = Electrons[0].isEcalDriven();
    isEcalDrivenl2 = Electrons[1].isEcalDriven();
    
    PassConversionVetol1  = (Electrons[0].PassConversionVeto()) ? 1 : 0;
    PassConversionVetol2  = (Electrons[1].PassConversionVeto()) ? 1 : 0;

    IsGsfCtfScPixChargeConsistentl1  = (Electrons[0].IsGsfCtfScPixChargeConsistent()) ? 1 : 0;
    IsGsfCtfScPixChargeConsistentl2  = (Electrons[1].IsGsfCtfScPixChargeConsistent()) ? 1 : 0;

  }
  else{

    Dxyl1   = Muons[0].dXY();
    Dxyl2   = Muons[1].dXY();

    Dzl1   = Muons[0].dZ();
    Dzl2   = Muons[1].dZ();

    RelIsol1    = Muons[0].RelIso();
    RelIsol2    = Muons[1].RelIso();

    IP3Dl1    = Muons[0].IP3D();
    IP3Dl2    = Muons[1].IP3D();

    MVAl1    = Muons[0].MVA();
    MVAl2    = Muons[1].MVA();

    Minirelisol1   = Muons[0].MiniRelIso();
    Minirelisol2   = Muons[1].MiniRelIso();


    POGTightl1 = Muons[0].isPOGTight() ?  1: 0;
    POGTightl2 = Muons[1].isPOGTight() ?  1: 0;

    POGMediuml1 = Muons[0].isPOGMedium() ?  1: 0;
    POGMediuml2 = Muons[1].isPOGMedium() ?  1: 0;



    Chi2l1 = Muons[0].Chi2();
    Chi2l2 = Muons[1].Chi2();
    
    Validhitsl1 = Muons[0].ValidMuonHits();
    Validhitsl2 = Muons[1].ValidMuonHits();

    Matched_stationsl1 = Muons[0].MatchedStations();
    Matched_stationsl2 = Muons[1].MatchedStations();

    Pixel_hitsl1  = Muons[0].PixelHits();
    Pixel_hitsl2  = Muons[1].PixelHits();
    Tracker_layersl1 = Muons[0].TrackerLayers();
    Tracker_layersl2 = Muons[1].TrackerLayers();

  }
  //==== Vars for non-prompt lepton bkg
  int IdxMatchJetl1=-1, IdxMatchAwayJetl1=-1, IdxMatchJetl2=-1, IdxMatchAwayJetl2=-1;
  float mindR1=999., maxdPhi1=-999., mindR2=999., maxdPhi2=-999.;

  for(unsigned int ij=0; ij<JetAllColl.size(); ij++){

    float dPhi1 = fabs(TVector2::Phi_mpi_pi(LepTColl.at(0)->Phi() - JetAllColl.at(ij).Phi()));
    if(dPhi1>maxdPhi1){ maxdPhi1=dPhi1; IdxMatchAwayJetl1=ij; }
    float dR1=LepTColl.at(0)->DeltaR(JetAllColl.at(ij));
    if(dR1>0.4) continue;
    if(dR1<mindR1){ mindR1=dR1; IdxMatchJetl1=ij; }

  }

  for(unsigned int ij=0; ij<JetAllColl.size(); ij++){

    float dPhi2 = fabs(TVector2::Phi_mpi_pi(LepTColl.at(1)->Phi() - JetAllColl.at(ij).Phi()));
    if(dPhi2>maxdPhi2){ maxdPhi2=dPhi2; IdxMatchAwayJetl2=ij; }
    float dR2=LepTColl.at(1)->DeltaR(JetAllColl.at(ij));
    if(dR2>0.4) continue;
    if(dR2<mindR2){ mindR2=dR2; IdxMatchJetl2=ij; }

  }

  if(IdxMatchJetl1!=-1){

    PtRatiol1   = LepTColl.at(0)->Pt()/JetAllColl.at(IdxMatchJetl1).Pt();
    TLorentzVector JetNoLep1(JetAllColl.at(IdxMatchJetl1));
    JetNoLep1  -= *LepTColl.at(0);
    PtRelv0l1   = LepTColl.at(0)->Perp(JetAllColl.at(IdxMatchJetl1).Vect());
    PtRelv1l1   = LepTColl.at(0)->Perp(JetNoLep1.Vect());
    CEMFracCJl1 = JetAllColl.at(IdxMatchJetl1).ChargedEmEnergyFraction();
    NEMFracCJl1 = JetAllColl.at(IdxMatchJetl1).NeutralEmEnergyFraction();
    CHFracCJl1  = JetAllColl.at(IdxMatchJetl1).ChargedHadEnergyFraction();
    NHFracCJl1  = JetAllColl.at(IdxMatchJetl1).NeutralHadEnergyFraction();
    MuFracCJl1  = JetAllColl.at(IdxMatchJetl1).MuonEnergyFraction();
    JetDiscCJl1 = JetAllColl.at(IdxMatchJetl1).GetTaggerResult(JetTagging::DeepJet);

  }
  else{

    PtRatiol1=-1., PtRelv0l1=-1., PtRelv1l1=-1., CEMFracCJl1=-1., NEMFracCJl1=-1., CHFracCJl1=-1., NHFracCJl1=-1., MuFracCJl1=-1., JetDiscCJl1=-1.;

  }

  if(IdxMatchJetl2!=-1){

    PtRatiol2   = LepTColl.at(1)->Pt()/JetAllColl.at(IdxMatchJetl2).Pt();
    TLorentzVector JetNoLep2(JetAllColl.at(IdxMatchJetl2));
    JetNoLep2  -= *LepTColl.at(1);
    PtRelv0l2   = LepTColl.at(1)->Perp(JetAllColl.at(IdxMatchJetl2).Vect());
    PtRelv1l2   = LepTColl.at(1)->Perp(JetNoLep2.Vect());
    CEMFracCJl2 = JetAllColl.at(IdxMatchJetl2).ChargedEmEnergyFraction();
    NEMFracCJl2 = JetAllColl.at(IdxMatchJetl2).NeutralEmEnergyFraction();
    CHFracCJl2  = JetAllColl.at(IdxMatchJetl2).ChargedHadEnergyFraction();
    NHFracCJl2  = JetAllColl.at(IdxMatchJetl2).NeutralHadEnergyFraction();
    MuFracCJl2  = JetAllColl.at(IdxMatchJetl2).MuonEnergyFraction();
    JetDiscCJl2 = JetAllColl.at(IdxMatchJetl2).GetTaggerResult(JetTagging::DeepJet);

  }
  else{

    PtRatiol2=-1., PtRelv0l2=-1., PtRelv1l2=-1., CEMFracCJl2=-1., NEMFracCJl2=-1., CHFracCJl2=-1., NHFracCJl2=-1., MuFracCJl2=-1., JetDiscCJl2=-1.;

  }

  if(IdxMatchAwayJetl1!=-1){

    PtRatioAJl1 = JetAllColl.at(IdxMatchAwayJetl1).Pt()/LepTColl.at(0)->Pt();
    CEMFracAJl1 = JetAllColl.at(IdxMatchAwayJetl1).ChargedEmEnergyFraction();
    NEMFracAJl1 = JetAllColl.at(IdxMatchAwayJetl1).NeutralEmEnergyFraction();
    CHFracAJl1  = JetAllColl.at(IdxMatchAwayJetl1).ChargedHadEnergyFraction();
    NHFracAJl1  = JetAllColl.at(IdxMatchAwayJetl1).NeutralHadEnergyFraction();
    MuFracAJl1  = JetAllColl.at(IdxMatchAwayJetl1).MuonEnergyFraction();
    JetDiscAJl1 = JetAllColl.at(IdxMatchAwayJetl1).GetTaggerResult(JetTagging::DeepJet);

  }
  else{

    PtRatioAJl1=-1., CEMFracAJl1=-1., NEMFracAJl1=-1., CHFracAJl1=-1., NHFracAJl1=-1., MuFracAJl1=-1., JetDiscAJl1=-1.;

  }

  if(IdxMatchAwayJetl2!=-1){

    PtRatioAJl2 = JetAllColl.at(IdxMatchAwayJetl2).Pt()/LepTColl.at(1)->Pt();
    CEMFracAJl2 = JetAllColl.at(IdxMatchAwayJetl2).ChargedEmEnergyFraction();
    NEMFracAJl2 = JetAllColl.at(IdxMatchAwayJetl2).NeutralEmEnergyFraction();
    CHFracAJl2  = JetAllColl.at(IdxMatchAwayJetl2).ChargedHadEnergyFraction();
    NHFracAJl2  = JetAllColl.at(IdxMatchAwayJetl2).NeutralHadEnergyFraction();
    MuFracAJl2  = JetAllColl.at(IdxMatchAwayJetl2).MuonEnergyFraction();
    JetDiscAJl2 = JetAllColl.at(IdxMatchAwayJetl2).GetTaggerResult(JetTagging::DeepJet);

  }
  else{

    PtRatioAJl2=-1., CEMFracAJl2=-1., NEMFracAJl2=-1., CHFracAJl2=-1., NHFracAJl2=-1., MuFracAJl2=-1., JetDiscAJl2=-1.;

  }

  
  w_tot     = !IsDATA? weight:-1.;
  if(lep_channel == MuMu) tree_mm->Fill();
  if(lep_channel == EE)   tree_ee->Fill();
  

}



void HNL_LepIDKinVar::executeEventFromParameter(AnalyzerParameter param){

  
}


void HNL_LepIDKinVar::InitializeTreeVars(){

  Ptl1=-1, Ptl2=-1, Etal1=-1, Etal2=-1;
  PtRatiol1=-1, PtRatiol2=-1, PtRatioAJl1=-1, PtRatioAJl2=-1, PtRelv0l1=-1, PtRelv1l1=-1, PtRelv0l2=-1, PtRelv1l2=-1;
  CEMFracAJl1=-1, CEMFracAJl2=-1, NEMFracAJl1=-1, NEMFracAJl2=-1, CHFracAJl1=-1, CHFracAJl2=-1, NHFracAJl1=-1, NHFracAJl2=-1, MuFracAJl1=-1, MuFracAJl2=-1, JetDiscAJl1=-1, JetDiscAJl2=-1;
  CEMFracCJl1=-1, CEMFracCJl2=-1, NEMFracCJl1=-1, NEMFracCJl2=-1, CHFracCJl1=-1, CHFracCJl2=-1, NHFracCJl1=-1, NHFracCJl2=-1, MuFracCJl1=-1, MuFracCJl2=-1, JetDiscCJl1=-1, JetDiscCJl2=-1;

  Dxyl1=-1.;  Dxyl2=-1.;
  Dzl1=-1.;Dzl2=-1.;
  RelIsol1=-1.;RelIsol2=-1.;
  IP3Dl1=-1.;IP3Dl2=-1.;
  MVAl1=-1.;MVAl2=-1.;
  Chi2l1=-1.;Chi2l2=-1.;
  Validhitsl1=-1.;Validhitsl2=-1.;
  Matched_stationsl1=-1.;Matched_stationsl2=-1.;
  Pixel_hitsl1=-1.;Pixel_hitsl2=-1.;
  Minirelisol1=-1.;Minirelisol2=-1.;
  Pixel_hitsl1=-1.;Pixel_hitsl2=-1.;
  Tracker_layersl1=-1.;Tracker_layersl2=-1.;
  MissingHitsl1=-1.;MissingHitsl2=-1.;
  Full5x5_sigmaIetaIetal1=-1.;Full5x5_sigmaIetaIetal2=-1.;
  dEtaSeedl1=-1.;dEtaSeedl2=-1.;
  dPhiInl1=-1.;dPhiInl2=-1.;
  HoverEl1=-1.;HoverEl2=-1; 
  TrkIsol1=-1.;TrkIsol2=-1.;
  InvEminusInvP_l1=-1.;InvEminusInvP_l2=-1.;
  ecalPFClusterIsol1=-1.;ecalPFClusterIsol2=-1.;
  hcalPFClusterIsol1=-1.;hcalPFClusterIsol2=-1.;
  POGTightl1=-1;
  POGTightl2=-1;
  POGMediuml1 = -1;
  POGMediuml2 = -1;
  isEcalDrivenl1= -1;
  isEcalDrivenl2=-1;
  PassConversionVetol1=-1 , PassConversionVetol2= -1;
  IsGsfCtfScPixChargeConsistentl1 =-1;
  IsGsfCtfScPixChargeConsistentl2 = -1;
  
  w_tot=-1;

}



HNL_LepIDKinVar::HNL_LepIDKinVar(){

  tree_mm = new TTree("Tree_mm", "Tree_mm");
  tree_ee = new TTree("Tree_ee", "Tree_ee");

}


HNL_LepIDKinVar::~HNL_LepIDKinVar(){

  delete tree_mm;
  delete tree_ee;

}


void HNL_LepIDKinVar::WriteHist(){

  AnalyzerCore::WriteHist();

  outfile->cd();
  tree_mm->Write();
  tree_ee->Write();
  outfile->cd();

}
