#include "KinVarSearch.h"

void KinVarSearch::initializeAnalyzer(){

  TriLep=false, TetraLep=false, SS2l=false, SystRun=false; 
  for(unsigned int i=0; i<Userflags.size(); i++){
    if(Userflags.at(i).Contains("SS2l"))   SS2l=true;
    if(Userflags.at(i).Contains("TriLep")) TriLep=true;
    if(Userflags.at(i).Contains("TetraLep")) TetraLep=true; 
    if(Userflags.at(i).Contains("SystRun")) SystRun=true; 
  }

  DblMu=false, DblEG=false, MuEG=false;
  if     (DataStream.Contains("DoubleMuon")) DblMu=true;
  else if(DataStream.Contains("MuonEG"))     MuEG =true;
  else if(DataStream.Contains("DoubleEG"))   DblEG=true;
  else if(DataYear==2018 and DataStream.Contains("EGamma")) DblEG=true;


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
  jtps.push_back( JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets) );
  mcCorr->SetJetTaggingParameters(jtps);

  InitializeTreeVars();
  tree_mm->Branch("Nj", &Nj, "Nj/I");                   tree_ee->Branch("Nj", &Nj, "Nj/I");
  tree_mm->Branch("Nb", &Nb, "Nb/I");                   tree_ee->Branch("Nb", &Nb, "Nb/I");
  tree_mm->Branch("Ptl1", &Ptl1, "Ptl1/F");             tree_ee->Branch("Ptl1", &Ptl1, "Ptl1/F");
  tree_mm->Branch("Ptl2", &Ptl2, "Ptl2/F");             tree_ee->Branch("Ptl2", &Ptl2, "Ptl2/F");
  tree_mm->Branch("Ptj1", &Ptj1, "Ptj1/F");             tree_ee->Branch("Ptj1", &Ptj1, "Ptj1/F");
  tree_mm->Branch("Ptj2", &Ptj2, "Ptj2/F");             tree_ee->Branch("Ptj2", &Ptj2, "Ptj2/F");
  tree_mm->Branch("Ptj3", &Ptj3, "Ptj3/F");             tree_ee->Branch("Ptj3", &Ptj3, "Ptj3/F");
  tree_mm->Branch("MET", &MET, "MET/F");                tree_ee->Branch("MET", &MET, "MET/F");
  tree_mm->Branch("HT", &HT, "HT/F");                   tree_ee->Branch("HT", &HT, "HT/F");
  tree_mm->Branch("dRll", &dRll, "dRll/F");             tree_ee->Branch("dRll", &dRll, "dRll/F");
  tree_mm->Branch("dRlj11", &dRlj11, "dRlj11/F");       tree_ee->Branch("dRlj11", &dRlj11, "dRlj11/F");
  tree_mm->Branch("dRlj12", &dRlj12, "dRlj12/F");       tree_ee->Branch("dRlj12", &dRlj12, "dRlj12/F");
  tree_mm->Branch("dRlj13", &dRlj13, "dRlj13/F");       tree_ee->Branch("dRlj13", &dRlj13, "dRlj13/F");
  tree_mm->Branch("dRlj21", &dRlj21, "dRlj21/F");       tree_ee->Branch("dRlj21", &dRlj21, "dRlj21/F");
  tree_mm->Branch("dRlj22", &dRlj22, "dRlj22/F");       tree_ee->Branch("dRlj22", &dRlj22, "dRlj22/F");
  tree_mm->Branch("dRlj23", &dRlj23, "dRlj23/F");       tree_ee->Branch("dRlj23", &dRlj23, "dRlj23/F");
  tree_mm->Branch("dRlb11", &dRlb11, "dRlb11/F");       tree_ee->Branch("dRlb11", &dRlb11, "dRlb11/F");
  tree_mm->Branch("dRlb21", &dRlb21, "dRlb21/F");       tree_ee->Branch("dRlb21", &dRlb21, "dRlb21/F");
  tree_mm->Branch("dRlnb11", &dRlnb11, "dRlnb11/F");    tree_ee->Branch("dRlnb11", &dRlnb11, "dRlnb11/F");
  tree_mm->Branch("dRlnb21", &dRlnb21, "dRlnb21/F");    tree_ee->Branch("dRlnb21", &dRlnb21, "dRlnb21/F");
  tree_mm->Branch("MSSSF", &MSSSF, "MSSSF/F");          tree_ee->Branch("MSSSF", &MSSSF, "MSSSF/F");
  tree_mm->Branch("MTvl1", &MTvl1, "MTvl1/F");          tree_ee->Branch("MTvl1", &MTvl1, "MTvl1/F");
  tree_mm->Branch("MTllv", &MTllv, "MTllv/F");          tree_ee->Branch("MTllv", &MTllv, "MTllv/F");
  tree_mm->Branch("Ml2j1W_BkdTop", &Ml2j1W_BkdTop, "Ml2j1W_BkdTop/F");  tree_ee->Branch("Ml2j1W_BkdTop", &Ml2j1W_BkdTop, "Ml2j1W_BkdTop/F");
  tree_mm->Branch("Ml2W_BkdTop", &Ml2W_BkdTop, "Ml2W_BkdTop/F");        tree_ee->Branch("Ml2W_BkdTop", &Ml2W_BkdTop, "Ml2W_BkdTop/F");
  tree_mm->Branch("MTbl1v_BkdTop", &MTbl1v_BkdTop, "MTbl1v_BkdTop/F");  tree_ee->Branch("MTbl1v_BkdTop", &MTbl1v_BkdTop, "MTbl1v_BkdTop/F");
  tree_mm->Branch("Ml1v_BkdTop", &Ml1v_BkdTop, "Ml1v_BkdTop/F");        tree_ee->Branch("Ml1v_BkdTop", &Ml1v_BkdTop, "Ml1v_BkdTop/F");
  tree_mm->Branch("Mbl1v_BkdTop", &Mbl1v_BkdTop, "Mbl1v_BkdTop/F");     tree_ee->Branch("Mbl1v_BkdTop", &Mbl1v_BkdTop, "Mbl1v_BkdTop/F");
  tree_mm->Branch("MbllW_1jL", &MbllW_1jL, "MbllW_1jL/F"); tree_ee->Branch("MbllW_1jL", &MbllW_1jL, "MbllW_1jL/F");
  tree_mm->Branch("MllW_1jL", &MllW_1jL, "MllW_1jL/F");    tree_ee->Branch("MllW_1jL", &MllW_1jL, "MllW_1jL/F");
  tree_mm->Branch("Ml1W_1jL", &Ml1W_1jL, "Ml1W_1jL/F");    tree_ee->Branch("Ml1W_1jL", &Ml1W_1jL, "Ml1W_1jL/F");
  tree_mm->Branch("Ml2W_1jL", &Ml2W_1jL, "Ml2W_1jL/F");    tree_ee->Branch("Ml2W_1jL", &Ml2W_1jL, "Ml2W_1jL/F");
  tree_mm->Branch("MbllW_1jH", &MbllW_1jH, "MbllW_1jH/F"); tree_ee->Branch("MbllW_1jH", &MbllW_1jH, "MbllW_1jH/F");
  tree_mm->Branch("MllW_1jH", &MllW_1jH, "MllW_1jH/F");    tree_ee->Branch("MllW_1jH", &MllW_1jH, "MllW_1jH/F");
  tree_mm->Branch("Ml1W_1jH", &Ml1W_1jH, "Ml1W_1jH/F");    tree_ee->Branch("Ml1W_1jH", &Ml1W_1jH, "Ml1W_1jH/F");
  tree_mm->Branch("Ml2W_1jH", &Ml2W_1jH, "Ml2W_1jH/F");    tree_ee->Branch("Ml2W_1jH", &Ml2W_1jH, "Ml2W_1jH/F");
  tree_mm->Branch("MbllW_H", &MbllW_H, "MbllW_H/F");       tree_ee->Branch("MbllW_H", &MbllW_H, "MbllW_H/F");
  tree_mm->Branch("Ml1W_H", &Ml1W_H, "Ml1W_H/F");          tree_ee->Branch("Ml1W_H", &Ml1W_H, "Ml1W_H/F");
  tree_mm->Branch("Ml2W_H", &Ml2W_H, "Ml2W_H/F");          tree_ee->Branch("Ml2W_H", &Ml2W_H, "Ml2W_H/F");
  tree_mm->Branch("w_tot", &w_tot, "w_tot/F");             tree_ee->Branch("w_tot", &w_tot, "w_tot/F");


  outfile->cd();

}


void KinVarSearch::executeEvent(){


  Event ev = GetEvent();
  float weight = 1., w_GenNorm=1., w_BR=1., w_PU=1.;
  if(!IsDATA){
    w_GenNorm = MCweight()*ev.GetTriggerLumi("Full");
    w_BR      = GetBRWeight();
    w_PU      = GetPileUpWeight(nPileUp, 0);
    weight *= w_GenNorm * w_BR * w_PU;
  }
  FillHist("CutFlow", 0., weight, 20, 0., 20.);

  bool PassTrig=false;
  if(TetraLep or TriLep){
    if(!IsDATA) PassTrig = ev.PassTrigger(TrigList_MuEG) or ev.PassTrigger(TrigList_DblMu) or ev.PassTrigger(TrigList_DblEG);
    else{
      if     (MuEG)  PassTrig = ev.PassTrigger(TrigList_MuEG);
      else if(DblMu) PassTrig = (!ev.PassTrigger(TrigList_MuEG)) and ev.PassTrigger(TrigList_DblMu);
      else if(DblEG) PassTrig = (!(ev.PassTrigger(TrigList_MuEG) or ev.PassTrigger(TrigList_DblMu))) and ev.PassTrigger(DblEG);
    }
  }
  else if(SS2l){
    if(!IsDATA) PassTrig = ev.PassTrigger(TrigList_DblMu) or ev.PassTrigger(TrigList_DblEG);
    else{
      if     (DblMu) PassTrig = ev.PassTrigger(TrigList_DblMu);
      else if(DblEG) PassTrig = ev.PassTrigger(TrigList_DblEG);
    }
  }
  if(!PassTrig) return;
  FillHist("CutFlow", 1., weight, 20, 0., 20.);
  if(!PassMETFilter()) return;
  FillHist("CutFlow", 2., weight, 20, 0., 20.);

  bool PreCutPass=false;
  vector<Muon>     muonPreColl     = GetMuons("NOCUT", 5., 2.4);
  vector<Electron> electronPreColl = GetElectrons("NOCUT", 5., 2.5);
  sort(muonPreColl.begin(), muonPreColl.end(), PtComparing);
  sort(electronPreColl.begin(), electronPreColl.end(), PtComparing);
  if(TriLep and (muonPreColl.size()+electronPreColl.size())>2 ) PreCutPass=true;
  if(TetraLep and (muonPreColl.size()+electronPreColl.size())>3 ) PreCutPass=true;
  if(SS2l){
    int NPreMu=muonPreColl.size(), NPreEl=electronPreColl.size();
    if( (NPreMu+NPreEl)>2 ) PreCutPass=true;
    else if(NPreMu==2 and SumCharge(muonPreColl)!=0) PreCutPass=true;
    else if(NPreEl==2 and SumCharge(electronPreColl)!=0) PreCutPass=true;
  }
  if(!PreCutPass) return;


  TString IDSSLabel = SS2l? "SS":"";
  TString MuTID = "TopHNT", MuLID = "TopHNL", MuVID=MuLID;
  TString ElTID = "TopHNSST", ElLID = "TopHNSSL_"+GetEraShort(), ElVID = "TopHNL_"+GetEraShort();  
  vector<Muon>     muonTightColl     = SelectMuons(muonPreColl, MuTID, 10., 2.4);
  vector<Electron> electronTightColl = SelectElectrons(electronPreColl, ElTID, 15., 2.5);
  vector<Muon>     muonLooseColl     = SelectMuons(muonPreColl, MuLID, 10., 2.4);
  vector<Electron> electronLooseColl = SelectElectrons(electronPreColl, ElLID, 15., 2.5);
  vector<Muon>     muonVetoColl      = SelectMuons(muonPreColl, MuVID, 10., 2.4);
  vector<Electron> electronVetoColl  = SelectElectrons(electronPreColl, ElVID, 10., 2.5);


  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
  vector<Jet> jetNoVetoColl  = GetJets("tightLepVeto", 25., 2.4);
  sort(jetNoVetoColl.begin(), jetNoVetoColl.end(), PtComparing);
  vector<Jet> bjetNoVetoColl = SelBJets(jetNoVetoColl, param_jets);
  vector<Jet> jetColl  = JetsVetoLeptonInside(jetNoVetoColl, electronVetoColl, muonVetoColl, 0.4);
  vector<Jet> bjetColl = SelBJets(jetColl, param_jets);

  Particle vMET_T1xy = GetvMET("PUPPIMETT1xyCorr");


  bool EventCand = false;
  if(SS2l    ){ EventCand = (muonTightColl.size()+electronTightColl.size()) >1; }
  if(TriLep  ){ EventCand = (muonTightColl.size()+electronTightColl.size()) >2; }
  if(TetraLep){ EventCand = (muonTightColl.size()+electronTightColl.size()) >3; }

  float w_Prefire = 1., sf_Trig = 1.;
  float sf_MuID = 1., sf_ElReco = 1., sf_ElID = 1., sf_BTag = 1.;
  if((!IsDATA) and EventCand){
    sf_MuID   = GetMuonSF(muonTightColl, MuTID, "ID");
    sf_ElReco = GetElectronSF(electronLooseColl, "", "Reco");
    sf_ElID   = GetElectronSF(electronTightColl, ElTID, "ID");
    sf_BTag   = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets);
    //ElKey: DiElIso_HNTopID17SS DiElIso_HNTopIDSS  //MuKey: DiMuIso_HNTopID
    int NEl = electronTightColl.size(), NMu = muonTightColl.size();
    TString TrSFKey = NMu>1? "DiMuIso_HNTopID":NEl>1? "DiElIso_HNTopIDSS":"";
    bool ApplyTrSF = TrSFKey!="" && (SS2l or TriLep);
    sf_Trig   = ApplyTrSF? mcCorr->GetTriggerSF(electronTightColl, muonTightColl, TrSFKey, ""):1.;
    w_Prefire = GetPrefireWeight(0);
  }
  weight *= w_Prefire * sf_Trig;
  weight *= sf_MuID * sf_ElReco * sf_ElID * sf_BTag;

 
  if(SS2l){
    MakeTreeSS2L(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
                 jetColl, bjetColl, vMET_T1xy, weight, "");
  }

}

void KinVarSearch::MakeTreeSS2L(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                                vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                                vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{

  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  if( !( (NMuT==2 and NElT==0) or (NElT==2 and NMuT==0) ) ) return;
  if( !(NMuT==NMuL and NElT==NElL) ) return;
  if( !(NMuT==NMuV and NElT==NElV) ) return;
  if(NMuT==2){
    if(MuTColl.at(0).Charge()!=MuTColl.at(1).Charge()) return;
    if(!(MuTColl.at(0).Pt()>20 && MuTColl.at(1).Pt()>10)) return;
    float Mll = (MuTColl.at(0)+MuTColl.at(1)).M();
    if(Mll<4) return; 
    if(BJetColl.size()<1) return;
    if(JetColl.size() <3) return;
    if((JetColl.size()-BJetColl.size())==0) return;

    vector<Jet> BCandColl = BJetColl.size()>1? BJetColl:JetColl;
    vector<Jet> NonBJetColl = SelLightJets(JetColl, jtps.at(0));

    InitializeTreeVars();
    Nj      = JetColl.size();
    Nb      = min((Int_t) BJetColl.size(), (Int_t) 2);
    Ptl1    = MuTColl.at(0).Pt();
    Ptl2    = MuTColl.at(1).Pt();
    Ptj1    = JetColl.at(0).Pt();
    Ptj2    = JetColl.at(1).Pt();
    Ptj3    = JetColl.at(2).Pt();
    MET     = vMET.Pt();
    dRll    = MuTColl.at(0).DeltaR(MuTColl.at(1));
    dRlj11  = MuTColl.at(0).DeltaR(JetColl.at(0));
    dRlj12  = MuTColl.at(0).DeltaR(JetColl.at(1));
    dRlj13  = MuTColl.at(0).DeltaR(JetColl.at(2));
    dRlj21  = MuTColl.at(1).DeltaR(JetColl.at(0));
    dRlj22  = MuTColl.at(1).DeltaR(JetColl.at(1));
    dRlj23  = MuTColl.at(1).DeltaR(JetColl.at(2));
    dRlb11  = MuTColl.at(0).DeltaR(BJetColl.at(0));
    dRlb21  = MuTColl.at(1).DeltaR(BJetColl.at(0));
    dRlnb11 = MuTColl.at(0).DeltaR(NonBJetColl.at(0));
    dRlnb21 = MuTColl.at(1).DeltaR(NonBJetColl.at(0));
    MSSSF   = (MuTColl.at(0)+MuTColl.at(1)).M();
    MTvl1   = MT(MuTColl.at(0),vMET);
    MTllv   = MT(MuTColl.at(0)+MuTColl.at(1), vMET);

    //Vars requiring complex algo.
    HT      = 0;  for(unsigned int itj=0; itj<JetColl.size(); itj++){ HT+=JetColl.at(itj).Pt(); }


    int Idxj1W=-1, Idxj2W=-1; float bestmjjW=-1;
    for(unsigned int ij1=0; ij1<NonBJetColl.size(); ij1++){
    for(unsigned int ij2=ij1+1; ij2<NonBJetColl.size(); ij2++){
      float mjj = (NonBJetColl.at(ij1)+NonBJetColl.at(ij2)).M();
      if(bestmjjW<0){ bestmjjW = mjj; Idxj1W=ij1, Idxj2W=ij2; }
      else{ if(fabs(mjj-80.4)<fabs(bestmjjW-80.4)){ bestmjjW = mjj; Idxj1W=ij1, Idxj2W=ij2; } }
    }} 
    Ml2j1W_BkdTop = (MuTColl.at(1)+NonBJetColl.at(0)).M();
    Ml2W_BkdTop   = bestmjjW<0? Ml2j1W_BkdTop:(MuTColl.at(1)+NonBJetColl.at(Idxj1W)+NonBJetColl.at(Idxj2W)).M();
    MTbl1v_BkdTop = MT(BJetColl.at(0)+MuTColl.at(0),vMET);
    float Pzv1 = GetvPz(MuTColl.at(0), vMET, "+"); Particle vMET1; vMET1.SetXYZM(vMET.X(), vMET.Y(), Pzv1, 0);
    float Pzv2 = GetvPz(MuTColl.at(0), vMET, "-"); Particle vMET2; vMET2.SetXYZM(vMET.X(), vMET.Y(), Pzv2, 0);
    float Mblv1 = (BJetColl.at(0)+MuTColl.at(0)+vMET1).M(), Mblv2 = (BJetColl.at(0)+MuTColl.at(1)+vMET2).M();
    Particle vMET_CondMWt = fabs(Mblv1-172.5)<fabs(Mblv2-172.5)? vMET1:vMET2;
    Ml1v_BkdTop  = (MuTColl.at(0)+vMET_CondMWt).M();
    Mbl1v_BkdTop = (BJetColl.at(0)+MuTColl.at(0)+vMET_CondMWt).M();

   
    int Idxj1W_1jL=-1, Idxbt_1jL=-1; float BestSumDelta_L=-1; 
    for(unsigned int ib=0; ib<BCandColl.size(); ib++){
    for(unsigned int inb=0; inb<NonBJetColl.size(); inb++){
      if(BCandColl.at(ib).DeltaR(NonBJetColl.at(inb))<0.1) continue;
      float mllj = (MuTColl.at(0)+MuTColl.at(1)+NonBJetColl.at(inb)).M();
      float mbllj = (MuTColl.at(0)+MuTColl.at(1)+NonBJetColl.at(inb)+BCandColl.at(ib)).M();
      float SumDelta = fabs(mbllj-160)+fabs(mllj-75);
      if(BestSumDelta_L<0){ BestSumDelta_L=SumDelta; Idxj1W_1jL=inb; Idxbt_1jL=ib;}
      else{  
        if(SumDelta<BestSumDelta_L){ BestSumDelta_L=SumDelta; Idxj1W_1jL=inb; Idxbt_1jL=ib;}
      }
    }}
    MbllW_1jL = (MuTColl.at(0)+MuTColl.at(1)+NonBJetColl.at(Idxj1W_1jL)+BCandColl.at(Idxbt_1jL)).M();
    MllW_1jL  = (MuTColl.at(0)+MuTColl.at(1)+NonBJetColl.at(Idxj1W_1jL)).M();
    Ml1W_1jL  = (MuTColl.at(0)+NonBJetColl.at(Idxj1W_1jL)).M();
    Ml2W_1jL  = (MuTColl.at(1)+NonBJetColl.at(Idxj1W_1jL)).M();


    int Idxj1W_1jH=-1, Idxbt_1jH=-1; float BestDeltambllj=-1;
    for(unsigned int ib=0; ib<BCandColl.size(); ib++){
    for(unsigned int inb=0; inb<NonBJetColl.size(); inb++){
      if(BCandColl.at(ib).DeltaR(NonBJetColl.at(inb))<0.1) continue;
      float mbllj = (MuTColl.at(0)+MuTColl.at(1)+NonBJetColl.at(inb)+BCandColl.at(ib)).M();
      float Deltambllj = fabs(mbllj-130);
      if(BestDeltambllj<0){ BestDeltambllj = Deltambllj; Idxj1W_1jH=inb; Idxbt_1jH=ib;}
      else{  
        if(Deltambllj<BestDeltambllj){ BestDeltambllj = Deltambllj; Idxj1W_1jH=inb; Idxbt_1jH=ib;}
      }
    }}
    MbllW_1jH = (MuTColl.at(0)+MuTColl.at(1)+NonBJetColl.at(Idxj1W_1jH)+BCandColl.at(Idxbt_1jH)).M();
    MllW_1jH  = (MuTColl.at(0)+MuTColl.at(1)+NonBJetColl.at(Idxj1W_1jH)).M();
    Ml1W_1jH  = (MuTColl.at(0)+NonBJetColl.at(Idxj1W_1jH)).M();
    Ml2W_1jH  = (MuTColl.at(1)+NonBJetColl.at(Idxj1W_1jH)).M();


    int Idxj1W_H=-1, Idxj2W_H=-1, Idxbt_H=-1; float BestSumDelta_H=-1; 
    for(unsigned int ib=0; ib<BCandColl.size(); ib++){
    for(unsigned int inb1=0; inb1<NonBJetColl.size(); inb1++){
    for(unsigned int inb2=inb1+1; inb2<NonBJetColl.size(); inb2++){
      if(BCandColl.at(ib).DeltaR(NonBJetColl.at(inb1))<0.1) continue;
      if(BCandColl.at(ib).DeltaR(NonBJetColl.at(inb2))<0.1) continue;
      float mjj    = (NonBJetColl.at(inb1)+NonBJetColl.at(inb2)).M();
      float mblljj = (MuTColl.at(0)+MuTColl.at(1)+NonBJetColl.at(inb1)+NonBJetColl.at(inb2)+BCandColl.at(ib)).M();
      float SumDelta = fabs(mblljj-172.5)+fabs(mjj-80.4);
      if(BestSumDelta_H<0){ BestSumDelta_H=SumDelta; Idxj1W_H=inb1; Idxj2W_H=inb2; Idxbt_H=ib;}
      else{  
        if(SumDelta<BestSumDelta_H){ BestSumDelta_H=SumDelta; Idxj1W_H=inb1; Idxj2W_H=inb2; Idxbt_H=ib;}
      }
    }}}
    MbllW_H = BestSumDelta_H<0? -1.:(MuTColl.at(0)+MuTColl.at(1)+NonBJetColl.at(Idxj1W_H)+NonBJetColl.at(Idxj2W_H)+BCandColl.at(Idxbt_H)).M();
    Ml1W_H  = BestSumDelta_H<0? -1.:(MuTColl.at(0)+NonBJetColl.at(Idxj1W_H)+NonBJetColl.at(Idxj2W_H)).M();
    Ml2W_H  = BestSumDelta_H<0? -1.:(MuTColl.at(1)+NonBJetColl.at(Idxj1W_H)+NonBJetColl.at(Idxj2W_H)).M();

    w_tot    = !IsDATA? weight:-1.;

    tree_mm->Fill();
  }
  if(NElT==2){
    if(ElTColl.at(0).Charge()!=ElTColl.at(1).Charge()) return;
    if(!(ElTColl.at(0).Pt()>25 && ElTColl.at(1).Pt()>15)) return;
    float Mll = (ElTColl.at(0)+ElTColl.at(1)).M();
    if(BJetColl.size()<1) return;
    if(JetColl.size() <3) return;
    if(fabs(Mll-91.2)<10.) return;
    if((JetColl.size()-BJetColl.size())==0) return;

    vector<Jet> BCandColl = BJetColl.size()>1? BJetColl:JetColl;
    vector<Jet> NonBJetColl = SelLightJets(JetColl, jtps.at(0));

    InitializeTreeVars();
    Nj      = JetColl.size();
    Nb      = min((Int_t) BJetColl.size(), (Int_t) 2);
    Ptl1    = ElTColl.at(0).Pt();
    Ptl2    = ElTColl.at(1).Pt();
    Ptj1    = JetColl.at(0).Pt();
    Ptj2    = JetColl.at(1).Pt();
    Ptj3    = JetColl.at(2).Pt();
    MET     = vMET.Pt();
    dRll    = ElTColl.at(0).DeltaR(ElTColl.at(1));
    dRlj11  = ElTColl.at(0).DeltaR(JetColl.at(0));
    dRlj12  = ElTColl.at(0).DeltaR(JetColl.at(1));
    dRlj13  = ElTColl.at(0).DeltaR(JetColl.at(2));
    dRlj21  = ElTColl.at(1).DeltaR(JetColl.at(0));
    dRlj22  = ElTColl.at(1).DeltaR(JetColl.at(1));
    dRlj23  = ElTColl.at(1).DeltaR(JetColl.at(2));
    dRlb11  = ElTColl.at(0).DeltaR(BJetColl.at(0));
    dRlb21  = ElTColl.at(1).DeltaR(BJetColl.at(0));
    dRlnb11 = ElTColl.at(0).DeltaR(NonBJetColl.at(0));
    dRlnb21 = ElTColl.at(1).DeltaR(NonBJetColl.at(0));
    MSSSF   = (ElTColl.at(0)+ElTColl.at(1)).M();
    MTvl1   = MT(ElTColl.at(0),vMET);
    MTllv   = MT(ElTColl.at(0)+ElTColl.at(1), vMET);

    //Vars requiring complex algo.
    HT      = 0;  for(unsigned int itj=0; itj<JetColl.size(); itj++){ HT+=JetColl.at(itj).Pt(); }


    int Idxj1W=-1, Idxj2W=-1; float bestmjjW=-1;
    for(unsigned int ij1=0; ij1<NonBJetColl.size(); ij1++){
    for(unsigned int ij2=ij1+1; ij2<NonBJetColl.size(); ij2++){
      float mjj = (NonBJetColl.at(ij1)+NonBJetColl.at(ij2)).M();
      if(bestmjjW<0){ bestmjjW = mjj; Idxj1W=ij1, Idxj2W=ij2; }
      else{ if(fabs(mjj-80.4)<fabs(bestmjjW-80.4)){ bestmjjW = mjj; Idxj1W=ij1, Idxj2W=ij2; } }
    }} 
    Ml2j1W_BkdTop = (ElTColl.at(1)+NonBJetColl.at(0)).M();
    Ml2W_BkdTop   = bestmjjW<0? -1.:(ElTColl.at(1)+NonBJetColl.at(Idxj1W)+NonBJetColl.at(Idxj2W)).M();
    MTbl1v_BkdTop = MT(BJetColl.at(0)+ElTColl.at(0),vMET);
    float Pzv1 = GetvPz(ElTColl.at(0), vMET, "+"); Particle vMET1; vMET1.SetXYZM(vMET.X(), vMET.Y(), Pzv1, 0);
    float Pzv2 = GetvPz(ElTColl.at(0), vMET, "-"); Particle vMET2; vMET2.SetXYZM(vMET.X(), vMET.Y(), Pzv2, 0);
    float Mblv1 = (BJetColl.at(0)+ElTColl.at(0)+vMET1).M(), Mblv2 = (BJetColl.at(0)+ElTColl.at(1)+vMET2).M();
    Particle vMET_CondMWt = fabs(Mblv1-172.5)<fabs(Mblv2-172.5)? vMET1:vMET2;
    Ml1v_BkdTop  = (ElTColl.at(0)+vMET_CondMWt).M();
    Mbl1v_BkdTop = (BJetColl.at(0)+ElTColl.at(0)+vMET_CondMWt).M();

   
    int Idxj1W_1jL=-1, Idxbt_1jL=-1; float BestSumDelta_L=-1; 
    for(unsigned int ib=0; ib<BCandColl.size(); ib++){
    for(unsigned int inb=0; inb<NonBJetColl.size(); inb++){
      if(BCandColl.at(ib).DeltaR(NonBJetColl.at(inb))<0.1) continue;
      float mllj = (ElTColl.at(0)+ElTColl.at(1)+NonBJetColl.at(inb)).M();
      float mbllj = (ElTColl.at(0)+ElTColl.at(1)+NonBJetColl.at(inb)+BCandColl.at(ib)).M();
      float SumDelta = fabs(mbllj-160)+fabs(mllj-75);
      if(BestSumDelta_L<0){ BestSumDelta_L=SumDelta; Idxj1W_1jL=inb; Idxbt_1jL=ib;}
      else{  
        if(SumDelta<BestSumDelta_L){ BestSumDelta_L=SumDelta; Idxj1W_1jL=inb; Idxbt_1jL=ib;}
      }
    }}
    MbllW_1jL = (ElTColl.at(0)+ElTColl.at(1)+NonBJetColl.at(Idxj1W_1jL)+BCandColl.at(Idxbt_1jL)).M();
    MllW_1jL  = (ElTColl.at(0)+ElTColl.at(1)+NonBJetColl.at(Idxj1W_1jL)).M();
    Ml1W_1jL  = (ElTColl.at(0)+NonBJetColl.at(Idxj1W_1jL)).M();
    Ml2W_1jL  = (ElTColl.at(1)+NonBJetColl.at(Idxj1W_1jL)).M();


    int Idxj1W_1jH=-1, Idxbt_1jH=-1; float BestDeltambllj=-1;
    for(unsigned int ib=0; ib<BCandColl.size(); ib++){
    for(unsigned int inb=0; inb<NonBJetColl.size(); inb++){
      if(BCandColl.at(ib).DeltaR(NonBJetColl.at(inb))<0.1) continue;
      float mbllj = (ElTColl.at(0)+ElTColl.at(1)+NonBJetColl.at(inb)+BCandColl.at(ib)).M();
      float Deltambllj = fabs(mbllj-130);
      if(BestDeltambllj<0){ BestDeltambllj = Deltambllj; Idxj1W_1jH=inb; Idxbt_1jH=ib;}
      else{  
        if(Deltambllj<BestDeltambllj){ BestDeltambllj = Deltambllj; Idxj1W_1jH=inb; Idxbt_1jH=ib;}
      }
    }}
    MbllW_1jH = (ElTColl.at(0)+ElTColl.at(1)+NonBJetColl.at(Idxj1W_1jH)+BCandColl.at(Idxbt_1jH)).M();
    MllW_1jH  = (ElTColl.at(0)+ElTColl.at(1)+NonBJetColl.at(Idxj1W_1jH)).M();
    Ml1W_1jH  = (ElTColl.at(0)+NonBJetColl.at(Idxj1W_1jH)).M();
    Ml2W_1jH  = (ElTColl.at(1)+NonBJetColl.at(Idxj1W_1jH)).M();


    int Idxj1W_H=-1, Idxj2W_H=-1, Idxbt_H=-1; float BestSumDelta_H=-1; 
    for(unsigned int ib=0; ib<BCandColl.size(); ib++){
    for(unsigned int inb1=0; inb1<NonBJetColl.size(); inb1++){
    for(unsigned int inb2=inb1+1; inb2<NonBJetColl.size(); inb2++){
      if(BCandColl.at(ib).DeltaR(NonBJetColl.at(inb1))<0.1) continue;
      if(BCandColl.at(ib).DeltaR(NonBJetColl.at(inb2))<0.1) continue;
      float mjj    = (NonBJetColl.at(inb1)+NonBJetColl.at(inb2)).M();
      float mblljj = (ElTColl.at(0)+ElTColl.at(1)+NonBJetColl.at(inb1)+NonBJetColl.at(inb2)+BCandColl.at(ib)).M();
      float SumDelta = fabs(mblljj-172.5)+fabs(mjj-80.4);
      if(BestSumDelta_H<0){ BestSumDelta_H=SumDelta; Idxj1W_H=inb1; Idxj2W_H=inb2; Idxbt_H=ib;}
      else{  
        if(SumDelta<BestSumDelta_H){ BestSumDelta_H=SumDelta; Idxj1W_H=inb1; Idxj2W_H=inb2; Idxbt_H=ib;}
      }
    }}}
    MbllW_H = BestSumDelta_H<0? -1.:(ElTColl.at(0)+ElTColl.at(1)+NonBJetColl.at(Idxj1W_H)+NonBJetColl.at(Idxj2W_H)+BCandColl.at(Idxbt_H)).M();
    Ml1W_H  = BestSumDelta_H<0? -1.:(ElTColl.at(0)+NonBJetColl.at(Idxj1W_H)+NonBJetColl.at(Idxj2W_H)).M();
    Ml2W_H  = BestSumDelta_H<0? -1.:(ElTColl.at(1)+NonBJetColl.at(Idxj1W_H)+NonBJetColl.at(Idxj2W_H)).M();

    w_tot    = !IsDATA? weight:-1.;

    tree_ee->Fill();

  }

}



void KinVarSearch::executeEventFromParameter(AnalyzerParameter param){
}


void KinVarSearch::InitializeTreeVars(){

  Nj=-1, Nb=-1;
  Ptl1=-1, Ptl2=-1, Ptj1=-1, Ptj2=-1, Ptj3=-1, MET=-1, HT=-1;
  dRll=-1;
  dRlj11=-1, dRlj12=-1, dRlj13=-1, dRlj21=-1, dRlj22=-1, dRlj23=-1;
  dRlb11=-1, dRlb21=-1, dRlnb11=-1, dRlnb21=-1;
  MSSSF=-1;
  MTvl1=-1, MTllv=-1, Ml2j1W_BkdTop=-1, Ml2W_BkdTop=-1, MTbl1v_BkdTop=-1, Ml1v_BkdTop=-1, Mbl1v_BkdTop=-1;
  MbllW_1jL=-1, MllW_1jL=-1, Ml1W_1jL=-1, Ml2W_1jL=-1;
  MbllW_1jH=-1, MllW_1jH=-1, Ml1W_1jH=-1, Ml2W_1jH=-1;
  MbllW_H=-1, Ml1W_H=-1, Ml2W_H=-1; 
  w_tot=-1;

}



KinVarSearch::KinVarSearch(){

  tree_mm = new TTree("Tree_mm", "Tree_mm");
  tree_ee = new TTree("Tree_ee", "Tree_ee");

}


KinVarSearch::~KinVarSearch(){

  delete tree_mm;
  delete tree_ee;

}


void KinVarSearch::WriteHist(){

  outfile->cd();
  tree_mm->Write();
  tree_ee->Write();
  outfile->cd();

}
