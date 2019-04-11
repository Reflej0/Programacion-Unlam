#ifndef INDICE_STRING_H
#define INDICE_STRING_H


typedef struct
{
	char codigo[11];
	long nro_reg;
}
t_ind;


int ind_buscar(t_ind* vec_ind_rec, int ce_ind, t_ind* reg_ind);
int ind_buscar_res(t_ind* vec_ind_rec, int ce_ind, t_ind* reg_ind);


#endif // INDICE_STRING_H
