#include <CriterioStockDescarte.h>

CriterioStockDescarte::CriterioStockDescarte()
{
  numeroCartas = NUMERO_CARTAS_MOV_STOCK_DESCARTE;
  puntuacion = PUNTUACION_STOCK_DESCARTE;
  valoracion = VALORACION_STOCK_DESCARTE;
}

CriterioStockDescarte::CriterioStockDescarte(const CriterioStockDescarte& criterio) : CriterioMovimiento(criterio)
{
}

CriterioStockDescarte::~CriterioStockDescarte()
{
}

bool CriterioStockDescarte::checkMovimiento() const
{
  bool retval = false;
  if (mazoOrigen->tieneCartas())
  {
    retval = true;
  }
  return retval;
}

void CriterioStockDescarte::doMovimiento() const
{
  std::stack<Carta> cartasDesplazadas;
  for(int i = 0; i < numeroCartas && mazoOrigen->tieneCartas(); i++)
  {
    cartasDesplazadas.push(*(mazoOrigen->getUltimaCarta()));
    mazoOrigen->quitarCarta();
  }

  while(not cartasDesplazadas.empty())
  {
    Carta cartaDesplazada = cartasDesplazadas.top();
    cartaDesplazada.setVisibilidad(true);
    mazoDestino->ponerCarta(cartaDesplazada);
    cartasDesplazadas.pop();
  }
}

void CriterioStockDescarte::undoMovimiento() const
{
  std::stack<Carta> cartasDesplazadas;
  for(int i = 0; i < numeroCartas && mazoDestino->tieneCartas(); i++)
  {
    cartasDesplazadas.push(*(mazoDestino->getUltimaCarta()));
    mazoDestino->quitarCarta();
  }

  while(not cartasDesplazadas.empty())
  {
    Carta cartaDesplazada = cartasDesplazadas.top();
    cartaDesplazada.setVisibilidad(false);
    mazoOrigen->ponerCarta(cartaDesplazada);
    cartasDesplazadas.pop();
  }
}

void CriterioStockDescarte::acepta(CriterioMovimientoVisitor *visitor)
{
  visitor->visita(this);
}

CriterioMovimiento* CriterioStockDescarte::clone()
{
  return new CriterioStockDescarte(*this);
}
