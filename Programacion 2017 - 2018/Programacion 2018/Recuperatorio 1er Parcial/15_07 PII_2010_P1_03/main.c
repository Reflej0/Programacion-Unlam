#include <stdio.h>
#include <stdlib.h>

//Eleva con exponentes positivos.
int elevar(int n, int pot)
{
    if(pot==0)return 1;
    int i;
    int r = n;
    for(i=0; i<pot-1;i++)
        r*=n;
    return r;
}

float calculo(int x, int tolerancia)
{
    if(tolerancia<0 || tolerancia>1) return -1;
    float resultado = 1 + x;
    float termino;
    int potencia = 2;
    int divisor = 2;
    do
    {
        termino = (float)elevar(x, potencia) / divisor;
        resultado += termino;
        potencia++;
        divisor*=potencia;
    }
    while(termino>tolerancia);
    return resultado;
}

int main()
{
    float resultado = calculo(4, 0.01);
    printf("Resultado: %f", resultado);
    return 0;
}
