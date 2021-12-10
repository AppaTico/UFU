#include <stdlib.h>
#include "pilha.h"

struct no
{
    int info;
    struct no * prox;
};

/*
- Retorna uma pilha no estado de vazia
    . Topo igual a NULL
- Retorna o endereço do topo (NULL)
*/
Pilha cria_pilha ()
{
    return NULL;
}

/*
- Verifica se a pilha está no estado de vazia
    . Ponteiro da pilha igual a NULL
*/
int pilha_vazia (Pilha p)
{
    if (p == NULL)
        return 1;
    else
        return 0;
}

/*
- Aloca um novo nó
- Preenche os campos do novo nó
    . Campo info recebe o valor do elemento
    . Campo prox recebe o endereço do topo da pilha
- Faz a pilha apontar para o novo nó
*/
int push (Pilha *p, int elem)
{
    Pilha N = (Pilha) malloc(sizeof(struct no));

    if (N == NULL)
        return 0;

    N -> info = elem;
    N -> prox = *p;
    *p = N;

    return 1;
}

/*
- Remove o elemento que está no topo da pilha
    . Pilha passa a apontar para o sucessor do topo
    . Libera memória ocupada pelo antigo topo
- Retorna o valor do elemento removido
    . Valor é armazenado na variável de retorno
*/
int pop (Pilha *p, int *elem)
{
    if (pilha_vazia(*p) == 1)
        return 0;
    
    Pilha aux = *p;
    *elem = aux -> info;
    *p = aux -> prox;
    free (aux);

    return 1;
}

/*
- Simplificação do código da operação pop()
    . Retorna o elemento sem removê-lo
*/
int le_topo (Pilha *p, int *elem)
{
    if (pilha_vazia(*p) == 1)
        return 0;
    
    *elem = (*p) -> info;

    return 1;
}

int libera_pilha(Pilha *p) 
{
    if (p == NULL)
        return 0;

    int *liberando;

    while (*p != NULL) 
    {
        pop(p, &liberando);
        free(liberando);
        liberando = NULL;
    }
    
    return 1;

}

int esvazia_pilha(Pilha p) 
{
  return libera_pilha(p);
}