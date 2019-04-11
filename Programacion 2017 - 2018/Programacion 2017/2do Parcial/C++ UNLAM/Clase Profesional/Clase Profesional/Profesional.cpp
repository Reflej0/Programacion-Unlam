#include "Profesional.h"
char* duplicarCadena(char*);

/*Profesional::Profesional()
{
    Nombre=NULL;
    Matricula=0;
    Sueldo=0;
}*/

Profesional::~Profesional()
{
    delete[] Nombre;
}

Profesional::Profesional(char* nom, int mat, float suel)
{
    Nombre=duplicarCadena(nom);
    if(nom && *nom && !Nombre)
        cerr<<"Sin espacio en memoria para almacenar: "<<"\""<<nom<<"\""<<endl;
    Matricula = mat;
    Sueldo = suel;
}

Profesional::Profesional(const Profesional& obj)
{
    //copy ctor: no pedido
}

Profesional& Profesional::operator=(const Profesional& prof)
{
    Nombre = duplicarCadena(prof.Nombre);
    if(prof.Nombre && *prof.Nombre && !Nombre)
        cerr<<"Sin espacio en memoria para almacenar: "<<"\""<<prof.Nombre<<"\""<<endl;
    Matricula = prof.Matricula;
    Sueldo = prof.Sueldo;
    return *this;
}

Profesional& Profesional::operator+(const float aumento)
{
    Sueldo+=aumento;
    return *this;
}

ostream& operator<<(ostream& salida, Profesional& prof)
{
    salida<<"\nNombre: "<<(prof.Nombre?prof.Nombre:"Sin Cargar")<<"\tMatricula: "<<prof.Matricula<<"\tSueldo: "<<"$"<<prof.Sueldo<<endl;
    return salida;
}

istream& operator>>(istream& entrada, Profesional& prof)
{
    char aux[100];
    cout<<"\nIntroducir Nombre: ";
    entrada>>aux;
    prof.Nombre=duplicarCadena(aux);
    if(aux && *aux && !prof.Nombre)
        cerr<<"Sin memoria para: "<<"\""<<aux<<"\""<<endl;
    cout<<"\nIntroducir Matricula: ";
    entrada>>prof.Matricula;
    cout<<"\nIntroducir Sueldo: ";
    entrada>>prof.Sueldo;
    return entrada;
}

char* duplicarCadena(char*s)
{
    if(s&&*s)
    {
        try
        {
            //return strcpy(char* new char[strlen(s)+1],s)
            char* aux = new char[strlen(s)+1];
            strcpy(aux,s);
            return aux;
        }
        catch(bad_alloc&)
        {
            //
        }
    }
    return NULL;
}
