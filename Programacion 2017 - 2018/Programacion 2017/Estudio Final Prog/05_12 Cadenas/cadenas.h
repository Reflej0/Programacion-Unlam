#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED

size_t _strlen(const char* cadena);

void _strcpy(char* destino, const char *origen);

void _strcat(char* destino, const char* origen);

char* _strchr(char* cadena, int c);

char* _strstr(char* cadena, const char* abuscar);

int _strcmp(const char* c1, const char* c2);

void invertir(char* invertida, const char* cadena);

void normalizar(char* salida, const char* entrada);

#endif // CADENAS_H_INCLUDED
