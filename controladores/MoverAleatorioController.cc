#include <MoverAleatorioController.h>
#include <iostream>

MoverAleatorioController::MoverAleatorioController() : puntuacionMovimiento(0), origenPrevio(-1), tableauToTableauAvg(0)
{
  
}

MoverAleatorioController::MoverAleatorioController(const std::shared_ptr<PartidaKlondike>& partida) : MoverController(partida), puntuacionMovimiento(0), origenPrevio(-1), tableauToTableauAvg(0)
{
}

MoverAleatorioController::~MoverAleatorioController()
{
}

bool MoverAleatorioController::mover()
{
  bool success = false;
  if (criterio->checkMovimiento())
  {
    criterio->doMovimiento();
    success = true;
    movimientos.insertMovimiento(criterio);
    getPartida()->incMarcador(criterio->getPuntuacion());

    puntuacionMovimiento = 0;
    mazoOrigen = 0;
    mazoDestino = 0;

    if (numeroCartas == 0) {
      tableauToTableauAvg -= 1;
    }

    numeroCartas = 0;
    
    if (getPartida()->comprobarVictoria()) {
      terminarPartida();
    }
  }
  return success;
}

void MoverAleatorioController::acepta(OperacionControllerVisitor *operacionControllerVisitor)
{
  operacionControllerVisitor->visita(this);
}

void MoverAleatorioController::visita(CriterioDescarteStock *criterio)
{
  criterio->setMazoOrigen(partida->getDescartes());
  criterio->setMazoDestino(partida->getStock());
  
  if (criterio->getValoracion() > puntuacionMovimiento && criterio->checkMovimiento()) {
    puntuacionMovimiento = criterio->getValoracion();
    this->criterio = criterio;
  }
}

void MoverAleatorioController::visita(CriterioStockDescarte *criterio)
{
  criterio->setMazoOrigen(partida->getStock());
  criterio->setMazoDestino(partida->getDescartes());
  
  if (criterio->getValoracion() > puntuacionMovimiento && criterio->checkMovimiento()) {
    puntuacionMovimiento = criterio->getValoracion();
    this->criterio = criterio;
  }
}

void MoverAleatorioController::visita(CriterioDescarteFundacion *criterio)
{
  
  for (int i = 0; i < partida->getNumFundaciones(); i++) {
    mazoDestino = i;
    criterio->setMazoOrigen(partida->getDescartes());
    criterio->setMazoDestino(partida->getFundacion(mazoDestino));
  
    if (criterio->getValoracion() > puntuacionMovimiento && criterio->checkMovimiento()) {
      puntuacionMovimiento = criterio->getValoracion();
      this->criterio = criterio;
      break;
    }
  }
}

void MoverAleatorioController::visita(CriterioDescarteTableau *criterio)
{
  for (int i = 0; i < partida->getNumTableaus(); i++) {
    mazoDestino = i;
    criterio->setMazoOrigen(partida->getDescartes());
    criterio->setMazoDestino(partida->getTableau(mazoDestino));
    if (criterio->getValoracion() > puntuacionMovimiento && criterio->checkMovimiento()) {
      puntuacionMovimiento = criterio->getValoracion();
      this->criterio = criterio;
      break;
    }
  }
}

void MoverAleatorioController::visita(CriterioTableauFundacion *criterio)
{
  int found = false;
  for (int i = 0; i < partida->getNumTableaus() && not found; i++) {
    for (int j = 0; j < partida->getNumFundaciones() && not found; j++) {
      mazoOrigen = i;
      mazoDestino = j;
      criterio->setMazoOrigen(partida->getTableau(mazoOrigen));
      criterio->setMazoDestino(partida->getFundacion(mazoDestino));
      if (criterio->getValoracion() > puntuacionMovimiento && criterio->checkMovimiento()) {
	puntuacionMovimiento = criterio->getValoracion();
      	this->criterio = criterio;
	found = true;
      }
    }
  }
}

int MoverAleatorioController::testTableauToTableau(CriterioTableauTableau *criterio, MazoPointer origen, MazoPointer destino) {
  criterio->setMazoOrigen(origen);
  criterio->setMazoDestino(destino);
  int mejorJugada = 0;
  
  for (int i = 1; i <= origen->getNumeroCartasVisibles(); i++) {
    criterio->setCartasParaMover(i);
    if (criterio->checkMovimiento()) {
      int current = criterio->getValoracion() + origen->getNumeroCartasNoVisibles() + (i/2) - tableauToTableauAvg;
      if (puntuacionMovimiento < current) {
	mejorJugada = i;
	puntuacionMovimiento = current;
      }
    }
  }
  
  return mejorJugada;
}

void MoverAleatorioController::visita(CriterioTableauTableau *criterio)
{
  int origenFinal = 0;
  int destinoFinal = 0;
  int cartasFinal = 0;
  
  for (int i = 0; i < partida->getNumTableaus(); i++) {
    for (int j = 0; j < partida->getNumTableaus(); j++) {
      if (origenPrevio != j) {
	int nCartas = testTableauToTableau(criterio, partida->getTableau(i), partida->getTableau(j));
      
	if (nCartas) {
	  origenFinal = i;
	  destinoFinal = j;
	  cartasFinal = nCartas;
	}
      }
    }
  }
  
  if (cartasFinal != 0) {
    tableauToTableauAvg += 1;
    origenPrevio = origenFinal;
    criterio->setMazoOrigen(partida->getTableau(origenFinal));
    criterio->setMazoDestino(partida->getTableau(destinoFinal));
    criterio->setCartasParaMover(cartasFinal);
    numeroCartas = cartasFinal;
    this->criterio = criterio;
  }
}

void MoverAleatorioController::visita(CriterioFundacionTableau *criterio)
{
  mazoDestino = 0;
  mazoOrigen = 0;
  bool found = true;
  for (int i = 0; i < partida->getNumFundaciones() && not found; i++) {
    for (int j = 0; j < partida->getNumTableaus() && not found; j++) {
      mazoOrigen = i;
      mazoDestino = j;
      criterio->setMazoOrigen(partida->getFundacion(mazoOrigen));
      criterio->setMazoDestino(partida->getTableau(mazoDestino));
      
      if (criterio->getValoracion() > puntuacionMovimiento && criterio->checkMovimiento()) {
	puntuacionMovimiento = criterio->getValoracion();
      	this->criterio = criterio;
	found = true;
      }
    }
  }
}
