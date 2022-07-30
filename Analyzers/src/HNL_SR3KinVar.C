#include "HNL_SR3KinVar.h"

void HNL_SR3KinVar::initializeAnalyzer(){

   for(unsigned int i=0; i<Userflags.size(); i++){
   }
   
  DblMuon_Channel=false, DblEG_Channel=false, MuonEG_Channel=false;
  if     (DataStream.Contains("DoubleMuon")) DblMuon_Channel=true;
  else if(DataStream.Contains("MuonEG"))     MuonEG_Channel =true;
  else if(DataStream.Contains("DoubleEG"))   DblEG_Channel=true;
  else if(DataYear==2018 and DataStream.Contains("EGamma")) DblEG_Channel=true;
  


  if(GetEraShort()=="2016a"){
    TrigList_DblMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v", "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v"};
    TrigList_DblEG = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"};
    TrigList_MuEG  = {"HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v", "HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v"};
  }
  else if(GetEraShort()=="2016b"){
    TrigList_DblMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v", "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v", "HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v"};
    TrigList_DblEG = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"};
    TrigList_MuEG  = {"HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v", "HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"};
  }
  else if(DataYear==2017){
    TrigList_DblMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v", "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v"};
    TrigList_DblEG = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v"};
    TrigList_MuEG  = {"HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v", "HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v"};
  }
  else if(DataYear==2018){
    TrigList_DblMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v"};
    TrigList_DblEG = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v"};
    TrigList_MuEG  = {"HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v", "HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v"};
  }


  //Set up the tagger map only for the param settings to be used.
  vector<JetTagging::Parameters> jtps;
  jtps.push_back( JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets) );
  mcCorr->SetJetTaggingParameters(jtps);

  InitializeTreeVars();
  tree_mm->Branch("Nj", &Nj, "Nj/I");                   tree_ee->Branch("Nj", &Nj, "Nj/I");                   tree_em->Branch("Nj", &Nj, "Nj/I");
  tree_mm->Branch("Nvbfj", &Nvbfj, "Nvbfj/I");                   tree_ee->Branch("Nvbfj", &Nvbfj, "Nvbfj/I");                   tree_em->Branch("Nvbfj", &Nvbfj, "Nvbfj/I");
  tree_mm->Branch("Ptl1", &Ptl1, "Ptl1/F");             tree_ee->Branch("Ptl1", &Ptl1, "Ptl1/F");             tree_em->Branch("Ptl1", &Ptl1, "Ptl1/F");
  tree_mm->Branch("Ptl2", &Ptl2, "Ptl2/F");             tree_ee->Branch("Ptl2", &Ptl2, "Ptl2/F");             tree_em->Branch("Ptl2", &Ptl2, "Ptl2/F");
  tree_mm->Branch("Ptj1", &Ptj1, "Ptj1/F");             tree_ee->Branch("Ptj1", &Ptj1, "Ptj1/F");            tree_em->Branch("Ptj1", &Ptj1, "Ptj1/F");
  tree_mm->Branch("Ptj2", &Ptj2, "Ptj2/F");             tree_ee->Branch("Ptj2", &Ptj2, "Ptj2/F");            tree_em->Branch("Ptj2", &Ptj2, "Ptj2/F");
  tree_mm->Branch("Ptj3", &Ptj3, "Ptj3/F");             tree_ee->Branch("Ptj3", &Ptj3, "Ptj3/F");            tree_em->Branch("Ptj3", &Ptj3, "Ptj3/F");
  tree_mm->Branch("MET", &MET, "MET/F");                tree_ee->Branch("MET", &MET, "MET/F");            tree_em->Branch("MET", &MET, "MET/F");
  tree_mm->Branch("MET2ST", &MET2ST, "MET2ST/F");       tree_ee->Branch("MET2ST", &MET2ST, "MET2ST/F");            tree_em->Branch("MET2ST", &MET2ST, "MET2ST/F");
  tree_mm->Branch("HT", &HT, "HT/F");                   tree_ee->Branch("HT", &HT, "HT/F");            tree_em->Branch("HT", &HT, "HT/F");
  tree_mm->Branch("LT", &LT, "LT/F");                   tree_ee->Branch("LT", &LT, "LT/F");            tree_em->Branch("LT", &LT, "LT/F");
  tree_mm->Branch("HTLT", &HTLT, "HTLT/F");             tree_ee->Branch("HTLT", &HTLT, "HTLT/F");            tree_em->Branch("HTLT", &HTLT, "HTLT/F");
  tree_mm->Branch("HTLT1", &HTLT1, "HTLT1/F");          tree_ee->Branch("HTLT1", &HTLT1, "HTLT1/F");            tree_em->Branch("HTLT1", &HTLT1, "HTLT1/F");
  tree_mm->Branch("HTLT2", &HTLT2, "HTLT2/F");          tree_ee->Branch("HTLT2", &HTLT2, "HTLT2/F");            tree_em->Branch("HTLT2", &HTLT2, "HTLT2/F");
  tree_mm->Branch("MET2HT", &MET2HT, "MET2HT/F");       tree_ee->Branch("MET2HT", &MET2HT, "MET2HT/F");            tree_em->Branch("MET2HT", &MET2HT, "MET2HT/F");
  tree_mm->Branch("dEtall", &dEtall, "dEtall/F");       tree_ee->Branch("dEtall", &dEtall, "dEtall/F");            tree_em->Branch("dEtall", &dEtall, "dEtall/F");
  tree_mm->Branch("dRll", &dRll, "dRll/F");             tree_ee->Branch("dRll", &dRll, "dRll/F");            tree_em->Branch("dRll", &dRll, "dRll/F");
  tree_mm->Branch("dRjj12", &dRjj12, "dRjj12/F");       tree_ee->Branch("dRjj12", &dRjj12, "dRjj12/F");            tree_em->Branch("dRjj12", &dRjj12, "dRjj12/F");
  tree_mm->Branch("dRjj23", &dRjj23, "dRjj23/F");       tree_ee->Branch("dRjj23", &dRjj23, "dRjj23/F");            tree_em->Branch("dRjj23", &dRjj23, "dRjj23/F");
  tree_mm->Branch("dRjj13", &dRjj13, "dRjj13/F");       tree_ee->Branch("dRjj13", &dRjj13, "dRjj13/F");            tree_em->Branch("dRjj13", &dRjj13, "dRjj13/F");
  tree_mm->Branch("dRlj11", &dRlj11, "dRlj11/F");       tree_ee->Branch("dRlj11", &dRlj11, "dRlj11/F");            tree_em->Branch("dRlj11", &dRlj11, "dRlj11/F");
  tree_mm->Branch("dRlj12", &dRlj12, "dRlj12/F");       tree_ee->Branch("dRlj12", &dRlj12, "dRlj12/F");            tree_em->Branch("dRlj12", &dRlj12, "dRlj12/F");
  tree_mm->Branch("dRlj13", &dRlj13, "dRlj13/F");       tree_ee->Branch("dRlj13", &dRlj13, "dRlj13/F");            tree_em->Branch("dRlj13", &dRlj13, "dRlj13/F");
  tree_mm->Branch("dRlj21", &dRlj21, "dRlj21/F");       tree_ee->Branch("dRlj21", &dRlj21, "dRlj21/F");            tree_em->Branch("dRlj21", &dRlj21, "dRlj21/F");
  tree_mm->Branch("dRlj22", &dRlj22, "dRlj22/F");       tree_ee->Branch("dRlj22", &dRlj22, "dRlj22/F");            tree_em->Branch("dRlj22", &dRlj22, "dRlj22/F");
  tree_mm->Branch("dRlj23", &dRlj23, "dRlj23/F");       tree_ee->Branch("dRlj23", &dRlj23, "dRlj23/F");            tree_em->Branch("dRlj23", &dRlj23, "dRlj23/F");
  tree_mm->Branch("MSSSF", &MSSSF, "MSSSF/F");          tree_ee->Branch("MSSSF", &MSSSF, "MSSSF/F");            tree_em->Branch("MSSSF", &MSSSF, "MSSSF/F");
  tree_mm->Branch("Mlj11", &Mlj11, "Mlj11/F");          tree_ee->Branch("Mlj11", &Mlj11, "Mlj11/F");            tree_em->Branch("Mlj11", &Mlj11, "Mlj11/F");
  tree_mm->Branch("Mlj12", &Mlj12, "Mlj12/F");          tree_ee->Branch("Mlj12", &Mlj12, "Mlj12/F");            tree_em->Branch("Mlj12", &Mlj12, "Mlj12/F");
  tree_mm->Branch("Mlj13", &Mlj13, "Mlj13/F");          tree_ee->Branch("Mlj13", &Mlj13, "Mlj13/F");            tree_em->Branch("Mlj13", &Mlj13, "Mlj13/F");
  tree_mm->Branch("Mlj21", &Mlj21, "Mlj21/F");          tree_ee->Branch("Mlj21", &Mlj21, "Mlj21/F");            tree_em->Branch("Mlj21", &Mlj21, "Mlj21/F");
  tree_mm->Branch("Mlj22", &Mlj22, "Mlj22/F");          tree_ee->Branch("Mlj22", &Mlj22, "Mlj22/F");            tree_em->Branch("Mlj22", &Mlj22, "Mlj22/F");
  tree_mm->Branch("Mlj23", &Mlj23, "Mlj23/F");          tree_ee->Branch("Mlj23", &Mlj23, "Mlj23/F");            tree_em->Branch("Mlj23", &Mlj23, "Mlj23/F");
  tree_mm->Branch("MTvl1", &MTvl1, "MTvl1/F");          tree_ee->Branch("MTvl1", &MTvl1, "MTvl1/F");            tree_em->Branch("MTvl1", &MTvl1, "MTvl1/F");
  tree_mm->Branch("MTvl2", &MTvl2, "MTvl2/F");          tree_ee->Branch("MTvl2", &MTvl2, "MTvl2/F");            tree_em->Branch("MTvl2", &MTvl2, "MTvl2/F");
  tree_mm->Branch("Mllj1", &Mllj1, "Mllj1/F");          tree_ee->Branch("Mllj1", &Mllj1, "Mllj1/F");            tree_em->Branch("Mllj1", &Mllj1, "Mllj1/F");
  tree_mm->Branch("Mllj2", &Mllj2, "Mllj2/F");          tree_ee->Branch("Mllj2", &Mllj2, "Mllj2/F");            tree_em->Branch("Mllj2", &Mllj2, "Mllj2/F");
  tree_mm->Branch("Mllj3", &Mllj3, "Mllj3/F");          tree_ee->Branch("Mllj3", &Mllj3, "Mllj3/F");            tree_em->Branch("Mllj3", &Mllj3, "Mllj3/F");
  tree_mm->Branch("Mllj4", &Mllj4, "Mllj4/F");          tree_ee->Branch("Mllj4", &Mllj4, "Mllj4/F");            tree_em->Branch("Mllj4", &Mllj4, "Mllj4/F");
  tree_mm->Branch("Mlljj12", &Mlljj12, "Mlljj12/F");    tree_ee->Branch("Mlljj12", &Mlljj12, "Mlljj12/F");            tree_em->Branch("Mlljj12", &Mlljj12, "Mlljj12/F");
  tree_mm->Branch("Mlljj13", &Mlljj13, "Mlljj13/F");    tree_ee->Branch("Mlljj13", &Mlljj13, "Mlljj13/F");            tree_em->Branch("Mlljj13", &Mlljj13, "Mlljj13/F");
  tree_mm->Branch("Mlljj14", &Mlljj14, "Mlljj14/F");    tree_ee->Branch("Mlljj14", &Mlljj14, "Mlljj14/F");            tree_em->Branch("Mlljj14", &Mlljj14, "Mlljj14/F");
  tree_mm->Branch("Mlljj23", &Mlljj23, "Mlljj23/F");    tree_ee->Branch("Mlljj23", &Mlljj23, "Mlljj23/F");            tree_em->Branch("Mlljj23", &Mlljj23, "Mlljj23/F");
  tree_mm->Branch("Mlljj24", &Mlljj24, "Mlljj24/F");    tree_ee->Branch("Mlljj24", &Mlljj24, "Mlljj24/F");            tree_em->Branch("Mlljj24", &Mlljj24, "Mlljj24/F");
  tree_mm->Branch("Mlljj34", &Mlljj34, "Mlljj34/F");    tree_ee->Branch("Mlljj34", &Mlljj34, "Mlljj34/F");            tree_em->Branch("Mlljj34", &Mlljj34, "Mlljj34/F");
  tree_mm->Branch("Mljj112", &Mljj112, "Mljj112/F");    tree_ee->Branch("Mljj112", &Mljj112, "Mljj112/F");            tree_em->Branch("Mljj112", &Mljj112, "Mljj112/F");
  tree_mm->Branch("Mljj113", &Mljj113, "Mljj113/F");    tree_ee->Branch("Mljj113", &Mljj113, "Mljj113/F");            tree_em->Branch("Mljj113", &Mljj113, "Mljj113/F");
  tree_mm->Branch("Mljj114", &Mljj114, "Mljj114/F");    tree_ee->Branch("Mljj114", &Mljj114, "Mljj114/F");            tree_em->Branch("Mljj114", &Mljj114, "Mljj114/F");
  tree_mm->Branch("Mljj123", &Mljj123, "Mljj123/F");    tree_ee->Branch("Mljj123", &Mljj123, "Mljj123/F");            tree_em->Branch("Mljj123", &Mljj123, "Mljj123/F");
  tree_mm->Branch("Mljj124", &Mljj124, "Mljj124/F");    tree_ee->Branch("Mljj124", &Mljj124, "Mljj124/F");            tree_em->Branch("Mljj124", &Mljj124, "Mljj124/F");
  tree_mm->Branch("Mljj134", &Mljj134, "Mljj134/F");    tree_ee->Branch("Mljj134", &Mljj134, "Mljj134/F");            tree_em->Branch("Mljj134", &Mljj134, "Mljj134/F");
  tree_mm->Branch("Mljj212", &Mljj212, "Mljj212/F");    tree_ee->Branch("Mljj212", &Mljj212, "Mljj212/F");            tree_em->Branch("Mljj212", &Mljj212, "Mljj212/F");
  tree_mm->Branch("Mljj213", &Mljj213, "Mljj213/F");    tree_ee->Branch("Mljj213", &Mljj213, "Mljj213/F");            tree_em->Branch("Mljj213", &Mljj213, "Mljj213/F");
  tree_mm->Branch("Mljj214", &Mljj214, "Mljj214/F");    tree_ee->Branch("Mljj214", &Mljj214, "Mljj214/F");            tree_em->Branch("Mljj214", &Mljj214, "Mljj214/F");
  tree_mm->Branch("Mljj223", &Mljj223, "Mljj223/F");    tree_ee->Branch("Mljj223", &Mljj223, "Mljj223/F");            tree_em->Branch("Mljj223", &Mljj223, "Mljj223/F");
  tree_mm->Branch("Mljj224", &Mljj224, "Mljj224/F");    tree_ee->Branch("Mljj224", &Mljj224, "Mljj224/F");            tree_em->Branch("Mljj224", &Mljj224, "Mljj224/F");
  tree_mm->Branch("Mljj234", &Mljj234, "Mljj234/F");    tree_ee->Branch("Mljj234", &Mljj234, "Mljj234/F");            tree_em->Branch("Mljj234", &Mljj234, "Mljj234/F");
  tree_mm->Branch("Mjj12", &Mjj12, "Mjj12/F");          tree_ee->Branch("Mjj12", &Mjj12, "Mjj12/F");            tree_em->Branch("Mjj12", &Mjj12, "Mjj12/F");
  tree_mm->Branch("Mjj13", &Mjj13, "Mjj13/F");          tree_ee->Branch("Mjj13", &Mjj13, "Mjj13/F");            tree_em->Branch("Mjj13", &Mjj13, "Mjj13/F");
  tree_mm->Branch("Mjj14", &Mjj14, "Mjj14/F");          tree_ee->Branch("Mjj14", &Mjj14, "Mjj14/F");            tree_em->Branch("Mjj14", &Mjj14, "Mjj14/F");
  tree_mm->Branch("Mjj23", &Mjj23, "Mjj23/F");          tree_ee->Branch("Mjj23", &Mjj23, "Mjj23/F");            tree_em->Branch("Mjj23", &Mjj23, "Mjj23/F");
  tree_mm->Branch("Mjj24", &Mjj24, "Mjj24/F");          tree_ee->Branch("Mjj24", &Mjj24, "Mjj24/F");            tree_em->Branch("Mjj24", &Mjj24, "Mjj24/F");
  tree_mm->Branch("Mjj34", &Mjj34, "Mjj34/F");          tree_ee->Branch("Mjj34", &Mjj34, "Mjj34/F");            tree_em->Branch("Mjj34", &Mjj34, "Mjj34/F");
  tree_mm->Branch("M_W2_jj", &M_W2_jj, "M_W2_jj/F");    tree_ee->Branch("M_W2_jj", &M_W2_jj, "M_W2_jj/F");     tree_em->Branch("M_W2_jj", &M_W2_jj, "M_W2_jj/F");    
  tree_mm->Branch("M_W1_lljj", &M_W1_lljj, "M_W1_lljj/F");    tree_ee->Branch("M_W1_lljj", &M_W1_lljj, "M_W1_lljj/F");    tree_em->Branch("M_W1_lljj", &M_W1_lljj, "M_W1_lljj/F");    

  tree_mm->Branch("M_N1_l1jj", &M_N1_l1jj, "M_N1_l1jj/F");      tree_ee->Branch("M_N1_l1jj", &M_N1_l1jj, "M_N1_l1jj/F");      tree_em->Branch("M_N1_l1jj", &M_N1_l1jj, "M_N1_l1jj/F");    

  tree_mm->Branch("M_N2_l2jj", &M_N2_l2jj, "M_N2_l2jj/F");      tree_ee->Branch("M_N2_l2jj", &M_N2_l2jj, "M_N2_l2jj/F");      tree_em->Branch("M_N2_l2jj", &M_N2_l2jj, "M_N2_l2jj/F");    

  tree_mm->Branch("w_tot", &w_tot, "w_tot/F");          tree_ee->Branch("w_tot", &w_tot, "w_tot/F");



  outfile->cd();

}


void HNL_SR3KinVar::executeEvent(){

  Event ev = GetEvent();
  float weight = 1., w_GenNorm=1., w_PU=1.;
  if(!IsDATA){
    w_GenNorm = MCweight(true,true)*GetKFactor()*ev.GetTriggerLumi("Full");
    w_PU      = GetPileUpWeight(nPileUp, 0);
    weight *= w_GenNorm  * w_PU;
  }
  FillHist("CutFlow", 0., weight, 20, 0., 20.);

  bool PassTrig=false;
  if     (!IsDATA || DblMuon_Channel) PassTrig = ev.PassTrigger(TrigList_DblMu);
  //else if(DblEG_Channel) PassTrig = ev.PassTrigger(TrigList_DblEG);
  //else if(MuonEG_Channel) PassTrig = ev.PassTrigger(TrigList_MuEG);

  if(!PassTrig) return;

  if(!PassMETFilter()) return;

  TString IDSSLabel = SS2l? "SS":"";
  TString MuTID = "HNTightV2", MuLID = "HNLooseV1", MuVID="HNVeto2016";
  TString ElTID = "HNTightV2", ElLID = "HNLooseV4", ElVID = "HNVeto2016";  
  
  
  //std::vector<Electron>   myelectrons_js = GetElectrons(this_AllElectrons, "HNTight_17028", 10., 2.5);
  //  #std::vector<Muon>       mymuons_js     = GetMuons    (this_AllMuons,     "HNTight_17028", 10., 2.4);


  std::vector<Electron>   electronTightColl  = GetElectrons( ElTID, 10., 2.5);
  std::vector<Muon>       muonTightColl      = GetMuons    (   MuTID, 10., 2.4);


  std::vector<Electron>   electronVetoColl  = GetElectrons( ElVID, 10., 2.5);
  std::vector<Muon>       muonsVetoColl     = GetMuons    (   MuVID, 5., 2.4);

  std::vector<Tau>        mytaus       = GetTaus("HNVeto",20., 2.3);

  std::vector<FatJet>   fatjets_tmp  = GetFatJets("tight", 200., 5);
  std::vector<Jet>      jets_tmp     = GetJets("tight", 15., 5);

  std::vector<FatJet> fatjetColl        = GetAK8Jets(fatjets_tmp, 200., 2.7, true,  1., true, -999, true, 40., 130., electronVetoColl, muonsVetoColl);
  std::vector<Jet>    jetColl              = GetAK4Jets(jets_tmp,       20., 2.7, true,  0.4,0.8,"loose",        electronVetoColl, muonsVetoColl,fatjetColl);
  std::vector<Jet>    jetVBFColl          = GetAK4Jets(jets_tmp,       30., 4.7, true,  0.4,0.8,"loose",   electronVetoColl, muonsVetoColl,fatjetColl);



  int  NBJets_medium      =  GetNBJets2a("tight","Medium");

  //vector<Jet> bjetNoVetoColl = SelBJets(jetNoVetoColl, param_jets);

  Particle vMET_T1xy = GetvMET("T1xyCorr");

  bool EventCand = false;
  
  if ((NBJets_medium==0) && SameCharge(muonTightColl) && muonsVetoColl.size()==2 && electronVetoColl.size()==0&&mytaus.size()==0){
    if (GetLLMass(muonTightColl) > 10.){
      if (fatjetColl.size() ==0) {
	
	if(!PassVBFInitial(jetVBFColl)) {
	  
	  EventCand=true;
	  
	}
	
      }
      
    }
    
  }

  if(!EventCand) return;

  float w_Prefire = 1., sf_Trig=1.;
  float sf_MuID = 1., sf_ElReco = 1., sf_ElID = 1., sf_BTag = 1.;
  if((!IsDATA) and EventCand){
    sf_MuID   = 1.;
    sf_ElReco = 1.;
    sf_ElID   = 1.;
    sf_BTag   = 1.;
    w_Prefire = GetPrefireWeight(0);
  }
  weight *= w_Prefire * sf_Trig;
  weight *= sf_MuID * sf_ElReco * sf_ElID * sf_BTag;

 
  std::vector<Lepton *> leps  = MakeLeptonPointerVector(muonTightColl,electronTightColl);

  MakeTreeSS2L(leps, jetColl, jetVBFColl, vMET_T1xy, weight, "");
    

}

void HNL_SR3KinVar::MakeTreeSS2L(vector<Lepton *>  LepTColl, 
				 vector<Jet>& JetColl, 
				 vector<Jet>& JetVBFColl, 
				 Particle& vMET, float weight, TString Label)
{

  
  
  if(!SameCharge(LepTColl)) return;
  

  if(LepTColl[0]->LeptonFlavour()==Lepton::MUON && LepTColl[1]->LeptonFlavour()==Lepton::MUON){

    // MM events
    
    if(!(LepTColl[0]->Pt()>20 && LepTColl[1]->Pt()>10)) return;

    float Mll = GetLLMass(LepTColl);

    InitializeTreeVars();

    Nj      = JetColl.size();
    Nvbfj   = JetVBFColl.size();
    Ptl1    = LepTColl[0]->Pt();
    Ptl2    = LepTColl.at(1)->Pt();
    LT      = GetLT(LepTColl);
    Ptj1    =  JetColl.size()<1? -1.: JetColl.at(0).Pt();
    Ptj2    =  JetColl.size()<2? -1.:JetColl.at(1).Pt();
    Ptj3    =  JetColl.size()<3? -1.:JetColl.at(2).Pt();
    MET     = vMET.Pt();
    
    dEtall  = abs(LepTColl.at(0)->Eta()-LepTColl.at(1)->Eta());
    dRll    = LepTColl.at(0)->DeltaR(*LepTColl.at(1));
    dRjj12  =  JetColl.size()<2? -1.:JetColl.at(0).DeltaR(JetColl.at(1));
    dRjj23  =  JetColl.size()<3? -1.:JetColl.at(1).DeltaR(JetColl.at(2));
    dRjj13  =  JetColl.size()<3? -1.:JetColl.at(0).DeltaR(JetColl.at(2));
    dRlj11  =  JetColl.size()<1? -1.:LepTColl.at(0)->DeltaR(JetColl.at(0));
    dRlj12  =  JetColl.size()<2? -1.:LepTColl.at(0)->DeltaR(JetColl.at(1));
    dRlj13  =  JetColl.size()<3? -1.:LepTColl.at(0)->DeltaR(JetColl.at(2));
    dRlj21  =  JetColl.size()<1? -1.:LepTColl.at(1)->DeltaR(JetColl.at(0));
    dRlj22  =  JetColl.size()<2? -1.:LepTColl.at(1)->DeltaR(JetColl.at(1));
    dRlj23  =  JetColl.size()<3? -1.:LepTColl.at(1)->DeltaR(JetColl.at(2));

    MSSSF   = Mll;
    Mlj11   =  JetColl.size()<1? -1.:(*LepTColl.at(0)+JetColl.at(0)).M();
    Mlj12   =  JetColl.size()<2? -1.:(*LepTColl.at(0)+JetColl.at(1)).M();
    Mlj13   =  JetColl.size()<3? -1.:(*LepTColl.at(0)+JetColl.at(2)).M();
    Mlj21   =  JetColl.size()<1? -1.:(*LepTColl.at(1)+JetColl.at(0)).M();
    Mlj22   =  JetColl.size()<2? -1.:(*LepTColl.at(1)+JetColl.at(1)).M();
    Mlj23   =  JetColl.size()<3? -1.:(*LepTColl.at(1)+JetColl.at(2)).M();
    MTvl1   = MT(*LepTColl.at(0),vMET);
    MTvl2   = MT(*LepTColl.at(1),vMET);
    Mllj1   =  JetColl.size()<1? -1.:(*LepTColl.at(0)+*LepTColl.at(1)+JetColl.at(0)).M();
    Mllj2   =  JetColl.size()<2? -1.:(*LepTColl.at(0)+*LepTColl.at(1)+JetColl.at(1)).M();
    Mllj3   =  JetColl.size()<3? -1.:(*LepTColl.at(0)+*LepTColl.at(1)+JetColl.at(2)).M();
    Mllj4   = JetColl.size()<4? -1.:(*LepTColl.at(0)+*LepTColl.at(1)+JetColl.at(3)).M();
    Mlljj12 =  JetColl.size()<2? -1.:(*LepTColl.at(0)+*LepTColl.at(1)+JetColl.at(0)+JetColl.at(1)).M();
    Mlljj13 =  JetColl.size()<3? -1.:(*LepTColl.at(0)+*LepTColl.at(1)+JetColl.at(0)+JetColl.at(2)).M();
    Mlljj14 = JetColl.size()<4? -1.:(*LepTColl.at(0)+*LepTColl.at(1)+JetColl.at(0)+JetColl.at(3)).M();
    Mlljj23 =  JetColl.size()<3? -1.:(*LepTColl.at(0)+*LepTColl.at(1)+JetColl.at(1)+JetColl.at(2)).M();
    Mlljj24 = JetColl.size()<4? -1.:(*LepTColl.at(0)+*LepTColl.at(1)+JetColl.at(1)+JetColl.at(3)).M();
    Mlljj34 = JetColl.size()<4? -1.:(*LepTColl.at(0)+*LepTColl.at(1)+JetColl.at(2)+JetColl.at(3)).M();
    Mljj112 =  JetColl.size()<2? -2.:(*LepTColl.at(0)+JetColl.at(0)+JetColl.at(1)).M();
    Mljj113 =  JetColl.size()<3? -1.:(*LepTColl.at(0)+JetColl.at(0)+JetColl.at(2)).M();
    Mljj114 = JetColl.size()<4? -1.:(*LepTColl.at(0)+JetColl.at(0)+JetColl.at(3)).M();
    //return;
    Mljj123 =  JetColl.size()<3? -1.:(*LepTColl.at(0)+JetColl.at(1)+JetColl.at(2)).M();
    Mljj124 = JetColl.size()<4? -1.:(*LepTColl.at(0)+JetColl.at(1)+JetColl.at(3)).M();
    Mljj134 = JetColl.size()<4? -1.:(*LepTColl.at(0)+JetColl.at(2)+JetColl.at(3)).M();
    Mljj212 =  JetColl.size()<2? -1.:(*LepTColl.at(1)+JetColl.at(0)+JetColl.at(1)).M();
    Mljj213 =  JetColl.size()<3? -1.:(*LepTColl.at(1)+JetColl.at(0)+JetColl.at(2)).M();
    Mljj214 = JetColl.size()<4? -1.:(*LepTColl.at(1)+JetColl.at(0)+JetColl.at(3)).M();
    Mljj223 =  JetColl.size()<3? -1.:(*LepTColl.at(1)+JetColl.at(1)+JetColl.at(2)).M();
    Mljj224 = JetColl.size()<4? -1.:(*LepTColl.at(1)+JetColl.at(1)+JetColl.at(3)).M();
    Mljj234 = JetColl.size()<4? -1.:(*LepTColl.at(1)+JetColl.at(2)+JetColl.at(3)).M();
    Mjj12   =  JetColl.size()<2? -1.:(JetColl.at(0)+JetColl.at(1)).M();
    Mjj13   =  JetColl.size()<3? -1.:(JetColl.at(0)+JetColl.at(2)).M();
    Mjj14   = JetColl.size()<4? -1.:(JetColl.at(0)+JetColl.at(3)).M();
    Mjj23   =  JetColl.size()<3? -1.:(JetColl.at(1)+JetColl.at(2)).M();
    Mjj24   = JetColl.size()<4? -1.:(JetColl.at(1)+JetColl.at(3)).M();
    Mjj34   = JetColl.size()<4? -1.:(JetColl.at(2)+JetColl.at(3)).M();
    
    //Vars requiring complex algo.
    HT      = 0;
    for(unsigned int itj=0; itj<JetColl.size(); itj++){ HT+=JetColl.at(itj).Pt(); }
    
    HTLT=HT/LT;
    HTLT1=HT/LepTColl.at(0)->Pt();
    HTLT2=HT/LepTColl.at(1)->Pt();

    std::vector<FatJet> FatJetColl;

    double ST = GetST( LepTColl, JetColl, FatJetColl, vMET);
    
    MET2HT  = pow(MET,2.)/HT;
    MET2ST  = pow(MET,2.)/ST;


    float dijetmass_tmp=9999.;
    float dijetmass=99990000.;
    int m=-999;
    int n=-999;

    for(UInt_t emme=0; emme<JetColl.size(); emme++){
      for(UInt_t enne=1; enne<JetColl.size(); enne++) {

        dijetmass_tmp = (JetColl[emme]+JetColl[enne]).M();
        if(emme == enne) continue;

        if ( fabs(dijetmass_tmp-80.4) < fabs(dijetmass-80.4) ) {
          dijetmass = dijetmass_tmp;
          m = emme;
          n = enne;
        }
      }
    }
    
    M_W2_jj  =   JetColl.size() > 1 ? (JetColl[m] +  JetColl[n]).M() : -1;
    M_W1_lljj = JetColl.size() > 1 ? (JetColl[m] + JetColl[n]+*LepTColl.at(0)+*LepTColl.at(1)).M() : -1;
    M_N1_l1jj = JetColl.size() > 1 ? (JetColl[m] + JetColl[n]+*LepTColl.at(0)).M() : -1;
    M_N2_l2jj = JetColl.size() > 1 ? (JetColl[m] + JetColl[n]+*LepTColl.at(1)).M() : -1;

    w_tot    = !IsDATA? weight:-1.;
    tree_mm->Fill();
  }

}



void HNL_SR3KinVar::executeEventFromParameter(AnalyzerParameter param){

  
}


void HNL_SR3KinVar::InitializeTreeVars(){

  Nj=-1, Nvbfj=-1;
  Ptl1=-1, Ptl2=-1, Ptj1=-1, Ptj2=-1, Ptj3=-1, MET=-1, HTLT=-1, HTLT1=-1,HTLT2=-1,LT=-1,  HT=-1, MET2HT=-1, MET2ST=-1;
  dEtall=-1, dRll=-1, dRjj12=-1, dRjj23=-1, dRjj13=-1;
  dRlj11=-1, dRlj12=-1, dRlj13=-1, dRlj21=-1, dRlj22=-1, dRlj23=-1;
  MSSSF=-1, Mlj11=-1, Mlj12=-1, Mlj13=-1, Mlj21=-1, Mlj22=-1, Mlj23=-1;
  MTvl1=-1, MTvl2=-1, Mllj1=-1, Mllj2=-1, Mllj3=-1, Mllj4=-1;
  Mlljj12=-1, Mlljj13=-1, Mlljj14=-1, Mlljj23=-1, Mlljj24=-1, Mlljj34=-1;
  Mljj112=-1, Mljj113=-1, Mljj114=-1, Mljj123=-1, Mljj124=-1, Mljj134=-1;
  Mljj212=-1, Mljj213=-1, Mljj214=-1, Mljj223=-1, Mljj224=-1, Mljj234=-1;
  Mjj12=-1, Mjj13=-1, Mjj14=-1, Mjj23=-1, Mjj24=-1, Mjj34=-1;
  M_W2_jj=-1, M_W1_lljj=-1, M_N1_l1jj=-1, M_N2_l2jj=-1;

  w_tot=-1;

}



HNL_SR3KinVar::HNL_SR3KinVar(){

  tree_mm = new TTree("Tree_mm", "Tree_mm");
  tree_ee = new TTree("Tree_ee", "Tree_ee");
  tree_em = new TTree("Tree_em", "Tree_em");

}


HNL_SR3KinVar::~HNL_SR3KinVar(){

  delete tree_mm;
  delete tree_ee;
  delete tree_em;

}


void HNL_SR3KinVar::WriteHist(){

  AnalyzerCore::WriteHist();

  outfile->cd();
  tree_mm->Write();
  tree_ee->Write();
  tree_em->Write();
  outfile->cd();

}
