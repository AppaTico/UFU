//Este programa apresenta o conteúdo de uma matriz NxN e dados sobre essa matriz (diagonal principal, secundaria e a soma dos valores da linha selecionada pelo usuario)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dp(int N, int M[10][10]);
void ds(int N, int M[10][10]);
int tl(int X, int N, int M[10][10]);

int
main()
{
    FILE *matriz = NULL;

    char nomeArq[100]; //Nome do Arquivo
    int M[10][10]; //Array da matriz
    int i = 0; //Laço for
    int j = 0; //Preenchimento do array da matriz
    int N, X; //Ordem da matriz e linha da função tl
    char desejo[3]; //Oq o usuario deseja
    char bbb[3] = "dp"; //Se o usuario digita dp
    char ccc[3] = "ds"; //Se o usuario digita ds
    char aaa[3] = "tl"; //Se o usuario digita tl
    char sla[5] = "sair"; //Se o usuario digita sair

    printf("Digite o nome do arquivo que deseja ler: ");
    scanf("%s", nomeArq);
    matriz = fopen(nomeArq, "r");

    if (matriz == NULL)
    {
        fprintf(stderr, "\nArquivo não encontrado.\n");
        return 0;
    }

    fscanf(matriz, "%d", &N);
    printf("%d\n", N);

    while(!feof(matriz))
    {
        for (i = 0; i < N; i++)
        {
        while (j < N)
        {
            fscanf(matriz, "%d", &M[i][j]);
            printf("%d\t", M[i][j]);
            j++;
        }
        j = 0;
        printf("\n");
        }

        do
        {
            printf("\nSe desejas gerar a diagonal principal, digite dp\n");
            printf("Se desejas gerar a diagonal secundária, digite ds\n");
            printf("Se desejas realizar a soma dos valores de uma linha da matriz, digite tl\n");
            printf("Se não desejas fazer nada, digite sair\n");
            printf("\nDigite o que desejas: ");
            scanf("%s", desejo);

        
            if (strcmp(desejo, sla) == 0)
            {
                return 0;
            }

            else if(strcmp(desejo, bbb) == 0)
            {
                dp(N, M);
            }
        
            else if (strcmp(desejo, ccc) == 0)
            {
                ds(N, M);
            }
            else if (strcmp(desejo, aaa) == 0)
            {
                tl(X, N, M);
            }
            else if (strcmp(desejo, sla) == 0)
            {
                return 0;
            }
        }
        while(strcmp(desejo, sla) != 0);
    }

    printf("\n");

    

    fclose(matriz);
    matriz = NULL;

    return 0;
}

//Esta função imprime a diagonal primária da matriz M
void
dp(int N, int M[10][10])
{
    int i; //Laço for

    printf("\nDiagonal Primária: ");
    for (i = 0; i < N; i++)
    {
        printf("%d ", M[i][i]);
    }
    printf("\n");

    return;
}

//Esta função imprime a diagonal secundária da matriz M
void
ds(int N, int M[10][10])
{
    int i; //Laço for

    printf("\nDiagonal Secundária: ");
    for(i = 0; i < N; i++)
    {
        printf("%d ", M[i][(N - 1) - i]);
    }
    printf("\n");

    return;
}

//Esta função realiza a soma dos valores de uma linha da matriz M
int
tl(int X, int N, int M[10][10])
{
    int i; //Laço for
    int soma = 0; //Soma dos valores da matriz

    printf("\nDigite qual linha deseja somar: ");
    scanf("%d", &X);

    for(i = 0; i < N; i++)
    {
        soma = M[X - 1][i] + soma;
    }
    printf("\nSoma dos valores da %dª linha: %d\n", X, soma);

    return soma;
}
