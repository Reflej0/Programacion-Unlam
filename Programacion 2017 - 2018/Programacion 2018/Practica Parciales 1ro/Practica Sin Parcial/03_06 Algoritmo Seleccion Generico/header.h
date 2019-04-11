#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define ASC 0
#define DESC 1

typedef int (*T_cmp) (const void*, const void*, int);

int comp_int(const void* a, const void* b, int);

void* buscarMenor(void* v, void* pos_ini, const size_t size_ele, T_cmp cmp, const int orden);

void intercambiar(void* a, void* b, const size_t s);

void ordenar(void* v, const size_t size_ele, const size_t nro_ele, T_cmp cmp, const int orden)

void mostrar_vector_int(int* v, const size_t nro_ele);

#endif // HEADER_H_INCLUDED
