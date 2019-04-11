#include <Arbol.h>

void crear_arbol(t_arbol* pa)
{
    *pa = NULL;
}

int cargar_arbol_de_archivo_ordenado_mio(t_arbol* pa, FILE* arch)
{
    fseek(arch, 0L, SEEK_END);
    long i = 0;
    long d = (ftell(arch)/sizeof(t_reg_ind))-1;
    return cargar_arbol_rec(pa, arch, i, d);
}

int cargar_arbol_rec(t_arbol* pa, FILE* arch, int i, int d)
{
    t_reg_ind dato;
    if(i>d)
    {
        return 1;
    }
    long m = (i+d)/2;
    fseek(arch, m*sizeof(t_reg_ind), SEEK_SET);
    fread(&dato, sizeof(t_reg_ind), 1, arch);
    *pa = (t_nodo_arbol*)malloc(sizeof(t_nodo_arbol));
    (*pa)->info = dato;
    (*pa)->pizq = NULL;
    (*pa)->pder = NULL;
    int resp = cargar_arbol_rec(&(*pa)->pizq, arch, i, m-1);
    if(resp != 1)
    {
        return resp;
    }
    else
    {
        return cargar_arbol_rec(&(*pa)->pder, arch, m+1, d);
    }
}

int buscar_en_arbol_bin_busq(const t_arbol* pa, t_dato_arbol* pd, t_cmp cmp)
{
    if(!*pa)
    {
        return -1;
    }
    int comp = cmp(pd, &(*pa)->info);
    if(comp == 0)
    {
        *pd = (*pa)->info;
        return 1;
    }
    if(comp < 0)
    {
        return buscar_en_arbol_bin_busq(&(*pa)->pizq, pd, cmp);
    }
    else
    {
        return buscar_en_arbol_bin_busq(&(*pa)->pder, pd, cmp);
    }
}

void mostrar_arbol_pre(t_arbol* pa)
{
    if(!*pa)
    {
        return;
    }
    printf("N DEP: %d, C PROD: %s, NRO REG: %ld\n", (*pa)->info.nro_dep, (*pa)->info.cod_prod, (*pa)->info.nro_reg);
    mostrar_arbol_pre(&(*pa)->pizq);
    mostrar_arbol_pre(&(*pa)->pder);
}
