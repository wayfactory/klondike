#ifndef SALVARCOMMAND_H
#define SALVARCOMMAND_H

#include <MenuCommand.h>
#include <VistaSalvarPartida.h>

class SalvarCommand : public MenuCommand
{
 public:
   SalvarCommand();
   void execute(const KlondikeVista& vista);
   ~SalvarCommand();
};

#endif
