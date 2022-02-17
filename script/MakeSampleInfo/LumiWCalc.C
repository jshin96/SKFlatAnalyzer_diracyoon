void LumiWCalc(TString filepath){

  int Nevent=0; int SumW=0.;

  TFile* file = new TFile(filepath);
  if(!file){ cout<<"no file"<<endl; return; }
  TH1* hist = (TH1*) file->Get("sumW");
  if(!hist){ cout<<"no hist:sumW"<<endl; return; }
  Nevent = hist->GetEntries();
  SumW = hist->GetBinContent(1);
  
  printf("%d %d\n", Nevent, SumW);

  delete file;
  return; 
}



float GetNentries_old(TString filename){

  TFile* file = new TFile(filename);

  TTree* tree;
  file->GetObject("recoTree/SKFlat", tree);
//  if(tree==NULL){ delete file; return 0; }

  Long64_t nentries = tree->GetEntries();

  delete file;

  return nentries;
}


float GetSumW_old(TString filename){

  TFile* file = new TFile(filename);

  TTree* tree = (TTree*) file->Get("recoTree/SKFlat");
//  if(tree==NULL){ delete file; return 0; }

  double gen_Weight=0;
  TBranch        *b_gen_Weight;

  tree->SetBranchAddress("gen_weight", &gen_Weight, &b_gen_Weight);

  double sum_weight=0.;
  Long64_t nentries = tree->GetEntries();

  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    tree->LoadTree(jentry);
    tree->GetEntry(jentry);
    sum_weight += gen_Weight;
  }

  delete file;

  return sum_weight;
}

void LumiWCalc_old(std::string filepath){

  std::vector<TString> Vec_subfile;
  ifstream filelist(filepath);
  string line;
  while (getline(filelist,line)){
    TString currentfile(line);
    Vec_subfile.push_back(currentfile);
  }

  float Nevent=0; float SumW=0.;

  for(unsigned int it=0; it<Vec_subfile.size(); it++){
    Nevent+=GetNentries_old(Vec_subfile.at(it));
    SumW+=GetSumW_old(Vec_subfile.at(it));
  }

  cout<<Nevent<<" "<<SumW<<endl;
   
}
