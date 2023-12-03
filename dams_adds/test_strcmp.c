#include <stdio.h>
#include <string.h>

// Déclaration de la fonction my_strcmp
extern int my_strcmp(const char *str1, const char *str2);

void test_strcmp(const char *str1, const char *str2) {
    int result_libc = strcmp(str1, str2);
    int result_my = my_func015(str1, str2);

    printf("Comparaison de '%s' et '%s'\n", str1, str2);
    printf("Libc strcmp: %d\n", result_libc);
    printf("My strcmp: %d\n", result_my);

    if (result_libc == result_my) {
        printf("Les résultats sont identiques.\n");
    } else {
        printf("Les résultats sont différents.\n");
    }
}

int main() {
    test_strcmp("hello", "hello");
    test_strcmp("abc", "abd");
    test_strcmp("test", "test123");
    test_strcmp("", "");
    return 0;
}
