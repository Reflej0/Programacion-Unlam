#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia,
        mes,
        anio;
}   tFecha;

int main()
{
    int i = 0; // Variable temporal.
    int verdadero = 0; // Si el valor es menor a 0, no es verdadero.
    tFecha Fecha; // Variable tipo tFecha.
    int mesescon30[] = {4, 6, 9, 11}; // Vector con los numeros de los meses que tienen 30 dias.
    int len = sizeof(mesescon30) / sizeof(int); // La longitud del vector mesescon30.
    printf("Ingrese el dia, mes y año:");
    scanf("%d %d %d", &Fecha.dia, &Fecha.mes, &Fecha.anio);
    if(Fecha.dia<=0 || Fecha.dia >31 || Fecha.mes<=0 || Fecha.mes>12){ // Primero compruebo que el dia y el mes.
        verdadero--;
    }
    else{
        if(Fecha.dia == 31){ // Compruebo si el numero del dia es 31.
                for(i=0;i<len;i++){
                    if(Fecha.mes!=mesescon30[i]){
                        verdadero++;
                    }
                }
        }
        if(Fecha.dia == 30){ // Compruebo si el numero del dia es 30.
                for(i=0;i<len;i++){
                    if(Fecha.mes==mesescon30[i]){
                        verdadero++;
                    }
                }
        }
        if(Fecha.dia == 29 && Fecha.mes == 2){
            if((Fecha.anio % 100 == 0 && Fecha.anio % 400 ==0) || (Fecha.anio % 4 == 0 && Fecha.anio % 100 !=0)){
                verdadero++;
            }
        }
    }
    if(verdadero >=0){
        printf("La fecha ingresada es correcta.");
    }
    else{
        printf("La fecha ingresada es incorrecta.");
    }
}
