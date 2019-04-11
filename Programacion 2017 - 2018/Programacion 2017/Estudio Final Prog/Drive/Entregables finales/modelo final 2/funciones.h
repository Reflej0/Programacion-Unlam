
#ifndef FUNCIONES_H__
#define FUNCIONES_H__

#include "main.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define     CONMSJ      1

#define     CLA_DUP     2
#define     TODO_BIEN   1
#define     SIN_MEM     0

#define     TAM_LINEA   200


typedef struct
{
    char            linea[TAM_LINEA];
} tInfo;

typedef struct  sNodoD
{
    tInfo   info;
    struct sNodoD  *sig,
                   *ant;
} tNodoD, *tListaD;

void crearArchivo();
void mostrarArchivo(const char *nomArch);
int abrirArchivo(FILE **fp, const char *arch, const char *modo, int conSin);



/** -------------------------x---o---x------------------------------ */
/** FUNCIONES A DESARROLLAR  -, Sus versiones deberían ser sin   _2  */
/** -------------------------x---o---x------------------------------ */

/** esta función recibe el archivo a leer, los archivos a generar ya abiertos
 *      y la lista recién creada.
 *  se encarga de leer el archivo, reemplazar las cadenas abreviadas e insertar
 *      en la lista las líneas que comienzan con fecha y hora ordenando por
 *      fecha y hora, las lineas que no tienen fecha y hora van al archivo de
 *      errores.
 *  luego se encarga de sacar de la lista almacenando en el archivo de salida.
 *  si se produjera algún error con la lista, muestra el mensaje correspondiente
 *      y sigue adelante.
 */
void leerPonerEnListaSacarReemplazarYGrabar_2(FILE *fpEnt, FILE *fpSal,
                                              FILE *fpMal, tListaD *lista);

/** esta función crea la lista como lista vacía
 */
void crearListaD_2(tListaD *p);

/** esta función inserta en orden en la lista, pero si encuentra la misma clave,
 *      devuelve un indicador de Clave Duplicada.
 *  siempre deja la lista con la dirección del último insertado.
 *  devuelve un indicador de fracaso o éxito (SIN_MEM, CLA_DUP o TODO_BIEM).
 */
int insertarEnOrden_2(tListaD *p, const tInfo *d,
                      int (*comp)(const tInfo *d1, const tInfo *d2));

/** se encarga de recuperar la información del primero de la lista,
 *      devolviendo un indicador de éxito o fracaso.
 */
int sacarPrimero_2(tListaD *p, tInfo *d);

/** no obligatorio pero conveniente resolverla para la función que inserta en
 *      la lista doblemente enlazada en forma ordenada.
 */
int compXFechaYHora_2(const tInfo *d1, const tInfo *d2);

/** determina si la línea de texto comienza con una fecha y hora con el formato
 *      dd/mm/aaaa hh:mm:ss,ccc:
 *  no controla que sea una fecha y hora válidas, sólo que esté bien formada.
 */
int empiezaConFechaYHora_2(const char *s);

/** hace los reemplazos de las abreviaciones expandiendo la cadena de carácteres
 */
void reemplazarAbreviaciones_2(char *s);



#endif
