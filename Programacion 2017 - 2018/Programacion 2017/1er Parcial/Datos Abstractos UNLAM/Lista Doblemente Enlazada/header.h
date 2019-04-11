#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct{

    int num;
}t_info;

typedef struct s_nodo{

    t_info info;
    struct s_nodo* sig;
    struct s_nodo* ant;

}t_nodo;

typedef t_nodo* t_lista;

void crearLista(t_lista*p);

void cargarInfo(t_info*d);

int insertarAlPrincipio(t_lista*p,t_info*d);
int recorrerDesdePrincipio(t_lista*p);
int insertarAlFinal(t_lista*p,t_info*d);
int recorrerDesdeFinal(t_lista*p);



#endif // HEADER_H_INCLUDED
