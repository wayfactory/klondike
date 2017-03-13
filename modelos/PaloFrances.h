#include "Palo.h"

const int TIPO_PALO_FRANCES = 2;

class PaloFrances : public Palo
{
 public:
  enum Palos {
    ROMBOS,
    CORAZONES,
    TREBOLES,
    PICAS,
    LAST
  };
  PaloFrances();
  PaloFrances(const int palo);
  ~PaloFrances();
  const std::string getTextoPalo() const;
  const bool mismoColor(const std::shared_ptr<Palo>& palo) const;

 protected:
 private:
  const char *numeroATexto[Palos::LAST] = { " ROMBOS\0", "CORAZONES\0", "TREBOLES\0", "  PICAS\0"};
};
