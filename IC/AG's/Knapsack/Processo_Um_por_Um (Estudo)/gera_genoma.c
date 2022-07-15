#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define tamanho_genoma 5
#define tamanho_pop 6

void gera_genoma(int genoma[])
{
    for(int j = 0; j < tamanho_pop; j++)
    {
        printf("[%d] ", j);
        for(int i = 0; i < tamanho_genoma; i++)
        {
            genoma[i] = rand() % 2;
            printf("%d", genoma[i]);
        }
        printf("\n");
    }
}

int main()
{
    srand(time(0));
    int genoma[tamanho_genoma];
    gera_genoma(genoma);
    return 0;
}