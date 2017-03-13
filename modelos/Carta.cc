#include "Carta.h"

Carta::Carta() : palo(nullptr), numero(nullptr), visibilidad(false)
{

}

Carta::Carta(const std::shared_ptr<Palo> palo,  const std::shared_ptr<Numero> num) : palo(palo),
                                                                                     numero(num),
                                                                                     visibilidad(false)
{

}

Carta::Carta(const Carta& carta)
{
  this->palo = carta.getPalo();
  this->numero = carta.getNumero();
  this->visibilidad = carta.getVisibilidad();
}

Carta::~Carta()
{

}

bool Carta::mismoNumero(const Carta& carta) const
{
  return this->numero == carta.getNumero();
}

bool Carta::mismoColor(const Carta& carta) const
{
  return this->palo->mismoColor(carta.getPalo());
}

bool Carta::mismoPalo(const Carta& carta) const 
{
  return this->getPalo() == carta.getPalo();
}

const std::shared_ptr<Numero> Carta::getNumero() const
{
  return this->numero;
}

bool Carta::getVisibilidad() const
{
  return visibilidad;
}

void Carta::setVisibilidad(bool visible)
{
  this->visibilidad = visible;
}

const std::shared_ptr<Palo> Carta::getPalo() const
{
  return this->palo;
}
