#include "SkimTree_DileptonBDT.h"

void SkimTree_DileptonBDT::initializeAnalyzer(){

  outfile->cd();
  cout << "[SkimTree_DileptonBDT::initializeAnalyzer()] gDirectory = " << gDirectory->GetName() << endl;
  newtree = fChain->CloneTree(0);


  SetupIDMVAReaderDefault();


  double_triggers.clear();
  single_electron_triggers.clear();
  single_muon_triggers.clear();
  if(DataYear==2016){
    double_triggers = {
      "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v",
      "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v",
      "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v",
      "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v",
      "HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v",
      "HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v",              // H                                                                                                                                                                                                         
      "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v",
      "HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v",       // B-G                                                                                                                                                                                                       
      "HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v",      // B-G                                                                                                                                                                                                       
      "HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v",    // H                                                                                                                                                                                                         
      "HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"    // H                                                                                                                                                                                                         
    };
    single_muon_triggers = {
      "HLT_IsoMu24_v",
      "HLT_IsoTkMu24_v",
    };
    single_electron_triggers = {
      "HLT_Ele27_WPTight_Gsf_v",
    };
  }else if(DataYear==2017){
    double_triggers = {
      "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v",                  // B                                                                                                                                                                                                         
      "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v",          // C-F                                                                                                                                                                                                       
      "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8_v",
      "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v",
      "HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v",      // C-F                                                                                                                                                                                                       
      "HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v",
      "HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"
    };
    single_muon_triggers = {
      "HLT_IsoMu24_v",
      "HLT_IsoMu27_v",
    };
    single_electron_triggers = {
      "HLT_Ele27_WPTight_Gsf_v",
      "HLT_Ele32_WPTight_Gsf_v",
      "HLT_Ele32_WPTight_Gsf_L1DoubleEG_v",
    };
  }else if(DataYear==2018){
    double_triggers = {
      "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v",
      "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v",
      "HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v",
      "HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v",
      "HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"
    };
    single_muon_triggers = {
      "HLT_IsoMu24_v",
    };
    single_electron_triggers = {
      "HLT_Ele27_WPTight_Gsf_v",
      "HLT_Ele28_WPTight_Gsf_v",
      "HLT_Ele32_WPTight_Gsf_v",
    };
  }else{
    cout<<"[SkimTree_Dilepton::initializeAnalyzer] DataYear is wrong : " << DataYear << endl;
  }

  cout << "[SkimTree_Dilepton::initializeAnalyzer] triggers to skim = " << endl;
  for(unsigned int i=0; i<double_triggers.size(); i++){
    cout << "[SkimTree_Dilepton::initializeAnalyzer]   " << double_triggers.at(i) << endl;
  }
  for(unsigned int i=0; i<single_muon_triggers.size(); i++){
    cout << "[SkimTree_Dilepton::initializeAnalyzer]   " << single_muon_triggers.at(i) << endl;
  }
  for(unsigned int i=0; i<single_electron_triggers.size(); i++){
    cout << "[SkimTree_Dilepton::initializeAnalyzer]   " << single_electron_triggers.at(i) << endl;
  }

  vSKWeight=0;
  velectron_ptratio = 0;
  velectron_ptrel  = 0;
  velectron_cj_bjetdisc = 0;
  velectron_cj_flavour = 0;
  velectron_mva_cf_v1 = 0;
  velectron_mva_cf_v2 = 0;
  velectron_mva_cf_v2p1 = 0;
  velectron_mva_cf_v2p2 = 0;
  velectron_mva_cf_ed_v2 = 0;
  velectron_mva_cf_ed_v2p1 = 0;
  velectron_mva_cf_ed_v2p2 = 0;
  velectron_mva_conv_v1 = 0;
  velectron_mva_conv_v2 = 0;
  velectron_mva_fake_v1 = 0 ;
  velectron_mva_fake_v2 = 0 ;
  velectron_mva_fakeHF_v2 = 0 ;
  velectron_mva_fakeLF_v2 = 0 ;
  velectron_mva_fakeTop_v2 = 0 ;

  vmuon_mva_fake = 0;
  vmuon_ptratio = 0;
  vmuon_ptrel  = 0;
  vmuon_cj_bjetdisc = 0;
  vmuon_cj_flavour = 0;
  newtree->Branch("electron_ptrel",&velectron_ptrel);
  newtree->Branch("electron_ptratio",&velectron_ptratio);
  newtree->Branch("electron_cj_bjetdisc",&velectron_cj_bjetdisc);
  newtree->Branch("electron_mva_cf_v1",&velectron_mva_cf_v1);
  newtree->Branch("electron_mva_cf_v2",&velectron_mva_cf_v2);
  newtree->Branch("electron_mva_cf_v2p1",&velectron_mva_cf_v2p1);
  newtree->Branch("electron_mva_cf_v2p2",&velectron_mva_cf_v2p2);
  newtree->Branch("electron_mva_cf_ed_v2",&velectron_mva_cf_ed_v2);
  newtree->Branch("electron_mva_cf_ed_v2p1",&velectron_mva_cf_ed_v2p1);
  newtree->Branch("electron_mva_cf_ed_v2p2",&velectron_mva_cf_ed_v2p2);
  newtree->Branch("electron_mva_conv_v1",&velectron_mva_conv_v1);
  newtree->Branch("electron_mva_conv_v2",&velectron_mva_conv_v2);
  newtree->Branch("electron_mva_fake_v1",&velectron_mva_fake_v1);
  newtree->Branch("electron_mva_fake_v2",&velectron_mva_fake_v2);
  newtree->Branch("electron_mva_fakeHF_v2",&velectron_mva_fakeHF_v2);
  newtree->Branch("electron_mva_fakeLF_v2",&velectron_mva_fakeLF_v2);
  newtree->Branch("electron_mva_fakeTop_v2",&velectron_mva_fakeTop_v2);
  newtree->Branch("electron_cj_flavour",&velectron_cj_flavour);

  newtree->Branch("muon_ptrel",&vmuon_ptrel);
  newtree->Branch("muon_ptratio",&vmuon_ptratio);
  newtree->Branch("muon_cj_bjetdisc",&vmuon_cj_bjetdisc);
  newtree->Branch("muon_mva_fake",&vmuon_mva_fake);
  newtree->Branch("muon_cj_flavour",&vmuon_cj_flavour);

  newtree->Branch("SKWeight", &vSKWeight);

}

void SkimTree_DileptonBDT::executeEvent(){

  Event ev;
  ev.SetTrigger(*HLT_TriggerName);

  //=============================
  //==== If survived, fill tree
  //=============================

  velectron_ptrel->clear();
  velectron_ptratio->clear();
  velectron_cj_bjetdisc->clear();
  velectron_mva_cf_v1->clear();
  velectron_mva_cf_v2->clear();
  velectron_mva_cf_v2p1->clear();
  velectron_mva_cf_v2p2->clear();
  velectron_mva_cf_ed_v2->clear();
  velectron_mva_cf_ed_v2p1->clear();
  velectron_mva_cf_ed_v2p2->clear();
  velectron_mva_conv_v1->clear();
  velectron_mva_conv_v2->clear();
  velectron_mva_fake_v1->clear();
  velectron_mva_fake_v2->clear();
  velectron_mva_fakeHF_v2->clear();
  velectron_mva_fakeLF_v2->clear();
  velectron_mva_fakeTop_v2->clear();
  velectron_cj_flavour->clear();

  vmuon_mva_fake->clear();
  vmuon_ptrel->clear();
  vmuon_ptratio->clear();
  vmuon_cj_bjetdisc->clear();
  vmuon_cj_flavour->clear();



  vSKWeight=MCweight(true,true);
  
  std::vector<Muon>     AllmuonColl     = GetAllMuons();
  std::vector<Electron> AllelectronColl = GetAllElectrons();


  std::vector<Jet>    AK4_JetAllColl = GetJets("NoID", 10., 5.0);
  
  for(auto i: AllmuonColl){
    vmuon_mva_fake->push_back(GetBDTScoreMuon(i,AnalyzerCore::Fake,  "BDTGv2"));
    vmuon_ptratio->push_back(JetLeptonPtRatioLepAware(i,false));
    vmuon_ptrel->push_back(JetLeptonPtRelLepAware(i,true));
    
    float  JetDiscCJ = -999;
    int JetFlavourCJ=-999;
    int IdxMatchJet=-1;
    float mindR1=999.;
    
    for(unsigned int ij=0; ij<AK4_JetAllColl.size(); ij++){
      float dR1=i.DeltaR(AK4_JetAllColl.at(ij));
      if(dR1>0.4) continue;
      if(dR1<mindR1){ mindR1=dR1; IdxMatchJet=ij; }
    }
    if(IdxMatchJet!=-1)    {
      JetDiscCJ = AK4_JetAllColl.at(IdxMatchJet).GetTaggerResult(JetTagging::DeepJet);
      JetFlavourCJ = AK4_JetAllColl.at(IdxMatchJet).hadronFlavour();
      
    }
    else {
      JetDiscCJ=1.5;
      JetFlavourCJ=0;
    }
    vmuon_cj_bjetdisc->push_back(JetDiscCJ);
    vmuon_cj_flavour->push_back(JetFlavourCJ);
  }
  
  for(auto i: AllelectronColl){
    velectron_mva_fake_v1->push_back(GetBDTScoreElV1(i,AnalyzerCore::Fake,  "BDTGv1"));
    velectron_mva_cf_v1->push_back(GetBDTScoreElV1(i,AnalyzerCore::CF,  "BDTGv1"));
    velectron_mva_conv_v1->push_back(GetBDTScoreElV1(i,AnalyzerCore::Conv,  "BDTGv1"));

    velectron_mva_fake_v2->push_back(GetBDTScoreEl(i,AnalyzerCore::Fake,  "BDTGv2"));
    velectron_mva_fakeHF_v2->push_back(GetBDTScoreEl(i,AnalyzerCore::Fake,  "BDTGv2_HF"));
    velectron_mva_fakeLF_v2->push_back(GetBDTScoreEl(i,AnalyzerCore::Fake,  "BDTGv2_LF"));
    velectron_mva_fakeTop_v2->push_back(GetBDTScoreEl(i,AnalyzerCore::Fake,  "BDTGv2_Top"));
    velectron_mva_cf_v2->push_back(GetBDTScoreEl(i,AnalyzerCore::CF,  "BDTGv2"));
    velectron_mva_cf_v2p1->push_back(GetBDTScoreEl(i,AnalyzerCore::CF,  "BDTGv2p1"));
    velectron_mva_cf_v2p2->push_back(GetBDTScoreEl(i,AnalyzerCore::CF,  "BDTGv2p2"));
    velectron_mva_cf_ed_v2->push_back(GetBDTScoreEl_EtaDependant(i,AnalyzerCore::CF,  "BDTGv2"));
    velectron_mva_cf_ed_v2p1->push_back(GetBDTScoreEl_EtaDependant(i,AnalyzerCore::CF,  "BDTGv2p1"));
    velectron_mva_cf_ed_v2p2->push_back(GetBDTScoreEl_EtaDependant(i,AnalyzerCore::CF,  "BDTGv2p2"));
    velectron_mva_conv_v2->push_back(GetBDTScoreEl(i,AnalyzerCore::Conv,  "BDTGv2"));
    velectron_ptratio->push_back(JetLeptonPtRatioLepAware(i,false));
    velectron_ptrel->push_back(JetLeptonPtRelLepAware(i,true));

    float  JetDiscCJ = -999;
    int  JetFlavourCJ = -999;

    int IdxMatchJet=-1;
    float mindR1=999.;

    for(unsigned int ij=0; ij<AK4_JetAllColl.size(); ij++){
      float dR1=i.DeltaR(AK4_JetAllColl.at(ij));
      if(dR1>0.4) continue;
      if(dR1<mindR1){ mindR1=dR1; IdxMatchJet=ij; }
    }
    if(IdxMatchJet!=-1) {
      JetDiscCJ = AK4_JetAllColl.at(IdxMatchJet).GetTaggerResult(JetTagging::DeepJet);
      JetFlavourCJ  = AK4_JetAllColl.at(IdxMatchJet).hadronFlavour();

    }
    else {
      JetDiscCJ=1.5;
      JetDiscCJ=0;

    }
    velectron_cj_bjetdisc->push_back(JetDiscCJ);
    velectron_cj_flavour->push_back(JetFlavourCJ);
  }



  if( ev.PassTrigger(double_triggers) ){
    newtree->Fill();
    return;
  }

  vector<Muon> muons=GetAllMuons();
  std::sort(muons.begin(),muons.end(),PtComparing);
  vector<Electron> electrons=GetAllElectrons();
  std::sort(electrons.begin(),electrons.end(),PtComparing);
  int nmuon=muons.size();
  int nelectron=electrons.size();
  if(ev.PassTrigger(single_muon_triggers)){
    for(int i=0;i<nmuon;i++){
      for(int j=i+1;j<nmuon;j++){
        if(muons.at(i).Pt()<20) continue;
        if(muons.at(j).Pt()<7) continue;
	if((muons.at(i)+muons.at(j)).M()<48) continue;
        if(newtree->Fill()<0) exit(EIO);
        return;
      }
    }
    for(int i=0;i<nmuon;i++){
      for(int j=0;j<nelectron;j++){
        if(muons.at(i).Pt()<20) continue;
        if(electrons.at(j).Pt()<7) continue;
        if((muons.at(i)+electrons.at(j)).M()<48) continue;
        if(newtree->Fill()<0) exit(EIO);
        return;
      }
    }
  }
  if(ev.PassTrigger(single_electron_triggers)){
    for(int i=0;i<nelectron;i++){
      for(int j=i+1;j<nelectron;j++){
        if(electrons.at(i).Pt()<25) continue;
        if(electrons.at(j).Pt()<7) continue;
        if((electrons.at(i)+electrons.at(j)).M()<48) continue;
        if(newtree->Fill()<0) exit(EIO);
        return;
      }
    }
    for(int i=0;i<nelectron;i++){
      for(int j=0;j<nmuon;j++){
        if(electrons.at(i).Pt()<25) continue;
        if(muons.at(j).Pt()<7) continue;
        if((electrons.at(i)+muons.at(j)).M()<48) continue;
        if(newtree->Fill()<0) exit(EIO);
        return;
      }
    }
  }


}

void SkimTree_DileptonBDT::executeEventFromParameter(AnalyzerParameter param){

}

SkimTree_DileptonBDT::SkimTree_DileptonBDT(){

  newtree = NULL;

}

SkimTree_DileptonBDT::~SkimTree_DileptonBDT(){

}

void SkimTree_DileptonBDT::WriteHist(){

  outfile->mkdir("recoTree");
  outfile->cd("recoTree");
  newtree->Write();
  outfile->cd();

}
