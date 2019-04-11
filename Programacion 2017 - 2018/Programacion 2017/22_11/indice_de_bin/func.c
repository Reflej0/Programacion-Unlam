#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int abrir_arch(char*nom,char*modo,FILE**pf){

    *pf = fopen(nom,modo);

    if(!*pf){
        return 0;
    }

    return 1;
}

void cargar_bin(char*nom,FILE**pf){

    t_persona vec[4]={{3,"pepe"},{8,"pedro"},{5,"luis"},{7,"reodrigo"}};

    if(abrir_arch(nom,"wb",pf)==0){
        printf("\nError abrir arch");
        return;
    }

    fwrite(&vec,sizeof(t_persona),4,*pf);

    fclose(*pf);

}

void mostrar_bin(char*nom,FILE**pf){

    t_persona per;

    if(abrir_arch(nom,"rb",pf)==0){
        printf("\nError abrir arch");
        return;
    }

    fread(&per,sizeof(t_persona),1,*pf);
    while(!feof(*pf)){


        printf("\n%d %s",per.clave,per.nom);
        fread(&per,sizeof(t_persona),1,*pf);

    }

    fclose(*pf);
}

void cargar_indice(char*nom,FILE**pf,t_indice*indi,t_cmp cmp){

    //primero lo pense como ordenado desde carga de archivo, pero son mcuhas lecturas de archivo
    //perimero lo paso todo a lista y luego lo ordeno

    int i=0;
    t_persona per;
    t_dat_indice dat;

    indi->lista_indice = NULL; //creo lista

    if(abrir_arch(nom,"rb",pf)==0){
        printf("\nError abrir arch");
        return;
    }

    fread(&per,sizeof(t_persona),1,*pf);

    while(!feof(*pf)){

        dat.clave = per.clave;
        dat.pos = i;

        insertar_en_lista(&(indi->lista_indice),&dat);

        fread(&per,sizeof(t_persona),1,*pf);
        i++;
    }

    printf("\nLista indice antes de ordenar");

    mostrar_indice_desde_principio(indi);

    indi->lista_indice = ordenar_lista(&(indi->lista_indice),cmp);

    fclose(*pf);
}

void insertar_en_lista(t_lista*l,t_dat_indice*d){

    t_nodo*aux;

    aux = (t_nodo*)malloc(sizeof(t_nodo));

    if(!aux){
        printf("\nError malloc");
        return;
    }

    while(*l){
        l = &(*l)->sig;
    }

    aux->t_dat_indice = *d;
    aux->sig=NULL;

    *l = aux;

}

void mostrar_indice_desde_principio(t_indice*indi){

    t_nodo**p = &(indi->lista_indice);

    if(indi->lista_indice == NULL){
        printf("\nIndice vacio");
        return;
    }

    while(*p){

        printf("\n%d pos: %ld",(*p)->t_dat_indice.clave,(*p)->t_dat_indice.pos);

        p = &(*p)->sig;
    }
}

int cmp(void*a,void*b){

    t_dat_indice*aa = (t_dat_indice*)a;
    t_dat_indice*bb = (t_dat_indice*)b;

    return (aa->clave - bb->clave);
}

void insertar_lista_logica(t_lista*l,t_nodo*nodo_agr){

    while(*l){
        l = &(*l)->sig;
    }


    *l = nodo_agr;
    (*l)->sig = NULL;


}

void sacar_lista_logica(t_lista*l,t_nodo*nodo_sac){

    while(*l && *l != nodo_sac){
        l = &(*l)->sig;
    }

    if(*l == nodo_sac){
        *l=nodo_sac->sig;
    }
}

t_lista* ordenar_lista(t_lista*l,t_cmp cmp){

    t_lista*listaB=NULL;
    t_lista*listaA=l;
    t_dat_indice dat;
    t_nodo*menor;
    int i,j=0;

    while(*l){
        j++;
        l = &(*l)->sig;
    }

    for(i=0;i<j;i++){

        l = listaA;
        menor = *l;

        while(*l){

            if(cmp(&(*l)->t_dat_indice,&menor->t_dat_indice)<0){
                menor = *l;
            }
            printf("\nmenor: %d pos %ld",menor->t_dat_indice.clave,menor->t_dat_indice.pos);

            printf("\nleido: %d pos %ld",(*l)->t_dat_indice.clave,(*l)->t_dat_indice.pos);
            l = &(*l)->sig;
        }

        sacar_lista_logica(listaA,menor);
        insertar_lista_logica(&listaB,menor);

    }

    return listaB;
}

void mostrar_dato_clave(char*nom,FILE**pf,t_indice*indi,int clave){

    t_persona per;
    t_dat_indice dat;
    t_lista*l=&(indi->lista_indice);
    int flag=0;

    if(abrir_arch(nom,"rb",pf)==0){

        printf("\nError abrir arch");
        return;
    }

    while((*l)->sig != NULL){

        if((*l)->t_dat_indice.clave == clave){
            flag=1;
            break;
        }

        l = &(*l)->sig;
    }
    if(flag==0){
        printf("\nClave no encontrada");
        return;
    }

    fseek(*pf,(*l)->t_dat_indice.pos*sizeof(t_persona),SEEK_SET);

    fread(&per,sizeof(t_persona),1,*pf);

    printf("\n%d %s",per.clave,per.nom);
}
