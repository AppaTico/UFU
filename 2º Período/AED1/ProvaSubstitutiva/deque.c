#include <stdlib.h>
#include "deque.h"
//max_c ta definido em deque.h

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

int inserir_inicio (Deque d, char elem[max_c])
{
    if (d == NULL)
        return 0;

    struct no * N;
    N = (struct no *) malloc(sizeof(struct no));

    if (N == NULL)
        return 0;

    N -> string[max_c] = elem[max_c];

    N -> ant = d -> fim;
    N -> prox = d -> ini;
    
    (d -> ini) -> ant = N;
    d -> ini = N;

    return 1;
}

int inserir_final (Deque d, char elem[max_c])
{   
    if (d == NULL)
        return 0;

    struct no * N;
    N = (struct no *) malloc(sizeof(struct no));

    if (N == NULL)
        return 0; 

    N -> string[max_c] = elem[max_c];

    N -> prox = d -> ini;
    N -> ant = d -> fim;

    (d -> fim) -> prox = N;
    d -> fim = N;

    return 1;
}

int remover_inicio (Deque d, char *elem[max_c])
{
    if (deque_vazio(d) == 1 || d == NULL)
        return 0;
    
    if (d -> ini == d -> fim) //tratamento especial: deque com somente um nó
    {
        struct no * P = d -> ini;
        *elem[max_c] = P -> string[max_c];

        d -> ini = NULL;
        d -> fim = NULL;

        free (P);

        return 1;
    }

    struct no * P = d -> ini;
    *elem[max_c] = P -> string[max_c];

    d -> ini = P -> prox;
    (d -> ini) -> ant = d -> fim;

    free (P);
    
    return 1;
}

int remover_final (Deque d, char *elem[max_c])
{
    if (deque_vazio(d) == 1 || d == NULL)
        return 0;

    if (d -> ini == d -> fim) //tratamento especial: deque com somente um nó
    {
        struct no * P = d -> fim;
        elem = P -> string[max_c];

        d -> ini = NULL;
        d -> fim = NULL;

        free (P);

        return 1;
    }

    struct no * P = d -> fim;
    *elem[max_c] = P -> string[max_c];

    d -> fim = P -> ant;
    (d -> fim) -> prox = d -> ini;

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
        remover_inicio(d, esvaziando);
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