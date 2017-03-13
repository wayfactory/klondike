#ifndef DESCARTEFUNDACIONCOMMAND_H
#define DESCARTEFUNDACIONCOMMAND_H

#include <MenuCommand.h>
#include <CriterioDescarteFundacion.h>

class DescarteFundacionCommand : public MenuCommand
{
 public:
   DescarteFundacionCommand();
   void execute(const KlondikeVista& vista);
   ~DescarteFundacionCommand();
};

#endif
