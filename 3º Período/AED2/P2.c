struct NO
{
    int info;
    int altura;
    struct NO *esq;
    struct NO *dir;

    struct cont
    {
        int chave;
        int cont;
    }cont;
};
typedef struct NO* ArvAVL;

int max(int a, int b)
{
    return (a > b ? a : b);
}

int estaVazia_ArvAVL(ArvAVL *raiz)
{
    if(raiz == NULL)
        return 1;

    if(*raiz == NULL)
        return 1;

    return 0;
}

int altura_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL)
        return 0;

    if (*raiz == NULL)
        return 0;

    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));

    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

int fator_balanceamento(ArvAVL arv)
{
    if(arv == NULL) 
        return 0;

    return (altura_ArvAVL(arv->esq) - altura_ArvAVL(arv->dir));
}

int calculaDifAltura(ArvAVL p)
{
    ArvAVL aux;
    int alt_esq = 0, alt_dir = 0;

    if(p == NULL)
        return 0;
    else
    {
        alt_esq = 1 + calculaDifAltura(p->esq);
        alt_dir = 1 + calculaDifAltura(p->dir);

        int alt = max(alt_esq, alt_dir);

        p->altura = alt;
        return alt;
    }
}