#ifndef TABLEAU_H
#define TABLEAU_H

#include "Mazo.h"

class Tableau : public Mazo
{
 public:
  Tableau();
  Tableau(const int ind);
  ~Tableau();
  void acepta(const MazoVisitor* mazoVisitor) const;
  const inline int getIndice() const { return indice; };

 protected:
 private:
  int indice;
};

#endif
