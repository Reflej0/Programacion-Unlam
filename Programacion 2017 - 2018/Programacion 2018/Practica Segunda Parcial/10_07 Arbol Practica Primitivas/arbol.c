#include <stdio.h>
#include <stdlib.h>
#include "auxiliares_arbol.h"
#include "arbol.h"

void crear_arbol(T_arbol* pa)
{
    *pa = NULL;
}

int insertar_en_arbol(T_arbol* pa, const T_dato* d, T_cmp cmp)
{
    if(!*pa)
    {
        *pa = (T_nodo*)malloc(sizeof(T_nodo));
        if(!*pa) return 0; //SINMEMORIA.
        (*pa)->Hizq = NULL;
        (*pa)->Hder = NULL;
        (*pa)->info = *d;
        return 1;
    }
    int comp = cmp(d, &(*pa)->info);
    if(comp == 0)
        return -1; //DUPLICADO.
    if(comp > 0)
        return insertar_en_arbol(&(*pa)->Hder, d, cmp);
    else
        return insertar_en_arbol(&(*pa)->Hizq, d, cmp);
}

int buscar_en_arbol(const T_arbol* pa, T_dato* d, T_cmp cmp)
{
    if(!*pa)
        return 0; // NO ENCONTRADO.
    int comp = cmp(d, &(*pa)->info);
    if(comp == 0)
    {
        *d = (*pa)->info;
        return 1; //ENCONTRADO.
    }
    if(comp > 0)
        return buscar_en_arbol(&(*pa)->Hder, d, cmp);
    else
        return buscar_en_arbol(&(*pa)->Hizq, d, cmp);
}

int buscar_en_arbol_ite(const T_arbol* pa, T_dato* d, T_cmp cmp)
{
    while(*pa)
    {
        int comp = cmp(d, &(*pa)->info);
        if(comp == 0)
        {
            *d = (*pa)->info;
            return 1; //ENCONTRADO.
        }
        if(comp > 0)
            pa = &(*pa)->Hder;
        else
            pa = &(*pa)->Hizq;
    }
    return 0; //NO ENCONTRADO.
}

void recorrer_preorden(const T_arbol* pa, T_do hacer)
{
    if(!*pa) return;
    hacer(&(*pa)->info);
    recorrer_preorden(&(*pa)->Hizq, hacer);
    recorrer_preorden(&(*pa)->Hder, hacer);
}

void recorrer_inorden(const T_arbol* pa, T_do hacer)
{
    if(!*pa) return;
    recorrer_inorden(&(*pa)->Hizq, hacer);
    hacer(&(*pa)->info);
    recorrer_inorden(&(*pa)->Hder, hacer);
}

void recorrer_posorden(const T_arbol* pa, T_do hacer)
{
    if(!*pa) return;
    recorrer_posorden(&(*pa)->Hizq, hacer);
    recorrer_posorden(&(*pa)->Hder, hacer);
    hacer(&(*pa)->info);
}

T_nodo** mayor(const T_arbol* pa)
{
    if(!*pa || !(*pa)->Hder)
        return (T_arbol*)pa;
    return mayor(&(*pa)->Hder);
}

T_nodo** menor(const T_arbol* pa)
{
    if(!*pa || !(*pa)->Hizq)
        return (T_arbol*)pa;
    return menor(&(*pa)->Hizq);
}

void eliminar_arbol(T_arbol* pa)
{
    if(!*pa) return;
    eliminar_arbol(&(*pa)->Hizq);
    eliminar_arbol(&(*pa)->Hder);
    free(*pa);
    *pa = NULL;
}

size_t altura_arbol(const T_arbol* pa)
{
    if(!*pa) return 0;
    int hi = altura_arbol(&(*pa)->Hizq);
    int hd = altura_arbol(&(*pa)->Hder);
    return ((hi>hd)?hi:hd)+1;
}

int mostrar_nodo_y_cantidad(const T_arbol* pa)
{
    if(!*pa) return 0;
    int i = 1;
    return mostrar_nodo_y_cantidad_rec(pa, i);
}

int mostrar_nodo_y_cantidad_rec(const T_arbol* pa, int i)
{
    if(!*pa) return i-1;
    printf("%d)DATO:%d\n", i, (*pa)->info);
    i = mostrar_nodo_y_cantidad_rec(&(*pa)->Hizq, i+1);
    i = mostrar_nodo_y_cantidad_rec(&(*pa)->Hder, i+1);
    return i;
}

void recuperar_arbol_archivo(T_arbol* pa, FILE* arch)
{
    T_dato reg;
    fread(&reg, sizeof(T_dato), 1, arch);
    if(reg==-1)
        return;
    *pa = (T_nodo*)malloc(sizeof(T_nodo));
    (*pa)->info = reg;
    (*pa)->Hizq = NULL;
    (*pa)->Hder = NULL;
    recuperar_arbol_archivo(&(*pa)->Hizq, arch);
    recuperar_arbol_archivo(&(*pa)->Hder, arch);
}

void guardar_arbol_archivo(T_arbol* pa, FILE* arch)
{
    T_dato _null = -1;
    if(!*pa)
    {
        fwrite(&_null, sizeof(T_dato), 1, arch);
        return;
    }
    fwrite(&(*pa)->info, sizeof(T_dato), 1, arch);
    guardar_arbol_archivo(&(*pa)->Hizq, arch);
    guardar_arbol_archivo(&(*pa)->Hder, arch);
}

int mostrar_y_contar_hojas(const T_arbol* pa)
{
    if(!*pa) return 0;
    if(!(*pa)->Hizq && !(*pa)->Hder)
    {
        printf("DATO: %d\n", (*pa)->info);
        return 1;
    }
    return mostrar_y_contar_hojas(&(*pa)->Hizq) + mostrar_y_contar_hojas(&(*pa)->Hder);
}

int mostrar_y_contar_nohojas(const T_arbol* pa)
{
    if(!*pa) return 0;
    if(!(*pa)->Hizq && !(*pa)->Hder)
        return 0;
    else
        printf("DATO: %d\n", (*pa)->info);
    return mostrar_y_contar_nohojas(&(*pa)->Hizq) + mostrar_y_contar_nohojas(&(*pa)->Hder) + 1;
}

int es_arbol_completo(const T_arbol* pa)
{
    if(!*pa) return 1;
    int hi = altura_arbol(&(*pa)->Hizq);
    int hd = altura_arbol(&(*pa)->Hder);
    if(hi-hd !=0)
        return 0;
    return es_arbol_completo(&(*pa)->Hizq) && es_arbol_completo(&(*pa)->Hder);
}

int es_arbol_AVL(const T_arbol* pa)
{
    if(!*pa) return 1;
    int hi = altura_arbol(&(*pa)->Hizq);
    int hd = altura_arbol(&(*pa)->Hder);
    if(abs(hi-hd) >1)
        return 0;
    return es_arbol_AVL(&(*pa)->Hizq) && es_arbol_AVL(&(*pa)->Hder);
}

int es_arbol_balanceado(const T_arbol* pa)
{
    if(!*pa) return 1;
    int nivel = altura_arbol(pa) - 2;
    if(nivel<0)
        return 1;
    return es_arbol_balanceado_de_nivel(pa, nivel);
}

int es_arbol_balanceado_de_nivel(const T_arbol* pa, int nivel)
{
    if(!*pa || nivel == 0) return 1;
    return es_arbol_balanceado_de_nivel(&(*pa)->Hizq, nivel-1) && es_arbol_balanceado_de_nivel(&(*pa)->Hder, nivel-1);
}

int eliminar_dato_arbol(T_arbol* pa, const T_dato* d, T_cmp comp)
{
    if(!*pa) return 0; //ARBOL VACIO.
    T_nodo** nae = buscar_nodo_arbol(pa, d, comp);
    if(!nae)
        return -1; //NOENCONTRADO.
    eliminar_nodo(nae);
    return 1;
}

void eliminar_nodo(T_arbol* nae)
{
    if(!(*nae)->Hizq && !(*nae)->Hder)
    {
        free(*nae);
        *nae = NULL;
        return;
    }
    int hi = altura_arbol(&(*nae)->Hizq);
    int hd = altura_arbol(&(*nae)->Hder);
    T_nodo** nr = (hi>hd) ? mayor(&(*nae)->Hizq) : menor(&(*nae)->Hder);
    (*nae)->info = (*nr)->info;
    eliminar_nodo(nr);
}

T_nodo** buscar_nodo_arbol(const T_arbol* pa, const T_dato* d, T_cmp comp)
{
    if(!*pa) return NULL;
    int cmp = comp(d, &(*pa)->info);
    if(cmp == 0)
        return (T_arbol*)pa;
    if(cmp < 0)
        return buscar_nodo_arbol(&(*pa)->Hizq, d, comp);
    else
        return buscar_nodo_arbol(&(*pa)->Hder, d, comp);
}

void podar_arbol_dde_nivel(T_arbol* pa, int nivel)
{
    if(!*pa) return;
    if(nivel == 0)
    {
        free(*pa);
        *pa = NULL;
        return;
    }
    podar_arbol_dde_nivel(&(*pa)->Hizq, nivel-1);
    podar_arbol_dde_nivel(&(*pa)->Hder, nivel-1);
}

void imprimir_arbol(const T_arbol* pa)
{
    if(!*pa)
        return;
    int nivel = 0;
    imprimir_arbol_rec(pa, nivel, 0);
}

void imprimir_arbol_rec(const T_arbol* pa, int nivel, int lado)
{
    if(!*pa) return;
    imprimir_arbol_rec(&(*pa)->Hder, nivel+1, 1);
    mostrar_dato(&(*pa)->info, nivel, lado);
    imprimir_arbol_rec(&(*pa)->Hizq, nivel+1, 0);
}

void mostrar_dato(const T_dato* d, int nivel, int lado)
{
    int i;
    printf("\n");
    for(i=0;i<nivel;i++)
        printf("\t");
    if(lado)
          printf("/");
    else
        printf("\\");
    printf("%d", *d);
}

int cargar_arbol_archivo(T_arbol* pa, FILE* arch)
{
    long i = 0;
    fseek(arch, 0L, SEEK_END);
    long d = (ftell(arch)/sizeof(T_dato))-1;
    return cargar_arbol_archivo_rec(pa, arch, i, d);
}

int cargar_arbol_archivo_rec(T_arbol* pa, FILE* arch, long i, long d)
{
    T_dato dat;
    if(i>d)
        return 1;
    long m = (i+d)/2;
    fseek(arch, m*sizeof(T_dato), SEEK_SET);
    fread(&dat, sizeof(T_dato), 1, arch);
    (*pa) = (T_nodo*)malloc(sizeof(T_nodo));
    (*pa)->info = dat;
    (*pa)->Hizq = NULL;
    (*pa)->Hder = NULL;
    int comp = cargar_arbol_archivo_rec(&(*pa)->Hizq, arch, i, m-1);
    if(comp!=1)
        return comp;
    else
        cargar_arbol_archivo_rec(&(*pa)->Hder, arch, m+1, d);
}
