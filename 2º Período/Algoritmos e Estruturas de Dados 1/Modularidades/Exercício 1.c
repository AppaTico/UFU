#include <stdio.h>
#include <stdlib.h>

int vetor(int V[], int qt_el)
{
    int media_soma = 0;
    int media, i;

    for(i = 0; i < qt_el; i++)
        media_soma = media_soma + *(V + i);

    media = media_soma / qt_el;

    int j = 0;
    int qt_mm = 0;
    int el = 0;
    for(j = 0; j < qt_el; j++)
    {
        el = *(V + j);
        
        if(el < media)
            qt_mm++;
    }
    printf("Quantidade de elementos menores que a média: %d\n", qt_mm);
    return media;
}

int main ()
{
    int V[15], qt_el, i;

    printf("Digite a quantidade de elementos a serem digitados (maximo de 15 elementos): \n");
    scanf("%d", &qt_el);

    if(qt_el > 15)
        return 0;

    printf("Digite os valores que deseja inserir no vetor: \n");

    for(i = 0; i < qt_el; i++)
        scanf("%d", &V[i]);

    int media = vetor(&V[0], qt_el);

    printf("Média: %d\n", media);
    
    return 0;
}
