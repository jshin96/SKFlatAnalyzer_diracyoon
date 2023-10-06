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
