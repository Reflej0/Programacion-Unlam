#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TODO_OK 1
#define SIN_MEMORIA 0
#define DUPLICADO 2

typedef struct
{
    int dato;
}t_info;

typedef struct s_nodo
{
    struct s_nodo *psig;
    struct s_nodo *pant;
    t_info info;
}t_nodo;

typedef t_nodo* t_lista;

char menu (const char[][40], const char*);
char pedir_opcion (const char [][40], const char *,const char*);
int cargarDato(t_info*);
void crearLista(t_lista*);
int insertarEnListaOrdenada(t_lista*,const t_info*);
int compararClaves(const t_info*,const t_info*);
void mostrarLista(t_lista*);
t_nodo* buscarClave(t_lista*,t_info*); //Devuelve la direccion de la clave
int buscarClavePos(t_lista*,t_info*); //Devuelve la pos de la clave
int eliminarClave(t_lista*,t_info*); //Devuelve la pos del elemento eliminado y su contenido en t_info

int main()
{
    t_lista lista;
    t_info dato;
    t_nodo* dir;
    int aux;
    const char opciones [][40] = {"012Q",
                                "Crear lista",
                                "Cargar dato",
                                "Mostrar lista",
                                "Salir"
                                };
    char op;
    do{
      op=menu(opciones,"Listas");
      switch(op)
      {
                    case '0':
                        crearLista(&lista);
                        puts("\nLista creada");
                        system("pause");
                        break;
                    case '1':
                        if(cargarDato(&dato))
                        {
                            if(!insertarEnListaOrdenada(&lista,&dato))
                                return SIN_MEMORIA;
                            printf("\nInsertado");
                        }
                        system("pause");
                        break;
                    case '2':
                        mostrarLista(&lista);
                        system("pause");
      }
    }while (op!='Q');
    return 0;
}

///////////////////////////////////////////////

char pedir_opcion (const char opc [][40], const char * titulo, const char * msj)
{
    int cant, i;
    char op;
    system ("CLS");
    printf("\n\n%s\n",titulo);
    cant=strlen(opc[0]);
    for(i=0;i<cant;i++)
        printf("\n\t%c: %s",opc [0][i],opc[i+1]);
    printf("\n\n%s", msj);
    fflush(stdin);
    scanf("%c",&op);
    op=toupper(op);
    return op;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 char menu (const char opciones [][40],const char*titulo)
 {
     char op= pedir_opcion(opciones,titulo,"Elija su opcion: ");
     while(!strchr(opciones[0],op))
        op=pedir_opcion(opciones,titulo,"Opcion erronea, ingrese nuevamente: ");
     return op;
 }

////////////////////////////////////////////////

  int cargarDato(t_info*info)
    {
        printf("\nIngrese un nro: ");
        scanf("%d",&info->dato);
        return TODO_OK;
    }

int compararClaves(const t_info*d1,const t_info*d2)
{
    return d1->dato-d2->dato;
}
/******************************************************************************/

void crearLista (t_lista* pl)
{
    *pl=NULL;
}

////////////////////////////////////////////////////////

void mostrarLista(t_lista*pl)
{
    if(!*pl)
        return;
    while((*pl)->pant )
        {
            pl=&(*pl)->pant;
        }
    while (*pl)
    {
        printf("\nNro: %d",(*pl)->info.dato);
        pl=&(*pl)->psig;
    }
}

/***************************************************************************/

int insertarEnListaOrdenada(t_lista *p,const t_info *d)
{
    t_nodo*act=*p,*ant,*nue;
    if(act)
    {
        while (act->psig&&compararClaves(d,&act->info)>0)
            act=act->psig;
        while (act->pant&&compararClaves(d,&act->info)<0)
            act=act->pant;
        if(compararClaves(d,&act->info)==0)
            return DUPLICADO;
    }
    if(act)
    {
        if(compararClaves(d,&act->info)>0)
        {
            ant=act;
            act=act->psig;
        }
        else
            ant=act->pant;
    }
    else
        ant=NULL;
    nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return SIN_MEMORIA;
    nue->info=*d;
    nue->psig=act;
    nue->pant=ant;
    if(ant)
        ant->psig=nue;
    if(act)
        act->pant=nue;
    *p=nue;
    return TODO_OK;
}
