#include "Vcb_BJetRegression_Mu_BReg.h"

void Vcb_BJetRegression_Mu_BReg::initializeAnalyzer(){

  RunSyst = HasFlag("RunSyst");
  run_debug = HasFlag("RunDebug");
  cout << "[ExampleRun::initializeAnalyzer] RunSyst = " << RunSyst << endl;

 

  if(DataYear == 2016){
    HLTMuTriggerName = "HLT_IsoMu24_v";
    HLTElTriggerName = "HLT_Ele27_WPTight_Gsf_v";
    MuTriggerName = "IsoMu24";
    ElTriggerName = "Ele27";
    ElTriggerSafePtCut = 30;
    MuTriggerSafePtCut = 26;
  }
  else if(DataYear == 2017){
    HLTMuTriggerName = "HLT_IsoMu27_v";
    HLTElTriggerName = "HLT_Ele32_WPTight_Gsf_L1DoubleEG_";
    MuTriggerName = "IsoMu27";
    ElTriggerName = "Ele32";
    ElTriggerSafePtCut = 35;
    MuTriggerSafePtCut = 30;
  }
  if(DataYear == 2018){
    HLTMuTriggerName = "HLT_IsoMu24_v";
    HLTElTriggerName = "HLT_Ele32_WPTight_Gsf_v";
    MuTriggerName = "IsoMu24";
    ElTriggerName = "Ele32";
    ElTriggerSafePtCut = 35;
    MuTriggerSafePtCut = 26;
  }

  cout << "[ExampleRun::initializeAnalyzer] HLTMuTriggerName = " << HLTMuTriggerName << endl;
  cout << "[ExampleRun::initializeAnalyzer MuTriggerSafePtCut = " << MuTriggerSafePtCut << endl;


  if(run_debug){
    jtps.push_back( JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::comb) );
  }
  else if (RunSyst){
    jtps.push_back( JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::iterativefit, JetTagging::iterativefit) );
  }
  mcCorr->SetJetTaggingParameters(jtps);
}
void Vcb_BJetRegression_Mu_BReg::executeEvent(){
  AnalyzerParameter param;
  AllMuons = GetAllMuons();
  AllJets = GetAllJets();
  AllElectrons = GetAllElectrons();

  param.Clear();
  param.syst_ = AnalyzerParameter::Central;
  param.Muon_Tight_ID = "POGTightWithTightIso";
  param.Muon_Loose_ID = "POGLoose";
  param.Muon_ID_SF_Key = "NUM_TightID_DEN_TrackerMuons";
  param.Muon_ISO_SF_Key = "NUM_TightRelIso_DEN_TightIDandIPCut";
  param.Electron_Loose_ID = "passMVAID_iso_WP90";
  param.Electron_Tight_ID = "passMVAID_iso_WP80";
  param.Jet_ID = "tight";
  param.PUJet_Veto_ID = "LoosePileupJetVeto";
  param.MuName = Muon_Tight_ID+"_"+"Central";
  param.ElName = Electron_Tight_ID+"_"+"Central";

  executeEventFromParameter(param);

  if(RunSyst){
    
    for(int it_syst=1; it_syst<AnalyzerParameter::NSyst; it_syst++){
      param.syst_ = AnalyzerParameter::Syst(it_syst);
      param.MuName = MuonID+"_"+"Syst_"+param.GetSystType();
      param.ElName = ElectronID+"_"+"Syst_"+param.GetSystType();
      executeEventFromParameter(param);
    }
    cout << "Pass Syst" << endl;
  }
}

void Vcb_BJetRegression_Mu_BReg::executeEventFromParameter(AnalyzerParameter param){
  FillHist(param.MuName+"/No_Cut_"+param.Name, 0., 1., 1, 0., 1.);

  if(!PassMETFilter()) return;

  Event ev = GetEvent();

  if(!(ev.PassTrigger(HLTElTriggerName))) return;
  FillHist(param.MuName+"/Trig_Cut_"+param.Name, 0., 1., 1, 0., 1.);

  vector<Jet> this_AllJets = AllJets;
  vector<Muon> this_AllMuons = AllMuons;
  vector<Electron> this_AllElectrons = AllElectrons;
  vector<Gen> gens = GetGens();


  if(param.syst_ == AnalyzerParameter::Central){

  }
  else if(param.syst_ == AnalyzerParameter::JetResUp){
    this_AllJets = SmearJets( this_AllJets, +1 );
    //this_AllFatJets = SmearFatJets( this_AllFatJets, +1 );
  }
  else if(param.syst_ == AnalyzerParameter::JetResDown){
    this_AllJets = SmearJets( this_AllJets, -1 );
  }
  else if(param.syst_ == AnalyzerParameter::JetEnUp){
    this_AllJets = ScaleJets( this_AllJets, +1 );
    //this_AllFatJets = ScaleFatJets( this_AllFatJets, +1 );
  }
  else if(param.syst_ == AnalyzerParameter::JetEnDown){
    this_AllJets = ScaleJets( this_AllJets, -1 );
    //this_AllFatJets = ScaleFatJets( this_AllFatJets, -1 );
  }
/*
  else if(param.syst_ == AnalyzerParameter::MuonEnUp){
    this_AllMuons = ScaleMuons( this_AllMuons, +1 );
  }
  else if(param.syst_ == AnalyzerParameter::MuonEnDown){
    this_AllMuons = ScaleMuons( this_AllMuons, -1 );
  }
  else if(param.syst_ == AnalyzerParameter::ElectronResUp){
    this_AllElectrons = SmearElectrons( this_AllElectrons, +1 );
  }
  else if(param.syst_ == AnalyzerParameter::ElectronResDown){
    this_AllElectrons = SmearElectrons( this_AllElectrons, -1 );
  }
  else if(param.syst_ == AnalyzerParameter::ElectronEnUp){
    this_AllElectrons = ScaleElectrons( this_AllElectrons, +1 );
  }
  else if(param.syst_ == AnalyzerParameter::ElectronEnDown){
    this_AllElectrons = ScaleElectrons( this_AllElectrons, -1 );
  }
*/
  else{
    cout << "[ExampleRun::executeEventFromParameter] Wrong syst" << endl;
    exit(EXIT_FAILURE);
  }


  vector<Jet> jets = SelectJets(this_AllJets, param.Jet_ID, 20., 2.5); 

  vector<Muon> muons = SelectMuons(this_AllMuons, param.Muon_Tight_ID, MuTriggerSafePtCut, 2.4);
  vector<Electron> electrons = SelectElectrons(this_AllElectrons, param.Electron_Tight_ID, ElTriggerSafePtCut, 2.5);
  vector<Muon> veto_muons = SelectMuons(this_AllMuons, param.Muon_Loose_ID, 15., 2.4); 
  vector<Electron> veto_electrons = SelectElectrons(this_AllElectrons, param.Electron_Loose_ID, 15., 2.5);
  jets = SelectJets(jets, param.PUJet_Veto_ID, 20., 2.5);
  jets = JetsVetoLeptonInside(jets,veto_electrons,veto_muons,0.4);
  

  std::sort(jets.begin(), jets.end(), PtComparing);
  if(jets.size() != 2) return;
  cout << "Pass 2Jets" << endl;
  double LeadBTagging_Score = jets.at(0).GetTaggerResult(JetTagging::DeepJet);
  double SubBTagging_Score = jets.at(1).GetTaggerResult(JetTagging::DeepJet);
  double BtagCutValue = mcCorr->GetJetTaggingCutValue( JetTagging::DeepJet, JetTagging::Medium);
  if(LeadBTagging_Score < BtagCutValue){
    cout << "Fail B Tagging" << endl;
    return;
  }

//  double BJetNNCorr = 1.0;          //To not apply BJetRegression
//  BJetNNCorr = jets.at(0).BJetNNCorrection();
//  jets.at(0) *= BJetNNCorr;


  vector<Jet> leadjet;
  leadjet.push_back(jets.at(0)); 
  if(jets.at(0).Pt()<20) return;
  double btagWeight = 1.0;
  if(run_debug){
    btagWeight = mcCorr->GetBTaggingReweight_1a(leadjet, jtps.at(0), "central");
  }
  else{
    if (RunSyst && param.syst_ == AnalyzerParameter::Central){
      btagWeight = mcCorr->GetBTaggingReweight_1d(leadjet, jtps.at(0), "central");
    }
    else if (param.syst_ == AnalyzerParameter::JetEnDown){
      btagWeight = mcCorr->GetBTaggingReweight_1d(leadjet, jtps.at(0), "down_jes");
    }
    else if (param.syst_ == AnalyzerParameter::JetEnUp){
      btagWeight = mcCorr->GetBTaggingReweight_1d(leadjet, jtps.at(0), "up_jes");
    }
    else{
      btagWeight = mcCorr->GetBTaggingReweight_1d(leadjet, jtps.at(0), "central");
    }
  }
  double DY_PT_Corr = 1.;
  double weight = 1.;
  weight_pujet_veto = 1.;
  FillHist(param.MuName+"/BTagWeight_"+param.Name, btagWeight, 1., 40, 0, 5);
  if(!IsDATA){    
    FillHist(param.MuName+"/MCWeight_"+param.Name, MCweight(), 1., 40, 0, 5);
    weight *= MCweight();

    weight *= ev.GetTriggerLumi("Full");
    FillHist(param.MuName+"/TrigWeight_"+param.Name, ev.GetTriggerLumi("Full"), 1., 100, 0, 1000);


    weight *= btagWeight;
    FillHist(param.MuName+"/Btagweight_"+param.Name, btagWeight, 1., 40, 0, 5);


    weight_Prefire = GetPrefireWeight(0); 
    weight_PileUp = mcCorr->GetPileUpWeight(nPileUp, 0);

//    if(RunSyst){
//      if(param.syst_ == AnalyzerParameter::JetEnUp){
//        weight_PileUp = mcCorr->GetPileUpWeight(nPileUp, +1);
//        weight_Prefire = GetPrefireWeight(+1);
//      }
//      if(param.syst_ == AnalyzerParameter::JetEnDown){
//        weight_PileUp = mcCorr->GetPileUpWeight(nPileUp, +1);
//        weight_Prefire = GetPrefireWeight(+1);
//      }
//      weight_pu_veto_down = mcCorr->PileupJetVeto_Reweight(jets, param.PUJet_Veto_ID, -1);
//      weight_pu_veto_up = mcCorr->PileupJetVeto_Reweight(jets, param.PUJet_Veto_ID, +1);
//    }
    weight *= weight_Prefire;
    weight *= weight_PileUp;
    FillHist(param.MuName+"/Pileupweight_"+param.Name, mcCorr->GetPileUpWeight(nPileUp, 0), 1., 40, 0, 5);
    FillHist(param.MuName+"/PrefireWeight_"+param.Name, weight_Prefire, 1., 40, 0, 5);
    AllGens = GetGens();
    DY_PT_Corr = mcCorr->GetOfficialDYReweight(AllGens,0);
    weight *= DY_PT_Corr;

    weight_pujet_veto = mcCorr->PileupJetVeto_Reweight(jets, param.PUJet_Veto_ID, 0);
    weight *= weight_pujet_veto;

  }

  cout << "Pass event weights" << endl;
    
  std::sort(muons.begin(), muons.end(), PtComparing);
  if(electrons.size() != 0 or muons.size()!=2) return;
  if(muons.at(0).Charge() == muons.at(1).Charge()) return;
  if(muons.at(0).Pt() <= ElTriggerSafePtCut) return;
  Particle Z_cand = muons.at(0) + muons.at(1);
 
  if(Z_cand.Pt() < 100) {
    return;
  }

  if(Z_cand.M() >= 111 || Z_cand.M() <= 71) return;



  if(!IsDATA){  
      //double this_triggersf = 1.;
//    double this_triggersf = mcCorr->ElectronTrigger_SF("passTightID", ElTriggerName , electrons, 0);
//    if(RunSyst){
//        double weight_El_trig_down = mcCorr->ElectronTrigger_SF("passTightID", ElTriggerName , electrons, -1);
//        double weight_El_trig_up = mcCorr->ElectronTrigger_SF("passTightID", ElTriggerName , electrons, -1);
//        weight_El_ID_down = 1.0;
//        weight_El_ID_up = 1.0;
//        weight_El_ISO_down = 1.0;
//        weight_El_ISO_up = 1.0;
//    }
//    weight *= this_triggersf;
    for(unsigned int i=0; i<muons.size(); i++){
      double this_idsf = mcCorr->MuonID_SF(param.Muon_Tight_ID, muons.at(i).Eta(), muons.at(i).MiniAODPt(),0);
      double this_isosf = mcCorr->MuonISO_SF(param.Muon_Tight_ID, muons.at(i).Eta(), muons.at(i).MiniAODPt(),0);
      weight *= this_idsf*this_isosf;     
//      if(RunSyst){
//        weight_Mu_ID_down *= mcCorr->MuonID_SF (param.Muon_ID_SF_Key,  muons.at(i).Eta(), muons.at(i).MiniAODPt(),-1);
//        weight_Mu_ID_up *= mcCorr->MuonID_SF (param.Muon_ID_SF_Key,  muons.at(i).Eta(), muons.at(i).MiniAODPt(),+1);
//        weight_Mu_ISO_down *= mcCorr->MuonISO_SF(param.Muon_ISO_SF_Key, muons.at(i).Eta(), muons.at(i).MiniAODPt(),-1);
//        weight_Mu_ISO_up  *= mcCorr->MuonISO_SF(param.Muon_ISO_SF_Key, muons.at(i).Eta(), muons.at(i).MiniAODPt(), +1);
//      }
    }
  }
  double Gen_Jet_dR = 999;

  if(!IsDATA){
    if (gens.size()==0) return; 
    for(unsigned int i=0; i<gens.size(); i++){
      if(jets.at(0).DeltaR(gens.at(i)) < 0.4 and jets.at(0).DeltaR(gens.at(i)) < Gen_Jet_dR and abs(gens.at(i).PID()) > 500 and abs(gens.at(i).PID()) < 600 and gens.at(i).isPrompt()==1){
        Gen_Jet_dR = jets.at(0).DeltaR(gens.at(i));
        Gen_b = gens.at(i);
      }
    }
    if (Gen_Jet_dR == 999) return;
    cout << "Pass gens" << endl;
  }
  Particle rest = Z_cand;
  float rest_PT = rest.Pt();

  if(abs(jets.at(0).DeltaPhi(Z_cand)) > 2.8) {
    FillHist(param.MuName+"/Z_leadjet_dphi_Cut_"+param.Name, 0., 1., 1, 0., 1.);
  } else return;


  if (abs(0.84-(jets.at(0).Pt()/rest_PT))< 0.24){
    FillHist(param.MuName+"/Balanced_subjet_frac_"+param.Name, (jets.at(1).Pt()/Z_cand.Pt()), weight, 40, 0.0, 2.0);
  } 
  else{
    FillHist(param.MuName+"/Unbalanced_subjet_frac_"+param.Name, (jets.at(1).Pt()/Z_cand.Pt()), weight, 40, 0.0, 2.0);
  }
  Particle rest_all = Z_cand+jets.at(1);
  float rest_all_PT = rest_all.Pt();
  if (abs(0.9-(jets.at(0).Pt()/rest_all_PT))< 0.24){
    FillHist(param.MuName+"/All_Balanced_subjet_frac_"+param.Name, (jets.at(1).Pt()/Z_cand.Pt()), weight, 40, 0.0, 2.0);
  } 
  else{
    FillHist(param.MuName+"/All_Unbalanced_subjet_frac_"+param.Name, (jets.at(1).Pt()/Z_cand.Pt()), weight, 40, 0.0, 2.0);
  }

  if(jets.at(1).Pt()/Z_cand.Pt() < 0.3) {
    FillHist(param.MuName+"/subleadjet_carry_pT_Cut_"+param.Name, 0., 1., 1, 0., 1.);
  } else return; 









  FillHist(param.MuName+"/Z_pT_"+param.Name, Z_cand.Pt(), weight, 40, 0., 200);
  FillHist(param.MuName+"/Z_mass_constraint_"+param.Name, 0., 1., 1, 0., 1.);
  FillHist(param.MuName+"/Z_leadjet_dphi_Val_"+param.Name, abs(jets.at(0).DeltaPhi(Z_cand)), weight, 30, 0., 3.2);
  FillHist(param.MuName+"/Z_subjet_dphi_Val_"+param.Name, abs(jets.at(1).DeltaPhi(Z_cand)), weight, 30, 0., 3.2);
  FillHist(param.MuName+"/subjet_pt_frac_"+param.Name, jets.at(1).Pt()/Z_cand.Pt(), weight, 20, 0, 1);
  FillHist(param.MuName+"/subjet_pt_"+param.Name, jets.at(1).Pt(), weight, 40, 0, 200);
  if(jets.at(1).Pt()/Z_cand.Pt()>0. and jets.at(1).Pt()/Z_cand.Pt()<0.155){
    FillHist(param.MuName+"/pTlead_over_rest_alpha_1_"+param.MuName, jets.at(0).Pt()/rest_PT, weight, 25, 0., 2.);
    FillHist(param.MuName+"/pTlead_over_rest_all_alpha_1_"+param.MuName, jets.at(0).Pt()/rest_all_PT, weight, 25, 0., 2.);
    FillHist(param.MuName+"/Genb_Jetb_1_"+param.MuName, jets.at(0).Pt()/Gen_b.Pt(), weight, 25, 0., 2.);
  }
  if(jets.at(1).Pt()/Z_cand.Pt()>0.155 and jets.at(1).Pt()/Z_cand.Pt()<0.185){
    FillHist(param.MuName+"/pTlead_over_rest_alpha_2_"+param.MuName, jets.at(0).Pt()/rest_PT, weight, 25, 0., 2.);
    FillHist(param.MuName+"/pTlead_over_rest_all_alpha_2_"+param.MuName, jets.at(0).Pt()/rest_all_PT, weight, 25, 0., 2.);
    FillHist(param.MuName+"/Genb_Jetb_2_"+param.MuName, jets.at(0).Pt()/Gen_b.Pt(), weight, 25, 0., 2.);
  }
  if(jets.at(1).Pt()/Z_cand.Pt()>0.185 and jets.at(1).Pt()/Z_cand.Pt()<0.23){
    FillHist(param.MuName+"/pTlead_over_rest_alpha_3_"+param.MuName, jets.at(0).Pt()/rest_PT, weight, 25, 0., 2.);
    FillHist(param.MuName+"/pTlead_over_rest_all_alpha_3_"+param.MuName, jets.at(0).Pt()/rest_all_PT, weight, 25, 0., 2.);
    FillHist(param.MuName+"/Genb_Jetb_3_"+param.MuName, jets.at(0).Pt()/Gen_b.Pt(), weight, 25, 0., 2.);
  }
  if(jets.at(1).Pt()/Z_cand.Pt()>0.23 and jets.at(1).Pt()/Z_cand.Pt()<0.3){
    FillHist(param.MuName+"/pTlead_over_rest_alpha_4_"+param.MuName, jets.at(0).Pt()/rest_PT, weight, 25, 0., 2.);
    FillHist(param.MuName+"/pTlead_over_rest_all_alpha_4_"+param.MuName, jets.at(0).Pt()/rest_all_PT, weight, 25, 0., 2.);
    FillHist(param.MuName+"/Genb_Jetb_4_"+param.MuName, jets.at(0).Pt()/Gen_b.Pt(), weight, 25, 0., 2.);
  }
  FillHist(param.MuName+"/leadjet_pt_"+param.Name, jets.at(0).Pt(),weight, 40, 0, 200);
  FillHist(param.MuName+"/leadjet_pt_frac_"+param.Name, jets.at(0).Pt()/Z_cand.Pt(), weight, 20, 0, 1);
  FillHist(param.MuName+"/LeadJet_BTagging_Score_"+param.Name, LeadBTagging_Score, weight, 40, 0, 1);
  FillHist(param.MuName+"/SubJet_BTagging_Score_"+param.Name, SubBTagging_Score, weight, 40, 0, 1);
  FillHist(param.MuName+"/Sum_BTagging_Score_"+param.Name, LeadBTagging_Score+SubBTagging_Score, weight, 40, 0, 2);  
  FillHist(param.MuName+"/ZCand_Mass_"+param.MuName, Z_cand.M(), weight, 40, 71., 111.);
  FillHist(param.MuName+"/pTlead_over_rest_"+param.MuName, jets.at(0).Pt()/rest.Pt(), weight, 25, 0., 2.);
  



//    weight *= weight_pujet_veto;
}


Vcb_BJetRegression_Mu_BReg::Vcb_BJetRegression_Mu_BReg(){

}

Vcb_BJetRegression_Mu_BReg::~Vcb_BJetRegression_Mu_BReg(){

}

