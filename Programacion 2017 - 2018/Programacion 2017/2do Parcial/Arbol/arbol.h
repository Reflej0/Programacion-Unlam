#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef int T_dato;

typedef struct S_nodo
{
    T_dato info;
    struct S_nodo* Hizq;
    struct S_nodo* Hder;
} T_nodo;

typedef T_nodo* T_arbol;

typedef int(T_cmp)(const void*, const void*);

int cmp(const void* d1, const void* d2);

void crear_arbol_bin(T_arbol* pa);

int buscar_en_arbol_bin(const T_arbol* pa, T_dato* d, T_cmp cmp);

int insertar_en_arbol_bin(T_arbol* pa, T_dato* d, T_cmp cmp);

int altura_arbol_bin(const T_arbol* pa);

int cargaAutomatica(T_arbol* pa, T_cmp cmp);

void eliminarArbol(T_arbol* pa);

void mostrarPreOrden(T_arbol* pa);

void mostrarInOrden(T_arbol* pa);

void mostrarPosOrden(T_arbol* pa);

int eliminar_de_arbol_bin(T_arbol* pa, T_dato* d, T_cmp cmp);

T_nodo** buscar_nodo(T_arbol* pa, T_dato* d, T_cmp cmp);

void eliminar_nodo(T_nodo** nae);

T_nodo** mayor(T_arbol* pa);

T_nodo** menor(T_arbol* pa);

int es_arbol_completo(const T_arbol* pa);

int es_arbol_avl(const T_arbol* pa);

int es_arbol_balanceado(const T_arbol* pa);

int es_arbol_completo_hasta_nivel(const T_arbol* pa, int nivel);

void vaciar_arbol(T_arbol* pa);

void podar_arbol_dde_nivel(T_arbol* pa, int nivel);

int cargar_arbol_de_archivo_ord(T_arbol* pa, FILE* arch);

int cargar_arbol_rec(T_arbol* pa, FILE* arch, long i, long d);

void generarArchivoArbol(FILE* arch);

#endif // ARBOL_H_INCLUDED
