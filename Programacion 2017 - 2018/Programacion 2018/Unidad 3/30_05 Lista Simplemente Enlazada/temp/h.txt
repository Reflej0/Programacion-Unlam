#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#define FALSO 0
#define VERDADERO 1

typedef int T_dato;

typedef int (*T_cmp) (const void*, const void*);

typedef void (*T_show)(const T_dato*);

typedef void (*T_do)(const T_dato*d);

///Funciones sobre T_dato.

int comp_dato(const void*, const void*);

void tratamiento(const T_dato* d);

typedef struct S_nodo
{
    struct S_nodo* sig;
    T_dato d;
} T_nodo;

typedef T_nodo* T_lista;

///Crea la lista.

void crear_lista(T_lista* l);

///Muestra los elementos de la lista, bajo una funcion del tipo T_show.

void mostrar_lista(const T_lista* l, T_show show);

///Establece la forma en la que se mostrara un dato.

void mostrar_dato(const T_dato* d);

///Agrega un elemento al principio de la lista.

int agregar_al_principio(T_lista* l, const T_dato* d);

///Agrega un elemento al final de la lista.

int agregar_al_final(T_lista* l, const T_dato* d);

///Agrega un elemento segun una posicion indicada en la lista.

int agregar_en_pos(T_lista* l, const T_dato* d, int pos);

///Agrega elementos de forma ordenada, segun un criterio de comparacion y admite duplicados en la lista.

int agregar_ordenado_duplicados(T_lista* l, const T_dato* d, T_cmp comp);

/**Agrega elementos de forma ordenada, segun un criterio de comparacion, no admite duplicados
y permite hacer un tratamiento del dato duplicado en la lista.*/

int agregar_ordenado_no_duplicados(T_lista* l, const T_dato* d, T_cmp comp, T_do hacer);

///Elimina el elemento ubicado al principio de la lista.

int eliminar_del_principio(T_lista* l, T_dato* d);

///Elimina el elemento ubicado al final de la lista.

int eliminar_del_final(T_lista* l, T_dato* d);

///Elimina el elemento segun en una posicion indicada de la lista.

int eliminar_segun_pos(T_lista* l, T_dato* d, int pos);

/**Elimina el elemento segun un criterio de comparacion de la lista.
Elimina la primera aparicion si hubiese mas de una.
Sin importar si la lista esta ordenada o no.*/

int eliminar_segun_comp(T_lista* l, T_dato* d, T_cmp cmp);

///Elimina todos los elementos de la lista.

void eliminar_todos_elementos_lista(T_lista* l);

///Busca un elemento ubicado segun una posicion indicada de la lista.

int buscar_por_posicion(const T_lista* l, T_dato* d, int pos);

/**Busca un elemento segun un criterio de comparacion de la lista.
Retorna la primera aparicion si hubiese mas de una.
Sin importar si la lista esta ordenada o no.*/

int buscar_por_comp(const T_lista* l, T_dato* d, T_cmp cmp);

#endif // LISTA_H_INCLUDED
