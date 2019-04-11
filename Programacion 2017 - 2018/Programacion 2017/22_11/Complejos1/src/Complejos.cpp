#include "Complejos.h"

Complejos::Complejos(){

    a=0;
    b=0;
}
Complejos::Complejos(float a,float b){

    this->a = a;
    this->b = b;
}

ostream& operator<<(ostream&sal,Complejos&obj){

    sal<<'('<<obj.a<<','<<obj.b<<')'<<endl;

    return sal;
}

Complejos& Complejos::operator=(const Complejos&obj){

    this->a = obj.a;
    this->b = obj.b;

    return *this;
}
Complejos Complejos::operator*(const Complejos&obj)const{

    Complejos aux;

    aux.a = (this->a*obj.a - this->b*obj.b);
    aux.b = (this->a*obj.b + this->b*obj.a);

    return aux;
}
Complejos Complejos::operator+(const Complejos&obj)const{

    Complejos aux;

    aux.a = this->a + obj.a;
    aux.b = this->b + obj.b;

    return aux;
}
Complejos Complejos::operator-(const Complejos&obj)const{

    Complejos aux;

    aux.a = this->a - obj.a;
    aux.b = this->b - obj.b;

    return aux;
}
Complejos Complejos::operator/(const Complejos&obj)const{

    Complejos aux;

    float a,b,c,d;
    a = this->a;
    b = this->b;
    c = obj.a;
    d = obj.b;

    aux.a = (a*c + b*d)/(c*c + d*d);
    aux.b = (c*b - a*d)/(c*c + d*d);

    return aux;
}

Complejos operator*(int numero,Complejos&obj){

    Complejos aux;

    aux.a = numero * obj.a;
    aux.b = numero * obj.b;

    return aux;
}
