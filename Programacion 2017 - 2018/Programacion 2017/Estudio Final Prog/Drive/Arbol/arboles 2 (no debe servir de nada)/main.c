#include <stdio.h>
#include <stdlib.h>
#include "parametros.h"
int main()
{
    t_arbol raiz;
    t_info info[]={{3},
                   {4},
                   {2},
                   {30}};

    crearArbol(&raiz);
    insertarEnArbol(&raiz,&info[0],sizeof(t_info),compararDni);
    insertarEnArbol(&raiz,&info[2],sizeof(t_info),compararDni);
    //vaciarArbol(&raiz);
    printf("Mayor dni del arbol:%d\n",((t_info*)buscarMayor(&raiz))->dni);///linea peligrosa, al estar vacio el arbol explota
    printf("comprobando la busqueda de nodo padre del %d (si no estaba,crasheara):%d",info[0].dni,
                                        ((t_info*)(*buscarNodoPadre(&raiz,&info[0],compararDni))->info)->dni);
    vaciarArbol(&raiz);
    return 0;
}
