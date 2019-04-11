#ifndef BIBLITECA_H
#define BIBLITECA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "info.h"
#include "lista.h"


#define EXIST           "maeprod"
#define MODO_1          "r+b"
#define CONMSJ          1
#define NOVED           "noveda.txt"
#define MODO_2          "rt"

int abrirArchivo(FILE **fp, const char *arch, const char *modo, int conSin);

void crearArchivos(void);

int leerYMostrarExist(FILE *fp);

/** debe desarrollar estas tres funciones ... **/
int leerArchivoYCargarLista(FILE *fp, t_lista *lista);
int eliminarDuplicados(t_lista *p);
int sacarDeListaYActualizarArchivo(FILE *fp, t_lista *d);
int comparar(const t_info *,const t_info *);
void acumularYMaxPrecio(t_info *, t_info *);
//int leerArchivoYCargarLista(FILE *fp, t_lista *lista, int(*insertarAlFinal)(const t_info *, const t_info *);

/** ... reemplazando el uso de estas **/
int leerArchivoYCargarLista_2(FILE *fp, t_lista *lista);
int eliminarDuplicados_2(t_lista *p);
int sacarDeListaYActualizarArchivo_2(FILE *fp, t_lista *d);



#endif // BIBLITECA_H
