#include "Descarte.h"

Descarte::Descarte()
{
}

Descarte::~Descarte()
{
}

void Descarte::acepta(const MazoVisitor* mazoVisitor) const
{
  mazoVisitor->visita(this);
}
