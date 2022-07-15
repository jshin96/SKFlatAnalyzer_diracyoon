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

  TString SKOutPath=getenv("SKFlatOutputDir"), SKFlatV=getenv("SKFlatV"), SpecDir="TopHN17SST/EleOnly/";
  TString FileDir = SKOutPath+"/"+SKFlatV+"/MeasCFlipRate/"+GetEraShort()+"/All2l/MCCFRate/"+SpecDir+"BkdMC/";
  f_CFR_DY = new TFile(FileDir+"MeasCFlipRate_DYJetsToEE_MiNNLO.root");
  //f_CFR_TT = new TFile(FileDir+"MeasCFlipRate_TTLL_powheg.root");

  outfile->cd();
}


void MeasCFlipRate::executeEvent(){


  Event ev = GetEvent();
  float weight = 1., w_GenNorm=1., w_BR=1., w_PU=1.;
  if(!IsDATA){
    w_GenNorm = ev.MCweight()*weight_norm_1invpb*GetKFactor()*ev.GetTriggerLumi("Full");
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
  TString MuTID = "TopHNT", MuLID = "TopHNLLIsop6SIP5";
  TString ElTID = "TopHN17SST", ElLID = "TopHNSSNM01LFixLMVAIsop4NoSIP_"+GetEraShort(), ElVID = "TopHNV";
  //TString ElTID = "TopHNSSTWP90Isop1", ElLID = "TopHNSSL_FixLMVAIsop4NoSIP_"+GetEraShort(), ElVID = "TopHNV";
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


  Particle vMET = ev.GetMETVector();
  Particle vMET_xyCorr(pfMET_Type1_PhiCor_pt*TMath::Cos(pfMET_Type1_PhiCor_phi), pfMET_Type1_PhiCor_pt*TMath::Sin(pfMET_Type1_PhiCor_phi), 0., pfMET_Type1_PhiCor_pt);
  //Particle vMET_T1xy = GetvMET("T1xyCorr");


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
    TString SFKey_Trig_All = muonTightColl.size()==2? "DiMuIso_HNTopID":electronTightColl.size()==2? "DiElIso_HNTopID17SS":""; 
    sf_Trig   = SFKey_Trig_All!=""? mcCorr->GetTriggerSF(electronTightColl, muonTightColl, SFKey_Trig_All, ""):1.;
    //sf_Trig   = SS2l or OS2l? mcCorr->GetTriggerSF(electronTightColl, muonTightColl, SFKey_Trig_All, ""):1.;
    w_Prefire = GetPrefireWeight(0);
    //cout<<" w_PU:"<<w_PU<<" w_Prefire:"<<w_Prefire<<" sf_Trig:"<<sf_Trig<<endl;
    //cout<<"sf_MuTk"<<sf_MuTk<<" sf_MuID:"<<sf_MuID<<" sf_MuIso:"<<sf_MuIso<<" sf_ElReco:"<<sf_ElReco<<" sf_ElID:"<<sf_ElID<<" sf_BTag:"<<sf_BTag<<endl;
  }
  //if(IsDATA && FakeRun && EventCand){
  //  w_FR      = CalcTestFakeWeight(muonLooseColl, electronLooseColl,
  //                "TopHN17T", "TopHN17L", "TopHN17"+IDSSLabel+"T", "TopHN17"+IDSSLabel+"L", bjetColl.size(), 0);
  //}
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
  vector<TString> IterStrList = {"_It1", "_It2", "_It3", "_It4", "_It5", "_It6"};//{"_It1", "_It2", "_It3", "_It4", "_It5"};
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
      if(Tag.EndsWith("It1")) SF = Idx==1? 0.77495:Idx==2? 0.775205:Idx==3? 0.758091:Idx==4? 0.752694:Idx==5? 0.77715:Idx==6? 0.786827:1.;
      if(Tag.EndsWith("It2")) SF = Idx==1? 1.00756:Idx==2? 1.00356:Idx==3? 0.992936:Idx==4? 0.994374:Idx==5? 0.999492:Idx==6? 1.00594:1.;
      if(Tag.EndsWith("It3")) SF = Idx==1? 1.00765:Idx==2? 1.00322:Idx==3? 0.99588:Idx==4? 0.998397:Idx==5? 0.999499:Idx==6? 1.00204:1.;
      if(Tag.EndsWith("It4")) SF = Idx==1? 1.00688:Idx==2? 1.00243:Idx==3? 0.9969:Idx==4? 0.999579:Idx==5? 0.999746:Idx==6? 1.00072:1.;
      if(Tag.EndsWith("It5")) SF = Idx==1? 1.00594:Idx==2? 1.00168:Idx==3? 0.997389:Idx==4? 0.999767:Idx==5? 0.999859:Idx==6? 1.00019:1.;
      if(Tag.EndsWith("It6")) SF = Idx==1? 1.00521:Idx==2? 1.00113:Idx==3? 0.997762:Idx==4? 0.999928:Idx==5? 0.999921:Idx==6? 1.00002:1.;
      if(Tag.EndsWith("It7")) SF = Idx==1? 1.00452:Idx==2? 1.00074:Idx==3? 0.998069:Idx==4? 1.00007:Idx==5? 0.999953:Idx==6? 0.999958:1.;
      if(Tag.EndsWith("Fin")){
        SF = Idx==1? 0.770188:Idx==2? 0.813516:Idx==3? 0.771032:Idx==4? 0.712556:Idx==5? 0.75322:Idx==6? 0.791322:1.;
        DataEff = Idx==1? 0.000125861:Idx==2? 0.00015171:Idx==3? 0.000169858:Idx==4? 0.00207889:Idx==5? 0.00255606:Idx==6? 0.00337988:1.;
        MCEff = Idx==1? 0.000163416:Idx==2? 0.000186487:Idx==3? 0.000220299:Idx==4? 0.00291751:Idx==5? 0.00339351:Idx==6? 0.00427117:1.;
      }
    }
    else if(GetEraShort()=="2016b"){
      if(Tag.EndsWith("It1")) SF = Idx==1? 0.818033:Idx==2? 0.837151:Idx==3? 0.893969:Idx==4? 0.815647:Idx==5? 0.860114:Idx==6? 0.834439:1.;
      if(Tag.EndsWith("It2")) SF = Idx==1? 0.979981:Idx==2? 0.992167:Idx==3? 1.04504:Idx==4? 0.995765:Idx==5? 1.00272:Idx==6? 0.996853:1.;
      if(Tag.EndsWith("It3")) SF = Idx==1? 0.982292:Idx==2? 0.994066:Idx==3? 1.03653:Idx==4? 0.999193:Idx==5? 1.00055:Idx==6? 0.999249:1.;
      if(Tag.EndsWith("It4")) SF = Idx==1? 0.986558:Idx==2? 0.995596:Idx==3? 1.02437:Idx==4? 0.999513:Idx==5? 1.00015:Idx==6? 1.00003:1.;
      if(Tag.EndsWith("It5")) SF = Idx==1? 0.984405:Idx==2? 0.996829:Idx==3? 1.01647:Idx==4? 0.999615:Idx==5? 1.00008:Idx==6? 1.00013:1.;
      if(Tag.EndsWith("It6")) SF = Idx==1? 0.985893:Idx==2? 0.99785:Idx==3? 1.01143:Idx==4? 0.999717:Idx==5? 1.00007:Idx==6? 1.0003:1.;
      if(Tag.EndsWith("It7")) SF = Idx==1? 0.987349:Idx==2? 0.998539:Idx==3? 1.00809:Idx==4? 0.999784:Idx==5? 1.00005:Idx==6? 0.996812:1.;
      if(Tag.EndsWith("Fin")){
        SF = Idx==1? 0.748377:Idx==2? 0.822857:Idx==3? 0.983595:Idx==4? 0.79469:Idx==5? 0.869773:Idx==6? 0.829995:1.;
        DataEff = Idx==1? 0.000123377:Idx==2? 0.000145494:Idx==3? 0.000211887:Idx==4? 0.00224042:Idx==5? 0.00276965:Idx==6? 0.00328515:1.;
        MCEff = Idx==1? 0.000164859:Idx==2? 0.000176816:Idx==3? 0.000215421:Idx==4? 0.00281924:Idx==5? 0.00318434:Idx==6? 0.00395804:1.;
      }
    }
    else if(DataYear==2017){
      if(Tag.EndsWith("It1")) SF = Idx==1? 1.29366:Idx==2? 1.32983:Idx==3? 1.40887:Idx==4? 1.31882:Idx==5? 1.29863:Idx==6? 1.25866:1.;
      if(Tag.EndsWith("It2")) SF = Idx==1? 0.997267:Idx==2? 1.0122:Idx==3? 1.04933:Idx==4? 1.00507:Idx==5? 1.00072:Idx==6? 0.989626:1.;
      if(Tag.EndsWith("It3")) SF = Idx==1? 0.990007:Idx==2? 1.00606:Idx==3? 1.02891:Idx==4? 1.00126:Idx==5? 1.00052:Idx==6? 0.99627:1.;
      if(Tag.EndsWith("It4")) SF = Idx==1? 0.989777:Idx==2? 1.00325:Idx==3? 1.01785:Idx==4? 1.0002:Idx==5? 0.998032:Idx==6? 0.998676:1.;
      if(Tag.EndsWith("It5")) SF = Idx==1? 0.990909:Idx==2? 1.00268:Idx==3? 1.01167:Idx==4? 0.999847:Idx==5? 1.00176:Idx==6? 0.999975:1.;
      if(Tag.EndsWith("It6")) SF = Idx==1? 0.99101:Idx==2? 1.00102:Idx==3? 1.00737:Idx==4? 0.997952:Idx==5? 1.00016:Idx==6? 0.999693:1.;
      if(Tag.EndsWith("It7")) SF = Idx==1? 0.992491:Idx==2? 1.00104:Idx==3? 1.00558:Idx==4? 0.999882:Idx==5? 0.999968:Idx==6? 1.00008:1.;
      if(Tag.EndsWith("Fin")){
        SF = Idx==1? 1.2696:Idx==2? 1.36965:Idx==3? 1.52389:Idx==4? 1.37131:Idx==5? 1.31699:Idx==6? 1.2204:1.;
        DataEff = Idx==1? 6.65722e-05:Idx==2? 8.34845e-05:Idx==3? 0.000117936:Idx==4? 0.00133884:Idx==5? 0.00140659:Idx==6? 0.00173507:1.;
        MCEff = Idx==1? 5.24355e-05:Idx==2? 6.0953e-05:Idx==3? 7.73914e-05:Idx==4? 0.000976318:Idx==5? 0.00106803:Idx==6? 0.00142172:1.;
      }
    }
    else if(DataYear==2018){
      if(Tag.EndsWith("It1")) SF = Idx==1? 1.31093:Idx==2? 1.29566:Idx==3? 1.36132:Idx==4? 1.29502:Idx==5? 1.25594:Idx==6? 1.3031:1.;
      if(Tag.EndsWith("It2")) SF = Idx==1? 1.01604:Idx==2? 1.01109:Idx==3? 1.0361:Idx==4? 0.998637:Idx==5? 0.996768:Idx==6? 1.00689:1.;
      if(Tag.EndsWith("It3")) SF = Idx==1? 1.01226:Idx==2? 1.00753:Idx==3? 1.0214:Idx==4? 0.998198:Idx==5? 0.998837:Idx==6? 1.00231:1.;
      if(Tag.EndsWith("It4")) SF = Idx==1? 1.01008:Idx==2? 1.0052:Idx==3? 1.01265:Idx==4? 0.998962:Idx==5? 0.99945:Idx==6? 1.00081:1.;
      if(Tag.EndsWith("It5")) SF = Idx==1? 1.00842:Idx==2? 1.00305:Idx==3? 1.0072:Idx==4? 0.99944:Idx==5? 0.999697:Idx==6? 1.00028:1.;
      if(Tag.EndsWith("It6")) SF = Idx==1? 1.00718:Idx==2? 1.00204:Idx==3? 1.00388:Idx==4? 0.99969:Idx==5? 0.999824:Idx==6? 1.00008:1.;
      if(Tag.EndsWith("It7")) SF = Idx==1? 1.00615:Idx==2? 1.00146:Idx==3? 1.00187:Idx==4? 0.999761:Idx==5? 0.999894:Idx==6? 1.00001:1.;
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
      if(Tag.EndsWith("It1")) SF = Idx==1? 0.753814:Idx==2? 0.796558:Idx==3? 0.740574:Idx==4? 0.820686:1.;
      if(Tag.EndsWith("It2")) SF = Idx==1? 0.973783:Idx==2? 1.01581:Idx==3? 0.984973:Idx==4? 1.01521:1.;
      if(Tag.EndsWith("It3")) SF = Idx==1? 0.975237:Idx==2? 1.01008:Idx==3? 0.995066:Idx==4? 1.00406:1.;
      if(Tag.EndsWith("It4")) SF = Idx==1? 0.976296:Idx==2? 1.00656:Idx==3? 0.998373:Idx==4? 1.00106:1.;
      if(Tag.EndsWith("It5")) SF = Idx==1? 0.977278:Idx==2? 1.0043:Idx==3? 0.999437:Idx==4? 1.00025:1.;
      if(Tag.EndsWith("It6")) SF = Idx==1? 0.978342:Idx==2? 1.00286:Idx==3? 0.999794:Idx==4? 1.00006:1.;
      if(Tag.EndsWith("It7")) SF = Idx==1? 0.979474:Idx==2? 1.00195:Idx==3? 0.998881:Idx==4? 1.00003:1.;
      if(Tag.EndsWith("Fin")){
        SF = Idx==1? 0.655387:Idx==2? 0.842453:Idx==3? 0.714889:Idx==4? 0.804131:1.;
        DataEff = Idx==1? 2.6199e-05:Idx==2? 0.000344799:Idx==3? 0.00230424:Idx==4? 0.00288139:1.;
        MCEff = Idx==1? 3.99749e-05:Idx==2? 0.00040928:Idx==3? 0.00322321:Idx==4? 0.00358324:1.;
      }
    }
    else if(GetEraShort()=="2016b"){
      if(Tag.EndsWith("It1")) SF = Idx==1? 0.818923:Idx==2? 0.856212:Idx==3? 0.844416:Idx==4? 0.847731:1.;
      if(Tag.EndsWith("It2")) SF = Idx==1? 0.969178:Idx==2? 1.00781:Idx==3? 0.999317:Idx==4? 1.00037:1.;
      if(Tag.EndsWith("It3")) SF = Idx==1? 0.970797:Idx==2? 1.00527:Idx==3? 0.999768:Idx==4? 0.999999:1.;
      if(Tag.EndsWith("It4")) SF = Idx==1? 0.969269:Idx==2? 1.00367:Idx==3? 0.999924:Idx==4? 0.999917:1.;
      if(Tag.EndsWith("It5")) SF = Idx==1? 0.974147:Idx==2? 1.00273:Idx==3? 1.00029:Idx==4? 0.999939:1.;
      if(Tag.EndsWith("It6")) SF = Idx==1? 0.97568:Idx==2? 1.00194:Idx==3? 0.999763:Idx==4? 0.999942:1.;
      if(Tag.EndsWith("It7")) SF = Idx==1? 0.977375:Idx==2? 1.00163:Idx==3? 0.999993:Idx==4? 1.00002:1.;
      if(Tag.EndsWith("Fin")){
        SF = Idx==1? 0.619954:Idx==2? 0.896209:Idx==3? 0.843693:Idx==4? 0.846716:1.;
        DataEff = Idx==1? 2.77502e-05:Idx==2? 0.000355046:Idx==3? 0.0026395:Idx==4? 0.00274673:1.;
        MCEff = Idx==1? 4.47616e-05:Idx==2? 0.000396165:Idx==3? 0.00312851:Idx==4? 0.00324398:1.;
      }
    }
    else if(DataYear==2017){
      if(Tag.EndsWith("It1")) SF = Idx==1? 1.31881:Idx==2? 1.32457:Idx==3? 1.34604:Idx==4? 1.27878:1.;
      if(Tag.EndsWith("It2")) SF = Idx==1? 1.00062:Idx==2? 1.00761:Idx==3? 1.00967:Idx==4? 0.99411:1.;
      if(Tag.EndsWith("It3")) SF = Idx==1? 0.997311:Idx==2? 1.00411:Idx==3? 1.00275:Idx==4? 0.998152:1.;
      if(Tag.EndsWith("It4")) SF = Idx==1? 0.996479:Idx==2? 1.00249:Idx==3? 1.0008:Idx==4? 0.999401:1.;
      if(Tag.EndsWith("It5")) SF = Idx==1? 0.996398:Idx==2? 1.00171:Idx==3? 1.00021:Idx==4? 0.999824:1.;
      if(Tag.EndsWith("It6")) SF = Idx==1? 0.99655:Idx==2? 1.0011:Idx==3? 1.00004:Idx==4? 0.999934:1.;
      if(Tag.EndsWith("It7")) SF = Idx==1? 0.996804:Idx==2? 1.00077:Idx==3? 1.00001:Idx==4? 0.999975:1.;
      if(Tag.EndsWith("Fin")){
        SF = Idx==1? 1.24704:Idx==2? 1.36859:Idx==3? 1.36859:Idx==4? 1.28726:1.;
        DataEff = Idx==1? 2.57751e-05:Idx==2? 0.000171696:Idx==3? 0.00117306:Idx==4? 0.00186744:1.;
        MCEff = Idx==1? 2.0669e-05:Idx==2? 0.000125455:Idx==3? 0.000857131:Idx==4? 0.0014507:1.;
      }
    }
    else if(DataYear==2018){
      if(Tag.EndsWith("It1")) SF = Idx==1? 1.29348:Idx==2? 1.31616:Idx==3? 1.31356:Idx==4? 1.23827:1.;
      if(Tag.EndsWith("It2")) SF = Idx==1? 1.00632:Idx==2? 1.02206:Idx==3? 1.0114:Idx==4? 0.993165:1.;
      if(Tag.EndsWith("It3")) SF = Idx==1? 1.00015:Idx==2? 1.01288:Idx==3? 1.00313:Idx==4? 0.997619:1.;
      if(Tag.EndsWith("It4")) SF = Idx==1? 0.997689:Idx==2? 1.00795:Idx==3? 1.00079:Idx==4? 0.999147:1.;
      if(Tag.EndsWith("It5")) SF = Idx==1? 0.996791:Idx==2? 1.00506:Idx==3? 1.00013:Idx==4? 0.999666:1.;
      if(Tag.EndsWith("It6")) SF = Idx==1? 0.996343:Idx==2? 1.00328:Idx==3? 0.999957:Idx==4? 0.999854:1.;
      if(Tag.EndsWith("It7")) SF = Idx==1? 0.996171:Idx==2? 1.00216:Idx==3? 0.999949:Idx==4? 0.999931:1.;
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

