#include <CriterioDescarteTableau.h>

CriterioDescarteTableau::CriterioDescarteTableau()
{
    numeroCartas = NUMERO_CARTAS_MOV_DESCARTE_TABLEAU;
    puntuacion = PUNTUACION_DESCARTE_TABLEAU;
    valoracion = VALORACION_DESCARTE_TABLEAU;
}

CriterioDescarteTableau::CriterioDescarteTableau(const CriterioDescarteTableau& criterio) : CriterioMovimiento(criterio)
{
}

CriterioDescarteTableau::~CriterioDescarteTableau()
{
}

bool CriterioDescarteTableau::checkMovimiento() const
{
  if (not mazoOrigen->tieneCartas())
  {
    return false;
  }
  const Carta *origen = mazoOrigen->getUltimaCarta();
  const Carta *destino = mazoDestino->getUltimaCarta();

  if (not mazoDestino->tieneCartas())
  {
    return true;
  }

  return checkColor(origen, destino) && checkNumeros(origen, destino);
}

void CriterioDescarteTableau::doMovimiento() const
{
  for (int i = 0; i < numeroCartas; i++) 
  {
    mazoDestino->ponerCarta(mazoOrigen->quitarCarta());
  }
}

void CriterioDescarteTableau::undoMovimiento() const
{
  for (int i = 0; i < numeroCartas; i++) 
  {
    mazoOrigen->ponerCarta(mazoDestino->quitarCarta());
  }
}

void CriterioDescarteTableau::acepta(CriterioMovimientoVisitor *visitor)
{
  visitor->visita(this);
}

bool CriterioDescarteTableau::checkColor(const Carta *origen, const Carta *destino) const
{
  return not origen->mismoColor(*destino);
}

bool CriterioDescarteTableau::checkNumeros(const Carta *origen, const Carta *destino) const
{
  return origen->getNumero()->getNumero() == (destino->getNumero())->getPrevNumero();
}

CriterioMovimiento* CriterioDescarteTableau::clone()
{
  return new CriterioDescarteTableau(*this);
}
