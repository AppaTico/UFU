#include <stdio.h>
#include <stdlib.h>
#include "rec.h"

struct no 
{
    double info;
    Lista prox;
};

Lista cria_lista ()
{
    return NULL;
}

int lista_vazia (Lista lst)
{
    return lst == NULL;
}

int insere_ord (Lista *lst, int elem)
{
    if (lista_vazia (*lst) || elem <= (*lst) -> info)
    {
        Lista N = (Lista) malloc(sizeof(struct no));

        if (N == NULL)
            return 0;
        
        N -> info = elem;
        N -> prox = *lst;
        *lst = N;

        return 1;
    }

    return insere_ord (&((*lst) -> prox), elem);
}

int remove_ord (Lista *lst, int elem)
{
    if (lista_vazia (*lst) || elem < (*lst) -> info)
        return 0;

    if (elem == (*lst) -> info)
    {
        Lista aux = (*lst) -> prox;
        (*lst) -> prox = aux -> prox;
        free (aux);

        return 1;
    }

    return remove_ord (&((*lst) -> prox), elem);
}

int apaga_lista (Lista *lst)
{
    esvazia_lista (lst);
    free (*lst);
}

int esvazia_lista (Lista *lst)
{
    if (lista_vazia (*lst))
    {
        return 0;
    }

    else
    {
        Lista aux = (*lst) -> prox;
        free (aux);
    }
}

int get_elem_pos (Lista lst, int pos, int *var)
{
    if (lista_vazia (lst) || pos < 0)
        return 0;

    if (pos == 0)
    {
        *var = lst -> info;
        return 1;
    }

    return get_elem_pos (lst -> prox, pos--, var);
}
