#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>

using namespace std;

class fecha{

    public:
        fecha(); //constructor por defecto
        fecha(int d,int m,int a); //constructor con parametros

        void sumar_dias(int dias);

        void operator+=(int dias);
        int operator-(const fecha&otra)const;
        fecha operator+(int dias)const;

        //friend ostream & operator<<(ostream&sal,fecha&obj);

        static bool esFechaValida(int d,int m,int a);
        static int diaJuliano(int d,int m,int a);

        fecha&operator++(); //preincremento

        fecha operator++(int); //postincremento

        static void julianoaGregoriano(int diajul,int a,int&d,int&m);

        void getDMA(int&d,int&m,int&a) const;

        friend istream&operator>>(istream&ent,fecha& f);




    protected:

    private:
        int diaRelativo;



};

ostream & operator<<(ostream&sal, const fecha& obj);

#endif // HEADER_H_INCLUDED
