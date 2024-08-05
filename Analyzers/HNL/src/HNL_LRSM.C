#include "HNL_LRSM.h"

void HNL_LRSM::initializeAnalyzer(){

  HNL_LeptonCore::initializeAnalyzer();

}


void HNL_LRSM::executeEvent(){

  
  //==== Gen for genmatching
  AnalyzerParameter param  = InitialiseHNLParameter("SignalStudy");

  Event ev = GetEvent();
  double weight =  (gen_weight > 0) ? 1. : -1. ; //SetupWeight(ev,param);

  if(event != 281722 ) return;
  
  vector<Muon>     InputMuons = GetMuons    ( "NoCut", 10., 2.4);
  vector<Electron> InputElectrons = GetElectrons    ( "NoCut", 10., 2.5);
  for(auto i : InputMuons) cout << "Muon Pt = " << i.Pt() << " eta = " << i.Eta() << endl;
  for(auto i : InputElectrons) cout << "Electron Pt = " << i.Pt() << " eta = " << i.Eta() << endl;
  std::vector<Lepton *> LepsNC        = MakeLeptonPointerVector(InputMuons,InputElectrons);

  PrintGen(All_Gens);
  for(auto lep : LepsNC) PrintMatchedGen(All_Gens, *lep);                                                                                                                                                                               

  return;
  
  FillHist ("NoCut", 1, weight, 2, 0., 2.,"");

  vector<Muon>     HNMuons     = SelectMuons (InputMuons, "POGLoose", 10., 2.4);
  vector<Electron> HNElectrons = SelectElectrons (InputElectrons, "passLooseID", 15., 2.4);
  
  vector<Muon>     HNMuonsHM = SelectMuons (InputMuons, "POGHighPtWithVLooseTrkIso", 50., 2.4);
  vector<Electron> HNElectronsHM = SelectElectrons (InputElectrons, "passHEEPID", 50., 2.4);


  FillHist( "NObj/Muons", HNMuons.size(),  weight,  5, 0.,5);
  FillHist( "NObj/Electrons", HNElectrons.size(),  weight,  5, 0.,5);
  
  std::vector<FatJet> AK8_JetColl                 = GetHNLAK8Jets("HNL_NoMass",param);
  std::vector<Jet>    AK4_JetColl                 = GetHNLJets(param.AK4JetColl,     param);

  FillHist( "NObj/AK8", AK8_JetColl.size(),  weight,  5, 0.,5);
  FillHist( "NObj/AK4", AK4_JetColl.size(),  weight,  5, 0.,5);
  
  Particle METv = GetvMET("PuppiT1xyULCorr",param);                                                                                                          
  
  vector<Tau> TauColl;
  std::vector<Lepton *> Leps        = MakeLeptonPointerVector(InputElectrons);
  std::vector<Lepton *> LepsT       = MakeLeptonPointerVector(HNMuons,HNElectrons,     param);
  std::vector<Lepton *> LepsTHM       = MakeLeptonPointerVector(HNMuonsHM,HNElectronsHM,     param);

  FillHist( "NObj/Leps", LepsT.size(),  weight,  5, 0.,5);
  FillHist( "NObj/LepsHM", LepsTHM.size(),  weight,  5, 0.,5);

  for(auto channel : {"EE","MuMu"}){
    
    param.Channel = channel;
    
    TString ChannelS = TString(channel);
    if(GetProcessLRSM() != channel) continue;
    
    FillHist((ChannelS + "/NoCut").Data(),1 ,  weight, 2, 0, 2 );

    //if( GetProcessLRSM() == "EE"){
      //for(auto lep : Leps) PrintMatchedGen(All_Gens, *lep);
    // for(auto lep : InputElectrons) cout << "Pass ID = " << lep.PassID("passLooseID") << endl;
    //  
    // }

    if( GetProcessLRSM() == "EE" && HNElectrons.size() ==0) continue;
    if( GetProcessLRSM() == "EE" && HNMuons.size() > 0) continue;
    
    if( GetProcessLRSM() == "MuMu" && HNElectrons.size() >0) continue;
    if( GetProcessLRSM() == "MuMu" && HNMuons.size() == 0) continue;
    
    
    if(ChannelS == "EE"){
      
      if(HNElectronsHM.size() == 2&& AK4_JetColl.size() > 1) Fill_RegionPlots(param,"DiEl_R" , TauColl, AK4_JetColl, AK8_JetColl, LepsTHM,  METv, nPV, weight);                                                    
      
      else if(HNElectrons.size() == 2 ) Fill_RegionPlots(param,"DiEl_B" , TauColl, AK4_JetColl, AK8_JetColl, LepsT,  METv, nPV, weight);                                                                            

      if(HNElectronsHM.size() == 2&& AK4_JetColl.size() > 1) FillHist((ChannelS + "/Resolved").Data(),1 ,  weight, 2, 0, 2 );
      else if(HNElectrons.size() == 1  ) FillHist((ChannelS + "/Boosted").Data(),1 ,  weight, 2, 0, 2 );
    }
    else{
      
      if(HNMuonsHM.size() == 2 && AK4_JetColl.size() > 1){
	Particle MLL =  HNMuonsHM[0] + HNMuonsHM[1];
	Particle MLLJJ =  HNMuonsHM[0] + HNMuonsHM[1] + AK4_JetColl[0] + AK4_JetColl[1];
	
	FillHist((ChannelS + "/Resolved").Data(),1 ,  weight, 2, 0, 2 );
	Fill_RegionPlots(param,"DiMu_R" , TauColl, AK4_JetColl, AK8_JetColl, LepsTHM,  METv, nPV, weight);
	if(MLL.M() > 200 && MLLJJ.M() > 800 )FillHist((ChannelS + "/Resolved_SR").Data(),1 ,  weight, 2, 0, 2 );
      }
      else if(HNMuons.size() == 2 ) {
	bool pID1 = HNMuons[0].PassID("POGHighPtWithVLooseTrkIso");
	bool pID2 = HNMuons[1].PassID("POGHighPtWithVLooseTrkIso");
        Particle MLL =  HNMuons[0] + HNMuons[1];
	
	if(pID1 || pID2) {

	  vector<Lepton *>  LepsTT;
	  if (pID1 ) LepsTT.push_back(LepsT[0]);
	  else if (pID2 ) LepsTT.push_back(LepsT[1]);
	  FillHist((ChannelS + "/Boosted").Data(),1 ,  weight, 2, 0, 2 );
	  Fill_RegionPlots(param,"DiMu_B" , TauColl, AK4_JetColl, AK8_JetColl, LepsT,  METv, nPV, weight);
	  Fill_RegionPlots(param,"DiMu_B_Tight" , TauColl, AK4_JetColl, AK8_JetColl, LepsTT,  METv, nPV, weight);
	  
	  if(AK8_JetColl.size() > 0)           Fill_RegionPlots(param,"DiMu_B_SR" , TauColl, AK4_JetColl, AK8_JetColl, LepsT,  METv, nPV, weight);

	   
	}
      }
    }

  }

}



      
//      std::vector<Muon> MuonCollB = SkimLepColl(MuonColl, "MBMO");
//      std::vector<Muon> MuonCollE = SkimLepColl(MuonColl, "ME");
//      std::vector<Muon> MuonCollFakeB = SkimLepColl(MuonCollFake, "MBMO");
//      std::vector<Muon> MuonCollFakeE = SkimLepColl(MuonCollFake, "ME");
//      std::vector<Muon> MuonCollConvB = SkimLepColl(MuonCollConv, "MBMO");
//      std::vector<Muon> MuonCollConvE = SkimLepColl(MuonCollConv, "ME");


  


HNL_LRSM::HNL_LRSM(){


}
 
HNL_LRSM::~HNL_LRSM(){

}

