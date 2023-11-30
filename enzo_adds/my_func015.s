section .text
    global my_func015

my_func015:
    push rbx
    
.loop:
    xor eax,eax
    mov dword [rsp-8], 0xDEADBEEF
    mov eax, dword [rsp-8]
    xor ebx,ebx
    mov ecx, 42
    imul ecx, ecx, 1
    add eax, ecx
    sub eax, ecx
    mov al,[rdi]
    mov bl,[rsi]
    cmp al,bl

    jne .done

    test al,al
    jz .done

    inc rdi
    inc rsi
    jmp .loop

.done:
    mov edx, 0xAAAA
    and edx, 0x5555
    or eax, edx
    sub eax,ebx
    pop rbx
    ret
