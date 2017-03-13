#ifndef DESCARTESTOCKCOMMAND_H
#define DESCARTESTOCKCOMMAND_H

#include <MenuCommand.h>
#include <CriterioDescarteStock.h>

class DescarteStockCommand : public MenuCommand
{
 public:
   DescarteStockCommand();
   void execute(const KlondikeVista& vista);
   ~DescarteStockCommand();
};

#endif
