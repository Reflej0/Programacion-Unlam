#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct{

    int clave;
    char nom[50];

}t_persona;

typedef struct{

    int clave;
    long pos;
}t_dat_indice;

typedef struct s_nodo{

    t_dat_indice t_dat_indice;
    struct s_nodo*sig;

}t_nodo;

typedef t_nodo* t_lista;

typedef struct{

    t_lista lista_indice;
    t_nodo*inicio;
    t_nodo*actual;
    int fin; //indica si estoy en el finald el indice con 1 o sino con 0
}t_indice;

typedef int(*t_cmp)(void*a,void*b);

int abrir_arch(char*nom,char*modo,FILE**pf);

void cargar_bin(char*nom,FILE**pf);

void mostrar_bin(char*nom,FILE**pf);

///-----------de indice--------------

void cargar_indice(char*nom,FILE**pf,t_indice*indi,t_cmp cmp);

void mostrar_indice_desde_principio(t_indice*indi);

void mostrar_dato_clave(char*nom,FILE**pf,t_indice*indi,int clave);

///---------de lista--------------

int cmp(void*a,void*b);

void insertar_en_lista(t_lista*l,t_dat_indice*d);

void insertar_lista_logica(t_lista*l,t_nodo*nodo_agr);

void sacar_lista_logica(t_lista*l,t_nodo*nodo_sac);

t_lista* ordenar_lista(t_lista*l,t_cmp cmp);


#endif // HEADER_H_INCLUDED
