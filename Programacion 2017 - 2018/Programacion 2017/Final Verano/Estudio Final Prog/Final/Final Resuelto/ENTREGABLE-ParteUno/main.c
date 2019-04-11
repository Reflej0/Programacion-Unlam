
#include "main.h"


int main()
{
    parte11a();
    parte11b();
    parte12a();
    parte12b();

    return 0;
}

/** ------------------------------o----x----o------------------------------ **/
void parte11a()
{
    char    cad[] =
            { ".-A esta hora, es la hora en que todo deberia funcionar sin"
              " problemas.O,no-es-asi?" };
    int     cantVocales = 3;

    puts("Parte 1.1-a.");
    printf("En la cadena: \n"
           "\"%s\"\n"
           "hay %d palabras con mas de %d vocales.\n\n",
           cad,
           contarPalabrasMasDeNVocales_1(cad, cantVocales),
           cantVocales);
}

/** ------------------------------o----x----o------------------------------ **/
void parte11b()
{
    char cad[] = { "\t  \tEs - tal y como te digo - esto lo que nos pasa:\n\n"
          "\t   En estas horas (las mas aciagas de nuestra historia),  se juega"
          "  el  destino de las generaciones por venir.\n" };

    puts("Parte 1.1-b.");
    puts("Antes:");
    printf("\"%s\"\n", cad);
    puts("Despues:");
    reemplazarSeparadoresDePalabras_1(cad);
    printf("\"%s\"\n\n", cad);
}

/** ------------------------------o----x----o------------------------------ **/
void parte12a()
{
    tArbol arbol;

    puts("Parte 1.2-a.");
    crearYCargarArbol(&arbol);
    mostrarArbol(&arbol);
    printf("El arbol tiene %d nodos internos.\n\n",
           contarNodosInternos_1(&arbol));
}

/** ------------------------------o----x----o------------------------------ **/
void parte12b()
{
    tArbol  arbol;
    int     h = 3;

    puts("Parte 1.2-b.");
    crearYCargarArbol(&arbol);
    mostrarArbol(&arbol);
    printf("Al podar ramas de altura %d o menor se eliminaron %d nodos.\n",
           h, podarRamasDeAlturaH_1(&arbol, h));
    mostrarArbol(&arbol);
    puts("");
}

