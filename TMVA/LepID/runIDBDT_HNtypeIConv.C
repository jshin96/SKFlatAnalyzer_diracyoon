void runIDBDT_HNtypeIConv(TString channel="EE",  int signal_mode=2, TString NTrees="800", TString NormMode="NumEvents", TString   MinNodeSize ="1.5", TString MaxDepth = "3", TString nCuts="200", bool IgnoreNegweights=true){


  TString NegWeights = (IgnoreNegweights)   ? ":IgnoreNegWeightsInTraining=True" : "";  
  TString NegWeightsString = (IgnoreNegweights)   ? "IgnoreNegWeightsInTraining" : "";

  bool TESTMODE=true;
  int eta_mode=0;

  TString signal="";
  if(signal_mode == 0 )signal = "SignalLowMass";
  if(signal_mode == 1 )signal = "SignalAll";
  if(signal_mode == 2 )signal = "DYTypeI_DF_M100_private";
  if(signal_mode == 3 )signal = "DYTypeI_DF_M250_private";
  if(signal_mode == 4 )signal = "DYTypeI_DF_M1000_private";

  TString era = "Run2", treeName = "";

  TString Eta_mode_txt = TString::Itoa(eta_mode, 10);

  TMVA::gConfig().GetVariablePlotting().fNbins1D = 500; 

  const TString path = "/data6/Users/jalmond/2020/HL_SKFlatAnalyzer_ULv3/SKFlatAnalyzer/HNDiLeptonWorskspace/InputFiles/MergedFiles/Run2UltraLegacy_v3/HNL_LepIDKinVar/"+era+"/";

  TFile* fsin = TFile::Open(path+"HNL_LepIDKinVar_"+signal+".root");
  TFile* fbin = TFile::Open(path+"HNL_LepIDKinVar_ConvBkg.root");

  if(channel == "MuMu") treeName = "Tree_mm";
  if(channel == "EE") treeName = "Tree_ee";

  TTree* tree_signal = (TTree*)fsin->Get(treeName);
  TTree* tree_bkg    = (TTree*)fbin->Get(treeName);
  TString fout_name = ("Convoutput_"+signal+"TypeI_"+channel+"_"+signal+"_"+era+"_"+Eta_mode_txt+"_NTrees"+NTrees+"_NormMode_"+NormMode+"_MinNodeSize_"+MinNodeSize+"_MaxDepth_"+MaxDepth+"_nCuts_"+nCuts+"_"+NegWeightsString+"_BDT.root");

  TFile* fout = TFile::Open(fout_name, "RECREATE");
  

  TMVA::Factory* factory = new TMVA::Factory("Conv_"+signal+"TypeI_"+channel+"_"+signal+"_"+era+"_"+Eta_mode_txt+"_NTrees"+NTrees+"_NormMode_"+NormMode+ "_MinNodeSize_"+MinNodeSize+"_MaxDepth_"+MaxDepth+"_nCuts_"+nCuts+"_"+NegWeightsString+"_TMVAClassification", fout,   "!V:!Silent:Color:DrawProgressBar:Transformations=I:AnalysisType=Classification");


  TMVA::DataLoader* data_loader = new TMVA::DataLoader("dataset");
  //==== Variables : Pt(l), HT, MET, Eta(l)
  data_loader->AddVariable("Pt", "Pt", "units", 'F');
  data_loader->AddVariable("Eta", "Eta", "units", 'F');

  data_loader->AddVariable("MiniIsoChHad", "MiniIsoChHad", "units", 'F'); 
      data_loader->AddVariable("MiniIsoNHad", "MiniIsoNHad", "units", 'F'); 
  data_loader->AddVariable("MiniIsoPhHad", "MiniIsoPhHad", "units", 'F');

  data_loader->AddVariable("RelMiniIsoCh", "RelMiniIsoCh", "units", 'F');
  data_loader->AddVariable("RelMiniIsoN", "RelMiniIsoN", "units", 'F');
 

  data_loader->AddVariable("IsoChHad", "IsoChHad", "units", 'F'); 
  data_loader->AddVariable("IsoNHad", "IsoNHad", "units", 'F'); 
  data_loader->AddVariable("IsoPhHad", "IsoPhHad", "units", 'F');


  //==== Variables regarding close/away jets

  data_loader->AddVariable("Dxy",  "Dxy", "units", 'F');
  data_loader->AddVariable("RelDxy",  "RelDxy", "units", 'F');
  data_loader->AddVariable("DxySig",  "DxySig", "units", 'F');
  data_loader->AddVariable("Dz",  "Dz", "units", 'F');   
  data_loader->AddVariable("RelDz",  "RelDz", "units", 'F');   
  data_loader->AddVariable("DzSig",  "DzSig", "units", 'F');   
  data_loader->AddVariable("RelIso", "RelIso", "units", 'F'); 
  data_loader->AddVariable("IP3D", "IP3D", "units", 'F');       
  data_loader->AddVariable("RelIP3D", "RelIP3D", "units", 'F');       
  if(channel == "EE")  data_loader->AddVariable("MVA",  "MVA", "units", 'F');          
  if(channel == "EE")  data_loader->AddVariable("RelMVA",  "RelMVA", "units", 'F');       

  data_loader->AddVariable("PtRatio",  "PtRatio", "units", 'F');
  data_loader->AddVariable("PtRatioCorr",  "PtRatioCorr", "units", 'F');
  data_loader->AddVariable("PtRel",  "PtRel", "units", 'F');
  data_loader->AddVariable("PtRelCorr",  "PtRelCorr", "units", 'F');
  //data_loader->AddVariable("JetNTrk",  "JetNTrk", "units", 'F');
  //data_loader->AddVariable("JetNMVATrk",  "JetNMVATrk", "units", 'F');
  data_loader->AddVariable("PileupJetId",  "PileupJetId", "units", 'F');
 
  data_loader->AddVariable("CEMFracCJ","CEMFracCJ", "units", 'F');
  data_loader->AddVariable("NEMFracCJ","NEMFracCJ", "units", 'F');
  data_loader->AddVariable("CHFracCJ","CHFracCJ", "units", 'F');
  data_loader->AddVariable("NHFracCJ","NHFracCJ","units", 'F');
  data_loader->AddVariable("MuFracCJ","MuFracCJ","units", 'F');
  data_loader->AddVariable("JetDiscCJ","JetDiscCJ","units", 'F');

  if(channel == "MuMu") {
    data_loader->AddVariable("Chi2", "Chi2", "units", 'F');
    data_loader->AddVariable("Validhits", "Validhits", "units", 'I');
    
    data_loader->AddVariable("Matched_stations", "Matched_stations", "units", 'I');
    
    data_loader->AddVariable("Pixel_hits",  "Pixel_hits", "units", 'I');
    
    data_loader->AddVariable("Minireliso",  "Minireliso", "units", 'F');
    
    data_loader->AddVariable("Tracker_layers",  "Tracker_layers", "units", 'I');
    //data_loader->AddVariable("MuonSetSegmentCompatibility","MuonSetSegmentCompatibility", "units", 'F');
  }
  
  if(channel == "EE")   {
    data_loader->AddVariable("MVAIso",  "MVAIso", "units", 'F');          
    data_loader->AddVariable("RelMVAIso",  "RelMVAIso", "units", 'F');          
    data_loader->AddVariable("Full5x5_sigmaIetaIeta",  "Full5x5_sigmaIetaIeta", "units", 'F');
   
    data_loader->AddVariable("dEtaSeed",  "dEtaSeed", "units", 'F');
    data_loader->AddVariable("dPhiIn",  "dPhiIn", "units", 'F');
    
    data_loader->AddVariable("HoverE",  "HoverE", "units", 'F');
    data_loader->AddVariable("EoverP",  "EoverP", "units", 'F');
    data_loader->AddVariable("FBrem",  "FBrem", "units", 'F');
    data_loader->AddVariable("R9",  "R9", "units", 'F');
    
    data_loader->AddVariable("TrkIso",  "TrkIso", "units", 'F');
    
    
    data_loader->AddVariable("InvEminusInvP", "InvEminusInvP", "units", 'F');
    
    data_loader->AddVariable("ecalPFClusterIso",  "ecalPFClusterIso", "units", 'F');
    
    data_loader->AddVariable("hcalPFClusterIso", "hcalPFClusterIso", "units", 'F');

                                                                                                                                                         
    data_loader->AddVariable("MissingHits",  "MissingHits", "units", 'I');                                                                                   
    data_loader->AddVariable("isEcalDriven", "isEcalDriven", "units", 'I');                                                                                  
    
    data_loader->AddVariable("PassConversionVeto",  "PassConversionVeto", "units", 'I');                                                                     
    data_loader->AddVariable("IsGsfCtfScPixChargeConsistent",  "IsGsfCtfScPixChargeConsistent", "units", 'I');                                               
    data_loader->AddVariable("IsGsfScPixChargeConsistent",  "IsGsfScPixChargeConsistent", "units", 'I');                                                     
    data_loader->AddVariable("IsGsfCtfChargeConsistent",  "IsGsfCtfChargeConsistent", "units", 'I'); 
  
    data_loader->AddVariable("dr03TkSumPt",  "dr03TkSumPt", "units", 'F');
    data_loader->AddVariable("dr03HcalTowerSumEt",  "dr03HcalTowerSumEt", "units", 'F');
    data_loader->AddVariable("dr03HcalDepth1TowerSumEt",  "dr03HcalDepth1TowerSumEt", "units", 'F');
    data_loader->AddVariable("dr03EcalRecHitSumEt",  "dr03EcalRecHitSumEt", "units", 'F');
    data_loader->AddVariable("e15",  "e15", "units", 'F');
    data_loader->AddVariable("e25",  "e25", "units", 'F');
    data_loader->AddVariable("e55",  "e55", "units", 'F');
    data_loader->AddVariable("e2x5OverE5x5",  "e2x5OverE5x5", "units", 'F');
    data_loader->AddVariable("e1x5OverE5x5",  "e1x5OverE5x5", "units", 'F');
    data_loader->AddVariable("EtaWidth",  "EtaWidth", "units", 'F');
    data_loader->AddVariable("PhiWidth",  "PhiWidth", "units", 'F');

}
  
  

  data_loader->AddSpectator("w_tot", "w_tot", "units", 'F');          

  data_loader->AddSignalTree(tree_signal, 1.);
  data_loader->AddBackgroundTree(tree_bkg, 1.0);
  data_loader->SetWeightExpression("w_tot");  

  //==== Nj, Nb cut
  TCut cut_s = "";
  TCut cut_b = "";

  if(eta_mode==1){
    cut_s = "(Eta<0.8)";
    cut_b = "(Eta<0.8)";
  }
  if(eta_mode==2){
    cut_s = "(Eta<1.5&&Eta>0.8)";
    cut_b = "(Eta<1.5&&Eta>0.8)";
  }
  if(eta_mode==3){
    cut_s = "(Eta>1.5)";
    cut_b = "(Eta>1.5)";
  }


  int n_train_signal = tree_signal->GetEntries(cut_s)/2;
  int n_train_back = tree_bkg->GetEntries(cut_b)/2;
  if(TESTMODE) {
    n_train_signal = 10000;
    n_train_back = 10000;
  }




  data_loader->PrepareTrainingAndTestTree(cut_s, cut_b,   Form("nTrain_Signal=%d:nTrain_Background=%d:nTest_Signal=%d:nTest_Background=%d:SplitMode=Random:NormMode="+NormMode+":V", n_train_signal, n_train_back, n_train_signal, n_train_back));

  
  //==== Adaptive Boost
  
  factory->BookMethod( data_loader,TMVA::Types::kBDT, "BDT",
                       "!H:!V:NTrees="+NTrees+":MinNodeSize="+MinNodeSize+"%:MaxDepth="+MaxDepth+":BoostType=AdaBoost:SeparationType=GiniIndex:nCuts="+nCuts+":PruneMethod=NoPruning"+NegWeights ); 


  //==== Gradient Boost
  //  factory->BookMethod(data_loader, TMVA::Types::kBDT, "BDTG",  "!H:!V:NTrees="+NTrees+":MinNodeSize="+MinNodeSize+"%:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.5:nCuts="+nCuts+":MaxDepth="+MaxDepth );

  factory->TrainAllMethods();
  factory->TestAllMethods();
  factory->EvaluateAllMethods();

  fout->Close();

  delete factory;
  delete data_loader;

  //TMVA::TMVAGui(fout_name);

  return;
}
