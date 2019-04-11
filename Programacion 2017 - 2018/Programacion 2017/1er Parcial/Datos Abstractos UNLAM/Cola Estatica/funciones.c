#include <stdio.h>
#include <stdlib.h>

#include "header.h"

void crearCola(t_cola*c){

    c->pri=0;
    c->ult=0;
}
int colaVacia(t_cola*c){

    return (c->pri==0 && c->ult==0);
}
int colaLlena(t_cola*c){

    return (c->ult == TAM);
}
int acolar(t_cola*c){

    if(colaLlena(c))return 0;

    printf("\nIngrese numero a acolar: ");
    scanf("%d",&c->info[c->ult]);

    c->ult++;
}

int desacolar(t_cola*c,t_info*inf){

    int i;

    //testing de tener todo siempre a la derecha

    if(colaVacia(c))return 0;

    *inf = c->info[c->pri];

    //corro todo a la derecha

    for(i=0;i<(c->ult);i++){

        c->info[i] = c->info[i+1];

    }

    c->ult--;
}
int verPrimero(t_cola*c){

    if(colaVacia(c))return 0;

    printf("\nPrimero: %d",c->info[c->pri].num);

    return 1;
}
void vaciarCola(t_cola*c){

    c->pri=0;
    c->ult=0;
}
