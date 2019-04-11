#ifndef UTILITARIAS_H
#define UTILITARIAS_H

#include <Lista.h>
#include <Cola.h>



void generar_arch_productos(t_ind* vec_indice_arch_prod, int* ce_ind);
void generar_arch_movimientos();
void generar_arch_prod_sin_stock();
void mostrar_productos(FILE* arch_productos);
void mostrar_prod_sin_stock(FILE* arch_prod_sin_stock);
void cargar_lista_movimientos(t_lista* plista_mov, FILE* arch_mov);
void actualizar_archivo_productos(FILE* arch_productos, t_ind* vec_indice_arch_prod, int ce_ind, t_lista* plista_mov, t_cola* pcola_prod_sin_stock);
void normalizar_nombres_productos(FILE* arch_productos);
void grabar_archivo_prod_sin_stock(t_cola* pcola_prod_sin_stock, FILE* arch_prod_sin_stock);
void cargar_lista_movimientos_res(t_lista* plista_mov, FILE* arch_mov);
void actualizar_archivo_productos_res(FILE* arch_productos, t_ind* vec_indice_arch_prod, int ce_ind, t_lista* plista_mov, t_cola* pcola_prod_sin_stock);
void normalizar_nombres_productos_res(FILE* arch_productos);
void grabar_archivo_prod_sin_stock_res(t_cola* pcola_prod_sin_stock, FILE* arch_prod_sin_stock);
void mostrar_movimiento(void* pvmov, void*);
void mostrar_cola(const t_cola* pcola);
int vector_buscar_res(t_ind* vec_indice_arch_prod, int ce_ind, t_ind* elem);

int compara_mov_por_codigo(t_mov * mov1, t_mov * mov2);
void actualizar_mov_cantidad(t_mov * mov, t_dato * dato);

//typedef int(* t_cmp)(void *, void *);

#endif // UTILITARIAS_H
