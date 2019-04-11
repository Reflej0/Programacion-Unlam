#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct{

    int num;
    int repe;
}t_info;

typedef struct s_nodo{

    t_info info;
    struct s_nodo* sig;

}t_nodo;

typedef t_nodo* t_lista;

void crearLista(t_lista*p);

void cargarInfo(t_info*d);

int insertarContandoRep(t_lista*p,t_info*d);
int eliminarRep(t_lista*p,t_info*d);

int compararMenoraMayor(void*a,void*b);

int insertarEnListaEnOrdenActualizar(t_lista*p,t_info*d,int (*cmp)(void*a,void*b));
int mostrarLista(t_lista*p);



#endif // HEADER_H_INCLUDED
