#ifndef HORA_H_
#define HORA_H_

#include <iostream>
using namespace std;


class Hora
{
private:
    int ss,mm,hh;
public:

    //Constructores
    Hora(int=0,int=0,int=0);
    Hora(long int);
    Hora(const Hora&);

    //Sobrecarga de operadores
    Hora operator*(const int&)const;
    friend Hora operator*(const int&,const Hora&);
    friend ostream& operator<<(ostream&out,const Hora&);
    Hora& operator=(const Hora&);
    Hora& operator+=(const Hora&);
    Hora& operator+=(const int&);
    Hora& operator-=(const int&);
    Hora& operator-=(const Hora&);
    Hora operator-(const Hora&)const;
};
#endif

