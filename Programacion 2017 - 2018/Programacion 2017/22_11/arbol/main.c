#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int dec,nivel;
    t_arbol a;
    t_info d;
    FILE*pf;

    crear_arbol(&a);

    printf("\n0.No cargar arbol \n1.Cargar arbol no avl,no bal,no comp \n2.Cargar arbol avl \n3.Cargar arbol Balanceado \n4.cargar arbol completo");
    scanf("%d",&dec);

    if(dec!=0){
        cargar_arbol(&a,dec,cmp);
        printf("\nArbol cargado: ");recorrer_pre(&a);
    }


    do{
        printf("\n\n1.Insertar Iterativa \n2.recorrer preorden, inorden y postorden \n3.insertar recursivo \n4.buscar \n5.Mostrar y contar hojas");
        printf("\n6.mostrar y contar no hojas \n7.Mostrar y contar hijos izq y der \n8.borrar hojas \n9.vaciar arbol \n10.Altura arbol");
        printf("\n11.Contar nodos en nivel \n12.arbol avl,balanceado,completo \n13.cargar arbol desde archivo ordenado");
        scanf("%d",&dec);

        switch(dec){
            case 1:ingresar_info(&d);
                    if(insertar_iterativo(&a,&d,cmp)==0){
                        printf("\nError a insertar");
                    }else{
                        printf("\nInsertado,recorro pre: ");
                        printf("\nPreorden: ");recorrer_pre(&a);
                        printf("\nInorden: ");recorrer_in(&a);
                        printf("\nPostorden: ");recorrer_post(&a);
                    }
                    break;
            case 2:printf("\nPreorden: ");recorrer_pre(&a);
                    printf("\nInorden: ");recorrer_in(&a);
                    printf("\nPostorden: ");recorrer_post(&a);
                    break;
            case 3:ingresar_info(&d);
                    if(insertar_recursivo(&a,&d,cmp)==0){
                        printf("\nError a insertar");
                    }else{
                        printf("\nInsertado,recorro pre: ");
                        printf("\nPreorden: ");recorrer_pre(&a);
                        printf("\nInorden: ");recorrer_in(&a);
                        printf("\nPostorden: ");recorrer_post(&a);
                    }
                    break;
            case 4:ingresar_info(&d);
                    if(buscar_existencia(&a,&d,cmp)==1){
                        printf("\nExiste");
                    }else{
                        printf("\nNo existe");
                    }
                    break;
            case 5:printf("\nCantidad hojas: %d",mostrar_y_contar_hojas(&a));
                    break;
            case 6:printf("\nCantidad no hojas: %d",mostrar_y_contar_no_hojas(&a));
                    break;
            case 7:printf("\nCantidad Hijos izq: %d",mostrar_y_contar_hizq(&a));
                    printf("\nCantidad Hijos der: %d",mostrar_y_contar_hder(&a));
                    break;
            case 8: printf("\nHojas borradas: %d",borrar_hojas(&a));
                    printf("\nRecorro luego de borrar hojas: ");recorrer_pre(&a);
                    break;
            case 9: vaciar_arbol(&a);
                    printf("\nRecorro luego de vaciar: ");recorrer_pre(&a);
                    break;
            case 10:printf("\nAltura: %d",altura_arbol(&a));
                    break;
            case 11:printf("\nprintf Ingrese nivel: ");scanf("%d",&nivel);
                    printf("\nNodos en nivel: %d",contar_nodos_en_nivel(&a,nivel));
                    break;
            case 12:if(es_avl(&a)==0){
                        printf("\nNo es avl");
                    }else{
                        printf("\nEs avl");
                    }
                    if(es_balanceado(&a)==0){
                        printf("\nNo es balanceado");
                    }else{
                        printf("\nEs balanceado");
                    }
                    if(es_completo(&a)==0){
                        printf("\nNo es completo");
                    }else{
                        printf("\nEs completo");
                    }
                    break;
            case 13:cargar_arch_bin("archivo.dat",&pf);
                    cargar_arbol_desde_archivo_ord(&a,"archivo.dat",&pf,cmp,0,19);
                    printf("\nInsertado,recorro pre: ");
                    printf("\nPreorden: ");recorrer_pre(&a);
                    printf("\nInorden: ");recorrer_in(&a);
                    printf("\nPostorden: ");recorrer_post(&a);

        }
    }while(dec!=0);
    return 0;
}
