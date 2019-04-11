#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct{

    int num;
}t_info;

typedef struct s_nodo{

    struct s_nodo*izq;
    t_info info;
    struct s_nodo*der;
}t_nodo;

typedef t_nodo* t_arbol;

typedef int(*t_cmp)(void*a,void*b);

void ingresar_info(t_info*d);
void mostrar_info(t_info*d);
int cmp(void*a,void*b);

void crear_arbol(t_arbol*a);
int insertar_iterativo(t_arbol*a,t_info*d,t_cmp cmp);
void recorrer_pre(t_arbol*a);
void recorrer_in(t_arbol*a);
void recorrer_post(t_arbol*a);
int insertar_recursivo(t_arbol*a,t_info*d,t_cmp cmp);
int buscar_existencia(t_arbol*a,t_info*d,t_cmp cmp);
int mostrar_y_contar_hojas(t_arbol*a);
int mostrar_y_contar_no_hojas(t_arbol*a);
int mostrar_y_contar_hizq(t_arbol*a);
int mostrar_y_contar_hder(t_arbol*a);
int borrar_hojas(t_arbol*a);
void vaciar_arbol(t_arbol*a);
int altura_arbol(t_arbol*a);
int contar_nodos_en_nivel(t_arbol*a,int nivel);

int es_avl(t_arbol*a);
int es_balanceado(t_arbol*a);
int es_completo(t_arbol*a);

void cargar_arbol(t_arbol*a,int dec,t_cmp cmp);
void cargar_arch_bin(char*nom,FILE**pf);
void cargar_arbol_desde_archivo_ord_rec(t_arbol*a,char*nom,FILE**pf,t_cmp cmp,long i,long d);
void cargar_arbol_desde_archivo_ord(t_arbol*a,char*nom,FILE**pf,t_cmp cmp,long i,long d);

#endif // HEADER_H_INCLUDED
