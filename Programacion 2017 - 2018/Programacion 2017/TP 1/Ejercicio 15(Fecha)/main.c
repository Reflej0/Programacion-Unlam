#include <stdio.h>
#include <stdlib.h>

typedef struct // Estructura de Datos. (Objeto tipo Fecha).
{
    int dia,
        mes,
        anio;
}   tFecha;

int ValidarFecha(tFecha Fecha) // Ejercicio 14.
{
    int i = 0; // Variable temporal.
    int verdadero = 0; // Si el valor es menor a 0, no es verdadero.
    int mesescon30[] = {4, 6, 9, 11}; // Vector con los numeros de los meses que tienen 30 dias.
    int len = sizeof(mesescon30) / sizeof(int); // La longitud del vector mesescon30.
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
                verdadero=90; // Si verdadero vale 90, el año es biciesto.
            }
        }
    }
    return verdadero; // Si el numero es negativo, entonces es falso.
}

int main()
{
    int actualizado = 0; // Esta variable me indica si actualice la fecha o no.
    tFecha Fecha;
    printf("Introduzca dia, mes y año:");
    scanf("%d %d %d", &Fecha.dia, &Fecha.mes, &Fecha.anio);
    if(ValidarFecha(Fecha)>=0){ // Valido la fecha.
        if(Fecha.dia == 28 && Fecha.mes == 2 && ValidarFecha(Fecha)!=90){ // Si estoy en un 28 de Febrero no biciesto.
            Fecha.dia=1;
            Fecha.mes=3;
            actualizado++;
        }
        if(Fecha.dia == 29 && Fecha.mes == 2 && ValidarFecha(Fecha)==90){ // Si estoy en un 29 de Febrero biciesto.
            Fecha.dia=1;
            Fecha.mes=3;
            actualizado++;
        }
        if(Fecha.dia == 30 && (Fecha.mes==4 || Fecha.mes==6 || Fecha.mes==9 || Fecha.mes==11)){ // Si estoy en un dia 30, de un mes que tiene 30 dias.
            Fecha.dia=1;
            Fecha.mes++;
            actualizado++;
        }
        if(Fecha.dia == 31 && (Fecha.mes==1 || Fecha.mes==3 || Fecha.mes==5 || Fecha.mes==7 || Fecha.mes==8 || Fecha.mes==10)){ // Si estoy en un dia 31, de un mes que tiene 31 dias.
            Fecha.dia=1;
            Fecha.mes++;
            actualizado++;
        }
        if(Fecha.dia == 31 && Fecha.mes==12){ // Si estoy en un 31 de diciembre.
            Fecha.dia = 1;
            Fecha.mes = 1;
            Fecha.anio++;
            actualizado++;
        }
        if(actualizado == 0){ // Si estoy en un dia que no finaliza el mes ni el año.
            Fecha.dia++;
        }
            printf("Dia:%d Mes:%d Año:%d", Fecha.dia, Fecha.mes, Fecha.anio);
    }
    else{
        printf("La fecha ingresada no es valida.");
    }
}
