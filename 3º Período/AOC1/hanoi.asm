.data

	askDisco: .asciiz "Número de discos? "
	movePino: .asciiz "Move disco do pino "
	movePino2: .asciiz "para o pino "
	space: .asciiz " "
	newLine: .asciiz "\n"

.text	
.globl main

main:

#int main()
#printf("Numero de discos? "):

	#printando askDisco
	li $v0, 4
	la $a0, askDisco
	syscall
	
#scanf("%d",&n);

	#Pegando o valor do usuario
	li $v0, 5
	syscall
	
	#Movendo o valor para outro registrador
	move $t0, $v0
	
#move(n, 'A','B','C');
	addi $s0, $zero, 'A' #de
	addi $s1, $zero, 'B' #via
	addi $s2, $zero, 'C' #para
	j Move

End:
	#return 0;
	li $v0, 10
	syscall
	
Move:

	#if (n > 1) n = $t0
	bgt $t0, 1, If
	
	#move do pino
	li $v0, 4
	la $a0, movePino
	syscall
	
	#'de'
	li $v0, 11
	move $a0, $s0
	syscall
	
	#" "
	li $v0, 4
	la $a0, space
	syscall
	
	#para o pino
	li $v0, 4
	la $a0, movePino2
	syscall
	
	#'para'
	li $v0, 11
	move $a0, $s1
	syscall
	
	#"nl"
	li $v0, 4
	la $a0, newLine
	syscall
	
	j End #termina o programa
				
If:

	#n = n - 1
	addi $t0, $t0, -1
	
	#move do pino
	li $v0, 4
	la $a0, movePino
	syscall
	
	#de
	li $v0, 11
	move $a0, $s0
	syscall
	
	#" "
	li $v0, 4
	la $a0, space
	syscall
	
	#para o pino
	li $v0, 4
	la $a0, movePino2
	syscall
	
	#para
	li $v0, 11
	move $a0, $s2
	syscall
	
	#"nl"
	li $v0, 4
	la $a0, newLine
	syscall
	
	#move(n - 1, de, para, via);
	move $s3, $s2 #move 'para' numa variavel vazia
	move $s2, $s1 #move 'via' onde ficava 'para'
	move $s1, $s3 #move 'para' onde ficava 'via'
	
	j Move