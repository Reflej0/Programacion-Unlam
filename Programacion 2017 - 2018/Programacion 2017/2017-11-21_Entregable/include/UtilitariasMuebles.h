#ifndef UTILITARIASMUEBLES_H
#define UTILITARIASMUEBLES_H


typedef struct
{
	int nro_dep;
	char cod_prod[16];
	int stock;
}
t_deposito;


typedef struct
{
	int dep_origen;
	int dep_destino;
	char cod_prod[16];
	int cantidad;
}
t_transferencia;


typedef struct
{
	int nro_dep;
	char cod_prod[16];
	long nro_reg;
}
t_reg_ind;



void generarArchivos();
void mostrar_archivo_transferencias(const char* archTransferencias);
void mostrar_archivo_depositos(const char* archDepositos);


#endif // UTILITARIASMUEBLES_H
