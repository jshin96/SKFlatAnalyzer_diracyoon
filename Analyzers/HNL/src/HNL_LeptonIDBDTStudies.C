#include "HNL_LeptonIDBDTStudies.h"

void HNL_LeptonIDBDTStudies::initializeAnalyzer(){

  // All default settings like trigger/ PD/ BJet are decalred in HNL_LeptonCore::initializeAnalyzer to make them consistent for all HNL codes

  HNL_LeptonCore::initializeAnalyzer();
  SetupIDMVAReaderDefault(); /// Not needed for BDT skim                                                                                                                    

}


void HNL_LeptonIDBDTStudies::executeEvent(){
  
  if((_jentry==0)){ 
    // Print out trigger info in HNL_LeptonCore::initializeAnalyzer
    TriggerPrintOut(GetEvent());
  }
  
  TString ID = "POG";

  AnalyzerParameter param  = HNL_LeptonCore::InitialiseHNLParameter(ID,"");
  
  Event ev = GetEvent();
  double weight = SetupWeight(ev,param);
  if(MCSample.Contains("Type")) {
    weight = 1;
  }
  else if(MCSample.Contains("DYJets")) weight *= 0.5;
  else if(MCSample.Contains("WJets")) weight *= 0.5;
  else if(MCSample.Contains("WGToLNuG")) weight *= 0.5;

  if(MCSample.Contains("WJets")){
    if (weight < 0) return;
  }


  //// weight WJet and DY by 0.5 to allow weigted sample to be consistent with TTBar when addinh WJet MG && MCatNLO

  std::vector<Electron>   ElectronCollProbe = GetElectrons("MVALoose", 10., 2.5); 
  std::vector<Electron>   ElectronColl      = GetElectrons("passPOGTight", 10., 2.5); 

  std::vector<Muon>       MuonCollProbe     = GetMuons    ("HNL_ULID_Baseline", 10., 2.4);
  std::vector<Muon>       MuonColl          = GetMuons    ("POGTightWithTightIso", 10., 2.4);


  if(!PassMETFilter()) return;

  std::vector<Jet> BJetColl  = GetHNLJets("BJetM", param);
  bool HasBjet = (BJetColl.size() > 0);


  //////////////////////////  //////////////////////////  //////////////////////////  //////////////////////////
  //////////////////////////  //////////////////////////  //////////////////////////  //////////////////////////
  //
  //  Make plots  of Bkg / Sig eff for MVA IDs
  //
  //////////////////////////  //////////////////////////  //////////////////////////  //////////////////////////
  //////////////////////////  //////////////////////////  //////////////////////////  //////////////////////////
  
  std::vector<Lepton *> LeptonCollProbe      = MakeLeptonPointerVector(ElectronCollProbe);  
  if(LeptonCollProbe.size() == 0) return;
  
  for(auto ilep : ElectronCollProbe){
    TString  LepType = "";
    if ( FindHEMElectron (ilep )) continue;
    
	
    if (ilep.IsConv())  LepType = "Conv";
    if (ilep.IsFake())  LepType = "Fake"+ilep.MotherJetFlavour();
    if (ilep.IsFake() && ilep.MotherJetFlavour() == "Pileup") continue;
    if (ilep.LeptonIsCF())  LepType = "CF";
    else if (ilep.IsPrompt()) LepType = "Prompt";
    if (LepType == "") continue;
    
    if(ilep.IsBB() ){

      if(ilep.IsIB() ) FillBDTHists(ilep,LepType+"/IB",weight);
      else if(ilep.IsOB() ) FillBDTHists(ilep,LepType+"/OB",weight);

      if(ilep.Pt() < 15 ) FillBDTHists(ilep,LepType+"/BB_Pt1",weight);
      else if(ilep.Pt() < 20 ) FillBDTHists(ilep,LepType+"/BB_Pt2",weight);
      else if(ilep.Pt() < 50 )  FillBDTHists(ilep,LepType+"/BB_Pt3",weight);
      else if(ilep.Pt() < 200 )  FillBDTHists(ilep,LepType+"/BB_Pt4",weight);
      else FillBDTHists(ilep,LepType+"/BB_Pt5",weight);
    }
    else{
      FillBDTHists(ilep,LepType+"/EC",weight);

      if(ilep.Pt() < 15 ) FillBDTHists(ilep,LepType+"/EC_Pt1",weight);
      else if(ilep.Pt() < 20 ) FillBDTHists(ilep,LepType+"/EC_Pt2",weight);
      else if(ilep.Pt() < 50 ) FillBDTHists(ilep,LepType+"/EC_Pt3",weight);
      else if(ilep.Pt() < 200 ) FillBDTHists(ilep,LepType+"/EC_Pt4",weight);
      else FillBDTHists(ilep,LepType+"/EC_Pt5",weight);
    }
  }

  return;

  bool SSMM = SameCharge(MuonCollProbe) && (ElectronCollProbe.size()==0) && PassTriggerSelection(MuMu, ev, LeptonCollProbe,"Dilep");
  bool SSEE = SameCharge(ElectronCollProbe) && (MuonCollProbe.size()==0) && PassTriggerSelection(EE, ev, LeptonCollProbe,"Dilep");
  
  double SSWeight = weight;

  if(MCSample.Contains("WJet")){ 
    
    if(LeptonCollProbe.size() > 1) return;
    
    if(LeptonCollProbe[0]->IsElectron()){
      if(LeptonCollProbe[0]->MotherJetFlavour() == "LF"){
	
	SSEE=true;
	if( (MatchGenDef(All_Gens, *LeptonCollProbe[0]) == "pi0ph") ||
	    (MatchGenDef(All_Gens, *LeptonCollProbe[0]) == "pi0") ||
	    (MatchGenDef(All_Gens, *LeptonCollProbe[0]) == "Pi0") ||
	    (MatchGenDef(All_Gens, *LeptonCollProbe[0]) == "ph") ||
	    (MatchGenDef(All_Gens, *LeptonCollProbe[0]) == "q") ||
	    (MatchGenDef(All_Gens, *LeptonCollProbe[0]) == "g") ||
	    (MatchGenDef(All_Gens, *LeptonCollProbe[0]) == "LightMeson") ||
	    (MatchGenDef(All_Gens, *LeptonCollProbe[0]) == "proton")) {
	  SSWeight=weight*0.1;
	}
	else SSEE=false;
      }
      else SSEE=false;
    }
    else{

      if(LeptonCollProbe[0]->MotherJetFlavour() == "LF"){
	
        SSMM=true;
        if( (MatchGenDef(All_Gens, *LeptonCollProbe[0]) == "q") ||
            (MatchGenDef(All_Gens, *LeptonCollProbe[0]) == "g")){
          SSWeight=weight*0.1;
        } 
        else SSMM=false;
      }
      else SSMM=false;
    }
  }
  
  
  if(SSMM) FillHist("Counter/NSS_MM", 1  , SSWeight, 3, 0., 3);
  if(SSEE) FillHist("Counter/NSS_EE", 1  , SSWeight, 3, 0., 3);
  FillHist("Counter/N_E", ElectronCollProbe.size()  , weight, 5, 0., 5);
  FillHist("Counter/N_Mu", MuonCollProbe.size()  , weight, 5, 0., 5);
  
  if(SSMM){
    int EventType(0);
    if(MuonCollProbe[0].IsPrompt() && MuonCollProbe[1].IsPrompt())  EventType=1;
    else     if(MuonCollProbe[0].IsPrompt() && MuonCollProbe[1].IsFake())  EventType=2;
    else     if(MuonCollProbe[1].IsPrompt() && MuonCollProbe[0].IsFake())  EventType=2;
    else     if(MuonCollProbe[0].IsPrompt() && MuonCollProbe[1].IsConv())  EventType=3;
    else     if(MuonCollProbe[1].IsPrompt() && MuonCollProbe[0].IsConv())  EventType=3;
    else     if(MuonCollProbe[0].IsFake() && MuonCollProbe[1].IsConv())  EventType=4;
    else     if(MuonCollProbe[1].IsFake() && MuonCollProbe[0].IsConv())  EventType=4;
    else     if(MuonCollProbe[0].IsFake() && MuonCollProbe[1].IsFake())  EventType=5;
    else     if(MuonCollProbe[0].IsConv() && MuonCollProbe[1].IsConv())  EventType=6;
    
    FillHist("Counter/SSMuon_Breakdown",  EventType , SSWeight, 10, 0, 10 );
  }
  if(SSEE){
    int EventType(0);
    if(ElectronCollProbe[0].IsPrompt() && ElectronCollProbe[1].IsPrompt())  EventType=0;
    else     if(ElectronCollProbe[0].IsPrompt() && ElectronCollProbe[1].IsFake())  EventType=1;
    else     if(ElectronCollProbe[1].IsPrompt() && ElectronCollProbe[0].IsFake())  EventType=1;
    else     if(ElectronCollProbe[0].IsPrompt() && ElectronCollProbe[1].IsConv())  EventType=2;
    else     if(ElectronCollProbe[1].IsPrompt() && ElectronCollProbe[0].IsConv())  EventType=2;
    else     if(ElectronCollProbe[0].IsFake() && ElectronCollProbe[1].IsConv())  EventType=3;
    else     if(ElectronCollProbe[1].IsFake() && ElectronCollProbe[0].IsConv())  EventType=3;
    else     if(ElectronCollProbe[0].IsFake() && ElectronCollProbe[1].IsFake())  EventType=4;
    else     if(ElectronCollProbe[0].IsConv() && ElectronCollProbe[1].IsConv())  EventType=5;
    else     if(ElectronCollProbe[0].LeptonIsCF() && ElectronCollProbe[1].LeptonIsCF())      EventType=6;
    else     if(ElectronCollProbe[0].IsPrompt() && ElectronCollProbe[1].LeptonIsCF())      EventType=7;
    else     if(ElectronCollProbe[1].IsPrompt() && ElectronCollProbe[0].LeptonIsCF())      EventType=7;
    else     if(ElectronCollProbe[0].IsFake() && ElectronCollProbe[1].LeptonIsCF())      EventType=8;
    else     if(ElectronCollProbe[1].IsFake() && ElectronCollProbe[0].LeptonIsCF())      EventType=8;
    else     if(ElectronCollProbe[0].IsConv() && ElectronCollProbe[1].LeptonIsCF())      EventType=9;
    else     if(ElectronCollProbe[1].IsConv() && ElectronCollProbe[0].LeptonIsCF())      EventType=9;
    FillHist("Counter/SSElectron_Breakdown",  EventType , SSWeight, 10, 0, 10 );
  }

  for(auto ilep : LeptonCollProbe){

    TString tag= ilep->LepGenTypeString();
    if(ilep->LeptonIsCF()) tag = tag +"_IsCF";
    TString etabin = (fabs(ilep->Eta()) < 1.5) ? "BB_" : "EC_";
    TString ptbin = "Ptlt20_";

    if(ilep->IsMuon()){
      if(ilep->Pt() < 15) ptbin = "Ptlt15_";
      else if(ilep->Pt() < 20) ptbin = "Ptlt20_";
      else if(ilep->Pt() < 50) ptbin = "Ptlt50_";
      else if(ilep->Pt() < 100) ptbin = "Ptlt100_";
      else  ptbin = "Ptgt100_";
    }
    else{
      if(ilep->Pt() < 20) ptbin = "Ptlt20_";
      else if(ilep->Pt() < 50) ptbin = "Ptlt50_";
      else if(ilep->Pt() < 100) ptbin = "Ptlt100_";
      else  ptbin = "Ptgt100_";

    }
    
    vector<TString>   Tags = {tag+etabin+"/MVA_",
	    tag+etabin+ilep->MotherJetFlavour()+"/MVA_",
	    tag+ptbin+etabin+"/MVA_",
    };

    for(auto i  : Tags){

      if(i.Contains("Pileup")) continue;
      if(i.Contains("IsEWtau")) continue;
      if(i.Contains("IsCF") && !i.Contains("IsPrompt")) continue;
      if(i.Contains("LF") && !i.Contains("IsFake")) continue;
      if(i.Contains("HF") && !i.Contains("IsFake")) continue;
      
      if(i.Contains("IsFake") && HasBjet) continue;
      map<TString, double> mapBDT = ilep->MAPBDT();
      for(auto imap : mapBDT )  FillHist("BDTVariables/"+ ilep->GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
      
      if(SSMM||SSEE) {
	for(auto imap : mapBDT )FillHist("SSBDTVariables/"+ ilep->GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , SSWeight, 200, -1., 1);

      }
    }
  }
  
  for(auto imuon : MuonCollProbe){
    
    TString tag= imuon.LepGenTypeString();
    if(imuon.LeptonIsCF()) tag = tag +"_IsCF";
    TString etabin = (fabs(imuon.Eta()) < 1.5) ? "BB_" : "EC_";
    TString ptbin = "Ptlt20_";
    if(imuon.Pt() < 15) ptbin = "Ptlt15_";
    else if(imuon.Pt() < 20) ptbin = "Ptlt20_";
    else if(imuon.Pt() < 50) ptbin = "Ptlt50_";
    else if(imuon.Pt() < 100) ptbin = "Ptlt100_";
    else  ptbin = "Ptgt100_";


    vector<TString> Tags = {
                            tag+etabin+"/MVA_",
                            tag+etabin+imuon.MotherJetFlavour()+"/MVA_",
                            tag+ptbin+etabin+"/MVA_",

    };

    for(auto i  : Tags){

      if(i.Contains("Pileup")) continue;
      if(i.Contains("IsEWtau")) continue;
      if(i.Contains("IsCF") && !i.Contains("IsPrompt")) continue;
      if(i.Contains("LF") && !i.Contains("IsFake")) continue;
      if(i.Contains("HF") && !i.Contains("IsFake")) continue;
      
      if(i.Contains("IsFake") && HasBjet) continue;

      if(imuon.PassID("HNL_ULID_"+GetYearString()))FillMuonKinematicPlots("TightUL_"+imuon.GetFlavour()+i,"Tight"+imuon.GetFlavour(), imuon, weight);
      
      map<TString, double> mapBDT = imuon.MAPBDT();
      for(auto imap : mapBDT )  {
        if(imuon.HNL_MVA_Fake("HFTop") > 0.)   FillHist("BDTVariablesHFNP1/"+ imuon.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
        if(imuon.HNL_MVA_Fake("EDv4")  > 0.)   FillHist("BDTVariablesNP1/"  + imuon.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
        if(imuon.HNL_MVA_Fake("HFTop") > 0.2)  FillHist("BDTVariablesHFNP2/"+ imuon.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
        if(imuon.HNL_MVA_Fake("EDv4")  > 0.2)  FillHist("BDTVariablesNP2/"  + imuon.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
        if(imuon.HNL_MVA_Fake("HFTop") > 0.4)  FillHist("BDTVariablesHFNP3/"+ imuon.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
        if(imuon.HNL_MVA_Fake("EDv4")  > 0.4)  FillHist("BDTVariablesNP3/"  + imuon.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
        if(imuon.HNL_MVA_Fake("HFTop") > 0.6)  FillHist("BDTVariablesHFNP4/"+ imuon.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
        if(imuon.HNL_MVA_Fake("EDv4")  > 0.6)  FillHist("BDTVariablesNP4/"  + imuon.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
      }

      vector<TString> IDs = {"HNTightV2","HNL_Peking","HNTight_17028","HNL_HN3L","HNL_ULID_LF","HNL_ULID_"+GetYearString(), "HNL_HF_v1","HNL_HF_v2","HNL_HF_v3","HNL_HF_v4", "HNL_LF_v1","HNL_LF_v2","HNL_LF_v3","HNL_LF_v4","HNL_ULIDv1_2016","HNL_ULIDv1_2017"};

      int nbin_pt    =10;
      double ptbins    [nbin_pt    +1] = { 10.,15.,20.,30.,35., 40.,50., 60., 80., 100.,200.};
      double PtLep = (imuon.Pt() > 200) ? 199 : imuon.Pt();
      
      if(!i.Contains("Pt") )FillHist("IDEff/"+imuon.GetFlavour()+"Ptbinned_"+i+"_denominator", PtLep,   weight, nbin_pt, ptbins,"");
      
      for(auto ID : IDs){
	FillHist("TightID/"+ imuon.GetFlavour()+ "/"+ i+"_"+ID, 0  , weight, 2, 0, 2);
	if(!i.Contains("Pt") ){
	  if(imuon.PassID(ID))       FillHist("IDEff/"+imuon.GetFlavour()+"Ptbinned_"+i+ "_"+ID , PtLep,   weight, nbin_pt, ptbins,"");
	}

	if(imuon.PassID(ID))       FillHist("TightID/"+ imuon.GetFlavour()+ "/"+ i+"_"+ID, 1  , weight, 2, 0, 2);
	if(SSMM) {
	  FillHist("SSTightID/"+ imuon.GetFlavour()+ "/"+ i+"_"+ID, 0  , SSWeight, 2, 0, 2);
	  if(imuon.PassID(ID))       FillHist("SSTightID/"+ imuon.GetFlavour()+ "/"+ i+"_"+ID, 1  , SSWeight, 2, 0, 2);
	}
      }
    }
  }
  
  
  for(auto iel : ElectronCollProbe){

    TString tag= iel.LepGenTypeString();
    if(iel.LeptonIsCF()) tag = tag +"_IsCF";
    TString etabin = (fabs(iel.Eta()) < 1.5) ? "BB_" : "EC_";
    TString ptbin = "Ptlt20_";
    if(iel.Pt() < 15) ptbin = "Ptlt15_";
    else if(iel.Pt() < 20) ptbin = "Ptlt20_";
    else if(iel.Pt() < 50) ptbin = "Ptlt50_";
    else if(iel.Pt() < 100) ptbin = "Ptlt100_";
    else  ptbin = "Ptgt100_";

    vector<TString>    Tags = {tag+etabin+"/MVA_",
			       tag+etabin+iel.MotherJetFlavour()+"/MVA_",
			       tag+ptbin+etabin+"/MVA_"
    };

    
    ///////// HNL_ULID_Baseline  HAS COnv veto on top of MVALoose

    if(iel.PassID("HNL_ULID_Baseline")) {
      Tags.push_back(tag+etabin+"/Baseline_MVA_");
      Tags.push_back(tag+etabin+iel.MotherJetFlavour()+"/Baseline_MVA_");
      Tags.push_back(tag+ptbin+etabin+"/Baseline_MVA_");
    }
    
    for(auto i  : Tags){

      if(i.Contains("Pileup")) continue;
      if(i.Contains("IsEWtau")) continue;
      if(i.Contains("IsCF") && !i.Contains("IsPrompt")) continue;
      if(i.Contains("LF") && !i.Contains("IsFake")) continue;
      if(i.Contains("HF") && !i.Contains("IsFake")) continue;
      if(i.Contains("IsFake") && HasBjet) continue;
      

      if(iel.PassID("HNL_ULID_"+GetYearString()))FillElectronKinematicPlots("TightUL_"+iel.GetFlavour()+i,"Tight"+iel.GetFlavour(), iel, weight);
      FillElectronKinematicPlots("LooseUL_"+iel.GetFlavour()+i,"Tight"+iel.GetFlavour(), iel, weight);

      
      map<TString, double> mapBDT = iel.MAPBDT();
      for(auto imap : mapBDT )  {
	
	if(iel.IsBB() && iel.HNL_MVA_Fake("EDv4") > 0.2)                                                 FillHist("BDTVariablesNPBB1/"+ iel.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
	if(iel.IsBB() && iel.PassID("HNL_ULID_Conv_"+GetYearString()) && iel.HNL_MVA_Fake("EDv4") > 0.2) FillHist("BDTVariablesNPBB2/"+ iel.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
	if(iel.IsEC() && iel.HNL_MVA_Fake("EDv4") > 0.2) FillHist("BDTVariablesNPEC1/"+ iel.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
	if(iel.IsEC() && iel.HNL_MVA_Fake("EDv4") > 0.2 && iel.PassID("HNL_ULID_Conv_"+GetYearString())) FillHist("BDTVariablesNPEC2/"+ iel.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
	
	if(iel.IsBB() && iel.HNL_MVA_CF("v2")   >0.2) FillHist("BDTVariablesCFBB1/"+ iel.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
	if(iel.IsEC() && iel.HNL_MVA_CF("EDv2") >0.2)  FillHist("BDTVariablesCFEC1/"+ iel.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
        if(iel.IsBB() && iel.HNL_MVA_CF("v2")   >0.4) FillHist("BDTVariablesCFBB2/"+ iel.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
        if(iel.IsEC() && iel.HNL_MVA_CF("EDv2") >0.4)  FillHist("BDTVariablesCFEC2/"+ iel.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);

	if(iel.IsBB() && iel.HNL_MVA_Fake("EDv4") > 0.2  && iel.HNL_MVA_CF("v2") >0.2) FillHist("BDTVariablesNPCFBB1/"+ iel.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
	if(iel.IsEC() && iel.HNL_MVA_Fake("EDv4") > 0.2  && iel.HNL_MVA_CF("EDv2") >0.2)  FillHist("BDTVariablesNPCFEC1/"+ iel.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
        if(iel.IsBB() && iel.HNL_MVA_Fake("EDv4") > 0.2  && iel.HNL_MVA_CF("v2") >0.4) FillHist("BDTVariablesNPCFBB2/"+ iel.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
        if(iel.IsEC() && iel.HNL_MVA_Fake("EDv4") > 0.2  && iel.HNL_MVA_CF("EDv2") >0.4)  FillHist("BDTVariablesNPCFEC2/"+ iel.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);

	if(iel.IsBB() && iel.HNL_MVA_CF("v2") >0.2 &&  iel.PassID("HNL_ULID_Conv_"+GetYearString()))      FillHist("BDTVariablesConvCFBB1/"+ iel.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
	if(iel.IsBB() && iel.HNL_MVA_CF("v2") >0.4 &&  iel.PassID("HNL_ULID_Conv_"+GetYearString()))      FillHist("BDTVariablesConvCFBB2/"+ iel.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
	if(iel.IsBB() && iel.HNL_MVA_CF("v2") >0.7 &&  iel.PassID("HNL_ULID_Conv_"+GetYearString()))      FillHist("BDTVariablesConvCFBB3/"+ iel.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
	
	if(iel.IsEC() && iel.HNL_MVA_CF("EDv2") >0.3 &&  iel.PassID("HNL_ULID_Conv_"+GetYearString())) FillHist("BDTVariablesConvCFEC1/"+ iel.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
	if(iel.IsEC() && iel.HNL_MVA_CF("EDv2") >0.5 &&  iel.PassID("HNL_ULID_Conv_"+GetYearString())) FillHist("BDTVariablesConvCFEC2/"+ iel.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , weight, 200, -1., 1);
	
	if(SSEE) {
	  if(iel.IsBB() && iel.HNL_MVA_Fake("EDv4") > .2) FillHist("SSBDTVariablesNPBB1/"+ iel.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , SSWeight, 200, -1., 1);
	  if(iel.IsBB() && iel.HNL_MVA_Conv("v2") > -0.7 && iel.HNL_MVA_Fake("EDv4") > 0.2) FillHist("SSBDTVariablesNPBB2/"+ iel.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , SSWeight, 200, -1., 1);
	  if(iel.IsEC() && iel.HNL_MVA_Fake("EDv4") > 0.2) FillHist("SSBDTVariablesNPEC1/"+ iel.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , SSWeight, 200, -1., 1);
	  if(iel.IsEC() && iel.HNL_MVA_Fake("EDv4") > 0.2 && iel.HNL_MVA_Conv("EDv2") > -0.7 ) FillHist("SSBDTVariablesNPEC2/"+ iel.GetFlavour()+ "/"+ i+"_"+imap.first, imap.second  , SSWeight, 200, -1., 1);
	}
      }
      

      vector<TString> IDs = {"HNTightV2","HNL_Peking_"+GetYearString(),  "HNTight_17028","HNL_ULID_"+GetYearString() , "HNL_ULID_Conv_"+GetYearString(),  "HNL_ULID_Fake1","HNL_ULID_Fake2","HNL_ULID_Fake3","HNL_ULID_Fake4" , "HNL_ULID_CF1","HNL_ULID_CF2","HNL_ULID_CF3","HNL_ULID_CF4","HNL_ULID_Conv1","HNL_ULID_Conv2"};

      int nbin_pt    =10;
      double ptbins    [nbin_pt    +1] = { 10.,15.,20.,30.,35., 40.,50., 60., 80., 100.,200.};
      double PtLep = (iel.Pt() > 200) ? 199 : iel.Pt();

      if(!i.Contains("Pt") )      FillHist("IDEff/"+iel.GetFlavour()+"Ptbinned_"+i+"_denominator", PtLep,   weight, nbin_pt, ptbins,"");
      

      for(auto ID : IDs){
        FillHist("TightID/"+ iel.GetFlavour()+ "/"+ i+"_"+ID, 0  , weight, 2, 0, 2);

	if(!i.Contains("Pt") ){
	  if(iel.PassID(ID))       FillHist("IDEff/"+iel.GetFlavour()+"Ptbinned_"+i+ "_"+ID , PtLep,   weight, nbin_pt, ptbins,"");
	}
        if(iel.PassID(ID))       FillHist("TightID/"+ iel.GetFlavour()+ "/"+ i+"_"+ID, 1  , weight, 2, 0, 2);
        if(SSEE) {
          FillHist("SSTightID/"+ iel.GetFlavour()+ "/"+ i+"_"+ID, 0  , SSWeight, 2, 0, 2);
          if(iel.PassID(ID))       FillHist("SSTightID/"+ iel.GetFlavour()+ "/"+ i+"_"+ID, 1  , SSWeight, 2, 0, 2);
        }
      } // IDs
    } // Tags
  }
  
  

  
  return;  
  CheckSSFakeBreakDown(param,EE, ElectronCollProbe, MuonCollProbe, weight);
  CheckSSFakeBreakDown(param,MuMu, ElectronCollProbe, MuonCollProbe, weight);
  


  HNL_LeptonCore::Channel dilep_channel= EE;
  if(MuonCollProbe.size() > 0) return;
  if(HasFlag("BDT"))MakeBDTPlots(param,dilep_channel, ElectronCollProbe, param.Electron_Tight_ID, weight);
  
  return;
  
  
}


void HNL_LeptonIDBDTStudies::MakeJetDiscPlots(TString label, AnalyzerParameter param,HNL_LeptonCore::Channel dilep_channel, vector<Electron> ElectronColl ,vector<Muon>       MuonColl, double weight_ll){

  TString channel_string = GetChannelString(dilep_channel) ;

  std::vector<Lepton *> LeptonColl      = MakeLeptonPointerVector(MuonColl, ElectronColl);

  if(label.Contains("Tight"))  weight_ll*=GetLeptonSFEventWeight(LeptonColl,param);
  
  std::vector<Electron>   ElectronCollV = GetElectrons(param.Electron_Veto_ID, 10., 2.5);
  std::vector<Muon>       MuonCollV     = GetMuons    (param.Muon_Veto_ID, 5., 2.4);
  std::vector<Lepton *>   LeptonCollV      = MakeLeptonPointerVector(MuonCollV, ElectronCollV);


  //// Select TT -> emu for Top sample
  
  Event ev = GetEvent();
  if(LeptonColl.size() != 2) return;
  if(HasFlag("SS")){
    if(!SameCharge(LeptonColl)) return;
  }
  else {
    if(SameCharge(LeptonColl)) return;
  }

  Particle METv = GetvMET("PuppiT1xyCorr"); // reyturns MET with systematic correction                                                                                                 

  std::vector<Jet>      JetColl     = GetHNLJets("Tight", param);
  std::vector<Jet> BJetColl  = GetHNLJets("BJetM", param);                                                                                                                

  if(HasFlag("SS")){
    if(BJetColl.size() == 0) return;
  }

  double metcut = (HasFlag("SS")) ? 30. : 40;
  

  if(ElectronColl.size() == 1 && MuonColl.size()   == 1){
    if(ElectronCollV.size() == 1 && MuonCollV.size()   == 1){
      if((JetColl.size() > 3 && METv.Pt() > metcut )){
	if(dilep_channel==MuMu){
	  if(PassTriggerSelection(dilep_channel, ev, LeptonColl,"Lep")){

	    if(MuonColl[0].Pt() > 20) {
	      
	      vector<Jet> JetAllColl = GetAllJets();
	      TString cut = "TopJets_TightMu";
	      
	      FillHist(cut +"/MET_"+channel_string, GetvMET("PuppiT1xyCorr").Pt(), weight_ll, 200, 0., 200);
	      if(JetColl.size() < 6) FillHist(cut +"/NJet_"+channel_string, JetColl.size(), weight_ll, 8, 0., 8);
	      else FillHist(cut +"/NJet_"+channel_string, 6., weight_ll, 8, 0., 8);

	      FillHist(cut +"/MuonPt_"+channel_string+"_"+label, MuonColl[0].Pt(), weight_ll, 40, 0., 200);
	      FillHist(cut +"/ElectronPt_"+channel_string+"_"+label, ElectronColl[0].Pt(), weight_ll, 40, 0., 200);
	      
              FillHist(cut +"/MET_"+channel_string+"_"+label, GetvMET("PuppiT1xyCorr").Pt(), weight_ll, 200, 0., 200);
              if(JetColl.size() < 6) FillHist(cut +"/NJet_"+channel_string+"_"+label, JetColl.size(), weight_ll, 8, 0., 8);
              else FillHist(cut +"/NJet_"+channel_string+"_"+label, 6., weight_ll, 8, 0., 8);

	      for(auto ilep: LeptonColl){
		
		if(ilep->Pt() > 25) FillHist( cut+ "/"+ilep->GetFlavour() + "Jet_gt25PtRatio_"+label   , JetLeptonPtRatioLepAware(*ilep) , weight_ll, 200,0,2);
		if(ilep->Pt() > 25)     FillHist( cut+ "/"+ilep->GetFlavour() + "Jet_gt25PtRel_"+label   , JetLeptonPtRelLepAware(*ilep) , weight_ll, 200,0,200);
                FillHist( cut+ "/"+ilep->GetFlavour() + "Jet_PtRel_"+label   , JetLeptonPtRelLepAware(*ilep) , weight_ll, 200,0,200);
                FillHist( cut+ "/"+ilep->GetFlavour() + "Jet_PtRatio_"+label   , JetLeptonPtRatioLepAware(*ilep) , weight_ll, 200,0,2);
		if(ilep->IsPrompt( )){
		  FillHist( cut+ "/"+ilep->GetFlavour() + "PromptLep_Jet_PtRel_"+label   , JetLeptonPtRelLepAware(*ilep) , weight_ll, 200,0,200);

		  FillHist( cut+ "/"+ilep->GetFlavour() + "PromptLep_Jet_PtRatio_"+label   , JetLeptonPtRatioLepAware(*ilep) , weight_ll, 200,0,2);

		}

              }

	      for(unsigned int ij=0; ij<JetAllColl.size(); ij++){
		
		bool closelep(false);
		TString lepflav="";
		TString ptlabel="";
		bool isprompt(true);

		for(auto ilep : LeptonCollV) {
		  if(ilep->DeltaR(JetAllColl.at(ij)) < 0.4) {
		    closelep=true;
		    lepflav=ilep->GetFlavour();
		    if(ilep->Pt() < 20) ptlabel="lt20_";
		    else if(ilep->Pt() < 35)ptlabel="lt35_";
		    else ptlabel="gt35_";
		    if(!ilep->IsPrompt( )) isprompt=false;
		  }
		}
		
		if(!closelep){
		  if(!JetAllColl.at(ij).PassID("tight")) continue;
		  if(JetAllColl.at(ij).Pt() < 20) continue;
		}
		
		FillHist( cut+ "/JetDisc_DeepJet_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
		
		if(closelep) {

		  double mc_cj_disc_corr  = GetCorrCloseJetDisc(true, JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet)) ;
		  
		  FillHist( cut+ "/CJ_JetDisc_DeepJet_"+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
		  FillHist( cut+ "/CJ_JetDisc_DeepJet_"+ptlabel+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
		  
		  FillHist( cut+ "/ModCJ_JetDisc_DeepJet_"+lepflav+"_"+label   , mc_cj_disc_corr , weight_ll, 1000,0,1);
		  FillHist( cut+ "/ModCJ_JetDisc_DeepJet_"+ptlabel+lepflav+"_"+label   , mc_cj_disc_corr , weight_ll, 1000,0,1);

		  if(isprompt){
		    FillHist( cut+ "/CJ_PromptLep_JetDisc_DeepJet_"+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
		    FillHist( cut+ "/CJ_PromptLep_JetDisc_DeepJet_"+ptlabel+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
		  }
		  else{
		    FillHist( cut+ "/CJ_NonPromptLep_JetDisc_DeepJet_"+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
                    FillHist( cut+ "/CJ_NonPromptLep_JetDisc_DeepJet_"+ptlabel+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
		  }
		}
		else {
		  FillHist( cut+ "/AJ_JetDisc_DeepJet_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
		  if(JetAllColl.at(ij).Pt() > 30) FillHist( cut+ "/AJ_JetDisc_DeepJet30_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
		}
		
		if(JetAllColl.at(ij).PassID("tight")) {
		  if(closelep)    FillHist( cut+ "/TightCJ_JetDisc_DeepJet_"+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
		  else {
		    FillHist( cut+ "/TightAJ_JetDisc_DeepJet_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
		    if(JetAllColl.at(ij).Pt() > 30) FillHist( cut+ "/TightAJ_JetDisc_DeepJet30_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
		  }
		}
	      }
	      
	      //FillElectronPlots("ElectronMuon","Top",ElectronColl,weight_ll);
	      //if(BJetColl.size() > 1)FillElectronPlots("ElectronMuon","BTop",ElectronColl,weight_ll);
	    }
	  }
	}
	else if(dilep_channel==EE){

	  if(PassTriggerSelection(dilep_channel, ev, LeptonColl,"Lep")){
	    
	    if(ElectronColl[0].Pt() > 20) {
	      
	      vector<Jet> JetAllColl = GetAllJets();
	      TString cut = "TopJets_TightEl";

	      FillHist(cut +"/MET_"+channel_string, GetvMET("PuppiT1xyCorr").Pt(), weight_ll, 200, 0., 200);
	      if(JetColl.size() < 6) FillHist(cut +"/NJet_"+channel_string, JetColl.size(), weight_ll, 8, 0., 8);
	      else FillHist(cut +"/NJet_"+channel_string, 6., weight_ll, 8, 0., 8);

	      FillHist(cut +"/MuonPt_"+channel_string+"_"+label, MuonColl[0].Pt(), weight_ll, 40, 0., 200);
	      FillHist(cut +"/ElectronPt_"+channel_string+"_"+label, ElectronColl[0].Pt(), weight_ll, 40, 0., 200);
	      FillHist(cut +"/MET_"+channel_string+"_"+label, GetvMET("PuppiT1xyCorr").Pt(), weight_ll, 200, 0., 200);
              if(JetColl.size() < 6) FillHist(cut +"/NJet_"+channel_string+"_"+label, JetColl.size(), weight_ll, 8, 0., 8);
              else FillHist(cut +"/NJet_"+channel_string+"_"+label, 6., weight_ll, 8, 0., 8);


	      for(auto ilep: LeptonColl){
		if(ilep->Pt() > 25) FillHist( cut+ "/"+ilep->GetFlavour() + "Jet_gt25PtRatio_"+label   , JetLeptonPtRatioLepAware(*ilep) , weight_ll, 200,0,2);
		if(ilep->Pt() > 25)     FillHist( cut+ "/"+ilep->GetFlavour() + "Jet_gt25PtRel_"+label   , JetLeptonPtRelLepAware(*ilep) , weight_ll, 200,0,200);
                FillHist( cut+ "/"+ilep->GetFlavour() + "Jet_PtRel_"+label   , JetLeptonPtRelLepAware(*ilep) , weight_ll, 200,0,200);
                FillHist( cut+ "/"+ilep->GetFlavour() + "Jet_PtRatio_"+label   , JetLeptonPtRatioLepAware(*ilep) , weight_ll, 200,0,2);

		if(ilep->IsPrompt()){
                  FillHist( cut+ "/"+ilep->GetFlavour() + "PromptLep_Jet_PtRel_"+label   , JetLeptonPtRelLepAware(*ilep) , weight_ll, 200,0,200);

                  FillHist( cut+ "/"+ilep->GetFlavour() + "PromptLep_Jet_PtRatio_"+label   , JetLeptonPtRatioLepAware(*ilep) , weight_ll, 200,0,2);

                }


	      }

	      for(unsigned int ij=0; ij<JetAllColl.size(); ij++){
		
		bool closelep(false);
		TString lepflav="";
		TString ptlabel="";
		bool isprompt=true;
		for(auto ilep : LeptonCollV) {
		  if(ilep->DeltaR(JetAllColl.at(ij)) < 0.4) {
		    closelep=true;
		    lepflav=ilep->GetFlavour();
		    if(ilep->Pt() < 20)ptlabel="lt20_";
                    else if(ilep->Pt() < 35)ptlabel="lt35_";
                    else ptlabel="gt35_";
                    if(!ilep->IsPrompt()) isprompt=false;

		  }
		}
		
		if(!closelep){
		  if(!JetAllColl.at(ij).PassID("tight")) continue;
		  if(JetAllColl.at(ij).Pt() < 20) continue;
		}
		
		FillHist( cut+ "/JetDisc_DeepJet_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
		
		if(closelep) {
                  double mc_cj_disc_corr  = GetCorrCloseJetDisc(false, JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet)) ;

		  FillHist( cut+ "/CJ_JetDisc_DeepJet_"+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
		  FillHist( cut+ "/CJ_JetDisc_DeepJet_"+ptlabel+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
		  
                  FillHist( cut+ "/ModCJ_JetDisc_DeepJet_"+lepflav+"_"+label   , mc_cj_disc_corr , weight_ll, 1000,0,1);

                  FillHist( cut+ "/ModCJ_JetDisc_DeepJet_"+ptlabel+lepflav+"_"+label   , mc_cj_disc_corr , weight_ll, 1000,0,1);


		  if(isprompt){
                    FillHist( cut+ "/CJ_PromptLep_JetDisc_DeepJet_"+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
                    FillHist( cut+ "/CJ_PromptLep_JetDisc_DeepJet_"+ptlabel+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
                  }
		  else{
                    FillHist( cut+ "/CJ_NonPromptLep_JetDisc_DeepJet_"+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
                    FillHist( cut+ "/CJ_NonPromptLep_JetDisc_DeepJet_"+ptlabel+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
                  }

		}
		else {
		  FillHist( cut+ "/AJ_JetDisc_DeepJet_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
                  if(JetAllColl.at(ij).Pt() > 30) FillHist( cut+ "/AJ_JetDisc_DeepJet30_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
		}
		
		if(JetAllColl.at(ij).PassID("tight")) {
		  if(closelep)    FillHist( cut+ "/TightCJ_JetDisc_DeepJet_"+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
		  else FillHist( cut+ "/TightAJ_JetDisc_DeepJet_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
		}
		if(BJetColl.size() > 1){
		  FillHist( cut+ "BJetEv/JetDisc_DeepJet_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
		  
		  if(closelep)    FillHist( cut+ "BJetEv/CJ_JetDisc_DeepJet_"+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
		  else FillHist( cut+ "BJetEv/AJ_JetDisc_DeepJet_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
		  
		  if(JetAllColl.at(ij).PassID("tight")) {
		    if(closelep)    FillHist( cut+ "BJetEv/TightCJ_JetDisc_DeepJet_"+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
		    else FillHist( cut+ "BJetEv/TightAJ_JetDisc_DeepJet_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
		  }
		  
		}
	      }
	    }
	  }
	}
      }
    }
  }
  else{
  

    if(!PassTriggerSelection(dilep_channel, ev, LeptonColl,"Lep")) return;

    if(dilep_channel==EE && ElectronCollV.size() != 2) return;
    if(dilep_channel==EE &&  MuonCollV.size() > 0) return;
    if(dilep_channel==MuMu && MuonCollV.size() != 2) return;
    if(dilep_channel==MuMu && ElectronCollV.size()  > 0) return;
       
    if(dilep_channel==EE && ElectronColl.size() != 2) return;
    if(dilep_channel==EE &&  MuonColl.size() > 0) return;
    if(dilep_channel==MuMu && MuonColl.size() != 2) return;
    if(dilep_channel==MuMu && ElectronColl.size()  > 0) return;

    if(LeptonColl.size() != 2) return;

    if(dilep_channel==EE && ElectronCollV[0].Pt() < 35) return;
    if(dilep_channel==MuMu && MuonCollV[0].Pt() < 35) return;
    if(SameCharge(LeptonColl)) return;

    // Z peak 
    

    if(fabs(GetLLMass(LeptonColl)- 90.1) < 10 && METv.Pt() < 30) {
     
      vector<Jet> JetAllColl = GetAllJets();
      TString cut = "ZJets_"+channel_string;

      if(dilep_channel==MuMu)FillHist(cut +"/MuonPt_"+channel_string+"_"+label, MuonColl[1].Pt(), weight_ll, 40, 0., 200);
      if(dilep_channel==EE)  FillHist(cut +"/ElectronPt_"+channel_string+"_"+label, ElectronColl[1].Pt(), weight_ll, 40, 0., 200);

      FillHist(cut +"/MET_"+channel_string, GetvMET("PuppiT1xyCorr").Pt(), weight_ll, 200, 0., 200);
      if(JetColl.size() < 6) FillHist(cut +"/NJet_"+channel_string, JetColl.size(), weight_ll, 8, 0., 8);
      else FillHist(cut +"/NJet_"+channel_string, 6., weight_ll, 8, 0., 8);


      FillHist(cut +"/MET_"+channel_string+"_"+label, GetvMET("PuppiT1xyCorr").Pt(), weight_ll, 200, 0., 200);
      if(JetColl.size() < 6) FillHist(cut +"/NJet_"+channel_string+"_"+label, JetColl.size(), weight_ll, 8, 0., 8);
      else FillHist(cut +"/NJet_"+channel_string+"_"+label, 6., weight_ll, 8, 0., 8);


      for(unsigned int ij=0; ij<JetAllColl.size(); ij++){

	bool closelep(false);
	TString lepflav="";
	TString ptlabel="";
	bool isprompt=true;
	for(auto ilep : LeptonCollV) {
	  if(ilep->DeltaR(JetAllColl.at(ij)) < 0.4) {
	    closelep=true;
	    lepflav=ilep->GetFlavour();
	    if(ilep->Pt() < 20)ptlabel="lt20_";
	    else if(ilep->Pt() < 35)ptlabel="lt35_";
	    else ptlabel="gt35_";
	    if(!ilep->IsPrompt()) isprompt=false;
	  }
	}
	
	if(!closelep){
	  if(!JetAllColl.at(ij).PassID("tight")) continue;
	  if(JetAllColl.at(ij).Pt() < 20) continue;
	}

	FillHist( cut+ "/JetDisc_DeepJet_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);

	if(closelep)    {
	  double mc_cj_disc_corr  = (lepflav=="Electron") ? GetCorrCloseJetDisc(false, JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet)):  GetCorrCloseJetDisc(true, JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet)) ;

	  FillHist( cut+ "/CJ_JetDisc_DeepJet_"+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
	  FillHist( cut+ "/CJ_JetDisc_DeepJet_"+ptlabel+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
	  FillHist( cut+ "/ModCJ_JetDisc_DeepJet_"+lepflav+"_"+label   , mc_cj_disc_corr , weight_ll, 1000,0,1);
	  FillHist( cut+ "/ModCJ_JetDisc_DeepJet_"+ptlabel+lepflav+"_"+label   , mc_cj_disc_corr , weight_ll, 1000,0,1);

	  if(isprompt){
	    FillHist( cut+ "/CJ_PromptLep_JetDisc_DeepJet_"+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
	    FillHist( cut+ "/CJ_PromptLep_JetDisc_DeepJet_"+ptlabel+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
	  }
	  else{
	    FillHist( cut+ "/CJ_NonPromptLep_JetDisc_DeepJet_"+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
	    FillHist( cut+ "/CJ_NonPromptLep_JetDisc_DeepJet_"+ptlabel+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
	  }

	}
	else FillHist( cut+ "/AJ_JetDisc_DeepJet_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);

	if(JetAllColl.at(ij).PassID("tight")) {
	  if(closelep)    FillHist( cut+ "/TightCJ_JetDisc_DeepJet_"+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
	  else FillHist( cut+ "/TightAJ_JetDisc_DeepJet_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
	}
	if(BJetColl.size() > 1){
	  FillHist( cut+ "BJetEv/JetDisc_DeepJet_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);

	  if(closelep)    FillHist( cut+ "BJetEv/CJ_JetDisc_DeepJet_"+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
	  else FillHist( cut+ "BJetEv/AJ_JetDisc_DeepJet_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);

	  if(JetAllColl.at(ij).PassID("tight")) {
	    if(closelep)    FillHist( cut+ "BJetEv/TightCJ_JetDisc_DeepJet_"+lepflav+"_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
	    else FillHist( cut+ "BJetEv/TightAJ_JetDisc_DeepJet_"+label   , JetAllColl.at(ij).GetTaggerResult(JetTagging::DeepJet) , weight_ll, 1000,0,1);
	  }
	  
	}
      }
      
      for(auto ilep : LeptonColl){

	if(ilep->Pt() > 25) FillHist( cut+ "/"+ilep->GetFlavour() + "Jet_gt25PtRatio_"+label   , JetLeptonPtRatioLepAware(*ilep) , weight_ll, 200,0,2);
	if(ilep->Pt() > 25) 	FillHist( cut+ "/"+ilep->GetFlavour() + "Jet_gt25PtRel_"+label   , JetLeptonPtRelLepAware(*ilep) , weight_ll, 200,0,200);
	
	FillHist( cut+ "/"+ilep->GetFlavour() + "Jet_PtRel_"+label   , JetLeptonPtRelLepAware(*ilep) , weight_ll, 200,0,200);

	FillHist( cut+ "/"+ilep->GetFlavour() + "Jet_PtRatio_"+label   , JetLeptonPtRatioLepAware(*ilep) , weight_ll, 200,0,2);


	if(ilep->IsPrompt()){
	  FillHist( cut+ "/"+ilep->GetFlavour() + "PromptLep_Jet_PtRel_"+label   , JetLeptonPtRelLepAware(*ilep) , weight_ll, 200,0,200);

	  FillHist( cut+ "/"+ilep->GetFlavour() + "PromptLep_Jet_PtRatio_"+label   , JetLeptonPtRatioLepAware(*ilep) , weight_ll, 200,0,2);

	}

      }
    }
  }
  
  return;

}



void HNL_LeptonIDBDTStudies::CheckSSFakeBreakDown(AnalyzerParameter param,HNL_LeptonCore::Channel dilep_channel, vector<Electron> ElectronColl, vector<Muon> MuonColl , double weight_ll){

  //// Check out SS Fake breakdown
  // How many By Type
  // Split by HF/LF

  if(IsData) return;

  TString channel_string = GetChannelString(dilep_channel) ;
  
  std::vector<Lepton *> LeptonColl      = MakeLeptonPointerVector(MuonColl, ElectronColl);

  vector<TString> lables = GetGenList();

  if(dilep_channel==EE){

    if(MuonColl.size()>0) return;

    vector<Electron> ElectronCollFake     = SkimLepColl(ElectronColl, param, "HFake");
    vector<Electron> ElectronCollPrompt   = SkimLepColl(ElectronColl, param, "PromptNoCF");
    
    if(ElectronCollFake.size()==0) return;
    
    for(auto iel : ElectronCollFake) {
      
      TString lep_fake_tag=MatchGenDef(All_Gens, iel); 
      if (std::find(lables.begin(), lables.end(), lep_fake_tag) == lables.end()){

        cout << "Reco " << iel.GetFlavour() << " pt = " << iel.Pt() << " eta = " << iel.Eta() << " phi = " << iel.Phi() << endl;                                        
        cout << "CloseJet_Flavour = " << iel.CloseJet_Flavour() << endl;                                                                             
	
	cout << "lep_fake_tag = " << lep_fake_tag << " missing "<< endl;
        PrintMatchedGen(All_Gens, iel);                                                                                                                                
	
      }
      else {
	if(iel.CloseJet_FlavourInt()==0) FillEventCutflowAll("Electron", "LF_Fake_type", weight_ll, lables,lep_fake_tag);
	if(iel.CloseJet_FlavourInt()==4) FillEventCutflowAll("Electron", "HFC_Fake_type", weight_ll, lables,lep_fake_tag);
	if(iel.CloseJet_FlavourInt()==5) FillEventCutflowAll("Electron", "HFB_Fake_type", weight_ll, lables,lep_fake_tag);
	
        if(iel.CloseJet_FlavourInt()==4) FillEventCutflowAll("Electron", "HF_Fake_type", weight_ll, lables,lep_fake_tag);
        if(iel.CloseJet_FlavourInt()==5) FillEventCutflowAll("Electron", "HF_Fake_type", weight_ll, lables,lep_fake_tag);

	if(SameCharge(LeptonColl)){
	  
	  if(iel.CloseJet_FlavourInt()==0) FillEventCutflowAll("SSElectron", "LF_Fake_type", weight_ll, lables,lep_fake_tag);
	  
	  if(iel.CloseJet_FlavourInt()==4) FillEventCutflowAll("SSElectron", "HFC_Fake_type", weight_ll, lables,lep_fake_tag);	  
	  if(iel.CloseJet_FlavourInt()==5) FillEventCutflowAll("SSElectron", "HFB_Fake_type", weight_ll, lables,lep_fake_tag);
	  if(iel.CloseJet_FlavourInt()==4) FillEventCutflowAll("SSElectron", "HF_Fake_type", weight_ll, lables,lep_fake_tag);
          if(iel.CloseJet_FlavourInt()==5) FillEventCutflowAll("SSElectron", "HF_Fake_type", weight_ll, lables,lep_fake_tag);

	}
      }
    }
    
    //// Now events are SS dilepton with 1/2 fakes
    
    FillAllElectronPlots("FakeElectron","MC"+channel_string,ElectronCollFake,weight_ll);
    FillAllElectronPlots("PromptElectron","MC"+channel_string,ElectronCollPrompt,weight_ll);

    if(!CheckLeptonFlavourForChannel(dilep_channel, LeptonColl)) return; // Check if EE cahnnel has 2 el                                                                                                                                                                                         
    if(!SameCharge(LeptonColl)) return;

    FillAllElectronPlots("SS_FakeElectron","MC"+channel_string,ElectronCollFake,weight_ll);
    FillAllElectronPlots("SS_PromptElectron","MC"+channel_string,ElectronCollPrompt,weight_ll);

    
  }
  
  if(dilep_channel==MuMu){

    if(ElectronColl.size()>0) return;

    vector<Muon> MuonCollFake     = SkimLepColl(MuonColl, param, "HFake");
    vector<Muon> MuonCollPrompt   = SkimLepColl(MuonColl, param, "Prompt");
    
    if(MuonCollFake.size()==0) return;

    //// Now events are SS dilepton with 1/2 fakes                                                                                                                                            
    FillAllMuonPlots("PromptMuon","MC"+channel_string,MuonCollPrompt,weight_ll);                                                                                                        
    FillAllMuonPlots("FakeMuon"  ,"MC"+channel_string,MuonCollFake,weight_ll);
                                                 
    for(auto imu : MuonCollFake) {

      TString lep_fake_tag=MatchGenDef(All_Gens, imu);
      
      if (std::find(lables.begin(), lables.end(), lep_fake_tag) == lables.end()){
	cout << "Reco " << imu.GetFlavour() << " pt = " << imu.Pt() << " eta = " << imu.Eta() << " phi = " << imu.Phi() << endl;
	cout << "CloseJet_Flavour = " << imu.CloseJet_Flavour() << endl;
	cout <<"lep_fake_tag = " << lep_fake_tag << " missing "<< endl;
        PrintMatchedGen(All_Gens, imu);

      }

      else{
	if(imu.CloseJet_FlavourInt()==0) FillEventCutflowAll("Muon", "LF_Fake_type", weight_ll, lables,lep_fake_tag);
	if(imu.CloseJet_FlavourInt()==4) FillEventCutflowAll("Muon", "HFC_Fake_type", weight_ll, lables,lep_fake_tag);
	if(imu.CloseJet_FlavourInt()==5) FillEventCutflowAll("Muon", "HFB_Fake_type", weight_ll, lables,lep_fake_tag);
        if(imu.CloseJet_FlavourInt()==4) FillEventCutflowAll("Muon", "HF_Fake_type", weight_ll, lables,lep_fake_tag);
        if(imu.CloseJet_FlavourInt()==5) FillEventCutflowAll("Muon", "HF_Fake_type", weight_ll, lables,lep_fake_tag);


	if(SameCharge(LeptonColl))  {
	  if(imu.CloseJet_FlavourInt()==0) FillEventCutflowAll("SSMuon", "LF_Fake_type", weight_ll, lables,lep_fake_tag);
	  
	  if(imu.CloseJet_FlavourInt()==4) FillEventCutflowAll("SSMuon", "HFC_Fake_type", weight_ll, lables,lep_fake_tag);	  
	  if(imu.CloseJet_FlavourInt()==5) FillEventCutflowAll("SSMuon", "HFB_Fake_type", weight_ll, lables,lep_fake_tag);
	  if(imu.CloseJet_FlavourInt()==4) FillEventCutflowAll("SSMuon", "HF_Fake_type", weight_ll, lables,lep_fake_tag);
          if(imu.CloseJet_FlavourInt()==5) FillEventCutflowAll("SSMuon", "HF_Fake_type", weight_ll, lables,lep_fake_tag);
	  
	}
      }
      
    }
    if(!SameCharge(LeptonColl))return;

    FillAllMuonPlots("SS_FakeMuon","MC"+channel_string,MuonCollFake,weight_ll);
    FillAllMuonPlots("SS_PromptMuon","MC"+channel_string,MuonCollPrompt,weight_ll);
        
  }
  
    

  return; 

}

void HNL_LeptonIDBDTStudies::MakeBDTPlots(AnalyzerParameter param,HNL_LeptonCore::Channel dilep_channel, vector<Electron> ElectronColl, TString ID, double weight_ll){

  TString channel_string = GetChannelString(dilep_channel) ;

  std::vector<Lepton *> LeptonColl      = MakeLeptonPointerVector(ElectronColl);
  
  if(!IsData){

    vector<Electron> ElectronCollFake     = SkimLepColl(ElectronColl, param, "HFake");
    FillAllElectronPlots("FakeElectron","MC"+channel_string,ElectronCollFake,weight_ll);

    vector<Electron> ElectronCollCF     = SkimLepColl(ElectronColl,  param, "CF");
    FillAllElectronPlots("CFElectron","MC"+channel_string,ElectronCollCF,weight_ll);

    vector<Electron> ElectronCollConv     = SkimLepColl(ElectronColl, param, "NHConv");
    FillAllElectronPlots("ConvElectron","MC"+channel_string,ElectronCollConv,weight_ll);

    vector<Electron> ElectronCollPrompt   = SkimLepColl(ElectronColl, param, "PromptNoCF");
    FillAllElectronPlots("PromptElectron","MC"+channel_string,ElectronCollPrompt,weight_ll);
  }
  

  if(!CheckLeptonFlavourForChannel(dilep_channel, LeptonColl)) return; // Check if EE cahnnel has 2 el                            
  Event ev = GetEvent();
  
  if(!PassTriggerSelection(dilep_channel, ev, LeptonColl,"Dilep")) return;

  if(LeptonColl.size() != 2) return;
 
  Particle METv = GetvMET("PuppiT1xyCorr"); // reyturns MET with systematic correction                                            

  std::vector<Jet> BJetColl  = GetHNLJets("BJetM", param);
  // use Z peak                                                                                                                              
  if(fabs(GetLLMass(LeptonColl)- 90.1) < 10 && METv.Pt() < 30&& BJetColl.size()==0) {
    
    if(ElectronColl[0].PassID("passPOGTight") && ElectronColl[1].PassID("passPOGTight") ){
      AnalyzerParameter paramPOG=param;
      paramPOG.Electron_ID_SF_Key = "passTightID";
      double POGSF = GetElectronSFEventWeight(ElectronColl,paramPOG);
      if(!IsData)  POGSF*= 0.95;
      FillHist(channel_string+"/"+ID+"/llmass_"+channel_string, GetLLMass(LeptonColl), weight_ll*POGSF, 70, 50., 120);
      FillHist(channel_string+"/"+ID+"/NVTX_"+channel_string, nPileUp, weight_ll*POGSF, 100, 0., 100);
      FillHist(channel_string+"/"+ID+"/MET_"+channel_string, GetvMET("PuppiT1xyCorr").Pt(), weight_ll*POGSF, 100, 0., 100);
    }
    
    for(auto iel : ElectronColl) {
      if(iel.PassID("HNL_ULID_Baseline")){
	
	map<TString, double> mapbdt = iel.MAPBDT();
	for(auto i : mapbdt){
	  if(SameCharge(ElectronColl))FillHist( channel_string+"_SS/"+i.first+"_"+channel_string  , i.second, weight_ll, 100, -1., 1., "MVA");
	  else FillHist( channel_string+"_OS/"+i.first+"_"+channel_string  , i.second, weight_ll, 100, -1., 1., "MVA");
	}
      }
    }
    

    std::vector<FatJet>   AK8_JetColl = GetHNLAK8Jets("", param);
    std::vector<Jet>      JetColl     = GetHNLJets("Tight", param);

    if(BJetColl.size() > 1) return;
    if(METv.Pt() > 30) return;
    if(!ZmassOSSFWindowCheck(LeptonColl, 10.)) return;

    FillAllElectronPlots("OSElectron","Z",ElectronColl,weight_ll);

    vector<Electron> ElectronCollDATATight;
    vector<Electron> ElectronCollDATAFake;
    for(auto iel : ElectronColl){
      if(iel.IsGsfCtfScPixChargeConsistent() && iel.SIP3D() < 3) ElectronCollDATATight.push_back(iel);
      if( iel.SIP3D() > 5) ElectronCollDATAFake.push_back(iel);
    }
    FillAllElectronPlots("OSElectron","ZTight",ElectronCollDATATight,weight_ll);
    FillAllElectronPlots("OSElectron","ZFake" ,ElectronCollDATAFake,weight_ll);

    
    std::vector<Electron>   ElectronCollV = GetElectrons(param.Electron_Veto_ID, 10., 2.5);
    std::vector<Muon>       MuonCollV     = GetMuons    (param.Muon_Veto_ID, 5., 2.4);
    
    
    std::vector<Tau> TauColl;

    Fill_RegionPlots(dilep_channel, 0, param.Name,"ZPeak" ,  TauColl, JetColl, AK8_JetColl, LeptonColl,  GetvMET("PuppiT1xyCorr"), nPV, weight_ll,param.WriteOutVerbose);
  }

  return;

}



HNL_LeptonIDBDTStudies::HNL_LeptonIDBDTStudies(){


}
 
HNL_LeptonIDBDTStudies::~HNL_LeptonIDBDTStudies(){

}

