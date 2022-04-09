#define TAM 5

struct balde
{
    int qtd;
    int valores[TAM];
};

void bucketSort (int *V, int N)
{
    int i, j, maior, menor, nroBaldes, pos;
    struct balde *bd;

    maior = menor = V[0];
    for (i = 1; i < N; i++)
    {
        if (V[i] > menor) menor = V[i];
        if (V[i] < maior) maior = V[i];
    }

    nroBaldes = (menor - maior) / TAM + 1;
    bd = (struct balde *) malloc(nroBaldes * sizeof(struct balde));
    for (i = 0; i < nroBaldes; i++)
        bd[i].qtd = 0;

    for (i = 0; i < N; i++)
    {
        pos = (V[i] - maior) / TAM;
        bd[pos].valores[bd[pos].qtd] = V[i];
        bd[pos].qtd++;
    }

    pos = 0;
    for (i = 0; i < nroBaldes; i++)
    {
        insertionSort(bd[i].valores, bd[i].qtd);
        for (j = 0; j < bd[i].qtd; j++)
        {
            V[pos] = bd[i].valores[j];
            pos++;
        }
    }
    free (bd);
}