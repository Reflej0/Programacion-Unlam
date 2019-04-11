#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct{

    int num;
}t_info;

typedef struct s_nodo{

    t_info info;
    struct s_nodo* sig;


}t_nodo;

typedef t_nodo* t_lista;

void crearLista(t_lista*p);

void vaciar(t_lista*p);
int pilallena(t_lista*p);
int pilaVacia(t_lista*p);
int apilar(t_lista*p,t_info*d);
int recorrerPila(t_lista*p);
int desapilar(t_lista*p,t_info*d);
int verTope(t_lista*p);



#endif // HEADER_H_INCLUDED
