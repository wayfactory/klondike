#ifndef KLONDIKEBUILDER_H
#define KLONDIKEBUILDER_H

#include <Fundacion.h>
#include <Stock.h>
#include <Descarte.h>
#include <Tableau.h>
#include <BarajaEspanolaBuilder.h>
#include <BarajaFrancesaBuilder.h>
#include <PartidaKlondike.h>
#include <fstream>
#include <iostream>

const int NUMERO_BARAJAS=2;
typedef std::shared_ptr<Mazo> MazoSharedPtr;

class KlondikeBuilder
{
 public:
  KlondikeBuilder();
  ~KlondikeBuilder();

  virtual void construyePartida(int tipoBaraja, std::shared_ptr<PartidaKlondike>& partida);
  void construyeFundaciones(Baraja& baraja, std::shared_ptr<PartidaKlondike>& partida);
  void construyeTableaus(Baraja& baraja, std::shared_ptr<PartidaKlondike>& partida);
  int leePuntuacionMinima(std::shared_ptr<PartidaKlondike>& partida);
 protected:
 private:
  BarajaBuilder *barajaBuilders[NUMERO_BARAJAS];
  virtual MazoSharedPtr construyeTableau(Baraja& baraja, const int cartasNoVisibles);
  virtual MazoSharedPtr construyeStock(Baraja& baraja);
};

#endif
