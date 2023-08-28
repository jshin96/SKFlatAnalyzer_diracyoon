#include "MeasCFlipRate.h"

void MeasCFlipRate::initializeAnalyzer(){

  All2l=false, SS2l=false, OS2l=false;
  CFlip=false, MCCFRate=false, CFMCClos=false, MDists=false, PTScale=false;
  FakeRun=false, ConvRun=false, FlipRun=false, SystRun=false; 
  for(unsigned int i=0; i<Userflags.size(); i++){
    if(Userflags.at(i).Contains("All2l"))      All2l      = true;
    if(Userflags.at(i).Contains("OS2l"))       OS2l       = true;
    if(Userflags.at(i).Contains("SS2l"))       SS2l       = true;
    if(Userflags.at(i).Contains("CFlip"))      CFlip      = true;
    if(Userflags.at(i).Contains("CFMCClos"))   CFMCClos   = true;
    if(Userflags.at(i).Contains("MDists"))     MDists     = true;
    if(Userflags.at(i).Contains("PTScale"))    PTScale    = true;
    if(Userflags.at(i).Contains("MCCFRate"))   MCCFRate   = true;
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

  if(DataYear==2016){
    TrigList_DblEG.push_back("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v");
  }
  if(DataYear==2017){
    TrigList_DblEG.push_back("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v");
  }
  if(DataYear==2018){
    TrigList_DblEG.push_back("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v");
  }

  //Set up the tagger map only for the param settings to be used.
  vector<JetTagging::Parameters> jtps;
  jtps.push_back( JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets) );
  mcCorr->SetJetTaggingParameters(jtps);

  TString SKOutPath=getenv("SKFlatOutputDir"), SKFlatV=getenv("SKFlatV"), SpecDir="TopHNSST/EleOnly/";
  TString FileDir = SKOutPath+"/"+SKFlatV+"/MeasCFlipRate/"+GetEraShort()+"/All2l/MCCFRate/"+SpecDir+"BkdMC/";
  f_CFR_DY = new TFile(FileDir+"MeasCFlipRate_DYJetsToEE_MiNNLO.root");
  //f_CFR_TT = new TFile(FileDir+"MeasCFlipRate_TTLL_powheg.root");

  outfile->cd();
}


void MeasCFlipRate::executeEvent(){


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
  if(All2l or SS2l or OS2l){ PassTrig = ev.PassTrigger(TrigList_DblEG); }
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
  
  if(!PreCutPass) return;


  TString IDSSLabel = "SS", TLabel = FakeRun? "L":"T";
  TString MuTID = "TopHNT", MuLID = "TopHNL";
  TString ElTID = "TopHNSST", ElLID = "TopHNSSL_"+GetEraShort(), ElVID = ElLID;
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
  vector<Jet> jetColl  = SelectJets(jetPreColl, muonLooseColl, electronVetoColl, "tightLepVeto", 25., 2.4, "LVeto");
  vector<Jet> bjetColl = SelBJets(jetColl, param_jets);


  //Particle vMET = ev.GetMETVector();
  //Particle vMET_xyCorr(pfMET_Type1_PhiCor_pt*TMath::Cos(pfMET_Type1_PhiCor_phi), pfMET_Type1_PhiCor_pt*TMath::Sin(pfMET_Type1_PhiCor_phi), 0., pfMET_Type1_PhiCor_pt);
  Particle vMET        = GetvMET("PUPPIMETT1");
  Particle vMET_xyCorr = GetvMET("PUPPIMETT1xyCorr");

  bool FillGenColl = MDists or MCCFRate or CFMCClos or PTScale;
  if(FillGenColl) truthColl = GetGens();

  bool EventCand = false;
  if(All2l or SS2l or OS2l){
    EventCand = (muonTightColl.size()+electronTightColl.size())==2;
    if(MCCFRate or CFMCClos or MDists or PTScale) EventCand = EventCand && electronTightColl.size()>0;
  }

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
    //sf_Trig   = SS2l or OS2l? mcCorr->GetTriggerSF(electronTightColl, muonTightColl, SFKey_Trig_All, ""):1.;
    w_Prefire = GetPrefireWeight(0);
    //cout<<" w_PU:"<<w_PU<<" w_Prefire:"<<w_Prefire<<" sf_Trig:"<<sf_Trig<<endl;
    //cout<<"sf_MuTk"<<sf_MuTk<<" sf_MuID:"<<sf_MuID<<" sf_MuIso:"<<sf_MuIso<<" sf_ElReco:"<<sf_ElReco<<" sf_ElID:"<<sf_ElID<<" sf_BTag:"<<sf_BTag<<endl;
  }
  weight *= w_TopPtRW * w_Prefire * sf_Trig * w_FR;
  weight *= sf_MuTk * sf_MuID * sf_MuIso * sf_ElReco * sf_ElID * sf_BTag;

 
  if(All2l){
    if(MCCFRate){ MeasMCCFRate(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
                               jetColl, bjetColl, vMET_xyCorr, weight, ""); }
    if(CFMCClos){ CheckMCCFClosure(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
                                 jetColl, bjetColl, vMET_xyCorr, weight, ""); }
    if(MDists){ GetMassDists(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
                             jetColl, bjetColl, vMET_xyCorr, weight, ""); }
    if(PTScale){ MeasMCPTScale(muonTightColl, muonLooseColl, muonVetoColl, electronTightColl, electronLooseColl, electronVetoColl,
                               jetColl, bjetColl, vMET_xyCorr, weight, ""); }
  }
  if(SystRun && ((!IsDATA) or FakeRun)){
  }
}


void MeasCFlipRate::GetMassDists(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                                 vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                                 vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{
  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  bool IsSS2l=false;  double Mll=-1.;
  if( FakeRun      and weight==0.  ) return; 
  if( !( NElT==2   and NMuT==0 ) ) return;
  if( !(NMuT==NMuL and NElT==NElL) ) return;
  if( !(NMuT==NMuV and NElT==NElV) ) return;
  if(NElT==2){
    if( ElTColl.at(0).Charge()==ElTColl.at(1).Charge()  ) IsSS2l=true;
    if(!(ElTColl.at(0).Pt()>25 && ElTColl.at(1).Pt()>15)) return;
    Mll = (ElTColl.at(0)+ElTColl.at(1)).M();
    if( !(Mll>60. && Mll<120.) ) return;
  }
  else return;

  if(IsSS2l) Label="_SS"+Label;
  else       Label="_OS"+Label;

  int IdxFlipped=-1;
  float CFSF1=1., CFSF2=1.;
  vector<TString> IterStrList = {"_It1", "_It2", "_It3", "_It4", "_It5", "_It6"}; //{"_It1", "_It2", "_It3", "_It4", "_It5", "_It6"};
  if( (!IsDATA) ){
    int NFk=0, NFlip=0, NCv=0;
    for(unsigned int ie=0; ie<ElTColl.size(); ie++){
      Electron* El(&ElTColl.at(ie));
      int LepType = GetLeptonType_JH(ElTColl.at(ie), truthColl);
      if(LepType<0 && LepType>-5) NFk++;
      else if(LepType<-4) NCv++;
      else if(LepType>0){
        int Idx_Closest    = GenMatchedIdx(*El,truthColl); 
        int IdxType_NearEl = LepType>3? GetPrElType_InSameSCRange(Idx_Closest, truthColl, "IdxType"):Idx_Closest;
        int Idx_NearEl     = LepType>3? IdxType_NearEl/10:Idx_Closest;
        if(El->Charge()*truthColl.at(Idx_NearEl).PID()>0){
          NFlip++; IdxFlipped=ie;
          for(unsigned int it=0; it<IterStrList.size(); it++){
            CFSF1 *= GetCFRSF(*El, "App2Bin1"+IterStrList.at(it)); CFSF2 *= GetCFRSF(*El, "App2Bin2"+IterStrList.at(it));
            //printf("%s, %f %f\n", IterStrList.at(it).Data(), CFSF1, CFSF2);
          }
        }
      } 
    }
    if( !(NFk==0 && NCv==0)  ) return;
    if(   IsSS2l && NFlip==0 ) return;
  }

  vector<float> fEtaEdges   = {0., 1.5, 2.5};
  vector<float> PTEdges     = {15., 35., 50., 200.};
  vector<float> fEtaEdges1D = {0., 0.8, 1.5, 2., 2.5};
  for(unsigned int ie=0; ie<ElTColl.size(); ie++){
    float PT=ElTColl.at(ie).Pt(), fEta=fabs(ElTColl.at(ie).Eta());
    int Nbins = (fEtaEdges.size()-1)*(PTEdges.size()-1), Nbins1D = fEtaEdges1D.size()-1;
    int TmpBinIndex1=0, TmpBinIndex2=0;
    for(unsigned int ieta=0; ieta<fEtaEdges.size()-1; ieta++){
    for(unsigned int ipt=0 ; ipt<PTEdges.size()-1; ipt++){
      if( !(fEta>=fEtaEdges.at(ieta) && fEta<fEtaEdges.at(ieta+1)) ) continue;
      if( !(  PT>=PTEdges.at(ipt)    &&   PT<PTEdges.at(ipt+1)   ) ) continue;
        TmpBinIndex1 = ieta*(PTEdges.size()-1)+ipt+1;
    }}
    for(unsigned int ieta=0; ieta<fEtaEdges1D.size()-1; ieta++){
      if( !(fEta>=fEtaEdges1D.at(ieta) && fEta<fEtaEdges1D.at(ieta+1)) ) continue;
        TmpBinIndex2 = ieta+1;
    }

    if(TmpBinIndex1!=0){
      TString TmpBinIdxStr1 = TString::Itoa(TmpBinIndex1,10);
      FillHist("Mll_App2Bin1_"+TmpBinIdxStr1+Label, Mll, weight*CFSF1, 60, 60., 120.);
      if(!IsDATA){
        FillHist("NCnt_App2Bin1"+Label, TmpBinIndex1, weight*CFSF1, Nbins+1, 0., Nbins+1);
        if(IdxFlipped==(int) ie) FillHist("NCntCF_App2Bin1"+Label, TmpBinIndex1, weight*CFSF1, Nbins+1, 0., Nbins+1);
      }
    }
    if(TmpBinIndex2!=0){
      TString TmpBinIdxStr2 = TString::Itoa(TmpBinIndex2,10);
      FillHist("Mll_App2Bin2_"+TmpBinIdxStr2+Label, Mll, weight*CFSF2, 60, 60., 120.);
      if(!IsDATA){
        FillHist("NCnt_App2Bin2"+Label, TmpBinIndex2, weight*CFSF2, Nbins1D+1, 0., Nbins1D+1);
        if(IdxFlipped==(int) ie) FillHist("NCntCF_App2Bin2"+Label, TmpBinIndex2, weight*CFSF2, Nbins1D+1, 0., Nbins1D+1);
      }
    }
  }
}


void MeasCFlipRate::CheckMCCFClosure(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                                     vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                                     vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{
  int NMuT=MuTColl.size(), NElT=ElTColl.size(), NMuL=MuLColl.size(), NElL=ElLColl.size(), NMuV=MuVColl.size(), NElV=ElVColl.size();
  bool IsSS2l=false, IsOnZ=false;
  double Mll=-1., PT1=-1., Eta1=999., PT2=-1., Eta2=999., dRll=-1.;
  if( FakeRun      and weight==0.  ) return; 
  if( !( (NElT==2  and NMuT==0)  ) ) return;
  if( !(NMuT==NMuL and NElT==NElL) ) return;
  if( !(NMuT==NMuV and NElT==NElV) ) return;
  if(NElT==2){
    if( ElTColl.at(0).Charge()==ElTColl.at(1).Charge()  ) IsSS2l=true;
    if(!(ElTColl.at(0).Pt()>25 && ElTColl.at(1).Pt()>15)) return;
    Mll  = (ElTColl.at(0)+ElTColl.at(1)).M();
    dRll = ElTColl.at(0).DeltaR(ElTColl.at(1));
    PT1 = ElTColl.at(0).Pt(), Eta1 = ElTColl.at(0).Eta();
    PT2 = ElTColl.at(1).Pt(), Eta2 = ElTColl.at(1).Eta();
  }
  else return;

  if(fabs(Mll-91.2)<15.) IsOnZ=true;

  //int IdxFlipped=-1;
  if( IsSS2l && (!IsDATA) ){
    int NFk=0, NFlip=0, NCv=0;
    for(unsigned int im=0; im<MuTColl.size(); im++){
      int LepType = GetLeptonType_JH(MuTColl.at(im), truthColl);
      if(LepType<0 && LepType>-5) NFk++;
    }
    for(unsigned int ie=0; ie<ElTColl.size(); ie++){
      int LepType = GetLeptonType_JH(ElTColl.at(ie), truthColl);
      if(LepType<0 && LepType>-5) NFk++;
      else if(LepType<-4) NCv++;
      else if(LepType>0){
        int Idx_Closest    = GenMatchedIdx(ElTColl.at(ie),truthColl); 
        int IdxType_NearEl = LepType>3? GetPrElType_InSameSCRange(Idx_Closest, truthColl, "IdxType"):Idx_Closest;
        int Idx_NearEl     = LepType>3? IdxType_NearEl/10:Idx_Closest;
        if(ElTColl.at(ie).Charge()*truthColl.at(Idx_NearEl).PID()>0){
          NFlip++;// IdxFlipped=ie; 
        }
      } 
    }
    if( !(NFk==0 && NCv==0 && NFlip>0) ) return;
  }


  float CFR1=0., CFR2=0., CFRMCDY=0.;
  //float CFR1=0., CFR2=0., CFRMCDY=0., CFRMCTT=0.;
  for(unsigned int ie=0; ie<ElTColl.size() && !IsSS2l; ie++){
    TString TypeStr=IsDATA? "Data":"MC";
    Electron* El(&ElTColl.at(ie));
    CFR1 += GetCFRSF(*El, "App2Bin1_Fin", TypeStr+"Eff");
    CFR2 += GetCFRSF(*El, "App2Bin2_Fin", TypeStr+"Eff");
    CFRMCDY += GetMCCFR(El->Pt(), fabs(El->Eta()), "h2D_PTfEta_QF_DY");
    //CFRMCTT += GetMCCFR(El->Pt(), fabs(El->Eta()), "h2D_PTfEta_QF_TT");
  }

  vector<TString> AppTagList = {"_App2Bin1", "_App2Bin2", "_CFRMCDY"};
  //vector<TString> AppTagList = {"_App2Bin1", "_App2Bin2", "_CFRMCDY", "_CFRMCTT"};
  vector<TString> MassTagList = {""}; if(IsOnZ) MassTagList.push_back("_OnZ");
  vector<float>   CFRList    = {CFR1, CFR2, CFRMCDY};
  //vector<float>   CFRList    = {CFR1, CFR2, CFRMCDY, CFRMCTT};
  TString TypeStr = IsSS2l? "_Obs":"_Exp";

  //Exp from CFR
  for(unsigned int it=0; it<AppTagList.size(); it++){
  for(unsigned int im=0; im<MassTagList.size(); im++){
    TString AppTag(AppTagList.at(it)), MassTag(MassTagList.at(im));
    float CFR = IsSS2l? 1.:CFRList.at(it);
    //printf("%d %.2e %.2e %.2e %.2e %.2e\n", it, CFR, PT1, Eta1, PT1, Eta2);

    FillHist("PTl1"+MassTag+Label+AppTag+TypeStr, PT1, weight*CFR, 30, 0., 300.); 
    FillHist("PTl2"+MassTag+Label+AppTag+TypeStr, PT2, weight*CFR, 20, 0., 200.); 
    FillHist("Etal1"+MassTag+Label+AppTag+TypeStr, Eta1, weight*CFR, 20, -5., 5.); 
    FillHist("Etal2"+MassTag+Label+AppTag+TypeStr, Eta2, weight*CFR, 20, -5., 5.); 
    FillHist("Mll"+MassTag+Label+AppTag+TypeStr, Mll, weight*CFR, 30, 0., 300.);
    FillHist("dRll"+MassTag+Label+AppTag+TypeStr, dRll, weight*CFR, 25, 0., 5.);
    FillHist("NCnt"+MassTag+Label+AppTag+TypeStr, 0., weight*CFR, 1, 0., 1.);
  }}
}


void MeasCFlipRate::MeasMCCFRate(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                                 vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                                 vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{
  if(IsDATA) return;
  vector<double> PtBinEdges   = {15., 25., 35., 50., 100., 200.};
  vector<double> EtaBinEdges  = {-2.5, -2., -1.47, -0.8, 0., 0.8, 1.47, 2., 2.5};
  vector<double> fEtaBinEdges = {0., 0.8, 1.47, 2., 2.5};

  for(unsigned int ie=0; ie<ElTColl.size(); ie++){
    Electron* El(&ElTColl.at(ie));
    bool IsFlipped=false;
    int ElType = GetLeptonType_JH(*El, truthColl);
    if(ElType<0 or ElType==3) continue;
    else{
      int Idx_Closest    = GenMatchedIdx(*El,truthColl); 
      int IdxType_NearEl = ElType>3? GetPrElType_InSameSCRange(Idx_Closest, truthColl, "IdxType"):Idx_Closest;
      int Idx_NearEl     = ElType>3? IdxType_NearEl/10:Idx_Closest;
      if(El->Charge()*truthColl.at(Idx_NearEl).PID()>0){ IsFlipped=true; }
    } 
  
    double PT = El->Pt(), Eta = El->Eta(), fEta = fabs(Eta);
    TString QLabel = IsFlipped? "_QF":"_QT";
    //float RelIsoNoEA = El->RelIso()+Rho*El->EA()/PT, RelTkIso = El->dr03TkSumPt()/PT ;
    //TString RelIsoTag = RelIsoNoEA<0.06? "_PFIsoNoEAp06":RelIsoNoEA<0.1? "_PFIsoNoEAp1": RelIsoNoEA<0.2? "_PFIsoNoEAp2":"_PRIsoNoEAgtp2";
    //TString TkIsoTag  = RelTkIso<0.06? "_RelTkIsop06":RelTkIso<0.1? "_RelTkIsop1": RelTkIso<0.2? "_RelTkIsop2":"_PRIsoNoEAgtp2";
    //vector<TString> CutTagList = {"", RelIsoTag, TkIsoTag};
    vector<TString> CutTagList = {""};
    for(unsigned int it=0; it<CutTagList.size(); it++){
      TString CutTag(CutTagList.at(it));
      FillHist("h1D_PT"+QLabel+CutTag+Label, PT, weight, PtBinEdges.size()-1, &PtBinEdges[0]);
      FillHist("h1D_Eta"+QLabel+CutTag+Label, Eta, weight, EtaBinEdges.size()-1, &EtaBinEdges[0]);
      FillHist("h2D_PTEta"+QLabel+CutTag+Label, PT, Eta, weight,
                PtBinEdges.size()-1, &PtBinEdges[0], EtaBinEdges.size()-1, &EtaBinEdges[0]);
      FillHist("h2D_PTfEta"+QLabel+CutTag+Label, PT, fEta, weight,
                PtBinEdges.size()-1, &PtBinEdges[0], fEtaBinEdges.size()-1, &fEtaBinEdges[0]);
    }
  }
}


void MeasCFlipRate::MeasMCPTScale(vector<Muon>& MuTColl, vector<Muon>& MuLColl, vector<Muon>& MuVColl,
                                  vector<Electron>& ElTColl, vector<Electron>& ElLColl, vector<Electron>& ElVColl,
                                  vector<Jet>& JetColl, vector<Jet>& BJetColl, Particle& vMET, float weight, TString Label)
{
  if(IsDATA) return;
  vector<double> PtBinEdges   = {15., 25., 35., 50., 100., 200.};
  vector<double> EtaBinEdges  = {-2.5, -2., -1.47, -0.8, 0., 0.8, 1.47, 2., 2.5};
  vector<double> fEtaBinEdges = {0., 0.8, 1.47, 2., 2.5};

  for(unsigned int ie=0; ie<ElTColl.size(); ie++){
    Electron* El(&ElTColl.at(ie));
    bool IsFlipped=false;
    int ElType = GetLeptonType_JH(*El, truthColl);
    double PT = El->Pt(), Eta = El->Eta(), fEta = fabs(Eta), PTGen=0., PTResponse=0.;
    if(ElType<0 or ElType==3) continue;
    else{
      int Idx_Closest    = GenMatchedIdx(*El,truthColl); 
      int IdxType_NearEl = ElType>3? GetPrElType_InSameSCRange(Idx_Closest, truthColl, "IdxType"):Idx_Closest;
      int Idx_NearEl     = ElType>3? IdxType_NearEl/10:Idx_Closest;
      int Idx_NearEl_1st = LastSelfMotherIdx(Idx_NearEl, truthColl);
      PTGen      = Idx_NearEl_1st>1? truthColl.at(Idx_NearEl_1st).Pt():0.;
      PTResponse =          PTGen>0?                          PT/PTGen:0.;
      if(El->Charge()*truthColl.at(Idx_NearEl).PID()>0){ IsFlipped=true; }
    } 
  
    TString QLabel = IsFlipped? "_QF":"_QT";
    vector<TString> NumDenList = {"_SumWPTResponse", "_SumW"};
    for(unsigned int im=0; im<NumDenList.size(); im++){
      TString NumDenTag(NumDenList.at(im));
      float ValZ = NumDenTag!="_SumW"? PTResponse*weight:weight;
      FillHist("h1D_PTGen"+QLabel+NumDenTag+Label, PTGen, ValZ, PtBinEdges.size()-1, &PtBinEdges[0]);
      FillHist("h1D_Eta"+QLabel+NumDenTag+Label, Eta, ValZ, EtaBinEdges.size()-1, &EtaBinEdges[0]);
      FillHist("h2D_PTGenEta"+QLabel+NumDenTag+Label, PTGen, Eta, ValZ,
                PtBinEdges.size()-1, &PtBinEdges[0], EtaBinEdges.size()-1, &EtaBinEdges[0]);
      FillHist("h2D_PTGenfEta"+QLabel+NumDenTag+Label, PTGen, fEta, ValZ,
                PtBinEdges.size()-1, &PtBinEdges[0], fEtaBinEdges.size()-1, &fEtaBinEdges[0]);
    }
  }
}


float MeasCFlipRate::GetFlipCorrPT(Electron& El, TString Tag, TString Option){

  if(!(IsDATA  && Option.Contains("Data"))) return 0.;

  bool DoScale = Option.Contains("Scale"), DoSmear = Option.Contains("Smear");
  float PT=El.Pt(), fEta=fabs(El.Eta());
  int EtaRegIndex1 = fEta<1.47? 0:1;
  int EtaRegIndex2 = fEta<0.8? 0:fEta<1.47? 1: fEta<2.? 2:3;
  int PtRegIndex1  = PT<35? 0:PT<50? 1: 2;
  int PtRegIndex2  = PT<35? 0:PT<50? 1:PT<100? 2:3;
  int BinIndex1 = EtaRegIndex1*3+PtRegIndex1+1; 
  int BinIndex2 = EtaRegIndex2+1; 
  int BinIndex3 = PtRegIndex2 +1; 

  float PTScaleCorr=0., PTResCorr=0., ReturnPT=PT, RelRes=0.;
  if(Tag.Contains("App2Bin1_")){
    int Idx = BinIndex1;
    PTScaleCorr = Idx==1? 0.978:Idx==2? 0.981:Idx==3? 0.988:Idx==4? 0.972:Idx==5? 0.985:Idx==6? 0.990:0.;
    PTResCorr   = Idx==1?  1.38:Idx==2?  1.47:Idx==3?  1.31:Idx==4?  1.15:Idx==5?  1.08:Idx==6? 0.981:0.;
    RelRes      = Idx==1? 0.0322:Idx==2? 0.0276:Idx==3? 0.0264:Idx==4? 0.0388:Idx==5? 0.0375:Idx==6? 0.0382:0.;
  }
  else if(Tag.Contains("App2Bin2_")){
    int Idx = BinIndex2;
    PTScaleCorr = 0.985;
    PTResCorr   = 1.75;
    RelRes      = Idx==1? 0.01:Idx==2? 0.0153:Idx==3? 0.0217:Idx==4? 0.0208:0.;
  }
  else if(Tag.Contains("App2Bin3_")){
    int Idx = BinIndex3;
    PTScaleCorr = Idx==1? 0.976:Idx==2? 0.985:Idx==3? 0.992:Idx==4? 0.999:0.;
    PTResCorr   = Idx==1?  1.29:Idx==2?  1.41:Idx==3?  1.32:Idx==4?  1.18:0.;
    RelRes      = Idx==1? 0.0343:Idx==2? 0.0287:Idx==3? 0.0285:Idx==4? 0.0297:0.;
  }
  PTScaleCorr = 1.-2.*(1.-PTScaleCorr);
  PTResCorr   = 1.-2.*(1.-PTResCorr);

  if(DoScale) ReturnPT = PT*PTScaleCorr;
  if(DoSmear) ReturnPT = ReturnPT*( 1.+gRandom->Gaus(0,RelRes)*sqrt(max(pow(PTResCorr,2.)-1,0.)) );

  return ReturnPT;
}


float MeasCFlipRate::GetCFRSF(Electron& El, TString Tag, TString Option){

  if     (IsDATA  && Option=="") return 1.;
  else if(IsDATA  && Option!="DataEff") return 0.;
  else if(!IsDATA && Option=="DataEff") return 0.;

  bool ReturnMCEff=Option.Contains("MCEff"), ReturnDataEff=Option.Contains("DataEff");
  float PT=min(El.Pt(),199.), fEta=min(fabs(El.Eta()),2.45);

  vector<float> fEtaEdges    = {0., 1.5, 2.5};
  vector<float> PTEdges      = {15., 35., 50., 200.};
  vector<float> fEtaEdges1D  = {0., 0.8, 1.5, 2., 2.5};

  int BinIndex1=0, BinIndex2=0;//, BinIndexMC=0;
  for(unsigned int ieta=0; ieta<fEtaEdges.size()-1; ieta++){
  for(unsigned int ipt=0 ; ipt<PTEdges.size()-1; ipt++){
    if( !(fEta>=fEtaEdges.at(ieta) && fEta<fEtaEdges.at(ieta+1)) ) continue;
    if( !(  PT>=PTEdges.at(ipt)    &&   PT<PTEdges.at(ipt+1)   ) ) continue;
      BinIndex1 = ieta*(PTEdges.size()-1)+ipt+1;
  }}
  for(unsigned int ieta=0; ieta<fEtaEdges1D.size()-1; ieta++){
    if( !(fEta>=fEtaEdges1D.at(ieta) && fEta<fEtaEdges1D.at(ieta+1)) ) continue;
      BinIndex2 = ieta+1;
  }


  float SF=1., MCEff=1., DataEff=1., ReturnVal=1.;
  if(Tag.Contains("App2Bin1_")){
    int Idx = BinIndex1;
    if(GetEraShort()=="2016a"){
      if(Tag.EndsWith("It1")) SF = Idx==1? 0.7763:Idx==2? 0.776021:Idx==3? 0.745748:Idx==4? 0.749913:Idx==5? 0.777415:Idx==6? 0.782312:1.;
      if(Tag.EndsWith("It2")) SF = Idx==1? 1.01195:Idx==2? 1.00527:Idx==3? 0.994333:Idx==4? 0.994527:Idx==5? 0.999886:Idx==6? 1.00454:1.;
      if(Tag.EndsWith("It3")) SF = Idx==1? 1.01125:Idx==2? 1.00407:Idx==3? 0.996186:Idx==4? 0.998612:Idx==5? 0.999565:Idx==6? 1.00152:1.;
      if(Tag.EndsWith("It4")) SF = Idx==1? 1.00978:Idx==2? 1.00289:Idx==3? 0.996665:Idx==4? 0.999627:Idx==5? 0.999735:Idx==6? 1.00046:1.;
      if(Tag.EndsWith("It5")) SF = Idx==1? 1.00843:Idx==2? 1.00195:Idx==3? 0.986327:Idx==4? 0.999861:Idx==5? 0.999849:Idx==6? 1.0001:1.;
      if(Tag.EndsWith("It6")) SF = Idx==1? 1.00767:Idx==2? 1.00146:Idx==3? 0.99029:Idx==4? 1.00005:Idx==5? 0.999972:Idx==6? 1.00001:1.;
      if(Tag.EndsWith("It7")) SF = Idx==1? 1.00686:Idx==2? 1.00099:Idx==3? 0.9929:Idx==4? 1.00013:Idx==5? 0.999967:Idx==6? 0.999954:1.;
      if(Tag.EndsWith("Fin")){
        SF = Idx==1? 0.770188:Idx==2? 0.813516:Idx==3? 0.771032:Idx==4? 0.712556:Idx==5? 0.75322:Idx==6? 0.791322:1.;
        DataEff = Idx==1? 0.000125861:Idx==2? 0.00015171:Idx==3? 0.000169858:Idx==4? 0.00207889:Idx==5? 0.00255606:Idx==6? 0.00337988:1.;
        MCEff = Idx==1? 0.000163416:Idx==2? 0.000186487:Idx==3? 0.000220299:Idx==4? 0.00291751:Idx==5? 0.00339351:Idx==6? 0.00427117:1.;
      }
    }
    else if(GetEraShort()=="2016b"){
      if(Tag.EndsWith("It1")) SF = Idx==1? 0.819695:Idx==2? 0.830703:Idx==3? 0.89013:Idx==4? 0.808581:Idx==5? 0.859135:Idx==6? 0.833188:1.;
      if(Tag.EndsWith("It2")) SF = Idx==1? 0.985335:Idx==2? 0.989235:Idx==3? 1.05053:Idx==4? 0.994737:Idx==5? 1.00287:Idx==6? 0.997352:1.;
      if(Tag.EndsWith("It3")) SF = Idx==1? 0.987021:Idx==2? 0.991971:Idx==3? 1.0349:Idx==4? 0.998961:Idx==5? 1.00047:Idx==6? 0.999396:1.;
      if(Tag.EndsWith("It4")) SF = Idx==1? 0.987809:Idx==2? 0.99422:Idx==3? 1.0235:Idx==4? 0.999501:Idx==5? 1.00025:Idx==6? 1.00001:1.;
      if(Tag.EndsWith("It5")) SF = Idx==1? 0.988673:Idx==2? 0.995937:Idx==3? 1.0159:Idx==4? 0.99964:Idx==5? 1.00011:Idx==6? 1.00017:1.;
      if(Tag.EndsWith("It6")) SF = Idx==1? 0.989613:Idx==2? 0.997157:Idx==3? 1.01091:Idx==4? 0.99971:Idx==5? 1.00007:Idx==6? 1.00021:1.;
      if(Tag.EndsWith("It7")) SF = Idx==1? 0.994707:Idx==2? 0.998119:Idx==3? 1.00754:Idx==4? 0.999844:Idx==5? 1.00002:Idx==6? 1.00027:1.;
      if(Tag.EndsWith("Fin")){
        SF = Idx==1? 0.748377:Idx==2? 0.822857:Idx==3? 0.983595:Idx==4? 0.79469:Idx==5? 0.869773:Idx==6? 0.829995:1.;
        DataEff = Idx==1? 0.000123377:Idx==2? 0.000145494:Idx==3? 0.000211887:Idx==4? 0.00224042:Idx==5? 0.00276965:Idx==6? 0.00328515:1.;
        MCEff = Idx==1? 0.000164859:Idx==2? 0.000176816:Idx==3? 0.000215421:Idx==4? 0.00281924:Idx==5? 0.00318434:Idx==6? 0.00395804:1.;
      }
    }
    else if(DataYear==2017){
      if(Tag.EndsWith("It1")) SF = Idx==1? 1.32142:Idx==2? 1.34492:Idx==3? 1.42387:Idx==4? 1.31041:Idx==5? 1.31226:Idx==6? 1.26195:1.;
      if(Tag.EndsWith("It2")) SF = Idx==1? 1.00956:Idx==2? 1.01603:Idx==3? 1.05415:Idx==4? 1.00353:Idx==5? 1.00166:Idx==6? 0.988908:1.;
      if(Tag.EndsWith("It3")) SF = Idx==1? 0.984839:Idx==2? 1.00808:Idx==3? 1.03086:Idx==4? 1.001:Idx==5? 1.0002:Idx==6? 0.995879:1.;
      if(Tag.EndsWith("It4")) SF = Idx==1? 1.00649:Idx==2? 1.00473:Idx==3? 1.01903:Idx==4? 1.0002:Idx==5? 0.999993:Idx==6? 0.998663:1.;
      if(Tag.EndsWith("It5")) SF = Idx==1? 1.00476:Idx==2? 1.00252:Idx==3? 1.01066:Idx==4? 0.999814:Idx==5? 0.999869:Idx==6? 0.999454:1.;
      if(Tag.EndsWith("It6")) SF = Idx==1? 1.00506:Idx==2? 1.00138:Idx==3? 1.00606:Idx==4? 0.999815:Idx==5? 0.999949:Idx==6? 0.999808:1.;
      if(Tag.EndsWith("It7")) SF = Idx==1? 1.00305:Idx==2? 1.00071:Idx==3? 1.00345:Idx==4? 0.999854:Idx==5? 0.999919:Idx==6? 0.9999:1.;
      if(Tag.EndsWith("Fin")){
        SF = Idx==1? 1.2696:Idx==2? 1.36965:Idx==3? 1.52389:Idx==4? 1.37131:Idx==5? 1.31699:Idx==6? 1.2204:1.;
        DataEff = Idx==1? 6.65722e-05:Idx==2? 8.34845e-05:Idx==3? 0.000117936:Idx==4? 0.00133884:Idx==5? 0.00140659:Idx==6? 0.00173507:1.;
        MCEff = Idx==1? 5.24355e-05:Idx==2? 6.0953e-05:Idx==3? 7.73914e-05:Idx==4? 0.000976318:Idx==5? 0.00106803:Idx==6? 0.00142172:1.;
      }
    }
    else if(DataYear==2018){
      if(Tag.EndsWith("It1")) SF = Idx==1? 1.30513:Idx==2? 1.29827:Idx==3? 1.35588:Idx==4? 1.2905:Idx==5? 1.25325:Idx==6? 1.30075:1.;
      if(Tag.EndsWith("It2")) SF = Idx==1? 1.01481:Idx==2? 1.0144:Idx==3? 1.03505:Idx==4? 0.998348:Idx==5? 0.996626:Idx==6? 1.00704:1.;
      if(Tag.EndsWith("It3")) SF = Idx==1? 1.01082:Idx==2? 1.01016:Idx==3? 1.02064:Idx==4? 0.998116:Idx==5? 0.99875:Idx==6? 1.00239:1.;
      if(Tag.EndsWith("It4")) SF = Idx==1? 1.00923:Idx==2? 1.00686:Idx==3? 1.01222:Idx==4? 0.998952:Idx==5? 0.999389:Idx==6? 1.00087:1.;
      if(Tag.EndsWith("It5")) SF = Idx==1? 1.00772:Idx==2? 1.00461:Idx==3? 1.00687:Idx==4? 0.999426:Idx==5? 0.999645:Idx==6? 1.00033:1.;
      if(Tag.EndsWith("It6")) SF = Idx==1? 1.00651:Idx==2? 1.00291:Idx==3? 1.00368:Idx==4? 0.999666:Idx==5? 0.999781:Idx==6? 1.0001:1.;
      if(Tag.EndsWith("It7")) SF = Idx==1? 1.00533:Idx==2? 1.00187:Idx==3? 1.00168:Idx==4? 0.999836:Idx==5? 0.999868:Idx==6? 1.00003:1.;
      if(Tag.EndsWith("Fin")){
        SF = Idx==1? 1.46065:Idx==2? 1.36472:Idx==3? 1.38385:Idx==4? 1.30511:Idx==5? 1.27019:Idx==6? 1.36434:1.;
        DataEff = Idx==1? 8.256e-05:Idx==2? 8.34791e-05:Idx==3? 0.000107939:Idx==4? 0.00125831:Idx==5? 0.00139244:Idx==6? 0.00190927:1.;
        MCEff = Idx==1? 5.65228e-05:Idx==2? 6.11694e-05:Idx==3? 7.79988e-05:Idx==4? 0.00096414:Idx==5? 0.00109625:Idx==6? 0.0013994:1.;
      }
    }
  } 
  else if(Tag.Contains("App2Bin2_")){
    int Idx = BinIndex2;
    if(GetEraShort()=="2016a"){
      if(Tag.EndsWith("It1")) SF = Idx==1? 0.752408:Idx==2? 0.798351:Idx==3? 0.737382:Idx==4? 0.820081:1.;
      if(Tag.EndsWith("It2")) SF = Idx==1? 0.973737:Idx==2? 1.0189:Idx==3? 0.984259:Idx==4? 1.01569:1.;
      if(Tag.EndsWith("It3")) SF = Idx==1? 0.979696:Idx==2? 1.01198:Idx==3? 0.99476:Idx==4? 1.0041:1.;
      if(Tag.EndsWith("It4")) SF = Idx==1? 0.97916:Idx==2? 1.00769:Idx==3? 0.998227:Idx==4? 1.00105:1.;
      if(Tag.EndsWith("It5")) SF = Idx==1? 0.979838:Idx==2? 1.00496:Idx==3? 0.999371:Idx==4? 1.00024:1.;
      if(Tag.EndsWith("It6")) SF = Idx==1? 0.977198:Idx==2? 1.00324:Idx==3? 0.999746:Idx==4? 1.00013:1.;
      if(Tag.EndsWith("It7")) SF = Idx==1? 0.981714:Idx==2? 1.00218:Idx==3? 0.999888:Idx==4? 1.00002:1.;
      if(Tag.EndsWith("Fin")){
        SF = Idx==1? 0.655387:Idx==2? 0.842453:Idx==3? 0.714889:Idx==4? 0.804131:1.;
        DataEff = Idx==1? 2.6199e-05:Idx==2? 0.000344799:Idx==3? 0.00230424:Idx==4? 0.00288139:1.;
        MCEff = Idx==1? 3.99749e-05:Idx==2? 0.00040928:Idx==3? 0.00322321:Idx==4? 0.00358324:1.;
      }
    }
    else if(GetEraShort()=="2016b"){
      if(Tag.EndsWith("It1")) SF = Idx==1? 0.817223:Idx==2? 0.854388:Idx==3? 0.842534:Idx==4? 0.840254:1.;
      if(Tag.EndsWith("It2")) SF = Idx==1? 0.962671:Idx==2? 1.00945:Idx==3? 1.00003:Idx==4? 0.999153:1.;
      if(Tag.EndsWith("It3")) SF = Idx==1? 0.972905:Idx==2? 1.00638:Idx==3? 0.999969:Idx==4? 0.999638:1.;
      if(Tag.EndsWith("It4")) SF = Idx==1? 0.973814:Idx==2? 1.00423:Idx==3? 0.999952:Idx==4? 0.99984:1.;
      if(Tag.EndsWith("It5")) SF = Idx==1? 0.975342:Idx==2? 1.00302:Idx==3? 0.999978:Idx==4? 0.999906:1.;
      if(Tag.EndsWith("It6")) SF = Idx==1? 0.977174:Idx==2? 1.00217:Idx==3? 1:Idx==4? 0.999943:1.;
      if(Tag.EndsWith("It7")) SF = Idx==1? 0.978538:Idx==2? 1.00161:Idx==3? 1.00001:Idx==4? 0.999965:1.;
      if(Tag.EndsWith("Fin")){
        SF = Idx==1? 0.619954:Idx==2? 0.896209:Idx==3? 0.843693:Idx==4? 0.846716:1.;
        DataEff = Idx==1? 2.77502e-05:Idx==2? 0.000355046:Idx==3? 0.0026395:Idx==4? 0.00274673:1.;
        MCEff = Idx==1? 4.47616e-05:Idx==2? 0.000396165:Idx==3? 0.00312851:Idx==4? 0.00324398:1.;
      }
    }
    else if(DataYear==2017){
      if(Tag.EndsWith("It1")) SF = Idx==1? 1.35418:Idx==2? 1.33295:Idx==3? 1.33841:Idx==4? 1.26717:1.;
      if(Tag.EndsWith("It2")) SF = Idx==1? 1.02801:Idx==2? 1.00707:Idx==3? 1.00964:Idx==4? 0.991703:1.;
      if(Tag.EndsWith("It3")) SF = Idx==1? 1.02165:Idx==2? 1.00379:Idx==3? 1.00301:Idx==4? 0.999398:1.;
      if(Tag.EndsWith("It4")) SF = Idx==1? 1.01704:Idx==2? 1.0012:Idx==3? 1.00046:Idx==4? 0.999473:1.;
      if(Tag.EndsWith("It5")) SF = Idx==1? 1.01455:Idx==2? 1.00864:Idx==3? 1.00004:Idx==4? 0.999775:1.;
      if(Tag.EndsWith("It6")) SF = Idx==1? 1.0113:Idx==2? 1.00506:Idx==3? 0.999713:Idx==4? 0.999801:1.;
      if(Tag.EndsWith("It7")) SF = Idx==1? 1.00922:Idx==2? 1.00302:Idx==3? 0.999747:Idx==4? 0.99987:1.;
      if(Tag.EndsWith("Fin")){
        SF = Idx==1? 1.24704:Idx==2? 1.36859:Idx==3? 1.36859:Idx==4? 1.28726:1.;
        DataEff = Idx==1? 2.57751e-05:Idx==2? 0.000171696:Idx==3? 0.00117306:Idx==4? 0.00186744:1.;
        MCEff = Idx==1? 2.0669e-05:Idx==2? 0.000125455:Idx==3? 0.000857131:Idx==4? 0.0014507:1.;
      }
    }
    else if(DataYear==2018){
      if(Tag.EndsWith("It1")) SF = Idx==1? 1.29972:Idx==2? 1.31553:Idx==3? 1.3093:Idx==4? 1.23683:1.;
      if(Tag.EndsWith("It2")) SF = Idx==1? 1.01264:Idx==2? 1.0231:Idx==3? 1.01095:Idx==4? 0.993349:1.;
      if(Tag.EndsWith("It3")) SF = Idx==1? 1.00567:Idx==2? 1.01349:Idx==3? 1.00297:Idx==4? 0.997659:1.;
      if(Tag.EndsWith("It4")) SF = Idx==1? 1.00297:Idx==2? 1.00829:Idx==3? 1.00073:Idx==4? 0.999143:1.;
      if(Tag.EndsWith("It5")) SF = Idx==1? 1.00124:Idx==2? 1.00515:Idx==3? 1.00009:Idx==4? 0.99965:1.;
      if(Tag.EndsWith("It6")) SF = Idx==1? 1.00021:Idx==2? 1.00326:Idx==3? 0.999938:Idx==4? 0.999842:1.;
      if(Tag.EndsWith("It7")) SF = Idx==1? 0.999776:Idx==2? 1.00212:Idx==3? 0.999926:Idx==4? 0.999921:1.;
      if(Tag.EndsWith("Fin")){
        SF = Idx==1? 1.37469:Idx==2? 1.39657:Idx==3? 1.35169:Idx==4? 1.24908:1.;
        DataEff = Idx==1? 2.57045e-05:Idx==2? 0.000183513:Idx==3? 0.00114237:Idx==4? 0.00183787:1.;
        MCEff = Idx==1? 1.86983e-05:Idx==2? 0.000131403:Idx==3? 0.000845138:Idx==4? 0.00147138:1.;
      }
    }
  }

  if     (ReturnMCEff  ) ReturnVal = MCEff;
  else if(ReturnDataEff) ReturnVal = DataEff;
  else                   ReturnVal = SF; 

  return ReturnVal;
}


float MeasCFlipRate::GetMCCFR(float VarX, float VarY, TString Key){

  bool DYCFR = Key.EndsWith("_DY"), TTCFR = Key.EndsWith("_TT");
  TString ProcTag = DYCFR? "_DY":TTCFR? "_TT":"";
  TString KeyTrim_SS = DYCFR or TTCFR? Key.ReplaceAll(ProcTag,""):Key;
  TString KeyTrim_OS(KeyTrim_SS); KeyTrim_OS.ReplaceAll("_QF","_QT");
  
  TFile* CFRFile = f_CFR_DY;
  //TFile* CFRFile = DYCFR? f_CFR_DY:TTCFR? f_CFR_TT:f_CFR_DY;
  if(!CFRFile->GetListOfKeys()->Contains(KeyTrim_SS)){ printf("[Error] No %s in CFR File.\n", KeyTrim_SS.Data()); return -1.; }
  if(!CFRFile->GetListOfKeys()->Contains(KeyTrim_OS)){ printf("[Error] No %s in CFR File.\n", KeyTrim_OS.Data()); return -1.; }
  TString NewKey = "CFR"+ProcTag;
  map<TString, TH2D*>::iterator mapit = maphist_CFR.find(NewKey);
  map<TString, TH2D*>::iterator mapit_den = maphist_CFR.find(NewKey+"_Den");
  if(mapit == maphist_CFR.end()){ //first usage
    maphist_CFR[NewKey] = (TH2D*) ((TH2*) CFRFile->Get(KeyTrim_SS))->Clone();
    maphist_CFR[NewKey+"_Den"] = (TH2D*) ((TH2*) CFRFile->Get(KeyTrim_OS))->Clone();
    mapit = maphist_CFR.find(NewKey);  mapit_den = maphist_CFR.find(NewKey+"_Den");
    mapit->second->Divide(mapit_den->second);
  }
  mapit = maphist_CFR.find(NewKey);  mapit_den = maphist_CFR.find(NewKey+"_Den");

  float Xmin = mapit->second->GetXaxis()->GetBinLowEdge(mapit->second->GetXaxis()->GetFirst());
  float Xmax = mapit->second->GetXaxis()->GetBinUpEdge(mapit->second->GetXaxis()->GetLast());
  float Ymin = mapit->second->GetYaxis()->GetBinLowEdge(mapit->second->GetYaxis()->GetFirst());
  float Ymax = mapit->second->GetYaxis()->GetBinUpEdge(mapit->second->GetYaxis()->GetLast());

  if(VarX<Xmin) VarX=Xmin+1E-10;
  if(VarX>Xmax) VarX=Xmax-1E-10;
  if(VarY<Ymin) VarY=Ymin+1E-10;
  if(VarY>Ymax) VarY=Ymax-1E-10;

  float CFR = mapit->second->GetBinContent(mapit->second->FindBin(VarX,VarY));
  return CFR;

}




MeasCFlipRate::MeasCFlipRate(){


}


MeasCFlipRate::~MeasCFlipRate(){

  delete f_CFR_DY; //delete f_CFR_TT;
  for(std::map< TString, TH2D* >::iterator mapit = maphist_CFR.begin(); mapit!=maphist_CFR.end(); mapit++){
    delete mapit->second;
  }
  maphist_CFR.clear();

}

