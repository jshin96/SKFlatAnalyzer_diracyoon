#include "HNL_RegionDefinitionsOpt.h"


/*
  
  Mirror of HNL_RegionDefinitions but allows var and cuts to be modified

 */



void HNL_RegionDefinitionsOpt::RunAllSignalRegions(HNL_LeptonCore::ChargeType qq, 
						   std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Tau> TauColl,
						   std::vector<Jet> AllJetColl ,  std::vector<Jet> JetCollLoose,std::vector<Jet> JetColl, std::vector<Jet> VBF_JetColl,std::vector<FatJet>  AK8_JetColl, 
						   std::vector<Jet> B_JetColl,std::vector<Jet> B_JetCollSR1, 
						   Event ev,   Particle METv, AnalyzerParameter param,   float weight_ll){

  vector<HNL_LeptonCore::Channel> channels = {EE,MuMu};

  
  for(auto dilep_channel : channels){

    //    if(param.Name.Contains("HNTightV2"))OutCutFlow(param.Name+"_"+GetChannelString(dilep_channel)+"_pre", weight_ll);

    float weight_channel = weight_ll;
    
    /// SelectChannel separates OS/SS samples and EE/MM since signales have all processes in sample
    if(MCSample.Contains("Type")&& !SelectChannel(dilep_channel)) continue;
 
    if (param.Name.Contains("MuOpt") && dilep_channel != MuMu) continue;
    if (param.Name.Contains("ElOpt") && dilep_channel != EE) continue;

    if(run_Debug)cout << "ID Mu  " << param.Muon_Tight_ID << " " << param.Muon_FR_ID << endl;
    if(run_Debug)cout << "ID El  " << param.Electron_Tight_ID << " " << param.Electron_FR_ID << endl;

    std::vector<Lepton *> leps       = MakeLeptonPointerVector(muons,electrons,param);
    
    TString channel_string = GetChannelString(dilep_channel);

    AnalyzerParameter param_channel = param;

    param_channel.Name =  channel_string + "/" + param_channel.Name;

    FillEventCutflow(HNL_LeptonCore::ChannelDepInc, weight_channel, GetChannelString(dilep_channel) +"_NoCut", "ChannelCutFlow/"+param_channel.Name,param.WriteOutVerbose);//DEf                                                                    

    HNL_LeptonCore::SearchRegion Regions = HNL_LeptonCore::MuonSRSummary;
    if (dilep_channel == EE)     Regions = HNL_LeptonCore::ElectronSRSummary;
    if (dilep_channel == EMu)    Regions = HNL_LeptonCore::ElectronMuonSRSummary;

    FillEventCutflow(Regions,  weight_channel, "Inclusive","Summary/"+param_channel.Name);


    //PassEventTypeFilter filters out events in MC if runconv and no conversion is present and vice versa
    if(!PassGenMatchFilter(leps, param_channel)) continue;

    FillEventCutflow(Regions,  weight_channel, "GenMatch","Summary/"+param_channel.Name);

    // CheckLeptonFlavourForChannel checks 2 leptons of type according rto dilep_channel are present in event and passes Trigger looses cuts
    if(!CheckLeptonFlavourForChannel(dilep_channel, leps)) continue;
    FillEventCutflow(Regions,  weight_channel, "CheckLeptonFlavourForChannel","Summary/"+param_channel.Name);


    /// Weight MC based on corr
    if(!IsDATA && dilep_channel != MuMu)  weight_channel*= GetElectronSFEventWeight(electrons, param_channel);
    if(!IsDATA && dilep_channel != EE)    weight_channel*= GetMuonSFEventWeight(muons, param_channel);

    if(!PassMETFilter()) return;
    FillEventCutflow(Regions,  weight_channel, "METFilter","Summary/"+param_channel.Name);

   
    std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto,param);
    
    if(leps.size() ==2)  FillEventCutflow(HNL_LeptonCore::ChannelDepDilep, weight_channel, GetChannelString(dilep_channel) +"_Dilep", "ChannelCutFlow/"+param_channel.Name,param.WriteOutVerbose);//Def
    
    if(RunCF){
      if(dilep_channel == MuMu) continue;
      if(IsData && SameCharge(leps)) continue;
      if(!IsData && !SameCharge(leps)) continue;
      if(IsData)weight_channel = GetCFWeightElectron(leps, param_channel);
      if(IsData)FillWeightHist(param_channel.Name+"/CFWeight",weight_channel);
    }
    else{
      if(!SameCharge(leps)) continue;
    }

    FillEventCutflow(Regions,  weight_channel, "CFCut","Summary/"+param_channel.Name);

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

    HNL_LeptonCore::SearchRegion LimitRegionsBDT = HNL_LeptonCore::MuonSRBDT;
    if (dilep_channel == EE) LimitRegionsBDT =HNL_LeptonCore::ElectronSRBDT;
    if (dilep_channel == EMu) LimitRegionsBDT =HNL_LeptonCore::ElectronMuonSRBDT;


    if(!PassPreselection(dilep_channel,qq, leps, leps_veto, TauColl, JetColl, VBF_JetColl, AK8_JetColl, B_JetColl,ev, METv ,param_channel,"", weight_channel)) continue;

    FillEventCutflow(Regions,  weight_channel, "Preselection","Summary/"+param_channel.Name);

    vector<TString> Masses = {"600", "700","800","1000", "2000" };
    vector<TString> BDTMasses = {"100","400","500"};

    bool SR1_version1 (false);
    bool SR1_version2 (true);
    bool SR1_version3 (false);
    bool SR1_version4 (false);
    TString PPNet = "";

    if(param_channel.SRConfig.Contains("OptSR")){
      if(param_channel.SRConfig.Contains("PPNet")) PPNet = "PPNet";
      SR1_version1= (param_channel.SRConfig.Contains("Sig1_v1")) ? true :  false;
      SR1_version2= (param_channel.SRConfig.Contains("Sig1_v2")) ? true :  false;
      SR1_version3= (param_channel.SRConfig.Contains("Sig1_v3")) ? true :  false;
      SR1_version4= (param_channel.SRConfig.Contains("Sig1_v4")) ? true :  false;
    }
    


    if(AK8_JetColl.size() > 0) {

      // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
      ///@@@@@@@@@@@@@@@@@@@     SR 1 [AK8] @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
      // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
      
      FillEventCutflow(Regions,  weight_channel, "AK8","Summary/"+param_channel.Name);
      
      //// plotSR1_version3 means mN bin is done for each mN
      if(SR1_version3){
	for(auto mass : Masses){
	  
	  TString SRbinMD= RunSignalRegionAK8String (mass, dilep_channel,qq, leps, leps_veto, TauColl, JetColl, AK8_JetColl, B_JetCollSR1,ev, METv ,param_channel,"Version3"+PPNet, weight_channel) ;
	  
	  ////// Fill Limit plot
	  if(SRbinMD != "false")  FillEventCutflow(LimitRegions, weight_channel, SRbinMD,"LimitInput/"+param_channel.Name+"/"+mass);
	  
	  ///// Fill Cutflow for 1 mass

	  if(mass == "1000") {
	    if(SRbinMD != "false")  FillEventCutflow(Regions,  weight_channel, "SigReg1","Summary/"+param_channel.Name);
	    else FillEventCutflow(Regions,  weight_channel, "SigReg1Fail","Summary/"+param_channel.Name);
	  }
	  
	} // Mass loop
	
      } /// SR1_version3  Mass Binned Limits
      else{

	TString version = "";
	if(SR1_version1) version = "Version1"+PPNet;
	if(SR1_version2) version = "Version2"+PPNet;
	if(SR1_version4) version = "Version4"+PPNet;

	TString SRbin= RunSignalRegionAK8String ("---", dilep_channel,qq, leps, leps_veto, TauColl, JetColl, AK8_JetColl, B_JetCollSR1,ev, METv ,param_channel,version, weight_channel) ;

	////// Fill Limit plot                                                                                                                                          
	if(SRbin != "false"){
	  FillEventCutflow(LimitRegions, weight_channel, SRbin,"LimitInput/"+param_channel.Name);
	  for(auto bdt_mass : BDTMasses) FillEventCutflow(LimitRegionsBDT, weight_channel, SRbin,"LimitInputBDT/"+param_channel.Name+"/"+bdt_mass);
	}

	///// Fill Cutflow
	if(SRbin != "false")  FillEventCutflow(Regions,  weight_channel, "SigReg1","Summary/"+param_channel.Name);
	else FillEventCutflow(Regions,  weight_channel, "SigReg1Fail","Summary/"+param_channel.Name);
      }


      
    }
    else{


      // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                                                                                 
      ///@@@@@@@@@@@@@@@@@@@     SR 2 [VBF] @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                                                                             
      // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                                                                                           


      TString Version = "Version1";      
      
      if(param_channel.SRConfig.Contains("OptSR")){
	if(param_channel.SRConfig.Contains("Sig2_v1")) Version= "Version1";
	if(param_channel.SRConfig.Contains("Sig2_v2")) Version= "Version2";
      }


      //// SR2  OR SR3
      
      
      TString SRbin = RunSignalRegionWWString( dilep_channel,qq, leps, leps_veto,  TauColl, JetCollLoose, VBF_JetColl,  AK8_JetColl, B_JetColl,ev, METv, param_channel,  Version, weight_channel);

      
      if(SRbin != "false"){

        ////// Fill Limit plot                                                                                                                                            

	if(SR1_version3){
	  for(auto mass : Masses)FillEventCutflow(LimitRegions, weight_channel, SRbin,"LimitInput/"+param_channel.Name+"/"+mass);
	}
	else FillEventCutflow(LimitRegions, weight_channel, SRbin,"LimitInput/"+param_channel.Name);

	
	for(auto bdt_mass : BDTMasses) FillEventCutflow(LimitRegionsBDT, weight_channel, SRbin,"LimitInputBDT/"+param_channel.Name+"/"+bdt_mass);


	
	FillEventCutflow(Regions,  weight_channel, "SigReg2","Summary/"+param_channel.Name);
      }
      else{

	// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  
	///@@@@@@@@@@@@@@@@@@@     SR 3 [AK4] @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                                                                         
	// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 

	FillEventCutflow(Regions,  weight_channel, "SigReg3","Summary/"+param_channel.Name);
	

	TString Version = "Version1";
	if(param_channel.SRConfig.Contains("OptSR")){
	  if(param_channel.SRConfig.Contains("Sig3_v1")) Version= "Version1";
	  if(param_channel.SRConfig.Contains("Sig3_v2")) Version= "Version2";
	  if(param_channel.SRConfig.Contains("Sig3_v3")) Version= "Version3";
	  if(param_channel.SRConfig.Contains("Sig3_v4")) Version= "Version4";
	}

	TString SRbin  = RunSignalRegionAK4String (dilep_channel,qq, leps, leps_veto, TauColl, JetColl, AK8_JetColl, B_JetColl, ev, METv ,param_channel,Version, weight_channel);

	TString SRBDT100 = RunSignalRegionAK4StringBDT("100", dilep_channel, leps,JetColl,B_JetColl, METv , ev);   
	TString SRBDT400 = RunSignalRegionAK4StringBDT("400", dilep_channel, leps,JetColl,B_JetColl, METv, ev);   
	TString SRBDT500 = RunSignalRegionAK4StringBDT("500", dilep_channel, leps,JetColl,B_JetColl, METv, ev);   
	
	if(SRBDT100 != "false") FillEventCutflow(LimitRegionsBDT, weight_channel, SRBDT100,"LimitInputBDT/"+param_channel.Name+"/100");
	if(SRBDT400 != "false") FillEventCutflow(LimitRegionsBDT, weight_channel, SRBDT400,"LimitInputBDT/"+param_channel.Name+"/400");
	if(SRBDT500 != "false") FillEventCutflow(LimitRegionsBDT, weight_channel, SRBDT500,"LimitInputBDT/"+param_channel.Name+"/500");
	
	
	if(SRbin != "false") {
	  if(SR1_version3){
	    for(auto mass : Masses)  FillEventCutflow(LimitRegions, weight_channel, SRbin,"LimitInput/"+param_channel.Name+"/"+mass);
	  }
	  else 	  FillEventCutflow(LimitRegions, weight_channel, SRbin, "LimitInput/"+param_channel.Name);

	  Fill_RegionPlots(dilep_channel, 0, param_channel.Name,"FailSelection" , TauColl, JetColl, AK8_JetColl, leps,  METv, nPV, weight_channel,param_channel.WriteOutVerbose);
	  FillEventCutflow(Regions,  weight_channel, "SigReg3Pass","Summary/"+param_channel.Name);
	}
	else           FillEventCutflow(Regions,  weight_channel, "SigReg3Fail","Summary/"+param_channel.Name);

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

  double mz_cut = 10.;
  if (param.SRConfig.Contains("PreSel_MZ_20_"))   mz_cut = 20.;
  if (param.SRConfig.Contains("PreSel_MZ_15_"))   mz_cut = 15.;
  if (param.SRConfig.Contains("PreSel_MZ_10_"))    mz_cut = 10.;
  if (param.SRConfig.Contains("PreSel_MZ_5_"))    mz_cut = 5.;
  if (param.SRConfig.Contains("PreSel_MZ_0_"))    mz_cut = 0.;

  if (channel==EE  && (fabs(ll.M()-90.) < mz_cut)) return false;

  if(ll.M() < 10) return false; // TO_CHECK: IS 20 BEST OPTION

  // REMOVE 0 Jet EVENTS
  //int njets     = JetColl.size() + AK8_JetColl.size() + VBF_JetColl.size();
 

  Fill_RegionPlots(channel, 0, param.Name,"Preselection" , TauColl, JetColl, AK8_JetColl, leps,  METv, nPV, w,param.WriteOutVerbose);
  FillEventCutflow(HNL_LeptonCore::ChannelDepPresel, w, GetChannelString(channel) +"_Presel", "ChannelCutFlow/"+param.Name,param.WriteOutVerbose);//Def
  
  return true;
}




bool  HNL_RegionDefinitionsOpt::RunSignalRegionAK8(HNL_LeptonCore::Channel channel, HNL_LeptonCore::ChargeType qq , std::vector<Lepton *> leps, std::vector<Lepton *> leps_veto , std::vector<Tau> TauColl, std::vector<Jet> JetColl, std::vector<FatJet>  AK8_JetColl, std::vector<Jet> B_JetColl, Event ev, Particle METv, AnalyzerParameter param, TString PostLabel ,  float w){


  TString SR1String = RunSignalRegionAK8String("",channel, qq, leps, leps_veto, TauColl,JetColl,AK8_JetColl,B_JetColl,ev, METv, param, PostLabel,w);
  
  if(SR1String == "false") return false;
  else return true;
  
}


/// Return TString for Limit bin

TString HNL_RegionDefinitionsOpt::RunSignalRegionAK8String(TString mass, HNL_LeptonCore::Channel channel, HNL_LeptonCore::ChargeType qq , std::vector<Lepton *> leps, std::vector<Lepton *> leps_veto , std::vector<Tau> TauColl, std::vector<Jet> JetColl, std::vector<FatJet>  AK8_JetColl, std::vector<Jet> B_JetColl, Event ev, Particle METv, AnalyzerParameter param, TString Modifier ,  float w){

  
  bool HasTightTau=false;
  for(auto itau: TauColl){
    bool HasTightTau_n=true;
    for (auto ilep : leps) if (ilep->DeltaR(itau) < 0.4) HasTightTau_n=false;
    for (auto ijet : AK8_JetColl) if (ijet.DeltaR(itau) < 1.)  HasTightTau_n=false;
    for (auto ijet : JetColl) if (ijet.DeltaR(itau) < 0.5)  HasTightTau_n=false;
    if(HasTightTau_n) HasTightTau=true;
  }
  
  TString PNMass = param.Name+"_"+mass;
  if (mass == "---") PNMass = param.Name;

  FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_Init",PNMass,param.WriteOutVerbose);
  
  if (leps_veto.size() != 2) return "false";
  FillEventCutflow(HNL_LeptonCore::SR1,w, "SR1_lep_pt",PNMass,param.WriteOutVerbose);
  if(AK8_JetColl.size() == 0) return "false";
  
  if(qq==Plus && leps[0]->Charge() < 0) return "false";
  if(qq==Minus && leps[0]->Charge() > 0) return "false";

  FillEventCutflow(HNL_LeptonCore::ChannelDepSR1, w, GetChannelString(channel) +"_SR1", "ChannelCutFlow/"+PNMass,param.WriteOutVerbose);//Def                                          


  FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_lep_charge",PNMass,param.WriteOutVerbose);
  FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_dilep_mass",PNMass,param.WriteOutVerbose);

  double ST = GetST(leps, JetColl, AK8_JetColl, METv);
  double HT = GetHT(JetColl, AK8_JetColl);
  double met2_st = pow(METv.Pt(),2.)/ ST;

  double met_cut = 10.;
  if (param.SRConfig.Contains("SR1MET_20_"))   met_cut = 20.;
  if (param.SRConfig.Contains("SR1MET_17_"))   met_cut = 17.;
  if (param.SRConfig.Contains("SR1MET_15_"))   met_cut = 15.;
  if (param.SRConfig.Contains("SR1MET_12_"))   met_cut = 12.;
  if (param.SRConfig.Contains("SR1MET_10_"))   met_cut = 10.;
    
  bool PassHMMet    = (met2_st < met_cut);
  bool PassBJetMVeto = (B_JetColl.size()==0);

  double mass_cut = 450.;

  if (param.SRConfig.Contains("SR1MLLJJ_500_"))   mass_cut = 500.;
  if (param.SRConfig.Contains("SR1MLLJJ_600_"))   mass_cut = 600.;
  if (param.SRConfig.Contains("SR1MLLJJ_700_"))   mass_cut = 700.;
  if (param.SRConfig.Contains("SR1MLLJJ_800_"))   mass_cut = 800.;
  if (param.SRConfig.Contains("SR1MLLJJ_900_"))   mass_cut = 900.;
  if (param.SRConfig.Contains("SR1MLLJJ_1000_"))   mass_cut = 1000.;
 
  double LowerMassSR1WmassCut = mass_cut;
  
  TString signal_region1 = "HNL_SR1";
  
  Fill_RegionPlots(channel, 0, PNMass,"InclusiveR1" , TauColl, JetColl, AK8_JetColl, leps,  METv, nPV, w,param.WriteOutVerbose);
  
  double dPhil2_l = fabs(TVector2::Phi_mpi_pi( ( (AK8_JetColl[0] + *leps[1]).Phi() - (leps[0]->Phi() ))));
  
  double pt_cut = 100.;
  if (param.SRConfig.Contains("SR1PT_80_"))   pt_cut = 80.;
  if (param.SRConfig.Contains("SR1PT_90_"))   pt_cut = 90.;
  if (param.SRConfig.Contains("SR1PT_100_"))   pt_cut = 100.;
  if (param.SRConfig.Contains("SR1PT_110_"))   pt_cut = 110.;
  if (param.SRConfig.Contains("SR1PT_120_"))   pt_cut = 120.;

  //if(AK8_JetColl.size() > 1) return "false";
  FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_1AK8",PNMass,param.WriteOutVerbose);

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
  Particle Wcand = AK8_JetColl[m] + *leps[0]+*leps[1];
  double MN1 = (N1cand.M() > 2000.) ? 1999. : N1cand.M();


  
  if(!PassHMMet) return "false";
  FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_MET",PNMass,param.WriteOutVerbose);


  if(Wcand.M()  < LowerMassSR1WmassCut ) return "false";
  FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_Wmass",PNMass,param.WriteOutVerbose);


  if(!PassBJetMVeto) return "false";
  
  FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_bveto",PNMass,param.WriteOutVerbose);
  

  if(leps[1]->Pt() < 20)      return "false";
  FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_Lep2Pt",PNMass,param.WriteOutVerbose);
  
  
  if(Modifier.Contains("Version1")){
    
    //if(!Modifier.Contains("PPNet")){
      
    if(!AK8_JetColl[0].PassTagger(JetTagging::particleNet_WvsQCD, DataEra))  return "false";
    if(!IsData) w*= AK8_JetColl[0].GetTaggerSF(JetTagging::particleNet_WvsQCD, DataEra,0);
    //}

    FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_PNTagger",PNMass,param.WriteOutVerbose);

    Fill_RegionPlots(channel, 0, PNMass,"InclusiveSR1" , TauColl, JetColl, AK8_JetColl, leps,  METv, nPV, w,param.WriteOutVerbose);

    if(leps[0]->Pt() < pt_cut)  return "false";

    FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_LepPt",PNMass,param.WriteOutVerbose);

    double dRl2_l2_cut = 2.;

    if(dPhil2_l < dRl2_l2_cut) return "false";

    FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_DphiN_Wlep",PNMass,param.WriteOutVerbose);

    if(HasTightTau) return "false";

    FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_TauVeto",PNMass,param.WriteOutVerbose);

    if( ( HT/leps[0]->Pt()) > 4.) return "false";

  }
  else{
    
    bool passBaseline=true;

    //if(Modifier.Contains("PPNet")){
    if(!AK8_JetColl[0].PassTagger(JetTagging::particleNet_WvsQCD, DataEra))  passBaseline=false;
    else{
      if(!IsData) w*= AK8_JetColl[0].GetTaggerSF(JetTagging::particleNet_WvsQCD, DataEra,0);
    }
    //}

    if(passBaseline) FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_PNTagger",PNMass,param.WriteOutVerbose);

    if(passBaseline) Fill_RegionPlots(channel, 0, PNMass,"InclusiveSR1" , TauColl, JetColl, AK8_JetColl, leps,  METv, nPV, w,param.WriteOutVerbose);

    if(leps[0]->Pt() < pt_cut)  passBaseline=false;
    
    if(passBaseline)FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_LepPt",PNMass,param.WriteOutVerbose);
    
    double dRl2_l2_cut = 2.;
    
    if(dPhil2_l < dRl2_l2_cut)  passBaseline=false;
    
    if(passBaseline) FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_DphiN_Wlep",PNMass,param.WriteOutVerbose);
    
    if(HasTightTau)  passBaseline=false;
    
    if(passBaseline) FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_TauVeto",PNMass,param.WriteOutVerbose);
    
    if( ( HT/leps[0]->Pt()) > 4.) passBaseline=false;
    
    if(!passBaseline){
      int nSRbins=5;
      double ml1jbins[nSRbins] = { 0.,500., 650.,800, 2000.};
      for(int ibin=1; ibin < nSRbins; ibin++){
	if(MN1 < ml1jbins[ibin]) return "SR1_MNbin"+to_string(ibin);
      }
      return "SR1_MNbin1";
    }
    
  }
    
  
  FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_HTPt",PNMass,param.WriteOutVerbose);
  Fill_RegionPlots(channel, 0, PNMass,"InclusiveSRHM1" , TauColl, JetColl, AK8_JetColl, leps,  METv, nPV, w,param.WriteOutVerbose);
  

  if(Modifier.Contains("Version4")){

    if(leps[0]->Pt() < 140)         return "SR1_MNbin1";

    else{
      
      int nSRbins=4;
      double ml1jbins[nSRbins] = { 0., 500., 750., 2000.};
      for(int ibin=1; ibin < nSRbins; ibin++){
        if(MN1 < ml1jbins[ibin]) return "SR1_MNbin"+to_string(ibin+4);
      }

      return "true";
    }
  }

  /// Bins 1-3 are filled with failing baseline

  else if(Modifier.Contains("Version3")){
    
    TString SR1Bin="SR1_MNbin1";
    
    if(leps[0]->Pt() < 140)   return SR1Bin;
    if(MN1 < 300) return SR1Bin;
        
    FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_masscuts",PNMass,param.WriteOutVerbose);
    
    int nSRbins=4;
    
    std::string::size_type sz;
    double central_mass = std::stod(std::string(mass),&sz);
    double ml1jbins[nSRbins] = { 0., LowMassEdgeSR1(channel,mass),UpperMassEdgeSR1(channel, mass), 2000.};
    
    if(param.WriteOutVerbose == 0)FillHist( "LimitSR1/"+PNMass+"/N1Mass_Central",  MN1,  w, nSRbins-1, ml1jbins, "Reco M_{l1jj}");

  									
    for(int ibin=1; ibin < nSRbins; ibin++){
      if(MN1 < ml1jbins[ibin]) return "SR1_MNbin"+to_string(ibin+4);
    }
  }
  else if (Modifier.Contains("Version2")){

    TString SR1Bin="SR1_MNbin1";

    if(channel==MuMu){
      if(MN1 > 225){
        if(leps[0]->Pt() < 140)   return SR1Bin;
      }
      else   if(MN1 > 150){
        if(leps[0]->Pt() < 70)   return SR1Bin;
      }
    }

    int nSRbins=5;
    double ml1jbins[nSRbins] = { 0.,  600.,700., 1000., 2000.};
    for(int ibin=1; ibin < nSRbins; ibin++){
      if(MN1 < ml1jbins[ibin]) return "SR1_MNbin"+to_string(ibin+4);
    }
  }

  else{

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
    for(int ibin=1; ibin < nSRbins; ibin++){
      if(MN1 < ml1jbins[ibin]) return "SR1_MNbin"+to_string(ibin);
    }
    
    return "true";
  }
  
  return "true";
  
}



double HNL_RegionDefinitionsOpt::LowMassEdgeSR1(HNL_LeptonCore::Channel channel,TString mass ){

  if (channel==MuMu){
    if(mass== "100") return 95;
    if(mass== "200") return 175;
    if(mass== "400") return 340;
    if(mass== "500") return 440;
    if(mass== "600") return 560;
    if(mass== "700") return 600;
    if(mass== "800") return 750;
    if(mass== "900") return 840;
    if(mass== "1000") return 900;
    if(mass== "1100") return 990;
    if(mass== "1200") return 1000;
    if(mass== "1300") return 1000;
    if(mass== "1400") return 1000;
    if(mass== "1500") return 1000;
    if(mass== "2000") return 1700;
    return 1000;
  }

  return 900;  
}


double HNL_RegionDefinitionsOpt::UpperMassEdgeSR1(HNL_LeptonCore::Channel channel,TString mass ){
  
  if(channel==MuMu){
    if(mass== "100") return 150;
    if(mass== "200") return 250;
    if(mass== "400") return 450;
    if(mass== "500") return 560;
    if(mass== "600") return 700;
    if(mass== "700") return 850;
    if(mass== "800") return 1000;
    if(mass== "900") return 1100;
    if(mass== "1000") return 1250;
    if(mass== "1100") return 1300;
    if(mass== "1200") return 1450;
    if(mass== "1300") return 1600;
    if(mass== "1400") return 1700;
    if(mass== "1500") return 1800;
    if(mass== "2000") return 1900;

  }
  return 2000;
}


/*double HNL_RegionDefinitionsOpt::LowMassEdgeSR3(HNL_LeptonCore::Channel channel,TString mass ){

  if (channel==MuMu){
    if(mass== "85")  return 40;
    if(mass== "90")  return 45;
    if(mass== "100") return 55;
    if(mass== "125") return 85;
    if(mass== "150") return 110;
    if(mass== "200") return 160;
    if(mass== "250") return 215;
    if(mass== "300") return 225;
    if(mass== "400") return 295;
    if(mass== "500") return 370;
    return 370;
  }

  
  if (channel==EE){
    if(mass== "85")  return 45;
    if(mass== "90")  return 50;
    if(mass== "100") return 50;
    if(mass== "125") return 90;
    if(mass== "150") return 130;
    if(mass== "200") return 160;
    if(mass== "250") return 230;
    if(mass== "300") return 235;
    if(mass== "400") return 335;
    if(mass== "500") return 400;
    return 400;
  }

  return 300;
}


double HNL_RegionDefinitionsOpt::UpperMassEdgeSR3(HNL_LeptonCore::Channel channel,TString mass ){

  if (channel==MuMu){
    if(mass== "85")  return 100;
    if(mass== "90")  return 105;
    if(mass== "100") return 115;
    if(mass== "125") return 140;
    if(mass== "150") return 170;
    if(mass== "200") return 215;
    if(mass== "250") return 270;
    if(mass== "300") return 340;
    if(mass== "400") return 490;
    if(mass== "500") return 370;
    return 370;
  }


  if (channel==EE){
    if(mass== "85")  return 45;
    if(mass== "90")  return 50;
    if(mass== "100") return 50;
    if(mass== "125") return 90;
    if(mass== "150") return 130;
    if(mass== "200") return 160;
    if(mass== "250") return 230;
    if(mass== "300") return 235;
    if(mass== "400") return 335;
    if(mass== "500") return 400;
    return 400;
  }


  return 2000;
}


*/




TString HNL_RegionDefinitionsOpt::RunSignalRegionAK4StringBDT(TString mN, HNL_LeptonCore::Channel channel, 
							      std::vector<Lepton *> LepTColl,  
							      std::vector<Jet> JetColl,std::vector<Jet> B_JetColl,Particle METv, Event  ev){

  if (LepTColl.size() != 2) return "false";
  Particle ll =  (*LepTColl[0]) + (*LepTColl[1]);
  if (channel==EE  && (fabs(ll.M()-90.) < 10)) return "false";

  float MVAvalue = ev.HNL_MVA_Event(GetChannelString(channel)+"_"+mN);

  std::vector<FatJet> FatJetColl;
  double ST = GetST( LepTColl, JetColl, FatJetColl, METv);
  double met2_st = pow(METv.Pt(),2.)/ ST;
  bool PassHMMet    = (met2_st < 15);

  TString LabelPrefix =  "SR3";
  if(!PassHMMet) return LabelPrefix+"_BDTbin1";
  if(B_JetColl.size() > 0)    return LabelPrefix+"_BDTbin1";
  
  if(MVAvalue< 0.0) return LabelPrefix+"_BDTbin1";
  else if(MVAvalue< 0.10) return LabelPrefix+"_BDTbin2";
  else if(MVAvalue< 0.15) return LabelPrefix+"_BDTbin3";
  else if(MVAvalue< 0.2) return LabelPrefix+"_BDTbin4";
  else if(MVAvalue< 0.25) return LabelPrefix+"_BDTbin5";
  else if(MVAvalue< 0.3) return LabelPrefix+"_BDTbin6";
  else if(MVAvalue< 0.35) return LabelPrefix+"_BDTbin7";
  else  return LabelPrefix+"_BDTbin8";

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
							  Event ev, Particle METv, AnalyzerParameter param, TString Modifier ,  float w){


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
  
  if(Modifier == "Version1"){
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
  }
  else if(Modifier == "Version2"){

    if(PassHMMet) {
      if ((HT/leps[0]->Pt()) < htltcut){
        if(PassBJetMVeto){

          double PTBin[5] = { 0.,50, 100., 120., 200};
	  double L2Pt = (leps[1]->Pt() > 200) ? 199. : leps[1]->Pt();
          if(param.WriteOutVerbose == 0)FillHist( "LimitSR2/"+param.Name+"/PT2_LT1_Central",  L2Pt,  w, 4, PTBin, "Reco PTLep2");
	  
	  
          if (L2Pt > 120)      return "SR2_HTLTbin1";
          return "SR2_HTLTbin2";
        }
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


TString HNL_RegionDefinitionsOpt::RunSignalRegionAK4String(HNL_LeptonCore::Channel channel, HNL_LeptonCore::ChargeType qq ,std::vector<Lepton *> leps, std::vector<Lepton *> leps_veto ,  std::vector<Tau> TauColl,std::vector<Jet> JetColl, std::vector<FatJet>  AK8_JetColl, std::vector<Jet> B_JetColl, Event ev, Particle METv, AnalyzerParameter param, TString Modifier ,  float w){
                                       
  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_lep_pt",param.Name,param.WriteOutVerbose);

  if (leps_veto.size() != 2) {
    FillEventCutflow(HNL_LeptonCore::SR3Fail, w, "SR3_2vl",param.Name,param.WriteOutVerbose);
    return "false";
  }

  if(qq==Plus && leps[0]->Charge() < 0)  return "false";
  if(qq==Minus && leps[0]->Charge() > 0) return "false";

  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_lep_charge",param.Name,param.WriteOutVerbose);

  Particle ll =  (*leps[0]) + (*leps[1]);
  if (channel==EE  && (fabs(ll.M()-90.) < 10)) {
    FillEventCutflow(HNL_LeptonCore::SR3Fail, w, "SR3_mll",param.Name,param.WriteOutVerbose);
    return "false";
  }

  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_dilep_mass",param.Name,param.WriteOutVerbose);

  double ST = GetST(leps, JetColl, AK8_JetColl, METv);
  double met2_st = pow(METv.Pt(),2.)/ ST;
  bool PassHMMet    = (met2_st < 10);
  if(Modifier == "Version1" || Modifier == "Version2" ) PassHMMet    = (met2_st < 15);
  if(Modifier == "Version4") PassHMMet    = (met2_st < 8);

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
  
  
  if(NB_JetColl>  0)  {
    FillEventCutflow(HNL_LeptonCore::SR3Fail, w, "SR3_bveto",param.Name,param.WriteOutVerbose);
    return "false";
  }
  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_bveto",param.Name,param.WriteOutVerbose);

  if(!PassHMMet) {
    FillEventCutflow(HNL_LeptonCore::SR3Fail, w, "SR3_met",param.Name,param.WriteOutVerbose);
    return "false";
  }
  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_MET",param.Name,param.WriteOutVerbose);  


  //////// SR1  PASS MET and BJet veto

  if(JetColl.size()==0)          Fill_RegionPlots(channel, 0, param.Name,"ZeroJetSR3" ,TauColl,  JetColl, AK8_JetColl, leps,  METv, nPV, w,param.WriteOutVerbose);
  else if(JetColl.size()==1)     Fill_RegionPlots(channel, 0, param.Name,"OneJetSR3" ,  TauColl,JetColl, AK8_JetColl, leps,  METv, nPV, w,param.WriteOutVerbose);
    
  
  if(JetColl.size() == 0 && leps[1]->Pt() > pt_bin1) {
    if(param.WriteOutVerbose == 0)FillHist( "LimitSR3/"+param.Name+"/SignalBins",   0.5, w, 16, 0, 16.,  "Signalbins");
    if(param.WriteOutVerbose == 0)    FillHist( "LimitSR3/"+param.Name+"/SignalBinsQ",   0.5*leps[0]->Charge(), w, 32, -16, 16., "Signalbins");                                       
    FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_0JetBin",param.Name,param.WriteOutVerbose);

    return "SR3_bin1";
  }
  if(JetColl.size() == 1 && leps[1]->Pt() > pt_bin2) {
    if(param.WriteOutVerbose == 0)FillHist( "LimitSR3/"+param.Name+"/SignalBins",   1.5, w, 16, 0, 16., "Signalbins");
    if(param.WriteOutVerbose == 0)FillHist( "LimitSR3/"+param.Name+"/SignalBinsQ",   1.5*leps[0]->Charge(), w, 32, -16, 16., "Signalbins");                                       
    FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_1JetBin",param.Name,param.WriteOutVerbose);

    return "SR3_bin2";
  }

  if(JetColl.size() >0)FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_jet",param.Name,param.WriteOutVerbose);

  if(JetColl.size() < 2) {
    FillEventCutflow(HNL_LeptonCore::SR3Fail, w, "SR3_dijet",param.Name,param.WriteOutVerbose);
    return "false";
  }
  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_dijet",param.Name,param.WriteOutVerbose);


  if(JetColl[0].Pt() < 25.)  {
    FillEventCutflow(HNL_LeptonCore::SR3Fail, w, "SR3_0jpt",param.Name,param.WriteOutVerbose);
    return "false";
  }
  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_J1Pt",param.Name,param.WriteOutVerbose);
 
  Fill_RegionPlots(channel, 0, param.Name,"DiJetSR3" ,TauColl,  JetColl, AK8_JetColl, leps,  METv, nPV, w,param.WriteOutVerbose);

  
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

  FillEventCutflow(HNL_LeptonCore::ChannelDepSR3, w, GetChannelString(channel) +"_SR3", "ChannelCutFlow/"+param.Name,param.WriteOutVerbose);//Def          

  
  if(leps[0]->Pt() > 120)Fill_RegionPlots(channel, 0, param.Name,"InclusiveSRHM3" , TauColl, JetColl, AK8_JetColl, leps,  METv, nPV, w,param.WriteOutVerbose);


  if(Modifier == "Version1"){

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
    
  
    TString signal_region = "HNL_SR3";

    return "SR3_bin"+sbin;
  }
  if(Modifier == "Version2"){
    double LT = leps[0]->Pt() + leps[1]->Pt();
    TString sbin="";

    if(LT > 150){
      if(N1cand.M() > 350.) {
	if(Wcand.M() > 600)  {
	  sbin="3";
	}
	else  {
	  sbin="4";
	}
      }
      else {
	sbin="5";
      }
    }
    else {
      if(N1cand.M() > 250.) {
	sbin="6";
      }
      else {
	sbin="7";
      }
    }


    TString signal_region = "HNL_SR3";


    return "SR3_bin"+sbin;


  }

  if(Modifier == "Version3"){
    
    if(Wcand.M() < 300)  {
      FillEventCutflow(HNL_LeptonCore::SR3Fail, w, "SR3_Wmass300",param.Name,param.WriteOutVerbose);
      return "false";
    }
    
    FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_Wmass",param.Name,param.WriteOutVerbose);
        
    int nSRbins=5;
    
    //std::string::size_type sz;
    //double central_mass = std::stod(std::string(mass),&sz);
    double ml1jbins[nSRbins] = { 300., 400, 550, 700, 2000.};
    
    if(param.WriteOutVerbose == 0)FillHist( "LimitSR3/"+param.Name+"/N1Mass_Central",  N1cand.M(),  w, nSRbins-1, ml1jbins, "Reco M_{l1jj}");
    
    if(leps[0]->Pt() < 110  || leps[1]->Pt() < 20)  {
      FillEventCutflow(HNL_LeptonCore::SR3Fail, w, "SR3_leppt",param.Name,param.WriteOutVerbose);
      
      return "false";
    }
    FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_LepPt",param.Name,param.WriteOutVerbose);
    
    if(Wcand.M() < 400) {
      FillEventCutflow(HNL_LeptonCore::SR3Fail, w, "SR3_Wmass400",param.Name,param.WriteOutVerbose);
      return "false";
    }
    FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_Wmass2",param.Name,param.WriteOutVerbose);
    if(N1cand.M() < 300)  {
      FillEventCutflow(HNL_LeptonCore::SR3Fail, w, "SR3_Nmass300",param.Name,param.WriteOutVerbose);
      
      return "false";
    }
    FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_Nmass",param.Name,param.WriteOutVerbose);
    
    if(channel==MuMu){
      
      if(met2_st > 7 ) {
	if(Wcand.M() > 600){
	  if(N1cand.M() < 500) return "SR3_bin3"; 
	  else return "SR3_bin4";
	}
	else return "SR3_bin5";
      }
      
      if(N1cand.M() < 370 || Wcand.M() < 600) return "SR3_bin6";
      if(Wcand.M() > 800) return "SR3_bin7";
      
      if(N1cand.M() < 500 ) return "SR3_bin8";
      if(N1cand.M() < 700 ) return "SR3_bin9";
      else return "SR3_bin10";
    }
    
    if(channel==EE){
      if(leps[0]->Pt() < 125) return "SR3_bin3";
      if(leps[1]->Pt() < 20)  return "SR3_bin4";
      
      if((GetMass("HNL_SR3_NLL", JetColl, AK8_JetColl,leps) < 750)) return "SR3_bin4";
      if((GetMass("HNL_SR3_N1L", JetColl, AK8_JetColl,leps) < 400)) return "SR3_bin4";
      
      if(met2_st < 6 ){
	if((GetMass("HNL_SR3_N1L", JetColl, AK8_JetColl,leps) < 700))  return "SR3_bin5";
	if((GetMass("HNL_SR3_N1L", JetColl, AK8_JetColl,leps) < 1000))  return "SR3_bin6";
      }
      return "SR3_bin7";
    }
  }

  if(Modifier == "Version4"){

    Fill_RegionPlots(channel, 0, param.Name,"SR3_R4" ,TauColl,  JetColl, AK8_JetColl, leps,  METv, nPV, w,param.WriteOutVerbose);

    
    if(leps[1]->Pt() < 30) return "false";
    if(Wcand.M() < 300) return "false";
    if(Wcand.M() < 400) return "SR3_bin4";
    if(Wcand.M() < 800) {
      Fill_RegionPlots(channel, 0, param.Name,"SR3_R4Low" ,TauColl,  JetColl, AK8_JetColl, leps,  METv, nPV, w,param.WriteOutVerbose);

      if(N1cand.M() < 500) return "SR3_bin5";
      if(N1cand.M() < 700) return "SR3_bin6";
      else return "SR3_bin7";
    }
    else{
      Fill_RegionPlots(channel, 0, param.Name,"SR3_R4High" ,TauColl,  JetColl, AK8_JetColl, leps,  METv, nPV, w,param.WriteOutVerbose);

      if(Wcand.M() < 700) return "SR3_bin7";
      if(Wcand.M() < 1000) return "SR3_bin8";
      return "SR3_bin9";
           
    }
  }

  return "false";
  
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






