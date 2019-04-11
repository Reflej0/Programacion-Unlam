#ifndef ARBOL_H
#define ARBOL_H

#include <TipoTDA.h>
#include <PunterosAFuncion.h>
#include <ListaD.h>


typedef struct s_nodo_arb
{
	t_dato_arbol info;
	struct s_nodo_arb* pizq;
	struct s_nodo_arb* pder;
}
t_nodo_arbol;



typedef t_nodo_arbol* t_arbol;


typedef void (*t_mostrarClave) (const void*);


void crear_arbol(t_arbol* pa);
void crear_arbol_res(t_arbol* pa);
int insertar_en_arbol_bin_busq(t_arbol* pa, const t_dato_arbol* pd, t_cmp cmp);
int insertar_en_arbol_bin_busq_res(t_arbol* pa, const t_dato_arbol* pd, t_cmp cmp);
int buscar_en_arbol_bin_busq(const t_arbol* pa, t_dato_arbol* pd, t_cmp cmp);
int buscar_en_arbol_bin_busq_res(const t_arbol* pa, t_dato_arbol* pd, t_cmp cmp);
int altura_arbol(const t_arbol* pa);
int altura_arbol_res(const t_arbol* pa);
int cargar_arbol_de_archivo_ordenado(t_arbol* pa, const char* path);
int cargar_arbol_de_archivo_ordenado_res(t_arbol* pa, const char* path, t_cmp cmp);
int cargar_arbol_de_archivo_ordenado_2_res(t_arbol* pa, const char* path);
int eliminar_de_arbol(t_arbol* pa, t_dato_arbol* pd, t_cmp cmp);
int eliminar_de_arbol_res(t_arbol* pa, t_dato_arbol* pd, t_cmp cmp);
void eliminar_raiz_res(t_arbol* pa);
int es_arbol_balanceado_res(const t_arbol* pa);
void arbolGrafico(t_arbol*, t_mostrarClave);
void mostrarGrafico(t_arbol *pa, int despl, t_mostrarClave);
void mostrarClave(const void* pv);
void eliminar_nodos_de_nivel_res(t_arbol* pa, int nivel, t_lista* pl, t_cmp cmp);
int vaciar_arbol(t_arbol* pa);
void vaciar_arbol_res(t_arbol* pa);
int cant_nodos_arbol(const t_arbol* pa);
int cant_nodos_arbol_res(const t_arbol* pa);
int grabar_arbol_en_archivo_ordenado_res(t_arbol* pa, const char* path);


#endif // ARBOL_H_INCLUDED
