#include <CriterioMovimiento.h>

CriterioMovimiento::CriterioMovimiento()
{
}

CriterioMovimiento::CriterioMovimiento(const CriterioMovimiento& criterio)
{
  mazoOrigen = criterio.mazoOrigen;
  mazoDestino = criterio.mazoDestino;
  numeroCartas = criterio.numeroCartas;
  puntuacion = criterio.puntuacion;
}

CriterioMovimiento::~CriterioMovimiento()
{
}

void CriterioMovimiento::setMazoOrigen(MazoPointer mazoOrigen)
{
  this->mazoOrigen = mazoOrigen;
}

void CriterioMovimiento::setMazoDestino(MazoPointer mazoDestino)
{
  this->mazoDestino = mazoDestino;
}

void CriterioMovimiento::setCartasParaMover(int numeroCartas)
{
  this->numeroCartas = numeroCartas;
}
