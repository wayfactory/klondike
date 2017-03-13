#ifndef CRITERIOTABLEAUFUNDACION_H
#define CRITERIOTABLEAUFUNDACION_H

#include <CriterioMovimiento.h>

class CriterioTableauFundacion : public CriterioMovimiento
{
 public:
  CriterioTableauFundacion();
  CriterioTableauFundacion(const CriterioTableauFundacion& criterio);

  ~CriterioTableauFundacion();

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
