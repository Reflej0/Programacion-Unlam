#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void entrada_dato(t_dato*d){

    puts("\nIngrese numero: ");
    scanf("%d",&(d->numero));
}
void mostrar_dato(t_dato*d){

    printf("\nDato: %d",d->numero);
}


//---- primitivas cola --------

void crear_cola(t_cola*pc){

    pc->cantElem = 0;
    pc->pri = 0;
    pc->ult = -1;
}

int poner_en_cola(t_cola*pc,t_dato*d){

    if(pc->cantElem >= TAM){
        return 0;
    }

    if(pc->ult == TAM-1){
        pc->ult = 0;
    }else{
        pc->ult++;
    }

    pc->vec[pc->ult] = *d;

    pc->cantElem++;

    return 1;
}

int sacar_de_cola(t_cola*pc,t_dato*d){

    if(pc->cantElem == 0){
        return 0;
    }

    *d = pc->vec[pc->pri];

    if(pc->pri == TAM-1){
        pc->pri = 0;
    }else{
        pc->pri++;
    }

    pc->cantElem--;
}

int ver_frente_cola(t_cola*pc,t_dato*d){

    if(pc->cantElem == 0){
        return 0;
    }

    *d = pc->vec[pc->pri];

    return 1;
}

void vaciar_cola(t_cola*pc){

    pc->pri=0;
    pc->ult=-1;
    pc->cantElem=0;
}

int cola_vacia(const t_cola*pc){

    if(pc->cantElem == 0)return 1;
    return 0;
}

int cola_llena(const t_cola*pc){

    if(pc->cantElem == TAM)return 1;

    return 0;
}

//----------------------------------------

void debug_datos_cola(t_cola*pc){
    int i;

    printf("\nPri: %d Ult: %d cantElem: %d VEC=",pc->pri,pc->ult,pc->cantElem);

    for(i=0;i<TAM;i++){

        if(i==pc->pri && i==pc->ult){
            printf(" [%d PRI ULT]: %d",i,pc->vec[i]);
        }
        else if(i==pc->pri){
            printf(" [%d PRI]: %d",i,pc->vec[i]);
        }else if(i == pc->ult){
            printf(" [%d ULT]: %d",i,pc->vec[i]);
        }else{
            printf(" [%d]: %d",i,pc->vec[i]);
        }

    }
}
