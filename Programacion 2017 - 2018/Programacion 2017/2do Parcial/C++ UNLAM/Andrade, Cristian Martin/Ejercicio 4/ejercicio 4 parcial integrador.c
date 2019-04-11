#include <stdio.h>
#include <stdlib.h>
#define COL 3

int esMatrizIdentidad(int[][COL]);
int main ()
{
    int mat[][COL]={{1,0,0},
                    {0,1,1},
                    {0,0,1}};
    if(esMatrizIdentidad(mat))
        printf("\nEs la matriz identidad");
    else
        printf("\nNo es la matriz identidad");
    return 0;
}

///////////////////////////////////////////////
int esMatrizIdentidad(int m[][COL])
{
    int i,j,esIdentidad=1;

    for(i=0;i<COL;i++)
        for(j=0;j<COL;j++)
        {
            if((i==j&&m[i][j]!=1) || (i!=j&&m[i][j] != 0))
                esIdentidad=0;
        }
    return esIdentidad;
}
