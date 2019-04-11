#ifndef RACIONALES_H_INCLUDED
#define RACIONALES_H_INCLUDED
#include<iostream>
using namespace std;

class Racional
{
    private:
        int numerador;
        int denominador;
        void simplificar();
        int encontrar_mcd();
    public:
        Racional(int x=0,int y=1);
        void mostrar()const;
        Racional operator*(const Racional&)const;
        Racional operator+(const Racional&)const;
        Racional operator/(const Racional&)const;
};

#endif // RACIONALES_H_INCLUDED
