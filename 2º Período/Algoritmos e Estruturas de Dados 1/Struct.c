#include <stdio.h>
#include <stdlib.h>

struct dados_pacientes
{
    float grau_miopia[2];
    int idade;
    double altura;
    char nome[10];
    double peso;
    int estado_civil;
};

int main ()
{
    struct dados_pacientes paciente;
    
    int tamanho_total = sizeof(paciente.idade) + sizeof(paciente.nome)
     + sizeof(paciente.peso) + sizeof(paciente.altura) + sizeof(paciente.estado_civil)
     + sizeof(paciente.grau_miopia);

    printf("\nTamanho do campo idade: %lu", sizeof(paciente.idade));
    printf("\nTamanho do campo nome: %lu", sizeof(paciente.nome));
    printf("\nTamanho do campo peso: %lu", sizeof(paciente.peso));
    printf("\nTamanho do campo altura: %lu", sizeof(paciente.altura));
    printf("\nTamanho do campo estado_civil: %lu", sizeof(paciente.estado_civil));
    printf("\nTamanho do campo grau_miopia: %lu", sizeof(paciente.grau_miopia));
    printf("\n\nTamanho total da estrutura: %d", tamanho_total);
    printf("\n\nTamanho real da estrutura: %lu", sizeof(paciente));

    printf("\n");
    return 0;
}
