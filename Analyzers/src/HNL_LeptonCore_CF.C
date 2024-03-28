#include "HNL_LeptonCore.h"


double HNL_LeptonCore::GetCFSF(AnalyzerParameter param, std::vector<Lepton* > leps, bool ApplySF){

  if(!ApplySF) return 1;
  /*
    Function to get DATA/MC SF for CF Bkg
    Depends on ID/Eta
   */

  double _SF=1.;

  map<TString,vector<double> > CFSFValues;
  CFSFValues["passPOGTight_BB"]      =  {0.884205, 0.859094, 1.208, 1.34367};
  CFSFValues["HNTightV2_BB"]     =  {0.655483, 0.742084, 1.026, 1.18759};
  CFSFValues["HNL_ULID_BB"]      =  {1.27854,  1.34035,  1.110, 0.754886};
  CFSFValues["TopHNSST_BB"]      =  {0.80,     0.79,     1.162, 1.47};
  CFSFValues["passPOGTight_EC"]      =  {0.771518, 0.76695,  1.026, 1.06369};
  CFSFValues["HNTightV2_EC"]     =  {0.659254, 0.683188, 1.060, 1.12502 };
  CFSFValues["HNL_ULID_EC"]      =  {1.23574,  1.10426,  1.111, 0.78659};
  CFSFValues["TopHNSST_EC"]      =  {0.78,     0.83,     1.31,  1.28};

  map<TString,vector<double> >::iterator CFMapIter ;
  for(auto i : leps) {
    if(i->IsMuon()) continue;
    TString CFKey = param.Electron_Tight_ID+"_"+i->GetEtaRegion(); 
    CFKey=CFKey.ReplaceAll("_"+GetYearString(),"");
    CFMapIter = CFSFValues.find(CFKey);
    if(CFMapIter == CFSFValues.end()) {  cout << "[HNL_LeptonCore::GetCFSF ] ERROR in CFSF.. " << CFKey  << endl;   exit(EXIT_FAILURE);}
    _SF*= CFMapIter->second[GetEraNum()-1];
  }
  

  return _SF;

}


double HNL_LeptonCore::GetCFWeightElectron(std::vector<Electron> El ,  AnalyzerParameter param, bool ApplySF){

  std::vector<Lepton *> Leptons = MakeLeptonPointerVector(El,param);
  return GetCFWeightElectron(Leptons, param, ApplySF);

}

double HNL_LeptonCore::GetCFWeightElectron(std::vector<Lepton* > leps ,  AnalyzerParameter param, bool ApplySF){

  vector<double> el_pt,el_eta;
  for(auto ilep : leps){
    if(ilep->LeptonFlavour()==Lepton::ELECTRON){
      el_pt.push_back(ilep->Pt());
      el_eta.push_back(ilep->defEta());
    }
  }
  
  if(leps.size()  != 2) return 1.;
  if(el_pt.size() != 2) return 1.;

  double el1_cf_rate =   cfEst->GetElectronCFRate(param.Electron_Tight_ID, param.k.Electron_CF,el_eta[0], el_pt[0], 0);
  double el2_cf_rate =   cfEst->GetElectronCFRate(param.Electron_Tight_ID, param.k.Electron_CF,el_eta[1], el_pt[1], 0);

  el1_cf_rate *= GetCFSF(param,leps,ApplySF);
  el2_cf_rate *= GetCFSF(param,leps,ApplySF);

  double cf_weight = (el1_cf_rate / (1.-el1_cf_rate))  + (el2_cf_rate/(1.-el2_cf_rate));

  if(run_Debug) cout << "GetCFWeightElectron weight=" << cf_weight << endl;
  return cf_weight;
}




double HNL_LeptonCore::GetZMassShift(vector<Electron> Electrons) {

  if(Electrons.size() != 2) return 1;

  if(Electrons[0].Charge() == Electrons[1].Charge()) return 1;

  if(DataEra=="2016preVFP"){
    if(Electrons[0].IsBB() && Electrons[1].IsBB())  return 0.993;
    if(Electrons[0].IsEC() && Electrons[1].IsEC())  return 0.996;
    return (0.993+0.996)/2.;

  }
  else  if(DataEra=="2016postVFP"){
    if(Electrons[0].IsBB() && Electrons[1].IsBB())  return 0.992;
    if(Electrons[0].IsEC() && Electrons[1].IsEC())  return 0.995;
    return (0.992+0.995)/2.;

  }
  if(DataEra=="2017"){
    if(Electrons[0].IsBB() && Electrons[1].IsBB())  return 0.987;
    if(Electrons[0].IsEC() && Electrons[1].IsEC())  return 0.993;
    return (0.987+0.993)/2.;
  }
  else if(DataEra=="2018"){
    /// 2018/16 Need updating
    if(Electrons[0].IsBB() && Electrons[1].IsBB())  return 0.988;
    if(Electrons[0].IsEC() && Electrons[1].IsEC())  return 0.993;
    return (0.988+0.993)/2.;
  }
  
  return 1;

}
double HNL_LeptonCore::GetShiftCFEl(Electron el) {

  //// Get Shift for  Prompt -> CF Pt response                                                                                                                                                                   

  double PtShift = 1.;
                                                                                                                                                                                                               
  if(DataEra=="2016preVFP"){
    if(el.etaRegionString() == "EB1"){
      if(el.Pt() < 30)       PtShift = 0.994;
      else if(el.Pt() < 50)  PtShift = 0.996;
      else if(el.Pt() < 100) PtShift = 0.999;
      else                   PtShift = 1;
    }
    else if(el.etaRegionString() == "EB2"){
      if(el.Pt() < 30)       PtShift = 0.986;
      else if(el.Pt() < 50)  PtShift = 0.992;
      else if(el.Pt() < 100) PtShift = 0.997;
      else if(el.Pt() < 250) PtShift = 0.999;
      else                   PtShift = 0.999;
    }
    else if(el.etaRegionString() == "EE1"){
      if(el.Pt() < 30)       PtShift = 0.979;
      else if(el.Pt() < 50)  PtShift = 0.989;
      else if(el.Pt() < 75)  PtShift = 0.994;
      else if(el.Pt() < 100) PtShift = 0.996;
      else if(el.Pt() < 250) PtShift = 0.998;
      else                   PtShift = 0.999;
    }
    else if(el.etaRegionString() == "EE2"){
      if(el.Pt() < 30)       PtShift = 0.986;
      else if(el.Pt() < 50)  PtShift = 0.993;
      else if(el.Pt() < 75)  PtShift = 0.996;
      else if(el.Pt() < 100) PtShift = 0.997;
      else if(el.Pt() < 250) PtShift = 0.998;
      else                   PtShift = 1.;
    }
  }

  if(DataEra=="2016postVFP"){
    if(el.etaRegionString() == "EB1"){
      if(el.Pt() < 30)       PtShift = 0.995;
      else if(el.Pt() < 50)  PtShift = 0.996;
      else if(el.Pt() < 75)  PtShift = 0.998;
      else if(el.Pt() < 100) PtShift = 0.998;
      else if(el.Pt() < 250) PtShift = 1;
      else                   PtShift = 1;
    }
    if(el.etaRegionString() == "EB2"){
      if(el.Pt() < 30)       PtShift = 0.987;
      else if(el.Pt() < 50)  PtShift = 0.991;
      else if(el.Pt() <  75) PtShift = 0.996;
      else if(el.Pt() < 100) PtShift = 0.997;
      else if(el.Pt() < 250) PtShift = 0.998;
      else                   PtShift = 1;
    }
    if(el.etaRegionString() == "EE1"){
      if(el.Pt() < 30)       PtShift = 0.98;
      else if(el.Pt() < 50)  PtShift = 0.988;
      else if(el.Pt() <  75) PtShift = 0.994;
      else if(el.Pt() < 100) PtShift = 0.996;
      else if(el.Pt() < 250) PtShift = 0.998;
      else                   PtShift = 1.;
    }
    if(el.etaRegionString() == "EE2"){
      if(el.Pt() < 30)       PtShift = 0.986;
      else if(el.Pt() < 50)  PtShift = 0.993;
      else if(el.Pt() <  75) PtShift = 0.996;
      else if(el.Pt() < 100) PtShift = 0.997;
      else if(el.Pt() < 250) PtShift = 0.998;
      else                   PtShift = 0.999;
    }
  }


  if(GetYearString() == "2017"){
    if(el.etaRegionString() == "EB1"){
      if(el.Pt() < 30)       PtShift = 0.97;
      else if(el.Pt() < 50)  PtShift = 0.993;
      else if(el.Pt() < 75)  PtShift = 0.993;
      else if(el.Pt() < 100) PtShift = 0.998;
      else if(el.Pt() < 250) PtShift = 0.999;
      else                   PtShift = 1;
    }
    if(el.etaRegionString() == "EB2"){
      if(el.Pt() < 30)       PtShift = 0.985;
      else if(el.Pt() < 50)  PtShift = 0.991;
      else if(el.Pt() <  75) PtShift = 0.995;
      else if(el.Pt() < 100) PtShift = 0.997;
      else if(el.Pt() < 250) PtShift = 0.999;
      else                   PtShift = 1;
    }
    if(el.etaRegionString() == "EE1"){
      if(el.Pt() < 30)       PtShift = 0.976;
      else if(el.Pt() < 50)  PtShift = 0.985;
      else if(el.Pt() < 100) PtShift = 0.992;
      else if(el.Pt() <  75) PtShift = 0.995;
      else if(el.Pt() < 250) PtShift = 0.997;
      else                   PtShift = 0.998;
    }
    if(el.etaRegionString() == "EE2"){
      if(el.Pt() < 30)       PtShift = 0.985;
      else if(el.Pt() < 50)  PtShift = 0.991;
      else if(el.Pt() <  75) PtShift = 0.994;
      else if(el.Pt() < 100) PtShift = 0.996;
      else if(el.Pt() < 250) PtShift = 0.998;
      else                   PtShift = 0.999;
    }

  }


  if(GetYearString() == "2018"){
    if(el.etaRegionString() == "EB1"){
      if(el.Pt() < 30)       PtShift = 0.971;
      else if(el.Pt() < 50)  PtShift = 0.995;
      else if(el.Pt() <  75) PtShift = 0.999;
      else if(el.Pt() < 100) PtShift = 0.999;
      else if(el.Pt() < 250) PtShift = 1;
      else                   PtShift = 1;
    }
    if(el.etaRegionString() == "EB2"){
      if(el.Pt() < 30)       PtShift = 0.987;
      else if(el.Pt() < 50)  PtShift = 0.992;
      else if(el.Pt() <  75) PtShift = 0.995;
      else if(el.Pt() < 100) PtShift = 0.998;
      else if(el.Pt() < 250) PtShift = 0.998;
      else                   PtShift = 1;
    }
    if(el.etaRegionString() == "EE1"){
      if(el.Pt() < 30)       PtShift = 0.976;
      else if(el.Pt() < 50)  PtShift = 0.985;
      else if(el.Pt() <  75) PtShift = 0.992;
      else if(el.Pt() < 100) PtShift = 0.994;
      else if(el.Pt() < 250) PtShift = 0.997;
      else                   PtShift = 0.999;
    }
    if(el.etaRegionString() == "EE2"){
      if(el.Pt() < 50)       PtShift = 0.985;
      else if(el.Pt() < 50)  PtShift = 0.991;
      else if(el.Pt() <  75) PtShift = 0.994;
      else if(el.Pt() < 100) PtShift = 0.996;
      else if(el.Pt() < 250) PtShift = 0.997;
      else                   PtShift = 0.998;
    }

  }


  return PtShift;
}

