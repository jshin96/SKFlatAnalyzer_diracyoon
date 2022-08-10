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
  
  if(MCSample.Contains("Type") || MCSample.Contains("private"))  MakeType1SignalPlots(process);
  

  AnalyzerParameter param  = InitialiseHNLParameter("SignalStudy","UL");

  double weight(1.);
  Event ev = GetEvent();

  //=== Apply MC weight
  if(!IsDATA){
    double this_mc_weight = ev.GetTriggerLumi("Full") * MCweight(true, true) * GetKFactor() *GetPileUpWeight(nPileUp,0);
    weight     *=  this_mc_weight;
    FillWeightHist("MCWeight_" ,MCweight(true, true));
    FillWeightHist("MCFullWeight_" , this_mc_weight);
   
  }
  
  // HL ID
  std::vector<Electron>   ElectronCollT = GetElectrons( param.Electron_Tight_ID, 10., 2.5);
  std::vector<Muon>       MuonCollT     = GetMuons    ( param.Muon_Tight_ID, 5., 2.4);

  // EXO17028 ID
  
  std::vector<Electron>   JSElectrons    = GetElectrons("HNTight_17028", 10., 2.5);  
  std::vector<Muon>       JSMuons        = GetMuons    ("HNTight_17028", 5., 2.4);


  std::vector<Electron>   ElectronCollV = GetElectrons(param.Electron_Veto_ID, 10., 2.5); 
  std::vector<Muon>       MuonCollV     = GetMuons    (param.Muon_Veto_ID, 5., 2.4);

  std::vector<Tau>        mytaus      = GetTaus(param.Tau_Veto_ID,20., 2.3); 

  std::vector<Lepton *> LepsT       = MakeLeptonPointerVector(MuonCollT,ElectronCollT);
  std::vector<Lepton *> LepsJS       = MakeLeptonPointerVector(JSMuons,JSElectrons);
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


  if (IsData || ( process.Contains("Mu+Mu+") or   process.Contains("Mu-Mu-") )){
    RunLeptonChannel(MuMu,LepsT, LepsV, mytaus, JetColl, VBF_JetColl, FatjetColl, BJetColl, ev, param, weight );
    //param.Name = def_paramName + "_LAK8";
    //RunLeptonChannel(MuMu,LepsT, LepsV, mytaus, JetColl, VBF_JetColl, FatjetColl_notag,BJetColl, ev, param, weight );
  }

  param.Name=param.DefName;

  if (IsData || ( process.Contains("El+El+") or   process.Contains("El-El-") )){
    RunLeptonChannel(EE,LepsT, LepsV, mytaus, JetColl, VBF_JetColl, FatjetColl, BJetColl, ev, param, weight );
  }

  param.Name=param.DefName;

  if (IsData || ( process.Contains("El+Mu+") or   process.Contains("El-Mu-") )){
    RunLeptonChannel(EMu,LepsT, LepsV, mytaus, JetColl, VBF_JetColl, FatjetColl, BJetColl, ev, param, weight );
  }


}


void HNL_SignalStudies::RunLeptonChannel(HNL_LeptonCore::Channel channel_ID, std::vector<Lepton *> LepsT,std::vector<Lepton *> LepsV, std::vector<Tau> TauColl,  std::vector<Jet> JetColl, std::vector<Jet> VBFJetColl,  std::vector<FatJet> FatjetColl,std::vector<Jet> BJetColl,   Event Ev, AnalyzerParameter param,  float _weight)   {
  
  HNL_LeptonCore::SearchRegion Region1 = sigmm;
  HNL_LeptonCore::SearchRegion Region2 = sigmm_17028;

  if(channel_ID == EE) {  Region1 = sigee;   Region2 = sigee_17028;}
  if(channel_ID == EMu){ Region1 = sigem; Region2 = sigem_17028;}
  
  Particle METUnsmearedv = GetvMET("T1xyCorr","");
  Particle METv =UpdateMETSmearedJet(METUnsmearedv, JetColl);


  //if(!CheckStream(Ev,channel_ID)){
  // cout << "[HNL_SignalStudies::RunLepton Channel] wrong data stream ran for Trigger_HNL_X.." << endl;
  //  exit(EXIT_FAILURE);

  //}

  int njets_old =  (JetColl.size() + FatjetColl.size()) ;
  int njets_vbf = (VBFJetColl.size() + FatjetColl.size());
  int njets = ( njets_vbf > njets_old) ? njets_vbf : njets_old ;

  bool dijet = (FatjetColl.size() > 0) || (JetColl.size() > 1);
  bool PassBJetMVeto = (BJetColl.size()==0);


  // Update NAME for Muon channel                                                                                               

  TString region1 = GetChannelString(channel_ID)+"_ChannelSignalsNewSel_"+param.DefName;                                                       
  TString region2 =GetChannelString(channel_ID)+"_ChannelSignalsOldSel_"+param.DefName;                                                       

  FillEventCutflow(Region1,_weight, "SSNoCut",region1);
  FillEventCutflow(Region2,_weight, "SSNoCut",region2);

  // UL ANALYSIS                                                                                                                

  if(MCSample.Contains("Type") || MCSample.Contains("private")){

    vector<Gen> gen_lep= GetGenLepronsSignal();
    std::sort(gen_lep.begin(),   gen_lep.end(),        PtComparing);

    if(gen_lep.size() == 2){
      if( (fabs(gen_lep[0].Eta()) < 2.4 && gen_lep[0].Pt() > 20) &&
          (fabs(gen_lep[1].Eta()) < 2.4 && gen_lep[1].Pt() > 10)){
        FillEventCutflow(Region1,_weight, "SSGen",region1);
	FillEventCutflow(Region2,_weight, "SSGen",region2);
        FillEventCutflow(Region1,_weight, "SSGen2",region1);
        FillEventCutflow(Region2,_weight, "SSGen2",region2);

      }
      else       if( (fabs(gen_lep[0].Eta()) < 2.4 && gen_lep[0].Pt() > 25) &&
                     (fabs(gen_lep[1].Eta()) < 2.4 && gen_lep[1].Pt() > 5)){
        FillEventCutflow(Region1,_weight, "SSGen",region1);
        FillEventCutflow(Region2,_weight, "SSGen",region2);

      }
      else return;
    }
    else return;
  }

  if (!PassTriggerSelection(channel_ID, Ev, LepsT,"Full",false)) return;


  FillEventCutflow(Region1,_weight, "SS"+GetChannelString(channel_ID)+"Trig",region1);
  FillEventCutflow(Region2,_weight, "SS"+GetChannelString(channel_ID)+"Trig",region2);

  if (!(PassTriggerSelection(channel_ID, Ev, LepsT,"Dilep",false) || PassTriggerSelection(channel_ID, Ev, LepsT,"HighPt",false))) return;

  FillEventCutflow(Region1,_weight, "SS"+GetChannelString(channel_ID)+"Trig2",region1);
  FillEventCutflow(Region2,_weight, "SS"+GetChannelString(channel_ID)+"Trig2",region2);


  // PASS DIMUON TRIGGER                                                                                                        
  if (!PassTriggerSelection(channel_ID, Ev, LepsT,"Dilep",false)) return;
  FillEventCutflow(Region1,_weight, "SS"+GetChannelString(channel_ID)+"Trig2L",region1);
  FillEventCutflow(Region2,_weight, "SS"+GetChannelString(channel_ID)+"Trig2L",region2);

  if (LepsT.size() != 2) return;

  if(!SameCharge(LepsT)) return;

  FillEventCutflow(Region1,_weight, "SS"+GetChannelString(channel_ID),region1);
  FillEventCutflow(Region2,_weight, "SS"+GetChannelString(channel_ID),region2);


  if (!CorrectChannelStream(channel_ID, LepsV)) return;

  FillEventCutflow(Region1,_weight, "SS"+GetChannelString(channel_ID)+"_Pt",region1);
  FillEventCutflow(Region2,_weight, "SS"+GetChannelString(channel_ID)+"_Pt",region2);

  if (LepsV.size() != 2) return;
  FillEventCutflow(Region1,_weight, "SS"+GetChannelString(channel_ID)+"_LepVeto",region1);
  FillEventCutflow(Region2,_weight, "SS"+GetChannelString(channel_ID)+"_LepVeto",region2);
  
  int nel_hem(0);   
  if (channel_ID==EE){
    if (DataEra=="2018"){
      for(auto iel : LepsT){
	if (iel->Eta() < -1.25){
	  if((iel->Phi() < -0.82) && (iel->Phi() > -1.62)) nel_hem++;
	}
      }      
    }
  }
  if(nel_hem == 0) {
    FillEventCutflow(Region1,_weight, "SS"+GetChannelString(channel_ID)+"_HEMVeto",region1);
    FillEventCutflow(Region2,_weight, "SS"+GetChannelString(channel_ID)+"_HEMVeto",region2);
  }

  if (channel_ID==EE  && (fabs(GetLLMass(LepsT)-90.) < 15)) return;

  if(GetLLMass(LepsT) > 10.) {
    
    param.Name = GetChannelString(channel_ID)+"_ChannelSignalsNewSel_"+param.DefName;
    

    FillEventCutflow(Region1,_weight, "SS"+GetChannelString(channel_ID)+"_LLMass",region1);

    bool tau_veto = (TauColl.size()==0);

    if(tau_veto) {

      FillEventCutflow(Region1,_weight, "SS"+GetChannelString(channel_ID)+"_vTau",region1);
      
      if(njets > 0 ){
        FillEventCutflow(Region1,_weight, "SS"+GetChannelString(channel_ID)+"_Jet",region1);
	
        if(PassBJetMVeto) {
          FillEventCutflow(Region1,_weight, "SS"+GetChannelString(channel_ID)+"_BJet",region1);
          if(dijet)        FillEventCutflow(Region1,_weight, "SS"+GetChannelString(channel_ID)+"_DiJet",region1);
	  
	  
          if(FatjetColl.size() > 0){
	    
            if(RunSignalRegionAK8( channel_ID, Inclusive, LepsT, LepsV, JetColl, FatjetColl, BJetColl, Ev, METv, param,  "", _weight ))  
	      {
		cout << "RunSignalRegionAK8 Filled" << endl;
		FillEventCutflow(Region1,_weight, "SS"+GetChannelString(channel_ID)+"_SR1",region1);

	      }
	    
            else FillEventCutflow(Region1,_weight, "SS"+GetChannelString(channel_ID)+"_SR1Fail",region1);
          }
          else{

	    if(PassVBFInitial(VBFJetColl)&&RunSignalRegionWW(channel_ID, Inclusive, LepsT, LepsV,  VBFJetColl, FatjetColl, BJetColl, Ev,  METv, param,  "", _weight )){
              FillEventCutflow(Region1,_weight, "SS"+GetChannelString(channel_ID)+"_SR2",region1);


            }
	    else{

              if(RunSignalRegionAK4(channel_ID, Inclusive, LepsT, LepsV , JetColl, FatjetColl, BJetColl, Ev, METv, param, "", _weight ))             FillEventCutflow(Region1,_weight, "SS"+GetChannelString(channel_ID)+"_SR3",region1);


              else if(JetColl.size() < 2 && LepsT[1]->Pt() >80.)             FillEventCutflow(Region1,_weight, "SS"+GetChannelString(channel_ID)+"_SR4",region1);

              else  FillEventCutflow(Region1,_weight, "SS"+GetChannelString(channel_ID)+"_SR3Fail",region1);

            } // FAIL SR2                                                                                                       
          }// Fail SR1                                                                                                          
        }// Fail Tau                                                                                                            
      }// NJET                                                                                                                  
      else if (LepsT[1]->Pt() >80.)   FillEventCutflow(Region1,_weight, "SS"+GetChannelString(channel_ID)+"_SR5",region1);
    } // NO  TAU                                                                                                                
  } // LLMASS      
 

  param.Name=param.DefName;


  // EXO17028 ANALYSIS STRUCTURE
 
  if(GetLLMass(LepsT) > 10.) {

    param.Name = GetChannelString(channel_ID)+"_ChannelSignalsOldSel_"+param.DefName;


    FillEventCutflow(Region2,_weight, "SS"+GetChannelString(channel_ID)+"_LLMass",region2);
    
    if(njets_old > 0){
      FillEventCutflow(Region2,_weight, "SS"+GetChannelString(channel_ID)+"_Jet",region2);
   
      if(PassBJetMVeto) {
        
	FillEventCutflow(Region2,_weight, "SS"+GetChannelString(channel_ID)+"_BJet",region2);
        if(dijet)            FillEventCutflow(Region2,_weight, "SS"+GetChannelString(channel_ID)+"_DiJet",region2);
	
	
        if(FatjetColl.size() > 0){
          if(RunSignalRegionAK8( channel_ID, Inclusive, LepsT, LepsV,JetColl, FatjetColl, BJetColl, Ev, METv, param,  "", _weight ))   FillEventCutflow(Region2,_weight, "SS"+GetChannelString(channel_ID)+"_SR1",region2);
	  
          else             FillEventCutflow(Region2,_weight, "SS"+GetChannelString(channel_ID)+"_SR1Fail",region2);
	  
        }
	else{
	  
	  if(RunSignalRegionAK4(channel_ID, Inclusive, LepsT, LepsV, JetColl, FatjetColl, BJetColl, Ev, METv, param, "", _weight ))             FillEventCutflow(Region2,_weight, "SS"+GetChannelString(channel_ID)+"_SR3",region2);
				
	  

	  else             FillEventCutflow(Region2,_weight, "SS"+GetChannelString(channel_ID)+"_SR3Fail",region2);

	}

      }
    }
  }
  
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
