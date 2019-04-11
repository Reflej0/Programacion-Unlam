#include <stdio.h>
#include <stdlib.h>
#include "vector_dinamico.h"

int main()
{
    int tam_inicial = 5; // Especifico el tamaño inicial en 5
    vector_t* vector = vector_crear(tam_inicial); // Creo el vector dinámico con tamaño inicial.
    int i = 0; //Contador del vector.
    float* elemento; //Variable auxiliar para manipular el vector dinámico.
    char numero[5]; // Lo declaro como un string para permitirle al usuario ingresar un "no-numero" para cortar el ingreso.
    float float_numero; //Esta variable contendrá el valor en tipo float de la variable numero.
    do
    {

        fflush(stdin); //Limpio el buffer de teclado.
        printf("Ingrese un numero real, cuando desee parar de ingresar numeros escriba exit\nIngreso:");
        scanf("%s", &numero); //Guardo el numero o el corte del usuario.
        float_numero = atof(&numero); // Convierto el string a float.
        vector_agregar(vector, i, &float_numero+i); // Agrego el float al vector.
        elemento = (float*)(vector_obtener(vector, i));
        printf("\nValor del elemento agregado:%f", *elemento);
        printf("\nPosicion de memoria:%p", elemento);
        i++; //Incremento el contador.
        if(i==vector_obtener_tam(vector)) // Si ocupe todo el vector.
        {
            vector_redimensionar(vector, (i+5)); // Le agrego mas espacio.
        }
    }
    while(strcmp(numero, "exit")); //Mientras que la entrada sea distinta de exit.
    printf("\nValor del elemento agregado:%f", *elemento);
    for(i=0;i<vector_obtener_tam(vector);i++)
    {
        if(!elemento){
        elemento = (float*)(vector_obtener(vector, i));
        printf("\nValor del elemento agregado:%f", *elemento);
        }

    }
    return 0;
}


