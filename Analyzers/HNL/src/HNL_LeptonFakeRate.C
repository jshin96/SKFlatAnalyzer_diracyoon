#include "HNL_LeptonFakeRate.h"

void HNL_LeptonFakeRate::initializeAnalyzer(){

  HNL_LeptonCore::initializeAnalyzer();

  TString AnalyzerPath=getenv("SKFlat_WD"), SKFlatV = getenv("SKFlatV");
  TString FilePath="/data/"+SKFlatV+"/"+GetEra()+"/FakeRate/NvtxSF/";
  NvtxSFFile = new TFile(AnalyzerPath+FilePath+"FakeRateNVtx13TeV_"+GetEra()+".root");

  //// Flags available in this code
  /// HasFlag("GetNvtxSF")

  /*
    Method 1
    
   */
  

}

void HNL_LeptonFakeRate::executeEvent(){

  Event ev = GetEvent();

  //************************************************///
  // setup list of IDs and jobs

  vector<AnalyzerParameter> VParameters;
  VParameters.push_back(SetupFakeParameter(MuMu,"FakeRate_Muon","HNL_ULID_"+GetYearString(),"HNL_ULID_"+GetYearString(), "HNL_ULID_FO"));
  			
  for(auto param : VParameters)  executeEventFromParameter(param);
  
}

void HNL_LeptonFakeRate::executeEventFromParameter(AnalyzerParameter param){

  
  //************************************************///
  // setup event level objects
  Event ev = GetEvent();

  double weight = SetupWeight(ev, param);
  if(IsData) weight = 1;
 
  if(!PassMETFilter()) return;
  
  std::vector<Electron> loose_electrons     = SelectElectrons( param,param.Electron_Loose_ID, 10, 2.5) ;
  std::vector<Muon>     loose_muons         = SelectMuons    ( param,param.Muon_Loose_ID,     5,   2.4);

  std::vector<Jet> jets_tmp     = SelectJets   ( param, "tight", 30., 2.7);
  std::vector<Jet> jets; 
  for(unsigned int ijet =0; ijet < jets_tmp.size(); ijet++){
    bool jetok=true;
    for(unsigned int iel=0 ; iel < loose_electrons.size(); iel++)   { if(jets_tmp[ijet].DeltaR(loose_electrons[iel]) < 0.4) jetok = false;}
    for(unsigned int iel=0 ; iel < loose_muons.size(); iel++)       { if(jets_tmp[ijet].DeltaR(loose_muons[iel]) < 0.4)     jetok = false;}
    if(jetok) jets.push_back(jets_tmp[ijet]);
  }
  if(param.Channel=="EE")   RunE(loose_electrons,loose_muons, jets,  param, weight);
  if(param.Channel=="MuMu") RunM(loose_electrons,loose_muons,  jets, param, weight);
  
}


void HNL_LeptonFakeRate::RunM(std::vector<Electron> loose_el,  std::vector<Muon> loose_mu, std::vector<Jet> jets,   AnalyzerParameter param,  float event_weight){

  if(IsData){
    if(this->DataStream == "DoubleEG") return;
    if(this->DataStream == "SingleElectron") return;
    if(this->DataStream == "EGamma") return;
  }

  Event ev = GetEvent();

  if(loose_mu.size() == 0) return;

  // remove if muon                                                                                                                          
  if(loose_el.size() > 0) return;

  std::vector<Lepton *> leps = MakeLeptonPointerVector(loose_mu);
  std::vector<bool> blepsT;
  for(auto ilep : loose_mu)   blepsT.push_back(ilep.PassID(param.Muon_Tight_ID));
  
  if(HasFlag("GetNvtxSF")){
    MakeNVertexDistPrescaledTrig(MuMu,param, ev, leps,blepsT,param.Name+param.Channel,event_weight);
    return;
  }

  if(HasFlag("RunRates")){
    GetFakeRateAndPromptRates(param, leps,blepsT,jets,param.Name+param.Channel,event_weight,-999.);
    return;
  }

  return;
  //  if (param.Muon_Tight_ID != "HNTightV2") return;

  MakeDiLepPlots(MuMu,param, ev, leps,blepsT,param.Name+param.Channel,event_weight);

  if(loose_mu.size() != 1) return;
  
  bool has_away_jet=false;
  for(unsigned int ij=0; ij < jets.size(); ij++){
    if(jets.at(ij).Pt() < 40.) continue;
    float dphi =fabs(TVector2::Phi_mpi_pi(loose_mu[0].Phi()- jets.at(ij).Phi()));
    if(dphi > 2.5){
      has_away_jet=true;
    }
  }

  /// Make plots to check control of prompt leptons and to plot Loose and Tight Samples
  /// Only run when not running MANY IDs so param.WriteOutVerbose is set to 2

  // prescale_trigger is to to weight of trigger prescalee depedning on the pt
  float prescale_trigger = GetPrescale(leps);
  if(prescale_trigger == 0.) return;
  event_weight*=prescale_trigger;


  Particle METv = GetvMET("PuppiT1xyULCorr",param);

  bool truth_match= false;
  if(!IsDATA) {
    if(loose_mu.at(0).LeptonGenType() > 0 ) truth_match=true;
  }
  else truth_match=true;

  if(jets.size() > 0){
    if(jets.at(0).Pt() > 40.){
      
      // Plot for 1  lep + Jet pT > trig pt
      FillRegionPlots("MuMu", "SingleLooseMuJet_"+param.Name , jets,   loose_el,loose_mu,  METv, event_weight);
      if(has_away_jet)       FillRegionPlots("MuMu","SingleLooseMuAwayJet_"+param.Name, jets,   loose_el,  loose_mu,  METv, event_weight);
      if(blepsT[0]){
        FillRegionPlots("MuMu","SingleTightMuJet_"+param.Name,  jets,  loose_el,loose_mu,  METv, event_weight);
        if(has_away_jet) FillRegionPlots("MuMu","SingleTightMuAwayJet_"+param.Name, jets,  loose_el, loose_mu,  METv, event_weight);
      }
    }
  }

  Double_t MT=0;
  Double_t METdphi=0;
  for(unsigned int imu = 0; imu < loose_mu.size();  imu++){
    METdphi=  TVector2::Phi_mpi_pi((loose_mu.at(imu).Phi()- METv.Phi()));
    MT = sqrt(2.* loose_mu.at(imu).Et()*METv.Pt() * (1 - cos( METdphi)));
  }
  if((60. < MT)  &&(MT < 100.)){
    if(loose_mu[0].Pt() > 20){
      if(jets.size() > 0 && blepsT[0]){
	if(jets[0].Pt() > 40){
	  
	  FillRegionPlots("MuMu","SingleTightMu_promptCR_"+param.Name, jets,  loose_el,loose_mu, METv, event_weight);
	  if(has_away_jet)FillRegionPlots("MuMu","SingleTightMuAwayJet_promptCR_"+param.Name, jets,  loose_el,loose_mu, METv, event_weight);

	  bool isPrompt=false;
	  for(unsigned int ij=0; ij < jets.size(); ij++){
	    if(jets.at(ij).Pt() < 40.) continue;
	    float dphi =fabs(TVector2::Phi_mpi_pi(loose_mu[0].Phi()- jets.at(ij).Phi()));
	    if(dphi > 2.5){
	      if((jets.at(ij).Pt() /  loose_mu[0].Pt() ) < 1.) isPrompt = true;
	    }
	  }
	  
	  if (isPrompt) FillRegionPlots("MuMu","SingleTightMu_promptCR2_"+param.Name, jets,  loose_el,loose_mu, METv, event_weight);
	  if (isPrompt&&has_away_jet) FillRegionPlots("MuMu","SingleTightMuAwayJet_promptCR2_"+param.Name, jets,  loose_el,loose_mu, METv, event_weight);
	}
	
      }
    }
  }

  
  bool useevent40 = UseEvent(leps , jets, 40., METv, event_weight);
  if(useevent40){
    if (blepsT[0] && jets.size() >= 1)FillRegionPlots("MuMu","TightMu40_notm_"+param.Name, jets,  loose_el,loose_mu, METv, event_weight);
    if (jets.size() >= 1)FillRegionPlots("MuMu","LooseMu40_notm_"+param.Name, jets,  loose_el,loose_mu, METv, event_weight);
    
    if(truth_match){
      if (blepsT[0] && jets.size() >= 1)FillRegionPlots("MuMu","TightMu40_"+param.Name , jets,  loose_el,loose_mu, METv, event_weight);
      if (jets.size() >= 1)FillRegionPlots("MuMu","LooseMu40_"+param.Name, jets,  loose_el,loose_mu, METv, event_weight);
    }
    
  }
  
  return;

} /// end function                      





void HNL_LeptonFakeRate::RunE( std::vector<Electron> loose_el, std::vector<Muon> loose_mu, std::vector<Jet> jets, AnalyzerParameter param,  float event_weight){

  return;
  if(IsData){
    if(this->DataStream == "DoubleMuon") return;
    if(this->DataStream == "SingleMuon") return;
  }

  TString channel_s="_EE";
  TString label = param.Name;
  Event ev = GetEvent();

  Particle METv = GetMiniAODvMET("PuppiT1xyULCorr");
  
  if(loose_el.size() == 0) return;
 

  TString triggerslist_8="HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30_v";   /// -> tighter cut in lepton ID form tighter trigger emulation cut                                     
  TString triggerslist_12="HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v";
  TString triggerslist_18="HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v";
  TString triggerslist_23="HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v";
  TString triggerslist_33="HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v"; /// 

  // remove if muon 
  if(loose_mu.size() > 0) return;

  //double isocut = GetIsoFromID("Electron", param.Electron_Tight_ID,loose_el[0].Eta(), loose_el[0].Pt());
  std::vector<Lepton *> leps = MakeLeptonPointerVector(loose_el);
  std::vector<bool> blepsT;
  for(auto ilep : loose_el) {
    blepsT.push_back(ilep.PassID(param.Electron_Tight_ID));
  }

  if(HasFlag("GetNvtxSF")){
    MakeNVertexDistPrescaledTrig(EE,param, ev, leps,blepsT,param.Name+channel_s,event_weight);
    return;
  }

  if(fabs(param.WriteOutVerbose) > 1) {
    GetFakeRateAndPromptRates(param, leps,blepsT,jets,param.Name+channel_s,event_weight,-999.);
    return;
  }


  ///  if (param.Electron_Tight_ID != "HNTightV2") return;

  MakeDiLepPlots(EE,param, ev, leps,blepsT,param.Name+channel_s,event_weight);
  
  if(loose_el.size() != 1) return;

  bool has_away_jet=false;
  for(unsigned int ij=0; ij < jets.size(); ij++){
    if(jets.at(ij).Pt() < 40.) continue;
    float dphi =fabs(TVector2::Phi_mpi_pi(loose_el[0].Phi()- jets.at(ij).Phi()));
    if(dphi > 2.5){
      has_away_jet=true;
    }
  } 


  float prescale_trigger =  GetPrescale(leps);
  if(prescale_trigger == 0.) return;
  event_weight*=prescale_trigger;



  bool truth_match= false;
  if(!IsDATA) {
    if(loose_el.at(0).LeptonGenType() > 0 ) truth_match=true;
  }
  else truth_match=true;

  if(jets.size() > 0){
    if(jets.at(0).Pt() > 40.){
      FillRegionPlots("EE","SingleLooseElJet_"+param.Name , jets,   loose_el,loose_mu,  METv, event_weight);
      if(has_away_jet)      FillRegionPlots("EE","SingleLooseElAwayJet_"+param.Name , jets,   loose_el,loose_mu,  METv, event_weight);
      if(blepsT[0]){
        FillRegionPlots("EE","SingleTightElJet_"+param.Name,  jets,  loose_el,loose_mu,  METv, event_weight);
        if(has_away_jet) FillRegionPlots("EE","SingleTightElAwayJet_"+param.Name, jets,  loose_el, loose_mu,  METv, event_weight);
      }
    }
  }

  Double_t MT=0;
  Double_t METdphi=0;
  for(unsigned int iel = 0; iel < loose_el.size();  iel++){
    METdphi = TVector2::Phi_mpi_pi((loose_el.at(iel).Phi()- METv.Phi()));
    MT = sqrt(2.* loose_el.at(iel).Et()*METv.Pt() * (1 - cos( METdphi)));
  }
  if((60. < MT)  &&(MT < 100.)){
    if(loose_el[0].Pt() > 25){
      if(jets.size() > 0 && blepsT[0]){
	if(jets[0].Pt() > 40){
	  FillRegionPlots("EE","SingleTightEl_promptCR_"+param.Name, jets,  loose_el,loose_mu, METv, event_weight);
	  if(has_away_jet)	  FillRegionPlots("EE","SingleTightElAwayJet_promptCR_"+param.Name, jets,  loose_el,loose_mu, METv, event_weight);

	  bool isPrompt=false;
          for(unsigned int ij=0; ij < jets.size(); ij++){
	    if(jets.at(ij).Pt() < 40.) continue;
            float dphi =fabs(TVector2::Phi_mpi_pi(loose_el[0].Phi()- jets.at(ij).Phi()));
            if(dphi > 2.5){
              if((jets.at(ij).Pt() /  loose_el[0].Pt() ) < 1.) isPrompt = true;
	    }
	  }
	  
          if (isPrompt ) FillRegionPlots("EE","SingleTightEl_promptCR2_"+param.Name, jets,  loose_el,loose_mu, METv, event_weight);
	  if (isPrompt && has_away_jet) FillRegionPlots("EE","SingleTightElAwayJet_promptCR2_"+param.Name, jets,  loose_el,loose_mu, METv, event_weight);
	}
      }
    }
  }
  


  bool useevent40 = UseEvent(leps , jets, 40., METv,event_weight);
  if(useevent40){
    if (blepsT[0] && jets.size() >= 1)FillRegionPlots("EE","TightEl40_notm_"+param.Name, jets,  loose_el,loose_mu, METv, event_weight);
    if (jets.size() >= 1)FillRegionPlots("EE","LooseEl40_notm_"+param.Name, jets,  loose_el,loose_mu, METv, event_weight);
    
    
    if(truth_match){
      if (blepsT[0] && jets.size() >= 1)FillRegionPlots("EE","TightEl40_"+param.Name , jets,  loose_el,loose_mu, METv, event_weight);
      if (jets.size() >= 1)FillRegionPlots("EE","LooseEl40_"+param.Name, jets,  loose_el,loose_mu, METv, event_weight);
    }
  }
  
  
  return;
  


} /// end function RunE

double HNL_LeptonFakeRate::ApplyNvtxReweight(int NPV, TString Key){

  if(IsData) return 1.;
  if(!NvtxSFFile->GetListOfKeys()->Contains(Key)){ printf("[Error] No %s in NvtxSF File.\n", Key.Data()); return -1.; }

  std::map<TString, TH1D*>::iterator mapit = maphist_NvtxSF.find(Key);
  if(mapit == maphist_NvtxSF.end()){ //first usage
    maphist_NvtxSF[Key] = (TH1D*) ((TH1*) NvtxSFFile->Get(Key))->Clone();
  }
  mapit = maphist_NvtxSF.find(Key);
  
  int this_bin = mapit->second->FindBin(NPV);
  double NvtxSF = mapit->second->GetBinContent(this_bin);
  if(NvtxSF>10) NvtxSF=1.;

  return NvtxSF;

}


void HNL_LeptonFakeRate::MakeDiLepPlots(HNL_LeptonCore::Channel channel, AnalyzerParameter param, Event ev, std::vector<Lepton *> leps,std::vector<bool> blepsT,  TString label, float event_weight){

  if(leps.size() != 2) return;
  if(!blepsT[0] || !blepsT[1]) return;

  // now we have 2 Tight leptons                                                                                                                             

  TString plot_dir = GetChannelString(channel);

  // Make Z peak                                                                                                                                            
  Particle Z = (*leps[0]) + (*leps[1]);
  if(leps[0]->Charge() == leps[1]->Charge()) return;
  bool PassZMass = (fabs(M_Z - Z.M()) < 10.) ? true : false;

  std::vector<Jet> jets_tmp     = SelectJets   ( param, param.Jet_ID, 20., 5.);
  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
  std::vector<Jet> BJetColl    = SelectBJets(param, jets_tmp , param_jets);
  double sf_btag               = GetBJetSF(param, jets_tmp, param_jets);
  if(!IsData )event_weight*= sf_btag;

  if(BJetColl.size() > 0) return;

  int nbin_pt    =6;
  double bins_pt[nbin_pt+1] = {0.,5., 10., 20., 30., 50., 200. };

  if(channel == MuMu){

    TString triggerslist_3="HLT_Mu3_PFJet40_v";
    TString triggerslist_8="HLT_Mu8_TrkIsoVVL_v";
    TString triggerslist_17="HLT_Mu17_TrkIsoVVL_v";

    double NVxt_Mu3 =  ApplyNvtxReweight(nPV,triggerslist_3);
    double NVxt_Mu8 =  ApplyNvtxReweight(nPV,triggerslist_8);
    double NVxt_Mu17 =  ApplyNvtxReweight(nPV,triggerslist_17);

    bool Mu3PD= (!IsDATA || (IsDATA&& ev.IsPDForTrigger(triggerslist_3, this->DataStream) ));
    bool Mu8PD= (!IsDATA || (IsDATA&& ev.IsPDForTrigger(triggerslist_8, this->DataStream) ));
    bool Mu17PD= (!IsDATA || (IsDATA&& ev.IsPDForTrigger(triggerslist_17, this->DataStream) ));

    bool pass_3 = ev.PassTrigger(triggerslist_3) && Mu3PD;
    bool pass_8 = ev.PassTrigger(triggerslist_8) && Mu8PD;
    bool pass_17 = ev.PassTrigger(triggerslist_17) && Mu17PD;


    if(pass_3){
      if(leps[1]->Pt() > 5){
        double prescale_weight  =  (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_3)*NVxt_Mu3;
	
        if(PassZMass) {
	  for(auto ilep : leps)FillHist(( plot_dir +  "/RegionPlots_Dilep/"+triggerslist_3 + "_LepPt").Data(), ilep->Pt() , event_weight*prescale_weight,nbin_pt, bins_pt);
        }
        FillHist(( plot_dir +  "/RegionPlots_Dilep/"+triggerslist_3 + "_LLMass").Data(), Z.M() , event_weight*prescale_weight, 100., 0., 200);
      }
    }
    
    if(pass_8){
      if(leps[1]->Pt() > 10){
        double prescale_weight  =  (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_8)*NVxt_Mu8;
	
        if(PassZMass){
	  for(auto ilep : leps)FillHist(( plot_dir +  "/RegionPlots_Dilep/"+triggerslist_8 + "_LepPt").Data(), ilep->Pt() , event_weight*prescale_weight,nbin_pt, bins_pt);
        }
        FillHist(( plot_dir +  "/RegionPlots_Dilep/"+triggerslist_8 + "_LLMass").Data(), Z.M() , event_weight*prescale_weight, 100., 0., 200);

      }
    }
    if(pass_17){
      if(leps[1]->Pt() > 20){
        double prescale_weight  =  (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_17)*NVxt_Mu17;
        if(PassZMass){
          for(auto ilep : leps)FillHist(( plot_dir +  "/RegionPlots_Dilep/"+triggerslist_17 + "_LepPt").Data(), ilep->Pt() , event_weight*prescale_weight,nbin_pt, bins_pt);
        }
        FillHist(( plot_dir +  "/RegionPlots_Dilep/"+triggerslist_17 + "_LLMass").Data(), Z.M() , event_weight*prescale_weight, 100., 0., 200);
      }
    }
  }
  
  if(channel == EE){

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
    double NVxt_El8 =  ApplyNvtxReweight(nPV,triggerslist_8);
    double NVxt_El12 =  ApplyNvtxReweight(nPV,triggerslist_12);
    double NVxt_El23 =  ApplyNvtxReweight(nPV,triggerslist_23);


    if(pass_8){
      if(leps[1]->Pt() > 10){
        double prescale_weight  =  (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_8)*NVxt_El8;
        if(PassZMass){
          for(auto ilep : leps)FillHist(( plot_dir +  "/RegionPlots_Dilep/"+triggerslist_8 + "_LepPt").Data(), ilep->Pt() , event_weight*prescale_weight,nbin_pt, bins_pt);
        }
        FillHist(( plot_dir +  "/RegionPlots_Dilep/"+triggerslist_8 + "_LLMass").Data(), Z.M() , event_weight*prescale_weight, 100., 0., 200);

      }
    }
    if(pass_12){
      if(leps[1]->Pt() > 14){
        double prescale_weight  =  (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_12)*NVxt_El12;
        if(PassZMass){
          for(auto ilep : leps)FillHist(( plot_dir +  "/RegionPlots_Dilep/"+triggerslist_12 + "_LepPt").Data(), ilep->Pt() , event_weight*prescale_weight,nbin_pt, bins_pt);
        }
        FillHist(( plot_dir +  "/RegionPlots_Dilep/"+triggerslist_12 + "_LLMass").Data(), Z.M() , event_weight*prescale_weight, 100., 0., 200);
      }
    }

    if(pass_17){
      if(leps[1]->Pt() > 20){
        double prescale_weight  =  (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_17)*NVxt_El12;
        if(PassZMass){
          for(auto ilep : leps)FillHist(( plot_dir +  "/RegionPlots_Dilep/"+triggerslist_17 + "_LepPt").Data(), ilep->Pt() , event_weight*prescale_weight,nbin_pt, bins_pt);
        }
        FillHist(( plot_dir +  "/RegionPlots_Dilep/"+triggerslist_17 + "_LLMass").Data(), Z.M() , event_weight*prescale_weight, 100., 0., 200);
      }
    }
    if(pass_23){
      if(leps[1]->Pt() > 25){
        double prescale_weight  =  (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_23)*NVxt_El23;
        if(PassZMass){
          for(auto ilep : leps)FillHist(( plot_dir +  "/RegionPlots_Dilep/"+triggerslist_23 + "_LepPt").Data(), ilep->Pt() , event_weight*prescale_weight,nbin_pt, bins_pt);
        }
        FillHist(( plot_dir +  "/RegionPlots_Dilep/"+triggerslist_23 + "_LLMass").Data(), Z.M() , event_weight*prescale_weight, 100., 0., 200);
      }
    }
  }

  return;


}



void HNL_LeptonFakeRate::MakeNVertexDistPrescaledTrig(HNL_LeptonCore::Channel channel, AnalyzerParameter param, Event ev, std::vector<Lepton *> leps,std::vector<bool> blepsT,  TString label, float event_weight){
  

  if(leps.size() != 2) return;
  if(!blepsT[0] || !blepsT[1]) return;
  
  // now we have 2 Tight leptons
  // Make Z peak 

  Particle Z = (*leps[0]) + (*leps[1]);
  if(leps[0]->Charge() == leps[1]->Charge()) return;


  // remove b jet 

  std::vector<Jet> jets_tmp     = SelectJets   ( param, param.Jet_ID, 20., 5.);
  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
  std::vector<Jet> BJetColl    = SelectBJets(param, jets_tmp , param_jets);
  double sf_btag               = GetBJetSF(param, jets_tmp, param_jets);
  if(!IsData )event_weight*= sf_btag;

  if(BJetColl.size() > 0) return;

  bool PassZMass = (fabs(M_Z - Z.M()) < 10.) ? true : false;


  // Now plot Z peak for

  int nbin_npv    =35;
  double bins_npv[nbin_npv+1] = { 0.,5., 10.,12., 14., 16., 18., 20., 22., 24., 26., 28., 30., 32., 34., 36., 38., 40., 42., 44., 46., 48., 50., 52., 54., 56., 58., 60., 62., 64., 66., 68., 70., 75., 80., 100.};



  if(channel == MuMu){

    TString triggerslist_3="HLT_Mu3_PFJet40_v";
    TString triggerslist_8="HLT_Mu8_TrkIsoVVL_v";
    TString triggerslist_17="HLT_Mu17_TrkIsoVVL_v";

    bool Mu3PD= (!IsDATA || (IsDATA&& ev.IsPDForTrigger(triggerslist_3, this->DataStream) ));
    bool Mu8PD= (!IsDATA || (IsDATA&& ev.IsPDForTrigger(triggerslist_8, this->DataStream) ));
    bool Mu17PD= (!IsDATA || (IsDATA&& ev.IsPDForTrigger(triggerslist_17, this->DataStream) ));

    bool pass_3 = ev.PassTrigger(triggerslist_3) && Mu3PD;
    bool pass_8 = ev.PassTrigger(triggerslist_8) && Mu8PD;
    bool pass_17 = ev.PassTrigger(triggerslist_17) && Mu17PD;


    if(pass_3){
      if(leps[1]->Pt() > 5){
	double prescale_weight  =  (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_3);

	if(PassZMass) {
	  FillHist(( triggerslist_3 + "_Nvtx").Data(),  nPV , event_weight*prescale_weight,nbin_npv, bins_npv);
	}
	FillHist(( triggerslist_3 + "_LLMass").Data(), Z.M() , event_weight*prescale_weight, 100., 0., 200);
      }
    }
    if(pass_8){
      if(leps[1]->Pt() > 10){
	double prescale_weight  =  (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_8);

	if(PassZMass){
	  FillHist(( triggerslist_8 + "_Nvtx").Data(),  nPV , event_weight*prescale_weight,nbin_npv, bins_npv);
	}
        FillHist(( triggerslist_8 + "_LLMass").Data(), Z.M() , event_weight*prescale_weight, 100., 0., 200);

      }
    }
    if(pass_17){
      if(leps[1]->Pt() > 20){
	double prescale_weight  =  (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_17);
	if(PassZMass){
	  FillHist(( triggerslist_17 + "_Nvtx").Data(),  nPV , event_weight*prescale_weight,nbin_npv, bins_npv);
	} 
	FillHist(( triggerslist_17 + "_LLMass").Data(), Z.M() , event_weight*prescale_weight, 100., 0., 200);
      }
    }   
  }
  


  if(channel == EE){

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


    if(pass_8){
      if(leps[1]->Pt() > 10){
        double prescale_weight  =  (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_8);
	if(PassZMass){
	  FillHist(( triggerslist_8 + "_Nvtx").Data(),  nPV , event_weight*prescale_weight,nbin_npv, bins_npv);
	}
        FillHist(( triggerslist_8 + "_LLMass").Data(), Z.M() , event_weight*prescale_weight, 100., 0., 200);

      }
    }
    if(pass_12){
      if(leps[1]->Pt() > 14){
        double prescale_weight  =  (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_12);
	if(PassZMass){
	  FillHist(( triggerslist_12 + "_Nvtx").Data(),  nPV , event_weight*prescale_weight,nbin_npv, bins_npv);
	}
	FillHist(( triggerslist_12 + "_LLMass").Data(), Z.M() , event_weight*prescale_weight, 100., 0., 200);
	      }
    }
    if(pass_17){
      if(leps[1]->Pt() > 20){
        double prescale_weight  =  (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_17);
	if(PassZMass){
	  FillHist(( triggerslist_17 + "_Nvtx").Data(),  nPV , event_weight*prescale_weight,nbin_npv, bins_npv);
	}
	FillHist(( triggerslist_17 + "_LLMass").Data(), Z.M() , event_weight*prescale_weight, 100., 0., 200);
      }
    }
    if(pass_23){
      if(leps[1]->Pt() > 25){
        double prescale_weight  =  (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_23);
	if(PassZMass){
	  FillHist(( triggerslist_23 + "_Nvtx").Data(),  nPV , event_weight*prescale_weight,nbin_npv, bins_npv);
	}
        FillHist(( triggerslist_23 + "_LLMass").Data(), Z.M() , event_weight*prescale_weight, 100., 0., 200);
      }
    }
  }
  
  return;
  

}
void HNL_LeptonFakeRate::GetFakeRateAndPromptRates(AnalyzerParameter param, std::vector<Lepton *> leps,std::vector<bool> blepsT, std::vector<Jet>    jetCollTight, TString label, float event_weight, float isocut){
						      
  if (leps.size()<1) return;
  
  Event ev = GetEvent();
  Particle METv = GetvMET("PuppiT1xyULCorr",param);
  
  if(leps.size()==1)  MakeFakeRatePlots("", label, param,leps,blepsT,  jetCollTight,   event_weight, isocut, METv);

  if(leps.size()==2){
    TString dilep_triggerslist = (leps[0]->LeptonFlavour() == Lepton::MUON) ?   "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v" : "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v";
    if(DataYear==2017) dilep_triggerslist = (leps[0]->LeptonFlavour() == Lepton::MUON) ?   "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_v" : "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v";

    if(DataYear==2018) dilep_triggerslist = (leps[0]->LeptonFlavour() == Lepton::MUON) ?   "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v" : "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v";

    

    if(IsDATA&& !(ev.IsPDForTrigger(dilep_triggerslist, this->DataStream) )) return;
    if(ev.PassTrigger(dilep_triggerslist))    MakePromptRatePlots("", label, param,leps,blepsT,  jetCollTight,   event_weight, isocut, METv);
  }
  return;
}


void HNL_LeptonFakeRate::MakePromptRatePlots(TString label, TString tag,AnalyzerParameter param,  std::vector<Lepton *> leps , std::vector<bool> blepsT , std::vector<Jet> jets,  float event_weight, float isocut, Particle MET){
  
  Event ev = GetEvent();

  if(leps.size() != 2) return;

  Particle Z = (*leps[0]) + (*leps[1]);
  if(leps[0]->Charge() == leps[1]->Charge()) event_weight = -1;

  if(fabs(M_Z - Z.M()) > 10.) return;

  if(blepsT[1]){
    // lep [1] is tag
    int ilep=0;
    float lep_pt = leps[ilep]->Pt();
    float lep_pt_corr =  leps[ilep]->CalcPtCone(leps[ilep]->RelIso(), isocut);
    float lep_eta = fabs(leps[ilep]->Eta());
    if(lep_pt_corr > 2000.) lep_pt_corr = 1999.;

    float lep_jet_ptratio = lep_pt/leps[ilep]->CloseJet_Ptratio();
    
    float weight_ptcorr=event_weight;
    TString L_prefix = "Prompt_Loose"+tag ;
    TString T_prefix = "Prompt_Tight"+tag;

    for(int Tlep = 0 ; Tlep < 2; Tlep++)  {
      TString prefix = (Tlep==0) ? L_prefix : T_prefix;
      if((Tlep==1) && ! (blepsT[ilep])) continue;
      FillHistogram((prefix + "_pt_eta").Data(),      lep_pt,         lep_eta,  weight_ptcorr, "PR_pt", "Eta4");
      FillHistogram((prefix + "_ptcone_eta").Data(),  lep_pt_corr,    lep_eta,  weight_ptcorr, "PR_pt", "Eta4");
      FillHistogram((prefix + "_ptratio_eta").Data(), lep_jet_ptratio,lep_eta,  weight_ptcorr, "PR_pt", "Eta4");
      if(fabs(M_Z - Z.M()) < 5){
	FillHistogram((prefix + "_TZ_pt_eta").Data(), lep_pt, lep_eta,  weight_ptcorr, "PR_pt", "Eta4");
	FillHistogram((prefix + "_TZ_ptcone_eta").Data(), lep_pt_corr, lep_eta,  weight_ptcorr, "PR_pt", "Eta4");
      }
    }
  }
  if(blepsT[0]){
    // lep [0] is tag                                                                                                                                                             
    int ilep=1;
    float lep_pt = leps[ilep]->Pt();
    float lep_pt_corr =  leps[ilep]->CalcPtCone(leps[ilep]->RelIso(), isocut);
    float lep_eta = fabs(leps[ilep]->Eta());
    float lep_jet_ptratio = leps[ilep]->CloseJet_Ptratio();

    if(lep_pt_corr > 2000.) lep_pt_corr = 1999.;
    float weight_ptcorr=event_weight;
    TString L_prefix = "Prompt_Loose"+tag ;
    TString T_prefix = "Prompt_Tight"+tag;

    for(int Tlep = 0 ; Tlep < 2; Tlep++)  {
      TString prefix = (Tlep==0) ? L_prefix : T_prefix;
      if((Tlep==1) && ! (blepsT[ilep])) continue;
      FillHistogram((prefix + "_pt_eta").Data(), lep_pt, lep_eta,  weight_ptcorr, "PR_pt", "Eta4");
      FillHistogram((prefix + "_ptcone_eta").Data(), lep_pt_corr, lep_eta,  weight_ptcorr, "PR_pt", "Eta4");
      FillHistogram((prefix + "_ptratio_eta").Data(), lep_jet_ptratio, lep_eta,  weight_ptcorr, "PR_pt", "Eta4");
      if(fabs(M_Z - Z.M()) < 5){
	FillHistogram((prefix + "_TZ_pt_eta").Data(), lep_pt, lep_eta,  weight_ptcorr, "PR_pt", "Eta4");
        FillHistogram((prefix + "_TZ_ptcone_eta").Data(), lep_pt_corr, lep_eta,  weight_ptcorr, "PR_pt", "Eta4");
      }
    }
  }


  return;
}


float HNL_LeptonFakeRate::GetPrescale(std::vector<Lepton *>   leps  ){

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
  
    double NVxt_Mu3 =  ApplyNvtxReweight(nPV,triggerslist_3);
    double NVxt_Mu8 =  ApplyNvtxReweight(nPV,triggerslist_8);
    double NVxt_Mu17 =  ApplyNvtxReweight(nPV,triggerslist_17);

    /// 10 - 20  HLT_Mu7
    /// 20 - INF  HLT_Mu17
    
    if(leps.at(0)->Pt() >= 20.){
      if(pass_17) prescale_trigger = (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_17)*NVxt_Mu17;
      else return 0;
    }
    else  if(leps.at(0)->Pt() >= 10.){

      if(pass_8)prescale_trigger =  (IsDATA) ? 1. :   ev.GetTriggerLumi(triggerslist_8)*NVxt_Mu8 ; //// 20 + GeV bins
      else return 0;
    }
    else  if(leps.at(0)->Pt() >= 5.){
      if(pass_3)prescale_trigger =  (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_3)*NVxt_Mu3 ; //// 20 + GeV bins                                                                             
      else return 0 ;
    }      
    else return 0 ;

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

    double NVxt_El8 =  ApplyNvtxReweight(nPV,triggerslist_8);
    double NVxt_El12 =  ApplyNvtxReweight(nPV,triggerslist_12);
    double NVxt_El23 =  ApplyNvtxReweight(nPV,triggerslist_23);

 
    if(leps.at(0)->Pt() >= 25.){
      if(pass_23)prescale_trigger = (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_23)*NVxt_El23;
      else return 0;
    }
    else   if(leps.at(0)->Pt() >= 20.){
      if(pass_17)prescale_trigger = (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_17)*NVxt_El12;
      else return 0;
    }
    else   if(leps.at(0)->Pt() >= 15.){
      if(pass_12) prescale_trigger = (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_12)*NVxt_El12;
      else return 0;
    }
    else   if(leps.at(0)->Pt() >= 9.5){
      if(pass_8) prescale_trigger = (IsDATA) ? 1. : ev.GetTriggerLumi(triggerslist_8)*NVxt_El8;
      else return 0;
    }
    else prescale_trigger = 0.;
    if(prescale_trigger == 0.) return 0.;
    if(leps.at(0)->Pt() < 9.5) return 0.;
    return prescale_trigger;

  }
  
  return prescale_trigger;
}
 

void HNL_LeptonFakeRate::MakeFakeRatePlots(TString label, TString mutag,AnalyzerParameter param,  std::vector<Lepton *> leps , std::vector<bool> blepsT ,  std::vector<Jet> jets,  float event_weight, float isocut, Particle MET){
				
  /// FOR FAKE RATE SUBTRACTION NEED ONLY PROMPT MUONS                                                                                                                                                  
  bool truth_match= true;

  if(!IsDATA && leps.size() > 0) truth_match = leps[0]->IsPrompt() ;

  if(!truth_match) return;

  double prescale_lep = GetPrescale(leps);
  if(prescale_lep == 0) return;
  event_weight*= prescale_lep;


  bool useevent20 = UseEvent(leps , jets, 20.,  MET, event_weight);
  bool useevent30 = UseEvent(leps , jets, 30.,  MET, event_weight);
  bool useevent40 = UseEvent(leps , jets, 40.,  MET, event_weight);
  bool useevent60 = UseEvent(leps , jets, 60.,  MET, event_weight);


  label= mutag;
  if(jets.size() >= 1){
    if(useevent40){

      double MVACut = 0.72;
      if(GetYearString() == "2017" || GetYearString() =="2018") MVACut = 0.64;
      double PtPartonUncorr = leps[0]->PtParton(1,MVACut,MVACut);

      FillProf((param.Name + "_FakeCR40_MVA_PtPartonUncorr").Data(), leps[0]->HNL_MVA_Fake("HFTop"), PtPartonUncorr, event_weight, 200, -1, 1);
      FillProf((param.Name + "_FakeCR40_MVA_"+leps[0]->etaRegionString()+"_PtPartonUncorr").Data(), leps[0]->HNL_MVA_Fake("HFTop"), PtPartonUncorr, event_weight, 200, -1, 1);
      
      GetFakeRates("Pt",leps, blepsT, param, label, jets,        label+"_AJ40",(event_weight),isocut);
      GetFakeRates("PtCorr",leps, blepsT, param, label, jets,    label+"_AJ40",(event_weight),isocut);
      GetFakeRates("PtParton",leps, blepsT, param, label, jets,  label+"_AJ40",(event_weight),isocut);
      GetFakeRates("MotherPt",leps, blepsT, param, label, jets,  label+"_AJ40",(event_weight),isocut);
    }
  }
  return;
}


bool HNL_LeptonFakeRate::UseEvent(std::vector<Lepton *> leps ,  std::vector< Jet> jets, float awayjetcut, Particle MET, float wt){

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
	  if( (jets.at(ij).ChargedEmEnergyFraction()) > 0.65)  continue;

          if(dphi > 2.5){
            if((jets.at(ij).Pt() /  leps.at(ielT)->Pt() ) < 1.2) continue;
            useevent = true;
          }
	}
      }
    }
  }

  return useevent;

}


void HNL_LeptonFakeRate::GetFakeRates(TString Method, std::vector<Lepton *> leps,std::vector<bool> blepsT,  AnalyzerParameter param,TString tightlabel,  std::vector<Jet> jets,  TString tag,float event_weight, float isocut){
					 
  /// METHOD 1  Pt vs Eta

  bool IsMuon=(leps[0]->LeptonFlavour() == Lepton::MUON);

  double MVACut = 0.72;
  if(GetYearString() == "2017" || GetYearString() =="2018") MVACut = 0.64;


  Event ev = GetEvent();

  float lep_pt (0);
  float lep_pt_LF (0);
  float lep_pt_HF (0);

  int Pt_Bin = 0;
  if(IsMuon){
    if(leps.at(0)->Pt() < 10) Pt_Bin = 1;
    else  if(leps.at(0)->Pt() < 20) Pt_Bin = 2;
    else Pt_Bin = 3;
  }

  float weight_ptcorr=event_weight;
  TString MVAKey = "HFTop";
  if(!IsMuon) MVAKey = "EDv5";
  if(Method == "Pt"){
    lep_pt      =  (leps[0]->Pt() < 80) ?  leps[0]->Pt() : 79;
    lep_pt_LF   =  (leps[0]->Pt() < 60) ?  leps[0]->Pt() : 59;
    lep_pt_HF   =  (leps[0]->Pt() < 50) ?  leps[0]->Pt() : 49;
  }
  if(Method == "PtParton"){
    
    double PTPartonSF =1;
    /// 2017 
    if(DataYear == 2017){
      if(leps[0].etaRegionString() == "EB1")  PTPartonSF = 0.727;
      if(leps[0].etaRegionString() == "EB2")  PTPartonSF = 0.729;
      if(leps[0].etaRegionString() == "EE1")  PTPartonSF = 0.727;
      if(leps[0].etaRegionString() == "EE2")  PTPartonSF = 0.717;
    }
    
    lep_pt      =  (leps[0]->PtParton(PTPartonSF, MVACut,MVACut) < 80) ?  leps[0]->PtParton(PTPartonSF, MVACut,MVACut) : 79;
    lep_pt_LF   =  (lep_pt < 60) ?  lep_pt : 59;
    lep_pt_HF   =  (lep_pt < 50) ?  lep_pt : 49;
    if(lep_pt > 30){
      if(leps[0]->Pt() < 20) return;
    }
    else if(lep_pt > 15){
      if( leps[0]->Pt() < 10) return;
    }
    else if(lep_pt > 5){
      if( leps[0]->Pt() < 5) return;
    }
    else return ;

  }
  if(Method == "PtCorr"){
    lep_pt      = (leps[0]->CalcMVACone(leps[0]->HNL_MVA_Fake(MVAKey), MVACut)  < 80) ? leps[0]->CalcMVACone(leps[0]->HNL_MVA_Fake(MVAKey), MVACut)  : 79;
    lep_pt_LF   =  (lep_pt < 60) ?  lep_pt : 59;
    lep_pt_HF   =  (lep_pt < 50) ?  lep_pt : 49;
    if(lep_pt > 30){
      if(leps[0]->Pt() < 20) return;
    }
    else if(lep_pt > 15){
      if( leps[0]->Pt() < 10) return;
    }
    else if(lep_pt > 5){
      if( leps[0]->Pt() < 5) return;
    }
    else return ;
    
  }
  if(Method == "MotherPt"){
    lep_pt      = leps[0]->MotherJetPt();
    lep_pt_LF   =  (lep_pt < 60) ?  lep_pt : 59;
    lep_pt_HF   =  (lep_pt < 50) ?  lep_pt : 49;
    // Muon
    if(lep_pt > 30){
      if(leps[0]->Pt() < 20) return;
    }
    else if(lep_pt > 15){
      if( leps[0]->Pt() < 10) return;
    }
    else if(lep_pt > 5){
      if( leps[0]->Pt() < 5) return;
    }
    else return;
  }

  TString Ptlab = "p_{T} (GeV)";
  if(Pt_Bin==1) FillHistogram((Method+"_PtBin1_pt").Data(), lep_pt,  weight_ptcorr, "Pt", Ptlab);
  if(Pt_Bin==2) FillHistogram((Method+"_PtBin2_pt").Data(), lep_pt,  weight_ptcorr, "Pt", Ptlab);
  if(Pt_Bin==3) FillHistogram((Method+"_PtBin3_pt").Data(), lep_pt,  weight_ptcorr, "Pt", Ptlab);
  

  float lep_eta     = leps[0]->fEta(); /// returns |eta| OR for el |scEta|
  float lep_reliso  = leps[0]->RelIso();
  float lep_mva_lfvshf  = leps[0]->HNL_MVA_Fake("QCD_LFvsHF_v5");
  float lep_mva_bvsc    = leps[0]->HNL_MVA_Fake("QCD_BvsC_v5");
  float lep_blscore     = leps[0]->CloseJet_BScore();
  float lep_cbscore     = leps[0]->CloseJet_CvsBScore();
  float lep_clscore     = leps[0]->CloseJet_CvsLScore();
  TString lepEtaRegion  = leps[0]->etaRegionString();
  TString lepRegion     = (leps[0]->IsBB()) ? "BB" : "EC";

  TString L_prefix = "Fake_"+Method+"_Loose"+tag;
  TString T_prefix = "Fake_"+Method+"_Tight"+tag;

  for(int ilep = 0 ; ilep < 2; ilep++)  {

    TString prefix = (ilep==0) ? L_prefix : T_prefix;
    if((ilep==1) && !(blepsT[0])) continue;
    
    prefix = Method + "/"+prefix;

    if(lep_pt >10){
      
      FillHistogram((prefix + "_pt").Data(),                 lep_pt,  weight_ptcorr, "FR_"+leps[0]->GetFlavour()+"_pt", Ptlab);
      FillHistogram((prefix + "_pt_"+ lepEtaRegion).Data(),  lep_pt,  weight_ptcorr, "FR_"+leps[0]->GetFlavour()+"_pt", Ptlab);
      FillHistogram((prefix + "_pt_"+ lepRegion).Data(),     lep_pt,  weight_ptcorr, "FR_"+leps[0]->GetFlavour()+"_pt", Ptlab);
      FillHistogram((prefix + "_eta").Data(),                lep_eta, weight_ptcorr ,"FR_eta","#eta");
      FillHist((prefix + "_eta_fine").Data(),           lep_eta, weight_ptcorr , 50, 0, 2.5,"#eta");
      FillHist((prefix + "_lep_mva_lfvshf").Data(),   lep_mva_lfvshf,  weight_ptcorr, 50, -1., 1.);
      FillHist((prefix + "_lep_mva_bvsc").Data(),   lep_mva_bvsc,  weight_ptcorr, 50, -1., 1.);
      FillHist((prefix + "_blscore").Data(), lep_blscore,    weight_ptcorr, 50, -1., 1.);
      FillHist((prefix + "_cbscore").Data(), lep_cbscore,    weight_ptcorr, 50, -1., 1.);
      FillHist((prefix + "_clscore").Data(), lep_clscore,    weight_ptcorr, 50, -1., 1.);

      if(lep_mva_lfvshf > 0.8){
	FillHistogram((prefix + "_LF_pt").Data(),                 lep_pt_LF,  weight_ptcorr, "FR_"+leps[0]->GetFlavour()+"_pt", Ptlab);
	FillHistogram((prefix + "_LF_pt_"+ lepEtaRegion).Data(),  lep_pt_LF,  weight_ptcorr, "FR_"+leps[0]->GetFlavour()+"_pt", Ptlab);
	FillHistogram((prefix + "_LF_pt_"+ lepRegion).Data(),     lep_pt_LF,  weight_ptcorr, "FR_"+leps[0]->GetFlavour()+"_pt", Ptlab);
	FillHistogram((prefix + "_LF_eta").Data(),                lep_eta, weight_ptcorr ,"FR_eta","#eta");
	FillHist((prefix + "_LF_eta_fine").Data(),           lep_eta, weight_ptcorr , 50, 0, 2.5,"#eta");
      }
      else{
	if(lep_mva_bvsc > 0.6){
	  FillHistogram((prefix + "_HF1_pt").Data(),                 lep_pt_HF,   weight_ptcorr,        "FR_"+leps[0]->GetFlavour()+"_pt", Ptlab);
	  FillHistogram((prefix + "_HF1_pt_"+ lepEtaRegion).Data(),  lep_pt_HF,  weight_ptcorr, "FR_"+leps[0]->GetFlavour()+"_pt", Ptlab);
	  FillHistogram((prefix + "_HF1_pt_"+ lepRegion).Data(),     lep_pt_HF,  weight_ptcorr, "FR_"+leps[0]->GetFlavour()+"_pt", Ptlab);
	  FillHistogram((prefix + "_HF1_eta").Data(),    lep_eta,             weight_ptcorr ,"FR_eta","#eta");
	  FillHist((prefix + "_HF1_eta_fine").Data(),    lep_eta, weight_ptcorr , 50, 0, 2.5,"#eta");
	}
	else if(lep_mva_bvsc > -0.4){
          FillHistogram((prefix + "_HF2_pt").Data(),                 lep_pt_HF,   weight_ptcorr,        "FR_"+leps[0]->GetFlavour()+"_pt", Ptlab);
          FillHistogram((prefix + "_HF2_pt_"+ lepEtaRegion).Data(),  lep_pt_HF,  weight_ptcorr, "FR_"+leps[0]->GetFlavour()+"_pt", Ptlab);
          FillHistogram((prefix + "_HF2_pt_"+ lepRegion).Data(),     lep_pt_HF,  weight_ptcorr, "FR_"+leps[0]->GetFlavour()+"_pt", Ptlab);
          FillHistogram((prefix + "_HF2_eta").Data(),    lep_eta,             weight_ptcorr ,"FR_eta","#eta");
          FillHist((prefix + "_HF2_eta_fine").Data(),    lep_eta, weight_ptcorr , 50, 0, 2.5,"#eta");
	}
	else{
	  FillHistogram((prefix + "_HF3_pt").Data(),                 lep_pt_HF,   weight_ptcorr,        "FR_"+leps[0]->GetFlavour()+"_pt", Ptlab);
	  FillHistogram((prefix + "_HF3_pt_"+ lepEtaRegion).Data(),  lep_pt_HF,  weight_ptcorr, "FR_"+leps[0]->GetFlavour()+"_pt", Ptlab);
	  FillHistogram((prefix + "_HF3_pt_"+ lepRegion).Data(),     lep_pt_HF,  weight_ptcorr, "FR_"+leps[0]->GetFlavour()+"_pt", Ptlab);
	  FillHistogram((prefix + "_HF3_eta").Data(),    lep_eta,             weight_ptcorr ,"FR_eta","#eta");
	  FillHist((prefix + "_HF3_eta_fine").Data(),    lep_eta, weight_ptcorr , 50, 0, 2.5,"#eta");
	}
      }
    }
  }
  return;
}


HNL_LeptonFakeRate::HNL_LeptonFakeRate(){
  
}
 
HNL_LeptonFakeRate::~HNL_LeptonFakeRate(){

  //  delete NvtxSFFile;
  //for(std::map< TString, TH1D* >::iterator mapit = maphist_NvtxSF.begin(); mapit!=maphist_NvtxSF.end(); mapit++){
  //  delete mapit->second;
  // }
  //maphist_NvtxSF.clear();

}

void HNL_LeptonFakeRate::FillRegionPlots( TString plot_dir, TString region,  std::vector<Jet> jets,  std::vector<Electron> els, std::vector<Muon> mus, Particle  met,  double w){
  
  if((els.size()+ mus.size()) != 1) return;
  Lepton lep1;
  if(els.size()==1) lep1=els[0];
  else lep1 = mus[0];

  FillHistogram( plot_dir +  "/RegionPlots_"+ region+ "/Lep1_binned_pt", lep1.Pt()  , w, "FR_pt","p_{T} GeV");
  FillHist( plot_dir +  "/RegionPlots_"+ region+ "/Lep1_pt", lep1.Pt()  , w, 400, 0., 2000.,"p_{T} GeV");
  FillHist( plot_dir +  "/RegionPlots_"+ region+ "/Lep1_eta", lep1.Eta()  , w, 30, -3., 3,"#eta");
  FillHist( plot_dir +  "/RegionPlots_"+ region+ "/Lep1_CloseJet_Ptrel", lep1.CloseJet_Ptrel(), w, 50., 0., 2.,"PtRel");
  FillHist( plot_dir +  "/RegionPlots_"+ region+ "/Lep1_CloseJet_Ptratio", lep1.CloseJet_Ptratio(), w, 50., 0., 2.,"PtRel");

  FillHist( plot_dir +  "/RegionPlots_"+ region+ "/Met", met.Pt()  , w, 200, 0., 400.,"MET GeV");
  FillHist( plot_dir +  "/RegionPlots_"+ region+ "/MetPhi", met.Phi()  , w, 100, -5, 5,"MET GeV");
  FillHist( plot_dir +  "/RegionPlots_"+ region+ "/njets" , jets.size() , w, 5, 0., 5., "N_{jets}");

  float lep_reliso  = lep1.RelIso();
  float lep_minireliso  = lep1.MiniRelIso();
  float lep_ip3d    = fabs(lep1.IP3D()/lep1.IP3Derr());
  float lep_mva     =  lep1.LepMVA();
  float lep_dxy     = fabs(lep1.dXY());

  if(els.size() > 0)   FillHist( plot_dir +  "/RegionPlots_"+ region+ "/NMissingHits", els[0].NMissingHits(), w, 5, 0., 5.);


  FillHist( plot_dir +  "/RegionPlots_"+ region+ "/Reliso", lep_reliso, w, 50, 0., 1.);
  FillHist( plot_dir +  "/RegionPlots_"+ region+ "/MiniReliso", lep_minireliso, w, 50, 0., 1.);
  FillHist( plot_dir +  "/RegionPlots_"+ region+ "/dXY",    lep_dxy, w, 100, 0., 0.5);
  FillHist( plot_dir +  "/RegionPlots_"+ region+ "/IP3D",   lep_ip3d, w, 50, 0., 10.);
  FillHist( plot_dir +  "/RegionPlots_"+ region+ "/Mva",    lep_mva, w, 50, -1., 1.);



  double lep_jet_ratio= 0.;
  double jet_CEEF = 0.;  double jet_CHEF = 0.;
  for(unsigned int ij=0; ij < jets.size(); ij++){
    if(jets.at(ij).Pt() < 40.) continue;
    float dphi =fabs(TVector2::Phi_mpi_pi(lep1.Phi()- jets.at(ij).Phi()));
    if(dphi > 2.5){
      lep_jet_ratio = jets.at(ij).Pt() /  lep1.Pt();
      jet_CEEF = jets.at(ij).ChargedEmEnergyFraction();
      jet_CHEF = jets.at(ij).ChargedHadEnergyFraction();
    }
  }
  
  FillHist( plot_dir +  "/RegionPlots_"+ region+ "/JetLepPtRatio" , lep_jet_ratio  , w, 50, 0., 5.,"P^{jet}_{T} / P^{lepton}_{T}");
  FillHist( plot_dir +  "/RegionPlots_"+ region+ "/AwayJetChargedEMEnergyFraction" , jet_CEEF  , w, 50, 0., 2.,"Jet charged EMF");
  FillHist( plot_dir +  "/RegionPlots_"+ region+ "/AwayJetChargedHadEnergyFraction" , jet_CHEF  , w, 50, 0., 2.,"Jet charged EMF");
  


  double METdphi = TVector2::Phi_mpi_pi(lep1.Phi()-met.Phi());
  double MT = sqrt(2.* lep1.Et()*met.Pt() * (1 - cos( METdphi)));
  
  FillHist( plot_dir +  "/RegionPlots_"+ region+ "/Mt" , MT  , w, 40, 0., 200.,"MET GeV");
  
}


void HNL_LeptonFakeRate::FillEventCutflow(int charge_i, int cf,float wt, TString cut,   TString label){


  return;

}

void HNL_LeptonFakeRate::FillWeightHist(TString label, double _weight){
  FillHist( "weights/"+ label , _weight ,1., 200, 0., 5,"ev weight");
}
void HNL_LeptonFakeRate::FillCutFlow(bool IsCentral, TString suffix, TString histname, double weight){

  if(IsCentral){

    FillHist(suffix+"/"+histname, 0., weight, 1, 0., 1.);

  }

}

