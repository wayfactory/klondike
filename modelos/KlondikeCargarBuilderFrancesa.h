#ifndef KLONDIKECARGARBUILDERFRANCESA_H
#define KLONDIKECARGARBUILDERFRANCESA_H

#include <KlondikeCargarBuilder.h>

class KlondikeCargarBuilderFrancesa : public KlondikeCargarBuilder
{
public:
    KlondikeCargarBuilderFrancesa();
    void construyePalos();
    void construyeNumeros();
    void anadePalo(int numeroPalo);
    void anadeNumero(int num);
};

#endif // KLONDIKECARGARBUILDERFRANCESA_H
