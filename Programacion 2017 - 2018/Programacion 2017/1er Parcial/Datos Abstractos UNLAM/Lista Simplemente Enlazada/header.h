#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct{

    int num;
}t_info;

typedef struct s_nodo{

    t_info info;
    struct s_nodo* sig;

}t_nodo;

typedef t_nodo* t_lista;

void crearLista(t_lista*p);
int insertarAlPrincipio(t_lista*p);
int insertarAlFinal(t_lista*p);
int eliminardelista(t_lista*p);
void vaciarLista(t_lista*p);
int mostrarLista(t_lista*p);



#endif // HEADER_H_INCLUDED
