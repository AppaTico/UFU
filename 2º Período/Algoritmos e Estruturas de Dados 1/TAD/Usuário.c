#include <stdio.h>
#include "ponto.h"

int main()
{
    Ponto *ponto1, *ponto2;
    double x, y;

    printf("\nDigite as coordenadas do ponto 1\nx e y: ");
    scanf("%lf %lf", &x, &y);

    ponto1 = Cria_pto (x, y);

    printf("\nDigite as coordenadas do ponto 2\nx e y: ");
    scanf("%lf %lf", &x, &y);

    ponto2 = Cria_pto (x, y);

    printf("\nA distância entre esses dois pontos é: %.3lf\n", Distancia_pto (ponto1, ponto2));

    Libera_pto (&ponto1);
    Libera_pto (&ponto2);

    return 0;
}
