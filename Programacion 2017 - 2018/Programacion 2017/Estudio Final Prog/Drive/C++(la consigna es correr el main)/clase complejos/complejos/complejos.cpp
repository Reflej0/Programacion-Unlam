#include"complejos.h"

using namespace std;

Complejo::Complejo(int x,int y)
{
    real=x;
    imaginaria=y;
}
Complejo Complejo::operator*(const Complejo& z)const
{
    return Complejo(real*z.real-imaginaria*z.imaginaria,real*z.imaginaria+imaginaria*z.real);
}

Complejo operator*(int n,const Complejo& z)
{
    return Complejo(z.real*n,z.imaginaria*n);
}
ostream& operator<<(ostream& out,const Complejo& z)
{
    out<<"("<<z.real<<","<<z.imaginaria<<")";
    return out;
}
