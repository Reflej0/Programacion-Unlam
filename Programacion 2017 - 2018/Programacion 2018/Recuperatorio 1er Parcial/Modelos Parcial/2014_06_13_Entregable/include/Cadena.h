#ifndef CADENA_H
#define CADENA_H

#include <stdlib.h>

typedef struct
{
	char * ini;
	char * fin;
} t_palabra;

void normalizar(char* origen, char* destino);
void normalizar_res(char* cad_ori, char* cad_dest);
char * leer_palabra(char * pdesde, t_palabra * palabra);
char * escribir_palabra(char * pdesde, const t_palabra * palabra);
void ucfirst(t_palabra * palabra);
char a_mayus(char c);
char a_minus(char c);
int es_letra(char c);

#endif // CADENA_H
