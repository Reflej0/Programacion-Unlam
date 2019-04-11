#include<stdio.h>

void rellenar (int *v, int tope);
void ordenar (int *v, int tope);
void mostrar(int* v, int tope);

int main()
{
    int tope = 10;
    int vec[10];

    rellenar(vec, tope);
    ordenar(vec, tope);
    mostrar(vec, tope);
    return 1;
}

void rellenar(int *v, int tope)
{
    int i=0;
    for(i=0; i<tope; i++)
    {
        printf("rellenar vector:");
        scanf("%d", &v[i]);
    }
}

void ordenar(int *v, int tope)
{
    int j=0, k=0, aux;
    for(j=1; j<tope; j++)
    {
      for(k=0; k<tope-1; k++)
      {
            if(v[k]>v[k+1])
            {
                aux = v[k];
                v[k] = v[k+1];
                v[k+1] = aux;
            }
      }
    }
}

void mostrar(int* v, int tope)
{
    int i;
    for(i=0; i<tope; i++)
    {
        printf("%d\n", v[i]);
    }
}
