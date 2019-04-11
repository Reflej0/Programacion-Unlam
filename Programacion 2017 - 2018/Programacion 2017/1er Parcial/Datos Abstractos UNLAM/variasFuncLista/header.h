#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#define ERR_MALLOC -1
#define TODO_OK 1
#define NO_ENCONTRADO -2
#define VACIA -3;

typedef struct{

    int numero;
    int cantidad;
}t_dato;

typedef struct s_nodo{

    t_dato info;
    struct s_nodo*sig;

}t_nodo;

typedef t_nodo* t_lista;

typedef int(*t_cmp)(void*a,void*b);

int cmp(void*a,void*b);
void ingresar_dato(t_dato*d);
void mostrar_dato(t_dato*d);

//------- primitivas lista

void crear_lista(t_lista*pl);
int poner_en_lista_desordenado(t_lista*pl,t_dato*d);
int poner_en_lista_ordenado(t_lista*pl,t_dato*d,t_cmp cmp);
int sacar_elemento_por_llave(t_lista*pl,t_dato*d,t_cmp cmp);
int sacar_ultimo(t_lista*pl,t_dato*d);

void sacar_por_punt(t_lista*pl,t_nodo*sacar);
void agregar_por_punt(t_lista*pl,t_nodo*agregar);

void ordenar_lista(t_lista*pl,t_cmp cmp);

//----------- otros

void recorrer_lista_simple(t_lista*pl);

#endif // HEADER_H_INCLUDED
