#include "BarajaBuilder.h"

BarajaBuilder::BarajaBuilder()
{
}

BarajaBuilder::~BarajaBuilder()
{
}

void BarajaBuilder::anadePalo(const std::shared_ptr<Palo>& palo)
{
  palos.push_back(palo);
}

void BarajaBuilder::anadeNumero(const std::shared_ptr<Numero>& numero)
{
  numeros.push_back(numero);
}

Baraja& BarajaBuilder::getBaraja()
{
  return baraja;
}

Baraja& BarajaBuilder::construirBaraja()
{
  construirPalos();
  construirNumeros();

  for (auto palo : palos) {
    for (auto numero : numeros) {
      Carta carta(palo, numero);
      this->baraja.ponerCarta(carta);
    }
  }
  return this->baraja;
}
