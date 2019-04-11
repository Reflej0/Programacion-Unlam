#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main()
{
    ///CREACION DEL ARBOL.
    T_arbol arbol;
    crear_arbol(&arbol);
    T_dato numero = 5;
    insertar_en_arbol(&arbol, &numero, cmp);
    T_dato numero2 = 17;
    insertar_en_arbol(&arbol, &numero2, cmp);
    T_dato numero3 = 1;
    insertar_en_arbol(&arbol, &numero3, cmp);
    mostrar_arbol_pos(&arbol);
    printf("\nALTURA: %d", altura_arbol(&arbol));
    printf("\nEl 17 ESTA EN EL ARBOL: %d", buscar_en_arbol(&arbol, &numero2, cmp));
    eliminar_de_arbol(&arbol, &numero2, cmp);
    printf("\nEl 17 ESTA EN EL ARBOL: %d", buscar_en_arbol(&arbol, &numero2, cmp));
}
