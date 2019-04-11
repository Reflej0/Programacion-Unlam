#include <stdio.h>
#include <stdlib.h>
#include <ListaD.h>
#include <Arbol.h>
#include <UtilitariasMuebles.h>
#include <Solucion2doPMuebles.h>
#include "string.h"



int main()
{
	generarArchivos();

	puts("Archivo Transferencias:");
	puts("Dep Orig | Dep Dest | Cod Prod | Cant");
	mostrar_archivo_transferencias("Transferencias.txt");

	puts("");
	puts("Depositos antes de actualizar:");
	puts("Dep | Producto | Stock");
	mostrar_archivo_depositos("Depositos.dat");

	actualizarDepositos("Transferencias.txt", "Depositos.dat", "Depositos.idx");
	///actualizarDepositos_res("Transferencias.txt", "Depositos.dat", "Depositos.idx");

	puts("");
	puts("Depositos despues de actualizar:");
	puts("Dep | Producto | Stock");
	mostrar_archivo_depositos("Depositos.dat");

	return 0;
}

///FUNCION DE COMPARACION DEL INDICE.

int cmp_indc(const void* reg1, const void* reg2)
{
    t_reg_ind* r1 = (t_reg_ind*)reg1;
    t_reg_ind* r2 = (t_reg_ind*)reg2;
    int comp1 = (r1->nro_dep)*100 + strlen(r1->cod_prod);
    int comp2 = (r2->nro_dep)*100 + strlen(r2->cod_prod);
    return comp1 - comp2;

}

int cmp_trans(const void* reg1, const void* reg2)
{
    t_transferencia* t1 = (t_transferencia*)reg1;
    t_transferencia* t2 = (t_transferencia*)reg2;
    int comp1 = (t1->dep_origen)*100 + (t1->dep_destino);
    int comp2 = (t2->dep_origen)*100 + (t2->dep_destino);
    return comp1 - comp2;
}


///ACTUALIZO DEPOSITOS, MIRANDO TRANSFERENCIAS.
void actualizarDepositos(const char* archTransferencias, const char* archDepositos, const char* archIndiceDep)
{
    ///CREACION DEL ARBOL.
	t_arbol indice;
	crear_arbol_res(&indice);

	///CARGA INDICE EN EL ARBOL.
	cargar_arbol_de_archivo_ordenado_2_res(&indice, archIndiceDep);

    ///CREACION DE LA LISTA.
	t_lista transferencias;
	crear_lista_res(&transferencias);


	///APERTURA DEL ARCHIVO DE TRANSFERENCIAS.
	FILE* arch_tranferencias = fopen(archTransferencias, "rt");
	t_transferencia transferencia;
	fscanf(arch_tranferencias, "%d|%d|%[^|]|%d", &transferencia.dep_origen, &transferencia.dep_destino, transferencia.cod_prod, &transferencia.cantidad);
	while(!feof(arch_tranferencias))
    {
        ///CARGA DE TRANSFERENCIAS EN LA LISTA.
        insertar_en_lista_ord_res(&transferencias, &transferencia, cmp_trans);
        fscanf(arch_tranferencias, "%d|%d|%[^|]|%d", &transferencia.dep_origen, &transferencia.dep_destino, transferencia.cod_prod, &transferencia.cantidad);
    }
    ///CIERRE DEL ARCHIVO DE TRANSFERENCIAS.
    fclose(arch_tranferencias);


    ///APERTURA DEL ARCHIVO DE DEPOSITOS.

    FILE* arch_depo = fopen(archDepositos, "rb+");

    ///MIENTRAS QUE LA LISTA NO ESTE VACIA.
    while(!lista_vacia_res(&transferencias))
    {
        ///VOY SACANDO DE LA LISTA.
        t_transferencia transferencia_extraida;
        lista_sacar_primero_res(&transferencias, &transferencia_extraida);
        printf("%d-%d-%s", transferencia_extraida.dep_origen, transferencia_extraida.dep_destino, transferencia_extraida.cod_prod);
        printf("-%d\n", transferencia_extraida.cantidad); /// <------ ERROR
        system("PAUSE");
        ///VARIABLES AUXILIARES PARA BUSCAR EN EL ARBOL.
        t_dato_arbol origen;
        t_dato_arbol destino;
        origen.nro_dep = transferencia_extraida.dep_origen;
        strcpy(origen.cod_prod, transferencia_extraida.cod_prod);
        destino.nro_dep = transferencia_extraida.dep_destino;
        strcpy(destino.cod_prod, transferencia_extraida.cod_prod);
            ///BUSCO EN EL ARBOL EL NUMERO DE REGISTRO QUE CORRESPONDE PARA EL DEPOSITO DE ORIGEN.
            if(buscar_en_arbol_bin_busq_res(&indice, &origen, cmp_indc) == 1)
            {
                ///BUSCO EN EL ARBOL EL NUMERO DE REGISTRO QUE CORRESPONDE PARA EL DEPOSITO DE DESTINO.
                if(buscar_en_arbol_bin_busq_res(&indice, &destino, cmp_indc) == 1)
                {
                    t_deposito auxiliar;
                    ///ME DIRIJO A LA CUENTA DE ORIGEN EN EL ARCHIVO DE DEPOSITO.
                    fseek(arch_depo, (origen.nro_reg*sizeof(t_deposito)), SEEK_SET);
                    ///LEO EL REGISTRO DEL DEPOSITO.
                    fread(&auxiliar, sizeof(t_deposito), 1, arch_depo);
                    ///RESTO EL STOCK DESDE EL ORIGEN.
                    auxiliar.stock -= transferencia_extraida.cantidad;
                    ///VUELVO PARA ATRAS (PARA ACTUALIZAR EL ARCHIVO).
                    fseek(arch_depo, -1L*sizeof(t_deposito), SEEK_CUR);
                    ///ACTUALIZO EL ARCHIVO.
                    fwrite(&auxiliar, sizeof(t_deposito), 1, arch_depo);
                    ///COMO LEO Y ESCRIBO.
                    fseek(arch_depo, 0L, SEEK_CUR);
                    ///ME DIRIJO A LA CUENTA DE DESTINO EN EL ARCHIVO DE DEPOSITO.
                    fseek(arch_depo, (destino.nro_reg*sizeof(t_deposito)), SEEK_SET);
                    ///LEO EL REGISTRO DEL DEPOSITO.
                    fread(&auxiliar, sizeof(t_deposito), 1, arch_depo);
                    ///SUMO EL STOCK AL DESTINO.
                    auxiliar.stock += transferencia.cantidad;
                    fseek(arch_depo, -1L*sizeof(t_deposito), SEEK_CUR);
                    ///ACTUALIZO EL ARCHIVO.
                    fwrite(&auxiliar, sizeof(t_deposito), 1, arch_depo);
                    ///COMO LEO Y ESCRIBO.
                    fseek(arch_depo, 0L, SEEK_CUR);
                }
            }
    }
    fclose(arch_depo);

}
