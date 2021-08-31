#include <stdio.h>
#include "rec.h"

void print_lista (Lista lst, int qnt)
{
    int elem;

    for(int indice = 0; indice < qnt; indice++)
    {
        get_elem_pos (lst, indice, &elem);
        printf ("%d ", elem);
        indice ++;
    }

    printf ("\n");
}

int main ()
{
    Lista lst = NULL;
    int opcao, qnt, elem;

    while (1)
    {
        printf("\nSelecione uma opção:\n");
        printf("\n[1] Criar Lista");
        printf("\n[2] Imprimir Lista");
        printf("\n[3] Apagar Lista");
        printf("\n[4] Esvaziar Lista");
        printf("\n[5] Sair do programa");
        printf("\nDigite a opção desejada: ");

        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:

                lst = cria_lista ();

                printf("\nQuantos elementos terá a lista?\n");
                scanf("%d", &qnt);

                printf("\nDigite os elementos um por um até completar a quantia:\n");

                for (int i = 0; i < qnt; i++)
                {
                    int elem;

                    printf("\nDigite um elemento: ");
                    scanf("%d", &elem);

                    insere_ord (&lst, elem);
                }

                printf ("\nPronto!\n");

                break;

            case 2:

                if (lst == NULL)
                {
                    printf("\nNão há lista para imprimir!\n");
                }
                else
                print_lista (lst, qnt);

                break;

            case 3:
                
                if (lst == NULL)
                {
                    printf("\nNão há lista para ser apagada!\n");
                }
                else 
                apaga_lista (&lst);

                break;

            case 4:

                if (lst == NULL)
                {
                    printf("\nNão há lista para ser esvaziada!\n");
                }
                else 
                esvazia_lista (&lst);

                break;

            case 5:
                
                return 0;
        }
    }

    return 0;
}
