#include <Lista.h>
#include <stdio.h>
#include <stdlib.h>
#include <Tipos.h>
#define TODO_OK 1
#define SIN_MEM 5;
#define LISTA_VACIA 4;
int insertar_en_lista_ord(t_lista* pl, const t_dato* pd, t_cmp cmp)
{
	///Inserte el código acá
	if (pl==NULL)
        return LISTA_VACIA;
	t_lista *aux=NULL;
    t_nodod *nuevo_elemento=(t_nodod*)malloc(sizeof(t_nodod));
    if (nuevo_elemento==NULL)
        return SIN_MEM;
    aux=*pl;
    nuevo_elemento->info=*pd;
    if ((*aux)->psig==NULL && (*aux)->pant==NULL) //La lista tiene un solo elemento
    {
        nuevo_elemento->pant=(*aux)->pant;
        nuevo_elemento->psig=(*aux)->psig;
    }else{
        while(aux!=NULL && cmp(&((*aux)->info),&pd)==1)
        {
                aux = (*aux)->psig;
        }
        if (aux==NULL) //Llegue al ultimo elemento
        {
            nuevo_elemento->pant=*aux;
            nuevo_elemento->psig=(*aux)->psig; //Igual a NULL
            return TODO_OK;
        }else{

            nuevo_elemento->pant=*aux;
            nuevo_elemento->psig=(*aux)->pant;
            *pl=aux;
        }

    }
}


void recorrer_lista(const t_lista* pl, t_accion accion, void* datos_accion)
{

	while(*pl!=NULL && accion(&pl,&datos_accion))
    {
         *pl=(*pl)->psig;
    }
}
