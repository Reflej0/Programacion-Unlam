#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

size_t strlen(char const *cadena);

int strcmp(char const *c, char const *c2);

int comparacion_lexicografica(char c[], char c2[]);

void strcpy(char const *fuente, char *destino);

int strchr(char const *cadena, char caracter);

#endif // STRING_H_INCLUDED
