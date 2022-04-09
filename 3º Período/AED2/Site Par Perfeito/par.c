#include <stdio.h>
#include <stdlib.h>
#define MAX_NOME 100
#define MAX_ELEM 1000

typedef struct pessoas
{
    char nome[MAX_NOME];
    char sexo;
    int idade;
}pessoa;

void mergesort_sexo (pessoa*, int, int);
void intercala_sexo (pessoa*, int, int, int);
void mergesort_idade (pessoa*, int, int);
void intercala_idade (pessoa*, int, int, int);
int par(pessoa*, int);

int main ()
{
    pessoa v[MAX_ELEM];
    int N;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s %c %d", v[i].nome, &v[i].sexo, &v[i].idade);
    }

    mergesort_idade(v, 0, N - 1);
    mergesort_sexo(v, 0, N - 1);

    int i = par (v, N);
    printf("%d", i);
}

int par(pessoa *v, int N)
{
    int soma = 0, i, j;

    for(i = 0; v[i].sexo == 'f'; i++);

    for (j = i, i = 0; v[i].sexo == 'f' && v[j].sexo == 'm'; i++, j++)
    {
        if((v[i].idade + v[j].idade) % 2 == 0)
            soma++;
    }
    
    return soma;
}

void intercala_idade (pessoa v[], int e, int m, int d)
{
    pessoa *r;
    int i,j,k;

    r = (pessoa*) malloc (((d + 1)-e)*sizeof(pessoa));
    i = e;
    j = m + 1;
    k = 0;

    while ((i <= m) && (j <= d))
    { 
        if(v[i].idade > v[j].idade)
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

void intercala_sexo (pessoa v[], int e, int m, int d)
{
    pessoa *r;
    int i,j,k;

    r = (pessoa*) malloc (((d + 1)-e)*sizeof(pessoa));
    i = e;
    j = m + 1;
    k = 0;

    while ((i <= m) && (j <= d))
    { 
        if(v[i].sexo < v[j].sexo)
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

void mergesort_idade (pessoa v[], int e, int d)
{
    int m;
    if (e < d)
    {
        m = (e + d)/2;
        mergesort_idade(v, e, m);
        mergesort_idade(v, m + 1, d);
        intercala_idade(v, e, m, d);
    }
}

void mergesort_sexo (pessoa v[], int e, int d)
{
    int m;
    if (e < d)
    {
        m = (e + d)/2;
        mergesort_sexo(v, e, m);
        mergesort_sexo(v, m + 1, d);
        intercala_sexo(v, e, m, d);
    }
}