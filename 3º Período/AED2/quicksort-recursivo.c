#include <stdlib.h>
#include <stdio.h>
#define N 16

void troca(int v[], int i, int j)
{
    int temp;
    temp=v[i];
    v[i]=v[j];
    v[j]=temp;
}

int particao(int v[],int esq,int dir)
{
    int i, fim;
    printf("\n Subvetor:\n");

    for (i = esq; i <= dir; i++) printf("%d ",v[i]); printf("\n");
    fim = esq;

    for(i = esq + 1; i <= dir; i++)

    if(v[i]<v[esq]) 
    {
        fim = fim + 1;
        troca(v,fim,i);
    }

    troca(v,esq,fim);

    for(i = esq; i <= fim; i++) printf("%d ",v[i]); printf("\n");
    for(i = fim + 1; i <= dir; i++) printf("%d ",v[i]); printf("\n");
    return fim;
}

void quicksort(int v[], int esq, int dir)
{
    int i;

    if(esq>=dir) return ;

    i = particao(v,esq,dir);
    quicksort(v,esq,i-1);
    quicksort(v,i+1,dir);
}

int main()
{
    int i,a[N];
    for(i = 0; i < N; i++) 
        a[i] = rand()%100;

    for(i = 0; i < N; i++) printf("%d ",a[i]);

    quicksort(a,0,N-1);
    printf("\n Ordenado:\n");
    for(i = 0; i < N; i++) printf("%d ",a[i]);

    return 0;
}
