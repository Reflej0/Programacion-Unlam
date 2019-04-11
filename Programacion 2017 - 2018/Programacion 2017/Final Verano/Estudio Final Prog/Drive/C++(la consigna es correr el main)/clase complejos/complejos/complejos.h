#ifndef COMPLEJOS_H_INCLUDED
#define COMPLEJOS_H_INCLUDED
#include <iostream>

using namespace std;
class Complejo
{
    private:
        int real;
        int imaginaria;
    public:
        Complejo(int x=0,int y=0);
        Complejo operator*(const Complejo&)const;
        friend Complejo operator*(int ,const Complejo&);
        friend ostream& operator<<(ostream&,const Complejo&);
};

#endif // COMPLEJOS_H_INCLUDED
