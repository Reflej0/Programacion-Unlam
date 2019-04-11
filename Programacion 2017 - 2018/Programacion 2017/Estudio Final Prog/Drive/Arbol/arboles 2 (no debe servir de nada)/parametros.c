#include "parametros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compararDni(const void* s1,const void* s2)
{
    return (((t_info*)s1)->dni)-(((t_info*)s2)->dni);
}

void crearArbol(t_arbol* a)
{
    *a=NULL;
}

int insertarEnArbol(t_arbol* p,void* d,int tam,int (*cmp)(const void*,const void*))
{
    while(*p)
    {
        if(cmp((*p)->info,d)<0)
            p=&(*p)->der;
        else if(cmp((*p)->info,d)>0)
            p=&(*p)->izq;
        else return 0;
    }
    *p=(t_nodo*)malloc(sizeof(t_nodo));
    (*p)->der=(*p)->izq=NULL;
    (*p)->info=malloc(tam);
    memcpy((*p)->info,d,tam);
    printf("DNI(pruebo la insercion):%d\n",((t_info*)(*p)->info)->dni);
    return 1;
}

void vaciarArbol(t_arbol* p)
{
    if(!*p)
        return;
    vaciarArbol(&(*p)->izq);
    vaciarArbol(&(*p)->izq);
    free((*p)->info);
    free((*p));
    *p=NULL;
}

int alturaArbol(t_arbol* p)
{
    int i,j;
    if(!*p)
        return 0;
    i=alturaArbol(&(*p)->izq);
    j=alturaArbol(&(*p)->der);
    return i>j?i+1:j+1;
}

int nivelArbol(t_arbol* p)
{
    int i,j;
    if(!*p)
        return -1;
    i=alturaArbol(&(*p)->izq);
    j=alturaArbol(&(*p)->der);
    return i>j?i+1:j+1;
}

void* buscarMayor(t_arbol* p)
{
    void* aux=NULL;
    while(*p)
    {
        aux=(*p)->info;
        p=&(*p)->der;
    }
    return aux;
}

void* buscarMenor(t_arbol* p)
{
    void* aux=NULL;
    while(*p)
    {
        aux=(*p)->info;
        p=&(*p)->izq;
    }
    return aux;
}

t_nodo** buscarNodoPadre(t_arbol* p,void* d,int (*cmp)(const void*,const void*))///guarda la direccion de la
                                                            ///parte de la estructura que apunta al nodo buscado
{
    while(*p)
    {
        if(cmp((*p)->info,d)<0)
            p=&(*p)->der;
        else if(cmp((*p)->info,d)>0)
            p=&(*p)->izq;
        else
            return p;

    }
    return NULL;

}

