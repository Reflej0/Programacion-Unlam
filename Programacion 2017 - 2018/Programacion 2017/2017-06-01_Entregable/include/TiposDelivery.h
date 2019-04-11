#ifndef TIPOS_H
#define TIPOS_H


typedef struct
{
    int nro_pedido;
    char cod_receta[11];
    int cantidad;
}
t_pedido;


typedef struct
{
	char cod_receta[11];
	char cod_ingr[11];
	int cantidad;
}
t_receta;


typedef struct
{
	char cod_ingr[11];
	int stock;
}
t_ingrediente;


#endif // TIPOS_H
