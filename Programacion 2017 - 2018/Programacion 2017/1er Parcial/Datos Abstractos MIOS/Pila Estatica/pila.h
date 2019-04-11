#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#define TAM 10

typedef struct
{
    int dni;
    char* nombre;
} T_alumno;

typedef struct
{
    T_alumno alumnos[TAM];
    int tope;
} T_pila;

void crear_pila(T_pila* pila);

void vaciar_pila(T_pila* pila);

int apilar(T_pila* pila, const T_alumno* alumno);

int desapilar(T_pila* pila, T_alumno* alumno);

int ver_tope(T_pila* pila, T_alumno* alumno);

int pila_llena(T_pila* pila);

int pila_vacia(T_pila* pila);

#endif // PILA_H_INCLUDED
