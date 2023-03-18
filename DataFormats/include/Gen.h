#ifndef Gen_h
#define Gen_h

#include "Particle.h"

class Gen: public Particle {
public:

  Gen();
  ~Gen();

  void  PrintObject(TString label);


  //==== For empty Gen
  void SetIsEmpty(bool b);
  inline bool IsEmpty() const { return j_IsEmpty; }

  void SetIndexPIDStatus(int i, int p, int t);
  inline int Index() const { return j_index; }
  inline int PID() const { return j_PID; }
  inline TString SPID() const {
    
    if(fabs(j_PID)  < 7){
      TString sign="";
      if (j_PID < 0) sign="bar";
      if(fabs(j_PID) == 6) return "t"+sign;
      if(fabs(j_PID) == 5) return "b"+sign;
      if(fabs(j_PID) == 4) return "c"+sign;
      if(fabs(j_PID) == 3) return "s"+sign;
      if(fabs(j_PID) == 2) return "d"+sign;
      if(fabs(j_PID) == 1) return "u"+sign;
    }
    
    if(fabs(j_PID) == 11) return "e";
    if(fabs(j_PID) == 12) return "nue";
    if(fabs(j_PID) == 13) return "mu";
    if(fabs(j_PID) == 14) return "numu";
    if(fabs(j_PID) == 15) return "tau";
    if(fabs(j_PID) == 16) return "nutau";

    if(fabs(j_PID) == 21) return "g";
    if(fabs(j_PID) == 22) return "ph";
    if(fabs(j_PID) == 23) return "Z";
    if(fabs(j_PID) == 24) return "W";
    if(fabs(j_PID) == 2212) return "proton";

    if(fabs(j_PID) == 111) return "pi0";
    if(fabs(j_PID) == 211) return "pi+";
    if(fabs(j_PID) == 421) return "D0";
    if(fabs(j_PID) == 411) return "D+";
    if(fabs(j_PID) == 213) return "ρ(770)+";
    if(fabs(j_PID) == 311) return "K0";
    if(fabs(j_PID) == 321) return "K+";
    if(fabs(j_PID) == 511) return "B0";
    if(fabs(j_PID) == 521) return "B+";
    if(fabs(j_PID) == 523) return "B∗+";
    if(fabs(j_PID) == 425) return "D∗2(2460)0";
    if(fabs(j_PID) == 130) return "K0L";
    if(fabs(j_PID) == 310) return "K0S";

    if(fabs(j_PID) == 10313) return "K1(1270)0";

    return to_string(j_PID); 

  }

  inline int Status() const { return j_status; }
  void SetMother(int mindex);
  inline int MotherIndex() const { return j_mother_index; }

  //==== Gen Status Flags
  void SetGenStatusFlag_isPrompt(int i);
  void SetGenStatusFlag_isPromptFinalState(int i);
  void SetGenStatusFlag_isTauDecayProduct(int i);
  void SetGenStatusFlag_isPromptTauDecayProduct(int i);
  void SetGenStatusFlag_isDirectPromptTauDecayProductFinalState(int i);
  void SetGenStatusFlag_isHardProcess(int i);
  void SetGenStatusFlag_isLastCopy(int i);
  void SetGenStatusFlag_isLastCopyBeforeFSR(int i);
  void SetGenStatusFlag_isPromptDecayed(int i);
  void SetGenStatusFlag_isDecayedLeptonHadron(int i);
  void SetGenStatusFlag_fromHardProcessBeforeFSR(int i);
  void SetGenStatusFlag_fromHardProcessDecayed(int i);
  void SetGenStatusFlag_fromHardProcessFinalState(int i);
  void SetGenStatusFlag_isMostlyLikePythia6Status3(int i);

  inline bool isPrompt() const { return j_isPrompt; }
  inline bool isPromptFinalState() const { return j_isPromptFinalState; }
  inline bool isTauDecayProduct() const { return j_isTauDecayProduct; }
  inline bool isPromptTauDecayProduct() const { return j_isPromptTauDecayProduct; }
  inline bool isDirectPromptTauDecayProductFinalState() const { return j_isDirectPromptTauDecayProductFinalState; }
  inline bool isHardProcess() const { return j_isHardProcess; }
  inline bool isLastCopy() const { return j_isLastCopy; }
  inline bool isLastCopyBeforeFSR() const { return j_isLastCopyBeforeFSR; }
  inline bool isPromptDecayed() const { return j_isPromptDecayed; }
  inline bool isDecayedLeptonHadron() const { return j_isDecayedLeptonHadron; }
  inline bool fromHardProcessBeforeFSR() const { return j_fromHardProcessBeforeFSR; }
  inline bool fromHardProcessDecayed() const { return j_fromHardProcessDecayed; }
  inline bool fromHardProcessFinalState() const { return j_fromHardProcessFinalState; }
  inline bool isMostlyLikePythia6Status3() const { return j_isMostlyLikePythia6Status3; }

  virtual void Print() const;

private:

  bool j_IsEmpty;
  int j_index, j_PID, j_status;
  int j_mother_index;
  bool j_isPrompt, j_isPromptFinalState, j_isTauDecayProduct, j_isPromptTauDecayProduct, j_isDirectPromptTauDecayProductFinalState, j_isHardProcess, j_isLastCopy, j_isLastCopyBeforeFSR, j_isPromptDecayed, j_isDecayedLeptonHadron, j_fromHardProcessBeforeFSR, j_fromHardProcessDecayed, j_fromHardProcessFinalState, j_isMostlyLikePythia6Status3;

  ClassDef(Gen,1)
};

#endif
