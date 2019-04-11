#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <stdio.h>

 // Lo cree yo porque no estaba.
typedef struct
{
    int nro;
} t_entrada;

typedef struct
{
	char cod_socio[11];
	char club;
}
t_pedido_entrada;


typedef struct
{
	char cod_socio[11];
	char club;
	int nro_asiento;
}
t_socio_entrada;


typedef struct
{
	char cod_socio[11];
	char apyn[51];
	int antiguedad;
}
t_socio_a;


typedef struct
{
	int nro_socio;
	char apyn[51];
	int antiguedad;
}
t_socio_b;



void asignar_entradas(FILE* arch_pedidos_entradas, FILE* arch_entradas, FILE* arch_socios_entradas);
void asignar_entradas_res(FILE* arch_pedidos_entradas, FILE* arch_entradas, FILE* arch_socios_entradas);
void fusionar_archivos(FILE* arch_socios_a, FILE* arch_socios_b, FILE* arch_fusionado);
void fusionar_archivos_res(FILE* arch_socios_a, FILE* arch_socios_b, FILE* arch_fusionado);


#endif // ARCHIVO
