#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

typedef struct
{
    struct elemento *proximo;
    char *nombre;
} elemento;

void agregar(elemento *_elemento);

elemento* extraer();

#endif // COLA_H_INCLUDED
