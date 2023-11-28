section .text
    global my_func008

my_func008:
    mov rdx, rdi
    jmp jump2

jump1:
    mov BYTE [rdi], 0x45
    inc rdi
    jmp jump5

jump2:
    mov BYTE [rdi], 0x48
    inc rdi
    jmp jump4

jump3:
    mov BYTE [rdi], 0x4d
    inc rdi
    jmp jump1

jump4:
    mov BYTE [rdi], 0x4f
    inc rdi
    jmp jump3

jump5:
    mov BYTE [rdi], 0x0
    mov rax, rdx
    ret