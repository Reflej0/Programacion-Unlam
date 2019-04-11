#ifndef EJERCICIO3_H_INCLUDED
#define EJERCICIO3_H_INCLUDED

typedef struct
{
   int suma;
   float promedio;
} suma_promedio;

int ingresar_numero(int* vector);

void sumaypromedio(int* vector, size_t tam, suma_promedio *resultado);


#endif // EJERCICIO3_H_INCLUDED
