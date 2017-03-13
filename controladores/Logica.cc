#include "Logica.h"

Logica::Logica()
{
  std::shared_ptr<PartidaKlondike> p (new PartidaKlondike());
  this->partida = p;
  inicioController = new InicioController(partida);
  moverManualController = new MoverManualController(partida);
  moverAleatorioController = new MoverAleatorioController(partida);
}

Logica::~Logica()
{
}

OperacionController* Logica::getController()
{
  OperacionController *returnController = nullptr;
  
  switch(partida->getEstado()) {
  case PartidaKlondike::Estado::INICIAL:
    returnController = inicioController;
    break;
  case PartidaKlondike::Estado::EN_CURSO:
    returnController = moverManualController;
    break;
  case PartidaKlondike::Estado::EN_CURSO_AUTOMATICO:
    returnController = moverAleatorioController;
    break;
  case PartidaKlondike::Estado::SALIR:
    break;
  }

  return returnController;
}
