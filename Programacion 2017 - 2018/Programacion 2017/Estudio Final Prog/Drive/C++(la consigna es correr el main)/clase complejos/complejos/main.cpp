#include"complejos.h"

using namespace std;

int main()
{
    Complejo c0;
    Complejo c1;
    Complejo c2(1, 2);
    Complejo c3(3, 4);

    cout << "Valores iniciales:" << endl;
    cout << "c0 = " << c0 << endl << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl << "c3 = " << c3 << endl;
    c0 = 5 * c3;
    c1 = c2 * c3;
    cout << "Valores finales:" << endl ;
    cout << "c0 = " << c0 << endl << "c1 = " << c1 << endl;
    return 0;
}

