#ifndef RACIONAL_H
#define RACIONAL_H
#include <iostream>
#include "Euclides.h"

using namespace std;

class Racional
{
    public:
        Racional();
        Racional(int aa);
        Racional(int aa,int bb);
        void simplificar();
        friend ostream& operator<<(ostream&sal,Racional&obj);
        Racional& operator=(const Racional&obj);
        Racional operator/(const Racional&obj)const;
        Racional& operator-=(int num);
        Racional& operator/=(int num);
        Racional operator+(const Racional&obj)const;
        Racional& operator *=(const Racional&obj);
        Racional operator++(int);//x++



    protected:

    private:
        int a,b;
};

#endif // RACIONAL_H
