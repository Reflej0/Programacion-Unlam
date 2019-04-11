#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#define TODO_OK 1
#define ERR_MALLOC -1
#define FALSO 0
#define VERDADERO 1

typedef struct{

    int num;
}t_dato;

typedef struct s_nodo{

    struct s_nodo* hizq;
    t_dato info;
    struct s_nodo* hder;
}t_nodo;

typedef t_nodo* t_arbol;

typedef int(*t_cmp)(void*,void*);

int cmp(void*d1,void*d2);

void crear_arbol(t_arbol*a);

void insertar_dato(t_dato*d);

void mostrar_dato(t_dato*d);

int insertar_en_arbol_iterativa(t_arbol*a,t_dato*d,t_cmp cmp);

void recorrer_arbol_preorden(t_arbol*a);
void recorrer_arbol_inorden(t_arbol*a);
void recorrer_arbol_postorden(t_arbol*a);

int insertar_en_arbol_recursiva(t_arbol*a,t_dato*d,t_cmp cmp);

int buscar_en_arbol_bin(t_arbol*a,t_dato*d,t_cmp cmp);

int contar_y_mostrar_hojas(t_arbol*a);

int contar_y_mostrar_nodos_no_hojas(t_arbol*a);

int mostrar_y_constar_hder(t_arbol*a);

int mostrar_y_constar_hizq(t_arbol*a);

void borrar_hojas(t_arbol*a);

void vaciar_arbol(t_arbol*a);

int altura_arbol(t_arbol*a);

int contar_nodos_nivel(t_arbol*a,int nivel);

int es_arbol_completo(t_arbol*a);

int es_arbol_balanceado(t_arbol*a);

int es_arbol_avl(t_arbol*a);

void podar_arbol_desde_nivel_n(t_arbol*a,int nivel);

int cargar_arbol_rec(t_arbol*a,FILE*arch,long i,long d,t_cmp cmp);

int cargar_arbol_de_arch_ord(t_arbol*a,FILE*arch,t_cmp cmp);

///-------- para eliminar_de_arbol

void eliminar_nodo(t_nodo**nae);

t_nodo** buscar_nodo(t_arbol*pa,t_dato*d,t_cmp cmp);

t_nodo** mayor(t_arbol*pa);

t_nodo** menor(t_arbol*pa);

int eliminar_de_arbol(t_arbol*pa,t_dato*d,t_cmp);

void mostrar_por_nodo(t_nodo**pa);

///------avl_bal_comp clase-------------------------

int es_arbol_completo_hasta_nivel(t_arbol*pa,int nivel);

int es_arbol_avl_clase(t_arbol*pa);

int es_arbol_completo_clase(t_arbol*pa);

int es_arbol_balanceado_clase(t_arbol*pa);


///------- otras funciones--------------------------------------------------

void cargar_arbol(t_arbol*a,t_cmp cmp,int selec);

#endif // HEADER_H_INCLUDED
