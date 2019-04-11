
#include "listaDoble.h"

int main()
{
    t_info info={"MATVI","Martillo de Vidrio",30.000,"Unidades"};
    t_info info2={"CARRAM","Caramelos Amargos",18.000,"Unidades"};
    t_info info3={"CARRAM","Caramelos Amargos",28.000,"Unidades"};
    t_info info4={"MATVI","Martillo de Vidrio",28.000,"Unidades"};
    t_lista lista;
    crearLista(&lista);
    insertarEnListaDesordenada(&lista,&info);
    insertarEnListaDesordenada(&lista,&info2);
    insertarEnListaDesordenada(&lista,&info2);
    insertarEnListaDesordenada(&lista,&info2);
    insertarEnListaDesordenada(&lista,&info3);
    ordinsertarEnListaDesordenada(&lista,&info4);
    recorrerLista(&lista);
    eliminarDuplicados(&lista);
    recorrerLista(&lista);
    return 0;
}
