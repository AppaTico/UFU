#define MAX_NOME 100
#define MAX_ELEM 1000

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Cliente
{
    char nome[MAX_NOME];
    int agencia;
}cliente;

void intercala (cliente*, int, int, int);
void mergesort (cliente*, int, int);

void intercala (cliente v[], int e, int m, int d)
{
    cliente *r;
    int i,j,k;

    r = (cliente*) malloc (((d + 1)-e)*sizeof(cliente));
    i = e;
    j = m + 1;
    k = 0;

    while ((i <= m) && (j <= d))
    { 
        if(strcmp(v[i].nome, v[j].nome) < 0)
        { 
            r[k] = v[i];
            i++; 
        }
        else
        {
            r[k] = v[j];
            j++; 
        }

        k++;
    }

    while (i <= m) 
    {
        r[k] = v[i];
        i++;
        k++;
    } 
    
    while (j <= d) 
    {
        r[k] = v[j];
        j++;
        k++;
    } 

    j = 0;
    
    for(i = e; i <= d; i++)
    {
        v[i] = r[j]; 
        j++; 
    }

    free(r);
}

void mergesort (cliente v[], int e, int d)
{
    int m;
    if (e < d)
    {
        m = (e + d)/2;
        mergesort(v, e, m);
        mergesort(v, m + 1, d);
        intercala(v, e, m, d);
    }
}

void insertionsort(cliente* v, int n)
{
    int i, j;
    cliente aux;

    for(i = 1; i < n; i++)
    {
        aux = v[i];
        j = i - 1;
        while(j >= 0 && aux.agencia < v[j].agencia)
        {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = aux;
    }
}

int main ()
{
    cliente vetor[MAX_ELEM]; int N;
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", vetor[i].nome);
        scanf("%d", &vetor[i].agencia);
    }

    mergesort(vetor, 0, N-1);
    insertionsort(vetor, N);

    for (int i = 0; i < N; i++)
    {
        printf("%s ", vetor[i].nome);
        printf("%d\n", vetor[i].agencia);
    }
}