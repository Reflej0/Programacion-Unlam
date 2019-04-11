#ifndef ORDENAMIENTO_H_INCLUDED
#define ORDENAMIENTO_H_INCLUDED

typedef int (*T_cmp) (const void*, const void*);

typedef struct
{
    int dni;
    char* nombre;
} T_alumno;

int cmp_alu(const void* alu1, const void* alu2);

void ingresar_lote_alumnos(T_alumno *alumnos);

void ordenar_alumnos(T_alumno *alumnos, size_t cantidad_alumnos, T_cmp cmp_alu);

void intercambiar_punteros(void** p1, void** p2);

void mostrar_alumnos(T_alumno *alumnos, size_t cantidad_alumnos);

#endif // ORDENAMIENTO_H_INCLUDED
