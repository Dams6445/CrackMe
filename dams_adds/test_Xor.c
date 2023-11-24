#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <string.h>

//Pour tester :
// nasm -f elf64 -o Xor_Encrypt.o Xor_Encrypt.s
// gcc -no-pie -o Xor_Encrypt.o test_Xor.c -o test_Xor  
// ./test_Xor

void funcTest(const char *input, const char *key, unsigned char *output, int *length);

//Fonction à définir en assembler pour définir le mot de passé crypté ainsi que la clé de cryptage
void xorEncrypt(const char *input, const char *key, unsigned char *output, int *length) {
    int inputLen = strlen(input);
    int keyLen = strlen(key);

    for (int i = 0; i < inputLen; i++) {
        output[i] = input[i] ^ key[i % keyLen];
    }
    *length = inputLen; // Définir la longueur réelle du texte chiffré
}

int main(int argc, char const *argv[])
{
    char password[100];
    const char *secretPassword = "secretPassword";
    const char *key = "myKey";
    unsigned char encryptedBytesASM[100] = {0}; // Initialisez avec des zéros
    unsigned char encryptedBytesC[100] = {0}; // Initialisez avec des zéros
    int encryptedLengthASM;
    int encryptedLengthC;

    xorEncrypt(secretPassword, key, encryptedBytesC, &encryptedLengthC);
    printf("C: %s\n", encryptedBytesC);

    funcTest(secretPassword, key, encryptedBytesASM, &encryptedLengthASM);

    printf("ASM: %s\n", encryptedBytesASM);

    if (strcmp(encryptedBytesASM, encryptedBytesC) == 0) {
        printf("OK\n");
    } else {
        printf("Incorrect password!\n");
    }
    return 0;
}
