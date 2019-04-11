#include <iostream>
#include "fecha.h"

using namespace std;

int main()
{
    Fecha fecha_teclado;
    cout << "Introduzca la fecha:";
    cin >> fecha_teclado;
    fecha_teclado += 1;
    cout << "Fecha introducida:" << fecha_teclado;
    return 0;
}
