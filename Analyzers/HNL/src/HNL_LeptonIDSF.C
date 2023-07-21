#include "HNL_LeptonIDSF.h"

void HNL_LeptonIDSF::initializeAnalyzer(){

  // All default settings like trigger/ PD/ BJet are decalred in HNL_LeptonCore::initializeAnalyzer to make them consistent for all HNL codes

  HNL_LeptonCore::initializeAnalyzer();

  SetupIDMVAReaderDefault();


  cout << "HNL_LeptonIDSF Code is used to measure and study lepton ID efficinecy and SF (temp SF)" << endl;

}


void HNL_LeptonIDSF::executeEvent(){
  
  if((_jentry==0)){ 
    // Print out trigger info in HNL_LeptonCore::initializeAnalyzer
    TriggerPrintOut(GetEvent());
  }
  
  AnalyzerParameter param =  HNL_LeptonCore::InitialiseHNLParameter("MVAUL","");


  MeasureElectronEfficiencies(param);
  MeasureMuonEfficiencies(param);

  MeasureElectronIDSF(param);
  MeasureMuonIDSF(param);
  return ;
}

void HNL_LeptonIDSF::MeasureMuonEfficiencies(AnalyzerParameter param){

  Event ev = GetEvent();
  double weight = SetupWeight(ev,param)/MCweight(true, true);
  weight *= MCweight(true, false);


  HNL_LeptonCore::Channel dilep_channel = MuMu;
  std::vector<Muon>       MuonCollProbe     = GetMuons    ("passProbe",    10., 2.4);
  vector<Muon> MuonCollProbePrompt;
  for(auto im : MuonCollProbe) {
    if(im.IsPrompt()) MuonCollProbePrompt.push_back(im);
  }

  std::vector<Lepton *> LeptonColl      = MakeLeptonPointerVector(MuonCollProbePrompt);

  if (!PassTriggerSelection(dilep_channel, ev, LeptonColl,"POG")) return;


  FillMuonPlots("MuonEff" , "Muon", MuonCollProbePrompt, weight);

  vector<TString> IDs = {"HNL_Peking", "HNTightV2","HNL_HN3L","MVAID","MVALoose","HNL_ULID_2016","HNL_ULID_2017","HNL_ULID_LF","HNL_ULID_2016_L","HNL_ULID_2017_L"};
  for(auto ID : IDs) PlotIDEfficiency(param,dilep_channel, MuonCollProbePrompt ,  ID,  weight);
  

}

void HNL_LeptonIDSF::MeasureElectronEfficiencies(AnalyzerParameter param){

  Event ev = GetEvent();

  double weight = SetupWeight(ev,param)/(ev.GetTriggerLumi("Full") *MCweight(true, true));
  weight *= MCweight(true, false);
  FillHist("MeasureElectronEfficiencies/Weight",  weight,   1, 100, -10, 10);

  HNL_LeptonCore::Channel dilep_channel= EE;

  std::vector<Electron> ProbeEl = GetElectrons( "passProbeID", 10., 2.5);

  vector<Electron> ElectronCollProbePrompt;
  vector<Electron> ElectronCollProbeConv;
  vector<Electron> ElectronCollProbeCF;
  vector<Electron> ElectronCollProbeFake;
  for(auto iel : ProbeEl) {
    if(iel.IsPrompt()) ElectronCollProbePrompt.push_back(iel);
    if(iel.LeptonIsCF())     ElectronCollProbeCF.push_back(iel);
    if(iel.IsConv())   ElectronCollProbeConv.push_back(iel);
    if(iel.IsFake())   ElectronCollProbeFake.push_back(iel);
  }


  std::vector<Lepton *> LeptonColl      = MakeLeptonPointerVector(ProbeEl);
  
  FillElectronPlots("ElEff" , "Electron",  ElectronCollProbePrompt, weight);

  vector<TString> IDs = {"HNL_ULID_Baseline",
			 "HNTightV2", 
			 "HNL_Peking_2016","HNL_Peking_2017",
			 "passHEEPID","passMediumID","passTightID","passMVAID_Iso_WP80","passMVAID_Iso_WP90","passMVAID_noIso_WP80","passMVAID_noIso_WP90",
			 "MVAID","passProbeID","passProbeIDTight","MVALoose",
			 "HNL_ULID_Run2_OPT","HNL_ULID_2016_OPT","HNL_ULID_2017_OPT","HNL_ULID_2018_OPT",
			 "HNL_ULID_OPT1",
			 "HNL_ULID_OPT2",			 
			 "HNL_ULID_OPT3",
			 "HNL_ULID_OPT4",
			 "HNL_ULID_OPT5",
			 "HNL_ULID_OPT6",
			 "HNL_ULID_OPT7",
			 "HNL_ULID_OPT8",
			 "HNL_ULID_OPT9",
			 "HNL_ULID_OPT10",
			 "HNL_ULID_OPT11",
			 "HNL_ULID_OPT12",
			 "HNL_ULID_OPT13",
			 "HNL_ULID_OPT14", "HNL_ULID_OPT_POG1", "HNL_ULID_OPT_POG2", "HNL_ULID_OPT_POG3", "HNL_ULID_OPT_POG4",
			 "HNL_ULID_CF_VL","HNL_ULID_CF_L","HNL_ULID_CF_M","HNL_ULID_CF_T","HNL_ULID_CF_VT","HNL_ULID_Fake_VL","HNL_ULID_Fake_L","HNL_ULID_Fake_M","HNL_ULID_Fake_T","HNL_ULID_Fake_VT","HNL_ULID_Conv_2016","HNL_ULID_Conv_2017","HNL_ULID_Conv_2018","HNL_ULID_Conv_Run2","HNL_ULID_Conv_L","HNL_ULID_Conv_M","HNL_ULID_Conv_T","HNL_ULID_2016","HNL_ULID_CFv2","HNL_ULID_CFv2p1","HNL_ULID_CFv2p2", "HNL_ULID_CFEDv2","HNL_ULID_CFEDv2p1","HNL_ULID_CFEDv2p2"};


  vector<TString> BarrelIDs = {"BBv1","BBv2","BBv3","BBv4","BBv5","BBv6","BBv7","BBv8","BBv9","BBv10","BBv11","BBv12","BBv13","BBv14","BBv15","BBv16","BBv17","BBv18","BBv19","BBv20","BBv21","BBv22","BBv23","BBv24","BBv25","BBv26","BBv27","BBv28","BBv29","BBv30","BBv31","BBv32","BBv33","BBv34","BBv35","BBv36","BBv37","BBv38","BBv39"};
  vector<TString> EndcapIDs = {"ECv1","ECv2","ECv3","ECv4","ECv5","ECv6","ECv7","ECv8","ECv9","ECv10","ECv11","ECv12","ECv13","ECv14","ECv15","ECv16","ECv17","ECv18","ECv19","ECv20","ECv21","ECv22","ECv23","ECv24","ECv25","ECv26","ECv27","ECv28","ECv29","ECv30","ECv31","ECv32","ECv33","ECv34","ECv35","ECv36","ECv37","ECv38","ECv39","ECv40", "ECv41","ECv42","ECv43","ECv44","ECv45","ECv46","ECv47","ECv48","ECv49","ECv50","ECv51","ECv52","ECv53","ECv54"};

  if (PassTriggerSelection(dilep_channel, ev, LeptonColl,"Dilep")) {
    for(auto id : BarrelIDs)    PlotIDEfficiency(param,"EE_Prompt", ElectronCollProbePrompt ,  "FINAL_BBID"+id+"_ECIDECv1",  weight);
    for(auto id : EndcapIDs)    PlotIDEfficiency(param,"EE_Prompt", ElectronCollProbePrompt ,  "FINAL_ECID"+id+"_BBIDBBv1",  weight);
    for(auto ID : IDs)PlotIDEfficiency(param,"EE_Prompt", ElectronCollProbePrompt ,  ID,  weight);
  }

  for(auto ID : IDs)PlotIDEfficiency(param,"EE_Fake", ElectronCollProbeFake ,   ID,  weight);
  for(auto ID : IDs)PlotIDEfficiency(param,"EE_CF", ElectronCollProbeCF  ,    ID,  weight);
  for(auto ID : IDs)PlotIDEfficiency(param,"EE_Conv", ElectronCollProbeConv ,   ID,  weight);

  return;
  for(auto i : ElectronCollProbePrompt) {
    
    if(i.PassID("HNL_ULID_NPCFOPT_Barrel") && i.PassID("HNL_ULID_NPCFOPT_EndCap")) {
      vector<TString> MVAString = {"v2","EDv2"};
      for(auto i_mvastring : MVAString){
        if(i.HNL_MVA_Conv(i_mvastring) >= i.GetPtSlopeCut(10,60, -0.45,0.4)) FilllHistBins(i, true,  GetChannelString(dilep_channel), "Conv_"+i_mvastring+"_slopcut1",  weight);
        else  FilllHistBins(i, false,  GetChannelString(dilep_channel), "Conv_"+i_mvastring+"_slopcut1",  weight);
	
        if(i.HNL_MVA_Conv(i_mvastring) >= i.GetPtSlopeCut(10,60, -0.45,0.25)) FilllHistBins(i, true,  GetChannelString(dilep_channel), "Conv_"+i_mvastring+"_slopcut2",  weight);
        else  FilllHistBins(i, false,  GetChannelString(dilep_channel), "Conv_"+i_mvastring+"_slopcut2",  weight);
	
        if(i.HNL_MVA_Conv(i_mvastring) >= i.GetPtSlopeCut(10,60, -0.45,0.)) FilllHistBins(i, true,  GetChannelString(dilep_channel), "Conv_"+i_mvastring+"_slopcut3",  weight);
        else  FilllHistBins(i, false,  GetChannelString(dilep_channel), "Conv_"+i_mvastring+"_slopcut3",  weight);
	
	
        if(i.HNL_MVA_Conv(i_mvastring) >= i.GetPtSlopeCut(10,60, -0.7,0.4)) FilllHistBins(i, true,  GetChannelString(dilep_channel), "Conv_"+i_mvastring+"_slopcut4",  weight);
        else  FilllHistBins(i, false,  GetChannelString(dilep_channel), "Conv_"+i_mvastring+"_slopcut4",  weight);

        if(i.HNL_MVA_Conv(i_mvastring) >= i.GetPtSlopeCut(10,60, -0.7,0.25)) FilllHistBins(i, true,  GetChannelString(dilep_channel), "Conv_"+i_mvastring+"_slopcut5",  weight);
        else  FilllHistBins(i, false,  GetChannelString(dilep_channel), "Conv_"+i_mvastring+"_slopcut5",  weight);

        if(i.HNL_MVA_Conv(i_mvastring) >= i.GetPtSlopeCut(10,60, -0.7,0.)) FilllHistBins(i, true,  GetChannelString(dilep_channel), "Conv_"+i_mvastring+"_slopcut6",  weight);
        else  FilllHistBins(i, false,  GetChannelString(dilep_channel), "Conv_"+i_mvastring+"_slopcut6",  weight);
	
	
      }
    }
  }

  
  //////// Check Efficiency for each MVA with fine scan from -1 to 0.9
  for(int imva=0 ; imva < 91 ; imva++){
    double mva_d=  -1. + double(imva)*.02;
    TString mvaTS= DoubleToString(mva_d);

    for(auto i : ElectronCollProbePrompt) {
      
      if(i.PassID("HNL_ULID_NPCFOPT_Barrel") && i.PassID("HNL_ULID_NPCFOPT_EndCap")) {
	vector<TString> MVAString = {"v2","EDv2"};
	for(auto i_mvastring : MVAString){
	  if(i.HNL_MVA_Conv(i_mvastring) >= mva_d)    FilllHistBins(i, true,  GetChannelString(dilep_channel), "Conv_"+i_mvastring+"_"+mvaTS,  weight);
	  else FilllHistBins(i, false,  GetChannelString(dilep_channel),"Conv_"+i_mvastring+"_"+mvaTS,  weight);
	}
      } 
     
      if(i.PassID("HNL_ULID_NPConvOPT_Barrel") && i.PassID("HNL_ULID_NPConvOPT_EndCap")) {
	vector<TString> MVAString = {"v2", "v2p1","v2p2","EDv2","EDv2p2","EDv2p2",};
	for(auto i_mvastring : MVAString){
          if(i.HNL_MVA_CF(i_mvastring) >= mva_d)    FilllHistBins(i, true,  GetChannelString(dilep_channel), "CF_"+i_mvastring+"_"+mvaTS,  weight);
          else FilllHistBins(i, false,  GetChannelString(dilep_channel),"CF_"+i_mvastring+"_"+mvaTS,  weight);
        }
      } 
      
      if(i.PassID("HNL_ULID_CFConvOPT_Barrel") && i.PassID("HNL_ULID_CFConvOPT_EndCap")) {
        vector<TString> MVAString = {"v4", "EDv4"};
        for(auto i_mvastring : MVAString){
          if(i.HNL_MVA_Fake(i_mvastring) >= mva_d)    FilllHistBins(i, true,  GetChannelString(dilep_channel), "Fake_"+i_mvastring+"_"+mvaTS,  weight);
          else FilllHistBins(i, false,  GetChannelString(dilep_channel),"Fake_"+i_mvastring+"_"+mvaTS,  weight);
        }
      }
    }
  }
  
  return;
}


void HNL_LeptonIDSF::PlotIDEfficiency(AnalyzerParameter param,HNL_LeptonCore::Channel dilep_channel, vector<Electron> ElectronColl, TString ID, double weight_ll){

  TString channel_string = GetChannelString(dilep_channel) ;
  
  for(auto iel : ElectronColl) {
    FilllHistBins(iel, iel.PassID(ID),  channel_string,ID, weight_ll);
  }

}

void HNL_LeptonIDSF::PlotIDEfficiency(AnalyzerParameter param, TString channel_string, vector<Electron> ElectronColl, TString IDs, double weight_ll){

  for(auto iel : ElectronColl) {
    FilllHistBins(iel, iel.PassID(IDs),  channel_string,IDs, weight_ll);
  }

}



void HNL_LeptonIDSF::PlotIDEfficiency(AnalyzerParameter param,HNL_LeptonCore::Channel dilep_channel, vector<Muon> MuonColl, TString ID, double weight_ll){

  TString channel_string = GetChannelString(dilep_channel) ;

  for(auto imu : MuonColl) {
    FilllHistBins(imu, imu.PassID(ID),  channel_string,ID, weight_ll);
  }

}



void HNL_LeptonIDSF::MeasureMuonIDSF(AnalyzerParameter param){

  Event ev = GetEvent();
  double weight =SetupWeight(ev,param);

  HNL_LeptonCore::Channel dilep_channel = MuMu;
  std::vector<Muon>       MuonCollProbe     = GetMuons    ("passProbe",    10., 2.4);

  /// Event cuts                                                                                                                                                                                                                       

  std::vector<Electron>   ElectronCollV = GetElectrons(param.Electron_Veto_ID, 10., 2.5);
  if(ElectronCollV.size() != 0) return;                                                                                                                                                                                                

  std::vector<Jet> BJetColl  = GetHNLJets("BJetL", param);
  Particle METv              = GetvMET("PuppiT1xyCorr"); // reyturns MET with systematic correction                                                                                                                                                                                                                                                                                                                                                                                      
  if(BJetColl.size() > 0 ) return;
  if(!PassMETFilter()) return;

  std::vector<Lepton *> LeptonColl      = MakeLeptonPointerVector(MuonCollProbe);

  // Chose Typ1 Phi corr MET + smear jets 
  if(!CheckLeptonFlavourForChannel(dilep_channel, LeptonColl)) return;
  if (!PassTriggerSelection(dilep_channel, ev, LeptonColl,"POG")) return;

  // Reuqire 2 Probe muons in Z mass
  if(MuonCollProbe.size() != 2) return;
  if(fabs(GetLLMass(MuonCollProbe)- 90.1) > 10) return;

  if(!IsData){
    if(!MuonCollProbe[0].IsPrompt()) return;
    if(!MuonCollProbe[1].IsPrompt()) return;
  }

  vector<TString> IDs = {
    "MVALoose",
    "MVAID",
    "POGLoose",
    "POGMedium",    
    "HNL_ULID_2016",                                                                                                                                                                                                                                 
    "HNL_ULID_2017",                                                                                                                                                                                                                                 
    "HNTightV2"
  };

  /// Make cuts to remove fakes
  
  for(auto id : IDs) MeasureIDSF(param,dilep_channel, MuonCollProbe, id, weight);
  
  return;
}



void HNL_LeptonIDSF::MeasureElectronIDSF(AnalyzerParameter param){

  Event ev = GetEvent();
  double weight =SetupWeight(ev,param);

  HNL_LeptonCore::Channel dilep_channel= EE;

  /// Event cuts
  std::vector<Jet> BJetColl  = GetHNLJets("BJetL", param);
  Particle METv = GetvMET("PuppiT1xyCorr"); // reyturns MET with systematic correction                                                                                                                            

  if(BJetColl.size() > 0 ) return;
  if(!PassMETFilter()) return;

  /// Obj cuts
  std::vector<Muon>       MuonCollV     = GetMuons    (param.Muon_Veto_ID, 5., 2.4);
  if(MuonCollV.size() != 0) return;

  std::vector<Electron> ProbeEl = GetElectrons( "passProbeID", 10., 2.5);
  if(ProbeEl.size() != 2) return;
  if(!IsData){
    if(!ProbeEl[0].IsPrompt()) return;
    if(!ProbeEl[1].IsPrompt()) return;
  }

  if(fabs(GetLLMass(ProbeEl)- 90.1) > 10) return;

  std::vector<Lepton *> LeptonColl      = MakeLeptonPointerVector(ProbeEl);
  if(!PassTriggerSelection(dilep_channel, ev, LeptonColl,"POG")) return;
  if(!CheckLeptonFlavourForChannel(dilep_channel, LeptonColl)) return; // Check if EE cahnnel has 2 el...                                                                                                         
  
  vector<TString> IDs = {  "HNL_ULID_2016",  "HNL_ULID_2017",      "HNL_ULID_2018",  "HNL_LID_2016",    "HNL_ULID_Run2",  "HNL_ULID_Run2v2", "HNTightV2","HNL_ULID_Run2v3","HNL_ULID_Run2v4","HNL_ULID_Run2NoConv","HNL_ULID_Run2NoFake","HNL_ULID_Run2NoCF"};
  IDs.push_back("passProbeIDTight");
  IDs.push_back("MVALoose");


  for(auto id : IDs)    MeasureIDSF(param ,dilep_channel, ProbeEl, id, weight);
  
  return;
  
}
     

void HNL_LeptonIDSF::MeasureIDSF(AnalyzerParameter param,HNL_LeptonCore::Channel dilep_channel, vector<Muon> MuonColl, TString ID, double weight_ll){

  TString channel_string = GetChannelString(dilep_channel) ;
       
  std::vector<Lepton *> LeptonColl      = MakeLeptonPointerVector(MuonColl);


  if(SameCharge(MuonColl)) channel_string=channel_string+"_SS";
  else  channel_string=channel_string+"_OS";


  if(MuonColl[0].PassID("POGTightWithTightIso") && MuonColl[0].Pt() > 35) {
    
    double SF=1;
    if(!IsData){
      double lep1_pt  = MuonColl[0].MiniAODPt();
      double lep1_eta = MuonColl[0].Eta();
      double lep2_pt  = MuonColl[1].MiniAODPt();
      double lep2_eta = MuonColl[1].Eta();
      
      double lep1_idsf   = mcCorr->MuonID_SF ("NUM_TightID_DEN_TrackerMuons",  lep1_eta, lep1_pt,0);
      double lep1_isosf  = mcCorr->MuonISO_SF("NUM_TightRelIso_DEN_TightIDandIPCut", lep1_eta, lep1_pt,0);
      double lep1_recosf = mcCorr->MuonReco_SF("MuonRecoSF", lep1_eta, lep1_pt,0);
      double lep2_recosf = mcCorr->MuonReco_SF("MuonRecoSF", lep2_eta, lep2_pt,0);

      SF = lep1_idsf*lep1_isosf*lep1_recosf*lep2_recosf;
    }
    
    FilllHistBins(Lepton(MuonColl[1]), MuonColl[1].PassID(ID),  channel_string,ID, SF*weight_ll);
    

  }
  if(MuonColl[1].PassID("POGTightWithTightIso")&& MuonColl[1].Pt() > 35) {

    double SF=1;
    if(!IsData){
      double lep1_pt  = MuonColl[1].MiniAODPt();
      double lep1_eta = MuonColl[1].Eta();
      double lep2_pt  = MuonColl[0].MiniAODPt();
      double lep2_eta = MuonColl[0].Eta();
      
      double lep1_idsf   = mcCorr->MuonID_SF ("NUM_TightID_DEN_TrackerMuons",  lep1_eta, lep1_pt,0);
      double lep1_isosf  = mcCorr->MuonISO_SF("NUM_TightRelIso_DEN_TightIDandIPCut", lep1_eta, lep1_pt,0);
      double lep1_recosf = mcCorr->MuonReco_SF("MuonRecoSF", lep1_eta, lep1_pt,0);
      double lep2_recosf = mcCorr->MuonReco_SF("MuonRecoSF", lep2_eta, lep2_pt,0);

      SF = lep1_idsf*lep1_isosf*lep1_recosf*lep2_recosf;
    }

    FilllHistBins(Lepton(MuonColl[0]), MuonColl[0].PassID(ID),  channel_string,ID, SF*weight_ll);

  }
  

  return;

}



void HNL_LeptonIDSF::MeasureIDSF(AnalyzerParameter param,HNL_LeptonCore::Channel dilep_channel, vector<Electron> ElectronColl, TString ID, double weight_ll){
  
  TString channel_string = GetChannelString(dilep_channel) ;

  std::vector<Lepton *> LeptonColl      = MakeLeptonPointerVector(ElectronColl);

  //if(!ZmassOSSFWindowCheck(LeptonColl, 10.)) return;


  if(!IsData){
    if(!SameCharge(ElectronColl)) {
      if( ElectronColl[0].LeptonIsCF() || ElectronColl[1].LeptonIsCF()) return;
    }
  }

  if(SameCharge(ElectronColl)) channel_string=channel_string+"_SS";
  else  channel_string=channel_string+"_OS";
  
  /*for(unsigned int i=0; i < 2; i++){
    if(ElectronColl[i].PassID("HNTightV2") && ! ElectronColl[i].PassID("MVALoose")) {
      cout << "Pass Tight and not MVALoose" << endl;
      cout << "passMVAID_noiso_WPLoose = " << ElectronColl[i].passMVAID_noiso_WPLoose() << endl;
      cout << "Pass_TriggerEmulationLoose = " << ElectronColl[i].Pass_TriggerEmulationLoose() << endl;
      cout << "this->Pt()= " << ElectronColl[i].Pt() << endl;
      cout << "this->fEta " << ElectronColl[i].fEta() << endl;
      cout << "MiniRelIso() = " << ElectronColl[i].MiniRelIso() << endl;
      cout << "NMissingHits() " << ElectronColl[i].NMissingHits() << endl;
      cout << "SIP3D() " << ElectronColl[i].SIP3D() << endl;
      cout << "this->fdXY() " << ElectronColl[i].fdXY() << endl;
      cout << "this->fdZ() = " << ElectronColl[i].fdZ() << endl;
      cout << "passTightID_NoCC() = " << ElectronColl[i].passTightID_NoCC()  << endl;
      cout << "PassHNID() " << ElectronColl[i].PassHNID() << endl;
    }
    }*/

  if(ElectronColl[0].PassID("passPOGTight")&& ElectronColl[0].Pt() > 35) {

    double SF=1;
    if(!IsData){
      double this_recosf  = mcCorr->ElectronReco_SF(ElectronColl[0].scEta(),ElectronColl[0].Pt(), 0);
      double this_idsf    = mcCorr->ElectronID_SF("passTightID", ElectronColl[0].scEta(), ElectronColl[0].Pt(), 0);
      
      double lep2_recosf  = mcCorr->ElectronReco_SF(ElectronColl[1].scEta(),ElectronColl[1].Pt(), 0);
      SF = this_recosf*this_idsf*lep2_recosf;
    }


    FilllHistBins(Lepton(ElectronColl[1]), ElectronColl[1].PassID(ID),  channel_string,ID, SF*weight_ll);

  }
  if(ElectronColl[1].PassID("passPOGTight")&& ElectronColl[1].Pt() > 35) {

    double SF=1;
    if(!IsData){
      double this_recosf  = mcCorr->ElectronReco_SF(ElectronColl[1].scEta(),ElectronColl[1].Pt(), 0);
      double this_idsf    = mcCorr->ElectronID_SF("passTightID", ElectronColl[1].scEta(), ElectronColl[1].Pt(), 0);
      
      double lep2_recosf  = mcCorr->ElectronReco_SF(ElectronColl[0].scEta(),ElectronColl[0].Pt(), 0);
      SF = this_recosf*this_idsf*lep2_recosf;
    }

    FilllHistBins(Lepton(ElectronColl[0]), ElectronColl[0].PassID(ID),  channel_string,ID, SF*weight_ll);

  }

  return;

}


HNL_LeptonIDSF::HNL_LeptonIDSF(){


}
 
HNL_LeptonIDSF::~HNL_LeptonIDSF(){

}



void HNL_LeptonIDSF::FilllHistBins(Lepton lep, bool passID,  TString Channel_string,TString _ID, double lep_weight){
  
  int nbin_pt    =5;
  int nbin_eta   =10;

  double ptbins    [nbin_pt +1]    = { 10.,20.,30., 40.,50., 2000};
  double etabins   [nbin_eta+1   ] = {-2.5, -2.0, -1.56, -1.4442, -1.0, 0, 1.0, 1.4442, 1.56, 2.0, 2.5};
  
  int lepType = (IsData) ? 1 : lep.LeptonGenType();
  TString TypeLable="";

  if(!IsData && !lep.IsPrompt()) return;

  TString Den_tag=TypeLable+"_denom";

  double PtLep = (lep.Pt() > 2000) ? 1999 : lep.Pt();

  FillHist(Channel_string+"/Pt_Eta_"+_ID+Den_tag,lep.Pt(), lep.Eta(),  lep_weight, nbin_pt, ptbins, nbin_eta , etabins);
  FillHist(Channel_string+"/Eta_Pt_"+_ID+Den_tag,lep.Eta(), lep.Pt(),  lep_weight, nbin_eta , etabins,  nbin_pt, ptbins);
  FillHist(Channel_string+"/Pt_"+_ID+Den_tag,  PtLep,   lep_weight, 100, 0, 200);
  FillHist(Channel_string+"/Ptbinned_"+lep.etaRegionString()+"_"+_ID+Den_tag,PtLep,   lep_weight, nbin_pt, ptbins,"");
  FillHist(Channel_string+"/Pt_"+lep.etaRegionString()+"_"+_ID+Den_tag,PtLep,         lep_weight, 100, 0, 200.);
  FillHist(Channel_string+"/Eta"+_ID+Den_tag,lep.Eta(),   lep_weight, 60., -3, 3.);
  
  if(passID){
    TString Num_tag=TypeLable+"_num";
    FillHist(Channel_string+"/Pt_Eta_"+_ID+Num_tag,PtLep, lep.Eta(),  lep_weight, nbin_pt, ptbins, nbin_eta , etabins);
    FillHist(Channel_string+"/Eta_Pt_"+_ID+Num_tag,lep.Eta(), lep.Pt(),  lep_weight, nbin_eta , etabins,  nbin_pt, ptbins);
    FillHist(Channel_string+"/Pt_"+    _ID+Num_tag,lep.Pt(),   lep_weight, 100, 0, 200.);
    FillHist(Channel_string+"/Pt_"+lep.etaRegionString()+"_"+_ID+Num_tag,PtLep,         lep_weight, 100,0, 200.);
    FillHist(Channel_string+"/Ptbinned_"+lep.etaRegionString()+"_"+_ID+Num_tag,PtLep,   lep_weight, nbin_pt, ptbins,"");
    FillHist(Channel_string+"/Eta"+_ID+Num_tag,lep.Eta(),   lep_weight, 60, -3, 3.);
    
  }

  return;
}

