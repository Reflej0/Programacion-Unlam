#include <stdio.h>
#include <stdlib.h>

#include "header.h"

void cargarInfo(t_info*d){

    printf("\nIngrese numero: ");
    scanf("%d",&d->num);
}

int insertarIterativa(t_arbol*p,t_info*d){

    t_nodo*aux;

    aux =(t_nodo*)malloc(sizeof(t_nodo));

    if(!aux)return 0;

    if(!*p){//arbol vacio

        aux->info = *d;
        aux->der=NULL;
        aux->izq=NULL;

        *p=aux;

        return 1;
    }

    while(*p){

        if(aux->info.num < (*p)->info.num){
            p=&(*p)->izq;
        }else{
            p=&(*p)->der;
        }
    }

    aux->info = *d;
    aux->der=NULL;
    aux->izq=NULL;

    *p=aux;

    return 1;
}
int insertarrecursiva(t_arbol*p,t_info*d){

    t_nodo*aux;

    if(!*p){

        aux = (t_nodo*)malloc(sizeof(t_nodo));

        if(!aux)return 0;

        aux->info = *d;

        aux->izq = NULL;

        aux->der = NULL;

        *p = aux;

        return 1;
    }

    if(d->num < (*p)->info.num){

        insertarrecursiva(&(*p)->izq,d);
    }else{
        insertarrecursiva(&(*p)->der,d);
    }
}
void mostrarPreOrden(t_arbol*p){

    if(!*p)return;

    printf(" %d ",(*p)->info.num);

    mostrarPreOrden(&(*p)->izq);

    mostrarPreOrden(&(*p)->der);
}
void mostrarInOrden(t_arbol*p){

    if(!*p)return;

    mostrarInOrden(&(*p)->izq);

    printf(" %d ",(*p)->info.num);

    mostrarInOrden(&(*p)->der);
}
void mostrarPosOrden(t_arbol*p){

    if(!*p)return;

    mostrarPosOrden(&(*p)->izq);

    mostrarPosOrden(&(*p)->der);

    printf(" %d ",(*p)->info.num);
}
