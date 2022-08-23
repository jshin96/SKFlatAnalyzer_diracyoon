#include "HNL_ControlRegionPlotter.h"

void HNL_ControlRegionPlotter::initializeAnalyzer(){

  HNL_LeptonCore::initializeAnalyzer();

}


void HNL_ControlRegionPlotter::executeEvent(){


  Event ev = GetEvent();

  if(!IsData)  gens = GetGens();

  AnalyzerParameter param_signal = HNL_LeptonCore::InitialiseHNLParameter("HNL","_UL");
  RunControlRegions(param_signal);

  if(!IsData) RunSyst=true;
  if(RunSyst){
    TString param_signal_name = param_signal.Name;
    vector<AnalyzerParameter::Syst> SystList = GetSystList("Initial");
    
    for(auto isyst : SystList){
      param_signal.syst_ = AnalyzerParameter::Syst(isyst);

      param_signal.Name = "Syst_"+param_signal.GetSystType()+param_signal_name;
      param_signal.DefName = "Syst_"+param_signal.GetSystType()+param_signal_name;
      RunControlRegions(param_signal);
    }
  }


}

void HNL_ControlRegionPlotter::RunControlRegions(AnalyzerParameter param){
  
  Event ev = GetEvent();
  double weight =SetupWeight(ev,param);
  

  // HL ID                                                                                                                                                   
  std::vector<Electron>   ElectronCollV = GetElectrons(param.Electron_Veto_ID, 10., 2.5);
  std::vector<Muon>       MuonCollV     = GetMuons    (param.Muon_Veto_ID, 5., 2.4);

  TString el_ID = (RunFake) ?  param.Electron_FR_ID : param.Electron_Tight_ID ;
  TString mu_ID = (RunFake) ?  param.Muon_FR_ID :  param.Muon_Tight_ID ;

  std::vector<Muon>       MuonCollT     = MuonPromptOnly    ( GetMuons    ( param,mu_ID, 5, 2.4, RunFake)      ,gens,param);
  std::vector<Electron>   ElectronCollT = ElectronPromptOnly( GetElectrons( param,el_ID, 10, 2.5, RunFake) ,gens,param);

  // Creat Lepton vector to have lepton blind codes                                                                                                          
  std::vector<Lepton *> LepsT       = MakeLeptonPointerVector(MuonCollT,ElectronCollT);
  std::vector<Lepton *> LepsV  = MakeLeptonPointerVector(MuonCollV,ElectronCollV);
  
  Particle METv = GetvMET("PuppiT1xyULCorr",param); // reyturns MET with systematic correction                                                                      

  std::vector<FatJet> fatjets_tmp  = GetFatJets(param, param.FatJet_ID, 200., 5.);
  std::vector<FatJet> FatjetColl                  = GetAK8Jets(fatjets_tmp, 200., 5., true,  1., false, -999, false, 0., 20000., ElectronCollV, MuonCollV);

  std::vector<Jet> jets_tmp     = GetJets   ( param, param.Jet_ID, 20., 5.);
  std::vector<Jet> bjets_tmp     = GetJets   ( param, param.Jet_ID, 20., 2.5);

  TString PUIDWP="";
  std::vector<Jet> JetColl                        = GetAK4Jets(jets_tmp,     20., 2.7, true,  0.4,0.8, PUIDWP,   ElectronCollV,MuonCollV, FatjetColl);
  std::vector<Jet> VBF_JetColl                    = GetAK4Jets(jets_tmp,     30., 4.7, true,  0.4,0.8, PUIDWP,  ElectronCollV,MuonCollV, FatjetColl);   // High ETa jets                                                                                                                                              
  
  double PJet_PUID_weight = GetJetPileupIDSF(JetColl, PUIDWP, param);
  weight*= PJet_PUID_weight;
  FillWeightHist("PJet_PUID_weight_" ,PJet_PUID_weight);
                                                                                                                                                             
  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);

  std::vector<Jet> BJetColl    = GetBJets(param, bjets_tmp, param_jets);
  double sf_btag               = GetBJetSF(param, bjets_tmp, param_jets);
  if(!IsData )weight*= sf_btag;

  RunAllControlRegions(ElectronCollT,ElectronCollV,MuonCollT,MuonCollV,  JetColl,VBF_JetColl,FatjetColl, BJetColl, ev,METv, param, weight);

  

}




HNL_ControlRegionPlotter::HNL_ControlRegionPlotter(){


}
 
HNL_ControlRegionPlotter::~HNL_ControlRegionPlotter(){

}
