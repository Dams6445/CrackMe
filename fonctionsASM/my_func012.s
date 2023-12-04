section .text
    global my_func012

my_func012:

    ; Dead code - opérations inutiles pour complexifier
    xor r10, r10
    add r10, 5
    sub r10, 5

    loop:
        mov r8b, [rdi]      ; Charger le caractère courant de str1 dans al
        mov r9b, [rsi]      ; Charger le caractère courant de str2 dans bl

        ; Dead code - opérations inutiles
        nop                 ; No Operation - ne fait rien

        cmp r8b, r9b        ; Comparer les caractères
        ja superieur        ; Si les caractères sont superieur, sortir de la boucle
        jb inferieur        ; Si les caractères sont inférieur, sortir de la boucle

        ; Dead code - instructions sans effet
        mov r11, rax
        xor r11, r11
        add rax, r11

        test r8b, r8b       ; Tester si le caractère est nul
        jz equal            ; Si les caractères sont égaux, sortir de la boucle

        ; Passer au caractère suivant
        inc rdi
        inc rsi

        jmp loop            ; Continuer la boucle

    equal:
        xor rax, rax        ; Mettre 0 dans rax
        ret
    
    superieur:
        push 1
        pop rax             ; Mettre 1 dans rax (valeur de retour)
        ret
    
    inferieur:
        push -1
        pop rax             ; Mettre -1 dans rax

        ; Dead code - faux branchement
        jmp end             ; Saut vers la fin (qui n'existe pas)

    ; Dead code - Étiquette de fin fictive
    end:
        nop                 ; No Operation - ne fait rien
        ret
