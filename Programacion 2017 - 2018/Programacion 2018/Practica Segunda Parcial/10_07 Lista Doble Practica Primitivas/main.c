#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "auxiliares_lista.h"

int main()
{
    T_lista lista;
    crear_lista(&lista);
    T_dato uno = 100;
    T_dato dos = -100;
    T_dato tres = 500;
    T_dato cuatro = -15;
    T_dato cinco = -15;
    T_dato seis = 125;
    T_dato siete = 500;
    T_dato ocho = 500;
    T_dato nueve = -15;
    agregar_al_principio(&lista, &uno);
    agregar_al_principio(&lista, &dos);
    agregar_al_principio(&lista, &tres);
    agregar_al_principio(&lista, &cuatro);
    agregar_al_principio(&lista, &cinco);
    agregar_al_principio(&lista, &seis);
    agregar_al_principio(&lista, &siete);
    agregar_al_principio(&lista, &ocho);
    agregar_al_principio(&lista, &nueve);
    //ordenar_lista_sin_seleccion(&lista, comp_int);
    ordenar_lista(&lista, comp_int);
    //eliminar_lista(&lista);
    mostrar_lista_desde_principio(&lista, show_int);
    return 0;
}

/*int main()
{
    T_lista lista;
    crear_lista(&lista);
    T_dato uno = 100;
    T_dato dos = -100;
    T_dato tres = 500;
    T_dato cuatro = -15;
    T_dato cinco = -15;
    T_dato seis = 125;
    T_dato siete = 500;
    T_dato ocho = 500;
    T_dato nueve = -15;
    agregar_ordenado_duplicados(&lista, &uno, comp_int);
    agregar_ordenado_duplicados(&lista, &dos, comp_int);
    agregar_ordenado_duplicados(&lista, &tres, comp_int);
    agregar_ordenado_duplicados(&lista, &cuatro, comp_int);
    agregar_ordenado_duplicados(&lista, &cinco, comp_int);
    agregar_ordenado_duplicados(&lista, &seis, comp_int);
    agregar_ordenado_duplicados(&lista, &siete, comp_int);
    agregar_ordenado_duplicados(&lista, &ocho, comp_int);
    agregar_ordenado_duplicados(&lista, &nueve, comp_int);
    eliminar_duplicados(&lista, comp_int);
    //eliminar_ordenado(&lista, &siete, comp_int);
    mostrar_lista_desde_principio(&lista, show_int);
    ///LOS N MEJORES.
    printf("Los 3 numeros mas grandes\n");
    T_dato vec[3];
    los_n_mejores(&lista, vec, comp_int, 3);
    int i;
    for(i=0;i<3; i++)
        printf("Mejor: %d\n", vec[i]);
    return 0;
}*/
