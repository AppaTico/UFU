#include <stdlib.h>

/*

Cromossomo
<Disciplina, Professor, Sala, Per�odo, Dia, Hora>

Disciplina
45 obrigat�rias + 39 optativas
Aqui primeiro farei incluindo somente as obrigat�rias
111111 -> 6 bits = valor max 63 > 45

GBC011 - Empreendedorismo em Inform�tica - 000000
GBC012 - C�lculo Diferencial e Integral 1 - 000001
GBC013 - Geometria Anal�tica e �lgebra Linear - 000010
GBC014 � Programa��o Procedimental - 000011
GBC015 - Introdu��o � Ci�ncia da Computa��o - 000100
GBC016 � L�gica para Computa��o - 000101

GBC022 - C�lculo Diferencial e Integral 2 - 000110
GBC023 - Matem�tica para Ci�ncia da Computa��o - 000111
GBC021 - Profiss�o em Computa��o e Inform�tica - 001000
GBC024 - Algoritmos e Estruturas de Dados 1 - 001001
GBC025 - Programa��o L�gica - 001010
GBC026 - Sistemas Digitais  - 001011

GBC032 � C�lculo Diferencial e Integral 3 - 001100
GBC041 � Estat�stica - 001101
GBC033 � Programa��o Funcional - 001110
GBC034 � Algoritmos e Estruturas de Dados 2 - 001111
GBC035 � Prog. Orientada a Objetos 1 - 010000
GBC036 � Arquitetura e Organiza��o de Comp. 1 - 010001

FAMAT31041 - Estat�stica Computacional - 010010
GBC042 � Teoria dos Grafos - 010011
GBC043 � Sistemas de Banco de Dados - 010100
GBC044 � Linguagens Formais e Aut�matos - 010101
GBC045 � Sistemas Operacionais - 010110
GBC046 � Arquitetura e Organiza��o de Comp. 2 - 010111

Professor
Farei o mesmo numero de disciplinas, simulando 1 professor com prefer�ncia pra cada + 1 bit que ser� 1 caso a disciplina seja de sua prefer�ncia ou 0 caso n�o seja
1 111111 -> 7 bits

Sala
A FACOM s� usa 4 SALAS (1B202, 1B204, 5R-A-200, 5R-A-201) por�m podemos incluir 2 labs (1 pra cada bloco) ent�o faremos com 6
111 -> 3 bits = valor max 7 > 6

Per�odo
FACOM possui 8 per�odos
1111 -> 4 bits = valor max 15 > 8
*/

int main ()
{

    return 0;
}
