#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main()
{
    //Cola CIRCULAR

    t_lista cola;


    t_info d;
    int dec,num;

    crearLista(&cola);

    do{
        printf("\n\n-cola circular simple-");
        printf("\n1.crear cola circular \n2.vaciar \n3.cola llena \n4.cola vacia \n5.acolar \n6.desacolar \n7.Ver principio \n8.Recorrer cola");
        scanf("%d",&dec);

        switch(dec){
        case 1:
            crearLista(&cola);
            break;
        case 2:

            vaciar(&cola);
            break;
        case 3:

            if(!colallena(&cola)){
                printf("\ncola no llena");
            }else{
                printf("\ncola llena");
            }

            break;
        case 4:

            if(colaVacia(&cola)){
                printf("\ncola vacia");
            }else{
                printf("\ncola no vacia");
            }

            break;

        case 5:
            cargarInfo(&d);
            if(!acolar(&cola,&d)){
                printf("\nError");
            }else{
                printf("\nAcolado");
            }

            if(!recorrercola(&cola)){
                printf("\ncola vacia");
            }

            break;
        case 6:
            if(!desacolar(&cola,&d)){
                printf("\ncola vacia");
            }else{
                printf("\nDesacolado %d",d.num);
            }

            if(!recorrercola(&cola)){
                printf("\ncola vacia");
            }

            break;
        case 7:
            if(!verTope(&cola)){
                printf("\ncola vacia");
            }
            break;
        case 8:
            if(!recorrercola(&cola)){
                printf("\ncola vacia");
            }
            break;
        default:
            printf("\nnumero menu incorrecto");

        }
    }while(dec!=0);

    return 0;
}
