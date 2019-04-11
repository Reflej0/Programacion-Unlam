#include "Carta.h"
char* duplicarCadena(char*);

Carta::Carta(char* dest,char pdedest[20] , float pre)
{
destinatario=duplicarCadena(dest);
if(dest && *dest && !destinatario)
    cerr<<"\nProblema al cargar "<<"\""<<dest<<"\""<<endl;
if(pdedest)
    strcpy(paisDeDestino,pdedest);
else
    *paisDeDestino='\0';
precio=pre;
}

Carta::~Carta()
{
    delete[] destinatario;
}

Carta& Carta::operator=(const Carta&obj)
{
    delete[] destinatario;
    destinatario=duplicarCadena(obj.destinatario);
    if(obj.destinatario && *obj.destinatario && !destinatario)
        cerr<<"\nProblema al cargar "<<"\""<<obj.destinatario<<"\""<<endl;
    if(obj.paisDeDestino)
        strcpy(paisDeDestino,obj.paisDeDestino);
    else
        *paisDeDestino='\0';
    precio = obj.precio;
    return *this;

}

Carta& Carta::operator++()
{
    precio++;
    return *this;
}

istream& operator>>(istream& entrada, Carta& obj)
{
    char aux[50];
    cout<<"\nIntroducir destinatario: ";
    entrada>>aux;
    obj.destinatario=duplicarCadena(aux);
    if(aux && *aux && !obj.destinatario)
        cerr<<"\nProblema al cargar "<<"\""<<aux<<"\""<<endl;
    cout<<"\nIntroducir pais de destino: ";
    entrada>>obj.paisDeDestino;
    cout<<"\nIntroducir Precio: ";
    entrada>>obj.precio;
    return entrada;
}

ostream& operator<<(ostream& salida, Carta& obj)
{
    salida<<"\nDestinatario: "<<(obj.destinatario?obj.destinatario:"Sin Cargar")<<"\t"<<"\nPais de destino: "<<obj.paisDeDestino<<"\t"<<"\nPrecio: "<<obj.precio<<endl;
    return salida;
}

////////////////////////////////////
char* duplicarCadena(char*s)
{
    if(s&&*s)
    {
        try
        {
            //return strcpy(new char[strlen(s)+1],s);
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
