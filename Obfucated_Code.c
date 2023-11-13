#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    const char *secretPassword = "SuperSecret123"; // The expected password

    printf("Enter the password: ");
    fgets(password, sizeof(password), stdin);

    // Remove the newline character if it exists
    password[strcspn(password, "\n")] = 0;

    if (strcmp(password, secretPassword) == 0) {
        printf("OK\n");
    } else {
        printf("Incorrect password!\n");
    }

    return 0;
}
