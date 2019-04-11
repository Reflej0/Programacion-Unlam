#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#define TAM 5

typedef struct{

    int num;
}t_info;

typedef struct{

    t_info info[TAM];
    int tope;

}t_pila;

void crearPila(t_pila*);
void vaciarPila(t_pila*);
int pilaLlena(t_pila*,int tam);
int pilaVacia(t_pila*);
void apilar(t_pila*,int tam);
int desapilar(t_pila*,t_info*,int tam);
void vertope(t_pila*,int tam);

#endif // HEADER_H_INCLUDED
