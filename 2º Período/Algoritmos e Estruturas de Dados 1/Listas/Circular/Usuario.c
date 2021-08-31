#include <stdio.h>
#include "lista.h"

void inserir_bebida (Lista *bbd, Bebida bebida, int qnt)
{
    for (int i = 0; i < qnt; i++)
    {
        printf("\nDigite o nome da bebida: ");
        scanf("%s", bebida.nome);

        printf("\nDigite o preço da bebida: ");
        scanf("%f", &bebida.preco);

        printf("\nDigite o volume (em ml) da bebida: ");
        scanf("%d", &bebida.volume);

        insere_final (bbd, bebida);
    }
}

void print_lista (Lista *bbd, Bebida *bebida)
{
    int indice = 0;

    while(get_elem_pos(*bbd, indice, bebida) != 0)
    {
       printf ("\nBebida: %s", bebida -> nome);
       printf ("\nPreço: %.2f", bebida -> preco);
       printf ("\nVolume: %dml", bebida -> volume);
       indice ++;
    }
}

int main ()
{
    Bebida bebida;
    Lista bbd = NULL;
    int opcao, qnt;
    
    while(1)
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

                printf ("\nQuantas bebidas adicionará à lista?\n");
                printf ("\nQuantia: ");
                scanf ("%d", &qnt);

                bbd = cria_lista ();

                inserir_bebida (&bbd, bebida, qnt);
                break;

            case 2:

                if(bbd == NULL)
                {
                    printf("\nVai imprimir o que amigão?\n");
                }
                else
                {
                    print_lista (&bbd, &bebida);
                }

                break;

            case 3:

                if(bbd == NULL)
                {
                    printf("\nVai apagar o que amigão?\n");
                }
                else
                {
                    apaga_lista (&bbd);
                    return 1;
                }

                break;

            case 4:

                if(bbd == NULL)
                {
                    printf("\nVai esvaziar o que amigão?\n");
                }
                else
                {
                    esvazia_lista (&bbd);
                    return 1;
                }

                break;

            case 5:

                return 0;
        }
    }
}
