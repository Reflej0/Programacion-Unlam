#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

size_t _strlen(const char* cadena);

void _strcpy(char* destino, const char *origen);

void _strcat(char* destino, const char* origen);

char* _strchr(char* cadena, int c);

char* _strstr(char* cadena, char* abuscar);

int _strcmp(const char* c1, const char* c2);

void invertir(char* invertida, char* cadena);

void normalizar(char* salida, const char* entrada);

#endif // STRING_H_INCLUDED
