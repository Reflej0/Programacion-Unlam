#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct
{
    int nro_pedido;
    char nro_articulo[11];
    int cantidad_pedida;
    float precio_unitario;
} T_pedido;

typedef struct
{
    int nro_pedido;
    int cant_pedida_total;
    float precio_total;
}

#endif // HEADER_H_INCLUDED
