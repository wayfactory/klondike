#include "Fundacion.h"

Fundacion::Fundacion() : indice (0)
{
}

Fundacion::Fundacion(int ind) : indice (ind)
{
}

Fundacion::~Fundacion()
{
}

void Fundacion::acepta(const MazoVisitor* mazoVisitor) const
{
  mazoVisitor->visita(this);
}
