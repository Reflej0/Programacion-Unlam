#include <stdlib.h>
#include <string.h>
#include "pila.h"

void intercambio_gen(void* a, void* b, size_t l)
{
    void* aux = malloc(l);
    memcpy(aux, a, l);
    memcpy(a, b, l);
    memcpy(b, aux, l);
    free(aux);
}

void crear_pila(T_pila* p)
{
    p->tope = -1;
}

int apilar(T_pila* p, const T_dato *d)
{
    if(p->tope == TAM-1)
        return FALSO; // PILA LLENA.
    p->tope++;
    int i;
    //Voy corriendo los elementos existentes hacia la derecha.
    for(i=p->tope; i>=0; i--)
        intercambio_gen(&p->v[i], &p->v[i+1], sizeof(T_dato));
    //El nuevo elemento siempre se inserta en la primera posicion.
    memcpy(&p->v[0], d, sizeof(T_dato)); //Es mas generico. Con un char[20] no se podria.
    //p->v[0] = *d;
    return 1;
}

int ver_tope(const T_pila* p, T_dato* d)
{
    if(p->tope == -1)
        return FALSO; // PILA VACIA.
    //El elemento del tope de la pila siempre esta en la primera posicion.
    memcpy(d, &p->v[0], sizeof(T_dato)); //Es mas generico. Con un char[20] no se podria.
    //*d = p->v[0];
    return VERDADERO;
}

int desapilar(T_pila* p, T_dato *d)
{
    if(p->tope == -1)
        return FALSO; // PILA VACIA.
    memcpy(d, &p->v[0], sizeof(T_dato)); //Es mas generico. Con un char[20] no se podria.
    //*d = p->v[0];
    int i;
    //Voy corriendo los elementos hacia la izquierda.
    for(i=0; i<p->tope; i++)
        memcpy(&p->v[i], &p->v[i+1], sizeof(T_dato));
    //Decremento el tope.
    p->tope--;
    return VERDADERO;
}

int pila_llena(const T_pila* p)
{
    if(p->tope == TAM-1)
        return VERDADERO; // PILA LLENA.
    return FALSO;
}

int pila_vacia(const T_pila* p)
{
    if(p->tope == -1)
        return VERDADERO; // PILA VACIA.
    return FALSO;
}

void vaciar_pila(T_pila* p)
{
    p->tope = -1;
}
