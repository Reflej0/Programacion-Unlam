#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int eliminar_de_arbol(t_arbol*pa,t_dato*d,t_cmp cmp){

    t_nodo**nae;

    nae = buscar_nodo(pa,d,cmp);

    if(nae==NULL)return FALSO;

    eliminar_nodo(nae);

    return VERDADERO;
}

t_nodo** buscar_nodo(t_arbol*pa,t_dato*d,t_cmp cmp){

    int comp;

    if(!*pa)return NULL;

    comp = cmp(d,&(*pa)->info);

    if(comp == 0)return pa;

    if(comp <0)

        return buscar_nodo(&(*pa)->hizq,d,cmp);

    if(comp >0)

        return buscar_nodo(&(*pa)->hder,d,cmp);


}

t_nodo** mayor(t_arbol*pa){

    if(!(*pa)->hder)return pa;

    mayor(&(*pa)->hder);
}

t_nodo** menor(t_arbol*pa){

    if(!(*pa)->hizq)return pa;

    menor(&(*pa)->hizq);
}

void eliminar_nodo(t_nodo**nae){

    int hi,hd;

    t_nodo** nodoReemplazo;

    if((*nae)->hizq == NULL && (*nae)->hder==NULL){//si es hoja

        free(*nae);

        *nae=NULL;

        return;
    }

    hi = altura_arbol(&(*nae)->hizq);

    hd = altura_arbol(&(*nae)->hder);

    if(hi>hd){

        nodoReemplazo = mayor(&(*nae)->hizq);

    }else{

        nodoReemplazo = menor(&(*nae)->hder);
    }

    (*nae)->info = (*nodoReemplazo)->info;

    eliminar_nodo(nodoReemplazo);

}

void mostrar_por_nodo(t_nodo**pa){

    printf("\nNodo: %d",(*pa)->info.num);
}
