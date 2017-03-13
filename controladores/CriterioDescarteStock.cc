#include <CriterioDescarteStock.h>

CriterioDescarteStock::CriterioDescarteStock()
{
    puntuacion = PUNTUACION_DESCARTE_STOCK;
    valoracion = VALORACION_DESCARTE_STOCK;
}

CriterioDescarteStock::CriterioDescarteStock(const CriterioDescarteStock& criterio) : CriterioMovimiento(criterio)
{
}

CriterioDescarteStock::~CriterioDescarteStock()
{
}

bool CriterioDescarteStock::checkMovimiento() const
{
  return not mazoDestino->tieneCartas();
}

void CriterioDescarteStock::doMovimiento() const
{
  while(mazoOrigen->tieneCartas())
  {
    mazoDestino->ponerCarta(mazoOrigen->quitarCarta());
  }
}

void CriterioDescarteStock::undoMovimiento() const
{
  while(mazoDestino->tieneCartas())
  {
    mazoOrigen->ponerCarta(mazoDestino->quitarCarta());
  }
}

void CriterioDescarteStock::acepta(CriterioMovimientoVisitor *visitor)
{
  visitor->visita(this);
}

CriterioMovimiento* CriterioDescarteStock::clone()
{
  return new CriterioDescarteStock(*this);
}
