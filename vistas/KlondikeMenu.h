#ifndef KLONDIKEMENU_H
#define KLONDIKEMENU_H

const int N_OPTIONS = 12;

#include <DescarteStockCommand.h>
#include <StockDescarteCommand.h>
#include <DescarteFundacionCommand.h>
#include <DescarteTableauCommand.h>
#include <TableauFundacionCommand.h>
#include <TableauTableauCommand.h>
#include <FundacionTableauCommand.h>
#include <SalvarCommand.h>
#include <CargarCommand.h>
#include <DeshacerCommand.h>
#include <RehacerCommand.h>
#include <TerminarCommand.h>
#include <KlondikeVista.h>
#include <list>
#include <string>
#include <sstream>

class KlondikeMenu
{
 public:
  KlondikeMenu();
  std::list<std::string> getOptions() const;
  
  int generateRandomSelection(MoverController* controller);
  void execute(MoverManualController* receiver, const KlondikeVista& vista);
  void execute(MoverAleatorioController* receiver, const KlondikeVista& vista);
  ~KlondikeMenu();

 private:
  MenuCommand *comandos[N_OPTIONS];
};

#endif
