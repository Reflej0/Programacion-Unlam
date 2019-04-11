#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED

using namespace std;

class Hora
{
private:
    int segundos;
    int minutos;
    int horas;
public:
    Hora(int segundos);
    Hora();
    Hora operator+(Hora& otra);
    Hora& operator++();
    friend ostream& operator<<(ostream& sal, Hora& h);
};

#endif // HORA_H_INCLUDED
