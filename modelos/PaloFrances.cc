#include "PaloFrances.h"

PaloFrances::PaloFrances(const int palo) : Palo(palo, TIPO_PALO_FRANCES)
{
}

PaloFrances::~PaloFrances()
{
}

const bool PaloFrances::mismoColor(const std::shared_ptr<Palo>& palo) const 
{
  bool thisRojo = false;
  bool paloRojo = false;
    
  if (ROMBOS == this->getPalo() || CORAZONES == this->getPalo()) {
    thisRojo = true;
  }

  if (ROMBOS == palo->getPalo() || CORAZONES == palo->getPalo()) {
    paloRojo = true;
  }

  return thisRojo == paloRojo;
}

const std::string PaloFrances::getTextoPalo() const 
{ 
  return numeroATexto[palo];
}
