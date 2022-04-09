#include <stdlib.h>
#include <stdio.h>

void ordSelecaoRec(int v[], int ini, int tam)
{
    int minimo, j, menor;

  if (ini == tam) 
    return;
  else
  {
    minimo = ini;
    
    for (j = ini + 1; j < tam; j++)
    {
        if (v[j] < v[minimo])
            minimo = j;
    }

    menor = v[minimo];
    v[minimo] = v[ini];
    v[ini] = menor;
    ordSelecaoRec(v , ini + 1, tam);
  }
}

int main()
{
    int v[9], i;
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &v[i]);
    }

    ordSelecaoRec(v,0,10);

    for (i = 0; i < 10; i++)
    {
        printf("%d ",v[i]);
    }
}