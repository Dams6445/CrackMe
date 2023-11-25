section .text
    global my_func002

;00 00 00 00 00 3A 0B 31
;C  r  a  c  k  _  e  n

my_func002:
    cmp BYTE [rdi], 0x0
    je jump3
    inc rdi
    jmp my_func002

jump0:
    inc rdi
    mov BYTE [rdi], 0x0
    jmp jump9

jump1:
    inc rdi
    mov BYTE [rdi], 0x3a ;xor _ 0x5f
    jmp jump5

jump2:
    inc rdi
    mov BYTE [rdi], 0x00 ;xor a 0x61
    jmp jump4

jump3:
    mov BYTE [rdi], 0x00 ;xor C 0x43
    jmp jump8

jump4:
    inc rdi
    mov BYTE [rdi], 0x00 ;xor c 0x63
    jmp jump6

jump5:
    inc rdi
    mov BYTE [rdi], 0x0B ;xor e 0x65
    jmp jump7

jump6:
    inc rdi
    mov BYTE [rdi], 0x00 ;xor k 0x6b
    jmp jump1

jump7:
    inc rdi
    mov BYTE [rdi], 0x31 ;xor n 0x6e
    jmp jump0

jump8:
    inc rdi
    mov BYTE [rdi], 0x00 ;xor r 0x72
    jmp jump2

jump9:
    mov rax, 0x16f
    ret
