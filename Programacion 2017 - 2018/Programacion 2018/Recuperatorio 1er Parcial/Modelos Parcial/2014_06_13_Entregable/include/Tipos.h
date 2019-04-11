#ifndef TIPOS_H
#define TIPOS_H


typedef struct
{
	char codigo[11];
	int cantidad;
}
t_mov;


typedef struct
{
	char codigo[11];
	char nombre[101];
	int cantidad;
}
t_prod;



typedef t_mov t_dato;


typedef struct
{
	char codigo[11];
	long nro_reg;
}
t_ind;


#endif // TIPOS_H
