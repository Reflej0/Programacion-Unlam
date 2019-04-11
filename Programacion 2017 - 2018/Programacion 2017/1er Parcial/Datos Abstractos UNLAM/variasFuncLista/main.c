#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    t_lista lista;
    t_dato d;
    int dec;

    crear_lista(&lista);

    do{
        printf("\n\n---menu lista---\n 0.Salir \n1.recorrer lista \n2.poner en lista desordenado \n3.poner en lista ordenado \n4.Sacar Elemento por llave");
        printf("\n5.Sacar ultimo \n6.Ordenar lista");
        scanf("%d",&dec);

        switch(dec){
            case 0:break;
            case 1:recorrer_lista_simple(&lista);
                    break;
            case 2:ingresar_dato(&d);
                    if(poner_en_lista_desordenado(&lista,&d) == ERR_MALLOC){
                        puts("\nError malloc");
                    }
                    recorrer_lista_simple(&lista);
                    break;
            case 3:ingresar_dato(&d);
                    if(poner_en_lista_ordenado(&lista,&d,cmp) == ERR_MALLOC){
                        puts("\nError malloc");
                    }
                    recorrer_lista_simple(&lista);
                    break;

            case 4: ingresar_dato(&d);
                    if(sacar_elemento_por_llave(&lista,&d,cmp) == TODO_OK){

                        printf("\nDato sacado= ");
                        mostrar_dato(&d);
                    }else{
                        puts("\nDato no encntrado");
                    }
                    recorrer_lista_simple(&lista);
                    break;
            case 5: if(sacar_ultimo(&lista,&d) == TODO_OK){
                        printf("\nDato sacado= ");
                        mostrar_dato(&d);
                    }else{

                        printf("\nLista vacia");
                    }
                    recorrer_lista_simple(&lista);
                    break;
            case 6: ordenar_lista(&lista,cmp);
                    recorrer_lista_simple(&lista);
                    break;
        }
    }while(dec != 0);
    return 0;
}
