#include ".h"

int sacarS2deS1(char* s1, const char* s2)/// tema doble espacios. Probados todos los casos, más polémica con el de defecto
{
    const char* p2;
          char* p1;
          char* z1;

    if(!*s1 || !*s2)
            return 0;
    while(*s1)
    {
        while(*s1 && *s2 && *s1!=*s2)
            s1++;
        p2=s2;
        p1=s1;
        while(*s1==*p2 && *p2 && *s1)
        {
            s1++;
            p2++;
        }
        if(!*p2)
        {
            z1=p1;
            while(*s1)
            {
                *p1=*s1;
                p1++;
                s1++;
            }
            *p1='\0';
            s1=z1;
        }
    }
    return 1;
}

int CuentaValida(const char* ncuenta)
{
    const char* cuenta=ncuenta;
    int valor=0,
        validacion;
    while(ESNUMERO(*cuenta) && *cuenta!='-')
    {
        valor+=*cuenta-'0';
        cuenta++;
    }
    cuenta++;
    validacion=*cuenta-'0';
    if((valor/10+valor%10)==validacion)
        return 1;
    return 0;
}

int s2Ens1(const char* s1, const char* s2)
{
    int i=0;
    const char* p2;
    while(*s1)
    {
        while(*s2!=*s1 && *s1)
        {
            if(ESLETRA(*s1))
                i++;
            s1++;
        }
        if(!*s1)
            return -1;
        p2=s2;
        while(*s2 && A_MAYUSCULA(*s1)==A_MAYUSCULA(*s2))
        {
            s1++;
            s2++;
            i++;
        }
        if(!*s2)
        {
            i+=-(s2-p2)+1;
            return i;
        }
        s2=p2;
    }
    return -1;
}

int listaVacia(t_lista* lista)
{
    return *lista==NULL;
}

int EliminarPrimerElemento(t_lista* lista,t_dato* reg)
{
    t_nodo* aux=*lista;

    if(!aux)
        return 0;
    *reg=aux->dato;
    *lista=aux->sig;
    free(aux);
    return 1;
}

int insertarEnListaOrdenado(t_lista* lista,t_dato* reg,int (*cmp)(void* e1,void* e2))
{
    t_nodo* nue=(t_nodo*)malloc(sizeof(t_nodo));

    if(!nue)
        return 0;
    while(*lista && cmp(&((*lista)->dato),reg)<=0)
        lista=&(*lista)->sig;

    nue->dato=*reg;
    nue->sig=*lista;
    *lista=nue;
    return 1;
}

void crearLista(t_lista* lista)
{
    *lista=NULL;
}

int cmp(void* e1,void* e2)
{
    int aux;
    aux=((t_dato*)e1)->mov-((t_dato*)e2)->mov;
    if(!aux)
        return aux;
    return ((t_dato*)e1)->importe-((t_dato*)e2)->importe;
}

int listaLLena(t_lista* lista)
{
    t_nodo* aux=(t_nodo*)malloc(sizeof(t_nodo));
    free(aux);
    return aux==NULL;
}

int cmpNom(t_dato* e1,t_dato* e2)
{
    return strcmp(e1->ncuenta,e2->ncuenta);
}
