#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#define TAM 5

typedef struct{

    int numero;
}t_dato;

typedef struct{

    t_dato vec[TAM];

    int cantElem;
    int pri;
    int ult;
}t_cola;

void entrada_dato(t_dato*d);
void mostrar_dato(t_dato*d);


//---- primitivas cola --------

void crear_cola(t_cola*pc);

int poner_en_cola(t_cola*pc,t_dato*d);

int sacar_de_cola(t_cola*pc,t_dato*d);

int ver_frente_cola(t_cola*pc,t_dato*d);

void vaciar_cola(t_cola*pc);

int cola_vacia(const t_cola*pc);

int cola_llena(const t_cola*pc);

//---------------

void debug_datos_cola(t_cola*pc);

#endif // HEADER_H_INCLUDED
