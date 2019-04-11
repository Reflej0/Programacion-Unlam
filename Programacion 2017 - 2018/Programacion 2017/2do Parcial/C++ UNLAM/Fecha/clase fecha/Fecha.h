#ifndef FECHA_H
#define FECHA_H
#include <iostream>
using namespace std;

class Fecha
{
    public:
        ~Fecha();
        Fecha(int=01, int=01, int=1900);
        Fecha(const Fecha&);
    Fecha& operator=(const Fecha&);
    friend ostream& operator<<(ostream&,Fecha&);
    friend istream& operator>>(istream&, Fecha&);

    protected:
    private:
        int Dia;
        int Mes;
        int Anio;
};

#endif // FECHA_H
