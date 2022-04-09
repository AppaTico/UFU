.data
	askString: .asciiz "Insira uma string de numeros decimais:\n"
	errorString: .asciiz "Caracter invalido!\n"
	newLine: .asciiz "\n"

	inputString: .space 100
.text
	# insercao de string
	li $v0, 4
	la $a0, askString
	syscall
	
	# leitura da string
	li $v0, 8
	la $a0, inputString
	la $a1, 100
	syscall
	
	# armazenamento do valor
	li $s0, 0
	li $s2, 0

	# calculo do tamanho da string
	jal strLen # Value in s1

	# zera o contador
	li $s0, 0

	# agora calculamos o valor dos caracteres
	j atoiMain

	# calculo potencia
	pow: # armazena em s3
		# inicia o contador
		li $t0, 1

		# copia a2 para t1
		add $t1, $a2, 0

		
		beq $a3, 0, powZeroReturn

		j powLoop

	powLoop:
		bge $t0, $a3, powReturn
		
		# a2 = a2 * t1
		mul $a2, $a2, $t1
		
		# modifica contador
		addi $t0, $t0, 1
		
		j powLoop

	powReturn:	
		# o resultado esta em s3
		move $s3, $a2
		
		# resume o programa
		jr $ra
		
	powZeroReturn:
		li $s3, 1
		
		# Resume o programa
		jr $ra
	
	# encontra a posicao do valor decimal e multiplica pelo char
	atoiMain: # s4 armazena resultado
		# carrega o endereco da string
		la $a1, inputString
		addu $a1, $a1, $s0
		lbu $a0, ($a1)
		
		# confere se eh ‘/n’
		beq, $a0, '\n', atoiReturn
		
		# confere se eh o ultimo algarismo
		beq $a0, $zero, atoiReturn
		
		# confere se o valor nao extrapola o parametro 0-9
		blt $a0, '0', atoiCharError
		bgt $a0, '9', atoiCharError
		
		# como o valor eh char, subtraímos 48 para conseguirmos o valor em int
		subi $s7, $a0, 48
						
		#calcula posicao
		li $a2, 10
		subi $a3, $s1, 1 # a3 = s1 - 1 (position)
		jal pow
		
		
		subi $s1, $s1, 1
		
		# multiplica os numeros por posicao 
		mul $s2, $s3, $s7 # s2 = s3 * a0

	       	# armazena em s4
		add $s4, $s4, $s2 # s4 = s4 + s2

	  
		addi $s0, $s0, 1

		# repete operacoes 
		j atoiMain
	
	atoiReturn:
		li $v0, 4
		la $a0, newLine
		syscall
		
		# imprime resultado
		li $v0, 1
		move $a0, $s4
		syscall
	
		# saida do programa
		li $v0, 10
		syscall
		
	# para NaN 
	atoiCharError:
		# imprime o caracter erro 
		li $v0, 11
		syscall
		
		li $v0, 1
		li $a0, -1
		syscall
		

		
		li $v0, 4
		la $a0, newLine
		syscall
	
		# mensagem de erro
		li $v0, 4
		la $a0, errorString
		syscall
		
		# encerra o programa
		li $v0, 10
		syscall
	
	strLen:
		# carrega o endereco da string
		la $a1, inputString
		addu $a1, $a1, $s0
		lbu $a0, ($a1)
		
		# confere se eh o ultimo algarismo
		beq $a0, $zero, strLenReturn
		
		# altera contador
		addi $s0, $s0, 1
		j strLen
		
	strLenReturn:
		# altera contador
		subi $s1, $s0, 1
		
		# resume o programa
		jr $ra
