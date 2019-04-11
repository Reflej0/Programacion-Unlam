#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED

#include <iostream>

using namespace std;

///PARA DEFINIR PARAMETROS POR DEFECTO LOS DEFINO EN EL .H PERO NO EN EL .CPP
class Hora
{
    private://Si no pongo nada, por defecto es privado.
        int segRel;//00:01:02->62.
        static const int segRelMax;
        static int husoHorarioPorDefecto;
    public:
        Hora(const Hora&);
        Hora(int h=0,int m=0,int s=0);///SE LLAMA PARAMETRIZADO POR DEFECTO.

        void sumarSeg(int s);
        void imprimir()const;//Cuando el llamador es constante, es decir que no va a ser modificado por la funcion se pone ese CONST;
        void validaciones();
        static bool esHoraValida(int h, int m, int s);//NO NECESITA UN OBJETO LLAMADOR. SE LLAMA DIRECTAMENTE DESDE LA CLASE
        //static int getHusoHorarioPorDefecto();

        Hora masNSegundos(int n)const;
        Hora operator+(int n)const;
        Hora operator+(const Hora& h)const;
        Hora operator-(const Hora& h)const;
        Hora operator-(int n)const;
        bool operator<(const Hora& h)const;
        bool operator>(const Hora& h)const;
        bool operator==(const Hora& h)const;
        Hora& operator+=(const Hora& h);
        Hora& operator-=(const Hora& h);
        Hora& operator++();
        Hora operator++(int);
        friend ostream& operator<<(ostream& out, const Hora& h);
        friend Hora operator+(int n,const Hora& h);//le da acceso de los atributos privados de los parametros.
        friend istream& operator>>(istream& in, Hora& h);
};

#endif // HORA_H_INCLUDED

///Constuctores
/*
  Hora(const Hora&);
  Hora();///CONSTRUCTOR.SE LLAMA POR DEFECTO
  Hora(int h,int m=0,int s=0);///OTRO CONSTRUCTOR.PRIMER CONSTRUCTOR: HORA, SEGUNDO: HORA Y MINUTOS, TERCERO: HORA, MINUTOS Y SEGUNDOS. SE LLAMA PARAMETRIZADO
  Hora(int h=0,int m=0,int s=0);///SE LLAMA PARAMETRIZADO POR DEFECTO.
  Hora(int h,int m, int s, int huso):husoHorario(husoHorarioPorDefecto)
*/

///PARA CONSTANTE
/*  private://Si no pongo nada, por defecto es privado.
        int segRel;//Segundos relativos//00:01:02->62 SegRel.//LOS ATRIBUTOS PUEDEN SER CONSTANTES Y TAMBIEN ESTATICOS
        //LOS ESTATICOS PUEDEN SERVIR PARA GUARDAR CIERTA INFORMACION QUE CORRESPONEDE A TODOS LOS OBJETOS DE NUESTRA CLASE
        static const int segRelMax;
        static int husoHorarioPorDefecto;
        const int husoHorario;
    public:
        Hora():segRel(0),husoHorario(husoHorarioPorDefecto)
        {}
        Hora(int h, int m=0, int s=0, int husoHorarioPorDefecto
*/

///ESTATICOS: PUEDEN SERVIR PARA GUARDAR INFORMACION QUE CORRESPONDE A TODOS LOS OBJETOS DE NUESTRA CLASE



