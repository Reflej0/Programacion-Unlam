#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main()
{
    //lista simplemente enlazada con repeticiones

    t_lista lista;
    t_info d;
    int dec,num;

    crearLista(&lista);

    do{
        printf("\n\n-Lista doblemente enlazada sin repeticiones-");
        printf("\n1.crear lista doblemente enlazada \n2.Insertar al principio \n3.Insertar al final \n4.recorrer desde principio \n5.recorrer desde final");
        scanf("%d",&dec);

        switch(dec){
        case 1:
            crearLista(&lista);
            break;
        case 2:
            cargarInfo(&d);
            if(!insertarAlPrincipio(&lista,&d)){
                printf("\nError malloc");
            }else{
                printf("\nInsertado");
            }
            recorrerDesdePrincipio(&lista);
            break;
        case 3:
            cargarInfo(&d);
            if(!insertarAlFinal(&lista,&d)){
                printf("\nError malloc");
            }else{
                printf("\nInsertado");
            }
            recorrerDesdePrincipio(&lista);
            break;
        case 4:

            if(!recorrerDesdePrincipio(&lista)){
                printf("\nLista vacia");
            }

            break;

        case 5:
            if(!recorrerDesdeFinal(&lista)){
                printf("\nLista vacia");
            }
            break;
        default:
            printf("\nnumero menu incorrecto");

        }
    }while(dec!=0);

    return 0;
}
