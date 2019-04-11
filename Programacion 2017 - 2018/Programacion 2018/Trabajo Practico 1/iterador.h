#ifndef ITERADOR_H_INCLUDED
#define ITERADOR_H_INCLUDED

#include "def.h"

///EL ITERADOR ME SIRVE PARA RECORRER EL INDICE, ES EL INTERMEDIARIO ENTRE LISTA E INDICE.

typedef struct
{
    //Si es solo para recorrer solo puntero simple.
    T_nodo* ini;
    T_nodo* act;
    //Cuando actual es nulo, no se me da el fin y proceso lo que obtuve de siguiente.
    unsigned fin;
} T_iterador;

void crear_iterador(T_iterador* pit);

void eliminar_iterador(T_iterador* pit);

void set_nodo_inicial(T_iterador* pit, T_nodo *ini);

void set_nodo_actual(T_iterador* pit, T_nodo *act);

unsigned esFinal(T_iterador* pit);

void set_fin(T_iterador* pit);

int get_reg_inicial(T_iterador* pit, t_reg_indice *ini);

int get_reg_siguiente(T_iterador* pit, t_reg_indice *sig);

#endif // ITERADOR_H_INCLUDED
