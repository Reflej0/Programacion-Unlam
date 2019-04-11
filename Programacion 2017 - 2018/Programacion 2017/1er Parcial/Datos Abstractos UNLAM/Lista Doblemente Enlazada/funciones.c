#include <stdio.h>
#include <stdlib.h>

#include "header.h"

void crearLista(t_lista*p){

    *p=NULL;
}

void cargarInfo(t_info*d){

    printf("\nIngrese numero: ");
    scanf("%d",&d->num);

}

int insertarAlPrincipio(t_lista*p,t_info*d){

    t_nodo*aux;

    aux=(t_nodo*)malloc(sizeof(t_nodo));

    if(!aux)return 0;

    aux->info = *d;

    aux->ant=NULL;

    aux->sig = *p;

    if(*p){

        (*p)->ant = aux;
    }

    *p=aux;

    return 1;
}
int recorrerDesdePrincipio(t_lista*p){

    int i=1;

    if(!*p)return 0;

    while(*p){

        printf("\nNodo %d Num %d",i,(*p)->info.num);

        i++;

        p=&(*p)->sig;
    }

    return 1;
}
int insertarAlFinal(t_lista*p,t_info*d){

    t_nodo*aux;

    if(!*p){

        aux = (t_nodo*)malloc(sizeof(t_nodo));

        if(!aux)return 0;

        aux->info = *d;

        aux->sig = NULL;

        aux->ant = NULL;

        *p=aux;

        return 1;
    }

    while(*p && (*p)->sig != NULL){

        p=&(*p)->sig;
    }

    aux = (t_nodo*)malloc(sizeof(t_nodo));

    if(!aux)return 0;

    aux->info = *d;

    aux->sig = NULL;

    aux->ant = *p;

    (*p)->sig = aux;

    return 1;
}

int recorrerDesdeFinal(t_lista*p){

    int i=1;

    if(!*p)return 0;

    while(*p && (*p)->sig){

        p=&(*p)->sig;

        i++;
    }

    while(*p){
        printf("\nNodo %d num %d",i,(*p)->info.num);
        //printf("\nant: %p",(*p)->ant);
        p=&(*p)->ant;
        i--;
    }

    return 1;
}
