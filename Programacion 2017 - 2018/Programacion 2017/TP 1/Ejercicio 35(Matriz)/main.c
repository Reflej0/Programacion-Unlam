#include <stdio.h>
#include <stdlib.h>

int transponermatriz(int columnas, int filas, int matriz[columnas][filas])
{
    int i, j;
    int matriztranspuesta[columnas][filas];
    //INICIALIZACION DE LA MATRIZ TRANSPUESTA.
    for(i=0;i<columnas;i++){
        for(j=0;j<columnas;j++){
            matriztranspuesta[i][j] = 0;
        }
    }

    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
                    matriztranspuesta[j][i] = matriz[i][j];
            }
        }
    puts("\n");
    puts("\n");
    puts("\n");
    for(i=0;i<columnas;i++){
        for(j=0;j<filas;j++){
            printf("%d\t", matriztranspuesta[i][j]);
        }
        puts("\n");
    }
}

int main()
{
    int i, j, filas, columnas;
    puts("Ingrese las columnas de la matriz:");
    scanf("%d", &columnas);
    puts("Ingrese las filas de la matriz:");
    scanf("%d", &filas);
    int matriz[filas][columnas];
    int matriztranspuesta[columnas][filas];
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            puts("Ingrese un numero:");
            scanf("%d", &matriz[i][j]);
        }
    }
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
                    matriztranspuesta[j][i] = matriz[i][j];
            }
        }
    puts("\n");
    puts("\n");
    puts("\n");
    for(i=0;i<columnas;i++){
        for(j=0;j<filas;j++){
            printf("%d\t", matriztranspuesta[i][j]);
        }
        puts("\n");
    }
    return 0;
}
