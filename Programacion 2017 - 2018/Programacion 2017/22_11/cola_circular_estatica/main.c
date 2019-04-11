#include <stdio.h>
#include <stdlib.h>
#include "cola_circular_estatica.h"

int main()
{
    int dec;
    t_cola cola;
    t_info inf;

    crear_cola(&cola);

    do{
        printf("\n\n--Menu cola circular estatica---\n1.recorrer \n2.acolar \n3.desacolar \n4.ver principio \n5.cola llena \n6.cola vacia \n7.vaciar \n");
        scanf("%d",&dec);

        switch(dec){
            case 1:recorrer_cola_est(&cola);
                    break;
            case 2:ingresar_dato(&inf);
                    acolar(&cola,&inf);
                    printf("\nRecorro:");
                    recorrer_cola_est(&cola);
                    break;
            case 3:if(desacolar(&cola,&inf)==0){
                        printf("\nCola vacia");
                    }else{
                        printf("desacolado: %d",inf.num);
                        printf("\nRecorro:");
                        recorrer_cola_est(&cola);
                    }
                    break;
            case 4: ver_principio(&cola);
                    break;
            case 5: cola_llena(&cola);
                    break;
            case 6: cola_vacia(&cola);
                    break;
            case 7: vaciar(&cola);
                    printf("\nRecorro:");
                    recorrer_cola_est(&cola);
                    break;
        }
    }while(dec!=0);
    return 0;
}
