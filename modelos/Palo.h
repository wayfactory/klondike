#ifndef PALO_H
#define PALO_H

#include <cstdint>
#include <memory>
#include <iostream>

class Palo
{

 public:
  Palo();
  Palo(int palo, int tipoPalo);
  Palo(const Palo* palo);

  virtual ~Palo();

  const Palo* operator=(const Palo* palo);
  const bool operator==(const Palo* palo);
  const int getPalo() const;
  const int getTipo() const;
  virtual const std::string getTextoPalo() const = 0;
  virtual const bool mismoColor(const std::shared_ptr<Palo>& palo) const = 0;

 protected:
  int palo;
  int tipo;
};

#endif
