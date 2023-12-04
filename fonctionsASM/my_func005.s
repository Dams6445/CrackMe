section .text
    global my_func005

my_func005:
    push rdi
    push rsi

    mov eax, 0xc9
    xor edi, edi
    syscall

    mov ecx, 0xe10
    xor edx, edx
    div ecx

    mov eax, edx
    mov ecx, 0x3c
    xor edx, edx
    div ecx

    pop rsi
    pop rdi

    jmp jump0

jump0:
    cmp BYTE [rdi], 0x0
    je jump1
    inc rdi
    jmp jump0

jump1:
    add rax, 0x20
    mov BYTE [rdi], al
    inc rdi
    mov BYTE [rdi], 0x0

    ret
