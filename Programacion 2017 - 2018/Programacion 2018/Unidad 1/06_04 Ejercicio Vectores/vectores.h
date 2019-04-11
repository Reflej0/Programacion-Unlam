#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

int Insertar_Elemento_Vector(int* vec, int tam, int elemento, int posicion);

int Insertar_Elemento_Ordenado_Vector(int* vec, int tam, int elemento);

int Insertar_Elemento_Ordenado_Vector_2(int* vec, int tam, int elemento);

int Eliminar_Elemento_Posicion_Vector(int* vec, int tam, int posicion);

void Eliminar_Primera_Aparicion_Elemento_Vector(int* vec, int tam, int elemento);

int Eliminar_Todas_Apariciones_Elemento_Vector(int* vec, int tam, int elemento);

void Mostrar_Vector(int* vec, int tam);

#endif // VECTORES_H_INCLUDED
