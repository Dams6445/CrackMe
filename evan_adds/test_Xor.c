#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <string.h>

//Pour tester :
// nasm -f elf64 -o Xor_Encrypt.o Xor_Encrypt.s
// gcc -no-pie Xor_Encrypt.o test_Xor.c -o test_Xor  
// ./test_Xor

void Xor_Encrypt(const char *input, const char *key, unsigned char *output, int *length);

void Xor_Decrypt(const char *input, int length, char *output, const char *key);

//Fonction à définir en assembler pour définir le mot de passé crypté ainsi que la clé de cryptage
void xorEncrypt(const char *input, const char *key, unsigned char *output, int *length) {
    int inputLen = strlen(input);
    int keyLen = strlen(key);

    for (int i = 0; i < inputLen; i++) {
        output[i] = input[i] ^ key[i % keyLen];
    }
    *length = inputLen; // Définir la longueur réelle du texte chiffré
}

//Fonction à définir en assembler pour décrypter le mot de passé crypté
void xorDecrypt(const unsigned char *input, int length, char *output, const char *key) {
    int keyLen = strlen(key);

    for (int i = 0; i < length; i++) {
        output[i] = input[i] ^ key[i % keyLen];
    }

    output[length] = '\0'; // Null-terminate the decrypted string
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
    char *decryptedC = malloc(100 * sizeof(char));
    char *decryptedASM = malloc(100 * sizeof(char));
    Xor_Encrypt(secretPassword, key, encryptedBytesASM, &encryptedLengthASM);
    xorEncrypt(secretPassword, key, encryptedBytesC, &encryptedLengthC);
    printf("Encrypted C: %s\n", encryptedBytesC);
    printf("Encrypted ASM: %s\n", encryptedBytesASM);
    if (strcmp(encryptedBytesASM, encryptedBytesC) == 0) {
        printf("Encrypt OK\n");
    } else {
        printf("Encrypt NOT OK!\n");
    }
    xorDecrypt(encryptedBytesC, encryptedLengthC, decryptedC, key);
    Xor_Decrypt(encryptedBytesASM, encryptedLengthASM, decryptedASM, key);
    printf("decrypted C : %s\n", decryptedC);
    printf("decrypted ASM : %s\n", decryptedASM);
    return 0;
}
