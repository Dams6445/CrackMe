section .text
    global my_func004

my_func004:
    cmp BYTE [rdi], 0x0
    je jump0
    inc rdi
    jmp my_func004

jump0:
    mov BYTE [rdi], 0x43
    jmp jump1

jump1:
    inc rdi
    mov BYTE [rdi], 0x72
    jmp jump2

jump2:
    inc rdi
    mov BYTE [rdi], 0x61
    jmp jump3

jump3:
    inc rdi
    mov BYTE [rdi], 0x63
    jmp jump4

jump4:
    inc rdi
    mov BYTE [rdi], 0x6b
    jmp jump5

jump5:
    inc rdi
    mov BYTE [rdi], 0x65
    jmp jump6

jump6:
    inc rdi
    mov BYTE [rdi], 0x64
    jmp jump7

jump7:
    inc rdi
    mov BYTE [rdi], 0x4b
    jmp jump8

jump8:
    inc rdi
    mov BYTE [rdi], 0x65
    jmp jump9

jump9:
    inc rdi
    mov BYTE [rdi], 0x79
    jmp jump10

jump10:
    inc rdi
    mov BYTE [rdi], 0x0
    jmp jump11

jump11:
    mov rax, 0x16f
    ret