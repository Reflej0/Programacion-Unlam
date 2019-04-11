#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

using namespace std;

class Fecha
{
private:
    int dia;
    int mes;
    int ano;
    Fecha(int dias);
public:
    Fecha(int dia, int mes, int ano);
    Fecha();
    Fecha operator+(int dias)const;
    Fecha operator-(int dias)const;
    int FechaaDias()const;
    static Fecha DiasaFecha(int dias);
    static bool esBisiesto(int ano);
    static int cantDiasMes(int mes, int ano);
    static int cantDiasAno(int ano);
    static bool validarFecha(int dia, int mes, int ano);
    friend ostream& operator<<(ostream& sal, const Fecha& otra);
    friend istream& operator>>(istream& ent, Fecha& otra);
};

#endif // FECHA_H_INCLUDED
