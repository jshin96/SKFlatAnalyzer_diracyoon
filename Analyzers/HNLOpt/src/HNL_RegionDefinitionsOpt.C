#include "HNL_RegionDefinitionsOpt.h"


/*


  Analysis REGION Functions 
  -----------------------------------                                                                                                                   a) RunPreslection
  b) PassVBFInitial : Use this IF using shape for SR2 
  c) PassVBF

  SR Functions
  -----------------------------------
  1- RunSignalRegionAK8 (SR1)
  2- RunSignalRegionWW  (SR2)
  3- RunSignalRegionAK4 (SR3)
  4- RunSignalRegionTrilepton  (REMNANT)


  CR Functions
  -----------------------------------
  1- RunElectronChannelCR
  2- RunMuonChannelCR

 */





void HNL_RegionDefinitionsOpt::RunAllSignalRegions(HNL_LeptonCore::ChargeType qq, 
						   std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Tau> TauColl,
						   std::vector<Jet> AllJetColl ,  std::vector<Jet> JetCollLoose,std::vector<Jet> JetColl, std::vector<Jet> VBF_JetColl,std::vector<FatJet>  AK8_JetColl, 
						   std::vector<Jet> B_JetColl,std::vector<Jet> B_JetCollSR1, 
						   Event ev,   Particle METv, AnalyzerParameter param,   float weight_ll){


  // Only opt for EE/MM
  vector<HNL_LeptonCore::Channel> channels = {EE,MuMu};

  for(auto dilep_channel : channels){
    
    if(run_Debug) cout << "HNL_RegionDefinitionsOpt::RunAllSignalRegions " << GetChannelString(dilep_channel) <<  endl;
    
    if(param.Name.Contains("HNTightV2"))OutCutFlow(param.Name+"_"+GetChannelString(dilep_channel)+"_pre", weight_ll);

    float weight_channel = weight_ll;
    
    /// SelectChannel separates OS/SS samples and EE/MM since signales have all processes in sample
    if(MCSample.Contains("Type")&& !SelectChannel(dilep_channel)) continue;
 
    if (param.Name.Contains("MuOpt") && dilep_channel != MuMu) continue;
    if (param.Name.Contains("ElOpt") && dilep_channel != EE) continue;

    if(run_Debug)cout << "ID Mu  " << param.Muon_Tight_ID << " " << param.Muon_FR_ID << endl;
    if(run_Debug)cout << "ID El  " << param.Electron_Tight_ID << " " << param.Electron_FR_ID << endl;

    if(run_Debug)cout << "ParamName = " << param.Name << endl;
    std::vector<Lepton *> leps       = MakeLeptonPointerVector(muons,electrons,param);
    

    TString channel_string = GetChannelString(dilep_channel);
    // Make channel speciific AnalyzerParameter                                                                                                                                                                   
    AnalyzerParameter param_channel = param;

    param_channel.Name =  channel_string + "/" + param_channel.Name;
    FillEventCutflow(HNL_LeptonCore::ChannelDepInc, weight_channel, GetChannelString(dilep_channel) +"_NoCut", "ChannelCutFlow/"+param_channel.Name,param.WriteOutVerbose);//DEf                                                                    

    //PassEventTypeFilter filters out events in MC if runconv and no conversion is present and vice versa
    if(!PassGenMatchFilter(leps, param_channel)) continue;

    // CheckLeptonFlavourForChannel checks 2 leptons of type according rto dilep_channel are present in event and passes Trigger looses cuts
    if(!CheckLeptonFlavourForChannel(dilep_channel, leps)) continue;


    /// Weight MC based on corr
    if(!IsDATA && dilep_channel != MuMu)  weight_channel*= GetElectronSFEventWeight(electrons, param_channel);
    if(!IsDATA && dilep_channel != EE)    weight_channel*= GetMuonSFEventWeight(muons, param_channel);

    if(!PassMETFilter()) return;
   
    std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto,param);
    
    if(leps.size() ==2)  FillEventCutflow(HNL_LeptonCore::ChannelDepDilep, weight_channel, GetChannelString(dilep_channel) +"_Dilep", "ChannelCutFlow/"+param_channel.Name,param.WriteOutVerbose);//Def
    

    if(RunCF){
      if(dilep_channel == MuMu) continue;
      if(IsData && SameCharge(leps)) continue;
      if(!IsData && !SameCharge(leps)) continue;
      if(IsData)weight_channel = GetCFWeightElectron(leps, param_channel);
      if(IsData)FillWeightHist(param.Name+"/CFWeight",weight_channel);
    }
    else{
      if(!SameCharge(leps)) continue;
    }

    if(RunFake&& IsData){
      
      if(run_Debug)cout << "ID2 Mu  " << param_channel.Muon_Tight_ID << " " << param_channel.Muon_FR_ID << endl;
      if(run_Debug)cout << "ID2 El  " << param_channel.Electron_Tight_ID << " " << param_channel.Electron_FR_ID << endl;

      weight_channel = GetFakeWeight(leps, param_channel, false);

      if(run_Debug)cout << "Fake " << weight_channel << endl;
      FillWeightHist(param_channel.Name+"/FakeWeight",weight_channel);
    }
    
    // Run PRESEL + SR1-3                                                                                                                                                           
    //bool run_ORTrigger = false;


    HNL_LeptonCore::SearchRegion LimitRegions = HNL_LeptonCore::MuonSR;
    if (dilep_channel == EE) LimitRegions =HNL_LeptonCore::ElectronSR;
    if (dilep_channel == EMu) LimitRegions =HNL_LeptonCore::ElectronMuonSR;

    //HNL_LeptonCore::SearchRegion LimitRegionsQ = HNL_LeptonCore::MuonSRQQ;
    //if (dilep_channel == EE) LimitRegionsQ =HNL_LeptonCore::ElectronSRQQ;
    //if (dilep_channel == EMu) LimitRegionsQ =HNL_LeptonCore::ElectronMuonSRQQ;

    HNL_LeptonCore::SearchRegion LimitRegionsBDT = HNL_LeptonCore::MuonSRBDT;
    if (dilep_channel == EE) LimitRegionsBDT =HNL_LeptonCore::ElectronSRBDT;
    if (dilep_channel == EMu) LimitRegionsBDT =HNL_LeptonCore::ElectronMuonSRBDT;

    

    if(!PassPreselection(dilep_channel,qq, leps, leps_veto, TauColl, JetColl, VBF_JetColl, AK8_JetColl, B_JetColl,ev, METv ,param_channel,"", weight_channel)) continue;

 
    //FillAllMuonPlots("Presel", "Muons"  , muons ,weight_channel);
    //FillAllElectronPlots("Presel", "Electrons"  , electrons ,weight_channel);
    
    TString  lep_charge =  (leps[0]->Charge() < 0)  ? "QM" :  "QP";

    if(AK8_JetColl.size() > 0) {
      TString SRbin= RunSignalRegionAK8String (dilep_channel,qq, leps, leps_veto, TauColl, JetColl, AK8_JetColl, B_JetCollSR1,ev, METv ,param_channel,"", weight_channel) ;
      
      if(SRbin != "false") FillEventCutflow(LimitRegions, weight_channel, SRbin,"LimitInput/"+param.Name);
      if(SRbin != "false") FillEventCutflow(LimitRegionsBDT, weight_channel, SRbin,"LimitInputBDT/"+param.Name+"/100");
      if(SRbin != "false") FillEventCutflow(LimitRegionsBDT, weight_channel, SRbin,"LimitInputBDT/"+param.Name+"/400");
    }
    else{
      
      TString SRbin = RunSignalRegionWWString( dilep_channel,qq, leps, leps_veto,  TauColl, JetCollLoose, VBF_JetColl,  AK8_JetColl, B_JetColl,ev, METv, param_channel,  "", weight_channel);
            
      if(SRbin != "false"){
	FillEventCutflow(LimitRegions, weight_channel, SRbin,"LimitInput/"+param.Name);
	FillEventCutflow(LimitRegionsBDT, weight_channel, SRbin,"LimitInputBDT/"+param.Name+"/100");
	FillEventCutflow(LimitRegionsBDT, weight_channel, SRbin,"LimitInputBDT/"+param.Name+"/400");
      }
      else{

	SRbin  = RunSignalRegionAK4String (dilep_channel,qq, leps, leps_veto, TauColl, JetColl, AK8_JetColl, B_JetColl, ev, METv ,param_channel,"", weight_channel);

	TString SRBDT100 = RunSignalRegionAK4StringBDT("100", dilep_channel, leps, ev);   
	TString SRBDT400 = RunSignalRegionAK4StringBDT("400", dilep_channel, leps, ev);   
	/*
	  // TEST ev.HNL_MVA_Event is consistent with SetupEventBDTVariables 
	SetupEventBDTVariables(leps,
			       AllJetColl, JetColl,VBF_JetColl,B_JetColl,
			       ev,METv,param);

	TString MVATagStr = "BDT_M100_NCut300_NTree850_"+GetChannelString(dilep_channel);
	float MVAvalue = 0.;
	if(GetChannelString(dilep_channel) == "MuMu") MVAvalue = MVAReaderMM->EvaluateMVA(MVATagStr);
	if(GetChannelString(dilep_channel) == "EE")   MVAvalue = MVAReaderEE->EvaluateMVA(MVATagStr);
	if(GetChannelString(dilep_channel) == "EMu")  MVAvalue = MVAReaderEM->EvaluateMVA(MVATagStr);
	
	if(MVAvalue != ev.HNL_MVA_Event(GetChannelString(dilep_channel)+"_100")){
	  cout << "Summary of BDT 100"<< endl;
	  cout << "MVAvalue = " << MVAvalue << endl;
	  cout << "Predetermined value = " << ev.HNL_MVA_Event(GetChannelString(dilep_channel)+"_100") << endl;
	}

	*/

	if(SRBDT100 != "false") FillEventCutflow(LimitRegionsBDT, weight_channel, SRBDT100,"LimitInputBDT/"+param.Name+"/100");
	if(SRBDT400 != "false") FillEventCutflow(LimitRegionsBDT, weight_channel, SRBDT400,"LimitInputBDT/"+param.Name+"/400");
	if(SRbin != "false")  FillEventCutflow(LimitRegions, weight_channel, SRbin,"LimitInput/"+param.Name);

      }
    }
  }
  return;
}




bool  HNL_RegionDefinitionsOpt::PassPreselection(HNL_LeptonCore::Channel channel,HNL_LeptonCore::ChargeType qq, std::vector<Lepton *> leps,std::vector<Lepton *> leps_veto, vector<Tau> TauColl,  std::vector<Jet> JetColl, std::vector<Jet> VBF_JetColl,std::vector<FatJet>  AK8_JetColl, std::vector<Jet> B_JetColl, Event ev, Particle METv, AnalyzerParameter param, TString TriggerOption ,  float w){

  // ONLY CODE SS PRESLECTION 
  
  // APPLY PT CUTS
  /*
    ee channel 25/10
    emu   25/5
    mm    20/5
    
    THIS IS APPLIED IN PassTriggerSelection
    
   */
  
  if(run_Debug) cout << "HNL_RegionDefinitionsOpt::PassPreselection " << GetChannelString(channel) <<  endl;

  // Make sure events contain 2 leps                                                                                                       
  // Make sure correct leptons are used                                                                                                                                      

  if (! (  PassMultiTriggerSelection(channel, ev, leps,"Dilep", "HighPt") || PassMultiTriggerSelection(channel, ev, leps,"Dilep", "Lep"))) return false;
  
  FillEventCutflow(HNL_LeptonCore::ChannelDepTrigger, w, GetChannelString(channel) +"_MultiTrigger", "ChannelCutFlow/"+param.Name,param.WriteOutVerbose);//Def
  
  if(param.SRConfig.Contains("Trig1OR")){
    if( !(PassMultiTriggerSelection(channel, ev, leps,"Dilep","HighPt")))  return false;
  }
  else if(param.SRConfig.Contains("Trig2OR")){
    if(!(PassMultiTriggerSelection(channel, ev, leps,"Dilep","Lep")))  return false;
  }
  else if(param.SRConfig.Contains("Trig3OR")){
    if( !((PassMultiTriggerSelection(channel, ev, leps,"Dilep","Lep")) || PassMultiTriggerSelection(channel, ev, leps,"Dilep", "HighPt"))) return false;
  }
  else      if (!PassTriggerSelection(channel, ev, leps,"Dilep")) return false;
  
  w *= HNLZvtxSF(channel);

  
  FillEventCutflow(HNL_LeptonCore::ChannelDepTrigger, w, GetChannelString(channel) +"_Trigger", "ChannelCutFlow/"+param.Name,param.WriteOutVerbose);//Def


  if(run_Debug) cout << "HNL_RegionDefinitionsOpt::PassTriggerSelection " << GetChannelString(channel) <<  endl;

  
  int nel_hem(0);
  if (channel==EE){
    if (DataEra=="2018"){
      for(auto iel : leps){
	if (iel->Eta() < -1.25){
          if((iel->Phi() < -0.82) && (iel->Phi() > -1.62)) nel_hem++;
	}
      }
    }
  }

  if(nel_hem > 0) return false;


  // Make sure events contain 2 leps
  if (leps_veto.size() != 2) return false;

  
  // CUT ON MASS OF LL PAIR

  Particle ll =  (*leps[0]) + (*leps[1]);
  
  // VETO Z PEAK IN EE CHANNEL
  if (channel==EE  && (fabs(ll.M()-90.) < 15)) return false;

  if(ll.M() < 10) return false; // TO_CHECK: IS 20 BEST OPTION

  // REMOVE 0 Jet EVENTS
  //int njets     = JetColl.size() + AK8_JetColl.size() + VBF_JetColl.size();
 

  Fill_RegionPlots(channel, 0, param.Name,"Preselection" , TauColl, JetColl, AK8_JetColl, leps,  METv, nPV, w,param.WriteOutVerbose);
  FillEventCutflow(HNL_LeptonCore::ChannelDepPresel, w, GetChannelString(channel) +"_Presel", "ChannelCutFlow/"+param.Name,param.WriteOutVerbose);//Def
  
  return true;
}




bool  HNL_RegionDefinitionsOpt::RunSignalRegionAK8(HNL_LeptonCore::Channel channel, HNL_LeptonCore::ChargeType qq , std::vector<Lepton *> leps, std::vector<Lepton *> leps_veto , std::vector<Tau> TauColl, std::vector<Jet> JetColl, std::vector<FatJet>  AK8_JetColl, std::vector<Jet> B_JetColl, Event ev, Particle METv, AnalyzerParameter param, TString PostLabel ,  float w){


  TString SR1String = RunSignalRegionAK8String(channel, qq, leps, leps_veto, TauColl,JetColl,AK8_JetColl,B_JetColl,ev, METv, param, PostLabel,w);
  
  if(SR1String == "false") return false;
  else return true;
  
}


/// Return TString for Limit bin

TString HNL_RegionDefinitionsOpt::RunSignalRegionAK8String(HNL_LeptonCore::Channel channel, HNL_LeptonCore::ChargeType qq , std::vector<Lepton *> leps, std::vector<Lepton *> leps_veto , std::vector<Tau> TauColl, std::vector<Jet> JetColl, std::vector<FatJet>  AK8_JetColl, std::vector<Jet> B_JetColl, Event ev, Particle METv, AnalyzerParameter param, TString PostLabel ,  float w){


  bool HasTightTau=false;
  for(auto itau: TauColl){
    bool HasTightTau_n=true;
    for (auto ilep : leps) if (ilep->DeltaR(itau) < 0.4) HasTightTau_n=false;
    for (auto ijet : AK8_JetColl) if (ijet.DeltaR(itau) < 1.)  HasTightTau_n=false;
    for (auto ijet : JetColl) if (ijet.DeltaR(itau) < 0.5)  HasTightTau_n=false;
    if(HasTightTau_n) HasTightTau=true;
  }

  FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_Init",param.Name,param.WriteOutVerbose);
  
  if (leps_veto.size() != 2) return "false";
  FillEventCutflow(HNL_LeptonCore::SR1,w, "SR1_lep_pt",param.Name,param.WriteOutVerbose);
  if(AK8_JetColl.size() == 0) return "false";
  
  if(qq==Plus && leps[0]->Charge() < 0) return "false";
  if(qq==Minus && leps[0]->Charge() > 0) return "false";

  FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_lep_charge",param.Name,param.WriteOutVerbose);

  Particle ll =  (*leps[0]) + (*leps[1]);
  if (channel==EE  && (fabs(ll.M()-90.) < 15)) return "false";
  
  FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_dilep_mass",param.Name,param.WriteOutVerbose);

  double ST = GetST(leps, JetColl, AK8_JetColl, METv);
  double HT = GetHT(JetColl, AK8_JetColl);
  double met2_st = pow(METv.Pt(),2.)/ ST;

  double met_cut = 15.;
  if (param.SRConfig.Contains("SR1MET_20_"))   met_cut = 20.;
  if (param.SRConfig.Contains("SR1MET_17_"))   met_cut = 17.;
  if (param.SRConfig.Contains("SR1MET_15_"))   met_cut = 15.;
  if (param.SRConfig.Contains("SR1MET_12_"))   met_cut = 12.;
  if (param.SRConfig.Contains("SR1MET_10_"))   met_cut = 10.;
    
  bool PassHMMet    = (met2_st < met_cut);
  bool PassBJetMVeto = (B_JetColl.size()==0);

  double mass_cut = 500.;

  if (param.SRConfig.Contains("SR1MLLJJ_500_"))   mass_cut = 500.;
  if (param.SRConfig.Contains("SR1MLLJJ_600_"))   mass_cut = 600.;
  if (param.SRConfig.Contains("SR1MLLJJ_700_"))   mass_cut = 700.;
  if (param.SRConfig.Contains("SR1MLLJJ_800_"))   mass_cut = 800.;
  if (param.SRConfig.Contains("SR1MLLJJ_900_"))   mass_cut = 900.;
  if (param.SRConfig.Contains("SR1MLLJJ_1000_"))   mass_cut = 1000.;
 
  double LowerMassSR1WmassCut = mass_cut;
  
  TString signal_region1 = "HNL_SR1";
  
  //double FatJetTau21_SF = GetEventFatJetSF(AK8_JetColl,"ak8_type1", 0);
  //FillWeightHist(param.Name+"/fatjet_ak8_type1_sf_"+param.Name,FatJetTau21_SF);
  //if(!IsData)w*=  FatJetTau21_SF;
  Fill_RegionPlots(channel, 0, param.Name,"InclusiveSR1" , TauColl, JetColl, AK8_JetColl, leps,  METv, nPV, w,param.WriteOutVerbose);
  
  double dPhil2_l = fabs(TVector2::Phi_mpi_pi( ( (AK8_JetColl[0] + *leps[1]).Phi() - (leps[0]->Phi() ))));
  
  double pt_cut = 100.;
  if (param.SRConfig.Contains("SR1PT_80_"))   pt_cut = 80.;
  if (param.SRConfig.Contains("SR1PT_90_"))   pt_cut = 90.;
  if (param.SRConfig.Contains("SR1PT_100_"))   pt_cut = 100.;
  if (param.SRConfig.Contains("SR1PT_110_"))   pt_cut = 110.;
  if (param.SRConfig.Contains("SR1PT_120_"))   pt_cut = 120.;

  
  if(leps[0]->Pt() < pt_cut) return "false";
  FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_LepPt",param.Name,param.WriteOutVerbose);

  double dRl2_l2_cut = 2.;//(GetMass(signal_region1,JetColl, AK8_JetColl,  leps) > 1000) ? 2.5 : 1.5;

  if (dPhil2_l > dRl2_l2_cut){

    FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_DphiN_Wlep",param.Name,param.WriteOutVerbose);
    

    if(!HasTightTau) {
      FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_TauVeto",param.Name,param.WriteOutVerbose);
      
      if( ( HT/leps[0]->Pt()) < 4.) {
	FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_HTPt",param.Name,param.WriteOutVerbose);
	
	
	if(GetMass(signal_region1,JetColl, AK8_JetColl,  leps) > LowerMassSR1WmassCut ){
	  
	  
	  FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_Wmass",param.Name,param.WriteOutVerbose); 
	  if(PassHMMet)FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_MET",param.Name,param.WriteOutVerbose);
	  if(PassHMMet&&PassBJetMVeto)FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_bveto",param.Name,param.WriteOutVerbose);
	  
	  
	  if(PassHMMet&&PassBJetMVeto) {
	    
	    
	    //Fill Limit plot
	    
	    float dijetmass_tmp=999.;
	    float dijetmass=9990000.;
	    
	    int m=-999;
	    for(UInt_t emme=0; emme<AK8_JetColl.size(); emme++){
	      dijetmass_tmp = AK8_JetColl[emme].SDMass();
	      if ( fabs(dijetmass_tmp-80.4) < fabs(dijetmass-80.4) ) {
		dijetmass = dijetmass_tmp;
		m = emme;
	      }
	    }
	    
	    Particle N1cand = AK8_JetColl[m] + *leps[0];
	    
	    double MN1 = (N1cand.M() > 2000.) ? 1999. : N1cand.M();

	    if(channel==MuMu){
	      if(MN1 > 350){
		if(leps[0]->Pt() < 140)   return "false";
		if(leps[1]->Pt() < 65)    return "false";
	      }
	      else   if(MN1 > 280){
		if(leps[0]->Pt() < 140)   return "false";
		if(leps[1]->Pt() < 40)    return "false";
	      }   
	      else if(MN1 > 225){
		if(leps[0]->Pt() < 140)   return "false";
		if(leps[1]->Pt() < 25)    return "false";
	      }   
	      else   if(MN1 > 150){
		if(leps[0]->Pt() < 70)   return "false";
		if(leps[1]->Pt() < 15)    return "false";
	      }   
	    }
	    if(channel==EE || channel==EMu){
              if(MN1 > 635){
                if(leps[0]->Pt() < 140)   return "false";
		if(leps[1]->Pt() < 50)    return "false";
              }
              else   if(MN1 > 550){
                if(leps[0]->Pt() < 120)   return "false";
		if(leps[1]->Pt() < 50)    return "false";
              }
              else if(MN1 > 440){
                if(leps[0]->Pt() < 120)   return "false";
                if(leps[1]->Pt() < 35)    return "false";
              }
              else   if(MN1 > 270){
                if(leps[0]->Pt() < 100)   return "false";
                if(leps[1]->Pt() < 25)    return "false";
              }
	    }   

	    int nSRbins=8;
	    double ml1jbins[nSRbins] = { 0., 200., 400.,500., 600.,700., 1000., 2000.};
	    double Qml1jbins[13] = {-2000., -1000., -500., -300., -200., -100,  0., 100.,200.,300.,500., 1000., 2000.};
	    
	    
	    
	    if(param.WriteOutVerbose == 0)FillHist( "LimitSR1/"+param.Name+"/N1Mass_Central",  MN1,  w, 7, ml1jbins, "Reco M_{l1jj}");
	    if(param.WriteOutVerbose == 0 )FillHist( "LimitSR1/"+param.Name+"/Q_N1Mass_Central",  leps[0]->Charge()*MN1,  w, 12, Qml1jbins, "Reco M_{l1jj}");
	    
	    //Fill_RegionPlots      (channel, true, hist_label+"/SR1/" , "", JetColl, AK8_JetColl, leps,  METv, nPV, w);
	    
	    FillEventCutflow(HNL_LeptonCore::ChannelDepSR1, w, GetChannelString(channel) +"_SR1", "ChannelCutFlow/"+param.Name,param.WriteOutVerbose);//Def
	    
	    for(int ibin=1; ibin < nSRbins; ibin++){
	      if(MN1 < ml1jbins[ibin]) return "SR1_MNbin"+to_string(ibin);
	    }
	    
	    return "true";
	  }
	}
      }
    }
  }
  return "false";
}






TString HNL_RegionDefinitionsOpt::RunSignalRegionAK4StringBDT(TString mN, HNL_LeptonCore::Channel channel, 
							      std::vector<Lepton *> LepTColl,  Event  ev){

  if (LepTColl.size() != 2) return "false";
  Particle ll =  (*LepTColl[0]) + (*LepTColl[1]);
  if (channel==EE  && (fabs(ll.M()-90.) < 10)) return "false";

  float MVAvalue = ev.HNL_MVA_Event(GetChannelString(channel)+"_"+mN);

  if(MVAvalue < 0.)       return "SR3_BDTbin1";
  else if(MVAvalue< 0.05) return "SR3_BDTbin2";
  else if(MVAvalue< 0.10) return "SR3_BDTbin3";
  else if(MVAvalue< 0.15) return "SR3_BDTbin4";
  else if(MVAvalue< 0.175)  return "SR3_BDTbin5";
  else if(MVAvalue< 0.2) return "SR3_BDTbin6";
  else if(MVAvalue< 0.25)  return "SR3_BDTbin7";
  else if(MVAvalue< 0.3) return "SR3_BDTbin8";
  else                    return "SR3_BDTbin9";

  return "true";
}







bool  HNL_RegionDefinitionsOpt::RunSignalRegionWW(HNL_LeptonCore::Channel channel, HNL_LeptonCore::ChargeType qq ,
						  std::vector<Lepton *> leps, std::vector<Lepton *> leps_veto , std::vector<Tau> TauColl, 
						  std::vector<Jet> JetCollLoose, std::vector<Jet> JetColl, std::vector<FatJet>  AK8_JetColl, std::vector<Jet> B_JetColl, 
						  Event ev, Particle METv, AnalyzerParameter param, TString PostLabel ,  float w){

  TString SR2String = RunSignalRegionWWString(channel, qq, leps, leps_veto, TauColl,JetCollLoose, JetColl,AK8_JetColl,B_JetColl,ev, METv, param, PostLabel,w);
  if(SR2String == "false") return false;
  else return true;
  
}



TString HNL_RegionDefinitionsOpt::RunSignalRegionWWString(HNL_LeptonCore::Channel channel, HNL_LeptonCore::ChargeType qq ,
							  std::vector<Lepton *> leps, std::vector<Lepton *> leps_veto , std::vector<Tau> TauColl, 
							  std::vector<Jet> JetCollLoose, std::vector<Jet> JetColl, std::vector<FatJet>  AK8_JetColl, std::vector<Jet> B_JetColl, 
							  Event ev, Particle METv, AnalyzerParameter param, TString PostLabel ,  float w){


  if (leps_veto.size() != 2) return "false";


  if(qq==Plus && leps[0]->Charge() < 0) return "false";
  if(qq==Minus && leps[0]->Charge() > 0) return "false";

  FillEventCutflow(HNL_LeptonCore::SR2,w, "SR2_lep_charge",param.Name,param.WriteOutVerbose);

  FillEventCutflow(HNL_LeptonCore::SR2, w, "SR2_lep_pt",param.Name,param.WriteOutVerbose);

  Fill_RegionPlots(channel, 0, param.Name,"InclusiveSR2" ,  TauColl, JetColl, AK8_JetColl, leps,  METv, nPV, w,param.WriteOutVerbose);

  if (param.SRConfig.Contains("VBFLeadJet")){

    if (param.SRConfig.Contains("MJJ450")){
      if(!PassVBF(JetColl,leps,450., true)) return "false";
    }
    else if (param.SRConfig.Contains("MJJ500")){
      if(!PassVBF(JetColl,leps,500., true)) return "false";
    }   
    else if (param.SRConfig.Contains("MJJ600")){
      if(!PassVBF(JetColl,leps,600., true)) return "false";
    }
    else if (param.SRConfig.Contains("MJJ750")){
      if(!PassVBF(JetColl,leps,750., true)) return "false";
    }
    else if (param.SRConfig.Contains("MJJ800")){
      if(!PassVBF(JetColl,leps,800., true)) return "false";
    }
    else if (param.SRConfig.Contains("MJJ850")){
      if(!PassVBF(JetColl,leps,850., true)) return "false";
    }
    else if (param.SRConfig.Contains("MJJ900")){
      if(!PassVBF(JetColl,leps,900., true)) return "false";
    }
    else if (param.SRConfig.Contains("MJJ1000")){
      if(!PassVBF(JetColl,leps,1000., true)) return "false";
    }
    else if(!PassVBF(JetColl,leps,750., true)) return "false";

  }
  else   if (param.SRConfig.Contains("VBFAwayJet")){

    if (param.SRConfig.Contains("MJJ450")){
      if(!PassVBF(JetColl,leps,450., false)) return "false";
    }   
    else if (param.SRConfig.Contains("MJJ500")){
      if(!PassVBF(JetColl,leps,500., false)) return "false";
    }
    else if (param.SRConfig.Contains("MJJ600")){
      if(!PassVBF(JetColl,leps,600., false)) return "false";
    }
    else if (param.SRConfig.Contains("MJJ750")){
      if(!PassVBF(JetColl,leps,750., false)) return "false";
    }
    else if (param.SRConfig.Contains("MJJ800")){
      if(!PassVBF(JetColl,leps,800., false)) return "false";
    }
    else if (param.SRConfig.Contains("MJJ850")){
      if(!PassVBF(JetColl,leps,850., false)) return "false";
    }

    else if (param.SRConfig.Contains("MJJ900")){
      if(!PassVBF(JetColl,leps,900., false)) return "false";
    }
    else if (param.SRConfig.Contains("MJJ1000")){
      if(!PassVBF(JetColl,leps,1000., false)) return "false";
    }

    else if(!PassVBF(JetColl,leps,750., false)) return "false";
    
  }

  else       if(!PassVBF(JetColl,leps,750., true)) return "false";


  FillEventCutflow(HNL_LeptonCore::SR2, w, "SR2_VBF",param.Name,param.WriteOutVerbose);

  bool PassBJetMVeto = (B_JetColl.size()==0);

  double HT(0.);

  if (param.SRConfig.Contains("LooseJet")){
    for(auto ij : JetCollLoose) HT += ij.Pt();
  }
  else   if (param.SRConfig.Contains("tightJet")){
    for(auto ij : JetColl) HT += ij.Pt();
  }
  else{
    for(auto ij : JetColl) HT += ij.Pt();
  }


  double htltcut = 2.;
  
  if (param.SRConfig.Contains("HTLT10_")) htltcut = 1.;
  if (param.SRConfig.Contains("HTLT11_")) htltcut = 1.1;
  if (param.SRConfig.Contains("HTLT12_")) htltcut = 1.2;
  if (param.SRConfig.Contains("HTLT13_")) htltcut = 1.3;
  if (param.SRConfig.Contains("HTLT14_")) htltcut = 1.4;
  if (param.SRConfig.Contains("HTLT15_")) htltcut = 1.5;
  if (param.SRConfig.Contains("HTLT16_")) htltcut = 1.6;
  if (param.SRConfig.Contains("HTLT17_")) htltcut = 1.7;
  if (param.SRConfig.Contains("HTLT18_")) htltcut = 1.8;
  if (param.SRConfig.Contains("HTLT19_")) htltcut = 1.9;
  if (param.SRConfig.Contains("HTLT20_")) htltcut = 2.;


  double ST = GetST( leps, JetColl, AK8_JetColl, METv);
  double met2_st = pow(METv.Pt(),2.)/ ST;

  double metcut = 12.;
  if (param.SRConfig.Contains("MET15_")) htltcut = 15.;
  if (param.SRConfig.Contains("MET12_")) htltcut = 12.;
  if (param.SRConfig.Contains("MET10_")) htltcut = 10.;

  bool PassHMMet    = (met2_st < metcut); 
  
  if(PassHMMet) {
    FillEventCutflow(HNL_LeptonCore::SR2, w, "SR2_met",param.Name,param.WriteOutVerbose);
    
    if ( (HT/leps[0]->Pt()) < htltcut){
      
      FillEventCutflow(HNL_LeptonCore::SR2, w, "SR2_ht_lt1",param.Name,param.WriteOutVerbose);
      
      if(PassBJetMVeto){
	
	FillEventCutflow(HNL_LeptonCore::SR2, w, "SR2_bveto",param.Name,param.WriteOutVerbose);
	
	double HTLT[3] = { 0.,1., 2};
	double QHTLT[5] = { -2.,-1.,0.,1., 2};
	if(param.WriteOutVerbose == 0)FillHist( "LimitSR2/"+param.Name+"/HT_LT1_Central",  HT/leps[0]->Pt(),  w, 2, HTLT, "Reco HT/LT1");
	if(param.WriteOutVerbose == 0)FillHist( "LimitSR2/"+param.Name+"/Q_HT_LT1_Central",  (leps[0]->Charge()*HT)/leps[0]->Pt(),  w, 4 , QHTLT, "Reco HT/LT1 * Q");
	
	FillEventCutflow(HNL_LeptonCore::ChannelDepSR2, w, GetChannelString(channel) +"_SR2", "ChannelCutFlow/"+param.Name,param.WriteOutVerbose);//Def
	
	
	if (HT/leps[0]->Pt() < 1)      return "SR2_HTLTbin1";
	return "SR2_HTLTbin2";
      }
    }
  }

  return "false";
}



bool  HNL_RegionDefinitionsOpt::RunSignalRegionAK4(HNL_LeptonCore::Channel channel, HNL_LeptonCore::ChargeType qq ,std::vector<Lepton *> leps, std::vector<Lepton *> leps_veto ,  std::vector<Tau> TauColl,std::vector<Jet> JetColl, std::vector<FatJet>  AK8_JetColl, std::vector<Jet> B_JetColl, Event ev, Particle METv, AnalyzerParameter param, TString PostLabel ,  float w){



  TString SR3String = RunSignalRegionAK4String(channel, qq, leps, leps_veto, TauColl,JetColl,AK8_JetColl,B_JetColl,ev, METv, param, PostLabel,w);
  if(SR3String == "false") return false;
  else return true;

}


TString HNL_RegionDefinitionsOpt::RunSignalRegionAK4String(HNL_LeptonCore::Channel channel, HNL_LeptonCore::ChargeType qq ,std::vector<Lepton *> leps, std::vector<Lepton *> leps_veto ,  std::vector<Tau> TauColl,std::vector<Jet> JetColl, std::vector<FatJet>  AK8_JetColl, std::vector<Jet> B_JetColl, Event ev, Particle METv, AnalyzerParameter param, TString PostLabel ,  float w){
                                       
  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_lep_pt",param.Name,param.WriteOutVerbose);

  if (leps_veto.size() != 2) return "false";

  if(qq==Plus && leps[0]->Charge() < 0) return "false";
  if(qq==Minus && leps[0]->Charge() > 0) return "false";

  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_lep_charge",param.Name,param.WriteOutVerbose);

  Particle ll =  (*leps[0]) + (*leps[1]);
  if (channel==EE  && (fabs(ll.M()-90.) < 10)) return "false";

  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_dilep_mass",param.Name,param.WriteOutVerbose);

  double ST = GetST(leps, JetColl, AK8_JetColl, METv);
  double met2_st = pow(METv.Pt(),2.)/ ST;
  bool PassHMMet    = (met2_st < 15);

  //  double LowerMassSR3WmassCut = 50.;   double UpperMassSR3WmassCut = 120.;
  
  int  NB_JetColl      =  B_JetColl.size();

  double pt_bin1= 140.;
  if (param.SRConfig.Contains("SR3_bin1pt_60_")) pt_bin1= 60.;
  if (param.SRConfig.Contains("SR3_bin1pt_70_")) pt_bin1= 70.;
  if (param.SRConfig.Contains("SR3_bin1pt_80_")) pt_bin1= 80.;
  if (param.SRConfig.Contains("SR3_bin1pt_90_")) pt_bin1= 90.;
  if (param.SRConfig.Contains("SR3_bin1pt_100_")) pt_bin1= 100.;
  if (param.SRConfig.Contains("SR3_bin1pt_120_")) pt_bin1= 120.;

  double pt_bin2= 140.;
  if (param.SRConfig.Contains("SR3_bin2pt_60_")) pt_bin2= 60.;
  if (param.SRConfig.Contains("SR3_bin2pt_70_")) pt_bin2= 70.;
  if (param.SRConfig.Contains("SR3_bin2pt_80_")) pt_bin2= 80.;
  if (param.SRConfig.Contains("SR3_bin2pt_90_")) pt_bin2= 90.;
  if (param.SRConfig.Contains("SR3_bin2pt_100_")) pt_bin2= 100.;
  if (param.SRConfig.Contains("SR3_bin2pt_120_")) pt_bin2= 120.;
  
  if(NB_JetColl==0 && PassHMMet){
    if(JetColl.size()==0)          Fill_RegionPlots(channel, 0, param.Name,"ZeroJetSR3" ,TauColl,  JetColl, AK8_JetColl, leps,  METv, nPV, w,param.WriteOutVerbose);
    else if(JetColl.size()==1)     Fill_RegionPlots(channel, 0, param.Name,"OneJetSR3" ,  TauColl,JetColl, AK8_JetColl, leps,  METv, nPV, w,param.WriteOutVerbose);
  }
  
  if((NB_JetColl==0 && PassHMMet) && JetColl.size() == 0 && leps[1]->Pt() > pt_bin1) {
    if(param.WriteOutVerbose == 0)FillHist( "LimitSR3/"+param.Name+"/SignalBins",   0.5, w, 16, 0, 16.,  "Signalbins");
    if(param.WriteOutVerbose == 0)    FillHist( "LimitSR3/"+param.Name+"/SignalBinsQ",   0.5*leps[0]->Charge(), w, 32, -16, 16., "Signalbins");                                       
    FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_0JetBin",param.Name,param.WriteOutVerbose);

    return "SR3_bin1";
  }
  if((NB_JetColl==0 && PassHMMet) && JetColl.size() == 1 && leps[1]->Pt() > pt_bin2) {
    if(param.WriteOutVerbose == 0)FillHist( "LimitSR3/"+param.Name+"/SignalBins",   1.5, w, 16, 0, 16., "Signalbins");
    if(param.WriteOutVerbose == 0)FillHist( "LimitSR3/"+param.Name+"/SignalBinsQ",   1.5*leps[0]->Charge(), w, 32, -16, 16., "Signalbins");                                       
    FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_1JetBin",param.Name,param.WriteOutVerbose);

    return "SR3_bin2";
  }
  
  //if((NB_JetColl==0 && PassHMMet) && JetColl.size() == 0 && leps[1]->Pt() > 80.) FillHist( "LimitSR3/"+param.Name+"/SignalBinsQ",   0.5*leps[0]->Charge(), w, 28, -14, 14., "Signalbins");
  //if((NB_JetColl==0 && PassHMMet) && JetColl.size() == 1 && leps[1]->Pt() > 80.) FillHist( "LimitSR3/"+param.Name+"/SignalBinsQ",   1.5*leps[0]->Charge(), w, 28, -14, 14., "Signalbins");


  if(JetColl.size() >0)FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_jet",param.Name,param.WriteOutVerbose);

  //Fill_RegionPlots      (channel, true, param.Name+"/SR3Initial/" , "", JetColl, AK8_JetColl, leps,  METv, nPV, w);
  if(JetColl.size() < 2) return "false";


  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_dijet",param.Name,param.WriteOutVerbose);

  //if(!(GetMass("HNL_SR3", JetColl, AK8_JetColl,leps) < UpperMassSR3WmassCut && GetMass("HNL_SR3", JetColl, AK8_JetColl,leps) > LowerMassSR3WmassCut)) {
  //  return "false";
  // }
                                                           
  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_Wmass",param.Name,param.WriteOutVerbose);

  if(JetColl[0].Pt() < 25.)  return "false";
  
  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_J1Pt",param.Name,param.WriteOutVerbose);
   
  if(!PassHMMet)    return "false";
  
  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_MET",param.Name,param.WriteOutVerbose);

  if(NB_JetColl>  0)   return "false";
  
  Fill_RegionPlots(channel, 0, param.Name,"DiJetSR3" ,TauColl,  JetColl, AK8_JetColl, leps,  METv, nPV, w,param.WriteOutVerbose);

  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_bveto",param.Name,param.WriteOutVerbose);

  //Fill_RegionPlots      (channel, true, param.Name+"/SR3/" , "", JetColl, AK8_JetColl, leps,  METv, nPV, w);
  //FIll Limit 

  double bin = 0;
  
  float dijetmass_tmp=999.;
  float dijetmass=9990000.;
  int m=-999;
  int n=-999;
  for(UInt_t emme=0; emme<JetColl.size(); emme++){
    for(UInt_t enne=1; enne<JetColl.size(); enne++) {

      if(emme == enne) continue;      
      dijetmass_tmp = (JetColl[emme]+JetColl[enne]).M();

      
      if ( fabs(dijetmass_tmp-80.4) < fabs(dijetmass-80.4) ) {
        dijetmass = dijetmass_tmp;
        m = emme;
        n = enne;
      }
    }
  }
  
  Particle N1cand = JetColl[m] + JetColl[n]+ *leps[0];
  Particle N2cand = JetColl[m] + JetColl[n]+ *leps[1];
  Particle Wcand = JetColl[m] + JetColl[n]+ *leps[0]+ *leps[1];

  //  double dRl2JJ = leps[1]->DeltaR(JetColl[m] + JetColl[n]);
  //  double LT = leps[0]->Pt() + leps[1]->Pt();
  double L2T =  leps[1]->Pt();

  TString sbin="";
  
  if(L2T > 140)  sbin="3";
  else if(L2T > 80){
    if(N1cand.M() > 350.) {
      if(Wcand.M() > 600)  sbin="4";
      else  sbin="5";
    }
    else sbin="6";
  }
  else {
    if(N1cand.M() > 250.) {
      sbin="7";
    }  
    else {
      sbin="8";
    }
  }
  

  if(param.WriteOutVerbose == 0)FillHist( "LimitSR3/"+param.Name+"/SignalBins",   bin, w, 16, 0, 16., "Signalbins");

  double qbin = bin*double(leps[0]->Charge());
  if(param.WriteOutVerbose == 0)FillHist( "LimitSR3/"+param.Name+"/SignalBinsQ",   qbin, w, 32, -16, 16, "Signalbins");
  
  TString signal_region = "HNL_SR3";
  
  FillEventCutflow(HNL_LeptonCore::ChannelDepSR3, w, GetChannelString(channel) +"_SR3", "ChannelCutFlow/"+param.Name,param.WriteOutVerbose);//Def

  return "SR3_bin"+sbin;
  
}





HNL_RegionDefinitionsOpt::HNL_RegionDefinitionsOpt(){
      


}
 
HNL_RegionDefinitionsOpt::~HNL_RegionDefinitionsOpt(){

}




bool HNL_RegionDefinitionsOpt::PassVBFInitial(vector<Jet>  JetColl){

  if(JetColl.size() < 2) return false;

  double maxDiJetDeta=0.;
  int ijet1(-1), ijet2(-1);
  for(unsigned int ij = 0; ij < JetColl.size()-1; ij++){
    for(unsigned int ij2 = ij+1; ij2 < JetColl.size(); ij2++){

      double deta = fabs(JetColl[ij].Eta() - JetColl[ij2].Eta());
      if(deta > maxDiJetDeta) {
        maxDiJetDeta=deta;
        ijet1=ij;
        ijet2=ij2;
      }
    }
  }

  if(maxDiJetDeta < 2.5) return false;
  Particle JJ = JetColl[ijet1] + JetColl[ijet2];
  if(JJ.M() < 450.) return false;

  return true;


}

bool HNL_RegionDefinitionsOpt::PassVBF(vector<Jet>  JetColl,std::vector<Lepton *> leps, double mjj_cut ,bool use_leadjets){

  if(leps.size() != 2) return false;
  double ll_dphi = fabs(TVector2::Phi_mpi_pi( ( (*leps[0]).Phi() - (*leps[1]).Phi() )) );
  if(ll_dphi < 2.) return false;
  if( ( (*leps[0]) + (*leps[1]) ).M() < 20.) return false;
  if(JetColl.size() < 2) return false;

  double maxDiJetDeta=0.;
  int ijet1(-1), ijet2(-1);
  for(unsigned int ij = 0; ij < JetColl.size()-1; ij++){
    for(unsigned int ij2 = ij+1; ij2 < JetColl.size(); ij2++){

      double deta = fabs(JetColl[ij].Eta() - JetColl[ij2].Eta());
      if(deta > maxDiJetDeta) {
        maxDiJetDeta=deta;
        ijet1=ij;
        ijet2=ij2;
      }
    }
  }
  if(use_leadjets){ijet1=0;ijet2=1;}
  
  if(maxDiJetDeta < 2.5) return false;
  Particle JJ = JetColl[ijet1] + JetColl[ijet2];
  if(JJ.M() < mjj_cut) return false;
  double Av_JetEta= 0.5*(JetColl[ijet1].Eta()+ JetColl[ijet2].Eta());
  double zeppenfeld = TMath::Max((*leps[0]).Eta()  - Av_JetEta , (*leps[1]).Eta()  - Av_JetEta ) /maxDiJetDeta;

  if(zeppenfeld > 0.75) return false;

  return true;
}






