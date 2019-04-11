#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main()
{
    //LISTA CIRCULAR

    t_lista listaHead;
    t_lista listaTail;

    t_info d;
    int dec,num;

    crearLista(&listaHead,&listaTail);

    do{
        printf("\n\n-Lista circular simple-");
        printf("\n1.crear lista circular \n2.Insertar al principio \n3.Insertar al final \n4.recorrer desde principio \n5.vaciar lista");
        scanf("%d",&dec);

        switch(dec){
        case 1:
            crearLista(&listaHead,&listaTail);
            break;
        case 2:
            cargarInfo(&d);
            if(!insertarAlPrincipio(&listaHead,&listaTail,&d)){
                printf("\nError malloc");
            }else{
                printf("\nInsertado");
            }
            recorrerDesdePrincipio(&listaHead,&listaTail);
            break;
        case 3:
            cargarInfo(&d);
            if(!insertarAlFinal(&listaHead,&listaTail,&d)){
                printf("\nError malloc");
            }else{
                printf("\nInsertado");
            }
            recorrerDesdePrincipio(&listaHead,&listaTail);
            break;
        case 4:

            if(!recorrerDesdePrincipio(&listaHead,&listaTail)){
                printf("\nLista vacia");
            }

            break;

        case 5:
            if(!vaciarLista(&listaHead,&listaTail)){
                printf("\nLista vacia");
            }
            break;
        default:
            printf("\nnumero menu incorrecto");

        }
    }while(dec!=0);

    return 0;
}
