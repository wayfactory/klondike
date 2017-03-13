#ifndef OperacionController_H
#define OperacionController_H

#include <OperacionControllerVisitor.h>
#include <PartidaKlondike.h>

class OperacionController
{
public:
  OperacionController();
  OperacionController(const std::shared_ptr<PartidaKlondike>& partida);
  ~OperacionController();

  const std::shared_ptr<PartidaKlondike>& getPartida() const;

  virtual void acepta(OperacionControllerVisitor* operacionControllerVisitor) = 0;
 protected:
  std::shared_ptr<PartidaKlondike> partida;
 private:
};

#endif // OperacionController_H
