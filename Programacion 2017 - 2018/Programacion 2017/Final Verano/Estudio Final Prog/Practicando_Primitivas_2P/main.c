#include "Prototipos.h"

int main()
{
    t_lista lista,lista_a_ordenar;
    t_dato d1,d2,d3,d4,d5,d21,d22,d23,d0,d41,d42,aux;
    crear_Lista(&lista);
    crear_Lista(&lista_a_ordenar);
    d1=1,d2=2,d21=2,d22=2,d23=2,d3=3,d4=4,d5=5,d41=4,d42=5,d0=0;

    /**agregar_al_principio(&lista_a_ordenar,&d0);
    agregar_al_principio(&lista_a_ordenar,&d5);
    agregar_al_principio(&lista_a_ordenar,&d3);
    agregar_al_principio(&lista_a_ordenar,&d1);
    agregar_al_principio(&lista_a_ordenar,&d2);
    ordenarLista(&lista_a_ordenar,cmp);
    mostrar_Lista_Doble(&lista_a_ordenar);
    puts("\n");**/

    insertar_en_lista_ord(&lista,&d1,cmp);
    insertar_en_lista_ord(&lista,&d2,cmp);
    insertar_en_lista_ord(&lista,&d21,cmp);
    insertar_en_lista_ord(&lista,&d22,cmp);
    insertar_en_lista_ord(&lista,&d41,cmp);
    insertar_en_lista_ord(&lista,&d42,cmp);
    insertar_en_lista_ord(&lista,&d3,cmp);
    insertar_en_lista_ord(&lista,&d4,cmp);
    insertar_en_lista_ord(&lista,&d5,cmp);
    insertar_en_lista_ord(&lista,&d0,cmp);
    mostrar_Lista_Doble(&lista);
    puts("\n");
    eliminar_duplicados_lista(&lista,cmp);
    mostrar_Lista_Doble(&lista);
    eliminar_elemento_de_lista(&lista,&d4,cmp);
    puts("\n");
    mostrar_Lista_Doble(&lista);
    eliminar_elemento_de_lista(&lista,&d0,cmp);
    puts("\n");
    mostrar_Lista_Doble(&lista);
    eliminar_elemento_de_lista(&lista,&d5,cmp);
    puts("\n");
    mostrar_Lista_Doble(&lista);

    /**puts("\n");
    sacar_primero_de_lista_ord(&lista,&aux);
    mostrar_Lista_Doble(&lista);
    puts("\n");
    sacar_primero_de_lista_ord(&lista,&aux);
    mostrar_Lista_Doble(&lista);
    puts("\n");
    sacar_primero_de_lista_ord(&lista,&aux);
    mostrar_Lista_Doble(&lista);
    puts("\n");
    sacar_primero_de_lista_ord(&lista,&aux);
    mostrar_Lista_Doble(&lista);
    puts("\n");
    sacar_primero_de_lista_ord(&lista,&aux);
    mostrar_Lista_Doble(&lista);**/
    return 0;
}
