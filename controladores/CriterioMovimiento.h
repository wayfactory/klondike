#ifndef CRITERIOMOVIMIENTO_H
#define CRITERIOMOVIMIENTO_H

#include <Mazo.h>
#include <CriterioMovimientoVisitor.h>

const int PUNTUACION_DESCARTE_FUNDACION = 10;
const int PUNTUACION_DESCARTE_STOCK = -100;
const int PUNTUACION_DESCARTE_TABLEAU = 5;
const int PUNTUACION_FUNDACION_TABLEAU = -15;
const int PUNTUACION_STOCK_DESCARTE = 0;
const int PUNTUACION_TABLEAU_FUNDACION = 10;
const int PUNTUACION_TABLEAU_TABLEAU = 0;

const int NUMERO_CARTAS_MOV_DESCARTE_FUNDACION = 1;
const int NUMERO_CARTAS_MOV_DESCARTE_TABLEAU = 1;
const int NUMERO_CARTAS_MOV_FUNDACION_TABLEAU = 1;
const int NUMERO_CARTAS_MOV_STOCK_DESCARTE = 3;
const int NUMERO_CARTAS_MOV_TABLEAU_FUNDACION = 1;
const int NUMERO_CARTAS_MOV_TABLEAU_TABLEAU = 1;

const int VALORACION_DESCARTE_STOCK = 2;
const int VALORACION_STOCK_DESCARTE = 3;
const int VALORACION_DESCARTE_FUNDACION = 12;
const int VALORACION_DESCARTE_TABLEAU = 4;
const int VALORACION_TABLEAU_FUNDACION = 10;
const int VALORACION_TABLEAU_TABLEAU = 8;
const int VALORACION_FUNDACION_TABLEAU = 1;

class CriterioMovimiento
{
 public:
  CriterioMovimiento();
  CriterioMovimiento(const CriterioMovimiento& criterio);
  virtual ~CriterioMovimiento();

  virtual bool checkMovimiento() const = 0;
  virtual void doMovimiento() const = 0;
  virtual void undoMovimiento() const = 0;

  void setMazoOrigen(MazoPointer mazoOrigen);
  void setMazoDestino(MazoPointer mazoDestino);
  void setCartasParaMover(int numeroCartas);
  int getPuntuacion() { return puntuacion; };
  int getValoracion() { return valoracion; };

  virtual void acepta(CriterioMovimientoVisitor *visitor) = 0;
  virtual CriterioMovimiento* clone() = 0;

 protected:
  int numeroCartas;
  int puntuacion;
  int valoracion;
  MazoPointer mazoOrigen;
  MazoPointer mazoDestino;
 private:
};

#endif
