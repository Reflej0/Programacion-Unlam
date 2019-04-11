#include <iostream>
#include "Complejos.h"

using namespace std;

int main()
{
    Complejos c0;
    Complejos c1;
    Complejos c2(1, 2);
    Complejos c3(3, 4);

    cout << "Valores iniciales:" << endl;
    cout << "c0 = " << c0 << endl << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl << "c3 = " << c3 << endl;
    c0 = 5 * c3;
    cout<<"c0 = 5 * c3: "<<c0<<endl;
    c1 = c2 * c3;
    cout<<"c1 = c2 * c3:  "<<c1<<endl;
    c0 = c2 + c3;
    cout<<"c0 = c2 + c3:  "<<c0<<endl;
    c0 = c2 - c3;
    cout<<"c0 = c2 - c3:  "<<c0<<endl;
    c0 = c2 / c3;
    cout<<"c0 = c2 / c3:  "<<c0<<endl;

    /*Salida:

    Valores iniciales:
    c0 = R: 0 I: 0

    c1 = R: 0 I: 0

    c2 = R: 1 I: 2

    c3 = R: 3 I: 4

    c0 = 5 * c3: R: 15 I: 20

    c1 = c2 * c3:  R: -5 I: 10

    c0 = c2 + c3:  R: 4 I: 6

    c0 = c2 - c3:  R: -2 I: -2

    c0 = c2 / c3:  R: 0.44 I: 0.08
    */
    return 0;
}
