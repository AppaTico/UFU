#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "calcula_fitness.h"

/*
a[linha][coluna]
*/

void preenche_mochila(item mochila[])
{
    strcpy(mochila[0].nome, "Laptop");
    mochila[0].valor = 500;
    mochila[0].peso = 2200;
    strcpy(mochila[1].nome, "Headphones");
    mochila[1].valor = 150;
    mochila[1].peso = 160;
    strcpy(mochila[2].nome, "Coffee Mug");
    mochila[2].valor = 60;
    mochila[2].peso = 350;
    strcpy(mochila[3].nome, "Notepad");
    mochila[3].valor = 40;
    mochila[3].peso = 333;
    strcpy(mochila[4].nome, "WaterBottle");
    mochila[4].valor = 30;
    mochila[4].peso = 192;
}

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

int calcula_fitness(int populacao[tamanho_pop][tamanho_genoma], item mochila[], int j)
{
    int fitness = 0;
    int peso = 0;

    for(int i = 0; i < tamanho_genoma; i++)
    {
        if(populacao[j][i] == 1)
        {
            fitness += mochila[i].valor;
            peso += mochila[i].peso;
        }
    }
    
    if(peso > limite_peso)
        fitness = 0;

    if(fitness >= limite_fitness)
    {
        printf("Solucao: ");
        for (int i = 0; i < tamanho_genoma; i++)
            printf("%d", populacao[j][i]);

        printf("\n");
        exit(1);
    }
    
    return fitness;
}

int main()
{
    srand(time(0));

    int populacao[tamanho_pop][tamanho_genoma];
    gera_populacao(populacao);

    item mochila[tamanho_mochila];
    preenche_mochila(mochila);

    int fit;
    for(int i = 0; i < tamanho_pop; i++)
    {
        fit = calcula_fitness(populacao, mochila, i);
        printf("Fitness [%d]: %d\n", i, fit);
    }
    
    return 0;
}