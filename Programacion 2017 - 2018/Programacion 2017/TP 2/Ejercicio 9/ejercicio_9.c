#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Esto es necesario para la comparacion del ingresar_numeros
#include "ejercicio_9.h"

void ingresar_numeros()
{
    FILE *f = fopen("ejercicio9.txt", "w"); //Empiezo a escribir en el archivo.
    char numero[5];
    puts("Ingrese un numero entero, cuando desee parar de ingresar numeros escriba exit");
    puts("Si desea escribir los numeros en otra linea escriba line");
    do
    {
        fflush(stdin);
        printf("Ingreso:");
        scanf("%s", &numero); //Guardo el numero o el corte del usuario.
        if(strcmp(numero, "exit")) //Esto esta hecho para que si ingreso exit, y al parsearlo no me guarde el 0.
        {
            int short small_int = atoi(numero);
            fprintf(f, (char*)small_int);
        }
        if(!strcmp(numero, "line"))
        {
            fprintf(f, "\n");
        }
    }
    while(strcmp(numero, "exit")); //Mientras que la entrada sea distinta de exit.
}
