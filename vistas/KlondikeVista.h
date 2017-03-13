#ifndef KLONDIKEVISTA_H
#define KLONDIKEVISTA_H

#include <OperacionControllerVisitor.h>
#include <OperacionController.h>
#include <InicioController.h>
#include <MoverController.h>
#include <MoverManualController.h>
#include <MoverAleatorioController.h>
#include <PartidaVista.h>
#include <VistaTableroGrande.h>
#include <iostream>

class KlondikeMenu;

enum NUMERO_CRITERIOS {
  DESCARTE_A_STOCK,
  STOCK_A_DESCARTE,
  DESCARTE_A_FUNDACION,
  DESCARTE_A_TABLEAU,
  TABLEAU_A_FUNDACION,
  TABLEAU_A_TABLEAU,
  FUNDACION_A_TABLEAU,
  NUMERO_CRITERIOS
};


const int PORCENTAJE_DESCARTE_A_STOCK = 4;
const int PORCENTAJE_TABLEAU_A_TABLEAU = 5;
const int NUM_MONTONES_STOCK = 1;
const int NUM_MONTONES_DESCARTES = 1;
const int LONGITUD_ENTRADA_CARACTERES = 5;
const int GUARDAR_PARTIDA  = 7;
const int CARGAR_PARTIDA   = 8;
const int DESHACER_MOVIMIENTO = 9;
const int REHACER_MOVIMIENTO = 10;
const int TERMINAR_PARTIDA = 11;

class KlondikeVista : public OperacionControllerVisitor
{
 public:
  KlondikeVista();
  ~KlondikeVista();

  void interactua(OperacionController *operacionController);

  void visita(InicioController *inicioController);
  void visita(MoverManualController *moverController);
  void visita(MoverAleatorioController *moverController);

  int preguntaBaraja();
  void preguntaResolucion();
  int preguntaManualAutomatico();
  int preguntaMazo(const std::string& mazo, int numMazos) const;
  int preguntaCartas() const;
  bool compruebaFichero(std::string nombrePartida) const;
  std::string preguntaNombreFichero() const;
  std::string preguntarNombrePuntuacion() const;

  void setVistaTablero(VistaTablero *vTablero) { vistaTablero = vTablero; };
  const VistaTablero* getVistaTablero() const { return vistaTablero; };

 protected:
 private:
  VistaTablero *vistaTablero;
  KlondikeMenu* menu;
};

#endif
