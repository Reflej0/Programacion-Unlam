#include <iostream>
#include "cadenas.h"

using namespace std;

int main()
{
    Cadena c1("Hola");
    Cadena c2("que");
    Cadena c3("tal");
    Cadena c5("Final");
    Cadena c4= c1+','+c2+' '+c3+'?';
    c4+=c5;
    cout<<c4<<endl;
    return 0;
}
