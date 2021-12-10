#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "deque.h"

/*
dado uma deque e uma letra como entrada, retorna essa mesma deque sem as 
strings que começam com a letra informada. Esta função também deve mostrar na tela a 
quantidade de strings removidas ou uma mensagem de erro se não for possível realizar a operação.
*/
int elimina_string (Deque d, char letra)
{
    if (deque_vazio(d) == 1 || d == NULL)
    {
        printf ("\nNão foi possível realizar a operação.\n");
        return 0;
    }

    int contador = 0;
    char elem[max_c];

    struct no * N;
    N = (struct no *) malloc(sizeof(struct no));

    if (N == NULL)
    {
        printf ("\nNão foi possível realizar a operação.\n");
        return 0;
    }

    N -> string[max_c] = (d -> ini) -> string[max_c];

    if (d -> ini == d -> fim && ((d -> ini) -> string[0]) == letra)
    {
        remover_inicio(d, elem[max_c]);
        contador ++;
    }

    Deque aux = cria_deque();
    if (aux == NULL)
    {
        printf("\nNão foi possível realizar a operação.\n");
        return 0;
    }
    
    aux -> ini = d -> ini;

    while (N -> prox != d -> ini)
    {
        if (N -> string[0] == letra)
        {
            d -> ini = N;
            remover_inicio(d, elem[max_c]);
            N = N -> prox;
            contador++;
        }
    }

    d -> ini = aux -> ini;
    free (aux);
    printf("\nForam removidas %d strings.\n", contador);

    return 1;
}

int main ()
{
    int op;
    printf("\nSelecione a opção desejada:\n[1]Criar o deque\n[2]Inserir uma string no deque\n[3]Esvaziar o deque\n[4]Apagar o deque\n[5]Imprimir o deque\n[6]Remover palavras do deque\n");
    printf("\nDigite a opção: ");
    scanf("%d", &op);
    printf("\n");
    char elem[max_c], letra;
    Deque d;
    switch(op)
    {
        //criar o deque
        case 1:
            d = cria_deque();
            if (d != NULL)
                printf ("\nDeque criada com sucesso.\n");
            else
                printf ("\nNão foi possível criar o deque.\n");

            break;

        //inserir no deque
        case 2:
            if (d == NULL)
            {
                printf ("\nNão há deque para inserir.\n");
                break;
            }

            printf ("\nDigite a string a ser inserida: ");
            scanf("%c", &elem[max_c]);
            printf("\n");
            inserir_final(d, elem[max_c]);

            if (inserir_final(d, elem[max_c]) != 1)
            {
                printf ("\nNão foi possível inserir o elemento no deque\n");
                break;
            }

            printf ("\nString inserida com sucesso.\n");

            break;

        //esvaziar o deque
        case 3:
            if (d == NULL)
            {
                printf ("\nNão há deque a ser esvaziado.\n");
                break;
            }

            esvazia_deque(d);

            if (esvazia_deque(d) != 1)
            {
                printf ("\nO deque já está vazio.\n");
                break;
            }

            printf ("\nDeque esvaziado com sucesso.\n");
            break;

        //apagar o deque
        case 4:
            if (d == NULL)
            {
                printf("\nNão há deque a ser apagado.\n");
                break;
            }

            apaga_deque(&d);
            printf("\nDeque apagado com sucesso.\n");

        //imprimir o deque
        case 5:
            if (d == NULL)
            {
                printf("\nNão há deque a ser imprimido.\n");
                break;
            }

            Deque aux = cria_deque();
            if (aux == NULL)
            {
                printf("\nNão foi possível realizar a operação.\n");
                break;
            }

            aux = d;

            struct no * N;
            N = (struct no *) malloc(sizeof(struct no));

            if (N == NULL)
            {
                printf ("\nNão foi possível realizar a operação.\n");
                break;
            }

            N = aux -> ini;
            printf("\n{ ");
            while(N -> prox != aux -> ini)
            {
                printf("%c ", (N -> string[max_c]));
                N = N -> prox;
            }
            printf("}\n");
            free(aux);
            free(N);
            break;

        //remover palavras e imprimir o deque resultante
        case 6:
            if (d == NULL || deque_vazio(d) == 1)
            {
                printf("\nNão foi possível realizar esta operação.\n");
                break;
            }

            printf("\nDeseja eliminar as strings que começam com qual letra?\n");
            scanf("%c", letra);
            elimina_string (d, letra);

            if (elimina_string(d, letra) != 1)
            {
                printf("\nNão foi possível realizar esta operação.\n");
                break;                
            }

            Deque aux = cria_deque();
            if (aux == NULL)
            {
                printf("\nNão foi possível realizar a operação.\n");
                break;
            }

            aux = d;

            struct no * N;
            N = (struct no *) malloc(sizeof(struct no));

            if (N == NULL)
            {
                printf ("\nNão foi possível realizar a operação.\n");
                break;
            }

            printf("\nDeque resultante:\n");
            N = aux -> ini;
            printf("\n{ ");
            while(N -> prox != aux -> ini)
            {
                printf("%c ", (N -> string[max_c]));
                N = N -> prox;
            }

            printf("}\n");
            free(aux);
            free(N);
            break;

    }
}