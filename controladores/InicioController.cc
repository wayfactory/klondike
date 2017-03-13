#include <InicioController.h>

InicioController::InicioController()
{

}

InicioController::InicioController(const std::shared_ptr<PartidaKlondike>& partida) : OperacionController(partida)
{
}

InicioController::~InicioController()
{

}

void InicioController::generarPartida(int tipoBaraja, int pilotoAutomatico)
{
  // TODO: Patron para generar el tipo de partida dependiendo de la baraja
  KlondikeBuilder partidaBuilder;
  partidaBuilder.construyePartida(tipoBaraja, partida);

  if (pilotoAutomatico)
  {
    partida->setEstado(PartidaKlondike::Estado::EN_CURSO_AUTOMATICO);
  }
  else
  {
    partida->setEstado(PartidaKlondike::Estado::EN_CURSO);
  }
}

void InicioController::acepta(OperacionControllerVisitor *operacionController)
{
    operacionController->visita(this);
}
