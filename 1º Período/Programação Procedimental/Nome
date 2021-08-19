//Este programa pega as palavras digitadas pelo usuario e apresenta suas Iniciais

#include <stdio.h>
#include <string.h>
#define MAX 100

int
main()
{
  char n[MAX]; //palavra digitada
  unsigned int i = 0;//laço while

  printf("Digite as palavras: ");
  scanf("%[^\n]c", n);

  do
  {
    printf("Iniciais: ");
    printf("%c", n[0]);
    while(i < strlen(n))
    {
      if(n[i] == 32 || n[i] == 9)
      {
        printf("%c", n[i + 1]);
      }
      i++;
    }
  }
  while(i < strlen(n));

  printf("\n");
  
  return 0;
}
