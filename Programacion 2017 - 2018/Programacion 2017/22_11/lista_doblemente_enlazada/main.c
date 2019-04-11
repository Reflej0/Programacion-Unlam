#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    t_lista lista;
    t_info dato;
    int dec;

    crear_lista(&lista);

    do{
        printf("\n-----Menu-----\n1.Insertar principio \n2.Recorrer desde principio \n3.Recorrer desde el final \n4.Insertar al final");
        printf("\n5.Eliminar de lista \n6.Vaciar lista \n7.Ordenar lista");
        scanf("%d",&dec);

        switch(dec){
            case 1:ingresar_dato(&dato);
                    if(insertar_al_principio(&lista,&dato) == ERR_MALLOC){
                        printf("\nError malloc");
                    }else{
                        printf("\nInsertado");
                    }
                    if(recorrer_desde_principio(&lista)==LISTA_VACIA){
                        printf("\nLista vacia");
                    }
                    break;
            case 2: if(recorrer_desde_principio(&lista)==LISTA_VACIA){
                        printf("\nLista vacia");
                    }
                    break;
            case 3: if(recorrer_desde_final(&lista)==LISTA_VACIA){
                        printf("\nLista vacia");
                    }
                    break;

            case 4: ingresar_dato(&dato);
                    if(insertar_al_final(&lista,&dato) == ERR_MALLOC){
                        printf("\nError malloc");
                    }else{
                        printf("\nInsertado");
                    }
                    if(recorrer_desde_principio(&lista)==LISTA_VACIA){
                        printf("\nLista vacia");
                    }
                    break;
            case 5: ingresar_dato(&dato);
                    if(eliminar_de_lista(&lista,&dato,cmp)== NO_ESTA){
                        printf("\nDato no encontrado");
                    }else{
                        printf("\nDato eliminado");
                        recorrer_desde_principio(&lista);
                    }
                    break;
            case 6: vaciar_lista(&lista);
                    printf("\nLista vaciada");
                    recorrer_desde_principio(&lista);
                    break;
            case 7: ordenar_lista(&lista,cmp);
                    printf("\nLista ordenada");
                    recorrer_desde_principio(&lista);
                    break;
        }
    }while(dec!= 0);

    return 0;
}
