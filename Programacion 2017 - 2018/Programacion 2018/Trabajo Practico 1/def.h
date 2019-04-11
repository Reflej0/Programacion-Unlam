#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED

#include "reg_ind.h"

///UBICADO ACA PARA QUE NO ENTRE EN CONFLICTO CON LISTA.H - INDICE.H o ITERADOR.H

typedef t_reg_indice T_dato;

typedef struct S_nodo
{
    struct S_nodo* siguiente;
    T_dato dato;
} T_nodo;

#endif // DEF_H_INCLUDED
