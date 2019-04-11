#include <iostream>
#include "header.h"


using namespace std;

int main()
{
    //cout << "Hello world!" << endl;

    fecha f;
    fecha f2(6,11,2017);

    cout<<"dias relativos f: "<<f<<endl;

    cout<<"dias relativos f2: "<<f2<<endl;

    f2.sumar_dias(30);

    cout<<"dias relativos f2 dsp de f2.sumar_dias(30);: "<<f2<<endl;

    f2+=30;

    cout<<"dias relativos f2 dsp de f2+=30;;: "<<f2<<endl;

    f2.operator+=(30);

    cout<<"dias relativos f2 dsp de f2.operator+=(30);: "<<f2<<endl;

    int dif = f2-f;

    cout<<"la dif = f2-f es: "<<dif<<endl;

    dif = f2.operator-(f);

    cout<<"la dif = f2.operator-(f); es: "<<dif<<endl;

    ///---------------clase 9/11/2017--------------

    fecha fhoy(9,11,2017);

    fecha fManiana = fhoy++; ///postincremento, da 9/11
    fecha fPasado = ++fhoy; ///preincremento da 11/11

    cout<<"-hoy es: "<<fhoy;
    cout<<" maniana sera "<<(++fhoy);
    cout<<" y pasado "<<(++fhoy)<<endl;

    cout<<"ingrese fecha(d/m/a) "<<endl;

    fecha fingreso;

    cin>>fingreso;
    cin.ignore(1); //fflush de c++

    cin>>fhoy;
    cin.ignore(1); //fflush de c++

    cout<<"se ingreso: "<<fingreso<< " y " << fhoy << endl;


    return 0;
}
