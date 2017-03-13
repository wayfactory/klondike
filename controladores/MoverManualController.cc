#include <MoverManualController.h>

MoverManualController::MoverManualController()
{
}

MoverManualController::MoverManualController(const std::shared_ptr<PartidaKlondike>& partida) : MoverController(partida)
{
}

MoverManualController::~MoverManualController()
{
}

bool MoverManualController::mover()
{
  bool success = false;
  if (criterio->checkMovimiento())
  {
    criterio->doMovimiento();
    success = true;
    movimientos.insertMovimiento(criterio);
    getPartida()->incMarcador(criterio->getPuntuacion());

    if (getPartida()->comprobarVictoria()) {
      terminarPartida();
    }
  }

  return success;
}

void MoverManualController::acepta(OperacionControllerVisitor *operacionControllerVisitor)
{
  operacionControllerVisitor->visita(this);
}

void MoverManualController::visita(CriterioDescarteStock *criterio)
{
  criterio->setMazoOrigen(partida->getDescartes());
  criterio->setMazoDestino(partida->getStock());
}

void MoverManualController::visita(CriterioStockDescarte *criterio)
{
  criterio->setMazoOrigen(partida->getStock());
  criterio->setMazoDestino(partida->getDescartes());
}

void MoverManualController::visita(CriterioDescarteFundacion *criterio)
{
  criterio->setMazoOrigen(partida->getDescartes());
  criterio->setMazoDestino(partida->getFundacion(mazoDestino));
}

void MoverManualController::visita(CriterioDescarteTableau *criterio)
{
  criterio->setMazoOrigen(partida->getDescartes());
  criterio->setMazoDestino(partida->getTableau(mazoDestino));
}

void MoverManualController::visita(CriterioTableauFundacion *criterio)
{
  criterio->setMazoOrigen(partida->getTableau(mazoOrigen));
  criterio->setMazoDestino(partida->getFundacion(mazoDestino));
}

void MoverManualController::visita(CriterioTableauTableau *criterio)
{
  criterio->setCartasParaMover(numeroCartas);
  criterio->setMazoOrigen(partida->getTableau(mazoOrigen));
  criterio->setMazoDestino(partida->getTableau(mazoDestino));
}

void MoverManualController::visita(CriterioFundacionTableau *criterio)
{
  criterio->setMazoOrigen(partida->getFundacion(mazoOrigen));
  criterio->setMazoDestino(partida->getTableau(mazoDestino));
}
