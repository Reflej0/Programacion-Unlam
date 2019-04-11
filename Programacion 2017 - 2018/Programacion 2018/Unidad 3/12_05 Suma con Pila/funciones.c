#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funciones.h"
#include "pila.h"

void cargar_primer_operando_archivo_en_pila(T_pila* p, FILE* arch)
{
    T_dato c;
    while((c = fgetc(arch))!='\n') apilar(p, &c); // Se tiene que estar seguro que exista un \n en el txt de lo contrario da error.
}

void cargar_segundo_operando_archivo_en_pila(T_pila* p, FILE* arch)
{
    T_dato c;
    while((c = fgetc(arch))!=EOF) apilar(p, &c); // Se tiene que estar seguro que exista un \n en el txt de lo contrario da error.
}

void sumar_pilas(T_pila* p1, T_pila* p2, T_pila* pr)
{
    T_dato n1, n2, c;
    int acarreo = 0;
    ///Pila vacia devuelve 1 si esta vacia, entonces si ambas pilas estan vacia el resultado es 2.
    while(pila_vacia(p1)+pila_vacia(p2)<2)
    {
        if(!desapilar(p1, &n1)) n1 = '0';
        if(!desapilar(p2, &n2)) n2 = '0';
        c = (n1-'0'+n2-'0'+acarreo)%10+'0';
        apilar(pr, &c);
        if((n1-'0'+n2-'0'+acarreo) >=10) acarreo = 1;
        else acarreo = 0;
    }
    ///Tengo que preguntar al final si quedo el acarreo en 1.
    if(acarreo == 1) {c = '1'; apilar(pr, &c);}
}

void mostrar_pila(T_pila* p)
{
    char c;
    while(desapilar(p, &c)) printf("%c", c);
}
