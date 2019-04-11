#ifndef COLA_CIRCULAR_DINAMICA_H_INCLUDED
#define COLA_CIRCULAR_DINAMICA_H_INCLUDED

typedef struct{
    int num;
}t_info;

typedef struct s_nodo{

    t_info info;
    struct s_nodo*sig;
}t_nodo;

typedef t_nodo* t_cola;

void crear_cola(t_cola*cola);

void recorrer_cola_est(t_cola*cola);

void acolar(t_cola*cola,t_info*inf);

int desacolar(t_cola*cola,t_info*inf);

void ver_principio(t_cola*cola);

void cola_llena(t_cola*cola);

void cola_vacia(t_cola*cola);

void vaciar(t_cola*cola);

///--------------otros

void ingresar_dato(t_info*inf);

#endif // COLA_CIRCULAR_DINAMICA_H_INCLUDED
