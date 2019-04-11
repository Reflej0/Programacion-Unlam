#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void crear_pila(T_pila* pila)
{
    pila->tope = -1;
}

void vaciar_pila(T_pila* pila)
{
    pila->tope = -1;
}

int apilar(T_pila* pila, const T_alumno* alumno)
{
    if(pila->tope == TAM)
    {
        return 1; //PILA LLENA
    }
    pila->tope++;
    pila->alumnos[pila->tope] = *alumno;
    return 0; // EXITO.
}

int desapilar(T_pila* pila, T_alumno* alumno)
{
    if(pila->tope == 0)
    {
        return 1; //PILA VACIA.
    }
    *alumno = pila->alumnos[pila->tope];
    pila->tope--;
    return 0; // EXITO.
}

int ver_tope(T_pila* pila, T_alumno* alumno)
{
    if(pila->tope == -1)
    {
        return 1; //PILA VACIA.
    }
    *alumno = pila->alumnos[pila->tope];
    return 0; // EXITO.
}

int pila_llena(T_pila* pila)
{
    if(pila->tope == TAM)
    {
        return 1; // PILA LLENA.
    }
    return 0; // PILA CON ESPACIO.
}

int pila_vacia(T_pila* pila)
{
    if(pila->tope == -1)
    {
        return 1; // PILA VACIA.
    }
    return 0; // PILA CON ESPACIO.
}
