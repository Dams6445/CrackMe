#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    const char *encryptedHex = "1e1c28171c19292a160a1a163901"; // Replace with your encrypted hex text
    const char *key = "myKey"; // Replace with your key
    unsigned char encryptedBytes[100];
    int encryptedLength;
    char decrypted[100]; // Make sure this is large enough to hold the decrypted text

    hexStringToBytes(encryptedHex, encryptedBytes, &encryptedLength);
    xorDecrypt(encryptedBytes, encryptedLength, decrypted, key);

    printf("Decrypted text: %s\n", decrypted);

    return 0;
}
