
#include "punto.h"

Punto::Punto(int x,int y){

    this->x = x;
    this->y = y;
}
Punto::Punto(const Punto & obj){

    this->x = obj.x;
    this->y = obj.y;
}
void Punto::mostrarCoordenadas(){

    cout<<"("<<this->x<<";"<<this->y<<")"<<endl;
}

/*void Punto::operator=(const Punto&obj){

    this->x = obj.x;
    this->y = obj.y;


}*/

Punto& Punto::operator=(const Punto&obj){

    this->x = obj.x;
    this->y = obj.y;

    return *this;
}

Punto& Punto::operator+=(const Punto&obj){

    this->x += obj.x;
    this->y += obj.y;

    return *this;
}

Punto& Punto::operator -=(const Punto&obj){

    this->x -= obj.x;
    this->y -= obj.y;

    return *this;
}
Punto& Punto::operator /=(const Punto&obj){

    this->x /= obj.x;
    this->y /= obj.y;

    return *this;
}
Punto& Punto::operator *=(const Punto&obj){

    this->x *= obj.x;
    this->y *= obj.y;

    return *this;
}
Punto& Punto::operator %=(const Punto&obj){

    this->x %= obj.x;
    this->y %= obj.y;

    return *this;
}

bool Punto::operator==(const Punto&obj)const{

    if(this->x == obj.x && this->y == obj.y){
        return true;
    }else{
        return false;
    }
}
bool Punto::operator!=(const Punto&obj)const{

    if(this->x != obj.x || this->y != obj.y){
        return true;
    }else{
        return false;
    }
}



Punto Punto::operator+(const Punto&obj)const{

    Punto aux(*this);

    aux.x += obj.x;
    aux.y += obj.y;

    return aux;
}
Punto Punto::operator-(const Punto&obj)const {

    Punto aux(*this);

    aux.x -= obj.x;
    aux.y -= obj.y;

    return aux;
}

Punto operator+(int a,const Punto&obj){

    Punto aux;

    aux.x = a+obj.x;
    aux.y = a+obj.y;
    return aux;
}

ostream & operator<<(ostream &sal,const Punto & obj){

    sal<<"("<<obj.x<<";"<<obj.y<<")";

    return sal;
}
istream & operator>>(istream &ent,Punto &obj){

    cout<<"Ingrese x:"<<endl;
    ent>>obj.x;
    cout<<"ingrese y:"<<endl;
    ent>>obj.y;

    return ent;
}


