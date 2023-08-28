void LumiWCalc(TString filepath){

  int Nevent=0, SumSgn=0; double SumW=0.;

  TFile* file = new TFile(filepath);
  if(!file){ cout<<"no file"<<endl; return; }
  TH1* histSumSgn = (TH1*) file->Get("sumSign");
  TH1* histSumW   = (TH1*) file->Get("sumW");
  if(!histSumW or !histSumSgn){ cout<<"no histSumW or histSumSgn"<<endl; return; }
  Nevent = histSumSgn->GetEntries();
  SumSgn = histSumSgn->GetBinContent(1);
  SumW   = histSumW  ->GetBinContent(1);
  
  printf("%d %d %e\n", Nevent, SumSgn, SumW);

  delete file;
  return; 
}
