
#include "main.h"


int main()
{
/** para la primer parte:                                                   */
    char    cadena[] = { "Cadena de caracteres" },
            subCad[] = { "por " },   /// <- pruebe con distintas cadenas
           *aux;
    int     veces;

/** para la segunda parte:                                                  */
    tLista  lista;

    crearYCargarLista(&lista);


/** parte 1.a.-                                                             */
    puts("Probando parte 1.a.-");
    printf("Buscando en: \"%s\" ...\n"
           "... la primer ocurrencia de: \"%s\".\n",
           cadena, subCad);
    aux = buscarPrimerOcurrencia(cadena, subCad); /** <- invoque su función */
    if(aux)
        printf("Encontrado a partir de \"%s\"\n", aux);
    else
        printf("NO encontrado\n");

/** parte 1.b.-                                                             */
    puts("\nProbando parte 1.b.-");
    veces = contarOcurrencias(cadena, subCad);    /** <- invoque su función */
    printf("En la cadena \"%s\" ...\n"
           "... los caracteres \"%s\", "
           "se encuentran %d ve%s%s.\n",
               cadena, subCad,
               veces, veces == 1 ? "z" : "ces",
               veces == 0 ? " (no se encuentran)" : "");

/** parte 2.-                                                               */
    mostrarLista(&lista, "Estado inicial de la lista");

    eliminarDuplicadosYAcumular(&lista,           /** <- invoque su función */
                                  compararXClaCliClaProd,
                                  acumular);

    mostrarLista(&lista, "\nDespues de eliminar los duplicados");

    ordenarLista(&lista,                          /** <- invoque su función */
                   compararXClaCliClaProd);

    mostrarLista(&lista, "\nDespues de ordenar la lista");

    vaciarLista(&lista);

    return 0;
}

