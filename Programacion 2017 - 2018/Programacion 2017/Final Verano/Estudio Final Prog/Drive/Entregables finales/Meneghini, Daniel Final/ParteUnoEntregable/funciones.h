#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SIN_MEM                     0
#define CLA_DUP                     1
#define TODO_BIEN                   2

typedef struct
{
    char    codClie[11],
            codProd[11];
    int     cantUni;
} tInfo;

typedef struct sNodo
{
    tInfo   info;
    struct sNodo   *ant,
                   *sig;
} tNodo, *tLista;


char *buscarPrimerOcurrencia_2(const char *s1, const char *s2);

int contarOcurrencias_2(const char *s1, const char *s2);


void crearYCargarLista(tLista *p);

void mostrarLista(const tLista *p, const char *mensaje);

void vaciarLista(tLista *p);

int compararXClaCliClaProd_2(const tInfo *d1, const tInfo *d2);

void acumular_2(tInfo *d1, const tInfo *d2);

int eliminarDuplicadosYAcumular_2(tLista *,
                                  int (*comp)(const tInfo*, const tInfo*),
                                  void (*acum)(tInfo*, const tInfo*));

void ordenarLista_2(tLista *, int (*comp)(const tInfo*, const tInfo*));

/** debe resolver sus propias versiones de las siguientes funciones         */
/** función(1-a) a reemplazar                                               */
char *buscarPrimerOcurrencia(const char *s1, const char *s2);

/** función(1-b) a reemplazar                                               */
int contarOcurrencias(const char *s1, const char *s2);

/** función(2-a y 2-b) a reemplazar                                         */
int compararXClaCliClaProd(const tInfo *d1, const tInfo *d2);

void acumular(tInfo *d1, const tInfo *d2);

int eliminarDuplicadosYAcumular(tLista *,
                                int (*comp)(const tInfo*, const tInfo*),
                                void (*acum)(tInfo*, const tInfo*));

void ordenarLista(tLista *, int (*comp)(const tInfo*, const tInfo*));

#endif

