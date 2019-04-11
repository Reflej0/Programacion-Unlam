#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char n[11];
    char a[11];
    int t;
} T_prueba;

int lectura_fija_txt(const char* dir)
{
    FILE* arch = fopen(dir, "rt");
    if(!arch)
        return -1;
    T_prueba aux;
    while(fscanf(arch, "%10c%10c%d\n", aux.n, aux.a, &aux.t) != EOF)
    {
        aux.n[10] = '\0';
        aux.a[10] = '\0';
        printf("Nombre:%s\nApellido:%s\nNumero:%d\n", aux.n, aux.a, aux.t);
    }
    fclose(arch);
    return 1;
}

int main()
{
    lectura_fija_txt("test.txt");
    return 0;
}
