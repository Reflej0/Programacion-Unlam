#ifndef PUNTO_H
#define PUNTO_H
#include <iostream>
using namespace std;
class Punto
{
    public:
        ~Punto();
        Punto(const Punto&);
        Punto(int=0,int=0);
        void mostrar();
        Punto& operator=(const Punto&);
        Punto& operator+=(const Punto&);
        Punto& operator-=(const Punto&);
        Punto operator+(const Punto&)const;
        Punto operator-(const Punto&)const;
        bool operator ==(const Punto&)const;
        bool operator >(const Punto&)const;
        bool operator <(const Punto&)const;
        bool operator >=(const Punto&)const;
        bool operator <=(const Punto&)const;
        Punto operator++(int); //posfijo
        Punto& operator++();   //prefijo
        Punto operator+(const int&)const;
        friend Punto operator+(const int&,const Punto&);
        friend ostream& operator<<(ostream&,const Punto&);
        friend istream& operator>>(istream&,Punto&);
    protected:
    private:
        int x;
        int y;
};

#endif // PUNTO_H
