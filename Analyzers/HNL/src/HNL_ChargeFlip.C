#include "HNL_ChargeFlip.h"

void HNL_ChargeFlip::initializeAnalyzer(){

  HNL_LeptonCore::initializeAnalyzer();
  


}

void HNL_ChargeFlip::executeEvent(){


  vector<TString> LepIDs = {"HNL_ULID_"+GetYearString(),"HNTightV2","TopHN", "DefaultPOGTight"};
  
  for (auto id: LepIDs){
    AnalyzerParameter param = InitialiseHNLParameter("SignalStudy","HNL");
    param.Name    =  id;
    param.DefName =  id;
    
    param.FakeMethod   = "DATA";
    param.CFMethod   = "DATA";
    param.ConvMethod = "MC";

    param.Electron_Tight_ID = (id == "TopHN") ? "TopHNSST" :  id;
    param.Muon_Tight_ID     = (id == "TopHN") ? "TopHNT"   :  id;

    if(id =="DefaultPOGTight"){
      param.Muon_Tight_ID   =    "POGTightWithTightIso";
      param.Electron_Tight_ID  = "passPOGTight";
    }
    executeEventFromParameter(param);
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

void HNL_ChargeFlip::executeEventFromParameter(AnalyzerParameter param){

  if(_jentry==0) PrintParam(param);
  run_Debug = (_jentry%nLog==0);

  if(!PassMETFilter()) return;

 
  Event ev = GetEvent();

  double weight =SetupWeight(ev,param);

  // Electrons 
  std::vector<Electron> ElectronColltmp;
  if(param.Electron_Tight_ID.Contains("HEEP")) ElectronColltmp = GetElectrons(param.Electron_Tight_ID,50.,2.5);
  else ElectronColltmp = GetElectrons(param.Electron_Tight_ID,15.,2.5);

  // Muons
  std::vector<Muon> MuonColl; std::vector<Muon> MuonCollVeto;
  if(param.Muon_Tight_ID.Contains("HEEP")) MuonColl = GetMuons(param.Muon_Tight_ID,25.,2.4);
  else MuonColl = GetMuons(param.Muon_Tight_ID,10.,2.4);
  MuonCollVeto = GetMuons(param.Muon_Veto_ID,10.,2.4);
  std::sort(MuonColl.begin(),MuonColl.end(),PtComparing);

  // Gen

  vector<Electron> ElectronColl = ElectronPromptOnly(ElectronColltmp,All_Gens,param);
  vector<Muon> PromptMuonColl   = MuonPromptOnly(MuonColl,All_Gens,param);
  std::sort(ElectronColl.begin(),ElectronColl.end(),PtComparing);
  std::vector<Lepton *> Leptons = MakeLeptonPointerVector(PromptMuonColl,ElectronColl,param);

  // Jet
  vector<Jet> JetColl = GetJets(param.Jet_ID,10.,5.);
  vector<Jet> BJetColl;
  JetTagging::Parameters jtp;
  jtp = JetTagging::Parameters(JetTagging::DeepCSV, JetTagging::Medium, JetTagging::incl, JetTagging::comb);
  BJetColl = SelBJets(JetColl,jtp);

  if("ScaleFactor"){
    if (!PassTriggerSelection(EE, ev,   Leptons,"Dilep")) return ;
  }

  if(HasFlag("MuonCF")){

    /*
    1. 2 muons (25,25)
    2. 3rd lepton veto
    3. mll > 60
    4. anti-btag

    --> mll plot in MuonCFrate/SS(OS)ij where i,j is pT bin #
    */

    //if(!IsDATA) weight *= MCweight() * ev.GetTriggerLumi("Full");

    if(MuonColl.size()!=2) return;
    if(!(MuonColl.at(0).Pt()>25&&MuonColl.at(1).Pt()>25)) return;
    if(MuonCollVeto.size()>2) return;
    Particle ll = MuonColl.at(0) + MuonColl.at(1) ;
    if(ll.M()<=60) return;
    if(BJetColl.size()>0) return;

    double mllbin[7] = {60.,90.,120.,175.,300.,500.,1000.};
    // (pT1,pT2) = {00,10,11,20,21,22}
    TString l1index("0"); TString l2index("0");
    TString bin("00");

    if(25<=MuonColl.at(0).Pt()&&MuonColl.at(0).Pt()<=100) l1index = "0";
    else if(100<MuonColl.at(0).Pt()&&MuonColl.at(0).Pt()<=200) l1index = "1";
    else if(200<MuonColl.at(0).Pt()) l1index = "2";

    if(25<=MuonColl.at(1).Pt()&&MuonColl.at(1).Pt()<=100) l2index = "0";
    else if(100<MuonColl.at(1).Pt()&&MuonColl.at(1).Pt()<=200) l2index = "1";
    else if(200<MuonColl.at(1).Pt()) l2index = "2";

    bin = l1index+l2index;
    std::map<TString, double> binmap = {{"00",0.},{"10",1.},{"11",2.},{"20",3.},{"21",4.},{"22",5.}};

    if(MuonColl.at(0).Charge()*MuonColl.at(1).Charge()>0){
      FillHist(param.Name+"/MuonCFrate/SS"+bin,ll.M(),weight,6,mllbin,"m(ll)");
      FillHist(param.Name+"/MuonCFrate/nSS",binmap[bin],weight,6,0.,6.);
    }
    if(MuonColl.at(0).Charge()*MuonColl.at(1).Charge()<0){
      FillHist(param.Name+"/MuonCFrate/OS"+bin,ll.M(),weight,6,mllbin,"m(ll)");
      FillHist(param.Name+"/MuonCFrate/nOS",binmap[bin],weight,6,0.,6.);
    }

  }


  if(!PassHEMVeto(Leptons)) return ;


  if(HasFlag("ElCFRates")){

    if(IsDATA) return;
    
    double invptbins[12] = { 0., 0.005, 0.0075,0.010,0.015,0.020,0.025, 0.030,0.035, 0.040,0.05, 0.1};
    
    double etabins   [6] = { 0.,0.8,  1.4442,1.556, 2.,  2.5};
    
    for(unsigned int i=0 ; i < ElectronColl.size() ; i++){
      
      Gen truth_lep = GetGenMatchedLepton(ElectronColl.at(i),All_Gens);
      
      if(ElectronColl.at(i).LeptonGenType() <= 0 || ElectronColl.at(i).LeptonGenType() >=4) continue;
      
      if(truth_lep.PID() ==0 ) continue;

      bool IsCF = ElectronColl.at(i).LeptonIsCF();
    
      if(HasFlag("CFratePtInverse")){
	
	/// CF Rate Method 2 WIth Int Conv                                                                                                                                                                                                                                                                                                                                  
	if(abs(ElectronColl.at(i).scEta())<0.8){
	  FillHist(param.Name+"/CFrate/EtaRegion1_Denom",ElectronColl.at(i).InvPt(), weight, 11, invptbins,"#pT^{-1}");
	  if(IsCF)  FillHist(param.Name+"/CFrate/EtaRegion1_Num",ElectronColl.at(i).InvPt(), weight, 11, invptbins,"#pT^{-1}");
	}
	else if(0.8<=abs(ElectronColl.at(i).scEta())&&abs(ElectronColl.at(i).scEta())<1.4442){
	  FillHist(param.Name+"/CFrate/EtaRegion2_Denom",ElectronColl.at(i).InvPt(), weight, 11, invptbins,"#pT^{-1}");
	  if(IsCF)  FillHist(param.Name+"/CFrate/EtaRegion2_Num",ElectronColl.at(i).InvPt(), weight, 11, invptbins,"#pT^{-1}");
	}
	else if(1.556<=abs(ElectronColl.at(i).scEta())&&abs(ElectronColl.at(i).scEta())<2.){
	  FillHist(param.Name+"/CFrate/EtaRegion3_Denom",ElectronColl.at(i).InvPt(), weight, 11, invptbins,"#pT^{-1}");
	  if(IsCF)  FillHist(param.Name+"/CFrate/EtaRegion3_Num",ElectronColl.at(i).InvPt(), weight, 11, invptbins,"#pT^{-1}");
	}
	else if(2.<=abs(ElectronColl.at(i).scEta())&&abs(ElectronColl.at(i).scEta())<2.5){
          FillHist(param.Name+"/CFrate/EtaRegion4_Denom",ElectronColl.at(i).InvPt(), weight, 11, invptbins,"#pT^{-1}");
          if(IsCF)  FillHist(param.Name+"/CFrate/EtaRegion4_Num",ElectronColl.at(i).InvPt(), weight, 11, invptbins,"#pT^{-1}");
        }

	FillHist(param.Name+"/CFrate_Eta/Denom", ElectronColl.at(i).scEta(), weight, 50, -2.5, 2.5,"scEta");
	FillHist(param.Name+"/CFrate_IP/Denom", ElectronColl.at(i).dXY(), weight, 200, -0.1, 0.1,"dXY");
	FillHist(param.Name+"/CFrate_2D/Denom",ElectronColl.at(i).InvPt(), ElectronColl.at(i).scEta(), weight, 11, invptbins, 5,etabins);
	if(IsCF) {
	  FillHist(param.Name+"/CFrate_Eta/Num", ElectronColl.at(i).scEta(), weight, 50, -2.5, 2.5);
	  FillHist(param.Name+"/CFrate_IP/Num", ElectronColl.at(i).dXY(), weight, 200, -0.1, 0.1);
	  FillHist(param.Name+"/CFrate_2D/Num",ElectronColl.at(i).InvPt(), ElectronColl.at(i).scEta(), weight, 11, invptbins, 5,etabins);
	}
      
      }

      double pTbin[10] = {0.,20.,30.,40.,50.,100.,200.,500.,1000.,2000.};
      int nbin = 9;//pTbin.size()-1;
      
      if(abs(ElectronColl.at(i).scEta())<0.8){
	FillHist(param.Name+"/CFratePt/EtaRegion1_Denom", ElectronColl.at(i).Pt(), weight,nbin, pTbin,"pT");
	if(IsCF)   FillHist(param.Name+"/CFratePt/EtaRegion1_Num", ElectronColl.at(i).Pt(), weight,nbin, pTbin,"pT");
      }
      else if(0.8<=abs(ElectronColl.at(i).scEta()) && abs(ElectronColl.at(i).scEta())<1.4442){
	FillHist(param.Name+"/CFratePt/EtaRegion2_Denom", ElectronColl.at(i).Pt(), weight,nbin, pTbin,"pT");
	if(IsCF)        FillHist(param.Name+"/CFratePt/EtaRegion2_Num", ElectronColl.at(i).Pt(), weight,nbin, pTbin,"pT");
      }
      else if(1.556<=abs(ElectronColl.at(i).scEta()) && abs(ElectronColl.at(i).scEta())<2.){
	FillHist(param.Name+"/CFratePt/EtaRegion3_Denom", ElectronColl.at(i).Pt(), weight,nbin, pTbin,"pT");
	if(IsCF) FillHist(param.Name+"/CFratePt/EtaRegion3_Num", ElectronColl.at(i).Pt(), weight,nbin, pTbin,"pT");
      }
      else if(2.<=abs(ElectronColl.at(i).scEta()) && abs(ElectronColl.at(i).scEta())<2.5){
	FillHist(param.Name+"/CFratePt/EtaRegion4_Denom", ElectronColl.at(i).Pt(), weight,nbin, pTbin,"pT");
	if(IsCF) FillHist(param.Name+"/CFratePt/EtaRegion4_Num", ElectronColl.at(i).Pt(), weight,nbin, pTbin,"pT");
      }
      
      FillHist(param.Name+"/CFrate_2DPt/Denom",ElectronColl.at(i).Pt(), ElectronColl.at(i).scEta(), weight, nbin, pTbin, 5,etabins);
      if(IsCF)           FillHist(param.Name+"/CFrate_2DPt/Num",ElectronColl.at(i).Pt(), ElectronColl.at(i).scEta(), weight, nbin, pTbin, 5,etabins);

    }
  }

  if(HasFlag("ScaleFactor")){
    
  }
}

HNL_ChargeFlip::HNL_ChargeFlip(){

}

HNL_ChargeFlip::~HNL_ChargeFlip(){

}
