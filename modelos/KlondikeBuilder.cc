#include <KlondikeBuilder.h>

const int NUMERO_TABLEAUS = 7;
const int NUMERO_FUNDACIONES = 4;

KlondikeBuilder::KlondikeBuilder()
{
  barajaBuilders[0] = new BarajaEspanolaBuilder();
  barajaBuilders[1] = new BarajaFrancesaBuilder();
}

KlondikeBuilder::~KlondikeBuilder()
{
  delete barajaBuilders[0];
  delete barajaBuilders[1];
}

void KlondikeBuilder::construyePartida(int tipoBaraja, std::shared_ptr<PartidaKlondike>& partida)
{

  BarajaBuilder *barajaBuilder = barajaBuilders[tipoBaraja];
  Baraja baraja =barajaBuilder->construirBaraja();
  baraja.barajar();

  partida->setMinimo(leePuntuacionMinima(partida));
  partida->setTipoPartida(tipoBaraja);

  construyeTableaus(baraja, partida);

  partida->addStock(construyeStock(baraja));

  MazoPointer descarte (new Descarte());
  partida->addDescartes(descarte);

  construyeFundaciones(baraja, partida);
}

int KlondikeBuilder::leePuntuacionMinima(std::shared_ptr<PartidaKlondike>& partida)
{
  std::string linea;
  std::ifstream ficheroPuntuaciones(".ranking");
  int puntuacionMinima = 0;

  for (int i = 0; i<MAX_RANKING; i++)
  {
    std::getline(ficheroPuntuaciones, linea, '$');
    partida->setNombreRanking(i, linea);
    std::getline(ficheroPuntuaciones, linea, '\n');
    puntuacionMinima = atoi(linea.c_str());
    partida->setPuntuacionRanking(i, puntuacionMinima);
  }

  return puntuacionMinima;
}

void KlondikeBuilder::construyeTableaus(Baraja& baraja, std::shared_ptr<PartidaKlondike>& partida)
{
  for(int i = 0; i < NUMERO_TABLEAUS; i++) 
  {
    partida->addTableau(construyeTableau((baraja), i));
  }
}

void KlondikeBuilder::construyeFundaciones(Baraja& baraja, std::shared_ptr<PartidaKlondike>& partida)
{
  for (int i = 0; i < NUMERO_FUNDACIONES; i++) 
  {
    MazoPointer fundacion (new Fundacion(i));
    partida->addFundacion(fundacion);
  }
}

MazoSharedPtr KlondikeBuilder::construyeTableau(Baraja& baraja, const int cartasNoVisibles)
{
  MazoSharedPtr tableau(new Tableau(cartasNoVisibles));

  for(int i = 0; i < cartasNoVisibles; i++)
  {
    (*tableau).ponerCarta(baraja.robarCarta());
  }

  Carta carta = baraja.robarCarta();
  carta.setVisibilidad(true);
  (*tableau).ponerCarta(carta);

  return tableau;
}

MazoSharedPtr KlondikeBuilder::construyeStock(Baraja& baraja)
{
  MazoSharedPtr stock(new Stock());
  while(not baraja.estaVacia())
  {
    (*stock).ponerCarta(baraja.robarCarta());
  }

  return stock;
}
