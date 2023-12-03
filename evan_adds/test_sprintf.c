#include <stdio.h>
#include <string.h>

// Déclaration de votre fonction sprintf personnalisée
int custom_sprintf(char *str, const char *format, ...);

int main() {
    char buffer1[100];
    char buffer2[100];
    int num1, num2;
    const char *testString = "Test %d, %s";

    // Utilisez votre fonction sprintf personnalisée
    num1 = custom_sprintf(buffer1, testString, 123, "abc");

    // Utilisez la fonction sprintf de la bibliothèque standard
    num2 = sprintf(buffer2, testString, 123, "abc");

    // Comparer les résultats
    printf("Custom sprintf returned: %d, Output: %s\n", num1, buffer1);
    printf("Standard sprintf returned: %d, Output: %s\n", num2, buffer2);

    // Vérifier si les chaînes et les valeurs de retour sont identiques
    if (strcmp(buffer1, buffer2) == 0 && num1 == num2) {
        printf("Les deux fonctions sprintf produisent le même résultat.\n");
    } else {
        printf("Les résultats diffèrent.\n");
    }

    return 0;
}
