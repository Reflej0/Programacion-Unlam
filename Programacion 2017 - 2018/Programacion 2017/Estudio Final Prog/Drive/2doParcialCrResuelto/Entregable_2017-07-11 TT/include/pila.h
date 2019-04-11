#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include<arbol.h>
typedef t_nodo_arbol * t_info_pila;

typedef struct s_nodo{
    t_info_pila info;
    struct s_nodo * psig;
}t_nodo;

typedef t_nodo * t_pila;

void crear_pila(t_pila * ppila);
int pila_llena(const t_pila * ppila);
int pila_vacia(const t_pila * ppila);
int poner_en_pila(t_pila * ppila, const t_info_pila * pinfo);
int sacar_de_pila(t_pila * ppila, t_info_pila * pinfo);
int tope_de_pila(const t_pila * ppila, t_info_pila * pinfo);
void vaciar_pila(t_pila * ppila);

void crear_pila_res(t_pila * ppila);
int pila_llena_res(const t_pila * ppila);
int pila_vacia_res(const t_pila * ppila);
int poner_en_pila_res(t_pila * ppila, const t_info_pila * pinfo);
int sacar_de_pila_res(t_pila * ppila, t_info_pila * pinfo);
int tope_de_pila_res(const t_pila * ppila, t_info_pila * pinfo);
void vaciar_pila_res(t_pila * ppila);

#endif // PILA_H_INCLUDED
