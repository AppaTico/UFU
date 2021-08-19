//Esse programa apresenta a Matriz Quadrada digitada pelo usuário e a Diagonal Secundária da mesma. Se o valor digitado para a ordem N ser menor que 2 ou maior que 10, uma mensagem de erro explicativa em stderr vai aparecer e o programa vai encerrar

#include <stdio.h>
#include <string.h>

int
main()
{
  int N; //ordem N da matriz

  printf("Digite o valor da ordem N da matriz quadrada M: ");
  scanf("%d", &N);

  if(N < 2 || N > 10)
  {
    fprintf(stderr, "Erro: O valor de N não pode ser menor que 2, ou maior que 10.");
    return 0;
  }

  int Matriz[10][10]; // array bidimensional 10x10 para armazenar os valores de M
  int i = 0; // laço for para armazenamento dos valores de M
  int j = 0; // laço while dentro do for para armazenar os valores de M
  printf("\nAgora digite os valores a serem armazenados na matriz M de ordem %d\n", N);

  for (i = 0; i < N; i++)
  {
    while (j < N)
    {
      scanf("%d", &Matriz[i][j]);
      printf("%d\t", Matriz[i][j]);
      j++;
    }
    j = 0;
    printf("\n");
  }

  printf("\nDiagonal Secundária\n");
  for(i = 0; i < N; i++)
  {
    printf("%d ", Matriz[i][(N - 1) - i]);
  }

  return 0;
}
