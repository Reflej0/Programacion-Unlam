#ifndef INDICE_H_INCLUDED
#define INDICE_H_INCLUDED

#include "lista.h"
#include "reg_ind.h"


typedef struct
{
    T_lista *pl;
} T_indice;

void ind_crear(T_indice *pi);

int ind_insertar(T_indice *pi, const t_reg_indice *reg);

int ind_eliminar(T_indice *pi, t_reg_indice *reg);

int ind_buscar(const T_indice *pi, t_reg_indice *reg);

int ind_cargar(T_indice *pi, const char* path);

int ind_grabar(const T_indice *pi, const char* path);

void ind_vaciar(T_indice *pi);

int ind_primero(T_indice *pi, t_reg_indice *reg);

int ind_siguiente(T_indice *pi, t_reg_indice *reg);

int ind_fin(const T_indice *pi);

#endif // INDICE_H_INCLUDED
