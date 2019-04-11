#ifndef LISTA_H
#define LISTA_H

#include <TipoTDA.h>
#include <PunterosAFuncion.h>


typedef struct s_nodod
{
	t_dato_lista info;
	struct s_nodod* pant;
	struct s_nodod* psig;
}
t_nodod;


typedef t_nodod* t_lista;


void crear_lista(t_lista* pl);
int insertar_en_lista_ord(t_lista* pl, const t_dato_lista* pd, t_cmp cmp);
int insertar_en_lista_ord_dup(t_lista* pl, const t_dato_lista* pd, t_cmp cmp);
int lista_actualizar_insertar(t_lista* pl, const t_dato_lista* pd, t_cmp cmp, t_actualizar actualizar);
int lista_vacia(const t_lista* pl);
void lista_consolidar(t_lista* pl, t_cmp cmp, t_actualizar actualizar);
void recorrer_lista(const t_lista* pl, t_accion accion, void* datos_accion);
int lista_sacar_primero(t_lista* pl, t_dato_lista* pd);
void eliminar_de_lista_elementos_bajo_condicion(t_lista* pl, t_condicion condicion);
void vaciar_lista(t_lista* pl);

void crear_lista_res(t_lista* pl);
int insertar_en_lista_ord_res(t_lista* pl, const t_dato_lista* pd, t_cmp cmp);
int insertar_en_lista_ord_dup_res(t_lista* pl, const t_dato_lista* pd, t_cmp cmp);
int lista_actualizar_insertar_res(t_lista* pl, const t_dato_lista* pd, t_cmp cmp, t_actualizar actualizar);
int lista_vacia_res(const t_lista* pl);
void lista_consolidar_res(t_lista* pl, t_cmp cmp, t_actualizar actualizar);
void recorrer_lista_res(const t_lista* pl, t_accion accion, void* datos_accion);
int lista_sacar_primero_res(t_lista* pl, t_dato_lista* pd);
void eliminar_de_lista_elementos_bajo_condicion_res(t_lista* pl, t_condicion condicion);
void vaciar_lista_res(t_lista* pl);


#endif // LISTA_H
