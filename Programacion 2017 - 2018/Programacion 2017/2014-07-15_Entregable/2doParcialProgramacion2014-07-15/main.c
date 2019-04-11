#include <stdio.h>
#include <stdlib.h>
#include <Lista.h>
#include <Arbol.h>
#include <Utilitarias.h>



int main()
{
	t_arbol arbol_alu;
	t_lista lista; ///Lista Doblemente Enlazada Ordenada Asc.

	crear_arbol_res(&arbol_alu);
	crear_lista_res(&lista);

    cargar_arbol(&arbol_alu);

	///Para test
	puts("Arbol antes del proceso");
	arbol_grafico(&arbol_alu, mostrar_clave);


    ///Tiene que insertar en la lista los alumnos en al árbol que están en condición de aprobados.
    ///La condición de aprobado se da cuando las notas del primer y segundo parcial son de 4 o más y el TP está aprobado(A).
    ///Esta función es una primitiva de arbol, no conoce a la struct t_alumno.
    ///recorrer_arbol_pre(&arbol_alu, acc_insertar_l, &lista);
	recorrer_arbol_pre_res(&arbol_alu, acc_insertar_l_res, &lista);

	///Para test
	puts("\n");
	puts("Lista con los alumnos aprobados");
	///recorrer_lista(&lista, acc_mostrar_clave_para_lista, NULL);
	recorrer_lista_res(&lista, acc_mostrar_clave_para_lista, NULL);


    ///Esta primitiva NO la tiene que desarrollar:
    //eliminar_de_lista_elementos_bajo_condicion_res(&lista, cond_alu_no_promoc_res);


	///Para test
	puts("\n");
	puts("Lista con los alumnos Promocionados");
	recorrer_lista_res(&lista, acc_mostrar_clave_para_lista, NULL);


    ///tiene que eliminar del árbol los alumnos que están en la lista.
    ///Esta función es una primitiva de lista, no conoce a la struct t_alumno ni el árbol.
    ///recorrer_lista(&lista, acc_eliminar_de_arbol, &arbol_alu);
	recorrer_lista_res(&lista, acc_eliminar_de_arbol_res, &arbol_alu);

	///Para test
	puts("\n");
	puts("Arbol despues del proceso");
	arbol_grafico(&arbol_alu, mostrar_clave);


	vaciar_arbol_res(&arbol_alu);
	vaciar_lista_res(&lista);


    return 0;
}
