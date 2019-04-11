#include <stdio.h>
#include <stdlib.h>
#include <ListaD.h>
#include <Arbol.h>
#include <string.h>
#include <UtilitariasMuebles.h>
#include <Solucion2doPMuebles.h>
///EMPIEZO 19:11

int cmp_indc(const void* reg1, const void* reg2)
{
    t_reg_ind* r1 = (t_reg_ind*)reg1;
    t_reg_ind* r2 = (t_reg_ind*)reg2;
    t_reg_ind _r1 = *r1;
    t_reg_ind _r2 = *r2;
    int comp1 = (_r1.nro_dep)*100 + strlen(_r1.cod_prod);
    int comp2 = (_r2.nro_dep)*100 + strlen(_r2.cod_prod);
    return comp1 - comp2;

}

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
	//actualizarDepositos_res("Transferencias.txt", "Depositos.dat", "Depositos.idx");

	puts("");
	puts("Depositos despues de actualizar:");
	puts("Dep | Producto | Stock");
	mostrar_archivo_depositos("Depositos.dat");

	return 0;
}



void actualizarDepositos(const char* archTransferencias, const char* archDepositos, const char* archIndiceDep)
{
    ///ABRO LOS ARCHIVOS.
	FILE* _archTransferencias = fopen(archTransferencias, "rt");
    FILE* _archDepositos = fopen(archDepositos, "rb+");
    FILE* _archIndiceDep = fopen(archIndiceDep, "rb");
    ///CARGO EL INDICE EN EL ARBOL.
    t_arbol i;
    crear_arbol(&i);
    cargar_arbol_de_archivo_ordenado_mio(&i, _archIndiceDep);
    //DEBUG
    //mostrar_arbol_pre(&i);
    //system("PAUSE");
    ///CIERRO EL ARCHIVO DE INDICE DESPUES DE LA CARGA>
    fclose(_archIndiceDep);
    ///CARGO EL ARCHIVO DE TRANSACCIONES EN UNA LISTA DOBLE.
    t_lista l;
    crear_lista(&l);
    t_transferencia t;
    while(fscanf(_archTransferencias, "%d|%d|%[^|]|%d", &t.dep_origen, &t.dep_destino, t.cod_prod, &t.cantidad)!=EOF)
    {
        insertar_en_lista_principio(&l, &t);
    }
    fclose(_archTransferencias);
    ///TENGO EL INDICE EN EL ARBOL Y LAS TRANSACCIONES EN LA LISTA.
    ///TENGO QUE ACTUALIZAR LOS DEPOSITOS.
    t_transferencia tt;
    ///VOY SACANDO DE LA LISTA MIENTRAS HAYA.
    while(sacar_principio_lista(&l, &tt) != 0)
    {
        t_dato_arbol origen;
        origen.nro_dep = tt.dep_origen;
        strcpy(origen.cod_prod, tt.cod_prod);
        t_dato_arbol dest;
        dest.nro_dep = tt.dep_destino;
        strcpy(dest.cod_prod, tt.cod_prod);
        ///TENGO EL NUMERO DE REGISTRO QUE OCUPAN EN EL ARCHIVO DE DEPOSITOS.
        if(buscar_en_arbol_bin_busq(&i, &origen, cmp_indc)== 1)
        {
            if(buscar_en_arbol_bin_busq(&i, &dest, cmp_indc)== 1)
            {
                ///ME PARO EN EL ORIGEN.
                t_deposito ori;
                fseek(_archDepositos, origen.nro_reg*sizeof(t_deposito), SEEK_SET);
                fread(&ori, sizeof(t_deposito), 1, _archDepositos);
                ori.stock-=tt.cantidad;
                fseek(_archDepositos, -1L*sizeof(t_deposito), SEEK_CUR);
                fwrite(&ori, sizeof(t_deposito), 1, _archDepositos);
                fseek(_archDepositos, 0L, SEEK_CUR);
                ///LISTO, DEL ORIGEN DESCONTE.
                t_deposito des;
                fseek(_archDepositos, dest.nro_reg*sizeof(t_deposito), SEEK_SET);
                fread(&des, sizeof(t_deposito), 1, _archDepositos);
                des.stock+=tt.cantidad;
                fseek(_archDepositos, -1L*sizeof(t_deposito), SEEK_CUR);
                fwrite(&des, sizeof(t_deposito), 1, _archDepositos);
                fseek(_archDepositos, 0L, SEEK_CUR);
            }
        }


    }
    fclose(_archDepositos);
}
