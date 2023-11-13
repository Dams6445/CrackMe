#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hexCharToValue(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return 10 + c - 'a';
    if (c >= 'A' && c <= 'F') return 10 + c - 'A';
    return 0; // Not a valid hexadecimal character
}

void hexStringToBytes(const char *hexString, unsigned char *bytes, int *length) {
    *length = 0;
    while (*hexString && *(hexString + 1)) {
        int value = hexCharToValue(*hexString++) << 4;
        value |= hexCharToValue(*hexString++);
        bytes[(*length)++] = (unsigned char)value;
    }
}

void xorDecrypt(const unsigned char *input, int length, char *output, const char *key) {
    int keyLen = strlen(key);

    for (int i = 0; i < length; i++) {
        output[i] = input[i] ^ key[i % keyLen];
    }

    output[length] = '\0'; // Null-terminate the decrypted string
}

int main() {
    char password[100];
    //Still need to hide this from strings
    const char *encryptedHex = "1e1c28171c19292a160a1a163901"; //encrypted version of secretPassword
    const char *key = "myKey"; // Replace with your key
    unsigned char encryptedBytes[100];
    int encryptedLength;
    char *decrypted = malloc(100 * sizeof(char));   // Make sure this is large enough to hold the decrypted text

    printf("Enter the password: ");
    fgets(password, sizeof(password), stdin);

    // Remove the newline character if it exists
    password[strcspn(password, "\n")] = 0;

    // Decrypt the secret password
    hexStringToBytes(encryptedHex, encryptedBytes, &encryptedLength);
    xorDecrypt(encryptedBytes, encryptedLength, decrypted, key);

    if (strcmp(password, decrypted) == 0) {
        printf("OK\n");
    } else {
        printf("Incorrect password!\n");
    }

    // Overwrite the sensitive data
    memset(decrypted, 0, 100 * sizeof(char));

    // Free the memory
    free(decrypted);

    return 0;
}
