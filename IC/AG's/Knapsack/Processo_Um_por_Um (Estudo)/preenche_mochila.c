#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "preenche_mochila.h"


void preenche_mochila(item mochila[])
{
    strcpy(mochila[0].nome, "Laptop");
    mochila[0].valor = 500;
    mochila[0].peso = 2200;
    strcpy(mochila[1].nome, "Headphones");
    mochila[1].valor = 150;
    mochila[1].peso = 160;
    strcpy(mochila[2].nome, "Coffee Mug");
    mochila[2].valor = 60;
    mochila[2].peso = 350;
    strcpy(mochila[3].nome, "Notepad");
    mochila[3].valor = 40;
    mochila[3].peso = 333;
    strcpy(mochila[4].nome, "WaterBottle");
    mochila[4].valor = 30;
    mochila[4].peso = 192;
}

int main()
{
    item mochila[tamanho_mochila];
    preenche_mochila(mochila);
    for(int i = 0; i < tamanho_mochila; i++)
        printf("[Item %d]\nNome: %s\nPeso: %d\nValor: %d\n\n", i, mochila[i].nome, mochila[i].peso, mochila[i].valor);

    return 0;
}