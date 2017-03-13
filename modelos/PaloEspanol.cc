#include "PaloEspanol.h"

PaloEspanol::PaloEspanol(const int palo) : Palo(palo, TIPO_PALO_ESPANOL)
{
}

PaloEspanol::~PaloEspanol() 
{
}
  
const bool PaloEspanol::mismoColor(const std::shared_ptr<Palo>& palo) const 
{
  return this->getPalo() == palo->getPalo();
}

const std::string PaloEspanol::getTextoPalo() const
{ 
  return numeroATexto[palo];
};
