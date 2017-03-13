#ifndef NUMERO_H
#define NUMERO_H


class Numero
{
protected:
    int numero;
public:
    Numero();
    ~Numero();
    const bool operator==(const Numero* numero);

    void setNumero(int num) { numero = num; };
    int getNumero() const;
    virtual int getNextNumero() = 0;
    virtual int getPrevNumero() = 0;
    virtual const char* getTextoNumero() =0;
};

#endif // NUMERO_H
