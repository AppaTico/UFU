#include <stdlib.h>
#include "deque.h"

struct no
{
    int info;
    struct no * prox, * ant;
};

struct deque
{
    struct no * ini;
    struct no * fim;
};

Deque cria_deque ()
{
    Deque d;
    d = (Deque) malloc(sizeof(struct deque));

    if (d != NULL)
    {
        d -> ini = NULL;
        d -> fim = NULL;
    }

    return d;
}

int deque_vazio (Deque d)
{
    if (d -> ini == NULL)
        return 1;
    else
        return 0;
}

int inserir_início (Deque d, int elem)
{
    if (d == NULL)
        return 0;

    struct no * N;
    N = (struct no *) malloc(sizeof(struct no));

    if (N == NULL)
        return 0;

    N -> info = elem;

    N -> ant = NULL;
    N -> prox = d -> ini;
    
    (d -> ini) -> ant = N;
    d -> ini = N;

    return 1;
}

int inserir_final (Deque d, int elem)
{   
    if (d == NULL)
        return 0;

    struct no * N;
    N = (struct no *) malloc(sizeof(struct no));

    if (N == NULL)
        return 0; 

    N -> info = elem;

    N -> prox = NULL;
    N -> ant = d -> fim;

    (d -> fim) -> prox = N;
    d -> fim = N;

    return 1;
}

int remover_início (Deque d, int *elem)
{
    if (deque_vazio(d) == 1 || d == NULL)
        return 0;
    
    if (d -> ini == d -> fim) //tratamento especial: deque com somente um nó
    {
        struct no * P = d -> ini;
        *elem = P -> info;

        d -> ini = NULL;
        d -> fim = NULL;

        free (P);

        return 1;
    }

    struct no * P = d -> ini;
    *elem = P -> info;

    d -> ini = P -> prox;
    (d -> ini) -> ant = NULL;

    free (P);
    
    return 1;
}

int remover_final (Deque d, int *elem)
{
    if (deque_vazio(d) == 1 || d == NULL)
        return 0;

    if (d -> ini == d -> fim) //tratamento especial: deque com somente um nó
    {
        struct no * P = d -> fim;
        *elem = P -> info;

        d -> ini = NULL;
        d -> fim = NULL;

        free (P);

        return 1;
    }

    struct no * P = d -> fim;
    *elem = P -> info;

    d -> fim = P -> ant;
    (d -> fim) -> prox = NULL;

    free (P);

    return 1;
}

int esvazia_deque (Deque d)
{
    if (deque_vazio (d) == 1 || d == NULL)
        return 0;

    int * esvaziando;

    while (d -> ini != NULL)
    {
        remover_início(d, &esvaziando);
        free (esvaziando);
        esvaziando = NULL;
    }

    return 1;
}

int apaga_deque (Deque *d)
{
    esvazia_deque(d);
    free (*d);
    *d = NULL;

    return 1;
}