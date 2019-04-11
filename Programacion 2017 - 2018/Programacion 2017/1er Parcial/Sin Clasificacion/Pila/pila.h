#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

typedef struct
{
    struct elemento* siguiente;
    char *nombre;

} elemento;

void agregar(elemento* _elemento);

elemento* extraer();

#endif // PILA_H_INCLUDED
