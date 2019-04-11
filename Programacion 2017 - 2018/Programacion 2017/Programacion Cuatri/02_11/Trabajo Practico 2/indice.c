#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "indice.h"
#include "def.h"

///Crea la lista y el iterador.
void ind_crear(T_indice *pi)
{
    crear_lista(&(pi->l));
    //Primitivas para el iterador.
    //pi->piterador = NULL;
}


///inserta en la lista en orden según el dni
//Devuelve 0 si la operacion es exitosa.
int ind_insertar(T_indice *pi, const t_reg_indice *reg)
{
    //Se inserta el DNI en la lista de forma ordenada.
    int resultado = agregar_ordenado(pi->pl, reg, cmp);
    //Se establece el ini del Iterador en base al primer nodo de la lista.
    pi->piterador->ini = pi->pl;
    return resultado;
}
