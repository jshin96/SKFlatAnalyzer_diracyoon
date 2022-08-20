#include "HNL_FakeRate.h"

void HNL_FakeRate::initializeAnalyzer(){

  HNL_LeptonCore::initializeAnalyzer();


}

void HNL_FakeRate::executeEvent(){

  Event ev = GetEvent();


  if(!IsDATA){
    //==== nPileUp starts from 0
    N_VTX          = nPileUp;
    weight_PU      = GetPileUpWeight(N_VTX,0);
  }
  
  AnalyzerParameter param;

  //************************************************///
  // setup list of IDs
  //************************************************///
  vector<pair<TString, TString> > MuIDs; vector<pair<TString, TString> > ELIDs;
  vector<TString> channel;
  vector<TString>  mu_loose_id;
  vector<TString>  el_loose_id;
  vector<TString> paramnames;
  
  TString           era="2016";
  if(DataYear==2017)era="2017";
  if(DataYear==2018)era="2018";
  
  // Loose ID has no loose IP
  // HNTight_17028 :  PassMVA(0.9, 0.825, 0.5)) && fabs(dXY())<0.01 && fabs(dZ())<0.04 && fabs(IP3D()/IP3Derr())<4. RelIso()<0.08
  //                  PassConversionVeto() IsGsfCtfScPixChargeConsistent Pass_TriggerEmulation
  // HNLoose_17028 : Pass_HNLoose2016(0.6, 0.2, 0.1, 10.) && MVA(-0.1, 0.1, -0.1) PassConversionVeto() IsGsfCtfScPixChargeConsistent Pass_TriggerEmulation
  ELIDs.push_back(make_pair("HNTight_17028",   "HNVeto2016"));   el_loose_id.push_back("HNLoose_17028"); 
  // passIDHN(3,0.01, 0.01, 0.04,0.04, 4.,4., 0.1, 0.06, -999., -999.)&&PassMVA(0.65,0.81, 0.89)
  // passIDHN(3,0.01, 0.01, 0.04,0.04, 4.,4., 0.6, 0.6, -999., -999.)&&PassMVA(-0.1,0.1, -0.1))  ? 1 : 0)
  ELIDs.push_back(make_pair("HNTightV2",       "HNVeto2016"));   el_loose_id.push_back("HNLooseV4"); 
  ELIDs.push_back(make_pair("passPOGTight",   "HNVeto2016")) ;  el_loose_id.push_back("HNLoosePOG");
  ELIDs.push_back(make_pair("passPOGMedium",   "HNVeto2016")) ;  el_loose_id.push_back("HNLoosePOG");
  

  paramnames.push_back("HNTight_17028"  );
  paramnames.push_back("HNTightV2"      );
  paramnames.push_back("passPOGTight"  );
  paramnames.push_back("passPOGMedium"  );


  ELIDs.push_back(make_pair("HNTightV2", "HNVeto2016"));        el_loose_id.push_back("HNLooseV4_LooseIP");
  paramnames.push_back("HNTightV2_LIP");
  
  
  for (auto i: ELIDs) {
    channel.push_back("EE");
    MuIDs.push_back(make_pair("HNVeto2016","HNVeto2016"));
    mu_loose_id.push_back("HNLoose_17028");
  }


  // MUON IDS
  MuIDs.push_back(make_pair("POGTightWithTightIso","HNVeto2016"));       mu_loose_id.push_back("HNLoosePOG");
  MuIDs.push_back(make_pair("HNTight_17028","HNVeto2016"));       mu_loose_id.push_back("HNLoose_17028");
  MuIDs.push_back(make_pair("HNTightV2","HNVeto2016"));       mu_loose_id.push_back("HNLooseV1");
  paramnames.push_back("POGTightWithTightIso");
  paramnames.push_back("HNTight_17028");
  paramnames.push_back("HNTightV2");

  int iel= MuIDs.size() - channel.size();
  for (int i =0; i < iel; i++){
    channel.push_back("MuMu");
    el_loose_id.push_back("HNLoose_17028");
    ELIDs.push_back(make_pair("HNVeto2016", "HNVeto2016"));
  }


  for(unsigned int it_id=0; it_id<ELIDs.size(); it_id++){
    
    //************************************************///
    // setup leptton veto/loose/tight 
    //************************************************///

    TString MuonTightID      = MuIDs[it_id].first;
    TString MuonLooseID      = mu_loose_id[it_id];
    TString MuonVetoID       = MuIDs[it_id].second;
    TString ElectronTightID  = ELIDs[it_id].first;
    TString ElectronLooseID  = el_loose_id[it_id];
    TString ElectronVetoID   = ELIDs[it_id].second;

    TString FakeRateID       = (channel[it_id] == "MuMu") ? MuonLooseID :  ElectronLooseID;
    TString Tight_ID         = (channel[it_id] == "MuMu") ? MuonTightID :  ElectronTightID;
    
    param.Clear();
  
    param.syst_ = AnalyzerParameter::Central;
    param.Name = paramnames[it_id];
    param.MCCorrrectionIgnoreNoHist = false;

   
    //==== Muon IDparam.Muon_Loose_ID
    param.Muon_Tight_ID        = MuonTightID;
    param.Muon_Loose_ID        = MuonLooseID;
    param.Muon_Veto_ID         = MuonVetoID;

    //==== Electron ID
    param.Electron_Tight_ID       = ElectronTightID;
    param.Electron_Loose_ID       = ElectronLooseID;
    param.Electron_Veto_ID        = ElectronVetoID;

    //==== Jet ID
    param.Jet_ID    = "HNTight";

    param.Name = channel[it_id] + "_"+ paramnames[it_id];
    
    //************************************************///
    // run event
    //************************************************///
    
    executeEventFromParameter(param, Tight_ID, channel[it_id]);
  } 
}

void HNL_FakeRate::executeEventFromParameter(AnalyzerParameter param, TString El_ID, TString channel){
  

  bool EE = (channel != "MuMu") ? true : false;

  //************************************************///
  // setup event level objects
  Event ev = GetEvent();

  double weight = SetupWeight(ev, param) / ev.GetTriggerLumi("Full");
  if(IsData) weight = 1;
  
  if(!PassMETFilter()) return;

  
  std::vector<Electron> loose_electrons     = GetElectrons( param,param.Electron_Loose_ID, 9.5, 2.5,false) ;
  std::vector<Muon>     loose_muons         = GetMuons    ( param,param.Muon_Loose_ID, 5, 2.4, false);
  

  std::vector<Jet> jets_tmp     = GetJets   ( param, "tight", 30., 5.);
  std::vector<Jet>      jets;
  for(unsigned int ijet =0; ijet < jets_tmp.size(); ijet++){
    bool jetok=true;
    
    for(unsigned int iel=0 ; iel < loose_electrons.size(); iel++){
      if(jets_tmp[ijet].DeltaR(loose_electrons[iel]) < 0.4) jetok = false;
    }
    for(unsigned int iel=0 ; iel < loose_muons.size(); iel++){
      if(jets_tmp[ijet].DeltaR(loose_muons[iel]) < 0.4) jetok = false;
    }
    if(jetok) jets.push_back(jets_tmp[ijet]);
  }

  if(EE)  RunE(loose_electrons,loose_muons, jets,  param, weight);

  else        RunM(loose_electrons,loose_muons,  jets, param, weight);
  
}


void HNL_FakeRate::RunM(std::vector<Electron> loose_el,  std::vector<Muon> loose_mu, std::vector<Jet> jets,   AnalyzerParameter param,  float event_weight){
  
  if(IsData){
    if(this->DataStream == "DoubleEG") return;
    if(this->DataStream == "SingleElectron") return;
    if(this->DataStream == "EGamma") return;
  }

  TString label    = param.Name;
  TString channel_s="_MuMu";
  Event ev = GetEvent();

  Particle METv = GetvMET("T1xyCorr",param);

  if(loose_mu.size() == 0) return;

  
  // remove if muon                                                                                                                          
  if(loose_el.size() > 0) return;

  double isocut = GetIsoFromID("Muon", param.Muon_Tight_ID,loose_mu[0].Eta(), loose_mu[0].Pt());
  std::vector<Lepton *> leps = MakeLeptonPointerVector(loose_mu);
  std::vector<bool> blepsT;
  for(auto ilep : loose_mu) {
    blepsT.push_back(ilep.PassID(param.Muon_Tight_ID));
  }
  GetFakeRateAndPromptRates(leps,blepsT,param,param.Name+channel_s,event_weight,isocut);

  if(loose_mu.size() != 1) return;

  float prescale_trigger = GetPrescale(leps);
  if(prescale_trigger == 0.) return;
  event_weight*=prescale_trigger;

  bool truth_match= false;
  if(!IsDATA) {
    gens = GetGens();
    if(GetLeptonType(loose_mu.at(0), gens) > 0 ) truth_match=true;
  }
  else truth_match=true;

  if(jets.size() > 0){
    if(jets.at(0).Pt() > 40.){
      FillRegionPlots("SingleLooseMuJet_"+param.Name , jets,   loose_el,loose_mu,  METv, event_weight);
      if(truth_match)       FillRegionPlots("SingleLooseMuJet_matched_"+param.Name, jets,   loose_el,  loose_mu,  METv, event_weight);
      if(blepsT[0]){
        FillRegionPlots("SingleTightMuJet_"+param.Name,  jets,  loose_el,loose_mu,  METv, event_weight);
        if(truth_match) FillRegionPlots("SingleTightMuJet_matched_"+param.Name, jets,  loose_el, loose_mu,  METv, event_weight);
      }
    }
  }

  Double_t MT=0;
  Double_t METdphi=0;
  for(unsigned int imu = 0; imu < loose_mu.size();  imu++){
    METdphi = TVector2::Phi_mpi_pi((loose_mu.at(imu).Phi()- METv.Phi()));
    MT = sqrt(2.* loose_mu.at(imu).Et()*METv.Pt() * (1 - cos( METdphi)));
  }
  if(METv.Pt()  > 30 && (60. < MT)  &&(MT < 100.) &&truth_match){
    if(jets.size() > 0 && blepsT[0]){
      if(jets[0].Pt() > 40){
        if(truth_match) FillRegionPlots("SingleTightMu_promptCR_"+param.Name, jets,  loose_el,loose_mu, METv, event_weight);
      }
    }
  }

  
  bool useevent40 = UseEvent(leps , jets, 40., METv, event_weight);
  if(useevent40){
    if (blepsT[0] && jets.size() >= 1)FillRegionPlots("TightMu40_notm_"+param.Name, jets,  loose_el,loose_mu, METv, event_weight);
    if (jets.size() >= 1)FillRegionPlots("LooseMu40_notm_"+param.Name, jets,  loose_el,loose_mu, METv, event_weight);
    
    if(truth_match){
      if (blepsT[0] && jets.size() >= 1)FillRegionPlots("TightMu40_"+param.Name , jets,  loose_el,loose_mu, METv, event_weight);
      if (jets.size() >= 1)FillRegionPlots("LooseMu40_"+param.Name, jets,  loose_el,loose_mu, METv, event_weight);
    }
    
  }
  
  return;

} /// end function                      





void HNL_FakeRate::RunE( std::vector<Electron> loose_el, std::vector<Muon> loose_mu, std::vector<Jet> jets, AnalyzerParameter param,  float event_weight){

  if(IsData){
    if(this->DataStream == "DoubleMuon") return;
    if(this->DataStream == "SingleMuon") return;
  }

  TString channel_s="_EE";
  TString label = param.Name;
  Event ev = GetEvent();

  Particle METv = GetvMET("T1xyCorr",param);
  
  if(loose_el.size() == 0) return;
 

  TString triggerslist_8="HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v";   /// -> tighter cut in lepton ID form tighter trigger emulation cut                                     
  TString triggerslist_12="HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v";
  TString triggerslist_18="HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v";
  TString triggerslist_23="HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v";
  TString triggerslist_33="HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v"; /// 

  // remove if muon 
  if(loose_mu.size() > 0) return;

  double isocut = GetIsoFromID("Electron", param.Electron_Tight_ID,loose_el[0].Eta(), loose_el[0].Pt());
 


  std::vector<Lepton *> leps = MakeLeptonPointerVector(loose_el);
  std::vector<bool> blepsT;
  for(auto ilep : loose_el) {
    blepsT.push_back(ilep.PassID(param.Electron_Tight_ID));
  }
  GetFakeRateAndPromptRates(leps,blepsT,param,param.Name+channel_s,event_weight,isocut);
 
  if(loose_el.size() != 1) return;

 
  float prescale_trigger =  GetPrescale(leps);
  if(prescale_trigger == 0.) return;
  event_weight*=prescale_trigger;


  bool truth_match= false;
  if(!IsDATA) {
    gens = GetGens();
    if(GetLeptonType(loose_el.at(0), gens) > 0 ) truth_match=true;
  }
  else truth_match=true;

  if(jets.size() > 0){
    if(jets.at(0).Pt() > 40.){
      FillRegionPlots("SingleLooseElJet_"+param.Name , jets,   loose_el,loose_mu,  METv, event_weight);
      if(truth_match)       FillRegionPlots("SingleLooseElJet_matched_"+param.Name, jets,   loose_el,  loose_mu,  METv, event_weight);
      if(blepsT[0]){
        FillRegionPlots("SingleTightElJet_"+param.Name,  jets,  loose_el,loose_mu,  METv, event_weight);
        if(truth_match) FillRegionPlots("SingleTightElJet_matched_"+param.Name, jets,  loose_el, loose_mu,  METv, event_weight);
      }
    }
  }

  Double_t MT=0;
  Double_t METdphi=0;
  for(unsigned int iel = 0; iel < loose_el.size();  iel++){
    METdphi = TVector2::Phi_mpi_pi((loose_el.at(iel).Phi()- METv.Phi()));
    MT = sqrt(2.* loose_el.at(iel).Et()*METv.Pt() * (1 - cos( METdphi)));
  }
  if(METv.Pt()  > 30 && (60. < MT)  &&(MT < 100.) &&truth_match){
    if(jets.size() > 0 && blepsT[0]){
      if(jets[0].Pt() > 40){
        if(truth_match) FillRegionPlots("SingleTightEl_promptCR_"+param.Name, jets,  loose_el,loose_mu, METv, event_weight);
      }
    }
  }


  bool useevent40 = UseEvent(leps , jets, 40., METv,event_weight);
  if(useevent40){
    if (blepsT[0] && jets.size() >= 1)FillRegionPlots("TightEl40_notm_"+param.Name, jets,  loose_el,loose_mu, METv, event_weight);
    if (jets.size() >= 1)FillRegionPlots("LooseEl40_notm_"+param.Name, jets,  loose_el,loose_mu, METv, event_weight);
    
    
    if(truth_match){
      if (blepsT[0] && jets.size() >= 1)FillRegionPlots("TightEl40_"+param.Name , jets,  loose_el,loose_mu, METv, event_weight);
      if (jets.size() >= 1)FillRegionPlots("LooseEl40_"+param.Name, jets,  loose_el,loose_mu, METv, event_weight);
    }
  }
  
  
  return;
  


} /// end function RunE


void HNL_FakeRate::GetFakeRateAndPromptRates(std::vector<Lepton *> leps,std::vector<bool> blepsT,AnalyzerParameter param, TString label, float event_weight, float isocut){
						      
  
  if (leps.size()<1) return;
  
  Event ev = GetEvent();
  Particle METv = GetvMET("T1xyCorr",param);

  std::vector<Jet>      jetColl   = GetJets(param, "tight", 30., 2.5);
  std::vector<Jet>    jetCollTight ;
  for(unsigned int ijet =0; ijet < jetColl.size(); ijet++){
    bool jetok=true;

    for(auto ilep : leps){
      if(ilep->DeltaR(jetColl[ijet]) < 0.4) jetok = false;
    }
    if(jetok) jetCollTight.push_back(jetColl[ijet]);
  }

  
  if(leps.size()==1){
    MakeFakeRatePlots("", label, param,leps,blepsT,  jetCollTight, jetColl,  event_weight, isocut, METv);
  }
  if(leps.size()==2){
    TString dilep_triggerslist = (leps[0]->LeptonFlavour() == Lepton::MUON) ?   "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v" : "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v";
    if(DataYear==2017) dilep_triggerslist = (leps[0]->LeptonFlavour() == Lepton::MUON) ?   "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_v" : "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v";

    if(DataYear==2018) dilep_triggerslist = (leps[0]->LeptonFlavour() == Lepton::MUON) ?   "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v" : "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v";

    

    if(IsDATA&& !(ev.IsPDForTrigger(dilep_triggerslist, this->DataStream) )) return;
    if(ev.PassTrigger(dilep_triggerslist))    MakePromptRatePlots("", label, param,leps,blepsT,  jetCollTight, jetColl,  event_weight, isocut, METv);
  }
  return;
}


void HNL_FakeRate::MakePromptRatePlots(TString label, TString tag,AnalyzerParameter param,  std::vector<Lepton *> leps , std::vector<bool> blepsT , std::vector<Jet> jets, std::vector<Jet> alljets, float event_weight, float isocut, Particle MET){
  
  int nbin_ptcone=11;
  int nbin_pt    =11;
  int nbin_eta   =4;
  double ptbinscone[nbin_ptcone+1] = { 10.,15.,20.,30.,35., 40.,50., 60., 80., 100.,200.,2000.};
  double ptbins    [nbin_pt    +1] = { 10.,15.,20.,30.,35., 40.,50., 60., 80., 100.,200.,2000.};
  double etabins   [nbin_eta+1   ] = { 0.,0.8,  1.479, 2.,  2.5};

  Event ev = GetEvent();

  if(leps.size() != 2) return;

  Particle Z = (*leps[0]) + (*leps[1]);
  if(leps[0]->Charge() == leps[1]->Charge()) return;
  if(fabs(90. - Z.M()) > 10.) return;

  if(blepsT[1]){
    // lep [1] is tag
    int ilep=0;
    float lep_pt = leps[ilep]->Pt();
    float lep_pt_corr =  leps[ilep]->CalcPtCone(leps[ilep]->RelIso(), isocut);
    float lep_eta = fabs(leps[ilep]->Eta());
    if(lep_pt_corr > 2000.) lep_pt_corr = 1999.;
    float weight_ptcorr=event_weight;
    TString L_prefix = "Prompt_Loose"+tag ;
    TString T_prefix = "Prompt_Tight"+tag;
    
    for(int Tlep = 0 ; Tlep < 2; Tlep++)  {
      TString prefix = (Tlep==0) ? L_prefix : T_prefix;
      if((Tlep==1) && ! (blepsT[ilep])) continue;
      FillHist((prefix + "_pt_eta").Data(), lep_pt, lep_eta,  weight_ptcorr, nbin_pt, ptbins, nbin_eta , etabins);
      FillHist((prefix + "_ptcone_eta").Data(), lep_pt_corr, lep_eta,  weight_ptcorr, nbin_ptcone, ptbinscone, nbin_eta , etabins);
      if(fabs(90. - Z.M()) < 5){
	FillHist((prefix + "_TZ_pt_eta").Data(), lep_pt, lep_eta,  weight_ptcorr, nbin_pt, ptbins, nbin_eta , etabins);
	FillHist((prefix + "_TZ_ptcone_eta").Data(), lep_pt_corr, lep_eta,  weight_ptcorr, nbin_ptcone, ptbinscone, nbin_eta , etabins);
      }
    }
  }
  if(blepsT[0]){
    // lep [0] is tag                                                                                                                                                             
    int ilep=1;
    float lep_pt = leps[ilep]->Pt();
    float lep_pt_corr =  leps[ilep]->CalcPtCone(leps[ilep]->RelIso(), isocut);
    float lep_eta = fabs(leps[ilep]->Eta());
    if(lep_pt_corr > 2000.) lep_pt_corr = 1999.;
    float weight_ptcorr=event_weight;
    TString L_prefix = "Prompt_Loose"+tag ;
    TString T_prefix = "Prompt_Tight"+tag;

    for(int Tlep = 0 ; Tlep < 2; Tlep++)  {
      TString prefix = (Tlep==0) ? L_prefix : T_prefix;
      if((Tlep==1) && ! (blepsT[ilep])) continue;
      FillHist((prefix + "_pt_eta").Data(), lep_pt, lep_eta,  weight_ptcorr, nbin_pt, ptbins, nbin_eta , etabins);
      FillHist((prefix + "_ptcone_eta").Data(), lep_pt_corr, lep_eta,  weight_ptcorr, nbin_ptcone, ptbinscone, nbin_eta , etabins);
      if(fabs(90. - Z.M()) < 5){
	FillHist((prefix + "_TZ_pt_eta").Data(), lep_pt, lep_eta,  weight_ptcorr, nbin_pt, ptbins, nbin_eta , etabins);
        FillHist((prefix + "_TZ_ptcone_eta").Data(), lep_pt_corr, lep_eta,  weight_ptcorr, nbin_ptcone, ptbinscone, nbin_eta , etabins);
      }
    }
  }


  return;
}


float HNL_FakeRate::GetPrescale(std::vector<Lepton *>   leps  ){

  if(leps.size() != 1) return 0.;

  
  Event ev = GetEvent();
  float prescale_trigger= 1.;
  if(leps[0]->LeptonFlavour() == Lepton::MUON){

    TString triggerslist_3="HLT_Mu3_PFJet40_v";
    TString triggerslist_8="HLT_Mu8_TrkIsoVVL_v";
    TString triggerslist_17="HLT_Mu17_TrkIsoVVL_v";

    bool Mu3PD= (!IsDATA || (IsDATA&& ev.IsPDForTrigger(triggerslist_3, this->DataStream) ));
    bool Mu8PD= (!IsDATA || (IsDATA&& ev.IsPDForTrigger(triggerslist_8, this->DataStream) ));
    bool Mu17PD= (!IsDATA || (IsDATA&& ev.IsPDForTrigger(triggerslist_17, this->DataStream) ));

    bool pass_3 = ev.PassTrigger(triggerslist_3) && Mu3PD;
    bool pass_8 = ev.PassTrigger(triggerslist_8) && Mu8PD;
    bool pass_17 = ev.PassTrigger(triggerslist_17) && Mu17PD;
  

    /// 10 - 20  HLT_Mu7
    /// 20 - INF  HLT_Mu17
    
    if(leps.at(0)->Pt() >= 20.){
      if(pass_17) prescale_trigger = (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_17);
      else return 0;
    }
    else  if(leps.at(0)->Pt() >= 10.){

      if(pass_8)prescale_trigger =  (IsDATA) ? 1. :   ev.GetTriggerLumi(triggerslist_8) ; //// 20 + GeV bins
      else return 0;
    }
    else  if(leps.at(0)->Pt() >= 5.){
      if(pass_3)prescale_trigger =  (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_3) ; //// 20 + GeV bins                                                                             
      else return 0 ;
    }      
    if(prescale_trigger == 0.) return 0.;
    if(leps.at(0)->Pt() < 5.) return 0.;
    
    return prescale_trigger;
  }
  else{
    TString triggerslist_8="HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v";  
    TString triggerslist_12="HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v";
    TString triggerslist_17="HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v";
    TString triggerslist_23="HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v";
    bool El8PD= (!IsDATA || (IsDATA&& ev.IsPDForTrigger(triggerslist_8, this->DataStream) ));
    bool EL12PD= (!IsDATA || (IsDATA&& ev.IsPDForTrigger(triggerslist_12, this->DataStream) ));
    bool EL17PD= (!IsDATA || (IsDATA&& ev.IsPDForTrigger(triggerslist_17, this->DataStream) ));
    bool EL23PD= (!IsDATA || (IsDATA&& ev.IsPDForTrigger(triggerslist_23, this->DataStream) ));

    bool pass_8 = ev.PassTrigger(triggerslist_8) && El8PD;
    bool pass_12 = ev.PassTrigger(triggerslist_12) && EL12PD ;
    bool pass_17 = ev.PassTrigger(triggerslist_17) && EL17PD;
    bool pass_23 = ev.PassTrigger(triggerslist_23) && EL23PD;
 
    if(leps.at(0)->Pt() >= 25.){
      if(pass_23)prescale_trigger = (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_23);
      else return 0;
    }
    else   if(leps.at(0)->Pt() >= 20.){
      if(pass_17)prescale_trigger = (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_17);
      else return 0;
    }
    else   if(leps.at(0)->Pt() >= 15.){
      if(pass_12) prescale_trigger = (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_12);
      else return 0;
    }
    else   if(leps.at(0)->Pt() >= 9.5){
      if(pass_8) prescale_trigger = (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_8);
      else return 0;
    }
    else prescale_trigger = 0.;
    if(prescale_trigger == 0.) return 0.;
    if(leps.at(0)->Pt() < 9.5) return 0.;
    return prescale_trigger;

  }
  
  return prescale_trigger;
}
 

void HNL_FakeRate::MakeFakeRatePlots(TString label, TString mutag,AnalyzerParameter param,  std::vector<Lepton *> leps , std::vector<bool> blepsT ,  std::vector<Jet> jets, std::vector<Jet> alljets, float event_weight, float isocut, Particle MET){
				
  if(!IsDATA)gens = GetGens();


  /// FOR FAKE RATE SUBTRACTION NEED ONLY PROMPT MUONS                                                                                                                                                  
  bool truth_match= false;

  if(!IsDATA) {
    if(leps.size() > 0){
      if(GetLeptonType(*leps[0], gens) > 0 ) truth_match=true;
    }
  }
  else truth_match=true;
  if(!truth_match) return;

  bool useevent20 = UseEvent(leps , jets, 20.,  MET, event_weight);
  bool useevent30 = UseEvent(leps , jets, 30.,  MET, event_weight);
  bool useevent40 = UseEvent(leps , jets, 40.,  MET, event_weight);
  bool useevent60 = UseEvent(leps , jets, 60.,  MET, event_weight);


  label= mutag;
  if(jets.size() >= 1){
    if(useevent20)GetFakeRates(leps, blepsT, param, label, jets, alljets,  label+"_20",(event_weight),isocut);
    if(useevent30)GetFakeRates(leps, blepsT,param, label, jets, alljets,  label+"_30",(event_weight),isocut);
    if(useevent40)GetFakeRates(leps, blepsT,param, label, jets, alljets,  label+"_40",(event_weight),isocut);
    if(useevent60)GetFakeRates(leps, blepsT,param, label,jets, alljets,  label+"_60",(event_weight),isocut);
  }
  return;
}


bool HNL_FakeRate::UseEvent(std::vector<Lepton *> leps ,  std::vector< Jet> jets, float awayjetcut, Particle MET, float wt){


  bool useevent = false;
  if(leps.size() != 1) return false;
  
  Double_t MT=0;
  Double_t METdphi=0;
  for(unsigned int w = 0; w < leps.size();  w++){
    METdphi = TVector2::Phi_mpi_pi(leps.at(w)->Phi()-MET.Phi());
    MT = sqrt(2.* leps.at(w)->Et()*MET.Pt() * (1 - cos( METdphi)));
    if(( (MET.Pt() < 40) && (MT < 25.)) ) {

      for (unsigned int ielT=0; ielT < leps.size(); ielT++){
        for(unsigned int ij=0; ij < jets.size(); ij++){
          if(jets.at(ij).Pt() < awayjetcut) continue;
          float dphi =fabs(TVector2::Phi_mpi_pi(leps.at(ielT)->Phi()- jets.at(ij).Phi()));
          if(dphi > 2.5){
            if((jets.at(ij).Pt() /  leps.at(ielT)->Pt() ) < 1.) continue;
            useevent = true;
          }
	}
      }
    }
  }

  return useevent;

}


void HNL_FakeRate::GetFakeRates(std::vector<Lepton *> leps,std::vector<bool> blepsT,  AnalyzerParameter param,TString tightlabel,  std::vector<Jet> jets,  std::vector<Jet> lljets, TString tag,float event_weight, float isocut){
					 
  bool IsMuon=(leps[0]->LeptonFlavour() == Lepton::MUON);
  int nbin_ptcone=  IsMuon ? 10 : 9;
  int nbin_pt    = IsMuon ? 10 : 10;
  int nbin_eta   = 4;
  
  double ptbinscone  [nbin_ptcone+1];
  double ptbins      [nbin_pt+1];
  double etabins   [nbin_eta+1   ] =  { 0.,0.8,  1.479, 2.,  2.5};
  if(IsMuon){
    vector<double> vptbinscone = {6.,10., 15.,20.,25.,30.,35.,40.,50., 60.,200. } ;
    vector<double> vptbins =  { 5., 10., 15.,20.,25.,30.,35.,40.,50.,60.,200.} ; 
    std::copy(vptbinscone.begin(), vptbinscone.end(), ptbinscone);
    std::copy(vptbins.begin(), vptbins.end(), ptbins);
  }
  else{
    vector<double> vptbinscone = { 10., 15.,23.,30.,35., 40.,50.,60.,100.,200.};
    vector<double> vptbins     = { 10., 15.,20.,25.,30., 35.,40.,50.,60.,100., 200.};
    std::copy(vptbinscone.begin(), vptbinscone.end(), ptbinscone);
    std::copy(vptbins.begin(), vptbins.end(), ptbins);

  }
  Event ev = GetEvent();

  float lep_pt = leps[0]->Pt();
  float lep_pt_corr =  leps[0]->CalcPtCone(leps[0]->RelIso(), isocut);
  float lep_eta =   fabs(leps[0]->Eta());
  float lep_reliso  = leps[0]->RelIso();
  float lep_ip3d    = fabs(leps[0]->IP3D()/leps[0]->IP3Derr());
  float lep_mva     =  leps[0]->lep_mva();
  float lep_dxy     = leps[0]->dXY();
  if(lep_pt_corr > 200.) lep_pt_corr = 200.;

  float weight_ptcorr=event_weight;
  float weight_pt=event_weight;
  TString L_prefix = "Fake_Loose"+tag;
  TString T_prefix =  "Fake_Tight"+tag;

  double prescale_lep (1.);

  bool fill_plot=false;

  if(IsMuon){
    TString triggerslist_3="HLT_Mu3_PFJet40_v";
    TString triggerslist_8="HLT_Mu8_TrkIsoVVL_v";
    TString triggerslist_17="HLT_Mu17_TrkIsoVVL_v";
    bool Mu3PD= (!IsDATA || (IsDATA&& ev.IsPDForTrigger(triggerslist_3, this->DataStream) ));
    bool Mu8PD= (!IsDATA || (IsDATA&& ev.IsPDForTrigger(triggerslist_8, this->DataStream) ));
    bool Mu17PD= (!IsDATA || (IsDATA&& ev.IsPDForTrigger(triggerslist_17, this->DataStream) ));

    if(lep_pt_corr< 5) return;
    else if (lep_pt_corr > 5  && lep_pt_corr < 15){
      if(lep_pt > 5.) {
	if(Mu3PD&&ev.PassTrigger(triggerslist_3)) { fill_plot=true; if(!IsDATA)weight_ptcorr = event_weight * ev.GetTriggerLumi(triggerslist_3);}
	else { fill_plot=false;weight_ptcorr = 0.;	}
      }
    }
    
    else if ( lep_pt_corr < 30){
      if(lep_pt > 10) {

	if(Mu8PD&&ev.PassTrigger(triggerslist_8)) {  fill_plot=true;if(!IsDATA)weight_ptcorr= event_weight * ev.GetTriggerLumi(triggerslist_8); }
	else{ fill_plot=false;weight_ptcorr = 0.;      }
      }
    }
    
    else {
      if(lep_pt > 20) {
	if(Mu17PD && ev.PassTrigger(triggerslist_17)) {  fill_plot=true; if(!IsDATA) weight_ptcorr= event_weight * ev.GetTriggerLumi(triggerslist_17);}
        else{ fill_plot=false;weight_ptcorr = 0.;      }
      }
    }
    
    /// Get precale weiht for normal pt bins
    prescale_lep = GetPrescale(leps);
  } 
  else{
    
    TString triggerslist_8="HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v";   /// -> tighter cut in lepton ID form tighter trigger emulation cut                    
    TString triggerslist_12="HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v";
    TString triggerslist_17="HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v";
    TString triggerslist_23="HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v";

    bool El8PD=  (!IsDATA || (IsDATA&& ev.IsPDForTrigger(triggerslist_8, this->DataStream) ));
    bool El12PD= (!IsDATA || (IsDATA&& ev.IsPDForTrigger(triggerslist_12, this->DataStream) ));
    bool El17PD= (!IsDATA || (IsDATA&& ev.IsPDForTrigger(triggerslist_17, this->DataStream) ));
    bool El23PD= (!IsDATA || (IsDATA&& ev.IsPDForTrigger(triggerslist_23, this->DataStream) ));


    if (lep_pt_corr > 10  && lep_pt_corr < 23){
      if(lep_pt > 10) {
	if(El8PD && ev.PassTrigger(triggerslist_8)) { fill_plot=true;if(!IsDATA)weight_ptcorr = event_weight * ev.GetTriggerLumi(triggerslist_8);}
	else{fill_plot=false;weight_ptcorr = 0.;}
      }
    }
    else if ( lep_pt_corr < 35){
      if(lep_pt > 15) {
	if(El12PD&&ev.PassTrigger(triggerslist_12)) {  fill_plot=true;if(!IsDATA)weight_ptcorr = event_weight * ev.GetTriggerLumi(triggerslist_12);}
	else{ fill_plot=false;weight_ptcorr = 0.;}
      }
    }
    
    else if (lep_pt_corr < 40){
      if(lep_pt > 20) {
	if(El17PD&& ev.PassTrigger(triggerslist_17)) {fill_plot=true; if(!IsDATA)weight_ptcorr = event_weight * ev.GetTriggerLumi(triggerslist_17);}
	else{fill_plot=false;weight_ptcorr = 0.;}
      }
    }
    else{
      if(lep_pt > 25) {
	if(El23PD&&ev.PassTrigger(triggerslist_23)) {fill_plot=true;if(!IsDATA)weight_ptcorr = event_weight * ev.GetTriggerLumi(triggerslist_23);}
	else{fill_plot=false;	  weight_ptcorr = 0.;}
      }// pt 
    }// end ptbin check
    prescale_lep = GetPrescale(leps);
  }


  int NBJet = GetNBJets2a("tight","DeepJet_Medium");
  
  double ptminfix = IsMuon ? 8 : 12;
  double ptmin    = IsMuon ? 10 : 10;

  for(int ilep = 0 ; ilep < 2; ilep++)  {
    TString prefix = (ilep==0) ? L_prefix : T_prefix;
    if((ilep==1) && !(blepsT[0])) continue;
    if(lep_pt > ptmin){
      FillHist((prefix + "_reliso").Data(), lep_reliso, weight_pt*prescale_lep, 50, 0., 1.);
      FillHist((prefix + "_dXY").Data(),    lep_dxy, weight_pt*prescale_lep, 50, 0., 1.);
      FillHist((prefix + "_IP3D").Data(),   lep_ip3d, weight_pt*prescale_lep, 50, 0., 10.);
      FillHist((prefix + "_mva").Data(),    lep_mva, weight_pt*prescale_lep, 50, -1., 1.);
      FillHist((prefix + "_pt_eta").Data(), lep_pt, lep_eta,weight_pt*prescale_lep, nbin_pt, ptbins, nbin_eta , etabins);
      FillHist((prefix + "_pt").Data(),     lep_pt, weight_pt*prescale_lep, nbin_pt, ptbins, "p_{T} (GeV)");
      FillHist((prefix + "_eta").Data(),    lep_eta, weight_pt*prescale_lep , nbin_eta, etabins,"#eta");
      if(NBJet==0){
	FillHist((prefix + "_0BJet_pt").Data(),     lep_pt, weight_pt*prescale_lep, nbin_pt, ptbins, "p_{T} (GeV)");
	FillHist((prefix + "_0BJet_eta").Data(),    lep_eta, weight_pt*prescale_lep , nbin_eta, etabins,"#eta");
      }
      else{
	FillHist((prefix + "_BJet_pt").Data(),     lep_pt, weight_pt*prescale_lep, nbin_pt, ptbins, "p_{T} (GeV)");
        FillHist((prefix + "_BJet_eta").Data(),    lep_eta, weight_pt*prescale_lep , nbin_eta, etabins,"#eta");
      }
    }    
    if(fill_plot) {
      FillHist((prefix + "_ptcone_eta").Data(), lep_pt_corr, lep_eta,  weight_ptcorr, nbin_ptcone, ptbinscone, nbin_eta , etabins);
      if(lep_pt > ptminfix) FillHist((prefix + "_ptcone_ptfix_eta").Data(), lep_pt_corr, lep_eta,  weight_ptcorr, nbin_ptcone, ptbinscone, nbin_eta , etabins);
    }
  }
  return;
}


HNL_FakeRate::HNL_FakeRate(){
  
}
 
HNL_FakeRate::~HNL_FakeRate(){

}


TString HNL_FakeRate::SingleElectronPD(TString hlt){

  /// --- return PD name for E channel data                                                                                                
  if(DataYear==2016){
    if(hlt=="HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v")  return "DoubleEG";
    if(hlt=="HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v")  return "DoubleEG";
    if(hlt=="HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v")  return "DoubleEG";
    return "NULL";
  }
  if(DataYear==2017){
    if(hlt=="HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v")  return "SingleElectron";
    if(hlt=="HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v")  return "SingleElectron";
    if(hlt=="HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v")  return "DoubleEG";
    return "NULL";
  }
  if(DataYear==2018) return "EGamma";

  return "";

  /*
HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v
purpose:
active lumi: 36.47 fb-1 (2016) 36.75 fb-1 (2017) 59.96 fb-1 (2018)
effective lumi: 0.0151 fb-1 (2016) 0.0276 fb-1 (2017) 0.0390 fb-1 (2018)
run range in menu: 273158 - 284044 (2016) 299368 - 306460 (2017) 315257 - 325172 (2018)
dataset: DoubleEG (2016) SingleElectron (2017) EGamma (2018)

   */

}

TString HNL_FakeRate::SingleMuonPD(TString hlt){

  if(DataYear==2016){
    if(hlt=="HLT_Mu3_PFJet40_v") return "DoubleMuon";
    if(hlt=="HLT_Mu18_TrkIsoVVL_v") return "DoubleMuon";
    if(hlt=="HLT_Mu17_TrkIsoVVL_v") return "DoubleMuon";
    if(hlt=="HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v") return "DoubleMuon";
  }

  if(DataYear==2017){
    if(hlt=="HLT_Mu3_PFJet40_v") return "SingleMuon";
    if(hlt=="HLT_Mu18_TrkIsoVVL_v") return "DoubleMuon";
    if(hlt=="HLT_Mu17_TrkIsoVVL_v") return "DoubleMuon";
    if(hlt=="HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v") return "DoubleMuon";
  }


  if(DataYear==2016){
    if(hlt=="HLT_Mu3_PFJet40_v") return "SingleMuon";
    if(hlt=="HLT_Mu18_TrkIsoVVL_v") return "DoubleMuon";
    if(hlt=="HLT_Mu17_TrkIsoVVL_v") return "DoubleMuon";
    if(hlt=="HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v") return "DoubleMuon";
  }

  return "SingleMuon";

}


void HNL_FakeRate::FillRegionPlots( TString label_1,  std::vector<Jet> jets,  std::vector<Electron> els, std::vector<Muon> mus, Particle  met,  double w){
  
  if((els.size()+ mus.size()) != 1) return;
  Particle lep1;
  if(els.size()==1) lep1=els[0];
  else lep1 = mus[0];

  FillHist( label_1 +  "/lep1_pt_" + label_1, lep1.Pt()  , w, 400, 0., 2000.,"p_{T} GeV");

  FillHist( label_1 +  "/lep1_eta_" + label_1, lep1.Eta()  , w, 30, -3., 3,"#eta");
  
  FillHist( label_1 +  "/met_" + label_1, met.Pt()  , w, 200, 0., 400.,"MET GeV");

  FillHist( label_1 +  "/njets_" + label_1, jets.size() , w, 10, 0., 10., "N_{jets}");


  double METdphi = TVector2::Phi_mpi_pi(lep1.Phi()-met.Phi());
  double MT = sqrt(2.* lep1.Et()*met.Pt() * (1 - cos( METdphi)));

  FillHist( label_1 +  "/mt_" + label_1, MT  , w, 50, 0., 100.,"MET GeV");

}


void HNL_FakeRate::FillEventCutflow(int charge_i, int cf,float wt, TString cut,   TString label){


  return;

}

void HNL_FakeRate::FillWeightHist(TString label, double _weight){
  FillHist( "weights/"+ label , _weight ,1., 200, 0., 5,"ev weight");
}
void HNL_FakeRate::FillCutFlow(bool IsCentral, TString suffix, TString histname, double weight){

  if(IsCentral){

    FillHist(suffix+"/"+histname, 0., weight, 1, 0., 1.);

  }

}

