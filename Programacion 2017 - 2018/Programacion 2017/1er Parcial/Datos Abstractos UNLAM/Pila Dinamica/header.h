#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct{

    int num;
}t_info;

typedef struct s_nodo{

    t_info info;
    struct s_nodo* siguiente;
}t_nodo;

typedef t_nodo* t_pila;

void crearPila(t_pila*p);
int vaciarPila(t_pila*p);
int pilaLlena(t_pila*p);
int pilaVacia(t_pila*p);
int apilar(t_pila*p,t_info*d);
int desapilar(t_pila*p,t_info*inf);
int vertope(t_pila*p);

#endif // HEADER_H_INCLUDED
