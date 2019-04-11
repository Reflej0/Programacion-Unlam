#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED

using namespace std;

class Hora
{
private:
    int segundos;
    int minutos;
    int horas;
    int HoraaSegundos();
public:
    Hora(int segundos, int minutos, int horas);
    Hora(int segundos);
    Hora(const Hora& otra);
    Hora();
    Hora& operator=(const Hora &otra);
    Hora& operator+=(const Hora &otra);
    Hora& operator+=(int segundos);
    Hora operator-(Hora &otra);
    Hora operator*(int numero);
    friend Hora operator*(int n,Hora& otra);
    friend ostream& operator<<(ostream& sal, const Hora& otra);
};

#endif // HORA_H_INCLUDED
