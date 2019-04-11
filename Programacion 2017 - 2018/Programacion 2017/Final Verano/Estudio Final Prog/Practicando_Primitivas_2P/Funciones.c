#include "Prototipos.h"
int cmp(const void *pv1,const void *pv2)
{
    t_dato *d1 = (t_dato *)pv1;
    t_dato *d2 = (t_dato *)pv2;
    return (*d1 - *d2);
}
t_nodo_a **buscar_en_arbol_bin(t_arbol *pa,t_dato *pd,t_cmp cmp)
{
    int comp;
    if(!*pa)
        return NULL;
    comp = cmp(pd,&(*pa)->info);
    if(comp == 0)
        return pa;
    if(comp < 0)
        return buscar_en_arbol_bin(&(*pa)->pizq,pd,cmp);
    else
        return buscar_en_arbol_bin(&(*pa)->pder,pd,cmp);
}
int altura_arbol(t_arbol *pa)
{
    int hd,hi;
    if(!*pa)
        return 0;
    hd = altura_arbol(&(*pa)->pder);
    hi = altura_arbol(&(*pa)->pizq);
    return (hi>hd?hi:hd)+1;
}
t_arbol *mayor(t_arbol *pa)
{
    if(!(*pa)->pder)
        return pa;
    return mayor(&(*pa)->pder);
}
t_arbol *menor(t_arbol *pa)
{
    if(!(*pa)->pizq)
        return pa;
    return menor(&(*pa)->pizq);
}
void eliminar_nodo(t_arbol *pa)
{
    if((*pa)->pizq == NULL && (*pa)->pder == NULL)
    {
        free(*pa);
        *pa = NULL;
        return;
    }
    t_nodo_a **nae;
    int hd = altura_arbol(&(*pa)->pder);
    int hi = altura_arbol(&(*pa)->pizq);
    nae = hi>hd?mayor(&(*pa)->pizq):menor(&(*pa)->pder);
    (*pa)->info = (*nae)->info;
    eliminar_nodo(nae);

}
int eliminar_de_arbol_bin(t_arbol *pa,t_dato *pd,t_cmp cmp)
{
    t_nodo_a **nae = buscar_en_arbol_bin(pa,pd,cmp);
    if(!nae)
        return 0;
    eliminar_nodo(nae);
    return 1;
}


int contar_nodos_de_nivel(t_arbol *pa,int nivel)
{
    if(!*pa)
        return 0;
    if(nivel == 0)
        return 1;
    return (contar_nodos_de_nivel(&(*pa)->pizq,nivel-1) + contar_nodos_de_nivel(&(*pa)->pder,nivel-1));
}
int es_arbol_balanceado(t_arbol *pa)
{
    int h,cant_nodos_calculado,cant_nodos_teorico;
    h = altura_arbol(pa);
    if(!*pa)
        return 1;
    if(h<=2)
        return 1;
    cant_nodos_teorico = pow(2,h-2);
    cant_nodos_calculado = contar_nodos_de_nivel(pa,h-2);
    if(cant_nodos_calculado == cant_nodos_teorico)
        return 1;
    return 0;


}
int insertar_en_arbol_bin(t_arbol *pa,t_dato *pd,t_cmp cmp)
{
    int comp = 0;
    if(!*pa)
    {
        *pa = (t_nodo_a *)malloc(sizeof(t_nodo_a));
            if(!*pa)
                return 3;///SIN MEM;
        (*pa)->info = *pd;
        (*pa)->pder = (*pa)->pizq = NULL;
        return 1;///TODO OK;
    }
    comp = cmp(pd,&(*pa)->info);
    if(comp == 0)
        return 2;///DUPLICADO;
    if(comp < 0)
        return insertar_en_arbol_bin(&(*pa)->pizq,pd,cmp);
    else
        return insertar_en_arbol_bin(&(*pa)->pizq,pd,cmp);
}

void eliminar_nodos_de_nivel(t_arbol *pa,int nivel,t_cmp cmp)
{
    if(!*pa)
        return;
    if(nivel == 0)
    {
        ///lo que quieras hacer
        eliminar_nodo(pa);
    }
    eliminar_nodos_de_nivel(&(*pa)->pizq,nivel-1,cmp);
    eliminar_nodos_de_nivel(&(*pa)->pder,nivel-1,cmp);
}
int cargar_arbol_rec(t_arbol *pa,long i,long d,FILE *arch)
{
    t_dato dato_arbol;
    if(i>d)
        return 1;///todo ok;
    long m = (i+d)/2;
    fseek(arch,m*sizeof(t_dato),SEEK_SET);
    fread(&dato_arbol,sizeof(t_dato),1,arch);
    *pa = (t_nodo_a*)malloc(sizeof(t_nodo_a));
        if(!*pa)
            return 3;///SIN MEM;
    (*pa)->info = dato_arbol;
    (*pa)->pder = (*pa)->pizq = NULL;
    int resp = cargar_arbol_rec(&(*pa)->pizq,i,m-1,arch);
    if(resp != 1) ///!= de TODO OK;
        return resp;
    return cargar_arbol_rec(&(*pa)->pder,m+1,d,arch);

}
int cargar_arbol_desde_archivo(t_arbol *pa,FILE *arch)
{
    fseek(arch,0L,SEEK_END);
    long i=0,d;
    d = (ftell(arch)/sizeof(t_dato))-1;
    return cargar_arbol_rec(pa,i,d,arch);
}
