#include <stdio.h>
#include <stdlib.h>

#include "header.h"

void crearPila(t_pila*p){

    *p=NULL;
}
int vaciarPila(t_pila*p){

    int cant=0;

    t_nodo* aux;

    while(*p != NULL){

        aux = *p;

        *p = (*p)->siguiente;

        free(aux);

        cant++;
    }

    return cant;
}
int pilaLlena(t_pila*p){

    t_nodo*aux;

    aux = (t_nodo*)malloc(sizeof(t_nodo));

    free(aux);

    if(!aux){
        return 1;
    }else{

        return 0;
    }
}
int pilaVacia(t_pila*p){

    if(!*p){
        return 1;
    }else{
        return 0;
    }
}
int apilar(t_pila*p,t_info*d){

    t_nodo* aux;

    aux = (t_nodo*)malloc(sizeof(t_nodo));

    if(!aux){
        printf("\nError");
        return 0;
    }

    aux->info = *d;
    aux->siguiente = *p;

    *p = aux;


    return 1;

}
int desapilar(t_pila*p,t_info*inf){

    t_nodo*aux;

    if(!*p)return 0;

    *inf = (*p)->info;

    aux = *p;

    *p=(*p)->siguiente;

    free(aux);

    return 1;
}
int vertope(t_pila*p){



    if(!*p)return 0;



    printf("\nTope: %d",(**p).info.num);

    return 1;
}
