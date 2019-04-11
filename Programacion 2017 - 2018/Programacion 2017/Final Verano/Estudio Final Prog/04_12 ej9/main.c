#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main()
{
    srand(time(NULL));
    //NUMERO ALEATORIO ENTRE UNO Y SIETE.
    short int lineas = rand() % (7-1+1) + 1;
    printf("Ingrese numeros y termine con un exit");
    //VARIABLES PARA EL INGRESO POR TECLADO.
    char numero_teclado_char[6] = "";
    short int numero_teclado;
    //TERMINA CUANDO EL USUARIO INGRESA EXIT.
    FILE* arch = fopen("datos.txt", "wt");
    int i = 0; // AUXILIAR PARA EL NUMERO DE LINEAS.
    while(strcmp(numero_teclado_char, "exit") != 0)
    {
        printf("\nNumero:");
        scanf("%s", numero_teclado_char);
        numero_teclado = atoi(numero_teclado_char);
        //PARCHE PARA QUE NO SE INGRESE EL EXIT COMO UN 0.
        if(strcmp(numero_teclado_char, "exit") != 0)
        {
            fprintf(arch, "%hu\t", numero_teclado);
        }
        i++;
        if(i == lineas)
        {
            fprintf(arch, "\n");
            i = 0;
            lineas = rand() % (7-1+1) + 1;
        }
    }
    fclose(arch);
}
