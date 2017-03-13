#ifndef NUMEROFRANCES_H
#define NUMEROFRANCES_H

#include "Numero.h"

const int NUM_CARTAS_FRANCES = 13;

class NumeroFrances : public Numero
{
  const char *numeroATexto[NUM_CARTAS_FRANCES+1] = { "   AS", "   DOS", "  TRES", " CUATRO",
                                                     "  CINCO", "  SEIS", "  SIETE", "  OCHO",
                                                     "  NUEVE", "  DIEZ", "  JACK", "  REINA",
                                                     "  REY" };
public:
    NumeroFrances();    
    ~NumeroFrances();
    int getNextNumero();
    int getPrevNumero();
    const char *getTextoNumero() { return numeroATexto[numero]; };
};

#endif // NUMEROFRANCES_H
