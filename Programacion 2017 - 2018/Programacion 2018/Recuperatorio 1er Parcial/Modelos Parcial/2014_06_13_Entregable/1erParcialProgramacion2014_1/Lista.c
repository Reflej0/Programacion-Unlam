#include <Lista.h>



void crear_lista(t_lista* plista)
{
	*plista = NULL;
}

int lista_actualizar_insertar(t_lista * plista, const t_dato * pd, t_cmp cmp, t_actualizar actualizar)
{
    t_nodo * pn;

    while (*plista && cmp(pd, &(*plista)->info) > 0)
        plista = &(*plista)->psig;

    if (*plista && cmp(pd, &(*plista)->info) == 0) {
        actualizar(&(*plista)->info, pd);
        return TODO_OK;
    } else {
        pn = (t_nodo *) malloc(sizeof(t_nodo));

        if (!pn)
            return ERROR_SIN_MEMORIA;

        pn->psig = *plista;
        *plista = pn;
        pn->info = *pd;

        return TODO_OK;
    }
}

int lista_sacar_primero(t_lista * plista, t_dato * pd)
{
    t_nodo * nodo_elim;

    if (*plista == NULL)
        return 0;

    nodo_elim = (*plista);
    *pd = (*plista)->info;
    *plista = (*plista)->psig;

    free(nodo_elim);

    return TODO_OK;
}
