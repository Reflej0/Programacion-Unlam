#include <Arbol.h>



void recorrer_arbol_pre(const t_arbol* pa, t_accion accion, void* datos_accion)
{
    t_arbol aux;
    aux=*pa;
	if(*pa)
        puts("arbol vacio");
    while (aux->pder==NULL && aux->pizq==NULL)

        return recorrer_arbol_pre(&(*pa)->pder,accion(&(*pa)->info,&datos_accion)
}



int eliminar_de_arbol(t_arbol* pa, t_dato* pd, t_cmp cmp)
{
	///Inserte el código acá
}
