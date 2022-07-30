#include "HNL_SignalStudies.h"

void HNL_SignalStudies::initializeAnalyzer(){

  std::vector<JetTagging::Parameters> jtps;
  //  jtps.push_back( JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Loose, JetTagging::incl, JetTagging::comb) );
  //jtps.push_back( JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets) );
  //jtps.push_back( JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Tight, JetTagging::incl, JetTagging::comb) );

  jtps.push_back( JetTagging::Parameters(JetTagging::DeepCSV, JetTagging::Loose, JetTagging::incl, JetTagging::comb) );
  jtps.push_back( JetTagging::Parameters(JetTagging::DeepCSV, JetTagging::Medium, JetTagging::incl, JetTagging::comb) );
  jtps.push_back( JetTagging::Parameters(JetTagging::DeepCSV, JetTagging::Tight, JetTagging::incl, JetTagging::comb) );


  //--- Method 1d using JetTagging::iterativefit needs csv file changing in histmap to run
  // jtps.push_back( JetTagging::Parameters(JetTagging::DeepCSV, JetTagging::Medium, JetTagging::iterativefit, JetTagging::iterativefit) );
  mcCorr->SetJetTaggingParameters(jtps);

  //====== reduce branches to speed up processing                                                                                                                                      
  if(fChain->GetListOfFiles()->GetEntries()){
    TString filename=fChain->GetListOfFiles()->At(0)->GetTitle();
    if(filename.Contains("Run2UltraLegacy_v2")) IsUL=true;
    else IsUL=false;
  }else{
    cout<<"[AFBAnalyzer::initializeAnalyzer] no input file"<<endl;
    exit(EXIT_FAILURE);
  }


  

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


  AnalyzerParameter param  ;
  param.Clear();

  param.syst_ = AnalyzerParameter::Central;
  param.Name  = "SignalStudy";

  param.MCCorrrectionIgnoreNoHist = false;

  param.Jet_ID                     = "tight";
  param.FatJet_ID                  = "tight";
  param.BJet_Method                = "2a";




  //************************************************/// 
  // setup vector of all objects
  //************************************************///
  AllMuons     = GetAllMuons();
  AllElectrons = GetAllElectrons();
  AllTaus      = GetAllTaus();
  AllJets      = GetAllJets();
  AllFatJets   = puppiCorr->Correct(GetAllFatJets());

  vector<Electron> this_AllElectrons1 = AllElectrons;
  vector<Muon>     this_AllMuons1     = AllMuons;

  std::vector<Electron>   my_electrons = SelectElectrons(this_AllElectrons1, "NoCut", 10., 2.5);
  std::sort(my_electrons.begin(),       my_electrons.end(),        PtComparing);

  std::vector<Muon>   my_muons = SelectMuons(this_AllMuons1, "NoCut", 10., 2.5);
  std::sort(my_muons.begin(),       my_muons.end(),        PtComparing);
  
  double weight(1.);

  Event ev = GetEvent();

  //=== Apply MC weight
  if(!IsDATA){
    double this_mc_weight = ev.GetTriggerLumi("Full") * MCweight(true, true) * GetKFactor();
    weight     *=  this_mc_weight;
    FillWeightHist("MCWeight_" ,MCweight(true, true));
    FillWeightHist("MCFullWeight_" , this_mc_weight);
    
  }

  
  // HL ID
  std::vector<Electron>   myelectrons = GetElectrons( "HNTightV2", 10., 2.5);
  std::vector<Muon>       mymuons     = GetMuons    ( "HNTightV2", 5., 2.4);

  // EXO17028 ID
  
  std::vector<Electron>   myelectrons_js = GetElectrons("HNTight_17028", 10., 2.5);  
  std::vector<Muon>       mymuons_js     = GetMuons    ("HNTight_17028", 5., 2.4);


  std::vector<Electron>   vetoelectrons = GetElectrons("HNVeto2016", 10., 2.5); 
  std::vector<Muon>       vetomuons     = GetMuons    ("HNVeto2016", 5., 2.4);

  std::vector<Tau>        mytaus      = GetTaus("HNVeto",20., 2.3); 
  std::vector<Tau>        alltaus     = GetTaus("NoCut", 20., 2.3);
  

  std::vector<FatJet>   fatjets_tmp  = GetFatJets( param.FatJet_ID, 200, 5.);
  std::vector<Jet>      jets_tmp     = GetJets   ( param.Jet_ID,    15., 5.);

  std::vector<FatJet> fatjets                  = GetAK8Jets(fatjets_tmp, 200., 2.7, true,  1., true, -999, true, 40., 130., vetoelectrons, vetomuons);
  std::vector<Jet> jets                        = GetAK4Jets(jets_tmp,     20., 2.7, true,  0.4,0.8,"loose",        vetoelectrons, vetomuons,fatjets);
  std::vector<Jet> vbf_jets                    = GetAK4Jets(jets_tmp,     30., 4.7, true,  0.4,0.8,"loose",   vetoelectrons, vetomuons,fatjets);

  
  int njets = vbf_jets.size() + fatjets.size();

  if ( process.Contains("Mu+Mu+") or   process.Contains("Mu-Mu-") ){
    
    param.Name = "MuonChannelSignals";
    FillEventCutflow(sigmm,weight, "SSNoCut", param.Name);
    
    if(SameCharge(mymuons) && vetomuons.size()==2 && vetoelectrons.size()==0 ) {
      
      FillEventCutflow(sigmm,weight, "SSMM",  param.Name);
     
      if(GetLLMass(mymuons) > 10.)            FillEventCutflow(sigmm,weight, "SSMM_LLMass",  param.Name);
      if(njets > 0 && GetLLMass(mymuons) > 10.)            FillEventCutflow(sigmm,weight, "SSMM_Jet",  param.Name);

      TString channel_string= GetChannelString(MuMu, SS);
      
      if(GetLLMass(mymuons) > 10. && mytaus.size()==0 ) {
	
	if(njets > 0) FillEventCutflow(sigmm,weight, "SSMM_Jet_vTau",  param.Name);
      
	if(fatjets.size() > 0){
	  if(RunSignalRegionAK8( MuMu, SS, myelectrons, vetoelectrons, mymuons, vetomuons, jets, fatjets, "Medium", ev, param,  channel_string, weight ))
	    FillEventCutflow(sigmm,weight, "SSMM_SR1",  param.Name);
	}
	else{
	  
	  if(PassVBFInitial(vbf_jets)) {
	    
	    FillEventCutflow(sigmm,weight, "SSMM_SR2a",  param.Name);
	    
	    if(PassVBFInitial(vbf_jets)&&RunSignalRegionWW( MuMu,SS, myelectrons, vetoelectrons, mymuons, vetomuons,  vbf_jets, fatjets, "Medium", ev, param,  channel_string, weight ))             FillEventCutflow(sigmm,weight, "SSMM_SR2b",  param.Name);

	  
	  }
	  else{
	    
	    if(RunSignalRegionAK4(MuMu, SS, myelectrons, vetoelectrons, mymuons, vetomuons, jets, fatjets, "Medium", ev, param,  channel_string, weight ))             FillEventCutflow(sigmm,weight, "SSMM_SR3",  param.Name);
	    
   
	    else if(jets.size() < 2 && mymuons[1].Pt() > 100)             FillEventCutflow(sigmm,weight, "SSMM_SR4",  param.Name);

	    else             FillEventCutflow(sigmm,weight, "SSMM_Fail",  param.Name);

	  }
	}
      }
    }
  }
  return;

  if(SameCharge(myelectrons))  FillHist (process + "/SSEE", 1, weight, 2, 0., 2.,"");
  if(SameCharge(myelectrons,mymuons))  FillHist (process + "/SSEM", 1, weight, 2, 0., 2.,"");



  

  if(SameCharge(mymuons,-1))   FillHist (process + "/SSmm_MM", 1, weight, 2, 0., 2.,"");
  if(SameCharge(myelectrons,-1))  FillHist (process + "/SSmm_EE", 1, weight, 2, 0., 2.,"");
  if(SameCharge(myelectrons,mymuons,-1))  FillHist (process + "/SSmm_EM", 1, weight, 2, 0., 2.,"");

  if(SameCharge(mymuons,1))   FillHist (process + "/SSpp_MM", 1, weight, 2, 0., 2.,"");
  if(SameCharge(myelectrons,1))  FillHist (process + "/SSpp_EE", 1, weight, 2, 0., 2.,"");
  if(SameCharge(myelectrons,mymuons,1))  FillHist (process + "/SSpp_EM", 1, weight, 2, 0., 2.,"");
  



  return;

  if (SameCharge(mymuons) || SameCharge(myelectrons)){
    FillHist("Taus/NEv",0,weight, 1., 0., 1.,"");
    int ntau = 0;
    vector<int> ntaus;

    for(unsigned int ij = 0 ; ij < 7; ij++){
      for(unsigned int ie = 0 ; ie < 7; ie++){
	for(unsigned int im = 0 ; im < 4; im++){
	  ntaus.push_back(0);
	}
      }
    }

    int itau(0);
    for(auto i : alltaus){
      itau++;

      if(i.DecayMode() == 0 || i.DecayMode() ==1 || i.DecayMode() ==10 || i.DecayMode() ==11){
	if(i.DecayModeNewDM()){
	    
	  if(i.passVVLIDvJet()) FillHist("Taus/IDcheckJet",0,weight, 10., 0., 10.,"");
	  if(i.passVLIDvJet()) FillHist("Taus/IDcheckJet",1,weight, 10., 0., 10.,"");
	  if(i.passLIDvJet()) FillHist("Taus/IDcheckJet",2,weight, 10., 0., 10.,"");
	  if(i.passMIDvJet()) FillHist("Taus/IDcheckJet",3,weight, 10., 0., 10.,"");
	  if(i.passTIDvJet()) FillHist("Taus/IDcheckJet",4,weight, 10., 0., 10.,"");
	  if(i.passVTIDvJet()) FillHist("Taus/IDcheckJet",5,weight, 10., 0., 10.,"");
	  if(i.passVVTIDvJet()) FillHist("Taus/IDcheckJet",6,weight, 10., 0., 10.,"");
	    
	  if(i.passVVLIDvEl()) FillHist("Taus/IDcheckEl",0,weight, 10., 0., 10.,"");
	  if(i.passVLIDvEl()) FillHist("Taus/IDcheckEl",1,weight, 10., 0., 10.,"");
	  if(i.passLIDvEl()) FillHist("Taus/IDcheckEl",2,weight, 10., 0., 10.,"");
	  if(i.passMIDvEl()) FillHist("Taus/IDcheckEl",3,weight, 10., 0., 10.,"");
	  if(i.passTIDvEl()) FillHist("Taus/IDcheckEl",4,weight, 10., 0., 10.,"");
	  if(i.passVTIDvEl()) FillHist("Taus/IDcheckEl",5,weight, 10., 0., 10.,"");
	  if(i.passVVTIDvEl()) FillHist("Taus/IDcheckEl",6,weight, 10., 0., 10.,"");
	    
	  if(i.passVVLIDvMu()) FillHist("Taus/IDcheckMu",0,weight, 10., 0., 10.,"");
	  if(i.passVLIDvMu()) FillHist("Taus/IDcheckMu",1,weight, 10., 0., 10.,"");
	  if(i.passLIDvMu()) FillHist("Taus/IDcheckMu",2,weight, 10., 0., 10.,"");
	  if(i.passMIDvMu()) FillHist("Taus/IDcheckMu",3,weight, 10., 0., 10.,"");
	  if(i.passTIDvMu()) FillHist("Taus/IDcheckMu",4,weight, 10., 0., 10.,"");
	  if(i.passVTIDvMu()) FillHist("Taus/IDcheckMu",5,weight, 10., 0., 10.,"");
	  if(i.passVVTIDvMu()) FillHist("Taus/IDcheckMu",6,weight, 10., 0., 10.,"");
	    
	  vector<bool> vj = {i.passVVLIDvJet(),i.passVLIDvJet(),i.passLIDvJet(),i.passMIDvJet(), i.passTIDvJet(), i.passVTIDvJet(), i.passVVTIDvJet()};
	  vector<bool> ve = {i.passVVLIDvEl(),i.passVLIDvEl(),i.passLIDvEl(),i.passMIDvEl(), i.passTIDvEl(), i.passVTIDvEl(), i.passVVTIDvEl()};
	  vector<bool> vm = {i.passVLIDvMu(),i.passLIDvMu(),i.passMIDvMu(),i.passTIDvMu()};
	    
	  int j(0);
	  for(unsigned int ij = 0 ; ij < vj.size(); ij++){
	    for(unsigned int ie = 0 ; ie < ve.size(); ie++){
	      for(unsigned int im = 0 ; im < vm.size(); im++){
		if(vj[ij] && ve[ie] && vm[im]) ntaus[j] = ntaus[j] +1;
		j++;
	      }
	    }
	  }
	  if(i.passVLIDvJet() && i.passMIDvEl()&& i.passMIDvMu()) ntau++;
	}
      }
    }
    for(unsigned int j = 0 ; j < ntaus.size(); j ++){
      if(ntaus[j]==0)FillHist("Taus/NTaus",j, weight, ntaus.size(), 0., ntaus.size(),"");
    }

    FillHist("Taus/NTau",ntau,weight, 10., 0., 10.,"");
  }




  return;
  
}
void HNL_SignalStudies::FillAllMuonPlots(TString label , TString cut,  std::vector<Muon> muons, float w){

  for(unsigned int i=0; i <  muons.size(); i++){

    TString mu_lab="muon1";
    if(i==1) mu_lab="muon2";
    if(i==2) mu_lab="muon3";

    TString eta_label="";
    if(fabs(muons.at(i).Eta()) < 1.5) eta_label = "_barrel";
    else eta_label = "_endcap";

    
    FillAllMuonPlots(mu_lab+label, cut, muons.at(i), w);
    FillAllMuonPlots(mu_lab+label+eta_label, cut, muons.at(i), w);

    FillAllMuonPlots("muon"+label, cut, muons.at(i), w);
    FillAllMuonPlots("muon"+label+eta_label, cut, muons.at(i), w);

    if(muons.at(i).MVA() < 0.5)     FillAllMuonPlots("muon"+label+eta_label+"_lowmva", cut, muons.at(i), w);
    else FillAllMuonPlots("muon"+label+eta_label+"_highmva", cut, muons.at(i), w);


  }

  return;
}
void HNL_SignalStudies::FillAllMuonPlots(TString label , TString cut,  Muon mu, float w){
  
  vector<Jet> JetAllColl = GetJets("NoID", 10., 3.0);
  int IdxMatchJet=-1;
  double mindR(999.);

  double PtRelv0(0.);
  double PtRelv1(0.);
  double PtRatio(1.);
  double jet_disc(-1);
  for(unsigned int ij=0; ij<JetAllColl.size(); ij++){
    float dR=mu.DeltaR(JetAllColl.at(ij));
    if(dR>0.4) continue;
    if(dR<mindR){ mindR=dR; IdxMatchJet=ij; }
  }
  if(IdxMatchJet!=-1){
    PtRatio = mu.Pt()/JetAllColl.at(IdxMatchJet).Pt();
    TLorentzVector JetNoLep(JetAllColl.at(IdxMatchJet));
    JetNoLep -= mu;
    PtRelv0 = mu.Perp(JetAllColl.at(IdxMatchJet).Vect());
    PtRelv1 = mu.Perp(JetNoLep.Vect());
    jet_disc = JetAllColl.at(IdxMatchJet).GetTaggerResult(JetTagging::DeepCSV);

  }

  FillHist( cut+ "/ID_POGLoose_"+label, mu.PassID("POGLoose"), w, 2, 0., 2.);
  FillHist( cut+ "/ID_POGMedium_"+label, mu.PassID("POGMedium"), w, 2, 0., 2.);
  FillHist( cut+ "/ID_POGTight_"+label, mu.PassID("POGTight"), w, 2, 0., 2.);
  FillHist( cut+ "/ID_POGHighPt_"+label, mu.PassID("POGHighPt"), w, 2, 0., 2.);

  FillHist( cut+ "/ptrel_0_"+label , PtRelv0 , w, 200, 0., 20., "");
  FillHist( cut+ "/ptrel_1_"+label , PtRelv1 , w, 200, 0., 20., "");
  FillHist( cut+ "/ptrel_def_"+label , mu.lep_jet_ptrel() , w, 200, 0., 20., "");
  FillHist( cut+ "/ptratio_def_"+label , mu.lep_jet_ptratio() , w, 100, 0., 2., "");
  FillHist( cut+ "/ptratio_"+label , PtRatio , w, 100, 0., 2., "");
  FillHist( cut+ "/jet_disc_"+label , jet_disc , w, 400, -2., 2., "");

  double new_iso = mu.RelIso() / (PtRatio * PtRelv1);
  double new_miso = mu.MiniRelIso() / (PtRatio * PtRelv1);
  FillHist( cut+ "/new_iso_"+label , new_iso , fabs(w), 100000, 0., 1., "");
  FillHist( cut+ "/new_miso_"+label , new_miso , fabs(w), 100000, 0., 1., "");
  FillHist( cut+ "/ptratio_rel", PtRelv1, PtRatio, fabs(w), 200, 0., 20., 100, 0., 2.);

  if(mu.MiniRelIso() < 0.2)   FillHist( cut+ "/ptratio_rel_miso02", PtRelv1, PtRatio, fabs(w), 200, 0., 20., 100, 0., 2.);
  if(mu.MiniRelIso() < 0.1)   FillHist( cut+ "/ptratio_rel_miso01", PtRelv1, PtRatio, fabs(w), 200, 0., 20., 100, 0., 2.);
  if(mu.MiniRelIso() < 0.08)   FillHist( cut+ "/ptratio_rel_miso008", PtRelv1, PtRatio, fabs(w), 200, 0., 20., 100, 0., 2.);
  if(mu.MiniRelIso() < 0.05)   FillHist( cut+ "/ptratio_rel_miso005", PtRelv1, PtRatio, fabs(w), 200, 0., 20., 100, 0., 2.);
  if(mu.RelIso() < 0.2)   FillHist( cut+ "/ptratio_rel_iso02", PtRelv1, PtRatio, fabs(w), 200, 0., 20., 100, 0., 2.);
  if(mu.RelIso() < 0.1)   FillHist( cut+ "/ptratio_rel_iso01", PtRelv1, PtRatio, fabs(w), 200, 0., 20., 100, 0., 2.);
  if(mu.RelIso() < 0.08)   FillHist( cut+ "/ptratio_rel_iso008", PtRelv1, PtRatio, fabs(w), 200, 0., 20., 100, 0., 2.);
  if(mu.RelIso() < 0.05)   FillHist( cut+ "/ptratio_rel_iso005", PtRelv1, PtRatio, fabs(w), 200, 0., 20., 100, 0., 2.);

  FillHist( cut+ "/pt_mu_"+label , mu.Pt() , w, 500, 0., 1000., "muon p_{T} GeV");
  FillHist( cut+ "/dxy_mu_"+label , mu.dXY() , w, 500, -0.2, 0.2, "dXY");
  FillHist( cut+ "/dz_mu_"+label , mu.dZ() , w, 500, -0.5, 0.5, "dZ");
  FillHist( cut+ "/reliso_mu_"+label , mu.RelIso() , w, 50, 0., 1., "R_{ISO} GeV");
  FillHist( cut+ "/eta_"+label  , mu.Eta() , w, 60, -3., 3.,"muon #eta");
  FillHist( cut+ "/IP3D_"+label  , mu.IP3D()/mu.IP3Derr(), w, 400, -20., 20., "IP3D");

  FillHist( cut+ "/mva_"+label  , mu.MVA(), w, 400, -1., 1., "MVA");
  FillHist( cut+ "/pt_mva_"+label , mu.Pt() , mu.MVA(), fabs(w), 200, 0., 1000., 400, -1., 1.);

  FillHist( cut+ "/chi2_"+label  , mu.Chi2(), w, 1000,0., 100., "chi2");
  FillHist( cut+ "/validhits_"+label  , mu.ValidMuonHits(), w, 100,0., 100., "");
  FillHist( cut+ "/matched_stations_"+label  , mu.MatchedStations(), w, 10,0., 10., "");
  FillHist( cut+ "/pixel_hits_"+label  , mu.PixelHits(), w, 10,0., 10., "");
  FillHist( cut+ "/minireliso_mu_"+label , mu.MiniRelIso() , w, 50, 0., 1., "R_{ISO} GeV");
  FillHist( cut+ "/tracker_layers_"+label  , mu.TrackerLayers(), w, 50,0., 50., "");
  
  return; 
}

void HNL_SignalStudies::FillAllElectronPlots(TString label , TString cut,  std::vector<Electron> els, float w){

  FillHist( cut+ "/nelectrons"+label , size(els) , w, 5, 0., 5., "n_{el}");

  for(unsigned int i=0; i < els.size(); i++){
    TString el_lab="el1";
    if(i==1) el_lab="el2";
    if(i==2) el_lab="el3";
    if(!els[i].IsGsfCtfScPixChargeConsistent()){
      FillHist( cut+ "/pt_vetoel_cc_"+el_lab+label , els.at(i).Pt() , w, 500, 0., 1000., "el p_{T} GeV");
      
    }

    //FillAllElectronPlots(el_label+label, cut, el, w);

  }
  return;

}

HNL_SignalStudies::HNL_SignalStudies(){


}
 
HNL_SignalStudies::~HNL_SignalStudies(){

}

bool HNL_SignalStudies::PassVBF(vector<Jet>  jets,std::vector<Lepton *> leps){
  
  if(leps.size() != 2) return false;
  double ll_dphi = fabs(TVector2::Phi_mpi_pi( ( (*leps[0]).Phi() - (*leps[1]).Phi() )) );
  if(ll_dphi < 2.) return false;
  if( ( (*leps[0]) + (*leps[1]) ).M() < 20.) return false;
  if(jets.size() < 2) return false;
  
  double maxDiJetDeta=0.;
  int ijet1(-1), ijet2(-1);
  for(unsigned int ij = 0; ij < jets.size()-1; ij++){
    for(unsigned int ij2 = ij+1; ij2 < jets.size(); ij2++){
      
      double deta = fabs(jets[ij].Eta() - jets[ij2].Eta());
      if(deta > maxDiJetDeta) {
	maxDiJetDeta=deta;
	ijet1=ij;
	ijet2=ij2;
      }
    }
  }

  if(jets[1].Pt() < 30) return false;
  if(maxDiJetDeta < 2.5) return false;
  Particle JJ = jets[ijet1] + jets[ijet2];
  if(JJ.M() < 750.) return false;
  double Av_JetEta= 0.5*(jets[ijet1].Eta()+ jets[ijet2].Eta());
  double zeppenfeld = TMath::Max((*leps[0]).Eta()  - Av_JetEta , (*leps[1]).Eta()  - Av_JetEta ) /maxDiJetDeta;
  
  if(zeppenfeld > 0.75) return false;
  
  return true;
}

bool HNL_SignalStudies::PassVBFv2(vector<Jet>  jets,std::vector<Lepton *> leps){

  if(leps.size() != 2) return false;
  double ll_dphi = fabs(TVector2::Phi_mpi_pi( ( (*leps[0]).Phi() - (*leps[1]).Phi() ))) ;
  if(ll_dphi < 2.) return false;
  if( ( (*leps[0]) + (*leps[1]) ).M() < 20.) return false;
  if(jets.size() < 2) return false;

  int ijet1=0;
  int ijet2=1;

  double DiJetDeta = fabs(jets[ijet1].Eta() - jets[ijet2].Eta());
  if(DiJetDeta < 2.5) return false;

  if(jets[1].Pt() < 30)  return false;
  Particle JJ = jets[ijet1] + jets[ijet2];
  if(JJ.M() < 750.) return false;
  double Av_JetEta= 0.5*(jets[ijet1].Eta()+ jets[ijet2].Eta());
  double zeppenfeld = TMath::Max((*leps[0]).Eta()  - Av_JetEta , (*leps[1]).Eta()  - Av_JetEta ) /DiJetDeta;

  if(zeppenfeld > 0.75) return false;

  return true;
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
