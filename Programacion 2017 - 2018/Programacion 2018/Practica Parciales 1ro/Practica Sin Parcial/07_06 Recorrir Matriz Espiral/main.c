#include <stdio.h>
#include <stdlib.h>


int mostrarEnEspiral (int fmax, int cmax, int matriz[fmax][cmax]) {
    int fmin=0;
    int cmin=0;
    int f=0;
    int c=-1;
    while (fmin<fmax && cmin<cmax) {
        for (c++;c<cmax;c++)
            printf ("%d, ",matriz[f][c]);
        fmin++;
        c--;
        for (f++;f<fmax;f++)
            printf ("%d, ",matriz[f][c]);
        cmax--;
        f--;
        for (c--;c>=cmin;c--)
            printf ("%d, ",matriz[f][c]);
        fmax--;
        c++;
        for (f--;f>=fmin;f--)
            printf ("%d, ",matriz[f][c]);
        cmin++;
        f++;
    }
    return 1;
}

int main()
{
    int m[3][2] = {{1, 4},{2, 5},{3, 6}};
    int m2[2][3] = {{1, 2, 3},{4, 5, 6}};
    mostrarEnEspiral(3, 2, m);
    return 1;
}
