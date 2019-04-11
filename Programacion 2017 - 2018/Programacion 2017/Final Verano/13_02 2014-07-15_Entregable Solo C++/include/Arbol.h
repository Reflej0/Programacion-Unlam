#ifndef ARBOL_H
#define ARBOL_H


#include <Tipos.h>


typedef struct s_nodo_arb
{
	t_dato info;
	struct s_nodo_arb* pizq;
	struct s_nodo_arb* pder;
}
t_nodo_arb;


typedef t_nodo_arb* t_arbol;



void crear_arbol(t_arbol* pa);
int insertar_en_arbol(t_arbol* pa, t_dato* pd, t_cmp cmp);
int buscar_en_arbol(const t_arbol* pa, t_dato* pd, t_cmp cmp);
int altura_arbol(const t_arbol* pa);
int eliminar_de_arbol(t_arbol* pa, t_dato* pd, t_cmp cmp);
void recorrer_arbol_pre(const t_arbol* pa, t_accion accion, void* datos_accion);
void recorrer_arbol_en(const t_arbol* pa, t_accion accion, void* datos_accion);
void recorrer_arbol_pos(const t_arbol* pa, t_accion accion, void* datos_accion);
void podar_arbol(t_arbol* pa, int nivel);
int contar_hojas(const t_arbol* pa);
int contar_no_hojas(const t_arbol* pa);
int es_arbol_avl(const t_arbol* pa);
int es_arbol_balanceado(const t_arbol* pa);
void vaciar_arbol(t_arbol* pa);
void arbol_grafico(t_arbol *pa, t_mostrar_clave mostrar_cl);

void crear_arbol_res(t_arbol* pa);
int insertar_en_arbol_res(t_arbol* pa, t_dato* pd, t_cmp cmp);
int buscar_en_arbol_res(const t_arbol* pa, t_dato* pd, t_cmp cmp);
int altura_arbol_res(const t_arbol* pa);
int eliminar_de_arbol_res(t_arbol* pa, t_dato* pd, t_cmp cmp);
void recorrer_arbol_pre_res(const t_arbol* pa, t_accion accion, void* datos_accion);
void recorrer_arbol_en_res(const t_arbol* pa, t_accion accion, void* datos_accion);
void recorrer_arbol_pos_res(const t_arbol* pa, t_accion accion, void* datos_accion);
void podar_arbol_res(t_arbol* pa, int nivel);
int contar_hojas_res(const t_arbol* pa);
int contar_no_hojas_res(const t_arbol* pa);
int es_arbol_avl_res(const t_arbol* pa);
int es_arbol_balanceado_res(const t_arbol* pa);
void vaciar_arbol_res(t_arbol* pa);
void arbol_grafico(t_arbol *pa, t_mostrar_clave mostrar_cl);


#endif // ARBOL_H
