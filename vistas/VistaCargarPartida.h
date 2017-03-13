#ifndef VISTACARGARPARTIDA_H
#define VISTACARGARPARTIDA_H


#include <memory>
#include <MazoVisitor.h>
#include <Tableau.h>
#include <Fundacion.h>
#include <Stock.h>
#include <Descarte.h>
#include <VistaTablero.h>
#include <KlondikeCargarBuilder.h>
#include <fstream>
#include <iostream>

class PartidaKlondike;

class VistaCargarPartida
{
    std::string nombrePartida;
    std::ifstream *fichero;
    KlondikeCargarBuilder *cargarBuilder;
public:
    VistaCargarPartida(std::string nombreFichero);
    ~VistaCargarPartida();
    void cargar(std::shared_ptr<PartidaKlondike> partida);
    void cargaTipoPartida(std::shared_ptr<PartidaKlondike> partida);
    void cargaStock(std::shared_ptr<PartidaKlondike> partida);
    void cargaDescarte(std::shared_ptr<PartidaKlondike> partida);
    void cargaFundaciones(std::shared_ptr<PartidaKlondike> partida);
    void cargaTableaus(std::shared_ptr<PartidaKlondike> partida);
};

#endif // VISTACARGARPARTIDA_H
