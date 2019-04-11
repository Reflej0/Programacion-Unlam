#include <tipos.h>
#include <stdio.h>
#include <stdlib.h>
#include <arbol.h>
#include <pila.h>


int buscar_en_arbol_bin_busq(const t_arbol* a, t_info* d, int (*cmp)(const t_info*, const t_info*))
{
    int comp;
    while(*a && (comp=cmp(&(*a)->info,d)))
    {
        if(comp>0)
            a=&(*a)->izq;
        if(comp<0)
            a=&(*a)->der;
    }
    if(!*a)
        return FALSO;
    else
    {
        *d=(*a)->info;
        return VERDADERO;
    }
}

void cargarArbolBalanceado(t_arbol *a,int inicio,int fin,FILE *pf)
{
    int medio;
    medio=(inicio+fin)/2;

    if(fin<inicio)
        return;
    fseek(pf,medio*(sizeof(t_reg_ind)),SEEK_SET);
    *a=(t_nodo_arbol*)malloc(sizeof(t_nodo_arbol));

    if(!*a)
        return;
    fread(&(*a)->info,sizeof(t_info),1,pf);
    (*a)->izq=NULL;
    (*a)->der=NULL;

    cargarArbolBalanceado(&(*a)->izq,inicio,medio-1,pf);
    cargarArbolBalanceado(&(*a)->der,medio+1,fin,pf);

}
int cargar_arbol_de_archivo_ordenado(t_arbol* pa, const char* path)
{
    FILE *pf;
    int fin;
    pf=fopen(path,"r+b");
    if(!pf)
    {
        return ERROR_ARCHIVO;
    }
    fseek(pf,0L,SEEK_END);

    fin=(ftell(pf)/sizeof(t_reg_ind))-1;

    cargarArbolBalanceado(pa,0,fin,pf);


    return TODO_OK;
}


