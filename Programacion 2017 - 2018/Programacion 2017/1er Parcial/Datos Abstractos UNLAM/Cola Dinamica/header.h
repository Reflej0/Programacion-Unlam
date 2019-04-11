#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct{
    int num;
}t_info;

typedef struct s_nodo{

    t_info info;

    struct s_nodo* sig;
}t_nodo;

typedef struct{

    t_nodo*pri;

    t_nodo*ult;

}t_cola;

void crearCola(t_cola*c);
int colaVacia(t_cola*c);
int colaLlena(t_cola*c);
int acolar(t_cola*c);
int desacolar(t_cola*c,t_info*inf);
int verPrimero(t_cola*c);
void vaciarCola(t_cola*c);


#endif // HEADER_H_INCLUDED
