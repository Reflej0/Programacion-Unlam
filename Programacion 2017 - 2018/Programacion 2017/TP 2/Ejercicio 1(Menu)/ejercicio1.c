#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Esto es necesario para la comparacion del llenar_vector
#include "ejercicio1.h"

//La función devuelve el tamaño final del vector, decidí realizar los reallocs cada 5 números.
int llenar_vector(float *vector)
{
    int i = 0; //Contador del vector.
    char numero[5]; // Lo declaro como un string para permitirle al usuario ingresar un "no-numero" para cortar el ingreso.
    puts("Ingrese un numero real, cuando desee parar de ingresar numeros escriba exit");
    do
    {
        i++;
        fflush(stdin);
        printf("Ingreso:");
        scanf("%s", &numero); //Guardo el numero o el corte del usuario.
        if(strcmp(numero, "exit")) //Esto esta hecho para que si ingreso exit, y al parsearlo no me guarde el 0.
        {
            vector[i-1] = atof(numero); // Almaceno en el vector dinámico el número ingresado por el usuario.
        }
        if(i%5==0){ //Cada 5 numeros redimensiono el vector.
            realloc((void*)vector, (i+5)); //Redimensiono el vector 5 lugares mas.
        }
    }
    while(strcmp(numero, "exit")); //Mientras que la entrada sea distinta de exit.
    return i-1;
}

//Este método muestra una lista de opciones y retorna la opción elegida.
int menu()
{
    int opcion;
    printf("1)Buscar el minimo elemento\n2)Calcular el promedio de los valores de las posiciones pares\n3)Mostrarlo en orden inverso\n4)Salir\nOpcion:");
    scanf("%d", &opcion);
    return opcion;
}

//Este método recibe la opción elegida por el usuario, y el vector y procesa la tarea.
void opciones(int opcion, float* vector, int size)
{
    int i = 0; //Variable para los ciclos iterativos.
    float promedio = 0; //Variable donde se almacenará el promedio.
    int pares = 0; //Variable donde se almacenará el total de opciones pares.
    float minimo = vector[0]; //Empiezo tomando la primera posicion como el valor minimo.
    switch(opcion)
    {
    case 1:
        for(i=0;i<size;i++)
        {
            if(vector[i]<minimo)
            {
                minimo = vector[i];
            }
        }
        printf("El valor minimo es %.2f", minimo);
    break;
    case 2:
        for(i=0;i<size;i+=2) //Voy saltando de 2 en 2, así me evito hacer un if preguntando i%2==0
        {
            promedio+=vector[i]; //Primero la variable promedio guarda la suma de los numeros en las posiciones pares.
            pares++; //Cuento la cantidad de posiciones pares.
        }
        printf("El promedio de las posiciones pares es %.2f", (promedio/pares));
    break;
    case 3:
        for(i=size-1; i>=0; i--)
        {
            printf("%.2f\n", vector[i]);
        }
    break;
    }
}

void guardar(float *vector, int size)
{
int i;
FILE *f = fopen("ejercicio1.txt", "w");
for(i=0;i<size;i++)
{
    fprintf(f, "%.2f\n", vector[i]);
}
}
