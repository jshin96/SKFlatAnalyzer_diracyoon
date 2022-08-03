#include "HNL_RegionDefinitions.h"


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


bool  HNL_RegionDefinitions::PassPreselection(HNL_LeptonCore::Channel channel,HNL_LeptonCore::ChargeType q, std::vector<Lepton *> leps,std::vector<Lepton *> leps_veto, std::vector<Jet> jets, std::vector<Jet> vbf_jets,std::vector<FatJet>  fatjets, std::vector<Jet> bjets, Event ev, Particle METv, AnalyzerParameter param, TString channel_string ,  float w){

  //  FillSSPreselectionPlots(leps ,leps_veto, jets, fatjets, bjets, ev, METv, param);




  return true;
}


void HNL_RegionDefinitions::RunSignalRegions(HNL_LeptonCore::Channel channel,HNL_LeptonCore::ChargeType q, std::vector<Lepton *> leps,std::vector<Lepton *> leps_veto, std::vector<Jet> jets, std::vector<Jet> vbf_jets,std::vector<FatJet>  fatjets, std::vector<Jet> bjets, Event ev, Particle METv, AnalyzerParameter param, TString channel_string ,  float w){
  
  
  if(!PassPreselection(channel,q, leps, leps_veto, jets, vbf_jets, fatjets, bjets,ev, METv ,param,channel_string, w)) return;
  
  if(fatjets.size() > 0) RunSignalRegionAK8 (channel,q, leps, leps_veto, jets, fatjets, bjets,ev, METv ,param,channel_string, w) ;
  else{
    if(!(PassVBFInitial(vbf_jets)&&RunSignalRegionWW( channel,q, leps, leps_veto,  vbf_jets, fatjets, bjets,ev, METv, param,  channel_string, w))){
      
      RunSignalRegionAK4 (channel,q, leps, leps_veto, jets, fatjets, bjets, ev, METv ,param,channel_string, w);
    } 
    
  }
  
}
					     


bool  HNL_RegionDefinitions::RunSignalRegionAK8(HNL_LeptonCore::Channel channel, HNL_LeptonCore::ChargeType analysis_charge ,std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet>  fatjets, std::vector<Jet> bjets, Event ev, Particle METv,  AnalyzerParameter param, TString channel_string ,  float w){
			    
  //Particle METUnsmearedv = ev.GetMETVector();
  //Event ev, Particle METv =UpdateMETSmearedJet(METUnsmearedv, jets);

  std::vector<Lepton *> leps       = MakeLeptonPointerVector(muons,electrons);
  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);
  
  
  return RunSignalRegionAK8(channel, analysis_charge, leps, leps_veto, jets, fatjets, bjets, ev, METv, param, channel_string, w);

  
}

bool  HNL_RegionDefinitions::RunSignalRegionAK8(HNL_LeptonCore::Channel channel, HNL_LeptonCore::ChargeType analysis_charge , std::vector<Lepton *> leps, std::vector<Lepton *> leps_veto , std::vector<Jet> jets, std::vector<FatJet>  fatjets, std::vector<Jet> bjets, Event ev, Particle METv, AnalyzerParameter param, TString channel_string ,  float w){

  double lep1_ptcut= (channel==MuMu) ?   20. : 25.;
  double lep2_ptcut= (channel==MuMu) ?   10. : 15.;

  if (leps.size() != 2 and leps_veto.size() != 2) return false;

  if (channel==EE     && !(leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::ELECTRON)) return false;
  if (channel==MuMu   && !(leps[0]->LeptonFlavour() == Lepton::MUON     && leps[1]->LeptonFlavour() == Lepton::MUON))    return false;
  if ((channel==EMu || channel==MuE)  && 
      !( (leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::MUON) ||
	 (leps[0]->LeptonFlavour() == Lepton::MUON && leps[1]->LeptonFlavour() == Lepton::ELECTRON) ))  return false;


  if(fatjets.size() == 0) return false;;


  TString analyis_string = GetChannelString(channel, analysis_charge);

  bool same_sign =  (RunCF) ? !SameCharge(leps)  : SameCharge(leps);
  if (RunCF && channel!=EE  ) return false;

  if (analysis_charge==SS && !same_sign) return false;
  if (analysis_charge==OS && same_sign) return false;

  FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_lep_charge",param.Name);

  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut)) return false;

  FillEventCutflow(HNL_LeptonCore::SR1,w, "SR1_lep_pt",param.Name);

  Particle ll =  (*leps[0]) + (*leps[1]);
  if (channel==EE  && (fabs(ll.M()-90.) < 15)) return false;
  //if(ll.M() < 20) return false;

  FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_dilep_mass",param.Name);

  double ST = GetST(leps, jets, fatjets, METv);
  double met2_st = pow(METv.Pt(),2.)/ ST;
  bool PassHMMet    = (met2_st < 15);

  int  NBJets_medium      =  bjets.size();
  bool PassBJetMVeto = (NBJets_medium==0);
 
  double LowerMassSR1WmassCut = 40.;
  double UpperMassSR1WmassCut = 130.;

  TString signal_region1 = "HNL_SR1";

  if(GetMass(signal_region1,jets, fatjets) < UpperMassSR1WmassCut  &&GetMass(signal_region1,jets, fatjets) > LowerMassSR1WmassCut){
    
    FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_Wmass",param.Name); 
    if(PassHMMet)     FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_MET",param.Name);
    if(PassHMMet&&PassBJetMVeto)     FillEventCutflow(HNL_LeptonCore::SR1, w, "SR1_bveto",param.Name);

    // fill general high mass plots                                                                                                                                                     
    //    if(PassHMMet&&PassBJetMVeto) Fill_RegionPlots(channel,true,signal_region1 + "_Highmass", param.Name, jets,  fatjets, leps,  METv, nPV, w);
    if(PassHMMet&&PassBJetMVeto) PrintEvent(param, "SR1",w);    
    //if(PassHMMet&&PassBJetMVeto) Fill_All_SignalRegion1(channel, signal_region1, IsDATA, QToString(analysis_charge), param.Name, jets, fatjets,  leps,  METv, nPV  ,w,true);

    if(PassHMMet&&PassBJetMVeto) {

      //Fill Limit plot

      float dijetmass_tmp=999.;
      float dijetmass=9990000.;

      int m=-999;
      double ST(0.);
      for(UInt_t emme=0; emme<jets.size(); emme++){
	ST += jets[emme].Pt();
      }
      for(UInt_t emme=0; emme<fatjets.size(); emme++){
	ST += fatjets[emme].Pt();
	dijetmass_tmp = fatjets[emme].SDMass();
	if ( fabs(dijetmass_tmp-80.4) < fabs(dijetmass-80.4) ) {
	  dijetmass = dijetmass_tmp;
	  m = emme;
	}
      }

      Particle N1cand = fatjets[m] + *leps[0];

      double ml1jbins[7] = { 0., 100.,200.,300.,500., 1000., 2000.};

      FillHist( "SR1/" +  param.Name + "/N1Mass_Central",  N1cand.M(),  w, 6, ml1jbins, "Reco M_{l1jj}");
    }

    /// return true if SR is filled
    if(PassHMMet&&PassBJetMVeto) return true;
  }
  return false;
}

bool  HNL_RegionDefinitions::RunSignalRegionWW(HNL_LeptonCore::Channel channel, HNL_LeptonCore::ChargeType analysis_charge, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet>  fatjets, std::vector<Jet> bjets, Event ev, Particle METv,AnalyzerParameter param, TString channel_string ,  float w){



  std::vector<Lepton *> leps       = MakeLeptonPointerVector(muons,electrons);
  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);



  return RunSignalRegionWW(channel,analysis_charge, leps, leps_veto, jets,fatjets, bjets, ev, METv, param,channel_string, w);
  
}

bool  HNL_RegionDefinitions::RunSignalRegionWW(HNL_LeptonCore::Channel channel, HNL_LeptonCore::ChargeType analysis_charge ,std::vector<Lepton *> leps, std::vector<Lepton *> leps_veto ,  std::vector<Jet> jets, std::vector<FatJet>  fatjets, std::vector<Jet> bjets, Event ev, Particle METv, AnalyzerParameter param, TString channel_string ,  float w){



  double lep1_ptcut= (channel==MuMu) ?   20. : 25.;
  double lep2_ptcut= (channel==MuMu) ?   10. : 15.;

  if (leps.size() != 2 and leps_veto.size() != 2) return false;

  if (channel==EE     && !(leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::ELECTRON)) return false;
  if (channel==MuMu   && !(leps[0]->LeptonFlavour() == Lepton::MUON     && leps[1]->LeptonFlavour() == Lepton::MUON))    return false;
  if ((channel==EMu || channel==MuE)  &&
      !( (leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::MUON) ||
         (leps[0]->LeptonFlavour() == Lepton::MUON && leps[1]->LeptonFlavour() == Lepton::ELECTRON) ))  return false;



  bool same_sign =  (RunCF) ? !SameCharge(leps)  : SameCharge(leps);
  if (analysis_charge==SS && !same_sign) return false;
  if (analysis_charge==OS && same_sign) return false;

  FillEventCutflow(HNL_LeptonCore::SR2,w, "SR2_lep_charge",param.Name);


  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut)) return false;

  FillEventCutflow(HNL_LeptonCore::SR2, w, "SR2_lep_pt",param.Name);
  
  if(!PassVBF(jets,leps)) return false;

  FillEventCutflow(HNL_LeptonCore::SR2, w, "SR2_VBF",param.Name);

  int  NBJets_medium      =  bjets.size();
  bool PassBJetMVeto = (NBJets_medium==0);

  double HT(0.);
  for(UInt_t emme=0; emme<jets.size(); emme++){
    HT += jets[emme].Pt();
  }
  if (HT/leps[1]->Pt() < 2){

    FillEventCutflow(HNL_LeptonCore::SR2, w, "SR2_ht_lt1",param.Name);
    
    if(PassBJetMVeto){
      FillEventCutflow(HNL_LeptonCore::SR2, w, "SR2_bveto",param.Name);
      //PrintEvent(param,"SR2_"+channel_string,w);
      //      Fill_RegionPlots(channel,true,"HNL_"+QToString(analysis_charge)+"WW", param.Name, jets,  fatjets,  leps, METv, nPV, w);
      //FillHist( param.Name+"/HNL_"+QToString(analysis_charge)+"WW/"+ param.Name+"HNL_SSWW_nevent_" ,  1.,  w, 2, 0.,2. );

      
      double HTLT[2] = { 0., 2};
      FillHist( "SR2/" +  param.Name + "/HT_LT1_Central",  HT/leps[1]->Pt(),  w, 1, HTLT, "Reco HT/LT1");
      
      return true;
    }
  }

  return false;
}


bool  HNL_RegionDefinitions::RunSignalRegionAK4(HNL_LeptonCore::Channel channel, HNL_LeptonCore::ChargeType analysis_charge, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet>  fatjets, std::vector<Jet> bjets, Event ev,Particle METv,  AnalyzerParameter param, TString channel_string ,  float w){



  std::vector<Lepton *> leps       = MakeLeptonPointerVector(muons,electrons);
  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);


  return RunSignalRegionAK4(channel, analysis_charge, leps, leps_veto, jets, fatjets, bjets, ev ,METv,param, channel_string, w);
}

bool  HNL_RegionDefinitions::RunSignalRegionAK4(HNL_LeptonCore::Channel channel, HNL_LeptonCore::ChargeType analysis_charge ,std::vector<Lepton *> leps, std::vector<Lepton *> leps_veto ,  std::vector<Jet> jets,std::vector<FatJet>  fatjets, std::vector<Jet> bjets, Event ev, Particle METv, AnalyzerParameter param, TString channel_string ,  float w){
						


  if(run_Debug) cout << "RunSignalRegionSSAK4:start" << endl;
  
  double lep1_ptcut= (channel==MuMu) ?   20. : 25.;
  double lep2_ptcut= (channel==MuMu) ?   10. : 15.;

  if (leps.size() != 2 and leps_veto.size() != 2) return false;

  if (channel==EE     && !(leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::ELECTRON)) return false;
  if (channel==MuMu   && !(leps[0]->LeptonFlavour() == Lepton::MUON     && leps[1]->LeptonFlavour() == Lepton::MUON))    return false;
  if ((channel==EMu || channel==MuE)  &&
      !( (leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::MUON) ||
         (leps[0]->LeptonFlavour() == Lepton::MUON && leps[1]->LeptonFlavour() == Lepton::ELECTRON) ))  return false;


  if(run_Debug) cout <<"RunSignalRegionSSAK4:[1]" <<endl;


  bool same_sign =  (RunCF) ? !SameCharge(leps)  : SameCharge(leps);
  if (analysis_charge==SS && !same_sign) return false;
  if (analysis_charge==OS && same_sign) return false;
  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_lep_charge",param.Name);


  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut)) return false;

  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_lep_pt",param.Name);


  Particle ll =  (*leps[0]) + (*leps[1]);
  if (channel==EE  && (fabs(ll.M()-90.) < 15)) return false;
  //  if(ll.M() < 20) return false;

  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_dilep_mass",param.Name);

  double ST = GetST(leps, jets, fatjets, METv);
  double met2_st = pow(METv.Pt(),2.)/ ST;
  bool PassHMMet    = (met2_st < 15);

  double LowerMassSR3WmassCut = 30.;
  double UpperMassSR3WmassCut = 150.;

  if(jets.size() >0 )FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_jet",param.Name);

  if(jets.size() <2) return false;

  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_dijet",param.Name);

  if(!(GetMass("HNL_SR3", jets, fatjets) < UpperMassSR3WmassCut && GetMass("HNL_SR3", jets, fatjets) > LowerMassSR3WmassCut)) return false;
							   
  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_Wmass",param.Name);

  if(jets[0].Pt() < 25.)  return false;
  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_J1Pt",param.Name);

  if(!PassHMMet) return false;
  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_MET",param.Name);


  int  NBJets      =  bjets.size();
  if(NBJets>  0) return false;

  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_bveto",param.Name);

  //  Run High Mass with main jet collections                                                                                                                
  double FatJetTau21_SF = GetEventFatJetSF(fatjets,"ak8_type1", 0);      
  FillWeightHist(param.Name+"/fatjet_ak8_type1_sf_"+param.Name,FatJetTau21_SF);

  //FIll Limit 
  bool fill_limit_hist=true;
  if(fill_limit_hist){
    int bin = 0;
    
    float dijetmass_tmp=999.;
    float dijetmass=9990000.;
    int m=-999;
    int n=-999;
    double ST(0.);
    for(UInt_t emme=0; emme<jets.size(); emme++){
      ST += jets[emme].Pt();
      for(UInt_t enne=1; enne<jets.size(); enne++) {

	dijetmass_tmp = (jets[emme]+jets[enne]).M();
	if(emme == enne) continue;

	if ( fabs(dijetmass_tmp-80.4) < fabs(dijetmass-80.4) ) {
	  dijetmass = dijetmass_tmp;
	  m = emme;
	  n = enne;
	}
      }
    }
    

    if(jets.size() == 0 && leps[1]->Pt() > 100.) bin=1;
    else     if(jets.size() == 1 && leps[1]->Pt() > 80.) bin=2;
    else{
      
      Particle N1cand = jets[m] + jets[n]+ *leps[0];
      Particle N2cand = jets[m] + jets[n]+ *leps[1];

      if(leps[1]->Pt() < 100) {
	if(N2cand.M() < 100.) bin=3;
	else if(N2cand.M() < 125.) bin=4;
	else if(N2cand.M() < 150.) bin=5;
	else if(N2cand.M() < 175.) bin=6;
	else if(N2cand.M() < 200.) bin=7;
	else bin=8;
      }
      else{
	if(N1cand.M() < 200)  bin=9;
	else  if(N1cand.M() < 250.) bin=10;
	else if(N1cand.M() < 300.) bin=11;
	else if(N1cand.M() < 500.) bin=12;
	else if(N1cand.M() < 1000.) bin=13;
	else bin = 14;
	
      }
    }
    


    FillHist( "SR3/" +  param.Name + "/SignalBins",   bin, w, 14, 0, 14, "Signalbins");
  }

  
  if(jets.size() > 1 && fatjets.size()==0)  {  

    TString signal_region = "HNL_SR3";

    PrintEvent(param,"SR3_"+channel_string,w);
   
    //    Fill_RegionPlots      (channel,true,signal_region+"_Highmass" , param.Name, jets,  fatjets,  leps,  METv, nPV, w);
    //Fill_All_SignalRegion3 (channel, signal_region, IsDATA,  analysis_charge, param.Name, jets, fatjets,  electrons, muons,  METv, nPV ,w ,true);


    return true;
  }// 0 AK8                                                                                                                                                                                 
  
  
  return false;
}



bool HNL_RegionDefinitions::RunSignalRegionTrilepton(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet>  fatjets, std::vector<Jet> bjets, Event ev, Particle METv, AnalyzerParameter param, TString channel_string ,  float w){




  std::vector<Lepton *> leps       = MakeLeptonPointerVector(muons,electrons);
  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);


  return RunSignalRegionTrilepton(channel, leps, leps_veto, jets, fatjets, bjets,ev, METv,param, channel_string, w);

}

bool HNL_RegionDefinitions::RunSignalRegionTrilepton(HNL_LeptonCore::Channel channel,std::vector<Lepton *> leps, std::vector<Lepton *> leps_veto ,  std::vector<Jet> jets ,std::vector<FatJet>  fatjets, std::vector<Jet> bjets, Event ev, Particle METv, AnalyzerParameter param, TString channel_string ,  float w){
  
  
  
  double lep1_ptcut= (channel==MuMuMu) ?   20. : 25.;
  double lep2_ptcut= (channel==MuMuMu) ?   10. : 15.;
  double lep3_ptcut= (channel==MuMuMu) ?   10. : 15.;
  
  if (leps.size() != 2 and leps_veto.size() != 2) return false;
  
  if (channel==EEE     && !(leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::ELECTRON && leps[2]->LeptonFlavour() == Lepton::ELECTRON)) return false;
  if (channel==MuMuMu  && !(leps[0]->LeptonFlavour() == Lepton::MUON     && leps[1]->LeptonFlavour() == Lepton::MUON  && leps[2]->LeptonFlavour() == Lepton::MUON ))    return false;
  if (channel==EEMu    && !((leps[0]->LeptonFlavour() == Lepton::ELECTRON     && leps[1]->LeptonFlavour() == Lepton::ELECTRON  && leps[2]->LeptonFlavour() == Lepton::MUON )||
			    (leps[0]->LeptonFlavour() == Lepton::ELECTRON     && leps[1]->LeptonFlavour() == Lepton::MUON      && leps[2]->LeptonFlavour() == Lepton::ELECTRON )||
			    (leps[0]->LeptonFlavour() == Lepton::MUON         && leps[1]->LeptonFlavour() == Lepton::ELECTRON  && leps[2]->LeptonFlavour() == Lepton::MUON ))) return false;
      
  if (channel==MuMuE   && !((leps[0]->LeptonFlavour() == Lepton::MUON         && leps[1]->LeptonFlavour() == Lepton::MUON  && leps[2]->LeptonFlavour() == Lepton::ELECTRON )||
			    (leps[0]->LeptonFlavour() == Lepton::MUON         && leps[1]->LeptonFlavour() == Lepton::ELECTRON && leps[2]->LeptonFlavour() == Lepton::MUON )||
			    (leps[0]->LeptonFlavour() == Lepton::ELECTRON     && leps[1]->LeptonFlavour() == Lepton::MUON  && leps[2]->LeptonFlavour() == Lepton::ELECTRON ))) return false;


  if (leps.size() < 3) return false ;

  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut && leps[2]->Pt()  > lep3_ptcut)) return false;

  //  HNL_LeptonCore::Channel  channel_lll  = channel;

  FillEventCutflow(HNL_LeptonCore::SR4,w, "SR4_3lep",param.Name);
  
  
  // If running fake bkg now set weight to Fake weight
  //if(RunFake)   w= GetFakeWeightMuon(leps, param);
  if(RunFake)   FillWeightHist(param.Name+"/FakeWeight_"+param.Name,w);

  int n_veto_lep  = leps_veto.size();
  
  bool pass_sr1(true);

  if(n_veto_lep > 3) pass_sr1=false;

  if(pass_sr1)FillEventCutflow(HNL_LeptonCore::SR4,w, "SR4_3lep_veto",param.Name);

 
 
  if(pass_sr1)FillEventCutflow(HNL_LeptonCore::SR4,w, "SR4_3lep_chargereq",param.Name);

  int  NBJets      = bjets.size();

  if (NBJets > 0)pass_sr1=false;
  
  if(pass_sr1)FillEventCutflow(HNL_LeptonCore::SR4,w, "SR4_3lep_bjet",param.Name);
  
  if(ZmasslllWindowCheck(leps)) pass_sr1=false;
  if(pass_sr1)FillEventCutflow(HNL_LeptonCore::SR4,w, "SR4_3lep_Zmlll",param.Name);
  if(ZmassOSWindowCheck(leps)) pass_sr1=false;
  if(pass_sr1)FillEventCutflow(HNL_LeptonCore::SR4,w, "SR4_3lep_Zmll_os",param.Name);

  
  if(pass_sr1)  {
    // For Cut flow comparison
    PrintEvent(param,"SR4_"+channel_string,w);    
    // For event cut flow
    FillEventCutflow(HNL_LeptonCore::SR4, w, "SR4_lll_mu",param.Name);
    // Make histograms generically
    //    Fill_RegionPlots(channel_lll,true,"HNL_SR4_lll" , param.Name, jets,  fatjets,  leps,  METv, nPV, w);
    // make limit inout plots
    //Fill_SigRegionPlots4(channel_lll, param.Name, jets,  fatjets, leps,  METv, nPV, w);

    FillEventCutflow(SR,w, "SR4Pass",param.Name);

  }

  if(!pass_sr1)     FillEventCutflow(SR,w, "SR4Fail",param.Name);

  return pass_sr1;
 
  
}



HNL_RegionDefinitions::HNL_RegionDefinitions(){
      


}
 
HNL_RegionDefinitions::~HNL_RegionDefinitions(){

}




bool HNL_RegionDefinitions::PassVBFInitial(vector<Jet>  jets){

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

  if(maxDiJetDeta < 2.5) return false;
  Particle JJ = jets[ijet1] + jets[ijet2];
  if(JJ.M() < 450.) return false;

  return true;


}

bool HNL_RegionDefinitions::PassVBF(vector<Jet>  jets,std::vector<Lepton *> leps, bool use_leadjets){

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
  if(use_leadjets){ijet1=0;ijet2=1;}
  
  if(maxDiJetDeta < 2.5) return false;
  Particle JJ = jets[ijet1] + jets[ijet2];
  if(JJ.M() < 450.) return false;
  double Av_JetEta= 0.5*(jets[ijet1].Eta()+ jets[ijet2].Eta());
  double zeppenfeld = TMath::Max((*leps[0]).Eta()  - Av_JetEta , (*leps[1]).Eta()  - Av_JetEta ) /maxDiJetDeta;

  if(zeppenfeld > 0.75) return false;

  return true;
}





void HNL_RegionDefinitions::RunElectronChannelCR(std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<Jet> jets_vbf,   std::vector<FatJet> fatjets, std::vector<Jet> bjets,  Event ev, Particle METv, AnalyzerParameter param,  float weight_ee ){


  if(IsDATA &&  DataYear==2016 &&   !(this->DataStream == "DoubleEG"  )) return;
  if(IsDATA &&  DataYear==2017 &&   !(this->DataStream == "DoubleEG"  )) return;
  if(IsDATA &&  DataYear==2018 &&   !(this->DataStream == "EGamma"  )) return;



  if(!IsDATA) weight_ee*= GetElectronSFEventWeight(electrons, param);

  TString label    = param.Name;

  if(!PassMETFilter()) return;


  //=== Trigger                                                                                                    
  bool PassDoubleElectronTrig = ev.PassTrigger(Trigger_HNL_Electron);


  if(!(PassDoubleElectronTrig)) return;
  if(electrons.size() < 2) return;
  if(electrons[0].Pt() < 25) return;
  if(electrons[1].Pt() < 15) return;

  if(RunFake)   weight_ee= GetFakeWeightElectron(electrons, Trigger_HNL_Electron,param);
  if(RunFake)      FillWeightHist("FakeEE_"+param.Name , weight_ee);

  if(RunCF && electrons.size() != 2) return;
  if(RunCF && muons_veto.size() > 0) return;

  Fill_RegionPlots(EE, true,"Inclusive" , param.Name+"_Electron", jets,  fatjets,  electrons, muons,  ev.GetMETVector(), nPV, weight_ee);
  Fill_RegionPlots(EE, false,"Inclusive" , param.Name+"_Electron", jets_vbf,  fatjets,  electrons, muons,  ev.GetMETVector(), nPV, weight_ee);
  



  //OS CR                                                                                                                                                                                                          

  vector<TString> passed;
  if(FillZCRPlots  (EE, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_ee)) passed.push_back("ZAK8_CR");
  if(FillTopCRPlots(EE, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_ee)) passed.push_back("TopAK8_CR");
  if(FillSSPreselectionPlots(EE, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_ee)) passed.push_back("SSPresel");
  if(FillSSVBFPreselectionPlots(EE, electrons, electrons_veto, muons,  muons_veto, jets_vbf, fatjets, bjets, ev, METv, param, weight_ee)) passed.push_back("SSVBFPresel");
  if(FillOSPreselectionPlots(EE, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_ee)) passed.push_back("OSPresel");
  //VBF CR                                                                                                                                                                                                         
  if(FillWWCRPlots  (EE, electrons, electrons_veto, muons,  muons_veto, jets_vbf, fatjets, bjets, ev, METv, param, weight_ee)) passed.push_back("WpWp_CR");
  if(FillWWNPCRPlots(EE, electrons, electrons_veto, muons,  muons_veto, jets_vbf, fatjets, bjets, ev, METv, param, weight_ee)) passed.push_back("WpWpNP_CR");
  if(FillWZ2CRPlots (EEE, electrons, electrons_veto, muons,  muons_veto, jets_vbf, fatjets, bjets, ev, METv, param, weight_ee)) passed.push_back("WZ2_CR");
  if(FillWZBCRPlots (EEE, electrons, electrons_veto, muons,  muons_veto, jets_vbf, fatjets, bjets, ev, METv, param, weight_ee)) passed.push_back("WZB_CR");

  // LLL+                                                                                                                                                                                                          
  if(FillZZCRPlots( EEEE, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_ee)) passed.push_back("ZZ_CR");
  if(FillZZ2CRPlots( EEEE, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_ee)) passed.push_back("ZZLoose_CR");
  if(FillWZCRPlots( EEE, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_ee)) passed.push_back("WZ_CR");
  if(FillWGCRPlots( EEE, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_ee)) passed.push_back("WG_CR");
  if(FillZGCRPlots( EEE, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_ee)) passed.push_back("ZG_CR");
  if(FillZNPCRPlots(EEE, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_ee)) passed.push_back("ZNP_CR");

  // 17-028 +CR                                                                                                                                                                                                    
  if(FillHighMassSR1CRPlots(EE, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_ee)) passed.push_back("HighMassSR1_CR");
  if(FillHighMassSR2CRPlots(EE, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_ee)) passed.push_back("HighMassSR2_CR");
  if(FillHighMass1JetCRPlots(EE, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_ee)) passed.push_back("HighMass1Jet_CR");
  if(FillHighMassBJetCRPlots(EE, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_ee)) passed.push_back("HighMassBJet_CR");
  if(FillHighMassNPCRPlots(EE, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_ee)) passed.push_back("HighMassNP_CR");


  vector<TString> cutlabels = { "TopAK8_CR","ZAK8_CR","WpWp_CR","WpWpNP_CR","ZZ_CR","ZZLoose_CR","ZG_CR","WG_CR","WZ_CR","WZ2_CR","WZB_CR","HighMassSR1_CR","HighMassSR2_CR","HighMass1Jet_CR","HighMassBJet_CR","HighMassNP_CR","ZNP_CR","SSPresel","OSPresel","SSVBFPresel"};



  for(unsigned int ipass =0; ipass < passed.size();ipass++){
    //void AnalyzerCore::FillTypeCutflow(TString histname, double weight, vector<TString> lables, TString label1, TString label2){                                                                                 
    for(unsigned int ipass2=ipass+1; ipass2 < passed.size(); ipass2++){

      FillTypeCutflow("EE_CR_Correlation"+param.Name, weight_ee, cutlabels, passed[ipass], passed[ipass2]);
    }
  }
  return;
}



void HNL_RegionDefinitions::RunMuonChannelCR(std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<Jet> jets_vbf, std::vector<FatJet> fatjets, std::vector<Jet> bjets,  Event ev, Particle METv, AnalyzerParameter param,  float weight_mm ){


  if(IsDATA &&  !(this->DataStream.Contains("Muon"))) return;  // SingleMuon + DoubleMuon                                                                                                                          

  if(!IsDATA) weight_mm*= GetMuonSFEventWeight(muons, param);

  //HNL_LeptonCore::Channel  channel  = MuMu;

  /// Get MET l corrected for jet smearing in MC                                                                                                                                                                   

  if(!PassMETFilter()) return;

  //=== Apply trigger                                                                                                                                                                                              
  bool PassDoubleMuonTrig = ev.PassTrigger(Trigger_HNL_Muon);
  //bool PassHighPtMuonTrig = ev.PassTrigger(Trigger_HNL_HighPtMuon);

  if(!(PassDoubleMuonTrig)) return;

  if(muons.size() <2) return;
  if(muons[0].Pt() < 20) return;
  if(muons[1].Pt() < 10) return;

  if(!IsDATA && DataEra=="2016postVFP"){

    double dimu_trig_weight=0.;
    if(ev.PassTrigger(Trigger_HNL_Muon))  dimu_trig_weight += 8348.4792;
    if(ev.PassTrigger(Trigger_HNL_MuonH)) dimu_trig_weight += 8463.6725;

    weight_mm *= (dimu_trig_weight / ev.GetTriggerLumi("Full"));
  }

  //double AnalyzerCore::GetFakeWeightMuon(std::vector<Muon> muons , vector<TString> trigs, AnalyzerParameter param){                                                                                              

  if(RunFake)   weight_mm= GetFakeWeightMuon(muons, Trigger_HNL_Muon,param);
  if(RunFake)    FillWeightHist("FakeMM_"+param.Name , weight_mm);

  Fill_RegionPlots(MuMu, true,"Inclusive" , param.Name+"_Muon", jets,  fatjets,  electrons, muons,  ev.GetMETVector(), nPV, weight_mm);
  Fill_RegionPlots(MuMu, false,"Inclusive" , param.Name+"_Muon", jets_vbf,  fatjets,  electrons, muons,  ev.GetMETVector(), nPV, weight_mm);




  vector<TString> passed;
  if(FillZCRPlots  (MuMu, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_mm)) passed.push_back("ZAK8_CR");
  if(FillTopCRPlots(MuMu, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_mm)) passed.push_back("TopAK8_CR");
  if(FillSSPreselectionPlots(MuMu, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_mm)) passed.push_back("SSPresel");
  if(FillSSVBFPreselectionPlots(MuMu, electrons, electrons_veto, muons,  muons_veto, jets_vbf, fatjets, bjets, ev, METv, param, weight_mm)) passed.push_back("SSVBFPresel");
  if(FillOSPreselectionPlots(MuMu, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_mm)) passed.push_back("OSPresel");
  //VBF CR                                                                                                                                                                                                         
  if(FillWWCRPlots  (MuMu, electrons, electrons_veto, muons,  muons_veto, jets_vbf, fatjets, bjets, ev, METv, param, weight_mm)) passed.push_back("WpWp_CR");
  if(FillWWNPCRPlots(MuMu, electrons, electrons_veto, muons,  muons_veto, jets_vbf, fatjets, bjets, ev, METv, param, weight_mm)) passed.push_back("WpWpNP_CR");
  if(FillWZ2CRPlots (MuMuMu, electrons, electrons_veto, muons,  muons_veto, jets_vbf, fatjets, bjets, ev, METv, param, weight_mm)) passed.push_back("WZ2_CR");
  if(FillWZBCRPlots (MuMuMu, electrons, electrons_veto, muons,  muons_veto, jets_vbf, fatjets, bjets, ev, METv, param, weight_mm)) passed.push_back("WZB_CR");

  // LLL+                                                                                                                                                                                                          
  if(FillZZCRPlots( MuMuMuMu, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_mm)) passed.push_back("ZZ_CR");
  if(FillZZ2CRPlots( MuMuMuMu, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_mm)) passed.push_back("ZZLoose_CR");
  if(FillWZCRPlots( MuMuMu, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_mm)) passed.push_back("WZ_CR");
  if(FillWGCRPlots( MuMuMu, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_mm)) passed.push_back("WG_CR");
  if(FillZGCRPlots( MuMuMu, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_mm)) passed.push_back("ZG_CR");
  if(FillZNPCRPlots(MuMuMu, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_mm)) passed.push_back("ZNP_CR");

  // 17-028 +CR                                                                                                                                                                                                    
  if(FillHighMassSR1CRPlots(MuMu, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_mm)) passed.push_back("HighMassSR1_CR");
  if(FillHighMassSR2CRPlots(MuMu, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_mm)) passed.push_back("HighMassSR2_CR");
  if(FillHighMass1JetCRPlots(MuMu, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_mm)) passed.push_back("HighMass1Jet_CR");
  if(FillHighMassBJetCRPlots(MuMu, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_mm)) passed.push_back("HighMassBJet_CR");
  if(FillHighMassNPCRPlots(MuMu, electrons, electrons_veto, muons,  muons_veto, jets, fatjets, bjets, ev, METv, param, weight_mm)) passed.push_back("HighMassNP_CR");



  vector<TString> cutlabels = { "TopAK8_CR","ZAK8_CR","WpWp_CR","WpWpNP_CR","ZZ_CR","ZZLoose_CR","ZG_CR","WG_CR","WZ_CR","WZ2_CR","WZB_CR","HighMassSR1_CR","HighMassSR2_CR","HighMass1Jet_CR","HighMassBJet_CR","HighMassNP_CR","ZNP_CR","SSPresel","OSPresel","SSVBFPresel"};

  for(unsigned int ipass =0; ipass < passed.size();ipass++){
    //void AnalyzerCore::FillTypeCutflow(TString histname, double weight, vector<TString> lables, TString label1, TString label2){                                                                                 
    for(unsigned int ipass2=0; ipass2 < passed.size(); ipass2++){

      FillTypeCutflow("MM_CR_Correlation"+param.Name, weight_mm, cutlabels, passed[ipass], passed[ipass2]);
    }
  }

  return;
}


bool HNL_RegionDefinitions::FillTopCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto   , std::vector< Jet> jets, std::vector<FatJet> fatjets, std::vector< Jet> bjets,  Event ev, Particle METv, AnalyzerParameter param, float w){


  TString channel_string = GetChannelString(channel);

  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);
  std::vector<Lepton *> leps  = MakeLeptonPointerVector(muons,electrons);


  double lep1_ptcut= (channel==MuMu) ?   20. : 25.;
  double lep2_ptcut= (channel==MuMu) ?   10. : 15.;


  if (leps.size() != 2 and leps_veto.size() != 2) return false;

  if (channel==EE     && !(leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::ELECTRON)) return false;
  if (channel==MuMu   && !(leps[0]->LeptonFlavour() == Lepton::MUON     && leps[1]->LeptonFlavour() == Lepton::MUON))    return false;
  if ((channel==EMu || channel==MuE)  &&
      !( (leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::MUON) ||
         (leps[0]->LeptonFlavour() == Lepton::MUON && leps[1]->LeptonFlavour() == Lepton::ELECTRON) ))  return false;




  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut)) return false;

  if(METv.Pt() < 50) return false;
  
  int NBJets = bjets.size();
  if(NBJets == 0) return false;
  if(fatjets.size() == 0) return false;

  if(run_Debug){
    cout << "HNL_TopAK8_TwoLepton_CR " << event << endl;
    for(auto ilep: leps) cout << "HNL_TopAK8_TwoLepton_CR Type " <<  GetLeptonType(*ilep, gens) << endl;
    //PrintGen(gens);                                                                                                                                                                                              
  }
  Fill_RegionPlots(channel, true,"HNL_TopAK8_TwoLepton_CR" , param.Name+"_"+channel_string, jets  ,fatjets,  electrons, muons,  METv, nPV, w);
  if(!param.Name.Contains("_noconv")) Fill_RegionPlots(channel, true,"HNL_TopAK8_TwoLepton_CR" , param.Name, jets,  fatjets,  electrons, muons,  METv, nPV, w);

  return true;
}



bool HNL_RegionDefinitions::FillZNPCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto   , std::vector<Jet> jets, std::vector<FatJet> fatjets, std::vector<Jet> bjets,  Event ev, Particle METv, AnalyzerParameter param, float w){

  TString channel_string= (channel==EEE) ?  "Electron" : "Muon";

  std::vector<Lepton *> leps  = MakeLeptonPointerVector(muons,electrons);
  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);


  if(channel==MuMuMu && !(muons.size() ==3 && electrons_veto.size() == 0 && muons_veto.size()==3)) return false;
  if(channel==EEE   && !(electrons.size() ==3 && electrons_veto.size() == 3 && muons_veto.size()==0)) return false;

  double lep1_ptcut= (channel==EEE) ?   25. : 20.;
  double lep2_ptcut= (channel==EEE) ?   15. : 10.;
  double lep3_ptcut= (channel==EEE) ?   10. : 10.;
  if(DataEra=="2017" || DataEra=="2018"){
    lep2_ptcut= 15;
    lep3_ptcut= 15;
  }

  double metcut = 30.;
  double mtcut = 30.;

  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut && leps[2]->Pt()  > lep3_ptcut)) return false;

  if(METv.Pt() > metcut) return false;
  if(GetIndexNonBestZ(leps,15.) < 0) return false;
  if(M_T((*leps[GetIndexNonBestZ(leps,15.)]), METv) > mtcut) return false;

  if(run_Debug){
    cout << "HNL_ZNP_ThreeLepton_CR " << param.Name+"_"+channel_string << " " << event  << endl;
    for(auto ilep: leps) cout << "HNL_ZNP_ThreeLepton_CR Type " <<  GetLeptonType(*ilep, gens) << endl;
  }

  Fill_RegionPlots(channel,true,"HNL_ZNP_ThreeLepton_CR" , param.Name+"_"+channel_string, jets,  fatjets,  electrons, muons,  METv, nPV, w);
  if(!param.Name.Contains("_noconv"))Fill_RegionPlots(channel,true,"HNL_ZNP_ThreeLepton_CR" , param.Name, jets,  fatjets,  electrons, muons,  METv, nPV, w);

  return true;

}

bool HNL_RegionDefinitions::FillZCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto   , std::vector<Jet> jets, std::vector<FatJet> fatjets,  std::vector< Jet> bjets,Event ev, Particle METv, AnalyzerParameter param, float w){


  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);
  std::vector<Lepton *> leps  = MakeLeptonPointerVector(muons,electrons);


  TString channel_string = GetChannelString(channel);


  double lep1_ptcut= (channel==MuMu) ?   20. : 25.;
  double lep2_ptcut= (channel==MuMu) ?   10. : 15.;

  if(DataEra=="2017" || DataEra=="2018"){
    lep2_ptcut= 15;
  }

  if (leps.size() != 2 and leps_veto.size() != 2) return false;
  
  if (channel==EE     && !(leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::ELECTRON)) return false;
  if (channel==MuMu   && !(leps[0]->LeptonFlavour() == Lepton::MUON     && leps[1]->LeptonFlavour() == Lepton::MUON))    return false;
  if ((channel==EMu || channel==MuE)  &&
      !( (leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::MUON) ||
         (leps[0]->LeptonFlavour() == Lepton::MUON && leps[1]->LeptonFlavour() == Lepton::ELECTRON) ))  return false;

  
  
  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut)) return false;
  
  if(METv.Pt() > 30) return false;
  int NBJets = bjets.size();
  if(NBJets > 0) return false;
  if(fatjets.size() == 0) return false;

  Particle  ll = (*leps[0]) + (*leps[1]);

  if(ll.Charge() != 0) return false;
  if (fabs(ll.M()-90.) > 15) return false;

  if(run_Debug){
    cout << "HNL_ZAK8_TwoLepton_CR " << param.Name+"_"+channel_string << " " << event  << endl;
    for(auto ilep: leps) cout << "HNL_ZAK8_TwoLepton_CR Type " <<  GetLeptonType(*ilep, gens) << endl;
  }
  Fill_RegionPlots(channel, true,"HNL_ZAK8_TwoLepton_CR" , param.Name+"_"+channel_string, jets , fatjets,  electrons, muons,  METv, nPV, w);
  if(!param.Name.Contains("_noconv"))Fill_RegionPlots(channel, true,"HNL_ZAK8_TwoLepton_CR" , param.Name, jets,  fatjets,  electrons, muons,  METv, nPV, w);

  return true;

}


bool HNL_RegionDefinitions::FillWWCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto   , std::vector<Jet> jets_eta5, std::vector<FatJet> fatjets,  std::vector< Jet> bjets,Event ev, Particle METv, AnalyzerParameter param, float w){
  
  
  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);
  std::vector<Lepton *> leps  = MakeLeptonPointerVector(muons,electrons);
  
  TString channel_string = GetChannelString(channel);
  

  double lep1_ptcut= (channel==MuMu) ?   20. : 25.;
  double lep2_ptcut= (channel==MuMu) ?   10. : 15.;
  
  if(DataEra=="2017" || DataEra=="2018"){
    lep2_ptcut= 15;
  }
  
  if (leps.size() != 2 and leps_veto.size() != 2) return false;

  if (channel==EE     && !(leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::ELECTRON)) return false;
  if (channel==MuMu   && !(leps[0]->LeptonFlavour() == Lepton::MUON     && leps[1]->LeptonFlavour() == Lepton::MUON))    return false;
  if ((channel==EMu || channel==MuE)  &&
      !( (leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::MUON) ||
         (leps[0]->LeptonFlavour() == Lepton::MUON && leps[1]->LeptonFlavour() == Lepton::ELECTRON) ))  return false;



  if(jets_eta5.size() < 2) return false;


  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut)) return false;
  
  if(!RunCF){
    if(leps[0]->Charge() == leps[1]->Charge()) return false;
  }
  else{
    if(leps[0]->Charge() != leps[1]->Charge()) return false;
  }

  std::vector<Jet> jets                  = GetAK4Jets(jets_eta5, 20., 2.5, true,  0.4,0.8,"",    electrons_veto, muons_veto,fatjets);
  int NBJets = bjets.size();
  /***
   //file:///Users/john/Downloads/AN2019_089_v7.pdf SSWW +WZ  + AN2020_045  
   //https://arxiv.org/pdf/2005.01173.pdf 
   **/

  
  Particle ll =  (channel==EE) ?  electrons[0]  + electrons[1] : muons[0]+muons[1];


  // two highest pt jets with    
  Jet j1 = jets_eta5[0] ;
  Jet j2 = jets_eta5[1];
  if(!(j1.Pt() > 30.) && (j2.Pt() > 30.)) return false;
  if ( ll.M() < 20.) return false;
  if ( METv.Pt() < 30.) return false;
  if (NBJets>0) return false;
  if ((j1+j2).M() < 500.) return false;

  double DiJetDeta = fabs(j1.Eta() - j2.Eta());
  if (DiJetDeta  <2.5) return false;

  double Av_JetEta= 0.5*(j1.Eta()+ j2.Eta());
  double zeppenfeld = TMath::Max(leps[0]->Eta()  - Av_JetEta , (leps[1])->Eta()  - Av_JetEta ) /DiJetDeta;
  if (zeppenfeld > 0.75) return false;
  if (channel==EE  && (fabs(ll.M()-90.) < 15)) return false;

  if(run_Debug){
    cout << "HNL_WpWp_TwoLepton_CR " << param.Name+"_"+channel_string << " " << event  << endl;
    for(auto ilep: leps) cout << "HNL_WpWp_TwoLepton_CR Type " <<  GetLeptonType(*ilep, gens) << endl;
  }
  Fill_RegionPlots(channel, true,"HNL_WpWp_TwoLepton_CR" , param.Name+"_"+channel_string, jets_eta5,  fatjets,  electrons, muons,  METv, nPV, w);



  if(!param.Name.Contains("_noconv")) Fill_RegionPlots(channel, true,"HNL_WpWp_TwoLepton_CR" , param.Name, jets_eta5,  fatjets,  electrons, muons,  METv, nPV, w);

  return true;

}



bool HNL_RegionDefinitions::FillWWNPCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto   , std::vector<Jet> jets_eta5, std::vector<FatJet> fatjets,std::vector< Jet> bjets,  Event ev, Particle METv, AnalyzerParameter param, float w){


  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);
  std::vector<Lepton *> leps  = MakeLeptonPointerVector(muons,electrons);
  
  TString channel_string = GetChannelString(channel);


  double lep1_ptcut= (channel==MuMu) ?   20. : 25.;
  double lep2_ptcut= (channel==MuMu) ?   10. : 15.;

  if(DataEra=="2017" || DataEra=="2018"){
    lep2_ptcut= 15;
  }
  
  if (leps.size() != 2 and leps_veto.size() != 2) return false;
  
  if (channel==EE     && !(leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::ELECTRON)) return false;
  if (channel==MuMu   && !(leps[0]->LeptonFlavour() == Lepton::MUON     && leps[1]->LeptonFlavour() == Lepton::MUON))    return false;
  if ((channel==EMu || channel==MuE)  &&
      !( (leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::MUON) ||
         (leps[0]->LeptonFlavour() == Lepton::MUON && leps[1]->LeptonFlavour() == Lepton::ELECTRON) ))  return false;
  
  
  if(jets_eta5.size() < 2) return false;
  
  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut)) return false;

  if(!RunCF){
    if(leps[0]->Charge() == leps[1]->Charge()) return false;
  }
  else{
    if(leps[0]->Charge() != leps[1]->Charge()) return false;
  }



  std::vector<Jet> jets                  = GetAK4Jets(jets_eta5, 20., 2.5, true,  0.4,0.8,"",    electrons_veto, muons_veto,fatjets);
  int NBJets = bjets.size();
  //file:///Users/john/Downloads/AN2019_089_v7.pdf SSWW +WZ  + AN2020_045
  //https://arxiv.org/pdf/2005.01173.pdf 
  
  Particle ll =  (channel==EE) ?  electrons[0]  + electrons[1] : muons[0]+muons[1];
  
  // two highest pt jets with   
  
  Jet j1 = jets_eta5[0] ;
  Jet j2 = jets_eta5[1];
  if(!(j1.Pt() > 30.) && (j2.Pt() > 30.)) return false;
  
  if ( METv.Pt() < 30.) return false;
  if (NBJets>0) return false;
  if ((j1+j2).M() < 500.) return false;
  
  double DiJetDeta = fabs(j1.Eta() - j2.Eta());
  if (DiJetDeta  <2.5) return false;

  double Av_JetEta= 0.5*(j1.Eta()+ j2.Eta());
  double zeppenfeld = TMath::Max((leps[0])->Eta()  - Av_JetEta , leps[1]->Eta()  - Av_JetEta ) /DiJetDeta;
  if (zeppenfeld > 0.75) return false;
  if (channel==EE  && (fabs(ll.M()-90.) < 15)) return false;



  if(run_Debug){
    cout << "HNL_WpWpNP_TwoLepton_CR " << param.Name+"_"+channel_string << " " << event  << endl;
    for(auto ilep: leps) cout << "HNL_WpWpNP_TwoLepton_CR Type " <<  GetLeptonType(*ilep, gens) << endl;
  }

  Fill_RegionPlots(channel, true,"HNL_WpWpNP_TwoLepton_CR" , param.Name+"_"+channel_string, jets_eta5,  fatjets,  electrons, muons,  METv, nPV, w);

  if(!param.Name.Contains("_noconv")) Fill_RegionPlots(channel, true,"HNL_WpWpNP_TwoLepton_CR" , param.Name, jets_eta5,  fatjets,  electrons, muons,  METv, nPV, w);

  return true;

}


bool HNL_RegionDefinitions::FillOSPreselectionPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto   , std::vector<Jet> jets, std::vector<FatJet> fatjets, std::vector<Jet> bjets,  Event ev, Particle METv, AnalyzerParameter param, float w){


  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);
  std::vector<Lepton *> leps  = MakeLeptonPointerVector(muons,electrons);

  TString channel_string = GetChannelString(channel);


  double lep1_ptcut= (channel==MuMu) ?   20. : 25.;
  double lep2_ptcut= (channel==MuMu) ?   10. : 15.;

  if(DataEra=="2017" || DataEra=="2018"){
    lep2_ptcut= 15;
  }

  if (leps.size() != 2 and leps_veto.size() != 2) return false;

  if (channel==EE     && !(leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::ELECTRON)) return false;
  if (channel==MuMu   && !(leps[0]->LeptonFlavour() == Lepton::MUON     && leps[1]->LeptonFlavour() == Lepton::MUON))    return false;
  if ((channel==EMu || channel==MuE)  &&
      !( (leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::MUON) ||
         (leps[0]->LeptonFlavour() == Lepton::MUON && leps[1]->LeptonFlavour() == Lepton::ELECTRON) ))  return false;

  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut)) return false;

  if(!RunCF){
    if(leps[0]->Charge() == leps[1]->Charge()) return false;
  }
  else{
    if(leps[0]->Charge() != leps[1]->Charge()) return false;
  }
  Particle ll =  (*leps[0]) + (*leps[1]);
  if (channel==EE  && (fabs(ll.M()-90.) < 15)) return false;
  if(ll.M() < 110) return false;

  //double ST = GetST(electrons, muons, jets, fatjets, ev);
  //  double met2_st = pow(METv.Pt(),2.)/ ST;

  int njet = fatjets.size();

  if(njet < 1) return false;

  Fill_RegionPlots(channel,true,"HNL_OSPresel_TwoLepton"  , param.Name+"_"+channel_string, jets,  fatjets,  electrons, muons,  METv, nPV, w);
  if(!param.Name.Contains("_noconv")) Fill_RegionPlots(channel, true,"HNL_OSPresel_TwoLepton" , param.Name, jets,  fatjets,  electrons, muons,  METv, nPV, w);



  return true;

}


bool HNL_RegionDefinitions::FillSSPreselectionPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto   , std::vector<Jet> jets, std::vector<FatJet> fatjets, std::vector<Jet> bjets,  Event ev, Particle METv, AnalyzerParameter param, float w){



  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);
  std::vector<Lepton *> leps  = MakeLeptonPointerVector(muons,electrons);

  TString channel_string = GetChannelString(channel);


  double lep1_ptcut= (channel==MuMu) ?   20. : 25.;
  double lep2_ptcut= (channel==MuMu) ?   10. : 15.;


  if (leps.size() != 2 and leps_veto.size() != 2) return false;

  if (channel==EE     && !(leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::ELECTRON)) return false;
  if (channel==MuMu   && !(leps[0]->LeptonFlavour() == Lepton::MUON     && leps[1]->LeptonFlavour() == Lepton::MUON))    return false;
  if ((channel==EMu || channel==MuE)  && 
      !( (leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::MUON) ||
         (leps[0]->LeptonFlavour() == Lepton::MUON && leps[1]->LeptonFlavour() == Lepton::ELECTRON) ))  return false;



  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut)) return false;


  if(!RunCF){
    if(leps[0]->Charge() != leps[1]->Charge()) return false;
  }
  else{
    if(leps[0]->Charge() == leps[1]->Charge()) return false;
  }
  Particle ll =  (*leps[0]) + (*leps[1]);
  if (channel==EE  && (fabs(ll.M()-90.) < 15)) return false;
  if(ll.M() < 20) return false;

  //double ST = GetST(electrons, muons, jets, fatjets, ev);
  //double met2_st = pow(METv.Pt(),2.)/ ST;

  int njets = jets.size() + fatjets.size();

  if(njets < 1) return false;

  Fill_RegionPlots(channel,true,"HNL_SSPresel_TwoLepton"  , param.Name+"_"+channel_string, jets,  fatjets,  electrons, muons,  METv, nPV, w);
  if(!param.Name.Contains("_noconv")) Fill_RegionPlots(channel, true,"HNL_SSPresel_TwoLepton" , param.Name, jets,  fatjets,  electrons, muons,  METv, nPV, w);
  return true;

}



bool HNL_RegionDefinitions::FillSSVBFPreselectionPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto , std::vector<Jet> jets_vbf, std::vector<FatJet> fatjets, std::vector<Jet> bjets,  Event ev, Particle METv, AnalyzerParameter param, float w){


  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);
  std::vector<Lepton *> leps  = MakeLeptonPointerVector(muons,electrons);

  TString channel_string = GetChannelString(channel);


  double lep1_ptcut= (channel==MuMu) ?   20. : 25.;
  double lep2_ptcut= (channel==MuMu) ?   10. : 15.;

  if(DataEra=="2017" || DataEra=="2018"){
    lep2_ptcut= 15;
  }

  if (leps.size() != 2 and leps_veto.size() != 2) return false;

  if (channel==EE     && !(leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::ELECTRON)) return false;
  if (channel==MuMu   && !(leps[0]->LeptonFlavour() == Lepton::MUON     && leps[1]->LeptonFlavour() == Lepton::MUON))    return false;
  if ((channel==EMu || channel==MuE)  &&
      !( (leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::MUON) ||
         (leps[0]->LeptonFlavour() == Lepton::MUON && leps[1]->LeptonFlavour() == Lepton::ELECTRON) ))  return false;

  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut)) return false;


  std::vector<Jet> jets                  = GetAK4Jets(jets_vbf, 20., 2.5, true,  0.4,0.8,"",    electrons_veto, muons_veto,fatjets);

  if(!RunCF){
    if(leps[0]->Charge() != leps[1]->Charge()) return false;
  }
  else{
    if(leps[0]->Charge() == leps[1]->Charge()) return false;
  }
  Particle ll =  (*leps[0]) + (*leps[1]);
  if (channel==EE  && (fabs(ll.M()-90.) < 15)) return false;
  if(ll.M() < 20) return false;


  if(jets_vbf.size() < 2) return false;

  Fill_RegionPlots(channel,true,"HNL_SSVBFPresel_TwoLepton"  , param.Name+"_"+channel_string, jets_vbf,  fatjets,  electrons, muons,  METv, nPV, w);
  if(!param.Name.Contains("_noconv")) Fill_RegionPlots(channel, true,"HNL_SSVBFPresel_TwoLepton" , param.Name, jets_vbf,  fatjets,  electrons, muons,  METv, nPV, w);

  return true;

}

bool HNL_RegionDefinitions::FillHighMassSR1CRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto   , std::vector<Jet> jets, std::vector<FatJet> fatjets, std::vector<Jet> bjets,  Event ev, Particle METv, AnalyzerParameter param, float w){


  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);
  std::vector<Lepton *> leps  = MakeLeptonPointerVector(muons,electrons);

  TString channel_string = GetChannelString(channel);


  double lep1_ptcut= (channel==MuMu) ?   20. : 25.;
  double lep2_ptcut= (channel==MuMu) ?   10. : 15.;

  if(DataEra=="2017" || DataEra=="2018"){
    lep2_ptcut= 15;
  }

  if (leps.size() != 2 and leps_veto.size() != 2) return false;

  if (channel==EE     && !(leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::ELECTRON)) return false;
  if (channel==MuMu   && !(leps[0]->LeptonFlavour() == Lepton::MUON     && leps[1]->LeptonFlavour() == Lepton::MUON))    return false;
  if ((channel==EMu || channel==MuE)  &&
      !( (leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::MUON) ||
         (leps[0]->LeptonFlavour() == Lepton::MUON && leps[1]->LeptonFlavour() == Lepton::ELECTRON) ))  return false;


  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut)) return false;

  int NBJets = bjets.size();

  if(!RunCF){
    if(leps[0]->Charge() != leps[1]->Charge()) return false;
  }
  else{
    if(leps[0]->Charge() == leps[1]->Charge()) return false;
  }
  Particle ll =  (*leps[0]) + (*leps[1]);
  if (channel==EE  && (fabs(ll.M()-90.) < 15)) return false;
  if(ll.M() < 20) return false;

  double ST = GetST(electrons, muons, jets, fatjets, ev);
  double met2_st = pow(METv.Pt(),2.)/ ST;
  bool PassHMMet    = (met2_st < 20);


  double LowerMassSR1WmassCut = 30.;
  double UpperMassSR1WmassCut = 150.;

  if(jets.size() <2) return false;

  if(!(GetMass("HNL_SR1", jets, fatjets) < UpperMassSR1WmassCut && GetMass("HNL_SR1", jets, fatjets) > LowerMassSR1WmassCut)) return false;

  if(PassHMMet && NBJets==0) return false;

  if(run_Debug){
    cout << "HNL_HighMassSR1_TwoLepton_CR " << param.Name+"_"+channel_string << " " << event  << endl;
    for(auto ilep: leps){
      Gen gen_closest = GetGenMatchedLepton(*ilep, gens);

      cout << "HNL_HighMassSR1_TwoLepton_CR Type " <<  GetLeptonType(*ilep, gens) << " " << ilep->Pt() << " " << ilep->Eta() << " " << ilep->Phi() << " matched gen = " <<  gen_closest.Index() << endl;


    }

    PrintGen(gens);

    cout << "HNL_HighMassSR1_TwoLepton_CR " << param.Name+"_"+channel_string << " " << event  << endl;
    for(auto ilep: leps)  cout << "HNL_HighMassSR1_TwoLepton_CR Type " <<  GetLeptonType(*ilep, gens) << " " << ilep->Pt() << " " << ilep->Eta() << " " << ilep->Phi() << endl;
  }

  if(jets.size() > 1 && fatjets.size()==0)   Fill_RegionPlots(channel,true,"HNL_HighMassSR1_TwoLepton_CR"  , param.Name+"_"+channel_string, jets,  fatjets,  electrons, muons,  METv, nPV, w);
  if(jets.size() > 1 && fatjets.size()==0){
    if(!param.Name.Contains("_noconv")) Fill_RegionPlots(channel, true,"HNL_HighMassSR1_TwoLepton_CR" , param.Name, jets,  fatjets,  electrons, muons,  METv, nPV, w);
  }
  return false;
}


bool HNL_RegionDefinitions::FillHighMass1JetCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto   , std::vector<Jet> jets, std::vector<FatJet> fatjets, std::vector<Jet> bjets,  Event ev, Particle METv, AnalyzerParameter param, float w){



  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);
  std::vector<Lepton *> leps  = MakeLeptonPointerVector(muons,electrons);

  TString channel_string = GetChannelString(channel);


  double lep1_ptcut= (channel==MuMu) ?   20. : 25.;
  double lep2_ptcut= (channel==MuMu) ?   10. : 15.;

  if(DataEra=="2017" || DataEra=="2018"){
    lep2_ptcut= 15;
  }

  if (leps.size() != 2 and leps_veto.size() != 2) return false;

  if (channel==EE     && !(leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::ELECTRON)) return false;
  if (channel==MuMu   && !(leps[0]->LeptonFlavour() == Lepton::MUON     && leps[1]->LeptonFlavour() == Lepton::MUON))    return false;
  if ((channel==EMu || channel==MuE)  &&
      !( (leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::MUON) ||
         (leps[0]->LeptonFlavour() == Lepton::MUON && leps[1]->LeptonFlavour() == Lepton::ELECTRON) ))  return false;


  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut)) return false;

  if(!RunCF){
    if(leps[0]->Charge() != leps[1]->Charge()) return false;
  }
  else{
    if(leps[0]->Charge() == leps[1]->Charge()) return false;
  }
  Particle ll =  (*leps[0]) + (*leps[1]);
  if (channel==EE  && (fabs(ll.M()-90.) > 10)) return false;

  if(jets.size() != 1) return false;
  Fill_RegionPlots(channel,true,"HNL_HighMass1Jet_TwoLepton_CR"  , param.Name+"_"+channel_string, jets,  fatjets,  electrons, muons,  METv, nPV, w);
  if(!param.Name.Contains("_noconv")) Fill_RegionPlots(channel, true,"HNL_HighMass1Jet_TwoLepton_CR" , param.Name, jets,  fatjets,  electrons, muons,  METv, nPV, w);

  return true;

}


bool HNL_RegionDefinitions::FillHighMassBJetCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto   , std::vector<Jet> jets, std::vector<FatJet> fatjets, std::vector<Jet> bjets,  Event ev, Particle METv, AnalyzerParameter param, float w){




  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);
  std::vector<Lepton *> leps  = MakeLeptonPointerVector(muons,electrons);

  TString channel_string = GetChannelString(channel);


  double lep1_ptcut= (channel==MuMu) ?   20. : 25.;
  double lep2_ptcut= (channel==MuMu) ?   10. : 15.;

  if(DataEra=="2017" || DataEra=="2018"){
    lep2_ptcut= 15;
  }

  if (leps.size() != 2 and leps_veto.size() != 2) return false;

  if (channel==EE     && !(leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::ELECTRON)) return false;
  if (channel==MuMu   && !(leps[0]->LeptonFlavour() == Lepton::MUON     && leps[1]->LeptonFlavour() == Lepton::MUON))    return false;
  if ((channel==EMu || channel==MuE)  &&
      !( (leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::MUON) ||
         (leps[0]->LeptonFlavour() == Lepton::MUON && leps[1]->LeptonFlavour() == Lepton::ELECTRON) ))  return false;


  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut)) return false;

  if(!RunCF){
    if(leps[0]->Charge() != leps[1]->Charge()) return false;
  }
  else{
    if(leps[0]->Charge() == leps[1]->Charge()) return false;
  }

  Particle ll =  (*leps[0]) + (*leps[1]);
  if (channel==EE  && (fabs(ll.M()-90.) > 10)) return false;
  if(ll.M() < 10) return false;
  int NBJets = bjets.size();

  if(NBJets == 0) return false;
  Fill_RegionPlots(channel,true,"HNL_HighMassBJet_TwoLepton_CR"  , param.Name+"_"+channel_string, jets,  fatjets,  electrons, muons,  METv, nPV, w);
  if(!param.Name.Contains("_noconv")) Fill_RegionPlots(channel, true,"HNL_HighMassBJet_TwoLepton_CR" , param.Name, jets,  fatjets,  electrons, muons,  METv, nPV, w);

  return true;

}


bool HNL_RegionDefinitions::FillHighMassNPCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto   , std::vector<Jet> jets, std::vector<FatJet> fatjets, std::vector<Jet> bjets,  Event ev, Particle METv, AnalyzerParameter param, float w){



  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);
  std::vector<Lepton *> leps  = MakeLeptonPointerVector(muons,electrons);

  TString channel_string = GetChannelString(channel);


  double lep1_ptcut= (channel==MuMu) ?   20. : 25.;
  double lep2_ptcut= (channel==MuMu) ?   10. : 15.;

  if(DataEra=="2017" || DataEra=="2018"){
    lep2_ptcut= 15;
  }

  if (leps.size() != 2 and leps_veto.size() != 2) return false;

  if (channel==EE     && !(leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::ELECTRON)) return false;
  if (channel==MuMu   && !(leps[0]->LeptonFlavour() == Lepton::MUON     && leps[1]->LeptonFlavour() == Lepton::MUON))    return false;
  if ((channel==EMu || channel==MuE)  &&
      !( (leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::MUON) ||
         (leps[0]->LeptonFlavour() == Lepton::MUON && leps[1]->LeptonFlavour() == Lepton::ELECTRON) ))  return false;


  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut)) return false;

  if(jets.size() > 0) return false;

  if(!RunCF){
    if(leps[0]->Charge() != leps[1]->Charge()) return false;
  }
  else{
    if(leps[0]->Charge() == leps[1]->Charge()) return false;
  }

  Particle ll =  (*leps[0]) + (*leps[1]);
  if (channel==EE  && (fabs(ll.M()-90.) > 10)) return false;

  if(leps[0]->DeltaPhi(*leps[1]) < 2.5) return false;

  Fill_RegionPlots(channel,true,"HNL_HighMassNP_TwoLepton_CR"  , param.Name+"_"+channel_string, jets,  fatjets,  electrons, muons,  METv, nPV, w);
  if(!param.Name.Contains("_noconv")) Fill_RegionPlots(channel, true,"HNL_HighMassNP_TwoLepton_CR" , param.Name, jets,  fatjets,  electrons, muons,  METv, nPV, w);

  return true;

}



bool HNL_RegionDefinitions::FillHighMassSR2CRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto   , std::vector<Jet> jets, std::vector<FatJet> fatjets, std::vector<Jet> bjets,  Event ev, Particle METv, AnalyzerParameter param, float w){




  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);
  std::vector<Lepton *> leps  = MakeLeptonPointerVector(muons,electrons);

  TString channel_string = GetChannelString(channel);


  double lep1_ptcut= (channel==MuMu) ?   20. : 25.;
  double lep2_ptcut= (channel==MuMu) ?   10. : 15.;

  if(DataEra=="2017" || DataEra=="2018"){
    lep2_ptcut= 15;
  }

  if (leps.size() != 2 and leps_veto.size() != 2) return false;

  if (channel==EE     && !(leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::ELECTRON)) return false;
  if (channel==MuMu   && !(leps[0]->LeptonFlavour() == Lepton::MUON     && leps[1]->LeptonFlavour() == Lepton::MUON))    return false;
  if ((channel==EMu || channel==MuE)  &&
      !( (leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::MUON) ||
         (leps[0]->LeptonFlavour() == Lepton::MUON && leps[1]->LeptonFlavour() == Lepton::ELECTRON) ))  return false;



  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut)) return false;

  int NBJets = bjets.size();
  if(!RunCF){
    if(leps[0]->Charge() != leps[1]->Charge()) return false;
  }
  else{
    if(leps[0]->Charge() == leps[1]->Charge()) return false;
  }
  Particle ll =  (*leps[0]) + (*leps[1]);
  if (channel==EE  && (fabs(ll.M()-90.) < 15)) return false;
  if(ll.M() < 20) return false;

  double ST = GetST(electrons, muons, jets, fatjets, ev);
  double met2_st = pow(METv.Pt(),2.)/ ST;
  bool PassHMMet    = (met2_st < 20);

  if(PassHMMet && NBJets==0) return false;


  double LowerMassSR2WmassCut = 50.;
  double UpperMassSR2WmassCut = 150.;

  if(fatjets.size()==0) return false;

  if(!(GetMass("HNL_SR2", jets, fatjets) < UpperMassSR2WmassCut && GetMass("HNL_SR2", jets, fatjets) > LowerMassSR2WmassCut)) return false;

  if(fatjets.size()>0){
    Fill_RegionPlots(channel,true,"HNL_HighMassSR2_TwoLepton_CR"  , param.Name+"_"+channel_string, jets,  fatjets,  electrons, muons,  METv, nPV, w);

    if(!param.Name.Contains("_noconv")) Fill_RegionPlots(channel, true,"HNL_HighMassSR2_TwoLepton_CR" , param.Name, jets,  fatjets,  electrons, muons,  METv, nPV, w);
  }
  return true;
}

bool HNL_RegionDefinitions::FillWZ2CRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto   , std::vector<Jet> jets_eta5, std::vector<FatJet> fatjets, std::vector<Jet> bjets,  Event ev, Particle METv, AnalyzerParameter param, float w){



  TString channel_string= (channel==EEE) ?  "Electron" : "Muon";

  double lep1_ptcut= (channel==EEE) ?   25. : 20.;
  double lep2_ptcut= (channel==EEE) ?   15. : 10.;
  double lep3_ptcut= (channel==EEE) ?   10. : 10.;

  if(jets_eta5.size() < 2) return false;

  std::vector<Lepton *> leps  = MakeLeptonPointerVector(muons,electrons);
  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);

  if(channel==MuMuMu && !(muons.size() ==3 && electrons_veto.size() == 0 && muons_veto.size()==3)) return false;
  if(channel==EEE   && !(electrons.size() ==3 && electrons_veto.size() == 3 && muons_veto.size()==0)) return false;

  double metcut = 30.;
  double trilep_masscut=105.;

  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut && leps[2]->Pt()  > lep3_ptcut)) return false;

  std::vector<Jet> jets                  = GetAK4Jets(jets_eta5, 20., 2.5, true,  0.4,0.8,"",    electrons_veto, muons_veto,fatjets);
  int NBJets = bjets.size();

  ////file:///Users/john/Downloads/AN2019_089_v7.pdf SSWW +WZ  + AN2020_045                                                                                                                                        
  double maxDiJetDeta=0.;
  int ijet1(-1), ijet2(-1);
  for(unsigned int ij = 0; ij < jets_eta5.size(); ij++){
    for(unsigned int ij2 = ij+1; ij2 < jets_eta5.size(); ij2++){
      double deta = fabs(jets_eta5[ij].Eta() - jets_eta5[ij2].Eta());
      if(deta > maxDiJetDeta) {
        maxDiJetDeta=deta;
        ijet1=ij;
        ijet2=ij2;
      }
    }
  }
  if(GetIndexNonBestZ(leps,15.) < 0) return false;
  if(GetMassMinOSSF(leps)  < 20.) return false;
  if(((*leps[0])+ (*leps[1]) + (*leps[2])).M() <  trilep_masscut) return false;


  if(jets_eta5.size() < 2) return false;
  Jet j1 = jets_eta5[ijet1] ;
  Jet j2 = jets_eta5[ijet2];
  if(!(j1.Pt() > 30.) && (j2.Pt() > 30.)) return false;
  if ( METv.Pt() < metcut) return false;
  if (NBJets>0) return false;
  if ((j1+j2).M() < 500.) return false;
  if (maxDiJetDeta<2.5) return false;

  double Av_JetEta= 0.5*(jets_eta5[ijet1].Eta()+ jets_eta5[ijet2].Eta());
  double zeppenfeld = TMath::Max((*leps[0]).Eta()  - Av_JetEta , (*leps[1]).Eta()  - Av_JetEta ) /maxDiJetDeta;
  double zeppenfeld2 = TMath::Max((*leps[0]).Eta()  - Av_JetEta , (*leps[2]).Eta()  - Av_JetEta ) /maxDiJetDeta;
  if(zeppenfeld2 > zeppenfeld) zeppenfeld=zeppenfeld2;

  if (zeppenfeld > 1.00) return false;

  Fill_RegionPlots(channel, true,"HNL_WZ2_ThreeLepton_CR" , param.Name+"_"+channel_string, jets_eta5,  fatjets,  electrons, muons,  METv, nPV, w);

  if(!param.Name.Contains("_noconv")) Fill_RegionPlots(channel, true,"HNL_WZ2_ThreeLepton_CR" , param.Name, jets_eta5,  fatjets,  electrons, muons,  METv, nPV, w);


  return true;

}

bool HNL_RegionDefinitions::FillWZBCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto   , std::vector<Jet> jets_eta5, std::vector<FatJet> fatjets, std::vector<Jet> bjets,  Event ev, Particle METv, AnalyzerParameter param, float w){




  TString channel_string= (channel==EEE) ?  "Electron" : "Muon";
  double lep1_ptcut= (channel==EEE) ?   25. : 20.;
  double lep2_ptcut= (channel==EEE) ?   15. : 10.;
  double lep3_ptcut= (channel==EEE) ?   10. : 10.;

  if(jets_eta5.size() < 2) return false;

  std::vector<Lepton *> leps  = MakeLeptonPointerVector(muons,electrons);
  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);

  if(channel==MuMuMu && !(muons.size() ==3 && electrons_veto.size() == 0 && muons_veto.size()==3)) return false;
  if(channel==EEE   && !(electrons.size() ==3 && electrons_veto.size() == 3 && muons_veto.size()==0)) return false;

  double metcut = 30.;
  double trilep_masscut=105.;

  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut && leps[2]->Pt()  > lep3_ptcut)) return false;

  std::vector<Jet> jets                  = GetAK4Jets(jets_eta5, 20., 2.5, true,  0.4,0.8,"",    electrons_veto, muons_veto,fatjets);
  int NBJets = bjets.size();
  //file:///Users/john/Downloads/AN2019_089_v7.pdf SSWW +WZ  + AN2020_045                                                                                                                                          


  if(jets_eta5.size() < 2) return false;
  double maxDiJetDeta=0.;
  int ijet1(-1), ijet2(-1);
  for(unsigned int ij = 0; ij < jets_eta5.size(); ij++){
    for(unsigned int ij2 = ij+1; ij2 < jets_eta5.size(); ij2++){
      double deta = fabs(jets_eta5[ij].Eta() - jets_eta5[ij2].Eta());
      if(deta > maxDiJetDeta) {
        maxDiJetDeta=deta;
        ijet1=ij;
        ijet2=ij2;
      }
    }
  }

  if(GetIndexNonBestZ(leps,15.) < 0) return false;
  if(((*leps[0])+ (*leps[1]) + (*leps[2])).M() <  trilep_masscut) return false;

  Jet j1 = jets_eta5[ijet1] ;
  Jet j2 = jets_eta5[ijet2];
  if(!(j1.Pt() > 30.) && (j2.Pt() > 30.)) return false;
  if ( METv.Pt() < metcut) return false;
  if (NBJets==0) return false;
  if ((j1+j2).M() < 500.) return false;
  if (maxDiJetDeta<2.5) return false;

  double Av_JetEta= 0.5*(jets_eta5[ijet1].Eta()+ jets_eta5[ijet2].Eta());
  double zeppenfeld = TMath::Max((*leps[0]).Eta()  - Av_JetEta , (*leps[1]).Eta()  - Av_JetEta ) /maxDiJetDeta;
  double zeppenfeld2 = TMath::Max((*leps[0]).Eta()  - Av_JetEta , (*leps[2]).Eta()  - Av_JetEta ) /maxDiJetDeta;
  if(zeppenfeld2 > zeppenfeld) zeppenfeld=zeppenfeld2;

  if (zeppenfeld > 1.00) return false;


  Fill_RegionPlots(channel, true,"HNL_WZB_ThreeLepton_CR" , param.Name+"_"+channel_string, jets_eta5,  fatjets,  electrons, muons,  METv, nPV, w);


  if(!param.Name.Contains("_noconv")) Fill_RegionPlots(channel, true,"HNL_WZB_ThreeLepton_CR" , param.Name, jets_eta5,  fatjets,  electrons, muons,  METv, nPV, w);

  return true;

}


bool HNL_RegionDefinitions::FillZZCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet> fatjets, std::vector<Jet> bjets,  Event ev, Particle METv, AnalyzerParameter param, float w){



  TString channel_string= (channel==EEEE) ?  "Electron" : "Muon";

  std::vector<Lepton *> leps  = MakeLeptonPointerVector(muons,electrons);
  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);

  if(channel==MuMuMuMu && !(muons.size() ==4 && electrons_veto.size() == 0 && muons_veto.size()==4)) return false;
  if(channel==EEEE   && !(electrons.size() ==4 && electrons_veto.size() == 4 && muons_veto.size()==0)) return false;


  double lep1_ptcut= (channel==EEEE) ?   25. : 20.;
  double lep2_ptcut= (channel==EEEE) ?   15. : 10.;
  double lep3_ptcut= (channel==EEEE) ?   10. : 10.;
  double lep4_ptcut= (channel==EEEE) ?   10. : 10.;

  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut && leps[2]->Pt()  > lep3_ptcut && leps[3]->Pt()  > lep4_ptcut)) return false;


  if(leps.size() != 4){
    cout<<"[HNL_RegionDefinitions::FillZZCRPlots lep number error" << endl;
    cout << "electrons.size()  = " << electrons.size()  << endl;
    cout << "veto electrons.size()  = " << electrons_veto.size()  << endl;
    cout << "muons.size()  = " << muons.size()  << endl;
    cout << "veto muon.size()  = " << muons_veto.size()  << endl;
    cout << param.Name << endl;
    if(channel==EEE) cout << "EEE" << endl;
    else if(channel==MuMuMu) cout << "MMM" << endl;
    else cout << "Wrong channel " << endl;
    for(auto iel : electrons){
      cout << "El " << iel.Pt() << endl;
      cout << "Pass ID "  << param.Electron_Veto_ID << " " << iel.PassID("HNVeto") << endl;
      if(!IsDATA)cout << "Type = " << GetLeptonType(iel,gens) << endl;
    }
    exit(EXIT_FAILURE);
  }

  int NBJets=bjets.size();


  if(NBJets  > 0 ) return false;
  bool m_llos_l10(false), z_cr_pass(false);

  Particle Z1Cand;
  Particle Z2Cand;


  for(unsigned int iel =0; iel < leps.size() ; iel++){
    for(unsigned int iel2 =iel+1; iel2 < leps.size() ; iel2++){
      if(iel== iel2) continue;
      Z1Cand = (*leps[iel]) + (*leps[iel2]) ;
      if(leps[iel]->Charge() != leps[iel2]->Charge()){
        if(Z1Cand.M() < 10) m_llos_l10=true;

        int zel1(-9), zel2(-9);
        if(iel ==0 && iel2==1){ zel1=2; zel2=3;    Z2Cand = (*leps[2]) + (*leps[3]);}
        if(iel ==0 && iel2==2){ zel1=1; zel2=3;    Z2Cand = (*leps[1]) + (*leps[3]);}
        if(iel ==0 && iel2==3){ zel1=1; zel2=2;    Z2Cand = (*leps[1]) + (*leps[2]);}
        if(iel ==1 && iel2==2){ zel1=0; zel2=3;    Z2Cand = (*leps[0]) + (*leps[3]);}
        if(iel ==1 && iel2==3){ zel1=0; zel2=2;    Z2Cand = (*leps[0]) + (*leps[2]);}
        if(iel ==2 && iel2==3){ zel1=0; zel2=1;    Z2Cand = (*leps[0]) + (*leps[1]);}

        if(leps[zel1]->Charge() != leps[zel2]->Charge()){
          if(fabs(Z1Cand.M() - 90.1) < 15.){
	    if(fabs(Z2Cand.M() - 90.1) < 15.){
	      z_cr_pass=true;
	    }
          }
        }
      }
    }
  }
  if(m_llos_l10 || !z_cr_pass)  return false;
  Fill_RegionPlots(channel, true,"HNL_ZZ_FourLepton_CR" , param.Name+"_"+channel_string, jets,  fatjets,  electrons, muons,  METv, nPV, w);
  if(!param.Name.Contains("_noconv")) Fill_RegionPlots(channel,true,"HNL_ZZ_FourLepton_CR" , param.Name, jets,  fatjets,  electrons, muons,  METv, nPV, w);

  return true;
}


bool HNL_RegionDefinitions::FillZZ2CRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet> fatjets, std::vector<Jet> bjets,  Event ev, Particle METv, AnalyzerParameter param, float w){



  TString channel_string= (channel==EEEE) ?  "Electron" : "Muon";

  std::vector<Lepton *> leps  = MakeLeptonPointerVector(muons,electrons);
  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);

  if(channel==MuMuMuMu && !(muons.size() ==4 && electrons_veto.size() == 0 && muons_veto.size()==4)) return false;
  if(channel==EEEE   && !(electrons.size() ==4 && electrons_veto.size() == 4 && muons_veto.size()==0)) return false;


  double lep1_ptcut= (channel==EEEE) ?   25. : 20.;
  double lep2_ptcut= (channel==EEEE) ?   15. : 10.;
  double lep3_ptcut= (channel==EEEE) ?   10. : 10.;
  double lep4_ptcut= (channel==EEEE) ?   10. : 10.;

  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut && leps[2]->Pt()  > lep3_ptcut && leps[3]->Pt()  > lep4_ptcut)) return false;


  int NBJets=bjets.size();


  if(NBJets  > 0 ) return false;
  bool m_llos_l10(false), z_cr_pass(false);

  Particle Z1Cand;

  for(unsigned int iel =0; iel < leps.size() ; iel++){
    for(unsigned int iel2 =iel+1; iel2 < leps.size() ; iel2++){
      if(iel== iel2) continue;
      Z1Cand = (*leps[iel]) + (*leps[iel2]) ;
      if(leps[iel]->Charge() != leps[iel2]->Charge()){
        if(Z1Cand.M() < 12) m_llos_l10=true;

        if(fabs(Z1Cand.M() - 90.1) < 15.){
          z_cr_pass=true;
        }
      }
    }
  }



  if(m_llos_l10 || !z_cr_pass)  return false;
  Fill_RegionPlots(channel, true,"HNL_ZZLoose_FourLepton_CR" , param.Name+"_"+channel_string, jets,  fatjets,  electrons, muons,  METv, nPV, w);
  if(!param.Name.Contains("_noconv")) Fill_RegionPlots(channel,true,"HNL_ZZLoose_FourLepton_CR" , param.Name, jets,  fatjets,  electrons, muons,  METv, nPV, w);

  return true;
}


bool HNL_RegionDefinitions::FillZGCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet> fatjets, std::vector<Jet> bjets,  Event ev, Particle METv, AnalyzerParameter param, float w){

  if(MCSample.Contains("DY")) return false;


  TString channel_string= (channel==EEE) ?  "Electron" : "Muon";

  std::vector<Lepton *> leps  = MakeLeptonPointerVector(muons,electrons);
  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);

  if(channel==MuMuMu && !(muons.size() ==3 && electrons_veto.size() == 0 && muons_veto.size()==3)) return false;
  if(channel==EEE   && !(electrons.size() ==3 && electrons_veto.size() == 3 && muons_veto.size()==0)) return false;

  double lep1_ptcut= (channel==EEE) ?   25. : 20.;
  double lep2_ptcut= (channel==EEE) ?   15. : 10.;
  double lep3_ptcut= (channel==EEE) ?   10. : 10.;
  if(DataEra=="2017" ||DataEra=="2018"){
    lep2_ptcut=15;
    lep3_ptcut= 15;
  }
  if(leps.size() != 3){
    cout<<"[HNL_RegionDefinitions::FillZGCRPlots lep number error" << endl;
    cout << "electrons.size()  = " << electrons.size()  << endl;
    cout << "veto electrons.size()  = " << electrons_veto.size()  << endl;
    cout << "muons.size()  = " << muons.size()  << endl;
    cout << "veto muon.size()  = " << muons_veto.size()  << endl;
    cout << param.Name << endl;
    if(channel==EEE) cout << "EEE" << endl;
    else if(channel==MuMuMu) cout << "MMM" << endl;
    else cout << "Wrong channel " << endl;
    for(auto iel : electrons){
      cout << "El " << iel.Pt() << endl;
      cout << "Pass ID "  << param.Electron_Veto_ID << " " << iel.PassID("HNVeto") << endl;
      if(!IsDATA)cout << "Type = " << GetLeptonType(iel,gens) << endl;
    }
    exit(EXIT_FAILURE);
  }


  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut && leps[2]->Pt()  > lep3_ptcut)) return false;

  double metcut = 50.;
  int NBJets=bjets.size();


  Particle lll = (*leps[0]) + (*leps[1])+ (*leps[2]);
  bool passZmass_lll_Window = (fabs(lll.M() - 90.1) < 15.);
  if(!passZmass_lll_Window) return false;

  Particle ll1 = *leps[0] + *leps[1];
  Particle ll2 = *leps[0] + *leps[2];
  Particle ll3 = *leps[1] + *leps[2];
  if(!ZmassOSSFWindowCheck(leps,15.)) return false;
  if(NBJets > 0) return false;
  if(METv.Pt() > metcut) return false;

  if(run_Debug){
    cout << "HNL_ZG_ThreeLepton_CR " << param.Name+"_"+channel_string << " " << event  << endl;

    for(auto ilep: leps){
      Gen gen_closest = GetGenMatchedLepton(*ilep, gens);
      Gen gen_photon_closest = GetGenMatchedPhoton(*ilep, gens);
      //int NearPhotonType = GetGenPhotonType(gen_photon_closest,gens);

      FillHist("Photon_pt_HNL_ZG_ThreeLepton_CR",gen_photon_closest.Pt() , w, 100., 0.,  200.);
    }

    PrintGen(gens);
  }

  Fill_RegionPlots(channel,true,"HNL_ZG_ThreeLepton_CR" , param.Name+"_"+channel_string, jets,  fatjets,  electrons, muons,  METv, nPV, w);
  if(!param.Name.Contains("_noconv")) Fill_RegionPlots(channel,true,"HNL_ZG_ThreeLepton_CR" , param.Name, jets,  fatjets,  electrons, muons,  METv, nPV, w);

  return true;

}



bool HNL_RegionDefinitions::FillWGCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet> fatjets, std::vector<Jet> bjets,  Event ev, Particle METv, AnalyzerParameter param, float w){



  TString channel_string= (channel==EEE) ?  "Electron" : "Muon";

  std::vector<Lepton *> leps  = MakeLeptonPointerVector(muons,electrons);
  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);

  if(HasLowMassMeson(leps)) return false;
  if(channel==MuMuMu && !(muons.size() ==3 && electrons_veto.size() == 0 && muons_veto.size()==3)) return false;
  if(channel==EEE   && !(electrons.size() ==3 && electrons_veto.size() == 3 && muons_veto.size()==0)) return false;
  double lep1_ptcut= (channel==EEE) ?   25. : 20.;
  double lep2_ptcut= (channel==EEE) ?   15. : 10.;
  double lep3_ptcut= (channel==EEE) ?   10. : 10.;

  if(DataEra=="2017" || DataEra=="2018"){
    lep2_ptcut= 15;
    lep3_ptcut= 15;
  }
  double metcut = 30.;
  double mt_cut = 30.;
  int NBJets=bjets.size();


  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut && leps[2]->Pt()  > lep3_ptcut)) return false;

  Particle ll1 = (*leps[0]) + (*leps[1]);
  Particle ll2 = (*leps[0]) + (*leps[2]);
  Particle ll3 = (*leps[1]) + (*leps[2]);
  bool passlos_ll_mass=false;
  if(ll1.Charge() == 0 && (ll1.M() < 4.)) passlos_ll_mass=true;
  if(ll2.Charge() == 0 && (ll2.M() < 4.)) passlos_ll_mass=true;
  if(ll3.Charge() == 0 && (ll3.M() < 4.)) passlos_ll_mass=true;
  if(!passlos_ll_mass) return false;
  Particle lll = (*leps[0]) + (*leps[1])+ (*leps[2]);
  double MT_lll = M_T(METv,lll);

  if(MT_lll <= mt_cut) return false;
  if(NBJets > 0)return false;
  if(METv.Pt() < metcut)return false;

  if(run_Debug){
    cout << "HNL_WG_ThreeLepton_CR " << param.Name+"_"+channel_string << " " << event  << endl;

    PrintGen(gens);
  }
  Fill_RegionPlots(channel,true,"HNL_WG_ThreeLepton_CR"  , param.Name+"_"+channel_string, jets,  fatjets,  electrons, muons,  METv, nPV, w);
  if(!param.Name.Contains("_noconv"))Fill_RegionPlots(channel,true,"HNL_WG_ThreeLepton_CR" , param.Name, jets,  fatjets,  electrons, muons,  METv, nPV, w);

  return true;
}


bool HNL_RegionDefinitions::FillWZCRPlots(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet> fatjets, std::vector<Jet> bjets,  Event ev, Particle METv, AnalyzerParameter param, float w){


  TString channel_string= (channel==EEE) ?  "Electron" : "Muon";

  std::vector<Lepton *> leps  = MakeLeptonPointerVector(muons,electrons);
  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);

  if(channel==MuMuMu && !(muons.size() ==3 && electrons_veto.size() == 0 && muons_veto.size()==3)) return false;
  if(channel==EEE   && !(electrons.size() ==3 && electrons_veto.size() == 3 && muons_veto.size()==0)) return false;

  double lep1_ptcut= (channel==EEE) ?   25. : 20.;
  double lep2_ptcut= (channel==EEE) ?   15. : 10.;
  double lep3_ptcut= (channel==EEE) ?   10. : 10.;
  if(DataEra=="2017" || DataEra=="2018"){
    lep2_ptcut= 15;
    lep3_ptcut= 15;
  }

  double metcut = 50.;
  double mtcut = 20.;
  double trilep_masscut=105.;

  if(!(leps[0]->Pt() > lep1_ptcut && leps[1]->Pt()  > lep2_ptcut && leps[2]->Pt()  > lep3_ptcut)) return false;

  int NBJets=bjets.size();
  

  if(METv.Pt() < metcut) return false;
  if(NBJets > 0) return false;
  if(GetIndexNonBestZ(leps,15.) < 0) return false;
  if(M_T((*leps[GetIndexNonBestZ(leps,15.)]), METv)  < mtcut) return false;
  if(GetMassMinOSSF(leps)  < 10.) return false;
  if(((*leps[0])+ (*leps[1]) + (*leps[2])).M() <  trilep_masscut) return false;
  
  Fill_RegionPlots(channel,true,"HNL_WZ_ThreeLepton_CR" , param.Name+"_"+channel_string, jets,  fatjets,  electrons, muons,  METv, nPV, w);
  if(!param.Name.Contains("_noconv"))Fill_RegionPlots(channel,true,"HNL_WZ_ThreeLepton_CR" , param.Name, jets,  fatjets,  electrons, muons,  METv, nPV, w);
  
  return true;
}


