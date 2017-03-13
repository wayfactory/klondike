#ifndef CRITERIOVISITOR_H
#define CRITERIOVISITOR_H

class CriterioDescarteStock;
class CriterioStockDescarte;
class CriterioDescarteFundacion;
class CriterioDescarteTableau;
class CriterioTableauFundacion;
class CriterioTableauTableau;
class CriterioFundacionTableau;

class CriterioMovimientoVisitor
{
 public:

  virtual void visita(CriterioDescarteStock *criterio) = 0;
  virtual void visita(CriterioStockDescarte *criterio) = 0;
  virtual void visita(CriterioDescarteFundacion *criterio) = 0;
  virtual void visita(CriterioDescarteTableau *criterio) = 0;
  virtual void visita(CriterioTableauFundacion *criterio) = 0;
  virtual void visita(CriterioTableauTableau *criterio) = 0;
  virtual void visita(CriterioFundacionTableau *criterio) = 0;

 protected:
 private:
};

#endif
