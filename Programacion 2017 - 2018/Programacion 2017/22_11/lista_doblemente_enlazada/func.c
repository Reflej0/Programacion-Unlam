#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int cmp(void*d1,void*d2){

    t_info*aa = (t_info*)d1;
    t_info*bb = (t_info*)d2;

    return (aa->num - bb->num);
}

void ingresar_dato(t_info*d){

    printf("\nIngrese dato: ");
    scanf("%d",&d->num);
}
void mostrar_dato(t_info*d){

    printf("\nDato: %d",d->num);
}

void crear_lista(t_lista*pl){

    *pl = NULL;
}

int insertar_al_principio(t_lista*pl,t_info*d){

    t_nodo*aux;

    aux = (t_nodo*)malloc(sizeof(t_nodo));

    if(!aux)return ERR_MALLOC;

    aux->info = *d;

    aux->ant = NULL;
    aux->sig = *pl;

    if(*pl){
        (*pl)->ant = aux;
    }

    *pl = aux;

    return TODO_OK;
}
int recorrer_desde_principio(t_lista*pl){

    if(*pl == NULL){
        return LISTA_VACIA;
    }

    while(*pl){
        printf("\nAnt: %p P: %p num: %d Sig: %p",(*pl)->ant,(*pl),(*pl)->info.num,(*pl)->sig);

        pl = &(*pl)->sig;
    }

    return TODO_OK;
}
int recorrer_desde_final(t_lista*pl){

    if(*pl == NULL){
        return LISTA_VACIA;
    }

    while((*pl)->sig){

        pl = &(*pl)->sig;
    }


    while(*pl){
        printf("\nAnt: %p P: %p num: %d Sig: %p",(*pl)->ant,(*pl),(*pl)->info.num,(*pl)->sig);

        pl = &(*pl)->ant;
    }

    return TODO_OK;

}
int insertar_al_final(t_lista*pl,t_info*d){

    t_nodo*aux;
    t_nodo*ant=NULL;

    aux = (t_nodo*)malloc(sizeof(t_nodo));

    if(!aux)return ERR_MALLOC;

    while(*pl){

        ant = *pl;

        pl = &(*pl)->sig;

    }

    aux->info = *d;

    aux->ant = ant;
    aux->sig = NULL;

    *pl = aux;

    return TODO_OK;
}

int eliminar_de_lista(t_lista*pl,t_info*d,t_cmp cmp){

    t_nodo*nae;

    if(!*pl)return NO_ESTA;

    while(*pl && cmp(&(*pl)->info,d)!=0){

        pl = &(*pl)->sig;
    }

    if(cmp(&(*pl)->info,d)==0){

        nae = *pl;

        *pl = nae->sig;

        if(nae->sig != NULL){

            nae->sig->ant = nae->ant;
        }

        free(nae);

        return TODO_OK;
    }else{
        return NO_ESTA;
    }


}

void vaciar_lista(t_lista*pl){

    t_nodo*nae;
    t_lista*p = pl;

    if(!*pl)return;


    while(*pl){

        nae = *pl;

        pl = &(*pl)->sig;

        free(nae);
    }

    pl = p;

    *pl = NULL;

}

void eliminar_logicamente(t_lista*pl,t_nodo*nae){

    while(*pl && *pl!=nae){
        pl = &(*pl)->sig;
    }

    if(*pl == nae){

        *pl = nae->sig;

        if(nae->sig != NULL){

            nae->sig->ant = nae->ant;
        }
    }
}
void insertar_logicamente_final(t_lista*pl,t_nodo*nai){

    t_nodo*ant=NULL;

    while(*pl){

        ant = *pl;
        pl = &(*pl)->sig;
    }

    *pl=nai;

    nai->sig=NULL;

    nai->ant = ant;
}

void ordenar_lista(t_lista*pl,t_cmp cmp){

    t_lista*listaA=pl;
    t_lista*listaB=NULL;
    t_nodo*menor;
    int i,j=0;

    while(*pl){
        j++;
        pl = &(*pl)->sig;
    }

    for(i=0;i<j;i++){

        pl = listaA;
        menor = *pl;

        printf("\nRecorro iteracion %d",i);
        recorrer_desde_principio(pl);

        while(*pl){

            if(cmp(&(*pl)->info,&menor->info)<0){

                menor = *pl;

            }

            pl = &(*pl)->sig;
        }

        printf("\nmenor: %d",menor->info.num);

        eliminar_logicamente(listaA,menor);
        insertar_logicamente_final(&listaB,menor);

    }

    pl = listaA;
    *pl = listaB;
}
