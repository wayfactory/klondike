#ifndef BARAJA_H
#define BARAJA_H

#include "Carta.h"
#include <vector>
#include <algorithm>
#include <ctime>

class Baraja
{
public:
    Baraja();
    virtual ~Baraja();

    void ponerCarta(const Carta& carta);
    Carta& robarCarta();
    void barajar();
    const bool estaVacia() const;

 protected:

 private:
    std::vector<Carta> baraja;
};

#endif // BARAJA_H
