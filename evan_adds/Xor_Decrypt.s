global Xor_Decrypt
section .text
Xor_Decrypt:
    xor     r9, r9
    mov     r8, r10
    xor     r11, r11
    push    r12
    mov     r12, rdx
count_key:
    cmp     byte [r8], 0
    je      loop
    inc     r9
    inc     r8
    jmp     count_key
loop:
    cmp     r11, rsi
    jge     done
    xor     rdx, rdx
    mov     rax, r11
    div     r9
    movzx   eax, byte [rdi + r11]
    movzx   ebx, byte [r10 + rdx]
    xor     eax, ebx
    mov     [r12 + r11], al
    inc     r11
    jmp     loop
done:
    mov     byte [r12 + rsi], 0
    pop     r12
    ret