#include <stdlib.h>
#include "hora.h"
using namespace std;
Hora::Hora(const Hora&obj)
{
    ss=obj.ss;
    mm=obj.mm;
    hh=obj.hh;
}
Hora::Hora(int ss,int mm, int hh)
{
    this->ss=ss;
    this->mm=mm;
    this->hh=hh;
}

Hora::Hora(long int seg)
{


}

Hora Hora::operator*(const int&seg)const
{
    Hora nue(ss*seg,mm,hh);
    return nue;
}

Hora operator*(const int&seg,const Hora&obj)
{
    Hora nue(seg*obj.ss,obj.mm,obj.hh);
    return nue;
}

Hora& Hora::operator=(const Hora&obj)
{
    ss=obj.ss;
    mm=obj.mm;
    hh=obj.hh;
    return *this;
}

Hora& Hora::operator+=(const int&num)
{
    ss+=num;
    return *this;
}

Hora& Hora::operator+=(const Hora&obj)
{
    ss+=obj.ss;
    mm+=obj.mm;
    hh+=obj.hh;
    return *this;
}
Hora& Hora::operator-=(const int&num)
{
    ss-=num;
    return *this;
}

Hora& Hora::operator-=(const Hora&obj)
{
    ss-=obj.ss;
    mm-=obj.mm;
    hh-=obj.hh;
    return *this;
}
ostream& operator<<(ostream&out,const Hora&obj)
{
    out<<obj.ss<<":"<<obj.mm<<":"<<obj.hh<<endl;
    return out;
}

Hora Hora::operator-(const Hora&obj)const
{
    Hora nue(ss-obj.ss,mm-obj.mm,hh-obj.hh);
    return nue;
}
