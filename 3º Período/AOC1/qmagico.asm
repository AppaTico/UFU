---------------------------------------------------------------------------------ASSEMBLY--------------------------------------------------------------------------------
# Primeiro laço for

000 LOAD M(0F2); STOR+ M(002,28:39)	# Carrega M[i][i]
001 ADD M(0FB); STOR M(0F2)		# Adiciona 5 e armazena em M[i][i]
002 LOAD M(0F5); ADD M(000)		# Carrega soma 1 e adiciona M[i][i]
003 STOR M(0F5); LOAD M(0F3)		# Armazena soma 1 e carrega M[i][n-1-i]
004 STOR+ M(006,8:19); ADD M(0FC)	# Adiciona 3
005 STOR M(0F3); LOAD M(0F6)		# Armazena em M[i][n-1-i] e carrega soma2
006 ADD M(004); STOR M(0F6)		# Adiciona M[i][n-1-i] em soma2 e armazena em soma2
007 LOAD M(0F0); SUB M(0F1)		# Carrega o contador n(3) e subtrai 1
008 STOR M(0F0); JUMP+ M(000,0:19)	# Armazena o resultado em n e volta para o começo se for positivo

# if (soma1 != soma2) magico = 0;

009 LOAD M(0F5); SUB M(0F6)		# Carrega soma1 e subtrai soma2 dela
00A STOR M(0F8); LOAD M(0F9)		# Armazena o resultado em TEMP e carrega a constante 0
00B SUB |M(0F8)|; JUMP+ M(00E,0:19)	# Subtrai módulo de TEMP de 0 e vai para else se for positivo (>= 0)
00C LOAD M(0F4); SUB M(0F1)		# Senão carrega mágico e subtrai 1
00D STOR M(0F4); NOP			# Magico = 0, fim do programa

# else

00E LOAD M(0F0); ADD M(0FD)		# Carrega a variável n e adiciona 4 para voltar a valer 3
00F STOR M(0F0); LOAD M(0F6)		# Armazena em n e carrega soma2
010 SUB M(0FE); STOR M(0F6)		# Volta soma2 a 0
011 LOAD M(0F2); SUB M(0FF)		# Carrega M[i][i] e retorna para 0x200
012 STOR M(0F2); LOAD M(0F3)		# Armazena M[i][i] e carrega M[i][n-1-i]
013 SUB M(100); STOR M(0F3)		# Retorna para 0x200 e armazena

014 LOAD M(0F2); STOR+ M(016, 28:39)	# Carrega M[i][j]
015 ADD M(0F1); STOR M(0F2)		# Adiciona 1 e armazena em M[i][j]
016 LOAD M(0F6); ADD M(011)		# Carrega soma2 e adiciona M[i][j]
017 STOR M(0F6); LOAD M(0F3)		# Armazena soma2 e carrega M[j][i]
018 STOR+ M(01A,8:19); ADD M(0FD)	# Adiciona 4
019 STOR M(0F3); LOAD M(0F7)		# Armazena M[j][i] e carrega soma3
01A ADD M(018); STOR M(0F7)		# Adiciona M[j][i] em soma3 e armazena em soma3
01B LOAD M(0F0); SUB M(0F1)		# Carrega contador n e subtrai 1
01C STOR M(0F0); JUMP+ M(014,0:19)	# Armazena em m e recomeça o laço

# if(soma2 != soma3) magico = 0;

01D LOAD M(0F6); SUB M(0F7)		# Carrega soma2 e subtrai soma3 dela
01E STOR M(0F8); LOAD M(0F9)		# Armazena o resultado em TEMP e carrega a constante 0
01F SUB |M(0F8)|; JUMP+ M(022,0:19)	# Subtrai o módulo de TEMP de 0 e vai para o prox if se for positivo
020 LOAD M(0F4); SUB M(0F1)		# Senão carrega mágico e subtrai 1
021 STOR M(0F4); NOP			# Mágico = 0, fim do programa

# else if(soma1 != soma2) magico = 0;

022 LOAD M(0F6); ADD M(0F7)		# Carrega soma2 e soma soma3
023 STOR M(0F6); LOAD M(0F5)		# Armazena soma2 e carrega soma1
024 SUB M(0F6); STOR M(0F8)		# Subtrai soma2 de soma1 e armazena em TEMP
025 LOAD M(0F9); SUB |M(0F8)|		# Carrega a constante 0 e subtrai de modulo de TEMP
026 JUMP+ M(028,0:19); LOAD M(0F4)	# Vai para fim do programa com magico sendo 1 senao carrega magico
027 SUB M(0F1); STOR M(0F4)		# Subtrai 1 de magico e armazena
028 NOP					# Fim do programa


0F0 00 00 00 00 03	# Contador de interações n(3)
0F1 00 00 00 00 01	# Constante 1

0F2 00 00 00 02 00	# Apontador do endereço M[i][i] && M[i][j]
0F3 00 00 00 02 03	# Apontador do endereço M[i][n-1-i] && M[j][i]

0F4 00 00 00 00 01	# Variável magico
0F5 00 00 00 00 00	# Variável soma1
0F6 00 00 00 00 00	# Variável soma2
0F7 00 00 00 00 00	# Variável soma3

0F8 00 00 00 00 00	# TEMP
0F9 00 00 00 00 00	# ZERO

0FA 00 00 00 00 04	# Variável n = 4

0FB 00 00 00 00 05	# Constante 5
0FC 00 00 00 00 03	# Constante 3
0FD 00 00 00 00 04	# Constante 4
0FE 00 00 00 02 0C	# Constante para resetar soma2
0FF 00 00 00 00 0F	# Constante para resetar M[i][i]
100 00 00 00 00 0C	# Constante para resetar M[i][n-1-i]

# Matriz {16,3,2,13,5,10,11,8,9,6,7,12,4,15,14,1};

200 00 00 00 00 10
201 00 00 00 00 03
202 00 00 00 00 02
203 00 00 00 00 0D
204 00 00 00 00 05
205 00 00 00 00 0A
206 00 00 00 00 0B
207 00 00 00 00 08
208 00 00 00 00 09
209 00 00 00 00 06
20A 00 00 00 00 07
20B 00 00 00 00 0C
20C 00 00 00 00 04
20D 00 00 00 00 0F
20E 00 00 00 00 0E
20F 00 00 00 00 01

---------------------------------------------------------------------------------HEXADEC--------------------------------------------------------------------------------

000 010F213002
001 050FB210F2
002 010F505000
003 210F5010F3
004 12006050FC
005 210F3010F6
006 05004210F6
007 010F0060F1
008 210F00F000


009 010F5060F6
00A 210F8010F9
00B 080F80F00E
00C 010F4060F1
00D 210F40D00D


00E 010F0050FD
00F 210F0010F6
010 060FE210F6
011 010F2060FF
012 210F2010F3
013 06100210F3

014 010F213016
015 050F1210F2
016 010F605011
017 210F6010F3
018 1201A050FD
019 210F3010F7
01A 05018210F7
01B 010F0060F1
01C 210F00F014


01D 010F6060F6
01E 210F8010F9
01F 080F80F022
020 010F4060F1
021 210F40D021


022 010F6050F7
023 210F6010F5
024 060F6210F8
025 010F9080F8
026 0F028010F4
027 060F1210F4
028 0D02800000

0F0 0000000003
0F1 0000000001

0F2 0000000200
0F3 0000000203

0F4 0000000001
0F5 0000000000
0F6 0000000000
0F7 0000000000

0F8 0000000000
0F9 0000000000

0FA 0000000004

0FB 0000000005
0FC 0000000003
0FD 0000000004
0FE 000000020C
0FF 000000000F
100 000000000C

200 0000000010
201 0000000003
202 0000000002
203 000000000D
204 0000000005
205 000000000A
206 000000000B
207 0000000008
208 0000000009
209 0000000006
20A 0000000007
20B 000000000C
20C 0000000004
20D 000000000F
20E 000000000E
20F 0000000001