#include <stdio.h>
#include <stdlib.h>
#include <Tipos.h>
#include <Utilitarias.h>
#include <Archivo.h>


int main()
{
	FILE* arch_socios_a, * arch_socios_b, * arch_fusionado, * arch_socios_entradas, * arch_pedidos_entradas, * arch_entradas;

    generar_archivo_socios_club_a();
    generar_archivo_socios_club_b();
    generar_archivo_pedidos_entradas();
    generar_archivo_entradas();

    arch_pedidos_entradas = fopen("../Archivos/pedidos_entradas.dat", "rb");
    arch_entradas = fopen("../Archivos/entradas.dat", "rb");
    arch_socios_entradas = fopen("../Archivos/socios_entradas.dat", "w+b");
    if(!arch_pedidos_entradas || !arch_entradas || !arch_socios_entradas)
	{
		puts("No se pudieron abrir los archivos.");
		exit(1);
	}

	mostrar_arch_pedidos_entradas(arch_pedidos_entradas);
	mostrar_arch_entradas(arch_entradas);

/**
	Esta función debe asignar las entradas disponibles a los socios, dándole prioridad a los socios locales(Club A).
	Por lo que al leerse del archivo pedidos_entrada.dat, un pedido de un socio del club B, el mismo debe colocarse en
	una cola.
	Una vez procesado el archivo de pedidos, Las entradas restantes se asignarán a los socios que quedaron en la cola.
	Las entradas se encuentran en el archivo entradas.dat, que simplemente contiene los números de asiento de las entradas
	disponibles.
	La estructura del archivo pedidos_entradas.dat, consiste en el código de socio, y el club al que pertenece.
	El modo de asignación consiste en grabar en el archivo socios_entradas.dat, el código del socio, su club y el nro de
	asiento	asignado.
*/
	///Para que ejecute su código, debe descomentar asignar_entradas y comentar asignar_entradas_res.

	asignar_entradas(arch_pedidos_entradas, arch_entradas, arch_socios_entradas);

	//asignar_entradas_res(arch_pedidos_entradas, arch_entradas, arch_socios_entradas);
    mostrar_arch_socios_entradas(arch_socios_entradas);

    //return 0;

    fclose(arch_entradas);
    fclose(arch_pedidos_entradas);
    fclose(arch_socios_entradas);


    arch_socios_a = fopen("../Archivos/socios_club_a.dat", "rb");
    arch_socios_b = fopen("../Archivos/socios_club_b.dat", "rb");
    arch_fusionado = fopen("../Archivos/socios_fus.dat", "w+b");

    if(!arch_socios_a || !arch_socios_b || !arch_fusionado)
	{
		puts("No se pudieron abrir los archivos.");
		exit(1);
	}

    mostrar_arch_socios_a(arch_socios_a);
    mostrar_arch_socios_b(arch_socios_b);


/**
	Esta función debe fusionar los archivos de los socios del club A y los del club B en un nuevo archivo.
	La estructura del archivo fusionado es la del archivo de socios del club A.
	El código de socio en el archivo fusionado debe incluir el club de donde proviene. Existen socios que se encuentran en
	los 2 clubes. Ej: socio 1 del club A, el código resultante es 1-A. El código del socio 2, que está en los 2 clubes
	queda 2-AB.
	La antigüedad se toma la mayor.
*/
    ///Para que ejecute su código, debe descomentar fusionar_archivos y comentar fusionar_archivos_res.
    fusionar_archivos(arch_socios_a, arch_socios_b, arch_fusionado);
    //fusionar_archivos_res(arch_socios_a, arch_socios_b, arch_fusionado);

    puts("Archivo Fusionado");
    mostrar_arch_socios_a(arch_fusionado);


    fclose(arch_socios_a);
    fclose(arch_socios_b);
    fclose(arch_fusionado);

    return 0;
}
