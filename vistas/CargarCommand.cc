#include <CargarCommand.h>

CargarCommand::CargarCommand() : MenuCommand("Cargar partida")
{
}

void CargarCommand::execute(const KlondikeVista& vista)
{
  std::string nombrePartida = vista.preguntaNombreFichero();

  while (not vista.compruebaFichero(nombrePartida)) {
    std::cout << "Fichero de partida no encontrado. Introduzca un nombre de partida existente" << std::endl;
    nombrePartida = vista.preguntaNombreFichero();
  }

  VistaCargarPartida cargar(nombrePartida);
  cargar.cargar(receiver->getPartida());
}

CargarCommand::~CargarCommand()
{
}
