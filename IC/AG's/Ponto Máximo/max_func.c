#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "max_func.h"

/* lembrete de como funciona double array em C:
a[linha][coluna]
*/

clock_t t; //relogio que contabiliza o tempo do programa

int cont_geracoes = 1; //numero de geracoes que leva para chegar a resposta

//inicializa a primeira geracao composta de cromossomos com bits aleatorios
void inicializa_populacao(int populacao[tamanho_pop][tamanho_bits])
{
    for(int j = 0; j < tamanho_pop; j++)
    {
        for(int i = 0; i < tamanho_bits; i++)
            populacao[j][i] = rand() % 2;
    }
}

//calcula o fitness de cada cromossomo de uma geracao
float calcula_fitness(int populacao[tamanho_pop][tamanho_bits], int i)
{
    float x = 0;
    float fitness = 0;
    int traducao_binario = 0;

    //traduzindo (calculando) o valor em binario do cromossoma
    for(int j = 0; j < tamanho_bits; j++)
    {
        if (populacao[i][j] == 1)
        {
            traducao_binario += pow(2, ((tamanho_bits - 1) - j));
        }
    }

// b10/2^l - 1
    float componente1 = traducao_binario / (pow(2, tamanho_bits) - 1);
// max - min
    float componente2 = valor_maximo - valor_minimo;
// min + (componente1 * componente2)
    x = valor_minimo + (componente1 * componente2);
// x * seno(10*pi*x) + 1
    fitness = x*sin(10*M_PI*x) + 1;

    if(fitness >= limite_fitness)
    {
        printf("Solucao: ");
        for (int j = 0; j < tamanho_bits; j++)
            printf("%d", populacao[i][j]);
        printf("\n");
        printf("Numero de geracoes: %d\n", cont_geracoes);
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
        printf("O programa levou %f segundos para executar\n", time_taken);
        exit(1);
    }

    return fitness;
}

//seleciona o valor do maior fitness da geracao
float maior_fitness(int populacao[tamanho_pop][tamanho_bits])
{
    float fit;
    float maior_fit = 0;

    for (int i = 0; i < tamanho_pop; i++)
    {
        fit = calcula_fitness(populacao, i);

        if(fit >= maior_fit)
            maior_fit = fit;
    }

    return maior_fit;
}

//seleciona os dois cromossomos da geracao com maior fitness
void seleciona_pais(int populacao[tamanho_pop][tamanho_bits], int pai[], int mae[])
{
    float fit;
    float maior_fit = maior_fitness(populacao);
    float segundo_maior_fit = 0;

    for (int i = 0; i < tamanho_pop; i++)
    {
        fit = calcula_fitness(populacao, i);

        if (fit == maior_fit)
        {
            for(int j = 0; j < tamanho_bits; j++)
                pai[j] = populacao[i][j];
        }
        else if (fit < maior_fit && fit >= segundo_maior_fit)
        {
            segundo_maior_fit = fit;
            for(int j = 0; j < tamanho_bits; j++)
                mae[j] = populacao[i][j];
        }
    }
}

//faz a reproducao entre pai e mae para gerar dois filhos cuja composicao sao (p:m) e (m:p)
void crossover(int pai[], int mae[], int filho1[], int filho2[])
{
    for (int i = 0; i < (tamanho_bits / 2); i++)
    {
        filho1[i] = pai[i];
        filho2[i] = mae[i];
    }

    for (int i = (tamanho_bits / 2); i < tamanho_bits; i++)
    {
        filho1[i] = mae[i];
        filho2[i] = pai[i];
    }
}

//sorteia qual bit dos filhos sera mudado e posto em um novo cromossomo
void mutacao(int filho1[], int filho2[], int mutacao1[], int mutacao2[])
{
    float a = 1;
    float pb;
    for (int i = 0; i < tamanho_bits; i++)
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
int resto(int populacao[tamanho_pop][tamanho_bits])
{
    int pai[tamanho_bits];
    int mae[tamanho_bits];

    seleciona_pais(populacao, pai, mae);

    int posterior[tamanho_pop][tamanho_bits];

    for(int i = 0; i < tamanho_bits; i++)
    {
        posterior[0][i] = pai[i];
        posterior[1][i] = mae[i];
    }

//faz o crossover entre o pai e mae da geracao para gerar os dois filhos

    int filho1[tamanho_bits];
    int filho2[tamanho_bits];

    crossover(pai, mae, filho1, filho2);
    for(int i = 0; i < tamanho_bits; i++)
    {
        posterior[2][i] = filho1[i];
        posterior[3][i] = filho2[i];
    }

//faz a mutacao dos dois filhos gerados para preencher a geracao

    int mutacao1[tamanho_bits];
    int mutacao2[tamanho_bits];

    mutacao(filho1, filho2, mutacao1, mutacao2);
    for(int i = 0; i < tamanho_bits; i++)
    {
        posterior[4][i] = mutacao1[i];
        posterior[5][i] = mutacao2[i];
    }

    printf("\n=======GERACAO %d=======\n", cont_geracoes);
    for(int i = 0; i < tamanho_pop; i++)
    {
        printf("[%d] ", i);
        for(int j = 0; j < tamanho_bits; j++)
            printf("%d", posterior[i][j]);
        printf("\n");
    }
    printf("\n");

    float fit;
    for(int i = 0; i < tamanho_pop; i++)
    {
        fit = calcula_fitness(posterior, i);
        printf("Fitness [%d]: %f\n", i, fit);
    }
    printf("\n");
    cont_geracoes++;

    if(cont_geracoes <= limite_geracoes)
        resto(posterior);
    else
    {
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
        printf("\nSolucao nao encontrada!\nO programa levou %f segundos para executar\n", time_taken);
        exit(1);
    }
    return 0;
}

//gera e formaliza a primeira geracao e chama a recursao que continuara para as geracoes seguintes
int main ()
{
    srand(time(0));
    t = clock();

//gera a primeira geracao

    int populacao[tamanho_pop][tamanho_bits];
    inicializa_populacao(populacao);

    printf("\n=======GERACAO %d=======\n", cont_geracoes);
    for(int i = 0; i < tamanho_pop; i++)
    {
        printf("[%d] ", i);
        for(int j = 0; j < tamanho_bits; j++)
            printf("%d", populacao[i][j]);
        printf("\n");
    }
    printf("\n");

//calcula os fitness da primeira geracao

    float fit;
    for(int i = 0; i < tamanho_pop; i++)
    {
        fit = calcula_fitness(populacao, i);
        printf("[%d] Fitness: %f\n", i, fit);
    }
    printf("\n");
    cont_geracoes++;

//chama a recursao para as geracoes seguintes
    resto(populacao);

    return 0;
}