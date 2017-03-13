#include <OperacionController.h>

OperacionController::OperacionController()
{
}

OperacionController::OperacionController(const std::shared_ptr<PartidaKlondike>& partida)
{
  this->partida = partida;
}

const std::shared_ptr<PartidaKlondike>& OperacionController::getPartida() const
{
  return this->partida;
}

OperacionController::~OperacionController()
{
}
