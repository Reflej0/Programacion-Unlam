#ifndef LISTA_H
#define LISTA_H

#include <Tipos.h>


typedef struct s_nodod
{
	t_dato info;
	struct s_nodod* pant;
	struct s_nodod* psig;
}
t_nodod;


typedef t_nodod* t_lista;


void crear_lista(t_lista* pl);
int insertar_en_lista_ord(t_lista* pl, const t_dato* pd, t_cmp cmp);
void recorrer_lista(const t_lista* pl, t_accion accion, void* datos_accion);
void eliminar_de_lista_elementos_bajo_condicion(t_lista* pl, t_condicion condicion);
void vaciar_lista(t_lista* pl);

void crear_lista_res(t_lista* pl);
int insertar_en_lista_ord_res(t_lista* pl, const t_dato* pd, t_cmp cmp);
void recorrer_lista_res(const t_lista* pl, t_accion accion, void* datos_accion);
void eliminar_de_lista_elementos_bajo_condicion_res(t_lista* pl, t_condicion condicion);
void vaciar_lista_res(t_lista* pl);


#endif // LISTA_H
