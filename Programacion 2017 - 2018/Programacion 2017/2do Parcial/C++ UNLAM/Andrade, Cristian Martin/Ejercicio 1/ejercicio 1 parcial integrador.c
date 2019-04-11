#include <stdio.h>
#include <stdlib.h>
#define ERROR -1

/*********** ARCHIVO *****************/
typedef struct
{
    char nombre_articulo[50];
    float cant;
}t_archivo;
/************** ARBOL ****************/
typedef struct
{
    int CodArticulo;
    char CodRubro;
    float cantidad;
}t_infoArb;

typedef struct s_nodoArb
{
    t_infoArb datos;
    struct s_nodoArb* izq;
    struct s_nodoArb* der;
}t_nodoArb;

typedef t_nodoArb* t_arbol;
/************ LISTA **************/

typedef struct
{
    char CodigoRubro;
    float SumatoriaCantidades;
}t_infoLista;

typedef struct s_nodo
{
    t_infoLista datos;
    struct s_nodo* ant;
    struct s_nodo* sig;
}t_nodoLista;

typedef t_nodoLista* t_lista;

/*************************************/
int recorrerArbolAcualizandoArchivo(t_arbol*,t_lista*,FILE*,int);
int recorrerGuardando(t_arbol*,t_lista*,FILE*,int, int*);
void crearLista(t_lista*);
int insertarEnListaDoble(t_lista*,t_infoLista*);
int compara(t_infoLista*,t_infoLista*);

int main ()
{
    FILE *pf;
    t_arbol arbol; ///ya se encuentra cargado
    t_lista lista;
    int cant,altura;
    pf = fopen("Archivo stock.bin","r+b");
    if(!pf)
        exit(1);
    printf("\nIngrese la altura del arbol deseada: ");
    scanf("%d",&altura);
    crearLista(&lista);
    cant = recorrerArbolAcualizandoArchivo(&arbol,&lista,pf,altura);
    if(cant != ERROR)
        printf("\nCantidad de nodos visitados: %d",cant);
    else
        printf("\nHa ocurrido un error");
    fclose(pf);
    return 0;
}

//////////////////////////////////////////////
int recorrerArbolAcualizandoArchivo(t_arbol*pa,t_lista*pl,FILE*pf, int altura)
{
    int cantidad = 0;
    if(!recorrerGuardando(pa,pl,pf,altura,&cantidad))
        return ERROR;
    return cantidad;
}
//////////////////////////////////////////////////////////
int recorrerGuardando(t_arbol*pa, t_lista*pl, FILE*pf, int alt, int* cant)
{
    t_infoLista aux;
    t_archivo auxArch;
    if(*pa)
    {
        *cant++;
        if(alt!=0)
        {
            recorrerGuardando(&(*pa)->izq,pl,pf,alt-1,cant);
            recorrerGuardando(&(*pa)->der,pl,pf,alt-1,cant);
        }
        else
        {
            aux.CodigoRubro=(*pa)->datos.CodRubro;
            aux.SumatoriaCantidades=(*pa)->datos.cantidad;
            if(!insertarEnListaDoble(pl,&aux))           ///dudas en esto (justo en lo que tuve dudas practicando)
                return 0;                                //
            fseek(pf,sizeof(t_archivo)*((*pa)->datos.CodArticulo),0);
            fread(&auxArch,sizeof(t_archivo),1,pf);
            fseek(pf,sizeof(t_archivo)*((*pa)->datos.CodArticulo),0);
            auxArch.cant+=(*pa)->datos.cantidad;
            fwrite(&auxArch,sizeof(t_archivo),1,pf);
        }
    }
}
///////////////////////////////////////////////////
int insertarEnListaDoble(t_lista*pl,t_infoLista* d)
{
    int cmp=-1;  ///es para que, si nunca entra al while, poder determinar que es el primer elemento de la lista
    t_nodoLista* nue;
    while(*pl && (cmp=compara(&(*pl)->datos,d))<=0)
    {
        if(cmp>0)
            *pl=(*pl)->sig;
        if(cmp<0)
            *pl=(*pl)->ant;
    }
    if(cmp==0)
    {
        (*pl)->datos.SumatoriaCantidades += (*d).SumatoriaCantidades;
    }
    else
    {
        nue = malloc(sizeof(t_nodoLista));
        if(!nue)
            return 0;
    }
    if(cmp=-1) ///pregunto si es primer nodo
    {
        nue->ant=NULL;
        nue->sig=NULL;
    }
    else
    {

    }
    return 1;
}
//////////////////////////////////////////////////////
void crearLista(t_lista*pl)
{
    *pl=NULL;
}
////////////////////////////////////////////////////
int compara(t_infoLista* d1,t_infoLista* d2)
{
    return d1->CodigoRubro - d2->CodigoRubro;
}
