#ifndef LISTA_H
#define LISTA_H

#include "info.h"


#define SIN_MEM            0
#define TODO_BIEN          1

typedef t_noved t_info;

typedef struct s_nodo
{
   t_info info;
   struct s_nodo *sig;
} t_nodo;

typedef t_nodo *t_lista;

void crearLista(t_lista *p);

int listaLlena(t_lista *);

int insertarAlFinal(t_lista *p, const t_info *d);

void vaciarLista(t_lista *p);

int mostrarLista(t_lista *p);

int listaVacia(t_lista *p);

int sacarPrimeroLista(t_lista *p, t_info *d);


#endif // LISTA_H
