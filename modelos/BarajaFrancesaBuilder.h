#ifndef BARAJAFRANCESABUILDER_H
#define BARAJAFRANCESABUILDER_H

#include <BarajaBuilder.h>
#include <PaloFrances.h>
#include <NumeroFrances.h>

class BarajaFrancesaBuilder : public BarajaBuilder
{
 public: 
  BarajaFrancesaBuilder();
  ~BarajaFrancesaBuilder();

  void construirBaraja();
 protected: 

 private:
  void construirPalos();
  void construirNumeros();
};

#endif
