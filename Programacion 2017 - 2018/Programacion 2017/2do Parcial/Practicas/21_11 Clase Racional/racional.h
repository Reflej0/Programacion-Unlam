#ifndef RACIONAL_H_INCLUDED
#define RACIONAL_H_INCLUDED

using namespace std;

class Racional
{
private:
    unsigned numerador;
    unsigned denominador;
    int signo;
public:
    Racional();
    Racional(const float);
    unsigned getNumerador()const;
    unsigned getDenominador()const;
    int getSigno()const;
    void operator+=(const Racional&);
    Racional& operator-=(const Racional&);
    Racional& operator*=(const Racional&);
    Racional& operator/=(const Racional&);
    void Simplificar();
    ///METODOS ESTATICOS.
    static int MCM(int a, int b);
    static int MCD(int a, int b);
};

#endif // RACIONAL_H_INCLUDED
