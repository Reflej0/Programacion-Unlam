#include <stdio.h>
#include <stdlib.h>

#include "header.h"

void crearCola(t_cola*c){

    c->pri=NULL;
    c->ult=NULL;
}
int colaVacia(t_cola*c){

    return (c->pri==NULL && c->ult==NULL);
}
int colaLlena(t_cola*c){

    void*aux;

    aux = malloc(sizeof(t_nodo));

    free(aux);

    if(!aux)return 1;

    return 0;
}

int acolar(t_cola*c){

    t_nodo*aux;

    if(colaLlena(c))return 0;

    aux = (t_nodo*)malloc(sizeof(t_nodo));

    if(!aux)return 0;

    printf("\nIngrese numero a acolar: ");
    scanf("%d",&aux->info.num);

    aux->sig=NULL;

    if(c->pri == NULL){

        c->pri = aux;
        c->ult = aux;

    }else{
        c->ult->sig=aux;

        c->ult = aux;
    }



    return 1;
}

int desacolar(t_cola*c,t_info*inf){

    if(colaVacia(c))return 0;

    if(c->pri){

    *inf = c->pri->info;

    c->pri = c->pri->sig;
    }else{
        return 0;
    }

    return 1;



}
int verPrimero(t_cola*c){

    if(colaVacia(c))return 0;

    printf("\nprimero: %d",c->pri->info.num);

    return 1;
}
void vaciarCola(t_cola*c){

    t_nodo*aux;

    if(colaVacia(c))return;

    while(c->pri->sig != NULL){

        aux = c->pri;

        c->pri = aux->sig;

        printf("\nLiberando numero: %d",aux->info.num);
        free(aux);
    }

    aux = c->pri;

    c->pri = aux->sig;

    printf("\nLiberando numero: %d",aux->info.num);
    free(aux);

    if(!c->pri){
        c->ult = NULL;
    }
}
