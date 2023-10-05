#include "AnalyzerCore.h"


double AnalyzerCore::GetMuonSFEventWeight(std::vector<Muon> muons,AnalyzerParameter param ){

  double this_weight(1.);
  if(!IsDATA){

    mcCorr->IgnoreNoHist = param.MCCorrrectionIgnoreNoHist;

    for (auto mu: muons){
      double MiniAODP = sqrt( mu.MiniAODPt() * mu.MiniAODPt() + mu.Pz() * mu.Pz() );
      double this_pt  = mu.MiniAODPt();
      double this_eta = mu.Eta();


      //if(this_pt < 20) cout << "Muon ID SF " << param.Muon_ID_SF_Key << endl;                                                                                                                                                                                                                                                                                                                                                          

      int SystDir_MuonIDSF(0), SystDir_MuonISOSF(0), SystDir_MuonRecoSF (0);
      if(param.syst_ == AnalyzerParameter::MuonRecoSFUp)SystDir_MuonRecoSF = +1;
      else if(param.syst_ == AnalyzerParameter::MuonRecoSFDown)SystDir_MuonRecoSF = -1;
      else if(param.syst_ == AnalyzerParameter::MuonIDSFUp)  SystDir_MuonIDSF = +1;
      else if(param.syst_ == AnalyzerParameter::MuonIDSFDown)  SystDir_MuonIDSF = -1;
      else if(param.syst_ == AnalyzerParameter::MuonISOSFUp) SystDir_MuonISOSF  = +1;
      else if(param.syst_ == AnalyzerParameter::MuonISOSFDown) SystDir_MuonISOSF  = -1;

      double this_idsf   = mcCorr->MuonID_SF (param.Muon_ID_SF_Key,  this_eta, this_pt,SystDir_MuonIDSF);
      double this_isosf  = mcCorr->MuonISO_SF(param.Muon_ISO_SF_Key, this_eta, this_pt,SystDir_MuonISOSF);

      if(!HasFlag("NoIDSF")) this_weight *= this_idsf*this_isosf;

      if(param.DEBUG) cout << "GetMuonSFEventWeight this_idsf=" << this_idsf << " this_isosf=" << this_isosf  << endl;

      double reco_pt = (param.Muon_RECO_SF_Key  == "HighPtMuonRecoSF") ?  MiniAODP : this_pt;

      double this_recosf = mcCorr->MuonReco_SF(param.Muon_RECO_SF_Key, this_eta, reco_pt,SystDir_MuonRecoSF);

      this_weight *= this_recosf;

      FillWeightHist(param.Name+"/RecoMuWeight_"+param.Name,this_recosf);
      FillWeightHist(param.Name+"/IDMuWeight_"+param.Name,this_idsf);
      FillWeightHist(param.Name+"/ISOMuWeight_"+param.Name,this_isosf);

    }// end of muon loop                                                                                                                                                                                                                                                                                                                                                                                                                 

  }// end of MC req.                                                                                                                                                                                                                                                                                                                                                                                                                     

  bool apply_tracking_SF = true;
  double MuonTrackineSF(1.);

  //https://twiki.cern.ch/twiki/bin/view/CMSPublic/TrackingPOGResultsRun2Legacy#Muon_tracking_performance_in_AN2                                                                                                                                                                                                                                                                                                                         
  // https://cds.cern.ch/record/2724492/files/DP2020_035.pdf                                                                                                                                                                                                                                                                                                                                                                             
  if (apply_tracking_SF){
    if(DataEra=="2016preVFP"){
      for(auto im : muons) {
        if(fabs(im.Eta()) > 1.5) MuonTrackineSF*= 0.99;

      }
    }
    if(DataEra=="2016postVFP"){
      for(auto im : muons) {
        if(fabs(im.Eta()) > 1.) MuonTrackineSF*= 0.995;
      }
    }
    if(DataYear==2017){
      for(auto im : muons) {
        if(im.Pt() > 60. && im.Pt() < 120) MuonTrackineSF*= 0.995;
      }
    }

    if(DataYear==2018){
      for(auto im : muons) {
        if(im.Pt() > 60. && im.Pt() < 120) MuonTrackineSF*= 0.997;
      }
    }
    this_weight=this_weight*MuonTrackineSF;

    FillWeightHist(param.Name+"/TrackerMuWeight_"+param.Name,MuonTrackineSF);
  }

  FillWeightHist(param.Name+"/FullMuWeight_"+param.Name,this_weight);

  return this_weight;

}



double AnalyzerCore::GetLeptonSFEventWeight(std::vector<Lepton *> leps, AnalyzerParameter param ){

  double this_weight(1.);
  if(!IsDATA){

    mcCorr->IgnoreNoHist = param.MCCorrrectionIgnoreNoHist;

    int SystDir_MuonIDSF(0), SystDir_MuonISOSF(0), SystDir_MuonRecoSF (0);
    if(param.syst_ == AnalyzerParameter::MuonRecoSFUp)SystDir_MuonRecoSF = +1;
    else if(param.syst_ == AnalyzerParameter::MuonRecoSFDown)SystDir_MuonRecoSF = -1;
    else if(param.syst_ == AnalyzerParameter::MuonIDSFUp)  SystDir_MuonIDSF = +1;
    else if(param.syst_ == AnalyzerParameter::MuonIDSFDown)  SystDir_MuonIDSF = -1;
    else if(param.syst_ == AnalyzerParameter::MuonISOSFUp) SystDir_MuonISOSF  = +1;
    else if(param.syst_ == AnalyzerParameter::MuonISOSFDown) SystDir_MuonISOSF  = -1;

    int SystDir_ElectronIDSF(0),SystDir_ElectronRecoSF (0);
    if(param.syst_ == AnalyzerParameter::ElectronRecoSFUp)SystDir_ElectronRecoSF = +1;
    else if(param.syst_ == AnalyzerParameter::ElectronRecoSFDown)SystDir_ElectronRecoSF = -1;
    else if(param.syst_ == AnalyzerParameter::ElectronIDSFUp)  SystDir_ElectronIDSF = +1;
    else if(param.syst_ == AnalyzerParameter::ElectronIDSFDown)  SystDir_ElectronIDSF = -1;

    for (auto lep: leps){
      if(lep->LeptonFlavour() == Lepton::ELECTRON){
        double this_recosf  = mcCorr->ElectronReco_SF(lep->Eta(),lep->Pt(), SystDir_ElectronRecoSF);
        double this_idsf    = mcCorr->ElectronID_SF(param.Electron_ID_SF_Key, lep->Eta(), lep->Pt(), SystDir_ElectronIDSF);

	this_weight *= this_recosf*this_idsf;
      }
      if(lep->LeptonFlavour() == Lepton::MUON){

	double this_pt  = lep->Pt();
        double this_eta = lep->Eta();

	double this_idsf   = mcCorr->MuonID_SF (param.Muon_ID_SF_Key,  this_eta, this_pt,SystDir_MuonIDSF);
        double this_isosf  = mcCorr->MuonISO_SF(param.Muon_ISO_SF_Key, this_eta, this_pt,SystDir_MuonISOSF);

	this_weight *= this_idsf*this_isosf;

	//double reco_pt = (param.Muon_RECO_SF_Key  == "HighPtMuonRecoSF") ?  MiniAODP : this_pt;                                                                                                                                                                                                                                                                                                                                        
        double reco_pt =this_pt;
        double this_recosf = mcCorr->MuonReco_SF(param.Muon_RECO_SF_Key, this_eta, reco_pt,SystDir_MuonRecoSF);

	this_weight *= this_recosf;

      } 

    }

  }
  return this_weight;


}
double AnalyzerCore::GetElectronSFEventWeight(std::vector<Electron> electrons, AnalyzerParameter param ){

  double this_weight(1.);
  if(!IsDATA){

    mcCorr->IgnoreNoHist = param.MCCorrrectionIgnoreNoHist;


    int SystDir_ElectronIDSF(0), SystDir_ElectronRecoSF (0), SystDir_ElectronTriggerSF(0);
    if(param.syst_ == AnalyzerParameter::ElectronRecoSFUp)SystDir_ElectronRecoSF = +1;
    else if(param.syst_ == AnalyzerParameter::ElectronRecoSFDown)SystDir_ElectronRecoSF = -1;
    else if(param.syst_ == AnalyzerParameter::ElectronIDSFUp)  SystDir_ElectronIDSF = +1;
    else if(param.syst_ == AnalyzerParameter::ElectronIDSFDown)  SystDir_ElectronIDSF = -1;



    for (auto el: electrons){

      double pt = (el.Pt() < 15) ? 16 : el.Pt();
      double this_recosf  = mcCorr->ElectronReco_SF(el.scEta(),pt, SystDir_ElectronRecoSF);
      double this_idsf    = mcCorr->ElectronID_SF(param.Electron_ID_SF_Key, el.scEta(), pt, SystDir_ElectronIDSF);

      this_weight *= this_recosf*this_idsf;

      if(param.WriteOutVerbose == 0){
        FillWeightHist(param.Name+"/el_reco_sf_"+param.Name, this_recosf);
        FillWeightHist(param.Name+"/el_id_sf_"+param.Name, this_idsf);
      }
    }
  }
  return this_weight;

}





std::vector<Electron> AnalyzerCore::ScaleElectrons(const std::vector<Electron>& electrons, int sys){

  std::vector<Electron> out;
  for(unsigned int i=0; i<electrons.size(); i++){
    //==== electrons is a const vector. So in this function, we have to copy the elements like below                                                                                                                                                                                                                                                                                                                                     
    Electron this_electron = electrons.at(i);

    double this_sf = this_electron.EnShift(sys);
    this_electron.SetPtEtaPhiM( this_electron.Pt() * this_sf, this_electron.Eta(), this_electron.Phi(), this_electron.M() );

    out.push_back( this_electron );
  }
  std::sort(out.begin(),       out.end(),        PtComparing);

  return out;

}
std::vector<Electron> AnalyzerCore::SmearElectrons(const std::vector<Electron>& electrons, int sys){

  std::vector<Electron> out;
  for(unsigned int i=0; i<electrons.size(); i++){
    //==== electrons is a const vector. So in this function, we have to copy the elements like below                                                                                                                                                                                                                                                                                                                                     
    Electron this_electron = electrons.at(i);

    double this_sf = this_electron.ResShift(sys);
    this_electron.SetPtEtaPhiM( this_electron.Pt() * this_sf, this_electron.Eta(), this_electron.Phi(), this_electron.M() );

    out.push_back( this_electron );
  }

  std::sort(out.begin(),       out.end(),        PtComparing);

  return out;

}



std::vector<Muon> AnalyzerCore::ScaleMuons(const std::vector<Muon>& muons, int sys){

  std::vector<Muon> out;
  for(unsigned int i=0; i<muons.size(); i++){
    //==== muons is a const vector. So in this function, we have to copy the elements like below                                                                                                                                                                                                                                                                                                                                         
    Muon this_muon = muons.at(i);

    //==== Even for TuneP muons, MomentumShift() are set correctly from AnalyzerCore::UseTunePMuon()                                                                                                                                                                                                                                                                                                                                     
    //==== So we can just use MomentumShift()                                                                                                                                                                                                                                                                                                                                                                                            

    this_muon.SetPtEtaPhiM( this_muon.MomentumShift(sys), this_muon.Eta(), this_muon.Phi(), this_muon.M() );

    out.push_back(this_muon);

  }

  std::sort(out.begin(),       out.end(),        PtComparing);

  return out;

}

