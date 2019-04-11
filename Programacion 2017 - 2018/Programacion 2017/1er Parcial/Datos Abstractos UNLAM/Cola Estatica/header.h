#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#define TAM 5

typedef struct{
    int num;
}t_info;

typedef struct{
    t_info info[TAM];
    int pri;
    int ult;
}t_cola;

void crearCola(t_cola*c);
int colaVacia(t_cola*c);
int colaLlena(t_cola*c);
int acolar(t_cola*c);
int desacolar(t_cola*c,t_info*inf);
int verPrimero(t_cola*c);
void vaciarCola(t_cola*c);


#endif // HEADER_H_INCLUDED
