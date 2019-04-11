#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#define TAM 5

typedef char* T_dato;

typedef struct
{
	T_dato vcola[TAM];
	int frente;
	int fondo;
	int ce;
}
T_cola;



void crear_cola(T_cola* pcola);
int poner_en_cola(T_cola* pcola, const T_dato* pd);
int sacar_de_cola(T_cola* pcola, T_dato* pd);
int frente_de_cola(const T_cola* pcola, T_dato* pd);
int cola_vacia(const T_cola* pcola);
int cola_llena(const T_cola* pcola);
void vaciar_cola(T_cola* pcola);

#endif // COLA_H_INCLUDED
