#ifndef PARAMETROS_H_INCLUDED
#define PARAMETROS_H_INCLUDED

typedef struct
{
    int dni;
}t_info;

typedef struct s_nodo
{
    struct s_nodo* izq;
    void* info;
    struct s_nodo* der;
}t_nodo;

typedef t_nodo* t_arbol;

int insertarEnArbol(t_arbol* p,void* d,int tam,int (*cmp)(const void*,const void*));
void crearArbol(t_arbol* a);
int compararDni(const void* s1,const void* s2);
void vaciarArbol(t_arbol* p);
int alturaArbol(t_arbol* p);
int nivelArbol(t_arbol* p);
void* buscarMenor(t_arbol* p);
void* buscarMayor(t_arbol* p);
t_nodo** buscarNodoPadre(t_arbol* p,void* d,int (*cmp)(const void*,const void*));///guarda la direccion de la
                                                            ///parte de la estructura que apunta al nodo buscado


#endif // PARAMETROS_H_INCLUDED
