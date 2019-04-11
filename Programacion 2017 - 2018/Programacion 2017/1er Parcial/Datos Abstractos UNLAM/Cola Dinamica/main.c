#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main()
{
    //cola estatica
    t_cola cola;
    t_info info;
    int dec;

    crearCola(&cola);

    do{
        printf("\n-cola dinamica- \n0.Salir \n1.crear cola \n2.cola vacia \n3.cola llena \n4.acolar \n5.desacolar \n6.ver primero \n7.vaciar cola \n");
        scanf("%d",&dec);

        switch(dec){
        case 0:
            break;
        case 1:
            crearCola(&cola);
            break;
        case 2:
            if(colaVacia(&cola)){
                printf("\nCola vacia");
            }else{
                printf("\nCola no vacia");
            }
            break;
        case 3:
            if(colaLlena(&cola)){
                printf("\nCola llena");
            }else{
                printf("\nCola no llena");
            }
            break;
        case 4:
            if(acolar(&cola)){
                printf("\nAcolado");
            }else{
                printf("\nCola llena");
            }
            break;
        case 5:
            if(!desacolar(&cola,&info)){
                printf("\nCola vacia");
            }else{
                printf("\nDesacolado: %d",info.num);
            }
            break;
        case 6:
            if(!verPrimero(&cola)){
                printf("\nCola vacia");
            }
            break;
        case 7:
            vaciarCola(&cola);
            break;
        default:
            printf("\nNumero menu error");
        }

    }while(dec!=0);


    return 0;
}
