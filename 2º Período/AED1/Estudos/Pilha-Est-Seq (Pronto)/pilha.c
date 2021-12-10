#include <stdlib.h>
#include "pilha.h"
#define max 20

struct pilha
{
    int no[max];
    int topo;
};

/*
- Aloca estrutura pilha
- Coloca a pilha no estado de vazia
- Retorna o endereço da pilha alocada
*/
Pilha cria_pilha ()
{
    Pilha p;
    p = (Pilha)malloc(sizeof(struct pilha));
    
    if (p != NULL)
        p -> topo = -1;

    return p;
}

/*
- Verifica se a pilha está na condição de vazia
*/
int pilha_vazia (Pilha p)
{
    if (p -> topo = -1)
        return 1;
    else
        return 0;
}

/*
- Verifica se a pilha está na condição de cheia
*/
int pilha_cheia (Pilha p)
{
    if (p -> topo = max - 1)
        return 1;
    else
        return 0;
}

/*
- Incrementa o indicador de topo
- Insere o elemento no topo da pilha
*/
int push (Pilha p, int elem)
{
    if (p == NULL || pilha_cheia (p) == 1)
        return 0;
    
    //insere o elemento no topo
    p -> topo++;
    p -> no[p -> topo] = elem;

    return 1;
}

/*
- Remove o elemento do topo da pilha
    . Decrementa o indicador de topo
- Retorna o valor do elemento (por referência)
*/
int pop (Pilha p, int *elem)
{
    if (p == NULL || pilha_vazia (p) == 1)
        return 0;
    
    *elem = p -> no[p -> topo]; //retorna o elemento
    p -> topo--; //remove o elemento do topo

    return 1;
}

/*
- Retorna o valor do elemento no topo da pilha
- Mesmo código da pop() sem a parte de remoção do elemento (decremento do topo)
*/

int le_topo (Pilha p, int *elem)
{
    if (p == NULL || pilha_vazia (p) == 1)
        return 0;
    
    *elem = p -> no[p -> topo]; //retorna o elemento
    return 1;
}

int esvazia_pilha (Pilha p)
{
    p -> topo = -1;
    return 1;
}

int libera_pilha (Pilha *p)
{
    esvazia_pilha (p);
    free (*p);
    *p = NULL;

    return 1;
}