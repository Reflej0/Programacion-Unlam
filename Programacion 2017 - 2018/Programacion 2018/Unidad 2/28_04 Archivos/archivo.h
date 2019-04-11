#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

///LECTURA DE ARCHIVOS.

int leer_txt_fijo(char* dir);

int leer_txt_variable(char* dir);

int leer_bin(char* dir);

///CONVERSIONES DE ARCHIVOS.

int txt_variable_a_bin(char* dirtxt, char* dirbin);

int txt_fijo_a_bin(char* dirtxt, char* dirbin);

int bin_a_txt_variable(char* dirbin, char* dirtxt);

int bin_a_txt_fijo(char* dirbin, char* dirtxt);

#endif // ARCHIVO_H_INCLUDED
