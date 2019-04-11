#include <iostream>
#include "punto.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;


    Punto p1(2,5);
    Punto p2;
    Punto p3(p1);
    Punto p4(1,2);


    cout<<"p1: ";p1.mostrarCoordenadas();
    cout<<"p2: ";p2.mostrarCoordenadas();
    cout<<"p3: ";p3.mostrarCoordenadas();

    p2 = p1;
    cout<<"p2 = p1; p2:";p2.mostrarCoordenadas();

    p2+=p1;

    cout<<"p2+=p1; p2:";p2.mostrarCoordenadas();

    p2-=p1;

    cout<<"p2-=p1; p2:";p2.mostrarCoordenadas();

    p2/=p1;

    cout<<"p2/=p1; p2:";p2.mostrarCoordenadas();

    p2*=p1;

    cout<<"p2*=p1; p2:";p2.mostrarCoordenadas();

    p2%=p4;

    cout<<"p4: ";p4.mostrarCoordenadas();
    cout<<"p2%=p4; p2:";p2.mostrarCoordenadas();

    cout<<"p1: ";p1.mostrarCoordenadas();
    cout<<"p2: ";p2.mostrarCoordenadas();


    if(p1==p2){
        cout<<"p1 es igual a p2"<<endl;
    }else{
        cout<<"p1 no es igual a p2"<<endl;
    }

    Punto p5(p1);
    cout<<"p5: ";p5.mostrarCoordenadas();

    if(p1==p5){
        cout<<"p1 es igual a p5"<<endl;
    }else{
        cout<<"p1 no es igual a p5"<<endl;
    }

    cout<<"p1+p5:"<<p1+p5<<endl;
    Punto p6 = p1+p5;
    cout<<"p6 = p1+p5; p6: ";p6.mostrarCoordenadas();
    Punto p7 = p1-p5;
    cout<<"p7 = p1-p5; p7: ";p7.mostrarCoordenadas();

    cout<<"p1: ";p1.mostrarCoordenadas();
    Punto p8 = 3 + p1;
    cout<<"p8 = 3 + p1;; p8: ";p8.mostrarCoordenadas();

    Punto p11 = p1 = p2;
    cout<<"p11 = p1 = p2; p11: "<<p11<<" p1: "<<p1<<" p2: "<<p2<<endl;

    Punto p9;

    cin>>p9;

    cout<<"Ingresado: "<<p9<<endl;

    return 0;
}
