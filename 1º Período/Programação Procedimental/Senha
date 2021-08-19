//Este programa criptografa a senha que o usuario digitar para a tabela ASCII

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int
main()
{
  char fim[4] = "FIM"; //string pra definir o break quando o usuario escrever FIM
  char N[MAX]; //senha digitada
  int i = 0; //laço for

  printf("Digite uma senha\n\n");
  do
  {
    scanf("%s", N);

    if(strcmp(N, fim) == 0)
    {
      break;
    }

    else for(i = 0; i < strlen(N); i++)
    {
      if(N[i] != 10)
      {
        printf("%d ", N[i]);
      }

      if(N[i] == '\n')
      {
        scanf("%s", N);
        printf("%d ", N[i]);
      }
    }
  }
  while(strcmp(N, fim) != 0);

  return 0;
}
