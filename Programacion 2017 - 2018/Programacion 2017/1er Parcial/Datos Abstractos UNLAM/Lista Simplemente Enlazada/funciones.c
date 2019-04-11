#include <stdio.h>
#include <stdlib.h>

#include "header.h"

void crearLista(t_lista*p){

    *p=NULL;
}
int insertarAlPrincipio(t_lista*p){

    t_nodo*aux;

    aux=(t_nodo*)malloc(sizeof(t_nodo));

    if(!aux)return 0;

    printf("\nIngrese dato: ");
    scanf("%d",&aux->info.num);

    aux->sig = *p;

    *p=aux;

    return 1;
}
int insertarAlFinal(t_lista*p){

    t_nodo*aux;

    aux=(t_nodo*)malloc(sizeof(t_nodo));

    if(!aux)return 0;

    printf("\nIngrese dato: ");
    scanf("%d",&aux->info.num);

    while(*p){

        p = &(*p)->sig;
    }

    aux->sig = NULL;

    *p=aux;

    return 1;
}
int eliminardelista(t_lista*p){

    int dato;
    t_nodo*aux;

    if(!*p)return 0;

    printf("\nIngresar dato a eliminar: ");
    scanf("%d",&dato);



    while(*p){


        if((*p)->info.num == dato){
            printf("\nNodo encontrado");

            aux = *p;

            *p = aux->sig;

            free(aux);

            printf("\nNodo liberado");

            return;
        }else{
            p = &(*p)->sig;
        }
    }
}
void vaciarLista(t_lista*p){

    t_nodo*aux;

    if(!*p)return;

    while(*p){

        aux = *p;

        *p = aux->sig;



        free(aux);

        printf("\nNodo liberado");
    }
}
int mostrarLista(t_lista*p){

    if(!*p)return 0;

    while(*p){

        printf("\n %d ",(*p)->info.num);

        p = &(*p)->sig;
    }

    return 1;
}
