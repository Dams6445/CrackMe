section .text
global test_blk2

test_blk2:
    mov rsi, rdi     ; Copie de l'adresse de la chaîne dans RSI pour le comptage
    mov rcx, 0       ; RCX compte le nombre de caractères, initialisé à 0
    xor rax, rax     ; Initialisation de RAX à 0 (pour le résultat)

count_loop:
    cmp byte [rsi], 0 ; Compare le caractère actuel à 0 (fin de chaîne)
    je check_length   ; Si fin de chaîne, vérifie la longueur
    inc rsi           ; Sinon, passe au caractère suivant
    inc rcx           ; Incrémente le compteur de caractères
    jmp count_loop    ; Continue la boucle

check_length:
    cmp rcx, 8       ; Vérifie si on a compté 9 caractères ou plus
    jge length_ok    ; Si oui, la longueur est ok
    xor rax, rax     ; Met 0 dans RAX pour indiquer faux
    jmp done         ; Passe à la fin du programme

length_ok:
    mov rax, 1       ; Met 1 dans RAX pour indiquer vrai

done:
    ret              ; Retourne avec le résultat dans RAX
