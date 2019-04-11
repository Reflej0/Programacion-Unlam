#ifndef FECHA_H
#define FECHA_H
#include <iostream>
#include <ostream>

class Fecha
{
    public:
        ~Fecha();
        Fecha(int=01, int=01, int=1900);
        Fecha(const Fecha&);
    Fecha& operator=(const Fecha&);
    friend ostream& operator<<(ostream&,Fecha&);
    friend istream& operator>>(istream&, Fecha&);
    friend class Persona;

    protected:
    private:
        int Dia;
        int Mes;
        int Anio;
};

#endif // FECHA_H
