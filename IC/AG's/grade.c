#include <stdlib.h>

/*

Cromossomo
<Disciplina, Professor, Sala, Período, Dia, Hora>

Disciplina
45 obrigatórias + 39 optativas
Aqui primeiro farei incluindo somente as obrigatórias
111111 -> 6 bits = valor max 63 > 45

GBC011 - Empreendedorismo em Informática - 000000
GBC012 - Cálculo Diferencial e Integral 1 - 000001
GBC013 - Geometria Analítica e Álgebra Linear - 000010
GBC014 – Programação Procedimental - 000011
GBC015 - Introdução à Ciência da Computação - 000100
GBC016 – Lógica para Computação - 000101

GBC022 - Cálculo Diferencial e Integral 2 - 000110
GBC023 - Matemática para Ciência da Computação - 000111
GBC021 - Profissão em Computação e Informática - 001000
GBC024 - Algoritmos e Estruturas de Dados 1 - 001001
GBC025 - Programação Lógica - 001010
GBC026 - Sistemas Digitais  - 001011

GBC032 – Cálculo Diferencial e Integral 3 - 001100
GBC041 – Estatística - 001101
GBC033 – Programação Funcional - 001110
GBC034 – Algoritmos e Estruturas de Dados 2 - 001111
GBC035 – Prog. Orientada a Objetos 1 - 010000
GBC036 – Arquitetura e Organização de Comp. 1 - 010001

FAMAT31041 - Estatística Computacional - 010010
GBC042 – Teoria dos Grafos - 010011
GBC043 – Sistemas de Banco de Dados - 010100
GBC044 – Linguagens Formais e Autômatos - 010101
GBC045 – Sistemas Operacionais - 010110
GBC046 – Arquitetura e Organização de Comp. 2 - 010111

Professor
Farei o mesmo numero de disciplinas, simulando 1 professor com preferência pra cada + 1 bit que será 1 caso a disciplina seja de sua preferência ou 0 caso não seja
1 111111 -> 7 bits

Sala
A FACOM só usa 4 SALAS (1B202, 1B204, 5R-A-200, 5R-A-201) porém podemos incluir 2 labs (1 pra cada bloco) então faremos com 6
111 -> 3 bits = valor max 7 > 6

Período
FACOM possui 8 períodos
1111 -> 4 bits = valor max 15 > 8
*/

int main ()
{

    return 0;
}
