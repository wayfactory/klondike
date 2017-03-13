#include "Numero.h"

Numero::Numero()
{

}

Numero::~Numero()
{

}

const bool Numero::operator==(const Numero* numero)
{
  return this-numero == numero->numero;
}

int Numero::getNumero() const
{
  return numero;
}
