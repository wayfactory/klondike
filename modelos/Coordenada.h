#ifndef COORDENADA_H
#define COORDENADA_H

#include <cstdint>

class Coordenada
{
    int coordenadaX;
    int coordenadaY;

public:
    Coordenada();
    Coordenada(int coordX, int coordY);
    ~Coordenada();

    int getCoordX(void) { return coordenadaX; };
    int getCoordY(void) { return coordenadaY; };


    void setCoordX(int coordX) { coordenadaX = coordX; };
    void setCoordY(int coordY) { coordenadaY = coordY; };
    void setCoord(int coordX, int coordY);
};

#endif // COORDENADA_H
