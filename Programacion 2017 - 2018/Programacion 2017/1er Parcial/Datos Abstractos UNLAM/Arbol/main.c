#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main()
{
    int dec;
    t_arbol a=NULL;
    t_info d;

    do{
        printf("\n--Arbol-- \n1.Insertar Iterativa \n2.Insertar recursiva \n3.Mostrar preorden \n4.Mostrar InOrden \n5.Mostrar PosOrden");
        scanf("%d",&dec);

        switch(dec){

        case 1:
            cargarInfo(&d);
            if(!insertarIterativa(&a,&d)){
                printf("\nError malloc");
            }
            break;
        case 2:
            cargarInfo(&d);
            if(!insertarrecursiva(&a,&d)){
                printf("\nError malloc");
            }
            break;
        case 3:
            mostrarPreOrden(&a);

            break;
        case 4:
            mostrarInOrden(&a);

            break;
        case 5:
            mostrarPosOrden(&a);

            break;
        default:
            printf("\nNumero incorrecto de menu");
        }
    }while(dec!=0);

    return 0;
}
