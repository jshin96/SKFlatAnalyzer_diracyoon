#ifndef GenJet_h
#define GenJet_h

#include "Particle.h"

class GenJet: public Particle {
public:

  GenJet();
  ~GenJet();

  //==== For empty GenJet
  void SetIsEmpty(bool b);
  inline bool IsEmpty() const { return j_IsEmpty; }

  //==== GenJet Status Flags

private:
  bool j_IsEmpty;
  ClassDef(GenJet,1)


};

#endif
