#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int cmp(const void* n1, const void* n2)
{
    T_dato* num1 = (T_dato*)n1;
    T_dato* num2 = (T_dato*)n2;
    return (*num1)-(*num2);
}

void crear_lista(T_lista* pl)
{
    *pl = NULL;
}

int agregar_al_principio(T_lista* pl, T_dato* d)
{
    ///VOY AL PRINCIPIO.
    while((*pl) && (*pl)->anterior)
    {
        pl = &(*pl)->anterior;
    }
    T_nodo* nue = malloc(sizeof(T_nodo)); //FALTA COMPROBACION DE MEMORIA (QUE NO PASA NUNCA).
    nue->anterior = NULL; //EL NUEVO PRIMERO NO TIENE ANTERIOR.
    nue->info = *d;
    nue->siguiente = *pl; //EL SIGUIENTE DEL NUEVO PRIMERO ES EL ANTIGUO PRIMERO.
    ///SI LA LISTA TIENE AL MENOS UN ELEMENTO.
    if(*pl)
    {
        (*pl)->anterior = nue;
    }
    *pl = nue; //La lista queda apuntando al ultimo elemento que inserte, que en este caso es el primero.
    return 1; //VERDADERO.
}


int agregar_al_final(T_lista* pl, T_dato* d)
{
    ///VOY AL FINAL.
    while((*pl) && (*pl)->siguiente)
    {
        pl = &(*pl)->siguiente;
    }
    T_nodo* nue = malloc(sizeof(T_nodo));
    nue->siguiente = NULL; // EL NUEVO ULTIMO NO TIENE SIGUIENTE.
    nue->info = *d;
    nue->anterior = *pl; // EL ANTERIOR DEL NUEVO ULTIMO ES EL ANTIGUO ULTIMO.
    if(*pl)
    {
        (*pl)->siguiente = nue;
    }
    *pl = nue; // La lista queda apuntando al ultimo elemento que inserte, que en este caso es el ultimo.
    return 1; //VERDADERO.
}

void ver_lista_desde_principio(T_lista* pl)
{
    ///VOY AL PRINCIPIO.
    while((*pl) && (*pl)->anterior)
    {
        pl = &(*pl)->anterior;
    }
    ///RECORRO LA LISTA HASTA EL FINAL.
    while(*pl)
    {
        printf("DATO: %d", (*pl)->info);
        printf("\n");
        pl = &(*pl)->siguiente;
    }
}

void ver_lista_desde_final(T_lista* pl)
{
    ///VOY AL FINAL.
    while((*pl) && (*pl)->siguiente)
    {
        pl = &(*pl)->siguiente;
    }
    ///RECORRO LA LISTA HASTA EL PRINCIPIO.
    while(*pl)
    {
        printf("DATO: %d", (*pl)->info);
        printf("\n");
        pl = &(*pl)->anterior;
    }
}

int eliminar_primero(T_lista* pl, T_dato* d)
{
    if(!*pl)
    {
        return 0; //LISTA VACIA.
    }
    ///VOY AL PRINCIPIO.
    while((*pl) && (*pl)->anterior)
    {
        pl = &(*pl)->anterior;
    }
    ///SI LA LISTA TIENE MAS DE UN ELEMENTO.
    if((*pl)->siguiente)
    {
        pl = &(*pl)->siguiente; // LA LISTA QUEDA APUNTANDO AL NUEVO PRIMERO.
        (*pl)->anterior = NULL; // ELIMINO LA REFERENCIA DEL ANTERIOR.
        free((*pl)->anterior); //ELIMINO EL ANTERIOR(EL PRIMERO).
    }
    ///SI LA LISTA TIENE SOLO UN ELEMENTO.
    else
    {
        free(*pl);
        *pl = NULL;
    }
    return 1;
}

int eliminar_ultimo(T_lista* pl, T_dato* d)
{
    if(!*pl)
    {
        return 0; //LISTA VACIA.
    }
    ///VOY AL PRINCIPIO.
    while((*pl) && (*pl)->siguiente)
    {
        pl = &(*pl)->siguiente;
    }
    ///SI LA LISTA TIENE MAS DE UN ELEMENTO.
    if((*pl)->anterior)
    {
        pl = &(*pl)->anterior; // LA LISTA QUEDA APUNTANDO AL NUEVO ULTIMO.
        (*pl)->siguiente = NULL; // ELIMINO LA REFERENCIA DEL SIGUIENTE.
        free((*pl)->siguiente); //ELIMINO EL SIGUIENTE(EL ULTIMO).
    }
    else
    {
        free(*pl);
        *pl = NULL;
    }
    return 1; //VERDADERO.
}

int buscar_valor_lista(T_lista* pl, T_dato* d, T_cmp compare)
{
    if(!*pl)
    {
        return 0; //LISTA VACIA.
    }
    ///REALIZO LA COMPARACION DESDE DONDE HAYA QUEDADO LA LISTA, PRINCIPIO, FINAL, MEDIO, ETC.
    int comp = compare(d, &(*pl)->info);
    /*
        Mientras que el valor que estoy buscando sea menor al que esta posicionado actualmente
        el puntero de la lista, y TENGA un anterior tengo que retroceder.
    */
    while(comp < 0  && (*pl)->anterior)
    {
        pl = &(*pl)->anterior;
        comp = compare(d, &(*pl)->info);
    }
    //Si al salir del ciclo lo encontre.
    if(comp == 0)
    {
        *d = (*pl)->info;
        return 1; //ENCONTRADO / VERDADERO.s
    }
    //Misma lógica anterior.
    while(comp > 0 && (*pl)->siguiente)
    {
        pl = &(*pl)->siguiente;
        comp = compare(d, &(*pl)->info);
    }
    if(comp == 0)
    {
        *d = (*pl)->info;
        return 1; //ENCONTRADO / VERDADERO.s
    }
    return -1; // NO ENCONTRADO.
}

int eliminar_valor_lista(T_lista* pl, T_dato* pd, T_cmp cmp)
{
T_nodo *elim;
elim=*pl;

while(elim&&cmp(pd,&elim->info)>0)
    elim=elim->siguiente;

while(elim&&cmp(pd,&elim->info)<0)
    elim=elim->anterior;

    if(!elim)
    {
        return 0;
    }
    if(elim==*pl)
    {
        *pl=elim->anterior;
    }
    else
    {
        *pl=elim->siguiente;
    }
    if(elim->anterior)
    {
       elim->anterior->siguiente=elim->siguiente;
    }
    if(elim->siguiente)
    {
       elim->siguiente->anterior=elim->anterior;
    }

    free(elim);
    return 1;

}

int agregar_ordenado(T_lista* pl,T_dato *pd,T_cmp cmp)
{
   T_nodo *nuevo,*ant,*sig,*act;

   act=*pl;
   if(!*pl)
   {
       nuevo=(T_nodo*)malloc(sizeof(T_nodo));
       nuevo->info=*pd;
       nuevo->siguiente=nuevo->anterior=NULL;
       *pl=nuevo;
       return 1;
   }

   while(act&&act->siguiente&&cmp(pd,&(act)->info)>0)
    act=act->siguiente;

   while(act&&act->siguiente&&cmp(pd,&(act)->info)<0)
    act=act->anterior;

    nuevo=(T_nodo*)malloc(sizeof(T_nodo));
    nuevo->info=*pd;

    if(act&&cmp(pd,&(act)->info)>0)
    {
        ant=act;
        sig=ant->siguiente;
    }
    else
    {
        sig=act;
        ant=sig->anterior;
    }

    nuevo->anterior=ant;
    nuevo->siguiente=sig;

    if(ant)
     ant->siguiente=nuevo;
    if(sig)
    sig->anterior=nuevo;


    *pl=nuevo;
    return 1;
}

void eliminar_duplicados(T_lista* pl, T_cmp cmp)
{
    ///SI ESTA VACIO O TIENE UN ELEMENTO NO HAY DUPLICADOS.
    if(!*pl || !(*pl)->siguiente)
    {
        return;
    }
    T_nodo* act = *pl;
    T_nodo* sig = act->siguiente;
    ///MIENTRAS QUE HAYA UN ACTUAL Y UN SIGUIENTE.
    while(act && sig)
    {
        ///LOS COMPARO.
        int comp = cmp(&(act->info), &(sig->info));
        ///SI EL SIGUIENTE Y EL ACTUAL SON IGUALES.
        while(comp == 0)
        {
            ///SI EL SIGUIENTE TIENE SIGUIENTE.
            if(sig->siguiente)
            {
                act->siguiente = sig->siguiente;
                sig->siguiente->anterior = act;
                free(sig);
                sig = act->siguiente;
                comp = cmp(&(act->info), &(sig->info));
            }
            ///SI EL SIGUIENTE ES EL ULTIMO DE LA LISTA.
            else
            {
                act->siguiente = NULL;
                free(sig);
                return;
            }
        }
        ///AVANZO ACT Y SIG.
        act = act->siguiente;
        sig = act->siguiente;
    }
}