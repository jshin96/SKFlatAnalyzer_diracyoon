#include "GenJet.h"

ClassImp(GenJet)

GenJet::GenJet() : Particle() {
  j_IsEmpty = true;
}

GenJet::~GenJet(){
}

void GenJet::SetIsEmpty(bool b){
  j_IsEmpty = b;
}
