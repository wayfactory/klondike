#ifndef KLONDIKECARGARBUILDER_H
#define KLONDIKECARGARBUILDER_H

#include <Fundacion.h>
#include <Stock.h>
#include <Descarte.h>
#include <Tableau.h>
#include <BarajaEspanolaBuilder.h>
#include <BarajaFrancesaBuilder.h>
#include <PartidaKlondike.h>
#include <Carta.h>

class KlondikeCargarBuilder
{
public:
    KlondikeCargarBuilder();
    std::shared_ptr<Mazo> construyeStock(CartaList &cartas);
    std::shared_ptr<Mazo> construyeDescarte(CartaList &cartas);
    std::shared_ptr<Mazo> construyeFundacion(CartaList& cartas, int numeroFundacion);
    std::shared_ptr<Mazo> construyeTableau(CartaList& cartas, const int numeroTableau);
    virtual void construyePalos() = 0;
    virtual void construyeNumeros() = 0;
    virtual void anadePalo(int numeroPalo) = 0;
    virtual void anadeNumero(int num) = 0;
    const std::shared_ptr<Numero>& getNumero(int num);
    const std::shared_ptr<Palo>& getPalo(int palo);
protected:
    std::vector<std::shared_ptr<Palo>> palos;
    std::vector<std::shared_ptr<Numero>> numeros;
};

#endif // KLONDIKECARGARBUILDER_H
