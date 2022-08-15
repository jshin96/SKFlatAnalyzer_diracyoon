#include "HNL_SignalRegionPlotter.h"

void HNL_SignalRegionPlotter::initializeAnalyzer(){

  // All default settings like trigger/ PD/ BJet are decalred in HNL_LeptonCore::initializeAnalyzer to make them consistent for all HNL codes

  HNL_LeptonCore::initializeAnalyzer();

}


void HNL_SignalRegionPlotter::executeEvent(){
  
  if((_jentry==0)){ 
    // Print out trigger info in HNL_LeptonCore::initializeAnalyzer
    TriggerPrintOut(GetEvent());
  }
  
  if(!IsData)  gens = GetGens();

  AnalyzerParameter param_signal = HNL_LeptonCore::InitialiseHNLParameter("HNL","_UL");
  RunULAnalysis(param_signal);

  if(!IsData) RunSyst=true;
  if(RunSyst){
    TString param_signal_name = param_signal.Name;
    vector<AnalyzerParameter::Syst> SystList = {AnalyzerParameter::JetResUp,AnalyzerParameter::JetResDown,
						AnalyzerParameter::JetEnUp, AnalyzerParameter::JetEnDown,
						//JetMassUp,JetMassDown,
						//JetMassSmearUp,JetMassSmearDown,
						//MuonRecoSFUp,MuonRecoSFDown,
						//MuonEnUp,MuonEnDown,
						//MuonIDSFUp,MuonIDSFDown,
						//MuonISOSFUp,MuonISOSFDown,
						//ElectronRecoSFUp,ElectronRecoSFDown,
						//ElectronResUp,ElectronResDown,
						//ElectronEnUp,ElectronEnDown,
						//ElectronIDSFUp,ElectronIDSFDown,
						//ElectronTriggerSFUp,ElectronTriggerSFDown,
						//BTagUp,BTagDown,
						//METUnclUp,METUnclDown,
						//CFUp,CFDown,
						//FRUp,FRDown,
						//PrefireUp,PrefireDown,
						AnalyzerParameter::PUUp,AnalyzerParameter::PUDown};

    for(auto isyst : SystList){
      param_signal.syst_ = AnalyzerParameter::Syst(isyst);
      
      param_signal.Name = "Syst_"+param_signal.GetSystType()+param_signal_name;
      param_signal.DefName = "Syst_"+param_signal.GetSystType()+param_signal_name;
      RunULAnalysis(param_signal);
    }
  }    


  //  RunEXO17028Analysis(HNL_LeptonCore::InitialiseHNLParameter("HNL","_2016Anal"));
  
  RunULAnalysis(HNL_LeptonCore::InitialiseHNLParameter("EXO17028","_UL"));
  //RunEXO17028Analysis(HNL_LeptonCore::InitialiseHNLParameter("EXO17028","_2016Anal"));
  return ;
}

void HNL_SignalRegionPlotter::RunULAnalysis(AnalyzerParameter param){

  if(run_Debug) cout << "HNL_SignalRegionPlotter::executeEvent " << endl;

  // SignalRegion settings in InitialiseHNLParameter HNL_LeptonCore.
  //AnalyzerParameter param  = HNL_LeptonCore::InitialiseHNLParameter("SignalRegion");
  //PrintParam(param);

  
  Event ev = GetEvent();
  double weight =SetupWeight(ev,param);

  
  // HL ID
  std::vector<Electron>   ElectronCollV = GetElectrons(param.Electron_Veto_ID, 10., 2.5); 
  std::vector<Muon>       MuonCollV     = GetMuons    (param.Muon_Veto_ID, 5., 2.4);
  std::vector<Muon>       MuonCollT     = MuonPromptOnly    ( GetMuons    ( param,param.Muon_Tight_ID, 5, 2.4, RunFake)      ,gens,param);
  std::vector<Electron>   ElectronCollT = ElectronPromptOnly( GetElectrons( param,param.Electron_Tight_ID, 10, 2.5, RunFake) ,gens,param);

  std::vector<Tau>        mytaus        = GetTaus     (param.Tau_Veto_ID,20., 2.3); 

  // Creat Lepton vector to have lepton blind codes 
  std::vector<Lepton *> LepsT       = MakeLeptonPointerVector(MuonCollT,ElectronCollT);
  std::vector<Lepton *> LepsV  = MakeLeptonPointerVector(MuonCollV,ElectronCollV);

  // JET COLLECTION
  std::vector<FatJet>   fatjets_tmp  = GetFatJets(param, param.FatJet_ID, 200., 5.);
  std::vector<FatJet> FatjetColl                  = GetAK8Jets(fatjets_tmp, 200., 2.7, true,  1., true, -999, true, 40., 130., ElectronCollV, MuonCollV);
  std::vector<FatJet> FatjetColl_notag            = GetAK8Jets(fatjets_tmp, 200., 2.7, true,  1., false, -999, true, 40., 130., ElectronCollV, MuonCollV);


  // AK4 JET
  std::vector<Jet> jets_tmp     = GetJets   ( param, param.Jet_ID, 10., 5.);

  std::vector<Jet> JetColl                        = GetAK4Jets(jets_tmp,     20., 2.7, true,  0.4,0.8,"loose",   ElectronCollV,MuonCollV, FatjetColl);
  std::vector<Jet> VBF_JetColl                    = GetAK4Jets(jets_tmp,     30., 4.7, true,  0.4,0.8,"loose",  ElectronCollV,MuonCollV, FatjetColl);    // High ETa jets 

  // select B jets
  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);

  std::vector<Jet> BJetColl                       = GetBJets(param, jets_tmp,     20., 2.7, false,  0.4,0.8,"loose",   ElectronCollV,MuonCollV, FatjetColl, param_jets);

  // Chose Typ1 Phi corr MET + smear jets 
  Particle METUnsmearedv = GetvMET("T1xyCorr",param); // reyturns MET with systematic correction
  Particle METv =UpdateMETSmearedJet(METUnsmearedv, jets_tmp); // smears MET
  
  RunAllSignalRegions(Inclusive, ElectronCollT,ElectronCollV,MuonCollT,MuonCollV,  JetColl,VBF_JetColl,FatjetColl, BJetColl, ev,METv, param, weight);

  
  
}



void HNL_SignalRegionPlotter::RunEXO17028Analysis(AnalyzerParameter param){

  if(run_Debug) cout << "HNL_SignalRegionPlotter::executeEvent " << endl;

  // SignalRegion settings in InitialiseHNLParameter HNL_LeptonCore.                                                                                                                                       
  //AnalyzerParameter param  = HNL_LeptonCore::InitialiseHNLParameter("EXO17028SR");
  //PrintParam(param);                                                                                                                                                                                     

  Event ev = GetEvent();
  double weight =SetupWeight(ev,param);

  // HL ID                                                                                                                                                                                                 

  std::vector<Electron>   ElectronCollV = GetElectrons(param.Electron_Veto_ID, 10., 2.5);
  std::vector<Muon>       MuonCollV     = GetMuons    (param.Muon_Veto_ID, 5., 2.4);
  std::vector<Muon>       MuonCollT     = MuonPromptOnly    ( GetMuons    ( param,param.Muon_Tight_ID, 5, 2.4, RunFake)      ,gens,param);
  std::vector<Electron>   ElectronCollT = ElectronPromptOnly( GetElectrons( param,param.Electron_Tight_ID, 10, 2.5, RunFake) ,gens,param);



  // Creat Lepton vector to have lepton blind codes                                                                                                                                                        
  std::vector<Lepton *> LepsT       = MakeLeptonPointerVector(MuonCollT,ElectronCollT);
  std::vector<Lepton *> LepsV  = MakeLeptonPointerVector(MuonCollV,ElectronCollV);

  // JET COLLECTION                                                                                                                                                                                        
  std::vector<FatJet>   fatjets_tmp  = GetFatJets(param,param.FatJet_ID, 200, 5.);
  std::vector<FatJet> FatjetColl                  = GetAK8Jets(fatjets_tmp, 200., 2.7, true,  1., true, -999, true, 40., 130., ElectronCollV, MuonCollV);
  // AK4 JET                                                                                                                                                                                               
  std::vector<Jet> jets_tmp     = GetJets   ( param,   param.Jet_ID, 10., 5.);
  std::vector<Jet> JetColl                        = GetAK4Jets(jets_tmp,     20., 2.7, true,  0.4,0.8,"loose",   ElectronCollV,MuonCollV, FatjetColl);

  // select B jets                                                                                                                                                                                         
  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
  std::vector<Jet> BJetColl                       = GetBJets(param,jets_tmp,     20., 2.7, false,  0.4,0.8,"loose",   ElectronCollV,MuonCollV, FatjetColl, param_jets);

  // Chose Typ1 Phi corr MET + smear jets                                                                                                                                                                  
  Particle METUnsmearedv = GetvMET("T1xyCorr",param);
  Particle METv =UpdateMETSmearedJet(METUnsmearedv, jets_tmp);

  RunEXO17028SignalRegions(ElectronCollT,ElectronCollV,MuonCollT,MuonCollV,  JetColl,FatjetColl, BJetColl, ev,METv, param, weight);





}

 


HNL_SignalRegionPlotter::HNL_SignalRegionPlotter(){


}
 
HNL_SignalRegionPlotter::~HNL_SignalRegionPlotter(){

}




