#include "HNL_Validation.h"

void HNL_Validation::initializeAnalyzer(){

  // All default settings like trigger/ PD/ BJet are decalred in HNL_LeptonCore::initializeAnalyzer to make them consistent for all HNL codes

  HNL_LeptonCore::initializeAnalyzer();

}


void HNL_Validation::executeEvent(){
  
  
  if(!IsData)  gens = GetGens();

  AnalyzerParameter param_signal = HNL_LeptonCore::InitialiseHNLParameter("HNL","_UL");
  

  if((_jentry==0)){
    // Print out trigger info in HNL_LeptonCore::initializeAnalyzer                                                                                            
    TriggerPrintOut(GetEvent());
    PrintParam(param_signal);
  }
  if(run_Debug) cout << "HNL_Validation::executeEvent " << endl;
  
  Event ev = GetEvent();
  double weight =SetupWeight(ev,param_signal);
  
  // HL ID                                                                                                                                                                                                
  std::vector<Electron>   ElectronCollV = GetElectrons(param_signal.Electron_Veto_ID, 10., 2.5);
  std::vector<Muon>       MuonCollV     = GetMuons    (param_signal.Muon_Veto_ID, 5., 2.4);

  TString el_ID = (RunFake) ?  param_signal.Electron_FR_ID : param_signal.Electron_Tight_ID ;
  TString mu_ID = (RunFake) ?  param_signal.Muon_FR_ID :  param_signal.Muon_Tight_ID ;

  std::vector<Muon>       MuonCollT     = MuonPromptOnly    ( GetMuons    ( param_signal,mu_ID, 5, 2.4, RunFake)      ,gens,param_signal);
  std::vector<Electron>   ElectronCollT = ElectronPromptOnly( GetElectrons( param_signal,el_ID, 10, 2.5, RunFake) ,gens,param_signal);

  std::vector<Tau>        mytaus        = GetTaus     (param_signal.Tau_Veto_ID,20., 2.3); 

  // Creat Lepton vector to have lepton blind codes 
  std::vector<Lepton *> LepsT       = MakeLeptonPointerVector(MuonCollT,ElectronCollT,param_signal);
  std::vector<Lepton *> LepsV  = MakeLeptonPointerVector(MuonCollV,ElectronCollV);
  
  // JET COLLECTION
  std::vector<FatJet>   fatjets_tmp  = GetFatJets(param_signal, param_signal.FatJet_ID, 200., 5.);
  std::vector<FatJet> AK8_JetColl                  = GetAK8Jets(fatjets_tmp, 200., 5., true,  1., false, -999, false, 40., 130., ElectronCollV, MuonCollV);
  
  
  // AK4 JET
  std::vector<Jet> jets_tmp     = GetJets   ( param_signal, param_signal.Jet_ID, 10., 5.);

  std::vector<Jet> JetColl                        = GetAK4Jets(jets_tmp,     20., 2.7, true,  0.4,0.8,"",   ElectronCollV,MuonCollV, AK8_JetColl);
  std::vector<Jet> VBF_JetColl                    = GetAK4Jets(jets_tmp,     30., 4.7, true,  0.4,0.8,"",  ElectronCollV,MuonCollV, AK8_JetColl);    // High ETa jets 
  
  // select B jets
  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
  
  std::vector<Jet> BJetColl                       = GetBJets(param_signal, jets_tmp,     20., 2.7, false,  0.4,0.8,"loose",   ElectronCollV,MuonCollV, AK8_JetColl, param_jets);
  
  // Chose Typ1 Phi corr MET + smear jets 
  Particle METv = GetvMET("T1xyCorr"); // reyturns MET with systematic correction
  
  if(!PassMETFilter()) return;
  
  vector<HNL_LeptonCore::Channel> channels = {EE,MuMu, EMu};
  
  for(auto dilep_channel : channels){
    
    if(run_Debug) cout << "HNL_RegionDefinitions::RunAllSignalRegions " << GetChannelString(dilep_channel) <<  endl;
    
    if(!CorrectChannelStream(dilep_channel, LepsT)) continue;
    
    if (!PassTriggerSelection(dilep_channel, ev, LepsT,"Dilep")) continue;
    
    AnalyzerParameter param_channel = param_signal;
    
    
    TString channel_string = GetChannelString(dilep_channel);
    param_channel.Name =  channel_string + "/" + param_channel.DefName;
    
    float weight_channel = weight;

    if(!IsDATA && dilep_channel != MuMu)  weight_channel*= GetElectronSFEventWeight(ElectronCollT, param_channel);
    if(!IsDATA && dilep_channel != EE)    weight_channel*= GetMuonSFEventWeight(MuonCollT, param_channel);

    if(SameCharge(LepsT)) continue;

    if(RunFake){
      weight_channel = GetFakeWeight(LepsT, param_channel, true);
      FillWeightHist(param_channel.Name+"/FakeWeight",weight_channel);
    }

    int nel_hem(0);
    if (dilep_channel==EE){
      if (DataEra=="2018"){
	for(auto iel : LepsT){
	  if (iel->Eta() < -1.25){
	    if((iel->Phi() < -0.82) && (iel->Phi() > -1.62)) nel_hem++;
	  }
	}
      }
    }
    if(nel_hem > 0) continue;
    if (LepsT.size() != 2 ) continue;
    if (LepsV.size() != 2) continue;
    
    if(LepsT[1]->Pt() > 15)  Fill_RegionPlots(dilep_channel, 0, param_channel.Name,"Dilepton" ,  JetColl, AK8_JetColl, LepsT,  METv, nPV, weight_channel);
    if(LepsT[1]->Pt() > 20)  Fill_RegionPlots(dilep_channel, 0, param_channel.Name,"Dilepton_pt20" ,  JetColl, AK8_JetColl, LepsT,  METv, nPV, weight_channel);
    if(LepsT[1]->Pt() > 20)  Fill_RegionPlots(dilep_channel, 0, param_channel.Name,"Dilepton_pt20_VBF" ,  VBF_JetColl, AK8_JetColl, LepsT,  METv, nPV, weight_channel);
    
    if(BJetColl.size() > 1){
      if(LepsT[1]->Pt() > 20)  Fill_RegionPlots(dilep_channel, 0, param_channel.Name,"BJetDilepton" ,  JetColl, AK8_JetColl, LepsT,  METv, nPV, weight_channel);
    }
        
  }
  return;
}
 


HNL_Validation::HNL_Validation(){


}
 
HNL_Validation::~HNL_Validation(){

}




