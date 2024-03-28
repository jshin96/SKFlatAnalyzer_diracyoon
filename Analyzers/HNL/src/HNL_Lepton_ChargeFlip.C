#include "HNL_Lepton_ChargeFlip.h"

void HNL_Lepton_ChargeFlip::initializeAnalyzer(){

  HNL_LeptonCore::initializeAnalyzer();
  
  /// 5 MODES
  ///
  // HasFlag("MuonCF") 
  // HasFlag("ShiftEnergy")  ---> Step 1 measure Pt response of CF vs Prompt Electron to Get Pt/Eta dep shift  
  // HasFlag("ElCFRates")    ---> Measure rates in DY/Top MC (using Pt CF response)
  // HasFlag("ShiftEnergyZ") ---> Check mc closure  (Using only DY)
  // HasFlag("ScaleFactor")  ---> Compare Data SS vs OS weighted in BB / EC (using CF Rates) 
  
  //  cfEst->IgnoreNoHist = true;

  //  if(HasFlag("ShiftEnergy"))cfEst->IgnoreNoHist = true;
  
}

void HNL_Lepton_ChargeFlip::executeEvent(){
  
  
  vector<TString> LepIDs = {"HNL_ULID_"+GetYearString(),"HNTightV2", "POGTight"};
  vector<TString> CFMethods ={};

  if(HasFlag("ElCFRates") || HasFlag("ShiftEnergy")){
    CFMethods.push_back("");
  }
  else{
    CFMethods ={"CFRate_PtInv","CFRate_Pt"};
  }
  for (auto id: LepIDs){
    for (auto CFMethod : CFMethods){
      AnalyzerParameter param = InitialiseHNLParameter("SignalStudy");
      //GetElectronCFRate(param.Electron_Tight_ID, "CFRate_PtInv_EtaRegion_
      param.Name    =  id+CFMethod;
      param.DefName =  id+CFMethod;
      
      //// Do not include Xsec norm since looking to Add TT/DY samples in Eff
      param.Apply_Weight_LumiNorm = false;
      if(HasFlag("ScaleFactor"))param.Apply_Weight_LumiNorm = true;
      param.Apply_Weight_SumQ     = true;
      param.Apply_Weight_PileUp   = true;
      param.Apply_Weight_PreFire  = true;
      param.Apply_Weight_kFactor  = false;
      param.Apply_Weight_IDSF     = true;
      param.Apply_Weight_RECOSF     = true;
      param.Apply_Weight_TriggerSF= true;
      
      param.FakeMethod   = "DATA";
      param.CFMethod     = "DATA";
      param.ConvMethod   = "MC";
      
      param.Electron_Tight_ID = (id == "TopHN") ? "TopHNSST" :  id;
      param.Muon_Tight_ID     = (id == "TopHN") ? "TopHNT"   :  id;
      param.k.Electron_CF  = CFMethod+"_EtaRegion_"+id;
      if(id =="POGTight"){
	param.Muon_Tight_ID   =    "POGTightWithTightIso";
	param.Electron_Tight_ID  = "passPOGTight";
	param.k.Electron_CF  = CFMethod+"_EtaRegion_POGTight";
      }
      executeEventFromParameter(param);
    }
  }
}

// check if fitting is useless
/*
 execute under --userflag CFfitval
1. pick up some processes with large xsec (ttbar DY)
2. choose OS ee events
3-1. use CF rate fit function to estimate SS ee from OS ee events
3-2. use CF rate bin values to estimate SS ee from OS ee events

and compare 3-1 and 3-2

*/

void HNL_Lepton_ChargeFlip::executeEventFromParameter(AnalyzerParameter param){

  if(_jentry==0) param.PrintParameters();
  run_Debug = (_jentry%nLog==0);

  if(!PassMETFilter()) return;

 
  Event ev = GetEvent();

  double EvWeight =SetupWeight(ev,param);
  
  // Electrons 
  std::vector<Electron> ElectronColltmp;
  if(param.Electron_Tight_ID.Contains("HEEP")) ElectronColltmp = GetElectrons(param.Electron_Tight_ID,50.,2.5);
  else ElectronColltmp = GetElectrons(param.Electron_Tight_ID,15.,2.5);
  
  if(run_Debug) cout <<  "Number of All ID Electrons = " << ElectronColltmp.size() << endl;

  // Muons
  std::vector<Muon> MuonColl; std::vector<Muon> MuonCollVeto;
  if(param.Muon_Tight_ID.Contains("HEEP")) MuonColl = GetMuons(param.Muon_Tight_ID,25.,2.4);
  else MuonColl = GetMuons(param.Muon_Tight_ID,10.,2.4);
  MuonCollVeto = GetMuons(param.Muon_Veto_ID,10.,2.4);
  std::sort(MuonColl.begin(),MuonColl.end(),PtComparing);

  // Gen

  vector<Electron> ElectronCollPrompt = ElectronPromptOnly(ElectronColltmp,All_Gens,param);
  vector<Electron> ElectronColl;
  for(auto iel: ElectronCollPrompt){
    if(HasPromptConv(iel)) continue;
    if(iel.LeptonGenType() >= 4 ) continue;
    ElectronColl.push_back(iel);
  }



  vector<Muon> PromptMuonColl   = MuonPromptOnly(MuonColl,All_Gens,param);
  std::sort(ElectronColl.begin(),ElectronColl.end(),PtComparing);
  std::vector<Lepton *> Leptons = MakeLeptonPointerVector(PromptMuonColl,ElectronColl,param);

  if(run_Debug)cout <<  "Number of GEN MATCHED ID Electrons = "<< ElectronColl.size() << endl;


  // Jet
  vector<Jet> JetColl = GetJets(param.Jet_ID,10.,5.);
  vector<Jet> BJetColl;
  JetTagging::Parameters jtp;
  jtp = JetTagging::Parameters(JetTagging::DeepCSV, JetTagging::Medium, JetTagging::incl, JetTagging::comb);
  BJetColl = SelBJets(JetColl,jtp);



  if(!PassHEMVeto(Leptons)) return ;


  //// E shift from Z peak

  // BB 2017 0.075%
  // EC 2017 0.08%

  if(HasFlag("ElCFRates")){

    if(IsDATA) return;
    
    if(SameCharge(ElectronColl)){
      if(ElectronColl[0].LeptonIsCF() || ElectronColl[1].LeptonIsCF()){
	double el1CF = ElectronColl[0].HNL_MVA_CF("EDv5");
	double el2CF = ElectronColl[1].HNL_MVA_CF("EDv5");
	
	if(el1CF < el2CF) {
	  if(ElectronColl[0].LeptonIsCF())FillHist(param.Name+"/CFMVATEST/CheckTagger", 1, EvWeight,5, 0, 5);
	  else  FillHist(param.Name+"/CFMVATEST/CheckTagger", 2, EvWeight,5, 0, 5);
	}
	else{
	  if(ElectronColl[1].LeptonIsCF())FillHist(param.Name+"/CFMVATEST/CheckTagger", 1, EvWeight,5, 0, 5);
          else FillHist(param.Name+"/CFMVATEST/CheckTagger", 2, EvWeight,5, 0, 5);
	}
	
	double el1_cf_rate =   1.;//cfEst->GetElectronCFRate(param.Electron_Tight_ID, param.k.Electron_CF, ElectronColl[0].defEta(), ElectronColl[0].Pt(), 0);
	double el2_cf_rate =   1.;//cfEst->GetElectronCFRate(param.Electron_Tight_ID, param.k.Electron_CF, ElectronColl[1].defEta(), ElectronColl[1].Pt(), 0);

	if(el2_cf_rate < el1_cf_rate) {
          if(ElectronColl[0].LeptonIsCF())FillHist(param.Name+"/CFMVATEST/CheckRates", 1, EvWeight,5, 0, 5);
          else  FillHist(param.Name+"/CFMVATEST/CheckRates", 2, EvWeight,5, 0, 5);
        }
        else{
          if(ElectronColl[1].LeptonIsCF())FillHist(param.Name+"/CFMVATEST/CheckRates", 1, EvWeight,5, 0, 5);
          else FillHist(param.Name+"/CFMVATEST/CheckRates", 2, EvWeight,5, 0, 5);
        }
      }
    }


    int nbins_invpt(12);
    int nbin = 11;
    double invptbins [nbins_invpt+1] = { 0., 0.002,0.005, 0.0075,0.010,0.0125,0.015,0.020,0.0225,0.025, 0.030,0.035, 0.04};
    double ptbin     [12] = {25.,30.,35., 40.,45., 50.,65., 80.,  100., 150., 200.,500.};       
    double etabins   [11] = { 0.,0.8,1.2,  1.4442,1.556, 1.9, 2.1,2.2,2.3,2.4 , 2.5};
    double etabins2  [9] = { -2.5,-1.556,-1.444, -0.8, 0.,0.8, 1.4442,1.556,  2.5};

    double ipbins    [9]  = {0, 0.0025,0.005,0.0075,0.01,0.0125,0.015,0.02,0.1};
    double mvabins   [14] = { -1,-0.5,0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,0.95,1};

    for(unsigned int i=0 ; i < ElectronColl.size() ; i++){

      /// Remove Conv and Fakeelectrons
      if(ElectronColl.at(i).LeptonGenType() <= 0 || ElectronColl.at(i).LeptonGenType() >=4) continue;
      
      /////TruthIdx returns matched lepton status 1 index
      int TruthIdx  = GenMatchedIdx(ElectronColl.at(i), All_Gens);;
      if(TruthIdx < 0 || (TruthIdx > int(All_Gens.size()))) continue;

      ///// Get access to Matched status 1 gen el
      Gen truth_lep = All_Gens[TruthIdx];
      if(truth_lep.PID() ==0 ) continue;


      bool IsCF = ElectronColl.at(i).LeptonIsCF();
    
      /// CF Rate Method 2 WIth Int Conv                                                                                                                    
      
      if(HasPromptConv(ElectronColl.at(i))) continue;
      

      double PtShift = 1. / GetShiftCFEl(ElectronColl.at(i));

      if(HasFlag("RateNoShift")) PtShift = 1.;
      
      vector<TString> FillCFrates = {"Denom"};
      if(IsCF) FillCFrates.push_back("Num");
      vector<double> ShiftValue = {1., PtShift};

      int cfindex(-1);
      for(auto icf : FillCFrates){
	cfindex++;

	//// Pt Inclusive
	FillHist(param.Name+"/CFrateInv/" +icf, ElectronColl.at(i).InvPt(ShiftValue[cfindex]), EvWeight, nbins_invpt, invptbins,"#pT^{-1}");
	FillHist(param.Name+"/CFratePt/"  +icf, ElectronColl.at(i).PtMaxed(500)*ShiftValue[cfindex], EvWeight,nbin, ptbin,"pT");

	/// Pt EtaBinned
	TString EtaTag="";
	if(abs(ElectronColl.at(i).scEta())<0.8)  EtaTag="EtaRegion1_";
	else if(0.8<=abs(ElectronColl.at(i).scEta())&&abs(ElectronColl.at(i).scEta())<1.2)    EtaTag="EtaRegion2_";
	else if(1.2<=abs(ElectronColl.at(i).scEta())&&abs(ElectronColl.at(i).scEta())<1.4442) EtaTag="EtaRegion3_";
	else if(1.556<=abs(ElectronColl.at(i).scEta())&&abs(ElectronColl.at(i).scEta())<1.9)  EtaTag="EtaRegion4_";
        else if(1.9<=abs(ElectronColl.at(i).scEta())&&abs(ElectronColl.at(i).scEta())<2.1)    EtaTag="EtaRegion5_";
	else if(2.1<=abs(ElectronColl.at(i).scEta())&&abs(ElectronColl.at(i).scEta())<2.2)    EtaTag="EtaRegion6_";
        else if(2.2<=abs(ElectronColl.at(i).scEta())&&abs(ElectronColl.at(i).scEta())<2.3)    EtaTag="EtaRegion7_";
        else if(2.3<=abs(ElectronColl.at(i).scEta())&&abs(ElectronColl.at(i).scEta())<2.4)    EtaTag="EtaRegion8_";
        else if(2.4<=abs(ElectronColl.at(i).scEta())&&abs(ElectronColl.at(i).scEta())<2.5)    EtaTag="EtaRegion9_";
	else  EtaTag="EtaRegion10_";

	TString mEtaTag="";
        if(abs(ElectronColl.at(i).scEta())<0.8)  mEtaTag="mEtaRegion1_";
        else if(0.8<=abs(ElectronColl.at(i).scEta())&&abs(ElectronColl.at(i).scEta())<1.442)  mEtaTag="mEtaRegion2_";
	else if(1.556<=abs(ElectronColl.at(i).scEta())&&abs(ElectronColl.at(i).scEta())<2.5)    mEtaTag="mEtaRegion3_";
        else  mEtaTag="mEtaRegion4_";
	

        FillHist(param.Name+"/CFrate/absEta"  +icf, fabs(ElectronColl.at(i).scEta()),  EvWeight, 10,etabins ,"#eta");
        FillHist(param.Name+"/CFrate/Eta"  +icf, ElectronColl.at(i).scEta(),  EvWeight, 8,etabins2 ,"#eta");

	FillHist(param.Name+"/CFrateInvPt/"  +EtaTag  +icf, ElectronColl.at(i).InvPt(ShiftValue[cfindex]),      EvWeight, nbins_invpt, invptbins,"#pT^{-1}");
	FillHist(param.Name+"/CFratePt/"+EtaTag+icf, ElectronColl.at(i).PtMaxed(500)*ShiftValue[cfindex],       EvWeight, nbin,        ptbin,"pT");
	
	FillHist(param.Name+"/CFrateInvPt/"  +mEtaTag  +icf, ElectronColl.at(i).InvPt(ShiftValue[cfindex]),     EvWeight, nbins_invpt, invptbins,"#pT^{-1}");
        FillHist(param.Name+"/CFratePt/"+mEtaTag+icf,   ElectronColl.at(i).PtMaxed(500)*ShiftValue[cfindex],    EvWeight, nbin,        ptbin,"pT");


	if(fabs(ElectronColl.at(i).dXY())< 0.004) {
	  FillHist(param.Name+"/CFrate/IP1_"+EtaTag  +icf, ElectronColl.at(i).InvPt(ShiftValue[cfindex]),       EvWeight, nbins_invpt, invptbins,"#pT^{-1}");
	  FillHist(param.Name+"/CFratePt/IP1_"+EtaTag+icf, ElectronColl.at(i).PtMaxed(500)*ShiftValue[cfindex], EvWeight, nbin,        ptbin,"pT");
	}
	else if(fabs(ElectronColl.at(i).dXY())< 0.01) {
          FillHist(param.Name+"/CFrate/IP2_"+EtaTag  +icf, ElectronColl.at(i).InvPt(ShiftValue[cfindex]),       EvWeight, nbins_invpt, invptbins,"#pT^{-1}");
          FillHist(param.Name+"/CFratePt/IP2_"+EtaTag+icf, ElectronColl.at(i).PtMaxed(500)*ShiftValue[cfindex], EvWeight, nbin,        ptbin,"pT");
	}
	else{
	  FillHist(param.Name+"/CFrate/IP3_"+EtaTag  +icf, ElectronColl.at(i).InvPt(ShiftValue[cfindex]),      EvWeight, nbins_invpt, invptbins,"#pT^{-1}");
          FillHist(param.Name+"/CFratePt/IP3_"+EtaTag+icf, ElectronColl.at(i).PtMaxed(500)*ShiftValue[cfindex], EvWeight, nbin,        ptbin,"pT");
	}

	if(ElectronColl.at(i).HNL_MVA_CF("EDv5") < 0.8){
	  FillHist(param.Name+"/CFrate/MVA1_"+EtaTag  +icf, ElectronColl.at(i).InvPt(ShiftValue[cfindex]),      EvWeight, nbins_invpt, invptbins,"#pT^{-1}");
          FillHist(param.Name+"/CFratePt/MVA1_"+EtaTag+icf, ElectronColl.at(i).PtMaxed(500)*ShiftValue[cfindex], EvWeight, nbin,        ptbin,"pT");
	}
	else if(ElectronColl.at(i).HNL_MVA_CF("EDv5") < 0.9){
          FillHist(param.Name+"/CFrate/MVA2_"+EtaTag  +icf, ElectronColl.at(i).InvPt(ShiftValue[cfindex]),      EvWeight, nbins_invpt, invptbins,"#pT^{-1}");
          FillHist(param.Name+"/CFratePt/MVA2_"+EtaTag+icf, ElectronColl.at(i).PtMaxed(500)*ShiftValue[cfindex], EvWeight, nbin,        ptbin,"pT");
	}

	else if(ElectronColl.at(i).HNL_MVA_CF("EDv5") < 0.95){
          FillHist(param.Name+"/CFrate/MVA3_"+EtaTag  +icf, ElectronColl.at(i).InvPt(ShiftValue[cfindex]),      EvWeight, nbins_invpt, invptbins,"#pT^{-1}");
          FillHist(param.Name+"/CFratePt/MVA3_"+EtaTag+icf, ElectronColl.at(i).PtMaxed(500)*ShiftValue[cfindex], EvWeight, nbin,        ptbin,"pT");
	}
	else {
          FillHist(param.Name+"/CFrate/MVA4_"+EtaTag  +icf, ElectronColl.at(i).InvPt(ShiftValue[cfindex]),      EvWeight, nbins_invpt, invptbins,"#pT^{-1}");
          FillHist(param.Name+"/CFratePt/MVA4_"+EtaTag+icf, ElectronColl.at(i).PtMaxed(500)*ShiftValue[cfindex], EvWeight, nbin,        ptbin,"pT");
	}

	FillHist(param.Name+"/CFrate_Eta/"+icf, ElectronColl.at(i).scEta(), EvWeight, 50, -2.5, 2.5,"scEta");
	FillHist(param.Name+"/CFrate_IP/"+icf,  fabs(ElectronColl.at(i).dXY()),   EvWeight, 200, 0., 0.1,"dXY");
	FillHist(param.Name+"/CFrate_MVA/"+icf, ElectronColl.at(i).HNL_MVA_CF("EDv5"), EvWeight, 200, -1, 1,"CF MVA");
	
	if(ElectronColl.at(i).scEta() > 0){
	  FillHist(param.Name+"/CFrate_pEta/"+icf, abs(ElectronColl.at(i).scEta()), EvWeight, 50,0, 2.5,"scEta");
	  FillHist(param.Name+"/CFratePt_pEta/"+icf,ElectronColl.at(i).PtMaxed(500)*ShiftValue[cfindex], EvWeight,nbin, ptbin,"pT");
	}
	else {
	  FillHist(param.Name+"/CFrate_mEta/"+icf, abs(ElectronColl.at(i).scEta()), EvWeight, 50,0, 2.5,"scEta");
	  FillHist(param.Name+"/CFratePt_mEta/"+icf,ElectronColl.at(i).PtMaxed(500)*ShiftValue[cfindex], EvWeight,nbin, ptbin,"pT");
	}

	//// 2 D 
	FillHist(param.Name+"/CFrate_2DIP/"+icf, ElectronColl.at(i).PtMaxed(500)*ShiftValue[cfindex], fabs(ElectronColl.at(i).dXY()), EvWeight, nbin, ptbin, 8,ipbins);
	FillHist(param.Name+"/CFrate_2DMVA/"+icf,ElectronColl.at(i).PtMaxed(500)*ShiftValue[cfindex], ElectronColl.at(i).HNL_MVA_CF("EDv5"), EvWeight, nbin, ptbin, 13,mvabins);
	FillHist(param.Name+"/CFrate_2DPt/"+icf,ElectronColl.at(i).PtMaxed(500)*ShiftValue[cfindex], ElectronColl.at(i).scEta(), EvWeight, nbin, ptbin, 10,etabins);
	
	if(ElectronColl.at(i).Pt() < 50)FillHist(param.Name+"/CFrate_Eta_Ptlt50/"+icf, ElectronColl.at(i).scEta(), EvWeight, 50, -2.5, 2.5,"scEta");
	else  FillHist(param.Name+"/CFrate_Eta_Ptgt50/"+icf, ElectronColl.at(i).scEta(), EvWeight, 50, -2.5, 2.5,"scEta");

      }
    }
    return;
  }
  
  if(HasFlag("ShiftCFStudy")){

    for(auto iel : ElectronColl){
      Gen MatchedGen = GetGenMatchedLepton(iel, All_Gens);
      
      if(iel.LeptonIsCF()) {

	FillHist(param.Name+"/CFStudy/CF_El_Eta", iel.scEta() /MatchedGen.Eta() , EvWeight ,100, 0 , 5);
	FillHist(param.Name+"/CFStudy/CF_El_Phi", iel.Phi() /MatchedGen.Phi() , EvWeight ,100, 0 , 5);
        FillHist(param.Name+"/CFStudy/CF_El_E",   iel.E() /MatchedGen.E() , EvWeight ,100, 0 , 5);
        FillHist(param.Name+"/CFStudy/CF_El_Pt",  iel.Pt() /MatchedGen.Pt() , EvWeight ,100, 0 , 5);
      }
      else{
	FillHist(param.Name+"/CFStudy/Prompt_El_Eta", iel.scEta() /MatchedGen.Eta() , EvWeight ,100, 0 , 5);
        FillHist(param.Name+"/CFStudy/Prompt_El_Phi", iel.Phi() /MatchedGen.Phi() , EvWeight ,100, 0 , 5);
        FillHist(param.Name+"/CFStudy/Prompt_El_E",   iel.E() /MatchedGen.E() , EvWeight ,100, 0 , 5);
        FillHist(param.Name+"/CFStudy/Prompt_El_Pt",  iel.Pt() /MatchedGen.Pt() , EvWeight ,100, 0 , 5);
      }
    }   
    
    return;
  }


  
  if(HasFlag("ShiftEnergyZ")){
    
    int nbinNeg= 17;

    double pTbinNeg[nbinNeg+1] = {-200,-100,-80,-50,-45,-40,-35,-30,-15, 15.,30.,35,40.,45, 50., 80.,100.,200.};
    double ptbin     [13]      = {0.,20.,30.,35., 40.,45., 50.,65., 80.,  100., 150., 200.,500.};
    double etabins   [11]      = {0.,0.8,1.2,  1.4442,1.556, 1.9, 2.1,2.2,2.3,2.4 , 2.5};
    double ipbins    [9]  = {0, 0.0025,0.005,0.0075,0.01,0.0125,0.015,0.02,0.1};
    double mvabins   [14] = { -1,-0.5,0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,0.95,1};


    if(run_Debug) cout << "ShiftEnergyZ processing " << endl;

    for(auto iel : ElectronColl){
      /// Remove Conv and Fakeelectrons                                                                                                                                                                                              
      if(iel.LeptonGenType() <= 0 || iel.LeptonGenType() >=4) continue;

      /////TruthIdx returns matched lepton status 1 index                                                                                                                                                                            
      int TruthIdx  = GenMatchedIdx(iel, All_Gens);;
      if(TruthIdx < 0 || (TruthIdx > int(All_Gens.size()))) continue;

      ///// Get access to Matched status 1 gen el                                                                                                                                                                                    
      Gen truth_lep = All_Gens[TruthIdx];
      if(truth_lep.PID() ==0 ) continue;


      bool IsCF = iel.LeptonIsCF();
      
      if(HasPromptConv(iel)) continue;
      
      double PtShift = GetShiftCFEl(iel);
      
      TString CFKey = param.Electron_Tight_ID;
      if(CFKey =="passPOGTight") CFKey="POGTight";

      double rate_cf_eta       = cfEst->GetElectronCFRate(param.Electron_Tight_ID, "CFRate_PtInv_EtaRegion_" +CFKey,iel.defEta(), iel.Pt(), 0); 
      double rate_cf_meta      = cfEst->GetElectronCFRate(param.Electron_Tight_ID, "CFRate_PtInv_MergedEtaRegion_" +CFKey,iel.defEta(), iel.Pt(), 0);                                                            
      double rate_cf_inv_eta   = cfEst->GetElectronCFRate(param.Electron_Tight_ID, "CFRate_Pt_EtaRegion_" +CFKey,iel.defEta(), iel.Pt(), 0);
      double rate_cf_inv_meta  = cfEst->GetElectronCFRate(param.Electron_Tight_ID, "CFRate_Pt_MergedEtaRegion_" +CFKey,iel.defEta(), iel.Pt(), 0);                                                          

      if(IsCF){
	FillHist(param.Name+"/Closure/CF_LepPt",   iel.PtMaxed(500) ,       EvWeight        , 12, ptbin,"pT");
	FillHist(param.Name+"/Closure/CF_LepEta",  fabs(iel.scEta()) ,       EvWeight        , 50,0, 2.5);
	if(iel.PtMaxed(500) < 40) FillHist(param.Name+"/Closure/CF_LepEta1",  fabs(iel.scEta()) ,       EvWeight        , 50,0, 2.5);
	else  if(iel.PtMaxed(500) < 100) FillHist(param.Name+"/Closure/CF_LepEta2",  fabs(iel.scEta()) ,       EvWeight        , 50,0, 2.5);
	else  if(iel.PtMaxed(500) < 500) FillHist(param.Name+"/Closure/CF_LepEta3",  fabs(iel.scEta()) ,       EvWeight        , 50,0, 2.5);

	FillHist(param.Name+"/Closure/CF_LepIP",fabs(iel.dXY()), EvWeight, 8,ipbins);
        FillHist(param.Name+"/Closure/CF_LepMVA", iel.HNL_MVA_CF("EDv5"), EvWeight, 13,mvabins);

      }
      else {
	vector<TString> WeightS = {"_W1","_W2","_W3","_W4"};
	vector<double> WeightD = {rate_cf_eta,rate_cf_meta,rate_cf_inv_eta,rate_cf_inv_meta};
	for(unsigned int iw = 0 ; iw < 4; iw++){
	  FillHist(param.Name+"/Closure/NonCF_LepPt"+WeightS[iw],  iel.PtMaxed(500)*PtShift ,  WeightD[iw]*EvWeight , 12, ptbin,"pT");
	  FillHist(param.Name+"/Closure/NonCF_LepEta"+WeightS[iw],  fabs(iel.scEta()) ,       WeightD[iw]*EvWeight        , 50,0, 2.5);

	  if(iel.PtMaxed(500) < 40) FillHist(param.Name+"/Closure/NonCF_LepEta1"+WeightS[iw],  fabs(iel.scEta()) ,       WeightD[iw]*EvWeight        , 50,0, 2.5);

	  else  if(iel.PtMaxed(500) < 100) FillHist(param.Name+"/Closure/NonCF_LepEta2"+WeightS[iw],  fabs(iel.scEta()) ,       WeightD[iw]*EvWeight        , 50,0, 2.5);

	  else  if(iel.PtMaxed(500) < 500) FillHist(param.Name+"/Closure/NonCF_LepEta3"+WeightS[iw],  fabs(iel.scEta()) ,       WeightD[iw]*EvWeight        , 50,0, 2.5);



	  FillHist(param.Name+"/Closure/NonCF_LepIP"+WeightS[iw],fabs(iel.dXY()), WeightD[iw]*EvWeight, 8,ipbins);
	  FillHist(param.Name+"/Closure/NonCF_LepMVA"+WeightS[iw], iel.HNL_MVA_CF("EDv5"), WeightD[iw]*EvWeight, 13,mvabins);

	}
      }

    }


    if(ElectronColl.size() != 2) return;

    //// Select SS events in MC that are 1 Prompt + 1 CF
    if(SameCharge(ElectronColl)){
      if(ElectronColl.at(0).IsPrompt() && ElectronColl.at(1).IsPrompt() && (ElectronColl.at(0).LeptonIsCF() || ElectronColl.at(1).LeptonIsCF())){

	/// Remove rare converstions  where e->eee share SC using HasPromptConv
	if(!HasPromptConv(ElectronColl.at(0)) && !HasPromptConv(ElectronColl.at(1))) {
	  
	  // To be safe remove LeptonGenType() > 4 which are conversions
	  if(ElectronColl.at(0).LeptonGenType() < 4 &&  ElectronColl.at(1).LeptonGenType() <4) {
	    
	    // Construct LL candidate
	    Particle ZCand = ElectronColl.at(0)+ElectronColl.at(1);
	    double Zmass = ZCand.M(); 
	    if(Zmass < 70) Zmass=70;
	    if(Zmass > 130) Zmass=130;

	    if(ElectronColl[0].IsBB() && ElectronColl[1].IsBB())  FillHist(param.Name+"/ZMass/SS_BB", Zmass , EvWeight ,60 , 70, 130);
	    if(ElectronColl[0].IsEC() && ElectronColl[1].IsEC())  FillHist(param.Name+"/ZMass/SS_EC", Zmass , EvWeight ,60 , 70, 130);
	    if(ElectronColl[0].IsBB() && ElectronColl[1].IsBB()) {
	      FillHist(param.Name+"/Z/SS_BB_LepPt",  ElectronColl[0].PtMaxed(200) ,         EvWeight , nbinNeg, pTbinNeg,"pT");
	      FillHist(param.Name+"/Z/SS_BB_LepPt", -1*ElectronColl[1].PtMaxed(200) ,      EvWeight , nbinNeg, pTbinNeg,"pT");
	      FillHist(param.Name+"/Z/SS_BB_LepEta",  (ElectronColl[0].scEta()+2.5) , EvWeight, 100., -5., 5., "Eta");
	      FillHist(param.Name+"/Z/SS_BB_LepEta",  -1*(ElectronColl[1].scEta()+2.5) , EvWeight, 100., -5., 5., "Eta");

	    }
	    
	    if(ElectronColl[0].IsEC() && ElectronColl[1].IsEC()) {
              FillHist(param.Name+"/Z/SS_EC_LepPt", ElectronColl[0].PtMaxed(200) ,         EvWeight , nbinNeg, pTbinNeg,"pT");
              FillHist(param.Name+"/Z/SS_EC_LepPt", -1*ElectronColl[1].PtMaxed(200) ,      EvWeight , nbinNeg, pTbinNeg,"pT");
	      FillHist(param.Name+"/Z/SS_EC_LepEta",  (ElectronColl[0].scEta()+2.5) , EvWeight, 100., -5., 5., "Eta");
	      FillHist(param.Name+"/Z/SS_EC_LepEta",  -1*(ElectronColl[1].scEta()+2.5) , EvWeight, 100., -5., 5., "Eta");

	    } // EC
	  } /// Non Conv
	} 
      } //// END OF Prompt + CF
    }
    else {

      //// Now plot OS * CF rate [Energy Shifted] to compare
      if(ElectronColl.at(0).IsPrompt() && !ElectronColl.at(0).LeptonIsCF()  && ElectronColl.at(1).IsPrompt() && !ElectronColl.at(0).LeptonIsCF() ){

	if(HasPromptConv(ElectronColl.at(0))  || HasPromptConv(ElectronColl.at(1))) return;
	if(ElectronColl.at(0).LeptonGenType() >= 4 || ElectronColl.at(1).LeptonGenType() >=4) return;
	

	//// Loop several Energy shift
	for (unsigned int ishift = 0 ; ishift < 4; ishift++){
	  

	  TString ShiftVersion = "Default";
	  if(ishift==1) ShiftVersion = "MVATag";
	  if(ishift==2) ShiftVersion = "Split";
	  if(ishift==3) ShiftVersion = "Split";

	  vector<Electron> ShiftedEl;
          Electron this_el1 = ElectronColl.at(0);
          Electron this_el2 = ElectronColl.at(1);

	  Particle ZCand = this_el1+this_el2;
          double Zmass = ZCand.M();

	  double shiftEl1 = GetShiftCFEl(this_el1);
	  double shiftEl2 = GetShiftCFEl(this_el2);
	  TString shift_string = "SingleElShift";

	  Electron this_el_CF;
	  
	  if(ishift==0) {
	    this_el1*= shiftEl1;
            this_el2*= shiftEl2;
          }

	  else  if(ishift==1) {
	    if(this_el1.HNL_MVA_CF("EDv5") < this_el2.HNL_MVA_CF("EDv5")) {
	      this_el1*= shiftEl1;
	      this_el_CF = this_el1;
	    }
	    else {
	      this_el2*= shiftEl2;
	      this_el_CF = this_el2;
	    }
	  }

	  else if(ishift==2)  this_el1*= shiftEl1;
	  else this_el2*= shiftEl2;


	  Particle ZShiftedCand = this_el1+this_el2;
	  double ZShiftedmass = ZShiftedCand.M();
	  if(ZShiftedmass < 70) ZShiftedmass=70;
	  if(ZShiftedmass > 130) ZShiftedmass=130;

	  if(Zmass < 70) Zmass = 70;
	  if(Zmass > 130) Zmass = 130;


          if(ElectronColl[0].IsBB() && ElectronColl[1].IsBB())FillHist(param.Name+"/"+ShiftVersion+"/ZMass/OS_BB_EnergyShift_"+shift_string, ZShiftedmass , EvWeight ,60 , 70, 130);
          if(ElectronColl[0].IsEC() && ElectronColl[1].IsEC())FillHist(param.Name+"/"+ShiftVersion+"/ZMass/OS_EC_EnergyShift_"+shift_string, ZShiftedmass , EvWeight ,60 , 70, 130);

	  /// Non shifted
          if(ElectronColl[0].IsBB() && ElectronColl[1].IsBB())FillHist(param.Name+"/"+ShiftVersion+"/ZMass/OS_BB_"+shift_string, Zmass , EvWeight ,60 , 70, 130);
          if(ElectronColl[0].IsEC() && ElectronColl[1].IsEC())FillHist(param.Name+"/"+ShiftVersion+"/ZMass/OS_EC_"+shift_string, Zmass , EvWeight ,60 , 70, 130);
	  
	  
	  
	  if(fabs(ElectronColl[0].dXY()) < 0.005 || fabs(ElectronColl[1].dXY()) < 0.005) {
	    if(ElectronColl[0].IsBB() && ElectronColl[1].IsBB())FillHist(param.Name+"/"+ShiftVersion+"/ZMass/OS_IP1_BB_"+shift_string, Zmass , EvWeight ,60 , 70, 130);
	    if(ElectronColl[0].IsEC() && ElectronColl[1].IsEC())FillHist(param.Name+"/"+ShiftVersion+"/ZMass/OS_IP1_EC_"+shift_string, Zmass , EvWeight ,60 , 70, 130);
	  }
	  else  if(fabs(ElectronColl[0].dXY()) < 0.01 || fabs(ElectronColl[1].dXY()) < 0.01) {
            if(ElectronColl[0].IsBB() && ElectronColl[1].IsBB())FillHist(param.Name+"/"+ShiftVersion+"/ZMass/OS_IP2_BB_"+shift_string, Zmass , EvWeight ,60 , 70, 130);
            if(ElectronColl[0].IsEC() && ElectronColl[1].IsEC())FillHist(param.Name+"/"+ShiftVersion+"/ZMass/OS_IP2_EC_"+shift_string, Zmass , EvWeight ,60 , 70, 130);
          }
	  else {
	    if(ElectronColl[0].IsBB() && ElectronColl[1].IsBB())FillHist(param.Name+"/"+ShiftVersion+"/ZMass/OS_IP3_BB_"+shift_string, Zmass , EvWeight ,60 , 70, 130);
            if(ElectronColl[0].IsEC() && ElectronColl[1].IsEC())FillHist(param.Name+"/"+ShiftVersion+"/ZMass/OS_IP3_EC_"+shift_string, Zmass , EvWeight ,60 , 70, 130);
	  }

	  ShiftedEl.clear();
	  ShiftedEl.push_back(this_el1);
	  ShiftedEl.push_back(this_el2);

	  TString CFKey = param.Electron_Tight_ID;
	  if(CFKey =="passPOGTight")CFKey="POGTight";
	  double weight_shifted = 1;

	  if(ishift==0) {
            this_el1*= shiftEl1;
            this_el2*= shiftEl2;

	    double CFRate1   = cfEst->GetElectronCFRate(param.Electron_Tight_ID, "CFRate_PtInv_EtaRegion_" +CFKey,this_el1.defEta(), this_el1.Pt(), 0);
	    double CFRate2   = cfEst->GetElectronCFRate(param.Electron_Tight_ID, "CFRate_PtInv_EtaRegion_" +CFKey,this_el2.defEta(), this_el2.Pt(), 0);
	    
	    weight_shifted = (CFRate1/(1-CFRate1)) + (CFRate2/(1-CFRate2));
          }

          else  if(ishift==1) {
            if(this_el1.HNL_MVA_CF("EDv5") < this_el2.HNL_MVA_CF("EDv5")) {
              this_el1*= shiftEl1;
              this_el_CF = this_el1;
	      double CFRate1   = cfEst->GetElectronCFRate(param.Electron_Tight_ID, "CFRate_PtInv_EtaRegion_" +CFKey,this_el1.defEta(), this_el1.Pt(), 0);
	      weight_shifted = (CFRate1/(1-CFRate1));
            }
            else {
              this_el2*= shiftEl2;
              this_el_CF = this_el2;
	      double CFRate2   = cfEst->GetElectronCFRate(param.Electron_Tight_ID, "CFRate_PtInv_EtaRegion_" +CFKey,this_el2.defEta(), this_el2.Pt(), 0);
	      weight_shifted = (CFRate2/(1-CFRate2));
            }
          }

          else if(ishift==2)  {
	    this_el1*= shiftEl1;
	    double CFRate1   = cfEst->GetElectronCFRate(param.Electron_Tight_ID, "CFRate_PtInv_EtaRegion_" +CFKey,this_el1.defEta(), this_el1.Pt(), 0);
	    weight_shifted = (CFRate1/(1-CFRate1));
	  }
          else {
	    this_el2*= shiftEl2;
	    double CFRate2   = cfEst->GetElectronCFRate(param.Electron_Tight_ID, "CFRate_PtInv_EtaRegion_" +CFKey,this_el2.defEta(), this_el2.Pt(), 0);
	    weight_shifted = (CFRate2/(1-CFRate2));

	  }


          if(ElectronColl[0].IsBB() && ElectronColl[1].IsBB()){
	    FillHist(param.Name+"/"+ShiftVersion+"/ZMass/OS_BB_Weighted_EnergyShift_"+shift_string,  ZShiftedmass             , weight_shifted*EvWeight ,60 , 70, 130);
            FillHist(param.Name+"/"+ShiftVersion+"/ZMass/OS_BB_Weighted_"+shift_string,  Zmass                                , weight_shifted*EvWeight ,60 , 70, 130);

	    FillHist(param.Name+"/"+ShiftVersion+"/Z/OS_BB_Weighted_EnergyShift_Pt_"+shift_string,   this_el1.PtMaxed(200)    , weight_shifted*EvWeight , nbinNeg, pTbinNeg,"pT");
	    FillHist(param.Name+"/"+ShiftVersion+"/Z/OS_BB_Weighted_EnergyShift_Pt_"+shift_string,   -1*this_el2.PtMaxed(200) , weight_shifted*EvWeight , nbinNeg, pTbinNeg,"pT");
            FillHist(param.Name+"/"+ShiftVersion+"/Z/OS_BB_Weighted_EnergyShift_Eta_"+shift_string,  (this_el1.scEta()+2.5)     , weight_shifted*EvWeight ,100., -5, 5, "Eta");
            FillHist(param.Name+"/"+ShiftVersion+"/Z/OS_BB_Weighted_EnergyShift_Eta_"+shift_string,  -1*(this_el2.scEta()+2.5)  , weight_shifted*EvWeight ,100., -5, 5, "Eta");

            FillHist(param.Name+"/"+ShiftVersion+"/Z/OS_BB_Weighted_EnergyShift_IP_"+shift_string,  fabs(this_el1.dXY()) ,     weight_shifted*EvWeight , 8,ipbins);
            FillHist(param.Name+"/"+ShiftVersion+"/Z/OS_BB_Weighted_EnergyShift_IP_"+shift_string,   -1*fabs(this_el2.dXY()) , weight_shifted*EvWeight , 8,ipbins);
	    FillHist(param.Name+"/"+ShiftVersion+"/Z/OS_BB_Weighted_EnergyShift_MVA_"+shift_string,  this_el1.HNL_MVA_CF("EDv5"), weight_shifted*EvWeight, 13,mvabins);   
	    FillHist(param.Name+"/"+ShiftVersion+"/Z/OS_BB_Weighted_EnergyShift_MVA_"+shift_string,  this_el2.HNL_MVA_CF("EDv5"), weight_shifted*EvWeight, 13,mvabins);   
	    
	  }
          if(ElectronColl[0].IsEC() && ElectronColl[1].IsEC()){
	    FillHist(param.Name+"/"+ShiftVersion+"/ZMass/OS_EC_Weighted_EnergyShift_"+shift_string, ZShiftedmass            , weight_shifted*EvWeight ,60 , 70, 130);
            FillHist(param.Name+"/"+ShiftVersion+"/ZMass/OS_EC_Weighted_"+shift_string,  Zmass                                , weight_shifted*EvWeight ,60 , 70, 130);

            FillHist(param.Name+"/"+ShiftVersion+"/Z/OS_EC_Weighted_EnergyShift_Pt_"+shift_string,  this_el1.PtMaxed(200)   , weight_shifted*EvWeight , nbinNeg, pTbinNeg,"pT");
            FillHist(param.Name+"/"+ShiftVersion+"/Z/OS_EC_Weighted_EnergyShift_Pt_"+shift_string, -1*this_el2.PtMaxed(200) , weight_shifted*EvWeight , nbinNeg, pTbinNeg,"pT");
            FillHist(param.Name+"/"+ShiftVersion+"/Z/OS_EC_Weighted_EnergyShift_Eta_"+shift_string, (this_el1.scEta()+2.5)    , weight_shifted*EvWeight ,100., -5, 5, "Eta");
            FillHist(param.Name+"/"+ShiftVersion+"/Z/OS_EC_Weighted_EnergyShift_Eta_"+shift_string, -1*(this_el2.scEta()+2.5) , weight_shifted*EvWeight ,100., -5, 5, "Eta");

            FillHist(param.Name+"/"+ShiftVersion+"/Z/OS_EC_Weighted_EnergyShift_IP_"+shift_string,  fabs(this_el1.dXY()) ,     weight_shifted*EvWeight , 8,ipbins);
            FillHist(param.Name+"/"+ShiftVersion+"/Z/OS_EC_Weighted_EnergyShift_IP_"+shift_string,   -1*fabs(this_el2.dXY()) , weight_shifted*EvWeight , 8,ipbins);
            FillHist(param.Name+"/"+ShiftVersion+"/Z/OS_EC_Weighted_EnergyShift_MVA_"+shift_string,  this_el1.HNL_MVA_CF("EDv5"), weight_shifted*EvWeight, 13,mvabins);
            FillHist(param.Name+"/"+ShiftVersion+"/Z/OS_EC_Weighted_EnergyShift_MVA_"+shift_string,  this_el2.HNL_MVA_CF("EDv5"), weight_shifted*EvWeight, 13,mvabins);

	  }
	}

      }
    }/// END OS
    return;
  }


  if(HasFlag("ShiftEnergy")){

    int nbinPt                = 9;
    double pTbin[nbinPt+1] = {0, 15.,30.,35,40.,45, 50., 80.,100.,200.};

    
    for(auto iel : ElectronColl){

      
      /// Remove Conv and Fakeelectrons
      if(iel.LeptonGenType() <= 0 || iel.LeptonGenType() >=4) continue;

      /////TruthIdx returns matched lepton status 1 index
      int TruthIdx  = GenMatchedIdx(iel, All_Gens);;
      if(TruthIdx < 0 || (TruthIdx > int(All_Gens.size()))) continue;

      ///// Get access to Matched status 1 gen el
      Gen truth_lep = All_Gens[TruthIdx];
      if(truth_lep.PID() ==0 ) continue;

      //int LastSelfIdx    = LastAbsSelfMotherIdx(TruthIdx,All_Gens);
      
      ///// Get sum of status 1 photon and electrons in dR < 0.1 to matched el 
      double PtSum = 0;
      Particle X = truth_lep;
      vector<Gen> MatchedStatus1;
      int nSt1el(0);
      for(unsigned int i=2; i < All_Gens.size(); i++){
	if(TruthIdx == int(i)) continue;
	if(fabs(All_Gens.at(TruthIdx).Eta()-All_Gens.at(i).Eta())>0.1) continue;
	if(All_Gens.at(TruthIdx).DeltaPhi(All_Gens.at(i))>0.3) continue;
	if(All_Gens[TruthIdx].MotherIndex() == All_Gens[i].MotherIndex()){
	  if(All_Gens[i].Status() == 1) {
	    MatchedStatus1.push_back(All_Gens[i]);
	    PtSum+= All_Gens[i].Pt() ;
	    X=X+All_Gens[i];
	    if(fabs(All_Gens[i].PID()) == 11) nSt1el++;
	  }
	}
      }

      /// if nSt1el (number of status 1 electrons in dR < 0.4 from same mother , if > 1 e->eee  that passes JH Gen code
      bool bIsConv  =  HasPromptConv(iel);
      
      /// LeptonIsCF() == IsCF(iel, All_Gens, true);
      bool bIsCF     =  iel.LeptonIsCF() ;// IsCF(iel, All_Gens, true);
      
      double gen_d_pt = ( (truth_lep.Pt()+PtSum) > 500) ? 500 : truth_lep.Pt() + PtSum;
      double gen_d_eta = X.Eta();
      double gen_d_phi = X.Phi();

      /// PtResponse measures how RECO pt compares to GEN pt
      double PtResponse  = (iel.Pt()  -  gen_d_pt) / gen_d_pt;
      double EtaResponse  = (iel.Eta()  -  gen_d_eta) / gen_d_eta;
      double PhiResponse  = (iel.Phi()  -  gen_d_phi) / gen_d_phi;
      

      TString EtaBin = iel.etaRegionString();//(iel.IsBB()) ? "BB" : "EC";
      
      //double rate_cf= cfEst->GetElectronCFRate(param.Electron_Tight_ID, param.Electron_CF_Key, iel.defEta(), iel.Pt(), 0);
      
      if(bIsConv) continue;
      
      if(iel.IsPrompt() && !bIsCF){
	FillHist(param.Name+"/EnergyShift/"+EtaBin+"_Pt_Prompt", PtResponse ,   EvWeight , 200, -1,1);
	FillHist(param.Name+"/EnergyShift/"+EtaBin+"_Eta_Prompt", EtaResponse , EvWeight , 200, -0.1,0.1);
	FillHist(param.Name+"/EnergyShift/"+EtaBin+"_Phi_Prompt", PhiResponse , EvWeight , 200,  -0.1,0.1);

      }
      if(iel.IsPrompt() &&  bIsCF){
	FillHist(param.Name+"/EnergyShift/"+EtaBin+"_Pt_CF", PtResponse , EvWeight , 200, -1,1);
        FillHist(param.Name+"/EnergyShift/"+EtaBin+"_Eta_CF", EtaResponse , EvWeight , 200, -0.1,0.1);
	FillHist(param.Name+"/EnergyShift/"+EtaBin+"_Phi_CF", PhiResponse , EvWeight , 200,  -0.1,0.1);
      }

      TString PtBinLabel =  "";
      if(iel.IsEC()){
	if(gen_d_pt < 30)       PtBinLabel = "_Pt1";
	else  if(gen_d_pt < 50) PtBinLabel = "_Pt2";
	else  if(gen_d_pt < 75) PtBinLabel = "_Pt3";
	else  if(gen_d_pt < 100)PtBinLabel = "_Pt4";
	else PtBinLabel = "_Pt5";
      }
      else{
	if(gen_d_pt< 50)   PtBinLabel = "_Pt1";
        else  if(gen_d_pt < 100)PtBinLabel = "_Pt2";
        else PtBinLabel = "_Pt3";

      }
      if(iel.IsPrompt() &&  bIsCF) FillHist(param.Name+"/EnergyShift/"+EtaBin+PtBinLabel+"_CF", PtResponse , EvWeight , 200, -1,1);
      if(iel.IsPrompt() &&  bIsCF) FillHist(param.Name+"/EnergyShift/"+EtaBin+"_CF", PtResponse , EvWeight , 200, -1,1);

      for (unsigned int ishift = 0 ; ishift < 150; ishift++){
	double shiftEl = 1.05 - double(ishift)*0.001;
	TString shift_string = DoubleToString(shiftEl);
	double PtResponseShift = (shiftEl*iel.Pt() - gen_d_pt) / (gen_d_pt);
	if(iel.IsPrompt() &&  !bIsCF) {

	  FillHist(param.Name+"/EnergyShift/"+EtaBin+PtBinLabel+"_PromptShifted_"+shift_string, PtResponseShift , EvWeight , 200, -1,1);
	  FillHist(param.Name+"/EnergyShift/"+EtaBin+"_PromptShifted_"+shift_string, PtResponseShift , EvWeight , 200, -1,1);
	}
      }
    }
    
    return;
  }

  
  if(HasFlag("ScaleFactor")){

    int nbinNeg                = 17;
    double pTbinNeg[nbinNeg+1] = {-200,-100,-80,-50,-45,-40,-35,-30,-15, 15.,30.,35,40.,45, 50., 80.,100.,200.};

    if (!PassTriggerSelection(EE, ev,   Leptons,"Dilep")) return ;

    if(ElectronColl.size() != 2) return;
    
    Particle ZCand  = ElectronColl.at(0)+ElectronColl.at(1);
    double MllLeft  = 60;
    double MllRight = 120;
    int NBin = 30;
    if(! (MllLeft<=ZCand.M()&&ZCand.M()<MllRight) ) return;

    vector<Electron> ElectronColl_shifted;// = ElectronColl; // copy the vector                                                                                                              

    Electron this_el1 = ElectronColl.at(0);
    Electron this_el2 = ElectronColl.at(1);


    if(abs(ElectronColl.at(0).scEta())<1.4442&&abs(ElectronColl.at(1).scEta())<1.4442){
      if(ElectronColl.at(0).Charge()*ElectronColl.at(1).Charge()>0){
        FillHist(param.Name+"/ScaleFactor/BB_ZMass_SS", ZCand.M(), EvWeight, NBin, MllLeft, MllRight);
	FillHist(param.Name+"/ScaleFactor/BB_LepPt_SS", this_el1.PtMaxed(200) , EvWeight , nbinNeg, pTbinNeg,"pT");
	FillHist(param.Name+"/ScaleFactor/BB_LepPt_SS", -1*this_el2.PtMaxed(200) , EvWeight , nbinNeg, pTbinNeg,"pT");
	FillHist(param.Name+"/ScaleFactor/BB_LepEta_SS", (this_el1.scEta()+2.5)    , EvWeight ,100., -5, 5, "Eta");
	FillHist(param.Name+"/ScaleFactor/BB_LepEta_SS", -1*(this_el2.scEta()+2.5)    , EvWeight ,100., -5, 5, "Eta");
	
      }
      if(ElectronColl.at(0).Charge()*ElectronColl.at(1).Charge()<0){
        FillHist(param.Name+"/ScaleFactor/BB_ZMass_OS", ZCand.M(), EvWeight, NBin, MllLeft, MllRight);
      } //JH : if you want to check OS distribution before applying the CF weight
    }
    // BE
    if((abs(ElectronColl.at(0).scEta())<1.4442&&abs(ElectronColl.at(1).scEta())>=1.556)||(abs(ElectronColl.at(0).scEta())>=1.556&&abs(ElectronColl.at(1).scEta())<1.4442)){
      if(ElectronColl.at(0).Charge()*ElectronColl.at(1).Charge()>0){
        FillHist(param.Name+"/ScaleFactor/BE_ZMass_SS", ZCand.M(), EvWeight, NBin, MllLeft, MllRight);
        FillHist(param.Name+"/ScaleFactor/BE_LepPt_SS", this_el1.PtMaxed(200) , EvWeight , nbinNeg, pTbinNeg,"pT");
	FillHist(param.Name+"/ScaleFactor/BE_LepPt_SS", -1*this_el2.PtMaxed(200) , EvWeight , nbinNeg, pTbinNeg,"pT");
	FillHist(param.Name+"/ScaleFactor/BE_LepEta_SS", (this_el1.scEta()+2.5)    , EvWeight ,100., -5, 5, "Eta");
	FillHist(param.Name+"/ScaleFactor/BE_LepEta_SS", -1*(this_el2.scEta()+2.5)    , EvWeight ,100., -5, 5, "Eta");

      }
      if(ElectronColl.at(0).Charge()*ElectronColl.at(1).Charge()<0){
        FillHist(param.Name+"/ScaleFactor/BE_ZMass_OS", ZCand.M(), EvWeight, NBin, MllLeft, MllRight);
      }
    }
    // EE
    if(abs(ElectronColl.at(0).scEta())>=1.556&&abs(ElectronColl.at(1).scEta())>=1.556){
      if(ElectronColl.at(0).Charge()*ElectronColl.at(1).Charge()>0){
        FillHist(param.Name+"/ScaleFactor/EE_ZMass_SS", ZCand.M(), EvWeight, NBin, MllLeft, MllRight);
        FillHist(param.Name+"/ScaleFactor/EE_LepPt_SS", this_el1.PtMaxed(200) , EvWeight , nbinNeg, pTbinNeg,"pT");
	FillHist(param.Name+"/ScaleFactor/EE_LepPt_SS", -1*this_el2.PtMaxed(200) , EvWeight , nbinNeg, pTbinNeg,"pT");
	FillHist(param.Name+"/ScaleFactor/EE_LepEta_SS", (this_el1.scEta()+2.5)    , EvWeight ,100., -5, 5, "Eta");
	FillHist(param.Name+"/ScaleFactor/EE_LepEta_SS", -1*(this_el2.scEta()+2.5)    , EvWeight ,100., -5, 5, "Eta");
      }
      if(ElectronColl.at(0).Charge()*ElectronColl.at(1).Charge()<0){
        FillHist(param.Name+"/ScaleFactor/EE_ZMass_OS", ZCand.M(), EvWeight, NBin, MllLeft, MllRight);
      }
    }
    
    
    double X = GetZMassShift(ElectronColl);;
  
    if(ElectronColl[0].IsBB() && ElectronColl[1].IsBB()){
      if(DataYear==2017) {
	
	if(HasFlag("FLATSF")) X = 0.988;
	else {
	  if(ElectronColl[0].Pt() < 50 && ElectronColl[1].Pt() < 50) X = 0.993;
	  else if(ElectronColl[0].Pt() < 100 && ElectronColl[1].Pt() < 50) X = 0.994;
	  else if( ElectronColl[1].Pt() < 100) X = 0.998;
	  else X=1;
	}
      }
    }
    if(ElectronColl[0].IsEC() && ElectronColl[1].IsEC()){
      if(DataYear==2017) {
	if(HasFlag("FLATSF"))X = 0.992;
	else{
	  if(ElectronColl[0].Pt() < 50 && ElectronColl[1].Pt() < 50) X = 0.99;
          else if(ElectronColl[0].Pt() < 100 && ElectronColl[1].Pt() < 50) X = 0.996;
          else if( ElectronColl[1].Pt() < 100) X = 0.996;
          else  if( ElectronColl[1].Pt() < 250) X = 0.997;
	  else  X=1;
	}
      }
    }

    this_el1*= X;
    this_el2*= X;
    
    TString X_string = "_Shifted";
    ElectronColl_shifted.push_back(this_el1);
    ElectronColl_shifted.push_back(this_el2);
        
    Particle ZCand_shifted = ElectronColl_shifted.at(0) + ElectronColl_shifted.at(1);
    double weight_shifted = GetCFWeightElectron(ElectronColl_shifted, param , false);
    weight_shifted *= EvWeight;
    double weight_shiftedSF = weight_shifted;

    std::vector<Lepton *> EL_Leptons = MakeLeptonPointerVector(ElectronColl,param);

    weight_shiftedSF *= GetCFSF(param,EL_Leptons);
    
    
    //Particle METv_shifted;
    //METv_shifted.SetPxPyPzE(METv.Px()+ZCand.Px()-ZCand_shifted.Px(),METv.Py()+ZCand.Py()-ZCand_shifted.Py(),0,METv.E()+ZCand.E()-ZCand_shifted.E());
    
    if(MllLeft<=ZCand_shifted.M()&&ZCand_shifted.M()<MllRight){
      if(ElectronColl.at(0).Charge()*ElectronColl.at(1).Charge()<0){

        // BB
        if(abs(ElectronColl_shifted.at(0).scEta())<1.4442&&abs(ElectronColl_shifted.at(1).scEta())<1.4442){
          FillHist(param.Name+"/ScaleFactor/BB_ZMass_OS_CFweighted_shifted_"+X_string, ZCand_shifted.M(),         weight_shifted, NBin, MllLeft, MllRight);
	  FillHist(param.Name+"/ScaleFactor/BB_LepPt_OS_CFweighted_shifted_"+X_string, this_el1.PtMaxed(200) ,    weight_shifted, nbinNeg, pTbinNeg,"pT");
	  FillHist(param.Name+"/ScaleFactor/BB_LepPt_OS_CFweighted_shifted_"+X_string, -1*this_el2.PtMaxed(200) , weight_shifted, nbinNeg, pTbinNeg,"pT");
	  FillHist(param.Name+"/ScaleFactor/BB_LepEta_OS_CFweighted_shifted_"+X_string, (this_el1.scEta()+2.5)    , weight_shifted, 100., -5, 5, "Eta");
	  FillHist(param.Name+"/ScaleFactor/BB_LepEta_OS_CFweighted_shifted_"+X_string, -1*(this_el2.scEta()+2.5) , weight_shifted, 100., -5, 5, "Eta");
	}

        // BE
        if((abs(ElectronColl_shifted.at(0).scEta())<1.4442&&abs(ElectronColl_shifted.at(1).scEta())>=1.556)||(abs(ElectronColl_shifted.at(0).scEta())>=1.556&&abs(ElectronColl_shifted.at(1).scEta())<1.4442)){
          FillHist(param.Name+"/ScaleFactor/BE_ZMass_OS_CFweighted_shifted_"+X_string, ZCand_shifted.M(),         weight_shifted, NBin, MllLeft, MllRight);
          FillHist(param.Name+"/ScaleFactor/BE_ZMass_OS_CFSFweighted_shifted_"+X_string, ZCand_shifted.M(),       weight_shiftedSF, NBin, MllLeft, MllRight);
          FillHist(param.Name+"/ScaleFactor/BE_LepPt_OS_CFweighted_shifted_"+X_string, this_el1.PtMaxed(200) ,    weight_shiftedSF, nbinNeg, pTbinNeg,"pT");
          FillHist(param.Name+"/ScaleFactor/BE_LepPt_OS_CFweighted_shifted_"+X_string, -1*this_el2.PtMaxed(200) , weight_shiftedSF, nbinNeg, pTbinNeg,"pT");
          FillHist(param.Name+"/ScaleFactor/BE_LepEta_OS_CFweighted_shifted_"+X_string, (this_el1.scEta()+2.5)    , weight_shiftedSF ,100., -5, 5, "Eta");
          FillHist(param.Name+"/ScaleFactor/BE_LepEta_OS_CFweighted_shifted_"+X_string, -1*(this_el2.scEta()+2.5) , weight_shiftedSF ,100., -5, 5, "Eta");

        }

        // EE
        if(abs(ElectronColl_shifted.at(0).scEta())>=1.556&&abs(ElectronColl_shifted.at(1).scEta())>=1.556){
          FillHist(param.Name+"/ScaleFactor/EE_ZMass_OS_CFweighted_shifted_"+X_string, ZCand_shifted.M(), weight_shifted, NBin, MllLeft, MllRight);
	  FillHist(param.Name+"/ScaleFactor/EE_LepPt_OS_CFweighted_shifted_"+X_string, this_el1.PtMaxed(200) ,    weight_shifted, nbinNeg, pTbinNeg,"pT");
          FillHist(param.Name+"/ScaleFactor/EE_LepPt_OS_CFweighted_shifted_"+X_string, -1*this_el2.PtMaxed(200) , weight_shifted, nbinNeg, pTbinNeg,"pT");
          FillHist(param.Name+"/ScaleFactor/EE_LepEta_OS_CFweighted_shifted_"+X_string, (this_el1.scEta()+2.5)    , weight_shifted ,100., -5, 5, "Eta");
          FillHist(param.Name+"/ScaleFactor/EE_LepEta_OS_CFweighted_shifted_"+X_string, -1*(this_el2.scEta()+2.5) , weight_shifted ,100., -5, 5, "Eta");

        }
      }
    }
  }
}

HNL_Lepton_ChargeFlip::HNL_Lepton_ChargeFlip(){

}

HNL_Lepton_ChargeFlip::~HNL_Lepton_ChargeFlip(){

}
