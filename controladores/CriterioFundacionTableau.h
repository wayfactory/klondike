#ifndef CRITERIOFUNDACIONTABLEAU_H
#define CRITERIOFUNDACIONTABLEAU_H

#include <CriterioMovimiento.h>
#include <stack>

class CriterioFundacionTableau : public CriterioMovimiento
{
 public:
  CriterioFundacionTableau();
  ~CriterioFundacionTableau();
  CriterioFundacionTableau(const CriterioFundacionTableau& criterio);

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
