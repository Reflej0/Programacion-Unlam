#include <iostream>


#include "racional.h"

using namespace std;

void calcular(int nUno, int nDos, int nTre, int nCua, int nCin);


int main()
{
   calcular(6936, -1200, 1200, -6936, 7);
   calcular(6936, 0, 1200, 0, 7);
    return 0;
}


void calcular(int nUno, int nDos, int nTre, int nCua, int nCin)
{
   Racional r0,
            r1,
            r2(nUno, nDos),
            r3(nTre, nCua);

   cout << "Valores iniciales:" << endl
        << "r0 = " << r0 << endl << "r1 = " << r1 << endl
        << "r2 = " << r2 << endl << "r3 = " << r3 << endl;

   r0 = nCin + r3;
   r1 = r2 + r3;

   cout << "Valores finales:" << endl
        << "r0 = " << r0 << endl << "r1 = " << r1 << endl << endl;
}

