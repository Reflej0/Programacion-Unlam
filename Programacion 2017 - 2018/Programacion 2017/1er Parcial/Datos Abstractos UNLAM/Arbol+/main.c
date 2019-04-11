#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main()
{
    int dec;
    t_arbol a=NULL;
    t_info d;

    cargaAutomatica(&a);
    printf("\nArbol cargado Automaticamente");

    do{
        printf("\n--Arbol-- \n1.Insertar Iterativa \n2.Insertar recursiva \n3.Mostrar preorden \n4.Mostrar InOrden \n5.Mostrar PosOrden");
        printf("\n6.Carga automatica \n7.Buscar Elemento \n8.Mostrar y contar hojas \n9.Contar nodos no hojas \n10.Contar hijos derecha \n11.Contar hijos izquierda");
        printf("\n12.podar hojas \n13.Eliminar arbol ");
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
        case 6:
            cargaAutomatica(&a);
            break;
        case 7:
            cargarInfo(&d);
            buscarElemento(&a,&d);
            break;
        case 8:
            printf("\nCantidad hojas: %d",mostrarYcontarHojas(&a));
            break;
        case 9:
            printf("\nCantidad nodos no hojas: %d",cantidadNodosNoHojas(&a));
            break;
        case 10:
            printf("\nCantidad hijos derecha: %d",contarHijosDerecha(&a));
            break;
        case 11:
            printf("\nCantidad hijos izquierda: %d",contarHijosIzquierda(&a));
            break;
        case 12:
            podarHojas(&a);
            break;
        case 13:
            eliminarArbol(&a);
            break;
        default:
            printf("\nNumero incorrecto de menu");
        }
    }while(dec!=0);

    return 0;
}
