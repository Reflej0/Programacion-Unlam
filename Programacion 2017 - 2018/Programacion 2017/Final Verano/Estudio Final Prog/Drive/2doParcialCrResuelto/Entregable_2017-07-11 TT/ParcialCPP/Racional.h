#ifndef RACIONAL_H_INCLUDED
#define RACIONAL_H_INCLUDED
#include <iostream>
using namespace std;

class Racional
{
private:
    int numerador;
    int denominador;
    void simplificar();
    int encontrarMCD();
public:
    Racional(const int n=0,const int d=1);
    Racional& operator=(const int n);
    Racional operator+(const Racional & r)const;
    bool operator>(const Racional&r)const;
    friend Racional operator+ (const int n,const Racional &r);
    friend ostream& operator<<(ostream& o,const Racional&r);
    friend istream& operator>>(istream &i,Racional&r);
    float real()const;

};

#endif // RACIONAL_H_INCLUDED
