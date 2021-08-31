#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

struct no
{
    Bebida bebida;
    struct no * prox;
};

Lista cria_lista ()
{
    return NULL;
}

int lista_vazia (Lista lst)
{
    if (lst == NULL)
        return 1;
    
    else 
        return 0;
}

int insere_final (Lista *lst, Bebida bbd)
{
    Lista N = (Lista) malloc(sizeof(struct no));
    
    if (N == NULL)
    {
        return 0;
    }

    N -> bebida = bbd;

    if (lista_vazia(*lst) == 1)
    {
        N -> prox = N;
        *lst = N;
    }

    else
    {
        N -> prox = (*lst) -> prox;
        (*lst) -> prox = N;
        *lst = N;
    }

    return 1;
}

int remove_ini (Lista *lst, Bebida *bbd)
{
    if (lista_vazia(*lst) == 1)
        return 0;
    
    Lista aux = (*lst) -> prox;
    *bbd = aux -> bebida;

    if (*lst == (*lst) -> prox)
        *lst = NULL;

    else 
        (*lst) -> prox = aux -> prox;

    free(aux);
    return 1;
}

int apaga_lista (Lista *lst)
{
    esvazia_lista (lst);
    free (*lst);
}

int esvazia_lista (Lista *lst)
{
    if (lista_vazia (*lst) == 1)
        return 0;
    
    if (*lst == NULL)
        return 1;

    Lista aux = *lst;
    Lista aux2;

    while (1)
    {
        if (aux -> prox == NULL)
        {
            free(aux);
            *lst = NULL;
            break;
        }

        while (aux -> prox -> prox != NULL)
            aux = aux -> prox;

        aux2 = aux -> prox;
        aux -> prox = NULL;
        free (aux2);
        aux = *lst;
    }
}

int get_elem_pos (Lista lst, int indice, Bebida *bbd)
{
    if(indice < 0 || lista_vazia(lst))
        return 0;

    Lista aux = lst -> prox;

    while (indice > 0 && aux->prox != lst -> prox) 
    {
        aux = aux->prox;
        indice--;
    }

    if (!indice) 
    {
        *bbd = aux -> bebida;
        return 1;
    }

    return 0;
}
