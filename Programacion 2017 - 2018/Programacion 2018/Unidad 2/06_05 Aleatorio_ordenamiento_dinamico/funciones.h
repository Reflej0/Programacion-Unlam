#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define ENTERO 0
#define REAL 1
#define CARACTER 2

void generar_semilla();

int generar_int_aleatorio(int menor, int mayor);

float generar_float_aleatorio(int menor, int mayor);

char generar_caracter_aleatorio();

void llenar_vector(void* v, size_t tam, int tipo);

void mostrar_vector(void* v, size_t tam, int tipo);

int comp_int(const void* a, const void* b);

int comp_float(const void* a, const void* b);

int comp_char(const void* a, const void* b);

#endif // FUNCIONES_H_INCLUDED
