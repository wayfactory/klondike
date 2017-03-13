#include <KlondikeCargarBuilderEspanola.h>
#include <memory>

KlondikeCargarBuilderEspanola::KlondikeCargarBuilderEspanola()
{
   construyePalos();
   construyeNumeros();
}

void KlondikeCargarBuilderEspanola::construyePalos()
{
  for (int i = PaloEspanol::Palos::OROS; i != PaloEspanol::Palos::LAST; i++)
  {
    anadePalo(i);
  }
}

void KlondikeCargarBuilderEspanola::anadePalo(int numeroPalo)
{
  std::shared_ptr<Palo> palo (new PaloEspanol(numeroPalo));
  palos.push_back(palo);
}

void KlondikeCargarBuilderEspanola::construyeNumeros()
{
  for (int i = 0; i != NUM_CARTAS_ESPANOL; i++)
  {
    anadeNumero(i);
  }
}

void KlondikeCargarBuilderEspanola::anadeNumero(int num)
{
  std::shared_ptr<Numero> numero(nullptr);
  numero = std::make_shared<NumeroEspanol>();
  numero->setNumero(num);
  numeros.push_back(numero);
}
