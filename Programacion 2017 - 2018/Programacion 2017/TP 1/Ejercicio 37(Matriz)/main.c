#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, orden;
    int incorrecta = 0;
    puts("Ingrese el orden de la matriz:");
    scanf("%d", &orden);
    int matriz[orden][orden];
    int vector[orden];
    for(k=0;k<orden;k++){
        vector[k] = 0;
    }
    for(i=0;i<orden;i++){
        for(j=0;j<orden;j++){
            puts("Ingrese un numero:");
            scanf("%d", &matriz[i][j]);
        }
    }
    for(i=0;i<orden;i++){
        for(j=0;j<orden;j++){
                if(i==j){ //Los resultados de la diagonal tienen que ser 0 ya que un equipo no puede enfrentarse contra el mismo.
                        if(matriz[i][j]==0){
                           }
                         else{
                                    incorrecta++;
                            }
                }
                if((matriz[i][j] ==0) || (matriz[i][j] ==1) || (matriz[i][j] ==3)){ // La puntuacion es 0, 1 o 3.
                }
                else{
                    incorrecta++;
                }
        }
    }
    if(incorrecta==0){
        puts("La matriz es correcta");
    }
    else{
        puts("La matriz es incorrecta");
        return 0;
    }
    for(k=0;k<orden;k++){
       for(i=0;i<orden;i++){
        for(j=0;j<orden;j++){
            if((i==k) || (j==k)){
                vector[k] += matriz[i][j];
            }
        }
    }
    }
    for(i=0;i<orden;i++){
        printf("Puntuacion del equipo %d es: %d", i, vector[i]);
    }
}
