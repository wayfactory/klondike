#ifndef BARAJAESPANOLABUILDER_H
#define BARAJAESPANOLABUILDER_H

#include <BarajaBuilder.h>
#include <PaloEspanol.h>
#include <NumeroEspanol.h>

class BarajaEspanolaBuilder : public BarajaBuilder
{
 public: 
  BarajaEspanolaBuilder();
  ~BarajaEspanolaBuilder();

  void construirBaraja();
 protected:

 private:
  void construirPalos();
  void construirNumeros();
};

#endif

