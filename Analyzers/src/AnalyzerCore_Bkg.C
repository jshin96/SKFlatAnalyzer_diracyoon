#include "AnalyzerCore.h"



int AnalyzerCore::GetFakeLepSrcType(const Lepton& Lep, vector<Jet>& JetColl){
  //Type: -1: Unmatched, 1:L, 2:C, 3:B                                                                                                                                                                                                                                                                                                                                                                                                   
  int SrcType=-1;
  bool NearB=false, NearC=false, NearL=false;
  for(unsigned int ij=0; ij<JetColl.size(); ij++){
    if(Lep.DeltaR(JetColl.at(ij))<0.4){
      if     (JetColl.at(ij).hadronFlavour()==5){ NearB=true; break; }//1)                                                                                                                                                                                                                                                                                                                                                               
      else if(JetColl.at(ij).hadronFlavour()==4){ NearC=true; }
      else if(JetColl.at(ij).hadronFlavour()==0){ NearL=true; }
    }
  }

  if     (NearB) SrcType=3;
  else if(NearC) SrcType=2;
  else if(NearL) SrcType=1;

  return SrcType;
  //1) Higher Priority to B. if there's multiple near jets, then b-jet has higher priority                                                                                                                                                                                                                                                                                                                                               

}





/*                                                                                                                                                                                                                                                                                                                                                                                                                                      FAKE RATE FUNCTIONS                                                                                                                                                                                               */

double AnalyzerCore::GetFakeRateElectron(Electron el, AnalyzerParameter param){

  //// Access individual lepton Fake Rate                                                                                                                                                                                                                                                                                                                                                                                                

  double  LepEta = el.fEta();
  double  LepPt  = el.PtMaxed(80);
  TString  fr_key = param.Electron_FR_Key;

  return fakeEst->GetElectronFakeRate(param.Electron_Tight_ID, fr_key,param.FakeRateMethod, LepEta, LepPt, el.LeptonFakeTagger() );


}
double AnalyzerCore::GetFakeRateMuon(Muon mu, AnalyzerParameter param){

  double  LepEta = mu.fEta();
  double  LepPt  = mu.PtMaxed(80);
  TString  fr_key = param.Muon_FR_Key;

  //// Access individual lepton Fake Ratex                                                                                                                                                                                                                                                                                                                                                                                               
  return fakeEst->GetMuonFakeRate(param.Muon_Tight_ID, fr_key,param.FakeRateMethod,LepEta, LepPt, mu.LeptonFakeTagger() );

}




double AnalyzerCore::GetFakeWeight(std::vector<Lepton *> leps, AnalyzerParameter _param, bool apply_r){

  //// Access event weight based on Lepton collection                                                                                                                                                                                                                                                                                                                                                                                    
  if(!IsData) return 1.;

  double this_weight = -1.;
  if(leps.size() == 1){

    TString fr_key1 = (leps[0]->LeptonFlavour() == Lepton::ELECTRON) ?  _param.Electron_FR_Key : _param.Muon_FR_Key;

    if(!leps[0]->LepIDSet()) {
      cout << "Lepton ID not set" << endl;
      exit(EXIT_FAILURE);
    }

    double this_fr1 = (leps[0]->LeptonFlavour() == Lepton::ELECTRON) ? fakeEst->GetElectronFakeRate(_param.Electron_Tight_ID, fr_key1,_param.FakeRateMethod, leps[0]->fEta(), leps[0]->Pt(),leps[0]->LeptonFakeTagger()) : fakeEst->GetMuonFakeRate(_param.Muon_Tight_ID, fr_key1,_param.FakeRateMethod, leps[0]->fEta(), leps[0]->Pt(),leps[0]->LeptonFakeTagger());

    double this_pr1 = 1.;

    this_weight=  fakeEst->CalculateLepWeight(this_pr1, this_fr1, leps[0]->PassLepID() );

    //    cout << this_weight<< " L"<<endl;                                                                                                                                                                                                                                                                                                                                                                                              

    return this_weight;


  }
  if (leps.size() == 2){

    if(!(leps[0]->LepIDSet() || leps[1]->LepIDSet())) {
      cout << "Lepton ID not set" << endl;
      exit(EXIT_FAILURE);
    }

    TString fr_key1 = (leps[0]->LeptonFlavour() == Lepton::ELECTRON) ?  _param.Electron_FR_Key : _param.Muon_FR_Key;
    TString fr_key2 = (leps[1]->LeptonFlavour() == Lepton::ELECTRON) ?  _param.Electron_FR_Key : _param.Muon_FR_Key;

    double this_fr1 =  (leps[0]->LeptonFlavour() == Lepton::ELECTRON) ? fakeEst->GetElectronFakeRate(_param.Electron_Tight_ID, fr_key1, _param.FakeRateMethod,leps[0]->fEta(), leps[0]->Pt(),leps[0]->LeptonFakeTagger()) : fakeEst->GetMuonFakeRate(_param.Muon_Tight_ID, fr_key1,_param.FakeRateMethod, leps[0]->fEta(), leps[0]->Pt(), leps[0]->LeptonFakeTagger());
    double this_fr2 = (leps[1]->LeptonFlavour() == Lepton::ELECTRON) ? fakeEst->GetElectronFakeRate(_param.Electron_Tight_ID, fr_key2, _param.FakeRateMethod,leps[1]->fEta(), leps[1]->Pt(),leps[1]->LeptonFakeTagger()) : fakeEst->GetMuonFakeRate(_param.Muon_Tight_ID, fr_key2,_param.FakeRateMethod, leps[1]->fEta(), leps[1]->Pt(), leps[1]->LeptonFakeTagger());

    ///// TEMP PR                                                                                                                                                                                                                                                                                                                                                                                                                        
    double this_pr1 = 0.9;
    double this_pr2 = 0.9;

    TString ID1 =  (leps[0]->LeptonFlavour() == Lepton::ELECTRON) ?  _param.Electron_Tight_ID : _param.Muon_Tight_ID;
    TString ID2 =  (leps[1]->LeptonFlavour() == Lepton::ELECTRON) ?  _param.Electron_Tight_ID : _param.Muon_Tight_ID;

    this_weight = fakeEst->CalculateDilepWeight(this_pr1,this_fr1, this_pr2, this_fr2, leps[0]->PassLepID(),leps[1]->PassLepID(),0);

    //cout << this_weight << " 2L"<<endl;                                                                                                                                                                                                                                                                                                                                                                                                
    return this_weight;
  }


  else{


    double this_weight = -1.;
    vector<double> FRs;

    double this_fr = -999.;
    for(auto lep : leps){

      if( lep->PassLepID() ) continue;

      TString fr_key = (lep->LeptonFlavour() == Lepton::ELECTRON) ?  _param.Electron_FR_Key : _param.Muon_FR_Key;

      this_fr =  (lep->LeptonFlavour() == Lepton::ELECTRON) ? fakeEst->GetElectronFakeRate(_param.Electron_Tight_ID, fr_key ,_param.FakeRateMethod, lep->fEta(), lep->Pt(),lep->LeptonFakeTagger()) : fakeEst->GetMuonFakeRate(_param.Muon_Tight_ID, fr_key , _param.FakeRateMethod,lep->fEta(), lep->Pt(),lep->LeptonFakeTagger());
      this_weight *= -1.*this_fr/(1.-this_fr);
      FRs.push_back(this_fr);

    }

    if(FRs.size()==0){
      return 0.;
    }
    else{
      //cout << this_weight<< " ML"<<endl;                                                                                                                                                                                                                                                                                                                                                                                               

      return this_weight;
    }
  }

  return -999.;
}





double AnalyzerCore::GetCFSF(AnalyzerParameter param, std::vector<Electron> electrons){

  double _SF=1.;

  for(auto i : electrons) {
    if(i.IsBB()) {
      if(GetYearString() == "2017"){
        if(param.Electron_Tight_ID == "POGTight") _SF*= 1.217 ;
        if(param.Electron_Tight_ID == "HNTightV2") _SF*=1.030 ;
        if(param.Electron_Tight_ID == "HNL_ULID_2017") _SF*= 1.119;
        if(param.Electron_Tight_ID == "TopHNSST") _SF*=1.162 ;
      }
      else{

      } 
    }
    else{
      if(GetYearString() == "2017"){
        if(param.Electron_Tight_ID == "POGTight") _SF*= 1.026;
        if(param.Electron_Tight_ID == "HNTightV2") _SF*= 1.060;
        if(param.Electron_Tight_ID == "HNL_ULID_2017") _SF*= 1.111 ;
        if(param.Electron_Tight_ID == "TopHNSST") _SF*= 1.052;
      }
      else{

      } 


    }
  }

  return _SF;

}


double AnalyzerCore::GetCFWeightElectron(std::vector<Lepton* > leps ,  AnalyzerParameter param, bool ApplySF){

  vector<double> el_pt,el_eta;
  for(auto ilep : leps){
    if(ilep->LeptonFlavour()==Lepton::ELECTRON){
      el_pt.push_back(ilep->Pt());
      el_eta.push_back(ilep->defEta());
    }
  }

  return GetCFWeightElectron(el_pt,el_eta, param, ApplySF);
}

double AnalyzerCore::GetCFWeightElectron(std::vector<Electron> electrons ,  AnalyzerParameter param,bool ApplySF){

  vector<double> el_pt, el_eta;
  for(auto ilep : electrons){
    el_pt.push_back(ilep.Pt());
    el_eta.push_back(ilep.scEta());
  }

  return GetCFWeightElectron(el_pt,el_eta, param, ApplySF);
}

double AnalyzerCore::GetCFWeightElectron(vector<double> el_pt, vector<double> el_eta, AnalyzerParameter param, bool ApplySF){

  //cfEst->IgnoreNoHist = param.MCCorrrectionIgnoreNoHist;                                                                                                                                                                                                                                                                                                                                                                               

  if(el_pt.size()  != 2) return 1.;


  double el1_cf_rate =   cfEst->GetElectronCFRate(param.Electron_Tight_ID, param.Electron_CF_Key,el_eta[0], el_pt[0], 0);
  double el2_cf_rate =   cfEst->GetElectronCFRate(param.Electron_Tight_ID, param.Electron_CF_Key,el_eta[1], el_pt[1], 0);

  if(ApplySF){
    el1_cf_rate *= 1.;
    el2_cf_rate *= 1.; /// No SF Yet                                                                                                                                                                                                                                                                                                                                                                                                     
  }

  double cf_weight = (el1_cf_rate / (1.-el1_cf_rate))  + (el2_cf_rate/(1.-el2_cf_rate));

  if(run_Debug) cout << "GetCFWeightElectron weight=" << cf_weight << endl;
  return cf_weight;
}





double AnalyzerCore::GetShiftCFEl(Electron el) {

  //// Get Shift for  Prompt -> CF Pt response                                                                                                                                                                                                                                                                                                                                                                                           
  double PtShift = 1.;
  if(el.IsBB()){
    if(el.Pt() < 50) PtShift = 0.995;
    else if(el.Pt() < 100) PtShift =  0.998;
    else  PtShift = 1;

  }
  else{
    if(el.Pt() < 50) PtShift = 0.987;
    else if(el.Pt() < 100) PtShift =  0.994;
    else if(el.Pt() < 250) PtShift =  0.997;
    else  PtShift = 0.999;
  }

  return PtShift;
}
