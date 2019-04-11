#ifndef UTILITARIAS_H
#define UTILITARIAS_H

#include <Arbol.h>


void cargar_arbol(t_arbol* pa);
int cmp_alu(const void* pva1, const void* pva2);
void acc_eliminar_de_arbol(void* pvd, void* pva);
void acc_insertar_l(void* pvd, void* pvl);
int cond_alu_no_promoc(const void* pvd);
void mostrar_clave(const void* pvd);
void acc_mostrar_clave_para_lista(void* pvd, void* datos_accion);

int cmp_alu_res(const void* pva1, const void* pva2);
void acc_eliminar_de_arbol_res(void* pvd, void* pva);
void acc_insertar_l_res(void* pvd, void* pvl);
int cond_alu_no_promoc_res(const void* pvd);


#endif // UTILITARIAS_H
