#include <stdio.h>
#include <stdlib.h>
#include "cola_circular_estatica.h"


void ingresar_dato(t_info*inf){

    printf("\nIngrese el dato: ");
    scanf("%d",&inf->num);
}

void crear_cola(t_cola*cola){

    cola->tam=5;
    cola->primElem=0;
    cola->cantElem=0;
    cola->ultElem=-1;
}

void recorrer_cola_est(t_cola*cola){

    int i=cola->primElem;
    int j=0;

    if(cola->cantElem == 0){
        printf("\ncola vacia");
        return;
    }

    while(j != cola->cantElem){

        printf("\n%d pos: %d",cola->vec[i],i);

        if(i == cola->primElem && i==cola->ultElem){
            printf(" <--primero y ultimo");
        }else if(i == cola->primElem){
            printf(" <--primero");
        }else if(i == cola->ultElem){
            printf(" <--ultimo");
        }



        if(i == cola->tam-1){
            i=0;
        }else{
            i++;
        }
        j++;
    }

}

void acolar(t_cola*cola,t_info*inf){

    if(cola->cantElem>=cola->tam){
        printf("\nCola llena");
        return;
    }

    if(cola->ultElem+1 > cola->tam-1){
        cola->ultElem = 0;
    }else{
        cola->ultElem++;
    }
    cola->cantElem++;
    cola->vec[cola->ultElem] = *inf;

    printf("\nIngresado en pos: %d",cola->ultElem);

    return;

}

int desacolar(t_cola*cola,t_info*inf){

    if(cola->cantElem ==0){
        return 0;
    }

    *inf = cola->vec[cola->primElem];

    cola->cantElem--;

    cola->primElem++;

    if(cola->primElem > cola->tam-1){
        cola->primElem = 0;
    }

    return 1;
}

void ver_principio(t_cola*cola){

    if(cola->cantElem==0){
        printf("\ncola vacia");
        return;
    }

    printf("\nprimero es %d",cola->vec[cola->primElem]);
}

void cola_llena(t_cola*cola){

    if(cola->cantElem >= cola->tam){
        printf("\nCola llena");
    }else{
        printf("\nCola no llena");
    }
}

void cola_vacia(t_cola*cola){

    if(cola->cantElem ==0){
        printf("\nCola vacia");
    }else{
        printf("\nCola no vacia");
    }
}

void vaciar(t_cola*cola){

    cola->tam=5;
    cola->primElem=0;
    cola->cantElem=0;
    cola->ultElem=-1;
}
