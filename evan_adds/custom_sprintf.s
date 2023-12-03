global custom_sprintf
section .text
custom_sprintf:
    xor     rbx, rbx
    inc     bl
loop:
    mov     al, [rsi]  
    mov     [rdi], al
    div     bl
    inc     rdx  
    inc     rsi        
    inc     rdi
    mov     r9b, al        
    cmp     al, 0      
    jne     loop       
done:
    add     r9, 0x30
    ret