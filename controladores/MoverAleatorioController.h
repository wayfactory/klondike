#ifndef MoverAleatorioController_H
#define MoverAleatorioController_H

#include <MoverController.h>
#include <CriterioDescarteStock.h>
#include <CriterioStockDescarte.h>
#include <CriterioDescarteFundacion.h>
#include <CriterioDescarteTableau.h>
#include <CriterioTableauFundacion.h>
#include <CriterioTableauTableau.h>
#include <KlondikeVista.h>

const int NUMERO_CARTAS_MAXIMO_A_MOVER = 9;

class MoverAleatorioController : public MoverController
{
 public:
    MoverAleatorioController();
    MoverAleatorioController(const std::shared_ptr<PartidaKlondike>& partida);
    ~MoverAleatorioController();

    bool mover();
    void acepta(OperacionControllerVisitor *operacionControllerVisitor);    
    void visita(CriterioDescarteStock *criterio);
    void visita(CriterioStockDescarte *criterio);
    void visita(CriterioDescarteFundacion *criterio);
    void visita(CriterioDescarteTableau *criterio);
    void visita(CriterioTableauFundacion *criterio);
    void visita(CriterioTableauTableau *criterio);
    void visita(CriterioFundacionTableau *criterio);
    
 private:
    int puntuacionMovimiento;
    int origenPrevio;
    int tableauToTableauAvg;
    int testTableauToTableau(CriterioTableauTableau *criterio, MazoPointer origen, MazoPointer destino);
};

#endif // MoverAleatorioController_H
