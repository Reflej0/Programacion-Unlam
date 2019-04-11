#include "cadenas.h"

Cadena::Cadena(int capacidad)
{
    this->cadena = new char[capacidad];
}

///CONSTRUCTOR QUE LE PASO UN CHAR*, osea una cadena de c normal.
Cadena::Cadena(const char* cadena)
{
    ///SI LA CADENA QUE PASAN ESTA VACIA o NULL.
    if(!cadena)
    {
        //Creo un nuevo objeto cadena con 1 caracter.
        this->cadena = new char[1];
        this->cadena[0]='\0';
        return;
    }
    this->cadena = new char[strlen(cadena)+1];
    strcpy(this->cadena, cadena);
    return;
}

///CONSTRUCTOR QUE LE PASO OTRO OBJETO TIPO CADENA.
Cadena::Cadena(const Cadena &otra)
{
    this->cadena = new char[strlen(otra.cadena)+1];
    strcpy(this->cadena, otra.cadena);
    return;
}

///DESTRUCTOR DE CADENA.
Cadena::~Cadena()
{
    delete[]this->cadena;
    return;
}

///SOBRECARGA OPERADOR = con otro objeto tipo CADENA.
Cadena &Cadena::operator=(const Cadena&otra)
{
    unsigned longOtra = strlen(otra.cadena);
    //Si las longitudes son diferentes, las adapto.
    if(strlen(this->cadena)!=longOtra)
    {
        delete[]this->cadena;
        this->cadena = new char[longOtra+1];
    }
    //Copio la cadena.
    strcpy(this->cadena, otra.cadena);
    //Retorno una copia.
    return *this;
}

///SOBRECARGA OPERADOR + con otro objeto tipo CADENA
Cadena Cadena::operator+(const Cadena &otra)const
{
    //Saco las longitudes.
    int longCa = strlen(this->cadena);
    int longOtra = strlen(otra.cadena);
    //Creo un nuevo objeto tipo cadena.
    Cadena Suma(longCa + longOtra + 1);
    //Primero copio la primera cadena a la nueva.
    strcpy(Suma.cadena, this->cadena);
    //Concateno la segunda a la nueva.
    strcat(Suma.cadena, otra.cadena);
    return Suma;
}

///SOBRECARGA OPERADOR + con CHAR*
Cadena Cadena::operator+(const char* otra)const
{
    //Saco las longitudes.
    int longC = strlen(this->cadena);
    int longO = strlen(otra);
    //Creo un nuevo objeto tipo cadena.
    Cadena Suma(longC + longO + 1);
    //Primero copio la primera cadena a la nueva.
    strcpy(Suma.cadena, this->cadena);
    //Concatneo la segunda a la nueva.
    strcat(Suma.cadena, otra);
    return Suma;
}

///SOBRECARGA OPERADOR + con CHAR(caracter)
Cadena Cadena::operator+(char c)const
{
    Cadena Suma(strlen(this->cadena)+2);
    strcpy(Suma.cadena, this->cadena);
    Suma.cadena[strlen(Suma.cadena)] = c;
    Suma.cadena[strlen(Suma.cadena)+1]='\0';
    return Suma;
}

///SOBRECARGA OPERADOR += con otro objeto tipo CADENA.
Cadena &Cadena::operator+=(const Cadena&otra)
{
    //Creo el char* con la longitud nueva.
    char *concat = new char[strlen(this->cadena)+strlen(otra.cadena)+1];
    strcpy(concat, this->cadena);
    strcat(concat, otra.cadena);
    //Elimino el anterior this->cadena del objeto.
    delete[]this->cadena;
    //Le seteo el nuevo.
    this->cadena = concat;
    //Devuelvo una copia.
    return *this;
}

ostream& operator<<(ostream &sal, Cadena&c)
{
    sal<<c.cadena;
    return sal;
}

char* Cadena::getCadena()const
{
    return this->cadena;
}
