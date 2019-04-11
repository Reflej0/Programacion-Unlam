#include <Cola.h>
#include <Archivo.h>
#include <string.h>



void asignar_entradas(FILE* arch_pedidos_entradas, FILE* arch_entradas, FILE* arch_socios_entradas)
{
    rewind(arch_pedidos_entradas);
	rewind(arch_entradas);
	rewind(arch_socios_entradas);
    t_cola socios_b; // Creo la cola para los socios del club B.
    crear_cola(&socios_b); // Creo la cola para los socios del club B.
	t_socio_entrada socio_entrada; // Variable auxiliar.
	t_pedido_entrada pedido_entrada; // Variable auxiliar.
	t_entrada entrada; // Variable auxiliar.
    fread(&pedido_entrada, sizeof(t_pedido_entrada), 1, arch_pedidos_entradas); // Leo el primer pedido.
    while(!feof(arch_pedidos_entradas)) // Leo el archivo de los pedidos de entradas.
    {
        if(pedido_entrada.club == 'A') // Tienen prioridad.
        {
            //Se supone que hay mas entradas que socios.
            //Sino en un momento el fread de &entrada pincha.
            fread(&entrada, sizeof(t_entrada), 1, arch_entradas); // Leo la primera entrada.
            socio_entrada.club = 'A';
            strcpy(socio_entrada.cod_socio, pedido_entrada.cod_socio);
            //socio_entrada.cod_socio = pedido_entrada.cod_socio;
            socio_entrada.nro_asiento = entrada.nro;
            fwrite(&socio_entrada, sizeof(t_socio_entrada), 1, arch_socios_entradas);
        }
        else // Si son del equipo B.
        {
            poner_en_cola(&socios_b, &pedido_entrada); // Si el pedido de entrada es del socio B se pone en la cola.
        }
        fread(&pedido_entrada, sizeof(t_pedido_entrada), 1, arch_pedidos_entradas);
    }
    //Una vez terminado el while ya asigne todas las entradas a los socios del club A.
    //Mientras que la cola no este vacia tengo que asignar entradas.
    while(cola_vacia(&socios_b) != 0)
    {
        //Tienen que sobrar suficientes entradas para los socios B.
        fread(&entrada, sizeof(t_entrada), 1, arch_entradas);
        sacar_de_cola(&socios_b, &pedido_entrada);
        socio_entrada.club = 'B';
        strcpy(socio_entrada.cod_socio, pedido_entrada.cod_socio);
        socio_entrada.nro_asiento = entrada.nro;
        fwrite(&socio_entrada, sizeof(t_socio_entrada), 1, arch_socios_entradas);
    }
}



void fusionar_archivos(FILE* arch_socios_a, FILE* arch_socios_b, FILE* arch_fusionado)
{
    int cant_socios_a = 0; // Esta variable guarda la cantidad total de socios del club a.
    int cant_socios_b = 0; // Esta variable guarda la cantidad total de socios del club b.
	rewind(arch_socios_a);
	rewind(arch_socios_b);
	rewind(arch_fusionado);
    t_socio_a socio_a;
    t_socio_b socio_b;
    t_socio_a fusion;
    char repetidos [10][41]; // Aca se pierde eficiencia.
    int i = 0; // Contador para los repetidos.
    fread(&socio_a, sizeof(t_socio_a), 1, arch_socios_a);
    while(!feof(arch_socios_a)) // Cuento la cantidad de socios del club a.
    {
        fread(&socio_a, sizeof(t_socio_a), 1, arch_socios_a);
        cant_socios_a++;
    }
    fread(&socio_b, sizeof(t_socio_b), 1, arch_socios_b);
    while(!feof(arch_socios_b)) // Cuento la cantidad de socios del club b.
    {
        fread(&socio_b, sizeof(t_socio_b), 1, arch_socios_b);
        cant_socios_b++;
    }
    rewind(arch_socios_a);
	rewind(arch_socios_b);
	int encontrado = 0; //Esto optimiza la performance de la busqueda.
    if(cant_socios_a <= cant_socios_b) // Esto es para determinar por cual pregunto FEOF.
    {
        fread(&socio_b, sizeof(t_socio_b), 1, arch_socios_b);
        fread(&socio_a, sizeof(t_socio_a), 1, arch_socios_a);
        while(!feof(arch_socios_b))
        {
            encontrado = 0;
            rewind(arch_socios_a);
            while(!feof(arch_socios_a) && encontrado == 0)
            {
                if(strcmp(socio_b.apyn, socio_a.apyn) == 0) // Proceso los que son socios de ambos clubs.
                {
                    strcpy(repetidos[i], socio_a.apyn); // Guardo los repetidos.
                    strcpy(fusion.apyn, socio_b.apyn); //
                    strcpy(fusion.cod_socio, socio_a.cod_socio);
                    strcat(fusion.cod_socio, "-AB");
                    if(socio_b.antiguedad>=socio_a.antiguedad)
                    {
                    fusion.antiguedad = socio_b.antiguedad;
                    }
                    else
                    {
                    fusion.antiguedad = socio_a.antiguedad;
                    }
                    fwrite(&fusion, sizeof(t_socio_a), 1, arch_fusionado);
                    encontrado++;
                }
                fread(&socio_a, sizeof(t_socio_a), 1, arch_socios_a);
            }
            if(encontrado == 0) // Proceso los que son socios solo del club B.
                {
                    strcpy(fusion.apyn, socio_b.apyn);
                    itoa(socio_b.nro_socio, fusion.cod_socio, 10);
                    strcat(fusion.cod_socio, "-B");
                    fusion.antiguedad = socio_b.antiguedad;
                    fwrite(&fusion, sizeof(t_socio_a), 1, arch_fusionado);
                }
            fread(&socio_b, sizeof(t_socio_b), 1, arch_socios_b);
            i++; // Variable auxiliar para los repetidos.
        }
        rewind(arch_socios_a);
        fread(&socio_a, sizeof(t_socio_a), 1, arch_socios_a);
        //En este momento se pierde toda la performance que podria haber tenido antes.
        while(!feof(arch_socios_a))
        {
            encontrado = 0;
            i = 0;
            while(i < 10)
            {
                if(strcmp(socio_a.apyn, repetidos[i])==0)
                {
                    encontrado++;
                }
                i++;
            }
            if(encontrado == 0)
            {
                strcpy(fusion.apyn, socio_a.apyn);
                strcpy(fusion.cod_socio, socio_a.cod_socio);
                strcat(fusion.cod_socio, "-A");
                fusion.antiguedad = socio_a.antiguedad;
                fwrite(&fusion, sizeof(t_socio_a), 1, arch_fusionado);
            }
            fread(&socio_a, sizeof(t_socio_a), 1, arch_socios_a);
        }
    }
}
