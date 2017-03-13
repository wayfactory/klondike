#include "KlondikeCargarBuilder.h"

KlondikeCargarBuilder::KlondikeCargarBuilder()
{

}

std::shared_ptr<Mazo> KlondikeCargarBuilder::construyeStock(CartaList& cartas)
{
  std::shared_ptr<Mazo> stock(new Stock());

  if (!cartas.empty())
  {
    for (CartaList::iterator it = cartas.begin(); it != cartas.end(); ++it)
    {
      (*stock).ponerCarta((*it));
    }
  }

  return stock;
}

std::shared_ptr<Mazo> KlondikeCargarBuilder::construyeDescarte(CartaList& cartas)
{
  std::shared_ptr<Mazo> descarte(new Descarte());

  if (!cartas.empty())
  {
    for (CartaList::iterator it = cartas.begin(); it != cartas.end(); ++it)
    {
      (*descarte).ponerCarta((*it));
    }
  }

  return descarte;
}

std::shared_ptr<Mazo> KlondikeCargarBuilder::construyeFundacion(CartaList& cartas, int numeroFundacion)
{
  std::shared_ptr<Mazo> fundacion(new Fundacion(numeroFundacion));

  if (!cartas.empty())
  {
    for (CartaList::iterator it = cartas.begin(); it != cartas.end(); ++it)
    {
      (*fundacion).ponerCarta((*it));
    }
  }

  return fundacion;
}

std::shared_ptr<Mazo> KlondikeCargarBuilder::construyeTableau(CartaList& cartas, const int numeroTableau)
{
  std::shared_ptr<Mazo> tableau(new Tableau(numeroTableau));

  if (!cartas.empty())
  {
    for (CartaList::iterator it = cartas.begin(); it != cartas.end(); ++it)
    {
      (*tableau).ponerCarta((*it));
    }
  }

  return tableau;
}

const std::shared_ptr<Numero>& KlondikeCargarBuilder::getNumero(int num)
{
  return numeros[num];
}

const std::shared_ptr<Palo>& KlondikeCargarBuilder::getPalo(int palo)
{
  return palos[palo];
}
