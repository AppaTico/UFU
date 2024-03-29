//Esse programa apresenta o IMC correspondente ao peso e altura das pessoas contidas em um arquivo

#include <stdio.h>
#include <ctype.h>
#define MAX 100

struct Pessoa
{
    char nome[MAX];
    float peso;
    float altura;
};
typedef struct Pessoa Pessoa;

float imc (float peso, float altura);
void showIMC (float IMC);
void showP (Pessoa z);

int
main()
{
    FILE *stream = NULL; //Ponteiro para o arquivo
    char nomeArq[MAX]; //Nome do arquivo

    printf("\nDigite o nome do arquivo que deseja ler: ");

    scanf("%s", nomeArq);
    stream = fopen(nomeArq,"r");

    if (stream == NULL)
    {
        fprintf(stderr, "\nO arquivo %s não foi encontrado.\n", nomeArq);
        return 0;
    }

    float IMC = 0.0; //IMC
    Pessoa z; //Pessoa do arquivo

    while ( !feof(stream) )
    {
  	    fscanf(stream, "%[^0-9] %f %f", z.nome, &z.peso, &z.altura);
        fscanf(stream, " ");
  	    IMC = imc(z.peso, z.altura);
  	    showP(z);
  	    showIMC(IMC);
    }
    printf("\n");

    fclose(stream); //Fecha o arquivo
    stream = NULL;				
    return 1;
}

//Essa função retorna o IMC calculado
float imc(float peso, float altura)
{
   float resultado = peso / (altura * altura); //IMC calculado
   return resultado;
}

//Essa função apresenta o IMC e sua classificação
void showIMC(float imc)
{
	printf("\nIMC:%.1f\n", imc);

	if(imc < 18.5)
	{
		printf("\nResultado: Abaixo do peso\n");
	}
	else if(imc <= 24.9)
	{
	    printf("\nResultado: Peso normal\n");
	}
	else if(imc <= 29.9)
	{
	    printf("\nResultado: Sobrepeso\n");
	}
	else
	{
	    printf("\nResultado: Obesidade\n");
	}

	return;
}

//Essa função apresenta os dados de uma pessoa, que foram capturados do arquivo
void showP(Pessoa z)
{
   printf ("\nNome: %s\n",z.nome);
   printf ("Peso: %.1f\n",z.peso);
   printf ("Altura: %.2f\n",z.altura);

   return;
}
