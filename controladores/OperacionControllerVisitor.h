#ifndef OPERACIONCONTROLLERVISITOR_H
#define OPERACIONCONTROLLERVISITOR_H

class InicioController;
class MoverManualController;
class MoverAleatorioController;

class OperacionControllerVisitor
{
 public:
  virtual void visita(InicioController *inicioController) = 0;
  virtual void visita(MoverManualController *moverController) = 0;
  virtual void visita(MoverAleatorioController *moverController) = 0;
};

#endif
