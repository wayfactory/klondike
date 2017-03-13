#include "Mazo.h"

Mazo::Mazo()
{
}

Mazo::~Mazo()
{
}

void Mazo::ponerCarta(Carta& carta)
{
  mazo.push_back(carta);
}

Carta& Mazo::quitarCarta()
{
  std::vector<Carta>::iterator primerElemento = mazo.end() - 1;
  mazo.pop_back();
  
  return *primerElemento;
}

bool Mazo::tieneCartas() const
{
  return mazo.size() != 0;
}

int Mazo::getNumeroCartas() const
{
  return mazo.size();
}

int Mazo::getNumeroCartasNoVisibles() const
{
  int noVisibles = 0;
  for (auto carta : mazo) {
    if (carta.getVisibilidad() == false) {
      noVisibles++;
    }
  }
  return noVisibles;
}

int Mazo::getNumeroCartasVisibles() const
{
  return (getNumeroCartas() - getNumeroCartasNoVisibles());
}

const CartaList Mazo::getCartas() const
{
  return mazo;
}


const Carta* Mazo::getUltimaCarta() const
{
  if (0 == mazo.size())
    return nullptr;

  return &(mazo.back());
}
