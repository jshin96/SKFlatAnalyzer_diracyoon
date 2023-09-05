#include "GenSigStudy.h"

void GenSigStudy::initializeAnalyzer(){

  All2l=false, SS2l=false, OS2l=false;
  TrAccCheck=false, TrRateCheck=false;
  FakeRun=false, ConvRun=false, FlipRun=false, SystRun=false; 
  for(unsigned int i=0; i<Userflags.size(); i++){
    if(Userflags.at(i).Contains("All2l"))      All2l      = true;
    if(Userflags.at(i).Contains("OS2l"))       OS2l       = true;
    if(Userflags.at(i).Contains("SS2l"))       SS2l       = true;
    if(Userflags.at(i).Contains("TrAccCheck") ) TrAccCheck  = true;
    if(Userflags.at(i).Contains("TrRateCheck")) TrRateCheck = true;
    if(Userflags.at(i).Contains("FakeRun"))    FakeRun    = true; 
    if(Userflags.at(i).Contains("ConvRun"))    ConvRun    = true; 
    if(Userflags.at(i).Contains("FlipRun"))    FlipRun    = true; 
    if(Userflags.at(i).Contains("SystRun"))    SystRun    = true; 
  }

  DblMu=false, DblEG=false, MuEG=false;
  if     (DataStream.Contains("DoubleMuon")) DblMu=true;
  else if(DataStream.Contains("MuonEG"))     MuEG =true;
  else if(DataStream.Contains("DoubleEG"))   DblEG=true;
  else if(DataYear==2018 and DataStream.Contains("EGamma")) DblEG=true;

  if(GetEraShort()=="2016a"){
    TrigList_SglMu = {"HLT_IsoMu24_v", "HLT_IsoTkMu24_v"}; TrigList_SglEl = {"HLT_Ele27_WPTight_Gsf_v"};
    TrigList_DblMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v", "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v"};
    TrigList_DblEG = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"};
    TrigList_MuEG  = {"HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v", "HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_v"};
  }
  else if(GetEraShort()=="2016b"){
    TrigList_SglMu = {"HLT_IsoMu24_v", "HLT_IsoTkMu24_v"}; TrigList_SglEl = {"HLT_Ele27_WPTight_Gsf_v"};
    TrigList_DblMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v", "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v", "HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v"};
    TrigList_DblEG = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"};
    TrigList_MuEG  = {"HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v", "HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"};
  }
  else if(DataYear==2017){
    TrigList_SglMu = {"HLT_IsoMu27_v"}; TrigList_SglEl = {"HLT_Ele32_WPTight_Gsf_L1DoubleEG_v"};
    TrigList_DblMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v", "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v"};
    TrigList_DblEG = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v"};
    TrigList_MuEG  = {"HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v", "HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v"};
  }
  else if(DataYear==2018){
    TrigList_SglMu = {"HLT_IsoMu24_v"}; TrigList_SglEl = {"HLT_Ele32_WPTight_Gsf_v"};
    TrigList_DblMu = {"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v", "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_v"};
    TrigList_DblEG = {"HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v"};
    TrigList_MuEG  = {"HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v", "HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_v"};
  }


  //Set up the tagger map only for the param settings to be used.
  vector<JetTagging::Parameters> jtps;
  jtps.push_back( JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets) );
  mcCorr->SetJetTaggingParameters(jtps);


  outfile->cd();
}


void GenSigStudy::executeEvent(){


  Event ev = GetEvent();
  float weight = 1., w_GenNorm=1., w_BR=1., w_PU=1.;
  if(!IsDATA){
    w_GenNorm = MCweight()*GetKFactor()*ev.GetTriggerLumi("Full");
    w_BR      = GetBRWeight();
    w_PU      = GetPileUpWeight(nPileUp, 0);
    weight *= w_GenNorm * w_BR * w_PU;
  }
  FillHist("CutFlow", 0., weight, 20, 0., 20.);

  bool PassTrig=false;
  if(All2l or SS2l or OS2l){ PassTrig = ev.PassTrigger(TrigList_DblEG) or ev.PassTrigger(TrigList_DblMu); }
  if(TrAccCheck or TrRateCheck) PassTrig=true;
  if(!PassTrig) return;
  FillHist("CutFlow", 1., weight, 20, 0., 20.);
  if(!PassMETFilter()) return;
  FillHist("CutFlow", 2., weight, 20, 0., 20.);

  bool PreCutPass=false;
  vector<Muon>     muonPreColl     = GetMuons("NOCUT", 5., 2.4);
  vector<Electron> electronPreColl = GetElectrons("NOCUT", 5., 2.5);
  sort(muonPreColl.begin(), muonPreColl.end(), PtComparing);
  sort(electronPreColl.begin(), electronPreColl.end(), PtComparing);
  int NPreMu=muonPreColl.size(), NPreEl=electronPreColl.size();
  if(SS2l){
    if( (NPreMu+NPreEl)>2 ) PreCutPass=true;
    else if(NPreMu==2 and SumCharge(muonPreColl)!=0) PreCutPass=true;
    else if(NPreEl==2 and SumCharge(electronPreColl)!=0) PreCutPass=true;
  }
  if((All2l or OS2l) && (NPreMu+NPreEl)>1 && NPreEl>0) PreCutPass=true;
  if(TrAccCheck or TrRateCheck) PreCutPass=true;
  
  if(!PreCutPass) return;


  TString IDSSLabel = "SS", TLabel = FakeRun? "L":"T";
  TString MuTID = "TopHNT", MuLID = "TopHNL";
  TString ElTID = "TopHNSST", ElLID = "TopHNSSL_"+GetEraShort(), ElVID = "TopHNL_"+GetEraShort();
  float PTminEl = ElTID.Contains("SS")? 15.:10.;
  vector<Muon>     muonTightColl     = SelectMuons(muonPreColl, MuTID, 10., 2.4);
  vector<Electron> electronTightColl = SelectElectrons(electronPreColl, ElTID, PTminEl, 2.5);
  vector<Muon>     muonLooseColl     = SelectMuons(muonPreColl, MuLID, 10., 2.4);
  vector<Electron> electronLooseColl = SelectElectrons(electronPreColl, ElLID, PTminEl, 2.5);
  vector<Muon>     muonVetoColl      = SelectMuons(muonPreColl, MuLID, 10., 2.4);
  vector<Electron> electronVetoColl  = SelectElectrons(electronPreColl, ElVID, 10., 2.5);


  JetTagging::Parameters param_jets = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
  vector<Jet> jetPreColl = GetAllJets();
  sort(jetPreColl.begin(), jetPreColl.end(), PtComparing);
  vector<Jet> jetColl  = SelectJets(jetPreColl, muonLooseColl, electronVetoColl, "tight", 25., 2.4, "LVeto");
  vector<Jet> bjetColl = SelBJets(jetColl, param_jets);


  Particle vMET_T1xy = GetvMET("PUPPIMETT1xyCorr");


  bool FillGenColl = TrAccCheck or TrRateCheck;
  if(FillGenColl) truthColl = GetGens();

  bool EventCand = false;
  if(All2l or SS2l or OS2l){
    EventCand = (muonTightColl.size()+electronTightColl.size())==2;
  }
  if(TrAccCheck or TrRateCheck) EventCand=false;

  float w_TopPtRW = 1., w_Prefire = 1., sf_Trig = 1., w_FR=1.;
  float sf_MuTk = 1., sf_MuID = 1., sf_MuIso = 1., sf_ElReco = 1., sf_ElID = 1., sf_BTag = 1.;
  if((!IsDATA) and EventCand){
    //w_TopPtRW = mcCorr->GetTopPtReweight(truthColl);
    //sf_MuID   = GetMuonSF(muonTightColl, "TopHNID_TkMu", "ID");
    sf_ElReco = GetElectronSF(electronTightColl, "", "Reco");
    sf_ElID   = GetElectronSF(electronTightColl, ElTID, "ID");
    sf_BTag   = mcCorr->GetBTaggingReweight_1a(jetColl, param_jets);
    TString SFKey_Trig_All = muonTightColl.size()==2? "DiMuIso_HNTopID":electronTightColl.size()==2? "DiElIso_HNTopIDSS":""; 
    sf_Trig   = SFKey_Trig_All!=""? mcCorr->GetTriggerSF(electronTightColl, muonTightColl, SFKey_Trig_All, ""):1.;
    w_Prefire = GetPrefireWeight(0);
  }
  weight *= w_TopPtRW * w_Prefire * sf_Trig * w_FR;
  weight *= sf_MuTk * sf_MuID * sf_MuIso * sf_ElReco * sf_ElID * sf_BTag;

  if(TrAccCheck ) TrigAccCheck(weight, ""); 
  if(TrRateCheck) RecoTrigRateCheck(muonPreColl, electronPreColl, ev, "TopHNT", "TopHNSST", weight, ""); 
  if(SystRun && ((!IsDATA) or FakeRun)){
  }
}

void GenSigStudy::TrigAccCheck(float weight, TString Label)
{
  if( !(MCSample.Contains("TT_HeavyN") && MCSample.Contains("_2L_")) ) return;

  int NMatchElSig=0, NMatchMuSig=0;
  vector<Gen> l_tlNCands, l_NffCands, l_SigCands;
  for(unsigned int it=2; it<truthColl.size(); it++){
    int PID = truthColl.at(it).PID(), aPID = abs(PID);
    if( !(aPID==11 or aPID==13)  ) continue;

    int MIdx = truthColl.at(it).MotherIndex(), MPID = MIdx>=0? truthColl.at(MIdx).PID():0, aMPID = abs(MPID);
    int GenSt = truthColl.at(it).Status();
    //muon pt is from track; should be close to state after FSR
    //electron pt is from SC, FSR photons and FSR photon->conversion electrons are included in the reco E.
    if(   aPID==11 && PID==MPID  ) continue;
    if(   aPID==13 && GenSt!=1   ) continue;

    int LastSelfIdx = LastSelfMotherIdx(it,truthColl);
    int MIdxOrig = truthColl.at(LastSelfIdx).MotherIndex();
    int MPIDOrig = truthColl.at(MIdxOrig).PID(), aMPIDOrig = abs(MPIDOrig);
    if( aPID==11 ){
      if( aMPID==11 or aMPID==13 or aMPID==15 ) continue;
      if( !(aMPID==6 or aMPID==24 or aMPID>9900000) ) continue;
      l_SigCands.push_back(truthColl.at(it));
      NMatchElSig++;
    }
    if( aPID==13 ){
      if( aMPIDOrig==11 or aMPIDOrig==13 or aMPIDOrig==15 ) continue;
      if( !(aMPIDOrig==6 or aMPIDOrig==24 or aMPIDOrig>9900000) ) continue;
      l_SigCands.push_back(truthColl.at(it));
      NMatchMuSig++;
    }
  }

  sort(l_SigCands.begin(), l_SigCands.end(), PtComparing);

  for(unsigned int il=0; il<l_SigCands.size(); il++){
    int MPID = truthColl.at( l_SigCands.at(il).MotherIndex() ).PID(), aMPID = abs(MPID);
    if(aMPID>9900000) l_NffCands.push_back(l_SigCands.at(il));
    else if(aMPID==6 or aMPID==24) l_tlNCands.push_back(l_SigCands.at(il));
  }
  FillHist("NMatchElSig", NMatchElSig, weight, 10, 0., 10.);
  FillHist("NMatchMuSig", NMatchMuSig, weight, 10, 0., 10.);
  //if(NMatchMuSig!=2){ PrintGen(truthColl); }

  if(l_tlNCands.size()>0 && l_NffCands.size()>0){
    FillHist("PTl_tlNCand"+Label, l_tlNCands.at(0).Pt(), weight, 40, 0., 200.);
    FillHist("PTl_NffCand"+Label, l_NffCands.at(0).Pt(), weight, 40, 0., 200.);
    if( (MCSample.Contains("Mu") && fabs(l_tlNCands.at(0).Eta())<2.4 && fabs(l_NffCands.at(0).Eta())<2.4)
     or (MCSample.Contains("El") && fabs(l_tlNCands.at(0).Eta())<2.5 && fabs(l_NffCands.at(0).Eta())<2.5) ){
      FillHist("PTl_EtaAcc_tlNCand"+Label, l_tlNCands.at(0).Pt(), weight, 40, 0., 200.);
      FillHist("PTl_EtaAcc_NffCand"+Label, l_NffCands.at(0).Pt(), weight, 40, 0., 200.);
    }
  }
  else FillHist("NCount_Not_tlNORNff"+Label, 0., weight, 1, 0., 1.);
  if(l_SigCands.size()>1){
    float PTl1 = l_SigCands.at(0).Pt(), PTl2 = l_SigCands.at(1).Pt();
    float Etal1 = l_SigCands.at(0).Eta(), Etal2 = l_SigCands.at(1).Eta();
    float fEtal1 = fabs(Etal1), fEtal2 = fabs(Etal2);
    //float Mll = (l_SigCands.at(0)+l_SigCands.at(1)).M();
    FillHist("PTl1_Sig"+Label, PTl1, weight, 40, 0., 200.);
    FillHist("PTl2_Sig"+Label, PTl2, weight, 40, 0., 200.);
    if( (MCSample.Contains("Mu") && fEtal1<2.4 && fEtal2<2.4)
     or (MCSample.Contains("El") && fEtal1<2.5 && fEtal2<2.5) ){
      FillHist("PTl1_EtaAcc_Sig"+Label, PTl1, weight, 40, 0., 200.);
      FillHist("PTl2_EtaAcc_Sig"+Label, PTl2, weight, 40, 0., 200.);
    }
    bool PassAcc_2EEta = fEtal1<2.5 && fEtal2<2.5;
    bool PassAcc_2MEta = fEtal1<2.4 && fEtal2<2.4;
    bool PassAcc_2ETr = PTl1>25 && PTl2>15 && fEtal1<2.5 && fEtal2<2.5;
    bool PassAcc_2MTr = PTl1>20 && PTl2>10 && fEtal1<2.4 && fEtal2<2.4;
    bool PassAcc_1MTrv1 = PTl1>27 && PTl2>5 && fEtal1<2.4 && fEtal2<2.4;
    bool PassAcc_1MTrv2 = PTl1>30 && PTl2>5 && fEtal1<2.4 && fEtal2<2.4;
    bool PassAcc_1ETrv1 = PTl1>30 && PTl2>5 && fEtal1<2.5 && fEtal2<2.5;
    bool PassAcc_1ETrv2 = PTl1>35 && PTl2>5 && fEtal1<2.5 && fEtal2<2.5;
    bool PassAcc_Dbl_1MTrv1 = PTl2>27 && fEtal1<2.4 && fEtal2<2.4;
    bool PassAcc_Dbl_1MTrv2 = PTl2>30 && fEtal1<2.4 && fEtal2<2.4;
    bool PassAcc_Dbl_1ETrv1 = PTl2>30 && fEtal1<2.5 && fEtal2<2.5;
    bool PassAcc_Dbl_1ETrv2 = PTl2>35 && fEtal1<2.5 && fEtal2<2.5;
    float LumiRun2 = 19.517+16.812+41.477+59.827;
    float FrLumi16 = (19.517+16.812)/LumiRun2;
    float FrLumi17 = 41.477/LumiRun2;
    float FrLumi18 = 59.827/LumiRun2;

    FillHist("NAcc_2EEta"+Label, 0., weight, 2, 0., 2.);
    if(PassAcc_2EEta ) FillHist("NAcc_2EEta"+Label, 1., weight, 2, 0., 2.);
    FillHist("NAcc_2MEta"+Label, 0., weight, 2, 0., 2.);
    if(PassAcc_2MEta ) FillHist("NAcc_2MEta"+Label, 1., weight, 2, 0., 2.);
    FillHist("NAcc_2ETr"+Label, 0., weight, 2, 0., 2.);
    if(PassAcc_2ETr  ) FillHist("NAcc_2ETr"+Label, 1., weight, 2, 0., 2.);
    FillHist("NAcc_2MTr"+Label, 0., weight, 2, 0., 2.);
    if(PassAcc_2MTr  ) FillHist("NAcc_2MTr"+Label, 1., weight, 2, 0., 2.);
    FillHist("NAcc_1ETrv1"+Label, 0., weight, 2, 0., 2.);
    if(PassAcc_1ETrv1) FillHist("NAcc_1ETrv1"+Label, 1., weight, 2, 0., 2.);
    FillHist("NAcc_1ETrv2"+Label, 0., weight, 2, 0., 2.);
    if(PassAcc_1ETrv2) FillHist("NAcc_1ETrv2"+Label, 1., weight, 2, 0., 2.);
    FillHist("NAcc_1MTrv1"+Label, 0., weight, 2, 0., 2.);
    if(PassAcc_1MTrv1) FillHist("NAcc_1MTrv1"+Label, 1., weight, 2, 0., 2.);
    FillHist("NAcc_1MTrv2"+Label, 0., weight, 2, 0., 2.);
    if(PassAcc_1MTrv2) FillHist("NAcc_1MTrv2"+Label, 1., weight, 2, 0., 2.);
    FillHist("NAcc_1ETrComb"+Label, 0., weight, 2, 0., 2.);
    if(PassAcc_1ETrv1) FillHist("NAcc_1ETrComb"+Label, 1., weight*FrLumi16, 2, 0., 2.);
    if(PassAcc_1ETrv2) FillHist("NAcc_1ETrComb"+Label, 1., weight*(FrLumi17+FrLumi18), 2, 0., 2.);
    FillHist("NAcc_1MTrComb"+Label, 0., weight, 2, 0., 2.);
    if(PassAcc_1MTrv1) FillHist("NAcc_1MTrComb"+Label, 1., weight*(FrLumi16+FrLumi18), 2, 0., 2.);
    if(PassAcc_1MTrv2) FillHist("NAcc_1MTrComb"+Label, 1., weight*FrLumi17, 2, 0., 2.);
    if(PassAcc_2ETr ) FillHist("NAcc2EBoost_1ETrv1"+Label, 0., weight, 2, 0., 2.);
    if(PassAcc_2ETr && PassAcc_Dbl_1ETrv1 ) FillHist("NAcc2EBoost_1ETrv1"+Label, 1., weight, 2, 0., 2.);
    if(PassAcc_2ETr ) FillHist("NAcc2EBoost_1ETrv2"+Label, 0., weight, 2, 0., 2.);
    if(PassAcc_2ETr && PassAcc_Dbl_1ETrv2 ) FillHist("NAcc2EBoost_1ETrv2"+Label, 1., weight, 2, 0., 2.);
    if(PassAcc_2MTr ) FillHist("NAcc2MBoost_1MTrv1"+Label, 0., weight, 2, 0., 2.);
    if(PassAcc_2MTr && PassAcc_Dbl_1MTrv1 ) FillHist("NAcc2MBoost_1MTrv1"+Label, 1., weight, 2, 0., 2.);
    if(PassAcc_2MTr ) FillHist("NAcc2MBoost_1MTrv2"+Label, 0., weight, 2, 0., 2.);
    if(PassAcc_2MTr && PassAcc_Dbl_1MTrv2 ) FillHist("NAcc2MBoost_1MTrv2"+Label, 1., weight, 2, 0., 2.);
  }
  else FillHist("NCount_Not_2lSig"+Label, 0., weight, 1, 0., 1.);

}


void GenSigStudy::RecoTrigRateCheck(vector<Muon>& MuPreColl, vector<Electron>& ElPreColl, Event& Ev, TString MuTID, TString ElTID, float weight, TString Label)
{

  vector<Muon> MuRecoColl; vector<Electron> ElRecoColl;
  vector<Muon> MuIDColl; vector<Electron> ElIDColl;
  int NPrMuReco=0, NPrMuID=0, NPrElReco=0, NPrElID=0;
  int Q1stPrMuReco=0, Q1stPrElReco=0, Q1stPrMuID=0, Q1stPrElID=0;
  for(unsigned int im=0; im<MuPreColl.size(); im++){
    Muon* Mu = &MuPreColl.at(im);
    if(Mu->Pt()<5) continue; 
    //bool PassID = Mu->PassID(MuTID), CheckType = MCSample.Contains("powheg")? PassID:true;
    bool CheckType=true;
    int LepType = CheckType? GetLeptonType(*Mu, truthColl):0;
    if(MCSample.Contains("TT_HeavyN") && LepType>0){
      MuRecoColl.push_back(*Mu);
      if(Mu->PassID(MuTID)) MuIDColl.push_back(*Mu);
    }
    else{
      if(LepType>0){
        if     (NPrMuReco==0              ){ MuRecoColl.push_back(*Mu); Q1stPrMuReco=Mu->Charge(); }
        else if(Mu->Charge()==Q1stPrMuReco)  MuRecoColl.push_back(*Mu);
        if(Mu->PassID(MuTID)){
          if     (NPrMuID==0              ){ MuIDColl.push_back(*Mu); Q1stPrMuID=Mu->Charge(); }
          else if(Mu->Charge()==Q1stPrMuID)  MuIDColl.push_back(*Mu);
        }
      }
      else{
        MuRecoColl.push_back(*Mu);
        if(Mu->PassID(MuTID)) MuIDColl.push_back(*Mu);
      }
    }
  }
  for(unsigned int im=0; im<ElPreColl.size(); im++){
    Electron* El = &ElPreColl.at(im);
    if(El->Pt()<5) continue; 
    //bool PassID = El->PassID(ElTID), CheckType = MCSample.Contains("powheg")? PassID:true;
    bool CheckType=true;
    int LepType = CheckType? GetLeptonType(*El, truthColl):0;
    if(MCSample.Contains("TT_HeavyN") && LepType>0){
      ElRecoColl.push_back(*El);
      if(El->PassID(ElTID)) ElIDColl.push_back(*El);
    }
    else{
      if(LepType>0){
        if     (NPrElReco==0              ){ ElRecoColl.push_back(*El); Q1stPrElReco=El->Charge(); }
        else if(El->Charge()==Q1stPrElReco)  ElRecoColl.push_back(*El);
        if(El->PassID(ElTID)){
          if     (NPrElID==0              ){ ElIDColl.push_back(*El); Q1stPrElID=El->Charge(); }
          else if(El->Charge()==Q1stPrElID)  ElIDColl.push_back(*El);
        }
      }
      else{
        ElRecoColl.push_back(*El);
        if(El->PassID(ElTID)) ElIDColl.push_back(*El);
      }
    }
  }

  float sf_MuID   = GetMuonSF(MuIDColl, MuTID, "ID");
  float sf_ElReco = GetElectronSF(ElIDColl, "", "Reco");
  float sf_ElID   = GetElectronSF(ElIDColl, ElTID, "ID");
  float w_Pref = GetPrefireWeight(0);

  //check rate without ID effect; Reco+Acc+Tr
  FillHist("NRecoAcc_2MTr"+Label, 0., weight, 2, 0., 2.);
  FillHist("NRecoAcc_1MTr"+Label, 0., weight, 2, 0., 2.);
  FillHist("NRecoAccTr_2MTr"+Label, 0., weight, 2, 0., 2.);
  FillHist("NRecoAccTr_1MTr"+Label, 0., weight, 2, 0., 2.);
  FillHist("NRecoAccTr_1MOR2MTr"+Label, 0., weight, 2, 0., 2.);
  if(MuRecoColl.size()>1 && MuRecoColl.at(0).Charge()==MuRecoColl.at(1).Charge()){ 
    float PTl1 = MuRecoColl.at(0).Pt(), PTl2 = MuRecoColl.at(1).Pt();
    float Mll = (MuRecoColl.at(0)+MuRecoColl.at(1)).M();
    bool PassEtaAcc = fabs(MuRecoColl.at(0).Eta())<2.4 && fabs(MuRecoColl.at(1).Eta())<2.4;
    bool PassAcc_2MTr = PTl1>20 && PTl2>10 && Mll>4 && PassEtaAcc;
    bool PassAcc_1MTr = DataYear!=2017? PTl1>27 && PassEtaAcc: PTl1>30 && PassEtaAcc;
    bool PassAccTr_2MTr = PassAcc_2MTr && Ev.PassTrigger(TrigList_DblMu);
    bool PassAccTr_1MTr = PassAcc_1MTr && Ev.PassTrigger(TrigList_SglMu);
    bool PassAccTr_1MOR2MTr = PassAcc_2MTr && (Ev.PassTrigger(TrigList_SglMu) or Ev.PassTrigger(TrigList_DblMu));
    if(PassAcc_2MTr) FillHist("NRecoAcc_2MTr"+Label, 1., weight*w_Pref, 2, 0., 2.);
    if(PassAcc_1MTr) FillHist("NRecoAcc_1MTr"+Label, 1., weight*w_Pref, 2, 0., 2.);
    if(PassAccTr_2MTr) FillHist("NRecoAccTr_2MTr"+Label, 1., weight*w_Pref, 2, 0., 2.);
    if(PassAccTr_1MTr) FillHist("NRecoAccTr_1MTr"+Label, 1., weight*w_Pref, 2, 0., 2.);
    if(PassAccTr_1MOR2MTr) FillHist("NRecoAccTr_1MOR2MTr"+Label, 1., weight*w_Pref, 2, 0., 2.);
  }
  FillHist("NRecoAcc_2ETr"+Label, 0., weight, 2, 0., 2.);
  FillHist("NRecoAcc_1ETr"+Label, 0., weight, 2, 0., 2.);
  FillHist("NRecoAccTr_2ETr"+Label, 0., weight, 2, 0., 2.);
  FillHist("NRecoAccTr_1ETr"+Label, 0., weight, 2, 0., 2.);
  FillHist("NRecoAccTr_1EOR2ETr"+Label, 0., weight, 2, 0., 2.);
  if(ElRecoColl.size()>1 && ElRecoColl.at(0).Charge()==ElRecoColl.at(1).Charge()){ 
    float PTl1 = ElRecoColl.at(0).Pt(), PTl2 = ElRecoColl.at(1).Pt();
    bool PassEtaAcc = fabs(ElRecoColl.at(0).Eta())<2.5 && fabs(ElRecoColl.at(1).Eta())<2.5;
    bool PassAcc_2ETr = PTl1>25 && PTl2>15 && PassEtaAcc;
    bool PassAcc_1ETr = DataYear!=2016? PTl1>35 && PassEtaAcc: PTl1>30 && PassEtaAcc;
    bool PassAccTr_2ETr = PassAcc_2ETr && Ev.PassTrigger(TrigList_DblEG);
    bool PassAccTr_1ETr = PassAcc_1ETr && Ev.PassTrigger(TrigList_SglEl);
    bool PassAccTr_1EOR2ETr = PassAcc_2ETr && (Ev.PassTrigger(TrigList_SglEl) or Ev.PassTrigger(TrigList_DblEG));
    if(PassAcc_2ETr) FillHist("NRecoAcc_2ETr"+Label, 1., weight*w_Pref*sf_ElReco, 2, 0., 2.);
    if(PassAcc_1ETr) FillHist("NRecoAcc_1ETr"+Label, 1., weight*w_Pref*sf_ElReco, 2, 0., 2.);
    if(PassAccTr_2ETr) FillHist("NRecoAccTr_2ETr"+Label, 1., weight*w_Pref*sf_ElReco, 2, 0., 2.);
    if(PassAccTr_1ETr) FillHist("NRecoAccTr_1ETr"+Label, 1., weight*w_Pref*sf_ElReco, 2, 0., 2.);
    if(PassAccTr_1EOR2ETr) FillHist("NRecoAccTr_1EOR2ETr"+Label, 1., weight*w_Pref*sf_ElReco, 2, 0., 2.);
  }


  //ID+Reco+Acc+Tr check
  FillHist("NIDAcc_2MTr"+Label, 0., weight, 2, 0., 2.);
  FillHist("NIDAcc_1MTr"+Label, 0., weight, 2, 0., 2.);
  FillHist("NIDAccTr_2MTr"+Label, 0., weight, 2, 0., 2.);
  FillHist("NIDAccTr_1MTr"+Label, 0., weight, 2, 0., 2.);
  FillHist("NIDAccTr_1MOR2MTr"+Label, 0., weight, 2, 0., 2.);
  if(MuIDColl.size()==2 && MuIDColl.at(0).Charge()==MuIDColl.at(1).Charge()){ 
    float PTl1 = MuIDColl.at(0).Pt(), PTl2 = MuIDColl.at(1).Pt();
    float Mll = (MuIDColl.at(0)+MuIDColl.at(1)).M();
    bool PassEtaAcc = fabs(MuIDColl.at(0).Eta())<2.4 && fabs(MuIDColl.at(1).Eta())<2.4;
    bool PassAcc_2MTr = PTl1>20 && PTl2>10 && Mll>4 && PassEtaAcc;
    bool PassAcc_1MTr = DataYear!=2017? PTl1>27 && PassEtaAcc: PTl1>30 && PassEtaAcc;
    bool PassAccTr_2MTr = PassAcc_2MTr && Ev.PassTrigger(TrigList_DblMu);
    bool PassAccTr_1MTr = PassAcc_1MTr && Ev.PassTrigger(TrigList_SglMu);
    bool PassAccTr_1MOR2MTr = PassAcc_2MTr && (Ev.PassTrigger(TrigList_SglMu) or Ev.PassTrigger(TrigList_DblMu));
    if(PassAcc_2MTr) FillHist("NIDAcc_2MTr"+Label, 1., weight*w_Pref*sf_MuID, 2, 0., 2.);
    if(PassAcc_1MTr) FillHist("NIDAcc_1MTr"+Label, 1., weight*w_Pref*sf_MuID, 2, 0., 2.);
    if(PassAccTr_2MTr) FillHist("NIDAccTr_2MTr"+Label, 1., weight*w_Pref*sf_MuID, 2, 0., 2.);
    if(PassAccTr_1MTr) FillHist("NIDAccTr_1MTr"+Label, 1., weight*w_Pref*sf_MuID, 2, 0., 2.);
    if(PassAccTr_1MOR2MTr) FillHist("NIDAccTr_1MOR2MTr"+Label, 1., weight*w_Pref*sf_MuID, 2, 0., 2.);
  }
  FillHist("NIDAcc_2ETr"+Label, 0., weight, 2, 0., 2.);
  FillHist("NIDAcc_1ETr"+Label, 0., weight, 2, 0., 2.);
  FillHist("NIDAccTr_2ETr"+Label, 0., weight, 2, 0., 2.);
  FillHist("NIDAccTr_1ETr"+Label, 0., weight, 2, 0., 2.);
  FillHist("NIDAccTr_1EOR2ETr"+Label, 0., weight, 2, 0., 2.);
  if(ElIDColl.size()==2 && ElIDColl.at(0).Charge()==ElIDColl.at(1).Charge()){ 
    float PTl1 = ElIDColl.at(0).Pt(), PTl2 = ElIDColl.at(1).Pt();
    bool PassEtaAcc = fabs(ElIDColl.at(0).Eta())<2.5 && fabs(ElIDColl.at(1).Eta())<2.5;
    bool PassAcc_2ETr = PTl1>25 && PTl2>15 && PassEtaAcc;
    bool PassAcc_1ETr = DataYear!=2016? PTl1>35 && PassEtaAcc: PTl1>30 && PassEtaAcc;
    bool PassAccTr_2ETr = PassAcc_2ETr && Ev.PassTrigger(TrigList_DblEG);
    bool PassAccTr_1ETr = PassAcc_1ETr && Ev.PassTrigger(TrigList_SglEl);
    bool PassAccTr_1EOR2ETr = PassAcc_2ETr && (Ev.PassTrigger(TrigList_SglEl) or Ev.PassTrigger(TrigList_DblEG));
    if(PassAcc_2ETr) FillHist("NIDAcc_2ETr"+Label, 1., weight*w_Pref*sf_ElReco*sf_ElID, 2, 0., 2.);
    if(PassAcc_1ETr) FillHist("NIDAcc_1ETr"+Label, 1., weight*w_Pref*sf_ElReco*sf_ElID, 2, 0., 2.);
    if(PassAccTr_2ETr) FillHist("NIDAccTr_2ETr"+Label, 1., weight*w_Pref*sf_ElReco*sf_ElID, 2, 0., 2.);
    if(PassAccTr_1ETr) FillHist("NIDAccTr_1ETr"+Label, 1., weight*w_Pref*sf_ElReco*sf_ElID, 2, 0., 2.);
    if(PassAccTr_1EOR2ETr) FillHist("NIDAccTr_1EOR2ETr"+Label, 1., weight*w_Pref*sf_ElReco*sf_ElID, 2, 0., 2.);
  }

}


GenSigStudy::GenSigStudy(){


}


GenSigStudy::~GenSigStudy(){


}

