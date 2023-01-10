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
  li $s0, 110 
  sw $s0, array + 0 
  li $s0, 97 
  sw $s0, array + 4 
  li $s0, 3 
  sw $s0, array + 8 
  lw $t0, array + 0 
  lw $t1, array + 4 
  sub $s0, $t0, $t1 
  sw $s0, array + 12 
  li $s0, 2 
  sw $s0, array + 16 
  lw $t0, array + 8 
  lw $t1, array + 16 
  mul $s0, $t0, $t1
  sw $s0, array + 20 
  lw $t0, array + 12 
  lw $t1, array + 20 
  add $s0, $t0, $t1
  sw $s0, array + 24 
  lw $t0, array + 24 
  move $s0, $t0 
  sw $s0, array + 8 
  lw $t0, array + 8 
  move $s0, $t0 
  sw $s0, array + 28 
  move $t7,$a0 
  move $a0, $s0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $a0,$t7 
  li $s0, 0 
  sw $s0, array + 32 
  lw $t0, array + 32 
  move $v0, $t0
  jr $ra
