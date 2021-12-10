/*
- Uso do incremento circular (insere_final e remove_inicio) e do decremento circular 
(insere_início e remove_final)

- Decremento circular

F Θ 1 = F - 1, se F > 0
F Θ 1 = max - 1, se F = 0
*/

/*
Diferenciação entre deque vazio e cheio adota as abordagens de fila:

- Desprezar 1 posição:
    . Deque vazio: ini = fim
    . Deque cheio: ini = (fim + 1) % max

- Uso de contador:
    . Deque vazio: cont = 0
    . Deque cheio: cont = max
*/

#include <stdlib.h>
#include "deque.h"
#define max 10

struct deque
{
    int no[max];
    int ini, fim;
};

Deque cria_deque ()
{
    Deque d;
    d = (Deque) malloc(sizeof(struct deque));

    if (d != NULL)
    {
        d -> ini = 0;
        d -> fim = 0;
    }

    return d;
}

int deque_vazio (Deque d)
{
    if (d -> ini == d -> fim && d != NULL)
        return 1;
    else
        return 0;
}

int deque_cheio (Deque d)
{
    if (d -> ini == (d -> fim + 1) % max && d != NULL)
        return 1;
    else
        return 0;
}

//Uso do decremento circular
int inserir_início (Deque d, int *elem)
{
    if (d == NULL || deque_cheio(d) == 1)
        return 0;
    
    if (d -> ini == 0)
        d -> ini = max - 1;
    else
        d -> ini -= 1;

    d -> no[d -> ini] = elem;
    return 1;
}

//Uso do incremento circular
int inserir_final (Deque d, int *elem)
{
    if (d == NULL || deque_cheio(d) == 1)
        return 0;
    
    d -> fim = (d -> fim + 1) % max;

    d -> no[d -> fim] = elem;

    return 1;
}

//Uso do incremento circular
int remover_início (Deque d, int *elem)
{
    if (deque_vazio(d) == 1 || d == NULL)
        return 0;

    //remove o elemento do inicio
    *elem = d -> no[d -> ini];

    d -> ini = (d -> ini + 1) % max;

    return 1;
}

//Uso do decremento circular
int remover_final (Deque d, int *elem)
{
    if (deque_vazio(d) == 1 || d == NULL)
        return 0;

    *elem = d -> no[d -> fim];

    if (d -> fim == 0)
        d -> fim = max - 1;
    else
        d -> fim -= 1;

    return 1;
}

int esvazia_deque (Deque d)
{
    if (d == NULL)
        return 0;
    else
    {
        d -> ini = 0;
        d -> fim = 0;
    }

    return 1;
}

int apaga_deque (Deque *d)
{
    free (*d);
    *d = NULL;

    return 1;
}