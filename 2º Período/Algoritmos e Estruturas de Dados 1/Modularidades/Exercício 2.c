#include <stdio.h>

char leitura_dados(char v[])
{
    int qt_al;
    scanf("%d", &qt_al);

    printf("Digite os dados desses alunos: \n");

    int limite = 3 * qt_al;
    int i = 0;

    for (i = 0; i < limite; i + 2)
    {
        int n_m;
        printf("Número de matrícula: ");
        scanf("%d", &n_m);
        *(v + i) = n_m;

        char nome;
        printf("\nNome: ");
        scanf("%s", &nome);
        *(v + i + 1) = nome;

        int nota;
        printf("\nNota: ");
        scanf("%d", &nota);
        if(nota < 0 || nota > 100)
        {
            printf("\nNota precisa ser um valor de 0 a 100.");
            return 0;
        }
        *(v + i + 2) = nota;
    }

    return *v;
}

int main ()
{

    char v[100];
    printf("Quantos alunos deseja registrar?\n");

    char opa = leitura_dados(&v[0]);

    printf("%c", opa);
}
