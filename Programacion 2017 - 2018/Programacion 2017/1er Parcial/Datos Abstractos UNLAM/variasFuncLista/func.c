#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int cmp(void*a,void*b){

    t_dato*aa = (t_dato*)a;
    t_dato*bb = (t_dato*)b;

    printf("\naa->numero: %d - bb->numero: %d",aa->numero,bb->numero);

    return (aa->numero - bb->numero);
}
void ingresar_dato(t_dato*d){

    printf("\nIngrese numero: ");
    scanf("%d",&(d)->numero);
    printf("\nIngrese cantidad: ");
    scanf("%d",&(d)->cantidad);
}

void mostrar_dato(t_dato*d){

    printf("\nNumero: %d Cantidad: %d",d->numero,d->cantidad);
}

//------- primitivas lista

void crear_lista(t_lista*pl){

    *pl = NULL;
}
int poner_en_lista_desordenado(t_lista*pl,t_dato*d){

    t_nodo*aux;

    aux = (t_nodo*)malloc(sizeof(t_nodo));

    if(!aux)return ERR_MALLOC;

    aux->info = *d;

    aux->sig = *pl;

    *pl = aux;

    return TODO_OK;
}
int poner_en_lista_ordenado(t_lista*pl,t_dato*d,t_cmp cmp){

    t_nodo*aux;

    aux = (t_nodo*)malloc(sizeof(t_nodo));

    if(!aux)return ERR_MALLOC;

    aux->info = *d;

    if(!*pl){
        aux->sig = NULL;
        *pl = aux;
        return TODO_OK;
    }

    while(*pl && cmp(d,&(*pl)->info) > 0){

        pl = &(*pl)->sig;
    }

    aux->sig = *pl;

    *pl = aux;

    return TODO_OK;
}

int sacar_elemento_por_llave(t_lista*pl,t_dato*d,t_cmp cmp){

    t_nodo*aux;

    while(*pl && cmp(d,&(*pl)->info) != 0){

        pl = &(*pl)->sig;
    }

    if(*pl && cmp(d,&(*pl)->info) == 0){

        *d = (*pl)->info;

        aux = *pl;

        *pl = aux->sig;

        free(aux);

        return TODO_OK;
    }

    return NO_ENCONTRADO;
}

int sacar_ultimo(t_lista*pl,t_dato*d){

    t_nodo*aux;

    if(!*pl){
        return VACIA;
    }

    while((*pl)->sig){

        pl = &(*pl)->sig;

    };

    aux = *pl;

    *d = aux->info;

    *pl = NULL;

    free(aux);

    return TODO_OK;

}

void sacar_por_punt(t_lista*pl,t_nodo*sacar){

    while(*pl != sacar){
        printf("\npl: %d punt: %p sig: %p",(*pl)->info.numero,*pl,(*pl)->sig);
        pl = &(*pl)->sig;
    }

    *pl = (*pl)->sig;
}

void agregar_por_punt(t_lista*pl,t_nodo*agregar){

    while(*pl){

        pl = &(*pl)->sig;
    }

    *pl = agregar;

    (*pl)->sig = NULL;
}

void ordenar_lista(t_lista*pl,t_cmp cmp){

    t_nodo* listaA = pl;
    t_nodo* listaB = NULL;
    int i,j=0;

    t_nodo*menor;

    while(*pl){
        pl = &(*pl)->sig;
        j++;
    }

    pl = listaA;

    for(i=0;i<j;i++){

        menor = *pl;

        while(*pl){

            if(cmp(&(*pl)->info,&menor->info) < 0){

                menor = *pl;
            }

            pl = &(*pl)->sig;
        }
        printf("\nMenor: %d punt: %p sig: %p",menor->info.numero,menor,menor->sig);
        sacar_por_punt(listaA,menor);
        agregar_por_punt(&listaB,menor);

        pl = listaA;
    }

    *pl = listaB;
}

//----------- otros

void recorrer_lista_simple(t_lista*pl){

    if(!*pl){
        printf("\nLista vacia");
        return;
    }
    printf("\n");

    while(*pl){

        printf("\nNumero: %d Cantidad: %d Dir: %p Sig: %p",(*pl)->info.numero,(*pl)->info.cantidad,*pl,(*pl)->sig);

        pl = &(*pl)->sig;
    }

    return;
}
