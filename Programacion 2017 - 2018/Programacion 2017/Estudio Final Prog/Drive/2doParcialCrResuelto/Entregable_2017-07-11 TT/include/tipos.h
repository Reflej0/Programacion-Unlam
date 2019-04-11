#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED


#define TODO_OK 1
#define SIN_MEM 2
#define ERROR_ARCHIVO 3
#define DUPLICADO 4
#define NO_EXISTE 5
#define VERDADERO 1
#define FALSO 0

#define PILA_LLENA 0
#define PILA_VACIA 0

typedef struct
{
	int dni;
	int nro_reg;
}
t_reg_ind;


typedef t_reg_ind t_info;


#endif // TIPOS_H_INCLUDED
