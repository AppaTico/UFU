#include <stdlib.h>
#include "fila.h"

struct no
{
    int info;
    struct no * prox;
};

struct fila
{
    struct no * ini;
    struct no * fim;
};

/*
- Aloca uma estrutura fila
– Coloca a fila no estado de vazia
    • Inicializa os campos ini e fim com NULL
*/
Fila cria_fila ()
{
    Fila f;
    f = (Fila) malloc(sizeof(struct fila));

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
int fila_vazia (Fila f)
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
int insere_fim (Fila f, int elem)
{
    if (f == NULL)
        return 0;
        
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

/*
– Cria um ponteiro auxiliar que recebe o endereço do 1º nó da fila (aux = f->ini)
– Faz campo ini da fila apontar o sucessor do nó endereçado por aux (f->ini = aux->prox)
– Se fila com um único elemento:
    • Faz campo fim apontar para NULL (f->fim = NULL)
– Retorna o valor do nó removido (*e = aux->info)
– Libera a memória usada pelo nó removido
*/
int remove_ini (Fila f, int *elem)
{
    if (fila_vazia (f) == 1 || f == NULL)
        return 0;
    
    struct no * aux = f -> ini; //aux aponta para o 1º no
    *elem = aux -> info; //retorna o valor do elemento

    //verifica se a fila tem um único nó
    if (f -> ini == f -> fim)
        f -> fim = NULL;

    f -> ini = aux -> prox; //retira 1º no da fila
    free (aux); //libera memoria alocada

    return 1;
}

int esvazia_fila (Fila f)
{
    if (f == NULL)
        return 0;

    f -> ini = NULL;
    f -> fim = NULL;
    return 1;
}

int apaga_fila (Fila *f)
{
    esvazia_fila(f);
    free (*f);
    *f = NULL;

    return 1;
}