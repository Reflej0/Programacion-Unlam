#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "biblioteca.h"
#include "lista.h"
#define TAM 31


int main()
{
   FILE       *fpExist,
              *fpNoved;
   t_lista     lista;
   int         cant;

   crearArchivos();       /* crea el lote de prueba  */

   crearLista(&lista);
   if(!abrirArchivo(&fpExist, EXIST, MODO_1, CONMSJ))
      return 1;

   leerYMostrarExist(fpExist); /* muestra el contenido del archivo */
   if(!abrirArchivo(&fpNoved, NOVED, MODO_2, CONMSJ))
   {
      fclose(fpExist);
      return 2;
   }
   /* función a crear que leyendo el archivo de texto de novedades genere
    *    una lista simplemente enlazada insertando al final de la misma
    */
   cant = leerArchivoYCargarLista(fpNoved, &lista);
   ///cant = leerArchivoYCargarLista_2(fpNoved, &lista);
   if(cant)
      printf("Se insertaron %d nodos en la lista\n", cant);
   else
   {
      fclose(fpExist);
      fclose(fpNoved);
      vaciarLista(&lista);
      return 4;
   }
   printf("La lista tiene %d nodos cargados\n",
          mostrarLista(&lista));
   /* función a crear que elimine los nodos duplicados de una lista no ordenada
    *    acumulando en el nodo que da origen a la duplicación
    */
    ///cant = eliminarDuplicados(&lista);
   cant = eliminarDuplicados_2(&lista);
   printf("Se eliminaron %d nodos\n", cant);
   printf("La lista queda con %d nodos\n",
          mostrarLista(&lista));
   /* función a crear que recuperando los nodos del comienzo de una lista
    *    actualiza el archivo
    */
   ///cant = sacarDeListaYActualizarArchivo(fpExist, &lista);
   cant = sacarDeListaYActualizarArchivo_2(fpExist, &lista);
   printf("Se actualizaron %d registros\n", cant);
   leerYMostrarExist(fpExist); /* muestra el contenido del archivo modificado */
   return 0;
}

