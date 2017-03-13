#include "NumeroFrances.h"

NumeroFrances::NumeroFrances()
{

}

NumeroFrances::~NumeroFrances()
{

}

int NumeroFrances::getNextNumero()
{
  if (numero == 12)
  {
    return 12;
  }

  return numero+1;
}

int NumeroFrances::getPrevNumero()
{
  if (numero == 1) {
    return 1;
  }
  return numero - 1;
}
