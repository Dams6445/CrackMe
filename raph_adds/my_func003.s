; prend la chaine, un double* et un entier

section .text
    global my_func003

process:
    mov r8b, dil
    shr r8b, 2
    neg r8b
    cmp cl, r8b
    jne other_process
    inc rdi
    jmp loop

my_func003:
    xor rax, rax
    inc rax
    jmp loop

other_process:
    xor rax, rax
    jmp loop

closure:
    ret

loop:
    cmp rax, 0x0
    je closure
    cmp BYTE [rdi], 0x0
    je closure
    jmp process