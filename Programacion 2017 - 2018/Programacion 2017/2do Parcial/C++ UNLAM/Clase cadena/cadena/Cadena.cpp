#include "Cadena.h"
char* duplicarCadena(const char*s);

Cadena::Cadena()
{
    *ce='\0';
    cd=NULL;
}

Cadena::Cadena(const char*cad)
{
    if(cad)
        strcpy(ce,cad);
    else
        *ce='\0';
    cd=duplicarCadena(cad);
    if(cad&&*cad&&!cd)
    {
        cerr<<"error: NO se pudo reservar memoria para"<<cad<<endl;
    }
}


/**Con lista de iniaziladores**NO LE GUSTA A LOPEZ**/
/*
Cadena::Cadena(const char*cad): cd(duplicarCadena(cad))
{
    if(cad)
        strcpy(ce,cad);
    else
        *ce='\0';
    if(cad&&*cad&&!cd)
    {
        cerr<<"error: NO se pudo reservar memoria para"<<cad<<endl;
    }
}
*/
Cadena::~Cadena()
{
    delete[] cd;
}

Cadena::Cadena(const Cadena& obj)
{
    cd= new char [strlen(obj.cd)+1];
    if(cd)
        strcpy(cd,obj.cd);
    strcpy(cd,obj.cd);
}

char* duplicarCadena(const char*s)
{
    if(s&&*s)
    {
        try
        {
            //return (strcpy(new char[strlen(s)+1],s));
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

Cadena& Cadena::operator=(const Cadena& s)
{
    strcpy(ce,s.ce);
    delete[]cd;
    cd=duplicarCadena(s.ce);
    if(s.cd&&*s.cd&&!cd)
        cerr<<"hubo un error al copiar: "<<"\""<<s.ce<<"\""<<" ,flaco"<<endl;
    return (*this);
}

ostream&operator<<(ostream&out,const Cadena&cad)
{
    out<<"Dinamica: "<<(cad.cd?cad.cd:"NULL")<<"\nEstatica: "<<cad.ce;
    return out;
}

istream&operator>>(istream&entrada,Cadena&cad)
{
    cout<<"Flaco, ingresa una cadena: "<<endl;
    entrada>>cad.ce;
    delete [] cad.cd;
    cad.cd=duplicarCadena(cad.ce);
    if(cad.ce&&*(cad.ce)&&!cad.cd)
        cerr<<"error";
    return entrada;
}
