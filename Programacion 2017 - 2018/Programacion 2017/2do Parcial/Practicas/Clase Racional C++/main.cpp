#include <iostream>
#include <stdlib.h>
#include "racional.h"

using namespace std;

int main()
{
    ///PRIMER NUMERO.
    cout << "Ingrese un numero decimal:";
    float numero;
    cin >> numero;
    ///SEGUNDO NUMERO.
    Racional num_racional = Racional(numero);
    cout << "Ingrese un numero decimal:";
    cin >> numero;
    Racional num_racional2 = Racional(numero);

    ///GETTERS.
    unsigned numerador = num_racional.getNumerador();
    unsigned denominador = num_racional.getDenominador();
    int signo = num_racional.getSigno();

    ///VERIFICACION DE GETTERS.
    cout << "El numerador es:" << numerador;
    cout << "\n";
    cout << "El denominador es:" << denominador;
    cout << "\n";
    cout << "Signo:" << signo;
    cout << "\n";

    ///VERIFICANDO+=
    /*num_racional+=num_racional2;
    numerador = num_racional.getNumerador();
    denominador = num_racional.getDenominador();
    cout << "El numerador es:" << numerador;
    cout << "\n";
    cout << "El denominador es:" << denominador;
    cout << "\n";*/

    ///VERIFICANDO-=
    /*num_racional+=num_racional2;
    numerador = num_racional.getNumerador();
    denominador = num_racional.getDenominador();
    cout << "El numerador es:" << numerador;
    cout << "\n";
    cout << "El denominador es:" << denominador;
    cout << "\n"*/;

    ///VERIFICANDO *=
    /*num_racional*=num_racional2;
    numerador = num_racional.getNumerador();
    denominador = num_racional.getDenominador();
    signo = num_racional.getSigno();
    cout << "El numerador es:" << numerador;
    cout << "\n";
    cout << "El denominador es:" << denominador;
    cout << "\n";
    cout << "Signo:" << signo;
    cout << "\n";*/

    ///VERIFICANDO /=
    /*num_racional/=num_racional2;
    numerador = num_racional.getNumerador();
    denominador = num_racional.getDenominador();
    signo = num_racional.getSigno();
    cout << "El numerador es:" << numerador;
    cout << "\n";
    cout << "El denominador es:" << denominador;
    cout << "\n";
    cout << "Signo:" << signo;
    cout << "\n";*/

    return 0;
}
