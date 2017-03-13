#ifndef CRITERIODESCARTESTOCK_H
#define CRITERIODESCARTESTOCK_H

#include <CriterioMovimiento.h>

class CriterioDescarteStock : public CriterioMovimiento
{
 public:
  CriterioDescarteStock();
  CriterioDescarteStock(const CriterioDescarteStock& criterio);
  ~CriterioDescarteStock();

  bool checkMovimiento() const;
  void doMovimiento() const;
  void undoMovimiento() const;

  void acepta(CriterioMovimientoVisitor *visitor);
  CriterioMovimiento* clone();

 protected:
 private:
};

#endif
