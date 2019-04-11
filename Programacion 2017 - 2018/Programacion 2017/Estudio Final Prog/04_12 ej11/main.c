#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* arch = fopen("datos.txt", "rt");
    FILE* arch_100 = fopen("100.txt", "wt");
    char line[100]; //VARIABLE PARA LEER LA LINEA.
    char *div;
    short int numero;
    //CONTADORES.
    int mul5 = 0;
    int mul6 = 0;
    int mul11 = 0;
    while(fgets(line, 100, arch))
    {
        div = strtok(line, "\t\n");
        while(div)
        {
            printf("%s\n", div);
            div = strtok(NULL, "\t\n");
            numero = atoi(div);
            if(numero % 5 == 0)
            {
                mul5++;
            }
            if(numero % 6 == 0)
            {
                mul6++;
            }
            if(numero % 11 == 0)
            {
                mul11++;
            }
            if(numero > 100)
            {
                fprintf(arch_100, "%hu\n", numero);
            }
        }
    }
    printf("Multiplos de 5: %d\n", mul5);
    printf("Multiplos de 6: %d\n", mul6);
    printf("Multiplos de 11: %d\n", mul11);
    fclose(arch);
    fclose(arch_100);
}
