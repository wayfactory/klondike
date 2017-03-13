#include <BarajaEspanolaBuilder.h>
#include <NumeroEspanol.h>

BarajaEspanolaBuilder::BarajaEspanolaBuilder()
{
}

BarajaEspanolaBuilder::~BarajaEspanolaBuilder()
{
}

void BarajaEspanolaBuilder::construirPalos()
{
  for (int i = PaloEspanol::Palos::OROS; i != PaloEspanol::Palos::LAST; i++) {
    std::shared_ptr<Palo> palo (new PaloEspanol(i));
    anadePalo(palo);
  }
}

void BarajaEspanolaBuilder::construirNumeros()
{
  for (int i = 0; i < NUM_CARTAS_ESPANOL; i++) {
    std::shared_ptr<Numero> numero(nullptr);
    numero = std::make_shared<NumeroEspanol>();
    numero->setNumero(i);
    anadeNumero(numero);
  }
}
