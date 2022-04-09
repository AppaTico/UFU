#include <stdio.h>
void move(int n, char de, char via, char para)
{
 if (n > 1) {
printf("%c %c %c\n", de, via, para);
 move(n - 1, de, para, via);
 printf("Move disco do pino %c para o pino %c\n", de, para);
 move(n - 1, via, de, para);
} else {
    printf("Move disco do pino %c para o pino %c\n", de, para);
    }
}
int main()
{
    int n;
    printf("Numero de discos? ");
    scanf("%d",&n);
    move(n, 'A','B','C');
    return 0;
}

/*
.data

        askDisco 

*/