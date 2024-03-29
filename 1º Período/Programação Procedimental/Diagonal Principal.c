//Este programa apresenta o conteúdo de um array bidimensional m[N][N] e a diagonal principal da mesma

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main()
{
    int j = 0; // laço for
    int i = 0; // laço for
    int N = 4; // valor do array bidimensional
    int m[N][N]; // array bidimensional

    void loadA(int j, int i, int N, int m[N][N]);
    void showArrayBi(int j, int i, int N, int m[N][N]);
    void dp(int j, int i, int N, int m[N][N]);

    loadA (j, i, N, m);
    showArrayBi(j, i, N, m);
    dp (j, i, N, m);

    return 0;
}

//Esta função carrega o array m com valores aleatórios de 0 a 20
void
loadA(int j, int i, int N, int m[N][N])
{
    srand (time(NULL));

    for (i = 0; i < N; i++)
    {
        while (j < N)
        {
            m[i][j] = (rand () % 21);
            j++;
        }
        j = 0;
    }
}

//Esta função imprime o array m
void
showArrayBi(int j, int i, int N, int m[N][N])
{
    for (i = 0; i < N; i++)
    {
        while (j < N)
        {
            printf ("%d\t", m[i][j]);
            j++;
        }
        j = 0;
        printf("\n");
    }

    printf("\n");
}

//Esta função imprime a diagonal primária do array m
void
dp(int j, int i, int N, int m[N][N])
{
    printf("\nDiagonal Primária\n\n");
    for (i = 0; i < N; i++)
    {
        printf("%d ", m[i][i]);
    }
    printf("\n");
}
