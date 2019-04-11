#ifndef RACIONAL_H
#define RACIONAL_H
#include <iostream>

using namespace std;

class Racional
{
private:
    int num;
    int den;
public:
    Racional();
    Racional(int a, int b);
    Racional operator+(Racional& otro);
    friend ostream& operator<<(ostream& sal, Racional& r);
    static int MCM(int mayor, int menor);
    static int MCD(int mayor, int menor);
    int getNumerador();
    int getDenominador();
};

Racional operator+(int otro, Racional& r);

#endif // RACIONAL_H
