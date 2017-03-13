#ifndef CRITERIOTABLEAUTABLEAU_H
#define CRITERIOTABLEAUTABLEAU_H

#include <CriterioMovimiento.h>
#include <stack>

class CriterioTableauTableau : public CriterioMovimiento
{
 public:
  CriterioTableauTableau();
  CriterioTableauTableau(const CriterioTableauTableau& criterio);
  ~CriterioTableauTableau();

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
