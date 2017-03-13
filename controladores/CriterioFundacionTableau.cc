#include <CriterioFundacionTableau.h>

CriterioFundacionTableau::CriterioFundacionTableau()
{
  numeroCartas = NUMERO_CARTAS_MOV_FUNDACION_TABLEAU;
  puntuacion = PUNTUACION_FUNDACION_TABLEAU;
  valoracion = VALORACION_FUNDACION_TABLEAU;
}

CriterioFundacionTableau::CriterioFundacionTableau(const CriterioFundacionTableau& criterio) : CriterioMovimiento(criterio)
{
}

CriterioFundacionTableau::~CriterioFundacionTableau()
{
}

bool CriterioFundacionTableau::checkMovimiento() const
{
  const Carta *origen = mazoOrigen->getUltimaCarta();
  const Carta *destino = mazoDestino->getUltimaCarta();

  if (not mazoDestino->tieneCartas())
  {
    return true;
  }

  return checkColor(origen, destino) && checkNumeros(origen, destino);
}

void CriterioFundacionTableau::doMovimiento() const
{
  for (int i = 0; i < numeroCartas; i++) 
  {
    mazoDestino->ponerCarta(mazoOrigen->quitarCarta());
  }
}

void CriterioFundacionTableau::undoMovimiento() const
{
  for (int i = 0; i < numeroCartas; i++) 
  {
    mazoOrigen->ponerCarta(mazoDestino->quitarCarta());
  }
}

void CriterioFundacionTableau::acepta(CriterioMovimientoVisitor *visitor)
{
  visitor->visita(this);
}

bool CriterioFundacionTableau::checkColor(const Carta *origen, const Carta *destino) const
{
  return not origen->mismoColor(*destino);
}

bool CriterioFundacionTableau::checkNumeros(const Carta *origen, const Carta *destino) const
{
  return origen->getNumero()->getNumero() == (destino->getNumero())->getPrevNumero();
}

CriterioMovimiento* CriterioFundacionTableau::clone()
{
  return new CriterioFundacionTableau(*this);
}
