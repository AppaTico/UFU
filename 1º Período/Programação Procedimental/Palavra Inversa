//Este programa apresenta uma string em ordem reversa informada pelo usuário, a string é capturada com o comando getchar() e apresentada com o comando putchar()

#include <stdio.h>
#include <string.h>
#define MAX 100

int
main()
{
  char palavra[MAX]; //palavra que o usuario vai digitar
  int i = 0; //laço for (vai fazer o programa ficar lendo as letras)
  int j = 1; //laço while (vai fazer o programa imprimir da ultima letra ate a primeira)

  printf("Digite a palavra a ser invertida: ");
  
  for(i = 0; i < MAX; i++)
  {
    palavra[i] = getchar();
    if(palavra[i] == '\n')
    {
      while((i - j) >= 0)
      { 
        palavra[i] = palavra [i - j];
        putchar(palavra[i]);
        j++;
      }
    }
  }

  return 0;
}
