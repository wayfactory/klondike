#ifndef FUNDACION_H
#define FUNDACION_H

#include "Mazo.h"

class Fundacion : public Mazo
{    
 public:
  Fundacion();
  Fundacion(int ind);
  ~Fundacion();
  void acepta(const MazoVisitor* mazoVisitor) const;
  inline int getIndice() const { return indice; };

 protected:
 private:
  int indice;
};

#endif
