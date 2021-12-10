/*
O elemento com MENOR prioridade deve ser removido

2 abordagens: estrutra sem critério de ordenação e estrutura com critério de ordenação
*/

/*
Fila de prioridade ordenada:
- Inserção ordenada
    . Busca a posição adequada para o elemento de acordo com a sua prioridade (valor)
- Remoção no início (como na fila)

Demais operações básicas são idênticas às usadas para fila
*/

#include <stdlib.h>
#include "fpa.h"

struct no
{
    int info;
    struct no * prox;
};

struct fpa
{
    struct no * ini;
    struct no * fim;
};

/*
- Aloca uma estrutura fila
– Coloca a fila no estado de vazia
    • Inicializa os campos ini e fim com NULL
*/
Fpa cria_fpa ()
{
    Fpa f;
    f = (Fpa) malloc(sizeof(struct fpa));

    if (f != NULL)
    {
        f -> ini = NULL;
        f -> fim = NULL;
    }

    return f;
}

/*
- Verifica se a fila está no estado de vazia
    • Usa um dos campos (ini ou fim) e verifica se é NULL
*/
int fpa_vazia (Fpa f)
{
    if (f -> ini == NULL)
        return 1;
    else
        return 0;
}

int insere_ord (Fpa f, int elem)
{
    if(f == NULL)
        return 0;

    struct no * N = (struct no *)malloc(sizeof(struct no));

    if(N == NULL)
        return 0;

    N -> info = elem;

    if (fpa_vazia(f))
    {
        f -> ini = N;
        f -> fim = N;
        N -> prox = NULL;
        return 1;
    }

    if (elem > ((f -> ini) -> info))
    {
        N -> prox = f -> ini;
        f -> ini = N;

        return 1;
    }

    struct no * aux = f -> ini;

    while(aux -> prox != NULL && ((aux -> prox) -> info) > elem)
        aux = aux->prox;

    N -> prox = aux -> prox;
    aux -> prox = N;

    if(aux == f -> fim)
        f -> fim = N;

    return 1;    
}

int remove_ini(Fpa f, int* elem)
{
    if(f == NULL || fpa_vazia(f))
        return 0;

    struct no * aux = f -> ini;
    *elem = aux->info;

    if(f -> ini == f -> fim)
        f -> fim = NULL;

    f ->ini = aux -> prox;
    free(aux);
    
    return 1;
}

int esvazia_fpa (Fpa f)
{
    f -> ini = NULL;
    f -> fim = NULL;
    return 1;
}

int apaga_fpa (Fpa *f)
{
    esvazia_fila(f);
    free (*f);
    *f = NULL;

    return 1;
}