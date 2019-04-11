#ifndef INDICE_H_INCLUDED
#define INDICE_H_INCLUDED

#include "lista.h"
#include "reg_ind.h"

typedef struct
{
    T_lista l;
    T_iterador ite;
} T_indice;

void ind_crear(T_indice *pi);

int ind_insertar(T_indice *pi, const t_reg_indice *reg);

int ind_eliminar(T_indice *pi, t_reg_indice *reg);

int ind_buscar(T_indice *pi, t_reg_indice *reg);

int ind_cargar(T_indice *pi, const char* path);

int ind_grabar(T_indice *pi, const char* path);

void ind_vaciar(T_indice *pi);

///FUNCION ADICIONAL PARA LEER SI EL INDICE FUE GENERADO CORRECTAMENTE.
void ind_leer_archivo(const char* path);

int ind_primero(T_indice *pi, t_reg_indice *reg);

int ind_siguiente(T_indice *pi, t_reg_indice *reg);

int ind_fin(T_indice *pi);

int ind_nro(T_indice *pi);

void mostrar_indice(T_indice *pi);

#endif // INDICE_H_INCLUDED
