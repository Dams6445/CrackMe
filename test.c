#include <stdio.h>
#include <string.h>

void xor_encrypt(char *input, const char *key, char *output) {
    size_t input_len = strlen(input);
    size_t key_len = strlen(key);

    for (size_t i = 0; i < input_len; i++) {
        output[i] = input[i] ^ key[i % key_len];
    }

    // Null-terminate the output string
    output[input_len] = '\0';
}

int main() {
    const char *key = "myKey";
    char text[] = "secretPassword";
    char encrypted[sizeof(text)];  // Make sure it's large enough to hold the input

    xor_encrypt(text, key, encrypted);
    printf("Encrypted: ");
    for (size_t i = 0; i < sizeof(text) - 1; i++) {
        printf("%02x", (unsigned char)encrypted[i]);
    }
    printf("\n");

    char decrypted[sizeof(text)];
    xor_encrypt(encrypted, key, decrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
