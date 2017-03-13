#ifndef STOCKDESCARTECOMMAND_H
#define STOCKDESCARTECOMMAND_H

#include <MenuCommand.h>
#include <CriterioStockDescarte.h>

class StockDescarteCommand : public MenuCommand
{
 public:
   StockDescarteCommand();
   void execute(const KlondikeVista& vista);
   ~StockDescarteCommand();
};

#endif
