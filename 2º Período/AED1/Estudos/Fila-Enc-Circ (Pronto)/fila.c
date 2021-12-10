#include <stdlib.h>
#include "fila.h"

struct no
{
    int info;
    struct no * prox;
};

Fila cria_fila ()
{
    return NULL;
}

/*
- Verifica se a fila está no estado de vazia
*/
int fila_vazia (Fila f)
{
    if (f == NULL)
        return 1;
    else
        return 0;
}

int insere_fim (Fila *f, int elem)
{
    if (f == NULL)
        return 0;
           
    //aloca um novo no e preenche o campo info
    Fila N = (Fila) malloc(sizeof(struct no));

    if (N == NULL)
        return 0; //falha: no nao alocado

    N -> info = elem; //insere o conteudo

    //trata fila vazia
    if (fila_vazia (*f) == 1)
    {
        N -> prox = N; //faz o novo nó apontar para ele mesmo
        *f = N; //faz a fila apontar para o novo no (ultimo no)
    }
    else
    {
        N -> prox = (*f) -> prox; //faz o novo no apontar o primeiro no
        (*f) -> prox = N; //faz o ultimo no apontar para o novo no
        *f = N; //faz a fila apontar para o novo no (ultimo no)
    }

    return 1;
}

int remove_ini (Fila *f, int *elem)
{
    //trata fila vazia
    if (fila_vazia (*f) == 1 || f == NULL)
        return 0; //falha: nao ha nos para remover

    Fila aux = (*f) -> prox; //faz aux apontar para o primeiro no
    *elem = aux -> info; //retorna valor do nó a ser removido

    if (*f == (*f) -> prox) //trata fila com um unico nó
        *f = NULL;
    else //trata fila com + de um nó
        (*f) -> prox = aux -> prox;

    free (aux);
    
    return 1;
}

int esvazia_fila (Fila f)
{
    if (f == NULL)
        return 0;

    int * esvaziando;

    while (f != NULL)
    {
        remove_ini(f, &esvaziando);
        free (esvaziando);
        esvaziando = NULL;
    }

    return 1;
}

int apaga_fila (Fila *f)
{
    esvazia_fila (f);
    free (*f);
    *f = NULL;

    return 1;
}