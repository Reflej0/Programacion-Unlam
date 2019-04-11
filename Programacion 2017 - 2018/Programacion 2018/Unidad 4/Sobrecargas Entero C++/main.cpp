#include <iostream>
#include "entero.h"

using namespace std;

int main()
{
    Entero n1;
    Entero n2 = 5;
    Entero n3 = 0;
    cin >> n1;
    cout << "El numero ingresado con respecto a 0: ";
    if(n1 == n3)
        cout << "Igual";
    else if(n1 < n3)
        cout << "Menor";
    else if(n1 > n3)
        cout << "Mayor";
    cout << "\nNumero ingresado * -1:" <<-n1;
    cout << "\n" << n1 << n2 <<"=" << n1+n2; //objeto + objeto.
    cout << "\n" << -10 << n1 <<"=" << -10+n1; //primitivo + objeto.
    cout << "\n" << n1 << "+" << 8  << "=" << n1+8; // objeto + primitivo.
    return 0;
}
