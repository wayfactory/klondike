#ifndef LOGICA_H
#define LOGICA_H

#include <InicioController.h>
#include <MoverManualController.h>
#include <MoverAleatorioController.h>

class Logica
{
 public:
  Logica();
  ~Logica();
  OperacionController *getController();
 protected:

 private:
  std::shared_ptr<PartidaKlondike> partida;
  OperacionController *inicioController;
  OperacionController *moverManualController;
  OperacionController *moverAleatorioController;
};

#endif
