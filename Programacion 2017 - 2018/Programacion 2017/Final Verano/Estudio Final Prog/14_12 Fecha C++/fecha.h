#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <istream>

using namespace std;

class Fecha
{
private:
    int dia;
    int mes;
    int ano;
    int FechaaDias()const;
public:
    Fecha(int dia, int mes, int ano);
    Fecha();
    Fecha& operator=(const Fecha& otra);
    Fecha operator+(int dias)const;
    Fecha operator-(int dias)const;
    Fecha operator++(int);
    Fecha& operator++();
    friend ostream& operator<<(ostream& sal, const Fecha& otra);
    friend istream& operator>>(istream& ent, Fecha &otra);
    static bool ValidarFecha(int dia, int mes, int ano);
    static bool EsBisiesto(int ano);
    static Fecha DiasaFechas(int dias);
    static int cantdiasano(int ano);
};

#endif // FECHA_H_INCLUDED
