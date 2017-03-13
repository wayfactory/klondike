#include <CriterioTableauTableau.h>

CriterioTableauTableau::CriterioTableauTableau()
{
  numeroCartas = NUMERO_CARTAS_MOV_TABLEAU_TABLEAU;
  puntuacion = PUNTUACION_TABLEAU_TABLEAU;
  valoracion = VALORACION_TABLEAU_TABLEAU;
}

CriterioTableauTableau::CriterioTableauTableau(const CriterioTableauTableau& criterio) : CriterioMovimiento(criterio)
{
}

CriterioTableauTableau::~CriterioTableauTableau()
{
}


bool CriterioTableauTableau::checkMovimiento() const
{
  if (not mazoOrigen->tieneCartas() || mazoOrigen == mazoDestino) 
  {
    return false;
  }
  bool allowedMovement = true;
  std::stack<Carta> cartasDesplazadas;
  for (int i = 0; i < numeroCartas && mazoOrigen->tieneCartas(); i++)
  {
    if (mazoOrigen->getUltimaCarta()->getVisibilidad()) {
      Carta cartaDesplazada = mazoOrigen->quitarCarta();
      cartasDesplazadas.push(cartaDesplazada);
    }
    else {
      allowedMovement = false;
    }
  }

  const Carta *origen = &cartasDesplazadas.top();
  const Carta *destino = mazoDestino->getUltimaCarta();

  allowedMovement &= (checkColor(origen, destino) && checkNumeros(origen, destino));

  while (not cartasDesplazadas.empty())
  {
    Carta cartaDevuelta = cartasDesplazadas.top();
    mazoOrigen->ponerCarta(cartaDevuelta);
    cartasDesplazadas.pop();
  }

  return allowedMovement;
}

void CriterioTableauTableau::doMovimiento() const
{
  std::stack<Carta> cartasDesplazadas;
  for (int i = 0; i < numeroCartas && mazoOrigen->tieneCartas(); i++)
  {
    cartasDesplazadas.push(mazoOrigen->quitarCarta());
  }

  while (not cartasDesplazadas.empty())
  {
    Carta &cartaDesplazada = cartasDesplazadas.top();
    cartaDesplazada.setVisibilidad(true);
    mazoDestino->ponerCarta(cartaDesplazada);
    cartasDesplazadas.pop();
  }
  if (mazoOrigen->tieneCartas() && false == mazoOrigen->getUltimaCarta()->getVisibilidad())
  {
    Carta cartaVolteada = mazoOrigen->quitarCarta();
    cartaVolteada.setVisibilidad(true);
    mazoOrigen->ponerCarta(cartaVolteada);
  }
}

void CriterioTableauTableau::undoMovimiento() const
{
  if (mazoDestino->tieneCartas() && true == mazoDestino->getUltimaCarta()->getVisibilidad())
  {
    Carta cartaVolteada = mazoOrigen->quitarCarta();
    cartaVolteada.setVisibilidad(false);
    mazoOrigen->ponerCarta(cartaVolteada);
  }

  std::stack<Carta> cartasDesplazadas;
  for (int i = 0; i < numeroCartas; i++)
  {
    cartasDesplazadas.push(mazoDestino->quitarCarta());
  }

  while (not cartasDesplazadas.empty())
  {
    Carta &cartaDesplazada = cartasDesplazadas.top();
    cartaDesplazada.setVisibilidad(true);
    mazoOrigen->ponerCarta(cartaDesplazada);
    cartasDesplazadas.pop();
  }
}

void CriterioTableauTableau::acepta(CriterioMovimientoVisitor *visitor)
{
  visitor->visita(this);
}

bool CriterioTableauTableau::checkColor(const Carta *origen, const Carta *destino) const
{
  if (nullptr == destino) return true;

  return not origen->mismoColor(*destino);
}

bool CriterioTableauTableau::checkNumeros(const Carta *origen, const Carta *destino) const
{
  if (nullptr == destino) return true;
  return ((origen->getNumero()->getNumero()) == ((destino->getNumero())->getPrevNumero()));
}

CriterioMovimiento* CriterioTableauTableau::clone()
{
  return new CriterioTableauTableau(*this);
}
