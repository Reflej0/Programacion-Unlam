#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    FILE*pf;
    t_indice indi;
    int dec,clave;


    cargar_bin("archivo.dat",&pf);

    printf("\nMostrar arch bin: ");

    mostrar_bin("archivo.dat",&pf);

    cargar_indice("archivo.dat",&pf,&indi,cmp);

    printf("\n\nMostrar lista de indice: ");

    mostrar_indice_desde_principio(&indi);

    do{
        printf("\n---menu indice--- \n1.Mostrar dato en clave seleccionada ");
        scanf("%d",&dec);

    switch(dec){
        case 1:printf("\nIngrese clave: ");
                scanf("%d",&clave);
                mostrar_dato_clave("archivo.dat",&pf,&indi,clave);
                break;
    }

    }while(dec!=0);



    return 0;
}
