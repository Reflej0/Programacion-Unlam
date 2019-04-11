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

void crearLista(t_lista*p,t_lista*t);

void cargarInfo(t_info*d);

int insertarAlPrincipio(t_lista*p,t_lista*t,t_info*d);
int recorrerDesdePrincipio(t_lista*p,t_lista*t);
int insertarAlFinal(t_lista*p,t_lista*t,t_info*d);
int vaciarLista(t_lista*p,t_lista*t);



#endif // HEADER_H_INCLUDED
