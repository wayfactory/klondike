#ifndef MOVERCONTROLLER_H
#define MOVERCONTROLLER_H

#include <OperacionController.h>
#include <CriterioMovimientoVisitor.h>
#include <CriterioMovimiento.h>
#include <HistoricoMovimiento.h>

#include <assert.h>

class MoverController : public OperacionController, public CriterioMovimientoVisitor
{
 public:
  MoverController();
  MoverController(const std::shared_ptr<PartidaKlondike>& partida);
  ~MoverController();

  void setMovimiento(int movimiento);
  int getMovimiento();
  void setCriterio(CriterioMovimiento *criterio);
  void setMazoOrigen(int mazoOrigen);
  void setMazoDestino(int mazoDestino);
  void setCartasParaMover(int numeroCartas);

  virtual bool mover() = 0;
  void undo();
  void redo();

  void terminarPartida();

  virtual void visita(CriterioDescarteStock *criterio) = 0;
  virtual void visita(CriterioStockDescarte *criterio) = 0;
  virtual void visita(CriterioDescarteFundacion *criterio) = 0;
  virtual void visita(CriterioDescarteTableau *criterio) = 0;
  virtual void visita(CriterioTableauFundacion *criterio) = 0;
  virtual void visita(CriterioTableauTableau *criterio) = 0;
  virtual void visita(CriterioFundacionTableau *criterio) = 0;

 protected:
  CriterioMovimiento *criterio;
  int movimiento;
  int mazoOrigen;
  int mazoDestino;
  int numeroCartas;
  HistoricoMovimiento movimientos;
};

#endif
