#include "Vcb_BJetRegression_Single_Mu.h"

void Vcb_BJetRegression_Single_Mu::initializeAnalyzer(){

  RunSyst = HasFlag("RunSyst");
  cout << "[ExampleRun::initializeAnalyzer] RunSyst = " << RunSyst << endl;

 
  LeptonIDs = {{"POGTight","passLooseID"}};
  LeptonIDSFKeys = {{"NUM_TightID_DEN_TrackerMuons","passLooseID"}};
  LeptonISOSFKeys = {{"NUM_TightRelIso_DEN_TightIDandIPCut","passLooseID"}};

  if(DataYear == 2016){
    IsoMuTriggerName = "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL";
    IsoElTriggerName = "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v";
    ElTriggerSafePtCut = 30;
    MuTriggerSafePtCut = 5;
  }
  else if(DataYear == 2017){
    IsoMuTriggerName = "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8";
    IsoElTriggerName = "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v";
    ElTriggerSafePtCut = 37;
    MuTriggerSafePtCut = 30;
  }
  if(DataYear == 2018){
    IsoMuTriggerName = "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8";
    IsoElTriggerName = "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v";
    ElTriggerSafePtCut = 35;
    MuTriggerSafePtCut = 26;
  }

  cout << "[ExampleRun::initializeAnalyzer] IsoMuTriggerName = " << IsoMuTriggerName << endl;
  cout << "[ExampleRun::initializeAnalyzer LeadMuTriggerSafePtCut = " << MuTriggerSafePtCut << endl;

//  jtps.push_back( JetTagging::Parameters(JetTagging::DeepCSV, JetTagging::Medium, JetTagging::iterativefit, JetTagging::iterativefit) );
  jtps.push_back( JetTagging::Parameters(JetTagging::DeepCSV, JetTagging::Medium, JetTagging::incl, JetTagging::comb) );
  mcCorr->SetJetTaggingParameters(jtps);
}
void Vcb_BJetRegression_Single_Mu::executeEvent(){
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
    param.MuName = MuonID+"_"+"Central";
    param.ElName = ElectronID+"_"+"Central";
    param.Muon_Tight_ID = MuonID;
    param.Muon_ID_SF_Key = MuonIDSFKey;
    param.Muon_ISO_SF_Key = MuonISOSFKey;
    param.Electron_Loose_ID = ElectronID;
    param.Electron_ID_SF_Key = ElectronIDSFKey;
    param.Jet_ID = "tight";
    param.Muon_Trigger_SF_Key = IsoMuTriggerName;
//    param.PUJet_Veto_ID = "LoosePileupJetVeto";

    executeEventFromParameter(param);

    if(RunSyst){
    
      for(int it_syst=1; it_syst<AnalyzerParameter::NSyst; it_syst++){
        param.syst_ = AnalyzerParameter::Syst(it_syst);
        param.MuName = MuonID+"_"+"Syst_"+param.GetSystType();
        param.ElName = ElectronID+"_"+"Syst_"+param.GetSystType();
        executeEventFromParameter(param);
      }
    }  
  }
}

void Vcb_BJetRegression_Single_Mu::executeEventFromParameter(AnalyzerParameter param){
  FillHist(param.MuName+"/NoCut_"+param.Name, 0., 1., 1, 0., 1.);
//  FillHist(param.ElName+"/NoCut_"+param.Name, 0., 1., 1, 0., 1.);

  if(!PassMETFilter()) return;

  Event ev = GetEvent();

  if(!(ev.PassTrigger(IsoMuTriggerName))) return;
//  if(!(ev.PassTrigger(IsoMuTriggerName))) return;
  FillHist(param.MuName+"/PassTrig_"+param.Name, 0., 1., 1, 0., 1.);
//  FillHist(param.ElName+"/PassTrig_"+param.Name, 0., 1., 1, 0., 1.);

  vector<Jet> this_AllJets = AllJets;
  vector<Muon> this_AllMuons = AllMuons;
  vector<Electron> this_AllElectrons = AllElectrons;
  vector<Gen> gens = GetGens();
//  vector<Electron> electrons = SelectElectrons(this_AllElectrons, param.Electron_Loose_ID, 20., 2.4);
//  FillHist(param.ElName+"/nElectron_"+param.Name, electrons.size(), 1., 10, 0., 11);
//  FillHist(param.ElName+"/njets_"+param.Name, jets.size(), 1., 10, 0., 11);
//  FillHist(param.MuName+"/njets_"+param.Name, jets.size(), 1., 10, 0., 11);


//  if(ev.PassTrigger(IsoElTriggerName)){
//    vector<Electron> electrons = SelectElectrons(this_AllElectrons, param.Electron_Loose_ID, 7., 2.4);
//  } 

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
//    this_AllElectrons = SmearElectrons( this_AllElectrons, +1 );
  }
  else if(param.syst_ == AnalyzerParameter::ElectronResDown){
//    this_AllElectrons = SmearElectrons( this_AllElectrons, -1 );
  }
  else if(param.syst_ == AnalyzerParameter::ElectronEnUp){
//    this_AllElectrons = ScaleElectrons( this_AllElectrons, +1 );
  }
  else if(param.syst_ == AnalyzerParameter::ElectronEnDown){
//    this_AllElectrons = ScaleElectrons( this_AllElectrons, -1 );
  }
*/
  else{
    cout << "[ExampleRun::executeEventFromParameter] Wrong syst" << endl;
    exit(EXIT_FAILURE);
  }


//  vector<Jet> jets = SelectJets(this_AllJets, param.Jet_ID, 20., 2.5); 
  vector<Jet> jets = SelectJets(this_AllJets, param.Jet_ID, 15., 2.0); 

  vector<Muon> muons = SelectMuons(this_AllMuons, param.Muon_Tight_ID, 20, 2.4);
  vector<Electron> electrons = SelectElectrons(this_AllElectrons, param.Electron_Loose_ID, ElTriggerSafePtCut, 2.5);
  vector<Muon> veto_muons = SelectMuons(this_AllMuons, param.Muon_Tight_ID, 15., 2.4); 
  vector<Electron> veto_electrons = SelectElectrons(this_AllElectrons, param.Electron_Loose_ID, 15., 2.5);
  FillHist(param.MuName+"/nMuon_"+param.Name, muons.size(), 1., 10, 0., 11);
  jets = JetsVetoLeptonInside(jets,veto_electrons,veto_muons,0.4);


  std::sort(jets.begin(), jets.end(), PtComparing);
  if(jets.size() != 1) return;
//  if(jets.size() != 2 or jets.size() != 1) return;
//  int njet = jets.size();
  double LeadBTagging_Score = jets.at(0).GetTaggerResult(JetTagging::DeepCSV);
  double BtagCutValue = mcCorr->GetJetTaggingCutValue( JetTagging::DeepCSV, JetTagging::Medium);
  if(LeadBTagging_Score < BtagCutValue){
    FillHist(param.MuName+"/FailBTagging_"+param.Name, 0, 1., 1, 0, 1);
    return;
  }

  vector<Jet> leadjet;
  leadjet.push_back(jets.at(0)); 
  if(jets.at(0).Pt()<20) return;
//  double btagWeight = mcCorr->GetBTaggingReweight_1d(leadjet, jtps.at(0), "central");
//  double btagWeight = mcCorr->GetBTaggingReweight_1d(jets, jtps.at(0), "central");
  double btagWeight = mcCorr->GetBTaggingReweight_1a(leadjet, jtps.at(0));
//  double btagWeight = mcCorr->GetBTaggingReweight_1a(jets, jtps.at(0));
//  double btagWeight = 1.;
//  double DY_PT_Corr = -999.;
  double weight = 1.;
  weight_pujet_veto = -999.;
  FillHist(param.MuName+"/BTagWeight_"+param.Name, btagWeight, 1., 40, 0, 5);
  if(!IsDATA){    
    FillHist(param.MuName+"/MCWeight_"+param.Name, MCweight(), 1., 40, 0, 5);
    weight *= MCweight();

    weight *= ev.GetTriggerLumi("Full");
    FillHist(param.MuName+"/TrigWeight_"+param.Name, ev.GetTriggerLumi("Full"), 1., 100, 0, 1000);

    weight_Prefire = GetPrefireWeight(0); 
    weight *= weight_Prefire;
    FillHist(param.MuName+"/PrefireWeight_"+param.Name, weight_Prefire, 1., 40, 0, 5);

    weight *= btagWeight;
    FillHist(param.MuName+"/Btagweight_"+param.Name, btagWeight, 1., 40, 0, 5);

    weight *= mcCorr->GetPileUpWeight(nPileUp, 0);
    FillHist(param.MuName+"/Pileupweight_"+param.Name, mcCorr->GetPileUpWeight(nPileUp, 0), 1., 40, 0, 5);
    if(RunSyst){
      weight_pileup_down = mcCorr->GetPileUpWeight(nPileUp, -1);
      weight_pileup_up = mcCorr->GetPileUpWeight(nPileUp, +1);
      weight_prefire_down = GetPrefireWeight(-1);
      weight_prefire_up = GetPrefireWeight(+1);
//      weight_pu_veto_down = mcCorr->PileupJetVeto_Reweight(jets, param.PUJet_Veto_ID, -1);
//      weight_pu_veto_up = mcCorr->PileupJetVeto_Reweight(jets, param.PUJet_Veto_ID, +1);
    }
//    AllGens = GetGens();
//    DY_PT_Corr = mcCorr->GetOfficialDYReweight(AllGens,0);
//    weight *= DY_PT_Corr;

//    weight_pujet_veto = mcCorr->PileupJetVeto_Reweight(jets, param.PUJet_Veto_ID, 0);
//    weight *= weight_pujet_veto;

  }
  std::sort(muons.begin(), muons.end(), PtComparing);
    
  if(muons.size() != 2) return;
  if(veto_electrons.size() != 0) return;
//  if(muons_veto.size() != 2) return;
//  if(electrons_veto.size() != 0) return;
  FillHist(param.MuName+"/TwoMuon_"+param.Name, 0., 1., 1, 0., 1.);
  if(muons.at(0).Charge() == muons.at(1).Charge()) return;
  FillHist(param.MuName+"/OppositeCharge_"+param.Name, 0., 1., 1, 0., 1.);
//  if(muons.at(0).Pt() <= 25) return;
//  FillHist(param.MuName+"/pT_Threshold_"+param.Name, 0., 1., 1, 0., 1.);
  Particle Z_cand = muons.at(0) + muons.at(1);
//  double BJetNNCorr = 1.0;          //To not apply BJetRegression
//  BJetNNCorr = jets.at(0).BJetNNCorrection();
//  jets.at(0) *= BJetNNCorr;
//  if(Z_cand.Pt() < 50) {
//    return;
//  }
  FillHist(param.MuName+"/Z_pT_Cut_"+param.Name, 0., 1., 1, 0., 1.);
  if(Z_cand.M() >= 111 || Z_cand.M() <= 71) return;


  if(!IsDATA){  
      //double this_triggersf = 1.;
    double this_triggersf = mcCorr->MuonTrigger_SF("POGTight", param.Muon_Trigger_SF_Key , muons, 0);
    if(RunSyst){
        weight_Mu_trig_down = mcCorr->MuonTrigger_SF("POGTight", param.Muon_Trigger_SF_Key , muons, -1);   
        weight_Mu_trig_up = mcCorr->MuonTrigger_SF("POGTight", param.Muon_Trigger_SF_Key , muons, +1);
        weight_Mu_ID_down = 1.0;
        weight_Mu_ID_up = 1.0;
        weight_Mu_ISO_down = 1.0;
        weight_Mu_ISO_up = 1.0;
    }
    weight *= this_triggersf;
    for(unsigned int i=0; i<muons.size(); i++){

        //double this_idsf = 1.;
      double this_idsf  = mcCorr->MuonID_SF (param.Muon_ID_SF_Key,  muons.at(i).Eta(), muons.at(i).MiniAODPt());

        //==== If you have iso SF, do below. Here we don't.
        //double this_isosf = 1.;
      double this_isosf = mcCorr->MuonISO_SF(param.Muon_ISO_SF_Key, muons.at(i).Eta(), muons.at(i).MiniAODPt());
      weight *= this_idsf*this_isosf;     
      if(RunSyst){
        weight_Mu_ID_down *= mcCorr->MuonID_SF (param.Muon_ID_SF_Key,  muons.at(i).Eta(), muons.at(i).MiniAODPt(),-1);
        weight_Mu_ID_up *= mcCorr->MuonID_SF (param.Muon_ID_SF_Key,  muons.at(i).Eta(), muons.at(i).MiniAODPt(),+1);
        weight_Mu_ISO_down *= mcCorr->MuonISO_SF(param.Muon_ISO_SF_Key, muons.at(i).Eta(), muons.at(i).MiniAODPt(),-1);
        weight_Mu_ISO_up  *= mcCorr->MuonISO_SF(param.Muon_ISO_SF_Key, muons.at(i).Eta(), muons.at(i).MiniAODPt(), +1);
      }
    }
  }


  if(abs(jets.at(0).DeltaPhi(Z_cand)) > 2.8) {
    FillHist(param.MuName+"/Z_leadjet_dphi_Cut_"+param.Name, 0., 1., 1, 0., 1.);
  } else return;








  Particle rest = Z_cand;
  float rest_PT = rest.Pt();

  if(!IsDATA){  
    double Gen_Jet_dR = 999;
    for(unsigned int i=0; i<gens.size(); i++){
      if  (gens.at(i).PID() == 23 and gens.at(i).isLastCopy()){
        FillHist(param.MuName+"/GenZ_pT_"+param.Name, gens.at(i).Pt(), weight, 50, 0., 500.);
      }
      if(jets.at(0).DeltaR(gens.at(i)) < 0.4 and jets.at(0).DeltaR(gens.at(i)) < Gen_Jet_dR){
        Gen_Jet_dR = jets.at(0).DeltaR(gens.at(i));
        Gen_b = gens.at(i);
      }
    }
  }
  FillHist(param.MuName+"/Z_pT_"+param.Name, Z_cand.Pt(), weight, 50, 0., 500);
  FillHist(param.MuName+"/Z_leadjet_dphi_Val_"+param.Name, abs(jets.at(0).DeltaPhi(Z_cand)), weight, 30, 0., 3.2);
  

  for(unsigned int pt_ind=0; pt_ind<7; pt_ind++){
    if(pt_ind<=3){
      if(jets.at(0).Pt()<(40+(pt_ind*20)) and jets.at(0).Pt()>=(20+(pt_ind*10))){
        FillHist(param.MuName+"/pTlead_over_rest_alpha_"+pt_ind+"_"+param.MuName, jets.at(0).Pt()/rest_PT, weight, 25, 0., 2.);
        FillHist(param.MuName+"/Genb_Jetb_"+pt_ind+"_"+param.MuName, jets.at(0).Pt()/Gen_b.Pt(), weight, 25, 0., 2.);
        break;
      }
    }
    if(pt_ind>3 and pt_ind <=5){
      if(jets.at(0).Pt()<((pt_ind*50)-50) and jets.at(0).Pt()>=((pt_ind*50)-100)){
        FillHist(param.MuName+"/pTlead_over_rest_alpha_"+pt_ind+"_"+param.MuName, jets.at(0).Pt()/rest_PT, weight, 25, 0., 2.);
        FillHist(param.MuName+"/Genb_Jetb_"+pt_ind+"_"+param.MuName, jets.at(0).Pt()/Gen_b.Pt(), weight, 25, 0., 2.);
        break;
      }
    }
    if(pt_ind>5){
      if(jets.at(0).Pt()<((pt_ind*200)-800) and jets.at(0).Pt()>=((pt_ind*200)-1000)){
        FillHist(param.MuName+"/pTlead_over_rest_alpha_"+pt_ind+"_"+param.MuName, jets.at(0).Pt()/rest_PT, weight, 25, 0., 2.);
        FillHist(param.MuName+"/Genb_Jetb_"+pt_ind+"_"+param.MuName, jets.at(0).Pt()/Gen_b.Pt(), weight, 25, 0., 2.);
        break;
      }
    }
  }
  FillHist(param.MuName+"/leadjet_pt_"+param.Name, jets.at(0).Pt(),weight, 50, 0, 500);
  FillHist(param.MuName+"/leadjet_pt_frac_"+param.Name, jets.at(0).Pt()/Z_cand.Pt(), weight, 20, 0, 1);
  FillHist(param.MuName+"/LeadJet_BTagging_Score_"+param.Name, LeadBTagging_Score, weight, 40, 0, 1);
  FillHist(param.MuName+"/ZCand_Mass_"+param.MuName, Z_cand.M(), weight, 40, 71., 111.);
  FillHist(param.MuName+"/pTlead_over_rest_"+param.MuName, jets.at(0).Pt()/rest.Pt(), weight, 25, 0., 2.);
  



//    weight *= weight_pujet_veto;
}


Vcb_BJetRegression_Single_Mu::Vcb_BJetRegression_Single_Mu(){

}

Vcb_BJetRegression_Single_Mu::~Vcb_BJetRegression_Single_Mu(){

}

