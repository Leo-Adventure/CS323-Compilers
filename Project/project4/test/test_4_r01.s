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
hanoi:
  move $s0, $a0 
  sw $s0, array + 0 
  li $s0, 1 
  sw $s0, array + 4 
  lw $t0, array + 0 
  lw $t1, array + 4 
  beq $t0, $t1, label0
  j label1
label0:
  move $s0, $a1 
  sw $s0, array + 8 
  li $s0, 10000 
  sw $s0, array + 12 
  lw $t0, array + 8 
  lw $t1, array + 12 
  mul $s0, $t0, $t1
  sw $s0, array + 16 
  move $s0, $a3 
  sw $s0, array + 20 
  lw $t0, array + 16 
  lw $t1, array + 20 
  add $s0, $t0, $t1
  sw $s0, array + 24 
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
  move $s0, $a0 
  sw $s0, array + 28 
  li $s0, 1 
  sw $s0, array + 32 
  lw $t0, array + 28 
  lw $t1, array + 32 
  sub $s0, $t0, $t1 
  sw $s0, array + 36 
  move $s0, $a1 
  sw $s0, array + 40 
  move $s0, $a3 
  sw $s0, array + 44 
  move $s0, $a2 
  sw $s0, array + 48 
  addi $sp, $sp, -20 
  sw $ra, 0($sp)
  sw $a0, 4($sp) 
  sw $a1, 8($sp) 
  sw $a2, 12($sp) 
  sw $a3, 16($sp) 
  lw $a0, array + 36
  lw $a1, array + 40
  lw $a2, array + 44
  lw $a3, array + 48
  jal hanoi
  lw $ra, 0($sp)
  lw $a0, 4($sp)
  lw $a1, 8($sp)
  lw $a2, 12($sp)
  lw $a3, 16($sp)
  addi $sp, $sp, 20
  move $s0, $v0
  sw $s0, array + 52
  move $s0, $a1 
  sw $s0, array + 56 
  li $s0, 10000 
  sw $s0, array + 60 
  lw $t0, array + 56 
  lw $t1, array + 60 
  mul $s0, $t0, $t1
  sw $s0, array + 64 
  move $s0, $a3 
  sw $s0, array + 68 
  lw $t0, array + 64 
  lw $t1, array + 68 
  add $s0, $t0, $t1
  sw $s0, array + 72 
  move $t7,$a0 
  move $a0, $s0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $a0,$t7 
  move $s0, $a0 
  sw $s0, array + 76 
  li $s0, 1 
  sw $s0, array + 80 
  lw $t0, array + 76 
  lw $t1, array + 80 
  sub $s0, $t0, $t1 
  sw $s0, array + 84 
  move $s0, $a2 
  sw $s0, array + 88 
  move $s0, $a1 
  sw $s0, array + 92 
  move $s0, $a3 
  sw $s0, array + 96 
  addi $sp, $sp, -20 
  sw $ra, 0($sp)
  sw $a0, 4($sp) 
  sw $a1, 8($sp) 
  sw $a2, 12($sp) 
  sw $a3, 16($sp) 
  lw $a0, array + 84
  lw $a1, array + 88
  lw $a2, array + 92
  lw $a3, array + 96
  jal hanoi
  lw $ra, 0($sp)
  lw $a0, 4($sp)
  lw $a1, 8($sp)
  lw $a2, 12($sp)
  lw $a3, 16($sp)
  addi $sp, $sp, 20
  move $s0, $v0
  sw $s0, array + 100
label2:
  li $s0, 0 
  sw $s0, array + 104 
  lw $t0, array + 104 
  move $v0, $t0
  jr $ra
main:
  li $s0, 3 
  sw $s0, array + 108 
  lw $t0, array + 108 
  move $s0, $t0 
  sw $s0, array + 112 
  lw $t0, array + 112 
  move $s0, $t0 
  sw $s0, array + 116 
  li $s0, 1 
  sw $s0, array + 120 
  li $s0, 2 
  sw $s0, array + 124 
  li $s0, 3 
  sw $s0, array + 128 
  addi $sp, $sp, -20 
  sw $ra, 0($sp)
  sw $a0, 4($sp) 
  sw $a1, 8($sp) 
  sw $a2, 12($sp) 
  sw $a3, 16($sp) 
  lw $a0, array + 116
  lw $a1, array + 120
  lw $a2, array + 124
  lw $a3, array + 128
  jal hanoi
  lw $ra, 0($sp)
  lw $a0, 4($sp)
  lw $a1, 8($sp)
  lw $a2, 12($sp)
  lw $a3, 16($sp)
  addi $sp, $sp, 20
  move $s0, $v0
  sw $s0, array + 132
  li $s0, 0 
  sw $s0, array + 136 
  lw $t0, array + 136 
  move $v0, $t0
  jr $ra
