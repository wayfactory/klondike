#ifndef ENMARCADO_H
#define ENMARCADO_H

#include "../modelos/Coordenada.h"
#include "VistaTablero.h"
#include <iostream>

class Coordenada;

class Enmarcado
{
    VistaTablero *tablero;
public:
    Enmarcado(VistaTablero *vistaTablero);
    ~Enmarcado();

    void pintaRayaHorizontal(Coordenada *inicio, const int longitud, const char caracter);
    void pintaRayaVertical(Coordenada *inicio, const int longitud, const char caracter);
};

#endif // ENMARCADO_H
