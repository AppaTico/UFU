#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "knapsack.h"

/* lembrete de como funciona double array em C:
a[linha][coluna]
*/

clock_t t; //relogio que contabiliza o tempo do programa

int cont_geracoes = 1; //numero de geracoes que leva para chegar a resposta

//prenche a mochila (array de itens) com os itens usados no problema da mochila
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

//gera a primeira geracao (populacao) de genomas que e completamente aleatoria
void gera_populacao(int populacao[tamanho_pop][tamanho_genoma])
{
    for(int j = 0; j < tamanho_pop; j++)
    {
        for(int i = 0; i < tamanho_genoma; i++)
            populacao[j][i] = rand() % 2;
    }
}

//calcula o fitness de cada genoma presente na populacao dada
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
        printf("Numero de geracoes: %d\n", cont_geracoes);
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
        printf("O programa levou %f segundos para executar\n", time_taken);
        exit(1);
    }
    
    return fitness;
}

//mostra qual o valor do maior fitness da populacao dada (usado para a funcao seleciona_pais)
int maior_fitness(int populacao[tamanho_pop][tamanho_genoma], item mochila[])
{
    int fit;
    int maior_fit = 0;

    for (int i = 0; i < tamanho_pop; i++)
    {
        fit = calcula_fitness(populacao, mochila, i);

        if(fit >= maior_fit)
            maior_fit = fit;
    }

    return maior_fit;
}

//seleciona o pai (genoma de maior fitness) e mae (genoma com o segundo maior fitness) de uma geracao
void seleciona_pais(int populacao[tamanho_pop][tamanho_genoma], item mochila[], int pai[], int mae[])
{
    int fit;
    int maior_fit = maior_fitness(populacao, mochila);
    int segundo_maior_fit = 0;

    for (int i = 0; i < tamanho_pop; i++)
    {
        fit = calcula_fitness(populacao, mochila, i);

        if (fit == maior_fit)
        {
            for(int j = 0; j < tamanho_genoma; j++)
                pai[j] = populacao[i][j];
        }
        else if (fit < maior_fit && fit >= segundo_maior_fit)
        {
            segundo_maior_fit = fit;
            for(int j = 0; j < tamanho_genoma; j++)
                mae[j] = populacao[i][j];
        }
    }
}

//faz a reproducao entre pai e mae para gerar dois filhos cuja composicao sao (p:m) e (m:p)
void crossover(int pai[], int mae[], int filho1[], int filho2[])
{
    for (int i = 0; i < (tamanho_genoma / 2); i++)
    {
        filho1[i] = pai[i];
        filho2[i] = mae[i];
    }

    for (int i = (tamanho_genoma / 2); i < tamanho_genoma; i++)
    {
        filho1[i] = mae[i];
        filho2[i] = pai[i];
    }
}

//sorteia qual bit dos filhos sera mudado e posto em um novo genoma 
void mutacao(int filho1[], int filho2[], int mutacao1[], int mutacao2[])
{
    float a = 1;
    float pb;
    for (int i = 0; i < tamanho_genoma; i++)
    {
        pb = (float)rand()/(float)(RAND_MAX/a);
        if (pb < probabilidade)
        {
            mutacao1[i] = abs((filho1[i]) - 1);
            mutacao2[i] = abs((filho2[i]) - 1);
        }
        if(pb >= probabilidade)
        {
            mutacao1[i] = filho1[i];
            mutacao2[i] = filho2[i];
        }
    }
}

//faz o processo para as geracoes 2 pra frente
int resto(int populacao[tamanho_pop][tamanho_genoma], item mochila[])
{
    int pai[tamanho_genoma];
    int mae[tamanho_genoma];

    seleciona_pais(populacao, mochila, pai, mae);

    int posterior[tamanho_pop][tamanho_genoma];

    for(int i = 0; i < tamanho_genoma; i++)
    {
        posterior[0][i] = pai[i];
        posterior[1][i] = mae[i];
    }

//faz o crossover entre o pai e mae da geracao para gerar os dois filhos

    int filho1[tamanho_genoma];
    int filho2[tamanho_genoma];

    crossover(pai, mae, filho1, filho2);
    for(int i = 0; i < tamanho_genoma; i++)
    {
        posterior[2][i] = filho1[i];
        posterior[3][i] = filho2[i];
    }

//faz a mutacao dos dois filhos gerados para preencher a geracao

    int mutacao1[tamanho_genoma];
    int mutacao2[tamanho_genoma];

    mutacao(filho1, filho2, mutacao1, mutacao2);
    for(int i = 0; i < tamanho_genoma; i++)
    {
        posterior[4][i] = mutacao1[i];
        posterior[5][i] = mutacao2[i];
    }

    printf("\n=======GERACAO %d=======\n", cont_geracoes);
    for(int i = 0; i < tamanho_pop; i++)
    {
        printf("[%d] ", i);
        for(int j = 0; j < tamanho_genoma; j++)
            printf("%d", posterior[i][j]);
        printf("\n");
    }
    printf("\n");

    int fit;
    for(int i = 0; i < tamanho_pop; i++)
    {
        fit = calcula_fitness(posterior, mochila, i);
        printf("Fitness [%d]: %d\n", i, fit);
    }
    printf("\n");
    cont_geracoes++;

    if(cont_geracoes <= limite_geracoes)
        resto(posterior, mochila);
    else
    {
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
        printf("O programa levou %f segundos para executar\n", time_taken);
        exit(1);
    }
    return 0;
}

//gera e formaliza a primeira geracao e chama a recursao que continuara para as geracoes seguintes
int main()
{
    srand(time(0));
    t = clock();

//gera a primeira geracao

    int populacao[tamanho_pop][tamanho_genoma];
    gera_populacao(populacao);

    printf("\n=======GERACAO %d=======\n", cont_geracoes);
    for(int i = 0; i < tamanho_pop; i++)
    {
        printf("[%d] ", i);
        for(int j = 0; j < tamanho_genoma; j++)
            printf("%d", populacao[i][j]);
        printf("\n");
    }
    printf("\n");

//preenche a lista de itens

    item mochila[tamanho_mochila];
    preenche_mochila(mochila);

//calcula os fitness da primeira geracao

    int fit;
    for(int i = 0; i < tamanho_pop; i++)
        fit = calcula_fitness(populacao, mochila, i);
    printf("\n");
    cont_geracoes++;

    resto(populacao, mochila);

    return 0;
}