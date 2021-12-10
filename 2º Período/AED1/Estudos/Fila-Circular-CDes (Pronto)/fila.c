#include <stdlib.h>
#include "fila.h"
#define max 20

struct fila
{
    int no[max];
    int ini, fim;
};

/*
- Aloca todas as posições da estrutura fila (vetor)
- Coloca a fila no estado vazia (ini = fim)
    . Inicializados como ZERO ou max - 1
*/
Fila cria_fila ()
{
    Fila f;
    f = (Fila) malloc(sizeof(struct fila));

    if (f != NULL)
    {
        f -> ini = 0;
        f -> fim = 0;
    }

    return f;
}

/*
- Verifica se a fila está no estado de vazia (ini = fim)
    . Independe do valor atual dos campos (não precisa ter o mesmo valor usado na inicialização)
*/
int fila_vazia (Fila f)
{
    if (f -> ini == f -> fim)
        return 1;
    else
        return 0;
}

/*
- Verifica se a fila está no estado de cheia (ini = fim ⊕ 1)
*/
int fila_cheia (Fila f)
{
    if (f -> ini == (f -> fim + 1) % max)
        return 1;
    else
        return 0;
}

/*
- Insere o elemento no final da fila
    . Posição indicada pelo campo fim
- Incrementa o campo fim (incremento circular)
*/
int insere_fim (Fila f, int elem)
{
    if (fila_cheia (f) == 1 || f == NULL)
        return 0;
    
    //insere elemento no final
    f -> no[f -> fim] = elem;
    f -> fim = (f -> fim + 1) % max; //incremento circular

    return 1;
}

/*
- Retorna o valor do elemento no início da fila
    . Posição indicada pelo campo ini
- Incrementa o campo ini (incremento circular)
*/
int remove_ini (Fila f, int *elem)
{
    if (fila_vazia (f) == 1 || f == NULL)
        return 0;

    //remove o elemento do inicio
    *elem = f -> no[f -> ini];
    f -> ini = (f -> ini + 1) % max;

    return 1;
}

int esvazia_fila (Fila f)
{
    if (f == NULL)
        return 0;
        
    f -> ini = 0;
    f -> fim = 0;

    return 1;
}

int apaga_fila (Fila *f)
{
    esvazia_fila (f);
    free (*f);
    *f = NULL;

    return 1;
}