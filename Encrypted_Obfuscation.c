#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int main() {
    char password[100];
    const char *secretPassword = "secretPassword";
    const char *key = "myKey";
    unsigned char encryptedBytes[100] = {0}; // Initialisez avec des zéros
    int encryptedLength;

    xorEncrypt(secretPassword, key, encryptedBytes, &encryptedLength);

    char *decrypted = malloc(100 * sizeof(char));

    printf("Enter the password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0; // Retirer le caractère de saut de ligne

    xorDecrypt(encryptedBytes, encryptedLength, decrypted, key);

    printf("Decrypted: %s\n", decrypted);

    if (strcmp(password, decrypted) == 0) {
        printf("OK\n");
    } else {
        printf("Incorrect password!\n");
    }

    memset(decrypted, 0, 100 * sizeof(char)); // Effacer les données sensibles
    free(decrypted); // Libérer la mémoire

    return 0;
}
