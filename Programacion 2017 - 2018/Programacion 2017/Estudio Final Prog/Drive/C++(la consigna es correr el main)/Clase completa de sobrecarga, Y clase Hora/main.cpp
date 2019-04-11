#include "Hora.h"

#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()///PUEDE NO HABER CONSTRUCTOR POR COPIA O POR DEFECTO, LO HACE EL COMPILADOR///
{
     Hora h1,
          h2(13,58,49),
          h3;

    /*h1=h2;
    h3=h1+10;// A LA IZQUIERDA DEL OPERADOR ES EL OBJETO LLAMADOR, A LA DERECHA EL PARAMETRO
    //h3=h1.operator+(10);
    h1-h2;
    h2-h1;
    h1+=h2+=h3;*/
    //h1=h2++;//Pos incremento
    //h1=++h2;//Pre incremento
    (++h2).imprimir();
    h2.imprimir();

    if(h1<h3)
        cout<<"h1:"<<h1<<"<"<<"h3:"<<h3<<endl;

    cout<<h1;
    h2=10+h1;

    return 0;
}


    /*if(!h1.esHoraValida(10,16,58))
        return 0;

    cout<<"HORA VALIDA"<<'\n'<<'\n';
    h1.sumarSeg(100);
    h2.imprimir();*/
