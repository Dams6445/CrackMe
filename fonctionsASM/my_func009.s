section .text
    global my_func009

extern getenv

my_func009:
    push rdi
    mov rdi, rsi
    call getenv
    pop rdi
    jmp jump0
    

jump0:
    mov r8, rdi
    cmp BYTE [rdi], 0x0
    je jump1
    inc rdi
    jmp jump0

jump1:
    mov rbx, [rax]
    mov [rdi], bl
    cmp BYTE [rax], 0x0
    je jump2
    inc rdi
    inc rax
    jmp jump1

jump2:
    mov rax, r8
    ret
