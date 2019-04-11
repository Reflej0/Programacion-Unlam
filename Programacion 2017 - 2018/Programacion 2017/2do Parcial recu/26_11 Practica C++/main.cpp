#include <iostream>
#include "prueba.h"

using namespace std;

int main()
{
    int numero = 5;
    Prueba number(9);
    int numero2 = numero + number;
    //int numero2 = number + numero;
    cout << numero2 << endl;
    return 0;
}
