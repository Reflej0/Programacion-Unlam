#ifndef PUNTO_H_INCLUDED
#define PUNTO_H_INCLUDED

#include <iostream>

using namespace std;

class Punto{

    private:
        int x;
        int y;


    public:
        Punto(int x=0,int y=0);
        Punto(const Punto & obj);
        void mostrarCoordenadas();
        //void operator=(const Punto&obj);
        Punto& operator=(const Punto&obj);
        Punto& operator+=(const Punto&obj);
        Punto& operator -=(const Punto&obj);
        Punto& operator /=(const Punto&obj);
        Punto& operator *=(const Punto&obj);
        Punto& operator %=(const Punto&obj);
        bool operator==(const Punto&obj)const;
        bool operator!=(const Punto&obj)const;

        Punto operator+(const Punto&obj)const;
        Punto operator-(const Punto&obj)const;

        friend Punto operator+(int a,const Punto&obj);
        friend ostream & operator<<(ostream &sal,const Punto & obj);
        friend istream & operator>>(istream &ent,Punto &obj);

};

#endif // PUNTO_H_INCLUDED
