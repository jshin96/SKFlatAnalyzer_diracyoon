#include "SkimTree_EventSkim.h"

void SkimTree_EventSkim::initializeAnalyzer(){

  outfile->cd();
  cout << "[SkimTree_EventSkim::initializeAnalyzer()] gDirectory = " << gDirectory->GetName() << endl;
  newtree = fChain->CloneTree(0);


}

void SkimTree_EventSkim::executeEvent(){

  newtree->Fill();
  //if(newtree->Fill()<0) exit(EIO);
  return;
}

void SkimTree_EventSkim::executeEventFromParameter(AnalyzerParameter param){

}

SkimTree_EventSkim::SkimTree_EventSkim(){
  newtree=NULL;
}

SkimTree_EventSkim::~SkimTree_EventSkim(){

}

void SkimTree_EventSkim::WriteHist(){

  outfile->mkdir("recoTree");
  outfile->cd("recoTree");
  newtree->Write();
  outfile->cd();

}
