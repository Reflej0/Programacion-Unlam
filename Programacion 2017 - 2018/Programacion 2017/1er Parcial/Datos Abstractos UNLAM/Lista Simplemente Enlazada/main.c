#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main()
{
    //lista simplemente enlazada sin repeticiones

    t_lista lista;
    int dec;

    crearLista(&lista);

    do{
        printf("\n-Lista simplemente enlazada sin repeticiones-");
        printf("\n1.crear lista \n2.Insertar al principio \n3.Insertar al final \n4.Eliminar de lista \n5.Vaciar lista \n6.Nostrar lista");
        scanf("%d",&dec);

        switch(dec){
        case 1:
            crearLista(&lista);
            break;
        case 2:
            if(!insertarAlPrincipio(&lista)){
                printf("\nError");
            }else{
                printf("\nInsertado");
            }
            break;
        case 3:
            if(!insertarAlFinal(&lista)){
                printf("\nError");
            }else{
                printf("\nInsertado");
            }
            break;
        case 4:
            if(!eliminardelista(&lista)){
                printf("\nlista vacia");
            }
            break;
        case 5:
            vaciarLista(&lista);
            break;
        case 6:
            if(!mostrarLista(&lista)){
                printf("\nLista vacia");
            }
            break;
        default:
            printf("\nnumero menu incorrecto");

        }
    }while(dec!=0);

    return 0;
}
