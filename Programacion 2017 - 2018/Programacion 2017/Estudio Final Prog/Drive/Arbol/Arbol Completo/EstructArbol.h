#ifndef ESTRUCTARBOL_H_INCLUDED
#define ESTRUCTARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define CLAVE_DUPLICADA 0
#define TRUE 1

typedef struct
{
    int x;
}t_dato;

typedef struct s_nodo{
    t_dato dato;
    struct s_nodo *izq,
                  *der;
}t_nodo;

typedef t_nodo* t_arbol;



void crearArbol(t_arbol*);
///ARBOL BINARIO DE EXPRESION
void mostrarInOrden(t_arbol*);
void mostrarPreOrden(t_arbol*);
void mostrarPosOrden(t_arbol*);

///ARBOL BINARIO DE BUSQUEDA-> SIN CLAVES DUPLICADAS. MAYOR A DERECHA. MENOR A IZQUIERDA.
int insertarEnArbolDeBusqueda(t_arbol*, t_dato *, int (*cmp)(const void*,const void*));
int insertar_en_arbol_de_busqueda(t_arbol *pa, const t_dato *d, int (*cmp)(const void*,const void*));

int insertarEnArbolDeBusqueda(t_arbol*,t_dato*, int (*cmp)(const void*,const void*));
void GuardarPreOrden(t_arbol *raiz,FILE** pf);
void GuardarPosOrden(t_arbol *raiz,FILE** pf);
void GuardarInOrden(t_arbol *raiz,FILE** pf);
t_nodo* BuscarNodoPadreEnArbolDeBusqueda(t_arbol *raiz, t_dato *d,int (*cmp)(const void*,const void*));
int contarNodos(t_arbol *raiz);
int contarHojas(t_arbol *raiz);
int mostrarContarHojas(t_arbol *raiz);
int contarMostrarNoHojas(t_arbol *raiz);
int contarSoloNoHojas(t_arbol *raiz);
int contarMostrarNodosDeNivel(t_arbol *raiz,int nivel);
int contarNodosAnterioresANivel(t_arbol *raiz,int nivel);
int CortarHojas(t_arbol *raiz);
void  borrarArbol(t_arbol *raiz);
int contarMostrarHijosPorIzquierda(t_arbol *raiz);
int contarMostrarHijosPorDerecha(t_arbol *raiz);
void PodarNivel(t_arbol *raiz,int nivel,void(*borrar)(t_arbol *));
int alturaArbol(t_arbol* raiz);
int comparar(const void* s1,const void* s2);
t_arbol* buscarMayor(t_arbol* raiz);
t_arbol* buscarMenor(t_arbol* raiz);
int eliminarNodo(t_arbol *raiz,t_dato *d,int(*cmp)(const void*, const void*));
t_arbol* buscarDevolverPos(t_arbol *raiz, const t_dato *d, int(*cmp)(const void*, const void*));
#endif // ESTRUCTARBOL_H_INCLUDED
