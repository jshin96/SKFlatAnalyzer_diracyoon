#include "HNL_SignalRegionPlotter.h"

void HNL_SignalRegionPlotter::initializeAnalyzer(){

  // All default settings like trigger/ PD/ BJet are decalred in HNL_LeptonCore::initializeAnalyzer to make them consistent for all HNL codes

  HNL_LeptonCore::initializeAnalyzer();

}


void HNL_SignalRegionPlotter::executeEvent(){

  // SignalRegion settings in InitialiseHNLParameter HNL_LeptonCore.
  AnalyzerParameter param  = HNL_LeptonCore::InitialiseHNLParameter("SignalRegion");
  //PrintParam(param);

  double weight(1.);
  Event ev = GetEvent();

  //=== Apply MC weight
  if(!IsDATA){
    double this_mc_weight = ev.GetTriggerLumi("Full") * MCweight(true, true) * GetKFactor()*GetPileUpWeight(nPileUp,0);
    weight     *=  this_mc_weight;
    FillWeightHist("MCWeight_" ,MCweight(true, true));
    FillWeightHist("MCFullWeight_" , this_mc_weight);
    FillWeightHist("PileupWeight_" , GetPileUpWeight(nPileUp,0));
  }
  
  // HL ID
  std::vector<Electron>   ElectronCollT = GetElectrons( param.Electron_Tight_ID, 10., 2.5);
  std::vector<Muon>       MuonCollT     = GetMuons    ( param.Muon_Tight_ID, 5., 2.4);

  std::vector<Electron>   ElectronCollV = GetElectrons(param.Electron_Veto_ID, 10., 2.5); 
  std::vector<Muon>       MuonCollV     = GetMuons    (param.Muon_Veto_ID, 5., 2.4);

  std::vector<Tau>        mytaus      = GetTaus(param.Tau_Veto_ID,20., 2.3); 

  // Creat Lepton vector to have lepton blind codes 
  std::vector<Lepton *> LepsT       = MakeLeptonPointerVector(MuonCollT,ElectronCollT);
  std::vector<Lepton *> LepsV  = MakeLeptonPointerVector(MuonCollV,ElectronCollV);

  
  vector<FatJet>   this_AllFatJets   =  puppiCorr->Correct(GetAllFatJets());
  std::vector<FatJet>   fatjets_tmp  = SelectFatJets(this_AllFatJets, param.FatJet_ID, 200, 5.);
  std::vector<Jet>      jets_tmp     = GetJets   ( param.Jet_ID,    15., 5.);

  std::vector<FatJet> FatjetColl                  = GetAK8Jets(fatjets_tmp, 200., 2.7, true,  1., true, -999, true, 40., 130., ElectronCollV, MuonCollV);
  std::vector<FatJet> FatjetColl_notag            = GetAK8Jets(fatjets_tmp, 200., 2.7, true,  1., false, -999, true, 40., 130., ElectronCollV, MuonCollV);
  std::vector<Jet> JetColl                        = GetAK4Jets(jets_tmp,     20., 2.7, true,  0.4,0.8,"loose",   ElectronCollV,MuonCollV, FatjetColl);

  // select B jets
  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);

  std::vector<Jet> BJetColl                       = GetBJets(jets_tmp,     20., 2.7, false,  0.4,0.8,"loose",   ElectronCollV,MuonCollV, FatjetColl, param_jets);

  std::vector<Jet> VBF_JetColl                    = GetAK4Jets(jets_tmp,     30., 4.7, true,  0.4,0.8,"loose",  ElectronCollV,MuonCollV, FatjetColl); 

  // Chose Typ1 Phi corr MET + smear jets 
  Particle METUnsmearedv = GetvMET("T1xyCorr","");
  Particle METv =UpdateMETSmearedJet(METUnsmearedv, JetColl);
  
  RunAllSignalRegions(Inclusive, ElectronCollT,ElectronCollV,MuonCollT,MuonCollV,  JetColl,VBF_JetColl,FatjetColl, BJetColl, ev,METv, param, weight);

  
}

 


HNL_SignalRegionPlotter::HNL_SignalRegionPlotter(){


}
 
HNL_SignalRegionPlotter::~HNL_SignalRegionPlotter(){

}




