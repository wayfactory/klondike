#include "Palo.h"

Palo::Palo()
{
}

Palo::Palo(int palo, int tipoPalo) : palo(palo), tipo(tipoPalo)
{
}

Palo::~Palo()
{
}

Palo::Palo(const Palo* palo) : palo(palo->getPalo())
{
}

const Palo* Palo::operator=(const Palo* palo)
{
  this->palo = palo->getPalo();
  return this;
}

const bool Palo::operator==(const Palo* palo)
{
  return this->palo == palo->getPalo();
}

const int Palo::getPalo() const
{
  return palo;
}

const int Palo::getTipo() const
{
  return tipo;
}
