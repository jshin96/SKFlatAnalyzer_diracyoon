#include "Vcb_BJetRegression_Single_El.h"

void Vcb_BJetRegression_Single_El::initializeAnalyzer(){

  RunSyst = HasFlag("RunSyst");
  cout << "[ExampleRun::initializeAnalyzer] RunSyst = " << RunSyst << endl;

 
  LeptonIDs = {{"POGTight","passLooseID"}};
  LeptonIDSFKeys = {{"NUM_TightID_DEN_TrackerMuons","passLooseID"}};
  LeptonISOSFKeys = {{"NUM_TightRelIso_DEN_TightIDandIPCut","passLooseID"}};

  if(DataYear == 2016){
    IsoMuTriggerName = "IsoMu24";
    IsoElTriggerName = "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v";
    ElTriggerSafePtCut = 30;
    MuTriggerSafePtCut = 26;
  }
  else if(DataYear == 2017){
    IsoMuTriggerName = "IsoMu27";
    IsoElTriggerName = "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v";
    ElTriggerSafePtCut = 37;
    MuTriggerSafePtCut = 30;
  }
  if(DataYear == 2018){
    IsoMuTriggerName = "IsoMu24";
    IsoElTriggerName = "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v";
    ElTriggerSafePtCut = 35;
    MuTriggerSafePtCut = 26;
  }

  cout << "[ExampleRun::initializeAnalyzer] IsoMuTriggerName = " << IsoMuTriggerName << endl;
  cout << "[ExampleRun::initializeAnalyzer LeadMuTriggerSafePtCut = " << MuTriggerSafePtCut << endl;

//  jtps.push_back( JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::iterativefit, JetTagging::iterativefit) );
  jtps.push_back( JetTagging::Parameters(JetTagging::DeepCSV, JetTagging::Medium, JetTagging::incl, JetTagging::comb) );
  mcCorr->SetJetTaggingParameters(jtps);
}
void Vcb_BJetRegression_Single_El::executeEvent(){
  AnalyzerParameter param;
  AllMuons = GetAllMuons();
  AllJets = GetAllJets();
  AllElectrons = GetAllElectrons();

  for(unsigned int it_LeptonID=0; it_LeptonID<LeptonIDs.size(); it_LeptonID++){
    TString MuonID = LeptonIDs.at(it_LeptonID).at(0);
    TString MuonIDSFKey = LeptonIDSFKeys.at(it_LeptonID).at(0);
    TString ElectronID = LeptonIDs.at(it_LeptonID).at(1);
    TString ElectronIDSFKey = LeptonIDSFKeys.at(it_LeptonID).at(1);
    TString MuonISOSFKey = LeptonISOSFKeys.at(it_LeptonID).at(0);
    TString ElectronISOSFKey = LeptonISOSFKeys.at(it_LeptonID).at(1);

    param.Clear();
    param.syst_ = AnalyzerParameter::Central;
    param.ElName = MuonID+"_"+"Central";
    param.ElName = ElectronID+"_"+"Central";
    param.Muon_Tight_ID = MuonID;
    param.Muon_ID_SF_Key = MuonIDSFKey;
    param.Muon_ISO_SF_Key = MuonISOSFKey;
    param.Electron_Loose_ID = ElectronID;
    param.Electron_ID_SF_Key = ElectronIDSFKey;
    param.Jet_ID = "tight";
    param.Muon_Trigger_SF_Key = IsoMuTriggerName;
    param.Electron_Trigger_SF_Key = IsoElTriggerName;
//    param.PUJet_Veto_ID = "LoosePileupJetVeto";

    executeEventFromParameter(param);

    if(RunSyst){
    
      for(int it_syst=1; it_syst<AnalyzerParameter::NSyst; it_syst++){
        param.syst_ = AnalyzerParameter::Syst(it_syst);
        param.ElName = MuonID+"_"+"Syst_"+param.GetSystType();
        param.ElName = ElectronID+"_"+"Syst_"+param.GetSystType();
        executeEventFromParameter(param);
      }
    }  
  }
}

void Vcb_BJetRegression_Single_El::executeEventFromParameter(AnalyzerParameter param){
  FillHist(param.ElName+"/NoCut_"+param.Name, 0., 1., 1, 0., 1.);
//  FillHist(param.ElName+"/NoCut_"+param.Name, 0., 1., 1, 0., 1.);

  if(!PassMETFilter()) return;

  Event ev = GetEvent();

  if(!(ev.PassTrigger(IsoElTriggerName))) return;
//  if(!(ev.PassTrigger(IsoMuTriggerName))) return;
  FillHist(param.ElName+"/PassTrig_"+param.Name, 0., 1., 1, 0., 1.);
//  FillHist(param.ElName+"/PassTrig_"+param.Name, 0., 1., 1, 0., 1.);

  vector<Jet> this_AllJets = AllJets;
  vector<Muon> this_AllMuons = AllMuons;
  vector<Electron> this_AllElectrons = AllElectrons;
  if(param.syst_ == AnalyzerParameter::Central){

  }
  else if(param.syst_ == AnalyzerParameter::JetResUp){
    this_AllJets = SmearJets( this_AllJets, +1 );
    //this_AllFatJets = SmearFatJets( this_AllFatJets, +1 );
  }
  else if(param.syst_ == AnalyzerParameter::JetResDown){
    this_AllJets = SmearJets( this_AllJets, -1 );
    
    //this_AllFatJetsthis_AllJets = SmearJets( this_AllJets, -1 ); = SmearFatJets( thit_AllFatJets, -1 ); }
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


//  jets = SelectJets(jets, param.PUJet_Veto_ID, 20., 2.5);


  vector<Muon> muons = SelectMuons(this_AllMuons, param.Muon_Tight_ID, MuTriggerSafePtCut, 2.4);
  vector<Electron> electrons = SelectElectrons(this_AllElectrons, param.Electron_Loose_ID, ElTriggerSafePtCut, 2.5);
  vector<Muon> veto_muons = SelectMuons(this_AllMuons, param.Muon_Tight_ID, 15., 2.4); 
  vector<Electron> veto_electrons = SelectElectrons(this_AllElectrons, param.Electron_Loose_ID, 15., 2.5);
  vector<Jet> jets = SelectJets(this_AllJets, param.Jet_ID, 20., 2.5); 
  FillHist(param.ElName+"/nElectrons_"+param.Name, electrons.size(), 1., 10, 0., 11);
  jets = JetsVetoLeptonInside(jets,veto_electrons,veto_muons,0.4);


//  if(ev.PassTrigger(IsoElTriggerName)){
//    vector<Electron> electrons = SelectElectrons(this_AllElectrons, param.Electron_Loose_ID, 7., 2.4);
//  } 

  std::sort(jets.begin(), jets.end(), PtComparing);
  if(jets.size() != 1) return;
  FillHist(param.ElName+"/PassTwoJets_"+param.Name, 0, 1., 1, 0, 1);
  double LeadBTagging_Score = jets.at(0).GetTaggerResult(JetTagging::DeepCSV);
  double BtagCutValue = mcCorr->GetJetTaggingCutValue( JetTagging::DeepCSV, JetTagging::Medium);
  if(LeadBTagging_Score < BtagCutValue){
    FillHist(param.ElName+"/FailBTagging_"+param.Name, 0, 1., 1, 0, 1);
    return;
  }
//  JetTagging::Parameters jtp_DeepJet_Tight = JetTagging::Parameters(JetTagging::DeepJet,
//                                                                     JetTagging::Medium,
//                                                                     JetTagging::iterativefit, JetTagging::iterativefit);
//  JetTagging::Parameters jtp_DeepJet_Tight = JetTagging::Parameters(JetTagging::DeepJet,
//                                                                     JetTagging::Medium,
//                                                                     JetTagging::incl, JetTagging::comb);
  vector<Jet> leadjet;
  leadjet.push_back(jets.at(0)); 
  double btagWeight = 1.;
//  double btagWeight = mcCorr->GetBTaggingReweight_1d(jets, jtps.at(0), "central");
  btagWeight = mcCorr->GetBTaggingReweight_1a(leadjet, jtps.at(0));
//  double btagWeight = mcCorr->GetBTaggingReweight_1a(jets, jtp_DeepJet_Tight);
//  double DY_PT_Corr = 1.;
  double weight = 1.;
  weight_pujet_veto = 1.;
  FillHist(param.ElName+"/BTagWeight_"+param.Name, btagWeight, 1., 40, 0, 5);
  if(!IsDATA){    
    FillHist(param.ElName+"/MCWeight_"+param.Name, MCweight(), 1., 40, 0, 5);
    weight *= MCweight();

    weight *= ev.GetTriggerLumi("Full");
    FillHist(param.ElName+"/TrigWeight_"+param.Name, ev.GetTriggerLumi("Full"), 1., 100, 0, 1000);

    weight_Prefire = GetPrefireWeight(0); 
    weight *= weight_Prefire;
    FillHist(param.ElName+"/PrefireWeight_"+param.Name, weight_Prefire, 1., 40, 0, 5);

    weight *= btagWeight;
    FillHist(param.ElName+"/Btagweight_"+param.Name, btagWeight, 1., 40, 0, 5);

    weight *= mcCorr->GetPileUpWeight(nPileUp, 0);
    FillHist(param.ElName+"/Pileupweight_"+param.Name, GetPileUpWeight(nPileUp, 0), 1., 40, 0, 5);


//    AllGens = GetGens();
//    DY_PT_Corr = mcCorr->GetOfficialDYReweight(AllGens,0);
//    weight *= DY_PT_Corr;

//    weight_pujet_veto = mcCorr->PileupJetVeto_Reweight(jets, param.PUJet_Veto_ID, 0);
//    weight *= weight_pujet_veto;

  }
  std::sort(electrons.begin(), electrons.end(), PtComparing);
    
  if(electrons.size() != 2) return;
  if(veto_muons.size() != 0) return;
  FillHist(param.ElName+"/TwoElectrons_"+param.Name, 0., 1., 1, 0., 1.);
  if(electrons.at(0).Charge() == electrons.at(1).Charge()) return;
  FillHist(param.ElName+"/OppositeCharge_"+param.Name, 0., 1., 1, 0., 1.);
  if(electrons.at(0).Pt() <= ElTriggerSafePtCut) return;
  FillHist(param.ElName+"/pT_Threshold_"+param.Name, 0., 1., 1, 0., 1.);
  Particle Z_cand = electrons.at(0) + electrons.at(1);
//  double BJetNNCorr = 1.0;          //To not apply BJetRegression
//  BJetNNCorr = jets.at(0).BJetNNCorrection();
//  jets.at(0) *= BJetNNCorr;
//  if(Z_cand.Pt() < 50) {
//    return;
//  }
  FillHist(param.ElName+"/Z_pT_Cut_"+param.Name, 0., 1., 1, 0., 1.);
  if(Z_cand.M() >= 111 || Z_cand.M() <= 71) return;



  if(!IsDATA){  
      //double this_triggersf = 1.;
//    double this_triggersf = mcCorr->ElectronTrigger_SF("POGLoose", param.Electron_Trigger_SF_Key , electrons, 0);
//    weight *= this_triggersf;
    for(unsigned int i=0; i<electrons.size(); i++){

        //double this_idsf = 1.;
      double this_idsf  = mcCorr->ElectronID_SF (param.Electron_ID_SF_Key,  electrons.at(i).scEta(), electrons.at(i).UncorrPt());

        //==== If you have iso SF, do below. Here we don't.
//      double this_recosf = 1.;
      double this_recosf = mcCorr->ElectronReco_SF(electrons.at(i).scEta(), electrons.at(i).UncorrPt(),0);
      weight *= this_idsf*this_recosf;     
    
    

    }
  }



  if(abs(jets.at(0).DeltaPhi(Z_cand)) > 2.8) {
    FillHist(param.ElName+"/Z_leadjet_dphi_Cut_"+param.Name, 0., 1., 1, 0., 1.);
  } else return;
  if(!IsDATA){  
    vector<Gen> gens = GetGens();
    double Gen_Jet_dR = 999;
    for(unsigned int i=0; i<gens.size(); i++){
      if  (gens.at(i).PID() == 23 and gens.at(i).isLastCopy()){
        FillHist(param.ElName+"/GenZ_pT_"+param.Name, gens.at(i).Pt(), weight, 50, 0., 500.);
      }
      if(jets.at(0).DeltaR(gens.at(i)) < 0.4 and jets.at(0).DeltaR(gens.at(i)) < Gen_Jet_dR){
        Gen_Jet_dR = jets.at(0).DeltaR(gens.at(i));
        Gen_b = gens.at(i);
      }
    }
  }
  Particle rest = Z_cand;
  float rest_PT = rest.Pt();

  FillHist(param.ElName+"/Z_pT_"+param.Name, Z_cand.Pt(), weight, 50, 0., 500);
  FillHist(param.ElName+"/Z_mass_constraint_"+param.Name, 0., 1., 1, 0., 1.);
  FillHist(param.ElName+"/Z_leadjet_dphi_Val_"+param.Name, abs(jets.at(0).DeltaPhi(Z_cand)), weight, 30, 0., 3.2);
  FillHist(param.ElName+"/leadjet_pt_"+param.Name, jets.at(0).Pt(),weight, 40, 0, 200);
  FillHist(param.ElName+"/leadjet_pt_frac_"+param.Name, jets.at(0).Pt()/Z_cand.Pt(), weight, 20, 0, 1);
  FillHist(param.ElName+"/LeadJet_BTagging_Score_"+param.Name, LeadBTagging_Score, weight, 40, 0, 1);
  FillHist(param.ElName+"/ZCand_Mass_"+param.ElName, Z_cand.M(), weight, 40, 71., 111.);
  FillHist(param.ElName+"/pTlead_over_rest_"+param.ElName, jets.at(0).Pt()/rest.Pt(), weight, 25, 0., 2.);
  for(unsigned int pt_ind=0; pt_ind<10; pt_ind++){
///////////(20,40,60,80,100)
    if(pt_ind<=3){
      if(jets.at(0).Pt()<(40+(pt_ind*20)) and jets.at(0).Pt()>=(20+(pt_ind*20))){
        FillHist(param.ElName+"/pTlead_over_rest_alpha_"+pt_ind+"_"+param.ElName, jets.at(0).Pt()/rest_PT, weight, 25, 0., 2.);
        FillHist(param.ElName+"/Genb_Jetb_"+pt_ind+"_"+param.ElName, jets.at(0).Pt()/Gen_b.Pt(), weight, 25, 0., 2.);
        break;
      }
    }
//////////(100,140,180,220,260,300)
    if(pt_ind>3 and pt_ind <=5){
      if(jets.at(0).Pt()<((pt_ind*50)-50) and jets.at(0).Pt()>=((pt_ind*50)-100)){
        FillHist(param.ElName+"/pTlead_over_rest_alpha_"+pt_ind+"_"+param.ElName, jets.at(0).Pt()/rest_PT, weight, 25, 0., 2.);
        FillHist(param.ElName+"/Genb_Jetb_"+pt_ind+"_"+param.ElName, jets.at(0).Pt()/Gen_b.Pt(), weight, 25, 0., 2.);
        break;
      }
    }
///////// (300,400)
    if(pt_ind>5){
      if(jets.at(0).Pt()<((pt_ind*200)-800) and jets.at(0).Pt()>=((pt_ind*200)-1000)){
        FillHist(param.ElName+"/pTlead_over_rest_alpha_"+pt_ind+"_"+param.ElName, jets.at(0).Pt()/rest_PT, weight, 25, 0., 2.);
        FillHist(param.ElName+"/Genb_Jetb_"+pt_ind+"_"+param.ElName, jets.at(0).Pt()/Gen_b.Pt(), weight, 25, 0., 2.);
        break;
      }
    }
  }
}
Vcb_BJetRegression_Single_El::Vcb_BJetRegression_Single_El(){

}

Vcb_BJetRegression_Single_El::~Vcb_BJetRegression_Single_El(){

}


