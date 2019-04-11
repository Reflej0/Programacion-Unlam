#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

void mostrar_nodo_arbol(const T_arbol* pa)
{
    if(!*pa) return;
    printf("NODO: %d\n", (*pa)->info);
}

int contar_mostrar_nodos(const T_arbol* pa)
{
    if(!*pa)
        return 0;
    mostrar_nodo_arbol(pa);
    return contar_mostrar_nodos(&(*pa)->Hizq) + contar_mostrar_nodos(&(*pa)->Hder) + 1;
}

int contar_mostrar_hojas(const T_arbol* pa)
{
    if(!*pa)
        return 0;
    if(!(*pa)->Hizq && !(*pa)->Hder)
    {
        mostrar_nodo_arbol(pa);
        return 1;
    }
    return (contar_mostrar_hojas(&(*pa)->Hizq) + contar_mostrar_hojas(&(*pa)->Hder));
}

int contar_mostrar_nohojas(const T_arbol* pa)
{
    if(!*pa)
        return 0;
    if(!(*pa)->Hizq && !(*pa)->Hder)
        return 0;
    mostrar_nodo_arbol(pa);
    return contar_mostrar_nohojas(&(*pa)->Hizq) + contar_mostrar_nohojas(&(*pa)->Hder) + 1;
}

int contar_nodos_hijos_izq(const T_arbol* pa)
{
    if(!*pa)
        return 0;
    if((*pa)->Hizq)
        return contar_nodos_hijos_izq(&(*pa)->Hizq)+1;
    return contar_nodos_hijos_izq(&(*pa)->Hder);
}

int contar_nodos_hijos_der(const T_arbol* pa)
{
    if(!*pa)
        return 0;
    if((*pa)->Hder)
        return contar_nodos_hijos_der(&(*pa)->Hder)+1;
    return contar_nodos_hijos_der(&(*pa)->Hizq);
}

int contar_nodos_hijos_soloizq(const T_arbol* pa)
{
    if(!*pa)
        return 0;
    if((*pa)->Hizq && !(*pa)->Hder)
        return contar_nodos_hijos_soloizq(&(*pa)->Hizq)+1;
    else
        return contar_nodos_hijos_soloizq(&(*pa)->Hizq);
    return contar_nodos_hijos_soloizq(&(*pa)->Hder);
}

int contar_nodos_hijos_soloder(const T_arbol* pa)
{
    if(!*pa)
        return 0;
    if((*pa)->Hder && !(*pa)->Hizq)
        return contar_nodos_hijos_soloder(&(*pa)->Hder)+1;
    else
        return contar_nodos_hijos_soloder(&(*pa)->Hder);
    return contar_nodos_hijos_soloder(&(*pa)->Hizq);
}

int mostrar_contar_nodos_de_altura(const T_arbol* pa, const int a)
{
    if(!*pa)
        return 0;
    int nivel_actual = 0;
    return mostrar_contar_nodos_de_altura_rec(pa, a, nivel_actual);
}

int mostrar_contar_nodos_de_altura_rec(const T_arbol* pa, const int amax, int aactual)
{
    if(!*pa)
        return 0;
    if(amax == aactual)
    {
        mostrar_nodo_arbol(pa);
        return 1;
    }
    return mostrar_contar_nodos_de_altura_rec(&(*pa)->Hizq, amax, aactual+1) + mostrar_contar_nodos_de_altura_rec(&(*pa)->Hder, amax, aactual+1);
}

int mostrar_contar_nodos_hasta_altura(const T_arbol* pa, const int a)
{
    if(!*pa)
        return 0;
    int nivel_actual = 0;
    return mostrar_contar_nodos_hasta_altura_rec(pa, a, nivel_actual);
}

int mostrar_contar_nodos_hasta_altura_rec(const T_arbol* pa, const int amax, int aactual)
{
    if(!*pa)
        return 0;
    mostrar_nodo_arbol(pa);
    if(amax == aactual)
    {
        return 1;
    }
    return mostrar_contar_nodos_hasta_altura_rec(&(*pa)->Hizq, amax, aactual+1) + mostrar_contar_nodos_hasta_altura_rec(&(*pa)->Hder, amax, aactual+1) + 1;
}

int contar_podar_hojas(T_arbol* pa)
{
    if(!*pa)
        return 0;
    if(!(*pa)->Hizq && !(*pa)->Hder)
    {
        free(*pa);
        *pa = NULL;
        return 1;
    }
    return (contar_podar_hojas(&(*pa)->Hizq) + contar_podar_hojas(&(*pa)->Hder));
}

