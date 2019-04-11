#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

int main()
{
    int i, j; // Variables para ciclos.
    int k, z;
    int matriz[2][2] = {10, 20, 30, 40}; //Para no ingresar por teclado.
    int matriz2[2][2] = {50, 60, 70, 80}; //Para no ingresar por teclado.
    int registros = sizeof(matriz)/sizeof(int); // Obtengo la cantidad de registros de la matriz.
    int columnas = sizeof(matriz[0])/sizeof(int); // Obtengo la cantidad de columnas de la matriz.
    int filas = registros / columnas; // Obtengo la cantidad de filas de la matriz2.
    int registros2 = sizeof(matriz2)/sizeof(int); // Obtengo la cantidad de registros de la matriz.
    int columnas2 = sizeof(matriz2[0])/sizeof(int); // Obtengo la cantidad de registros de la matriz.
    int filas2 = registros2 / columnas2; // Obtengo la cantidad de registros de la matriz.
    int vector[4] = {0};
    if(registros == registros2) { // Verifico si las matrices son compatibles para la multiplicacion.
        if(filas == filas2){ // Verifico si las matrices tienen la misma cantidad de filas y columnas.
             // Matriz que contendra el resultado de la multiplicacion.
     for(i=0; i<filas; i++)
        for(j=0; j<columnas2; j++)
            for(k=0; k<columnas; ++k)
            {
                result[i][j]+=a[i][k]*b[k][j];
            }
        }
        else{ // La multiplicacion es posible pero tienen distintas filas y columnas.

        }
    }
    else{
        puts("Las matrices no son compatibles para la multiplicacion");
    }
}
