#ifndef PALOESPANOL_H
#define PALOESPANOL_H

#include "Palo.h"

const int TIPO_PALO_ESPANOL = 1;

class PaloEspanol : public Palo
{

 public:
  enum Palos {
    OROS = 0,
    COPAS,
    ESPADAS,
    BASTOS,
    LAST
  };  

  PaloEspanol(const int palo);
  ~PaloEspanol();

  const std::string getTextoPalo() const;
  const bool mismoColor(const std::shared_ptr<Palo>& palo) const;
 protected:
 private:
  const char *numeroATexto[Palos::LAST] = { "  OROS\0", "  COPAS\0", " ESPADAS\0", " BASTOS\0"};
};

#endif
