#include "header.h"
#include <iostream>
using namespace std;

fecha::fecha(){

    diaRelativo =1;
}

fecha::fecha(int d,int m,int a){

    if(!esFechaValida(d,m,a)){
        //throw false;
        cout << "ERROR ES FECHA VALIDA" << endl;
    }

    long difAnios = a-1601;

    diaRelativo = difAnios * 365 + difAnios / 4 - difAnios / 100 + difAnios / 400 + diaJuliano(d,m,a);
}

bool fecha::esFechaValida(int d,int m,int a){

    int dias_mes[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    if(a%400 == 0 || (a%4 == 0 && a%100 !=0)){ //bisiesto

        dias_mes[1]=29;
    }

    if(d<1 || d > dias_mes[m-1]){
        return false;
    }

    if(m<1 || m > 12){
        return false;
    }

    if(a<1600){
        return false;
    }

    return true;
}

int fecha::diaJuliano(int d,int m,int a){

    int dias_mes[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int dias=0,i;

    if(a%400 == 0 || (a%4 == 0 && a%100 !=0)){ //bisiesto

        dias_mes[1]=29;
    }

    dias+=d;

    for(i=0;i<m-2;i++){
        dias+=dias_mes[i];
    }

    return dias;
}

void fecha::sumar_dias(int dias){

    if(dias < 0){

        //throw 1;
        cout << "dias < 0" << endl;
    }
    this->diaRelativo+=dias;
}

void fecha::operator+=(int dias){

    if(dias < 0){

        //throw 1;
        cout << "dias < 0" << endl;
    }

    this->diaRelativo+=dias;
}

int fecha::operator-(const fecha&otra)const{

    return this->diaRelativo - otra.diaRelativo;
}

fecha fecha::operator+(int dias)const{

    if(dias < 0){

        //throw 1;
        cout << "dias < 0" << endl;
    }

    fecha f;

    f.diaRelativo = this->diaRelativo + dias;

    return f;
}

/*ostream & operator<<(ostream&sal,fecha&obj){

    sal<<"diaRelativo: "<<obj.diaRelativo<<endl;

    return sal;
}*/

fecha&fecha::operator++(){

    diaRelativo++;

    return *this;

}

fecha fecha::operator++(int){

    fecha antes = *this;

    this->diaRelativo++;

    return antes;
}

ostream & operator<<(ostream&sal,const fecha& obj){

    int d,m,a;

    obj.getDMA(d,m,a);

    sal<<d<<'/'<<m<<'/'<<a;

    return sal;
}

istream &operator>>(istream&ent,fecha&f){

    int d,m,a;
    char c;

    ent>>d>>c>>m>>c>>a; //c levanta caracteres

    //f.setDMA(d,m,a); si se implementa, no s eusaria friend en el header

    int dif = a-1601;

    f.diaRelativo = dif*365 + dif/4 - dif/100 + dif/400 + fecha::diaJuliano(d,m,a);

    return ent;
}
void fecha::getDMA(int&d,int&m,int&a) const {

    int difAnios = diaRelativo/365;

    long diaRelCalculado = difAnios*365 + difAnios/4 - difAnios/100+difAnios/400;

    while(diaRelCalculado >= diaRelativo){

        difAnios--;

        diaRelCalculado = difAnios*365 + difAnios/4 - difAnios/100+difAnios/400;
    }

    a = difAnios +1601;

    julianoaGregoriano(diaRelativo - diaRelCalculado,a,d,m);
}

void fecha::julianoaGregoriano(int diajul,int a,int&d,int&m){

    int dias_mes[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int dias=0,i=0;

    m=0;
    d=0;

    if(a%400 == 0 || (a%4 == 0 && a%100 !=0)){ //bisiesto

        dias_mes[1]=29;
    }

    while(diajul > dias_mes[i]){
        m++;

        diajul-=dias_mes[i];

        i++;
    }

    m= m+1;

    d = diajul;
}
