#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <math.h>

int es_arbol_completo_hasta_nivel(t_arbol*pa,int nivel){

    if(nivel==0 || !*pa){

        return *pa;

    }

    return es_arbol_completo_hasta_nivel(&(*pa)->hizq,nivel-1) && es_arbol_completo_hasta_nivel(&(*pa)->hder,nivel-1);
}

int es_arbol_avl_clase(t_arbol*pa){

    int hi,hd;

    if(!*pa)return VERDADERO;

    hi = altura_arbol(&(*pa)->hizq);

    hd = altura_arbol(&(*pa)->hder);

    if(abs(hi-hd)>1){
        return FALSO;
    }

    return es_arbol_avl_clase(&(*pa)->hizq) && es_arbol_avl_clase(&(*pa)->hder);

}

int es_arbol_completo_clase(t_arbol*pa){

    int hi,hd;

    if(!*pa){
            //printf("\nvuelve verdadero");
            return VERDADERO;
    }
    hi = altura_arbol(&(*pa)->hizq);

    hd = altura_arbol(&(*pa)->hder);

    //printf("\nhi: %d hd: %d",hi,hd);

    if(abs(hi-hd) != 0){
            //printf("\nvuelve falso");
        return FALSO;
    }

    return es_arbol_completo_clase(&(*pa)->hizq) && es_arbol_completo_clase(&(*pa)->hder);

}

int es_arbol_balanceado_clase(t_arbol*pa){

    int n;

    n = altura_arbol(pa)-2;

    //printf("\nn: %d altura_arbol(pa): %d",n,altura_arbol(pa));

    if(n < 0){

        return VERDADERO;
    }

    return es_arbol_completo_hasta_nivel(pa,n);
}
