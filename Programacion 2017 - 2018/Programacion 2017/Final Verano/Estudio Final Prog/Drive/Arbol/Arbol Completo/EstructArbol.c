#include"EstructArbol.h"

int comparar(const void *s1,const void *s2)
{
    t_dato *e1=(t_dato*)s1,
            *e2=(t_dato*)s2;

    return (e1->x-e2->x);
}

void crearArbol(t_arbol *raiz)
{
    *raiz=NULL;
}

void mostrarInOrden(t_arbol *raiz)
{
    if(*raiz)
    {
        mostrarInOrden(&(*raiz)->izq);
        printf("%d\n",(*raiz)->dato.x);
        mostrarInOrden(&(*raiz)->der);
    }
}

void mostrarPreOrden(t_arbol *raiz)
{
    if(*raiz)
    {
        printf("%d\n",(*raiz)->dato.x);
        mostrarPreOrden(&(*raiz)->izq);
        mostrarPreOrden(&(*raiz)->der);
    }
}

void mostrarPosOrden(t_arbol *raiz)
{
    if(*raiz)
    {
        mostrarPosOrden(&(*raiz)->izq);
        mostrarPosOrden(&(*raiz)->der);
        printf("%d\n",(*raiz)->dato.x);
    }
}

///ARBOL BINARIO DE BUSQUEDA-> SIN CLAVES DUPLICADAS. MAYOR A DERECHA. MENOR A IZQUIERDA.

int insertarEnArbolDeBusqueda(t_arbol *raiz, t_dato *d,int (*cmp)(const void*,const void*))
{
    t_nodo *nue;

    if(!*raiz)
    {
        nue=(t_nodo*)malloc(sizeof(t_nodo));///PUEDE SER EL NUE EL *RAIZ
        if(!nue)
            return FALSE;

        nue->dato=*d;
        nue->der=nue->izq=NULL;
        *raiz=nue;
        return TRUE;
    }

    if(cmp(&(*raiz)->dato,d)>0)
        return insertarEnArbolDeBusqueda(&(*raiz)->izq,d,cmp);
    if(cmp(&(*raiz)->dato,d)<0)
        return insertarEnArbolDeBusqueda(&(*raiz)->der,d,cmp);
    return CLAVE_DUPLICADA;
}

///ITERATIVO

int insertar_en_arbol_de_busqueda(t_arbol *pa, const t_dato *d, int (*cmp)(const void*,const void*))
{
    while(*pa)
    {
        if(cmp(d,&(*pa)->dato)>0)
            pa=&(*pa)->der;
        else
        {
            if(cmp(d,&(*pa)->dato)<0)
                pa=&(*pa)->izq;
            else
                return CLAVE_DUPLICADA;
        }

    }
    (*pa)=(t_nodo*)malloc(sizeof(t_nodo));
    if(!*pa)
        return FALSE;

    (*pa)->dato=*d;
    (*pa)->der=(*pa)->izq=NULL;
    return TRUE;
}


void GuardarInOrden(t_arbol *raiz,FILE** pf)
{
    if(*raiz)
    {
        GuardarInOrden(&(*raiz)->izq,pf);
        fwrite(&(*raiz)->dato, sizeof(t_dato),1, *pf);
        GuardarInOrden(&(*raiz)->der,pf);
    }
}

void GuardarPreOrden(t_arbol *raiz,FILE** pf)
{
    if(*raiz)
    {
        fwrite(&(*raiz)->dato, sizeof(t_dato),1, *pf);
        GuardarPreOrden(&(*raiz)->izq,pf);
        GuardarPreOrden(&(*raiz)->der,pf);
    }
}

void GuardarPosOrden(t_arbol *raiz,FILE** pf)
{
    if(*raiz)
    {
        GuardarPosOrden(&(*raiz)->izq,pf);
        GuardarPosOrden(&(*raiz)->der,pf);
        fwrite(&(*raiz)->dato, sizeof(t_dato),1, *pf);
    }
}

t_nodo* BuscarNodoPadreEnArbolDeBusqueda(t_arbol *raiz, t_dato *d,int (*cmp)(const void*,const void*))
{

    if(!*raiz)
        return NULL;
    if(((*raiz)->izq && cmp(&(*raiz)->izq->dato,d)==0) || ((*raiz)->der && cmp(&(*raiz)->der->dato,d)==0))
        return *raiz;

    if(cmp(&(*raiz)->dato,d)>0)
        return BuscarNodoPadreEnArbolDeBusqueda(&(*raiz)->izq,d,cmp);
    if(cmp(&(*raiz)->dato,d)<0)
        return BuscarNodoPadreEnArbolDeBusqueda(&(*raiz)->der,d,cmp);
    return NULL;
}

int contarNodos(t_arbol *raiz)
{
    if(*raiz)
        return contarNodos(&(*raiz)->der)+contarNodos(&(*raiz)->izq)+1;

    return 0;
}

int contarHojas(t_arbol *raiz)
{
    if(!*raiz)
        return 0;
    if(!(*raiz)->izq && !(*raiz)->der)
        return 1;

    return contarHojas(&(*raiz)->izq)+contarHojas(&(*raiz)->der);
}

int mostrarContarHojas(t_arbol *raiz)
{

    if(!*raiz)
        return 0;
    if(!(*raiz)->izq && !(*raiz)->der)
    {
        printf("HOJA: %d\n",(*raiz)->dato.x);
        return 1;
    }

    return mostrarContarHojas(&(*raiz)->izq)+mostrarContarHojas(&(*raiz)->der);
}

int contarMostrarNoHojas(t_arbol *raiz)
{

    if(!*raiz)
        return 0;

    if(!(*raiz)->izq && !(*raiz)->der)
        return 0;

    printf("NO HOJA: %d\n",(*raiz)->dato.x);
    return contarMostrarNoHojas(&(*raiz)->izq)+contarMostrarNoHojas(&(*raiz)->der)+1;
}

int contarSoloNoHojas(t_arbol *raiz)
{
    if(!*raiz)
        return 0;

    if((*raiz)->izq || (*raiz)->der)
        return contarSoloNoHojas(&(*raiz)->izq)+contarSoloNoHojas(&(*raiz)->der)+1;

    return 0;
}

/*int contarSoloNoHojas(t_arbol *raiz)
{
    if(!*raiz)
        return 0;
    if(!(*raiz)->izq && !(*raiz)->der)
        return 0;

    return contarSoloNoHojas(&(*raiz)->izq)+contarSoloNoHojas(&(*raiz)->der)+1;
}VERSION MAXI*/

int contarMostrarNodosDeNivel(t_arbol *raiz,int nivel)
{
    if(*raiz)
    {
        if(nivel)
            return contarMostrarNodosDeNivel(&(*raiz)->izq,nivel-1)+contarMostrarNodosDeNivel(&(*raiz)->der,nivel-1);

        printf("NODO: %d\n",(*raiz)->dato.x);
        return 1;
    }
    return 0;
}

int contarNodosAnterioresANivel(t_arbol *raiz,int nivel)
{
    if(*raiz)
    {
        if(nivel)
        {
            printf("NODO: %d\n",(*raiz)->dato.x);
            return contarNodosAnterioresANivel(&(*raiz)->izq,nivel-1)+contarNodosAnterioresANivel(&(*raiz)->der,nivel-1)+1;
        }

        printf("NODO: %d\n",(*raiz)->dato.x);
        return 1;
    }

    return 0;
}

//CONTAR NODO A PARTIR DE UN NIVEL. EN CASA.

int CortarHojas(t_arbol *raiz)
{

    if(!*raiz)
        return 0;
    if(!(*raiz)->izq  && !(*raiz)->der)
    {
        free(*raiz);
        *raiz=NULL;
        return 1;
    }

    return CortarHojas(&(*raiz)->izq)+CortarHojas(&(*raiz)->der);
}


void  borrarArbol(t_arbol *raiz)
{
    if(*raiz)
    {
        borrarArbol(&(*raiz)->izq);
        borrarArbol(&(*raiz)->der);
        free(*raiz);
        *raiz=NULL;
    }

}

int contarMostrarHijosPorIzquierda(t_arbol *raiz)
{
    if(!*raiz)
        return 0;
    if(!(*raiz)->izq)
        return 0;
    printf("%d\n",(*raiz)->dato.x);
    return contarMostrarHijosPorIzquierda(&(*raiz)->izq)+contarMostrarHijosPorIzquierda(&(*raiz)->der)+1;
}

int contarMostrarHijosPorDerecha(t_arbol *raiz)
{
    if(!*raiz)
        return 0;
    if(!(*raiz)->der)
        return 0;
    printf("%d\n",(*raiz)->dato.x);
    return contarMostrarHijosPorDerecha(&(*raiz)->izq)+contarMostrarHijosPorDerecha(&(*raiz)->der)+1;
}

void PodarNivel(t_arbol *raiz,int nivel,void(*borrar)(t_arbol *))
{
    if(*raiz)
    {
        if(!nivel)
        {
            borrar(raiz);
            return;
        }
        PodarNivel(&(*raiz)->izq,nivel-1,borrar);
        PodarNivel(&(*raiz)->der,nivel-1,borrar);
    }
    return;
}

int alturaArbol(t_arbol* raiz)
{
    int i,j;
    if(!*raiz)
        return 0;
    i=alturaArbol(&(*raiz)->izq);
    j=alturaArbol(&(*raiz)->der);
    return i>j?i+1:j+1;
}

t_nodo* BuscarNodoMayorPadreEnArbolDeBusqueda(t_arbol *raiz, t_dato *d,int (*cmp)(const void*,const void*))
{

    if(!*raiz)
        return NULL;
    if(!(*raiz)->izq)

    if(cmp(&(*raiz)->dato,d)>0)
        return BuscarNodoPadreEnArbolDeBusqueda(&(*raiz)->izq,d,cmp);
    if(cmp(&(*raiz)->dato,d)<0)
        return BuscarNodoPadreEnArbolDeBusqueda(&(*raiz)->der,d,cmp);
    return NULL;
}

t_arbol* buscarMayor(t_arbol* raiz)
{

    if(!*raiz)
        return NULL;
    if((*raiz)->der)//while
        return buscarMayor(raiz);//a=&(*a)->der

    return raiz;
}

t_arbol* buscarMenor(t_arbol* raiz)
{

    if(!*raiz)
        return NULL;
    if((*raiz)->izq)
        return buscarMenor(raiz);

    return raiz;
}

t_arbol* buscarDevolverPos(t_arbol *raiz, const t_dato *d, int(*cmp)(const void*, const void*))
{
    int comparacion;
    while(*raiz)
    {
        if((comparacion=cmp((&(*raiz)->dato),d))>0)
            raiz=&(*raiz)->izq;
        else
        {
            if(comparacion<0)
                raiz=&(*raiz)->der;
            else
                return raiz;
        }
    }
    return NULL;
}

int eliminarNodo(t_arbol *raiz,t_dato *d,int(*cmp)(const void*, const void*))
{
    int hi,hd;
    t_nodo** remp;
    raiz=buscarDevolverPos(raiz,d,cmp);
    if(!raiz)
        return 0;//NO ENCONTRADO
    *d=(*raiz)->dato;//DEVUELVE INFO DEL DATO QUE ELIMINO

    while((*raiz)->izq || (*raiz)->der)
    {
        hi=alturaArbol(&(*raiz)->izq);
        hd=alturaArbol(&(*raiz)->der);
        if(hi<hd)
            remp=buscarMenor(&(*raiz)->der);
        else
            remp=buscarMayor(&(*raiz)->izq);
        (*raiz)->dato=(*remp)->dato;
        raiz=remp;
    }

    free(*raiz);
    *raiz=NULL;
    return 1;
}

int buscarMayorNoClave(t_arbol* a)
{
    if(!*a)
        return 0;
    if(mayor<(*a)->dato.nroReg)

}
