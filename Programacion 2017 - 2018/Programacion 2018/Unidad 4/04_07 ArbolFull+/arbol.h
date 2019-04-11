#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#define VERDADERO 1
#define FALSO 0
#define DUPLICADO -1
#define FALTA_MEMORIA -2
#define ARBOL_VACIO 0
#define NO_ENCONTRADO 0
#define ENCONTRADO 1

///T_CMP
typedef int (*T_cmp) (const void*, const void*);

///FUNCION DE COMPARACION
int cmp(const void* e1, const void* e2);

///T_DATO
typedef int T_dato;

///NODO DEL ARBOL
typedef struct S_nodo
{
    struct S_nodo* Hizq;
    struct S_nodo* Hder;
    T_dato info;
} T_nodo;


typedef T_nodo* T_arbol;

void crear_arbol(T_arbol* pa);

///CANTIDAD NODOS, HOJAS, NO HOJAS.

int cant_nodos(T_arbol* pa);

int cant_nodos_internos(T_arbol* pa);

int cant_hojas(T_arbol* pa);

int ver_arbol_y_nodos(T_arbol* pa, int i);

///BUSCAR, INSERTAR, ALTURA.

int buscar_en_arbol(const T_arbol* pa, T_dato* d, T_cmp cmp);

int insertar_en_arbol(T_arbol* pa, const T_dato* d, T_cmp cmp);

int insertar_en_arbol_ite(T_arbol* pa, const T_dato* d, T_cmp cmp);

int altura_arbol(const T_arbol* pa);

/// MOSTRAR ARBOL PRE-IN-POS

void mostrar_arbol_pre(const T_arbol* pa);

void mostrar_arbol_in(const T_arbol* pa);

void mostrar_arbol_pos(const T_arbol* pa);

///ELIMINAR DE ARBOL, ARBOL, PODAR.

void eliminar_arbol(T_arbol* pa);

int eliminar_de_arbol(T_arbol* pa, T_dato* d, T_cmp cmp);

T_nodo** buscar_nodo(T_arbol* pa, T_dato* d, T_cmp cmp);

void eliminar_nodo(T_arbol* nae);

void podar_arbol_dde_nivel(T_arbol* pa, int nivel);

///BUSCAR MAYOR/MENOR.

T_nodo** mayor(T_arbol* pa);

T_nodo** menor(T_arbol* pa);

///ARBOL COMPLETO - AVL - BALANCEADO

int es_arbol_completo(const T_arbol* pa);

int es_arbol_avl(const T_arbol* pa);

int es_arbol_balanceado(const T_arbol* pa);

int es_arbol_balanceado_hasta_nivel(const T_arbol* pa, int nivel);

///ARBOL - ARCHIVO.

int cargar_arbol_de_archivo_ord(T_arbol* pa, FILE* arch);

int cargar_arbol_rec(T_arbol* pa, FILE* arch, long i, long d);

void guardar_arbol_archivo(T_arbol* pa, FILE* arch);

void leer_arbol_archivo(T_arbol* pa, FILE* arch);

///RENATA 04-07

void mostrar_nodo_arbol(const T_arbol* pa);

int contar_mostrar_nodos(const T_arbol* pa);

int contar_mostrar_hojas(const T_arbol* pa);

int contar_mostrar_nohojas(const T_arbol* pa);

int contar_nodos_hijos_izq(const T_arbol* pa);

int contar_nodos_hijos_der(const T_arbol* pa);

int contar_nodos_hijos_soloizq(const T_arbol* pa);

int contar_nodos_hijos_soloder(const T_arbol* pa);

int mostrar_contar_nodos_de_altura(const T_arbol* pa, const int a);

int mostrar_contar_nodos_de_altura_rec(const T_arbol* pa, const int amax, int aactual);

int mostrar_contar_nodos_hasta_altura(const T_arbol* pa, const int a);

int mostrar_contar_nodos_hasta_altura_rec(const T_arbol* pa, const int amax, int aactual);

int contar_podar_hojas(T_arbol* pa);

#endif // ARBOL_H_INCLUDED
