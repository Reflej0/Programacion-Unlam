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

void vaciar(t_lista*p){

    t_nodo*aux;

    if(!*p)return;

    while((*p)->sig != *p){

        aux = (*p)->sig;

        (*p)->sig = aux->sig;

        printf("\nLiberando nodo num %d",aux->info.num);

        free(aux);
    }

    aux = *p;

    printf("\nLiberando nodo num %d",aux->info.num);

    free(aux);

    *p = NULL;

}
int pilallena(t_lista*p){

    void*aux;

    aux=(t_nodo*)malloc(sizeof(t_nodo));

    free(aux);

    if(!aux)return 1;

    return 0;
}
int pilaVacia(t_lista*p){

    return !*p;
}
int apilar(t_lista*p,t_info*d){

    t_nodo*aux;

    aux = (t_nodo*)malloc(sizeof(t_nodo));

    if(!aux)return 0;

    aux->info = *d;

    if(!*p){

        aux->sig = aux;

        *p = aux;

        return 1;
    }

    aux->sig = (*p)->sig;

    (*p)->sig = aux;

    return 1;
}
int recorrerPila(t_lista*p){

    t_nodo*fin;

    if(!*p)return 0;

    if(*p == (*p)->sig){

        printf("\nNodo num %d, punt %p, punt sig %p",(*p)->info.num,*p,(*p)->sig);
        return 1;
    }

    fin = *p;

    p=&(*p)->sig;

    while(*p != fin){

        printf("\nNodo num %d, punt %p, punt sig %p",(*p)->info.num,*p,(*p)->sig);

        p=&(*p)->sig;
    }

    printf("\nNodo num %d, punt %p, punt sig %p",(*p)->info.num,*p,(*p)->sig);

    return 1;
}
int desapilar(t_lista*p,t_info*d){

    t_nodo*aux;

    if(!*p)return 0;

    if(*p == (*p)->sig){//nodo unico

        aux = *p;

        *d = aux->info;

        free(aux);

        *p=NULL;

        return 1;
    }

    p=&(*p)->sig;

    aux = *p;

    *d = aux->info;

    *p = aux->sig;

    free(aux);

    return 1;

}
int verTope(t_lista*p){

    if(!*p)return 0;

    p=&(*p)->sig;

    printf("\nEl tope es %d, punt %p, punt sig %p",(*p)->info.num,*p,(*p)->sig);

    return 1;
}
