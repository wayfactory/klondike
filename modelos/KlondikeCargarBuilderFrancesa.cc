#include <KlondikeCargarBuilderFrancesa.h>

KlondikeCargarBuilderFrancesa::KlondikeCargarBuilderFrancesa()
{
  construyePalos();
  construyeNumeros();
}

void KlondikeCargarBuilderFrancesa::construyePalos()
{
  for (int i = PaloFrances::Palos::ROMBOS; i != PaloFrances::Palos::LAST; i++)
  {
    anadePalo(i);
  }
}

void KlondikeCargarBuilderFrancesa::anadePalo(int numeroPalo)
{
  std::shared_ptr<Palo> palo (new PaloFrances(numeroPalo));
  palos.push_back(palo);
}

void KlondikeCargarBuilderFrancesa::construyeNumeros()
{
  for (int i = 0; i != NUM_CARTAS_FRANCES; i++)
  {
    anadeNumero(i);
  }
}

void KlondikeCargarBuilderFrancesa::anadeNumero(int num)
{
  std::shared_ptr<Numero> numero(nullptr);
  numero = std::make_shared<NumeroFrances>();
  numero->setNumero(num);
  numeros.push_back(numero);
}
