#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void crear_cola(t_cola* pcola)
{
	pcola->frente = 0;
	pcola->fondo = -1;
	pcola->ce = 0;
}

int poner_en_cola(t_cola* pcola, const t_dato* pd)
{
	if(pcola->ce == TAM)
    {
        return 1; //COLA LLENA.
    }
    pcola->fondo = (pcola->fondo+1)%TAM;
    pcola->vcola[pcola->fondo] = *pd;
    pcola->ce++;
    return 0; //VERDADERO.
}

int sacar_de_cola(t_cola* pcola, t_dato* pd)
{
	if(pcola->ce == 0)
    {
        return 1; //COLA VACIA.
    }
    *pd = pcola->vcola[pcola->frente];
    pcola->frente = (pcola->frente+1)%TAM;
    pcola->ce--;
    return 0; // VERDADERO.
}

void vaciar_cola(t_cola* pcola)
{
    pcola->frente=0;
    pcola->fondo=-1;
    pcola->ce=0;
}

int frente_de_cola(const t_cola* pcola, t_dato* pd)
{
	if(pcola->ce == 0)
    {
        return 1; //COLA VACIA.
    }
    *pd = pcola->vcola[pcola->frente];
    return 0; // VERDADERO.
}

int cola_vacia(const t_cola* pcola)
{
	if(pcola->ce == 0)
    {
        return 0; //VACIA.
    }
    return 1; // NO VACIA.
}

int cola_llena(const t_cola* pcola)
{
	if(pcola->ce == TAM)
    {
        return 0; //LLENA.
    }
    return 1; //NO LLENA.
}
