#include "PartidaKlondike.h"

PartidaKlondike::PartidaKlondike() : marcador (0), minimo(0)
{
  estado = PartidaKlondike::Estado::INICIAL;
}

PartidaKlondike::PartidaKlondike(const PartidaKlondike& partida) : marcador (0), minimo(0)
{
  this->fundaciones = partida.getFundaciones();
  this->tableaus = partida.getTableaus();
  this->descartes = partida.getDescartes();
  this->stock = partida.getStock();
}

PartidaKlondike::~PartidaKlondike()
{

}

void PartidaKlondike::addTableau(const MazoPointer tableau)
{
  tableaus.push_back(tableau);
}

void PartidaKlondike::addFundacion(const MazoPointer fundacion)
{
  fundaciones.push_back(fundacion);
}

void PartidaKlondike::addStock(const MazoPointer stock)
{
  this->stock = stock;
}

void PartidaKlondike::addDescartes(const MazoPointer descartes)
{
  this->descartes = descartes;
}

void PartidaKlondike::deletePartida()
{
  descartes.reset();
  stock.reset();
  tableaus.clear();
  fundaciones.clear();
}

int PartidaKlondike::getEstado() const
{
  return estado;
}

void PartidaKlondike::setEstado(PartidaKlondike::Estado estado)
{
  this->estado = estado;
}

MazoPointer PartidaKlondike::getFundacion(int fundacion)
{
  return fundaciones[fundacion];
}

int PartidaKlondike::getNumFundaciones() {
  return fundaciones.size();
}

MazoPointer PartidaKlondike::getTableau(int tableau)
{
  return tableaus[tableau];
}

int PartidaKlondike::getNumTableaus() {
  return tableaus.size();
}

void PartidaKlondike::incMarcador(int puntuacion)
{
  marcador += puntuacion;
  if (marcador < 0)
  {
    marcador = 0;
  }
}

bool PartidaKlondike::tableausVacios()
{
  bool tableausVacios = true;
  for (int i = 0; i < getNumTableaus(); i++) {
    if (getTableau(i)->getNumeroCartas() != 0) {
      tableausVacios = false;
    }
  }
  return tableausVacios;
}

bool PartidaKlondike::comprobarVictoria()
{
  if (getStock()->getNumeroCartas() == 0 && getDescartes()->getNumeroCartas() == 0 && tableausVacios()) {
    return true;
  }
  return false;
}
