#include "funciones.h"
#include "propialibreria.h"

/** -------------------------x---o---x------------------------------ */
/** FUNCIONES A DESARROLLAR  -, Sus versiones deber�an ser sin   _2  */
/** -------------------------x---o---x------------------------------ */

/** esta funci�n recibe el archivo a leer, los archivos a generar ya abiertos
 *      y la lista reci�n creada.
 *  se encarga de leer el archivo, reemplazar las cadenas abreviadas e insertar
 *      en la lista las l�neas que comienzan con fecha y hora ordenando por
 *      fecha y hora, las lineas que no tienen fecha y hora van al archivo de
 *      errores.
 *  luego se encarga de sacar de la lista almacenando en el archivo de salida.
 *  si se produjera alg�n error con la lista, muestra el mensaje correspondiente
 *      y sigue adelante.
 */
void leerPonerEnListaSacarReemplazarYGrabar(FILE *fpEnt, FILE *fpSal,FILE *fpMal, tListaD *lista)
{
    tInfo cad;

    fseek(fpEnt,0L,SEEK_SET);
    fseek(fpSal,0L,SEEK_SET);
    fseek(fpMal,0L,SEEK_SET);
    while(fgets(cad.linea,sizeof(cad),fpEnt))
    {
        reemplazarAbreviaciones(cad.linea);
        if(empiezaConFechaYHora(cad.linea))
            insertarEnOrden_2(lista,&cad,compXFechaYHora);
        else
            fprintf(fpMal,"%s\n",cad.linea);
    }

    while(sacarPrimero(lista,&cad))
        fprintf(fpSal,"%s\n",cad.linea);

}
/** esta funci�n crea la lista como lista vac�a
 */
void crearListaD(tListaD *p)
{
    *p=NULL;
}

/** esta funci�n inserta en orden en la lista, pero si encuentra la misma clave,
 *      devuelve un indicador de Clave Duplicada.
 *  siempre deja la lista con la direcci�n del �ltimo insertado.
 *  devuelve un indicador de fracaso o �xito (SIN_MEM, CLA_DUP o TODO_BIEM).
 */
int insertarEnOrden(tListaD *p, const tInfo *d,int (*cmp)(const tInfo *d1, const tInfo *d2))
{

}
/** se encarga de recuperar la informaci�n del primero de la lista,
 *      devolviendo un indicador de �xito o fracaso.
 */
int sacarPrimero(tListaD *p, tInfo *d)
{
    tNodoD* aux=*p;
    if(!aux)
        return 0;
    while(aux->ant)
        aux=aux->ant;
    *d=aux->info;
    *p=aux->sig;
    free(aux);
    if((*p))
        (*p)->ant=NULL;
    return 1;

}

/** no obligatorio pero conveniente resolverla para la funci�n que inserta en
 *      la lista doblemente enlazada en forma ordenada.
 */
int compXFechaYHora(const tInfo *d1, const tInfo *d2)
{
    return strncmp((*d1).linea,(*d2).linea,23);
}

/** determina si la l�nea de texto comienza con una fecha y hora con el formato
 *      dd/mm/aaaa hh:mm:ss,ccc:
 *  no controla que sea una fecha y hora v�lidas, s�lo que est� bien formada.
 */
int empiezaConFechaYHora(const char *s)
{
    int aux;
    return (sscanf(s,"%02d/%02d/%04d %02d:%02d:%02d,%03d",&aux,&aux,&aux,&aux,&aux,&aux,&aux)<7)?0:1;
}
/** hace los reemplazos de las abreviaciones expandiendo la cadena de car�cteres
 */
void reemplazarAbreviaciones(char *s)
{
    char aux[TAM_LINEA]={"\0"};
    char* recorrido=s,
        * principio=s;

    while(*s)
    {
        recorrido=strchr(recorrido,'*');
        if(!recorrido)
        {
            strcat(aux,s);
            strcpy(principio,aux);
            return;
        }
        recorrido--;
        *recorrido='\0';
        strcat(aux,s);
        strcat(aux,"-que locura-");
        recorrido+=2;
        s=recorrido;
    }
}
