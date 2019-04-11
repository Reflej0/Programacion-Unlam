#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include<tipos.h>
#define OK 1
#define LISTA_LLENA 2

typedef int (*t_cmp_lista)(const t_info *, const t_info*);

typedef struct s_nodo{
    t_info info;
    struct s_nodo * psig;
}t_nodo;

typedef t_nodo * t_lista;

void crear_lista_res(t_lista * plista);
int lista_llena_res(const t_lista * plista);
int instertar_prim5_lista_res(t_lista * plista, const t_info * pinfo, int (*comp)(const t_info *, const t_info*));
int instertar_prim5_lista(t_lista * plista, const t_info * pinfo, int (*comp)(const t_info *, const t_info*));
int instertar_lista_res(t_lista * plista, const t_info * pinfo, int (*comp)(const t_info *, const t_info*));
int instertar_lista(t_lista * plista, const t_info * pinfo, int (*comp)(const t_info *, const t_info*));
int eliminar_lista_res(t_lista * plista, t_info * pinfo, int (*comp)(const t_info *, const t_info*));
int eliminar_lista(t_lista * plista, t_info * pinfo, int (*comp)(const t_info *, const t_info*));
int cargar_lista_de_archivo_ordenado(t_lista* plista, const char* path); ///Retorna TODO_OK, ERROR_ARCHIVO o SIN_MEM
int cargar_lista_de_archivo_ordenado_res(t_lista* plista, const char* path); ///Retorna TODO_OK, ERROR_ARCHIVO o SIN_MEM
void recorrer_lista_res(const t_lista * plista, void (*accion)(t_info* pinfo, void* datos_accion), void* datos_accion);
void recorrer_lista(const t_lista * plista, void (*accion)(t_info* pinfo, void* datos_accion), void* datos_accion);
void vaciar_lista_res(t_lista * plista);

#endif // LISTA_H_INCLUDED
