#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define BURBUJA 0
#define SELECCION 1
#define INSERCION 2
#define ASC 0
#define DESC 1
#define INT 0
#define FLOAT 1
#define CHAR 2

typedef int (*T_cmp)(const void*, const void*, int forma);

void ordenamiento_generico(void* v, size_t nro_elementos, size_t tam, int metodo, int forma, T_cmp comp);

void* buscarmenormax(void* v, int pos_ini, size_t nro_elementos, size_t tam, int forma, T_cmp comp);

//Intercambio y mostrar vector genericos.

void intercambio_generico(void* a, void* b, size_t tam);

void mostrar_vector(void* v, size_t nro_elementos, int tipo);

//Funciones de comparacion para enteros, flotantes y char.

int comp_int(const void* a, const void* b, int forma);

int comp_float(const void* a, const void* b, int forma);

int comp_letras(const void* a, const void* b, int forma);

#endif // HEADER_H_INCLUDED
