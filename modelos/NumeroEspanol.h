#ifndef NUMEROESPANOL_H
#define NUMEROESPANOL_H

#include "Numero.h"

const int NUM_CARTAS_ESPANOL = 10;

class NumeroEspanol : public Numero
{
  const int numeros[NUM_CARTAS_ESPANOL] = {1,2,3,4,5,6,7,8,9,10};
  const char *numeroATexto[NUM_CARTAS_ESPANOL] = { "   AS", "  DOS", "  TRES", " CUATRO",
                                                   " CINCO", "  SEIS", "  SIETE",
                                                   "  SOTA", " CABALLO", "  REY"};

public:
    NumeroEspanol();
    ~NumeroEspanol();
    virtual int getNextNumero();
    virtual int getPrevNumero();
    const char* getTextoNumero() { return numeroATexto[numero]; };
    const int getNumero(int numero) { return numeros[numero]; };
};

#endif // NUMEROESPANOL_H
