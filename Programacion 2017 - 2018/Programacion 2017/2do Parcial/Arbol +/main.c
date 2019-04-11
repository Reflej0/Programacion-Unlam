#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    t_arbol a;
    t_dato dato;
    int dec,nivel;
    t_nodo**aux;
    FILE*pf_arb;

    crear_arbol(&a);

    printf("\nCargar arbol? \n0.No \n1.No completo,no balanceado, no avl \n2.avl \n3.avl,balanceado \n4.avl,balanceado,completo ");

    scanf("%d",&dec);

    system("cls");

    if(dec != 0){

        cargar_arbol(&a,cmp,dec);
        recorrer_arbol_preorden(&a);
    }


    do{

        printf("\n\n-----Menu arbol-----\n1.insertar_en_arbol_iterativa \n2.recorrer_arbol_preorden \n3.recorrer_arbol_inorden \n4.recorrer_arbol_postorden");
        printf("\n5.insertar_en_arbol_recursiva \n6.buscar_en_arbol_bin \n7.Mostrar y contar hojas \n8.Mostrar y contar nodos no hojas");
        printf("\n9.contar hijos derecha y hijos izq \n10.borrar hojas \n11.Vaciar arbol \n12.altura arbol \n13.Contar nodos en nivel");
        printf("\n14.Arbol completo, balanceado, AVL");
        printf("\n15.Buscar_nodo \n16.Buscar mayor \n17.Buscar menor \n18.Eliminar de arbol \n19.Es avl,bal,comp clase");
        printf("\n20.Podar arbol desde nivel n \n21.Cargar arbol desde archivo ordenado");

        printf("\n");
        scanf("%d",&dec);

        switch(dec){

            case 1: insertar_dato(&dato);
                    if(insertar_en_arbol_iterativa(&a,&dato,cmp) == ERR_MALLOC){
                        printf("\nError malloc");
                    }else{
                        printf("\nDato insertado");
                        recorrer_arbol_preorden(&a);
                    }
                    break;

            case 2: recorrer_arbol_preorden(&a);
                    break;

            case 3: recorrer_arbol_inorden(&a);
                    break;

            case 4: recorrer_arbol_postorden(&a);
                    break;

            case 5: insertar_dato(&dato);
                    if(insertar_en_arbol_recursiva(&a,&dato,cmp) == ERR_MALLOC){
                        printf("\nError malloc\n");
                    }else{
                        printf("\nDato insertado\n");
                        recorrer_arbol_preorden(&a);
                    }
                    break;
            case 6: insertar_dato(&dato);
                    if(buscar_en_arbol_bin(&a,&dato,cmp) == 0){
                        printf("\nDato no encontrado");
                    }else{
                        printf("\nDato encontrado");
                        mostrar_dato(&dato);
                    }
                    break;
            case 7: printf("\nCantidad de hojas: %d",contar_y_mostrar_hojas(&a));
                    break;

            case 8: printf("\nCantidad de nodos no hojas: %d",contar_y_mostrar_nodos_no_hojas(&a));
                    break;

            case 9: printf("\nhijos derecha: %d",mostrar_y_constar_hder(&a));
                    printf("\nhijos izq: %d",mostrar_y_constar_hizq(&a));
                    break;

            case 10:printf("\nEstado actual del arbol: ");
                    recorrer_arbol_preorden(&a);
                    borrar_hojas(&a);
                    printf("\nEstado actual del arbol: ");
                    recorrer_arbol_preorden(&a);
                    break;

            case 11:printf("\nEstado actual del arbol: ");
                    recorrer_arbol_preorden(&a);
                    vaciar_arbol(&a);
                    printf("\nEstado actual del arbol: ");
                    recorrer_arbol_preorden(&a);
                    break;

            case 12:printf("\nLa altura es: %d",altura_arbol(&a));
                    break;

            case 13: printf("\nIngrese nivel: ");
                    scanf("%d",&nivel);
                    printf("\nLa cantidad de nodos en el nivel %d es de %d",nivel,contar_nodos_nivel(&a,nivel));
                    break;

            case 14: if(es_arbol_completo(&a)==0){
                        printf("\nNo es arbol completo");
                    }else{
                        printf("\nEs arbol completo");
                    }

                    if(es_arbol_balanceado(&a)==0){
                        printf("\nNo es arbol balanceado");
                    }else{
                        printf("\nEs arbol balanceado");
                    }

                    if(es_arbol_avl(&a)==0){
                        printf("\nNo es arbol avl");
                    }else{
                        printf("\nEs arbol avl");
                    }
                    break;

            case 15: insertar_dato(&dato);
                    aux = buscar_nodo(&a,&dato,cmp);

                    if(!aux){
                        printf("\nNodo no encontrado");
                    }else{
                        printf("\nNodo encontrado:");
                        mostrar_por_nodo(aux);
                    }
                    break;

            case 16: aux = mayor(&a);
                    if(!aux){
                        printf("\nNo existe");
                    }else{
                        mostrar_por_nodo(aux);
                    }
                    break;

            case 17: aux = menor(&a);
                    if(!aux){
                        printf("\nNo existe");
                    }else{
                        mostrar_por_nodo(aux);
                    }
                    break;
            case 18:insertar_dato(&dato);
                    if(eliminar_de_arbol(&a,&dato,cmp)==FALSO){
                        printf("\nEl nodo no se elimino");
                    }else{
                        printf("\nNodo eliminado, recorro por preorden: ");
                        recorrer_arbol_preorden(&a);
                    }
                    break;

            case 19: if(es_arbol_avl_clase(&a) == FALSO){
                        printf("\nNo es avl");
                        }else{
                            printf("\nEs avl");
                        }

                    if(es_arbol_balanceado_clase(&a) == FALSO){
                        printf("\nNo es balanceado");
                    }else{
                        printf("\nEs balanceado");
                    }

                    if(es_arbol_completo_clase(&a) == FALSO){
                        printf("\nNo es completo");
                    }else{
                        printf("\nEs completo");
                    }

                    break;

            case 20: printf("\nIngrese nivel: ");
                    scanf("%d",&nivel);

                    printf("\nArbol antes de podar: ");
                    recorrer_arbol_preorden(&a);

                    podar_arbol_desde_nivel_n(&a,nivel);

                    printf("\nArbol podado desde nivel %d, recorro: ",nivel);

                    recorrer_arbol_preorden(&a);
                    break;

            case 21: pf_arb = fopen("arbol inorden.txt","rt");
                    if(!pf_arb){
                        printf("\nError al abrir archivo");
                    }else{

                        if(cargar_arbol_de_arch_ord(&a,pf_arb,cmp) == TODO_OK){

                            printf("\nArbol cargado, recorro: ");
                            recorrer_arbol_preorden(&a);

                        }else{
                            printf("\nError alc argar arbol");
                        }

                        fclose(pf_arb);
                    }
                    break;

        }
    }while(dec!=0);

    return 0;
}
