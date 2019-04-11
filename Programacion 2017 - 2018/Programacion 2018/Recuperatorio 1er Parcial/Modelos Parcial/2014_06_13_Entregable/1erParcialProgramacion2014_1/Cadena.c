#include <Cadena.h>

void normalizar(char * origen, char * destino)
{
    char * porigen_act = origen;
    char * pdest_act = destino;
    t_palabra palabra;

    porigen_act = leer_palabra(porigen_act, &palabra);

    while (porigen_act && *porigen_act) {
        pdest_act = escribir_palabra(pdest_act, &palabra);
        *pdest_act = ' ';
        pdest_act++;
        porigen_act = leer_palabra(porigen_act, &palabra);
    }

    if (*palabra.ini) {
        pdest_act  = escribir_palabra(pdest_act, &palabra);
        *pdest_act = '\0';
    } else
        *(pdest_act - 1) = '\0';
}

char * leer_palabra(char * pdesde, t_palabra * palabra)
{
    char * pact = pdesde;

    while (*pact && !es_letra(*pact))
    	pact++;

    palabra->ini = pact;

    while (*pact && es_letra(*pact))
    	pact++;

    palabra->fin = pact - 1;

    return *pact ? pact : NULL;
}

char * escribir_palabra(char * pdesde, const t_palabra * palabra)
{
    char * pletra_act;
    char * pdest_act;
    t_palabra pal_destino;

    for (pletra_act = palabra->ini, pdest_act = pdesde; pletra_act <= palabra->fin; pletra_act++, pdest_act++)
        *pdest_act = *pletra_act;

    pal_destino.ini = pdesde;
    pal_destino.fin = pdest_act - 1;

    ucfirst(&pal_destino);

    return pdest_act;
}

void ucfirst(t_palabra * palabra)
{
    char * pact = palabra->ini;

    *pact = a_mayus(*pact);

    for (pact = pact + 1; pact <= palabra->fin; pact++)
        *pact = a_minus(*pact);
}

char a_mayus(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - ('a' - 'A'); // Atento al parentesis y el cambio de signos

    return c;
}

char a_minus(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A'; // En ASCII  la representación del alfabeto va en orden A..Za..z

    return c;
}

int es_letra(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
