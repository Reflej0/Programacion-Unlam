#include <stdio.h>
#include <stdlib.h>
#define ES_ALFANUMERICO(c) ((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) ? 1 : 0
#define ES_ESPACIO(c) (c==' ') ? 1 : 0

///La función elimina los espacios al final de una cadena y devuelve
int eliminar_espacios_al_final(char* cad)
{
    int espacios_al_final = 0;
    ///Avanzo hasta el final de la cadena.
    while(*cad)
    {
        cad++;
    }
    //Voy hasta el último caracter válido de la cadena.
    cad--;
    //Recorro la cadena desde la ultima posicion.
    while(ES_ESPACIO(*cad))
    {
        espacios_al_final++;
        cad--;
    }
    //Cad antes del ++ esta apuntando al caracter atras de espacio.
    cad++;
    *cad = '\0';
    return espacios_al_final;
}

///La función elimina los espacios adelantes de una cadena y devuelve el número de espacios eliminados.
int eliminar_espacios_al_principio(char* cad)
{
    //Variable auxiliar que contiene los espacios eliminados.
    ///Si el primer caracter es un espacio ya tengo que desplazar los demas caracteres.
    if(ES_ESPACIO(*cad))
    {
        char* aux = cad;
        int espacios_adelante = 0;
        while(*aux && ES_ESPACIO(*aux))
        {
            aux++;
            espacios_adelante++;
        }
        while(*aux)
        {
            *cad = *aux;
            cad++;
            aux++;
        }
        return espacios_adelante;
    }
    ///Si el primer caracter no es un espacio ya es valido.
    else
    {
        return 0;
    }
}

///Normalizar la cadena bajo el criterio de permitir solo caracteres alfanumericos.
void normalizar_cadena(char* cad)
{
    char* aux = cad;
    while(*aux)
    {
        if(ES_ALFANUMERICO(*aux) || ES_ESPACIO((*aux)))
        {
               *cad = *aux;
               cad++;
        }
        aux++;
    }
    *cad = '\0';
}


int main()
{
    ///Lotes de pruebas.
    char cad[] = "   *coDigO ileGib1blE#$% ";
    char cad2[] = "Cadena correcta.";
    char cad3[] = " Especie exotica ";
    char solo_espacios[] = "         ";
    char nada[] = "";
    int espacios_eliminados_adelante = eliminar_espacios_al_principio(cad);
    int espacios_eliminados_al_final = eliminar_espacios_al_final(cad);
    normalizar_cadena(cad);
    printf("%s", cad);
}
