#include "Racional.h"

Racional::Racional(){

    a=0;
    b=1;
}

Racional::Racional(int aa){

    a=aa;
    b=1;
}
Racional::Racional(int aa,int bb){

    a=aa;
    b=bb;

    simplificar();
}

void Racional::simplificar(){

    int mcd;

    mcd = euclides_mcd(a,b);

    cout<<"mcd: "<<mcd<<endl;

    if(mcd>0){
        a = a / mcd;
        b = b / mcd;
    }

    if(a<0 && b<0){
        a=-a;
        b=-b;
    }

}

ostream& operator<<(ostream&sal,Racional&obj){

    if(obj.b == 0){

        if(obj.a > 0){
            sal<<"(+ inf)"<<endl;


        }
        if(obj.a == 0){
            sal<<"(indet)"<<endl;
        }
        if(obj.a < 0){

            sal<<"(- inf.)"<<endl;
        }

        return sal;
    }

    sal<<'('<<obj.a<<'/'<<obj.b<<')';

    return sal;
}
Racional& Racional::operator=(const Racional&obj){

    a = obj.a;
    b = obj.b;

    return *this;
}
Racional Racional::operator/(const Racional&obj)const{

    Racional aux;
    int mcd;

    aux.a = a*obj.b;
    aux.b = b*obj.a;

    mcd = euclides_mcd(aux.a,aux.b);

    cout<<"mcd: "<<mcd<<endl;

    if(mcd>0){
        aux.a = aux.a / mcd;
        aux.b = aux.b / mcd;
    }

    return aux;
}

Racional& Racional::operator-=(int num){

    Racional rac2;

    rac2.a = num;
    rac2.b = 1;

    this->a = this->a*rac2.b - this->b*rac2.a;
    this->b = this->b * rac2.b;

    simplificar();

    return *this;
}

Racional& Racional::operator/=(int num){

    Racional rac2;

    rac2.a = num;
    rac2.b = 1;

    this->a = this->a*rac2.b;
    this->b= this->b*rac2.a;

    simplificar();

    return *this;
}

Racional Racional::operator+(const Racional&obj)const{

    Racional aux;

    aux.a = this->a * obj.b + this->b*obj.a;
    aux.b = this->b * obj.b;

    aux.simplificar();

    return aux;
}

Racional& Racional::operator *=(const Racional&obj){

    this->a = this->a*obj.a;
    this->b = this->b*obj.b;

    simplificar();

    return *this;
}

Racional Racional::operator++(int){
    Racional aux(*this);

    this->a += this->b;

    simplificar();

    return aux;
}//x++
