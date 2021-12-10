/*
- inserção no final
- remoção de acordo com a prioridade
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

/*
– Aloca uma novo nó
– Preenche seus os campos:
    • Campo info recebe o valor do elemento
    • Campo prox recebe NULL
– Se fila vazia:
    • Faz o campo ini da fila apontar para o novo nó
– Se fila com elementos:
    • Faz o último nó da fila apontar para o novo nó
– Faz o campo fim da fila apontar para o novo nó
*/
int insere_fim (Fpa f, int elem)
{
    struct no * N;
    N = (struct no *) malloc(sizeof(struct no));

    if (N == NULL)
        return 0;

    N -> info = elem; //preenche o campo info
    N -> prox = NULL; //preenche o campo prox

    if (fila_vazia (f) == 1)
        f -> ini = N; //se fila vazia
    else
        (f -> fim) -> prox = N; //se fila nao vazia
    
    f -> fim = N; //campo fim aponta para N
    
    return 1;
}

int remove_ord (Fpa f, int *elem)
{
    if(f == NULL || fpa_vazia(f))
        return 0;

    if(f->ini == f->fim)
    {
        *elem = (f -> ini) ->info;
        free(f->ini);

        f -> ini = NULL;
        f -> fim = NULL;

        return 1;
    }

    struct no * aux = f -> ini;
    struct no * aux2 = f -> ini;

    while (aux->prox != NULL)
    {
        if (((aux -> prox) -> info) > ((aux2 -> prox) -> info))
            aux2 = aux;
        
        aux = aux->prox;
    }

    if(((f -> ini) -> info) > ((aux2 -> prox) -> info))
    {
        aux = f -> ini;
        *elem = aux -> info;
        f -> ini = aux -> prox;

        free(aux);

        return 1;
    }

    aux = aux2 -> prox;
    *elem = aux -> info;
    aux2 -> prox = aux -> prox;

    if(aux == f -> fim)
        f -> fim = aux2;

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