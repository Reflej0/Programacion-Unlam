#ifndef EJERCICIO14_H_INCLUDED
#define EJERCICIO14_H_INCLUDED
#define TAM 100
#define PALABRA 50

size_t _strlen(char *c);

int _strcmp(char c[], char c2[]);

int comparacion_lexicografica(char c[], char c2[]);

int ingresar_cadenas(char c[][PALABRA]);

void imprimir(char c[][PALABRA], int const cantidad);

#endif // EJERCICIO14_H_INCLUDED
