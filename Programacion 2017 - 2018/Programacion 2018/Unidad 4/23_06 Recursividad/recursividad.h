#ifndef RECURSIVIDAD_H_INCLUDED
#define RECURSIVIDAD_H_INCLUDED

size_t _strlen(const char* s);

long long _factorial(long long n);

long long _primeros_n_cuadrado(long long n);

void _mostrar_cadena_menos_caracter(const char* s, const char c);

void _mostrar_cadena_escalonada(const char* s);

void _mostrar_cadena_escalonada_recursivo(const char* s, const char* inicio);

void _print_vector_int(const int* v, size_t l, const char separador);

void _print_vector_int_recursivo(const int* v, const int* fin, const char separador);

#endif // RECURSIVIDAD_H_INCLUDED
