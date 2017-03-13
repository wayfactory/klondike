#include <BarajaFrancesaBuilder.h>
#include <NumeroEspanol.h>

BarajaFrancesaBuilder::BarajaFrancesaBuilder()
{
}

BarajaFrancesaBuilder::~BarajaFrancesaBuilder()
{
}

void BarajaFrancesaBuilder::construirPalos()
{
  for (int i = PaloFrances::Palos::ROMBOS; i != PaloFrances::Palos::LAST; i++) {
    std::cout << "construyendo palo" << std::endl;
    std::shared_ptr<Palo> palo (new PaloFrances(i));
    anadePalo(palo);
  }
}

void BarajaFrancesaBuilder::construirNumeros()
{
  for (int i = 0; i < NUM_CARTAS_FRANCES; i++) {
    std::cout << "construyendo numero" << std::endl;
    std::shared_ptr<Numero> numero(nullptr);
    numero = std::make_shared<NumeroFrances>();
    numero->setNumero(i);
    anadeNumero(numero);
  }
}
