
#include "main.h"
using namespace std;

int main()
{
    cout << "Una prueba" << endl;
    probarHora(10, 20, 30, -30000);
    cout << "Otra prueba" << endl;
    probarHora(-10, -20, -30, 300000);
    cout << "Prueba Final" << endl;
    probarHora(10, 200, -300, 0);
    return 0;
}

void probarHora(int hh, int mm, int ss, long segundos)
{
    Hora    h1(hh, mm, ss),
            h2(segundos),
            h3(h1 * 3),
            h4(3 * h3),
            h5;

    cout << "h1 = " << h1 << endl <<
            "h2 = " << h2 << endl <<
            "h3 = " << h3 << endl <<
            "h4 = " << h4 << endl <<
            "h5 = " << h5 << endl << endl;
    h5 = h2 -= h3 += h4 -= ss;
    cout << "h1 - h2 = " << h1 - h2 << endl <<
            "h1 = " << h1 << endl <<
            "h2 = " << h2 << endl <<
            "h3 = " << h3 << endl <<
            "h4 = " << h4 << endl <<
            "h5 = " << h5 << endl << endl;
}

