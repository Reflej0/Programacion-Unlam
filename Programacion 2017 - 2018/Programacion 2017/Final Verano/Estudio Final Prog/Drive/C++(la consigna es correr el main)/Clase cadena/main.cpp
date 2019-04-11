
#include "main.h"


int main()
{
    char    cad[] = { "Una cadena cualquiera" };

    Cadena  c1,
            c2("Hola"),
            c3(cad);

    c1 = c2;

    Cadena c4;
    c4 = cad;

    c4 += c2;
    int num = 1234;
    c4 += num;

    cout << "c1 " << c1 << endl <<
            "c2 " << c2 << endl <<
            "c3 " << c3 << endl <<
            "c4 " << c4 << endl;

    c1 = c2 + c3;

    c3 = Cadena::aCadena("Que tal");
    return 0;
}

