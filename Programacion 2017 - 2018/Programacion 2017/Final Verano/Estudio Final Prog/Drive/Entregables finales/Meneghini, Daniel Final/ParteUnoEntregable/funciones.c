
#include "funciones.h"

/* ------------------------ */


/** funciones a reemplazar*/
char* buscarPrimerOcurrencia(const char *s1, const char *s2)
{
    char* p2=(char*)s2;
    while(*s1)
    {
        while(*s1 && *p2 && *s1!=*p2)
            p2++;
        if(!*s1)
            return NULL;
        if(*s1==*p2)
            return (char*)s1;

        p2=(char*)s2;
        s1++;
    }
    return NULL;
}

int contarOcurrencias(const char *s1, const char *s2)
{
    const char* p2=s2;
    int i=0;
    while(*s1)
    {
        while(*s1 && *p2 && *s1!=*p2)
            p2++;
        if(!*s1)
            return i;
        if(*s1==*p2)
            i++;

        p2=s2;
        s1++;
    }
    return i;
}

int compararXClaCliClaProd(const tInfo *d1, const tInfo *d2)
{

    return strcmp(d1->codClie,d2->codClie)?strcmp(d1->codClie,d2->codClie):strcmp(d1->codProd,d2->codProd);
}

void acumular(tInfo *d1, const tInfo *d2)
{
    d1->cantUni+=d2->cantUni;
}

int eliminarDuplicadosYAcumular(tLista *p,
                                int (*comp)(const tInfo*, const tInfo*),
                                void (*acum)(tInfo*, const tInfo*))
{
    tInfo aux;
    tNodo* actual=*p,
        * sig,
        *ant,
        *recorrido,
        *nodo_a_liberar;

    if(!actual)
        return 0;
    aux=actual->info;

    while(actual->ant)
        actual=actual->ant;

    while(actual)
    {
        recorrido=actual->sig;

        while(recorrido)
        {
            if(comp(&actual->info,&recorrido->info)==0)
            {
                nodo_a_liberar=recorrido;
                acum(&actual->info,&recorrido->info);
                sig=recorrido->sig;
                ant=recorrido->ant;
                if(ant)
                    ant->sig=sig;
                if(sig)
                    sig->ant=ant;
                free(nodo_a_liberar);
                recorrido=sig;
            }
            else
                recorrido=recorrido->sig;
        }
        if(comp(&aux,&actual->info)==0)
            *p=actual;
        actual=actual->sig;
    }
    return 1;
}

void ordenarLista(tLista *p, int (*comp)(const tInfo*, const tInfo*))
{
    tInfo aux,
        * menor,//podria ser mayor, depende de la fc de comparacion
        intercambio;
    tNodo* actual=*p,
        *recorrido;

    if(!actual)
        return;
    aux=actual->info;

    while(actual->ant)
        actual=actual->ant;

    while(actual)
    {
        menor=&actual->info;
        recorrido=actual->sig;
        while(recorrido)
        {
            if(comp(&recorrido->info,menor)<0)
                menor=&recorrido->info;
            recorrido=recorrido->sig;
        }
        intercambio=actual->info;
        actual->info=*menor;
        *menor=intercambio;
        if(comp(&aux,&actual->info)==0)
            *p=actual;
        actual=actual->sig;
    }
}


