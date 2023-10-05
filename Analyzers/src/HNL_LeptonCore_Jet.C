#include "HNL_LeptonCore.h"


std::vector<FatJet> HNL_LeptonCore::GetHNLAK8Jets(TString JetType, AnalyzerParameter param){

  std::vector<FatJet>   FatjetColl  = GetFatJets(param, "tight", 200., 5.);

  if(JetType=="Loose") return FatjetColl;

  std::vector<Electron>   ElectronCollV = GetElectrons(param.Electron_Veto_ID, 10., 2.5);
  std::vector<Muon>       MuonCollV     = GetMuons    (param.Muon_Veto_ID,     5.,  2.4);

  if(JetType=="HNL")       return SelectAK8Jets  (FatjetColl,  200., 2.7,  true,   1., false, -999, true,  40., 130.,     ElectronCollV, MuonCollV);
  if(JetType=="HNLNoMass") return SelectAK8Jets  (FatjetColl,  200., 2.7,  true,   1., false, -999, false, 0.,  200000.,  ElectronCollV, MuonCollV);
  if(JetType=="BDT")       return SelectAK8Jets  (FatjetColl,  200., 2.7,  true,   1., false, -999, false, 0.,  200000.,  ElectronCollV, MuonCollV);
  if(JetType=="HNL_PNL")   return SelectAK8Jetsv2(FatjetColl,  200., 2.7,  true,   1., false, -999, true,  40., 130.,     "particleNet_WvsQCD", ElectronCollV, MuonCollV);


  return SelectAK8Jets  (FatjetColl,  200., 5.,   true,   1., false, -999, false, 0., 20000., ElectronCollV, MuonCollV);

}

std::vector<Jet> HNL_LeptonCore::GetHNLJets(TString JetType, AnalyzerParameter param){

  /// AK4                                                                                                                                                                                                                              

  if(JetType=="All")          return GetJets   ( param, "NoID",      10.,  5.);
  if(JetType=="NoCut_Eta3")   return GetJets   ( param, "NoID",      10.,  3.);
  if(JetType=="SmearCorr")    return GetJets   ( param, param.Jet_ID,15.,  2.5);


  std::vector<Jet> AK4_Loose     = GetJets   ( param, param.Jet_ID, 10., 5.);

  // AK8                                                                                                                                                                                                                               
  std::vector<FatJet> AK8_JetColl             = GetHNLAK8Jets("HNL", param);

  /// Lepotns for cleaning                                                                                                                                                                                                             
  std::vector<Electron>   ElectronCollV = GetElectrons(param.Electron_Veto_ID, 10., 2.5);
  std::vector<Muon>       MuonCollV     = GetMuons    (param.Muon_Veto_ID,     5.,  2.4);

  if(JetType=="Loose")    return SelectAK4Jets(AK4_Loose,     15., 4.7, true,  0.4,0.8, "",   ElectronCollV,MuonCollV, AK8_JetColl);
  if(JetType=="Tight")    return SelectAK4Jets(AK4_Loose,     20., 2.7, true,  0.4,0.8, "",   ElectronCollV,MuonCollV, AK8_JetColl);
  if(JetType=="VBFTight") return SelectAK4Jets(AK4_Loose,     30., 4.7, true,  0.4,0.8, "",   ElectronCollV,MuonCollV, AK8_JetColl);

  /// BJET                                                                                                                                                                                                                             
  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
  JetTagging::Parameters param_jetsT = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Tight, JetTagging::incl, JetTagging::mujets);
  JetTagging::Parameters param_jetsL = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Loose, JetTagging::incl, JetTagging::mujets);

  if(JetType=="BJetM" || JetType== "BJetT" || JetType== "BJetL" ) {
    std::vector<Jet> BJetCollLoose                   = SelectAK4Jets(AK4_Loose,  20., 2.4, true,  0.4,0.8, "",   ElectronCollV,MuonCollV,  AK8_JetColl);
    if(JetType=="BJetM")          return SelectBJets(param, BJetCollLoose, param_jets);
    if(JetType=="BJetT")          return SelectBJets(param, BJetCollLoose, param_jetsT);
    if(JetType=="BJetL")          return SelectBJets(param, BJetCollLoose, param_jetsL);
  }
  if(JetType=="BJetMPtL" || JetType== "BJetTPtL") {
    std::vector<Jet> BJetCollLoose                   = SelectAK4Jets(AK4_Loose,  10., 2.4, true,  0.4,0.8, "",   ElectronCollV,MuonCollV,  AK8_JetColl);
    if(JetType=="BJetMPtL")          return SelectBJets(param, BJetCollLoose, param_jets);
    if(JetType=="BJetTPtL")          return SelectBJets(param, BJetCollLoose, param_jetsT);
  }

  if(JetType=="BJetMPtM" || JetType=="BJetTPtM") {
    std::vector<Jet> BJetCollLoose                   = SelectAK4Jets(AK4_Loose,  15., 2.4, true,  0.4,0.8, "",   ElectronCollV,MuonCollV,  AK8_JetColl);
    if(JetType=="BJetMPtM")          return SelectBJets(param, BJetCollLoose, param_jets);
    if(JetType=="BJetTPtM")          return SelectBJets(param, BJetCollLoose, param_jetsT);
  }


  if(JetType=="BJetM_NoJC" || JetType== "BJetT_NoJC") {

    std::vector<FatJet> Empty_AK8Coll;
    std::vector<Jet> BJetCollNoJCleaningLoose                   = SelectAK4Jets(AK4_Loose,  20., 2.4, true,  0.4,0.8, "",   ElectronCollV,MuonCollV,  Empty_AK8Coll);
    if(JetType=="BJetM_NoJC")          return SelectBJets(param, BJetCollNoJCleaningLoose, param_jets);
    if(JetType=="BJetT_NoJC")          return SelectBJets(param, BJetCollNoJCleaningLoose, param_jetsT);
  }

  if(JetType=="BJetM_NoLC" || JetType== "BJetT_NoLC") {
    std::vector<Jet> BJetCollNoLepClean              = SelectAK4Jets(AK4_Loose,  20., 2.4, false,  0.4,0.8, "",   ElectronCollV,MuonCollV,  AK8_JetColl);
    if(JetType=="BJetM_NoLC")     return SelectBJets(param, BJetCollNoLepClean, param_jets);
    if(JetType=="BJetT_NoLC")     return SelectBJets(param, BJetCollNoLepClean, param_jetsT);
  }

  // Else just return Standard Jet coll for HNL                                                                                                                                                                                        
  return SelectAK4Jets(AK4_Loose,     20., 2.7, true,  0.4,0.8, "",   ElectronCollV,MuonCollV, AK8_JetColl);

}


TString HNL_LeptonCore::CloseJetFlavour(std::vector<Jet> jetColl, Muon mu){

  int IdxMatchJet=-1;
  float mindR1=999.;

  for(unsigned int ij=0; ij<jetColl.size(); ij++){
    float dR1=mu.DeltaR(jetColl.at(ij));
    if(dR1>0.4) continue;
    if(dR1<mindR1){ mindR1=dR1; IdxMatchJet=ij; }
  }

  if(IdxMatchJet < 0)   return "NULL";

  int JetFlavour = jetColl.at(IdxMatchJet).hadronFlavour();

  if(JetFlavour == 5) return "HF";
  if(JetFlavour == 4) return "HF";
  if(JetFlavour == 0) return "LF";
  return "NULL";
}


TString HNL_LeptonCore::CloseJetFlavour(std::vector<Jet> jetColl, Electron el){

  int IdxMatchJet=-1;
  float mindR1=999.;

  for(unsigned int ij=0; ij<jetColl.size(); ij++){
    float dR1=el.DeltaR(jetColl.at(ij));
    if(dR1>0.4) continue;
    if(dR1<mindR1){ mindR1=dR1; IdxMatchJet=ij; }
  }
  if(IdxMatchJet < 0)   return "NULL";

  int JetFlavour = jetColl.at(IdxMatchJet).hadronFlavour();

  if(JetFlavour == 5) return "HF";
  if(JetFlavour == 4) return "HF";
  if(JetFlavour == 0) return "LF";
  return "NULL";
}


TString HNL_LeptonCore::CloseJetFlavour(std::vector<Jet> jetColl, Lepton* lep){

  int IdxMatchJet=-1;
  float mindR1=999.;

  for(unsigned int ij=0; ij<jetColl.size(); ij++){
    float dR1=lep->DeltaR(jetColl.at(ij));
    if(dR1>0.4) continue;
    if(dR1<mindR1){ mindR1=dR1; IdxMatchJet=ij; }
  }
  if(IdxMatchJet < 0)   return "NULL";

  int JetFlavour = jetColl.at(IdxMatchJet).hadronFlavour();

  if(JetFlavour == 5) return "HF";
  if(JetFlavour == 4) return "HF";
  if(JetFlavour == 0) return "LF";
  return "NULL";
}



std::vector<Jet> HNL_LeptonCore::SelBJets(std::vector<Jet>& jetColl, JetTagging::Parameters jtp){

  std::vector<Jet> bjetColl;
  for(unsigned int i=0; i<jetColl.size(); i++){
    if( jetColl.at(i).GetTaggerResult(jtp.j_Tagger) <= mcCorr->GetJetTaggingCutValue(jtp.j_Tagger, jtp.j_WP) ) continue;
    bjetColl.push_back( jetColl.at(i) );
  }
  return bjetColl;
}


