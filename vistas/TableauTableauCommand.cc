#include <TableauTableauCommand.h>

TableauTableauCommand::TableauTableauCommand() : MenuCommand("Mover de tableau a tableau")
{
  criterio = new CriterioTableauTableau();
}

void TableauTableauCommand::execute(const KlondikeVista& vista)
{
  receiver->setMazoOrigen(vista.preguntaMazo("Tableau origen", NUMERO_TABLEAUS));
  receiver->setMazoDestino(vista.preguntaMazo("Tableau destino", NUMERO_TABLEAUS));
  receiver->setCartasParaMover(vista.preguntaCartas());
  receiver->setCriterio(criterio);
  receiver->mover();
}

TableauTableauCommand::~TableauTableauCommand()
{
  delete criterio;
}
