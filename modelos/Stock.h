#ifndef STOCK_H
#define STOCK_H

#include <Mazo.h>

class Stock : public Mazo
{
 public:

  Stock();
  ~Stock();
  void acepta(const MazoVisitor* mazoVisitor) const;
  
 protected:
 private:
};

#endif
