#include <stdio.h>
#include <stdlib.h>

#include "header.h"

void crearLista(t_lista*p,t_lista*t){

    *p=NULL;
    *t=NULL;
}

void cargarInfo(t_info*d){

    printf("\nIngrese numero: ");
    scanf("%d",&d->num);

}

int insertarAlPrincipio(t_lista*p,t_lista*t,t_info*d){

    t_nodo*aux;

    aux = (t_nodo*)malloc(sizeof(t_nodo));

    if(!aux)return 0;

    aux->info = *d;

    if(!*p && !*t){ //estaba vacia

        aux->sig = aux;

        *p = aux;

        *t = aux;

        return 1;
    }


    aux->sig = *p;

    *p=aux;

    (*t)->sig = aux;

    return 1;
}
int recorrerDesdePrincipio(t_lista*p,t_lista*t){

    int i=1;

    if(!*p && !*t){
        return 0;
    }

    if(*p == *t){//solo un elemento

        printf("\nNodo %d num %d, dir %p, puntero sig: %p",i,(*p)->info.num,*p,(*p)->sig);

        return 1;
    }

    while(*p != *t){

        printf("\nNodo %d num %d, dir %p, puntero sig: %p",i,(*p)->info.num,*p,(*p)->sig);

        i++;

        p=&(*p)->sig;
    }

    printf("\nNodo %d num %d, dir %p, puntero sig: %p",i,(*p)->info.num,*p,(*p)->sig);

    return 1;
}
int insertarAlFinal(t_lista*p,t_lista*t,t_info*d){

    t_nodo*aux;

    aux = (t_nodo*)malloc(sizeof(t_nodo));

    if(!aux)return 0;

    aux->info = *d;

    if(!*p && !*t){ //estaba vacia

        aux->sig = aux;

        *p = aux;

        *t = aux;

        return 1;
    }

    (*t)->sig = aux;

    *t=aux;

    aux->sig = *p;

    return 1;


}
int vaciarLista(t_lista*p,t_lista*t){

    t_nodo*aux;
    int i=0;

    if(!*p && !*t)return 0;

    while(*p!=*t){

        aux = *p;

        *p = aux->sig;

        free(aux);

        i++;
    }

    aux = *p;

    free(aux);

    *p = NULL;

    *t = NULL;

    i++;

    printf("\n%d nodos liberados",i);
}
