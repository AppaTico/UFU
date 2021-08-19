//Esse programa apresenta o conteúdo de um arquivo (cujo nome foi informado pelo usuário) com os caracteres concatenados por um asterisco

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int
main()
{
    FILE *stream = NULL; //Ponteiro para o arquivo
    char nomeArq[MAX]; //Nome do arquivo
    char f; //Caracteres contidos dentro do arquivo

    printf("\nDigite o nome do arquivo que deseja ler: ");

    scanf("%s", nomeArq);
    stream = fopen(nomeArq,"r");

    if (stream == NULL)
    {
        fprintf(stderr, "\nO arquivo %s não foi encontrado.\n", nomeArq);
        return 0;
    }

    printf("\nConteúdo do arquivo:\n\n");

    f = fgetc(stream);
    while (!feof(stream))
    {
        printf("%c", f);
        f = fgetc(stream);

        if(f == 32)
        {
            printf("*");
            f = fgetc(stream);
        }
    }

    printf("\n");

    fclose(stream);
    stream = NULL;

    return 0;
}
