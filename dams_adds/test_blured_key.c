#include <stdio.h>
#include <sys/ptrace.h>

// Déclaration de la fonction externe
int get_string(int* string1, char* string2);
// extern char* get_string();

int main() {
    int test[255] = {0};
    char password2[255] = "";

    get_string(test, password2);
    char password1[255] = "";
    // cast de test en char*
    // sprintf(password1, "%s", (char*)test);
    password1 = test;
    printf("test : %s\n", (char*)test);
    printf("password1 : %s\n", password1);
    printf("password2 : %s\n", password2);
    return 0;
}
