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
    vector<AnalyzerParameter::Syst> SystList = GetSystList("Initial");

    for(auto isyst : SystList){
      param_signal.syst_ = AnalyzerParameter::Syst(isyst);
      
      param_signal.Name = "Syst_"+param_signal.GetSystType()+param_signal_name;
      param_signal.DefName = "Syst_"+param_signal.GetSystType()+param_signal_name;
      RunULAnalysis(param_signal);
    }
  }    


  //  RunEXO17028Analysis(HNL_LeptonCore::InitialiseHNLParameter("HNL","_2016Anal"));
  
  //RunULAnalysis(HNL_LeptonCore::InitialiseHNLParameter("EXO17028","_UL"));
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

  TString el_ID = (RunFake) ?  param.Electron_FR_ID : param.Electron_Tight_ID ;
  TString mu_ID = (RunFake) ?  param.Muon_FR_ID :  param.Muon_Tight_ID ;

  std::vector<Muon>       MuonCollT     = MuonPromptOnly    ( GetMuons    ( param,mu_ID, 5, 2.4, RunFake)      ,gens,param);
  std::vector<Electron>   ElectronCollT = ElectronPromptOnly( GetElectrons( param,el_ID, 10, 2.5, RunFake) ,gens,param);

  std::vector<Tau>        mytaus        = GetTaus     (param.Tau_Veto_ID,20., 2.3); 

  // Creat Lepton vector to have lepton blind codes 
  std::vector<Lepton *> LepsT       = MakeLeptonPointerVector(MuonCollT,ElectronCollT);
  std::vector<Lepton *> LepsV  = MakeLeptonPointerVector(MuonCollV,ElectronCollV);

  Particle METv = GetvMET("T1xyCorr",param); // reyturns MET with systematic correction

  
  // JET COLLECTION
  bool CheckJetOpt=false;

  if(CheckJetOpt){
    std::vector<FatJet> fatjets_tmp  = GetFatJets(param, param.FatJet_ID, 200., 5.);
    
    std::vector<FatJet> FatjetColl_1                  = GetAK8Jets(fatjets_tmp, 200., 2.7, true,  1., true, -999, true, 40., 130., ElectronCollV, MuonCollV);
    std::vector<FatJet> FatjetColl_2                  = GetAK8Jets(fatjets_tmp, 200., 5.,  true,  1., true, -999, true, 40., 130., ElectronCollV, MuonCollV);
    std::vector<FatJet> FatjetColl_3                  = GetAK8Jets(fatjets_tmp, 200., 2.7, true,  1., false, -999, true, 40., 130., ElectronCollV, MuonCollV);
    std::vector<FatJet> FatjetColl_4                  = GetAK8Jets(fatjets_tmp, 200., 5., true,  1., false, -999, true, 40., 130., ElectronCollV, MuonCollV);
    std::vector<FatJet> FatjetColl_5                  = GetAK8Jets(fatjets_tmp, 200., 2.7, true,  1., false, -999, false, 0., 20000, ElectronCollV, MuonCollV);

    
    // AK4 JET
    std::vector<Jet> jets_tmp     = GetJets   ( param, param.Jet_ID, 20., 5.);
    
    TString PUIDWP="loose";

    std::vector<Jet> BJetColltmp                       = GetAK4Jets(jets_tmp,     20., 2.4, true,  0.4,0.8, "",   ElectronCollV,MuonCollV, FatjetColl_1);
    std::vector<Jet> JetColl                        = GetAK4Jets(jets_tmp,     20., 2.7, true,  0.4,0.8, PUIDWP,   ElectronCollV,MuonCollV, FatjetColl_1);
    std::vector<Jet> VBF_JetColl                    = GetAK4Jets(jets_tmp,     30., 4.7, true,  0.4,0.8, PUIDWP,  ElectronCollV,MuonCollV, FatjetColl_1);    // High ETa jets 
  

    double PJet_PUID_weight = GetJetPileupIDSF(JetColl, PUIDWP, param);
    weight*= PJet_PUID_weight; 
    FillWeightHist("PJet_PUID_weight_" ,PJet_PUID_weight);
    
    
    // select B jets
    JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
    
    // Get BJets  and EV weight to corr BTag Eff                                                                                                                       
    std::vector<Jet> BJetColl    = GetBJets(param,  BJetColltmp, param_jets);
    double sf_btag               = GetBJetSF(param, BJetColltmp, param_jets);
    if(!IsData )weight*= sf_btag;

    
    RunAllSignalRegions(Inclusive, ElectronCollT,ElectronCollV,MuonCollT,MuonCollV,  JetColl,VBF_JetColl,FatjetColl_1, BJetColl, ev,METv, param, weight);
  }
  
  
  else{

    std::vector<FatJet> fatjets_tmp                 = GetFatJets(param, param.FatJet_ID, 200., 5.);

    std::vector<FatJet> AK8_JetColl                  = GetAK8Jets(fatjets_tmp, 200., 5., true,  1., false, -999, false, 0., 20000., ElectronCollV, MuonCollV);
    

    // AK4 JET                                                                                                                                                                              
    std::vector<Jet> jets_tmp     = GetJets   ( param, param.Jet_ID, 20., 5.);

    TString PUIDWP="";
    std::vector<Jet> JetColl                           = GetAK4Jets(jets_tmp,     20., 2.7, true,  0.4,0.8, PUIDWP,   ElectronCollV,MuonCollV, AK8_JetColl);
    std::vector<Jet> VBF_JetColl                       = GetAK4Jets(jets_tmp,     30., 4.7, true,  0.4,0.8, PUIDWP,  ElectronCollV,MuonCollV, AK8_JetColl);    // High ETa jets                 
    std::vector<Jet> BJetColltmp                       = GetAK4Jets(jets_tmp,     20., 2.4, true,  0.4,0.8, "",   ElectronCollV,MuonCollV, AK8_JetColl);

    cout << "Number of VBF_JetColl = " << VBF_JetColl.size() << endl;
    
    if(AK8_JetColl.size() > 0){

      if(AK8_JetColl[0].SDMass() < 20){

	cout << "SDMass = " << AK8_JetColl[0].SDMass()  << endl;
							
	if(MCSample.Contains("Type")){
	  Particle W2 = GetSignalObject("W2","DY");
	  cout << "W2 = " << W2.M() << " Eta " << W2.Eta()  << " phi = " << W2.Phi() << endl;
	  Particle j1 = GetSignalObject("j1","DY");
	  Particle j2 = GetSignalObject("j2","DY");
	  cout << "J1   pt" << j1.Pt() << " Eta " << j1.Eta()  << " phi = " << j1.Phi() <<endl;
	  cout << "J2   pt" << j2.Pt() << " Eta " << j2.Eta()  << " phi = " << j2.Phi() <<endl;
	}

	std::vector<Lepton *> leps       = MakeLeptonPointerVector(MuonCollV,ElectronCollV);
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for(auto ilep : leps) cout << ilep->GetFlavour() << " pt= " << ilep->Pt() << " Eta = " << ilep->Eta() << "  phi = " << ilep->Phi() << endl; 
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for(auto ilep : JetColl) cout << "AK4Jet  pt= " << ilep.Pt() << " Eta = " << ilep.Eta() << "  phi = " << ilep.Phi() << endl; 
	for(auto ilep : VBF_JetColl) cout << "VBF Jet pt= " << ilep.Pt() << " Eta = " << ilep.Eta() << "  phi = " << ilep.Phi() << endl; 
	for(auto ilep : AK8_JetColl) cout << "AK8Jet  pt= " << ilep.Pt() << " Eta = " << ilep.Eta() << "  phi = " << ilep.Phi() << endl;
      }

    }

    double PJet_PUID_weight = GetJetPileupIDSF(JetColl, PUIDWP, param);
    //    weight*= PJet_PUID_weight;
    //FillWeightHist("PJet_PUID_weight_" ,PJet_PUID_weight);


    // select B jets                                                                                                                                                                        
    JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);

    // Get BJets  and EV weight to corr BTag Eff                                                                                                                       
    std::vector<Jet> BJetColl    = GetBJets(param, BJetColltmp, param_jets);
    double sf_btag               = GetBJetSF(param, BJetColltmp, param_jets);
    if(!IsData )weight*= sf_btag;
    RunAllSignalRegions(Inclusive, ElectronCollT,ElectronCollV,MuonCollT,MuonCollV,  JetColl,VBF_JetColl,AK8_JetColl, BJetColl, ev,METv, param, weight);

  }

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


  TString el_ID = (RunFake) ?  param.Electron_FR_ID : param.Electron_Tight_ID ;
  TString mu_ID = (RunFake) ?  param.Muon_FR_ID :  param.Muon_Tight_ID ;

  std::vector<Muon>       MuonCollT     = MuonPromptOnly    ( GetMuons    ( param,mu_ID, 5, 2.4, RunFake)      ,gens,param);
  std::vector<Electron>   ElectronCollT = ElectronPromptOnly( GetElectrons( param,el_ID, 10, 2.5, RunFake) ,gens,param);




  // Creat Lepton vector to have lepton blind codes                                                                                                                                                        
  std::vector<Lepton *> LepsT       = MakeLeptonPointerVector(MuonCollT,ElectronCollT);
  std::vector<Lepton *> LepsV  = MakeLeptonPointerVector(MuonCollV,ElectronCollV);

  // JET COLLECTION                                                                                                                                                                                        
  std::vector<FatJet>   fatjets_tmp  = GetFatJets(param,param.FatJet_ID, 200, 5.);
  std::vector<FatJet> AK8_JetColl                  = GetAK8Jets(fatjets_tmp, 200., 2.7, true,  1., true, -999, true, 40., 130., ElectronCollV, MuonCollV);
  // AK4 JET                                                                                                                                                                                               
  std::vector<Jet> jets_tmp     = GetJets   ( param,   param.Jet_ID, 10., 5.);
  std::vector<Jet> JetColl                        = GetAK4Jets(jets_tmp,     20., 2.7, true,  0.4,0.8,"loose",   ElectronCollV,MuonCollV, AK8_JetColl);

  // select B jets                                                                                                                                                                                         
  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
  std::vector<Jet> BJetColl    = GetBJets(param, jets_tmp, param_jets);
  double sf_btag               = GetBJetSF(param, jets_tmp, param_jets);
  if(!IsData )weight*= sf_btag;

  // Chose Typ1 Phi corr MET + smear jets                                                                                                                                                                  
  Particle METUnsmearedv = GetvMET("T1xyCorr",param);
  Particle METv =UpdateMETSmearedJet(METUnsmearedv, jets_tmp);

  RunEXO17028SignalRegions(ElectronCollT,ElectronCollV,MuonCollT,MuonCollV,  JetColl,AK8_JetColl, BJetColl, ev,METv, param, weight);





}

 


HNL_SignalRegionPlotter::HNL_SignalRegionPlotter(){


}
 
HNL_SignalRegionPlotter::~HNL_SignalRegionPlotter(){

}




