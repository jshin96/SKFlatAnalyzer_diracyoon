#include "HNL_SignalStudies.h"

void HNL_SignalStudies::initializeAnalyzer(){

  HNL_LeptonCore::initializeAnalyzer();

}




void HNL_SignalStudies::executeEvent(){

  FillHist ("NoCut", 1, 1, 2, 0., 2.,"");
  
  //==== Gen for genmatching

  TString process="";
  if(!IsData){
    gens = GetGens();
    
    process = GetProcess();

    vector<TString> labels ={"Inclusive","OS_ElEl", "SS_El-El-", "SS_El+El+","OS_MuMu", "SS_Mu-Mu-" , "SS_Mu+Mu+","OS_ElMu","SS_El-Mu-" ,"SS_El+Mu+", "OS_MuEl","SS_Mu-El-","SS_Mu+El+"};

    HNL_LeptonCore::FillEventCutflowAll("SignalProcess","SplitChannel",MCweight(true,true), labels, process);
    HNL_LeptonCore::FillEventCutflowAll("SignalProcess","SplitChannel",MCweight(true,true), labels, "Inclusive");
    

    if(_jentry% 10000==0){
      cout << "process = " << process << endl;
      
      PrintGen(gens);
    }


  }
  else{
    if(this->DataStream == "SingleMuon") process = "MuMu";
    else if(this->DataStream == "DoubleMuon") process = "MuMu";
    else if(this->DataStream == "MuonEG") process = "EMu";
    else process = "EE";
  }
  
  
  RunSignalPlotter(process);
}

void HNL_SignalStudies::RunSignalPlotter(TString process){


  AnalyzerParameter param  = InitialiseHNLParameter("SignalStudy");

  double weight(1.);
  Event ev = GetEvent();

  //=== Apply MC weight
  if(!IsDATA){
    double this_mc_weight = ev.GetTriggerLumi("Full") * MCweight(true, true) * GetKFactor();
    weight     *=  this_mc_weight;
    FillWeightHist("MCWeight_" ,MCweight(true, true));
    FillWeightHist("MCFullWeight_" , this_mc_weight);
   
  }
  
  if(!IsData){

    std::vector<Electron>   ElectronCollNC = GetElectrons("NoCut", 10., 2.5);
    std::vector<Muon>       MuonCollNC     = GetMuons    ("NoCut", 5., 2.4);

    if(MuonCollNC.size() == 2){
      if(SameCharge(MuonCollNC))  FillHist ("MM_NoCut", 0, 1, 2, 0., 2.,"");
      else FillHist ("MM_NoCut", 1, 1, 2, 0., 2.,"");
      if(SameCharge(MuonCollNC)) {
	if (MuonCollNC[0].Charge() < 0) FillHist ("SSMM_NoCut", -1, 1, 4, -2., 2.,"");
	else FillHist ("SSMM_NoCut", 1, 1, 4, -2., 2.,"");

	
      }
    }
    if(ElectronCollNC.size() == 2){
      if(SameCharge(ElectronCollNC))  FillHist ("EE_NoCut", 0, 1, 2, 0., 2.,"");
      else FillHist ("EE_NoCut", 1, 1, 2, 0., 2.,"");
      
      if(SameCharge(ElectronCollNC)) {
	if (ElectronCollNC[0].Charge() < 0) FillHist ("SSEE_NoCut", -1, 1, 4, -2., 2.,"");
	else FillHist ("SSEE_NoCut", 1, 1, 4, -2., 2.,"");


      }

    }
  }
  
  return;
  
  // HL ID
  std::vector<Electron>   ElectronCollT = GetElectrons( param.Electron_Tight_ID, 10., 2.5);
  std::vector<Muon>       MuonCollT     = GetMuons    ( param.Muon_Tight_ID, 5., 2.4);

  // EXO17028 ID
  
  std::vector<Electron>   myelectrons_js = GetElectrons("HNTight_17028", 10., 2.5);  
  std::vector<Muon>       mymuons_js     = GetMuons    ("HNTight_17028", 5., 2.4);


  std::vector<Electron>   ElectronCollV = GetElectrons(param.Electron_Veto_ID, 10., 2.5); 
  std::vector<Muon>       MuonCollV     = GetMuons    (param.Muon_Veto_ID, 5., 2.4);

  std::vector<Tau>        mytaus      = GetTaus(param.Tau_Veto_ID,20., 2.3); 
  std::vector<Tau>        alltaus     = GetTaus("NoCut", 20., 2.3);
  
  vector<FatJet>   this_AllFatJets   =  puppiCorr->Correct(GetAllFatJets());

  std::vector<FatJet>   fatjets_tmp  = SelectFatJets(this_AllFatJets, param.FatJet_ID, 200, 5.);
  std::vector<Jet>      jets_tmp     = GetJets   ( param.Jet_ID,    15., 5.);

  std::vector<FatJet> FatjetColl                  = GetAK8Jets(fatjets_tmp, 200., 2.7, true,  1., true, -999, true, 40., 130., ElectronCollV, MuonCollV);
  std::vector<FatJet> FatjetColl_notag            = GetAK8Jets(fatjets_tmp, 200., 2.7, true,  1., false, -999, true, 40., 130., ElectronCollV, MuonCollV);
  std::vector<Jet> JetColl                        = GetAK4Jets(jets_tmp,     20., 2.7, true,  0.4,0.8,"loose",   ElectronCollV,MuonCollV, FatjetColl);
  // select B jets
  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);

  std::vector<Jet> BJetColl                       = GetBJets(jets_tmp,     20., 2.5, false,  0.4,0.8,"loose",   ElectronCollV,MuonCollV, FatjetColl,param_jets);
  std::vector<Jet> VBF_JetColl                    = GetAK4Jets(jets_tmp,     30., 4.7, true,  0.4,0.8,"loose",  ElectronCollV,MuonCollV, FatjetColl); 

  if (IsData || ( process.Contains("Mu+Mu+") or   process.Contains("Mu-Mu-") )){
    RunMuonChannel(ElectronCollT,ElectronCollV,MuonCollT,MuonCollV, mytaus, JetColl, VBF_JetColl, FatjetColl, BJetColl, ev, param, weight );

    param.Name = param.Name + "_LAK8";
    RunMuonChannel(ElectronCollT,ElectronCollV,MuonCollT,MuonCollV, mytaus, JetColl, VBF_JetColl, FatjetColl_notag,BJetColl, ev, param, weight );

  }

}


void HNL_SignalStudies::RunMuonChannel(std::vector<Electron> ElectronColl, std::vector<Electron> VetoElectronColl, std::vector<Muon> MuonColl,  std::vector<Muon> VetoMuonColl, std::vector<Tau> TauColl,  std::vector<Jet> JetColl, std::vector<Jet> VBFJetColl,  std::vector<FatJet> FatjetColl,std::vector<Jet> BJetColl,   Event Ev, AnalyzerParameter param,  float _weight)   {


  Particle METUnsmearedv = Ev.GetMETVector();
  Particle METv =UpdateMETSmearedJet(METUnsmearedv, JetColl);

  // check FOR data that data stream is correct for trigger list
  if(!CheckStream(Ev,Trigger_HNL_Muon)) {
    cout << "[HNL_SignalStudies::RunMuonChannel] wronmg data stream ran for Trigger_HNL_Muon.." << endl;
    exit(EXIT_FAILURE);

  }
  

  std::vector<Lepton *> leps       = MakeLeptonPointerVector(MuonColl,ElectronColl);
  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(VetoMuonColl,VetoElectronColl);

  
  int njets =  (VBFJetColl.size() + FatjetColl.size()) ;
  int njets_old =  (JetColl.size() + FatjetColl.size()) ;
  if( int(JetColl.size() + FatjetColl.size()) > njets) njets = JetColl.size() + FatjetColl.size();
  
  bool dijet = (FatjetColl.size() > 0) || (JetColl.size() > 1);



  //TLorentzVector HNL_LeptonCore::GetvMET(TString METType, TString Option){
    
			       
  int  NBJets_medium      = BJetColl.size();
  bool PassBJetMVeto = (NBJets_medium==0);
  

  param.Name = "MuonChannelSignals_"+param.Name;
  FillEventCutflow(sigmm,_weight, "SSNoCut", param.Name);
  FillEventCutflow(sigmm_17028,_weight, "SSNoCut", param.Name);
  
  // UL ANALYSIS
  
  if(!IsData){
    
    vector<Gen> gen_lep= GetGenLepronsSignal();
    std::sort(gen_lep.begin(),   gen_lep.end(),        PtComparing);

    if(gen_lep.size() == 2){
      if( (fabs(gen_lep[0].Eta()) < 2.4 && gen_lep[0].Pt() > 20) &&
	  (fabs(gen_lep[1].Eta()) < 2.4 && gen_lep[1].Pt() > 10)){
	FillEventCutflow(sigmm,_weight, "SSGen", param.Name);
	FillEventCutflow(sigmm_17028,_weight, "SSGen", param.Name);
	FillEventCutflow(sigmm,_weight, "SSGen2", param.Name);
        FillEventCutflow(sigmm_17028,_weight, "SSGen2", param.Name);

      }
      else       if( (fabs(gen_lep[0].Eta()) < 2.4 && gen_lep[0].Pt() > 25) &&
		     (fabs(gen_lep[1].Eta()) < 2.4 && gen_lep[1].Pt() > 5)){
        FillEventCutflow(sigmm,_weight, "SSGen", param.Name);
        FillEventCutflow(sigmm_17028,_weight, "SSGen", param.Name);

      }
      else return;
    }
    else return;
  }


  if(!Ev.PassTrigger(Trigger_Full_HNL_Muon)) return;

  FillEventCutflow(sigmm,_weight, "SSMMTrig",  param.Name);
  FillEventCutflow(sigmm_17028,_weight, "SSMMTrig",  param.Name);

  if(!Ev.PassTrigger(Trigger_HNL_Muon)) return;
  FillEventCutflow(sigmm,_weight, "SSMMTrig2",  param.Name);
  FillEventCutflow(sigmm_17028,_weight, "SSMMTrig2",  param.Name);

 
  if(SameCharge(VetoMuonColl)) {
    
    FillEventCutflow(sigmm,_weight, "SSMMLoose",  param.Name);
    FillEventCutflow(sigmm_17028,_weight, "SSMMLoose",  param.Name);

  }

  if(MuonColl.size()!=2)  return;
  if(!SameCharge(MuonColl)) return;
  FillEventCutflow(sigmm,_weight, "SSMM",  param.Name);
  FillEventCutflow(sigmm_17028,_weight, "SSMM",  param.Name);

  
  if(MuonColl[0].Pt() < 20) return;
  if(MuonColl[1].Pt() < 10) return;

  FillEventCutflow(sigmm,_weight, "SSMM_Pt",  param.Name);
  FillEventCutflow(sigmm_17028,_weight, "SSMM_Pt",  param.Name);

  
  if(SameCharge(MuonColl) && VetoMuonColl.size()==2 && VetoElectronColl.size()==0 ) {
    
    FillEventCutflow(sigmm,_weight, "SSMM_LepVeto",  param.Name);

    if(GetLLMass(leps) > 10.) {
      FillEventCutflow(sigmm,_weight, "SSMM_LLMass",  param.Name);

      bool tau_veto = (TauColl.size()==0);

      if(tau_veto) {

	FillEventCutflow(sigmm,_weight, "SSMM_vTau",  param.Name);

	
	if(njets > 0 ){
	  FillEventCutflow(sigmm,_weight, "SSMM_Jet",  param.Name);
	  
	  if(PassBJetMVeto) {
	    FillEventCutflow(sigmm,_weight, "SSMM_BJet",  param.Name);
	    if(dijet)        FillEventCutflow(sigmm,_weight, "SSMM_DiJet",  param.Name);	  
	    
	    TString channel_string= GetChannelString(MuMu, SS);
      
	    if(FatjetColl.size() > 0){
	      if(RunSignalRegionAK8( MuMu, SS, leps, leps_veto, JetColl, FatjetColl, BJetColl, Ev, METv, param,  channel_string, _weight ))   FillEventCutflow(sigmm,_weight, "SSMM_SR1",  param.Name);
	      else FillEventCutflow(sigmm,_weight, "SSMM_SR1Fail",  param.Name);
	    }
	    else{
	      
	      // 2 methods:
	      //1) cut on ht/pt  < 1 and Zepp -> Cut and count in SR2
	      //2) use ht/pt shape in SR2 and keep events
	      
	      //if(PassVBFInitial(vbf_jets)) {
	      
	      if(PassVBFInitial(VBFJetColl)&&RunSignalRegionWW( MuMu,SS, leps, leps_veto,  VBFJetColl, FatjetColl, BJetColl, Ev,  METv, param,  channel_string, _weight )){    
		FillEventCutflow(sigmm,_weight, "SSMM_SR2",  param.Name);
		
		
	      }
	      else{
		
		if(RunSignalRegionAK4(MuMu, SS, leps, leps_veto, JetColl, FatjetColl, BJetColl, Ev, METv, param,  channel_string, _weight ))             FillEventCutflow(sigmm,_weight, "SSMM_SR3",  param.Name);
		
		
		else if(JetColl.size() < 2 && leps[1]->Pt() >80.)             FillEventCutflow(sigmm,_weight, "SSMM_SR4",  param.Name);
		
		else  FillEventCutflow(sigmm,_weight, "SSMM_SR3Fail",  param.Name);
		
	      } // FAIL SR2
	    }// Fail SR1
	  }// Fail Tau
	}// NJET
	else if (leps[1]->Pt() >80.)   FillEventCutflow(sigmm,_weight, "SSMM_SR5",  param.Name);
      } // NO  TAU
    } // LLMASS
  }
  
  
  
  // 17028 ANALYSIS                                                                                                                                                                                                                                                                                                            
  
  if(SameCharge(MuonColl) && VetoMuonColl.size()==2 && VetoElectronColl.size()==0 ) {
    

    FillEventCutflow(sigmm_17028,_weight, "SSMM_LepVeto",  param.Name);
    if(GetLLMass(MuonColl) > 10.) {
      
      FillEventCutflow(sigmm_17028,_weight, "SSMM_LLMass",  param.Name);
      if(njets_old > 0){
	FillEventCutflow(sigmm_17028,_weight, "SSMM_Jet",  param.Name);
	if(PassBJetMVeto) {
	  FillEventCutflow(sigmm_17028,_weight, "SSMM_BJet",  param.Name);
	  if(dijet)            FillEventCutflow(sigmm_17028,_weight, "SSMM_DiJet",  param.Name);
	  
	  TString channel_string= GetChannelString(MuMu, SS);
      
	  if(FatjetColl.size() > 0){
	    if(RunSignalRegionAK8( MuMu, SS, leps, leps_veto, JetColl, FatjetColl, BJetColl, Ev, METv, param,  channel_string, _weight ))   FillEventCutflow(sigmm_17028,_weight, "SSMM_SR1",  param.Name);
	    else             FillEventCutflow(sigmm_17028,_weight, "SSMM_SR1Fail",  param.Name);
	    
	  }
	  else{
	    
	    if(RunSignalRegionAK4(MuMu, SS, leps, leps_veto, JetColl, FatjetColl, BJetColl, Ev, METv, param,  channel_string, _weight ))             FillEventCutflow(sigmm_17028,_weight, "SSMM_SR3",  param.Name);
	    
	    
	    else             FillEventCutflow(sigmm_17028,_weight, "SSMM_SR3Fail",  param.Name);
	    
	  }// SR3                                                                                                                                                                                                                                                                                                             
	} // NO AK8                                                                                                                                                                                                                                                                                                 
      } // LLMASS                                                                                                                                          
    }

  }
                                                                                                                                                                  
  

  return;
  
}


HNL_SignalStudies::HNL_SignalStudies(){


}
 
HNL_SignalStudies::~HNL_SignalStudies(){

}




void HNL_SignalStudies::MakeType1SignalPlots(TString process){

  bool mupt_pass=true;
  int mother_nu(0);
  unsigned int ind_w(0);
  TString  mu_ch="";

  gens = GetGens();
  
  for(unsigned int i=2; i<gens.size(); i++){
    Gen gen = gens.at(i);
    vector<int> history = TrackGenSelfHistory(gen, gens);
    
    if(gens.at(gen.MotherIndex()).PID() == 9900012 || gens.at(gen.MotherIndex()).PID() == 9900014){
      if(gen.PID() == 13) mu_ch="minus";
      if(gen.PID() == -13) mu_ch="plus";
      
    }
    
    

    if(fabs(gen.PID()) == 24 && (gens.at(gen.MotherIndex()).PID() == 9900012 || gens.at(gen.MotherIndex()).PID() == 9900014)){
      ind_w= i;
    }
    
    if((gen.PID() == 9900012 || gen.PID() == 9900014) &&  gen.Status() == 22) {
      mother_nu= gen.MotherIndex();
    }
  }
  for(unsigned int i=2; i<gens.size(); i++){
    Gen gen = gens.at(i);
    vector<int> history = TrackGenSelfHistory(gen, gens);
    
    
    if(int(gen.MotherIndex()) == ind_w && gen.Status() == 23) {
      FillHist( ("SignalGen"+process+"/" + mu_ch+"jet_w_pt").Data(), gens.at(i).Pt(), 1., 200, 0., 400.,"");
      FillHist( "SignalGen"+process+"/" + mu_ch+"jet_w_eta", gens.at(i).Eta(),  1., 60, -3., 3,"");
      FillHist( "SignalGen"+process+"/" + mu_ch+"w_dijet_mass", gens.at(gen.MotherIndex()).M(),  1., 200, 0., 200.,"");
    }
    if(gen.PID() == 9900012 || gen.PID() == 9900014){
      FillHist( "SignalGen"+process+"/" + mu_ch+"Neutrino_pt", gens.at(i).Pt(), 1., 200, 0., 400.,"");
      FillHist( "SignalGen"+process+"/" + mu_ch+"Neutrino_mass", gens.at(i).M(), 1., 200, 0., 2000.,"");
      FillHist( "SignalGen"+process+"/" + mu_ch+"Neutrino_eta", gens.at(i).Eta(), 1., 60, -3., 3,"");
    }
    if(fabs(gen.PID()) != 13) continue;

    FillHist( "SignalGen"+process+"/" + mu_ch+"Lep_mu_all_pt", gen.Pt(), 1., 200, 0., 400.,"");

    if(gens.at(gen.MotherIndex()).PID() == 9900012|| gens.at(gen.MotherIndex()).PID() == 9900014) {
      FillHist( "SignalGen"+process+"/" + mu_ch+"Lep_mu_Neutrino_pt", gen.Pt(), 1., 200, 0., 400.,"");
      FillHist( "SignalGen"+process+"/" + mu_ch+"Lep_mu_Neutrino_eta", gen.Eta(),  1., 60, -3., 3,"");
      
      for(unsigned int j=2; j<gens.size(); j++){
	Gen gen2 = gens.at(j);
	vector<int> history = TrackGenSelfHistory(gen2, gens);
	if(j==ind_w){
	  FillHist( "SignalGen"+process+"/" + mu_ch+"Lep_mu_Neutrino_dr_W_Neutrino", gen2.DeltaR(gen), 1., 100, 0., 10.,"");
	  FillHist( "SignalGen"+process+"/" + mu_ch+"Mass_mu_Neutrino__W_Neutrino", (gen2 + gen).M(), 1., 150, 0., 1500.,"");
	}
      }
      
      if(gen.Pt() < 50.) mupt_pass = false;
    }
    else if(gen.MotherIndex() == mother_nu){
      FillHist( "SignalGen"+process+"/" + mu_ch+"Lep_mu_W_pt", gen.Pt(), 1., 200, 0., 400.,"");
      FillHist( "SignalGen"+process+"/" + mu_ch+"Lep_mu_W_eta", gen.Eta(),  1., 60, -3., 3,"");
      if(gen.Pt() < 50.) mupt_pass = false;
      
    }
  }
  
  bool elpt_pass=true;
  for(unsigned int i=2; i<gens.size(); i++){
    Gen gen = gens.at(i);
    vector<int> history = TrackGenSelfHistory(gen, gens);
    
    if(fabs(gen.PID()) != 11) continue;
    
    if(gens.at(gen.MotherIndex()).PID() == 9900012|| gens.at(gen.MotherIndex()).PID() == 9900014) {
      FillHist( "SignalGen"+process+"/" + mu_ch+"Lep_el_Neutrino_pt", gen.Pt(), 1., 200, 0., 400.,"");
      if(gen.Pt() < 35.) elpt_pass = false;
    }
    else if(gen.MotherIndex() == mother_nu){
      
      FillHist( "SignalGen"+process+"/" + mu_ch+"Lep_el_W_pt", gen.Pt(), 1., 200, 0., 400., "");
      
      if(gen.Pt() < 35.) elpt_pass = false;
      
    }
  }
  


}
