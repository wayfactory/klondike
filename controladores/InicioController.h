#ifndef InicioController_H
#define InicioController_H

#include <OperacionController.h>
#include <KlondikeBuilder.h>

class InicioController : public OperacionController
{
 public:
    InicioController();
    InicioController(const std::shared_ptr<PartidaKlondike>& partida);
    ~InicioController();

    void acepta(OperacionControllerVisitor *operacionControllerVisitor);
    void generarPartida(int tipoBaraja, int pilotoAutomatico);
 protected:
 private:
    int tipoBaraja;
};

#endif // InicioController_H
