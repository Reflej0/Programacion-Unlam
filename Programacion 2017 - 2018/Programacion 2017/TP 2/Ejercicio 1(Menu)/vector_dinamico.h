#ifndef VECTOR_DINAMICO_H_INCLUDED
#define VECTOR_DINAMICO_H_INCLUDED

typedef struct vector vector_t;

//Crea el vector.
vector_t* vector_crear(size_t tam_inicial);

//Agrega el elemento, informa sobre errores.
int vector_agregar(vector_t* vector, size_t indice, void* elemento);

//Devuelve el elemento en el indice.
void* vector_obtener(vector_t* size_t indice);

//Devuelve el tamaño del vector.
size_t vector_obtener_tam(vector_t* vector);

//Redimensiona el vector, informa sobre errores.
int vector_redimensionar(vector_t* vector, size_t nuevotam);

//Libera la memoria del vector. Podría devolver error MUY raramente.
void vector_destruir(vector_t* vector);

#endif // VECTOR_DINAMICO_H_INCLUDED
