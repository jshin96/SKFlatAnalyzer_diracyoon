#include "AnalyzerCore.h"


double AnalyzerCore::GetPrefireWeight(int sys){

  if(IsDATA) return 1.;
  else{
    if(sys==0) return L1PrefireReweight_Central;
    else if(sys>0) return L1PrefireReweight_Up;
    else return L1PrefireReweight_Down;
  }

  cout << "[AnalyzerCore::GetPrefireWeight] wtf" << endl;
  exit(EXIT_FAILURE);
  return 1.;

}

double AnalyzerCore::GetPileUpWeight(int N_pileup, int syst){
  if(IsDATA) return 1.;
  else return mcCorr->GetPileUpWeight(N_pileup, syst);
}

double AnalyzerCore::GetPDFWeight(LHAPDF::PDF* pdf_){

  double pdf_1 = pdf_->xfxQ(genWeight_id1, genWeight_X1, genWeight_Q);
  double pdf_2 = pdf_->xfxQ(genWeight_id2, genWeight_X2, genWeight_Q);

  return pdf_1 * pdf_2;

}

double AnalyzerCore::GetPDFReweight(){

  return GetPDFWeight(pdfReweight->NewPDF)/GetPDFWeight(pdfReweight->ProdPDF);

}

double AnalyzerCore::GetPDFReweight(int member){

  return GetPDFWeight(pdfReweight->PDFErrorSet.at(member))/GetPDFWeight(pdfReweight->ProdPDF);

}






bool AnalyzerCore::IsHEMIssueRun(){

  if(!IsDATA) return false;

  int RunNumber=run;
  return RunNumber>319077;

}

bool AnalyzerCore::IsHEMIssueReg(Particle& Particle){

  bool IstheRegion=false;
  double eta=Particle.Eta(), phi=Particle.Phi();

  if(eta>-3. && eta<-1.3 && phi>-1.57 && phi<-0.87) IstheRegion=true;

  return IstheRegion;
}



bool AnalyzerCore::IsHEMCRReg(Particle& Particle, TString Option){

  bool IstheRegion=false;
  double eta=Particle.Eta(), phi=Particle.Phi();
  bool SameEta = Option.Contains("SameEta");
  bool SamePhi = Option.Contains("SamePhi");

  if     (SameEta && (eta>-3. && eta<-1.3) && !(phi>-1.57 && phi<-0.87) ) IstheRegion=true;
  else if(SamePhi && (eta< 3. && eta> 1.3) &&  (phi>-1.57 && phi<-0.87) ) IstheRegion=true;

  return IstheRegion;
}



bool AnalyzerCore::FindHEMElectron(Electron electron){

  if (DataYear != 2018) return false;

  if (electron.Eta() < -1.25){
    if((electron.Phi() < -0.82) && (electron.Phi() > -1.62)) return true;
  }

  return false;

}


bool AnalyzerCore::PassMETFilter(){

  //==== https://twiki.cern.ch/twiki/bin/viewauth/CMS/MissingETOptionalFiltersRun2#UL_data                                                                                                                                                                                                                                                                                                                                               

  if(!Flag_goodVertices) return false;
  if(!IsFastSim){
    if(!Flag_globalSuperTightHalo2016Filter) return false;
  }
  if(!Flag_HBHENoiseFilter) return false;
  if(!Flag_HBHENoiseIsoFilter) return false;
  if(!Flag_EcalDeadCellTriggerPrimitiveFilter) return false;
  if(!Flag_BadPFMuonFilter) return false;
  if(!Flag_BadPFMuonDzFilter) return false;
  if(!Flag_eeBadScFilter) return false;
  if(DataYear>=2017){
    if(!Flag_ecalBadCalibFilter) return false;
  }

  return true;

}


double AnalyzerCore::GetZ0Weight(double valx){
  if(IsDATA) return 1.;
  double rt=1.;
  if(GetEra()=="2016preVFP"){
    double data_val=TMath::Gaus(valx,2.46312e-01,3.50458e+00,true);
    double mc_val=TMath::Gaus(valx,9.28612e-01,3.65203e+00,true);
    rt=data_val/mc_val;
  }else if(GetEra()=="2016postVFP"){
    double data_val=TMath::Gaus(valx,2.41640e-01,3.63717e+00,true);
    double mc_val=TMath::Gaus(valx,9.30108e-01,3.65454e+00,true);
    rt=data_val/mc_val;
  }else if(GetEra()=="2017"){
    double data_val=TMath::Gaus(valx,3.81830e-01,3.67614e+00,true);
    double mc_val=TMath::Gaus(valx,8.19642e-01,3.50992e+00,true);
    rt=data_val/mc_val;
  }else if(GetEra()=="2018"){
    double data_val=TMath::Gaus(valx,-1.36030e-01,3.41464e+00,true);
    double mc_val=TMath::Gaus(valx,3.58575e-02,3.50953e+00,true);
    rt=data_val/mc_val;
  } 
  if(rt>2) rt=2;
  return rt;
}
