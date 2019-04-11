#include <stdio.h>
#include <stdlib.h>
#include "indice.h"
#include "def.h"
#include "lista.h"


int main()
{
   T_indice indice;
   ind_crear(&indice);
   T_dato registro;
   registro.dni = 12345678;
   registro.nro_reg = 1;
   ind_insertar(&indice, &registro);
}
