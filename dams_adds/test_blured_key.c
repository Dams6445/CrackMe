#include <stdio.h>

// Déclaration de la fonction externe
extern char* get_string();

int main() {
    char* str = get_string();  // Appel de la fonction NASM
    printf("coucou c'est : %s\n", str);       // Afficher la chaîne
    return 0;
}
