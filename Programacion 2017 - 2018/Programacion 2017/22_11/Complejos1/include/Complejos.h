#ifndef COMPLEJOS_H
#define COMPLEJOS_H
#include <iostream>

using namespace std;

class Complejos
{
    public:
        Complejos();
        Complejos(float a,float b);

        friend ostream& operator<<(ostream&sal,Complejos&obj);

        Complejos& operator=(const Complejos&obj);
        Complejos operator*(const Complejos&obj)const;
        Complejos operator+(const Complejos&obj)const;
        Complejos operator-(const Complejos&obj)const;
        Complejos operator/(const Complejos&obj)const;

        friend Complejos operator*(int numero,Complejos&obj);


    protected:

    private:
        float a,b;
};

#endif // COMPLEJOS_H
