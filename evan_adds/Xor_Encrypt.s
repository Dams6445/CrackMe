global Xor_Encrypt
section .text
Xor_Encrypt:
    xor     r8, r8
    xor     r10, r10
    mov     r11, rdi
    push    r12
    push    r13
    push    r14
    mov     r12, rsi
    mov     r13, rdx
    xor     r14, r14
count_input:
    cmp     byte [r11], 0
    je      count_key
    inc     r8
    inc     r11
    jmp     count_input
count_key:
    cmp     byte [r12], 0
    je      loop
    inc     r10
    inc     r12
    jmp     count_key
loop:
    cmp     r14, r8
    jge     done
    xor     rdx, rdx
    mov     rax, r14
    div     r10
    movzx   eax, byte [rdi + r14]
    movzx   ebx, byte [rsi + rdx]
    xor     eax, ebx
    mov     [r13 + r14], al
    inc     r14
    jmp     loop
done:
    mov     [rcx], r8
    pop     r14
    pop     r13
    pop     r12
    ret
