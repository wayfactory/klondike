#ifndef KLONDIKECARGARBUILDERESPANOL_H
#define KLONDIKECARGARBUILDERESPANOL_H

#include <KlondikeCargarBuilder.h>

class KlondikeCargarBuilderEspanola : public KlondikeCargarBuilder
{
public:
    KlondikeCargarBuilderEspanola();

    void construyePalos();
    void construyeNumeros();
    void anadePalo(int numeroPalo);
    void anadeNumero(int num);
private:
};


#endif // KLONDIKECARGARBUILDERESPANOL_H

