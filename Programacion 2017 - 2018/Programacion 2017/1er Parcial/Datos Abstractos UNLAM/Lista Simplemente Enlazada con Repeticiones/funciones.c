#include <stdio.h>
#include <stdlib.h>

#include "header.h"

void crearLista(t_lista*p){

    *p=NULL;
}

void cargarInfo(t_info*d){

    printf("\nIngrese numero: ");
    scanf("%d",&d->num);
    printf("\nIngrese cant repeticiones: ");
    scanf("%d",&d->repe);
}

int insertarContandoRep(t_lista*p,t_info*d){

    t_nodo* aux;

    while(*p && (*p)->info.num != d->num){

        p = &(*p)->sig;
    }

    if(*p && (*p)->info.num == d->num){

        (*p)->info.repe += d->repe;

        printf("\nNodo actualizado, ahora %d tiene %d repeticiones",(*p)->info.num,(*p)->info.repe);


        return 1;
    }

    aux = (t_nodo*)malloc(sizeof(t_nodo));

    if(!aux)return 0;

    aux->info = *d;

    aux->sig = NULL;

    if(!*p){

        *p = aux;

    }else{

        (*p)->sig = aux;

    }


    return 1;


}

int eliminarRep(t_lista*p,t_info*d){

    t_nodo*aux;

    if(!*p)return 0;

    while(*p && (*p)->info.num != d->num){

        p = &(*p)->sig;
    }

    if((*p)->info.num == d->num){

        if((*p)->info.repe > d->repe){

            (*p)->info.repe -= d->repe;

            printf("Se restaron %d repeticiones al num %d",d->repe,(*p)->info.num);

            return 1;

        }else{

            //borro el nodo

            aux = *p;

            *p = aux->sig;

            free(aux);

            printf("\nSe borro el nodo porque se restaron mas repeticiones que las que tenia");

            return 1;
        }
    }


    return 0;

}

int compararMenoraMayor(void*a,void*b){

    return ((*(int*)a) - (*(int*)b));
}


int insertarEnListaEnOrdenActualizar(t_lista*p,t_info*d,int (*cmp)(void*a,void*b)){

    t_nodo*aux;



    while(*p && cmp(&(*p)->info,d) < 0){

        p= &(*p)->sig;
    }

    if(*p && cmp(&(*p)->info,d) == 0){
            //actualizo repeticiones

            (*p)->info.repe += d->repe;

            printf("\nSe actualizo el nodo num %d, ahora tiene %d repeticiones",(*p)->info.num,(*p)->info.repe);

            return 1;
    }else if(*p){

        //inserto en el medio

        aux = (t_nodo*)malloc(sizeof(t_nodo));

        if(!aux)return 0;

        aux->info = *d;

        aux->sig = *p;

        *p=aux;

        return 1;
    }

    if(!*p){
        aux = (t_nodo*)malloc(sizeof(t_nodo));

        if(!aux)return 0;

        aux->info = *d;

        aux->sig = NULL;

        *p=aux;

        printf("\nLa lista estaba vacia o llego al final de lista, insertado");

        return 1;
    }


    return 0;
}
int mostrarLista(t_lista*p){

    int i=1;

    if(!*p)return 0;

    while(*p){

        printf("\nNodo %d, num %d, repe %d",i,(*p)->info.num,(*p)->info.repe);

        p = &(*p)->sig;
    }

    return 1;
}
