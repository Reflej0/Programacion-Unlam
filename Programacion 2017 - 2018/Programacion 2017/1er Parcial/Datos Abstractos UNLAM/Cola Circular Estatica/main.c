#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    t_cola cola;
    t_dato dat;
    int dec;

    crear_cola(&cola);

    do{
        puts("\n---Menu cola estatica---\n0.Salir \n1.poner en cola \n2.Sacar de cola \n3.ver frente cola \n4.vaciar cola \n5.cola vacia \n6.cola llena ");
        scanf("%d",&dec);

        switch(dec){
            case 0: break;
            case 1: entrada_dato(&dat);
                    if(poner_en_cola(&cola,&dat)){
                        puts("\nDato acolado");
                        debug_datos_cola(&cola);
                    }else{
                        puts("\nCola llena no se pudo acolar");
                        debug_datos_cola(&cola);
                    }
                    break;;
            case 2: if(sacar_de_cola(&cola,&dat)){
                        puts("\nDato desacolado: ");
                        mostrar_dato(&dat);
                        debug_datos_cola(&cola);
                    }else{
                        puts("\nCola vacia");
                        debug_datos_cola(&cola);
                    }
                    break;
            case 3: if(ver_frente_cola(&cola,&dat)){
                        printf("\nFrente: ");
                        mostrar_dato(&dat);
                        debug_datos_cola(&cola);
                    }else{
                        puts("\nCola vacia");
                        debug_datos_cola(&cola);
                    }
                    break;
            case 4: vaciar_cola(&cola);
                    debug_datos_cola(&cola);
                    break;
            case 5: if(cola_vacia(&cola)){
                        puts("\nCola vacia");
                    }else{
                        puts("\nCola no vacia");
                    }
                    break;
            case 6: if(cola_llena(&cola)){
                        puts("\nCola llena");
                    }else{
                        puts("\nCola no llena");
                    }
                    break;

        }
    }while(dec!=0);

    return 0;
}
