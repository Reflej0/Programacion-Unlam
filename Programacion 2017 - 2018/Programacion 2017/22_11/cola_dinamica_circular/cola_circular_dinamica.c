#include <stdio.h>
#include <stdlib.h>
#include "cola_circular_dinamica.h"

void ingresar_dato(t_info*inf){

    printf("\nIngrese el dato: ");
    scanf("%d",&inf->num);
}

void crear_cola(t_cola*cola){

    *cola = NULL;
}

void recorrer_cola_est(t_cola*cola){

    t_nodo*aux;


    if(*cola==NULL){
        printf("\ncola vacia");
        return;
    }else{
        aux = (*cola)->sig;
    }

    printf("\n%d ",aux->info);

    while(aux != *cola){


        aux = (aux)->sig;
        printf("\n%d ",aux->info);
    }

}

void acolar(t_cola*cola,t_info*inf){

    t_nodo*aux;

    aux = (t_nodo*)malloc(sizeof(t_nodo));

    if(!aux){
        printf("\nerror malloc");
        return;
    }

    aux->info = *inf;

    if(*cola == NULL){
        *cola = aux;
        aux->sig = aux;
    }else{

        aux->sig = (*cola)->sig;
        (*cola)->sig = aux;
        *cola=aux;
    }

}

int desacolar(t_cola*cola,t_info*inf){

    t_nodo*nae;

    if(*cola == NULL){


        return 0;
    }

    nae = (*cola)->sig;

    if((*cola) == (*cola)->sig){
        *cola = NULL;
    }else{
        (*cola)->sig = nae->sig;
    }
    *inf =nae->info;
    printf("\nEliminando nodo: %d",nae->info.num);
    free(nae);
    return 1;
}

void ver_principio(t_cola*cola){

    if(*cola == NULL){
        printf("\ncola vacia");
    }else{
        printf("\nPrincipio %d",((*cola)->sig)->info.num);
    }
}

void cola_llena(t_cola*cola){

    t_nodo*aux;

    aux = (t_nodo*)malloc(sizeof(t_nodo));

    if(!aux){
        printf("\nCola llena");
    }else{
        printf("\nCola no llena");
    }

    free(aux);
}

void cola_vacia(t_cola*cola){

    if(*cola == NULL){
        printf("\nCola vacia");
    }else{
        printf("\nCola no vacia");
    }
}

void vaciar(t_cola*cola){

    t_nodo*nae;

    if(*cola == NULL){
        return;
    }

    while(*cola != NULL){
        nae = (*cola)->sig;

        if((*cola) == (*cola)->sig){
            *cola = NULL;
        }else{
            (*cola)->sig = nae->sig;
        }

        printf("\nEliminando nodo: %d",nae->info.num);
        free(nae);
    }
}
