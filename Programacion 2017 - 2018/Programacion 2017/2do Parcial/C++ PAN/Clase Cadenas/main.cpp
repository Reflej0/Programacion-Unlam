#include <iostream>
#include "Cadenas.h"

using namespace std;

int main()
{
    ///13/11/2017
    Cadena c1("Hola");
    Cadena c2("que");
    Cadena c3("tal");
    Cadena c4= c1+","+c2+" "+c3+"?";
    cout<<c4<<endl;

    return 0;
}
