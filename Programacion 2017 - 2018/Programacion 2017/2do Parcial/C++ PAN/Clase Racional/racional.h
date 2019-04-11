#ifndef RACIONAL_H
#define RACIONAL_H
#include <cmath>
#include <iostream>


using namespace std;


class Racional
{
    private:
        int numerador; // REFLEJA EL SIGNO
        int denominador;
    public:
        Racional();
        Racional(int numerador,int denominador);
        friend ostream& operator<<(ostream& os,Racional& racional);
        friend int mcd(int n,int d);
        Racional& operator=(Racional& racional);
        friend Racional& operator+(int n,Racional& racional);
        Racional& operator+(Racional& racional);

        ~Racional();
};

#endif


