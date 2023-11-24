#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int checkPassword(const char *input) {
    const char *secretPassword = "SuperSecret123";
    while (*input) {
        if (*input != *secretPassword) {
            return 0; // Incorrect character
        }
        input++;
        secretPassword++;
    }
    return *secretPassword == '\0';
}

int main() {
    char password[100];

    printf("Enter the password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    int result = 0;
    int randomValue = rand() % 3; // Introduce some randomness

    switch (randomValue) {
        case 0:
            result = checkPassword(password);
            break;
        case 1:
            result = !checkPassword(password) ? 0 : 1;
            break;
        case 2:
            for (int i = 0; i < 2; i++) {
                result = checkPassword(password);
                if (result == 0) break;
            }
            break;
        default:
            printf("An unexpected error occurred.\n");
            exit(1);
    }

    if (result) {
        printf("OK\n");
    } else {
        printf("Incorrect password!\n");
    }

    return 0;
}
