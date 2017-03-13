#include <MoverController.h>

MoverController::MoverController()
{
}

MoverController::MoverController(const std::shared_ptr<PartidaKlondike>& partida) : OperacionController(partida)
{
}

MoverController::~MoverController()
{
}

void MoverController::setCriterio(CriterioMovimiento *criterio)
{
  this->criterio = criterio;
  criterio->acepta(this);
}

void MoverController::undo()
{
  movimientos.undo();
}

void MoverController::redo()
{
  movimientos.redo();
}

void MoverController::terminarPartida()
{
  partida->setEstado(PartidaKlondike::Estado::SALIR);
}

void MoverController::setMovimiento(int movimiento)
{
  this->movimiento = movimiento;
}

int MoverController::getMovimiento()
{
  return movimiento;
}

void MoverController::setMazoOrigen(int mazoOrigen)
{
  this->mazoOrigen = mazoOrigen;
}

void MoverController::setMazoDestino(int mazoDestino)
{
  this->mazoDestino = mazoDestino;
}

void MoverController::setCartasParaMover(int numeroCartas)
{
  this->numeroCartas = numeroCartas;
}
