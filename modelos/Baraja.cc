#include "Baraja.h"

Baraja::Baraja()
{
}

Baraja::~Baraja()
{
}

void Baraja::ponerCarta(const Carta& carta)
{
  baraja.push_back(carta);
}

Carta& Baraja::robarCarta()
{
  Carta& carta = baraja.back();
  baraja.pop_back();
  return carta;
}

void Baraja::barajar()
{
  std::srand( unsigned (std::time(0)));
  std::random_shuffle(std::begin(baraja), std::end(baraja));
}

const bool Baraja::estaVacia() const
{
  return baraja.size() == 0;
}
