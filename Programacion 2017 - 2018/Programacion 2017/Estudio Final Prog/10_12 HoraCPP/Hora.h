#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED
#include <iostream>

using namespace std;

class Hora
{
public:
    Hora();
    Hora(int segundos);
    Hora&operator=(const Hora &otra);
    Hora operator+(const Hora &otra);
    Hora&operator++();
    friend ostream& operator<<(ostream&sal, Hora &h);
private:
    int horas;
    int minutos;
    int segundos;
};

#endif // HORA_H_INCLUDED
