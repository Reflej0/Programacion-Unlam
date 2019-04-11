#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main()
{
    //PILA CIRCULAR

    t_lista pila;


    t_info d;
    int dec,num;

    crearLista(&pila);

    do{
        printf("\n\n-pila circular simple-");
        printf("\n1.crear pila circular \n2.vaciar \n3.pila llena \n4.pila vacia \n5.apilar \n6.desapilar \n7.Ver tope \n8.Recorrer pila");
        scanf("%d",&dec);

        switch(dec){
        case 1:
            crearLista(&pila);
            break;
        case 2:

            vaciar(&pila);
            break;
        case 3:

            if(!pilallena(&pila)){
                printf("\nPila no llena");
            }else{
                printf("\nPila llena");
            }

            break;
        case 4:

            if(pilaVacia(&pila)){
                printf("\nPila vacia");
            }else{
                printf("\nPila no vacia");
            }

            break;

        case 5:
            cargarInfo(&d);
            if(!apilar(&pila,&d)){
                printf("\nError");
            }else{
                printf("\nApilado");
            }

            if(!recorrerPila(&pila)){
                printf("\nPila vacia");
            }

            break;
        case 6:
            if(!desapilar(&pila,&d)){
                printf("\nPila vacia");
            }else{
                printf("\nDesapilado %d",d.num);
            }

            if(!recorrerPila(&pila)){
                printf("\nPila vacia");
            }

            break;
        case 7:
            if(!verTope(&pila)){
                printf("\nPila vacia");
            }
            break;
        case 8:
            if(!recorrerPila(&pila)){
                printf("\nPila vacia");
            }
            break;
        default:
            printf("\nnumero menu incorrecto");

        }
    }while(dec!=0);

    return 0;
}
