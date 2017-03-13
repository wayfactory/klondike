#include "Coordenada.h"

Coordenada::Coordenada()
{

}

Coordenada::Coordenada(int coordX, int coordY)
{
    coordenadaX = coordX;
    coordenadaY = coordY;
}

Coordenada::~Coordenada()
{

}

void Coordenada::setCoord(int coordX, int coordY)
{
    coordenadaX = coordX;
    coordenadaY = coordY;
}
