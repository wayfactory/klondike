#ifndef CRITERIOSTOCKDESCARTE_H
#define CRITERIOSTOCKDESCARTE_H

#include <CriterioMovimiento.h>
#include <stack>

class CriterioStockDescarte : public CriterioMovimiento
{
 public:
  CriterioStockDescarte();
  CriterioStockDescarte(const CriterioStockDescarte& criterio);
  ~CriterioStockDescarte();

  bool checkMovimiento() const;
  void doMovimiento() const;
  void undoMovimiento() const;

  void acepta(CriterioMovimientoVisitor *visitor);
  CriterioMovimiento* clone();

 protected:
 private:
};

#endif
