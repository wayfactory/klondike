#include <VistaTableroGrande.h>
#include <Enmarcado.h>
#include <Carta.h>
#include <PaloEspanol.h>
#include <NumeroEspanol.h>
#include <string.h>
#include <algorithm>
#include <KlondikeMenu.h>
#include <PartidaKlondike.h>

VistaTableroGrande::VistaTableroGrande()
{
    inicializaPosiciones();
}

VistaTableroGrande::~VistaTableroGrande()
{
}

void VistaTableroGrande::inicializaPosiciones()
{
    // Posicionamos los stocks
    int valorX = PRIMERA_POSICION_X;
    int i = 0;

    // Marcamos la posicion de las cartas de la primera fila
    posiCoordenadaX[i] = valorX;
    posiCoordenadaY[i] = POSICION_ARRIBA_Y;

    i++;
    valorX += LONG_CANTO_HORIZONTAL_SUPERIOR + MARGEN_SIMPLE_HORIZONTAL;
    posiCoordenadaX[i] = valorX;
    posiCoordenadaY[i] = POSICION_ARRIBA_Y;
    i++;
    valorX += LONG_CANTO_HORIZONTAL_SUPERIOR + MARGEN_DOBLE_HORIZONTAL_SUPERIOR;

    // Posicionamos las 4 fundaciones
    for (int j=i; i<j+NUM_PALOS; i++)
    {
       posiCoordenadaX[i] = valorX;
       posiCoordenadaY[i] = POSICION_ARRIBA_Y;
       valorX += LONG_CANTO_HORIZONTAL_SUPERIOR + MARGEN_HORIZONTAL_ENTRE_PALOS;
    }

    // Posicionamos los tableaus
    valorX = PRIMERA_POSICION_X;

    for (int j = 1; j<= NUMERO_TABLEAUS; j++)
    {
      for (int k = 0; k<j+NUM_CARTAS_PALO; k++)
      {
        posiCoordenadaX[i] = valorX;
        posiCoordenadaY[i] = POSICION_ABAJO_Y + ((k-j)*MARGEN_VERTICAL);
        valorX++;
        i++;
      }
      valorX = PRIMERA_POSICION_X + (j * (LONG_CANTO_HORIZONTAL_SUPERIOR + MARGEN_SIMPLE_HORIZONTAL));
    }
}

void VistaTableroGrande::imprimeMarco()
{
  Coordenada *coordenadaInicio = new Coordenada(MARGEN_HORIZONTAL_TABLERO, MARGEN_VERTICAL_TABLERO);
  Enmarcado *marcoTablero = new Enmarcado(this);

  // Imprimimos barra horizontal de arriba
  marcoTablero->pintaRayaHorizontal(coordenadaInicio, Resolucion::coordXAlta, '*');

  // Imprimimos barra vertical izquierda
  marcoTablero->pintaRayaVertical(coordenadaInicio, Resolucion::coordYAlta, '*');

  // Imprimimos barra horizontal de abajo
  coordenadaInicio->setCoordY(Resolucion::coordYAlta+MARGEN_VERTICAL_TABLERO);
  marcoTablero->pintaRayaHorizontal(coordenadaInicio, Resolucion::coordXAlta, '*');

  // Imprimimos barra vertical derecha
  coordenadaInicio->setCoordY(MARGEN_VERTICAL_TABLERO);
  coordenadaInicio->setCoordX(Resolucion::coordXAlta+MARGEN_HORIZONTAL_TABLERO);
  marcoTablero->pintaRayaVertical(coordenadaInicio, Resolucion::coordYAlta, '*');

  delete coordenadaInicio;
  delete marcoTablero;
}

void VistaTableroGrande::imprimeMenu(const KlondikeMenu& menu)
{
  int posX = Resolucion::coordXAlta + MARGEN_HORIZONTAL_MENU;
  int posY = MARGEN_VERTICAL_MENU;

  std::string imprimir = " MENU ";
  memcpy(tableroAImprimir[posY]+posX, imprimir.c_str(), imprimir.length());
  posY++;
  imprimir = "¿Que movimiento desea hacer? ";
  posX = Resolucion::coordXAlta + MARGEN_HORIZONTAL_MENU_CORTO;
  posY++;
  memcpy(tableroAImprimir[posY]+posX, imprimir.c_str(), imprimir.length());
  posY++;

  std::list<std::string> options = menu.getOptions();
  for (auto it : options) {
    posY++;
    memcpy(tableroAImprimir[posY]+posX, it.c_str(), it.length());
  }
}

void VistaTableroGrande::imprimeRanking(std::shared_ptr<PartidaKlondike> partida)
{
  int posX = Resolucion::coordXAlta + MARGEN_HORIZONTAL_MENU;
  int posY = MARGEN_VERTICAL_RANKING;

  std::string imprimir = "RANKING";
  memcpy(tableroAImprimir[posY]+posX, imprimir.c_str(), imprimir.length());

  posY++;
  imprimir = "NOMBRE               PUNTUACION";
  posX = Resolucion::coordXAlta + MARGEN_HORIZONTAL_MENU_CORTO;
  posY++;

  std::stringstream linea;

  for (int i=0; i<TAMANO_RANKING; i++)
  {
    linea.str("");
    linea << partida->getNombreRanking(i) << partida->getPuntuacionRanking(i);
    memcpy(tableroAImprimir[posY]+posX, linea.str().c_str(), TAMANO_MAXIMO_NOMBRE_RANKING);
    posY++;
  }
}

void VistaTableroGrande::imprimeLeyendas()
{
   std::string imprimir = "STOCK";
   memcpy(tableroAImprimir[LEYENDA_ARRIBA_Y]+LEYENDA_STOCK_X, imprimir.c_str(), imprimir.length());
   imprimir = "DESCARTES";
   memcpy(tableroAImprimir[LEYENDA_ARRIBA_Y]+LEYENDA_DESCARTES_X, imprimir.c_str(), imprimir.length());
   for (int i=0; i<NUM_PALOS; i++)
   {
     imprimir = "FUNDACION "+ std::to_string(i);
     memcpy(tableroAImprimir[LEYENDA_ARRIBA_Y]+LEYENDA_FUNDACION_1 + (i*MARGEN_LEYENDA_FUNDACIONES), imprimir.c_str(), imprimir.length());
   }

   for (int i=0; i<NUMERO_TABLEAUS; i++)
   {
     imprimir = "TABLEAU "+ std::to_string(i);
     memcpy(tableroAImprimir[LEYENDA_ABAJO_Y]+LEYENDA_TABLEAU_1 + (i*MARGEN_LEYENDA_TABLEAUS), imprimir.c_str(), imprimir.length());
   }
}

void VistaTableroGrande::imprimeMarcador(int marcador)
{ 
   Coordenada *coordenadaInicio = new Coordenada(Resolucion::coordXAlta + MARGEN_MARCADOR_X, MARGEN_MARCADOR_Y);
   Enmarcado *marcoTablero = new Enmarcado(this);

   std::string imprimir = " MARCADOR ";
   int posX = Resolucion::coordXAlta + MARGEN_MARCADOR_X;
   int posY = MARGEN_LEYENDA_MARCADOR_Y;
   memcpy(tableroAImprimir[posY]+posX, imprimir.c_str(), imprimir.length());

   posX += MARGEN_MENU_DESPLAZAMIENTO;
   posY += MARGEN_VERTICAL_TABLERO;
   imprimir = std::to_string(marcador);
   memcpy(tableroAImprimir[posY]+posX, imprimir.c_str(), imprimir.length());

   // Imprimimos barra horizontal de arriba
   marcoTablero->pintaRayaHorizontal(coordenadaInicio, MARGEN_MARCADOR_Y, '*');

   // Imprimimos barra vertical izquierda
   marcoTablero->pintaRayaVertical(coordenadaInicio, MARGEN_VERTICAL, '*');

   // Imprimimos barra horizontal de abajo
   coordenadaInicio->setCoordY(MARGEN_MARCADOR_Y + MARGEN_VERTICAL);
   marcoTablero->pintaRayaHorizontal(coordenadaInicio, MARGEN_MARCADOR_Y, '*');

   // Imprimimos barra vertical derecha
   coordenadaInicio->setCoordY(MARGEN_MARCADOR_Y);
   coordenadaInicio->setCoordX(Resolucion::coordXAlta + MARGEN_MARCADOR_X + MARGEN_MARCADOR_Y);
   marcoTablero->pintaRayaVertical(coordenadaInicio, MARGEN_VERTICAL, '*');

   delete coordenadaInicio;
   delete marcoTablero;
}

void VistaTableroGrande::imprimeTablero(std::shared_ptr<PartidaKlondike> partida)
{
   MazoPointer mazo = partida->getDescartes();
   mazo->acepta(this);
   mazo = partida->getStock();
   mazo->acepta(this);

   printTableaus(partida);
   printFundaciones(partida);
   imprimeMarcador(partida->getMarcador());
   imprimeMarco();
   imprimeLeyendas();
   system("clear");
   for(int i=0; i<Resolucion::coordYAlta+PRIMERA_POSICION_X; i++)
   {
     for(int j=0; j<Resolucion::coordXAlta+TAMANO_MAXIMO_MENU; j++)
     {
       printf("%c", tableroAImprimir[i][j]);
     }
     printf("\n");
   }   
   reInicializarTablero();
}

void VistaTableroGrande::printTableaus(std::shared_ptr<PartidaKlondike> partida)
{
  MazoList tableaus = partida->getTableaus();
  int nTableau = 0;
  for (MazoList::iterator it = tableaus.begin(); it != tableaus.end(); ++it)
  {    
    (*it)->acepta(this);
    nTableau++;
  }
}

void VistaTableroGrande::printFundaciones(std::shared_ptr<PartidaKlondike> partida)
{
  MazoList fundaciones = partida->getFundaciones();
  int nFundacion = 0;
  for (MazoList::iterator it = fundaciones.begin(); it != fundaciones.end(); ++it)
  {
    (*it)->acepta(this);
    nFundacion++;
  }
}

void VistaTableroGrande::visita(const Stock *stock) const
{
  CartaList cartasStock = stock->getCartas();

  imprimeCartaNoVisibleDestapada(POSICION_STOCK);
  if (!stock->tieneCartas())
  {
    imprimeLeyendaSinCarta(POSICION_STOCK);
  }
}

void VistaTableroGrande::visita(const Fundacion *fundacion) const
{
  CartaList cartasFundacion = fundacion->getCartas();
  int posi = POSICION_FUNDACION + fundacion->getIndice();

  if (fundacion->tieneCartas())
  {
    const Carta *carta = fundacion->getUltimaCarta();
    imprimeCartaVisibleDestapada((Carta*) carta, posi);
  }
  else
  {
    imprimeCartaNoVisibleDestapada(posi);
    imprimeLeyendaSinCarta(posi);
  }
}

void VistaTableroGrande::visita(const Tableau *tableau) const
{  
  CartaList cartasTableau = tableau->getCartas();
  int posi = POSICION_INICIAL_TABLEAUS[tableau->getIndice()];

  for (CartaList::iterator it = cartasTableau.begin(); it != cartasTableau.end(); ++it)
  {
    if ((*it).getVisibilidad() == false)
    {
      imprimeCartaNoVisibleTapada(posi);   
    }
    else if ((*it).getVisibilidad() == true &&  it != cartasTableau.end() - 1)
    {
	imprimeCartaVisibleTapada(&(*it), posi);
    }
    else
    {
      imprimeCartaVisibleDestapada(&(*it), posi);
    }
    posi++;
  }
}

void VistaTableroGrande::visita(const Descarte *descarte) const
{

  if (descarte->tieneCartas())
  {
    const Carta *carta = descarte->getUltimaCarta();
    imprimeCartaVisibleDestapada((Carta*) carta, POSICION_DESCARTES);
  }
  else
  {
    imprimeCartaNoVisibleDestapada(POSICION_DESCARTES);
    imprimeLeyendaSinCarta(POSICION_DESCARTES);
  }
}

void VistaTableroGrande::imprimeCartaNoVisibleTapada(int posicion) const
{   
   int posInicioX = posiCoordenadaX[posicion];
   int posInicioY = posiCoordenadaY[posicion];

   Coordenada *coordenadaInicio = new Coordenada(++posInicioX, posInicioY);
   Enmarcado *marco = new Enmarcado((VistaTablero*)this);

   // Pintamos el canto horizontal superior
   marco->pintaRayaHorizontal(coordenadaInicio, LONG_CANTO_HORIZONTAL_SUPERIOR, (const char) '_');

   coordenadaInicio->setCoordX(--posInicioX);
   // Pintamos el canto vertical izquierdo
   coordenadaInicio->setCoordY(++posInicioY);
   marco->pintaRayaVertical(coordenadaInicio, LONG_CANTO_VERTICAL_IZQUIERDO, '|');
   ++posInicioX;

   // Pintamos el canto vertical derecho
   coordenadaInicio->setCoordX(++posInicioX + LONG_CANTO_HORIZONTAL_SUPERIOR);
   marco->pintaRayaVertical(coordenadaInicio, LONG_CANTO_VERTICAL_DERECHO, '|');

   delete coordenadaInicio;
   delete marco;
}

void VistaTableroGrande::imprimeLeyendaCartaOculta(Carta *carta, int posicion) const
{    
    int posInicioX = posiCoordenadaX[posicion];
    int posInicioY = posiCoordenadaY[posicion];

    std::string de = " ";
    std::string leyenda = carta->getNumero()->getTextoNumero();
    std::string palo = carta->getPalo()->getTextoPalo();
    leyenda.erase(std::remove_if(leyenda.begin(), leyenda.end(), ::isspace), leyenda.end());
    palo.erase(std::remove_if(palo.begin(), palo.end(), ::isspace), palo.end());
    leyenda = leyenda + de + palo;

    if (leyenda.length() > TAMANO_MAX_LEYENDA)
    {
      std::string trozo = leyenda.substr(0, TAMANO_MAX_LEYENDA);
      memcpy(tableroAImprimir[posInicioY+MARGEN_LEYENDA]+posInicioX+MARGEN_LEYENDA,
             trozo.c_str(), TAMANO_MAX_LEYENDA);
    }
    else
    {
      memcpy(tableroAImprimir[posInicioY+MARGEN_LEYENDA]+posInicioX+MARGEN_LEYENDA, leyenda.c_str(), leyenda.length());
    }
}

void VistaTableroGrande::imprimeLeyendaCartaVisible(Carta *carta, int posicion) const
{    
    int posInicioX = posiCoordenadaX[posicion] + MARGEN_HORIZONTAL_LEYENDA_CARTA_DESCUBIERTA;
    int posInicioY = posiCoordenadaY[posicion] + MARGEN_VERTICAL_LEYENDA_CARTA_DESCUBIERTA;

    std::string leyenda = carta->getNumero()->getTextoNumero();

    memcpy(tableroAImprimir[posInicioY]+posInicioX, leyenda.c_str(), leyenda.length());

    posInicioY += MARGEN_VERTICAL_LEYENDA_CARTA_DESCUBIERTA;
    posInicioX ++;

    std::string de = "  DE ";

    memcpy(tableroAImprimir[posInicioY]+posInicioX, de.c_str(), de.length());
    posInicioX--;
    leyenda = carta->getPalo()->getTextoPalo();
    memcpy(tableroAImprimir[posInicioY+MARGEN_VERTICAL_LEYENDA_CARTA_DESCUBIERTA]+posInicioX, leyenda.c_str(), leyenda.length());
}

void VistaTableroGrande::imprimeLeyendaSinCarta(int posicion) const
{
    int posInicioX = posiCoordenadaX[posicion] + MARGEN_HORIZONTAL_LEYENDA_SIN_CARTA;
    int posInicioY = posiCoordenadaY[posicion] + MARGEN_VERTICAL_LEYENDA_SIN_CARTA;

    std::string leyenda = " X       X ";
    memcpy(tableroAImprimir[posInicioY]+posInicioX, leyenda.c_str(), leyenda.length());
    memcpy(tableroAImprimir[posInicioY+MARGEN_CARTA_OCULTA]+posInicioX, leyenda.c_str(), leyenda.length());

    leyenda = "  X     X  ";
    posInicioY++;
    memcpy(tableroAImprimir[posInicioY]+posInicioX, leyenda.c_str(), leyenda.length());
    memcpy(tableroAImprimir[posInicioY+LEYENDA_ARRIBA_Y]+posInicioX, leyenda.c_str(), leyenda.length());

    leyenda = "   X   X   ";
    posInicioY++;
    memcpy(tableroAImprimir[posInicioY]+posInicioX, leyenda.c_str(), leyenda.length());
    memcpy(tableroAImprimir[posInicioY+MARGEN_VERTICAL]+posInicioX, leyenda.c_str(), leyenda.length());
    posInicioY++;
    leyenda = "   VACIO ";
    memcpy(tableroAImprimir[posInicioY]+posInicioX, leyenda.c_str(), leyenda.length());
    posInicioY++;
}

void VistaTableroGrande::imprimeCartaNoVisibleDestapada(int posicion) const
{
   // Primero imprimimos el canto superior horizontal y el canto vertical izquierdo
   imprimeCartaNoVisibleTapada(posicion);

   int posInicioX = posiCoordenadaX[posicion];
   int posInicioY = posiCoordenadaY[posicion];
   // Ya tenemos pintada la esquina inferior izquierda
   posInicioX += MARGEN_HORIZONTAL_TABLERO;

   Coordenada *coordenadaInicio = new Coordenada(posInicioX, posInicioY + LONG_CANTO_VERTICAL_IZQUIERDO);
   Enmarcado *marco = new Enmarcado((VistaTablero*)this);

   // Pintamos el canto horizontal inferior
   marco->pintaRayaHorizontal(coordenadaInicio, LONG_CANTO_HORIZONTAL_SUPERIOR, '_');
   posInicioY ++;
   coordenadaInicio->setCoordX(posInicioX + LONG_CANTO_HORIZONTAL_SUPERIOR + MARGEN_HORIZONTAL_TABLERO);
   coordenadaInicio->setCoordY(posiCoordenadaY[posicion] + LONG_CANTO_VERTICAL_DERECHO);
   marco->pintaRayaVertical(coordenadaInicio, LONG_CANTO_VERTICAL_IZQUIERDO, '|');

   delete coordenadaInicio;
   delete marco;
}

void VistaTableroGrande::imprimeCartaVisibleTapada(Carta *carta, int posicion) const
{
    imprimeCartaNoVisibleTapada(posicion);
    imprimeLeyendaCartaOculta(carta, posicion);
}

void VistaTableroGrande::imprimeCartaVisibleDestapada(Carta *carta, int posicion) const
{
    imprimeCartaNoVisibleDestapada(posicion);
    imprimeLeyendaCartaVisible(carta, posicion);
}
