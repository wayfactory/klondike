#include "Resolucion.h"
#include <iostream>

Resolucion::Resolucion()
{
    pedirTamano();
}

Resolucion::~Resolucion()
{
}


void Resolucion::pedirTamano()
{
    do
    {
      std::cout << "Introduzca el tamano de tablero deseado:\n\n" ;
    } while (getTamano());
}

int Resolucion::getTamano()
{
    char c;

    std::cout << "\ta) " << coordXAlta << "x" << coordYAlta << " caracteres\n";
    std::cout << "\tb) " << coordXBaja << "x" << coordYBaja << " caracteres\n\n";

    // Forzamos al juego a usar el tablero de alta resolucion
    c = 'a';

    if (c == 'a' || c == 'A')
    {
       setAltaResolucion();
       return 0;
    }
    else if (c == 'b' || c == 'B')
    {
       setAltaResolucion();
       return 0;
    }
    return 1;
}

void Resolucion::setAltaResolucion()
{
}

void Resolucion::setBajaResolucion()
{
}
