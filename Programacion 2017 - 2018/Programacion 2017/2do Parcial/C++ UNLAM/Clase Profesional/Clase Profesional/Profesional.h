#ifndef PROFESIONAL_H
#define PROFESIONAL_H
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

class Profesional
{
    public:
        //Profesional();
        ~Profesional();
        Profesional(char* = NULL, int=0, float=0);
        Profesional(const Profesional&);
    friend ostream& operator<<(ostream&,Profesional&);
    friend istream& operator>>(istream&, Profesional&);
    Profesional& operator=(const Profesional&);
    Profesional& operator+(const float);

    protected://

    private:
        int Matricula;
        float Sueldo;
        char* Nombre;
};

#endif // PROFESIONAL_H
