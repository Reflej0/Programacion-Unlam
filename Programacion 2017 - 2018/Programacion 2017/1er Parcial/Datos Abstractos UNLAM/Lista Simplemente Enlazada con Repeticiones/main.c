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
        printf("\n\n-Lista simplemente enlazada con repeticiones-");
        printf("\n1.crear lista \n2.Insertar contando repeticiones \n3.Eliminar repeticiones \n4.insertar en lista en orden actualizar \n5.Mostrar lista");
        scanf("%d",&dec);

        switch(dec){
        case 1:
            crearLista(&lista);
            break;
        case 2:
            cargarInfo(&d);
            if(!insertarContandoRep(&lista,&d)){
                printf("\nError malloc");
            }else{
                printf("\nInsertado");
            }
            mostrarLista(&lista);
            break;
        case 3:
            cargarInfo(&d);

            if(!eliminarRep(&lista,&d)){
                printf("\nNo se elimino nada");
            }
            mostrarLista(&lista);
            break;
        case 4:
            cargarInfo(&d);
            if(!insertarEnListaEnOrdenActualizar(&lista,&d,compararMenoraMayor)){
                printf("\nError malloc");
            }else{
                printf("\nInsertado");
            }
            mostrarLista(&lista);

            break;

        case 5:
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
