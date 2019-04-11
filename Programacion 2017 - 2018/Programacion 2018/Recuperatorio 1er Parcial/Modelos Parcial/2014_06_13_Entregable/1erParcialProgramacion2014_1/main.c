#include <stdio.h>
#include <stdlib.h>
#include <Cadena.h>
#include <Lista.h>
#include <Cola.h>
#include <Utilitarias.h>
#include <string.h>
#define TAM_LINEA 1000

int main()
{
	FILE* arch_mov, *arch_productos, *arch_prod_sin_stock;
	t_lista lista_mov;
	t_cola cola_prod_sin_stock; ///Cola implementada en vector estático.
	t_ind vec_indice_arch_prod[100];
	int ce_ind;


	generar_arch_movimientos();

	arch_mov = fopen("Movimientos.txt", "rt");

	if(!arch_mov)
	{
		puts("No se pudo abrir el archivo Movimientos.txt");
		exit(1);
	}


	generar_arch_productos(vec_indice_arch_prod, &ce_ind);

	arch_productos = fopen("Productos.bin", "r+b");

	if(!arch_productos)
	{
		puts("No se pudo abrir el archivo Productos.bin");
		exit(2);
	}


	generar_arch_prod_sin_stock("Productos_sin_stock.txt");

	arch_prod_sin_stock = fopen("Productos_sin_stock.txt", "r+t");

	if(!arch_prod_sin_stock)
	{
		puts("No se pudo abrir el archivo Productos_sin_stock.txt");
		exit(3);
	}


    mostrar_productos(arch_productos);

	///crear_lista(&lista_mov);
	crear_lista_res(&lista_mov);

	///crear_cola(&cola_prod_sin_stock);
	crear_cola_res(&cola_prod_sin_stock);

	///Debe generar la lista de movimientos, consolidando los movimientos de los productos, a fin de que quede 1 sólo elemento en la lista por cada producto.
	///Aumentando o disminuyendo la cantidad según se trate de un ingreso o egreso de mercadería respectivamente.
	///cargar_lista_movimientos(&lista_mov, arch_mov);
	cargar_lista_movimientos(&lista_mov, arch_mov);


	///Para test
	puts("Lista movimientos");
	recorrer_lista_res(&lista_mov, mostrar_movimiento, NULL);

	puts("");

	///Debe actualizar el archivo binario de productos, sumando o restando la cantidad.
	///La cantidad en el archivo no puede quedar negativa. Si eso sucede, se deberá cargar en la cola el elemento de la lista.
	///Para acceder a cada registro, debe hacer uso del vector vec_indice_arch_prod, que tiene cada elemento el código del producto y su ubicación en el archivo(Nro de registro empezando por el 0).
	///actualizar_archivo_productos(arch_productos, vec_indice_arch_prod, ce_ind, &lista_mov, &cola_prod_sin_stock);
	actualizar_archivo_productos(arch_productos, vec_indice_arch_prod, ce_ind, &lista_mov, &cola_prod_sin_stock);


	///Para test
	mostrar_cola(&cola_prod_sin_stock);

	puts("");

	///Debe normalizar los nombres de los productos en el archivo.
	///Dejando sólo 1 espacio entre palabras, sin espacios ni caracteres antes de la primer palábra y después de la última.
	///Quedando la primer letra de cada palabra en mayúscula y el resto en minúscula.
	///normalizar_nombres_productos(arch_productos);
	normalizar_nombres_productos(arch_productos);


	///Graba el archivo de texto de registros de longitud variable Productos_sin_stock.txt, a partir de la información de la cola.
	grabar_archivo_prod_sin_stock(&cola_prod_sin_stock, arch_prod_sin_stock);


	mostrar_productos(arch_productos);

	mostrar_prod_sin_stock(arch_prod_sin_stock);


	vaciar_cola_res(&cola_prod_sin_stock);

	fclose(arch_mov);
	fclose(arch_productos);
	fclose(arch_prod_sin_stock);


    return 0;
}



void cargar_lista_movimientos(t_lista* plista_mov, FILE* arch_mov)
{
    char linea[TAM_LINEA];
    char * pact;
    long length;
    t_mov mov;

    fgets(&linea, TAM_LINEA, arch_mov);

    while (!feof(arch_mov)) {

        if (!(pact = strrchr(&linea, '\n'))) {
            puts("No se encuentra fin de linea en el archivo de movimientos!");
            exit(1);
        }

        length = pact - linea;

        *pact = '\0';
        pact = strrchr(&linea, '|');
        sscanf(pact+1, "%d", &mov.cantidad);

        *pact = '\0';
        strcpy(&mov.codigo, linea);

        lista_actualizar_insertar(plista_mov, &mov, compara_mov_por_codigo, actualizar_mov_cantidad);

        fgets(&linea, TAM_LINEA, arch_mov);
    }
}

int compara_mov_por_codigo(t_mov * mov1, t_mov * mov2)
{
    char * cod1 = &(mov1->codigo);
    char * cod2 = &(mov2->codigo);

    while (*(cod1) && *(cod2) && *(cod1) == *(cod2)) {
        cod1++;
        cod2++;
    }

    return *(cod1) - *(cod2);
}

void actualizar_mov_cantidad(t_mov * mov, t_mov * dato)
{
    mov->cantidad += dato->cantidad;
}

void actualizar_archivo_productos(FILE* arch_productos, t_ind* vec_indice_arch_prod, int ce_ind, t_lista* plista_mov, t_cola* pcola_prod_sin_stock)
{
    t_mov mov;
    t_ind elem;
    t_prod prod;

    t_dato prod_sin_stock;

    while (lista_sacar_primero(plista_mov, &mov)) {
        strcpy(&(elem.codigo), &(mov.codigo));

        if (!vector_buscar_res(vec_indice_arch_prod, ce_ind, &elem))
            return ERROR_DATO_NO_EXISTE;

        rewind(arch_productos);
        fseek(arch_productos, 1L * elem.nro_reg * sizeof(t_prod), SEEK_SET);
        fread(&prod, sizeof(t_prod), 1, arch_productos);

        prod.cantidad += mov.cantidad;

        if (prod.cantidad >= 0) {
            fseek(arch_productos, -1L * sizeof(t_prod), SEEK_CUR);
            fwrite(&prod, sizeof(t_prod), 1, arch_productos);
            fseek(arch_productos, 0L, SEEK_CUR);
        } else {
            prod_sin_stock.cantidad = mov.cantidad;
            strcpy(prod_sin_stock.codigo, mov.codigo);
            poner_en_cola_res(pcola_prod_sin_stock, &prod_sin_stock);
        }
    }

}



void normalizar_nombres_productos(FILE* arch_productos)
{
    t_prod prod;

    rewind(arch_productos);

	fread(&prod, sizeof(t_prod), 1, arch_productos);

	while (!feof(arch_productos)) {
        normalizar(&prod.nombre, &prod.nombre);

        fseek(arch_productos, -1L * sizeof(t_prod), SEEK_CUR);
        fwrite(&prod, sizeof(t_prod), 1, arch_productos);
        fseek(arch_productos, 0L, SEEK_CUR);

        fread(&prod, sizeof(t_prod), 1, arch_productos);
	}

	rewind(arch_productos);
}



void grabar_archivo_prod_sin_stock(t_cola* pcola_prod_sin_stock, FILE* arch_prod_sin_stock)
{
    t_dato prod_sin_stock;
    char linea[TAM_LINEA];

	while (sacar_de_cola_res(pcola_prod_sin_stock, &prod_sin_stock)) {
        sprintf(&linea, "%s|%d\n", prod_sin_stock.codigo, prod_sin_stock.cantidad);
        fputs(&linea, arch_prod_sin_stock);
	}
}
