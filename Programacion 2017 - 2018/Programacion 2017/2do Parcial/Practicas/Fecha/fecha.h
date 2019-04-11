#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <iostream>
using namespace std;
class Fecha
{
private:
    unsigned diarel;
public:
    Fecha();
    Fecha(int d, int m, int a);
    void operator+=(int dias);
    void operator-=(int dias);
    void operator-= (const Fecha &otra);
    Fecha operator+(int dias)const;
    int diaJuliano(int d, int m, int a)const;
    static void julianoaGregoriano(int diajul,int a,int&d,int&m);
    void getDMA(int &d, int &m, int &a)const;
    friend istream&operator>>(istream&ent, Fecha &f);
    friend ostream&operator<<(ostream&sal, const Fecha &f);
private:
    static bool esFechaValida(int d, int m, int a);
};

#endif // FECHA_H_INCLUDED
