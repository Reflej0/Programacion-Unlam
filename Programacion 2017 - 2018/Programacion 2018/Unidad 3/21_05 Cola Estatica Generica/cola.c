#include <stdlib.h>
#include <string.h>
#include "cola.h"

void crear_cola(T_cola* c)
{
    c->pri = 0;
    c->ult = -1;
}

int acolar(T_cola* c, const T_dato* d)
{
    if((c->pri == c->ult-1) && c->ult != -1)
        return FALSO; //COLA LLENA.
    c->ult = (c->ult+1) % TAM_COLA;
    memcpy(&c->cola[c->ult], d, sizeof(T_dato)); // c->cola[c->ult] = *d;
    return VERDADERO;
}

int desacolar(T_cola* c, T_dato* d)
{
    if(c->ult == -1)
        return FALSO; // COLA VACIA.
    memcpy(d, &c->cola[c->pri], sizeof(T_dato)); // *d = c->cola[c->pri]
    c->pri = (c->pri+1) % TAM_COLA;
    if(c->pri == c->ult-1) // Cada vez que desacolo tengo que preguntar si es el ultimo.
    {
        c->pri = 0;
        c->ult = -1;
    }
    return VERDADERO;
}

int ver_frente(const T_cola* c, T_dato* d)
{
    if(c->ult == -1)
        return FALSO; // COLA VACIA.
    memcpy(d, &c->cola[c->pri], sizeof(T_dato));
    return VERDADERO;
}

void vaciar_cola(T_cola* c) // Establezco las condiciones iniciales.
{
    c->pri = 0;
    c->ult = -1;
}

int cola_llena(const T_cola* c)
{
    return (c->pri == c->ult-1) && c->ult != -1;
}

int cola_vacia(const T_cola* c)
{
    return (c->ult == -1);
}
