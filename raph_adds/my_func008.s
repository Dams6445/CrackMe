section .text
    global my_func008

my_func008:
    xor r8, r8
    add rdi, rsi
    sub rcx, rdi
    mov rdx, 0
    inc rdx
    shl rdi, 1
    shr rcx, 1
    neg rdi
    add r8, rdx
    xor rdi, rcx
    shl r8, 2
    inc rsi
    sub rsi, rdx
    dec r8
    shl rsi, 3
    shr rdi, 2
    add rsi, rdi
    sub rdi, rsi
    xor rax, rax
    neg rdx
    add rax, rdx
    mov rdx, rax
    shl rdx, 1
    shr rdx, 1
    add rax, rdx
    mov rax, rdi
    ret