#ifndef CRITERIODESCARTEFUNDACION_H
#define CRITERIODESCARTEFUNDACION_H

#include <CriterioMovimiento.h>

class CriterioDescarteFundacion : public CriterioMovimiento
{
 public:
  CriterioDescarteFundacion();
  CriterioDescarteFundacion(const CriterioDescarteFundacion& criterio);
  ~CriterioDescarteFundacion();

  bool checkMovimiento() const;
  void doMovimiento() const;
  void undoMovimiento() const;

  void acepta(CriterioMovimientoVisitor *visitor);
  CriterioMovimiento* clone();

 protected:
 private:
  bool checkPalos(const Carta *origen, const Carta *destino) const;
  bool checkNumeros(const Carta *origen, const Carta *destino) const;
};

#endif
