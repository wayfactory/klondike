#ifndef DESCARTE_H
#define DESCARTE_H

#include "Mazo.h"

class Descarte : public Mazo
{
 public:
  Descarte();
  ~Descarte();
  void acepta(const MazoVisitor* mazoVisitor) const;
  
 protected:
 private:
};

#endif
