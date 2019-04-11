#ifndef INFO_H
#define INFO_H

typedef struct
{
   char  clave[7];
   float canti;
   float precio;
   int   nroReg;
} t_noved;

typedef struct
{
   char  descrip[21];
   char  clave[7];
   float exist;
   char  uniMed[4];
   float precio;
} t_exist;

void mostrarExist(const t_exist *d);

void mostrarNoved(const t_noved *d);

#endif // INFO_H#define
