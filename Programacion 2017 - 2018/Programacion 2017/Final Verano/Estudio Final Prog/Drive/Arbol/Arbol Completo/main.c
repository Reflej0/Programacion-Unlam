#include"EstructArbol.h"

int main()
{
    t_dato info[]={{30},{15},{40},{4},{20},{2},{18},{25},{50},{19}},
            reg,
            aux={15};
    int i;
    t_arbol arbol;
    FILE* preorden;

    preorden=fopen("ArbolEnPreOrden","wb");
    if(!preorden)
        exit(1);

    crearArbol(&arbol);
    for(i=0;i<10;i++)
        insertarEnArbolDeBusqueda(&arbol,&(info[i]),comparar);

    GuardarPreOrden(&arbol,&preorden);

    fclose(preorden);

    preorden=fopen("ArbolEnPreOrden","rb");
    fread(&reg,sizeof(t_dato),1,preorden);
    while(!feof(preorden))
    {
        insertarEnArbolDeBusqueda(&arbol,&reg,comparar);
        fread(&reg,sizeof(t_dato),1,preorden);
    }

    //BuscarNodoPadreEnArbolDeBusqueda(&arbol,&aux,comparar);
    //printf("%d\n",BuscarNodoPadreEnArbolDeBusqueda(&arbol,&aux,comparar)->dato);//siempre que le mande algo
    mostrarPosOrden(&arbol);                                                                            //encontrable que no sea raiz(comprobacion)
    //printf("Altura:%d\n",alturaArbol(&arbol));

    fclose(preorden);
    return 0;
}
