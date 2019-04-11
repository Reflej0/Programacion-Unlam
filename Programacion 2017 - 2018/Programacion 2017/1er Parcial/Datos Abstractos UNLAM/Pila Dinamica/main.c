#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main()
{
    //pila dinamica

    int dec;
    t_pila p; //es t_nodo* pila
    t_info inf;

    crearPila(&p);

    do{
        printf("\n-Pila dinamica- \n0.salir \n1.crear pila \n2.vaciar pila \n3.pila llena \n4.pila vacia \n5.apilar \n6.desapilar \n7.vertope\n");

        scanf("\n%d",&dec);

        switch(dec){
            case 0:
                break;
            case 1:
                crearPila(&p);
                printf("\nPila creada");
                break;
            case 2:

                printf("\npila vaciada, %d nodos liberados",vaciarPila(&p));
                break;
            case 3:
                if(pilaLlena(&p) ==1){
                    printf("\npila llena");
                }else{
                    printf("\npila no llena");
                }
                break;
            case 4:
                printf("\n%p",p);
                if(pilaVacia(&p)){

                    printf("\npila vacia");
                }else{
                    printf("\npila no vacia");
                }
                break;
            case 5:
                printf("\nIngrese dato: ");
                scanf("%d",&inf.num);

                if(apilar(&p,&inf)){
                    printf("\nApilado");
                }else{
                    printf("\nError malloc no apilado");
                }
                break;
            case 6:


                if(!desapilar(&p,&inf)){
                    printf("\npila vacia");

                }else{
                    printf("\nDesapilado= %d",inf.num);
                }
                break;
            case 7:
                if(!vertope(&p)){
                    printf("\npila vacia");
                }
                break;
            default:
                printf("\nNumero invalido de menu");
        }
    }while(dec!=0);
    return 0;
}
