#ifndef REHACERCOMMAND_H
#define REHACERCOMMAND_H

#include <MenuCommand.h>

class RehacerCommand : public MenuCommand
{
 public:
   RehacerCommand();
   void execute(const KlondikeVista& vista);
   ~RehacerCommand();
};

#endif
