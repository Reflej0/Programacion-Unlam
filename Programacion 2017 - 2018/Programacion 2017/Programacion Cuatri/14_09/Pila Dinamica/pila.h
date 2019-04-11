#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

typedef struct
{
    int numero;
} T_dato;

typedef struct
{
    T_dato *v_pila;
    T_dato *tope;
    size_t capacidad;
} T_pila;

void crear_pila(T_pila *p);
int poner_en_pila(T_pila *p, const T_dato *d);
int sacar_de_pila(T_pila *p, T_dato *d);
int pila_vacia(const T_pila *p);
int pila_llena(const T_pila *p);
int ver_tope_de_pila(const T_pila *p, T_dato *d);
void vaciar_pila(T_pila *p);

#endif // PILA_H_INCLUDED
