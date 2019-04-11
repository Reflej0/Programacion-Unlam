#include <iostream>
#include "C:\2014-07-15_Entregable\include\Racional.h"
using namespace std;

int main()
{
    Racional r1, r2(2, 4), r3, r4;

    r1 = r2;

    r3 = r1 + r2;

    r4 = 2 + r3;

	cout << "r1: "<< r1 << ", r2: " << r2 << ", r3: " << r3 << ", r4: " << r4 << endl;

    return 0;
}
