#include "Cadenas.h"

///13//11//2017

Cadena ::Cadena(int capacidad)
{
    this->cadena= new char[capacidad];
}
Cadena ::Cadena(const char * cadena)
{
    if(!cadena)
    {
        this->cadena = new char[1];
        this->cadena[0]='\0';
        return;
    }
    this->cadena= new char[strlen(cadena)+1];
    strcpy(this->cadena, cadena);
    return;
}

Cadena ::Cadena(const Cadena &otra)
{
    this->cadena= new char[strlen(otra.cadena)+1];
    strcpy(this->cadena, otra.cadena);
    return;
}

Cadena::~Cadena()
{
    delete[]this->cadena;
    return;
}
Cadena &Cadena ::operator=(const Cadena &otra)
{
    int longOtra = strlen(otra.cadena);
    if(strlen(this->cadena)!= longOtra)
    {
        delete[]this->cadena;
        this->cadena = new char[longOtra+1];
    }
    strcpy(this->cadena,otra.cadena);
    return *this;
}
Cadena Cadena::operator+(const Cadena &otra)const
{
    int longCa=strlen(this->cadena);
    int longOtra=strlen(otra.cadena);
    Cadena Suma(longCa + longOtra + 1);
    strcpy(Suma.cadena, this->cadena);
    strcat(Suma.cadena, otra.cadena);
    return Suma;
}
Cadena Cadena::operator+(const char*otra)const
{
    int longC = strlen(this->cadena);
    int longO = strlen(otra);
    Cadena Suma(longC + longO +1);
    strcpy(Suma.cadena, this->cadena);
    strcat(Suma.cadena, otra);
    return Suma;
}
Cadena Cadena::operator+(char c)const
{
    Cadena Suma(strlen(this->cadena)+2);
    strcpy(Suma.cadena, this->cadena);
    Suma.cadena[strlen(Suma.cadena)]=c;
    Suma.cadena[strlen(Suma.cadena)+1]='\0';
    return Suma;
}
Cadena &Cadena ::operator+=(const Cadena &otra)
{
    char * concat= new char[strlen(this->cadena) + strlen(otra.cadena) +1];
    strcpy(concat, this->cadena);
    strcat(concat, otra.cadena);
    delete[]this->cadena;
    this->cadena = concat;
    return *this;
}
ostream& operator<<(ostream &sal,Cadena &c)
{
    sal<<c.cadena;
    return sal;
}
