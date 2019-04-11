#include "Hora.h"

#include <iomanip>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


const int Hora::segRelMax=24*3600;

Hora::Hora(const Hora& c)
{
    segRel=c.segRel;
}

Hora::Hora(int h, int m, int s)
{
    segRel=h*3600+m*60+s;
    validaciones();
}

void Hora::validaciones()
{
    while(segRel<0)
        segRel+=segRelMax;

    segRel%=segRelMax;
}


void Hora::sumarSeg(int s)
{
    segRel+=s;
    validaciones();
}

void Hora::imprimir()const///THIS ES UN PUNTERO AL OBJETO LLAMADOR. PODRIA USAR this->segRel;
{
    cout<<setw(2)<<setfill('0')<<segRel/3600<<":"<<setw(2)<<setfill('0')<<((segRel%3600)/60)<<":"<<setw(2)<<setfill('0')<<(segRel%60)<<'\n'<<"Segundos relativos: "<<segRel<<'\n';
}

bool Hora::esHoraValida(int h, int m, int s)
{
    if(h>23 || m>59 || s>59 || h<0 || m<0 || s<0)
        return false;

    return true;
}

/*int Hora::getHusoHorarioPorDefecto()
{
    int x;
    cout<<"Ingrese huso horario";
    cin>>x;
    while(x>12 || x<-12)
    {
        cout<<"Error. Reingrese"<<'\n';
        cin>>x;
    }

    return x;
}*/

//int Hora::husoHorarioPorDefecto=Hora::getHusoHorarioPorDefecto();

/*Hora Hora::masNSegundos(int n)const//NO SE DEVUELVE UNA REFERENCIA PORQUE UNA VEZ QUE TERMINA LA FUNCION LA VARIABLE LOCAL DESAPARECE. DEVUELVO UNA REFERENCIA EN CASO DE QUE EL OBJETO QUE ESTOY DEVOLVIENDO ES UNO QUE RECIBI POR REFERENCIA
{
    return Hora NO SE LE PONE NOMBRE(0,0,segRel+n);// *THIS PORQUE ES EL CONTENIDO DE LA DIRECCION
}
*/

Hora Hora::operator+(int n)const//NO SE DEVUELVE UNA REFERENCIA PORQUE UNA VEZ QUE TERMINA LA FUNCION LA VARIABLE LOCAL DESAPARECE. DEVUELVO UNA REFERENCIA EN CASO DE QUE EL OBJETO QUE ESTOY DEVOLVIENDO ES UNO QUE RECIBI POR REFERENCIA
{
    return Hora /*NO SE LE PONE NOMBRE*/(0,0,segRel+n);//*THIS PORQUE ES EL CONTENIDO DE LA DIRECCION
}

Hora Hora::operator+(const Hora& h)const
{
    return Hora(0,0,segRel+h.segRel);
}

Hora Hora::operator-(const Hora& h)const
{
    return Hora(0,0,segRel-h.segRel);
}

Hora Hora::operator-(int n)const//NO SE DEVUELVE UNA REFERENCIA PORQUE UNA VEZ QUE TERMINA LA FUNCION LA VARIABLE LOCAL DESAPARECE. DEVUELVO UNA REFERENCIA EN CASO DE QUE EL OBJETO QUE ESTOY DEVOLVIENDO ES UNO QUE RECIBI POR REFERENCIA
{
    return Hora /*NO SE LE PONE NOMBRE*/(0,0,segRel-n);//*THIS PORQUE ES EL CONTENIDO DE LA DIRECCION
}

bool Hora::operator<(const Hora& h)const
{
    return segRel<h.segRel;
}

bool Hora::operator==(const Hora& h)const
{
    return segRel==h.segRel;
}

Hora& Hora::operator+=(const Hora& h)
{
    segRel+=h.segRel;
    //NORMALIZAR
    return *this;
}

Hora& Hora::operator-=(const Hora& h)
{
    segRel-=h.segRel;
    //NORMALIZAR
    return *this;
}

Hora& Hora::operator++()
{
    segRel++;
    return *this;
}

Hora Hora::operator++(int)
{
    Hora aux(*this);//aux(0,0,segRel);//
    segRel++;
    return aux;
}
/*
Hora operator<<(const Hora h)
{

}*/
/**POR FUNCION**/
//h2=10+h1;
Hora operator+(int n,const Hora& h)
{
    return Hora(0,0,h.segRel+n);
}

ostream& operator<<(ostream& out, const Hora& h)
{
    out<<setw(2)<<h.segRel/3600<<":"<<setw(2)<<setfill('0')<<((h.segRel%3600)/60)<<":"<<setw(2)<<setfill('0')<<(h.segRel%60)<<endl;
    return out;
}

istream& operator>>(istream& in, Hora& h)
{
    char c;
    int hora,m,s;

    in>>hora>>c>>m>>c>>s;
    h.segRel=hora*3600+m*60+s;
    return in;
}


/*Hora::Hora(int h,int m, int s, int huso):husoHorario(husoHorarioPorDefecto)
{
    if(huso!=0)
        h+=huso;
    validaciones();
}

Hora::Hora(const Hora& h):husoHorario(h.husoHorarioPorDefecto)
{

}
*/

///CONSTRUCTORES
/*Hora::Hora(const Hora& c)
{
    segRel=c.segRel;
}

Hora::Hora()
{
    segRel=0;
}*/
