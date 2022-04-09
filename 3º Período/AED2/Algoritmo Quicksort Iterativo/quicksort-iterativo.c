#include <stdlib.h>
#include <stdio.h>

#define true 1
#define false 0
typedef int bool;

#define min(a, b) ((a < b) ? a : b)
#define max(a, b) ((a > b) ? a : b)

#define MAX_ELEM 1000

typedef struct noPilha 
{
    int esq, dir;
    struct noPilha *frente;
} noPilha;

typedef struct 
{
    int tamanho;
    noPilha *topo;
} Pilha;

void inicPilha(Pilha *pilha) 
{
    pilha->tamanho = 0;
    pilha->topo = (noPilha*) malloc(sizeof(noPilha));
    pilha->topo->frente = NULL;
}

bool vaziaPilha(Pilha pilha) 
{
    return !pilha.tamanho;
}

void push(Pilha *pilha, int esq, int dir) 
{
    noPilha *aux;
    aux = (noPilha*) malloc(sizeof(noPilha));
    aux->frente = pilha->topo;
    pilha->topo->esq = esq;
    pilha->topo->dir = dir;
    pilha->topo = aux;
    pilha->tamanho++;
}

void pop(Pilha *pilha) 
{
    noPilha *aux;
    if (!vaziaPilha(*pilha)) 
    {
        aux = pilha->topo;
        pilha->topo = aux->frente;
        free(aux);
        pilha->tamanho--;
    }
}

void swap(int *a, int *b) 
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int particao(int vetor[], int esq, int dir) 
{
    int i = esq, j;
    int a = vetor[esq], b = vetor[(esq + dir) / 2], c = vetor[dir];

    int pivo = a ^ b ^ c ^ max(a, max(b, c)) ^ min(a, min(b,c));

    int posPivo = (pivo == a) ? esq : (pivo == b) ? (esq + dir) / 2 : dir;
    swap(&vetor[posPivo], &vetor[dir]);
   
    for (j = esq; j < dir; j++)
        if (vetor[j] < pivo)
            swap(&vetor[i++], &vetor[j]);

    swap(&vetor[i], &vetor[dir]);
    return i;
}

void quickSortI(int vetor[], int esq, int dir) 
{
    int e, d;
    Pilha pilha;

    inicPilha(&pilha);
    push(&pilha, esq, dir);
    while (!vaziaPilha(pilha)) 
    {
        e = pilha.topo->frente->esq;
        d = pilha.topo->frente->dir;

        pop(&pilha);
        if (e < d) 
        {
            int posPivo = particao(vetor, e, d);
            push(&pilha, e, posPivo - 1);
            push(&pilha, posPivo + 1, d);
        }
    }
}

int main()
{
    int i, N, a[MAX_ELEM];

    scanf("%d", &N);

    for(i = 0; i < N; i++) 
        scanf("%d", &a[i]);

    quickSortI(a,0,N-1);

    for(i = 0; i < N; i++)
        printf("%d ",a[i]);

    return 0;
}