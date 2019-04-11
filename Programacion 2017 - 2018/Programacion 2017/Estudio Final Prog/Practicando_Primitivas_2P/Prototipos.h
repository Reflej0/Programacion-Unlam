#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>

typedef int t_dato;
typedef struct s_nodo_a
{
    t_dato info;
    struct s_nodo_a *pder;
    struct s_nodo_a *pizq;
}t_nodo_a;

typedef struct s_nodo_lis
{
    t_dato info;
    struct s_nodo_lis *psig;
    struct s_nodo_lis *pant;
}t_nodo_lis;

typedef t_nodo_lis *t_lista;



typedef t_nodo_a *t_arbol;
typedef int(*t_cmp)(const void *,const void *);
int cmp(const void *,const void *);


///LISTA DOBLE
void crear_Lista(t_lista *);
void mostrar_Lista_Doble(t_lista *);
int insertar_en_lista_ord(t_lista *,t_dato *,t_cmp );
int eliminar_duplicados_lista(t_lista *,t_cmp );
int sacar_primero_de_lista_ord(t_lista *,t_dato *);
int ordenarLista(t_lista *pl,t_cmp cmp);
int agregar_al_principio(t_lista* pl, t_dato* d);
int eliminar_elemento_de_lista(t_lista *,t_dato *,t_cmp );
///FUNCIONES PARA ELIMINAR UN ELEMENTO DEL ARBOL Y DEJARLO BALANCEADO
int eliminar_de_arbol_bin(t_arbol *,t_dato *,t_cmp );
t_nodo_a **buscar_en_arbol_bin(t_arbol *,t_dato *,t_cmp );
void eliminar_nodo(t_arbol *);
t_arbol *mayor(t_arbol *);
t_arbol *menor(t_arbol *);
int altura_arbol(t_arbol *);
///ELIMINAR TODOS LOS NODOS DE UN NIVEL Y DEJARLO BALANCEADO
void eliminar_nodos_de_nivel(t_arbol *,int ,t_cmp );
///INSERTAR EN UN ARBOL BALANCEADO
int insertar_en_arbol_bin(t_arbol *pa,t_dato *pd,t_cmp cmp);
///CARGAR ARBOL A PARTIR DE ARCHIVO ORDENADO
int cargar_arbol_desde_archivo(t_arbol *,FILE *);
int cargar_arbol_rec(t_arbol *,long ,long ,FILE *);
///VER SI EL ARBOL ESTA BALANCEADO
int es_arbol_balanceado(t_arbol *);
int contar_nodos_de_nivel(t_arbol *,int );

#endif // PROTOTIPOS_H_INCLUDED
