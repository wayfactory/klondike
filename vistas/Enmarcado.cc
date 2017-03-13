#include "Enmarcado.h"
#include <assert.h>
#include <string.h>

Enmarcado::Enmarcado(VistaTablero *vistaTablero)
{
    tablero = vistaTablero;
}

Enmarcado::~Enmarcado()
{

}

void Enmarcado::pintaRayaVertical(Coordenada *inicio, int longitud,  const char caracter)
{
    assert((inicio->getCoordY() + longitud) < (DOBLE*tablero->getTamanoY()));

    char **tableroAPintar = tablero->getTableroAImprimir();

    for (int i = inicio->getCoordY(); i < (inicio->getCoordY()+longitud); i++)
    {
      memcpy(&(tableroAPintar[i][inicio->getCoordX()]), &caracter, sizeof(caracter));
    }
}

void Enmarcado::pintaRayaHorizontal(Coordenada *inicio, int longitud, const char caracter)
{
    assert((inicio->getCoordX() + longitud) < (DOBLE*tablero->getTamanoX()));

    char **tableroAPintar = tablero->getTableroAImprimir();

    for (int i = inicio->getCoordX(); i <= (inicio->getCoordX()+longitud); i++)
    {
      memcpy(&(tableroAPintar[inicio->getCoordY()][i]), &caracter, sizeof(caracter));
    }
}
