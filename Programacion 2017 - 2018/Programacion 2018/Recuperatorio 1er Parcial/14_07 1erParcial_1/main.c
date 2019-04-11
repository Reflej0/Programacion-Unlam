#include <stdio.h>
#include <stdlib.h>

size_t _strlen(const char* cad)
{
    if(!cad || !*cad) return 0;
    return _strlen(cad+1)+1;
}

typedef struct
{
    size_t l;
    char* s;
} T_dato;

/* Funcion que me retorna donde finaliza una cadena y su longitud
ambos datos recorriendo solo una vez la cadena.
*/
void _strlen_(const char* cad, T_dato* d)
{
    size_t l = 0;
    while(*cad)
    {
        cad++;
        l++;
    }
    d->s = (char*)--cad;
    d->l = l;
}

/*char* invertir_cadena(char* cad)
{
    if(!cad || !*cad) return cad;
    char* inicio = cad;
    int i = 0;
    T_dato d;
    _strlen_(cad, &d);
    while(i<d.l/2)
    {
        swap_(cad, d.s);
        cad++;
        d.s--;
        i++;
    }
    return inicio;
}*/

void swap_(char* a, char* b)
{
    char c = *a;
    *a = *b;
    *b = c;
}
/** Esta funcion me retorna la longitud de la cadena
y por parametro el ultimo caracter antes del /0 de una cadena.
*/
size_t __strlen(char** cad)
{
    if(!*cad || !**cad) return 0;
    size_t l = 0;
    while(**cad)
    {
        (*cad)++;
        l++;
    }
    (*cad)--;
    return l;
}

char* invertir_cadena(char* cad)
{
    if(!cad || !*cad) return cad;
    char* inicio = cad;
    char* aux = cad;
    int l = __strlen(&aux);
    int i = 0;
    while(i<l/2)
    {
        swap_(cad, aux);
        cad++;
        aux--;
        i++;
    }
    return inicio;
}

int main()
{
    char c1[20] = "Hola";
    char c1_[20] = "Holas";
    char c2[20] = "Extenso si";
    char c3[20] = "\0";
    char* c4 = NULL;
    printf("Cadena invertida: %s", invertir_cadena(c1));
    return 0;
}
