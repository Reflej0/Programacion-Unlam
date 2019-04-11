#include <stdio.h>
#include <stdlib.h>
#include <TiposDelivery.h>
#include <indice_string.h>
#include <1erParcialUtilitariasDelivery.h>
#include <string.h> // Para el STRCMP.



int main()
{
	t_ind vec_ind_rec[100];
	int ce_ind_rec;

	t_ind vec_ind_ingr[100];
	int ce_ind_ingr;

	generar_archivo_pedidos();
	generar_archivo_recetas(vec_ind_rec, &ce_ind_rec);
	generar_archivo_ingredientes(vec_ind_ingr, &ce_ind_ingr);

    FILE* arch_pedidos = fopen("Pedidos.txt", "rt");
    FILE* arch_recetas = fopen("Recetas.dat", "r+b");
    FILE* arch_ingredientes = fopen("Ingredientes.dat", "r+b");

	if(!arch_pedidos || !arch_recetas || !arch_ingredientes)
	{
		puts("Error en la apertura de los archivos");
		return 1;
	}

	mostrar_archivo_pedidos(arch_pedidos);
	mostrar_archivo_recetas(arch_recetas);

	puts("Ingredientes antes de la actualizacion");
	mostrar_archivo_ingredientes(arch_ingredientes);

	///satisfacer_pedidos(arch_pedidos, arch_recetas, arch_ingredientes, vec_ind_rec, ce_ind_rec, vec_ind_ingr, ce_ind_ingr);
	satisfacer_pedidos(arch_pedidos, arch_recetas, arch_ingredientes, vec_ind_rec, ce_ind_rec, vec_ind_ingr, ce_ind_ingr);

	puts("Ingredientes despues de la actualizacion");
	mostrar_archivo_ingredientes(arch_ingredientes);

	fclose(arch_pedidos);
	fclose(arch_recetas);
	fclose(arch_ingredientes);

	return 0;
}



///Procesa los pedidos del archivo Pedidos.txt, actualizando el archivo Ingredientes.dat, para que éste refleje la cantidad que queda en stock luego de despachar los pedidos.
void satisfacer_pedidos(FILE* arch_pedidos, FILE* arch_recetas, FILE* arch_ingredientes, t_ind* vec_ind_rec, int ce_ind_rec, t_ind* vec_ind_ingr, int ce_ind_ingr)
{
    t_cola cola;
    crear_cola(&cola);
	t_pedido ped;
	t_receta rec;
	t_ingrediente ing;
	//Llevo el lector de los archivos a la posicion de inicio.
    rewind(arch_pedidos);
    rewind(arch_recetas);
    rewind(arch_ingredientes);
    fscanf(arch_pedidos, "%d\t%s\t%d", &ped.nro_pedido, &ped.cod_receta, &ped.cantidad); // Leo el primer pedido.
    while(!feof(arch_pedidos)) // Mientras haya pedidos.
    {
        rewind(arch_recetas);
        fread(&rec, sizeof(t_receta), 1, arch_recetas); // Leo la primer receta.
        while(!feof(arch_recetas)) // Mientras haya recetas.
        {
            rewind(arch_ingredientes);
            if(strcmp(ped.cod_receta, rec.cod_receta) == 0) // Encuentro la receta asociada al pedido.
            {
                fread(&ing, sizeof(t_ingrediente), 1, arch_ingredientes); // Leo el primer ingrediente.
                while(!feof(arch_ingredientes)) // Mientras haya ingredientes.
                {
                    if(strcmp(rec.cod_ingr, ing.cod_ingr) == 0) // Encuentro el/los ingredientes asociados a la receta.
                    {
                        ing.stock -= (rec.cantidad*ped.cantidad); // El stock de los ingredientes se descuenta de la receta asociada al pedido.
                        fseek(arch_ingredientes, -1*sizeof(t_ingrediente), SEEK_CUR); // Vuelvo atras.
                        fwrite(&ing, sizeof(t_ingrediente), 1, arch_ingredientes); // Actualizo el archivo.
                        fseek(arch_ingredientes, sizeof(t_ingrediente), SEEK_CUR); // Esto es necesario.
                    }
                    fread(&ing, sizeof(t_ingrediente), 1, arch_ingredientes); // Leo el próximo ingrediente.
                }
            }
            fread(&rec, sizeof(t_receta), 1, arch_recetas); // Leo la próxima receta.
        }
        fscanf(arch_pedidos, "%d\t%s\t%d", &ped.nro_pedido, &ped.cod_receta, &ped.cantidad); // Leo el próximo pedido.
    }
}



///Genera una cola con los ingredientes de la receta.
int buscar_receta(FILE* arch_recetas, char* cod_receta, t_ind* vec_ind_rec, int ce_ind, t_cola* cola_rec_ingr)
{
	t_receta rec;
	while ( *cod_receta!= vec_ind_rec->codigo && ce_ind==0)
    {
        *vec_ind_rec++;
        ce_ind--;
    }
    fseek(arch_recetas,vec_ind_rec->nro_reg,SEEK_SET);
    fread(&rec,sizeof(t_receta),1,arch_recetas);
    while (!feof(arch_recetas) && vec_ind_rec->codigo!=*cod_receta)
    {
       poner_en_cola(&cola_rec_ingr,&rec);
       fread(&rec,sizeof(t_receta),1,arch_recetas);
    }



}



///Descuenta la cantidad indicada del ingrediente indicado, actualizando el archivo Ingredientes.dat.
void descontar_stock_arch_ingr(FILE* arch_ingredientes, char* cod_ingr, int cant_a_descontar, t_ind* vec_ind_ingr, int ce_ind_ingr)
{
	t_ingrediente ing;
	while(*cod_ingr!=vec_ind_ingr->codigo && ce_ind_ingr==0)
    {
        *vec_ind_ingr++;
        ce_ind_ingr--;
    }
    fseek(arch_ingredientes,sizeof(t_ingrediente),SEEK_SET);
    fread(&ing, sizeof(t_ingrediente),1,arch_ingredientes);
    ing.stock-=cant_a_descontar;
    fseek(arch_ingredientes,-1*sizeof(t_ingrediente),SEEK_CUR);
    fwrite(&ing, sizeof(t_ingrediente),1,arch_ingredientes);
}
