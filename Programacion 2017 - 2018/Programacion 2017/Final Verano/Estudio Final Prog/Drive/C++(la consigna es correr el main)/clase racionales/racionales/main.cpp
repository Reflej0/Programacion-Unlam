#include "racionales.h"


int main()
{
    Racional r1;
    Racional r2(147,700);
    Racional r3(8,4);
    Racional r4;
    Racional r5;
    Racional r6;

    r4=r2+r3;
    r5=r2*r3;
    r6=r2/r3;

    r2.mostrar();
    r3.mostrar();
    r4.mostrar();
    r5.mostrar();
    r6.mostrar();

    return 0;
}
