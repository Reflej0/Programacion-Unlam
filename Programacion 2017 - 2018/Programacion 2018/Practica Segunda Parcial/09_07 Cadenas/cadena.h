#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED
#define _TOUPPER(a) (a>='a' && a<='z') ? (a-32) : a
#define _TOLOWER(a) (a>='A' && a<='Z') ? (a+32) : a
#define _ESLETRA(a) (a>='a' && a<='z') || (a>='A' && a<='Z') ? 1 : 0

size_t _strlen(const char* s);

char* _strcpy(char* dest, const char* src);

char* _strncpy(char *dest, const char* src, size_t n);

char* _strcat(char* dest, const char* src);

char* _strncat(char* dest, const char* src, size_t n);

int _strcmp(const char* s1, const char* s2);

int _strncmp(const char* s1, const char* s2, size_t n);

size_t _strcspn(const char* s1, const char* s2);

char* _strpbrk(const char* s1, const char* s2);

char* _strstr(const char* s, const char* b);

char* normalizar_nombre(char* nombre);

char* normalizar_numeros(char* numeros);

int _strstrcantidad(const char* s, const char* b);

char* reemplazar_identicos(char* s, const char* b, const char* re);

char* __itoa(int n, char* s, int base);

char* invertir_cadena(char* s);

#endif // CADENA_H_INCLUDED
