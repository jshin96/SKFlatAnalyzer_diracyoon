#include "HNL_LeptonCore.h"

double HNL_LeptonCore::HNLZvtxSF(HNL_LeptonCore::Channel ch){
  // See https://indico.cern.ch/event/697573/contributions/2887077/attachments/1596611/2530584/hltZVtxInefficiency.pdf                                         

  if(ch == MuMu) return 1.;

  if(IsData) return 1.;
  if(DataYear==2016) return 1.;
  if(DataYear==2018) return 1.;
  if(DataYear==2017) return 0.991;

  return 1.;
}



bool HNL_LeptonCore::PassHEMVeto(std::vector<Lepton *> leps){

  int nel_hem(0);
  if (DataEra=="2018"){
    for(auto ilep : leps){
      if(ilep->IsMuon()) continue;

      if (ilep->Eta() < -1.25){
	if((ilep->Phi() < -0.82) && (ilep->Phi() > -1.62)) nel_hem++;
      }
    }
  }

  if(nel_hem >0) return false;

  return true;

}


double HNL_LeptonCore::GetDYWeakWeight(double mass){
  if(IsDATA) return 1.;
  if(!IsDYSample) return 1.;
  if(mass<55) return 0.988939;
  else if(mass<60) return 0.992556;
  else if(mass<65) return 0.996362;
  else if(mass<70) return 1.00086;
  else if(mass<75) return 1.00593;
  else if(mass<80) return 1.00989;
  else if(mass<85) return 1.01263;
  else if(mass<90) return 1.01373;
  else if(mass<95) return 1.01338;
  else if(mass<100) return 1.01242;
  else if(mass<110) return 1.01078;
  else if(mass<120) return 1.00839;
  else if(mass<130) return 1.00628;
  else if(mass<140) return 1.00461;
  else if(mass<150) return 1.0033;
  else if(mass<170) return 1.00201;
  else if(mass<200) return 0.999256;
  else if(mass<250) return 0.995825;
  else if(mass<300) return 0.992451;
  else if(mass<400) return 0.986289;
  else if(mass<500) return 0.979024;
  else if(mass<600) return 0.972292;
  else if(mass<700) return 0.967596;
  else if(mass<800) return 0.959725;
  else if(mass<1000) return 0.953025;
  else if(mass<1500) return 0.935142;
  else if(mass<2000) return 0.909548;
  else if(mass<3000) return 0.8895;
  else return 0.900657;
}

double HNL_LeptonCore::GetZptWeight(double mass,double rapidity,double pt,TString opt){

  if(!fZptWeightG) return 1.;

  if(mass==0) return 1.;
  if(isnan(rapidity)) return 1.;
  double m=mass;
  if(m<fZptWeightMaxis->GetXmin()) m=fZptWeightMaxis->GetXmin();
  if(m>=fZptWeightMaxis->GetXmax()) m=fZptWeightMaxis->GetXmax()-1e-6;
  double y=fabs(rapidity);
  if(y>=fZptWeightYaxis->GetXmax()) y=fZptWeightYaxis->GetXmax()-1e-6;
  if(pt<0) pt=0;
  if(pt>=650) pt=649.9;
  double sf=1.;

  opt.ToUpper();
  if(opt.Contains("G")) sf*=fZptWeightG->Eval(pt);

  if(opt.Contains("Y")){
    double ymin=fZptWeightYaxis->GetBinCenter(1);
    double ymax=fZptWeightYaxis->GetBinCenter(fZptWeightYaxis->GetNbins());
    int biny1,biny2;
    if(y<ymin){
      biny1=1;
      biny2=2;
    }else if(y>=ymax){
      biny1=fZptWeightYaxis->GetNbins()-1;
      biny2=fZptWeightYaxis->GetNbins();
    }else{
      int biny=fZptWeightYaxis->FindBin(y);
      if(y>=fZptWeightYaxis->GetBinCenter(biny)){
	biny1=biny;
	biny2=biny+1;
      }else{
	biny1=biny-1;
	biny2=biny;
      }
    }
    double y1=fZptWeightYaxis->GetBinCenter(biny1);
    double y2=fZptWeightYaxis->GetBinCenter(biny2);
    sf*=( (y2-y)*fZptWeightY[biny1]->Eval(pt) + (y-y1)*fZptWeightY[biny2]->Eval(pt) )/(y2-y1);
  }

  if(opt.Contains("M")){
    double mmin=fZptWeightMaxis->GetBinCenter(1);
    double mmax=fZptWeightMaxis->GetBinCenter(fZptWeightMaxis->GetNbins());
    int binm1,binm2;
    if(m<mmin){
      binm1=1;
      binm2=2;
    }else if(m>=mmax){
      binm1=fZptWeightMaxis->GetNbins()-1;
      binm2=fZptWeightMaxis->GetNbins();
    }else{
      int binm=fZptWeightMaxis->FindBin(m);
      if(m>=fZptWeightMaxis->GetBinCenter(binm)){
	binm1=binm;
	binm2=binm+1;
      }else{
	binm1=binm-1;
	binm2=binm;
      }
    }
    double m1=fZptWeightMaxis->GetBinCenter(binm1);
    double m2=fZptWeightMaxis->GetBinCenter(binm2);
    sf*=( (m2-m)*fZptWeightM[binm1]->Eval(pt) + (m-m1)*fZptWeightM[binm2]->Eval(pt) )/(m2-m1);
  }


  return sf;
}


void HNL_LeptonCore::SetupZptWeight(){
  TString _MCSample=MCSample;
  if(MCSample.Contains("MiNNLO")) _MCSample="MiNNLO";
  TString zptpath=(TString)getenv("DATA_DIR")+"/"+GetEra()+"/SMP/ZptWeight_"+_MCSample+".root";
  if(IsExists(zptpath)){
    cout<<"[SMPAnalyzerCore::SetupZptWeight] using file "+zptpath<<endl;
  }else{
    cout<<"[SMPAnalyzerCore::SetupZptWeight] no "+zptpath<<endl;
    return;
  }
  DeleteZptWeight();
  TFile f(zptpath);
  fZptWeightG=(TF1*)f.Get("zptweight_g");
  if(!fZptWeightG){
    cout<<"[SMPAnalyzerCore::SetupZptWeight] no zptweight_g"<<endl;
    exit(ENODATA);
  }
  fZptWeightYaxis=(TAxis*)f.Get("yaxis");
  if(!fZptWeightYaxis){
    cout<<"[SMPAnalyzerCore::SetupZptWeight] no yaxis"<<endl;
    exit(ENODATA);
  }
  fZptWeightY.resize(fZptWeightYaxis->GetNbins()+2,NULL);
  for(int i=1;i<fZptWeightYaxis->GetNbins()+1;i++){
    fZptWeightY[i]=(TF1*)f.Get(Form("zptweight_y%d",i));
    if(!fZptWeightY[i]){
      cout<<"[SMPAnalyzerCore::SetupZptWeight] no zptweight_y"+TString(i)<<endl;
      exit(ENODATA);
    }
  }
  fZptWeightMaxis=(TAxis*)f.Get("maxis");
  if(!fZptWeightMaxis){
    cout<<"[SMPAnalyzerCore::SetupZptWeight] no maxis"<<endl;
    exit(ENODATA);
  }
  fZptWeightM.resize(fZptWeightMaxis->GetNbins()+2,NULL);
  for(int i=1;i<fZptWeightMaxis->GetNbins()+1;i++){
    fZptWeightM[i]=(TF1*)f.Get(Form("zptweight_m%d",i));
    if(!fZptWeightM[i]){
      cout<<"[SMPAnalyzerCore::SetupZptWeight] no zptweight_m"+TString(i)<<endl;
      exit(ENODATA);
    }
  }
}


void HNL_LeptonCore::DeleteZptWeight(){
  if(fZptWeightG){
    delete fZptWeightG;
    fZptWeightG=NULL;
  }
  if(fZptWeightYaxis){
    delete fZptWeightYaxis;
    fZptWeightYaxis=NULL;
  }
  for(auto f:fZptWeightY){
    if(f) delete f;
  }
  fZptWeightY.clear();  
  if(fZptWeightMaxis){
    delete fZptWeightMaxis;
    fZptWeightMaxis=NULL;
  }
  for(auto f:fZptWeightM){
    if(f) delete f;
  }
  fZptWeightM.clear();
}


