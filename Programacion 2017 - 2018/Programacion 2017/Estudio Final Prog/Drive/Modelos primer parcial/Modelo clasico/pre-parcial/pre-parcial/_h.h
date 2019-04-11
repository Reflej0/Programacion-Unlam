#ifndef _H_INCLUDED
#define _H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ESNUMERO(x) (x>='0' && x<='9')?1:0
#define ESLETRA(x) ((x>='A' && x<='Z')||(x>='a' && x<='z'))?1:0
#define A_MAYUSCULA(x) (x>='a' && x<='z'?x+'A'-'a':x)
#define ARCHIVO_A_ESCRIBIR(x,z,w) (x<1000)?z:w
typedef struct
{
    char ncuenta[9];
    char mov;
    float importe;
}t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_lista;

int sacarS2deS1(char* s1, const char* s2);
int CuentaValida(const char* ncuenta);
int s2Ens1(const char* s1, const char* s2);

int EliminarPrimerElemento(t_lista* lista,t_dato* reg);
int listaVacia(t_lista* lista);
int insertarEnListaOrdenado(t_lista* lista,t_dato* reg,int (*cmp)(void* e1,void* e2));
void crearLista(t_lista* lista);
int listaLLena(t_lista* lista);

int cmpNom(t_dato* aux,t_dato* reg);
int cmp(void* e1,void* e2);

#endif // _H_INCLUDED
