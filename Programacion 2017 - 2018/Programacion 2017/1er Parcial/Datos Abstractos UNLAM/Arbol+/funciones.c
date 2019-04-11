#include <stdio.h>
#include <stdlib.h>

#include "header.h"

void cargarInfo(t_info*d){

    printf("\nIngrese numero: ");
    scanf("%d",&d->num);
}

int insertarIterativa(t_arbol*p,t_info*d){

    t_nodo*aux;

    aux =(t_nodo*)malloc(sizeof(t_nodo));

    if(!aux)return 0;

    if(!*p){//arbol vacio

        aux->info = *d;
        aux->der=NULL;
        aux->izq=NULL;

        *p=aux;

        return 1;
    }

    while(*p){

        if(aux->info.num < (*p)->info.num){
            p=&(*p)->izq;
        }else{
            p=&(*p)->der;
        }
    }

    aux->info = *d;
    aux->der=NULL;
    aux->izq=NULL;

    *p=aux;

    return 1;
}
int insertarrecursiva(t_arbol*p,t_info*d){

    t_nodo*aux;

    if(!*p){

        aux = (t_nodo*)malloc(sizeof(t_nodo));

        if(!aux)return 0;

        aux->info = *d;

        aux->izq = NULL;

        aux->der = NULL;

        *p = aux;

        return 1;
    }

    if(d->num < (*p)->info.num){

        insertarrecursiva(&(*p)->izq,d);
    }else{
        insertarrecursiva(&(*p)->der,d);
    }
}
void mostrarPreOrden(t_arbol*p){

    if(!*p)return;

    printf(" %d ",(*p)->info.num);

    mostrarPreOrden(&(*p)->izq);

    mostrarPreOrden(&(*p)->der);
}
void mostrarInOrden(t_arbol*p){

    if(!*p)return;

    mostrarInOrden(&(*p)->izq);

    printf(" %d ",(*p)->info.num);

    mostrarInOrden(&(*p)->der);
}
void mostrarPosOrden(t_arbol*p){

    if(!*p)return;

    mostrarPosOrden(&(*p)->izq);

    mostrarPosOrden(&(*p)->der);

    printf(" %d ",(*p)->info.num);
}

//ej26

int cargaAutomatica(t_arbol*p){

    int arr[9]={8,3,1,6,4,7,10,14,13};
    int i=0;
    t_info d;

    for(i=0;i<9;i++){

        d.num = arr[i];

        if(!insertarrecursiva(p,&d)){
            return 0;
        }
    }

    return 1;
}

void buscarElemento(t_arbol*p,t_info*d){

    if(!*p){
        printf("\nNo encontrado");
        return;
    }

    if((*p)->info.num == d->num){
        printf("\nElemento %d encontrado",d->num);
        return;
    }

    if(d->num < (*p)->info.num){
        printf("\nElemento %d es menor a %d, voy a la izq",d->num,(*p)->info.num);
        buscarElemento(&(*p)->izq,d);
    }else{
        printf("\nElemento %d es mayor a %d, voy a la der",d->num,(*p)->info.num);
        buscarElemento(&(*p)->der,d);
    }
}

int mostrarYcontarHojas(t_arbol*p){

    if(!*p)return 0;

    if(*p && !(*p)->der && !(*p)->izq){

        printf("\nHoja: %d",(*p)->info.num);

        return 1;
    }

    /*if((*p)->der){
        mostrarYcontarHojas(&(*p)->der);
    }

    if((*p)->izq){
        mostrarYcontarHojas(&(*p)->izq);
    }*/

    return mostrarYcontarHojas(&(*p)->der) + mostrarYcontarHojas(&(*p)->izq);
}

int cantidadNodosNoHojas(t_arbol*p){

    if(!*p)return 0;

    if(*p && ((*p)->der != NULL || (*p)->izq != NULL)){

        printf("\nNodo no hoja: %d",(*p)->info.num);

        return 1 + cantidadNodosNoHojas(&(*p)->izq) + cantidadNodosNoHojas(&(*p)->der);
    }


}

int contarHijosDerecha(t_arbol*p){

    if(!*p)return 0;

    if((*p)->der){

        printf("\nHijo por derecha: %d", ((*p)->der)->info.num);

        return 1 + contarHijosDerecha(&(*p)->izq) + contarHijosDerecha(&(*p)->der);
    }

    return contarHijosDerecha(&(*p)->izq);


}

int contarHijosIzquierda(t_arbol*p){

    if(!*p)return 0;

    if((*p)->izq){

        printf("\nHijo por izq: %d", ((*p)->izq)->info.num);

        return 1 + contarHijosIzquierda(&(*p)->izq) + contarHijosIzquierda(&(*p)->der);
    }

    return contarHijosIzquierda(&(*p)->der);


}

void podarHojas(t_arbol*p){

    t_nodo*aux;

    if(!*p)return;

    if(!(*p)->izq && !(*p)->der){

        aux=*p;

        *p=NULL;

        printf("\nPodando hoja: %d",aux->info.num);

        free(aux);

        return;
    }

    podarHojas(&(*p)->izq);
    podarHojas(&(*p)->der);

}

void eliminarArbol(t_arbol*p){

    if(!*p)return;

    printf("\nEliminando nodo %d",(*p)->info.num);

    eliminarArbol(&(*p)->izq);
    eliminarArbol(&(*p)->der);

    free(*p);

    *p =NULL;

    return;
}
