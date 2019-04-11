#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "funciones.h"


int contarPalabrasMasDeNVocales_1(char *s,int cant)
{
	int cantvocales=0,cantpalabras=0;

	while(*s)
	{
		cantvocales=0;

		while(*s == ' ') // aca irian todos los tipos de separadores osea , ; ( ) etc (HACER MACRO O FUNCION)
			s++;

		while(*s != ' ') // si es distinto de separadores
		{
			if(*s = 'a') // aca irian toas las vocales en min y en mas (HACER MACRO O FUNCION)
				cantvocales++;
			
			s++;
		}

		if(cantvocales>cant)
			cantpalabras++;

		s++;

	}

	return cantpalabras;
}


int reemplazarSeparadoresDePalabras_1(char *s)
{
    char*ori=s,*des=s;

    if(!*ori)
        return 0;
    while(*ori)
    {
        while(!noEsSeparador(*ori))
            ori++;
        if(*ori)
        {
            while(*ori && noEsSeparador(*ori))
            {
               *des=*ori;
                des++;
                ori++;
            }
            if(!noEsSeparador(*ori))
            {
                *des=';';
                des++;
                ori++;
            }
        }
    }
    if(des>s && *(des-1) == ';')
        des--;
    *des='\0';
    return 1;
}

int contarNodosInternos_1(const tArbol *p)
{
    if(*p)
    {
        return contarNodosInternos_1(&(*p)->izq) + contarNodosInternos_1(&(*p)->der) + ((*p)->izq && (*p)->der);
    }
    return 0;
}
/** ------------------------------o----x----o------------------------------ **/

int podarRamasDeAlturaH_1(tArbol *p, int h)
{
    
    if(*p)
    {
        if(h == 0)
           int vaciarArbol(p);       
       else
        {
            return podarRamasDeAlturaH_1(&(*p)->izq,h-1)+podarRamasDeAlturaH_1(&(*p)->der,h-1);
        }
    }
    return 0;
}

int vaciarArbol(tArbol*p)
{
    int cont;
    if(*p)
    {
        cont=vaciarArbol(&(*p)->izq)+vaciarArbol(&(*p)->der)+1;
        free(*p);
        *p=NULL;
		return cont+1;
    }
    return 0;
}

/** ------------------------------o----x----o------------------------------ **/


/** ------------------------------o----x----o------------------------------ **/



