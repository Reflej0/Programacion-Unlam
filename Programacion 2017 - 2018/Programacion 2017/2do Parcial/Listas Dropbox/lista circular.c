#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define TODO_OK 1
#define TODO_MAL 0
#define DUPLICADO 2
#define NO_ENCONTRADO NULL
#define NO_ELIMINADO -1
#define NO_RECORRIO_TODA_LA_LISTA(x,y) (*(x)!=(y)||yaRecorrio!=1)

typedef struct
{
    int dni;
    char apyn[31];
}t_info;

typedef struct s_nodo
{
    t_info dato;
    struct s_nodo* psig;
}t_nodo;

typedef t_nodo* t_lista;

char menu (const char[][40], const char*);
char pedir_opcion (const char [][40], const char *,const char*);
int cargarDato(t_info*);
void crearLista(t_lista*);
int insertarEnListaCircular(t_lista*,t_info*);
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
    const char opciones [][40] = {"01234Q",
                                "Crear lista",
                                "Cargar dato",
                                "Buscar clave",
                                "Eliminar clave",
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
                        system("cls");
                        if(cargarDato(&dato))
                            if(!insertarEnListaCircular(&lista,&dato))
                                puts("\nNo se pudo cargar");
                        break;

                    case '2':
                        system("cls");
                        puts("\nBUSCAR CLAVES");
                        if(lista!=NULL)
                        {
                            if(cargarDato(&dato))
                                dir=buscarClave(&lista,&dato);
                            if(dir==NO_ENCONTRADO)
                                puts("\nNo esta en la lista");
                            else
                                puts("\nClave encontrada");
                        }
                        else
                            puts("\nLista Vacia");
                        system("pause");
                        break;

                    case '3':
                        system("cls");
                        puts("\nELIMINAR CLAVES");
                        if(cargarDato(&dato))
                            if(lista!=NULL)
                            {
                                aux=eliminarClave(&lista,&dato);
                                if(aux!=NO_ELIMINADO)
                                    printf("\nDato eliminado:\n\nPosicion: %d\nNombre: %s\nDNI: %d\n",aux,dato.apyn,dato.dni);
                                else
                                    puts("No encontrado");
                            }
                            else
                                puts("Imposible eliminar, lista vacia");
                        system("pause");
                        break;

                    case '4':
                        system("cls");
                        puts("MOSTRANDO LISTA");
                        if(lista!=NULL)
                        {
                            mostrarLista(&lista);
                        }
                        else
                            puts("Lista Vacia\n");
                        system("pause");
                        break;
      }
    }while (op!='Q');
    return 0;
}

/************************* FUNCIONES ************************************/

/*********************** Pedir opcion ***********************************/

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

/*********************** Menu ***********************************/
 char menu (const char opciones [][40],const char*titulo)
 {
     char op= pedir_opcion(opciones,titulo,"Elija su opcion: ");
     while(!strchr(opciones[0],op))
        op=pedir_opcion(opciones,titulo,"Opcion erronea, ingrese nuevamente: ");
     return op;
 }

/*********************** Cargar en lista (sin orden) ***********************/
  int cargarDato(t_info*info)
    {
        printf("\nIngrese apellido y nombre: ");
        fflush(stdin);
        gets(info->apyn);
        printf("\nIngrese DNI: ");
        fflush(stdin);
        scanf("%d",&info->dni);
        return TODO_OK;
    }

/*********************** Mostrar lista ***********************************/
void mostrarLista(t_lista*lista)
{
    t_nodo*aux=*lista;
    while(aux->psig!=*lista)
    {
        printf("\nDNI: %d\tNombre: %s\n",aux->dato.dni,aux->dato.apyn);
        aux=aux->psig;
    }
     printf("\nDNI: %d\tNombre: %s\n",aux->dato.dni,aux->dato.apyn);
}

/*********************** Crear lista ***********************************/
void crearLista(t_lista*lista)
{
    *lista=NULL;
}

/*********************** Ins.en lista circular ***********************/
int insertarEnListaCircular(t_lista* lista, t_info* info)
{
    t_nodo* nue;
    nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return TODO_MAL;
    nue->dato=*info;
    if(!*lista)
    {
        nue->psig=nue;
        *lista=nue;
    }
    nue->psig=(*lista)->psig;
    (*lista)->psig=nue;
    return TODO_OK;
}

/***********************Comparar Clave ********************************/
int compararClaves(const t_info*cl1,const t_info*cl2)
{
    char buffer1[80];
    char buffer2[80];
    sprintf(buffer1,"%08d%-31s",cl1->dni,cl1->apyn);
    sprintf(buffer2,"%08d%-31s",cl2->dni,cl2->apyn);
    return strcmpi(buffer1,buffer2);
}

/*********************** Buscar clave ***********************************/
t_nodo* buscarClave(t_lista*lista,t_info*info)
{
    int cmp, yaRecorrio=0;
    t_nodo *aux=*lista;
    while(*lista&&(cmp=compararClaves(info,&(*lista)->dato)>0)&&NO_RECORRIO_TODA_LA_LISTA(lista,aux))
    {
        lista=&(*lista)->psig;
        if((*lista) == aux)
            yaRecorrio++;
    }
    if(cmp==0)
        return *lista;
    return NO_ENCONTRADO;
}

/************************** Eliminar Clave *******************************/
int eliminarClave(t_lista *lista, t_info *dato)
{
    int cmp,pos=2, yaRecorrio=0;
    t_nodo *aux=*lista, **aux2=lista;
    while((cmp=compararClaves(dato,&(*lista)->psig->dato))!=0&&NO_RECORRIO_TODA_LA_LISTA(lista,aux))
    {
        *lista=(*lista)->psig;
        pos++;
        if( (*lista) == aux )
            yaRecorrio++;
    }
    if(cmp!=0)
        return NO_ELIMINADO;
    if((*lista)->psig==aux)
        pos=1;
    aux=(*lista)->psig;
    (*lista)->psig=aux->psig;
    *aux2=aux->psig;
    if((*aux2) == (*aux2)->psig)
        *aux2 = NULL;
    free(aux);
    return (pos);
}
