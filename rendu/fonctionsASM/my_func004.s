section .text
    global my_func004

my_func004:
    cmp BYTE [rdi], 0x0
    je jump32
    inc rdi
    jmp my_func004

jump01:
    inc rdi
    mov BYTE [rdi], 0x64
    jmp jump15

jump02:
    inc rdi
    mov BYTE [rdi], 0xCC
    jmp jump23

jump03:
    inc rdi
    mov BYTE [rdi], 0xCE
    jmp jump42

jump04:
    inc rdi
    mov BYTE [rdi], 0x82
    jmp jump06

jump05:
    inc rdi
    mov BYTE [rdi], 0xA2
    jmp jump25

jump06:
    inc rdi
    mov BYTE [rdi], 0xB9
    jmp jump27

jump07:
    inc rdi
    mov BYTE [rdi], 0xB7
    jmp jump16

jump08:
    inc rdi
    mov BYTE [rdi], 0xA6
    jmp jump18

jump09:
    inc rdi
    mov BYTE [rdi], 0xA3
    jmp jump13

jump10:
    inc rdi
    mov BYTE [rdi], 0x72
    jmp jump34

jump11:
    inc rdi
    mov BYTE [rdi], 0xCE
    jmp jump33

jump12:
    inc rdi
    mov BYTE [rdi], 0xCE
    jmp jump07

jump13:
    inc rdi
    mov BYTE [rdi], 0x6F
    jmp jump10

jump14:
    inc rdi
    mov BYTE [rdi], 0x82
    jmp jump40

jump15:
    inc rdi
    mov BYTE [rdi], 0xE2
    jmp jump20

jump16:
    inc rdi
    mov BYTE [rdi], 0xE2
    jmp jump22

jump17:
    inc rdi
    mov BYTE [rdi], 0x69
    jmp jump47

jump18:
    inc rdi
    mov BYTE [rdi], 0x0
    jmp jump48

jump19:
    inc rdi
    mov BYTE [rdi], 0x65
    jmp jump28

jump20:
    inc rdi
    mov BYTE [rdi], 0x82
    jmp jump35

jump21:
    inc rdi
    mov BYTE [rdi], 0xA9
    jmp jump17

jump22:
    inc rdi
    mov BYTE [rdi], 0x82
    jmp jump44

jump23:
    inc rdi
    mov BYTE [rdi], 0x87
    jmp jump01

jump24:
    inc rdi
    mov BYTE [rdi], 0xE2
    jmp jump14

jump25:
    inc rdi
    mov BYTE [rdi], 0x68
    jmp jump43

jump26:
    inc rdi
    mov BYTE [rdi], 0x82
    jmp jump08

jump27:
    inc rdi
    mov BYTE [rdi], 0xC2
    jmp jump05

jump28:
    inc rdi
    mov BYTE [rdi], 0xC2
    jmp jump29

jump29:
    inc rdi
    mov BYTE [rdi], 0xA5
    jmp jump31

jump30:
    inc rdi
    mov BYTE [rdi], 0x82
    jmp jump21

jump31:
    inc rdi
    mov BYTE [rdi], 0xE2
    jmp jump41

jump32:
    mov BYTE [rdi], 0x24
    jmp jump03

jump33:
    inc rdi
    mov BYTE [rdi], 0xB9
    jmp jump02

jump34:
    inc rdi
    mov BYTE [rdi], 0xE2
    jmp jump45

jump35:
    inc rdi
    mov BYTE [rdi], 0xAC
    jmp jump12

jump36:
    inc rdi
    mov BYTE [rdi], 0xAE
    jmp jump37

jump37:
    inc rdi
    mov BYTE [rdi], 0x68
    jmp jump38

jump38:
    inc rdi
    mov BYTE [rdi], 0x65
    jmp jump39

jump39:
    inc rdi
    mov BYTE [rdi], 0xE2
    jmp jump30

jump40:
    inc rdi
    mov BYTE [rdi], 0xB3
    jmp jump46

jump41:
    inc rdi
    mov BYTE [rdi], 0x82
    jmp jump09

jump42:
    inc rdi
    mov BYTE [rdi], 0xB5
    jmp jump24

jump43:
    inc rdi
    mov BYTE [rdi], 0x48
    jmp jump11

jump44:
    inc rdi
    mov BYTE [rdi], 0xAD
    jmp jump19

jump45:
    inc rdi
    mov BYTE [rdi], 0x82
    jmp jump36

jump46:
    inc rdi
    mov BYTE [rdi], 0xE2
    jmp jump04

jump47:
    inc rdi
    mov BYTE [rdi], 0xE2
    jmp jump26

jump48:
    mov BYTE [rsi], 0x64
    inc rsi
    jmp jump49

jump49:
    mov BYTE [rsi], 0x65
    inc rsi
    jmp jump50

jump50:
    mov BYTE [rsi], 0x63
    inc rsi
    jmp jump51

jump51:
    mov BYTE [rsi], 0x72
    inc rsi
    jmp jump52

jump52:
    mov BYTE [rsi], 0x79
    inc rsi
    jmp jump53

jump53:
    mov BYTE [rsi], 0x70
    inc rsi
    jmp jump54

jump54:
    mov BYTE [rsi], 0x74
    inc rsi
    jmp jump55

jump55:
    mov BYTE [rsi], 0x4B
    inc rsi
    jmp jump56

jump56:
    mov BYTE [rsi], 0x65
    inc rsi
    jmp jump57

jump57:
    mov BYTE [rsi], 0x79
    mov rax, 0x16f
    ret