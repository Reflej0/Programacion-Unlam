#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"
#define TAM 10

int main()
{
    int opcion = 0;
    int lote_1[TAM]; // Array vacio.
    //Vector con elementos ordenados en forma ascendente(con espacio).
    int lote_2[TAM] = {2, 4, 7, 8, 11, 17, 22, 30, 0, 0};
    //Vector con elementos ordenados en forma ascendente(sin espacio).
    //int lote_2[TAM] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    //Vector con elementos repetidos.
    int lote_3[TAM] = {2, 4, 6, 2, 8, 10, 10, 14, 16, 2};
    do
    {
        system("CLS"); // Limpieza de pantalla.
        printf("EJERCICIOS CON VECTORES UNIDIMENSIONALES\n");
        printf("\n1)Insertar un elemento en un arreglo de enteros dado la posicion.");
        printf("\n2)Insertar un elemento en un arreglo de enteros en forma ascendente.");
        printf("\n3)Eliminar un elemento en un arreglo de enteros dado la posicion.");
        printf("\n4)Eliminar la primera aparicion de un elemento en un arreglo de enteros.");
        printf("\n5)Eliminar todas las apariciones de un elemento en un arreglo de enteros.");
        printf("\n0)Salir.");
        printf("\nOpcion:");
        scanf("%d", &opcion);
        switch(opcion)
        {
            //Variables comunes a los case.
            int elemento;
            int posicion;
            int correcto;
        case 1:
            system("CLS"); // Limpieza de pantalla.
            printf("Ingrese el elemento a insertar:");
            scanf("%d", &elemento);
            printf("\nIngrese la posicion a insertar:");
            scanf("%d", &posicion);
            correcto = Insertar_Elemento_Vector(lote_1, TAM, elemento, posicion);
            if(correcto == 1)
            {
                Mostrar_Vector(lote_1, TAM);
                system("PAUSE");
            }
            else
            {
                printf("Revise la posicion ingresada.");
                system("PAUSE");
            }
            break;
        case 2:
            system("CLS"); // Limpieza de pantalla.
            printf("Ingrese el elemento a insertar:");
            scanf("%d", &elemento);
            //correcto = Insertar_Elemento_Ordenado_Vector(lote_2, TAM, elemento);
            correcto = Insertar_Elemento_Ordenado_Vector_2(lote_2, TAM, elemento);
            if(correcto == 1)
            {
               Mostrar_Vector(lote_2, TAM);
               system("PAUSE");
            }
            else
            {
                printf("Vector lleno");
                system("PAUSE");
            }
            break;
        case 3:
            system("CLS"); // Limpieza de pantalla.
            printf("Ingrese la posicion a eliminar:");
            scanf("%d", &posicion);
            correcto = Eliminar_Elemento_Posicion_Vector(lote_3, TAM, posicion);
            if(correcto == 1)
            {
                Mostrar_Vector(lote_3, TAM);
                system("PAUSE");
            }
            else
            {
                printf("Revise la posicion ingresada.");
                system("PAUSE");
            }
            break;
        case 4:
            system("CLS"); // Limpieza de pantalla.
            printf("Ingrese el elemento a eliminar:");
            scanf("%d", &elemento);
            Eliminar_Primera_Aparicion_Elemento_Vector(lote_3, TAM, elemento);
            Mostrar_Vector(lote_3, TAM);
            system("PAUSE");
            break;
        case 5:
            system("CLS"); // Limpieza de pantalla.
            printf("Ingrese el elemento a eliminar:");
            scanf("%d", &elemento);
            int eliminados = Eliminar_Todas_Apariciones_Elemento_Vector(lote_3, TAM, elemento);
            printf("Elementos eliminados: %d\n", eliminados);
            Mostrar_Vector(lote_3, TAM);
            system("PAUSE");
            break;
        default:
            break;
        }
    }
    while(opcion!=0);
    return 0;
}
