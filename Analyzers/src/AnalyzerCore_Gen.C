#include "AnalyzerCore.h"


//=========================================================                                                                                                                                                        //==== Gen Matching Tools                                                                                                                                                                                          

void AnalyzerCore::PrintGen(const std::vector<Gen>& gens){

  cout << "===========================================================" << endl;
  cout << "RunNumber:EventNumber = " << run << ":" << event << endl;
  cout << "index\tPID\tStatus\tMIdx\tMPID\tStart\tPt\tEta\tPhi\tM" << endl;
  for(unsigned int i=2; i<gens.size(); i++){
    Gen gen = gens.at(i);
    if(!MCSample.Contains("Sherpa")){
      vector<int> history = TrackGenSelfHistory(gen, gens);
      cout << i << "\t" << gen.PID() << "\t" << gen.Status() << "\t" << gen.MotherIndex() << "\t" << gens.at(gen.MotherIndex()).PID()<< "\t" << history[0] << "\t";
    }

    printf("%.2f\t%.2f\t%.2f\t%.2f\n",gen.Pt(), gen.Eta(), gen.Phi(), gen.M());
  }

}

bool AnalyzerCore::GenTypeMatched(TString gen_string){

  vector<TString> lables =GetGenListPlot();
  if (std::find(lables.begin(), lables.end(), gen_string) == lables.end()) return false;

  return true;
}


vector<TString> AnalyzerCore::GetGenListPlot(){

  vector<TString> lables = {"electron",
                            "muon",
                            "pi0",
                            "pi+",
                            "ph",
                            "tau",
                            "q",
                            "c",
                            "b",
                            "t",
                            "g",
                            "K",
                            "K*",
                            "K+",
                            "D",
                            "D0",
                            "D+",
                            "B",
                            "B0",
                            "B+",
                            "D0_K+",
                            "B0_K+",
                            "LightMeson",
                            "ccMeson",
                            "bbMeson",
                            "CMeson",
                            "BMeson",
                            "CBaryon",
                            "BBaryon",
                            "proton",
                            "conv",

                            "__"};

  return lables;

}


vector<TString> AnalyzerCore::GetGenList(){

  vector<TString> lables = {"electron",
                            "muon",
                            "pi0ph",
                            "pi0",
                            "pi+",
                            "ph",
                            "tau",
                            "q",
                            "c",
                            "b",
                            "t",
                            "g",
                            "JPsi",
                            "K",
                            "K*",
                            "K+",
                            "D",
                            "D0",
                            "D+",
                            "B",
                            "B0",
                            "B+",
                            "D0_K+",
                            "B0_K+",
                            "LightMeson",
                            "CMeson",
                            "ccMeson",
                            "BMeson",
                            "bbMeson",
                            "CBaryon",
                            "BBaryon",
                            "proton",
                            "conv",

                            "__"};

  return lables;

}

TString AnalyzerCore::MatchGenPID(int PID, vector<Gen> gens,  Gen gen){

  if(PID == 13 && gen.Status()==1 && (fabs(gens.at(gen.MotherIndex()).PID()) == 24)) return "muon";
  if(PID == 11 && gen.Status()==1 && (fabs(gens.at(gen.MotherIndex()).PID()) == 24)) return "electron";
  if(PID == 22 && gen.Status()==1 && (fabs(gens.at(gen.MotherIndex()).PID()) == 111)) return "pi0ph";
  if(PID == 321 && gen.Status()==1 && (fabs(gens.at(gen.MotherIndex()).PID()) == 421)) {
    if(fabs( gens.at(gens.at(gen.MotherIndex()).MotherIndex()).PID()) == 413)     return "D";
    if(fabs( gens.at(gens.at(gen.MotherIndex()).MotherIndex()).PID()) == 423)     return "D";
    return "D0";
  }
  if(PID == 321 && gen.Status()==1 && (fabs(gens.at(gen.MotherIndex()).PID()) == 511)) {
    return "B0";
  }
  int MID = fabs(gens.at(gen.MotherIndex()).PID());

  if(PID == 511 )  return "B0";
  if(PID  == 531 ) return "B";
  if(PID  == 533 ) return "B";
  if(PID  == 521 ) return "B+";
  if(PID > 5000  && PID < 6000 ) return "BBaryon";
  if(PID > 4000  && PID < 5000 ) return "CBaryon";


  if(MID == 511 ) return "B0";
  if(MID  == 531 ) return "B";
  if(MID  == 533 ) return "B";
  if(MID  == 521 ) return "B+";
  if(MID  == 431 ) return "D";
  if(MID  == 433 ) return "D";
  if(MID > 5000  && MID < 6000 ) return "BBaryon";
  if(MID > 4000  && MID < 5000 ) return "CBaryon";


  return "";
}


TString AnalyzerCore::MatchGenDef(std::vector<Gen>& gens,const Lepton& Lep, bool DEBUG){

  //////////////// JOHN                                                                                                                                                                                                                                                                                                                                                                                                                  

  if(DEBUG) {cout << "Lepton type = " << Lep.GetFlavour() << endl;}
  int Idx_Closest    = GenMatchedIdx(Lep,gens);
  if(DEBUG) {cout << "Idx_Closest = " << Idx_Closest << endl;}
  if (Idx_Closest < 0){

    /// Check All particles since no matched status 1 lepton is found                                                                                                                                                                                                                                                                                                                                                                    

    double mindR=0.4;
    int closest_pid=9999;
    int Mclosest_pid=9999;

    vector<TString> MatchedGens;
    vector<int> MatchedGensID;
    vector<int> CloseGensID;
    int closest_id=-1;
    for(unsigned int i=2; i<gens.size(); i++){
      Gen gen = gens.at(i);
      if(gen.Pt() < 5) continue;
      if(fabs(gen.PID()) == 23) continue;
      if(fabs(gen.PID()) == 24) continue;
      if(fabs(gen.PID()) == 12) continue;
      if(fabs(gen.PID()) == 14) continue;
      if(fabs(gen.PID()) == 16) continue;
      if(fabs(gen.PID()) == 6) continue;

      if(Lep.DeltaR(gen) < 0.4)  {
        if(fabs(gen.Pt() - Lep.Pt() ) / Lep.Pt() < 0.25) {

          if(MatchGenPID(fabs(gen.PID()), gens, gen) != "") {
            return MatchGenPID(fabs(gen.PID()),gens,  gen);
          }
          MatchedGensID.push_back(i);
        }
        //cout << "CloseGensID.push_back " << i << endl;                                                                                                                                                                                                                                                                                                                                                                                 
        CloseGensID.push_back(i);
      }

      if(Lep.DeltaR(gen) < mindR ){
        mindR=Lep.DeltaR(gen) ;
        closest_pid= fabs(gen.PID());
        Mclosest_pid= fabs(gens[gen.MotherIndex()].PID());

        closest_id = i;
      }
    }

    mindR=0.4;
    TString pid_matched="NULL";
    for(auto j : MatchedGensID) {
      if(Lep.DeltaR(gens[j]) < mindR){
        mindR=Lep.DeltaR(gens[j]);

        if(fabs(gens[j].Pt() - Lep.Pt() ) / Lep.Pt() < 0.25) {
          pid_matched=Lep.PIDToString(fabs(gens[j].PID()));

          //cout << "pid_matched = " << pid_matched <<  " " <<  j <<endl;                                                                                                                                                                                                                                                                                                                                                                
          int mind = gens.at(j).MotherIndex();
          int pdid = j;
          //cout << "mind = " << mind << endl;                                                                                                                                                                                                                                                                                                                                                                                           
          while(std::find(CloseGensID.begin(), CloseGensID.end(), mind) != CloseGensID.end()) {
            if(fabs(gens.at(mind).PID()) <= 6)  break;
            if(fabs(gens.at(mind).PID()) == 2212)  break;

            pdid = mind;
            mind = gens.at(mind).MotherIndex();
          }

          if(fabs(gens[pdid].PID()) == 423) return "D";
          if(fabs(gens[pdid].PID()) == 421) return "D0";
          if(fabs(gens[pdid].PID()) == 431) return "D";
          if(fabs(gens[pdid].PID()) == 433) return "D";
          if(fabs(gens[pdid].PID()) == 413) return "D";
          if(fabs(gens[pdid].PID()) == 411) return "D+";
          if(fabs(gens[pdid].PID()) == 511) return "B0";
          if(fabs(gens[pdid].PID()) == 531) return "B";
          if(fabs(gens[pdid].PID()) == 533) return "B";
          if(fabs(gens[pdid].PID()) == 513) return "B";
          if(fabs(gens[pdid].PID()) == 521) return "B+";
          if(fabs(gens[pdid].PID()) == 523) return "B";

          if(fabs(gens[mind].PID()) == 423) return "D";
          if(fabs(gens[mind].PID()) == 421) return "D0";
          if(fabs(gens[mind].PID()) == 431) return "D";
          if(fabs(gens[mind].PID()) == 433) return "D";
          if(fabs(gens[mind].PID()) == 413) return "D";
          if(fabs(gens[mind].PID()) == 411) return "D+";
          if(fabs(gens[mind].PID()) == 511) return "B0";
          if(fabs(gens[mind].PID()) == 531) return "B";
          if(fabs(gens[mind].PID()) == 533) return "B";
          if(fabs(gens[mind].PID()) == 513) return "B";
          if(fabs(gens[mind].PID()) == 521) return "B+";
          if(fabs(gens[mind].PID()) == 523) return "B";

        }
      }
    }

    if(closest_pid == 11){
      vector<int> history = TrackGenSelfHistory(gens[closest_id], gens);
      if(fabs(gens.at(history[1]).PID()) == 23) return "electron";
      if(fabs(gens.at(history[1]).PID()) == 15) return "tau";
    }

    if(closest_pid == 13){
      vector<int> history = TrackGenSelfHistory(gens[closest_id], gens);
      if(fabs(gens.at(history[1]).PID()) == 23) return "muon";
      if(fabs(gens.at(history[1]).PID()) == 15) return "tau";
    }


    if(pid_matched!= "NULL")return pid_matched;

    if(closest_pid < 4) return "q";
    if(closest_pid == 4) return "c";
    if(closest_pid == 5) return "b";
    if(closest_pid == 11) return "electron";
    if(closest_pid == 13) return "muon";

    if(closest_pid == 22) return "ph";
    if(closest_pid == 21) return "g";
    if(closest_pid == 211)return "pi+";
    if(closest_pid == 111) return "pi0";
    if(closest_pid == 443) return "JPsi";
    if(closest_pid == 411) return "D+";
    if(closest_pid == 321) return "K+";
    if(closest_pid == 313) return "K*";
    if(closest_pid == 323) return "K*";

    if(closest_pid == 130) return "K";
    if(closest_pid == 310) return "K";
    if(closest_pid == 311) return "K";
    if(closest_pid == 10313) return "K";

    if(closest_pid == 223) return "LightMeson";
    if(closest_pid == 411) return "D+";
    if(closest_pid == 421) return "D0";
    if(closest_pid == 511) return "B0";
    if(closest_pid == 521) return "B+";
    if(closest_pid == 513) return "B";
    if(closest_pid == 523) return "B";
    if(closest_pid == 531) return "B";
    if(closest_pid == 533) return "B";

    int pdid2=-1;
    while(std::find(CloseGensID.begin(), CloseGensID.end(), closest_id) != CloseGensID.end()) {
      if(fabs(gens.at(closest_id).PID()) <= 6)  break;
      pdid2 = closest_id;
      closest_id = gens.at(closest_id).MotherIndex();
    }

    if(pdid2 > 0 )return Lep.PIDToString(gens.at(pdid2).PID());
    //    else {                                                                                                                                                                                                                                                                                                                                                                                                                         
    //  PrintMatchedGen(gens,Lep);                                                                                                                                                                                                                                                                                                                                                                                                       
    // }                                                                                                                                                                                                                                                                                                                                                                                                                                 

    if(closest_pid != 9999 )return Lep.PIDToString(closest_pid) ;


  }
  else{

    if(DEBUG) {cout << "MATCHED CLOSTEST  = fabs(gens.at(gens[Idx_Closest].MotherIndex()).PID()) " << fabs(gens.at(gens[Idx_Closest].MotherIndex()).PID())  <<endl;}


    vector<int> history; //= TrackGenSelfHistory(gens[Idx_Closest], gens);                                                                                                                                                                                                                                                                                                                                                               

    int motherindex = gens[Idx_Closest].MotherIndex();
    history.push_back(Idx_Closest);
    while(motherindex > 1){
      history.push_back(motherindex);
      motherindex = gens[motherindex].MotherIndex();
    }




    for(auto ig : history){
      if(fabs(gens.at(ig).PID()) == 521)return "B+";
      if(fabs(gens.at(ig).PID()) == 511)return "B0";
      if(fabs(gens.at(ig).PID()) == 421)return "D0";
      if(fabs(gens.at(ig).PID()) == 411)return "D+";
    }
    for(auto ig : history){
      if(Lep.LeptonFlavour()==Lepton::MUON && Lep.PIDToString(gens.at(ig).PID()) == "muon") continue;
      if(Lep.LeptonFlavour()==Lepton::ELECTRON && Lep.PIDToString(gens.at(ig).PID()) == "electron") continue;

      if(Lep.PIDToString(gens.at(ig).PID()) != "NULL") {
        if(Lep.PIDToString(gens.at(ig).PID()) == "D")  return Lep.PIDToString(gens.at(ig).PID());
        if(Lep.PIDToString(gens.at(ig).PID()) == "B")  return Lep.PIDToString(gens.at(ig).PID());
      }
    }

    for(auto ig : history){
      if(Lep.LeptonFlavour()==Lepton::MUON && Lep.PIDToString(gens.at(ig).PID()) == "muon") continue;
      if(Lep.LeptonFlavour()==Lepton::ELECTRON && Lep.PIDToString(gens.at(ig).PID()) == "electron") continue;
      if(Lep.PIDToString(gens.at(ig).PID()) != "NULL") return Lep.PIDToString(gens.at(ig).PID());
    }


    int mother_id = gens[Idx_Closest].MotherIndex();

    while(fabs(gens.at(mother_id).PID()) == 13)  mother_id = gens[mother_id].MotherIndex();
    while(fabs(gens.at(mother_id).PID()) == 11)  mother_id = gens[mother_id].MotherIndex();

    if(fabs(gens.at(mother_id).PID()) == 2212 ) {

      for(unsigned int i=2; i<gens.size(); i++){
        Gen gen = gens.at(i);
        if(Lep.DeltaR(gen) < 0.4)  {
          if(fabs(gen.PID()) == 22 && gen.Status()==1 && (fabs(gens.at(gen.MotherIndex()).PID()) == 111)) return "pi0ph";
          if((fabs(gens.at(gen.MotherIndex()).PID()) == 111)) return "pi0";
          if(fabs(gen.PID()) == 22 ) return "conv";

        }
      }
      return "proton";
    }

    if(fabs(gens.at(mother_id).PID()) == 2212)return "proton";
    if(fabs(gens.at(mother_id).PID()) == 22)return "ph";
    if(fabs(gens.at(mother_id).PID()) == 130)return "K0L";
    if(fabs(gens.at(mother_id).PID()) == 443)return "JPsi";
    if(fabs(gens.at(mother_id).PID()) == 15)return "tau";

    if(fabs(gens[Idx_Closest].PID()) != 11){
      if(fabs(gens.at(mother_id).PID()) == 11 )return "electron";
    }
    if(fabs(gens[Idx_Closest].PID()) !=13){

      if(fabs(gens.at(mother_id).PID()) == 13 )return "muon";
    }
  }

  return "__";
}




void AnalyzerCore::PrintMatchedGen(std::vector<Gen>& gens,const Lepton& Lep){

  cout << "===========================================================" << endl;
  cout << "RunNumber:EventNumber = " << run << ":" << event << endl;
  cout << "index\tPID\tStatus\tMIdx\tMPID\tStart\tPt\tEta\tPhi\tM" << endl;

  int Idx_Closest    = GenMatchedIdx(Lep,gens);
  cout << "Matched gen = " << Idx_Closest << endl;

  float minDr=1.;
  unsigned int closest_index = 0;
  for(unsigned int i=2; i<gens.size(); i++){

    Gen gen = gens.at(i);
    if(Lep.DeltaR(gen) < minDr)  {
      minDr = Lep.DeltaR(gen) ;
      closest_index = i;
    }
  }

  for(unsigned int i=2; i<gens.size(); i++){

    Gen gen = gens.at(i);
    vector<int> history = TrackGenSelfHistory(gen, gens);

    TString addon="";
    if(closest_index == i) addon = " ----> ";
    else addon="";
    if (Idx_Closest == i)  addon += " ----> ";
    //if(Lep.DeltaR(gen) < 0.4)     cout << "\033[91m\033[107m"<<  i << "\t" << gen.SPID() << "\t" << gen.Status() << "\t" << gen.MotherIndex() << "\t" << gens.at(gen.MotherIndex()).SPID()<< "\t" << history[0] << "\t \033[0m";                                                                                                                                                                                                       

    if(Lep.DeltaR(gen) < 0.4)  {
      cout <<  i << "\t" << gen.SPID() << "\t" << gen.Status() << "\t" << gen.MotherIndex() << "\t" << gens.at(gen.MotherIndex()).SPID()<< "\t" << history[0] << "\t";
      printf("%.2f\t%.2f\t%.2f\t%.2f =======> DrMatched %.2f\t "  +addon+ "\n",gen.Pt(), gen.Eta(), gen.Phi(), gen.M(),Lep.DeltaR(gen));
    }
    else {
      //  cout << i << "\t" << gen.SPID() << "\t" << gen.Status() << "\t" << gen.MotherIndex() << "\t" << gens.at(gen.MotherIndex()).SPID()<< "\t" << history[0] << "\t";                                                                                                                                                                                                                                                                
      //printf("%.2f\t%.2f\t%.2f\t%.2f\n",gen.Pt(), gen.Eta(), gen.Phi(), gen.M());                                                                                                                                                                                                                                                                                                                                                      
    }

  }

}





bool AnalyzerCore::HasPromptConv(Electron el){


  if(All_Gens.size() == 0) return false;

  int TruthIdx  = GenMatchedIdx(el, All_Gens);;

  int nSt1el(0);
  for(unsigned int i=2; i < All_Gens.size(); i++){
    if(TruthIdx == int(i)) continue;
    if(fabs(All_Gens.at(TruthIdx).Eta()-All_Gens.at(i).Eta())>0.1) continue;
    if(All_Gens.at(TruthIdx).DeltaPhi(All_Gens.at(i))>0.3) continue;
    if(All_Gens[TruthIdx].MotherIndex() == All_Gens[i].MotherIndex()){
      if(All_Gens[i].Status() == 1) {
        if(fabs(All_Gens[i].PID()) == 11) nSt1el++;
      }
    }
  }

  /// if nSt1el (number of status 1 electrons in dR < 0.4 from same mother , if > 1 e->eee  that passes JH Gen code                                                                                                                                                                                                                                                                                                                      
  bool bIsConv  =  (nSt1el > 0);

  return bIsConv;

}

bool AnalyzerCore::IsCF(Electron el, std::vector<Gen> truthColl, bool CheckCloseEl){

  int charge_el_reco = el.Charge();
  Lepton l = Lepton(el);

  int LepType = GetLeptonType_JH(el, truthColl);

  if(LepType<= 0)    return false;

  //// Get Index of matched Status 1 el                                                                                                                                                                                                                                                                                                                                                                                                  
  int Idx_Closest    = GenMatchedIdx(el,truthColl);

  if(CheckCloseEl){

    // check if multiple close status 1 el overlap                                                                                                                                                                                                                                                                                                                                                                                       
    int LastSelfIdx    = LastAbsSelfMotherIdx(Idx_Closest,All_Gens);

    int nSt1el(0);
    for(unsigned int i=2; i < All_Gens.size(); i++){
      if(Idx_Closest == i) continue;
      if(All_Gens[i].DeltaR(All_Gens[Idx_Closest])>0.1) continue;
      if(All_Gens[Idx_Closest].MotherIndex() == All_Gens[i].MotherIndex()){
        if(All_Gens[i].Status() == 1) {
          if(fabs(All_Gens[i].PID()) == 11) nSt1el++;
        }
      }
    }
    if(nSt1el > 0){
      int MGenQ = (All_Gens[LastSelfIdx].PID()  < 0 ) ? 1 : -1;
      if( fabs(All_Gens[LastSelfIdx].PID()) == 11 && (MGenQ != el.Charge()))  return  true;
      else return  false;
    }
  }

  int IdxType_NearEl = LepType>3? GetPrElType_InSameSCRange(Idx_Closest, truthColl, "IdxType"):Idx_Closest;
  int Idx_NearEl     = LepType>3? IdxType_NearEl/10:Idx_Closest;

  // METHOD 1                                                                                                                                                                                                                                                                                                                                                                                                                            
  // This does not include internal conv CF                                                                                                                                                                                                                                                                                                                                                                                              
  //bool method1=false;                                                                                                                                                                                                                                                                                                                                                                                                                  
  //Gen gen_el= GetGenMatchedLepton(l, truthColl);                                                                                                                                                                                                                                                                                                                                                                                       
  //int pdgid = gen_el.PID() ;                                                                                                                                                                                                                                                                                                                                                                                                           
  //if( (pdgid * charge_el_reco) > 0) method1=true;                                                                                                                                                                                                                                                                                                                                                                                      

  //if((charge_el_reco*truthColl.at(Idx_NearEl).PID()>0) != method1)cout << (charge_el_reco*truthColl.at(Idx_NearEl).PID()>0) << "  method 1= " << method1 << endl;                                                                                                                                                                                                                                                                      

  //  if((charge_el_reco*truthColl.at(Idx_NearEl).PID()>0) != method1) cout << "Lep Type = " << LepType << endl;                                                                                                                                                                                                                                                                                                                         

  if(charge_el_reco*truthColl.at(Idx_NearEl).PID()>0) return true;

  return false;
}


bool AnalyzerCore::IsCF(Muon mu, std::vector<Gen> truthColl){

  int charge_mu_reco = mu.Charge();
  Lepton l = Lepton(mu);

  int LepType = GetLeptonType_JH(mu, truthColl);

  if(LepType<= 0)    return false;
  int Idx_Closest    = GenMatchedIdx(mu,truthColl);
  int IdxType_NearEl = LepType>3? GetPrElType_InSameSCRange(Idx_Closest, truthColl, "IdxType"):Idx_Closest;
  int Idx_NearEl     = LepType>3? IdxType_NearEl/10:Idx_Closest;

  if(charge_mu_reco*truthColl.at(Idx_NearEl).PID()>0) return true;

  return false;
}

bool AnalyzerCore::ConversionSplitting(std::vector<Lepton *> leps, bool RunConvMode,  int nlep){

  if(!RunConvMode) return true;
  if(IsData) return true;

  int nlep_pt20(0);

  for(auto ilep : leps){

    if(ilep->Pt() > 15.) nlep_pt20++;
  }

  if(MCSample.Contains("WGTo") ||MCSample.Contains("ZGTo")){
    if(nlep_pt20 ==nlep) return true;
    else return false;
  }
  else if(MCSample.Contains("DYJet") || MCSample.Contains("WJet")) {

    if(nlep_pt20 !=nlep) return true;
    else return false;

  }

  return true;

}

bool AnalyzerCore::ConversionVeto(std::vector<Lepton *> leps,const std::vector<Gen>& gens){

  // function vetos conversion events in DY/X+G                                                                                                                                                                                                                                                                                                                                                                                          
  // since Z/G and WG have cut on photon in GEN need to overlap with DY                                                                                                                                                                                                                                                                                                                                                                  
  // Photon Cut is 15 GeV                                                                                                                                                                                                                                                                                                                                                                                                                
  //                                                                                                                                                                                                                                                                                                                                                                                                                                     

  if (IsData) return true;

  double ph_pt=-1;
  bool photon_found=false;
  bool GENTMatched=false;
  for(auto ilep : leps){
    for(unsigned int i=2; i<gens.size(); i++){
      Gen gen = gens.at(i);
      if(ilep->DeltaR(gen) < 0.2) {
        if(gen.PID() == 22 && gen.isPromptFinalState()) ph_pt = gen.Pt();
        if(gen.PID() == 22 && gen.isPromptFinalState() && gen.Pt()> 15.) {
          photon_found=true;
          GENTMatched=true;
          for(unsigned int j=2; j<gens.size(); j++){
            if(!(fabs(gens.at(j).PID()) <7 || fabs(gens.at(j).PID()) == 21)) continue;
            if(gens.at(j).Status() != 23) continue;
            if(gens.at(j).DeltaR(gen) <0.05)GENTMatched=false;
          }
        }
      }
    }
    if(GENTMatched) break;
  }

  if(!photon_found) {
    cout << "No Matching photon found " << endl;
    PrintGen(gens);
  }

  if(MCSample.Contains("WGTo") ||MCSample.Contains("ZGTo") )   {
    if(!photon_found) return true;
    if(!GENTMatched)cout << "GHENT Conv event removed in " << MCSample << endl;
    cout << "Matched photon pt = " << ph_pt << endl;
    return GENTMatched;
  }
  else if(MCSample.Contains("DYJet") || MCSample.Contains("WJet") ){
    if(!photon_found) return true;
    cout << "Matched photon pt = " << ph_pt << endl;
    return !GENTMatched;
  }

  return true;
}


