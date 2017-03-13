#ifndef MAZO_H
#define MAZO_H

#include <Carta.h>
#include <MazoVisitor.h>
#include <vector>

typedef std::vector<Carta> CartaList;

class Mazo
{
 public:

  Mazo();
  ~Mazo();

  bool tieneCartas() const;
  int getNumeroCartas() const;
  int getNumeroCartasNoVisibles() const;
  int getNumeroCartasVisibles() const;
  
  const Carta* getUltimaCarta() const;
  const CartaList getCartas() const;

  void ponerCarta(Carta& carta);
  Carta& quitarCarta();

  virtual void acepta(const MazoVisitor *mazoVisitor) const = 0;
  
 protected:
  CartaList mazo;

 private:
};

typedef std::shared_ptr<Mazo> MazoPointer;

#endif
