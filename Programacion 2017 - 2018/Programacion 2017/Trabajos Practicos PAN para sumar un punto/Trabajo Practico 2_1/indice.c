#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "indice.h"
#include <string.h>

///Crea la lista y el iterador.
void ind_crear(T_indice *pi)
{
    crear_lista(&(pi->l));
    crear_iterador(&(pi->ite));
}

///inserta en la lista en orden según el dni
//Devuelve 0 si la operacion es exitosa.
int ind_insertar(T_indice *pi, const t_reg_indice *reg)
{
    //Se inserta el DNI en la lista de forma ordenada.
    int resultado = agregar_ordenado(&(pi->l), reg, cmp, &(pi->ite));
    //Se establece el ini del Iterador en base al primer nodo de la lista.
    set_nodo_inicial(&(pi->ite), (pi->l));
    return resultado;
}

///elimina el dni informado de la lista.
//Devuelve 0 si la operacion es exitosa.
int ind_eliminar(T_indice *pi, t_reg_indice *reg)
{
    unsigned i = 0; // Contador.
    int resultado = 0;
    t_reg_indice dato; // Variable auxiliar para traer el dato.
    get_reg_inicial(&(pi->ite), &dato); // Obtengo el primer registro.
    if(dato.dni == reg->dni) // Si el primer registro es el DNI que estoy buscando eliminar.
    {
        resultado = eliminar_indice(&(pi->l), &dato, i); // Guardo el resultado de lo que me devuelve eliminar_indice (lista).
    }
    while(!get_reg_siguiente(&(pi->ite), &dato)) // Voy avanzando con el iterador por los registros de la lista.
    {
        i++; // Como ya realice la lectura sobre el primero, incremento el indice.
        if(dato.dni == reg->dni) // Voy comparando con el iterador por los registros de la lista.
        {
            resultado = eliminar_indice(&(pi->l), &dato, i);
            set_nodo_inicial(&(pi->ite), (pi->l));
            return resultado; // Corto aca, no sigo recorriendo.
        }
    }
    return resultado;
}
///si el dni existe en la lista deja el registro en reg_ind
//Devuelve 0 si la operacion es exitosa.
int ind_buscar(T_indice *pi, t_reg_indice *reg)
{
    t_reg_indice dato; //Variable auxiliar.
    get_reg_inicial(&(pi->ite), &dato); // Obtengo el primer registro.
    if(dato.dni == reg->dni) // Si el primer registro es el DNI que estoy buscando.
    {
        *reg = dato;
        return 0;
    }
    while(!get_reg_siguiente(&(pi->ite), &dato)) // Voy avanzando con el iterador por los registros de la lista.
    {
        if(dato.dni == reg->dni) // Voy comparando con el iterador por los registros de la lista.
        {
            *reg = dato;
            return 0;
        }
    }
    return 1;
}

///Carga la lista desde un archivo ordenado
int ind_cargar(T_indice *pi, const char* path)
{
    FILE* arch = fopen(path, "rb");
    T_dato registro;
    fread(&registro, sizeof(T_dato), 1, arch); // Leo el primer registro del archivo.
    while(!feof(arch))
    {
        agregar_ordenado(&(pi->l), &registro, cmp, &(pi->ite));
        set_nodo_inicial(&(pi->ite), (pi->l));
        //printf("DNI: %ld", registro.dni);
        fread(&registro, sizeof(T_dato), 1, arch);
    }
    fclose(arch);
    return 0;
}

///Carga la lista desde un archivo ordenado
void ind_leer_archivo(const char* path)
{
    FILE* arch = fopen(path, "rb");
    T_dato registro;
    fread(&registro, sizeof(T_dato), 1, arch); // Leo el primer registro del archivo.
    while(!feof(arch))
    {
        printf("\nINDICE: %d-DNI: %ld", registro.nro_reg, registro.dni);
        fread(&registro, sizeof(T_dato), 1, arch);
    }
    fclose(arch);
}

///Graba un archivo con el contenido del índice
int ind_grabar(T_indice *pi, const char* path)
{
    ///EL PATH YA RECIBE EL DIRECTORIO CON LA EXTENSION .idx
    FILE* arch = fopen(path, "wb"); // Abro el archivo.
    T_dato registro; // Esta variable tendra los registros de la lista.
    get_reg_inicial(&(pi->ite), &registro); // Obtengo el primer registro de la lista.
    while(ind_fin(pi) == 0) // Mientras no este en el final voy leyendo los registros.
    {
        fwrite(&registro, sizeof(T_dato), 1, arch); // Grabo el registro de la lista.
        get_reg_siguiente(&(pi->ite), &registro); // Obtengo el siguiente registro de la lista.
    }
    fclose(arch);
    return 0;
}
///deja el índice en su estado de vacío
void ind_vaciar(T_indice *pi)
{
    eliminar_lista(&(pi->l));
    eliminar_iterador(&(pi->ite));
}
///Deja el primer registro de índice en reg_ind
int ind_primero(T_indice *pi, t_reg_indice *reg)
{
    return get_reg_inicial(&(pi->ite), reg);
}
///Deja el registro siguiente al último entregado en reg_ind
int ind_siguiente(T_indice *pi, t_reg_indice *reg)
{
    return get_reg_siguiente(&(pi->ite), reg);
}
///Devuelve verdad si la última operación de acceso secuencial no entregó el registro por haber llagado al fin de la secuencia y falso en caso contrario.
int ind_fin(T_indice *pi)
{
    return esFinal(&(pi->ite));
}
