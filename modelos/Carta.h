#ifndef CARTA_H
#define CARTA_H

#include <Palo.h>
#include <Numero.h>
#include <cstdint>

const int UNDEFINED = 0;

class Carta
{
public:
    Carta();
    Carta(const std::shared_ptr<Palo> palo, const std::shared_ptr<Numero> num);
    Carta(const Carta& carta);
    ~Carta();

    bool getVisibilidad() const;
    void setVisibilidad(bool visible);

    const std::shared_ptr<Numero> getNumero() const;
    const std::shared_ptr<Palo>   getPalo()   const;

    bool mismoNumero(const Carta& carta) const;
    bool mismoColor(const Carta& carta) const;
    bool mismoPalo(const Carta& carta) const;

 protected:

 private:
    std::shared_ptr<Palo> palo;
    std::shared_ptr<Numero> numero;
    bool visibilidad;
};

#endif // CARTA_H
