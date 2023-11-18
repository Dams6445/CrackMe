#include <stdio.h>
#include <string.h>
#include <sys/ptrace.h>

int main() {
    char password[100];
    const char *secretPassword = "SuperSecret123"; // The expected password

    // Tentative d'attachement avec ptrace pour empêcher le debugging
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1) {
        printf("Debugging détecté !\n");
        return 1;
    }

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
