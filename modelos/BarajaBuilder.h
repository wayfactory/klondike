#ifndef BARAJABUILDER_H
#define BARAJABUILDER_H

#include "Baraja.h"

class BarajaBuilder
{
 public:

  BarajaBuilder();
  virtual ~BarajaBuilder();

  Baraja& construirBaraja();
  Baraja& getBaraja();
  
 protected:
  void anadePalo(const std::shared_ptr<Palo>& palo);
  void anadeNumero(const std::shared_ptr<Numero>& numero);

  std::vector<std::shared_ptr<Palo>> palos;
  std::vector<std::shared_ptr<Numero>> numeros;

  Baraja baraja;

 private:
  virtual void construirPalos() = 0;
  virtual void construirNumeros() = 0;
  int getTotalCartas();
};

#endif
