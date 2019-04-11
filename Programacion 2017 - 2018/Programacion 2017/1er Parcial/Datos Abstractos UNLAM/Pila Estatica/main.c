#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main()
{
    //pila estatica

    int dec;
    t_pila p;
    t_info inf;

    do{
        printf("\n-Pila estatica- \n0.salir \n1.crear pila \n2.vaciar pila \n3.pila llena \n4.pila vacia \n5.apilar \n6.desapilar \n7.vertope");
        scanf("\n%d",&dec);

        switch(dec){
            case 0:
                break;
            case 1:
                crearPila(&p);
                break;
            case 2:
                vaciarPila(&p);
                break;
            case 3:
                if(pilaLlena(&p,TAM) ==1){
                    printf("\npila llena");
                }else{
                    printf("\npila no llena");
                }
                break;
            case 4:
                if(pilaVacia(&p) ==1){
                    printf("\npila vacia");
                }else{
                    printf("\npila no vacia");
                }
                break;
            case 5:
                apilar(&p,TAM);
                break;
            case 6:


                if(desapilar(&p,&inf,TAM)){
                    printf("\nDesapilado= %d",inf.num);
                }
                break;
            case 7:
                vertope(&p,TAM);
                break;
            default:
                printf("\nNumero invalido de menu");
        }
    }while(dec!=0);

    return 0;
}
