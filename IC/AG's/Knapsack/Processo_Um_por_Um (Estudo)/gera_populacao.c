#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define tamanho_genoma 5
#define tamanho_pop 6

/*
a[linha][coluna]
*/

void gera_populacao(int populacao[tamanho_pop][tamanho_genoma])
{
    for(int j = 0; j < tamanho_pop; j++)
    {
        printf("[%d] ", j);
        for(int i = 0; i < tamanho_genoma; i++)
        {
            populacao[j][i] = rand() % 2;
            printf("%d", populacao[j][i]);
        }
        printf("\n");
    }
}

int main()
{
    srand(time(0));
    int populacao[tamanho_pop][tamanho_genoma];
    gera_populacao(populacao);


    return 0;
}