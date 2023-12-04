section .text
global test_blk4

; Fonction pour vérifier si la longueur de la chaîne en rdi est >= à la valeur en rsi
; Arguments: RDI = adresse de la chaîne, RSI = longueur à tester
; Retour: RAX = 1 si la longueur est >= à la valeur en rsi, 0 sinon
test_blk4:
    mov rax, rdi        ; Copie de l'adresse de la chaîne dans RAX pour le comptage
    xor rcx, rcx        ; RCX est le compteur de longueur, initialisé à 0

count_loop:
    cmp byte [rax], 0   ; Compare le caractère actuel à 0 (fin de chaîne)
    je test_blk4_done; Si fin de chaîne, sortie de la boucle
    inc rax             ; Sinon, passe au caractère suivant
    inc rcx             ; Incrémente le compteur de longueur
    jmp count_loop      ; Continue la boucle

test_blk4_done:
    cmp rcx, rsi        ; Compare la longueur comptée avec la longueur à tester
    jae length_ok       ; Si rcx >= rsi, longueur OK
    xor rax, rax        ; Met 0 dans RAX pour indiquer faux
    ret

length_ok:
    mov rax, 1          ; Met 1 dans RAX pour indiquer vrai
    ret
