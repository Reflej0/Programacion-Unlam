#include "libro.h"
using namespace std;

Libro::Libro(char* nom,char* au,int pag)
{
    strcpy(nombre,nom);
    strcpy(autor,au);
    paginas=pag;
}
Libro Libro::operator+(const Libro& x)const
{
    char aux1[100],
         aux2[100];
    return Libro(strcat(strcpy(aux1,nombre),x.nombre),strcat(strcpy(aux2,autor),x.autor),paginas+x.paginas);
}
bool Libro::operator==(const Libro& x)const
{
    if(strcmp(x.nombre,nombre))
        return false;
    if(strcmp(x.autor,autor))
        return false;
    if(x.paginas==paginas)
        return true;
    return false;
}
ostream& operator<<(ostream& out,Libro& libro)
{
    out<<"Nombre:"<<libro.nombre<<"|||"<<"Autor:"<<libro.autor<<"|||"<<"Cantidad de paginas:"<<libro.paginas;
    return out;
}
