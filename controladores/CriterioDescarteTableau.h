#ifndef CRITERIODESCARTETABLEAU_H
#define CRITERIODESCARTETABLEAU_H

#include <CriterioMovimiento.h>

class CriterioDescarteTableau : public CriterioMovimiento
{
 public:
  CriterioDescarteTableau();
  CriterioDescarteTableau(const CriterioDescarteTableau& criterio);
  ~CriterioDescarteTableau();

  bool checkMovimiento() const;
  void doMovimiento() const;
  void undoMovimiento() const;

  void acepta(CriterioMovimientoVisitor *visitor);
  CriterioMovimiento* clone();

 protected:
 private:
  bool checkColor(const Carta *origen, const Carta *destino) const;
  bool checkNumeros(const Carta *origen, const Carta *destino) const;
};

#endif
