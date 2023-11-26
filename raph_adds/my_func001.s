; ne prend que la chaine de caractere

section .text
    global my_func001

my_func001:
    xor rax, rax
    jmp loop

loop:
    cmp BYTE [rdi], 0x0
    je closure
    jmp fork

fork:
    mov BYTE [rcx], dil
    cmp BYTE cl, 0x4f
    jl first_process
    je second_process
    jg third_process

first_process:
    mov rbx, rcx
    push rcx
    add rbx, 0x41
    xor rcx, rbx
    add rcx, rbx
    imul rcx, rbx
    pop rdx
    add rcx, rdx
    jmp end_fork

second_process:
    add rcx, 0x41
    xor cl, 0xff
    inc ch
    jmp end_fork

third_process:
    mov rbx, rcx
    shl cl, 4
    shr ch, 2
    neg rcx
    xor rcx, rbx
    dec rcx
    sub rbx, 0xff
    imul rcx, rbx
    add rbx, 0xff
    add rcx, rbx
    jmp end_fork

end_fork:
    add rax, rcx
    inc rdi
    jmp loop

closure:
    sub rax, 0x2
    ret


