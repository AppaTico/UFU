#include <stdlib.h>
#include "fila.h"
#define max 20

struct fila
{
    int no[max];
    int ini, cont;
};

/*
- Aloca todas as posições da estrutura fila (vetor)
- Coloca a fila no estado vazia
    . Ini e cont são inicializados com ZERO
*/
Fila cria_fila ()
{
    Fila f;
    f = (Fila) malloc(sizeof(struct fila));

    if (f != NULL)
    {
        f -> ini = 0;
        f -> cont = 0;
    }

    return f;
}

/*
- Verifica se a fila está no estado de vazia (cont = 0)
    . Independe do valor dos campos ini e fim
*/
int fila_vazia (Fila f)
{
    if (f -> cont == 0)
        return 1;
    else
        return 0;
}

/*
- Verifica se a fila está no estado de cheia (cont = max)
*/
int fila_cheia (Fila f)
{
    if (f -> cont == max)
        return 1;
    else
        return 0;
}

/*
- Insere o elemento no final da fila
    . Posição calculada a partir dos campos ini e cont
- Incrementa (NÃO circular) o campo cont
*/
int insere_fim (Fila f, int elem)
{
    if (fila_cheia (f) == 1 || f == NULL)
        return 0;
    
    //insere elemento no final
    f -> no[(f -> ini + f-> cont) % max] = elem;
    f -> cont++;

    return 1;
}

/*
- Retorna o valor do elemento no início da fila
    . Posição indicada pelo campo ini
- Incrementa o campo ini (incremento circular)
- Decrementa o campo cont
*/
int remove_ini (Fila f, int *elem)
{
    if (fila_vazia (f) == 1 || f == NULL)
        return 0;

    //remove o elemento do inicio
    *elem = f -> no[f -> ini];
    f -> ini = (f -> ini + 1) % max;
    f -> cont--;

    return 1;
}

int esvazia_fila (Fila f)
{
    if (f == NULL)
        return 0;
    
    f -> cont = 0;
    return 1;
}

int apaga_fila (Fila *f)
{
    esvazia_fila (f);
    free (*f);
    *f = NULL;

    return 1;
}