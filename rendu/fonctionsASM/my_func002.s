section .text
    global my_func002

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
    mov BYTE [rdi], 0x5f
    jmp jump5

jump2:
    inc rdi
    mov BYTE [rdi], 0x61
    jmp jump4

jump3:
    mov BYTE [rdi], 0x63
    jmp jump8

jump4:
    inc rdi
    mov BYTE [rdi], 0x63
    jmp jump6

jump5:
    inc rdi
    mov BYTE [rdi], 0x65
    jmp jump7

jump6:
    inc rdi
    mov BYTE [rdi], 0x6b
    jmp jump1

jump7:
    inc rdi
    mov BYTE [rdi], 0x6e
    jmp jump0

jump8:
    inc rdi
    mov BYTE [rdi], 0x72
    jmp jump2

jump9:
    mov rax, 0x16f
    ret