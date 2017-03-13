#ifndef RESOLUCION_H
#define RESOLUCION_H

//class VistaTablero;

class Resolucion
{
//    VistaTablero *tablero;
public:
    enum POSICIONES { coordXAlta = 150, coordXBaja = 70, coordYAlta = 54, coordYBaja = 30 };

    Resolucion();
    ~Resolucion();
    int  getTamano();
    void pedirTamano();
    void setAltaResolucion();
    void setBajaResolucion();
//    VistaTablero* getTablero() { return tablero; };
};

#endif // RESOLUCION_H
