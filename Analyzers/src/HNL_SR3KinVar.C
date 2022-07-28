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
  tree_mm->Branch("Nj", &Nj, "Nj/I");                   tree_ee->Branch("Nj", &Nj, "Nj/I");
  tree_mm->Branch("Nvbfj", &Nvbfj, "Nvbfj/I");          tree_ee->Branch("Nvbfj", &Nvbfj, "Nvbfj/I");
  tree_mm->Branch("Nb", &Nb, "Nb/I");                   tree_ee->Branch("Nb", &Nb, "Nb/I");
  tree_mm->Branch("Ptl1", &Ptl1, "Ptl1/F");             tree_ee->Branch("Ptl1", &Ptl1, "Ptl1/F");
  tree_mm->Branch("Ptl2", &Ptl2, "Ptl2/F");             tree_ee->Branch("Ptl2", &Ptl2, "Ptl2/F");
  tree_mm->Branch("Ptj1", &Ptj1, "Ptj1/F");             tree_ee->Branch("Ptj1", &Ptj1, "Ptj1/F");
  tree_mm->Branch("Ptj2", &Ptj2, "Ptj2/F");             tree_ee->Branch("Ptj2", &Ptj2, "Ptj2/F");
  tree_mm->Branch("Ptj3", &Ptj3, "Ptj3/F");             tree_ee->Branch("Ptj3", &Ptj3, "Ptj3/F");
  tree_mm->Branch("MET", &MET, "MET/F");                tree_ee->Branch("MET", &MET, "MET/F");
  tree_mm->Branch("MET2ST", &MET2ST, "MET2ST/F");       tree_ee->Branch("MET2ST", &MET2ST, "MET2ST/F");
  tree_mm->Branch("HT", &HT, "HT/F");                   tree_ee->Branch("HT", &HT, "HT/F");
  tree_mm->Branch("HTLT", &HTLT, "HTLT/F");             tree_ee->Branch("HTLT", &HTLT, "HTLT/F");
  tree_mm->Branch("MET2HT", &MET2HT, "MET2HT/F");       tree_ee->Branch("MET2HT", &MET2HT, "MET2HT/F");
  tree_mm->Branch("dEtall", &dEtall, "dEtall/F");       tree_ee->Branch("dEtall", &dEtall, "dEtall/F");
  tree_mm->Branch("dRll", &dRll, "dRll/F");             tree_ee->Branch("dRll", &dRll, "dRll/F");
  tree_mm->Branch("dRjj12", &dRjj12, "dRjj12/F");       tree_ee->Branch("dRjj12", &dRjj12, "dRjj12/F");
  tree_mm->Branch("dRjj23", &dRjj23, "dRjj23/F");       tree_ee->Branch("dRjj23", &dRjj23, "dRjj23/F");
  tree_mm->Branch("dRjj13", &dRjj13, "dRjj13/F");       tree_ee->Branch("dRjj13", &dRjj13, "dRjj13/F");
  tree_mm->Branch("dRlj11", &dRlj11, "dRlj11/F");       tree_ee->Branch("dRlj11", &dRlj11, "dRlj11/F");
  tree_mm->Branch("dRlj12", &dRlj12, "dRlj12/F");       tree_ee->Branch("dRlj12", &dRlj12, "dRlj12/F");
  tree_mm->Branch("dRlj13", &dRlj13, "dRlj13/F");       tree_ee->Branch("dRlj13", &dRlj13, "dRlj13/F");
  tree_mm->Branch("dRlj21", &dRlj21, "dRlj21/F");       tree_ee->Branch("dRlj21", &dRlj21, "dRlj21/F");
  tree_mm->Branch("dRlj22", &dRlj22, "dRlj22/F");       tree_ee->Branch("dRlj22", &dRlj22, "dRlj22/F");
  tree_mm->Branch("dRlj23", &dRlj23, "dRlj23/F");       tree_ee->Branch("dRlj23", &dRlj23, "dRlj23/F");
  tree_mm->Branch("dRlb11", &dRlb11, "dRlb11/F");       tree_ee->Branch("dRlb11", &dRlb11, "dRlb11/F");
  tree_mm->Branch("dRlb21", &dRlb21, "dRlb21/F");       tree_ee->Branch("dRlb21", &dRlb21, "dRlb21/F");
  tree_mm->Branch("MSSSF", &MSSSF, "MSSSF/F");          tree_ee->Branch("MSSSF", &MSSSF, "MSSSF/F");
  tree_mm->Branch("Mbl11", &Mbl11, "Mbl11/F");          tree_ee->Branch("Mbl11", &Mbl11, "Mbl11/F");
  tree_mm->Branch("Mbl12", &Mbl12, "Mbl12/F");          tree_ee->Branch("Mbl12", &Mbl12, "Mbl12/F");
  tree_mm->Branch("Mbl21", &Mbl21, "Mbl21/F");          tree_ee->Branch("Mbl21", &Mbl21, "Mbl21/F");
  tree_mm->Branch("Mbl22", &Mbl22, "Mbl22/F");          tree_ee->Branch("Mbl22", &Mbl22, "Mbl22/F");
  tree_mm->Branch("Mlj11", &Mlj11, "Mlj11/F");          tree_ee->Branch("Mlj11", &Mlj11, "Mlj11/F");
  tree_mm->Branch("Mlj12", &Mlj12, "Mlj12/F");          tree_ee->Branch("Mlj12", &Mlj12, "Mlj12/F");
  tree_mm->Branch("Mlj13", &Mlj13, "Mlj13/F");          tree_ee->Branch("Mlj13", &Mlj13, "Mlj13/F");
  tree_mm->Branch("Mlj21", &Mlj21, "Mlj21/F");          tree_ee->Branch("Mlj21", &Mlj21, "Mlj21/F");
  tree_mm->Branch("Mlj22", &Mlj22, "Mlj22/F");          tree_ee->Branch("Mlj22", &Mlj22, "Mlj22/F");
  tree_mm->Branch("Mlj23", &Mlj23, "Mlj23/F");          tree_ee->Branch("Mlj23", &Mlj23, "Mlj23/F");
  tree_mm->Branch("MTvl1", &MTvl1, "MTvl1/F");          tree_ee->Branch("MTvl1", &MTvl1, "MTvl1/F");
  tree_mm->Branch("MTvl2", &MTvl2, "MTvl2/F");          tree_ee->Branch("MTvl2", &MTvl2, "MTvl2/F");
  tree_mm->Branch("Mllj1", &Mllj1, "Mllj1/F");          tree_ee->Branch("Mllj1", &Mllj1, "Mllj1/F");
  tree_mm->Branch("Mllj2", &Mllj2, "Mllj2/F");          tree_ee->Branch("Mllj2", &Mllj2, "Mllj2/F");
  tree_mm->Branch("Mllj3", &Mllj3, "Mllj3/F");          tree_ee->Branch("Mllj3", &Mllj3, "Mllj3/F");
  tree_mm->Branch("Mllj4", &Mllj4, "Mllj4/F");          tree_ee->Branch("Mllj4", &Mllj4, "Mllj4/F");
  tree_mm->Branch("Mllb1", &Mllb1, "Mllb1/F");          tree_ee->Branch("Mllb1", &Mllb1, "Mllb1/F");
  tree_mm->Branch("Mllb2", &Mllb2, "Mllb2/F");          tree_ee->Branch("Mllb2", &Mllb2, "Mllb2/F");
  tree_mm->Branch("Mlljj12", &Mlljj12, "Mlljj12/F");    tree_ee->Branch("Mlljj12", &Mlljj12, "Mlljj12/F");
  tree_mm->Branch("Mlljj13", &Mlljj13, "Mlljj13/F");    tree_ee->Branch("Mlljj13", &Mlljj13, "Mlljj13/F");
  tree_mm->Branch("Mlljj14", &Mlljj14, "Mlljj14/F");    tree_ee->Branch("Mlljj14", &Mlljj14, "Mlljj14/F");
  tree_mm->Branch("Mlljj23", &Mlljj23, "Mlljj23/F");    tree_ee->Branch("Mlljj23", &Mlljj23, "Mlljj23/F");
  tree_mm->Branch("Mlljj24", &Mlljj24, "Mlljj24/F");    tree_ee->Branch("Mlljj24", &Mlljj24, "Mlljj24/F");
  tree_mm->Branch("Mlljj34", &Mlljj34, "Mlljj34/F");    tree_ee->Branch("Mlljj34", &Mlljj34, "Mlljj34/F");
  tree_mm->Branch("Mljj112", &Mljj112, "Mljj112/F");    tree_ee->Branch("Mljj112", &Mljj112, "Mljj112/F");
  tree_mm->Branch("Mljj113", &Mljj113, "Mljj113/F");    tree_ee->Branch("Mljj113", &Mljj113, "Mljj113/F");
  tree_mm->Branch("Mljj114", &Mljj114, "Mljj114/F");    tree_ee->Branch("Mljj114", &Mljj114, "Mljj114/F");
  tree_mm->Branch("Mljj123", &Mljj123, "Mljj123/F");    tree_ee->Branch("Mljj123", &Mljj123, "Mljj123/F");
  tree_mm->Branch("Mljj124", &Mljj124, "Mljj124/F");    tree_ee->Branch("Mljj124", &Mljj124, "Mljj124/F");
  tree_mm->Branch("Mljj134", &Mljj134, "Mljj134/F");    tree_ee->Branch("Mljj134", &Mljj134, "Mljj134/F");
  tree_mm->Branch("Mljj212", &Mljj212, "Mljj212/F");    tree_ee->Branch("Mljj212", &Mljj212, "Mljj212/F");
  tree_mm->Branch("Mljj213", &Mljj213, "Mljj213/F");    tree_ee->Branch("Mljj213", &Mljj213, "Mljj213/F");
  tree_mm->Branch("Mljj214", &Mljj214, "Mljj214/F");    tree_ee->Branch("Mljj214", &Mljj214, "Mljj214/F");
  tree_mm->Branch("Mljj223", &Mljj223, "Mljj223/F");    tree_ee->Branch("Mljj223", &Mljj223, "Mljj223/F");
  tree_mm->Branch("Mljj224", &Mljj224, "Mljj224/F");    tree_ee->Branch("Mljj224", &Mljj224, "Mljj224/F");
  tree_mm->Branch("Mljj234", &Mljj234, "Mljj234/F");    tree_ee->Branch("Mljj234", &Mljj234, "Mljj234/F");
  tree_mm->Branch("Mjj12", &Mjj12, "Mjj12/F");          tree_ee->Branch("Mjj12", &Mjj12, "Mjj12/F");
  tree_mm->Branch("Mjj13", &Mjj13, "Mjj13/F");          tree_ee->Branch("Mjj13", &Mjj13, "Mjj13/F");
  tree_mm->Branch("Mjj14", &Mjj14, "Mjj14/F");          tree_ee->Branch("Mjj14", &Mjj14, "Mjj14/F");
  tree_mm->Branch("Mjj23", &Mjj23, "Mjj23/F");          tree_ee->Branch("Mjj23", &Mjj23, "Mjj23/F");
  tree_mm->Branch("Mjj24", &Mjj24, "Mjj24/F");          tree_ee->Branch("Mjj24", &Mjj24, "Mjj24/F");
  tree_mm->Branch("Mjj34", &Mjj34, "Mjj34/F");          tree_ee->Branch("Mjj34", &Mjj34, "Mjj34/F");
  tree_mm->Branch("MjjW1", &MjjW1, "MjjW1/F");          tree_ee->Branch("MjjW1", &MjjW1, "MjjW1/F");
  tree_mm->Branch("MjjW2", &MjjW2, "MjjW2/F");          tree_ee->Branch("MjjW2", &MjjW2, "MjjW2/F");
  tree_mm->Branch("MllW_2jL", &MllW_2jL, "MllW_2jL/F"); tree_ee->Branch("MllW_2jL", &MllW_2jL, "MllW_2jL/F");
  tree_mm->Branch("MllW_1jL", &MllW_1jL, "MllW_1jL/F"); tree_ee->Branch("MllW_1jL", &MllW_1jL, "MllW_1jL/F");
  tree_mm->Branch("MllW1_H", &MllW1_H, "MllW1_H/F");    tree_ee->Branch("MllW1_H", &MllW1_H, "MllW1_H/F");
  tree_mm->Branch("MllW2_H", &MllW2_H, "MllW2_H/F");    tree_ee->Branch("MllW2_H", &MllW2_H, "MllW2_H/F");
  tree_mm->Branch("Ml1W_2jL", &Ml1W_2jL, "Ml1W_2jL/F"); tree_ee->Branch("Ml1W_2jL", &Ml1W_2jL, "Ml1W_2jL/F");
  tree_mm->Branch("Ml1W_1jL", &Ml1W_1jL, "Ml1W_1jL/F"); tree_ee->Branch("Ml1W_1jL", &Ml1W_1jL, "Ml1W_1jL/F");
  tree_mm->Branch("Ml2W_2jL", &Ml2W_2jL, "Ml2W_2jL/F"); tree_ee->Branch("Ml2W_2jL", &Ml2W_2jL, "Ml2W_2jL/F");
  tree_mm->Branch("Ml2W_1jL", &Ml2W_1jL, "Ml2W_1jL/F"); tree_ee->Branch("Ml2W_1jL", &Ml2W_1jL, "Ml2W_1jL/F");
  tree_mm->Branch("Ml1W1_H", &Ml1W1_H, "Ml1W1_H/F");    tree_ee->Branch("Ml1W1_H", &Ml1W1_H, "Ml1W1_H/F");
  tree_mm->Branch("Ml1W2_H", &Ml1W2_H, "Ml1W2_H/F");    tree_ee->Branch("Ml1W2_H", &Ml1W2_H, "Ml1W2_H/F");
  tree_mm->Branch("Ml2W1_H", &Ml2W1_H, "Ml2W1_H/F");    tree_ee->Branch("Ml2W1_H", &Ml2W1_H, "Ml2W1_H/F");
  tree_mm->Branch("Ml2W2_H", &Ml2W2_H, "Ml2W2_H/F");    tree_ee->Branch("Ml2W2_H", &Ml2W2_H, "Ml2W2_H/F");
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
  if     (DblMuon_Channel) PassTrig = ev.PassTrigger(TrigList_DblMu);
  else if(DblEG_Channel) PassTrig = ev.PassTrigger(TrigList_DblEG);
  else if(MuonEG_Channel) PassTrig = ev.PassTrigger(TrigList_MuonEG);

  if(!PassTrig) return;

  if(!PassMETFilter()) return;

  TString IDSSLabel = SS2l? "SS":"";
  TString MuTID = "HNTightV2", MuLID = "HNLooseV1", MuVID="HNVeto2016";
  TString ElTID = "HNTightV2", ElLID = "HNLooseV4", ElVID = "HNVeto2016";  
  
  
  std::vector<Electron>   myelectrons_js = GetElectrons(this_AllElectrons, "HNTight_17028", 10., 2.5);
  std::vector<Muon>       mymuons_js     = GetMuons    (this_AllMuons,     "HNTight_17028", 10., 2.4);

  std::vector<Electron>   electronTightColl  = GetElectrons(this_AllElectrons, "HNTight_17028", 10., 2.5);
  std::vector<Muon>       muonTightColl      = GetMuons    (this_AllMuons,     "HNTight_17028", 10., 2.4);


  std::vector<Electron>   electronVetoColl  = GetElectrons(this_AllElectrons, "HNVeto2016", 10., 2.5);
  std::vector<Muon>       muonsVetoColl     = GetMuons    (this_AllMuons,     "HNVeto2016", 5., 2.4);

  std::vector<Tau>        mytaus       = GetTaus(this_AllTaus,"HNVeto",20., 2.3);

  std::vector<FatJet>   fatjets_tmp  = GetJets("tight", 200., 5);
  std::vector<Jet>      jets_tmp     = GetJets("tight", 15., 5);

  std::vector<FatJet> fatjetColl        = GetAK8Jets(fatjetColl_tmp, 200., 2.7, true,  1., true, -999, true, 40., 130., electronVetoColl, muonsVetoColl);
  std::vector<Jet> jetColl              = GetAK4Jets(jets_tmp,     20., 2.7, true,  0.4,0.8,"loose",        electronVetoColl, muonsVetoColl,fatjetColl);
  std::vector<Jet> vbf_jetColl          = GetAK4Jets(jets_tmp,     30., 4.7, true,  0.4,0.8,"loose",   vetoelectrons, vetomuons,fatjetColl);


  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
  vector<Jet> jetNoVetoColl  = GetJets("tight", 25., 2.4);
  vector<Jet> bjetNoVetoColl = SelBJets(jetNoVetoColl, param_jets);

  Particle vMET_T1xy = GetvMET("T1xyCorr");

  bool EventCand = false;
  if (DblMuon_Channel){

    if (SameCharge(muonTightColl) && muonVetoColl.size()==2 && electronVetoColl.size()==0&&mytaus.size()==0){
      if (GetLLMass(muonTightColl) > 10.){
	if (fatjetColl.size() ==0) {
	 
	  if(!PassVBFInitial(vbf_jetColl)) {
 
	    EventCand=true;
	  }
	}
	
      }
      
    }
    
  }
  
  float w_Prefire = 1., sf_Trig=1.;
  float sf_MuID = 1., sf_ElReco = 1., sf_ElID = 1., sf_BTag = 1.;
  if((!IsDATA) and EventCand){
    sf_MuID   = 1.;//GetMuonSF(muonTightColl, MuTID, "ID");
    sf_ElReco = 1.;//GetElectronSF(electronLooseColl, "", "Reco");
    sf_ElID   = 1.;//GetElectronSF(electronTightColl, ElTID, "ID");
    sf_BTag   = 1.;//mcCorr->GetBTaggingReweight_1a(jetColl, param_jets);
    //ElKey: DiElIso_HNTopID17SS DiElIso_HNTopIDSS  //MuKey: DiMuIso_HNTopID
    //int NEl = electronTightColl.size(), NMu = muonTightColl.size();
    //TString TrSFKey = NMu>1? "DiMuIso_HNTopID":NEl>1? "DiElIso_HNTopID17SS":"";
    //bool ApplyTrSF = TrSFKey!="" && (SS2l or TriLep);
    //sf_Trig   = ApplyTrSF? mcCorr->GetTriggerSF(electronTightColl, muonTightColl, TrSFKey, ""):1.;
    w_Prefire = GetPrefireWeight(0);
  }
  weight *= w_Prefire * sf_Trig;
  weight *= sf_MuID * sf_ElReco * sf_ElID * sf_BTag;

 
  if(EventCand){
    //AnalyzeSSDiLepton(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
    //                  jetColl, bjetColl, vMET_T1xy, weight, "");
    MakeTreeSS2L(muonTightColl,  muonVetoColl, electronTightColl,  electronVetoColl,
                 jetColl, bjetColl, vMET_T1xy, weight, "");
  }

}

void HNL_SR3KinVar::MakeTreeSS2L(vector<Muon>& MuTColl,  vector<Muon>& MuVColl,
                                vector<Electron>& ElTColl, vector<Electron>& ElVColl,
				 vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{

  int NMuT=MuTColl.size(), NElT=ElTColl.size(),  NMuV=MuVColl.size(), NElV=ElVColl.size();

  if(NMuT==2){
  
    if(!(MuTColl.at(0).Pt()>20 && MuTColl.at(1).Pt()>10)) return;
    float Mll = (MuTColl.at(0)+MuTColl.at(1)).M();

    InitializeTreeVars();
    Nj      = JetColl.size();
    Nb      = BJetColl.size();
    Ptl1    = MuTColl.at(0).Pt();
    Ptl2    = MuTColl.at(1).Pt();
    Ptj1    = JetColl.at(0).Pt();
    Ptj2    = JetColl.at(1).Pt();
    Ptj3    = JetColl.at(2).Pt();
    Ptb1    = BJetColl.at(0).Pt();
    Ptb2    = BJetColl.size()<2? -1.:BJetColl.at(1).Pt();
    MET     = vMET.Pt();
    dEtall  = abs(MuTColl.at(0).Eta()-MuTColl.at(1).Eta());
    dRll    = MuTColl.at(0).DeltaR(MuTColl.at(1));
    dRjj12  = JetColl.at(0).DeltaR(JetColl.at(1));
    dRjj23  = JetColl.at(1).DeltaR(JetColl.at(2));
    dRjj13  = JetColl.at(0).DeltaR(JetColl.at(2));
    dRlj11  = MuTColl.at(0).DeltaR(JetColl.at(0));
    dRlj12  = MuTColl.at(0).DeltaR(JetColl.at(1));
    dRlj13  = MuTColl.at(0).DeltaR(JetColl.at(2));
    dRlj21  = MuTColl.at(1).DeltaR(JetColl.at(0));
    dRlj22  = MuTColl.at(1).DeltaR(JetColl.at(1));
    dRlj23  = MuTColl.at(1).DeltaR(JetColl.at(2));
    dRlb11  = MuTColl.at(0).DeltaR(BJetColl.at(0));
    dRlb21  = MuTColl.at(1).DeltaR(BJetColl.at(0));
    MSSSF   = (MuTColl.at(0)+MuTColl.at(1)).M();
    Mbl11   = (MuTColl.at(0)+BJetColl.at(0)).M();
    Mbl12   = (MuTColl.at(1)+BJetColl.at(0)).M();
    Mbl21   = BJetColl.size()<2? -1.:(MuTColl.at(0)+BJetColl.at(1)).M();
    Mbl22   = BJetColl.size()<2? -1.:(MuTColl.at(1)+BJetColl.at(1)).M();
    Mlj11   = (MuTColl.at(0)+JetColl.at(0)).M();
    Mlj12   = (MuTColl.at(0)+JetColl.at(1)).M();
    Mlj13   = (MuTColl.at(0)+JetColl.at(2)).M();
    Mlj21   = (MuTColl.at(1)+JetColl.at(0)).M();
    Mlj22   = (MuTColl.at(1)+JetColl.at(1)).M();
    Mlj23   = (MuTColl.at(1)+JetColl.at(2)).M();
    MTvl1   = MT(MuTColl.at(0),vMET);
    MTvl2   = MT(MuTColl.at(1),vMET);
    Mllj1   = (MuTColl.at(0)+MuTColl.at(1)+JetColl.at(0)).M();
    Mllj2   = (MuTColl.at(0)+MuTColl.at(1)+JetColl.at(1)).M();
    Mllj3   = (MuTColl.at(0)+MuTColl.at(1)+JetColl.at(2)).M();
    Mllj4   = JetColl.size()<4? -1.:(MuTColl.at(0)+MuTColl.at(1)+JetColl.at(3)).M();
    Mllb1   = (MuTColl.at(0)+MuTColl.at(1)+BJetColl.at(0)).M();
    Mllb2   = BJetColl.size()<2? -1.:(MuTColl.at(0)+MuTColl.at(1)+BJetColl.at(1)).M();
    Mlljj12 = (MuTColl.at(0)+MuTColl.at(1)+JetColl.at(0)+JetColl.at(1)).M();
    Mlljj13 = (MuTColl.at(0)+MuTColl.at(1)+JetColl.at(0)+JetColl.at(2)).M();
    Mlljj14 = JetColl.size()<4? -1.:(MuTColl.at(0)+MuTColl.at(1)+JetColl.at(0)+JetColl.at(3)).M();
    Mlljj23 = (MuTColl.at(0)+MuTColl.at(1)+JetColl.at(1)+JetColl.at(2)).M();
    Mlljj24 = JetColl.size()<4? -1.:(MuTColl.at(0)+MuTColl.at(1)+JetColl.at(1)+JetColl.at(3)).M();
    Mlljj34 = JetColl.size()<4? -1.:(MuTColl.at(0)+MuTColl.at(1)+JetColl.at(2)+JetColl.at(3)).M();
    Mljj112 = (MuTColl.at(0)+JetColl.at(0)+JetColl.at(1)).M();
    Mljj113 = (MuTColl.at(0)+JetColl.at(0)+JetColl.at(2)).M();
    Mljj114 = JetColl.size()<4? -1.:(MuTColl.at(0)+JetColl.at(0)+JetColl.at(3)).M();
    Mljj123 = (MuTColl.at(0)+JetColl.at(1)+JetColl.at(2)).M();
    Mljj124 = JetColl.size()<4? -1.:(MuTColl.at(0)+JetColl.at(1)+JetColl.at(3)).M();
    Mljj134 = JetColl.size()<4? -1.:(MuTColl.at(0)+JetColl.at(2)+JetColl.at(3)).M();
    Mljj212 = (MuTColl.at(1)+JetColl.at(0)+JetColl.at(1)).M();
    Mljj213 = (MuTColl.at(1)+JetColl.at(0)+JetColl.at(2)).M();
    Mljj214 = JetColl.size()<4? -1.:(MuTColl.at(1)+JetColl.at(0)+JetColl.at(3)).M();
    Mljj223 = (MuTColl.at(1)+JetColl.at(1)+JetColl.at(2)).M();
    Mljj224 = JetColl.size()<4? -1.:(MuTColl.at(1)+JetColl.at(1)+JetColl.at(3)).M();
    Mljj234 = JetColl.size()<4? -1.:(MuTColl.at(1)+JetColl.at(2)+JetColl.at(3)).M();
    Mjj12   = (JetColl.at(0)+JetColl.at(1)).M();
    Mjj13   = (JetColl.at(0)+JetColl.at(2)).M();
    Mjj14   = JetColl.size()<4? -1.:(JetColl.at(0)+JetColl.at(3)).M();
    Mjj23   = (JetColl.at(1)+JetColl.at(2)).M();
    Mjj24   = JetColl.size()<4? -1.:(JetColl.at(1)+JetColl.at(3)).M();
    Mjj34   = JetColl.size()<4? -1.:(JetColl.at(2)+JetColl.at(3)).M();

    //Vars requiring complex algo.
    HT      = 0;
    for(unsigned int itj=0; itj<JetColl.size(); itj++){ HT+=JetColl.at(itj).Pt(); }
    MET2HT  = pow(MET,2.)/HT;
    int Idxj1W_2jL=-1, Idxj2W_2jL=-1; float bestmlljj=-1;
    int Idxj1W_1jL=-1; float bestmllj=-1;
    int Idxj1W1_H=-1, Idxj2W1_H=-1, Idxj1W2_H=-1, Idxj2W2_H=-1; float bestmjj1=-1, bestmjj2=-1;
    for(unsigned int itj1=0; itj1<JetColl.size(); itj1++){
      if(bestmllj<0){ Idxj1W_1jL=itj1; bestmllj=(MuTColl.at(0)+MuTColl.at(1)).M(); }
      else{
        float tmpmljj = (MuTColl.at(0)+MuTColl.at(1)+JetColl.at(itj1)).M();
        if(fabs(tmpmljj-80.4)<fabs(bestmllj-80.4)){ bestmllj=tmpmljj; Idxj1W_1jL=itj1; }
      }
      for(unsigned int itj2=itj1+1; itj2<JetColl.size(); itj2++){
        if(bestmlljj<0){ Idxj1W_2jL=itj1; Idxj2W_2jL=itj2; bestmlljj=(MuTColl.at(0)+MuTColl.at(1)+JetColl.at(itj1)+JetColl.at(itj2)).M(); }
        else{
          float tmpmlljj = (MuTColl.at(0)+MuTColl.at(1)+JetColl.at(itj1)+JetColl.at(itj2)).M();
          if(fabs(tmpmlljj-80.4)<fabs(bestmlljj-80.4)){ bestmlljj=tmpmlljj; Idxj1W_2jL=itj1, Idxj2W_2jL=itj2; }
        }
        if(bestmjj1<0){ Idxj1W1_H=itj1, Idxj2W1_H=itj2; bestmjj1=(JetColl.at(itj1)+JetColl.at(itj2)).M(); }
        else{
          float tmpmjj = (JetColl.at(itj1)+JetColl.at(itj2)).M();
          if(fabs(tmpmjj-80.4)<fabs(bestmjj1-80.4)){ bestmjj1=tmpmjj; Idxj1W1_H=itj1, Idxj2W1_H=itj2; }
        }
      }
    }
    for(unsigned int itj1=0; itj1<JetColl.size(); itj1++){
      for(unsigned int itj2=itj1+1; itj2<JetColl.size(); itj2++){
        if((int) itj1==Idxj1W1_H or (int) itj1==Idxj2W1_H or (int) itj2==Idxj1W1_H or (int) itj2==Idxj2W1_H) continue;
        if(bestmjj2<0){ Idxj1W2_H=itj1, Idxj2W2_H=itj2; bestmjj2=(JetColl.at(itj1)+JetColl.at(itj2)).M(); }
        else{
          float tmpmjj = (JetColl.at(itj1)+JetColl.at(itj2)).M();
          if(fabs(tmpmjj-80.4)<fabs(bestmjj2-80.4)){ bestmjj2=tmpmjj; Idxj1W2_H=itj1, Idxj2W2_H=itj2; }
        }
      }
    }
    MllW_2jL = bestmlljj;
    MllW_1jL = bestmllj;
    MllW1_H  = (MuTColl.at(0)+MuTColl.at(1)+JetColl.at(Idxj1W1_H)+JetColl.at(Idxj2W1_H)).M();
    MllW2_H  = bestmjj2<0? -1.:(MuTColl.at(0)+MuTColl.at(1)+JetColl.at(Idxj1W2_H)+JetColl.at(Idxj2W2_H)).M();
    MjjW1    = bestmjj1;
    MjjW2    = bestmjj2;
    Ml1W_2jL = (MuTColl.at(0)+JetColl.at(Idxj1W_2jL)+JetColl.at(Idxj2W_2jL)).M();
    Ml1W_1jL = (MuTColl.at(0)+JetColl.at(Idxj1W_1jL)).M();
    Ml2W_2jL = (MuTColl.at(1)+JetColl.at(Idxj1W_2jL)+JetColl.at(Idxj2W_2jL)).M();
    Ml2W_1jL = (MuTColl.at(1)+JetColl.at(Idxj1W_1jL)).M();
    Ml1W1_H  = (MuTColl.at(0)+JetColl.at(Idxj1W1_H)+JetColl.at(Idxj2W1_H)).M();
    Ml1W2_H  = bestmjj2<0? -1.:(MuTColl.at(0)+JetColl.at(Idxj1W2_H)+JetColl.at(Idxj2W2_H)).M();
    Ml2W1_H  = (MuTColl.at(1)+JetColl.at(Idxj1W1_H)+JetColl.at(Idxj2W1_H)).M();
    Ml2W2_H  = bestmjj2<0? -1.:(MuTColl.at(1)+JetColl.at(Idxj1W2_H)+JetColl.at(Idxj2W2_H)).M();
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
    InitializeTreeVars();
    Nj      = JetColl.size();
    Nb      = BJetColl.size();
    Ptl1    = ElTColl.at(0).Pt();
    Ptl2    = ElTColl.at(1).Pt();
    Ptj1    = JetColl.at(0).Pt();
    Ptj2    = JetColl.at(1).Pt();
    Ptj3    = JetColl.at(2).Pt();
    Ptb1    = BJetColl.at(0).Pt();
    Ptb2    = BJetColl.size()<2? -1.:BJetColl.at(1).Pt();
    MET     = vMET.Pt();
    dEtall  = abs(ElTColl.at(0).Eta()-ElTColl.at(1).Eta());
    dRll    = ElTColl.at(0).DeltaR(ElTColl.at(1));
    dRjj12  = JetColl.at(0).DeltaR(JetColl.at(1));
    dRjj23  = JetColl.at(1).DeltaR(JetColl.at(2));
    dRjj13  = JetColl.at(0).DeltaR(JetColl.at(2));
    dRlj11  = ElTColl.at(0).DeltaR(JetColl.at(0));
    dRlj12  = ElTColl.at(0).DeltaR(JetColl.at(1));
    dRlj13  = ElTColl.at(0).DeltaR(JetColl.at(2));
    dRlj21  = ElTColl.at(1).DeltaR(JetColl.at(0));
    dRlj22  = ElTColl.at(1).DeltaR(JetColl.at(1));
    dRlj23  = ElTColl.at(1).DeltaR(JetColl.at(2));
    dRlb11  = ElTColl.at(0).DeltaR(BJetColl.at(0));
    dRlb21  = ElTColl.at(1).DeltaR(BJetColl.at(0));
    MSSSF   = (ElTColl.at(0)+ElTColl.at(1)).M();
    Mbl11   = (ElTColl.at(0)+BJetColl.at(0)).M();
    Mbl12   = (ElTColl.at(1)+BJetColl.at(0)).M();
    Mbl21   = BJetColl.size()<2? -1.:(ElTColl.at(0)+BJetColl.at(1)).M();
    Mbl22   = BJetColl.size()<2? -1.:(ElTColl.at(1)+BJetColl.at(1)).M();
    Mlj11   = (ElTColl.at(0)+JetColl.at(0)).M();
    Mlj12   = (ElTColl.at(0)+JetColl.at(1)).M();
    Mlj13   = (ElTColl.at(0)+JetColl.at(2)).M();
    Mlj21   = (ElTColl.at(1)+JetColl.at(0)).M();
    Mlj22   = (ElTColl.at(1)+JetColl.at(1)).M();
    Mlj23   = (ElTColl.at(1)+JetColl.at(2)).M();
    MTvl1   = MT(ElTColl.at(0),vMET);
    MTvl2   = MT(ElTColl.at(1),vMET);
    Mllj1   = (ElTColl.at(0)+ElTColl.at(1)+JetColl.at(0)).M();
    Mllj2   = (ElTColl.at(0)+ElTColl.at(1)+JetColl.at(1)).M();
    Mllj3   = (ElTColl.at(0)+ElTColl.at(1)+JetColl.at(2)).M();
    Mllj4   = JetColl.size()<4? -1.:(ElTColl.at(0)+ElTColl.at(1)+JetColl.at(3)).M();
    Mllb1   = (ElTColl.at(0)+ElTColl.at(1)+BJetColl.at(0)).M();
    Mllb2   = BJetColl.size()<2? -1.:(ElTColl.at(0)+ElTColl.at(1)+BJetColl.at(1)).M();
    Mlljj12 = (ElTColl.at(0)+ElTColl.at(1)+JetColl.at(0)+JetColl.at(1)).M();
    Mlljj13 = (ElTColl.at(0)+ElTColl.at(1)+JetColl.at(0)+JetColl.at(2)).M();
    Mlljj14 = JetColl.size()<4? -1.:(ElTColl.at(0)+ElTColl.at(1)+JetColl.at(0)+JetColl.at(3)).M();
    Mlljj23 = (ElTColl.at(0)+ElTColl.at(1)+JetColl.at(1)+JetColl.at(2)).M();
    Mlljj24 = JetColl.size()<4? -1.:(ElTColl.at(0)+ElTColl.at(1)+JetColl.at(1)+JetColl.at(3)).M();
    Mlljj34 = JetColl.size()<4? -1.:(ElTColl.at(0)+ElTColl.at(1)+JetColl.at(2)+JetColl.at(3)).M();
    Mljj112 = (ElTColl.at(0)+JetColl.at(0)+JetColl.at(1)).M();
    Mljj113 = (ElTColl.at(0)+JetColl.at(0)+JetColl.at(2)).M();
    Mljj114 = JetColl.size()<4? -1.:(ElTColl.at(0)+JetColl.at(0)+JetColl.at(3)).M();
    Mljj123 = (ElTColl.at(0)+JetColl.at(1)+JetColl.at(2)).M();
    Mljj124 = JetColl.size()<4? -1.:(ElTColl.at(0)+JetColl.at(1)+JetColl.at(3)).M();
    Mljj134 = JetColl.size()<4? -1.:(ElTColl.at(0)+JetColl.at(2)+JetColl.at(3)).M();
    Mljj212 = (ElTColl.at(1)+JetColl.at(0)+JetColl.at(1)).M();
    Mljj213 = (ElTColl.at(1)+JetColl.at(0)+JetColl.at(2)).M();
    Mljj214 = JetColl.size()<4? -1.:(ElTColl.at(1)+JetColl.at(0)+JetColl.at(3)).M();
    Mljj223 = (ElTColl.at(1)+JetColl.at(1)+JetColl.at(2)).M();
    Mljj224 = JetColl.size()<4? -1.:(ElTColl.at(1)+JetColl.at(1)+JetColl.at(3)).M();
    Mljj234 = JetColl.size()<4? -1.:(ElTColl.at(1)+JetColl.at(2)+JetColl.at(3)).M();
    Mjj12   = (JetColl.at(0)+JetColl.at(1)).M();
    Mjj13   = (JetColl.at(0)+JetColl.at(2)).M();
    Mjj14   = JetColl.size()<4? -1.:(JetColl.at(0)+JetColl.at(3)).M();
    Mjj23   = (JetColl.at(1)+JetColl.at(2)).M();
    Mjj24   = JetColl.size()<4? -1.:(JetColl.at(1)+JetColl.at(3)).M();
    Mjj34   = JetColl.size()<4? -1.:(JetColl.at(2)+JetColl.at(3)).M();

    //Vars requiring complex algo.
    HT      = 0;
    for(unsigned int itj=0; itj<JetColl.size(); itj++){ HT+=JetColl.at(itj).Pt(); }
    MET2HT  = pow(MET,2.)/HT;
    int Idxj1W_2jL=-1, Idxj2W_2jL=-1; float bestmlljj=-1;
    int Idxj1W_1jL=-1; float bestmllj=-1;
    int Idxj1W1_H=-1, Idxj2W1_H=-1, Idxj1W2_H=-1, Idxj2W2_H=-1; float bestmjj1=-1, bestmjj2=-1;
    for(unsigned int itj1=0; itj1<JetColl.size(); itj1++){
      if(bestmllj<0){ Idxj1W_1jL=itj1; bestmllj=(ElTColl.at(0)+ElTColl.at(1)).M(); }
      else{
        float tmpmljj = (ElTColl.at(0)+ElTColl.at(1)+JetColl.at(itj1)).M();
        if(fabs(tmpmljj-80.4)<fabs(bestmllj-80.4)){ bestmllj=tmpmljj; Idxj1W_1jL=itj1; }
      }
      for(unsigned int itj2=itj1+1; itj2<JetColl.size(); itj2++){
        if(bestmlljj<0){ Idxj1W_2jL=itj1; Idxj2W_2jL=itj2; bestmlljj=(ElTColl.at(0)+ElTColl.at(1)+JetColl.at(itj1)+JetColl.at(itj2)).M(); }
        else{
          float tmpmlljj = (ElTColl.at(0)+ElTColl.at(1)+JetColl.at(itj1)+JetColl.at(itj2)).M();
          if(fabs(tmpmlljj-80.4)<fabs(bestmlljj-80.4)){ bestmlljj=tmpmlljj; Idxj1W_2jL=itj1, Idxj2W_2jL=itj2; }
        }
        if(bestmjj1<0){ Idxj1W1_H=itj1, Idxj2W1_H=itj2; bestmjj1=(JetColl.at(itj1)+JetColl.at(itj2)).M(); }
        else{
          float tmpmjj = (JetColl.at(itj1)+JetColl.at(itj2)).M();
          if(fabs(tmpmjj-80.4)<fabs(bestmjj1-80.4)){ bestmjj1=tmpmjj; Idxj1W1_H=itj1, Idxj2W1_H=itj2; }
        }
      }
    }
    for(unsigned int itj1=0; itj1<JetColl.size(); itj1++){
      for(unsigned int itj2=itj1+1; itj2<JetColl.size(); itj2++){
        if((int) itj1==Idxj1W1_H or (int) itj1==Idxj2W1_H or (int) itj2==Idxj1W1_H or (int) itj2==Idxj2W1_H) continue;
        if(bestmjj2<0){ Idxj1W2_H=itj1, Idxj2W2_H=itj2; bestmjj2=(JetColl.at(itj1)+JetColl.at(itj2)).M(); }
        else{
          float tmpmjj = (JetColl.at(itj1)+JetColl.at(itj2)).M();
          if(fabs(tmpmjj-80.4)<fabs(bestmjj2-80.4)){ bestmjj2=tmpmjj; Idxj1W2_H=itj1, Idxj2W2_H=itj2; }
        }
      }
    }
    MllW_2jL = bestmlljj;
    MllW_1jL = bestmllj;
    MllW1_H  = (ElTColl.at(0)+ElTColl.at(1)+JetColl.at(Idxj1W1_H)+JetColl.at(Idxj2W1_H)).M();
    MllW2_H  = bestmjj2<0? -1.:(ElTColl.at(0)+ElTColl.at(1)+JetColl.at(Idxj1W2_H)+JetColl.at(Idxj2W2_H)).M();
    MjjW1    = bestmjj1;
    MjjW2    = bestmjj2;
    Ml1W_2jL = (ElTColl.at(0)+JetColl.at(Idxj1W_2jL)+JetColl.at(Idxj2W_2jL)).M();
    Ml1W_1jL = (ElTColl.at(0)+JetColl.at(Idxj1W_1jL)).M();
    Ml2W_2jL = (ElTColl.at(1)+JetColl.at(Idxj1W_2jL)+JetColl.at(Idxj2W_2jL)).M();
    Ml2W_1jL = (ElTColl.at(1)+JetColl.at(Idxj1W_1jL)).M();
    Ml1W1_H  = (ElTColl.at(0)+JetColl.at(Idxj1W1_H)+JetColl.at(Idxj2W1_H)).M();
    Ml1W2_H  = bestmjj2<0? -1.:(ElTColl.at(0)+JetColl.at(Idxj1W2_H)+JetColl.at(Idxj2W2_H)).M();
    Ml2W1_H  = (ElTColl.at(1)+JetColl.at(Idxj1W1_H)+JetColl.at(Idxj2W1_H)).M();
    Ml2W2_H  = bestmjj2<0? -1.:(ElTColl.at(1)+JetColl.at(Idxj1W2_H)+JetColl.at(Idxj2W2_H)).M();
    w_tot    = !IsDATA? weight:-1.;
    tree_ee->Fill();
  }

}



void HNL_SR3KinVar::executeEventFromParameter(AnalyzerParameter param){
}


void HNL_SR3KinVar::InitializeTreeVars(){

  Nj=-1, Nb=-1;
  Ptl1=-1, Ptl2=-1, Ptj1=-1, Ptj2=-1, Ptj3=-1, Ptb1=-1, Ptb2=-1, MET=-1, HT=-1, MET2HT=-1;
  dEtall=-1, dRll=-1, dRjj12=-1, dRjj23=-1, dRjj13=-1;
  dRlj11=-1, dRlj12=-1, dRlj13=-1, dRlj21=-1, dRlj22=-1, dRlj23=-1;
  dRlb11=-1, dRlb21=-1;
  MSSSF=-1, Mbl11=-1, Mbl12=-1, Mbl21=-1, Mbl22=-1, Mlj11=-1, Mlj12=-1, Mlj13=-1, Mlj21=-1, Mlj22=-1, Mlj23=-1;
  MTvl1=-1, MTvl2=-1, Mllj1=-1, Mllj2=-1, Mllj3=-1, Mllj4=-1, Mllb1=-1, Mllb2=-1;
  Mlljj12=-1, Mlljj13=-1, Mlljj14=-1, Mlljj23=-1, Mlljj24=-1, Mlljj34=-1;
  Mljj112=-1, Mljj113=-1, Mljj114=-1, Mljj123=-1, Mljj124=-1, Mljj134=-1;
  Mljj212=-1, Mljj213=-1, Mljj214=-1, Mljj223=-1, Mljj224=-1, Mljj234=-1;
  Mjj12=-1, Mjj13=-1, Mjj14=-1, Mjj23=-1, Mjj24=-1, Mjj34=-1;
  MllW_2jL=-1, MllW_1jL=-1, MllW1_H=-1, MllW2_H=-1, MjjW1=-1, MjjW2=-1;
  Ml1W_2jL=-1, Ml1W_1jL=-1, Ml2W_2jL=-1, Ml2W_1jL=-1, Ml1W1_H=-1, Ml1W2_H=-1, Ml2W1_H=-1, Ml2W2_H=-1;
  w_tot=-1;

}



HNL_SR3KinVar::HNL_SR3KinVar(){

  tree_mm = new TTree("Tree_mm", "Tree_mm");
  tree_ee = new TTree("Tree_ee", "Tree_ee");

}


HNL_SR3KinVar::~HNL_SR3KinVar(){

  delete tree_mm;
  delete tree_ee;

}


void HNL_SR3KinVar::WriteHist(){

  outfile->cd();
  tree_mm->Write();
  tree_ee->Write();
  outfile->cd();

}
