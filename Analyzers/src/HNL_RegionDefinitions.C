#include "HNL_RegionDefinitions.h"



bool  HNL_RegionDefinitions::RunSignalRegionAK8(HNL_LeptonCore::Channel channel, HNL_LeptonCore::ChargeType analysis_charge ,std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet>  fatjets, TString bjet_wp, Event ev, AnalyzerParameter param, TString channel_string ,  float w){
			    
  Particle METUnsmearedv = ev.GetMETVector();
  Particle METv =UpdateMETSmearedJet(METUnsmearedv, jets);

  std::vector<Lepton *> leps       = MakeLeptonPointerVector(muons,electrons);
  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);
  
  
  return RunSignalRegionAK8(channel, analysis_charge, leps, leps_veto, jets, fatjets, bjet_wp, METv, param, channel_string, w);

  
}

bool  HNL_RegionDefinitions::RunSignalRegionAK8(HNL_LeptonCore::Channel channel, HNL_LeptonCore::ChargeType analysis_charge , std::vector<Lepton *> leps, std::vector<Lepton *> leps_veto , std::vector<Jet> jets, std::vector<FatJet>  fatjets, TString bjet_wp, Particle METv, AnalyzerParameter param, TString channel_string ,  float w){

  double lep1_ptcut= (channel==MuMu) ?   20. : 25.;
  double lep2_ptcut= (channel==MuMu) ?   10. : 15.;

  if (leps.size() != 2 and leps_veto.size() != 2) return false;

  if (channel==EE     && !(leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::ELECTRON)) return false;
  if (channel==MuMu   && !(leps[0]->LeptonFlavour() == Lepton::MUON     && leps[1]->LeptonFlavour() == Lepton::MUON))    return false;
  if ((channel==EMu || channel==MuE)  && 
      !( (leps[0]->LeptonFlavour() == Lepton::ELECTRON && leps[1]->LeptonFlavour() == Lepton::MUON) ||
	 (leps[0]->LeptonFlavour() == Lepton::MUON && leps[1]->LeptonFlavour() == Lepton::ELECTRON) ))  return false;



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

  int  NBJets_medium      =  GetNBJets2a(param.Jet_ID,"Medium");
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

    /// return true if SR is filled
    if(PassHMMet&&PassBJetMVeto) return true;
  }
  return false;
}

bool  HNL_RegionDefinitions::RunSignalRegionWW(HNL_LeptonCore::Channel channel, HNL_LeptonCore::ChargeType analysis_charge, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet>  fatjets, TString bjet_wp, Event ev, AnalyzerParameter param, TString channel_string ,  float w){


  Particle METUnsmearedv = ev.GetMETVector();
  Particle METv =UpdateMETSmearedJet(METUnsmearedv, jets);

  std::vector<Lepton *> leps       = MakeLeptonPointerVector(muons,electrons);
  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);



  return RunSignalRegionWW(channel,analysis_charge, leps, leps_veto, jets,fatjets, bjet_wp, METv, param,channel_string, w);
  
}

bool  HNL_RegionDefinitions::RunSignalRegionWW(HNL_LeptonCore::Channel channel, HNL_LeptonCore::ChargeType analysis_charge ,std::vector<Lepton *> leps, std::vector<Lepton *> leps_veto ,  std::vector<Jet> jets, std::vector<FatJet>  fatjets, TString bjet_wp, Particle METv, AnalyzerParameter param, TString channel_string ,  float w){



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

  int  NBJets_medium      =  GetNBJets2a(param.Jet_ID,"Medium");
  bool PassBJetMVeto = (NBJets_medium==0);

  double HT(0.);
  for(UInt_t emme=0; emme<jets.size(); emme++){
    HT += jets[emme].Pt();
  }
  if (HT/leps[1]->Pt() < 2){

    FillEventCutflow(HNL_LeptonCore::SR2, w, "SR2_ht_lt1",param.Name);
    
    if(PassBJetMVeto){
      FillEventCutflow(HNL_LeptonCore::SR2, w, "SR2_bveto",param.Name);
      PrintEvent(param,"SR2_"+channel_string,w);
      //      Fill_RegionPlots(channel,true,"HNL_"+QToString(analysis_charge)+"WW", param.Name, jets,  fatjets,  leps, METv, nPV, w);
      FillHist( param.Name+"/HNL_"+QToString(analysis_charge)+"WW/"+ param.Name+"HNL_SSWW_nevent_" ,  1.,  w, 2, 0.,2. );
      return true;
    }
  }

  return false;
}


bool  HNL_RegionDefinitions::RunSignalRegionAK4(HNL_LeptonCore::Channel channel, HNL_LeptonCore::ChargeType analysis_charge, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet>  fatjets, TString bjet_wp, Event ev, AnalyzerParameter param, TString channel_string ,  float w){


  Particle METUnsmearedv = ev.GetMETVector();
  Particle METv =UpdateMETSmearedJet(METUnsmearedv, jets);

  std::vector<Lepton *> leps       = MakeLeptonPointerVector(muons,electrons);
  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);


  return RunSignalRegionAK4(channel, analysis_charge, leps, leps_veto, jets, fatjets, bjet_wp, METv,param, channel_string, w);
}

bool  HNL_RegionDefinitions::RunSignalRegionAK4(HNL_LeptonCore::Channel channel, HNL_LeptonCore::ChargeType analysis_charge ,std::vector<Lepton *> leps, std::vector<Lepton *> leps_veto ,  std::vector<Jet> jets,std::vector<FatJet>  fatjets, TString bjet_wp, Particle METv, AnalyzerParameter param, TString channel_string ,  float w){
						


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


  int  NBJets      =  GetNBJets2a(param.Jet_ID,"Medium");
  if(NBJets>  0) return false;

  FillEventCutflow(HNL_LeptonCore::SR3, w, "SR3_bveto",param.Name);

  //  Run High Mass with main jet collections                                                                                                                
  double FatJetTau21_SF = GetEventFatJetSF(fatjets,"ak8_type1", 0);      
  FillWeightHist(param.Name+"/fatjet_ak8_type1_sf_"+param.Name,FatJetTau21_SF);
  
  if(jets.size() > 1 && fatjets.size()==0)  {  

    TString signal_region = "HNL_SR3";

    PrintEvent(param,"SR3_"+channel_string,w);
   
    //    Fill_RegionPlots      (channel,true,signal_region+"_Highmass" , param.Name, jets,  fatjets,  leps,  METv, nPV, w);
    //Fill_All_SignalRegion3 (channel, signal_region, IsDATA,  analysis_charge, param.Name, jets, fatjets,  electrons, muons,  METv, nPV ,w ,true);

    return true;
  }// 0 AK8                                                                                                                                                                                 
  
  
  return false;
}



bool HNL_RegionDefinitions::RunSignalRegionTrilepton(HNL_LeptonCore::Channel channel, std::vector<Electron> electrons, std::vector<Electron> electrons_veto, std::vector<Muon> muons, std::vector<Muon> muons_veto, std::vector<Jet> jets, std::vector<FatJet>  fatjets, TString bjet_wp, Event ev, AnalyzerParameter param, TString channel_string ,  float w){



  Particle METUnsmearedv = ev.GetMETVector();
  Particle METv =UpdateMETSmearedJet(METUnsmearedv, jets);

  std::vector<Lepton *> leps       = MakeLeptonPointerVector(muons,electrons);
  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(muons_veto,electrons_veto);


  return RunSignalRegionTrilepton(channel, leps, leps_veto, jets, fatjets, bjet_wp, METv,param, channel_string, w);

}

bool HNL_RegionDefinitions::RunSignalRegionTrilepton(HNL_LeptonCore::Channel channel,std::vector<Lepton *> leps, std::vector<Lepton *> leps_veto ,  std::vector<Jet> jets ,std::vector<FatJet>  fatjets, TString bjet_wp, Particle METv, AnalyzerParameter param, TString channel_string ,  float w){
  
  
  
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

  HNL_LeptonCore::Channel  channel_lll  = channel;

  FillEventCutflow(HNL_LeptonCore::SR4,w, "SR4_3lep",param.Name);
  
  
  // If running fake bkg now set weight to Fake weight
  //if(RunFake)   w= GetFakeWeightMuon(leps, param);
  if(RunFake)   FillWeightHist(param.Name+"/FakeWeight_"+param.Name,w);

  int n_veto_lep  = leps_veto.size();
  
  bool pass_sr1(true);

  if(n_veto_lep > 3) pass_sr1=false;

  if(pass_sr1)FillEventCutflow(HNL_LeptonCore::SR4,w, "SR4_3lep_veto",param.Name);

 
 
  if(pass_sr1)FillEventCutflow(HNL_LeptonCore::SR4,w, "SR4_3lep_chargereq",param.Name);

  int  NBJets      =  GetNBJets2a(param.Jet_ID,bjet_wp);

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

bool HNL_RegionDefinitions::PassVBF(vector<Jet>  jets,std::vector<Lepton *> leps){

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

  if(maxDiJetDeta < 2.5) return false;
  Particle JJ = jets[ijet1] + jets[ijet2];
  if(JJ.M() < 450.) return false;
  double Av_JetEta= 0.5*(jets[ijet1].Eta()+ jets[ijet2].Eta());
  double zeppenfeld = TMath::Max((*leps[0]).Eta()  - Av_JetEta , (*leps[1]).Eta()  - Av_JetEta ) /maxDiJetDeta;

  if(zeppenfeld > 0.75) return false;

  return true;
}

