#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"


void ingresar_info(t_info*d){

    printf("\nIngrese dato: ");
    scanf("%d",&d->num);
}
void mostrar_info(t_info*d){

    printf("\nDato: %d",d->num);
}
int cmp(void*a,void*b){

    t_info*aa = (t_info*)a;
    t_info*bb = (t_info*)b;

    //printf("\nComparo %d a %d",aa->num,bb->num);

    return (aa->num - bb->num);
}

void crear_arbol(t_arbol*a){

    *a = NULL;
}
int insertar_iterativo(t_arbol*a,t_info*d,t_cmp cmp){

    t_nodo*nue;

    nue = (t_nodo*)malloc(sizeof(t_nodo));

    if(!nue){
        return 0;
    }

    nue->info = *d;
    nue->der = NULL;
    nue->izq = NULL;

    if(!*a){
        *a = nue;
        return 1;
    }else{

        while(*a){

            if(cmp(&nue->info,&(*a)->info)>0){

                a = &(*a)->der;
            }else{
                a = &(*a)->izq;
            }
        }

        *a = nue;
        return 1;
    }


}

int insertar_recursivo(t_arbol*a,t_info*d,t_cmp cmp){

    t_nodo*nue;

    if(!*a){
        nue = (t_nodo*)malloc(sizeof(t_nodo));

        if(!nue){
            return 0;
        }

        nue->info = *d;
        nue->der = NULL;
        nue->izq = NULL;

        *a = nue;

        return 1;
    }

    if(cmp(d,&(*a)->info)<0){
        insertar_iterativo(&(*a)->izq,d,cmp);
    }else{
        insertar_iterativo(&(*a)->der,d,cmp);
    }
}
void recorrer_pre(t_arbol*a){

    if(!*a)return;

    printf("%d ",(*a)->info.num);

    recorrer_pre(&(*a)->izq);
    recorrer_pre(&(*a)->der);
}
void recorrer_in(t_arbol*a){

    if(!*a)return;

    recorrer_in(&(*a)->izq);

    printf("%d ",(*a)->info.num);

    recorrer_in(&(*a)->der);
}
void recorrer_post(t_arbol*a){

    if(!*a)return;

    recorrer_post(&(*a)->izq);
    recorrer_post(&(*a)->der);

    printf("%d ",(*a)->info.num);

}

int buscar_existencia(t_arbol*a,t_info*d,t_cmp cmp){

    if(*a && cmp(d,&(*a)->info)==0){
        return 1;
    }
    if(!*a)return 0;

    return buscar_existencia(&(*a)->izq,d,cmp) + buscar_existencia(&(*a)->der,d,cmp);
}

int mostrar_y_contar_hojas(t_arbol*a){

    if(!*a)return 0;

    if(*a && !(*a)->der && !(*a)->izq){
        mostrar_info(&(*a)->info);
        return 1;
    }



    return mostrar_y_contar_hojas(&(*a)->izq) + mostrar_y_contar_hojas(&(*a)->der);
}

int mostrar_y_contar_no_hojas(t_arbol*a){

    if(!*a)return 0;

    //printf("izq: %p p: %p num:%d der: %p",(*a)->izq,(*a),(*a)->info.num,(*a)->der);

    if(*a && ((*a)->der!=NULL || (*a)->izq!=NULL)){
        mostrar_info(&(*a)->info);

        return 1+ mostrar_y_contar_no_hojas(&(*a)->izq) + mostrar_y_contar_no_hojas(&(*a)->der);

    }else{
        return 0;
    }





    return mostrar_y_contar_no_hojas(&(*a)->izq) + mostrar_y_contar_no_hojas(&(*a)->der);
}

int mostrar_y_contar_hizq(t_arbol*a){

    if(!*a)return 0;



    if((*a)->izq){

        mostrar_info(&(*a)->izq->info);
        return 1 + mostrar_y_contar_hizq(&(*a)->izq) + mostrar_y_contar_hizq(&(*a)->der);;
    }

    mostrar_y_contar_hizq(&(*a)->der);
}
int mostrar_y_contar_hder(t_arbol*a){

    if(!*a)return 0;

    if((*a)->der){

        mostrar_info(&(*a)->der->info);
        return 1 + mostrar_y_contar_hder(&(*a)->izq) + mostrar_y_contar_hder(&(*a)->der);;
    }

    mostrar_y_contar_hder(&(*a)->izq);
}

int borrar_hojas(t_arbol*a){

    t_nodo*nae;

    if(!*a)return 0;

    if(*a && !(*a)->der && !(*a)->izq){

        nae = *a;
        printf("\nElimino nodo: %d",nae->info.num);
        free(nae);
        *a = NULL;

        return 1;
    }

    return borrar_hojas(&(*a)->der) + borrar_hojas(&(*a)->izq);
}

void vaciar_arbol(t_arbol*a){

    t_nodo*nae;

    if(!*a)return;

    vaciar_arbol(&(*a)->izq);
    vaciar_arbol(&(*a)->der);

    if(*a){
        nae = *a;
        printf("\nElimino nodo: %d",nae->info.num);
        free(nae);
        *a=NULL;
        return;
    }


}

int altura_arbol(t_arbol*a){

    int hder,hizq;

    if(!*a)return -1;

    hizq = altura_arbol(&(*a)->izq);

    hder = altura_arbol(&(*a)->der);

    if(hizq > hder){
        return hizq+1;
    }else{
        return hder+1;
    }


}

int contar_nodos_en_nivel(t_arbol*a,int nivel){

    if(!*a)return 0;

    if(nivel==0){
        return 1;
    }

    return contar_nodos_en_nivel(&(*a)->izq,nivel-1) + contar_nodos_en_nivel(&(*a)->der,nivel-1);


}

int es_avl(t_arbol*a){

    int hizq,hder;

    if(!*a)return 1;

    hizq = altura_arbol(&(*a)->izq);
    hder = altura_arbol(&(*a)->der);

    if(abs(hizq - hder ) > 1){
        return 0;
    }

    return altura_arbol(&(*a)->izq) + altura_arbol(&(*a)->der);
}
int es_balanceado(t_arbol*a){

    int cant_nodos_calc;
    int cant_nodos_real;
    int altura;

    altura = altura_arbol(a);

    cant_nodos_calc = pow(2,altura-1);
    printf("\nNodos calc: %d",cant_nodos_calc);

    cant_nodos_real = contar_nodos_en_nivel(a,altura-1);
    printf("\nNodos real en nivel %d calc: %d",altura-1,cant_nodos_real);

    if(cant_nodos_real == cant_nodos_calc){
        return 1;
    }
    return 0;

}
int es_completo(t_arbol*a){

    int cant_nodos_calc;
    int cant_nodos_real;
    int altura;

    altura = altura_arbol(a);

    cant_nodos_calc = pow(2,altura);
    printf("\nNodos calc: %d",cant_nodos_calc);

    cant_nodos_real = contar_nodos_en_nivel(a,altura);
    printf("\nNodos real en nivel %d calc: %d",altura,cant_nodos_real);

    if(cant_nodos_real == cant_nodos_calc){
        return 1;
    }
    return 0;
}


void cargar_arbol(t_arbol*a,int dec,t_cmp cmp){

    int arbol_nada[20]={22,15,3,8,40,45,13,20,30,1,7,34,48,53,9,23,12,51,4,10}; //No completo,no balanceado, no avl

    int arbol_avl[7]={12,8,5,4,11,18,17}; //avl

    int arbol_avl_bal[11]={50,17,12,9,14,23,19,72,76,54,67}; //balanceado,avl

    int arbol_avl_bal_comp[7]={50,17,12,23,72,76,54}; //completo,balanceado,avl

    t_info inf;

    int i;

    switch(dec){
        case 1:for(i=0;i<20;i++){
                inf.num = arbol_nada[i];
                insertar_iterativo(a,&inf,cmp);
                }
                break;

        case 2:for(i=0;i<7;i++){
                inf.num = arbol_avl[i];
                insertar_iterativo(a,&inf,cmp);
                }
                break;

        case 3:for(i=0;i<11;i++){
                inf.num = arbol_avl_bal[i];
                insertar_iterativo(a,&inf,cmp);
                }
                break;
        case 4:for(i=0;i<7;i++){
                inf.num = arbol_avl_bal_comp[i];
                insertar_iterativo(a,&inf,cmp);
                }
                break;
    }
}

void cargar_arch_bin(char*nom,FILE**pf){

    t_info vec[20]={1,3,4,7,8,9,10,12,13,15,20,22,23,30,34,40,45,48,51,53};

    *pf = fopen(nom,"wb");

    if(!*pf)exit(1);

    fwrite(&vec,sizeof(t_info),20,*pf);

    fclose(*pf);
}

void cargar_arbol_desde_archivo_ord_rec(t_arbol*a,char*nom,FILE**pf,t_cmp cmp,long i,long d){

    int m;
    t_info inf;

    if(i>d){
        return;
    }

    m = (i+d)/2;
    printf("\nm: %d",m);


    fseek(*pf,m*sizeof(t_info),SEEK_SET);

    fread(&inf,sizeof(t_info),1,*pf);

    mostrar_info(&inf);

    insertar_iterativo(a,&inf,cmp);

    cargar_arbol_desde_archivo_ord_rec(a,nom,pf,cmp,i,m-1);
    cargar_arbol_desde_archivo_ord_rec(a,nom,pf,cmp,m+1,d);


}
void cargar_arbol_desde_archivo_ord(t_arbol*a,char*nom,FILE**pf,t_cmp cmp,long i,long d){

    i = 0;

    *pf = fopen(nom,"rb");

    if(!*pf)exit(1);

    fseek(*pf,0,SEEK_END);
    d = (ftell(*pf)/sizeof(t_info))-1;
    printf("\nd_: %ld",d);

    cargar_arbol_desde_archivo_ord_rec(a,nom,pf,cmp,i,d);

    fclose(*pf);
}
