#ifndef COLA_CIRCULAR_ESTATICA_H_INCLUDED
#define COLA_CIRCULAR_ESTATICA_H_INCLUDED

typedef struct{

    int num;
}t_info;

typedef struct{

    int tam;
    t_info vec[5];
    int cantElem;
    int primElem;
    int ultElem;
}t_cola;

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

#endif // COLA_CIRCULAR_ESTATICA_H_INCLUDED
