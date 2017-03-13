#ifndef MAZOVISITOR_H
#define MAZOVISITOR_H

class Stock;
class Fundacion;
class Tableau;
class Descarte;

class MazoVisitor
{
 public:
  virtual void visita(const Stock *stock) const = 0;
  virtual void visita(const Fundacion *fundacion) const = 0;
  virtual void visita(const Tableau *tableau) const = 0;
  virtual void visita(const Descarte *descarte) const = 0;
};

#endif
