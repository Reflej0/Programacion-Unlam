#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int n;
    char s[21];
    float r;
} T_prueba;

int conversion(const char* e, const char* s)
{
    FILE* r = fopen(e, "rt");
    if(!r)
        return -9;
    FILE* w = fopen(s, "wt");
    if(!w)
        return -9;
    T_prueba aux;
    fscanf(r, "%d|%[^|]|%f", &aux.n, aux.s, &aux.r);
    aux.s[21] = '\0';
    while(!feof(r))
    {
        fprintf(w, "%-10d%-20s%.2f\n", aux.n, aux.s, aux.r);
        fscanf(r, "%d|%[^|]|%f", &aux.n, aux.s, &aux.r);
        aux.s[21] = '\0';
    }
    fclose(r);
    fclose(w);
    return 1;
}

int main()
{
    char* l = "test.txt";
    char* w = "salida.txt";
    return conversion(l, w);
}
