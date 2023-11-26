section .text
    global my_func006

my_func006:
    mov r8, rdi
    add r8, rsi
    mov r9, rsi
    sub r9, 0x2d
    xor rdx, rdx
    jmp loop_start

loop_start:
    inc rdx
    shl rsi, 0x4
    shr r9, 0x1
    xor rsi, r9
    add r8d, edx
    neg r8
    sub rsi, r8
    dec rdx
    shl rsi, 2
    dec rcx
    cmp rcx, 0x0
    je loop_start
    jmp end

end:
    mov rax, rdi
    ret