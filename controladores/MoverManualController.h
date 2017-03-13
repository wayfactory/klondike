#ifndef MOVERMANUALCONTROLLER_H
#define MOVERMANUALCONTROLLER_H

#include <MoverController.h>
#include <CriterioDescarteStock.h>
#include <CriterioStockDescarte.h>
#include <CriterioDescarteFundacion.h>
#include <CriterioDescarteTableau.h>
#include <CriterioTableauFundacion.h>
#include <CriterioTableauTableau.h>
#include <CriterioFundacionTableau.h>

class MoverManualController : public MoverController
{
public:
  MoverManualController();
  MoverManualController(const std::shared_ptr<PartidaKlondike>& partida);
  ~MoverManualController();

  bool mover();

  void acepta(OperacionControllerVisitor *operacionControllerVisitor);
  void visita(CriterioDescarteStock *criterio);
  void visita(CriterioStockDescarte *criterio);
  void visita(CriterioDescarteFundacion *criterio);
  void visita(CriterioDescarteTableau *criterio);
  void visita(CriterioTableauFundacion *criterio);
  void visita(CriterioTableauTableau *criterio);
  void visita(CriterioFundacionTableau *criterio);
};

#endif // MoverManualController_H
