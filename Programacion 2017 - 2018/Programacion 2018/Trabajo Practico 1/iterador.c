#include <stdio.h>
#include <stdlib.h>
#include "iterador.h"

void crear_iterador(T_iterador* pit)
{
    pit->act = NULL;
    pit->ini = NULL;
    pit->fin = 0;
}

void eliminar_iterador(T_iterador* pit)
{
    pit->act = NULL;
    pit->ini = NULL;
    pit->fin = 0;
}
///Seteo el registro inicial.
void set_nodo_inicial(T_iterador* pit, T_nodo *ini)
{
    pit->ini = ini;
}

///Seteo el registro actual.
void set_nodo_actual(T_iterador* pit, T_nodo *act)
{
    pit->act = act;
}

unsigned esFinal(T_iterador* pit)
{
    return pit->fin;
}

///Obtengo el registro inicial, y seteo el iterador al comienzo.
int get_reg_inicial(T_iterador* pit, t_reg_indice *ini)
{
    if(pit->ini) // SI HAY INICIAL.
    {
        *ini = pit->ini->dato; // Devuelvo el registro inicial.
        pit->act = pit->ini; // Seteo el actual en inicial.
        pit->fin = 0;
        return 1; // TIENE INICIAL.
    }
    pit->fin = 1; // SI NO TIENE INICIAL, ESTOY EN EL FINAL.
    ini = NULL;
    return 0; // NO TIENE INICIAL.
}

///Obtengo el registro actual.
int get_reg_actual(const T_iterador* pit, t_reg_indice *act)
{
    if(pit->act)
    {
        *act = pit->act->dato;
        return 1; // TIENE ACTUAL.
    }
    return 0; // NO TIENE ACTUAL.
}

///Obtengo el registro siguiente al actual y avanzo el actual.
int get_reg_siguiente(T_iterador* pit, t_reg_indice *sig)
{
    if(pit->act->siguiente) // SI HAY SIGUIENTE DEL ACTUAL.
    {
        *sig = pit->act->siguiente->dato; // Devuelvo el siguiente.
        pit->act = pit->act->siguiente; // Ahora cambia el actual.
        pit->fin = 0; //SI TIENE SIGUIENTE, TODAVIA NO LLEGUE AL FINAL.
        return 1; // TIENE SIGUIENTE.
    }
    sig = NULL;
    pit->fin = 1; // SI NO TIENE SIGUIENTE, LLEGUE AL FINAL.
    return 0; // NO TIENE SIGUIENTE.
}
