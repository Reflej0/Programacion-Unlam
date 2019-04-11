#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <math.h>

int cmp(void*d1,void*d2){

    t_dato*dd1 = (t_dato*)d1;
    t_dato*dd2 = (t_dato*)d2;

    return (dd1->num - dd2->num);
}

void crear_arbol(t_arbol*a){

    *a=NULL;
}

void insertar_dato(t_dato*d){

    printf("\nIngrese dato: ");
    scanf("%d",&d->num);
}

void mostrar_dato(t_dato*d){

    printf("\nDato: %d",d->num);
}

int insertar_en_arbol_iterativa(t_arbol*a,t_dato*d,t_cmp cmp){

    t_nodo*nue;

    nue = (t_nodo*)malloc(sizeof(t_nodo));

    if(!nue)return ERR_MALLOC;

    nue->info = *d;
    nue->hizq=NULL;
    nue->hder=NULL;

    while(*a){

        if(cmp(d,&(*a)->info) < 0){

            a = &(*a)->hizq;
        }else if(cmp(d,&(*a)->info) > 0){

            a = &(*a)->hder;
        }
    }

    *a = nue;

    return TODO_OK;

}

void recorrer_arbol_preorden(t_arbol*a){

    if(!*a){
        return;
    }

    printf(" %d",(*a)->info.num);

    recorrer_arbol_preorden(&(*a)->hizq);
    recorrer_arbol_preorden(&(*a)->hder);
}

void recorrer_arbol_inorden(t_arbol*a){

    if(!*a){
        return;
    }

    recorrer_arbol_inorden(&(*a)->hizq);

    printf(" %d",(*a)->info.num);

    recorrer_arbol_inorden(&(*a)->hder);
}

void recorrer_arbol_postorden(t_arbol*a){

    if(!*a){
        return;
    }

    recorrer_arbol_postorden(&(*a)->hizq);
    recorrer_arbol_postorden(&(*a)->hder);

    printf(" %d",(*a)->info.num);

}

int insertar_en_arbol_recursiva(t_arbol*a,t_dato*d,t_cmp cmp){

    t_nodo*nue;

    if(!*a){

        nue = (t_nodo*)malloc(sizeof(t_nodo));

        if(!nue)return ERR_MALLOC;

        nue->info = *d;
        nue->hizq = NULL;
        nue->hder = NULL;

        *a = nue;
    }

    if(cmp(d,&(*a)->info) < 0)return insertar_en_arbol_recursiva(&(*a)->hizq,d,cmp);
    if(cmp(d,&(*a)->info) > 0)return insertar_en_arbol_recursiva(&(*a)->hder,d,cmp);
}

int buscar_en_arbol_bin(t_arbol*a,t_dato*d,t_cmp cmp){

    if(!*a){
        return 0;
    }

    if(*a && cmp(d,&(*a)->info) == 0){

        *d = (*a)->info;
        return 1;
    }

    if(*a && cmp(d,&(*a)->info) < 0){
        return buscar_en_arbol_bin(&(*a)->hizq,d,cmp);;
    }else if (*a && cmp(d,&(*a)->info) > 0){
        return buscar_en_arbol_bin(&(*a)->hder,d,cmp);
    }


}

int contar_y_mostrar_hojas(t_arbol*a){



    if(!*a){
        return 0;
    }

    if(*a && (*a)->hizq == NULL && (*a)->hder == NULL){

        mostrar_dato(&(*a)->info);
        return 1;
    }

    return contar_y_mostrar_hojas(&(*a)->hizq) + contar_y_mostrar_hojas(&(*a)->hder);
}


int contar_y_mostrar_nodos_no_hojas(t_arbol*a){

    if(!*a){
        return 0;
    }

    if(*a &&((*a)->hizq || (*a)->hder)){

        mostrar_dato(&(*a)->info);
        return 1 + contar_y_mostrar_nodos_no_hojas(&(*a)->hizq) + contar_y_mostrar_nodos_no_hojas(&(*a)->hder);;
    }
}

int mostrar_y_constar_hder(t_arbol*a){

    if(!*a){
        return 0;
    }

    if((*a)->hder){

        mostrar_dato(&(*a)->hder->info);
        return 1 + mostrar_y_constar_hder(&(*a)->hder) + mostrar_y_constar_hder(&(*a)->hizq);
    }


    mostrar_y_constar_hder(&(*a)->hizq);
}

int mostrar_y_constar_hizq(t_arbol*a){

    if(!*a){
        return 0;
    }

    if((*a)->hizq){

        mostrar_dato(&(*a)->hizq->info);
        return 1 + mostrar_y_constar_hizq(&(*a)->hizq) + mostrar_y_constar_hizq(&(*a)->hder);
    }


    mostrar_y_constar_hizq(&(*a)->hder);
}

void borrar_hojas(t_arbol*a){

    if(!*a)return;

    if((*a)->hizq == NULL && (*a)->hder == NULL){

        printf("\nSe va a eliminar el nodo: %d",(*a)->info.num);

        free(*a);

        *a = NULL;

        return;
    }

    borrar_hojas(&(*a)->hizq);
    borrar_hojas(&(*a)->hder);
}

void vaciar_arbol(t_arbol*a){

    if(!*a)return;

    vaciar_arbol(&(*a)->hizq);
    vaciar_arbol(&(*a)->hder);

    printf("\nSe va a eliminar el nodo: %d",(*a)->info.num);

    free(*a);

    *a = NULL;
}

int altura_arbol(t_arbol*a){

    if(!*a)return 0;

    int hi = altura_arbol(&(*a)->hizq);

    int hd = altura_arbol(&(*a)->hder);

    if(hi > hd){
        return hi+1;
    }else{
        return hd+1;
    }
}

int contar_nodos_nivel(t_arbol*a,int nivel){

    if(!*a || nivel==-1) return 0;

    if(nivel==0) return 1; //Nivel 0 es la raiz!! ojo por eso se usa h-1 para el ultimo nivel en completo

    return contar_nodos_nivel(&(*a)->hizq,nivel-1) + contar_nodos_nivel(&(*a)->hder,nivel-1);
}

int es_arbol_completo(t_arbol*a){

    //los nodos del "ultimo" nivel tienen que tener hijo izq y hijo der

    int h,cant_nodos_ult_nivel_calculo,cant_nodos_ult_nivel_real; //si tiene 3 niveles el "ultimo" es el 2

    h = altura_arbol(a); printf("\nAltura: %d",h);

    if(h<=1)return 1;

    cant_nodos_ult_nivel_calculo =  pow(2,h-1);//#include <math.h>

    cant_nodos_ult_nivel_real = contar_nodos_nivel(a,h-1);

    printf("cant_nodos_ult_nivel_real: %d cant_nodos_ult_nivel_calculo: %d",cant_nodos_ult_nivel_real,cant_nodos_ult_nivel_calculo);

    if (cant_nodos_ult_nivel_real == cant_nodos_ult_nivel_calculo){
        return 1;
    }else{
        return 0;
    }


}

int es_arbol_balanceado(t_arbol*a){

    //los nodos del "penultimo" nivel tienen que tener hijo izq y hijo der

    int h,cant_nodos_penult_nivel_calculo,cant_nodos_penult_nivel_real; //si tiene 4 niveles el "penultimo" es el 2

    h = altura_arbol(a);

    if(h<=2)return 1;

    cant_nodos_penult_nivel_calculo =  pow(2,h-2);//#include <math.h>

    cant_nodos_penult_nivel_real = contar_nodos_nivel(a,h-2);

    return cant_nodos_penult_nivel_real == cant_nodos_penult_nivel_calculo;


}

int es_arbol_avl(t_arbol*a){

    //Los árboles AVL están siempre equilibrados de tal modo que para todos los nodos,
    //la altura de la rama izquierda no difiere en más de una unidad de la altura de la rama derecha o viceversa.

    //abs(hizq-hder) <= 1 para que sea verdadero

    int hizq,hder; //alturas

    if(!*a)return 1;

    hizq = altura_arbol(&(*a)->hizq);
    hder = altura_arbol(&(*a)->hder);

    if(abs(hizq-hder) > 1){
        return 0;
    }

    return es_arbol_avl(&(*a)->hizq) && es_arbol_avl(&(*a)->hder);

}

void podar_arbol_desde_nivel_n(t_arbol*a,int nivel){

    if(!a)return;

    if(nivel == 0){
        vaciar_arbol(a);
        return;
    }

    podar_arbol_desde_nivel_n(&(*a)->hizq,nivel-1);

    podar_arbol_desde_nivel_n(&(*a)->hder,nivel-1);
}


int cargar_arbol_rec(t_arbol*a,FILE*arch,long i,long d,t_cmp cmp){

    long m,m_copy; //m_copy es mio, para que ande el txt
    int res;
    t_dato dato;

    if(i > d) return TODO_OK; //Caso base, se cruzan

    m = (i+d)/2;

    printf("\nm = %d",m);



    fseek(arch,0L,SEEK_SET);

    m_copy = m;

    while(m_copy > 0){ //fseek(arch,m*sizeof(t_dato),SEEK_SET);

        fscanf(arch,"%d\n",&(dato.num));

        m_copy--;
    }

    //fread(&dato,sizeof(t_dato),1,arch);

    fscanf(arch,"%d\n",&(dato.num));

    mostrar_dato(&dato);

    insertar_en_arbol_recursiva(a,&dato,cmp);

    res = cargar_arbol_rec(&(*a)->hizq,arch,i,m-1,cmp);

    if(res != TODO_OK) return res;

    return cargar_arbol_rec(&(*a)->hder,arch,m+1,d,cmp);
}

int cargar_arbol_de_arch_ord(t_arbol*a,FILE*arch,t_cmp cmp){

    long i,d;

    fseek(arch,0L,SEEK_END);

    i=0;

    d = (ftell(arch)/sizeof(t_dato))-1;

    printf("\nd= %d",d);

    return cargar_arbol_rec(a,arch,i,d,cmp);
}


///------- otras funciones--------------------------------------------------

void cargar_arbol(t_arbol*a,t_cmp cmp,int selec){

    int arbol_nada[20]={22,15,3,8,40,45,13,20,30,1,7,34,48,53,9,23,12,51,4,10}; //No completo,no balanceado, no avl

    int arbol_avl[7]={12,8,5,4,11,18,17}; //avl

    int arbol_avl_bal[11]={50,17,12,9,14,23,19,72,76,54,67}; //balanceado,avl

    int arbol_avl_bal_comp[7]={50,17,12,23,72,76,54}; //completo,balanceado,avl

    t_dato dato;

    int i;

    switch(selec){

        case 1:

            for(i=0;i<20;i++){

                dato.num = arbol_nada[i];

                insertar_en_arbol_iterativa(a,&dato,cmp);
            }break;

        case 2:

            for(i=0;i<7;i++){

                dato.num = arbol_avl[i];

                insertar_en_arbol_iterativa(a,&dato,cmp);
            }break;

        case 3:

            for(i=0;i<11;i++){

                dato.num = arbol_avl_bal[i];

                insertar_en_arbol_iterativa(a,&dato,cmp);
            }break;

        case 4:

            for(i=0;i<7;i++){

                dato.num = arbol_avl_bal_comp[i];

                insertar_en_arbol_iterativa(a,&dato,cmp);
            }break;
    }



    printf("\nArbol cargado");
}
