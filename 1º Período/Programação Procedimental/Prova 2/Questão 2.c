//Este programa grava em um arquivo (cujo nome é informado pelo usuário) tudo que o usuário digitar e termina quando o usuário dá enter

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int
main()
{
    FILE *stream = NULL; //Ponteiro para o arquivo
    char nomeArq[MAX]; //Nome do arquivo
    char f[MAX]; //Caracteres que o usuário vai escrever
    int i = 0; //Laço for

    printf("\nDigite o nome do arquivo que deseja abrir: ");

    scanf("%s", nomeArq);
    stream = fopen(nomeArq,"r+");

    if (stream == NULL)
    {
        fprintf(stderr, "\nO arquivo %s não foi encontrado.\n", nomeArq);
        return 0;
    }

    printf("\nEscreva no arquivo:\n\n");

    f[i] = getchar();

    while(!feof(stream))
    {
        for(i = 0; i < MAX; i++)
        {
            f[i] = getchar();

            if(f[i] == '\n')
            {
                return 0;
            }

            fputc(f[i], stream);
        }
    }

    printf("\n");

    fclose(stream);
    stream = NULL;

    return 0;
}
