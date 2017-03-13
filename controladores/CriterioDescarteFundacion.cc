#include <CriterioDescarteFundacion.h>

CriterioDescarteFundacion::CriterioDescarteFundacion()
{
  numeroCartas = NUMERO_CARTAS_MOV_DESCARTE_FUNDACION;
  puntuacion = PUNTUACION_DESCARTE_FUNDACION;
  valoracion = VALORACION_DESCARTE_FUNDACION;
}

CriterioDescarteFundacion::CriterioDescarteFundacion(const CriterioDescarteFundacion& criterio) : CriterioMovimiento(criterio)
{
}

CriterioDescarteFundacion::~CriterioDescarteFundacion()
{
}

bool CriterioDescarteFundacion::checkMovimiento() const
{
  // TODO: REFACTORIZAR ESTA MIERDA
  if (not mazoOrigen->tieneCartas()) 
  {
    return false;
  }

  if (not mazoDestino->tieneCartas()) 
  {
    if (0 == mazoOrigen->getUltimaCarta()->getNumero()->getNumero())
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  const Carta *origen = mazoOrigen->getUltimaCarta();
  const Carta *destino = mazoDestino->getUltimaCarta();

  return checkPalos(origen, destino) && checkNumeros(origen, destino);
}

void CriterioDescarteFundacion::doMovimiento() const
{
  for (int i = 0; i < numeroCartas; i++) 
  {
    mazoDestino->ponerCarta(mazoOrigen->quitarCarta());
  }
}

void CriterioDescarteFundacion::undoMovimiento() const
{
  for (int i = 0; i < numeroCartas; i++) 
  {
    mazoOrigen->ponerCarta(mazoDestino->quitarCarta());
  }
}

void CriterioDescarteFundacion::acepta(CriterioMovimientoVisitor *visitor)
{
  visitor->visita(this);
}

bool CriterioDescarteFundacion::checkPalos(const Carta *origen, const Carta *destino) const
{
  return origen->getPalo() == destino->getPalo();
}

bool CriterioDescarteFundacion::checkNumeros(const Carta *origen, const Carta *destino) const
{
  return origen->getNumero()->getNumero() == (destino->getNumero())->getNextNumero();
}

CriterioMovimiento* CriterioDescarteFundacion::clone()
{
  return new CriterioDescarteFundacion(*this);
}
