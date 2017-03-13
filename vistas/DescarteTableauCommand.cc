#include <DescarteTableauCommand.h>

DescarteTableauCommand::DescarteTableauCommand() : MenuCommand("Mover de descarte a tableau")
{
  criterio = new CriterioDescarteTableau();
}

void DescarteTableauCommand::execute(const KlondikeVista& vista)
{
  receiver->setMazoDestino(vista.preguntaMazo("Tableau", NUMERO_TABLEAUS));
  receiver->setCriterio(criterio);
  receiver->mover();
}

DescarteTableauCommand::~DescarteTableauCommand()
{
  delete criterio;
}
