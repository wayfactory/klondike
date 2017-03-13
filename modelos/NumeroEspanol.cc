#include "NumeroEspanol.h"
#include <iostream>

NumeroEspanol::NumeroEspanol()
{

}

NumeroEspanol::~NumeroEspanol()
{

}

int NumeroEspanol::getNextNumero()
{
  if(numeros[numero-1] == NUM_CARTAS_ESPANOL)
  {
    return NUM_CARTAS_ESPANOL;
  }

  return numeros[numero];
}

int NumeroEspanol::getPrevNumero()
{
  if(numeros[numero-1] == 1)
  {
    return 0;
  }

  return numeros[numero - 2];
}
