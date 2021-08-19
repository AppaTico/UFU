#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto 
{
    double x, y;
};

struct ponto *Cria_pto (double x, double y)
{
    struct ponto *ponto = NULL;
    ponto = (struct ponto*) malloc(sizeof(struct ponto));

    if(ponto != NULL)
    {
        ponto -> x = x;
        ponto -> y = y;
    }

    return ponto;
}

void Libera_pto(struct ponto **p)
{
    free(*p);
    *p = NULL;
}

double Distancia_pto(struct ponto *p1, struct ponto *p2)
{
    if(p1 == NULL || p2 == NULL)
    {
        return -1; //distancia entre 2 pts pode ser 0, ent vou de -1
    }

    return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}
