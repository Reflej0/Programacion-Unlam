
#include "funciones.h"



/** dupliCadena
 ** argumentos :  s (E)
 ** devuelve   :  direcci�n de memoria en que gener� la copia din�mica o
 **                 NULL en caso de que no haya memoria o reciba una cadena
 **                 vac�a o NULL
 ** atenci�n   :  dado que new produce una excepci�n en caso de que no haya
 **                 memoria disponible, se atrapa esta posible excepci�n
 **                 para devolver NULL y no generar la copia din�mica
 **               en este caso se podr�a lanzar una excepci�n pero preferimos
 **                 hacer una versi�n parecida a strdup pero obteniendo memoria
 **                 con new
 ** note que   :  si new falla por falta de memoria, la asignaci�n a aux
 **                  no se hace (y tampoco el strcpy), y el control de
 **                  ejecuci�n lo toma el catch que no hace nada, porque
 **                  se devuelve NULL al final de la funci�n
 */
char *dupliCadena(const char *s)
{
    if(s && *s)
    {
        try {
            char *aux = new char[strlen(s) + 1];
            return strcpy(aux, s);
        } catch (std::bad_alloc &) {
            // throw 1;  //SIN_MEMORIA en dupliCadena
            // cerr << "ERROR: Sin Memoria en dupliCadena." << endl;
            // MEJOR, SI HAY ERRORES, LANZAR LAS EXCEPCIONES EN EL
            //    M�TODO QUE CORRESPONDA (O EMITIR MENSAJE DE ERROR)
        }
    }
    return NULL;
}


/** concatCadena
 ** argumentos :  s1 (E)
 **               s2 (E)
 ** devuelve   :  direcci�n de memoria en que gener� una cadena con
 **                  asignaci�n din�mica o NULL en caso de que no haya
 **                  memoria o s1 y s2 sean cadenas vac�as o NULL
 ** atenci�n   :  dado que new produce una excepci�n en caso de que no haya
 **                  memoria disponible, se atrapa esta posible excepci�n
 **                  para devolver NULL y no generar la copia din�mica
 **               en este caso se podr�a lanzar una excepci�n a ser
 **                  atrapada por quien invoca a concatCadena, pero preferimos
 **                  seguir con lo hecho en dupliCadena
 ** note que   :  si new falla por falta de memoria, la asignaci�n a aux
 **                  no se hace (y tampoco la concatenaci�n), y el control
 **                  de ejecuci�n lo toma el catch que no hace nada, porque
 **                  se devuelve NULL al final de la funci�n
 */
char *concatCadena(const char *s1, const char *s2)
{
    size_t  tam1 = s1 && *s1 ? strlen(s1) : 0,
            tam2 = s2 && *s2 ? strlen(s2) : 0;
    if(tam1 || tam2)
    {
        try {
            char *aux = new char[tam1 + tam2 + 1];
            if(tam1)
                strcpy(aux, s1);
            if(tam2)
                strcpy(aux + tam1, s2);
            return aux;
        } catch (std::bad_alloc &) {
         // throw 2;  //SIN_MEMORIA en concatCadena
         // cerr << "ERROR: Sin Memoria en concatCadena." << endl;
         // MEJOR, SI HAY ERRORES, LANZAR LAS EXCEPCIONES EN EL
         //    M�TODO QUE CORRESPONDA (O EMITIR MENSAJE DE ERROR)
        }
    }
    return NULL;
}

