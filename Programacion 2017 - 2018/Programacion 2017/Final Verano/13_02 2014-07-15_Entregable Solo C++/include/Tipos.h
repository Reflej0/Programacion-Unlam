#ifndef TIPOS_H
#define TIPOS_H


typedef struct
{
	int dni;
	char apyn[51];
	int nota_1p;
	int nota_2p;
	char nota_tp; /// A o R
}
t_alumno;


typedef t_alumno t_dato;


typedef int (*t_cmp)(const void* pv1, const void* pv2);
typedef void (*t_accion)(void* pvd, void* datos_accion);
typedef void (*t_mostrar_clave)(const void* pvd);
typedef int (*t_condicion)(const void* pvc);


#endif // TIPOS_H
