#include <PartidaVista.h>

PartidaVista::PartidaVista()
{
}

PartidaVista::PartidaVista(OperacionController *controlador)
{
  this->controlador = controlador;
}

PartidaVista::~PartidaVista()
{
}

void PartidaVista::pinta()
{
  std::shared_ptr<PartidaKlondike> partida = controlador->getPartida();

  MazoPointer mazo = partida->getDescartes();
  mazo->acepta(this);
  mazo = partida->getStock();
  mazo->acepta(this);

  MazoList fundaciones = partida->getFundaciones();
  for (MazoList::iterator it = fundaciones.begin(); it != fundaciones.end(); ++it)
  {
    (*it)->acepta(this);
  }

  printTableaus(partida);
  printFundaciones(partida);
}

void PartidaVista::printTableaus(std::shared_ptr<PartidaKlondike> partida)
{
  MazoList tableaus = partida->getTableaus();
  int nTableau = 0;
  for (MazoList::iterator it = tableaus.begin(); it != tableaus.end(); ++it)
  {
    (*it)->acepta(this);
    nTableau++;
  }
}

void PartidaVista::printFundaciones(std::shared_ptr<PartidaKlondike> partida)
{
  MazoList fundaciones = partida->getFundaciones();
  int nFundacion = 0;
  for (MazoList::iterator it = fundaciones.begin(); it != fundaciones.end(); ++it)
  {
    (*it)->acepta(this);
    nFundacion++;
  }
}

void PartidaVista::visita(const Stock *stock) const
{

}

void PartidaVista::visita(const Fundacion *fundacion) const
{

}

void PartidaVista::visita(const Tableau *tableau) const
{

}

void PartidaVista::visita(const Descarte *descarte) const
{

}
