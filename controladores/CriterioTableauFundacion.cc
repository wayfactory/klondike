#include <CriterioTableauFundacion.h>
#include <iostream>

CriterioTableauFundacion::CriterioTableauFundacion()
{
  numeroCartas = NUMERO_CARTAS_MOV_TABLEAU_FUNDACION;
  puntuacion = PUNTUACION_TABLEAU_FUNDACION;
  valoracion = VALORACION_TABLEAU_FUNDACION;
}

CriterioTableauFundacion::CriterioTableauFundacion(const CriterioTableauFundacion& criterio) : CriterioMovimiento(criterio)
{
}

CriterioTableauFundacion::~CriterioTableauFundacion()
{
}


bool CriterioTableauFundacion::checkMovimiento() const
{
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

  return checkColor(origen, destino) && checkNumeros(origen, destino);
}

void CriterioTableauFundacion::doMovimiento() const
{
  for (int i = 0; i < numeroCartas; i++) 
  {
    mazoDestino->ponerCarta(mazoOrigen->quitarCarta());
  }
  if (mazoOrigen->tieneCartas() && false == mazoOrigen->getUltimaCarta()->getVisibilidad()) 
  {
    Carta cartaVolteada = mazoOrigen->quitarCarta();
    cartaVolteada.setVisibilidad(true);
    mazoOrigen->ponerCarta(cartaVolteada);
  }
}

void CriterioTableauFundacion::undoMovimiento() const
{
  if (mazoOrigen->tieneCartas() && true == mazoOrigen->getUltimaCarta()->getVisibilidad()) 
  {
    Carta cartaVolteada = mazoOrigen->quitarCarta();
    cartaVolteada.setVisibilidad(false);
    mazoOrigen->ponerCarta(cartaVolteada);
  }

  for (int i = 0; i < numeroCartas; i++) 
  {
    mazoOrigen->ponerCarta(mazoDestino->quitarCarta());
  }
}

void CriterioTableauFundacion::acepta(CriterioMovimientoVisitor *visitor)
{
  visitor->visita(this);
}

bool CriterioTableauFundacion::checkColor(const Carta *origen, const Carta *destino) const
{
  return origen->mismoColor(*destino);
}

bool CriterioTableauFundacion::checkNumeros(const Carta *origen, const Carta *destino) const
{
  return origen->getNumero()->getNumero() == (destino->getNumero())->getNextNumero();
}

CriterioMovimiento* CriterioTableauFundacion::clone()
{
  return new CriterioTableauFundacion(*this);
}
