#ifndef AUTO_H
#define AUTO_H
#include<iostream>
#include<string.h>
using namespace std;

class Auto
{
    public:
        Auto();
        ~Auto();
        Auto(char*,char[15],int,float);
        Auto(const Auto&);
    Auto& operator=(const Auto&);
    Auto& operator++();
    friend ostream& operator<<(ostream&,const Auto&);
    void aumentarPrecio(float);

    protected:
    private:
        char* Marca;
        char Modelo[15];
        float Precio;
        int Anio;
};

#endif // AUTO_H
