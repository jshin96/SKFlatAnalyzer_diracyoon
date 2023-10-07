#include "AnalyzerCore.h"


TH1D* AnalyzerCore::GetHist1D(TString histname){

  TH1D *h = NULL;
  std::map<TString, TH1D*>::iterator mapit = maphist_TH1D.find(histname);
  if(mapit != maphist_TH1D.end()) return mapit->second;

  return h;  

}

TH2D* AnalyzerCore::GetHist2D(TString histname){

  TH2D *h = NULL;
  std::map<TString, TH2D*>::iterator mapit = maphist_TH2D.find(histname);
  if(mapit != maphist_TH2D.end()) return mapit->second;

  return h;

}

TH3D* AnalyzerCore::GetHist3D(TString histname){

  TH3D *h = NULL;
  std::map<TString, TH3D*>::iterator mapit = maphist_TH3D.find(histname);
  if(mapit != maphist_TH3D.end()) return mapit->second;

  return h;

}



double AnalyzerCore::FillWeightHist(TString label, double _weight){

  if(run_Debug) cout << "AnalyzerCore::FillWeightHist ["+label+"]  corr.=" <<   _weight << endl;

  double max_x_range = 5.;
  if(label.Contains("Lumi")) max_x_range = 5.+ 2*(fabs(_weight));

  if(!label.Contains("Syst_"))   FillHist( "weights/"+ label , _weight ,1., 200, -1.*max_x_range, max_x_range,"ev weight");

  return _weight;
}

double AnalyzerCore::FillFakeWeightHist(TString label, vector<Lepton *> Leps,AnalyzerParameter param,  double _weight){


  if(run_Debug) cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
  if(run_Debug) {
    for(auto i: Leps) {
      if(i->LeptonFlavour()==Lepton::MUON) cout << "Muon " << endl;
      else cout<< "Electron " << endl;
    }
  }

  if(run_Debug) cout << "nLep = " << Leps.size() << endl;
  if(run_Debug) cout << "Weight = " << _weight << endl;

  TString TLType="";
  for(auto i: Leps) {
    if(i->PassLepID())TLType+="T";
    else TLType+="L";
  }
  if(run_Debug) cout << "TLType = " << TLType << endl;

  //  if(Leps.size() > 0) cout << "LepTightIDName = " << Leps[0]->LepTightIDName() << endl;
  // cout << "TLType = " << TLType <<  " Weight = " << _weight << endl;

  FillHist( "FakeWeights/"+ label , _weight ,1., 200, -5., 5,"ev weight");

  if(Leps.size() == 2){

    bool T1 = Leps[0]->PassLepID();
    bool T2 = Leps[1]->PassLepID();
    if(T1&&T2)         FillHist( "FakeStudy/TLSplit/TightLoose"+ label , 1, _weight , 5, 0., 5);
    if(T1&&!T2)        FillHist( "FakeStudy/TLSplit/TightLoose"+ label , 2, _weight , 5, 0., 5);
    if(!T1&&T2)        FillHist( "FakeStudy/TLSplit/TightLoose"+ label , 3, _weight , 5, 0., 5);
    if(!T1&&!T2)       FillHist( "FakeStudy/TLSplit/TightLoose"+ label , 4, _weight , 5, 0., 5);
    if(run_Debug) cout << "FillFakeWeightHist Lepton Types T1T2 = " << T1 << " "  << T2 << endl;
  }

  for(auto ilep : Leps) {
    FillHist( "FakeStudy/MVAPlots/QCD_LFvsHF_v5_"+label, ilep->HNL_MVA_Fake("QCD_LFvsHF_v5"), 1, 100, -1., 1.);

    if(ilep->HNL_MVA_Fake("QCD_LFvsHF_v5") > 0) FillHist( "FakeStudy/MVAPlots/QCD_BvsC_v5_LF_"+label, ilep->HNL_MVA_Fake("QCD_BvsC_v5"), 1, 100, -1., 1);
    else  FillHist( "FakeStudy/MVAPlots/QCD_BvsC_v5_HF_"+label, ilep->HNL_MVA_Fake("QCD_BvsC_v5"), 1, 100, -1., 1.);


    if(!ilep->PassLepID())  {

      double FR = (ilep->LeptonFlavour()==Lepton::MUON) ? fakeEst->GetMuonFakeRate(param.Muon_Tight_ID, param.Muon_FR_Key , param.FakeRateMethod, ilep->fEta(), ilep->PtMaxed(60.), ilep->LeptonFakeTagger() ) :  fakeEst->GetElectronFakeRate(param.Electron_Tight_ID, param.Electron_FR_Key,param.FakeRateMethod, ilep->fEta(), ilep->PtMaxed(60.),ilep->LeptonFakeTagger() );


      double FRFlav = (ilep->LeptonFlavour()==Lepton::MUON) ? fakeEst->GetMuonFakeRate(param.Muon_Tight_ID, param.Muon_FR_Key , param.FakeRateMethod, ilep->fEta(), ilep->PtMaxed(60.), ilep->LeptonFakeTagger(),0) :  fakeEst->GetElectronFakeRate(param.Electron_Tight_ID,param.Electron_FR_Key,param.FakeRateMethod,ilep->fEta(), ilep->PtMaxed(60.), ilep->LeptonFakeTagger(), 0);

      if(run_Debug) cout << "!Tight Lep Type = " <<ilep->LeptonFakeTagger() << "  LFvsHFMVA = " << ilep->HNL_MVA_Fake("QCD_LFvsHF_v5") << " BvsC MVA = " << ilep->HNL_MVA_Fake("QCD_BvsC_v5")   << endl;
      if(run_Debug) cout << "!Tight Pt = " << ilep->PtMaxed(60.) << " pt = " << ilep->Pt() << " eta =  " << ilep->fEta() << " FR = " << FR << " FRFlav = " << FRFlav <<  endl;


      FillHist( "FakeStudy/Rates/"+ilep->LepTightIDName()+"/Loose_"+ label , FR, 1 , 1000, 0., 5);
      FillHist( "FakeStudy/Rates/"+ilep->LepTightIDName()+"/Loose_VsPt"+ label , ilep->PtMaxed(60.), FR, 1 , 60, 0, 60, 1000, 0., 5);
      FillHist( "FakeStudy/Rates/"+ilep->LepTightIDName()+"/Loose_"+ilep->sEtaRegion()+"_"+ label , FR, 1 , 1000, 0., 5);

    }

  }


  if(Leps.size() == 2){
    bool T1 = Leps[0]->PassLepID();
    bool T2 = Leps[1]->PassLepID();
    double FW = GetFakeWeight(Leps, param, false);
    if(T1&&T2)FillHist( "FakeStudy/EventWeight/TT_"+ label , FW, _weight , 100, 0., 5);
    if(T1&&!T2)FillHist( "FakeStudy/EventWeight/TL_"+ label , FW, _weight , 100, 0., 5);
    if(!T1&&T2)FillHist( "FakeStudy/EventWeight/LT_"+ label , FW, _weight , 100, 0., 5);
    if(!T1&&!T2)FillHist( "FakeStudy/EventWeight/LL_"+ label , FW, _weight , 100, 0., 5);
    if(run_Debug) cout << "EventWeight = " << FW << endl;
  }

  return _weight;
}




void AnalyzerCore::FillHist(TString histname, double value, double weight, int n_bin, double x_min, double x_max , TString label){

  TH1D *this_hist = GetHist1D(histname);
  if( !this_hist ){
    this_hist = new TH1D(histname, "", n_bin, x_min, x_max);
    this_hist->SetDirectory(NULL);
    this_hist->GetXaxis()->SetTitle(label);
    maphist_TH1D[histname] = this_hist;
  }

  this_hist->Fill(value, weight);

}


void AnalyzerCore::FillHist(TString histname, double value, double weight, int n_bin, double *xbins, TString label){

  TH1D *this_hist = GetHist1D(histname);
  if( !this_hist ){
    this_hist = new TH1D(histname, "", n_bin, xbins);
    this_hist->SetDirectory(NULL);
    this_hist->GetXaxis()->SetTitle(label);

    maphist_TH1D[histname] = this_hist;
  }

  this_hist->Fill(value, weight);

}

void AnalyzerCore::FillHist(TString histname,
			    double value_x, double value_y,
			    double weight,
			    int n_binx, double x_min, double x_max,
			    int n_biny, double y_min, double y_max){

  TH2D *this_hist = GetHist2D(histname);
  if( !this_hist ){
    this_hist = new TH2D(histname, "", n_binx, x_min, x_max, n_biny, y_min, y_max);
    this_hist->SetDirectory(NULL);
    maphist_TH2D[histname] = this_hist;
  }

  this_hist->Fill(value_x, value_y, weight);

}

void AnalyzerCore::FillHist(TString histname,
			    double value_x, double value_y,
			    double weight,
			    int n_binx, double *xbins,
			    int n_biny, double *ybins){

  TH2D *this_hist = GetHist2D(histname);
  if( !this_hist ){
    this_hist = new TH2D(histname, "", n_binx, xbins, n_biny, ybins);
    this_hist->SetDirectory(NULL);
    maphist_TH2D[histname] = this_hist;
    //cout << "CReating TH2D " <<  histname << endl;                                                                                                                                                                                                                                                                                                                        
  }

  this_hist->Fill(value_x, value_y, weight);

}

void AnalyzerCore::FillHist(TString histname,
                            double value_x, double value_y,
                            double weight,
                            int n_binx, double *xbins,
                            int n_biny, double y_min, double y_max){


  TH2D *this_hist = GetHist2D(histname);
  if( !this_hist ){
    this_hist = new TH2D(histname, "", n_binx, xbins, n_biny, y_min, y_max);
    this_hist->SetDirectory(NULL);
    maphist_TH2D[histname] = this_hist;
    //cout << "CReating TH2D " <<  histname << endl;                                                                                                                                                                                                                                                                                                                        
  }

  this_hist->Fill(value_x, value_y, weight);

}


void AnalyzerCore::FillHist(TString histname,
			    double value_x, double value_y, double value_z,
			    double weight,
			    int n_binx, double x_min, double x_max,
			    int n_biny, double y_min, double y_max,
			    int n_binz, double z_min, double z_max){

  TH3D *this_hist = GetHist3D(histname);
  if( !this_hist ){
    this_hist = new TH3D(histname, "", n_binx, x_min, x_max, n_biny, y_min, y_max, n_binz, z_min, z_max);
    this_hist->SetDirectory(NULL);
    maphist_TH3D[histname] = this_hist;
  }

  this_hist->Fill(value_x, value_y, value_z, weight);

}

void AnalyzerCore::FillHist(TString histname,
			    double value_x, double value_y, double value_z,
			    double weight,
			    int n_binx, const double *xbins,
			    int n_biny, const double *ybins,
			    int n_binz, const double *zbins){

  TH3D *this_hist = GetHist3D(histname);
  if( !this_hist ){
    this_hist = new TH3D(histname, "", n_binx, xbins, n_biny, ybins, n_binz, zbins);
    this_hist->SetDirectory(NULL);
    maphist_TH3D[histname] = this_hist;
  }

  this_hist->Fill(value_x, value_y, value_z, weight);

}

TH1D* AnalyzerCore::JSGetHist1D(TString suffix, TString histname){

  TH1D *h = NULL;

  std::map< TString, std::map<TString, TH1D*> >::iterator mapit = JSmaphist_TH1D.find(suffix);
  if(mapit==JSmaphist_TH1D.end()){
    return h;
  }
  else{

    std::map<TString, TH1D*> this_maphist = mapit->second;
    std::map<TString, TH1D*>::iterator mapitit = this_maphist.find(histname);
    if(mapitit != this_maphist.end()) return mapitit->second;

  }

  return h;

}




void AnalyzerCore::JSFillHist(TString suffix, TString histname, double value, double weight, int n_bin, double x_min, double x_max){

  TH1D *this_hist = JSGetHist1D(suffix, histname);
  if( !this_hist ){

    this_hist = new TH1D(histname, "", n_bin, x_min, x_max);
    (JSmaphist_TH1D[suffix])[histname] = this_hist;

  }

  this_hist->Fill(value, weight);

}

TH2D* AnalyzerCore::JSGetHist2D(TString suffix, TString histname){

  TH2D *h = NULL;

  std::map< TString, std::map<TString, TH2D*> >::iterator mapit = JSmaphist_TH2D.find(suffix);
  if(mapit==JSmaphist_TH2D.end()){
    return h;
  }
  else{

    std::map<TString, TH2D*> this_maphist = mapit->second;
    std::map<TString, TH2D*>::iterator mapitit = this_maphist.find(histname);
    if(mapitit != this_maphist.end()) return mapitit->second;

  }

  return h;

}

void AnalyzerCore::JSFillHist(TString suffix, TString histname,
			      double value_x, double value_y,
			      double weight,
			      int n_binx, double x_min, double x_max,
			      int n_biny, double y_min, double y_max){

  TH2D *this_hist = JSGetHist2D(suffix, histname);
  if( !this_hist ){

    this_hist = new TH2D(histname, "", n_binx, x_min, x_max, n_biny, y_min, y_max);
    (JSmaphist_TH2D[suffix])[histname] = this_hist;

  }

  this_hist->Fill(value_x, value_y, weight);

}

void AnalyzerCore::JSFillHist(TString suffix, TString histname,
			      double value_x, double value_y,
			      double weight,
			      int n_binx, double *xbins,
			      int n_biny, double *ybins){

  TH2D *this_hist = JSGetHist2D(suffix, histname);
  if( !this_hist ){

    this_hist = new TH2D(histname, "", n_binx, xbins, n_biny, ybins);
    (JSmaphist_TH2D[suffix])[histname] = this_hist;

  }

  this_hist->Fill(value_x, value_y, weight);

}


void AnalyzerCore::WriteHist(){

  outfile->cd();
  for(std::map< TString, TH1D* >::iterator mapit = maphist_TH1D.begin(); mapit!=maphist_TH1D.end(); mapit++){
    TString this_fullname=mapit->second->GetName();
    TString this_name=this_fullname(this_fullname.Last('/')+1,this_fullname.Length());
    TString this_suffix=this_fullname(0,this_fullname.Last('/'));
    TDirectory *dir = outfile->GetDirectory(this_suffix);
    if(!dir){
      outfile->mkdir(this_suffix);
    }
    outfile->cd(this_suffix);
    mapit->second->Write(this_name);
    outfile->cd();
  }
  for(std::map< TString, TH2D* >::iterator mapit = maphist_TH2D.begin(); mapit!=maphist_TH2D.end(); mapit++){
    TString this_fullname=mapit->second->GetName();
    TString this_name=this_fullname(this_fullname.Last('/')+1,this_fullname.Length());
    TString this_suffix=this_fullname(0,this_fullname.Last('/'));
    TDirectory *dir = outfile->GetDirectory(this_suffix);
    if(!dir){
      cout << "Making outdir  " << this_suffix << endl;
      outfile->mkdir(this_suffix);
    }
    outfile->cd(this_suffix);
    //cout << "Writing " << this_name << endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
    mapit->second->Write(this_name);
    outfile->cd();
  }
  for(std::map< TString, TH3D* >::iterator mapit = maphist_TH3D.begin(); mapit!=maphist_TH3D.end(); mapit++){
    TString this_fullname=mapit->second->GetName();
    TString this_name=this_fullname(this_fullname.Last('/')+1,this_fullname.Length());
    TString this_suffix=this_fullname(0,this_fullname.Last('/'));
    TDirectory *dir = outfile->GetDirectory(this_suffix);
    if(!dir){
      outfile->mkdir(this_suffix);
    }
    outfile->cd(this_suffix);
    mapit->second->Write(this_name);
    outfile->cd();
  }

  outfile->cd();
  for(std::map< TString, std::map<TString, TH1D*> >::iterator mapit=JSmaphist_TH1D.begin(); mapit!=JSmaphist_TH1D.end(); mapit++){

    TString this_suffix = mapit->first;
    std::map< TString, TH1D* > this_maphist = mapit->second;


    TDirectory *dir = outfile->GetDirectory(this_suffix);
    if(!dir){
      outfile->mkdir(this_suffix);
    }
    outfile->cd(this_suffix);

    for(std::map< TString, TH1D* >::iterator mapit = this_maphist.begin(); mapit!=this_maphist.end(); mapit++){
      mapit->second->Write();
    }

    outfile->cd();

  }

  for(std::map< TString, std::map<TString, TH2D*> >::iterator mapit=JSmaphist_TH2D.begin(); mapit!=JSmaphist_TH2D.end(); mapit++){

    TString this_suffix = mapit->first;
    std::map< TString, TH2D* > this_maphist = mapit->second;

    TDirectory *dir = outfile->GetDirectory(this_suffix);
    if(!dir){
      outfile->mkdir(this_suffix);
    }
    outfile->cd(this_suffix);

    for(std::map< TString, TH2D* >::iterator mapit = this_maphist.begin(); mapit!=this_maphist.end(); mapit++){
      mapit->second->Write();
    }

    outfile->cd();

  }


  //=== hist maps       
  if(TimingMap.size() > 0){
    auto itr = TimingMap.find("start");
    double start_time = itr->second;

    for(auto i : TimingMap) {
      cout << i.first << " processing time = " << (i.second- start_time) / CLOCKS_PER_SEC << endl;
    }
  }


  if(TimerMap.size() > 1){
    vector<TString> TimerLabels;
    for(auto i: TimeTagMatcher) TimerLabels.push_back(i.second);
    sort(TimerLabels.begin(), TimerLabels.end());

    TH1* timer_hist = new TH1D("TimeHist", "", TimerLabels.size(), 0, TimerLabels.size());
    for (unsigned int i=0 ; i < TimerLabels.size(); i++) timer_hist->GetXaxis()->SetBinLabel(i+1,TimerLabels[i]);
    timer_hist->SetDirectory(NULL);
    for(auto i : TimerMap) {
      if(i.first != "LATEST"){
        cout << i.first << " processing time = " << i.second << endl;
        timer_hist->Fill(i.first, i.second);
      }
    }

    TDirectory *dir = outfile->GetDirectory("Timer");
    if(!dir)  outfile->mkdir("Timer");
    outfile->cd("Timer");

    timer_hist->Write();
    outfile->cd();
    delete timer_hist;
  }


}




void AnalyzerCore::FillEventComparisonFile(AnalyzerParameter param,TString label,string date, double w){

  //// Make TEX file  

  ofstream ofile_tex;
  string lqdir = getenv("SKFlat_WD");

  if(!IsData)label = label  +"_" +MCSample;
  else label = label  +"_" +GetEra();

  string compfile = string(getenv("SKFlatEvCompDir")) +  "/"+date + "/"+string(param.Name)+string(label)+".txt";

  cout << "FillEventComparisonFile  " << label << " " << compfile << endl;
  ofile_tex.open(compfile.c_str(),ios::out | ios::app);

  ofile_tex.setf(ios::fixed,ios::floatfield);
  ofile_tex << "[ "<<getenv("USER") << " : " << run << " : " << event << " : " << param.Muon_Tight_ID << " : " << param.Electron_Tight_ID << " :  " << w <<   "]" << endl;

  ofile_tex.close();

  return;
}

void  AnalyzerCore::FillTimer(TString inittag){

  TString tag = "";
  if (TimeTagMatcher.find(inittag) == TimeTagMatcher.end()) {
    tag = TString(std::to_string(TimeTagMatcher.size())) +"_"+inittag;
    TimeTagMatcher[inittag] = tag;
  }
  else{
    auto itr = TimeTagMatcher.find(inittag);
    tag = itr->second;
  }

  if (TimerMap.find(tag) == TimerMap.end()) {
    auto itr = TimerMap.find("LATEST");
    double last_time = itr->second;
    TimerMap[tag] = (std::clock() - last_time)/ CLOCKS_PER_SEC;
  }
  else{
    auto itr = TimerMap.find("LATEST");
    auto itr2= TimerMap.find(tag);
    TimerMap[tag]= itr2->second + ( (std::clock() - itr->second)/ CLOCKS_PER_SEC);
  }
  TimerMap["LATEST"] =std::clock() ;

  if(_jentry==0) return;

  if(_jentry%10000==0){
    vector<TString> TimerLabels;
    for(auto i: TimeTagMatcher) TimerLabels.push_back(i.first);
    for(auto i : TimerMap) {
      if(i.first != "LATEST")    cout << i.first << " processing time = " << i.second << endl;
    }
  }

  return;
}
void  AnalyzerCore::AddTimerStamp(TString tag){

  if (TimingMap.find(tag) == TimingMap.end()) TimingMap[tag] = std::clock();

  return;

}

