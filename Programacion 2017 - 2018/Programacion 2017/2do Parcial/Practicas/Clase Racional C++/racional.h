#ifndef RACIONAL_H_INCLUDED
#define RACIONAL_H_INCLUDED
#include <iostream>
using namespace std;

class Racional
{
private:
    int signo = 1;
    unsigned numerador;
    unsigned denominador;
public:
    Racional();
    Racional(const float numero);
    Racional(const int num, const int den);
    void operator+=(const Racional &num);
    void operator-=(const Racional &num);
    void operator*=(const Racional &num);
    void operator/=(const Racional &num);
    void operator=(const float &num);
    friend ostream& operator<<(ostream &sal, Racional &num);
    unsigned getNumerador()const;
    unsigned getDenominador()const;
    int getSigno()const;
    void Simplificar();
    ///FUNCIONES ESTATICAS.
    static int MCD(int a, int b);
    static int MCM(int a, int b);
};

#endif // RACIONAL_H_INCLUDED
