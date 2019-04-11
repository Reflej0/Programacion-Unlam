#include <stdio.h>
#include <stdlib.h>
#define COL 5
#define FIL 3
void invertirFilas(int mat[][COL]);
void simetrizar(int mat[][COL]);
void mostrarMatriz(int mat[][COL]);
int main()
{
    int mat[FIL][COL]={
                    {3,2,1,0,1},
                    {2,3,4,5,6},
                    {7,8,9,10,11}
                   };
    mostrarMatriz(mat);
    puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
    simetrizar(mat);
    mostrarMatriz(mat);
    puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
    simetrizar(mat);
    invertirFilas(mat);
    mostrarMatriz(mat);
    return 0;
}
void invertirFilas(int mat[][COL])
{
    int i,j,aux;

    for(i=0;i<FIL/2;i++)
    {
        for(j=0;j<COL;j++)
        {
            aux=mat[i][j];
            mat[i][j]=mat[FIL-1-i][j];
            mat[FIL-1-i][j]=aux;
        }

    }
}
void simetrizar(int mat[][COL])
{
    int i,j,aux,filas_a_recorrer=FIL/2;

    for(i=0;i<filas_a_recorrer;i++)
    {

        for(j=0;j<COL;j++)
        {
            aux=mat[FIL-1-i][COL-1-j];
            mat[FIL-1-i][COL-1-j]=mat[i][j];
            mat[i][j]=aux;
        }
    }

    if(FIL%2==0)
        return;

    for(j=0;j<COL/2;j++)
        {
            aux=mat[FIL-1-i][COL-1-j];
            mat[FIL-1-i][COL-1-j]=mat[i][j];
            mat[i][j]=aux;
        }

}
void mostrarMatriz(int mat[][COL])
{
    int i,j;

    for(i=0;i<FIL;i++)
    {
        for(j=0;j<COL;j++)
            printf("%d\t",mat[i][j]);
        puts("\n");
    }
}
