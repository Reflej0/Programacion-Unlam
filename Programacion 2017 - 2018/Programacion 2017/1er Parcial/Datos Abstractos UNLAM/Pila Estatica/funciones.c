#include <stdio.h>
#include <stdlib.h>

#include "header.h"

void crearPila(t_pila*p){

    p->tope=0;
}
void vaciarPila(t_pila*p){

    p->tope=0;
}
int pilaLlena(t_pila*p,int tam){

    if(p->tope == (tam))return 1;

    return 0;
}
int pilaVacia(t_pila*p){

    if(p->tope == 0){
        return 1;
    }else{
        return 0;
    }
}
void apilar(t_pila*p,int tam){

    t_info inf;

    if(pilaLlena(p,tam)==1){
        printf("\nNo se peude apilar porque esta llena");
        return;
    }

    printf("\nIngrese numero a apilar: ");
    scanf("%d",&inf.num);



    p->info[p->tope] = inf;

    p->tope++;


}
int desapilar(t_pila*p,t_info*inf,int tam){

    t_info in;

    if(pilaVacia(p)==1){
        printf("\nNo se puede desapilar la pila esta vacia");
        return 0;
    }

    in = p->info[p->tope-1];

    inf->num = in.num;

    p->tope--;

    return 1;
}
void vertope(t_pila*p,int tam){

    if(pilaVacia(p)==1){
        printf("\nNo se peude ver el tope la pila esta vacia");
        return;
    }

    printf("\nTope: %d",p->info[p->tope]);

}
