# SPL compiler generated assembly
.data
array: .space 400
_prmpt: .asciiz "Enter an integer: "
_eol: .asciiz "\n"
.globl main
.text
read:
  li $v0, 4
  move $s6, $a0
  la $a0, _prmpt
  syscall
  move $a0, $s6
  li $v0, 5
  syscall
  jr $ra
write:
  li $v0, 1
  syscall
  li $v0, 4
  move $s6, $a0
  la $a0, _eol
  syscall
  move $a0, $s6
  move $v0, $0
  jr $ra
main:
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal read
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $s0, $v0
  sw $s0, array + 0
  lw $t0, array + 0 
  move $s0, $t0 
  sw $s0, array + 4 
  lw $t0, array + 4 
  move $s0, $t0 
  sw $s0, array + 8 
  li $s0, 0 
  sw $s0, array + 12 
  lw $t0, array + 8 
  lw $t1, array + 12 
  bgt $t0, $t1, label0
  j label1
label0:
  li $s0, 1 
  sw $s0, array + 16 
  move $t7,$a0 
  move $a0, $s0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $a0,$t7 
  j label2
label1:
  lw $t0, array + 4 
  move $s0, $t0 
  sw $s0, array + 20 
  li $s0, 0 
  sw $s0, array + 24 
  lw $t0, array + 20 
  lw $t1, array + 24 
  blt $t0, $t1, label3
  j label4
label3:
  li $s0, 1 
  sw $s0, array + 28 
  lw $t0, array + 28 
  neg $t0, $t0
  addi $s0, $t0, 0 
  sw $s0, array + 32 
  move $t7,$a0 
  move $a0, $s0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $a0,$t7 
  j label5
label4:
  li $s0, 0 
  sw $s0, array + 36 
  move $t7,$a0 
  move $a0, $s0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $a0,$t7 
label5:
label2:
  li $s0, 0 
  sw $s0, array + 40 
  lw $t0, array + 40 
  move $v0, $t0
  jr $ra
