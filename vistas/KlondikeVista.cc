#include <KlondikeVista.h>
#include <KlondikeMenu.h>

KlondikeVista::KlondikeVista()
{
  menu = new KlondikeMenu();
}

KlondikeVista::~KlondikeVista()
{
  delete menu;
}

void KlondikeVista::interactua(OperacionController *operacionController)
{
  operacionController->acepta(this);
}

void KlondikeVista::visita(InicioController *inicioController)
{
  int tipoBaraja = preguntaBaraja();
  preguntaResolucion();  
  inicioController->generarPartida(tipoBaraja, preguntaManualAutomatico());
  PartidaVista partidaVista(inicioController);
  partidaVista.pinta();
}

void KlondikeVista::visita(MoverManualController *moverController)
{
  int tipoMovimiento = -1;
  do
  {
    vistaTablero->imprimeMenu(*menu);
    vistaTablero->imprimeRanking(moverController->getPartida());
    vistaTablero->imprimeTablero(moverController->getPartida());
    std::cout << "Introduzca opcion: ";
    std::cin >> tipoMovimiento;
  } while(tipoMovimiento < DESCARTE_A_STOCK || tipoMovimiento > TERMINAR_PARTIDA);
  moverController->setMovimiento(tipoMovimiento);
  menu->execute(moverController, *this);
}

void KlondikeVista::visita(MoverAleatorioController *moverController)
{
  vistaTablero->imprimeMenu(*menu);
  vistaTablero->imprimeRanking(moverController->getPartida());
  vistaTablero->imprimeTablero(moverController->getPartida());

  menu->execute(moverController, *this);
}

int KlondikeVista::preguntaBaraja()
{
  int tipoBaraja = 0;
  do
  {
    std::cout << "Introduzca tipo de baraja: " << std::endl;
    std::cout << "0) Baraja Española (default)" << std::endl;
    std::cout << "1) Baraja Francesa" << std::endl;
    std::cout << "Introduzca opcion: " << std::endl;
    std::cin >> tipoBaraja;
  }while(tipoBaraja >= 2);

  return tipoBaraja;
}

void KlondikeVista::preguntaResolucion()
{
  // Como vamos un poco pelaetes de tiempo solo vamos a implementar
  // una modalidad de tablero (tamano grande)
  vistaTablero = (VistaTablero *) new VistaTableroGrande();
  vistaTablero->setTamanoX(Resolucion::coordXAlta);
  vistaTablero->setTamanoY(Resolucion::coordYAlta);
  vistaTablero->reservarMemoriaTableroAImprimir();
}

int KlondikeVista::preguntaManualAutomatico()
{
  int modoJuego = 0;
  do
  {
    std::cout << "Introduzca si quiere activar el piloto automatico: " << std::endl;
    std::cout << "0) No (default)" << std::endl;
    std::cout << "1) Si" << std::endl;
    std::cout << "Introduzca opcion: " << std::endl;
    std::cin >> modoJuego;
  }while(modoJuego >= 2);

  return modoJuego;
}

int KlondikeVista::preguntaMazo(const std::string& mazo, int maxMazos) const
{
  int seleccion;

  do {
    std::cout << "Introduzca numero de " << mazo <<" [0-" << (maxMazos - 1) << "]: " << std::endl;
    std::cin >> seleccion;
  } while (seleccion < 0 || seleccion > maxMazos - 1);

  return seleccion;
}

int KlondikeVista::preguntaCartas() const
{
  int seleccion;

  std::cout << "Introduzca numero de cartas a mover: " << std::endl;
  std::cin >> seleccion;

  return seleccion;
}

bool KlondikeVista::compruebaFichero(std::string nombrePartida) const
{
  if(std::ifstream (nombrePartida))
  {
    return true;
  }
  return false;
}

std::string KlondikeVista::preguntaNombreFichero() const
{
  std::string nombrePartida;

  std::cout << "Introduzca el nombre con el que desea cargar/guardar la partida: "<< std::endl;
  std::cout << "Partidas existentes: " << std::endl;
  system("ls ./partidas/");
  std::cout << std::endl << "> " ;

  std::cin >> nombrePartida;
  nombrePartida = "./partidas/" + nombrePartida;

  return nombrePartida;
}

std::string KlondikeVista::preguntarNombrePuntuacion() const
{
  std::string nombrePuntuacion;

  std::cout << "¡Enhorabuena! Su puntuación está entre las 10 mejores "<< std::endl;
  std::cout << "Introduzca el nombre con el que desea aparecer en el ranking."<< std::endl;

  std::cin >> nombrePuntuacion;

  return nombrePuntuacion;
}
