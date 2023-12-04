#include <stdio.h>
#include <string.h>

// Déclaration de la fonction NASM. Elle prend un const char* en paramètre et retourne un int.
int check_length(const char*);

int main() {
    const char* testString = "Hello, World!"; // Une chaîne de test

    // Test de la fonction NASM
    int result = check_length(testString);
    printf("Resultat de la fonction NASM (>= 8): %d\n", result);

    // Test de strlen pour comparaison
    size_t length = strlen(testString);
    printf("Longueur de la chaîne avec strlen: %zu\n", length);

    return 0;
}
