#include "Auto.h"
char* duplicarCadena(char*);

Auto::Auto()
{
    Marca=NULL;
    Anio=0;
    Precio=0;
    *Modelo='\0';
}

Auto::~Auto()
{
    delete[] Marca;
}

Auto::Auto(char*marca,char modelo[15], int anio, float precio)
{
    Anio=anio;
    Precio=precio;
    if(modelo)
        strcpy(Modelo,modelo);
    else
        *Modelo='\0';
    Marca=duplicarCadena(marca);
    if(marca&&*marca&&!Marca)
        cerr<<"\nSin espacio para guardar: "<<"\""<<marca<<"\""<<endl;
}

Auto::Auto(const Auto& obj)
{
    Marca=duplicarCadena(obj.Marca);
    Anio=obj.Anio;
    Precio=obj.Precio;
    strcpy(Modelo,obj.Modelo);
}

Auto& Auto::operator=(const Auto& coche)
{
    strcpy(Modelo,coche.Modelo);
    Anio = coche.Anio;
    Precio = coche.Precio;
    delete[] Marca;
    Marca = duplicarCadena(coche.Marca);
    if(coche.Marca && *coche.Marca && !Marca)
        cerr<<"\nSin espacio para guardar: "<<"\""<<coche.Marca<<"\""<<endl;
    return *this;
}

ostream& operator<<(ostream&salida,const Auto& coche)
{
    salida<<"\nMarca:"<<(coche.Marca?coche.Marca:"NULL")<<"\tModelo: "<<coche.Modelo<<"\tAnio: "<<coche.Anio<<"\tPrecio: "<<coche.Precio<<endl;
    return salida;
}

void Auto::aumentarPrecio(float aumento)
{
    Precio+=(Precio*aumento/100);
}

Auto& Auto::operator++()
{
    Anio++;
    return *this;
}
///////////////////////////////////////////////////
char* duplicarCadena(char*s)
{
    if(s&&*s)
    {
        try
        {
            return strcpy(new char[strlen(s)+1],s);
//            char* aux = new char[strlen(s)+1];
//            strcpy(aux,s);
//            return aux;
        }
        catch(bad_alloc&)
        {
            //
        }
    }
    return NULL;
}
