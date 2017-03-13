#ifndef PARTIDAVISTA_H
#define PARTIDAVISTA_H

#include <OperacionController.h>
#include <MazoVisitor.h>
#include <Tableau.h>
#include <Fundacion.h>
#include <Stock.h>
#include <Descarte.h>

class PartidaVista : public MazoVisitor
{
 public:
  PartidaVista();
  PartidaVista(OperacionController *controlador);
  ~PartidaVista();
  
  void pinta();

  void visita(const Stock *stock) const;
  void visita(const Fundacion *fundacion) const;
  void visita(const Tableau *tableau) const;
  void visita(const Descarte *descarte) const;

 protected:

 private:
  void printTableaus(std::shared_ptr<PartidaKlondike> partida);
  void printFundaciones(std::shared_ptr<PartidaKlondike> partida);

  OperacionController *controlador;  
};

#endif
