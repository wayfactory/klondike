#include "Tableau.h"

Tableau::Tableau() : indice (0)
{
}

Tableau::Tableau(const int ind) : indice (ind)
{
}

Tableau::~Tableau()
{
}

void Tableau::acepta(const MazoVisitor* mazoVisitor) const
{
  mazoVisitor->visita(this);
}
