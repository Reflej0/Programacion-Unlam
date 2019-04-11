#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char            codigo[7];
    char            descripcion[26];
    double          cantidad;
    char            uniMedida[11];
} t_info;

typedef struct sNodo
{
    t_info           info;
    struct sNodo   *sig,
                   *ant;
} t_nodo;

typedef t_nodo* t_lista;

typedef int (*t_cmp) (const void*v1,const void*v2);

void mostrarInfo(const t_info *i);
void crearLista(t_lista *l);
int insertarEnListaDesordenada(t_lista *l,const t_info *i);
void recorrerLista(const t_lista*l);
void eliminarDuplicados(t_lista*l);
void mostrarBaja(int cantElem,double cantProd,char codigo[]);

#endif // LISTADOBLE_H_INCLUDED
