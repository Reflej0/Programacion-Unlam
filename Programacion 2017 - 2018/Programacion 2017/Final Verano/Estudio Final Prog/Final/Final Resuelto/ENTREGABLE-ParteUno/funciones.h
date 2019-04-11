#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#define esVocal( X ) ( ( X ) == 'a' || ( X ) == 'e' || ( X ) == 'i' || ( X ) == 'o' || ( X ) == 'u' || ( X ) == 'A' || ( X ) == 'E' || ( X ) == 'I' || ( X ) == 'O' || ( X ) == 'U')
#define noEsSeparador( X ) ( ( ( X ) >= 'a' && ( X ) <= 'z' ) || ( ( X ) >= 'A' && ( X ) <= 'Z' ) || ( ( X ) >= '0' && ( X ) <= '9' ) )
typedef struct
{
    char letra;
} tInfo;

typedef struct sNodo
{
    tInfo           info;
    struct sNodo   *izq,
                   *der;
} tNodo, *tArbol;

void crearYCargarArbol(tArbol *p);

void mostrarArbol(const tArbol *p);


/** ------------------------------o----x----o------------------------------ **/
/** Funciones a reemplazar                                                  **/
/** ------------------------------o----x----o------------------------------ **/
int contarPalabrasMasDeNVocales_2(const char *s, int n);

int reemplazarSeparadoresDePalabras_1(char *s);

int contarNodosInternos_1(const tArbol *p);

int podarRamasDeAlturaH_1(tArbol *p, int h);
#endif

