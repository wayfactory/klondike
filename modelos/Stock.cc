#include "Stock.h"

Stock::Stock()
{
}

Stock::~Stock()
{
}

void Stock::acepta(const MazoVisitor* mazoVisitor) const
{
  mazoVisitor->visita(this);
}
