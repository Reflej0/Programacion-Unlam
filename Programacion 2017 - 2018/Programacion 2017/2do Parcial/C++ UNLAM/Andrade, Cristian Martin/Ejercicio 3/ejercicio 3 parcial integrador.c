#include <stdio.h>
#include <stdlib.h>

void decodificar_cadena(char*);

int main ()
{
    char cadena[50] = "2bm4btbd2tf6bdobmc",cadena2[50] = "3zpi6fwfvmm";
    printf("Cadena 1 codificada: %s", cadena);
    printf("\nCadena 2 codificada: %s", cadena2);
    decodificar_cadena(cadena);
    decodificar_cadena(cadena2);
    printf("\nCadena 1 decodificada: %s", cadena);
    printf("\nCadena 2 decodificada: %s", cadena2);
    return 0;
}

///////////////////////////////////////
void decodificar_cadena(char*cad)
{
    char* aux1=NULL,*aux2=NULL;
    char auxiliar;
    int cantidadDeLetras,cont;
    while(*cad)
    {
        cont=0;
        if(*cad > '0'&& *cad <= '9')
        {
            cantidadDeLetras = (*cad-48);
            aux1=cad+1;
            aux2=cad+cantidadDeLetras;
        }
        while(cont < (cantidadDeLetras/2))
        {
            auxiliar=(*aux1-1);
            *aux1=(*aux2-1);
            *aux2=auxiliar;
            aux1++;
            aux2--;
            cont++;
        }
        if(aux1==aux2)
            *aux1 = (*aux1-1);
        *cad=' ';
        cad=cad+cantidadDeLetras+1;
    }
}
