#ifndef ERPARCIALUTILITARIASDELIVERY_H
#define ERPARCIALUTILITARIASDELIVERY_H

#include <stdio.h>
#include <indice_string.h>
#include <cola.h>

void generar_archivo_pedidos();
void generar_archivo_recetas(t_ind* vec_ind_rec, int* ce_ind_rec);
void generar_archivo_ingredientes(t_ind* vec_ind_ingr, int* ce_ind_ingr);
void mostrar_archivo_pedidos(FILE* arch_pedidos);
void mostrar_archivo_recetas(FILE* arch_recetas);
void mostrar_archivo_ingredientes(FILE* arch_ingredientes);
void mostrar_receta(t_receta* receta);
void mostrar_ingrediente(t_ingrediente* ingrediente);

///Procesa los pedidos del archivo Pedidos.txt, actualizando el archivo Ingredientes.dat, para que éste refleje la cantidad que queda en stock luego de despachar los pedidos.
void satisfacer_pedidos(FILE* arch_pedidos, FILE* arch_recetas, FILE* arch_ingredientes, t_ind* vec_ind_rec, int ce_ind_rec, t_ind* vec_ind_ingr, int ce_ind_ingr);
void satisfacer_pedidos_res(FILE* arch_pedidos, FILE* arch_recetas, FILE* arch_ingredientes, t_ind* vec_ind_rec, int ce_ind_rec, t_ind* vec_ind_ingr, int ce_ind_ingr);

///Genera una cola con los ingredientes de la receta.
int buscar_receta(FILE* arch_recetas, char* cod_receta, t_ind* vec_ind_rec, int ce_ind, t_cola* cola_rec_ingr);
int buscar_receta_res(FILE* arch_recetas, char* cod_receta, t_ind* vec_ind_rec, int ce_ind, t_cola* cola_rec_ingr);

///Descuenta la cantidad indicada del ingrediente indicado, actualizando el archivo Ingredientes.dat.
void descontar_stock_arch_ingr(FILE* arch_ingredientes, char* cod_ingr, int cant_a_descontar, t_ind* vec_ind_ingr, int ce_ind_ingr);
void descontar_stock_arch_ingr_res(FILE* arch_ingredientes, char* cod_ingr, int cant_a_descontar, t_ind* vec_ind_ingr, int ce_ind_ingr);


#endif // 1ERPARCIALUTILITARIASDELIVERY_H
