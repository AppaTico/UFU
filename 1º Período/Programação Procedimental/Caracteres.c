//Este programa apresenta a quantidade de caracteres digitados pelo usuário, os caracteres na ordem inversa e o valor correspondente ao produto entre o primeiro, o do meio e o último caractere

#include <stdio.h>
#define MAX 50

int loadA (char a[MAX]);
void inv (char a[MAX]);
void prod (char a[MAX], int qtd);

int
main()
{
    char a[MAX]; //Array que armazena os caracteres
    int qtd = loadA(a); //Variável que armazena o retorno da função loadA

    printf("\nQuantidade de caracteres digitados: %d\n", qtd);

    if (qtd > MAX || qtd == MAX)
    {
        fprintf(stderr, "\nO número de caracteres alcançou o valor máximo\n");
    }

    inv (a);

    prod (a, qtd);

    return 0;
}

//Esta função coleta todos os caracteres digitados pelo usuário e registra quantos foram
int
loadA(char a[MAX])
{
    int i = 0; // laço for

    for (i = 0; i < MAX; i++)
    {
        a[i] = getchar();
        if (a[i] == '\n')
        {
            break;
        }
    }
    return i;
}

//Esta função inverte os caracteres digitados pelo usuário
void
inv(char a[MAX])
{
    int i; //laço for
    int j = 1; //variável para inverter os carac.

    printf("\nCaracteres Invertidos: ");

    for (i = 0; i < MAX; i++)
    {
        if (a[i] == '\n')
        {
        while ((i - j) >= 0)
        {
            a[i] = a[i - j];
            putchar(a[i]);
            j++;
        }
        }
    }

    printf("\n");
}

//Esta função calcula o produto entre o primeiro, o do meio e o último caractere
void
prod(char a[MAX], int qtd)
{
    int L = qtd - 1; //caracteres digitados menos o '\n'
    int meio = L / 2; //caracter do meio
    int produto = a[0] * a[L] * a[meio]; //produto entre os carac.
    printf("\nProduto da multiplicação do primeiro, do meio e o último caractere: %d", produto);
    printf("\n");
}
