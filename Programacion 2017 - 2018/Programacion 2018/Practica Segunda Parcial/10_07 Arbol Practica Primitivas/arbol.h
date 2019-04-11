#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef int (*T_cmp)(const void*, const void*);

typedef void (*T_do)(const void*);

typedef struct S_nodo
{
    struct S_nodo* Hizq;
    struct S_nodo* Hder;
    T_dato info;
} T_nodo;

typedef T_nodo* T_arbol;

void crear_arbol(T_arbol* pa);

///INSERTAR Y BUSCAR.

int insertar_en_arbol(T_arbol* pa, const T_dato* d, T_cmp cmp);

int buscar_en_arbol(const T_arbol* pa, T_dato* d, T_cmp cmp);

int buscar_en_arbol_ite(const T_arbol* pa, T_dato* d, T_cmp cmp);

size_t altura_arbol(const T_arbol* pa);

///RECORRIDOS.

void recorrer_preorden(const T_arbol* pa, T_do hacer);

void recorrer_inorden(const T_arbol* pa, T_do hacer);

void recorrer_posorden(const T_arbol* pa, T_do hacer);

///MAYOR - MENOR.

T_nodo** mayor(const T_arbol* pa);

T_nodo** menor(const T_arbol* pa);

///MOSTRAR NODOS.

int mostrar_y_contar_hojas(const T_arbol* pa);

int mostrar_y_contar_nohojas(const T_arbol* pa);

int mostrar_nodo_y_cantidad(const T_arbol* pa);

int mostrar_nodo_y_cantidad_rec(const T_arbol* pa, int i);

///ARCHIVO.

void recuperar_arbol_archivo(T_arbol* pa, FILE* arch);

void guardar_arbol_archivo(T_arbol* pa, FILE* arch);

int cargar_arbol_archivo(T_arbol* pa, FILE* arch);

int cargar_arbol_archivo_rec(T_arbol* pa, FILE* arch, long i, long d);

///TIPOS ARBOL.

int es_arbol_completo(const T_arbol* pa);

int es_arbol_AVL(const T_arbol* pa);

int es_arbol_balanceado(const T_arbol* pa);

int es_arbol_balanceado_de_nivel(const T_arbol* pa, int nivel);

///ELIMINAR

void eliminar_arbol(T_arbol* pa);

int eliminar_dato_arbol(T_arbol* pa, const T_dato* d, T_cmp comp);

T_nodo** buscar_nodo_arbol(const T_arbol* pa, const T_dato* d, T_cmp comp);

void eliminar_nodo(T_arbol* nae);

void podar_arbol_dde_nivel(T_arbol* pa, int nivel);

///MOSTRAR ARBOL

void imprimir_arbol(const T_arbol* pa);

void imprimir_arbol_rec(const T_arbol* pa, int nivel, int lado);

void mostrar_dato(const T_dato* d, int nivel, int lado);

#endif // ARBOL_H_INCLUDED
