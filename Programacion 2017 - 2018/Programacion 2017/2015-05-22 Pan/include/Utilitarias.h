#ifndef UTILITARIAS_H
#define UTILITARIAS_H


void generar_archivo_pedidos_entradas();
void generar_archivo_entradas();

void generar_archivo_socios_club_a();
void generar_archivo_socios_club_b();

void mostrar_arch_socios_entradas(FILE* arch_socios_entradas);
void mostrar_arch_socios_a(FILE* arch_socios_a);
void mostrar_arch_socios_b(FILE* arch_socios_b);
void mostrar_arch_pedidos_entradas(FILE* arch_pedidos_entradas);
void mostrar_pedido_entrada(t_pedido_entrada* pedido_entrada);
void mostrar_arch_entradas(FILE* arch_entradas);


#endif // UTILITARIAS_H
