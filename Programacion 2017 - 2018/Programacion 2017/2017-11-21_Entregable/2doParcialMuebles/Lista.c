#include <ListaD.h>
#include "stdlib.h"


int lista_sacar_primero(t_lista* pl, t_dato_lista* pd)
{

    if(!*pl)
    {
        return 0; //LISTA VACIA.
    }
    ///VOY AL PRINCIPIO.
    while((*pl) && (*pl)->pant)
    {
        pl = &(*pl)->pant;
    }
    *pd = (*pl)->info;
    ///SI LA LISTA TIENE MAS DE UN ELEMENTO.
    if((*pl)->psig)
    {
        pl = &(*pl)->psig; // LA LISTA QUEDA APUNTANDO AL NUEVO PRIMERO.
        //(*pl)->pant = NULL; // ELIMINO LA REFERENCIA DEL ANTERIOR.
        //free((*pl)->pant); //ELIMINO EL ANTERIOR(EL PRIMERO).
    }
    ///SI LA LISTA TIENE SOLO UN ELEMENTO.
    else
    {
        free(*pl);
        *pl = NULL;
    }
    return 1;
}
