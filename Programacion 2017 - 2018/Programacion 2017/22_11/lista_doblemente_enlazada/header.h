#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#define TODO_OK 1
#define ERR_MALLOC -1
#define LISTA_VACIA -2
#define NO_ESTA -3

typedef struct{

    int num;
}t_info;

typedef struct s_nodo{

    struct s_nodo* ant;
    t_info info;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_lista;

typedef int(*t_cmp)(void*,void*);

int cmp(void*d1,void*d2);

void ingresar_dato(t_info*d);
void mostrar_dato(t_info*d);

void crear_lista(t_lista*pl);

int insertar_al_principio(t_lista*pl,t_info*d);
int recorrer_desde_principio(t_lista*pl);
int recorrer_desde_final(t_lista*pl);
int insertar_al_final(t_lista*pl,t_info*d);

int eliminar_de_lista(t_lista*pl,t_info*d,t_cmp cmp);

void vaciar_lista(t_lista*pl);

void eliminar_logicamente(t_lista*pl,t_nodo*nae);
void insertar_logicamente_final(t_lista*pl,t_nodo*nai);

void ordenar_lista(t_lista*pl,t_cmp cmp);

#endif // HEADER_H_INCLUDED
